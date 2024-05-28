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
#ifndef LLM_OS_ApplicationModel_SocialInfo_Provider_H
#define LLM_OS_ApplicationModel_SocialInfo_Provider_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.ApplicationModel.SocialInfo.h"
#include "llm/impl/Windows.ApplicationModel.SocialInfo.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.ApplicationModel.SocialInfo.Provider.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_SocialInfo_Provider_ISocialDashboardItemUpdater<D>::OwnerRemoteId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater)->get_OwnerRemoteId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::SocialInfo::SocialFeedContent) consume_Windows_ApplicationModel_SocialInfo_Provider_ISocialDashboardItemUpdater<D>::Content() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater)->get_Content(&value));
        return llm::OS::ApplicationModel::SocialInfo::SocialFeedContent{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_ApplicationModel_SocialInfo_Provider_ISocialDashboardItemUpdater<D>::Timestamp() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater)->get_Timestamp(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_SocialInfo_Provider_ISocialDashboardItemUpdater<D>::Timestamp(llm::OS::Foundation::DateTime const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater)->put_Timestamp(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_SocialInfo_Provider_ISocialDashboardItemUpdater<D>::Thumbnail(llm::OS::ApplicationModel::SocialInfo::SocialItemThumbnail const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater)->put_Thumbnail(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::SocialInfo::SocialItemThumbnail) consume_Windows_ApplicationModel_SocialInfo_Provider_ISocialDashboardItemUpdater<D>::Thumbnail() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater)->get_Thumbnail(&value));
        return llm::OS::ApplicationModel::SocialInfo::SocialItemThumbnail{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_SocialInfo_Provider_ISocialDashboardItemUpdater<D>::CommitAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater)->CommitAsync(&operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_ApplicationModel_SocialInfo_Provider_ISocialDashboardItemUpdater<D>::TargetUri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater)->get_TargetUri(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_SocialInfo_Provider_ISocialDashboardItemUpdater<D>::TargetUri(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater)->put_TargetUri(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_SocialInfo_Provider_ISocialFeedUpdater<D>::OwnerRemoteId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::Provider::ISocialFeedUpdater)->get_OwnerRemoteId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::SocialInfo::SocialFeedKind) consume_Windows_ApplicationModel_SocialInfo_Provider_ISocialFeedUpdater<D>::Kind() const
    {
        llm::OS::ApplicationModel::SocialInfo::SocialFeedKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::Provider::ISocialFeedUpdater)->get_Kind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::SocialInfo::SocialFeedItem>) consume_Windows_ApplicationModel_SocialInfo_Provider_ISocialFeedUpdater<D>::Items() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::Provider::ISocialFeedUpdater)->get_Items(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::SocialInfo::SocialFeedItem>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_SocialInfo_Provider_ISocialFeedUpdater<D>::CommitAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::Provider::ISocialFeedUpdater)->CommitAsync(&operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::SocialInfo::Provider::SocialFeedUpdater>) consume_Windows_ApplicationModel_SocialInfo_Provider_ISocialInfoProviderManagerStatics<D>::CreateSocialFeedUpdaterAsync(llm::OS::ApplicationModel::SocialInfo::SocialFeedKind const& kind, llm::OS::ApplicationModel::SocialInfo::SocialFeedUpdateMode const& mode, param::hstring const& ownerRemoteId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::Provider::ISocialInfoProviderManagerStatics)->CreateSocialFeedUpdaterAsync(static_cast<int32_t>(kind), static_cast<int32_t>(mode), *(void**)(&ownerRemoteId), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::SocialInfo::Provider::SocialFeedUpdater>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::SocialInfo::Provider::SocialDashboardItemUpdater>) consume_Windows_ApplicationModel_SocialInfo_Provider_ISocialInfoProviderManagerStatics<D>::CreateDashboardItemUpdaterAsync(param::hstring const& ownerRemoteId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::Provider::ISocialInfoProviderManagerStatics)->CreateDashboardItemUpdaterAsync(*(void**)(&ownerRemoteId), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::SocialInfo::Provider::SocialDashboardItemUpdater>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_SocialInfo_Provider_ISocialInfoProviderManagerStatics<D>::UpdateBadgeCountValue(param::hstring const& itemRemoteId, int32_t newCount) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::Provider::ISocialInfoProviderManagerStatics)->UpdateBadgeCountValue(*(void**)(&itemRemoteId), newCount));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_SocialInfo_Provider_ISocialInfoProviderManagerStatics<D>::ReportNewContentAvailable(param::hstring const& contactRemoteId, llm::OS::ApplicationModel::SocialInfo::SocialFeedKind const& kind) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::Provider::ISocialInfoProviderManagerStatics)->ReportNewContentAvailable(*(void**)(&contactRemoteId), static_cast<int32_t>(kind)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_ApplicationModel_SocialInfo_Provider_ISocialInfoProviderManagerStatics<D>::ProvisionAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::Provider::ISocialInfoProviderManagerStatics)->ProvisionAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_SocialInfo_Provider_ISocialInfoProviderManagerStatics<D>::DeprovisionAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::Provider::ISocialInfoProviderManagerStatics)->DeprovisionAsync(&operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater> : produce_base<D, llm::OS::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater>
    {
        int32_t __stdcall get_OwnerRemoteId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().OwnerRemoteId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Content(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::SocialInfo::SocialFeedContent>(this->shim().Content());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Timestamp(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().Timestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Timestamp(int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Timestamp(*reinterpret_cast<llm::OS::Foundation::DateTime const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Thumbnail(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Thumbnail(*reinterpret_cast<llm::OS::ApplicationModel::SocialInfo::SocialItemThumbnail const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Thumbnail(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::SocialInfo::SocialItemThumbnail>(this->shim().Thumbnail());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CommitAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().CommitAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TargetUri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().TargetUri());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TargetUri(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TargetUri(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::SocialInfo::Provider::ISocialFeedUpdater> : produce_base<D, llm::OS::ApplicationModel::SocialInfo::Provider::ISocialFeedUpdater>
    {
        int32_t __stdcall get_OwnerRemoteId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().OwnerRemoteId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Kind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::SocialInfo::SocialFeedKind>(this->shim().Kind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Items(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::SocialInfo::SocialFeedItem>>(this->shim().Items());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CommitAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().CommitAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::SocialInfo::Provider::ISocialInfoProviderManagerStatics> : produce_base<D, llm::OS::ApplicationModel::SocialInfo::Provider::ISocialInfoProviderManagerStatics>
    {
        int32_t __stdcall CreateSocialFeedUpdaterAsync(int32_t kind, int32_t mode, void* ownerRemoteId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::SocialInfo::Provider::SocialFeedUpdater>>(this->shim().CreateSocialFeedUpdaterAsync(*reinterpret_cast<llm::OS::ApplicationModel::SocialInfo::SocialFeedKind const*>(&kind), *reinterpret_cast<llm::OS::ApplicationModel::SocialInfo::SocialFeedUpdateMode const*>(&mode), *reinterpret_cast<hstring const*>(&ownerRemoteId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateDashboardItemUpdaterAsync(void* ownerRemoteId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::SocialInfo::Provider::SocialDashboardItemUpdater>>(this->shim().CreateDashboardItemUpdaterAsync(*reinterpret_cast<hstring const*>(&ownerRemoteId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UpdateBadgeCountValue(void* itemRemoteId, int32_t newCount) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UpdateBadgeCountValue(*reinterpret_cast<hstring const*>(&itemRemoteId), newCount);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportNewContentAvailable(void* contactRemoteId, int32_t kind) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportNewContentAvailable(*reinterpret_cast<hstring const*>(&contactRemoteId), *reinterpret_cast<llm::OS::ApplicationModel::SocialInfo::SocialFeedKind const*>(&kind));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ProvisionAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().ProvisionAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DeprovisionAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().DeprovisionAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::ApplicationModel::SocialInfo::Provider
{
    inline auto SocialInfoProviderManager::CreateSocialFeedUpdaterAsync(llm::OS::ApplicationModel::SocialInfo::SocialFeedKind const& kind, llm::OS::ApplicationModel::SocialInfo::SocialFeedUpdateMode const& mode, param::hstring const& ownerRemoteId)
    {
        return impl::call_factory<SocialInfoProviderManager, ISocialInfoProviderManagerStatics>([&](ISocialInfoProviderManagerStatics const& f) { return f.CreateSocialFeedUpdaterAsync(kind, mode, ownerRemoteId); });
    }
    inline auto SocialInfoProviderManager::CreateDashboardItemUpdaterAsync(param::hstring const& ownerRemoteId)
    {
        return impl::call_factory<SocialInfoProviderManager, ISocialInfoProviderManagerStatics>([&](ISocialInfoProviderManagerStatics const& f) { return f.CreateDashboardItemUpdaterAsync(ownerRemoteId); });
    }
    inline auto SocialInfoProviderManager::UpdateBadgeCountValue(param::hstring const& itemRemoteId, int32_t newCount)
    {
        impl::call_factory<SocialInfoProviderManager, ISocialInfoProviderManagerStatics>([&](ISocialInfoProviderManagerStatics const& f) { return f.UpdateBadgeCountValue(itemRemoteId, newCount); });
    }
    inline auto SocialInfoProviderManager::ReportNewContentAvailable(param::hstring const& contactRemoteId, llm::OS::ApplicationModel::SocialInfo::SocialFeedKind const& kind)
    {
        impl::call_factory<SocialInfoProviderManager, ISocialInfoProviderManagerStatics>([&](ISocialInfoProviderManagerStatics const& f) { return f.ReportNewContentAvailable(contactRemoteId, kind); });
    }
    inline auto SocialInfoProviderManager::ProvisionAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<bool>(*)(ISocialInfoProviderManagerStatics const&), SocialInfoProviderManager, ISocialInfoProviderManagerStatics>([](ISocialInfoProviderManagerStatics const& f) { return f.ProvisionAsync(); });
    }
    inline auto SocialInfoProviderManager::DeprovisionAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncAction(*)(ISocialInfoProviderManagerStatics const&), SocialInfoProviderManager, ISocialInfoProviderManagerStatics>([](ISocialInfoProviderManagerStatics const& f) { return f.DeprovisionAsync(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::SocialInfo::Provider::ISocialFeedUpdater> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::SocialInfo::Provider::ISocialInfoProviderManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::SocialInfo::Provider::SocialDashboardItemUpdater> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::SocialInfo::Provider::SocialFeedUpdater> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::SocialInfo::Provider::SocialInfoProviderManager> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
