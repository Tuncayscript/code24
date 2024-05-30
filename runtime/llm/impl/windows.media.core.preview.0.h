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
#ifndef LLM_OS_Media_Core_Preview_0_H
#define LLM_OS_Media_Core_Preview_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    template <typename T> struct __declspec(empty_bases) EventHandler;
    struct EventRegistrationToken;
}
LLM_EXPORT namespace llm:OS::Media
{
    enum class SoundLevel : int32_t;
}
LLM_EXPORT namespace llm:OS::Media::Core::Preview
{
    struct ISoundLevelBrokerStatics;
    struct SoundLevelBroker;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Media::Core::Preview::ISoundLevelBrokerStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Core::Preview::SoundLevelBroker>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm:OS::Media::Core::Preview::SoundLevelBroker> = L"Windows.Media.Core.Preview.SoundLevelBroker";
    template <> inline constexpr auto& name_v<llm:OS::Media::Core::Preview::ISoundLevelBrokerStatics> = L"Windows.Media.Core.Preview.ISoundLevelBrokerStatics";
    template <> inline constexpr guid guid_v<llm:OS::Media::Core::Preview::ISoundLevelBrokerStatics>{ 0x6A633961,0xDBED,0x464C,{ 0xA0,0x9A,0x33,0x41,0x2F,0x5C,0xAA,0x3F } }; // 6A633961-DBED-464C-A09A-33412F5CAA3F
    template <> struct abi<llm:OS::Media::Core::Preview::ISoundLevelBrokerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SoundLevel(int32_t*) noexcept = 0;
            virtual int32_t __stdcall add_SoundLevelChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_SoundLevelChanged(llm::event_token) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Media_Core_Preview_ISoundLevelBrokerStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::SoundLevel) SoundLevel() const;
        LLM_IMPL_AUTO(llm::event_token) SoundLevelChanged(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler) const;
        using SoundLevelChanged_revoker = impl::event_revoker<llm:OS::Media::Core::Preview::ISoundLevelBrokerStatics, &impl::abi_t<llm:OS::Media::Core::Preview::ISoundLevelBrokerStatics>::remove_SoundLevelChanged>;
        [[nodiscard]] SoundLevelChanged_revoker SoundLevelChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) SoundLevelChanged(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::Media::Core::Preview::ISoundLevelBrokerStatics>
    {
        template <typename D> using type = consume_Windows_Media_Core_Preview_ISoundLevelBrokerStatics<D>;
    };
}
#endif
