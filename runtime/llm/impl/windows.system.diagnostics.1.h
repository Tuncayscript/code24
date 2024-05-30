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
#ifndef LLM_OS_System_Diagnostics_1_H
#define LLM_OS_System_Diagnostics_1_H
#include "llm/impl/Windows.System.Diagnostics.0.h"
LLM_EXPORT namespace llm:OS::System::Diagnostics
{
    struct __declspec(empty_bases) IDiagnosticActionResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDiagnosticActionResult>
    {
        IDiagnosticActionResult(std::nullptr_t = nullptr) noexcept {}
        IDiagnosticActionResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDiagnosticInvoker :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDiagnosticInvoker>
    {
        IDiagnosticInvoker(std::nullptr_t = nullptr) noexcept {}
        IDiagnosticInvoker(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDiagnosticInvoker2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDiagnosticInvoker2>
    {
        IDiagnosticInvoker2(std::nullptr_t = nullptr) noexcept {}
        IDiagnosticInvoker2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDiagnosticInvokerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDiagnosticInvokerStatics>
    {
        IDiagnosticInvokerStatics(std::nullptr_t = nullptr) noexcept {}
        IDiagnosticInvokerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProcessCpuUsage :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProcessCpuUsage>
    {
        IProcessCpuUsage(std::nullptr_t = nullptr) noexcept {}
        IProcessCpuUsage(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProcessCpuUsageReport :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProcessCpuUsageReport>
    {
        IProcessCpuUsageReport(std::nullptr_t = nullptr) noexcept {}
        IProcessCpuUsageReport(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProcessDiagnosticInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProcessDiagnosticInfo>
    {
        IProcessDiagnosticInfo(std::nullptr_t = nullptr) noexcept {}
        IProcessDiagnosticInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProcessDiagnosticInfo2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProcessDiagnosticInfo2>
    {
        IProcessDiagnosticInfo2(std::nullptr_t = nullptr) noexcept {}
        IProcessDiagnosticInfo2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProcessDiagnosticInfoStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProcessDiagnosticInfoStatics>
    {
        IProcessDiagnosticInfoStatics(std::nullptr_t = nullptr) noexcept {}
        IProcessDiagnosticInfoStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProcessDiagnosticInfoStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProcessDiagnosticInfoStatics2>
    {
        IProcessDiagnosticInfoStatics2(std::nullptr_t = nullptr) noexcept {}
        IProcessDiagnosticInfoStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProcessDiskUsage :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProcessDiskUsage>
    {
        IProcessDiskUsage(std::nullptr_t = nullptr) noexcept {}
        IProcessDiskUsage(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProcessDiskUsageReport :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProcessDiskUsageReport>
    {
        IProcessDiskUsageReport(std::nullptr_t = nullptr) noexcept {}
        IProcessDiskUsageReport(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProcessMemoryUsage :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProcessMemoryUsage>
    {
        IProcessMemoryUsage(std::nullptr_t = nullptr) noexcept {}
        IProcessMemoryUsage(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProcessMemoryUsageReport :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProcessMemoryUsageReport>
    {
        IProcessMemoryUsageReport(std::nullptr_t = nullptr) noexcept {}
        IProcessMemoryUsageReport(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemCpuUsage :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemCpuUsage>
    {
        ISystemCpuUsage(std::nullptr_t = nullptr) noexcept {}
        ISystemCpuUsage(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemCpuUsageReport :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemCpuUsageReport>
    {
        ISystemCpuUsageReport(std::nullptr_t = nullptr) noexcept {}
        ISystemCpuUsageReport(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemDiagnosticInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemDiagnosticInfo>
    {
        ISystemDiagnosticInfo(std::nullptr_t = nullptr) noexcept {}
        ISystemDiagnosticInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemDiagnosticInfoStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemDiagnosticInfoStatics>
    {
        ISystemDiagnosticInfoStatics(std::nullptr_t = nullptr) noexcept {}
        ISystemDiagnosticInfoStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemDiagnosticInfoStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemDiagnosticInfoStatics2>
    {
        ISystemDiagnosticInfoStatics2(std::nullptr_t = nullptr) noexcept {}
        ISystemDiagnosticInfoStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemMemoryUsage :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemMemoryUsage>
    {
        ISystemMemoryUsage(std::nullptr_t = nullptr) noexcept {}
        ISystemMemoryUsage(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemMemoryUsageReport :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemMemoryUsageReport>
    {
        ISystemMemoryUsageReport(std::nullptr_t = nullptr) noexcept {}
        ISystemMemoryUsageReport(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
