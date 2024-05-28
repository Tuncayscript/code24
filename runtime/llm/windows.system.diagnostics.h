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
#ifndef LLM_OS_System_Diagnostics_H
#define LLM_OS_System_Diagnostics_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.System.h"
#include "llm/impl/Windows.Data.Json.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.System.2.h"
#include "llm/impl/Windows.System.Diagnostics.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_System_Diagnostics_IDiagnosticActionResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IDiagnosticActionResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::ValueSet) consume_Windows_System_Diagnostics_IDiagnosticActionResult<D>::Results() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IDiagnosticActionResult)->get_Results(&value));
        return llm::OS::Foundation::Collections::ValueSet{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::System::Diagnostics::DiagnosticActionResult, llm::OS::System::Diagnostics::DiagnosticActionState>) consume_Windows_System_Diagnostics_IDiagnosticInvoker<D>::RunDiagnosticActionAsync(llm::OS::Data::Json::JsonObject const& context) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IDiagnosticInvoker)->RunDiagnosticActionAsync(*(void**)(&context), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::System::Diagnostics::DiagnosticActionResult, llm::OS::System::Diagnostics::DiagnosticActionState>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::System::Diagnostics::DiagnosticActionResult, llm::OS::System::Diagnostics::DiagnosticActionState>) consume_Windows_System_Diagnostics_IDiagnosticInvoker2<D>::RunDiagnosticActionFromStringAsync(param::hstring const& context) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IDiagnosticInvoker2)->RunDiagnosticActionFromStringAsync(*(void**)(&context), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::System::Diagnostics::DiagnosticActionResult, llm::OS::System::Diagnostics::DiagnosticActionState>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Diagnostics::DiagnosticInvoker) consume_Windows_System_Diagnostics_IDiagnosticInvokerStatics<D>::GetDefault() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IDiagnosticInvokerStatics)->GetDefault(&result));
        return llm::OS::System::Diagnostics::DiagnosticInvoker{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Diagnostics::DiagnosticInvoker) consume_Windows_System_Diagnostics_IDiagnosticInvokerStatics<D>::GetForUser(llm::OS::System::User const& user) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IDiagnosticInvokerStatics)->GetForUser(*(void**)(&user), &result));
        return llm::OS::System::Diagnostics::DiagnosticInvoker{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_Diagnostics_IDiagnosticInvokerStatics<D>::IsSupported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IDiagnosticInvokerStatics)->get_IsSupported(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Diagnostics::ProcessCpuUsageReport) consume_Windows_System_Diagnostics_IProcessCpuUsage<D>::GetReport() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessCpuUsage)->GetReport(&value));
        return llm::OS::System::Diagnostics::ProcessCpuUsageReport{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_System_Diagnostics_IProcessCpuUsageReport<D>::KernelTime() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessCpuUsageReport)->get_KernelTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_System_Diagnostics_IProcessCpuUsageReport<D>::UserTime() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessCpuUsageReport)->get_UserTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_System_Diagnostics_IProcessDiagnosticInfo<D>::ProcessId() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessDiagnosticInfo)->get_ProcessId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_Diagnostics_IProcessDiagnosticInfo<D>::ExecutableFileName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessDiagnosticInfo)->get_ExecutableFileName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Diagnostics::ProcessDiagnosticInfo) consume_Windows_System_Diagnostics_IProcessDiagnosticInfo<D>::Parent() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessDiagnosticInfo)->get_Parent(&value));
        return llm::OS::System::Diagnostics::ProcessDiagnosticInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_System_Diagnostics_IProcessDiagnosticInfo<D>::ProcessStartTime() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessDiagnosticInfo)->get_ProcessStartTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Diagnostics::ProcessDiskUsage) consume_Windows_System_Diagnostics_IProcessDiagnosticInfo<D>::DiskUsage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessDiagnosticInfo)->get_DiskUsage(&value));
        return llm::OS::System::Diagnostics::ProcessDiskUsage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Diagnostics::ProcessMemoryUsage) consume_Windows_System_Diagnostics_IProcessDiagnosticInfo<D>::MemoryUsage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessDiagnosticInfo)->get_MemoryUsage(&value));
        return llm::OS::System::Diagnostics::ProcessMemoryUsage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Diagnostics::ProcessCpuUsage) consume_Windows_System_Diagnostics_IProcessDiagnosticInfo<D>::CpuUsage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessDiagnosticInfo)->get_CpuUsage(&value));
        return llm::OS::System::Diagnostics::ProcessCpuUsage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::System::AppDiagnosticInfo>) consume_Windows_System_Diagnostics_IProcessDiagnosticInfo2<D>::GetAppDiagnosticInfos() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessDiagnosticInfo2)->GetAppDiagnosticInfos(&result));
        return llm::OS::Foundation::Collections::IVector<llm::OS::System::AppDiagnosticInfo>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_Diagnostics_IProcessDiagnosticInfo2<D>::IsPackaged() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessDiagnosticInfo2)->get_IsPackaged(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::System::Diagnostics::ProcessDiagnosticInfo>) consume_Windows_System_Diagnostics_IProcessDiagnosticInfoStatics<D>::GetForProcesses() const
    {
        void* processes{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessDiagnosticInfoStatics)->GetForProcesses(&processes));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::System::Diagnostics::ProcessDiagnosticInfo>{ processes, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Diagnostics::ProcessDiagnosticInfo) consume_Windows_System_Diagnostics_IProcessDiagnosticInfoStatics<D>::GetForCurrentProcess() const
    {
        void* processes{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessDiagnosticInfoStatics)->GetForCurrentProcess(&processes));
        return llm::OS::System::Diagnostics::ProcessDiagnosticInfo{ processes, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Diagnostics::ProcessDiagnosticInfo) consume_Windows_System_Diagnostics_IProcessDiagnosticInfoStatics2<D>::TryGetForProcessId(uint32_t processId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessDiagnosticInfoStatics2)->TryGetForProcessId(processId, &result));
        return llm::OS::System::Diagnostics::ProcessDiagnosticInfo{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Diagnostics::ProcessDiskUsageReport) consume_Windows_System_Diagnostics_IProcessDiskUsage<D>::GetReport() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessDiskUsage)->GetReport(&value));
        return llm::OS::System::Diagnostics::ProcessDiskUsageReport{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(int64_t) consume_Windows_System_Diagnostics_IProcessDiskUsageReport<D>::ReadOperationCount() const
    {
        int64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessDiskUsageReport)->get_ReadOperationCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int64_t) consume_Windows_System_Diagnostics_IProcessDiskUsageReport<D>::WriteOperationCount() const
    {
        int64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessDiskUsageReport)->get_WriteOperationCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int64_t) consume_Windows_System_Diagnostics_IProcessDiskUsageReport<D>::OtherOperationCount() const
    {
        int64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessDiskUsageReport)->get_OtherOperationCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int64_t) consume_Windows_System_Diagnostics_IProcessDiskUsageReport<D>::BytesReadCount() const
    {
        int64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessDiskUsageReport)->get_BytesReadCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int64_t) consume_Windows_System_Diagnostics_IProcessDiskUsageReport<D>::BytesWrittenCount() const
    {
        int64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessDiskUsageReport)->get_BytesWrittenCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int64_t) consume_Windows_System_Diagnostics_IProcessDiskUsageReport<D>::OtherBytesCount() const
    {
        int64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessDiskUsageReport)->get_OtherBytesCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Diagnostics::ProcessMemoryUsageReport) consume_Windows_System_Diagnostics_IProcessMemoryUsage<D>::GetReport() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessMemoryUsage)->GetReport(&value));
        return llm::OS::System::Diagnostics::ProcessMemoryUsageReport{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_System_Diagnostics_IProcessMemoryUsageReport<D>::NonPagedPoolSizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessMemoryUsageReport)->get_NonPagedPoolSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_System_Diagnostics_IProcessMemoryUsageReport<D>::PageFaultCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessMemoryUsageReport)->get_PageFaultCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_System_Diagnostics_IProcessMemoryUsageReport<D>::PageFileSizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessMemoryUsageReport)->get_PageFileSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_System_Diagnostics_IProcessMemoryUsageReport<D>::PagedPoolSizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessMemoryUsageReport)->get_PagedPoolSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_System_Diagnostics_IProcessMemoryUsageReport<D>::PeakNonPagedPoolSizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessMemoryUsageReport)->get_PeakNonPagedPoolSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_System_Diagnostics_IProcessMemoryUsageReport<D>::PeakPageFileSizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessMemoryUsageReport)->get_PeakPageFileSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_System_Diagnostics_IProcessMemoryUsageReport<D>::PeakPagedPoolSizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessMemoryUsageReport)->get_PeakPagedPoolSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_System_Diagnostics_IProcessMemoryUsageReport<D>::PeakVirtualMemorySizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessMemoryUsageReport)->get_PeakVirtualMemorySizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_System_Diagnostics_IProcessMemoryUsageReport<D>::PeakWorkingSetSizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessMemoryUsageReport)->get_PeakWorkingSetSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_System_Diagnostics_IProcessMemoryUsageReport<D>::PrivatePageCount() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessMemoryUsageReport)->get_PrivatePageCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_System_Diagnostics_IProcessMemoryUsageReport<D>::VirtualMemorySizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessMemoryUsageReport)->get_VirtualMemorySizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_System_Diagnostics_IProcessMemoryUsageReport<D>::WorkingSetSizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::IProcessMemoryUsageReport)->get_WorkingSetSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Diagnostics::SystemCpuUsageReport) consume_Windows_System_Diagnostics_ISystemCpuUsage<D>::GetReport() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::ISystemCpuUsage)->GetReport(&value));
        return llm::OS::System::Diagnostics::SystemCpuUsageReport{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_System_Diagnostics_ISystemCpuUsageReport<D>::KernelTime() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::ISystemCpuUsageReport)->get_KernelTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_System_Diagnostics_ISystemCpuUsageReport<D>::UserTime() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::ISystemCpuUsageReport)->get_UserTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_System_Diagnostics_ISystemCpuUsageReport<D>::IdleTime() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::ISystemCpuUsageReport)->get_IdleTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Diagnostics::SystemMemoryUsage) consume_Windows_System_Diagnostics_ISystemDiagnosticInfo<D>::MemoryUsage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::ISystemDiagnosticInfo)->get_MemoryUsage(&value));
        return llm::OS::System::Diagnostics::SystemMemoryUsage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Diagnostics::SystemCpuUsage) consume_Windows_System_Diagnostics_ISystemDiagnosticInfo<D>::CpuUsage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::ISystemDiagnosticInfo)->get_CpuUsage(&value));
        return llm::OS::System::Diagnostics::SystemCpuUsage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Diagnostics::SystemDiagnosticInfo) consume_Windows_System_Diagnostics_ISystemDiagnosticInfoStatics<D>::GetForCurrentSystem() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::ISystemDiagnosticInfoStatics)->GetForCurrentSystem(&value));
        return llm::OS::System::Diagnostics::SystemDiagnosticInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_Diagnostics_ISystemDiagnosticInfoStatics2<D>::IsArchitectureSupported(llm::OS::System::ProcessorArchitecture const& type) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::ISystemDiagnosticInfoStatics2)->IsArchitectureSupported(static_cast<int32_t>(type), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::ProcessorArchitecture) consume_Windows_System_Diagnostics_ISystemDiagnosticInfoStatics2<D>::PreferredArchitecture() const
    {
        llm::OS::System::ProcessorArchitecture value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::ISystemDiagnosticInfoStatics2)->get_PreferredArchitecture(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Diagnostics::SystemMemoryUsageReport) consume_Windows_System_Diagnostics_ISystemMemoryUsage<D>::GetReport() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::ISystemMemoryUsage)->GetReport(&value));
        return llm::OS::System::Diagnostics::SystemMemoryUsageReport{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_System_Diagnostics_ISystemMemoryUsageReport<D>::TotalPhysicalSizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::ISystemMemoryUsageReport)->get_TotalPhysicalSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_System_Diagnostics_ISystemMemoryUsageReport<D>::AvailableSizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::ISystemMemoryUsageReport)->get_AvailableSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_System_Diagnostics_ISystemMemoryUsageReport<D>::CommittedSizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::ISystemMemoryUsageReport)->get_CommittedSizeInBytes(&value));
        return value;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Diagnostics::IDiagnosticActionResult> : produce_base<D, llm::OS::System::Diagnostics::IDiagnosticActionResult>
    {
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Results(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::ValueSet>(this->shim().Results());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Diagnostics::IDiagnosticInvoker> : produce_base<D, llm::OS::System::Diagnostics::IDiagnosticInvoker>
    {
        int32_t __stdcall RunDiagnosticActionAsync(void* context, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::System::Diagnostics::DiagnosticActionResult, llm::OS::System::Diagnostics::DiagnosticActionState>>(this->shim().RunDiagnosticActionAsync(*reinterpret_cast<llm::OS::Data::Json::JsonObject const*>(&context)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Diagnostics::IDiagnosticInvoker2> : produce_base<D, llm::OS::System::Diagnostics::IDiagnosticInvoker2>
    {
        int32_t __stdcall RunDiagnosticActionFromStringAsync(void* context, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::System::Diagnostics::DiagnosticActionResult, llm::OS::System::Diagnostics::DiagnosticActionState>>(this->shim().RunDiagnosticActionFromStringAsync(*reinterpret_cast<hstring const*>(&context)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Diagnostics::IDiagnosticInvokerStatics> : produce_base<D, llm::OS::System::Diagnostics::IDiagnosticInvokerStatics>
    {
        int32_t __stdcall GetDefault(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::Diagnostics::DiagnosticInvoker>(this->shim().GetDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetForUser(void* user, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::Diagnostics::DiagnosticInvoker>(this->shim().GetForUser(*reinterpret_cast<llm::OS::System::User const*>(&user)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsSupported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Diagnostics::IProcessCpuUsage> : produce_base<D, llm::OS::System::Diagnostics::IProcessCpuUsage>
    {
        int32_t __stdcall GetReport(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::Diagnostics::ProcessCpuUsageReport>(this->shim().GetReport());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Diagnostics::IProcessCpuUsageReport> : produce_base<D, llm::OS::System::Diagnostics::IProcessCpuUsageReport>
    {
        int32_t __stdcall get_KernelTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().KernelTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UserTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().UserTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Diagnostics::IProcessDiagnosticInfo> : produce_base<D, llm::OS::System::Diagnostics::IProcessDiagnosticInfo>
    {
        int32_t __stdcall get_ProcessId(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().ProcessId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExecutableFileName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ExecutableFileName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Parent(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::Diagnostics::ProcessDiagnosticInfo>(this->shim().Parent());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProcessStartTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().ProcessStartTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DiskUsage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::Diagnostics::ProcessDiskUsage>(this->shim().DiskUsage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MemoryUsage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::Diagnostics::ProcessMemoryUsage>(this->shim().MemoryUsage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CpuUsage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::Diagnostics::ProcessCpuUsage>(this->shim().CpuUsage());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Diagnostics::IProcessDiagnosticInfo2> : produce_base<D, llm::OS::System::Diagnostics::IProcessDiagnosticInfo2>
    {
        int32_t __stdcall GetAppDiagnosticInfos(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::System::AppDiagnosticInfo>>(this->shim().GetAppDiagnosticInfos());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsPackaged(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsPackaged());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Diagnostics::IProcessDiagnosticInfoStatics> : produce_base<D, llm::OS::System::Diagnostics::IProcessDiagnosticInfoStatics>
    {
        int32_t __stdcall GetForProcesses(void** processes) noexcept final try
        {
            clear_abi(processes);
            typename D::abi_guard guard(this->shim());
            *processes = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::System::Diagnostics::ProcessDiagnosticInfo>>(this->shim().GetForProcesses());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetForCurrentProcess(void** processes) noexcept final try
        {
            clear_abi(processes);
            typename D::abi_guard guard(this->shim());
            *processes = detach_from<llm::OS::System::Diagnostics::ProcessDiagnosticInfo>(this->shim().GetForCurrentProcess());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Diagnostics::IProcessDiagnosticInfoStatics2> : produce_base<D, llm::OS::System::Diagnostics::IProcessDiagnosticInfoStatics2>
    {
        int32_t __stdcall TryGetForProcessId(uint32_t processId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::Diagnostics::ProcessDiagnosticInfo>(this->shim().TryGetForProcessId(processId));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Diagnostics::IProcessDiskUsage> : produce_base<D, llm::OS::System::Diagnostics::IProcessDiskUsage>
    {
        int32_t __stdcall GetReport(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::Diagnostics::ProcessDiskUsageReport>(this->shim().GetReport());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Diagnostics::IProcessDiskUsageReport> : produce_base<D, llm::OS::System::Diagnostics::IProcessDiskUsageReport>
    {
        int32_t __stdcall get_ReadOperationCount(int64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int64_t>(this->shim().ReadOperationCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WriteOperationCount(int64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int64_t>(this->shim().WriteOperationCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OtherOperationCount(int64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int64_t>(this->shim().OtherOperationCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BytesReadCount(int64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int64_t>(this->shim().BytesReadCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BytesWrittenCount(int64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int64_t>(this->shim().BytesWrittenCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OtherBytesCount(int64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int64_t>(this->shim().OtherBytesCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Diagnostics::IProcessMemoryUsage> : produce_base<D, llm::OS::System::Diagnostics::IProcessMemoryUsage>
    {
        int32_t __stdcall GetReport(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::Diagnostics::ProcessMemoryUsageReport>(this->shim().GetReport());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Diagnostics::IProcessMemoryUsageReport> : produce_base<D, llm::OS::System::Diagnostics::IProcessMemoryUsageReport>
    {
        int32_t __stdcall get_NonPagedPoolSizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().NonPagedPoolSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PageFaultCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().PageFaultCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PageFileSizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().PageFileSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PagedPoolSizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().PagedPoolSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PeakNonPagedPoolSizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().PeakNonPagedPoolSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PeakPageFileSizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().PeakPageFileSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PeakPagedPoolSizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().PeakPagedPoolSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PeakVirtualMemorySizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().PeakVirtualMemorySizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PeakWorkingSetSizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().PeakWorkingSetSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PrivatePageCount(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().PrivatePageCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VirtualMemorySizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().VirtualMemorySizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WorkingSetSizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().WorkingSetSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Diagnostics::ISystemCpuUsage> : produce_base<D, llm::OS::System::Diagnostics::ISystemCpuUsage>
    {
        int32_t __stdcall GetReport(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::Diagnostics::SystemCpuUsageReport>(this->shim().GetReport());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Diagnostics::ISystemCpuUsageReport> : produce_base<D, llm::OS::System::Diagnostics::ISystemCpuUsageReport>
    {
        int32_t __stdcall get_KernelTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().KernelTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UserTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().UserTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IdleTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().IdleTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Diagnostics::ISystemDiagnosticInfo> : produce_base<D, llm::OS::System::Diagnostics::ISystemDiagnosticInfo>
    {
        int32_t __stdcall get_MemoryUsage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::Diagnostics::SystemMemoryUsage>(this->shim().MemoryUsage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CpuUsage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::Diagnostics::SystemCpuUsage>(this->shim().CpuUsage());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Diagnostics::ISystemDiagnosticInfoStatics> : produce_base<D, llm::OS::System::Diagnostics::ISystemDiagnosticInfoStatics>
    {
        int32_t __stdcall GetForCurrentSystem(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::Diagnostics::SystemDiagnosticInfo>(this->shim().GetForCurrentSystem());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Diagnostics::ISystemDiagnosticInfoStatics2> : produce_base<D, llm::OS::System::Diagnostics::ISystemDiagnosticInfoStatics2>
    {
        int32_t __stdcall IsArchitectureSupported(int32_t type, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsArchitectureSupported(*reinterpret_cast<llm::OS::System::ProcessorArchitecture const*>(&type)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PreferredArchitecture(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::ProcessorArchitecture>(this->shim().PreferredArchitecture());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Diagnostics::ISystemMemoryUsage> : produce_base<D, llm::OS::System::Diagnostics::ISystemMemoryUsage>
    {
        int32_t __stdcall GetReport(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::Diagnostics::SystemMemoryUsageReport>(this->shim().GetReport());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Diagnostics::ISystemMemoryUsageReport> : produce_base<D, llm::OS::System::Diagnostics::ISystemMemoryUsageReport>
    {
        int32_t __stdcall get_TotalPhysicalSizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().TotalPhysicalSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AvailableSizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().AvailableSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CommittedSizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().CommittedSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::System::Diagnostics
{
    inline auto DiagnosticInvoker::GetDefault()
    {
        return impl::call_factory_cast<llm::OS::System::Diagnostics::DiagnosticInvoker(*)(IDiagnosticInvokerStatics const&), DiagnosticInvoker, IDiagnosticInvokerStatics>([](IDiagnosticInvokerStatics const& f) { return f.GetDefault(); });
    }
    inline auto DiagnosticInvoker::GetForUser(llm::OS::System::User const& user)
    {
        return impl::call_factory<DiagnosticInvoker, IDiagnosticInvokerStatics>([&](IDiagnosticInvokerStatics const& f) { return f.GetForUser(user); });
    }
    inline auto DiagnosticInvoker::IsSupported()
    {
        return impl::call_factory_cast<bool(*)(IDiagnosticInvokerStatics const&), DiagnosticInvoker, IDiagnosticInvokerStatics>([](IDiagnosticInvokerStatics const& f) { return f.IsSupported(); });
    }
    inline auto ProcessDiagnosticInfo::GetForProcesses()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<llm::OS::System::Diagnostics::ProcessDiagnosticInfo>(*)(IProcessDiagnosticInfoStatics const&), ProcessDiagnosticInfo, IProcessDiagnosticInfoStatics>([](IProcessDiagnosticInfoStatics const& f) { return f.GetForProcesses(); });
    }
    inline auto ProcessDiagnosticInfo::GetForCurrentProcess()
    {
        return impl::call_factory_cast<llm::OS::System::Diagnostics::ProcessDiagnosticInfo(*)(IProcessDiagnosticInfoStatics const&), ProcessDiagnosticInfo, IProcessDiagnosticInfoStatics>([](IProcessDiagnosticInfoStatics const& f) { return f.GetForCurrentProcess(); });
    }
    inline auto ProcessDiagnosticInfo::TryGetForProcessId(uint32_t processId)
    {
        return impl::call_factory<ProcessDiagnosticInfo, IProcessDiagnosticInfoStatics2>([&](IProcessDiagnosticInfoStatics2 const& f) { return f.TryGetForProcessId(processId); });
    }
    inline auto SystemDiagnosticInfo::GetForCurrentSystem()
    {
        return impl::call_factory_cast<llm::OS::System::Diagnostics::SystemDiagnosticInfo(*)(ISystemDiagnosticInfoStatics const&), SystemDiagnosticInfo, ISystemDiagnosticInfoStatics>([](ISystemDiagnosticInfoStatics const& f) { return f.GetForCurrentSystem(); });
    }
    inline auto SystemDiagnosticInfo::IsArchitectureSupported(llm::OS::System::ProcessorArchitecture const& type)
    {
        return impl::call_factory<SystemDiagnosticInfo, ISystemDiagnosticInfoStatics2>([&](ISystemDiagnosticInfoStatics2 const& f) { return f.IsArchitectureSupported(type); });
    }
    inline auto SystemDiagnosticInfo::PreferredArchitecture()
    {
        return impl::call_factory_cast<llm::OS::System::ProcessorArchitecture(*)(ISystemDiagnosticInfoStatics2 const&), SystemDiagnosticInfo, ISystemDiagnosticInfoStatics2>([](ISystemDiagnosticInfoStatics2 const& f) { return f.PreferredArchitecture(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::System::Diagnostics::IDiagnosticActionResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::IDiagnosticInvoker> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::IDiagnosticInvoker2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::IDiagnosticInvokerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::IProcessCpuUsage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::IProcessCpuUsageReport> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::IProcessDiagnosticInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::IProcessDiagnosticInfo2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::IProcessDiagnosticInfoStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::IProcessDiagnosticInfoStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::IProcessDiskUsage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::IProcessDiskUsageReport> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::IProcessMemoryUsage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::IProcessMemoryUsageReport> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::ISystemCpuUsage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::ISystemCpuUsageReport> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::ISystemDiagnosticInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::ISystemDiagnosticInfoStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::ISystemDiagnosticInfoStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::ISystemMemoryUsage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::ISystemMemoryUsageReport> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::DiagnosticActionResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::DiagnosticInvoker> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::ProcessCpuUsage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::ProcessCpuUsageReport> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::ProcessDiagnosticInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::ProcessDiskUsage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::ProcessDiskUsageReport> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::ProcessMemoryUsage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::ProcessMemoryUsageReport> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::SystemCpuUsage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::SystemCpuUsageReport> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::SystemDiagnosticInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::SystemMemoryUsage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::SystemMemoryUsageReport> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
