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
#ifndef LLM_OS_ApplicationModel_AppExtensions_1_H
#define LLM_OS_ApplicationModel_AppExtensions_1_H
#include "llm/impl/Windows.ApplicationModel.AppExtensions.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::AppExtensions
{
    struct __declspec(empty_bases) IAppExtension :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppExtension>
    {
        IAppExtension(std::nullptr_t = nullptr) noexcept {}
        IAppExtension(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppExtension2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppExtension2>
    {
        IAppExtension2(std::nullptr_t = nullptr) noexcept {}
        IAppExtension2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppExtensionCatalog :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppExtensionCatalog>
    {
        IAppExtensionCatalog(std::nullptr_t = nullptr) noexcept {}
        IAppExtensionCatalog(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppExtensionCatalogStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppExtensionCatalogStatics>
    {
        IAppExtensionCatalogStatics(std::nullptr_t = nullptr) noexcept {}
        IAppExtensionCatalogStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppExtensionPackageInstalledEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppExtensionPackageInstalledEventArgs>
    {
        IAppExtensionPackageInstalledEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppExtensionPackageInstalledEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppExtensionPackageStatusChangedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppExtensionPackageStatusChangedEventArgs>
    {
        IAppExtensionPackageStatusChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppExtensionPackageStatusChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppExtensionPackageUninstallingEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppExtensionPackageUninstallingEventArgs>
    {
        IAppExtensionPackageUninstallingEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppExtensionPackageUninstallingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppExtensionPackageUpdatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppExtensionPackageUpdatedEventArgs>
    {
        IAppExtensionPackageUpdatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppExtensionPackageUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppExtensionPackageUpdatingEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppExtensionPackageUpdatingEventArgs>
    {
        IAppExtensionPackageUpdatingEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppExtensionPackageUpdatingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
