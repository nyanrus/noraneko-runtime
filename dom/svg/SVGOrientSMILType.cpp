/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "SVGOrientSMILType.h"

#include "mozilla/SMILValue.h"
#include "mozilla/dom/SVGMarkerElement.h"
#include "nsDebug.h"
#include "SVGAnimatedOrient.h"
#include <math.h>

namespace mozilla {

using namespace dom::SVGAngle_Binding;
using namespace dom::SVGMarkerElement_Binding;

/*static*/
SVGOrientSMILType SVGOrientSMILType::sSingleton;

void SVGOrientSMILType::InitValue(SMILValue& aValue) const {
  MOZ_ASSERT(aValue.IsNull(), "Unexpected value type");

  aValue.mU.mOrient.mAngle = 0.0f;
  aValue.mU.mOrient.mUnit = SVG_ANGLETYPE_UNSPECIFIED;
  aValue.mU.mOrient.mOrientType = SVG_MARKER_ORIENT_ANGLE;
  aValue.mType = this;
}

void SVGOrientSMILType::DestroyValue(SMILValue& aValue) const {
  MOZ_ASSERT(aValue.mType == this, "Unexpected SMIL value.");
  aValue.mU.mPtr = nullptr;
  aValue.mType = SMILNullType::Singleton();
}

nsresult SVGOrientSMILType::Assign(SMILValue& aDest,
                                   const SMILValue& aSrc) const {
  MOZ_ASSERT(aDest.mType == aSrc.mType, "Incompatible SMIL types.");
  MOZ_ASSERT(aDest.mType == this, "Unexpected SMIL value.");

  aDest.mU.mOrient.mAngle = aSrc.mU.mOrient.mAngle;
  aDest.mU.mOrient.mUnit = aSrc.mU.mOrient.mUnit;
  aDest.mU.mOrient.mOrientType = aSrc.mU.mOrient.mOrientType;
  return NS_OK;
}

bool SVGOrientSMILType::IsEqual(const SMILValue& aLeft,
                                const SMILValue& aRight) const {
  MOZ_ASSERT(aLeft.mType == aRight.mType, "Incompatible SMIL types");
  MOZ_ASSERT(aLeft.mType == this, "Unexpected type for SMIL value");

  return aLeft.mU.mOrient.mAngle == aRight.mU.mOrient.mAngle &&
         aLeft.mU.mOrient.mUnit == aRight.mU.mOrient.mUnit &&
         aLeft.mU.mOrient.mOrientType == aRight.mU.mOrient.mOrientType;
}

static float ValueInDegrees(const SMILValue& aValue) {
  MOZ_ASSERT(aValue.mU.mOrient.mOrientType == SVG_MARKER_ORIENT_ANGLE);

  return aValue.mU.mOrient.mAngle == 0.0f
             ? 0.0f
             : aValue.mU.mOrient.mAngle * SVGAnimatedOrient::GetDegreesPerUnit(
                                              aValue.mU.mOrient.mUnit);
}

nsresult SVGOrientSMILType::Add(SMILValue& aDest, const SMILValue& aValueToAdd,
                                uint32_t aCount) const {
  MOZ_ASSERT(aValueToAdd.mType == aDest.mType, "Trying to add invalid types");
  MOZ_ASSERT(aValueToAdd.mType == this, "Unexpected source type");

  if (aDest.mU.mOrient.mOrientType != SVG_MARKER_ORIENT_ANGLE ||
      aValueToAdd.mU.mOrient.mOrientType != SVG_MARKER_ORIENT_ANGLE) {
    // TODO: it would be nice to be able to add to auto angles
    return NS_ERROR_FAILURE;
  }

  // We may be dealing with two different angle units, so we normalize to
  // degrees for the add:
  float currentAngle = ValueInDegrees(aDest);
  float angleToAdd = ValueInDegrees(aValueToAdd) * aCount;

  // And then we give the resulting animated value the same units as the value
  // that we're animating to/by (i.e. the same as aValueToAdd):
  aDest.mU.mOrient.mAngle =
      (currentAngle + angleToAdd) /
      SVGAnimatedOrient::GetDegreesPerUnit(aValueToAdd.mU.mOrient.mUnit);
  aDest.mU.mOrient.mUnit = aValueToAdd.mU.mOrient.mUnit;

  return NS_OK;
}

nsresult SVGOrientSMILType::ComputeDistance(const SMILValue& aFrom,
                                            const SMILValue& aTo,
                                            double& aDistance) const {
  MOZ_ASSERT(aFrom.mType == aTo.mType, "Trying to compare different types");
  MOZ_ASSERT(aFrom.mType == this, "Unexpected source type");

  if (aFrom.mU.mOrient.mOrientType != SVG_MARKER_ORIENT_ANGLE ||
      aTo.mU.mOrient.mOrientType != SVG_MARKER_ORIENT_ANGLE) {
    // TODO: it would be nice to be able to compute distance with auto angles
    return NS_ERROR_FAILURE;
  }

  // Normalize both to degrees in case they're different angle units:
  aDistance = fabs(ValueInDegrees(aTo) - ValueInDegrees(aFrom));

  return NS_OK;
}

nsresult SVGOrientSMILType::Interpolate(const SMILValue& aStartVal,
                                        const SMILValue& aEndVal,
                                        double aUnitDistance,
                                        SMILValue& aResult) const {
  MOZ_ASSERT(aStartVal.mType == aEndVal.mType,
             "Trying to interpolate different types");
  MOZ_ASSERT(aStartVal.mType == this, "Unexpected types for interpolation.");
  MOZ_ASSERT(aResult.mType == this, "Unexpected result type.");

  if (aStartVal.mU.mOrient.mOrientType != SVG_MARKER_ORIENT_ANGLE ||
      aEndVal.mU.mOrient.mOrientType != SVG_MARKER_ORIENT_ANGLE) {
    // TODO: it would be nice to be able to handle auto angles too.
    return NS_ERROR_FAILURE;
  }

  float start = ValueInDegrees(aStartVal);
  float end = ValueInDegrees(aEndVal);
  float result = (start + (end - start) * aUnitDistance);

  // we use the unit of the nearest value for the result:
  if (aUnitDistance > 0.5) {
    aResult.mU.mOrient.mAngle =
        result / SVGAnimatedOrient::GetDegreesPerUnit(aEndVal.mU.mOrient.mUnit);
    aResult.mU.mOrient.mUnit = aEndVal.mU.mOrient.mUnit;
  } else {
    aResult.mU.mOrient.mAngle = result / SVGAnimatedOrient::GetDegreesPerUnit(
                                             aStartVal.mU.mOrient.mUnit);
    aResult.mU.mOrient.mUnit = aStartVal.mU.mOrient.mUnit;
  }

  return NS_OK;
}

}  // namespace mozilla
