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
#ifndef LLM_OS_ApplicationModel_Appointments_AppointmentsProvider_H
#define LLM_OS_ApplicationModel_Appointments_AppointmentsProvider_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.ApplicationModel.Appointments.h"
#include "llm/impl/Windows.ApplicationModel.Appointments.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.ApplicationModel.Appointments.AppointmentsProvider.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Appointments::Appointment) consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IAddAppointmentOperation<D>::AppointmentInformation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation)->get_AppointmentInformation(&value));
        return llm::OS::ApplicationModel::Appointments::Appointment{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IAddAppointmentOperation<D>::SourcePackageFamilyName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation)->get_SourcePackageFamilyName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IAddAppointmentOperation<D>::ReportCompleted(param::hstring const& itemId) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation)->ReportCompleted(*(void**)(&itemId)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IAddAppointmentOperation<D>::ReportCanceled() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation)->ReportCanceled());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IAddAppointmentOperation<D>::ReportError(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation)->ReportError(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IAddAppointmentOperation<D>::DismissUI() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation)->DismissUI());
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IAppointmentsProviderLaunchActionVerbsStatics<D>::AddAppointment() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics)->get_AddAppointment(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IAppointmentsProviderLaunchActionVerbsStatics<D>::ReplaceAppointment() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics)->get_ReplaceAppointment(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IAppointmentsProviderLaunchActionVerbsStatics<D>::RemoveAppointment() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics)->get_RemoveAppointment(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IAppointmentsProviderLaunchActionVerbsStatics<D>::ShowTimeFrame() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics)->get_ShowTimeFrame(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IAppointmentsProviderLaunchActionVerbsStatics2<D>::ShowAppointmentDetails() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics2)->get_ShowAppointmentDetails(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IRemoveAppointmentOperation<D>::AppointmentId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation)->get_AppointmentId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>) consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IRemoveAppointmentOperation<D>::InstanceStartDate() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation)->get_InstanceStartDate(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IRemoveAppointmentOperation<D>::SourcePackageFamilyName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation)->get_SourcePackageFamilyName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IRemoveAppointmentOperation<D>::ReportCompleted() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation)->ReportCompleted());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IRemoveAppointmentOperation<D>::ReportCanceled() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation)->ReportCanceled());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IRemoveAppointmentOperation<D>::ReportError(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation)->ReportError(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IRemoveAppointmentOperation<D>::DismissUI() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation)->DismissUI());
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IReplaceAppointmentOperation<D>::AppointmentId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation)->get_AppointmentId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Appointments::Appointment) consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IReplaceAppointmentOperation<D>::AppointmentInformation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation)->get_AppointmentInformation(&value));
        return llm::OS::ApplicationModel::Appointments::Appointment{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>) consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IReplaceAppointmentOperation<D>::InstanceStartDate() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation)->get_InstanceStartDate(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IReplaceAppointmentOperation<D>::SourcePackageFamilyName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation)->get_SourcePackageFamilyName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IReplaceAppointmentOperation<D>::ReportCompleted(param::hstring const& itemId) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation)->ReportCompleted(*(void**)(&itemId)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IReplaceAppointmentOperation<D>::ReportCanceled() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation)->ReportCanceled());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IReplaceAppointmentOperation<D>::ReportError(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation)->ReportError(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IReplaceAppointmentOperation<D>::DismissUI() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation)->DismissUI());
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation> : produce_base<D, llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation>
    {
        int32_t __stdcall get_AppointmentInformation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Appointments::Appointment>(this->shim().AppointmentInformation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SourcePackageFamilyName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SourcePackageFamilyName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportCompleted(void* itemId) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportCompleted(*reinterpret_cast<hstring const*>(&itemId));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportCanceled() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportCanceled();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportError(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportError(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DismissUI() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DismissUI();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics> : produce_base<D, llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics>
    {
        int32_t __stdcall get_AddAppointment(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AddAppointment());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ReplaceAppointment(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ReplaceAppointment());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RemoveAppointment(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().RemoveAppointment());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ShowTimeFrame(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ShowTimeFrame());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics2> : produce_base<D, llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics2>
    {
        int32_t __stdcall get_ShowAppointmentDetails(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ShowAppointmentDetails());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation> : produce_base<D, llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation>
    {
        int32_t __stdcall get_AppointmentId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AppointmentId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InstanceStartDate(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>>(this->shim().InstanceStartDate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SourcePackageFamilyName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SourcePackageFamilyName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportCompleted() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportCompleted();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportCanceled() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportCanceled();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportError(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportError(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DismissUI() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DismissUI();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation> : produce_base<D, llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation>
    {
        int32_t __stdcall get_AppointmentId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AppointmentId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AppointmentInformation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Appointments::Appointment>(this->shim().AppointmentInformation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InstanceStartDate(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>>(this->shim().InstanceStartDate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SourcePackageFamilyName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SourcePackageFamilyName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportCompleted(void* itemId) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportCompleted(*reinterpret_cast<hstring const*>(&itemId));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportCanceled() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportCanceled();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportError(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportError(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DismissUI() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DismissUI();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::ApplicationModel::Appointments::AppointmentsProvider
{
    inline auto AppointmentsProviderLaunchActionVerbs::AddAppointment()
    {
        return impl::call_factory_cast<hstring(*)(IAppointmentsProviderLaunchActionVerbsStatics const&), AppointmentsProviderLaunchActionVerbs, IAppointmentsProviderLaunchActionVerbsStatics>([](IAppointmentsProviderLaunchActionVerbsStatics const& f) { return f.AddAppointment(); });
    }
    inline auto AppointmentsProviderLaunchActionVerbs::ReplaceAppointment()
    {
        return impl::call_factory_cast<hstring(*)(IAppointmentsProviderLaunchActionVerbsStatics const&), AppointmentsProviderLaunchActionVerbs, IAppointmentsProviderLaunchActionVerbsStatics>([](IAppointmentsProviderLaunchActionVerbsStatics const& f) { return f.ReplaceAppointment(); });
    }
    inline auto AppointmentsProviderLaunchActionVerbs::RemoveAppointment()
    {
        return impl::call_factory_cast<hstring(*)(IAppointmentsProviderLaunchActionVerbsStatics const&), AppointmentsProviderLaunchActionVerbs, IAppointmentsProviderLaunchActionVerbsStatics>([](IAppointmentsProviderLaunchActionVerbsStatics const& f) { return f.RemoveAppointment(); });
    }
    inline auto AppointmentsProviderLaunchActionVerbs::ShowTimeFrame()
    {
        return impl::call_factory_cast<hstring(*)(IAppointmentsProviderLaunchActionVerbsStatics const&), AppointmentsProviderLaunchActionVerbs, IAppointmentsProviderLaunchActionVerbsStatics>([](IAppointmentsProviderLaunchActionVerbsStatics const& f) { return f.ShowTimeFrame(); });
    }
    inline auto AppointmentsProviderLaunchActionVerbs::ShowAppointmentDetails()
    {
        return impl::call_factory_cast<hstring(*)(IAppointmentsProviderLaunchActionVerbsStatics2 const&), AppointmentsProviderLaunchActionVerbs, IAppointmentsProviderLaunchActionVerbsStatics2>([](IAppointmentsProviderLaunchActionVerbsStatics2 const& f) { return f.ShowAppointmentDetails(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::AddAppointmentOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::AppointmentsProviderLaunchActionVerbs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::RemoveAppointmentOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::ReplaceAppointmentOperation> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
