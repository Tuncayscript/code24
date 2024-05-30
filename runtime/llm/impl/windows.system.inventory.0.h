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
#ifndef LLM_OS_System_Inventory_0_H
#define LLM_OS_System_Inventory_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm:OS::System::Inventory
{
    struct IInstalledDesktopApp;
    struct IInstalledDesktopAppStatics;
    struct InstalledDesktopApp;
}
namespace llm::impl
{
    template <> struct category<llm:OS::System::Inventory::IInstalledDesktopApp>{ using type = interface_category; };
    template <> struct category<llm:OS::System::Inventory::IInstalledDesktopAppStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::System::Inventory::InstalledDesktopApp>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm:OS::System::Inventory::InstalledDesktopApp> = L"Windows.System.Inventory.InstalledDesktopApp";
    template <> inline constexpr auto& name_v<llm:OS::System::Inventory::IInstalledDesktopApp> = L"Windows.System.Inventory.IInstalledDesktopApp";
    template <> inline constexpr auto& name_v<llm:OS::System::Inventory::IInstalledDesktopAppStatics> = L"Windows.System.Inventory.IInstalledDesktopAppStatics";
    template <> inline constexpr guid guid_v<llm:OS::System::Inventory::IInstalledDesktopApp>{ 0x75EAB8ED,0xC0BC,0x5364,{ 0x4C,0x28,0x16,0x6E,0x05,0x45,0x16,0x7A } }; // 75EAB8ED-C0BC-5364-4C28-166E0545167A
    template <> inline constexpr guid guid_v<llm:OS::System::Inventory::IInstalledDesktopAppStatics>{ 0x264CF74E,0x21CD,0x5F9B,{ 0x60,0x56,0x78,0x66,0xAD,0x72,0x48,0x9A } }; // 264CF74E-21CD-5F9B-6056-7866AD72489A
    template <> struct default_interface<llm:OS::System::Inventory::InstalledDesktopApp>{ using type = llm:OS::System::Inventory::IInstalledDesktopApp; };
    template <> struct abi<llm:OS::System::Inventory::IInstalledDesktopApp>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Id(void**) noexcept = 0;
            virtual int32_t __stdcall get_DisplayName(void**) noexcept = 0;
            virtual int32_t __stdcall get_Publisher(void**) noexcept = 0;
            virtual int32_t __stdcall get_DisplayVersion(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::Inventory::IInstalledDesktopAppStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetInventoryAsync(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_System_Inventory_IInstalledDesktopApp
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Id() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayName() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Publisher() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayVersion() const;
    };
    template <> struct consume<llm:OS::System::Inventory::IInstalledDesktopApp>
    {
        template <typename D> using type = consume_Windows_System_Inventory_IInstalledDesktopApp<D>;
    };
    template <typename D>
    struct consume_Windows_System_Inventory_IInstalledDesktopAppStatics
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Foundation::Collections::IVectorView<llm:OS::System::Inventory::InstalledDesktopApp>>) GetInventoryAsync() const;
    };
    template <> struct consume<llm:OS::System::Inventory::IInstalledDesktopAppStatics>
    {
        template <typename D> using type = consume_Windows_System_Inventory_IInstalledDesktopAppStatics<D>;
    };
}
#endif
