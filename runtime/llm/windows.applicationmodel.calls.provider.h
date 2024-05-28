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
#ifndef LLM_OS_ApplicationModel_Calls_Provider_H
#define LLM_OS_ApplicationModel_Calls_Provider_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.ApplicationModel.Calls.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Storage.2.h"
#include "llm/impl/Windows.ApplicationModel.Calls.Provider.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_Provider_IPhoneCallOrigin<D>::Category() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOrigin)->get_Category(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_Provider_IPhoneCallOrigin<D>::Category(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOrigin)->put_Category(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_Provider_IPhoneCallOrigin<D>::CategoryDescription() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOrigin)->get_CategoryDescription(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_Provider_IPhoneCallOrigin<D>::CategoryDescription(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOrigin)->put_CategoryDescription(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_Provider_IPhoneCallOrigin<D>::Location() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOrigin)->get_Location(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_Provider_IPhoneCallOrigin<D>::Location(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOrigin)->put_Location(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Calls_Provider_IPhoneCallOrigin2<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOrigin2)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_Provider_IPhoneCallOrigin2<D>::DisplayName(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOrigin2)->put_DisplayName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::StorageFile) consume_Windows_ApplicationModel_Calls_Provider_IPhoneCallOrigin3<D>::DisplayPicture() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOrigin3)->get_DisplayPicture(&value));
        return llm::OS::Storage::StorageFile{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_Provider_IPhoneCallOrigin3<D>::DisplayPicture(llm::OS::Storage::StorageFile const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOrigin3)->put_DisplayPicture(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Calls_Provider_IPhoneCallOriginManagerStatics<D>::IsCurrentAppActiveCallOriginApp() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOriginManagerStatics)->get_IsCurrentAppActiveCallOriginApp(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_Provider_IPhoneCallOriginManagerStatics<D>::ShowPhoneCallOriginSettingsUI() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOriginManagerStatics)->ShowPhoneCallOriginSettingsUI());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Calls_Provider_IPhoneCallOriginManagerStatics<D>::SetCallOrigin(llm::guid const& requestId, llm::OS::ApplicationModel::Calls::Provider::PhoneCallOrigin const& callOrigin) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOriginManagerStatics)->SetCallOrigin(impl::bind_in(requestId), *(void**)(&callOrigin)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_ApplicationModel_Calls_Provider_IPhoneCallOriginManagerStatics2<D>::RequestSetAsActiveCallOriginAppAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOriginManagerStatics2)->RequestSetAsActiveCallOriginAppAsync(&result));
        return llm::OS::Foundation::IAsyncOperation<bool>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Calls_Provider_IPhoneCallOriginManagerStatics3<D>::IsSupported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOriginManagerStatics3)->get_IsSupported(&value));
        return value;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOrigin> : produce_base<D, llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOrigin>
    {
        int32_t __stdcall get_Category(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Category());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Category(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Category(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CategoryDescription(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().CategoryDescription());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CategoryDescription(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CategoryDescription(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Location(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Location());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Location(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Location(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOrigin2> : produce_base<D, llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOrigin2>
    {
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DisplayName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayName(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOrigin3> : produce_base<D, llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOrigin3>
    {
        int32_t __stdcall get_DisplayPicture(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::StorageFile>(this->shim().DisplayPicture());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DisplayPicture(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayPicture(*reinterpret_cast<llm::OS::Storage::StorageFile const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOriginManagerStatics> : produce_base<D, llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOriginManagerStatics>
    {
        int32_t __stdcall get_IsCurrentAppActiveCallOriginApp(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsCurrentAppActiveCallOriginApp());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowPhoneCallOriginSettingsUI() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowPhoneCallOriginSettingsUI();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetCallOrigin(llm::guid requestId, void* callOrigin) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetCallOrigin(*reinterpret_cast<llm::guid const*>(&requestId), *reinterpret_cast<llm::OS::ApplicationModel::Calls::Provider::PhoneCallOrigin const*>(&callOrigin));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOriginManagerStatics2> : produce_base<D, llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOriginManagerStatics2>
    {
        int32_t __stdcall RequestSetAsActiveCallOriginAppAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().RequestSetAsActiveCallOriginAppAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOriginManagerStatics3> : produce_base<D, llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOriginManagerStatics3>
    {
        int32_t __stdcall get_IsSupported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::ApplicationModel::Calls::Provider
{
    inline PhoneCallOrigin::PhoneCallOrigin() :
        PhoneCallOrigin(impl::call_factory_cast<PhoneCallOrigin(*)(llm::OS::Foundation::IActivationFactory const&), PhoneCallOrigin>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<PhoneCallOrigin>(); }))
    {
    }
    inline auto PhoneCallOriginManager::IsCurrentAppActiveCallOriginApp()
    {
        return impl::call_factory_cast<bool(*)(IPhoneCallOriginManagerStatics const&), PhoneCallOriginManager, IPhoneCallOriginManagerStatics>([](IPhoneCallOriginManagerStatics const& f) { return f.IsCurrentAppActiveCallOriginApp(); });
    }
    inline auto PhoneCallOriginManager::ShowPhoneCallOriginSettingsUI()
    {
        impl::call_factory_cast<void(*)(IPhoneCallOriginManagerStatics const&), PhoneCallOriginManager, IPhoneCallOriginManagerStatics>([](IPhoneCallOriginManagerStatics const& f) { return f.ShowPhoneCallOriginSettingsUI(); });
    }
    inline auto PhoneCallOriginManager::SetCallOrigin(llm::guid const& requestId, llm::OS::ApplicationModel::Calls::Provider::PhoneCallOrigin const& callOrigin)
    {
        impl::call_factory<PhoneCallOriginManager, IPhoneCallOriginManagerStatics>([&](IPhoneCallOriginManagerStatics const& f) { return f.SetCallOrigin(requestId, callOrigin); });
    }
    inline auto PhoneCallOriginManager::RequestSetAsActiveCallOriginAppAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<bool>(*)(IPhoneCallOriginManagerStatics2 const&), PhoneCallOriginManager, IPhoneCallOriginManagerStatics2>([](IPhoneCallOriginManagerStatics2 const& f) { return f.RequestSetAsActiveCallOriginAppAsync(); });
    }
    inline auto PhoneCallOriginManager::IsSupported()
    {
        return impl::call_factory_cast<bool(*)(IPhoneCallOriginManagerStatics3 const&), PhoneCallOriginManager, IPhoneCallOriginManagerStatics3>([](IPhoneCallOriginManagerStatics3 const& f) { return f.IsSupported(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOrigin> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOrigin2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOrigin3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOriginManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOriginManagerStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOriginManagerStatics3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::Provider::PhoneCallOrigin> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Calls::Provider::PhoneCallOriginManager> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
