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
#ifndef LLM_OS_Management_0_H
#define LLM_OS_Management_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    struct HResult;
    struct IAsyncAction;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IIterable;
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm:OS::Management
{
    enum class MdmAlertDataType : int32_t
    {
        String = 0,
        Base64 = 1,
        Boolean = 2,
        Integer = 3,
    };
    enum class MdmAlertMark : int32_t
    {
        None = 0,
        Fatal = 1,
        Critical = 2,
        Warning = 3,
        Informational = 4,
    };
    enum class MdmSessionState : int32_t
    {
        NotStarted = 0,
        Starting = 1,
        Connecting = 2,
        Communicating = 3,
        AlertStatusAvailable = 4,
        Retrying = 5,
        Completed = 6,
    };
    struct IMdmAlert;
    struct IMdmSession;
    struct IMdmSessionManagerStatics;
    struct MdmAlert;
    struct MdmSession;
    struct MdmSessionManager;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Management::IMdmAlert>{ using type = interface_category; };
    template <> struct category<llm:OS::Management::IMdmSession>{ using type = interface_category; };
    template <> struct category<llm:OS::Management::IMdmSessionManagerStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Management::MdmAlert>{ using type = class_category; };
    template <> struct category<llm:OS::Management::MdmSession>{ using type = class_category; };
    template <> struct category<llm:OS::Management::MdmSessionManager>{ using type = class_category; };
    template <> struct category<llm:OS::Management::MdmAlertDataType>{ using type = enum_category; };
    template <> struct category<llm:OS::Management::MdmAlertMark>{ using type = enum_category; };
    template <> struct category<llm:OS::Management::MdmSessionState>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::Management::MdmAlert> = L"Windows.Management.MdmAlert";
    template <> inline constexpr auto& name_v<llm:OS::Management::MdmSession> = L"Windows.Management.MdmSession";
    template <> inline constexpr auto& name_v<llm:OS::Management::MdmSessionManager> = L"Windows.Management.MdmSessionManager";
    template <> inline constexpr auto& name_v<llm:OS::Management::MdmAlertDataType> = L"Windows.Management.MdmAlertDataType";
    template <> inline constexpr auto& name_v<llm:OS::Management::MdmAlertMark> = L"Windows.Management.MdmAlertMark";
    template <> inline constexpr auto& name_v<llm:OS::Management::MdmSessionState> = L"Windows.Management.MdmSessionState";
    template <> inline constexpr auto& name_v<llm:OS::Management::IMdmAlert> = L"Windows.Management.IMdmAlert";
    template <> inline constexpr auto& name_v<llm:OS::Management::IMdmSession> = L"Windows.Management.IMdmSession";
    template <> inline constexpr auto& name_v<llm:OS::Management::IMdmSessionManagerStatics> = L"Windows.Management.IMdmSessionManagerStatics";
    template <> inline constexpr guid guid_v<llm:OS::Management::IMdmAlert>{ 0xB0FBC327,0x28C1,0x4B52,{ 0xA5,0x48,0xC5,0x80,0x7C,0xAF,0x70,0xB6 } }; // B0FBC327-28C1-4B52-A548-C5807CAF70B6
    template <> inline constexpr guid guid_v<llm:OS::Management::IMdmSession>{ 0xFE89314C,0x8F64,0x4797,{ 0xA9,0xD7,0x9D,0x88,0xF8,0x6A,0xE1,0x66 } }; // FE89314C-8F64-4797-A9D7-9D88F86AE166
    template <> inline constexpr guid guid_v<llm:OS::Management::IMdmSessionManagerStatics>{ 0xCF4AD959,0xF745,0x4B79,{ 0x9B,0x5C,0xDE,0x0B,0xF8,0xEF,0xE4,0x4B } }; // CF4AD959-F745-4B79-9B5C-DE0BF8EFE44B
    template <> struct default_interface<llm:OS::Management::MdmAlert>{ using type = llm:OS::Management::IMdmAlert; };
    template <> struct default_interface<llm:OS::Management::MdmSession>{ using type = llm:OS::Management::IMdmSession; };
    template <> struct abi<llm:OS::Management::IMdmAlert>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Data(void**) noexcept = 0;
            virtual int32_t __stdcall put_Data(void*) noexcept = 0;
            virtual int32_t __stdcall get_Format(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Format(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_Mark(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Mark(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_Source(void**) noexcept = 0;
            virtual int32_t __stdcall put_Source(void*) noexcept = 0;
            virtual int32_t __stdcall get_Status(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Target(void**) noexcept = 0;
            virtual int32_t __stdcall put_Target(void*) noexcept = 0;
            virtual int32_t __stdcall get_Type(void**) noexcept = 0;
            virtual int32_t __stdcall put_Type(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Management::IMdmSession>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Alerts(void**) noexcept = 0;
            virtual int32_t __stdcall get_ExtendedError(llm::hresult*) noexcept = 0;
            virtual int32_t __stdcall get_Id(void**) noexcept = 0;
            virtual int32_t __stdcall get_State(int32_t*) noexcept = 0;
            virtual int32_t __stdcall AttachAsync(void**) noexcept = 0;
            virtual int32_t __stdcall Delete() noexcept = 0;
            virtual int32_t __stdcall StartAsync(void**) noexcept = 0;
            virtual int32_t __stdcall StartWithAlertsAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Management::IMdmSessionManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SessionIds(void**) noexcept = 0;
            virtual int32_t __stdcall TryCreateSession(void**) noexcept = 0;
            virtual int32_t __stdcall DeleteSessionById(void*) noexcept = 0;
            virtual int32_t __stdcall GetSessionById(void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Management_IMdmAlert
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Data() const;
        LLM_IMPL_AUTO(void) Data(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Management::MdmAlertDataType) Format() const;
        LLM_IMPL_AUTO(void) Format(llm:OS::Management::MdmAlertDataType const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Management::MdmAlertMark) Mark() const;
        LLM_IMPL_AUTO(void) Mark(llm:OS::Management::MdmAlertMark const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Source() const;
        LLM_IMPL_AUTO(void) Source(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) Status() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Target() const;
        LLM_IMPL_AUTO(void) Target(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Type() const;
        LLM_IMPL_AUTO(void) Type(param::hstring const& value) const;
    };
    template <> struct consume<llm:OS::Management::IMdmAlert>
    {
        template <typename D> using type = consume_Windows_Management_IMdmAlert<D>;
    };
    template <typename D>
    struct consume_Windows_Management_IMdmSession
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Management::MdmAlert>) Alerts() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) ExtendedError() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Id() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Management::MdmSessionState) State() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) AttachAsync() const;
        LLM_IMPL_AUTO(void) Delete() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) StartAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) StartAsync(param::async_iterable<llm:OS::Management::MdmAlert> const& alerts) const;
    };
    template <> struct consume<llm:OS::Management::IMdmSession>
    {
        template <typename D> using type = consume_Windows_Management_IMdmSession<D>;
    };
    template <typename D>
    struct consume_Windows_Management_IMdmSessionManagerStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<hstring>) SessionIds() const;
        LLM_IMPL_AUTO(llm:OS::Management::MdmSession) TryCreateSession() const;
        LLM_IMPL_AUTO(void) DeleteSessionById(param::hstring const& sessionId) const;
        LLM_IMPL_AUTO(llm:OS::Management::MdmSession) GetSessionById(param::hstring const& sessionId) const;
    };
    template <> struct consume<llm:OS::Management::IMdmSessionManagerStatics>
    {
        template <typename D> using type = consume_Windows_Management_IMdmSessionManagerStatics<D>;
    };
}
#endif
