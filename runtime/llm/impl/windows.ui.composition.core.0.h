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
#ifndef LLM_OS_UI_Composition_Core_0_H
#define LLM_OS_UI_Composition_Core_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    struct EventRegistrationToken;
    struct IAsyncAction;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm:OS::UI::Composition
{
    struct Compositor;
}
LLM_EXPORT namespace llm:OS::UI::Composition::Core
{
    struct ICompositorController;
    struct CompositorController;
}
namespace llm::impl
{
    template <> struct category<llm:OS::UI::Composition::Core::ICompositorController>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::Core::CompositorController>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::Core::CompositorController> = L"Windows.UI.Composition.Core.CompositorController";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::Core::ICompositorController> = L"Windows.UI.Composition.Core.ICompositorController";
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::Core::ICompositorController>{ 0x2D75F35A,0x70A7,0x4395,{ 0xBA,0x2D,0xCE,0xF0,0xB1,0x83,0x99,0xF9 } }; // 2D75F35A-70A7-4395-BA2D-CEF0B18399F9
    template <> struct default_interface<llm:OS::UI::Composition::Core::CompositorController>{ using type = llm:OS::UI::Composition::Core::ICompositorController; };
    template <> struct abi<llm:OS::UI::Composition::Core::ICompositorController>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Compositor(void**) noexcept = 0;
            virtual int32_t __stdcall Commit() noexcept = 0;
            virtual int32_t __stdcall EnsurePreviousCommitCompletedAsync(void**) noexcept = 0;
            virtual int32_t __stdcall add_CommitNeeded(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_CommitNeeded(llm::event_token) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_UI_Composition_Core_ICompositorController
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::Compositor) Compositor() const;
        LLM_IMPL_AUTO(void) Commit() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) EnsurePreviousCommitCompletedAsync() const;
        LLM_IMPL_AUTO(llm::event_token) CommitNeeded(llm:OS::Foundation::TypedEventHandler<llm:OS::UI::Composition::Core::CompositorController, llm:OS::Foundation::IInspectable> const& handler) const;
        using CommitNeeded_revoker = impl::event_revoker<llm:OS::UI::Composition::Core::ICompositorController, &impl::abi_t<llm:OS::UI::Composition::Core::ICompositorController>::remove_CommitNeeded>;
        [[nodiscard]] CommitNeeded_revoker CommitNeeded(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::UI::Composition::Core::CompositorController, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) CommitNeeded(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::UI::Composition::Core::ICompositorController>
    {
        template <typename D> using type = consume_Windows_UI_Composition_Core_ICompositorController<D>;
    };
}
#endif
