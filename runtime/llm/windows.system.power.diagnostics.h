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
#ifndef LLM_OS_System_Power_Diagnostics_H
#define LLM_OS_System_Power_Diagnostics_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.System.Power.h"
#include "llm/impl/Windows.System.Power.Diagnostics.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_System_Power_Diagnostics_IBackgroundEnergyDiagnosticsStatics<D>::DeviceSpecificConversionFactor() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::Diagnostics::IBackgroundEnergyDiagnosticsStatics)->get_DeviceSpecificConversionFactor(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_System_Power_Diagnostics_IBackgroundEnergyDiagnosticsStatics<D>::ComputeTotalEnergyUsage() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::Diagnostics::IBackgroundEnergyDiagnosticsStatics)->ComputeTotalEnergyUsage(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_Power_Diagnostics_IBackgroundEnergyDiagnosticsStatics<D>::ResetTotalEnergyUsage() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::Diagnostics::IBackgroundEnergyDiagnosticsStatics)->ResetTotalEnergyUsage());
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_System_Power_Diagnostics_IForegroundEnergyDiagnosticsStatics<D>::DeviceSpecificConversionFactor() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::Diagnostics::IForegroundEnergyDiagnosticsStatics)->get_DeviceSpecificConversionFactor(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_System_Power_Diagnostics_IForegroundEnergyDiagnosticsStatics<D>::ComputeTotalEnergyUsage() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::Diagnostics::IForegroundEnergyDiagnosticsStatics)->ComputeTotalEnergyUsage(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_Power_Diagnostics_IForegroundEnergyDiagnosticsStatics<D>::ResetTotalEnergyUsage() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::Diagnostics::IForegroundEnergyDiagnosticsStatics)->ResetTotalEnergyUsage());
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Power::Diagnostics::IBackgroundEnergyDiagnosticsStatics> : produce_base<D, llm::OS::System::Power::Diagnostics::IBackgroundEnergyDiagnosticsStatics>
    {
        int32_t __stdcall get_DeviceSpecificConversionFactor(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().DeviceSpecificConversionFactor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ComputeTotalEnergyUsage(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().ComputeTotalEnergyUsage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ResetTotalEnergyUsage() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ResetTotalEnergyUsage();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Power::Diagnostics::IForegroundEnergyDiagnosticsStatics> : produce_base<D, llm::OS::System::Power::Diagnostics::IForegroundEnergyDiagnosticsStatics>
    {
        int32_t __stdcall get_DeviceSpecificConversionFactor(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().DeviceSpecificConversionFactor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ComputeTotalEnergyUsage(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().ComputeTotalEnergyUsage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ResetTotalEnergyUsage() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ResetTotalEnergyUsage();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::System::Power::Diagnostics
{
    inline auto BackgroundEnergyDiagnostics::DeviceSpecificConversionFactor()
    {
        return impl::call_factory_cast<double(*)(IBackgroundEnergyDiagnosticsStatics const&), BackgroundEnergyDiagnostics, IBackgroundEnergyDiagnosticsStatics>([](IBackgroundEnergyDiagnosticsStatics const& f) { return f.DeviceSpecificConversionFactor(); });
    }
    inline auto BackgroundEnergyDiagnostics::ComputeTotalEnergyUsage()
    {
        return impl::call_factory_cast<uint64_t(*)(IBackgroundEnergyDiagnosticsStatics const&), BackgroundEnergyDiagnostics, IBackgroundEnergyDiagnosticsStatics>([](IBackgroundEnergyDiagnosticsStatics const& f) { return f.ComputeTotalEnergyUsage(); });
    }
    inline auto BackgroundEnergyDiagnostics::ResetTotalEnergyUsage()
    {
        impl::call_factory_cast<void(*)(IBackgroundEnergyDiagnosticsStatics const&), BackgroundEnergyDiagnostics, IBackgroundEnergyDiagnosticsStatics>([](IBackgroundEnergyDiagnosticsStatics const& f) { return f.ResetTotalEnergyUsage(); });
    }
    inline auto ForegroundEnergyDiagnostics::DeviceSpecificConversionFactor()
    {
        return impl::call_factory_cast<double(*)(IForegroundEnergyDiagnosticsStatics const&), ForegroundEnergyDiagnostics, IForegroundEnergyDiagnosticsStatics>([](IForegroundEnergyDiagnosticsStatics const& f) { return f.DeviceSpecificConversionFactor(); });
    }
    inline auto ForegroundEnergyDiagnostics::ComputeTotalEnergyUsage()
    {
        return impl::call_factory_cast<uint64_t(*)(IForegroundEnergyDiagnosticsStatics const&), ForegroundEnergyDiagnostics, IForegroundEnergyDiagnosticsStatics>([](IForegroundEnergyDiagnosticsStatics const& f) { return f.ComputeTotalEnergyUsage(); });
    }
    inline auto ForegroundEnergyDiagnostics::ResetTotalEnergyUsage()
    {
        impl::call_factory_cast<void(*)(IForegroundEnergyDiagnosticsStatics const&), ForegroundEnergyDiagnostics, IForegroundEnergyDiagnosticsStatics>([](IForegroundEnergyDiagnosticsStatics const& f) { return f.ResetTotalEnergyUsage(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::System::Power::Diagnostics::IBackgroundEnergyDiagnosticsStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Power::Diagnostics::IForegroundEnergyDiagnosticsStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Power::Diagnostics::BackgroundEnergyDiagnostics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Power::Diagnostics::ForegroundEnergyDiagnostics> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
