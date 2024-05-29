/*
 * Copyright (c) 2024, NeXTech Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * Contact with ITGSS, 640 N McCarthy Blvd, in the
 * city of Milpitas, zip code 95035, state of California.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

#pragma once
#ifndef LLM_OS_ApplicationModel_LockScreen_2_H
#define LLM_OS_ApplicationModel_LockScreen_2_H
#include "llm/impl/Windows.ApplicationModel.LockScreen.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::LockScreen
{
    struct __declspec(empty_bases) LockApplicationHost : llm::OS::ApplicationModel::LockScreen::ILockApplicationHost
    {
        LockApplicationHost(std::nullptr_t) noexcept {}
        LockApplicationHost(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::LockScreen::ILockApplicationHost(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
    };
    struct __declspec(empty_bases) LockScreenBadge : llm::OS::ApplicationModel::LockScreen::ILockScreenBadge
    {
        LockScreenBadge(std::nullptr_t) noexcept {}
        LockScreenBadge(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::LockScreen::ILockScreenBadge(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LockScreenInfo : llm::OS::ApplicationModel::LockScreen::ILockScreenInfo
    {
        LockScreenInfo(std::nullptr_t) noexcept {}
        LockScreenInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::LockScreen::ILockScreenInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LockScreenUnlockingDeferral : llm::OS::ApplicationModel::LockScreen::ILockScreenUnlockingDeferral
    {
        LockScreenUnlockingDeferral(std::nullptr_t) noexcept {}
        LockScreenUnlockingDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::LockScreen::ILockScreenUnlockingDeferral(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LockScreenUnlockingEventArgs : llm::OS::ApplicationModel::LockScreen::ILockScreenUnlockingEventArgs
    {
        LockScreenUnlockingEventArgs(std::nullptr_t) noexcept {}
        LockScreenUnlockingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::LockScreen::ILockScreenUnlockingEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
