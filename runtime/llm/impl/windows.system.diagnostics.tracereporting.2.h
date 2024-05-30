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
#ifndef LLM_OS_System_Diagnostics_TraceReporting_2_H
#define LLM_OS_System_Diagnostics_TraceReporting_2_H
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.System.Diagnostics.TraceReporting.1.h"
LLM_EXPORT namespace llm:OS::System::Diagnostics::TraceReporting
{
    struct PlatformDiagnosticActions
    {
        PlatformDiagnosticActions() = delete;
        static auto IsScenarioEnabled(llm::guid const& scenarioId);
        static auto TryEscalateScenario(llm::guid const& scenarioId, llm:OS::System::Diagnostics::TraceReporting::PlatformDiagnosticEscalationType const& escalationType, param::hstring const& outputDirectory, bool timestampOutputDirectory, bool forceEscalationUpload, param::map_view<hstring, hstring> const& triggers);
        static auto DownloadLatestSettingsForNamespace(param::hstring const& partner, param::hstring const& feature, bool isScenarioNamespace, bool downloadOverCostedNetwork, bool downloadOverBattery);
        static auto GetActiveScenarioList();
        static auto ForceUpload(llm:OS::System::Diagnostics::TraceReporting::PlatformDiagnosticEventBufferLatencies const& latency, bool uploadOverCostedNetwork, bool uploadOverBattery);
        static auto IsTraceRunning(llm:OS::System::Diagnostics::TraceReporting::PlatformDiagnosticTraceSlotType const& slotType, llm::guid const& scenarioId, uint64_t traceProfileHash);
        static auto GetActiveTraceRuntime(llm:OS::System::Diagnostics::TraceReporting::PlatformDiagnosticTraceSlotType const& slotType);
        static auto GetKnownTraceList(llm:OS::System::Diagnostics::TraceReporting::PlatformDiagnosticTraceSlotType const& slotType);
    };
    struct __declspec(empty_bases) PlatformDiagnosticTraceInfo : llm:OS::System::Diagnostics::TraceReporting::IPlatformDiagnosticTraceInfo
    {
        PlatformDiagnosticTraceInfo(std::nullptr_t) noexcept {}
        PlatformDiagnosticTraceInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Diagnostics::TraceReporting::IPlatformDiagnosticTraceInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PlatformDiagnosticTraceRuntimeInfo : llm:OS::System::Diagnostics::TraceReporting::IPlatformDiagnosticTraceRuntimeInfo
    {
        PlatformDiagnosticTraceRuntimeInfo(std::nullptr_t) noexcept {}
        PlatformDiagnosticTraceRuntimeInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Diagnostics::TraceReporting::IPlatformDiagnosticTraceRuntimeInfo(ptr, take_ownership_from_abi) {}
    };
}
#endif
