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
#ifndef LLM_OS_Gaming_Preview_GamesEnumeration_H
#define LLM_OS_Gaming_Preview_GamesEnumeration_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/impl/Windows.ApplicationModel.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Storage.2.h"
#include "llm/impl/Windows.Gaming.Preview.GamesEnumeration.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::AppDisplayInfo) consume_Windows_Gaming_Preview_GamesEnumeration_IGameListEntry<D>::DisplayInfo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameListEntry)->get_DisplayInfo(&value));
        return llm::OS::ApplicationModel::AppDisplayInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Gaming_Preview_GamesEnumeration_IGameListEntry<D>::LaunchAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameListEntry)->LaunchAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Gaming::Preview::GamesEnumeration::GameListCategory) consume_Windows_Gaming_Preview_GamesEnumeration_IGameListEntry<D>::Category() const
    {
        llm::OS::Gaming::Preview::GamesEnumeration::GameListCategory value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameListEntry)->get_Category(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>) consume_Windows_Gaming_Preview_GamesEnumeration_IGameListEntry<D>::Properties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameListEntry)->get_Properties(&value));
        return llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Gaming_Preview_GamesEnumeration_IGameListEntry<D>::SetCategoryAsync(llm::OS::Gaming::Preview::GamesEnumeration::GameListCategory const& value) const
    {
        void* action{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameListEntry)->SetCategoryAsync(static_cast<int32_t>(value), &action));
        return llm::OS::Foundation::IAsyncAction{ action, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Gaming::Preview::GamesEnumeration::GameListEntryLaunchableState) consume_Windows_Gaming_Preview_GamesEnumeration_IGameListEntry2<D>::LaunchableState() const
    {
        llm::OS::Gaming::Preview::GamesEnumeration::GameListEntryLaunchableState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameListEntry2)->get_LaunchableState(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::IStorageFile) consume_Windows_Gaming_Preview_GamesEnumeration_IGameListEntry2<D>::LauncherExecutable() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameListEntry2)->get_LauncherExecutable(&value));
        return llm::OS::Storage::IStorageFile{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Gaming_Preview_GamesEnumeration_IGameListEntry2<D>::LaunchParameters() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameListEntry2)->get_LaunchParameters(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Gaming_Preview_GamesEnumeration_IGameListEntry2<D>::SetLauncherExecutableFileAsync(llm::OS::Storage::IStorageFile const& executableFile) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameListEntry2)->SetLauncherExecutableFileAsync(*(void**)(&executableFile), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Gaming_Preview_GamesEnumeration_IGameListEntry2<D>::SetLauncherExecutableFileAsync(llm::OS::Storage::IStorageFile const& executableFile, param::hstring const& launchParams) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameListEntry2)->SetLauncherExecutableFileWithParamsAsync(*(void**)(&executableFile), *(void**)(&launchParams), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Gaming_Preview_GamesEnumeration_IGameListEntry2<D>::TitleId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameListEntry2)->get_TitleId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Gaming_Preview_GamesEnumeration_IGameListEntry2<D>::SetTitleIdAsync(param::hstring const& id) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameListEntry2)->SetTitleIdAsync(*(void**)(&id), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Gaming::Preview::GamesEnumeration::GameModeConfiguration) consume_Windows_Gaming_Preview_GamesEnumeration_IGameListEntry2<D>::GameModeConfiguration() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameListEntry2)->get_GameModeConfiguration(&value));
        return llm::OS::Gaming::Preview::GamesEnumeration::GameModeConfiguration{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Gaming::Preview::GamesEnumeration::GameListEntry>>) consume_Windows_Gaming_Preview_GamesEnumeration_IGameListStatics<D>::FindAllAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameListStatics)->FindAllAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Gaming::Preview::GamesEnumeration::GameListEntry>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Gaming::Preview::GamesEnumeration::GameListEntry>>) consume_Windows_Gaming_Preview_GamesEnumeration_IGameListStatics<D>::FindAllAsync(param::hstring const& packageFamilyName) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameListStatics)->FindAllAsyncPackageFamilyName(*(void**)(&packageFamilyName), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Gaming::Preview::GamesEnumeration::GameListEntry>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Gaming_Preview_GamesEnumeration_IGameListStatics<D>::GameAdded(llm::OS::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameListStatics)->add_GameAdded(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Gaming_Preview_GamesEnumeration_IGameListStatics<D>::GameAdded_revoker consume_Windows_Gaming_Preview_GamesEnumeration_IGameListStatics<D>::GameAdded(auto_revoke_t, llm::OS::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler const& handler) const
    {
        return impl::make_event_revoker<D, GameAdded_revoker>(this, GameAdded(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_Preview_GamesEnumeration_IGameListStatics<D>::GameAdded(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameListStatics)->remove_GameAdded(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Gaming_Preview_GamesEnumeration_IGameListStatics<D>::GameRemoved(llm::OS::Gaming::Preview::GamesEnumeration::GameListRemovedEventHandler const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameListStatics)->add_GameRemoved(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Gaming_Preview_GamesEnumeration_IGameListStatics<D>::GameRemoved_revoker consume_Windows_Gaming_Preview_GamesEnumeration_IGameListStatics<D>::GameRemoved(auto_revoke_t, llm::OS::Gaming::Preview::GamesEnumeration::GameListRemovedEventHandler const& handler) const
    {
        return impl::make_event_revoker<D, GameRemoved_revoker>(this, GameRemoved(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_Preview_GamesEnumeration_IGameListStatics<D>::GameRemoved(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameListStatics)->remove_GameRemoved(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Gaming_Preview_GamesEnumeration_IGameListStatics<D>::GameUpdated(llm::OS::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameListStatics)->add_GameUpdated(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Gaming_Preview_GamesEnumeration_IGameListStatics<D>::GameUpdated_revoker consume_Windows_Gaming_Preview_GamesEnumeration_IGameListStatics<D>::GameUpdated(auto_revoke_t, llm::OS::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler const& handler) const
    {
        return impl::make_event_revoker<D, GameUpdated_revoker>(this, GameUpdated(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_Preview_GamesEnumeration_IGameListStatics<D>::GameUpdated(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameListStatics)->remove_GameUpdated(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::Preview::GamesEnumeration::GameListEntry>) consume_Windows_Gaming_Preview_GamesEnumeration_IGameListStatics2<D>::MergeEntriesAsync(llm::OS::Gaming::Preview::GamesEnumeration::GameListEntry const& left, llm::OS::Gaming::Preview::GamesEnumeration::GameListEntry const& right) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameListStatics2)->MergeEntriesAsync(*(void**)(&left), *(void**)(&right), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::Preview::GamesEnumeration::GameListEntry>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Gaming::Preview::GamesEnumeration::GameListEntry>>) consume_Windows_Gaming_Preview_GamesEnumeration_IGameListStatics2<D>::UnmergeEntryAsync(llm::OS::Gaming::Preview::GamesEnumeration::GameListEntry const& mergedEntry) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameListStatics2)->UnmergeEntryAsync(*(void**)(&mergedEntry), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Gaming::Preview::GamesEnumeration::GameListEntry>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Gaming_Preview_GamesEnumeration_IGameModeConfiguration<D>::IsEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameModeConfiguration)->get_IsEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_Preview_GamesEnumeration_IGameModeConfiguration<D>::IsEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameModeConfiguration)->put_IsEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Gaming_Preview_GamesEnumeration_IGameModeConfiguration<D>::RelatedProcessNames() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameModeConfiguration)->get_RelatedProcessNames(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Gaming_Preview_GamesEnumeration_IGameModeConfiguration<D>::PercentGpuTimeAllocatedToGame() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameModeConfiguration)->get_PercentGpuTimeAllocatedToGame(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_Preview_GamesEnumeration_IGameModeConfiguration<D>::PercentGpuTimeAllocatedToGame(llm::OS::Foundation::IReference<int32_t> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameModeConfiguration)->put_PercentGpuTimeAllocatedToGame(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Gaming_Preview_GamesEnumeration_IGameModeConfiguration<D>::PercentGpuMemoryAllocatedToGame() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameModeConfiguration)->get_PercentGpuMemoryAllocatedToGame(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_Preview_GamesEnumeration_IGameModeConfiguration<D>::PercentGpuMemoryAllocatedToGame(llm::OS::Foundation::IReference<int32_t> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameModeConfiguration)->put_PercentGpuMemoryAllocatedToGame(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Gaming_Preview_GamesEnumeration_IGameModeConfiguration<D>::PercentGpuMemoryAllocatedToSystemCompositor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameModeConfiguration)->get_PercentGpuMemoryAllocatedToSystemCompositor(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_Preview_GamesEnumeration_IGameModeConfiguration<D>::PercentGpuMemoryAllocatedToSystemCompositor(llm::OS::Foundation::IReference<int32_t> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameModeConfiguration)->put_PercentGpuMemoryAllocatedToSystemCompositor(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Gaming_Preview_GamesEnumeration_IGameModeConfiguration<D>::MaxCpuCount() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameModeConfiguration)->get_MaxCpuCount(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_Preview_GamesEnumeration_IGameModeConfiguration<D>::MaxCpuCount(llm::OS::Foundation::IReference<int32_t> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameModeConfiguration)->put_MaxCpuCount(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Gaming_Preview_GamesEnumeration_IGameModeConfiguration<D>::CpuExclusivityMaskLow() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameModeConfiguration)->get_CpuExclusivityMaskLow(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_Preview_GamesEnumeration_IGameModeConfiguration<D>::CpuExclusivityMaskLow(llm::OS::Foundation::IReference<int32_t> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameModeConfiguration)->put_CpuExclusivityMaskLow(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Gaming_Preview_GamesEnumeration_IGameModeConfiguration<D>::CpuExclusivityMaskHigh() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameModeConfiguration)->get_CpuExclusivityMaskHigh(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_Preview_GamesEnumeration_IGameModeConfiguration<D>::CpuExclusivityMaskHigh(llm::OS::Foundation::IReference<int32_t> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameModeConfiguration)->put_CpuExclusivityMaskHigh(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Gaming_Preview_GamesEnumeration_IGameModeConfiguration<D>::AffinitizeToExclusiveCpus() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameModeConfiguration)->get_AffinitizeToExclusiveCpus(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_Preview_GamesEnumeration_IGameModeConfiguration<D>::AffinitizeToExclusiveCpus(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameModeConfiguration)->put_AffinitizeToExclusiveCpus(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Gaming_Preview_GamesEnumeration_IGameModeConfiguration<D>::SaveAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameModeConfiguration)->SaveAsync(&operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Gaming_Preview_GamesEnumeration_IGameModeUserConfiguration<D>::GamingRelatedProcessNames() const
    {
        void* processNames{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameModeUserConfiguration)->get_GamingRelatedProcessNames(&processNames));
        return llm::OS::Foundation::Collections::IVector<hstring>{ processNames, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Gaming_Preview_GamesEnumeration_IGameModeUserConfiguration<D>::SaveAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameModeUserConfiguration)->SaveAsync(&operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Gaming::Preview::GamesEnumeration::GameModeUserConfiguration) consume_Windows_Gaming_Preview_GamesEnumeration_IGameModeUserConfigurationStatics<D>::GetDefault() const
    {
        void* userConfiguration{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Preview::GamesEnumeration::IGameModeUserConfigurationStatics)->GetDefault(&userConfiguration));
        return llm::OS::Gaming::Preview::GamesEnumeration::GameModeUserConfiguration{ userConfiguration, take_ownership_from_abi };
    }
    template <typename H> struct delegate<llm::OS::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler, H> final : implements_delegate<llm::OS::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* game) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::Gaming::Preview::GamesEnumeration::GameListEntry const*>(&game));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename H> struct delegate<llm::OS::Gaming::Preview::GamesEnumeration::GameListRemovedEventHandler, H> final : implements_delegate<llm::OS::Gaming::Preview::GamesEnumeration::GameListRemovedEventHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::Gaming::Preview::GamesEnumeration::GameListRemovedEventHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* identifier) noexcept final try
        {
            (*this)(*reinterpret_cast<hstring const*>(&identifier));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::Gaming::Preview::GamesEnumeration::IGameListEntry> : produce_base<D, llm::OS::Gaming::Preview::GamesEnumeration::IGameListEntry>
    {
        int32_t __stdcall get_DisplayInfo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::AppDisplayInfo>(this->shim().DisplayInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LaunchAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().LaunchAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Category(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Gaming::Preview::GamesEnumeration::GameListCategory>(this->shim().Category());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Properties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>>(this->shim().Properties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetCategoryAsync(int32_t value, void** action) noexcept final try
        {
            clear_abi(action);
            typename D::abi_guard guard(this->shim());
            *action = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SetCategoryAsync(*reinterpret_cast<llm::OS::Gaming::Preview::GamesEnumeration::GameListCategory const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Gaming::Preview::GamesEnumeration::IGameListEntry2> : produce_base<D, llm::OS::Gaming::Preview::GamesEnumeration::IGameListEntry2>
    {
        int32_t __stdcall get_LaunchableState(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Gaming::Preview::GamesEnumeration::GameListEntryLaunchableState>(this->shim().LaunchableState());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LauncherExecutable(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::IStorageFile>(this->shim().LauncherExecutable());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LaunchParameters(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().LaunchParameters());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetLauncherExecutableFileAsync(void* executableFile, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SetLauncherExecutableFileAsync(*reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&executableFile)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetLauncherExecutableFileWithParamsAsync(void* executableFile, void* launchParams, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SetLauncherExecutableFileAsync(*reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&executableFile), *reinterpret_cast<hstring const*>(&launchParams)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TitleId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().TitleId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetTitleIdAsync(void* id, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SetTitleIdAsync(*reinterpret_cast<hstring const*>(&id)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_GameModeConfiguration(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Gaming::Preview::GamesEnumeration::GameModeConfiguration>(this->shim().GameModeConfiguration());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Gaming::Preview::GamesEnumeration::IGameListStatics> : produce_base<D, llm::OS::Gaming::Preview::GamesEnumeration::IGameListStatics>
    {
        int32_t __stdcall FindAllAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Gaming::Preview::GamesEnumeration::GameListEntry>>>(this->shim().FindAllAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindAllAsyncPackageFamilyName(void* packageFamilyName, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Gaming::Preview::GamesEnumeration::GameListEntry>>>(this->shim().FindAllAsync(*reinterpret_cast<hstring const*>(&packageFamilyName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_GameAdded(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().GameAdded(*reinterpret_cast<llm::OS::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_GameAdded(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GameAdded(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_GameRemoved(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().GameRemoved(*reinterpret_cast<llm::OS::Gaming::Preview::GamesEnumeration::GameListRemovedEventHandler const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_GameRemoved(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GameRemoved(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_GameUpdated(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().GameUpdated(*reinterpret_cast<llm::OS::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_GameUpdated(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GameUpdated(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Gaming::Preview::GamesEnumeration::IGameListStatics2> : produce_base<D, llm::OS::Gaming::Preview::GamesEnumeration::IGameListStatics2>
    {
        int32_t __stdcall MergeEntriesAsync(void* left, void* right, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::Preview::GamesEnumeration::GameListEntry>>(this->shim().MergeEntriesAsync(*reinterpret_cast<llm::OS::Gaming::Preview::GamesEnumeration::GameListEntry const*>(&left), *reinterpret_cast<llm::OS::Gaming::Preview::GamesEnumeration::GameListEntry const*>(&right)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UnmergeEntryAsync(void* mergedEntry, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Gaming::Preview::GamesEnumeration::GameListEntry>>>(this->shim().UnmergeEntryAsync(*reinterpret_cast<llm::OS::Gaming::Preview::GamesEnumeration::GameListEntry const*>(&mergedEntry)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Gaming::Preview::GamesEnumeration::IGameModeConfiguration> : produce_base<D, llm::OS::Gaming::Preview::GamesEnumeration::IGameModeConfiguration>
    {
        int32_t __stdcall get_IsEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RelatedProcessNames(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().RelatedProcessNames());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PercentGpuTimeAllocatedToGame(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().PercentGpuTimeAllocatedToGame());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PercentGpuTimeAllocatedToGame(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PercentGpuTimeAllocatedToGame(*reinterpret_cast<llm::OS::Foundation::IReference<int32_t> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PercentGpuMemoryAllocatedToGame(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().PercentGpuMemoryAllocatedToGame());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PercentGpuMemoryAllocatedToGame(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PercentGpuMemoryAllocatedToGame(*reinterpret_cast<llm::OS::Foundation::IReference<int32_t> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PercentGpuMemoryAllocatedToSystemCompositor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().PercentGpuMemoryAllocatedToSystemCompositor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PercentGpuMemoryAllocatedToSystemCompositor(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PercentGpuMemoryAllocatedToSystemCompositor(*reinterpret_cast<llm::OS::Foundation::IReference<int32_t> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxCpuCount(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().MaxCpuCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_MaxCpuCount(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxCpuCount(*reinterpret_cast<llm::OS::Foundation::IReference<int32_t> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CpuExclusivityMaskLow(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().CpuExclusivityMaskLow());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CpuExclusivityMaskLow(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CpuExclusivityMaskLow(*reinterpret_cast<llm::OS::Foundation::IReference<int32_t> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CpuExclusivityMaskHigh(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().CpuExclusivityMaskHigh());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CpuExclusivityMaskHigh(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CpuExclusivityMaskHigh(*reinterpret_cast<llm::OS::Foundation::IReference<int32_t> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AffinitizeToExclusiveCpus(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().AffinitizeToExclusiveCpus());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AffinitizeToExclusiveCpus(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AffinitizeToExclusiveCpus(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SaveAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SaveAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Gaming::Preview::GamesEnumeration::IGameModeUserConfiguration> : produce_base<D, llm::OS::Gaming::Preview::GamesEnumeration::IGameModeUserConfiguration>
    {
        int32_t __stdcall get_GamingRelatedProcessNames(void** processNames) noexcept final try
        {
            clear_abi(processNames);
            typename D::abi_guard guard(this->shim());
            *processNames = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().GamingRelatedProcessNames());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SaveAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SaveAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Gaming::Preview::GamesEnumeration::IGameModeUserConfigurationStatics> : produce_base<D, llm::OS::Gaming::Preview::GamesEnumeration::IGameModeUserConfigurationStatics>
    {
        int32_t __stdcall GetDefault(void** userConfiguration) noexcept final try
        {
            clear_abi(userConfiguration);
            typename D::abi_guard guard(this->shim());
            *userConfiguration = detach_from<llm::OS::Gaming::Preview::GamesEnumeration::GameModeUserConfiguration>(this->shim().GetDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Gaming::Preview::GamesEnumeration
{
    inline auto GameList::FindAllAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Gaming::Preview::GamesEnumeration::GameListEntry>>(*)(IGameListStatics const&), GameList, IGameListStatics>([](IGameListStatics const& f) { return f.FindAllAsync(); });
    }
    inline auto GameList::FindAllAsync(param::hstring const& packageFamilyName)
    {
        return impl::call_factory<GameList, IGameListStatics>([&](IGameListStatics const& f) { return f.FindAllAsync(packageFamilyName); });
    }
    inline auto GameList::GameAdded(llm::OS::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler const& handler)
    {
        return impl::call_factory<GameList, IGameListStatics>([&](IGameListStatics const& f) { return f.GameAdded(handler); });
    }
    inline GameList::GameAdded_revoker GameList::GameAdded(auto_revoke_t, llm::OS::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler const& handler)
    {
        auto f = get_activation_factory<GameList, llm::OS::Gaming::Preview::GamesEnumeration::IGameListStatics>();
        return { f, f.GameAdded(handler) };
    }
    inline auto GameList::GameAdded(llm::event_token const& token)
    {
        impl::call_factory<GameList, IGameListStatics>([&](IGameListStatics const& f) { return f.GameAdded(token); });
    }
    inline auto GameList::GameRemoved(llm::OS::Gaming::Preview::GamesEnumeration::GameListRemovedEventHandler const& handler)
    {
        return impl::call_factory<GameList, IGameListStatics>([&](IGameListStatics const& f) { return f.GameRemoved(handler); });
    }
    inline GameList::GameRemoved_revoker GameList::GameRemoved(auto_revoke_t, llm::OS::Gaming::Preview::GamesEnumeration::GameListRemovedEventHandler const& handler)
    {
        auto f = get_activation_factory<GameList, llm::OS::Gaming::Preview::GamesEnumeration::IGameListStatics>();
        return { f, f.GameRemoved(handler) };
    }
    inline auto GameList::GameRemoved(llm::event_token const& token)
    {
        impl::call_factory<GameList, IGameListStatics>([&](IGameListStatics const& f) { return f.GameRemoved(token); });
    }
    inline auto GameList::GameUpdated(llm::OS::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler const& handler)
    {
        return impl::call_factory<GameList, IGameListStatics>([&](IGameListStatics const& f) { return f.GameUpdated(handler); });
    }
    inline GameList::GameUpdated_revoker GameList::GameUpdated(auto_revoke_t, llm::OS::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler const& handler)
    {
        auto f = get_activation_factory<GameList, llm::OS::Gaming::Preview::GamesEnumeration::IGameListStatics>();
        return { f, f.GameUpdated(handler) };
    }
    inline auto GameList::GameUpdated(llm::event_token const& token)
    {
        impl::call_factory<GameList, IGameListStatics>([&](IGameListStatics const& f) { return f.GameUpdated(token); });
    }
    inline auto GameList::MergeEntriesAsync(llm::OS::Gaming::Preview::GamesEnumeration::GameListEntry const& left, llm::OS::Gaming::Preview::GamesEnumeration::GameListEntry const& right)
    {
        return impl::call_factory<GameList, IGameListStatics2>([&](IGameListStatics2 const& f) { return f.MergeEntriesAsync(left, right); });
    }
    inline auto GameList::UnmergeEntryAsync(llm::OS::Gaming::Preview::GamesEnumeration::GameListEntry const& mergedEntry)
    {
        return impl::call_factory<GameList, IGameListStatics2>([&](IGameListStatics2 const& f) { return f.UnmergeEntryAsync(mergedEntry); });
    }
    inline auto GameModeUserConfiguration::GetDefault()
    {
        return impl::call_factory_cast<llm::OS::Gaming::Preview::GamesEnumeration::GameModeUserConfiguration(*)(IGameModeUserConfigurationStatics const&), GameModeUserConfiguration, IGameModeUserConfigurationStatics>([](IGameModeUserConfigurationStatics const& f) { return f.GetDefault(); });
    }
    template <typename L> GameListChangedEventHandler::GameListChangedEventHandler(L handler) :
        GameListChangedEventHandler(impl::make_delegate<GameListChangedEventHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> GameListChangedEventHandler::GameListChangedEventHandler(F* handler) :
        GameListChangedEventHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> GameListChangedEventHandler::GameListChangedEventHandler(O* object, M method) :
        GameListChangedEventHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> GameListChangedEventHandler::GameListChangedEventHandler(com_ptr<O>&& object, M method) :
        GameListChangedEventHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> GameListChangedEventHandler::GameListChangedEventHandler(weak_ref<O>&& object, M method) :
        GameListChangedEventHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto GameListChangedEventHandler::operator()(llm::OS::Gaming::Preview::GamesEnumeration::GameListEntry const& game) const
    {
        check_hresult((*(impl::abi_t<GameListChangedEventHandler>**)this)->Invoke(*(void**)(&game)));
    }
    template <typename L> GameListRemovedEventHandler::GameListRemovedEventHandler(L handler) :
        GameListRemovedEventHandler(impl::make_delegate<GameListRemovedEventHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> GameListRemovedEventHandler::GameListRemovedEventHandler(F* handler) :
        GameListRemovedEventHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> GameListRemovedEventHandler::GameListRemovedEventHandler(O* object, M method) :
        GameListRemovedEventHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> GameListRemovedEventHandler::GameListRemovedEventHandler(com_ptr<O>&& object, M method) :
        GameListRemovedEventHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> GameListRemovedEventHandler::GameListRemovedEventHandler(weak_ref<O>&& object, M method) :
        GameListRemovedEventHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto GameListRemovedEventHandler::operator()(param::hstring const& identifier) const
    {
        check_hresult((*(impl::abi_t<GameListRemovedEventHandler>**)this)->Invoke(*(void**)(&identifier)));
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Gaming::Preview::GamesEnumeration::IGameListEntry> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::Preview::GamesEnumeration::IGameListEntry2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::Preview::GamesEnumeration::IGameListStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::Preview::GamesEnumeration::IGameListStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::Preview::GamesEnumeration::IGameModeConfiguration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::Preview::GamesEnumeration::IGameModeUserConfiguration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::Preview::GamesEnumeration::IGameModeUserConfigurationStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::Preview::GamesEnumeration::GameList> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::Preview::GamesEnumeration::GameListEntry> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::Preview::GamesEnumeration::GameModeConfiguration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::Preview::GamesEnumeration::GameModeUserConfiguration> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
