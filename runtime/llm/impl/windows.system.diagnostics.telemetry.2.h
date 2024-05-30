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
#ifndef LLM_OS_System_Diagnostics_Telemetry_2_H
#define LLM_OS_System_Diagnostics_Telemetry_2_H
#include "llm/impl/Windows.System.Diagnostics.Telemetry.1.h"
LLM_EXPORT namespace llm:OS::System::Diagnostics::Telemetry
{
    struct PlatformTelemetryClient
    {
        PlatformTelemetryClient() = delete;
        static auto Register(param::hstring const& id);
        static auto Register(param::hstring const& id, llm:OS::System::Diagnostics::Telemetry::PlatformTelemetryRegistrationSettings const& settings);
    };
    struct __declspec(empty_bases) PlatformTelemetryRegistrationResult : llm:OS::System::Diagnostics::Telemetry::IPlatformTelemetryRegistrationResult
    {
        PlatformTelemetryRegistrationResult(std::nullptr_t) noexcept {}
        PlatformTelemetryRegistrationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Diagnostics::Telemetry::IPlatformTelemetryRegistrationResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PlatformTelemetryRegistrationSettings : llm:OS::System::Diagnostics::Telemetry::IPlatformTelemetryRegistrationSettings
    {
        PlatformTelemetryRegistrationSettings(std::nullptr_t) noexcept {}
        PlatformTelemetryRegistrationSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Diagnostics::Telemetry::IPlatformTelemetryRegistrationSettings(ptr, take_ownership_from_abi) {}
        PlatformTelemetryRegistrationSettings();
    };
}
#endif
