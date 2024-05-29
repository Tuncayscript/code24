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
#ifndef LLM_OS_ApplicationModel_CommunicationBlocking_0_H
#define LLM_OS_ApplicationModel_CommunicationBlocking_0_H
LLM_EXPORT namespace llm::OS::Foundation
{
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
}
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IIterable;
}
LLM_EXPORT namespace llm::OS::ApplicationModel::CommunicationBlocking
{
    struct ICommunicationBlockingAccessManagerStatics;
    struct ICommunicationBlockingAppManagerStatics;
    struct ICommunicationBlockingAppManagerStatics2;
    struct CommunicationBlockingAccessManager;
    struct CommunicationBlockingAppManager;
}
namespace llm::impl
{
    template <> struct category<llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAccessManagerStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::CommunicationBlocking::CommunicationBlockingAccessManager>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::CommunicationBlocking::CommunicationBlockingAppManager>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::CommunicationBlocking::CommunicationBlockingAccessManager> = L"Windows.ApplicationModel.CommunicationBlocking.CommunicationBlockingAccessManager";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::CommunicationBlocking::CommunicationBlockingAppManager> = L"Windows.ApplicationModel.CommunicationBlocking.CommunicationBlockingAppManager";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAccessManagerStatics> = L"Windows.ApplicationModel.CommunicationBlocking.ICommunicationBlockingAccessManagerStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics> = L"Windows.ApplicationModel.CommunicationBlocking.ICommunicationBlockingAppManagerStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics2> = L"Windows.ApplicationModel.CommunicationBlocking.ICommunicationBlockingAppManagerStatics2";
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAccessManagerStatics>{ 0x1C969998,0x9D2A,0x5DB7,{ 0xED,0xD5,0x0C,0xE4,0x07,0xFC,0x25,0x95 } }; // 1C969998-9D2A-5DB7-EDD5-0CE407FC2595
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics>{ 0x77DB58EC,0x14A6,0x4BAA,{ 0x94,0x2A,0x6A,0x67,0x3D,0x99,0x9B,0xF2 } }; // 77DB58EC-14A6-4BAA-942A-6A673D999BF2
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics2>{ 0x14A68EDD,0xED88,0x457A,{ 0xA3,0x64,0xA3,0x63,0x4D,0x6F,0x16,0x6D } }; // 14A68EDD-ED88-457A-A364-A3634D6F166D
    template <> struct abi<llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAccessManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsBlockingActive(bool*) noexcept = 0;
            virtual int32_t __stdcall IsBlockedNumberAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall ShowBlockNumbersUI(void*, bool*) noexcept = 0;
            virtual int32_t __stdcall ShowUnblockNumbersUI(void*, bool*) noexcept = 0;
            virtual int32_t __stdcall ShowBlockedCallsUI() noexcept = 0;
            virtual int32_t __stdcall ShowBlockedMessagesUI() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsCurrentAppActiveBlockingApp(bool*) noexcept = 0;
            virtual int32_t __stdcall ShowCommunicationBlockingSettingsUI() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RequestSetAsActiveBlockingAppAsync(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_CommunicationBlocking_ICommunicationBlockingAccessManagerStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsBlockingActive() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) IsBlockedNumberAsync(param::hstring const& number) const;
        LLM_IMPL_AUTO(bool) ShowBlockNumbersUI(param::iterable<hstring> const& phoneNumbers) const;
        LLM_IMPL_AUTO(bool) ShowUnblockNumbersUI(param::iterable<hstring> const& phoneNumbers) const;
        LLM_IMPL_AUTO(void) ShowBlockedCallsUI() const;
        LLM_IMPL_AUTO(void) ShowBlockedMessagesUI() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAccessManagerStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_CommunicationBlocking_ICommunicationBlockingAccessManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_CommunicationBlocking_ICommunicationBlockingAppManagerStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsCurrentAppActiveBlockingApp() const;
        LLM_IMPL_AUTO(void) ShowCommunicationBlockingSettingsUI() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_CommunicationBlocking_ICommunicationBlockingAppManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_CommunicationBlocking_ICommunicationBlockingAppManagerStatics2
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) RequestSetAsActiveBlockingAppAsync() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_CommunicationBlocking_ICommunicationBlockingAppManagerStatics2<D>;
    };
}
#endif
