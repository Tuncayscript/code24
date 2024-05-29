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
#ifndef LLM_OS_ApplicationModel_AppExtensions_2_H
#define LLM_OS_ApplicationModel_AppExtensions_2_H
#include "llm/impl/Windows.ApplicationModel.AppExtensions.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::AppExtensions
{
    struct __declspec(empty_bases) AppExtension : llm::OS::ApplicationModel::AppExtensions::IAppExtension,
        impl::require<AppExtension, llm::OS::ApplicationModel::AppExtensions::IAppExtension2>
    {
        AppExtension(std::nullptr_t) noexcept {}
        AppExtension(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::AppExtensions::IAppExtension(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppExtensionCatalog : llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog
    {
        AppExtensionCatalog(std::nullptr_t) noexcept {}
        AppExtensionCatalog(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog(ptr, take_ownership_from_abi) {}
        static auto Open(param::hstring const& appExtensionName);
    };
    struct __declspec(empty_bases) AppExtensionPackageInstalledEventArgs : llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageInstalledEventArgs
    {
        AppExtensionPackageInstalledEventArgs(std::nullptr_t) noexcept {}
        AppExtensionPackageInstalledEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageInstalledEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppExtensionPackageStatusChangedEventArgs : llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageStatusChangedEventArgs
    {
        AppExtensionPackageStatusChangedEventArgs(std::nullptr_t) noexcept {}
        AppExtensionPackageStatusChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageStatusChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppExtensionPackageUninstallingEventArgs : llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUninstallingEventArgs
    {
        AppExtensionPackageUninstallingEventArgs(std::nullptr_t) noexcept {}
        AppExtensionPackageUninstallingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUninstallingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppExtensionPackageUpdatedEventArgs : llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatedEventArgs
    {
        AppExtensionPackageUpdatedEventArgs(std::nullptr_t) noexcept {}
        AppExtensionPackageUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppExtensionPackageUpdatingEventArgs : llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatingEventArgs
    {
        AppExtensionPackageUpdatingEventArgs(std::nullptr_t) noexcept {}
        AppExtensionPackageUpdatingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatingEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
