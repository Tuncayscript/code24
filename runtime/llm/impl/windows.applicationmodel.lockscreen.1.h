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
#ifndef LLM_OS_ApplicationModel_LockScreen_1_H
#define LLM_OS_ApplicationModel_LockScreen_1_H
#include "llm/impl/Windows.ApplicationModel.LockScreen.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::LockScreen
{
    struct __declspec(empty_bases) ILockApplicationHost :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILockApplicationHost>
    {
        ILockApplicationHost(std::nullptr_t = nullptr) noexcept {}
        ILockApplicationHost(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILockApplicationHostStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILockApplicationHostStatics>
    {
        ILockApplicationHostStatics(std::nullptr_t = nullptr) noexcept {}
        ILockApplicationHostStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILockScreenBadge :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILockScreenBadge>
    {
        ILockScreenBadge(std::nullptr_t = nullptr) noexcept {}
        ILockScreenBadge(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILockScreenInfo :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILockScreenInfo>
    {
        ILockScreenInfo(std::nullptr_t = nullptr) noexcept {}
        ILockScreenInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILockScreenUnlockingDeferral :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILockScreenUnlockingDeferral>
    {
        ILockScreenUnlockingDeferral(std::nullptr_t = nullptr) noexcept {}
        ILockScreenUnlockingDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILockScreenUnlockingEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILockScreenUnlockingEventArgs>
    {
        ILockScreenUnlockingEventArgs(std::nullptr_t = nullptr) noexcept {}
        ILockScreenUnlockingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
