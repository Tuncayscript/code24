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
#ifndef LLM_OS_System_Diagnostics_Telemetry_1_H
#define LLM_OS_System_Diagnostics_Telemetry_1_H
#include "llm/impl/Windows.System.Diagnostics.Telemetry.0.h"
LLM_EXPORT namespace llm:OS::System::Diagnostics::Telemetry
{
    struct __declspec(empty_bases) IPlatformTelemetryClientStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlatformTelemetryClientStatics>
    {
        IPlatformTelemetryClientStatics(std::nullptr_t = nullptr) noexcept {}
        IPlatformTelemetryClientStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlatformTelemetryRegistrationResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlatformTelemetryRegistrationResult>
    {
        IPlatformTelemetryRegistrationResult(std::nullptr_t = nullptr) noexcept {}
        IPlatformTelemetryRegistrationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlatformTelemetryRegistrationSettings :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlatformTelemetryRegistrationSettings>
    {
        IPlatformTelemetryRegistrationSettings(std::nullptr_t = nullptr) noexcept {}
        IPlatformTelemetryRegistrationSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
