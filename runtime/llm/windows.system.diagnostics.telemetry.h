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
#ifndef LLM_OS_System_Diagnostics_Telemetry_H
#define LLM_OS_System_Diagnostics_Telemetry_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.System.Diagnostics.h"
#include "llm/impl/Windows.System.Diagnostics.Telemetry.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Diagnostics::Telemetry::PlatformTelemetryRegistrationResult) consume_Windows_System_Diagnostics_Telemetry_IPlatformTelemetryClientStatics<D>::Register(param::hstring const& id) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::Telemetry::IPlatformTelemetryClientStatics)->Register(*(void**)(&id), &result));
        return llm::OS::System::Diagnostics::Telemetry::PlatformTelemetryRegistrationResult{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Diagnostics::Telemetry::PlatformTelemetryRegistrationResult) consume_Windows_System_Diagnostics_Telemetry_IPlatformTelemetryClientStatics<D>::Register(param::hstring const& id, llm::OS::System::Diagnostics::Telemetry::PlatformTelemetryRegistrationSettings const& settings) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::Telemetry::IPlatformTelemetryClientStatics)->RegisterWithSettings(*(void**)(&id), *(void**)(&settings), &result));
        return llm::OS::System::Diagnostics::Telemetry::PlatformTelemetryRegistrationResult{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Diagnostics::Telemetry::PlatformTelemetryRegistrationStatus) consume_Windows_System_Diagnostics_Telemetry_IPlatformTelemetryRegistrationResult<D>::Status() const
    {
        llm::OS::System::Diagnostics::Telemetry::PlatformTelemetryRegistrationStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::Telemetry::IPlatformTelemetryRegistrationResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_System_Diagnostics_Telemetry_IPlatformTelemetryRegistrationSettings<D>::StorageSize() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::Telemetry::IPlatformTelemetryRegistrationSettings)->get_StorageSize(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_Diagnostics_Telemetry_IPlatformTelemetryRegistrationSettings<D>::StorageSize(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::Telemetry::IPlatformTelemetryRegistrationSettings)->put_StorageSize(value));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_System_Diagnostics_Telemetry_IPlatformTelemetryRegistrationSettings<D>::UploadQuotaSize() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::Telemetry::IPlatformTelemetryRegistrationSettings)->get_UploadQuotaSize(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_Diagnostics_Telemetry_IPlatformTelemetryRegistrationSettings<D>::UploadQuotaSize(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::Telemetry::IPlatformTelemetryRegistrationSettings)->put_UploadQuotaSize(value));
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Diagnostics::Telemetry::IPlatformTelemetryClientStatics> : produce_base<D, llm::OS::System::Diagnostics::Telemetry::IPlatformTelemetryClientStatics>
    {
        int32_t __stdcall Register(void* id, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::Diagnostics::Telemetry::PlatformTelemetryRegistrationResult>(this->shim().Register(*reinterpret_cast<hstring const*>(&id)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RegisterWithSettings(void* id, void* settings, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::Diagnostics::Telemetry::PlatformTelemetryRegistrationResult>(this->shim().Register(*reinterpret_cast<hstring const*>(&id), *reinterpret_cast<llm::OS::System::Diagnostics::Telemetry::PlatformTelemetryRegistrationSettings const*>(&settings)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Diagnostics::Telemetry::IPlatformTelemetryRegistrationResult> : produce_base<D, llm::OS::System::Diagnostics::Telemetry::IPlatformTelemetryRegistrationResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::Diagnostics::Telemetry::PlatformTelemetryRegistrationStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Diagnostics::Telemetry::IPlatformTelemetryRegistrationSettings> : produce_base<D, llm::OS::System::Diagnostics::Telemetry::IPlatformTelemetryRegistrationSettings>
    {
        int32_t __stdcall get_StorageSize(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().StorageSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_StorageSize(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StorageSize(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UploadQuotaSize(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().UploadQuotaSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_UploadQuotaSize(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UploadQuotaSize(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::System::Diagnostics::Telemetry
{
    inline auto PlatformTelemetryClient::Register(param::hstring const& id)
    {
        return impl::call_factory<PlatformTelemetryClient, IPlatformTelemetryClientStatics>([&](IPlatformTelemetryClientStatics const& f) { return f.Register(id); });
    }
    inline auto PlatformTelemetryClient::Register(param::hstring const& id, llm::OS::System::Diagnostics::Telemetry::PlatformTelemetryRegistrationSettings const& settings)
    {
        return impl::call_factory<PlatformTelemetryClient, IPlatformTelemetryClientStatics>([&](IPlatformTelemetryClientStatics const& f) { return f.Register(id, settings); });
    }
    inline PlatformTelemetryRegistrationSettings::PlatformTelemetryRegistrationSettings() :
        PlatformTelemetryRegistrationSettings(impl::call_factory_cast<PlatformTelemetryRegistrationSettings(*)(llm::OS::Foundation::IActivationFactory const&), PlatformTelemetryRegistrationSettings>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<PlatformTelemetryRegistrationSettings>(); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::System::Diagnostics::Telemetry::IPlatformTelemetryClientStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::Telemetry::IPlatformTelemetryRegistrationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::Telemetry::IPlatformTelemetryRegistrationSettings> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::Telemetry::PlatformTelemetryClient> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::Telemetry::PlatformTelemetryRegistrationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::Telemetry::PlatformTelemetryRegistrationSettings> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
