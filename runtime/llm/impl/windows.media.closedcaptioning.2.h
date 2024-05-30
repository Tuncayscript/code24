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
#ifndef LLM_OS_Media_ClosedCaptioning_2_H
#define LLM_OS_Media_ClosedCaptioning_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Media.ClosedCaptioning.1.h"
LLM_EXPORT namespace llm:OS::Media::ClosedCaptioning
{
    struct ClosedCaptionProperties
    {
        ClosedCaptionProperties() = delete;
        [[nodiscard]] static auto FontColor();
        [[nodiscard]] static auto ComputedFontColor();
        [[nodiscard]] static auto FontOpacity();
        [[nodiscard]] static auto FontSize();
        [[nodiscard]] static auto FontStyle();
        [[nodiscard]] static auto FontEffect();
        [[nodiscard]] static auto BackgroundColor();
        [[nodiscard]] static auto ComputedBackgroundColor();
        [[nodiscard]] static auto BackgroundOpacity();
        [[nodiscard]] static auto RegionColor();
        [[nodiscard]] static auto ComputedRegionColor();
        [[nodiscard]] static auto RegionOpacity();
        static auto PropertiesChanged(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using PropertiesChanged_revoker = impl::factory_event_revoker<llm:OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics2, &impl::abi_t<llm:OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics2>::remove_PropertiesChanged>;
        [[nodiscard]] static PropertiesChanged_revoker PropertiesChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto PropertiesChanged(llm::event_token const& token);
    };
}
#endif
