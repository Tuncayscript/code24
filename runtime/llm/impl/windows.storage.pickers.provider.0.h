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
#ifndef LLM_OS_Storage_Pickers_Provider_0_H
#define LLM_OS_Storage_Pickers_Provider_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    struct EventRegistrationToken;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm:OS::Storage
{
    struct IStorageFile;
}
LLM_EXPORT namespace llm:OS::Storage::Pickers::Provider
{
    enum class AddFileResult : int32_t
    {
        Added = 0,
        AlreadyAdded = 1,
        NotAllowed = 2,
        Unavailable = 3,
    };
    enum class FileSelectionMode : int32_t
    {
        Single = 0,
        Multiple = 1,
    };
    enum class SetFileNameResult : int32_t
    {
        Succeeded = 0,
        NotAllowed = 1,
        Unavailable = 2,
    };
    struct IFileOpenPickerUI;
    struct IFileRemovedEventArgs;
    struct IFileSavePickerUI;
    struct IPickerClosingDeferral;
    struct IPickerClosingEventArgs;
    struct IPickerClosingOperation;
    struct ITargetFileRequest;
    struct ITargetFileRequestDeferral;
    struct ITargetFileRequestedEventArgs;
    struct FileOpenPickerUI;
    struct FileRemovedEventArgs;
    struct FileSavePickerUI;
    struct PickerClosingDeferral;
    struct PickerClosingEventArgs;
    struct PickerClosingOperation;
    struct TargetFileRequest;
    struct TargetFileRequestDeferral;
    struct TargetFileRequestedEventArgs;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Storage::Pickers::Provider::IFileOpenPickerUI>{ using type = interface_category; };
    template <> struct category<llm:OS::Storage::Pickers::Provider::IFileRemovedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Storage::Pickers::Provider::IFileSavePickerUI>{ using type = interface_category; };
    template <> struct category<llm:OS::Storage::Pickers::Provider::IPickerClosingDeferral>{ using type = interface_category; };
    template <> struct category<llm:OS::Storage::Pickers::Provider::IPickerClosingEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Storage::Pickers::Provider::IPickerClosingOperation>{ using type = interface_category; };
    template <> struct category<llm:OS::Storage::Pickers::Provider::ITargetFileRequest>{ using type = interface_category; };
    template <> struct category<llm:OS::Storage::Pickers::Provider::ITargetFileRequestDeferral>{ using type = interface_category; };
    template <> struct category<llm:OS::Storage::Pickers::Provider::ITargetFileRequestedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Storage::Pickers::Provider::FileOpenPickerUI>{ using type = class_category; };
    template <> struct category<llm:OS::Storage::Pickers::Provider::FileRemovedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Storage::Pickers::Provider::FileSavePickerUI>{ using type = class_category; };
    template <> struct category<llm:OS::Storage::Pickers::Provider::PickerClosingDeferral>{ using type = class_category; };
    template <> struct category<llm:OS::Storage::Pickers::Provider::PickerClosingEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Storage::Pickers::Provider::PickerClosingOperation>{ using type = class_category; };
    template <> struct category<llm:OS::Storage::Pickers::Provider::TargetFileRequest>{ using type = class_category; };
    template <> struct category<llm:OS::Storage::Pickers::Provider::TargetFileRequestDeferral>{ using type = class_category; };
    template <> struct category<llm:OS::Storage::Pickers::Provider::TargetFileRequestedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Storage::Pickers::Provider::AddFileResult>{ using type = enum_category; };
    template <> struct category<llm:OS::Storage::Pickers::Provider::FileSelectionMode>{ using type = enum_category; };
    template <> struct category<llm:OS::Storage::Pickers::Provider::SetFileNameResult>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::Storage::Pickers::Provider::FileOpenPickerUI> = L"Windows.Storage.Pickers.Provider.FileOpenPickerUI";
    template <> inline constexpr auto& name_v<llm:OS::Storage::Pickers::Provider::FileRemovedEventArgs> = L"Windows.Storage.Pickers.Provider.FileRemovedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Storage::Pickers::Provider::FileSavePickerUI> = L"Windows.Storage.Pickers.Provider.FileSavePickerUI";
    template <> inline constexpr auto& name_v<llm:OS::Storage::Pickers::Provider::PickerClosingDeferral> = L"Windows.Storage.Pickers.Provider.PickerClosingDeferral";
    template <> inline constexpr auto& name_v<llm:OS::Storage::Pickers::Provider::PickerClosingEventArgs> = L"Windows.Storage.Pickers.Provider.PickerClosingEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Storage::Pickers::Provider::PickerClosingOperation> = L"Windows.Storage.Pickers.Provider.PickerClosingOperation";
    template <> inline constexpr auto& name_v<llm:OS::Storage::Pickers::Provider::TargetFileRequest> = L"Windows.Storage.Pickers.Provider.TargetFileRequest";
    template <> inline constexpr auto& name_v<llm:OS::Storage::Pickers::Provider::TargetFileRequestDeferral> = L"Windows.Storage.Pickers.Provider.TargetFileRequestDeferral";
    template <> inline constexpr auto& name_v<llm:OS::Storage::Pickers::Provider::TargetFileRequestedEventArgs> = L"Windows.Storage.Pickers.Provider.TargetFileRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Storage::Pickers::Provider::AddFileResult> = L"Windows.Storage.Pickers.Provider.AddFileResult";
    template <> inline constexpr auto& name_v<llm:OS::Storage::Pickers::Provider::FileSelectionMode> = L"Windows.Storage.Pickers.Provider.FileSelectionMode";
    template <> inline constexpr auto& name_v<llm:OS::Storage::Pickers::Provider::SetFileNameResult> = L"Windows.Storage.Pickers.Provider.SetFileNameResult";
    template <> inline constexpr auto& name_v<llm:OS::Storage::Pickers::Provider::IFileOpenPickerUI> = L"Windows.Storage.Pickers.Provider.IFileOpenPickerUI";
    template <> inline constexpr auto& name_v<llm:OS::Storage::Pickers::Provider::IFileRemovedEventArgs> = L"Windows.Storage.Pickers.Provider.IFileRemovedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Storage::Pickers::Provider::IFileSavePickerUI> = L"Windows.Storage.Pickers.Provider.IFileSavePickerUI";
    template <> inline constexpr auto& name_v<llm:OS::Storage::Pickers::Provider::IPickerClosingDeferral> = L"Windows.Storage.Pickers.Provider.IPickerClosingDeferral";
    template <> inline constexpr auto& name_v<llm:OS::Storage::Pickers::Provider::IPickerClosingEventArgs> = L"Windows.Storage.Pickers.Provider.IPickerClosingEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Storage::Pickers::Provider::IPickerClosingOperation> = L"Windows.Storage.Pickers.Provider.IPickerClosingOperation";
    template <> inline constexpr auto& name_v<llm:OS::Storage::Pickers::Provider::ITargetFileRequest> = L"Windows.Storage.Pickers.Provider.ITargetFileRequest";
    template <> inline constexpr auto& name_v<llm:OS::Storage::Pickers::Provider::ITargetFileRequestDeferral> = L"Windows.Storage.Pickers.Provider.ITargetFileRequestDeferral";
    template <> inline constexpr auto& name_v<llm:OS::Storage::Pickers::Provider::ITargetFileRequestedEventArgs> = L"Windows.Storage.Pickers.Provider.ITargetFileRequestedEventArgs";
    template <> inline constexpr guid guid_v<llm:OS::Storage::Pickers::Provider::IFileOpenPickerUI>{ 0xDDA45A10,0xF9D4,0x40C4,{ 0x8A,0xF5,0xC5,0xB6,0xB5,0xA6,0x1D,0x1D } }; // DDA45A10-F9D4-40C4-8AF5-C5B6B5A61D1D
    template <> inline constexpr guid guid_v<llm:OS::Storage::Pickers::Provider::IFileRemovedEventArgs>{ 0x13043DA7,0x7FCA,0x4C2B,{ 0x9E,0xCA,0x68,0x90,0xF9,0xF0,0x01,0x85 } }; // 13043DA7-7FCA-4C2B-9ECA-6890F9F00185
    template <> inline constexpr guid guid_v<llm:OS::Storage::Pickers::Provider::IFileSavePickerUI>{ 0x9656C1E7,0x3E56,0x43CC,{ 0x8A,0x39,0x33,0xC7,0x3D,0x9D,0x54,0x2B } }; // 9656C1E7-3E56-43CC-8A39-33C73D9D542B
    template <> inline constexpr guid guid_v<llm:OS::Storage::Pickers::Provider::IPickerClosingDeferral>{ 0x7AF7F71E,0x1A67,0x4A31,{ 0xAE,0x80,0xE9,0x07,0x70,0x8A,0x61,0x9B } }; // 7AF7F71E-1A67-4A31-AE80-E907708A619B
    template <> inline constexpr guid guid_v<llm:OS::Storage::Pickers::Provider::IPickerClosingEventArgs>{ 0x7E59F224,0xB332,0x4F12,{ 0x8B,0x9F,0xA8,0xC2,0xF0,0x6B,0x32,0xCD } }; // 7E59F224-B332-4F12-8B9F-A8C2F06B32CD
    template <> inline constexpr guid guid_v<llm:OS::Storage::Pickers::Provider::IPickerClosingOperation>{ 0x4CE9FB84,0xBEEE,0x4E39,{ 0xA7,0x73,0xFC,0x5F,0x0E,0xAE,0x32,0x8D } }; // 4CE9FB84-BEEE-4E39-A773-FC5F0EAE328D
    template <> inline constexpr guid guid_v<llm:OS::Storage::Pickers::Provider::ITargetFileRequest>{ 0x42BD3355,0x7F88,0x478B,{ 0x8E,0x81,0x69,0x0B,0x20,0x34,0x06,0x78 } }; // 42BD3355-7F88-478B-8E81-690B20340678
    template <> inline constexpr guid guid_v<llm:OS::Storage::Pickers::Provider::ITargetFileRequestDeferral>{ 0x4AEE9D91,0xBF15,0x4DA9,{ 0x95,0xF6,0xF6,0xB7,0xD5,0x58,0x22,0x5B } }; // 4AEE9D91-BF15-4DA9-95F6-F6B7D558225B
    template <> inline constexpr guid guid_v<llm:OS::Storage::Pickers::Provider::ITargetFileRequestedEventArgs>{ 0xB163DBC1,0x1B51,0x4C89,{ 0xA5,0x91,0x0F,0xD4,0x0B,0x3C,0x57,0xC9 } }; // B163DBC1-1B51-4C89-A591-0FD40B3C57C9
    template <> struct default_interface<llm:OS::Storage::Pickers::Provider::FileOpenPickerUI>{ using type = llm:OS::Storage::Pickers::Provider::IFileOpenPickerUI; };
    template <> struct default_interface<llm:OS::Storage::Pickers::Provider::FileRemovedEventArgs>{ using type = llm:OS::Storage::Pickers::Provider::IFileRemovedEventArgs; };
    template <> struct default_interface<llm:OS::Storage::Pickers::Provider::FileSavePickerUI>{ using type = llm:OS::Storage::Pickers::Provider::IFileSavePickerUI; };
    template <> struct default_interface<llm:OS::Storage::Pickers::Provider::PickerClosingDeferral>{ using type = llm:OS::Storage::Pickers::Provider::IPickerClosingDeferral; };
    template <> struct default_interface<llm:OS::Storage::Pickers::Provider::PickerClosingEventArgs>{ using type = llm:OS::Storage::Pickers::Provider::IPickerClosingEventArgs; };
    template <> struct default_interface<llm:OS::Storage::Pickers::Provider::PickerClosingOperation>{ using type = llm:OS::Storage::Pickers::Provider::IPickerClosingOperation; };
    template <> struct default_interface<llm:OS::Storage::Pickers::Provider::TargetFileRequest>{ using type = llm:OS::Storage::Pickers::Provider::ITargetFileRequest; };
    template <> struct default_interface<llm:OS::Storage::Pickers::Provider::TargetFileRequestDeferral>{ using type = llm:OS::Storage::Pickers::Provider::ITargetFileRequestDeferral; };
    template <> struct default_interface<llm:OS::Storage::Pickers::Provider::TargetFileRequestedEventArgs>{ using type = llm:OS::Storage::Pickers::Provider::ITargetFileRequestedEventArgs; };
    template <> struct abi<llm:OS::Storage::Pickers::Provider::IFileOpenPickerUI>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall AddFile(void*, void*, int32_t*) noexcept = 0;
            virtual int32_t __stdcall RemoveFile(void*) noexcept = 0;
            virtual int32_t __stdcall ContainsFile(void*, bool*) noexcept = 0;
            virtual int32_t __stdcall CanAddFile(void*, bool*) noexcept = 0;
            virtual int32_t __stdcall get_AllowedFileTypes(void**) noexcept = 0;
            virtual int32_t __stdcall get_SelectionMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_SettingsIdentifier(void**) noexcept = 0;
            virtual int32_t __stdcall get_Title(void**) noexcept = 0;
            virtual int32_t __stdcall put_Title(void*) noexcept = 0;
            virtual int32_t __stdcall add_FileRemoved(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_FileRemoved(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Closing(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Closing(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Storage::Pickers::Provider::IFileRemovedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Id(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Storage::Pickers::Provider::IFileSavePickerUI>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Title(void**) noexcept = 0;
            virtual int32_t __stdcall put_Title(void*) noexcept = 0;
            virtual int32_t __stdcall get_AllowedFileTypes(void**) noexcept = 0;
            virtual int32_t __stdcall get_SettingsIdentifier(void**) noexcept = 0;
            virtual int32_t __stdcall get_FileName(void**) noexcept = 0;
            virtual int32_t __stdcall TrySetFileName(void*, int32_t*) noexcept = 0;
            virtual int32_t __stdcall add_FileNameChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_FileNameChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_TargetFileRequested(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_TargetFileRequested(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Storage::Pickers::Provider::IPickerClosingDeferral>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Complete() noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Storage::Pickers::Provider::IPickerClosingEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ClosingOperation(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsCanceled(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Storage::Pickers::Provider::IPickerClosingOperation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
            virtual int32_t __stdcall get_Deadline(int64_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Storage::Pickers::Provider::ITargetFileRequest>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_TargetFile(void**) noexcept = 0;
            virtual int32_t __stdcall put_TargetFile(void*) noexcept = 0;
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Storage::Pickers::Provider::ITargetFileRequestDeferral>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Complete() noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Storage::Pickers::Provider::ITargetFileRequestedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Request(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Storage_Pickers_Provider_IFileOpenPickerUI
    {
        LLM_IMPL_AUTO(llm:OS::Storage::Pickers::Provider::AddFileResult) AddFile(param::hstring const& id, llm:OS::Storage::IStorageFile const& file) const;
        LLM_IMPL_AUTO(void) RemoveFile(param::hstring const& id) const;
        LLM_IMPL_AUTO(bool) ContainsFile(param::hstring const& id) const;
        LLM_IMPL_AUTO(bool) CanAddFile(llm:OS::Storage::IStorageFile const& file) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<hstring>) AllowedFileTypes() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::Pickers::Provider::FileSelectionMode) SelectionMode() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SettingsIdentifier() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Title() const;
        LLM_IMPL_AUTO(void) Title(param::hstring const& value) const;
        LLM_IMPL_AUTO(llm::event_token) FileRemoved(llm:OS::Foundation::TypedEventHandler<llm:OS::Storage::Pickers::Provider::FileOpenPickerUI, llm:OS::Storage::Pickers::Provider::FileRemovedEventArgs> const& handler) const;
        using FileRemoved_revoker = impl::event_revoker<llm:OS::Storage::Pickers::Provider::IFileOpenPickerUI, &impl::abi_t<llm:OS::Storage::Pickers::Provider::IFileOpenPickerUI>::remove_FileRemoved>;
        [[nodiscard]] FileRemoved_revoker FileRemoved(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Storage::Pickers::Provider::FileOpenPickerUI, llm:OS::Storage::Pickers::Provider::FileRemovedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) FileRemoved(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) Closing(llm:OS::Foundation::TypedEventHandler<llm:OS::Storage::Pickers::Provider::FileOpenPickerUI, llm:OS::Storage::Pickers::Provider::PickerClosingEventArgs> const& handler) const;
        using Closing_revoker = impl::event_revoker<llm:OS::Storage::Pickers::Provider::IFileOpenPickerUI, &impl::abi_t<llm:OS::Storage::Pickers::Provider::IFileOpenPickerUI>::remove_Closing>;
        [[nodiscard]] Closing_revoker Closing(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Storage::Pickers::Provider::FileOpenPickerUI, llm:OS::Storage::Pickers::Provider::PickerClosingEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) Closing(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::Storage::Pickers::Provider::IFileOpenPickerUI>
    {
        template <typename D> using type = consume_Windows_Storage_Pickers_Provider_IFileOpenPickerUI<D>;
    };
    template <typename D>
    struct consume_Windows_Storage_Pickers_Provider_IFileRemovedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Id() const;
    };
    template <> struct consume<llm:OS::Storage::Pickers::Provider::IFileRemovedEventArgs>
    {
        template <typename D> using type = consume_Windows_Storage_Pickers_Provider_IFileRemovedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Storage_Pickers_Provider_IFileSavePickerUI
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Title() const;
        LLM_IMPL_AUTO(void) Title(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<hstring>) AllowedFileTypes() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SettingsIdentifier() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) FileName() const;
        LLM_IMPL_AUTO(llm:OS::Storage::Pickers::Provider::SetFileNameResult) TrySetFileName(param::hstring const& value) const;
        LLM_IMPL_AUTO(llm::event_token) FileNameChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::Storage::Pickers::Provider::FileSavePickerUI, llm:OS::Foundation::IInspectable> const& handler) const;
        using FileNameChanged_revoker = impl::event_revoker<llm:OS::Storage::Pickers::Provider::IFileSavePickerUI, &impl::abi_t<llm:OS::Storage::Pickers::Provider::IFileSavePickerUI>::remove_FileNameChanged>;
        [[nodiscard]] FileNameChanged_revoker FileNameChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Storage::Pickers::Provider::FileSavePickerUI, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) FileNameChanged(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) TargetFileRequested(llm:OS::Foundation::TypedEventHandler<llm:OS::Storage::Pickers::Provider::FileSavePickerUI, llm:OS::Storage::Pickers::Provider::TargetFileRequestedEventArgs> const& handler) const;
        using TargetFileRequested_revoker = impl::event_revoker<llm:OS::Storage::Pickers::Provider::IFileSavePickerUI, &impl::abi_t<llm:OS::Storage::Pickers::Provider::IFileSavePickerUI>::remove_TargetFileRequested>;
        [[nodiscard]] TargetFileRequested_revoker TargetFileRequested(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Storage::Pickers::Provider::FileSavePickerUI, llm:OS::Storage::Pickers::Provider::TargetFileRequestedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) TargetFileRequested(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::Storage::Pickers::Provider::IFileSavePickerUI>
    {
        template <typename D> using type = consume_Windows_Storage_Pickers_Provider_IFileSavePickerUI<D>;
    };
    template <typename D>
    struct consume_Windows_Storage_Pickers_Provider_IPickerClosingDeferral
    {
        LLM_IMPL_AUTO(void) Complete() const;
    };
    template <> struct consume<llm:OS::Storage::Pickers::Provider::IPickerClosingDeferral>
    {
        template <typename D> using type = consume_Windows_Storage_Pickers_Provider_IPickerClosingDeferral<D>;
    };
    template <typename D>
    struct consume_Windows_Storage_Pickers_Provider_IPickerClosingEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::Pickers::Provider::PickerClosingOperation) ClosingOperation() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsCanceled() const;
    };
    template <> struct consume<llm:OS::Storage::Pickers::Provider::IPickerClosingEventArgs>
    {
        template <typename D> using type = consume_Windows_Storage_Pickers_Provider_IPickerClosingEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Storage_Pickers_Provider_IPickerClosingOperation
    {
        LLM_IMPL_AUTO(llm:OS::Storage::Pickers::Provider::PickerClosingDeferral) GetDeferral() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::DateTime) Deadline() const;
    };
    template <> struct consume<llm:OS::Storage::Pickers::Provider::IPickerClosingOperation>
    {
        template <typename D> using type = consume_Windows_Storage_Pickers_Provider_IPickerClosingOperation<D>;
    };
    template <typename D>
    struct consume_Windows_Storage_Pickers_Provider_ITargetFileRequest
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::IStorageFile) TargetFile() const;
        LLM_IMPL_AUTO(void) TargetFile(llm:OS::Storage::IStorageFile const& value) const;
        LLM_IMPL_AUTO(llm:OS::Storage::Pickers::Provider::TargetFileRequestDeferral) GetDeferral() const;
    };
    template <> struct consume<llm:OS::Storage::Pickers::Provider::ITargetFileRequest>
    {
        template <typename D> using type = consume_Windows_Storage_Pickers_Provider_ITargetFileRequest<D>;
    };
    template <typename D>
    struct consume_Windows_Storage_Pickers_Provider_ITargetFileRequestDeferral
    {
        LLM_IMPL_AUTO(void) Complete() const;
    };
    template <> struct consume<llm:OS::Storage::Pickers::Provider::ITargetFileRequestDeferral>
    {
        template <typename D> using type = consume_Windows_Storage_Pickers_Provider_ITargetFileRequestDeferral<D>;
    };
    template <typename D>
    struct consume_Windows_Storage_Pickers_Provider_ITargetFileRequestedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::Pickers::Provider::TargetFileRequest) Request() const;
    };
    template <> struct consume<llm:OS::Storage::Pickers::Provider::ITargetFileRequestedEventArgs>
    {
        template <typename D> using type = consume_Windows_Storage_Pickers_Provider_ITargetFileRequestedEventArgs<D>;
    };
}
#endif
