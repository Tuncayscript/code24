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
#ifndef LLM_OS_Services_Cortana_H
#define LLM_OS_Services_Cortana_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/impl/Windows.ApplicationModel.DataTransfer.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.System.2.h"
#include "llm/impl/Windows.Services.Cortana.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_Services_Cortana_ICortanaActionableInsights<D>::User() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Cortana::ICortanaActionableInsights)->get_User(&value));
        return llm::OS::System::User{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Services_Cortana_ICortanaActionableInsights<D>::IsAvailableAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Cortana::ICortanaActionableInsights)->IsAvailableAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Services_Cortana_ICortanaActionableInsights<D>::ShowInsightsForImageAsync(llm::OS::Storage::Streams::IRandomAccessStreamReference const& imageStream) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Cortana::ICortanaActionableInsights)->ShowInsightsForImageAsync(*(void**)(&imageStream), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Services_Cortana_ICortanaActionableInsights<D>::ShowInsightsForImageAsync(llm::OS::Storage::Streams::IRandomAccessStreamReference const& imageStream, llm::OS::Services::Cortana::CortanaActionableInsightsOptions const& options) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Cortana::ICortanaActionableInsights)->ShowInsightsForImageWithOptionsAsync(*(void**)(&imageStream), *(void**)(&options), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Services_Cortana_ICortanaActionableInsights<D>::ShowInsightsForTextAsync(param::hstring const& text) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Cortana::ICortanaActionableInsights)->ShowInsightsForTextAsync(*(void**)(&text), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Services_Cortana_ICortanaActionableInsights<D>::ShowInsightsForTextAsync(param::hstring const& text, llm::OS::Services::Cortana::CortanaActionableInsightsOptions const& options) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Cortana::ICortanaActionableInsights)->ShowInsightsForTextWithOptionsAsync(*(void**)(&text), *(void**)(&options), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Services_Cortana_ICortanaActionableInsights<D>::ShowInsightsAsync(llm::OS::ApplicationModel::DataTransfer::DataPackage const& datapackage) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Cortana::ICortanaActionableInsights)->ShowInsightsAsync(*(void**)(&datapackage), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Services_Cortana_ICortanaActionableInsights<D>::ShowInsightsAsync(llm::OS::ApplicationModel::DataTransfer::DataPackage const& datapackage, llm::OS::Services::Cortana::CortanaActionableInsightsOptions const& options) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Cortana::ICortanaActionableInsights)->ShowInsightsWithOptionsAsync(*(void**)(&datapackage), *(void**)(&options), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_Services_Cortana_ICortanaActionableInsightsOptions<D>::ContentSourceWebLink() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Cortana::ICortanaActionableInsightsOptions)->get_ContentSourceWebLink(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Services_Cortana_ICortanaActionableInsightsOptions<D>::ContentSourceWebLink(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Cortana::ICortanaActionableInsightsOptions)->put_ContentSourceWebLink(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Cortana_ICortanaActionableInsightsOptions<D>::SurroundingText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Cortana::ICortanaActionableInsightsOptions)->get_SurroundingText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Services_Cortana_ICortanaActionableInsightsOptions<D>::SurroundingText(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Cortana::ICortanaActionableInsightsOptions)->put_SurroundingText(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Cortana::CortanaActionableInsights) consume_Windows_Services_Cortana_ICortanaActionableInsightsStatics<D>::GetDefault() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Cortana::ICortanaActionableInsightsStatics)->GetDefault(&result));
        return llm::OS::Services::Cortana::CortanaActionableInsights{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Cortana::CortanaActionableInsights) consume_Windows_Services_Cortana_ICortanaActionableInsightsStatics<D>::GetForUser(llm::OS::System::User const& user) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Cortana::ICortanaActionableInsightsStatics)->GetForUser(*(void**)(&user), &result));
        return llm::OS::Services::Cortana::CortanaActionableInsights{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Services_Cortana_ICortanaPermissionsManager<D>::IsSupported() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Cortana::ICortanaPermissionsManager)->IsSupported(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Services_Cortana_ICortanaPermissionsManager<D>::ArePermissionsGrantedAsync(param::async_iterable<llm::OS::Services::Cortana::CortanaPermission> const& permissions) const
    {
        void* getGrantedPermissionsOperation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Cortana::ICortanaPermissionsManager)->ArePermissionsGrantedAsync(*(void**)(&permissions), &getGrantedPermissionsOperation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ getGrantedPermissionsOperation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Cortana::CortanaPermissionsChangeResult>) consume_Windows_Services_Cortana_ICortanaPermissionsManager<D>::GrantPermissionsAsync(param::async_iterable<llm::OS::Services::Cortana::CortanaPermission> const& permissions) const
    {
        void* grantOperation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Cortana::ICortanaPermissionsManager)->GrantPermissionsAsync(*(void**)(&permissions), &grantOperation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Cortana::CortanaPermissionsChangeResult>{ grantOperation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Cortana::CortanaPermissionsChangeResult>) consume_Windows_Services_Cortana_ICortanaPermissionsManager<D>::RevokePermissionsAsync(param::async_iterable<llm::OS::Services::Cortana::CortanaPermission> const& permissions) const
    {
        void* revokeOperation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Cortana::ICortanaPermissionsManager)->RevokePermissionsAsync(*(void**)(&permissions), &revokeOperation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Cortana::CortanaPermissionsChangeResult>{ revokeOperation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Cortana::CortanaPermissionsManager) consume_Windows_Services_Cortana_ICortanaPermissionsManagerStatics<D>::GetDefault() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Cortana::ICortanaPermissionsManagerStatics)->GetDefault(&result));
        return llm::OS::Services::Cortana::CortanaPermissionsManager{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Services_Cortana_ICortanaSettings<D>::HasUserConsentToVoiceActivation() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Cortana::ICortanaSettings)->get_HasUserConsentToVoiceActivation(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Services_Cortana_ICortanaSettings<D>::IsVoiceActivationEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Cortana::ICortanaSettings)->get_IsVoiceActivationEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Services_Cortana_ICortanaSettings<D>::IsVoiceActivationEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Cortana::ICortanaSettings)->put_IsVoiceActivationEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Services_Cortana_ICortanaSettingsStatics<D>::IsSupported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Cortana::ICortanaSettingsStatics)->IsSupported(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Cortana::CortanaSettings) consume_Windows_Services_Cortana_ICortanaSettingsStatics<D>::GetDefault() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Cortana::ICortanaSettingsStatics)->GetDefault(&result));
        return llm::OS::Services::Cortana::CortanaSettings{ result, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Cortana::ICortanaActionableInsights> : produce_base<D, llm::OS::Services::Cortana::ICortanaActionableInsights>
    {
        int32_t __stdcall get_User(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::User>(this->shim().User());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsAvailableAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().IsAvailableAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowInsightsForImageAsync(void* imageStream, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ShowInsightsForImageAsync(*reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStreamReference const*>(&imageStream)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowInsightsForImageWithOptionsAsync(void* imageStream, void* options, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ShowInsightsForImageAsync(*reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStreamReference const*>(&imageStream), *reinterpret_cast<llm::OS::Services::Cortana::CortanaActionableInsightsOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowInsightsForTextAsync(void* text, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ShowInsightsForTextAsync(*reinterpret_cast<hstring const*>(&text)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowInsightsForTextWithOptionsAsync(void* text, void* options, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ShowInsightsForTextAsync(*reinterpret_cast<hstring const*>(&text), *reinterpret_cast<llm::OS::Services::Cortana::CortanaActionableInsightsOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowInsightsAsync(void* datapackage, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ShowInsightsAsync(*reinterpret_cast<llm::OS::ApplicationModel::DataTransfer::DataPackage const*>(&datapackage)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowInsightsWithOptionsAsync(void* datapackage, void* options, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ShowInsightsAsync(*reinterpret_cast<llm::OS::ApplicationModel::DataTransfer::DataPackage const*>(&datapackage), *reinterpret_cast<llm::OS::Services::Cortana::CortanaActionableInsightsOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Cortana::ICortanaActionableInsightsOptions> : produce_base<D, llm::OS::Services::Cortana::ICortanaActionableInsightsOptions>
    {
        int32_t __stdcall get_ContentSourceWebLink(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().ContentSourceWebLink());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ContentSourceWebLink(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContentSourceWebLink(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SurroundingText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SurroundingText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SurroundingText(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SurroundingText(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Cortana::ICortanaActionableInsightsStatics> : produce_base<D, llm::OS::Services::Cortana::ICortanaActionableInsightsStatics>
    {
        int32_t __stdcall GetDefault(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Services::Cortana::CortanaActionableInsights>(this->shim().GetDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetForUser(void* user, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Services::Cortana::CortanaActionableInsights>(this->shim().GetForUser(*reinterpret_cast<llm::OS::System::User const*>(&user)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Cortana::ICortanaPermissionsManager> : produce_base<D, llm::OS::Services::Cortana::ICortanaPermissionsManager>
    {
        int32_t __stdcall IsSupported(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ArePermissionsGrantedAsync(void* permissions, void** getGrantedPermissionsOperation) noexcept final try
        {
            clear_abi(getGrantedPermissionsOperation);
            typename D::abi_guard guard(this->shim());
            *getGrantedPermissionsOperation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().ArePermissionsGrantedAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Services::Cortana::CortanaPermission> const*>(&permissions)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GrantPermissionsAsync(void* permissions, void** grantOperation) noexcept final try
        {
            clear_abi(grantOperation);
            typename D::abi_guard guard(this->shim());
            *grantOperation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Cortana::CortanaPermissionsChangeResult>>(this->shim().GrantPermissionsAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Services::Cortana::CortanaPermission> const*>(&permissions)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RevokePermissionsAsync(void* permissions, void** revokeOperation) noexcept final try
        {
            clear_abi(revokeOperation);
            typename D::abi_guard guard(this->shim());
            *revokeOperation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Cortana::CortanaPermissionsChangeResult>>(this->shim().RevokePermissionsAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Services::Cortana::CortanaPermission> const*>(&permissions)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Cortana::ICortanaPermissionsManagerStatics> : produce_base<D, llm::OS::Services::Cortana::ICortanaPermissionsManagerStatics>
    {
        int32_t __stdcall GetDefault(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Services::Cortana::CortanaPermissionsManager>(this->shim().GetDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Cortana::ICortanaSettings> : produce_base<D, llm::OS::Services::Cortana::ICortanaSettings>
    {
        int32_t __stdcall get_HasUserConsentToVoiceActivation(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().HasUserConsentToVoiceActivation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsVoiceActivationEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsVoiceActivationEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsVoiceActivationEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsVoiceActivationEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Cortana::ICortanaSettingsStatics> : produce_base<D, llm::OS::Services::Cortana::ICortanaSettingsStatics>
    {
        int32_t __stdcall IsSupported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDefault(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Services::Cortana::CortanaSettings>(this->shim().GetDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Services::Cortana
{
    inline auto CortanaActionableInsights::GetDefault()
    {
        return impl::call_factory_cast<llm::OS::Services::Cortana::CortanaActionableInsights(*)(ICortanaActionableInsightsStatics const&), CortanaActionableInsights, ICortanaActionableInsightsStatics>([](ICortanaActionableInsightsStatics const& f) { return f.GetDefault(); });
    }
    inline auto CortanaActionableInsights::GetForUser(llm::OS::System::User const& user)
    {
        return impl::call_factory<CortanaActionableInsights, ICortanaActionableInsightsStatics>([&](ICortanaActionableInsightsStatics const& f) { return f.GetForUser(user); });
    }
    inline CortanaActionableInsightsOptions::CortanaActionableInsightsOptions() :
        CortanaActionableInsightsOptions(impl::call_factory_cast<CortanaActionableInsightsOptions(*)(llm::OS::Foundation::IActivationFactory const&), CortanaActionableInsightsOptions>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<CortanaActionableInsightsOptions>(); }))
    {
    }
    inline auto CortanaPermissionsManager::GetDefault()
    {
        return impl::call_factory_cast<llm::OS::Services::Cortana::CortanaPermissionsManager(*)(ICortanaPermissionsManagerStatics const&), CortanaPermissionsManager, ICortanaPermissionsManagerStatics>([](ICortanaPermissionsManagerStatics const& f) { return f.GetDefault(); });
    }
    inline auto CortanaSettings::IsSupported()
    {
        return impl::call_factory_cast<bool(*)(ICortanaSettingsStatics const&), CortanaSettings, ICortanaSettingsStatics>([](ICortanaSettingsStatics const& f) { return f.IsSupported(); });
    }
    inline auto CortanaSettings::GetDefault()
    {
        return impl::call_factory_cast<llm::OS::Services::Cortana::CortanaSettings(*)(ICortanaSettingsStatics const&), CortanaSettings, ICortanaSettingsStatics>([](ICortanaSettingsStatics const& f) { return f.GetDefault(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Services::Cortana::ICortanaActionableInsights> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Cortana::ICortanaActionableInsightsOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Cortana::ICortanaActionableInsightsStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Cortana::ICortanaPermissionsManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Cortana::ICortanaPermissionsManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Cortana::ICortanaSettings> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Cortana::ICortanaSettingsStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Cortana::CortanaActionableInsights> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Cortana::CortanaActionableInsightsOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Cortana::CortanaPermissionsManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Cortana::CortanaSettings> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
