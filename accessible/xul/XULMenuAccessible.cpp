/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "XULMenuAccessible.h"

#include "LocalAccessible-inl.h"
#include "XULMenuBarElement.h"
#include "XULMenuParentElement.h"
#include "XULPopupElement.h"
#include "mozilla/Assertions.h"
#include "nsAccessibilityService.h"
#include "nsAccUtils.h"
#include "DocAccessible.h"
#include "mozilla/a11y/Role.h"
#include "States.h"
#include "XULFormControlAccessible.h"

#include "nsIContentInlines.h"
#include "nsIDOMXULContainerElement.h"
#include "nsIDOMXULSelectCntrlEl.h"
#include "nsIDOMXULSelectCntrlItemEl.h"
#include "nsIContent.h"
#include "nsMenuPopupFrame.h"

#include "mozilla/Preferences.h"
#include "mozilla/LookAndFeel.h"
#include "mozilla/dom/Document.h"
#include "mozilla/dom/Element.h"
#include "mozilla/dom/XULButtonElement.h"
#include "mozilla/dom/KeyboardEventBinding.h"

using namespace mozilla;
using namespace mozilla::a11y;

////////////////////////////////////////////////////////////////////////////////
// XULMenuitemAccessible
////////////////////////////////////////////////////////////////////////////////

XULMenuitemAccessible::XULMenuitemAccessible(nsIContent* aContent,
                                             DocAccessible* aDoc)
    : AccessibleWrap(aContent, aDoc) {}

uint64_t XULMenuitemAccessible::NativeState() const {
  uint64_t state = LocalAccessible::NativeState();

  // Has Popup?
  if (mContent->NodeInfo()->Equals(nsGkAtoms::menu, kNameSpaceID_XUL)) {
    state |= states::HASPOPUP | states::EXPANDABLE;
    if (mContent->AsElement()->HasAttr(nsGkAtoms::open)) {
      state |= states::EXPANDED;
    }
  }

  // Checkable/checked?
  static dom::Element::AttrValuesArray strings[] = {
      nsGkAtoms::radio, nsGkAtoms::checkbox, nullptr};

  if (mContent->AsElement()->FindAttrValueIn(kNameSpaceID_None, nsGkAtoms::type,
                                             strings, eCaseMatters) >= 0) {
    // Checkable?
    state |= states::CHECKABLE;

    // Checked?
    if (mContent->AsElement()->AttrValueIs(kNameSpaceID_None,
                                           nsGkAtoms::checked, nsGkAtoms::_true,
                                           eCaseMatters)) {
      state |= states::CHECKED;
    }
  }

  // Combo box listitem
  bool isComboboxOption = (Role() == roles::COMBOBOX_OPTION);
  if (isComboboxOption) {
    // Is selected?
    bool isSelected = false;
    nsCOMPtr<nsIDOMXULSelectControlItemElement> item =
        Elm()->AsXULSelectControlItem();
    NS_ENSURE_TRUE(item, state);
    item->GetSelected(&isSelected);

    // Is collapsed?
    bool isCollapsed = false;
    LocalAccessible* parent = LocalParent();
    if (parent && parent->State() & states::INVISIBLE) isCollapsed = true;

    if (isSelected) {
      state |= states::SELECTED;

      // Selected and collapsed?
      if (isCollapsed) {
        // Set selected option offscreen/invisible according to combobox state
        LocalAccessible* grandParent = parent->LocalParent();
        if (!grandParent) return state;
        NS_ASSERTION(grandParent->IsCombobox(),
                     "grandparent of combobox listitem is not combobox");
        uint64_t grandParentState = grandParent->State();
        state &= ~(states::OFFSCREEN | states::INVISIBLE);
        state |= (grandParentState & states::OFFSCREEN) |
                 (grandParentState & states::INVISIBLE) |
                 (grandParentState & states::OPAQUE1);
      }  // isCollapsed
    }  // isSelected
  }  // ROLE_COMBOBOX_OPTION

  return state;
}

uint64_t XULMenuitemAccessible::NativeInteractiveState() const {
  if (NativelyUnavailable()) {
    // Note: keep in sinc with nsXULPopupManager::IsValidMenuItem() logic.
    auto* button = dom::XULButtonElement::FromNode(GetContent());
    bool skipNavigatingDisabledMenuItem = true;
    if (!button || !button->IsOnMenuBar()) {
      skipNavigatingDisabledMenuItem = LookAndFeel::GetInt(
          LookAndFeel::IntID::SkipNavigatingDisabledMenuItem);
    }

    if (skipNavigatingDisabledMenuItem) return states::UNAVAILABLE;

    return states::UNAVAILABLE | states::FOCUSABLE | states::SELECTABLE;
  }

  return states::FOCUSABLE | states::SELECTABLE;
}

ENameValueFlag XULMenuitemAccessible::NativeName(nsString& aName) const {
  mContent->AsElement()->GetAttr(nsGkAtoms::label, aName);
  return eNameOK;
}

void XULMenuitemAccessible::Description(nsString& aDescription) const {
  mContent->AsElement()->GetAttr(nsGkAtoms::description, aDescription);
}

KeyBinding XULMenuitemAccessible::AccessKey() const {
  // Return menu accesskey: N or Alt+F.
  static int32_t gMenuAccesskeyModifier =
      -1;  // magic value of -1 indicates unitialized state

  // We do not use nsCoreUtils::GetAccesskeyFor() because accesskeys for
  // menu are't registered by EventStateManager.
  nsAutoString accesskey;
  mContent->AsElement()->GetAttr(nsGkAtoms::accesskey, accesskey);
  if (accesskey.IsEmpty()) return KeyBinding();

  uint32_t modifierKey = 0;

  LocalAccessible* parentAcc = LocalParent();
  if (parentAcc) {
    if (parentAcc->NativeRole() == roles::MENUBAR) {
      // If top level menu item, add Alt+ or whatever modifier text to string
      // No need to cache pref service, this happens rarely
      if (gMenuAccesskeyModifier == -1) {
        // Need to initialize cached global accesskey pref
        gMenuAccesskeyModifier = Preferences::GetInt("ui.key.menuAccessKey", 0);
      }

      switch (gMenuAccesskeyModifier) {
        case dom::KeyboardEvent_Binding::DOM_VK_CONTROL:
          modifierKey = KeyBinding::kControl;
          break;
        case dom::KeyboardEvent_Binding::DOM_VK_ALT:
          modifierKey = KeyBinding::kAlt;
          break;
        case dom::KeyboardEvent_Binding::DOM_VK_META:
        case dom::KeyboardEvent_Binding::DOM_VK_WIN:
          modifierKey = KeyBinding::kMeta;
          break;
      }
    }
  }

  return KeyBinding(accesskey[0], modifierKey);
}

KeyBinding XULMenuitemAccessible::KeyboardShortcut() const {
  nsAutoString keyElmId;
  mContent->AsElement()->GetAttr(nsGkAtoms::key, keyElmId);
  if (keyElmId.IsEmpty()) return KeyBinding();

  dom::Element* keyElm = mContent->OwnerDoc()->GetElementById(keyElmId);
  if (!keyElm) return KeyBinding();

  uint32_t key = 0;

  nsAutoString keyStr;
  keyElm->GetAttr(nsGkAtoms::key, keyStr);
  if (keyStr.IsEmpty()) {
    nsAutoString keyCodeStr;
    keyElm->GetAttr(nsGkAtoms::keycode, keyCodeStr);
    nsresult errorCode;
    key = keyStr.ToInteger(&errorCode, /* aRadix = */ 10);
    if (NS_FAILED(errorCode)) {
      key = keyStr.ToInteger(&errorCode, /* aRadix = */ 16);
    }
  } else {
    key = keyStr[0];
  }

  nsAutoString modifiersStr;
  keyElm->GetAttr(nsGkAtoms::modifiers, modifiersStr);

  uint32_t modifierMask = 0;
  if (modifiersStr.Find(u"shift") != -1) modifierMask |= KeyBinding::kShift;
  if (modifiersStr.Find(u"alt") != -1) modifierMask |= KeyBinding::kAlt;
  if (modifiersStr.Find(u"meta") != -1) modifierMask |= KeyBinding::kMeta;
  if (modifiersStr.Find(u"control") != -1) modifierMask |= KeyBinding::kControl;
  if (modifiersStr.Find(u"accel") != -1) {
    modifierMask |= KeyBinding::AccelModifier();
  }

  return KeyBinding(key, modifierMask);
}

role XULMenuitemAccessible::NativeRole() const {
  nsCOMPtr<nsIDOMXULContainerElement> xulContainer = Elm()->AsXULContainer();
  if (xulContainer) return roles::PARENT_MENUITEM;

  LocalAccessible* widget = ContainerWidget();
  if (widget && widget->Role() == roles::COMBOBOX_LIST) {
    return roles::COMBOBOX_OPTION;
  }

  if (mContent->AsElement()->AttrValueIs(kNameSpaceID_None, nsGkAtoms::type,
                                         nsGkAtoms::radio, eCaseMatters)) {
    return roles::RADIO_MENU_ITEM;
  }

  if (mContent->AsElement()->AttrValueIs(kNameSpaceID_None, nsGkAtoms::type,
                                         nsGkAtoms::checkbox, eCaseMatters)) {
    return roles::CHECK_MENU_ITEM;
  }

  return roles::MENUITEM;
}

int32_t XULMenuitemAccessible::GetLevel(bool aFast) const {
  return nsAccUtils::GetLevelForXULContainerItem(mContent);
}

void XULMenuitemAccessible::ActionNameAt(uint8_t aIndex, nsAString& aName) {
  if (aIndex == eAction_Click) aName.AssignLiteral("click");
}

bool XULMenuitemAccessible::HasPrimaryAction() const { return true; }

////////////////////////////////////////////////////////////////////////////////
// XULMenuitemAccessible: Widgets

bool XULMenuitemAccessible::IsActiveWidget() const {
  // Parent menu item is a widget, it's active when its popup is open.
  // Typically the <menupopup> is included in the document markup, and
  // <menu> prepends content in front of it.
  nsIContent* menuPopupContent = mContent->GetLastChild();
  if (menuPopupContent) {
    nsMenuPopupFrame* menuPopupFrame =
        do_QueryFrame(menuPopupContent->GetPrimaryFrame());
    return menuPopupFrame && menuPopupFrame->IsOpen();
  }
  return false;
}

bool XULMenuitemAccessible::AreItemsOperable() const {
  // Parent menu item is a widget, its items are operable when its popup is
  // open.
  nsIContent* menuPopupContent = mContent->GetLastChild();
  if (menuPopupContent) {
    nsMenuPopupFrame* menuPopupFrame =
        do_QueryFrame(menuPopupContent->GetPrimaryFrame());
    return menuPopupFrame && menuPopupFrame->IsOpen();
  }
  return false;
}

LocalAccessible* XULMenuitemAccessible::ContainerWidget() const {
  if (auto* button = dom::XULButtonElement::FromNode(GetContent())) {
    if (auto* popup = button->GetMenuParent()) {
      // We use GetAccessibleOrContainer instead of just GetAccessible because
      // we strip menupopups from the tree for ATK.
      return mDoc->GetAccessibleOrContainer(popup);
    }
  }
  return nullptr;
}

////////////////////////////////////////////////////////////////////////////////
// XULMenuSeparatorAccessible
////////////////////////////////////////////////////////////////////////////////

XULMenuSeparatorAccessible::XULMenuSeparatorAccessible(nsIContent* aContent,
                                                       DocAccessible* aDoc)
    : XULMenuitemAccessible(aContent, aDoc) {}

uint64_t XULMenuSeparatorAccessible::NativeState() const {
  // Isn't focusable, but can be offscreen/invisible -- only copy those states
  return XULMenuitemAccessible::NativeState() &
         (states::OFFSCREEN | states::INVISIBLE);
}

ENameValueFlag XULMenuSeparatorAccessible::NativeName(nsString& aName) const {
  return eNameOK;
}

role XULMenuSeparatorAccessible::NativeRole() const { return roles::SEPARATOR; }

bool XULMenuSeparatorAccessible::HasPrimaryAction() const { return false; }

////////////////////////////////////////////////////////////////////////////////
// XULMenupopupAccessible
////////////////////////////////////////////////////////////////////////////////

XULMenupopupAccessible::XULMenupopupAccessible(nsIContent* aContent,
                                               DocAccessible* aDoc)
    : XULSelectControlAccessible(aContent, aDoc) {
  if (nsMenuPopupFrame* menuPopupFrame = do_QueryFrame(GetFrame())) {
    if (menuPopupFrame->GetPopupType() == widget::PopupType::Menu) {
      mType = eMenuPopupType;
    }
  }

  // May be the anonymous <menupopup> inside <menulist> (a combobox)
  auto* parent = mContent->GetParentElement();
  nsCOMPtr<nsIDOMXULSelectControlElement> selectControl =
      parent ? parent->AsXULSelectControl() : nullptr;
  if (selectControl) {
    mSelectControl = parent;
  } else {
    mSelectControl = nullptr;
    mGenericTypes &= ~eSelect;
  }
}

uint64_t XULMenupopupAccessible::NativeState() const {
  uint64_t state = LocalAccessible::NativeState();

#ifdef DEBUG
  // We are onscreen if our parent is active
  nsMenuPopupFrame* menuPopupFrame = do_QueryFrame(GetFrame());
  bool isActive = menuPopupFrame ? menuPopupFrame->IsOpen() : false;
  if (!isActive) {
    LocalAccessible* parent = LocalParent();
    if (parent) {
      nsIContent* parentContent = parent->GetContent();
      if (parentContent && parentContent->IsElement())
        isActive = parentContent->AsElement()->HasAttr(nsGkAtoms::open);
    }
  }

  NS_ASSERTION(isActive || (state & states::INVISIBLE),
               "XULMenupopup doesn't have INVISIBLE when it's inactive");
#endif

  if (state & states::INVISIBLE) {
    state |= states::OFFSCREEN;
  }

  return state;
}

ENameValueFlag XULMenupopupAccessible::NativeName(nsString& aName) const {
  nsIContent* content = mContent;
  while (content && aName.IsEmpty()) {
    if (content->IsElement()) {
      content->AsElement()->GetAttr(nsGkAtoms::label, aName);
    }
    content = content->GetFlattenedTreeParent();
  }

  return eNameOK;
}

role XULMenupopupAccessible::NativeRole() const {
  nsMenuPopupFrame* menuPopupFrame = do_QueryFrame(GetFrame());
  if (menuPopupFrame && menuPopupFrame->IsContextMenu()) {
    return roles::MENUPOPUP;
  }

  if (mParent) {
    if (mParent->IsCombobox()) {
      return roles::COMBOBOX_LIST;
    }
  }

  // If accessible is not bound to the tree (this happens while children are
  // cached) return general role.
  return roles::MENUPOPUP;
}

////////////////////////////////////////////////////////////////////////////////
// XULMenupopupAccessible: Widgets

bool XULMenupopupAccessible::IsWidget() const { return true; }

bool XULMenupopupAccessible::IsActiveWidget() const {
  // If menupopup is a widget (the case of context menus) then active when open.
  nsMenuPopupFrame* menuPopupFrame = do_QueryFrame(GetFrame());
  return menuPopupFrame && menuPopupFrame->IsOpen();
}

bool XULMenupopupAccessible::AreItemsOperable() const {
  nsMenuPopupFrame* menuPopupFrame = do_QueryFrame(GetFrame());
  return menuPopupFrame && menuPopupFrame->IsOpen();
}

LocalAccessible* XULMenupopupAccessible::ContainerWidget() const {
  DocAccessible* document = Document();

  nsMenuPopupFrame* menuPopupFrame = do_QueryFrame(GetFrame());
  MOZ_ASSERT(menuPopupFrame);
  if (!menuPopupFrame) {
    return nullptr;
  }

  auto* cur = dom::XULPopupElement::FromNode(GetContent());
  while (cur) {
    auto* menu = cur->GetContainingMenu();
    if (!menu) {
      // <panel> / <tooltip> / etc.
      return nullptr;
    }
    dom::XULMenuParentElement* parent = menu->GetMenuParent();
    if (!parent) {
      LocalAccessible* menuPopup = document->GetAccessible(cur);
      MOZ_ASSERT(menuPopup);
      return menuPopup ? menuPopup->LocalParent() : nullptr;
    }

    if (parent->IsMenuBar()) {
      return document->GetAccessible(parent);
    }

    cur = dom::XULPopupElement::FromNode(parent);
    MOZ_ASSERT(cur, "Should be a popup");
  }

  MOZ_ASSERT_UNREACHABLE("How did we get out of the loop without returning?");
  return nullptr;
}

////////////////////////////////////////////////////////////////////////////////
// XULMenubarAccessible
////////////////////////////////////////////////////////////////////////////////

XULMenubarAccessible::XULMenubarAccessible(nsIContent* aContent,
                                           DocAccessible* aDoc)
    : AccessibleWrap(aContent, aDoc) {}

ENameValueFlag XULMenubarAccessible::NativeName(nsString& aName) const {
  aName.AssignLiteral("Application");
  return eNameOK;
}

role XULMenubarAccessible::NativeRole() const { return roles::MENUBAR; }

////////////////////////////////////////////////////////////////////////////////
// XULMenubarAccessible: Widgets

bool XULMenubarAccessible::IsActiveWidget() const {
  auto* menuBar = dom::XULMenuBarElement::FromNode(GetContent());
  return menuBar && menuBar->IsActive();
}

bool XULMenubarAccessible::AreItemsOperable() const { return true; }

LocalAccessible* XULMenubarAccessible::CurrentItem() const {
  auto* content = dom::XULMenuParentElement::FromNode(GetContent());
  MOZ_ASSERT(content);
  if (!content || !content->GetActiveMenuChild()) {
    return nullptr;
  }
  return mDoc->GetAccessible(content->GetActiveMenuChild());
}

void XULMenubarAccessible::SetCurrentItem(const LocalAccessible* aItem) {
  NS_ERROR("XULMenubarAccessible::SetCurrentItem not implemented");
}
