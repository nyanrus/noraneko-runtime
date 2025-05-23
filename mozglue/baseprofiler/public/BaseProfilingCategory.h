/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 * vim: set ts=8 sts=4 et sw=4 tw=99:
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BaseProfilingCategory_h
#define BaseProfilingCategory_h

#include "mozilla/Span.h"
#include "mozilla/Types.h"

#include <cstdint>

#include "ProfilingCategoryList.h"

namespace mozilla {
namespace baseprofiler {

// clang-format off

// An enum that lists all possible category pairs in one list.
// This is the enum that is used in profiler stack labels. Having one list that
// includes subcategories from all categories in one list allows assigning the
// category pair to a stack label with just one number.
#define CATEGORY_ENUM_BEGIN_CATEGORY(name, labelAsString, color)
#define CATEGORY_ENUM_SUBCATEGORY(supercategory, name, labelAsString) name,
#define CATEGORY_ENUM_END_CATEGORY
enum class ProfilingCategoryPair : uint32_t {
  MOZ_PROFILING_CATEGORY_LIST(CATEGORY_ENUM_BEGIN_CATEGORY,
                              CATEGORY_ENUM_SUBCATEGORY,
                              CATEGORY_ENUM_END_CATEGORY)
  COUNT,
  LAST = COUNT - 1,
};
#undef CATEGORY_ENUM_BEGIN_CATEGORY
#undef CATEGORY_ENUM_SUBCATEGORY
#undef CATEGORY_ENUM_END_CATEGORY

// An enum that lists just the categories without their subcategories.
#define SUPERCATEGORY_ENUM_BEGIN_CATEGORY(name, labelAsString, color) name,
#define SUPERCATEGORY_ENUM_SUBCATEGORY(supercategory, name, labelAsString)
#define SUPERCATEGORY_ENUM_END_CATEGORY
enum class ProfilingCategory : uint32_t {
  MOZ_PROFILING_CATEGORY_LIST(SUPERCATEGORY_ENUM_BEGIN_CATEGORY,
                              SUPERCATEGORY_ENUM_SUBCATEGORY,
                              SUPERCATEGORY_ENUM_END_CATEGORY)
  COUNT,
  LAST = COUNT - 1,
};
#undef SUPERCATEGORY_ENUM_BEGIN_CATEGORY
#undef SUPERCATEGORY_ENUM_SUBCATEGORY
#undef SUPERCATEGORY_ENUM_END_CATEGORY

// clang-format on

struct ProfilingCategoryInfo {
  const char* mName;
  const char* mColor;
  const mozilla::Span<const char* const> mSubcategoryNames;
};

struct ProfilingCategoryPairInfo {
  ProfilingCategory mCategory;
  uint32_t mSubcategoryIndex;
  const char* mLabel;
};

MFBT_API mozilla::Span<const ProfilingCategoryInfo> GetProfilingCategoryList();

MFBT_API const ProfilingCategoryPairInfo& GetProfilingCategoryPairInfo(
    ProfilingCategoryPair aCategoryPair);

}  // namespace baseprofiler
}  // namespace mozilla

#endif /* BaseProfilingCategory_h */
