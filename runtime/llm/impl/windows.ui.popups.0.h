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
#ifndef LLM_OS_UI_Popups_0_H
#define LLM_OS_UI_Popups_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    struct Point;
    struct Rect;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVector;
}
LLM_EXPORT namespace llm:OS::UI::Popups
{
    enum class MessageDialogOptions : uint32_t
    {
        None = 0,
        AcceptUserInputAfterDelay = 0x1,
    };
    enum class Placement : int32_t
    {
        Default = 0,
        Above = 1,
        Below = 2,
        Left = 3,
        Right = 4,
    };
    struct IMessageDialog;
    struct IMessageDialogFactory;
    struct IPopupMenu;
    struct IUICommand;
    struct IUICommandFactory;
    struct MessageDialog;
    struct PopupMenu;
    struct UICommand;
    struct UICommandSeparator;
    struct UICommandInvokedHandler;
}
namespace llm::impl
{
    template <> struct category<llm:OS::UI::Popups::IMessageDialog>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Popups::IMessageDialogFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Popups::IPopupMenu>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Popups::IUICommand>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Popups::IUICommandFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Popups::MessageDialog>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Popups::PopupMenu>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Popups::UICommand>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Popups::UICommandSeparator>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Popups::MessageDialogOptions>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Popups::Placement>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Popups::UICommandInvokedHandler>{ using type = delegate_category; };
    template <> inline constexpr auto& name_v<llm:OS::UI::Popups::MessageDialog> = L"Windows.UI.Popups.MessageDialog";
    template <> inline constexpr auto& name_v<llm:OS::UI::Popups::PopupMenu> = L"Windows.UI.Popups.PopupMenu";
    template <> inline constexpr auto& name_v<llm:OS::UI::Popups::UICommand> = L"Windows.UI.Popups.UICommand";
    template <> inline constexpr auto& name_v<llm:OS::UI::Popups::UICommandSeparator> = L"Windows.UI.Popups.UICommandSeparator";
    template <> inline constexpr auto& name_v<llm:OS::UI::Popups::MessageDialogOptions> = L"Windows.UI.Popups.MessageDialogOptions";
    template <> inline constexpr auto& name_v<llm:OS::UI::Popups::Placement> = L"Windows.UI.Popups.Placement";
    template <> inline constexpr auto& name_v<llm:OS::UI::Popups::IMessageDialog> = L"Windows.UI.Popups.IMessageDialog";
    template <> inline constexpr auto& name_v<llm:OS::UI::Popups::IMessageDialogFactory> = L"Windows.UI.Popups.IMessageDialogFactory";
    template <> inline constexpr auto& name_v<llm:OS::UI::Popups::IPopupMenu> = L"Windows.UI.Popups.IPopupMenu";
    template <> inline constexpr auto& name_v<llm:OS::UI::Popups::IUICommand> = L"Windows.UI.Popups.IUICommand";
    template <> inline constexpr auto& name_v<llm:OS::UI::Popups::IUICommandFactory> = L"Windows.UI.Popups.IUICommandFactory";
    template <> inline constexpr auto& name_v<llm:OS::UI::Popups::UICommandInvokedHandler> = L"Windows.UI.Popups.UICommandInvokedHandler";
    template <> inline constexpr guid guid_v<llm:OS::UI::Popups::IMessageDialog>{ 0x33F59B01,0x5325,0x43AB,{ 0x9A,0xB3,0xBD,0xAE,0x44,0x0E,0x41,0x21 } }; // 33F59B01-5325-43AB-9AB3-BDAE440E4121
    template <> inline constexpr guid guid_v<llm:OS::UI::Popups::IMessageDialogFactory>{ 0x2D161777,0xA66F,0x4EA5,{ 0xBB,0x87,0x79,0x3F,0xFA,0x49,0x41,0xF2 } }; // 2D161777-A66F-4EA5-BB87-793FFA4941F2
    template <> inline constexpr guid guid_v<llm:OS::UI::Popups::IPopupMenu>{ 0x4E9BC6DC,0x880D,0x47FC,{ 0xA0,0xA1,0x72,0xB6,0x39,0xE6,0x25,0x59 } }; // 4E9BC6DC-880D-47FC-A0A1-72B639E62559
    template <> inline constexpr guid guid_v<llm:OS::UI::Popups::IUICommand>{ 0x4FF93A75,0x4145,0x47FF,{ 0xAC,0x7F,0xDF,0xF1,0xC1,0xFA,0x5B,0x0F } }; // 4FF93A75-4145-47FF-AC7F-DFF1C1FA5B0F
    template <> inline constexpr guid guid_v<llm:OS::UI::Popups::IUICommandFactory>{ 0xA21A8189,0x26B0,0x4676,{ 0xAE,0x94,0x54,0x04,0x1B,0xC1,0x25,0xE8 } }; // A21A8189-26B0-4676-AE94-54041BC125E8
    template <> inline constexpr guid guid_v<llm:OS::UI::Popups::UICommandInvokedHandler>{ 0xDAF77A4F,0xC27A,0x4298,{ 0x9A,0xC6,0x29,0x22,0xC4,0x5E,0x7D,0xA6 } }; // DAF77A4F-C27A-4298-9AC6-2922C45E7DA6
    template <> struct default_interface<llm:OS::UI::Popups::MessageDialog>{ using type = llm:OS::UI::Popups::IMessageDialog; };
    template <> struct default_interface<llm:OS::UI::Popups::PopupMenu>{ using type = llm:OS::UI::Popups::IPopupMenu; };
    template <> struct default_interface<llm:OS::UI::Popups::UICommand>{ using type = llm:OS::UI::Popups::IUICommand; };
    template <> struct default_interface<llm:OS::UI::Popups::UICommandSeparator>{ using type = llm:OS::UI::Popups::IUICommand; };
    template <> struct abi<llm:OS::UI::Popups::IMessageDialog>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Title(void**) noexcept = 0;
            virtual int32_t __stdcall put_Title(void*) noexcept = 0;
            virtual int32_t __stdcall get_Commands(void**) noexcept = 0;
            virtual int32_t __stdcall get_DefaultCommandIndex(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_DefaultCommandIndex(uint32_t) noexcept = 0;
            virtual int32_t __stdcall get_CancelCommandIndex(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_CancelCommandIndex(uint32_t) noexcept = 0;
            virtual int32_t __stdcall get_Content(void**) noexcept = 0;
            virtual int32_t __stdcall put_Content(void*) noexcept = 0;
            virtual int32_t __stdcall ShowAsync(void**) noexcept = 0;
            virtual int32_t __stdcall get_Options(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Options(uint32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Popups::IMessageDialogFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateWithTitle(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Popups::IPopupMenu>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Commands(void**) noexcept = 0;
            virtual int32_t __stdcall ShowAsync(llm:OS::Foundation::Point, void**) noexcept = 0;
            virtual int32_t __stdcall ShowAsyncWithRect(llm:OS::Foundation::Rect, void**) noexcept = 0;
            virtual int32_t __stdcall ShowAsyncWithRectAndPlacement(llm:OS::Foundation::Rect, int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Popups::IUICommand>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Label(void**) noexcept = 0;
            virtual int32_t __stdcall put_Label(void*) noexcept = 0;
            virtual int32_t __stdcall get_Invoked(void**) noexcept = 0;
            virtual int32_t __stdcall put_Invoked(void*) noexcept = 0;
            virtual int32_t __stdcall get_Id(void**) noexcept = 0;
            virtual int32_t __stdcall put_Id(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Popups::IUICommandFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateWithHandler(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateWithHandlerAndId(void*, void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Popups::UICommandInvokedHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_UI_Popups_IMessageDialog
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Title() const;
        LLM_IMPL_AUTO(void) Title(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVector<llm:OS::UI::Popups::IUICommand>) Commands() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) DefaultCommandIndex() const;
        LLM_IMPL_AUTO(void) DefaultCommandIndex(uint32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) CancelCommandIndex() const;
        LLM_IMPL_AUTO(void) CancelCommandIndex(uint32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Content() const;
        LLM_IMPL_AUTO(void) Content(param::hstring const& value) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::UI::Popups::IUICommand>) ShowAsync() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Popups::MessageDialogOptions) Options() const;
        LLM_IMPL_AUTO(void) Options(llm:OS::UI::Popups::MessageDialogOptions const& value) const;
    };
    template <> struct consume<llm:OS::UI::Popups::IMessageDialog>
    {
        template <typename D> using type = consume_Windows_UI_Popups_IMessageDialog<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Popups_IMessageDialogFactory
    {
        LLM_IMPL_AUTO(llm:OS::UI::Popups::MessageDialog) Create(param::hstring const& content) const;
        LLM_IMPL_AUTO(llm:OS::UI::Popups::MessageDialog) CreateWithTitle(param::hstring const& content, param::hstring const& title) const;
    };
    template <> struct consume<llm:OS::UI::Popups::IMessageDialogFactory>
    {
        template <typename D> using type = consume_Windows_UI_Popups_IMessageDialogFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Popups_IPopupMenu
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVector<llm:OS::UI::Popups::IUICommand>) Commands() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::UI::Popups::IUICommand>) ShowAsync(llm:OS::Foundation::Point const& invocationPoint) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::UI::Popups::IUICommand>) ShowForSelectionAsync(llm:OS::Foundation::Rect const& selection) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::UI::Popups::IUICommand>) ShowForSelectionAsync(llm:OS::Foundation::Rect const& selection, llm:OS::UI::Popups::Placement const& preferredPlacement) const;
    };
    template <> struct consume<llm:OS::UI::Popups::IPopupMenu>
    {
        template <typename D> using type = consume_Windows_UI_Popups_IPopupMenu<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Popups_IUICommand
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Label() const;
        LLM_IMPL_AUTO(void) Label(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Popups::UICommandInvokedHandler) Invoked() const;
        LLM_IMPL_AUTO(void) Invoked(llm:OS::UI::Popups::UICommandInvokedHandler const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IInspectable) Id() const;
        LLM_IMPL_AUTO(void) Id(llm:OS::Foundation::IInspectable const& value) const;
    };
    template <> struct consume<llm:OS::UI::Popups::IUICommand>
    {
        template <typename D> using type = consume_Windows_UI_Popups_IUICommand<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Popups_IUICommandFactory
    {
        LLM_IMPL_AUTO(llm:OS::UI::Popups::UICommand) Create(param::hstring const& label) const;
        LLM_IMPL_AUTO(llm:OS::UI::Popups::UICommand) CreateWithHandler(param::hstring const& label, llm:OS::UI::Popups::UICommandInvokedHandler const& action) const;
        LLM_IMPL_AUTO(llm:OS::UI::Popups::UICommand) CreateWithHandlerAndId(param::hstring const& label, llm:OS::UI::Popups::UICommandInvokedHandler const& action, llm:OS::Foundation::IInspectable const& commandId) const;
    };
    template <> struct consume<llm:OS::UI::Popups::IUICommandFactory>
    {
        template <typename D> using type = consume_Windows_UI_Popups_IUICommandFactory<D>;
    };
}
#endif
