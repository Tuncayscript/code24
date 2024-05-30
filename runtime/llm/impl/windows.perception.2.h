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
#ifndef LLM_OS_Perception_2_H
#define LLM_OS_Perception_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Perception.1.h"
LLM_EXPORT namespace llm:OS::Perception
{
    struct __declspec(empty_bases) PerceptionTimestamp : llm:OS::Perception::IPerceptionTimestamp,
        impl::require<PerceptionTimestamp, llm:OS::Perception::IPerceptionTimestamp2>
    {
        PerceptionTimestamp(std::nullptr_t) noexcept {}
        PerceptionTimestamp(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Perception::IPerceptionTimestamp(ptr, take_ownership_from_abi) {}
    };
    struct PerceptionTimestampHelper
    {
        PerceptionTimestampHelper() = delete;
        static auto FromHistoricalTargetTime(llm:OS::Foundation::DateTime const& targetTime);
        static auto FromSystemRelativeTargetTime(llm:OS::Foundation::TimeSpan const& targetTime);
    };
}
#endif
