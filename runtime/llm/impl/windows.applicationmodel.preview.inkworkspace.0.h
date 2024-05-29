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
#ifndef LLM_OS_ApplicationModel_Preview_InkWorkspace_0_H
#define LLM_OS_ApplicationModel_Preview_InkWorkspace_0_H
LLM_EXPORT namespace llm::OS::Foundation
{
    struct IAsyncAction;
}
LLM_EXPORT namespace llm::OS::Graphics::Imaging
{
    struct SoftwareBitmap;
}
LLM_EXPORT namespace llm::OS::ApplicationModel::Preview::InkWorkspace
{
    struct IInkWorkspaceHostedAppManager;
    struct IInkWorkspaceHostedAppManagerStatics;
    struct InkWorkspaceHostedAppManager;
}
namespace llm::impl
{
    template <> struct category<llm::OS::ApplicationModel::Preview::InkWorkspace::IInkWorkspaceHostedAppManager>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Preview::InkWorkspace::IInkWorkspaceHostedAppManagerStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Preview::InkWorkspace::InkWorkspaceHostedAppManager>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Preview::InkWorkspace::InkWorkspaceHostedAppManager> = L"Windows.ApplicationModel.Preview.InkWorkspace.InkWorkspaceHostedAppManager";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Preview::InkWorkspace::IInkWorkspaceHostedAppManager> = L"Windows.ApplicationModel.Preview.InkWorkspace.IInkWorkspaceHostedAppManager";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Preview::InkWorkspace::IInkWorkspaceHostedAppManagerStatics> = L"Windows.ApplicationModel.Preview.InkWorkspace.IInkWorkspaceHostedAppManagerStatics";
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Preview::InkWorkspace::IInkWorkspaceHostedAppManager>{ 0xFE0A7990,0x5E59,0x4BB7,{ 0x8A,0x63,0x7D,0x21,0x8C,0xD9,0x63,0x00 } }; // FE0A7990-5E59-4BB7-8A63-7D218CD96300
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Preview::InkWorkspace::IInkWorkspaceHostedAppManagerStatics>{ 0xCBFD8CC5,0xA162,0x4BC4,{ 0x84,0xEE,0xE8,0x71,0x6D,0x52,0x33,0xC5 } }; // CBFD8CC5-A162-4BC4-84EE-E8716D5233C5
    template <> struct default_interface<llm::OS::ApplicationModel::Preview::InkWorkspace::InkWorkspaceHostedAppManager>{ using type = llm::OS::ApplicationModel::Preview::InkWorkspace::IInkWorkspaceHostedAppManager; };
    template <> struct abi<llm::OS::ApplicationModel::Preview::InkWorkspace::IInkWorkspaceHostedAppManager>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SetThumbnailAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Preview::InkWorkspace::IInkWorkspaceHostedAppManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetForCurrentApp(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Preview_InkWorkspace_IInkWorkspaceHostedAppManager
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) SetThumbnailAsync(llm::OS::Graphics::Imaging::SoftwareBitmap const& bitmap) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Preview::InkWorkspace::IInkWorkspaceHostedAppManager>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Preview_InkWorkspace_IInkWorkspaceHostedAppManager<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Preview_InkWorkspace_IInkWorkspaceHostedAppManagerStatics
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Preview::InkWorkspace::InkWorkspaceHostedAppManager) GetForCurrentApp() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Preview::InkWorkspace::IInkWorkspaceHostedAppManagerStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Preview_InkWorkspace_IInkWorkspaceHostedAppManagerStatics<D>;
    };
}
#endif
