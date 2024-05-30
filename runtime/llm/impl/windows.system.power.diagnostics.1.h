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
#ifndef LLM_OS_System_Power_Diagnostics_1_H
#define LLM_OS_System_Power_Diagnostics_1_H
#include "llm/impl/Windows.System.Power.Diagnostics.0.h"
LLM_EXPORT namespace llm:OS::System::Power::Diagnostics
{
    struct __declspec(empty_bases) IBackgroundEnergyDiagnosticsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundEnergyDiagnosticsStatics>
    {
        IBackgroundEnergyDiagnosticsStatics(std::nullptr_t = nullptr) noexcept {}
        IBackgroundEnergyDiagnosticsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IForegroundEnergyDiagnosticsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IForegroundEnergyDiagnosticsStatics>
    {
        IForegroundEnergyDiagnosticsStatics(std::nullptr_t = nullptr) noexcept {}
        IForegroundEnergyDiagnosticsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
