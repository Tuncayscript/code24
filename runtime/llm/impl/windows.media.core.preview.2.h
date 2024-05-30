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
#ifndef LLM_OS_Media_Core_Preview_2_H
#define LLM_OS_Media_Core_Preview_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Media.Core.Preview.1.h"
LLM_EXPORT namespace llm:OS::Media::Core::Preview
{
    struct SoundLevelBroker
    {
        SoundLevelBroker() = delete;
        [[nodiscard]] static auto SoundLevel();
        static auto SoundLevelChanged(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using SoundLevelChanged_revoker = impl::factory_event_revoker<llm:OS::Media::Core::Preview::ISoundLevelBrokerStatics, &impl::abi_t<llm:OS::Media::Core::Preview::ISoundLevelBrokerStatics>::remove_SoundLevelChanged>;
        [[nodiscard]] static SoundLevelChanged_revoker SoundLevelChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto SoundLevelChanged(llm::event_token const& token);
    };
}
#endif
