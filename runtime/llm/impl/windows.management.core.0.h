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
#ifndef LLM_OS_Management_Core_0_H
#define LLM_OS_Management_Core_0_H
LLM_EXPORT namespace llm:OS::Storage
{
    struct ApplicationData;
}
LLM_EXPORT namespace llm:OS::Management::Core
{
    struct IApplicationDataManager;
    struct IApplicationDataManagerStatics;
    struct ApplicationDataManager;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Management::Core::IApplicationDataManager>{ using type = interface_category; };
    template <> struct category<llm:OS::Management::Core::IApplicationDataManagerStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Management::Core::ApplicationDataManager>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm:OS::Management::Core::ApplicationDataManager> = L"Windows.Management.Core.ApplicationDataManager";
    template <> inline constexpr auto& name_v<llm:OS::Management::Core::IApplicationDataManager> = L"Windows.Management.Core.IApplicationDataManager";
    template <> inline constexpr auto& name_v<llm:OS::Management::Core::IApplicationDataManagerStatics> = L"Windows.Management.Core.IApplicationDataManagerStatics";
    template <> inline constexpr guid guid_v<llm:OS::Management::Core::IApplicationDataManager>{ 0x74D10432,0x2E99,0x4000,{ 0x9A,0x3A,0x64,0x30,0x7E,0x85,0x81,0x29 } }; // 74D10432-2E99-4000-9A3A-64307E858129
    template <> inline constexpr guid guid_v<llm:OS::Management::Core::IApplicationDataManagerStatics>{ 0x1E1862E3,0x698E,0x49A1,{ 0x97,0x52,0xDE,0xE9,0x49,0x25,0xB9,0xB3 } }; // 1E1862E3-698E-49A1-9752-DEE94925B9B3
    template <> struct default_interface<llm:OS::Management::Core::ApplicationDataManager>{ using type = llm:OS::Management::Core::IApplicationDataManager; };
    template <> struct abi<llm:OS::Management::Core::IApplicationDataManager>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::Management::Core::IApplicationDataManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateForPackageFamily(void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Management_Core_IApplicationDataManager
    {
    };
    template <> struct consume<llm:OS::Management::Core::IApplicationDataManager>
    {
        template <typename D> using type = consume_Windows_Management_Core_IApplicationDataManager<D>;
    };
    template <typename D>
    struct consume_Windows_Management_Core_IApplicationDataManagerStatics
    {
        LLM_IMPL_AUTO(llm:OS::Storage::ApplicationData) CreateForPackageFamily(param::hstring const& packageFamilyName) const;
    };
    template <> struct consume<llm:OS::Management::Core::IApplicationDataManagerStatics>
    {
        template <typename D> using type = consume_Windows_Management_Core_IApplicationDataManagerStatics<D>;
    };
}
#endif
