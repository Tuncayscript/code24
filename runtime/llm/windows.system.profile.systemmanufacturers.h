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
#ifndef LLM_OS_System_Profile_SystemManufacturers_H
#define LLM_OS_System_Profile_SystemManufacturers_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.System.Profile.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.System.Profile.SystemManufacturers.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_System_Profile_SystemManufacturers_IOemSupportInfo<D>::SupportLink() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Profile::SystemManufacturers::IOemSupportInfo)->get_SupportLink(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_System_Profile_SystemManufacturers_IOemSupportInfo<D>::SupportAppLink() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Profile::SystemManufacturers::IOemSupportInfo)->get_SupportAppLink(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_Profile_SystemManufacturers_IOemSupportInfo<D>::SupportProvider() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Profile::SystemManufacturers::IOemSupportInfo)->get_SupportProvider(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_Profile_SystemManufacturers_ISmbiosInformationStatics<D>::SerialNumber() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Profile::SystemManufacturers::ISmbiosInformationStatics)->get_SerialNumber(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_Profile_SystemManufacturers_ISystemSupportDeviceInfo<D>::OperatingSystem() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Profile::SystemManufacturers::ISystemSupportDeviceInfo)->get_OperatingSystem(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_Profile_SystemManufacturers_ISystemSupportDeviceInfo<D>::FriendlyName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Profile::SystemManufacturers::ISystemSupportDeviceInfo)->get_FriendlyName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_Profile_SystemManufacturers_ISystemSupportDeviceInfo<D>::SystemManufacturer() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Profile::SystemManufacturers::ISystemSupportDeviceInfo)->get_SystemManufacturer(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_Profile_SystemManufacturers_ISystemSupportDeviceInfo<D>::SystemProductName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Profile::SystemManufacturers::ISystemSupportDeviceInfo)->get_SystemProductName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_Profile_SystemManufacturers_ISystemSupportDeviceInfo<D>::SystemSku() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Profile::SystemManufacturers::ISystemSupportDeviceInfo)->get_SystemSku(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_Profile_SystemManufacturers_ISystemSupportDeviceInfo<D>::SystemHardwareVersion() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Profile::SystemManufacturers::ISystemSupportDeviceInfo)->get_SystemHardwareVersion(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_Profile_SystemManufacturers_ISystemSupportDeviceInfo<D>::SystemFirmwareVersion() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Profile::SystemManufacturers::ISystemSupportDeviceInfo)->get_SystemFirmwareVersion(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_Profile_SystemManufacturers_ISystemSupportInfoStatics<D>::LocalSystemEdition() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Profile::SystemManufacturers::ISystemSupportInfoStatics)->get_LocalSystemEdition(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Profile::SystemManufacturers::OemSupportInfo) consume_Windows_System_Profile_SystemManufacturers_ISystemSupportInfoStatics<D>::OemSupportInfo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Profile::SystemManufacturers::ISystemSupportInfoStatics)->get_OemSupportInfo(&value));
        return llm::OS::System::Profile::SystemManufacturers::OemSupportInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Profile::SystemManufacturers::SystemSupportDeviceInfo) consume_Windows_System_Profile_SystemManufacturers_ISystemSupportInfoStatics2<D>::LocalDeviceInfo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Profile::SystemManufacturers::ISystemSupportInfoStatics2)->get_LocalDeviceInfo(&value));
        return llm::OS::System::Profile::SystemManufacturers::SystemSupportDeviceInfo{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Profile::SystemManufacturers::IOemSupportInfo> : produce_base<D, llm::OS::System::Profile::SystemManufacturers::IOemSupportInfo>
    {
        int32_t __stdcall get_SupportLink(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().SupportLink());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportAppLink(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().SupportAppLink());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportProvider(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SupportProvider());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Profile::SystemManufacturers::ISmbiosInformationStatics> : produce_base<D, llm::OS::System::Profile::SystemManufacturers::ISmbiosInformationStatics>
    {
        int32_t __stdcall get_SerialNumber(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SerialNumber());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Profile::SystemManufacturers::ISystemSupportDeviceInfo> : produce_base<D, llm::OS::System::Profile::SystemManufacturers::ISystemSupportDeviceInfo>
    {
        int32_t __stdcall get_OperatingSystem(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().OperatingSystem());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FriendlyName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().FriendlyName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SystemManufacturer(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SystemManufacturer());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SystemProductName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SystemProductName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SystemSku(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SystemSku());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SystemHardwareVersion(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SystemHardwareVersion());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SystemFirmwareVersion(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SystemFirmwareVersion());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Profile::SystemManufacturers::ISystemSupportInfoStatics> : produce_base<D, llm::OS::System::Profile::SystemManufacturers::ISystemSupportInfoStatics>
    {
        int32_t __stdcall get_LocalSystemEdition(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().LocalSystemEdition());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OemSupportInfo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::Profile::SystemManufacturers::OemSupportInfo>(this->shim().OemSupportInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Profile::SystemManufacturers::ISystemSupportInfoStatics2> : produce_base<D, llm::OS::System::Profile::SystemManufacturers::ISystemSupportInfoStatics2>
    {
        int32_t __stdcall get_LocalDeviceInfo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::Profile::SystemManufacturers::SystemSupportDeviceInfo>(this->shim().LocalDeviceInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::System::Profile::SystemManufacturers
{
    inline auto SmbiosInformation::SerialNumber()
    {
        return impl::call_factory_cast<hstring(*)(ISmbiosInformationStatics const&), SmbiosInformation, ISmbiosInformationStatics>([](ISmbiosInformationStatics const& f) { return f.SerialNumber(); });
    }
    inline auto SystemSupportInfo::LocalSystemEdition()
    {
        return impl::call_factory_cast<hstring(*)(ISystemSupportInfoStatics const&), SystemSupportInfo, ISystemSupportInfoStatics>([](ISystemSupportInfoStatics const& f) { return f.LocalSystemEdition(); });
    }
    inline auto SystemSupportInfo::OemSupportInfo()
    {
        return impl::call_factory_cast<llm::OS::System::Profile::SystemManufacturers::OemSupportInfo(*)(ISystemSupportInfoStatics const&), SystemSupportInfo, ISystemSupportInfoStatics>([](ISystemSupportInfoStatics const& f) { return f.OemSupportInfo(); });
    }
    inline auto SystemSupportInfo::LocalDeviceInfo()
    {
        return impl::call_factory_cast<llm::OS::System::Profile::SystemManufacturers::SystemSupportDeviceInfo(*)(ISystemSupportInfoStatics2 const&), SystemSupportInfo, ISystemSupportInfoStatics2>([](ISystemSupportInfoStatics2 const& f) { return f.LocalDeviceInfo(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::System::Profile::SystemManufacturers::IOemSupportInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Profile::SystemManufacturers::ISmbiosInformationStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Profile::SystemManufacturers::ISystemSupportDeviceInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Profile::SystemManufacturers::ISystemSupportInfoStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Profile::SystemManufacturers::ISystemSupportInfoStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Profile::SystemManufacturers::OemSupportInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Profile::SystemManufacturers::SmbiosInformation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Profile::SystemManufacturers::SystemSupportDeviceInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Profile::SystemManufacturers::SystemSupportInfo> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
