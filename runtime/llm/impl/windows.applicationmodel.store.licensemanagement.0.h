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
#ifndef LLM_OS_ApplicationModel_Store_LicenseManagement_0_H
#define LLM_OS_ApplicationModel_Store_LicenseManagement_0_H
LLM_EXPORT namespace llm::OS::Foundation
{
    struct HResult;
    struct IAsyncAction;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
}
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IIterable;
    template <typename K, typename V> struct __declspec(empty_bases) IMapView;
}
LLM_EXPORT namespace llm::OS::Storage::Streams
{
    struct IBuffer;
}
LLM_EXPORT namespace llm::OS::ApplicationModel::Store::LicenseManagement
{
    enum class LicenseRefreshOption : int32_t
    {
        RunningLicenses = 0,
        AllLicenses = 1,
    };
    struct ILicenseManagerStatics;
    struct ILicenseManagerStatics2;
    struct ILicenseSatisfactionInfo;
    struct ILicenseSatisfactionResult;
    struct LicenseManager;
    struct LicenseSatisfactionInfo;
    struct LicenseSatisfactionResult;
}
namespace llm::impl
{
    template <> struct category<llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseManagerStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseManagerStatics2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionResult>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Store::LicenseManagement::LicenseManager>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionInfo>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionResult>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Store::LicenseManagement::LicenseRefreshOption>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Store::LicenseManagement::LicenseManager> = L"Windows.ApplicationModel.Store.LicenseManagement.LicenseManager";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionInfo> = L"Windows.ApplicationModel.Store.LicenseManagement.LicenseSatisfactionInfo";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionResult> = L"Windows.ApplicationModel.Store.LicenseManagement.LicenseSatisfactionResult";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Store::LicenseManagement::LicenseRefreshOption> = L"Windows.ApplicationModel.Store.LicenseManagement.LicenseRefreshOption";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseManagerStatics> = L"Windows.ApplicationModel.Store.LicenseManagement.ILicenseManagerStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseManagerStatics2> = L"Windows.ApplicationModel.Store.LicenseManagement.ILicenseManagerStatics2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo> = L"Windows.ApplicationModel.Store.LicenseManagement.ILicenseSatisfactionInfo";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionResult> = L"Windows.ApplicationModel.Store.LicenseManagement.ILicenseSatisfactionResult";
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseManagerStatics>{ 0xB5AC3AE0,0xDA47,0x4F20,{ 0x9A,0x23,0x09,0x18,0x2C,0x94,0x76,0xFF } }; // B5AC3AE0-DA47-4F20-9A23-09182C9476FF
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseManagerStatics2>{ 0xAB2EC47B,0x1F79,0x4480,{ 0xB8,0x7E,0x2C,0x49,0x9E,0x60,0x1B,0xA3 } }; // AB2EC47B-1F79-4480-B87E-2C499E601BA3
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo>{ 0x3CCBB08F,0xDB31,0x48D5,{ 0x83,0x84,0xFA,0x17,0xC8,0x14,0x74,0xE2 } }; // 3CCBB08F-DB31-48D5-8384-FA17C81474E2
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionResult>{ 0x3C674F73,0x3C87,0x4EE1,{ 0x82,0x01,0xF4,0x28,0x35,0x9B,0xD3,0xAF } }; // 3C674F73-3C87-4EE1-8201-F428359BD3AF
    template <> struct default_interface<llm::OS::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionInfo>{ using type = llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo; };
    template <> struct default_interface<llm::OS::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionResult>{ using type = llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionResult; };
    template <> struct abi<llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall AddLicenseAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetSatisfactionInfosAsync(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseManagerStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RefreshLicensesAsync(int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SatisfiedByDevice(bool*) noexcept = 0;
            virtual int32_t __stdcall get_SatisfiedByOpenLicense(bool*) noexcept = 0;
            virtual int32_t __stdcall get_SatisfiedByTrial(bool*) noexcept = 0;
            virtual int32_t __stdcall get_SatisfiedByPass(bool*) noexcept = 0;
            virtual int32_t __stdcall get_SatisfiedByInstallMedia(bool*) noexcept = 0;
            virtual int32_t __stdcall get_SatisfiedBySignedInUser(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsSatisfied(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_LicenseSatisfactionInfos(void**) noexcept = 0;
            virtual int32_t __stdcall get_ExtendedError(llm::hresult*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Store_LicenseManagement_ILicenseManagerStatics
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) AddLicenseAsync(llm::OS::Storage::Streams::IBuffer const& license) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionResult>) GetSatisfactionInfosAsync(param::async_iterable<hstring> const& contentIds, param::async_iterable<hstring> const& keyIds) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseManagerStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Store_LicenseManagement_ILicenseManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Store_LicenseManagement_ILicenseManagerStatics2
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) RefreshLicensesAsync(llm::OS::ApplicationModel::Store::LicenseManagement::LicenseRefreshOption const& refreshOption) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseManagerStatics2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Store_LicenseManagement_ILicenseManagerStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Store_LicenseManagement_ILicenseSatisfactionInfo
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) SatisfiedByDevice() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) SatisfiedByOpenLicense() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) SatisfiedByTrial() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) SatisfiedByPass() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) SatisfiedByInstallMedia() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) SatisfiedBySignedInUser() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsSatisfied() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Store_LicenseManagement_ILicenseSatisfactionInfo<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Store_LicenseManagement_ILicenseSatisfactionResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionInfo>) LicenseSatisfactionInfos() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) ExtendedError() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionResult>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Store_LicenseManagement_ILicenseSatisfactionResult<D>;
    };
}
#endif
