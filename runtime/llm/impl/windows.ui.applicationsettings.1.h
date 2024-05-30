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
#ifndef LLM_OS_UI_ApplicationSettings_1_H
#define LLM_OS_UI_ApplicationSettings_1_H
#include "llm/impl/Windows.UI.ApplicationSettings.0.h"
LLM_EXPORT namespace llm:OS::UI::ApplicationSettings
{
    struct __declspec(empty_bases) IAccountsSettingsPane :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAccountsSettingsPane>
    {
        IAccountsSettingsPane(std::nullptr_t = nullptr) noexcept {}
        IAccountsSettingsPane(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAccountsSettingsPaneCommandsRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAccountsSettingsPaneCommandsRequestedEventArgs>
    {
        IAccountsSettingsPaneCommandsRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAccountsSettingsPaneCommandsRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAccountsSettingsPaneCommandsRequestedEventArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAccountsSettingsPaneCommandsRequestedEventArgs2>
    {
        IAccountsSettingsPaneCommandsRequestedEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IAccountsSettingsPaneCommandsRequestedEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAccountsSettingsPaneEventDeferral :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAccountsSettingsPaneEventDeferral>
    {
        IAccountsSettingsPaneEventDeferral(std::nullptr_t = nullptr) noexcept {}
        IAccountsSettingsPaneEventDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAccountsSettingsPaneStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAccountsSettingsPaneStatics>
    {
        IAccountsSettingsPaneStatics(std::nullptr_t = nullptr) noexcept {}
        IAccountsSettingsPaneStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAccountsSettingsPaneStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAccountsSettingsPaneStatics2>,
        impl::require<llm:OS::UI::ApplicationSettings::IAccountsSettingsPaneStatics2, llm:OS::UI::ApplicationSettings::IAccountsSettingsPaneStatics>
    {
        IAccountsSettingsPaneStatics2(std::nullptr_t = nullptr) noexcept {}
        IAccountsSettingsPaneStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAccountsSettingsPaneStatics3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAccountsSettingsPaneStatics3>
    {
        IAccountsSettingsPaneStatics3(std::nullptr_t = nullptr) noexcept {}
        IAccountsSettingsPaneStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICredentialCommand :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICredentialCommand>
    {
        ICredentialCommand(std::nullptr_t = nullptr) noexcept {}
        ICredentialCommand(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICredentialCommandFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICredentialCommandFactory>
    {
        ICredentialCommandFactory(std::nullptr_t = nullptr) noexcept {}
        ICredentialCommandFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISettingsCommandFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISettingsCommandFactory>
    {
        ISettingsCommandFactory(std::nullptr_t = nullptr) noexcept {}
        ISettingsCommandFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISettingsCommandStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISettingsCommandStatics>
    {
        ISettingsCommandStatics(std::nullptr_t = nullptr) noexcept {}
        ISettingsCommandStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISettingsPane :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISettingsPane>
    {
        ISettingsPane(std::nullptr_t = nullptr) noexcept {}
        ISettingsPane(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISettingsPaneCommandsRequest :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISettingsPaneCommandsRequest>
    {
        ISettingsPaneCommandsRequest(std::nullptr_t = nullptr) noexcept {}
        ISettingsPaneCommandsRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISettingsPaneCommandsRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISettingsPaneCommandsRequestedEventArgs>
    {
        ISettingsPaneCommandsRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ISettingsPaneCommandsRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISettingsPaneStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISettingsPaneStatics>
    {
        ISettingsPaneStatics(std::nullptr_t = nullptr) noexcept {}
        ISettingsPaneStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountCommand :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountCommand>
    {
        IWebAccountCommand(std::nullptr_t = nullptr) noexcept {}
        IWebAccountCommand(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountCommandFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountCommandFactory>
    {
        IWebAccountCommandFactory(std::nullptr_t = nullptr) noexcept {}
        IWebAccountCommandFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountInvokedArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountInvokedArgs>
    {
        IWebAccountInvokedArgs(std::nullptr_t = nullptr) noexcept {}
        IWebAccountInvokedArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountProviderCommand :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountProviderCommand>
    {
        IWebAccountProviderCommand(std::nullptr_t = nullptr) noexcept {}
        IWebAccountProviderCommand(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountProviderCommandFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountProviderCommandFactory>
    {
        IWebAccountProviderCommandFactory(std::nullptr_t = nullptr) noexcept {}
        IWebAccountProviderCommandFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
