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
#ifndef LLM_OS_System_Diagnostics_2_H
#define LLM_OS_System_Diagnostics_2_H
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.System.Diagnostics.1.h"
LLM_EXPORT namespace llm:OS::System::Diagnostics
{
    struct __declspec(empty_bases) DiagnosticActionResult : llm:OS::System::Diagnostics::IDiagnosticActionResult
    {
        DiagnosticActionResult(std::nullptr_t) noexcept {}
        DiagnosticActionResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Diagnostics::IDiagnosticActionResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DiagnosticInvoker : llm:OS::System::Diagnostics::IDiagnosticInvoker,
        impl::require<DiagnosticInvoker, llm:OS::System::Diagnostics::IDiagnosticInvoker2>
    {
        DiagnosticInvoker(std::nullptr_t) noexcept {}
        DiagnosticInvoker(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Diagnostics::IDiagnosticInvoker(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
        static auto GetForUser(llm:OS::System::User const& user);
        [[nodiscard]] static auto IsSupported();
    };
    struct __declspec(empty_bases) ProcessCpuUsage : llm:OS::System::Diagnostics::IProcessCpuUsage
    {
        ProcessCpuUsage(std::nullptr_t) noexcept {}
        ProcessCpuUsage(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Diagnostics::IProcessCpuUsage(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ProcessCpuUsageReport : llm:OS::System::Diagnostics::IProcessCpuUsageReport
    {
        ProcessCpuUsageReport(std::nullptr_t) noexcept {}
        ProcessCpuUsageReport(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Diagnostics::IProcessCpuUsageReport(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ProcessDiagnosticInfo : llm:OS::System::Diagnostics::IProcessDiagnosticInfo,
        impl::require<ProcessDiagnosticInfo, llm:OS::System::Diagnostics::IProcessDiagnosticInfo2>
    {
        ProcessDiagnosticInfo(std::nullptr_t) noexcept {}
        ProcessDiagnosticInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Diagnostics::IProcessDiagnosticInfo(ptr, take_ownership_from_abi) {}
        static auto GetForProcesses();
        static auto GetForCurrentProcess();
        static auto TryGetForProcessId(uint32_t processId);
    };
    struct __declspec(empty_bases) ProcessDiskUsage : llm:OS::System::Diagnostics::IProcessDiskUsage
    {
        ProcessDiskUsage(std::nullptr_t) noexcept {}
        ProcessDiskUsage(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Diagnostics::IProcessDiskUsage(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ProcessDiskUsageReport : llm:OS::System::Diagnostics::IProcessDiskUsageReport
    {
        ProcessDiskUsageReport(std::nullptr_t) noexcept {}
        ProcessDiskUsageReport(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Diagnostics::IProcessDiskUsageReport(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ProcessMemoryUsage : llm:OS::System::Diagnostics::IProcessMemoryUsage
    {
        ProcessMemoryUsage(std::nullptr_t) noexcept {}
        ProcessMemoryUsage(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Diagnostics::IProcessMemoryUsage(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ProcessMemoryUsageReport : llm:OS::System::Diagnostics::IProcessMemoryUsageReport
    {
        ProcessMemoryUsageReport(std::nullptr_t) noexcept {}
        ProcessMemoryUsageReport(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Diagnostics::IProcessMemoryUsageReport(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SystemCpuUsage : llm:OS::System::Diagnostics::ISystemCpuUsage
    {
        SystemCpuUsage(std::nullptr_t) noexcept {}
        SystemCpuUsage(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Diagnostics::ISystemCpuUsage(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SystemCpuUsageReport : llm:OS::System::Diagnostics::ISystemCpuUsageReport
    {
        SystemCpuUsageReport(std::nullptr_t) noexcept {}
        SystemCpuUsageReport(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Diagnostics::ISystemCpuUsageReport(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SystemDiagnosticInfo : llm:OS::System::Diagnostics::ISystemDiagnosticInfo
    {
        SystemDiagnosticInfo(std::nullptr_t) noexcept {}
        SystemDiagnosticInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Diagnostics::ISystemDiagnosticInfo(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentSystem();
        static auto IsArchitectureSupported(llm:OS::System::ProcessorArchitecture const& type);
        [[nodiscard]] static auto PreferredArchitecture();
    };
    struct __declspec(empty_bases) SystemMemoryUsage : llm:OS::System::Diagnostics::ISystemMemoryUsage
    {
        SystemMemoryUsage(std::nullptr_t) noexcept {}
        SystemMemoryUsage(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Diagnostics::ISystemMemoryUsage(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SystemMemoryUsageReport : llm:OS::System::Diagnostics::ISystemMemoryUsageReport
    {
        SystemMemoryUsageReport(std::nullptr_t) noexcept {}
        SystemMemoryUsageReport(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Diagnostics::ISystemMemoryUsageReport(ptr, take_ownership_from_abi) {}
    };
}
#endif
