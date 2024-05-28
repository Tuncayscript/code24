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
#ifndef LLM_OS_Gaming_XboxLive_Storage_H
#define LLM_OS_Gaming_XboxLive_Storage_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.System.2.h"
#include "llm/impl/Windows.Gaming.XboxLive.Storage.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Gaming::XboxLive::Storage::GameSaveErrorStatus) consume_Windows_Gaming_XboxLive_Storage_IGameSaveBlobGetResult<D>::Status() const
    {
        llm::OS::Gaming::XboxLive::Storage::GameSaveErrorStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveBlobGetResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Storage::Streams::IBuffer>) consume_Windows_Gaming_XboxLive_Storage_IGameSaveBlobGetResult<D>::Value() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveBlobGetResult)->get_Value(&value));
        return llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Storage::Streams::IBuffer>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Gaming_XboxLive_Storage_IGameSaveBlobInfo<D>::Name() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveBlobInfo)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Gaming_XboxLive_Storage_IGameSaveBlobInfo<D>::Size() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveBlobInfo)->get_Size(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Gaming::XboxLive::Storage::GameSaveErrorStatus) consume_Windows_Gaming_XboxLive_Storage_IGameSaveBlobInfoGetResult<D>::Status() const
    {
        llm::OS::Gaming::XboxLive::Storage::GameSaveErrorStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveBlobInfoGetResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Gaming::XboxLive::Storage::GameSaveBlobInfo>) consume_Windows_Gaming_XboxLive_Storage_IGameSaveBlobInfoGetResult<D>::Value() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveBlobInfoGetResult)->get_Value(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Gaming::XboxLive::Storage::GameSaveBlobInfo>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveBlobInfoGetResult>) consume_Windows_Gaming_XboxLive_Storage_IGameSaveBlobInfoQuery<D>::GetBlobInfoAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveBlobInfoQuery)->GetBlobInfoAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveBlobInfoGetResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveBlobInfoGetResult>) consume_Windows_Gaming_XboxLive_Storage_IGameSaveBlobInfoQuery<D>::GetBlobInfoAsync(uint32_t startIndex, uint32_t maxNumberOfItems) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveBlobInfoQuery)->GetBlobInfoWithIndexAndMaxAsync(startIndex, maxNumberOfItems, &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveBlobInfoGetResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<uint32_t>) consume_Windows_Gaming_XboxLive_Storage_IGameSaveBlobInfoQuery<D>::GetItemCountAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveBlobInfoQuery)->GetItemCountAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<uint32_t>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainer<D>::Name() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveContainer)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Gaming::XboxLive::Storage::GameSaveProvider) consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainer<D>::Provider() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveContainer)->get_Provider(&value));
        return llm::OS::Gaming::XboxLive::Storage::GameSaveProvider{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveOperationResult>) consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainer<D>::SubmitUpdatesAsync(param::async_map_view<hstring, llm::OS::Storage::Streams::IBuffer> const& blobsToWrite, param::async_iterable<hstring> const& blobsToDelete, param::hstring const& displayName) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveContainer)->SubmitUpdatesAsync(*(void**)(&blobsToWrite), *(void**)(&blobsToDelete), *(void**)(&displayName), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveOperationResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveOperationResult>) consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainer<D>::ReadAsync(param::async_map_view<hstring, llm::OS::Storage::Streams::IBuffer> const& blobsToRead) const
    {
        void* action{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveContainer)->ReadAsync(*(void**)(&blobsToRead), &action));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveOperationResult>{ action, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveBlobGetResult>) consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainer<D>::GetAsync(param::async_iterable<hstring> const& blobsToRead) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveContainer)->GetAsync(*(void**)(&blobsToRead), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveBlobGetResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveOperationResult>) consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainer<D>::SubmitPropertySetUpdatesAsync(llm::OS::Foundation::Collections::IPropertySet const& blobsToWrite, param::async_iterable<hstring> const& blobsToDelete, param::hstring const& displayName) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveContainer)->SubmitPropertySetUpdatesAsync(*(void**)(&blobsToWrite), *(void**)(&blobsToDelete), *(void**)(&displayName), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveOperationResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Gaming::XboxLive::Storage::GameSaveBlobInfoQuery) consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainer<D>::CreateBlobInfoQuery(param::hstring const& blobNamePrefix) const
    {
        void* query{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveContainer)->CreateBlobInfoQuery(*(void**)(&blobNamePrefix), &query));
        return llm::OS::Gaming::XboxLive::Storage::GameSaveBlobInfoQuery{ query, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainerInfo<D>::Name() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveContainerInfo)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainerInfo<D>::TotalSize() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveContainerInfo)->get_TotalSize(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainerInfo<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveContainerInfo)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainerInfo<D>::LastModifiedTime() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveContainerInfo)->get_LastModifiedTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainerInfo<D>::NeedsSync() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveContainerInfo)->get_NeedsSync(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Gaming::XboxLive::Storage::GameSaveErrorStatus) consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainerInfoGetResult<D>::Status() const
    {
        llm::OS::Gaming::XboxLive::Storage::GameSaveErrorStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveContainerInfoGetResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Gaming::XboxLive::Storage::GameSaveContainerInfo>) consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainerInfoGetResult<D>::Value() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveContainerInfoGetResult)->get_Value(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Gaming::XboxLive::Storage::GameSaveContainerInfo>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveContainerInfoGetResult>) consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainerInfoQuery<D>::GetContainerInfoAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveContainerInfoQuery)->GetContainerInfoAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveContainerInfoGetResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveContainerInfoGetResult>) consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainerInfoQuery<D>::GetContainerInfoAsync(uint32_t startIndex, uint32_t maxNumberOfItems) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveContainerInfoQuery)->GetContainerInfoWithIndexAndMaxAsync(startIndex, maxNumberOfItems, &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveContainerInfoGetResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<uint32_t>) consume_Windows_Gaming_XboxLive_Storage_IGameSaveContainerInfoQuery<D>::GetItemCountAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveContainerInfoQuery)->GetItemCountAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<uint32_t>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Gaming::XboxLive::Storage::GameSaveErrorStatus) consume_Windows_Gaming_XboxLive_Storage_IGameSaveOperationResult<D>::Status() const
    {
        llm::OS::Gaming::XboxLive::Storage::GameSaveErrorStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveOperationResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_Gaming_XboxLive_Storage_IGameSaveProvider<D>::User() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveProvider)->get_User(&value));
        return llm::OS::System::User{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Gaming::XboxLive::Storage::GameSaveContainer) consume_Windows_Gaming_XboxLive_Storage_IGameSaveProvider<D>::CreateContainer(param::hstring const& name) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveProvider)->CreateContainer(*(void**)(&name), &result));
        return llm::OS::Gaming::XboxLive::Storage::GameSaveContainer{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveOperationResult>) consume_Windows_Gaming_XboxLive_Storage_IGameSaveProvider<D>::DeleteContainerAsync(param::hstring const& name) const
    {
        void* action{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveProvider)->DeleteContainerAsync(*(void**)(&name), &action));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveOperationResult>{ action, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Gaming::XboxLive::Storage::GameSaveContainerInfoQuery) consume_Windows_Gaming_XboxLive_Storage_IGameSaveProvider<D>::CreateContainerInfoQuery() const
    {
        void* query{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveProvider)->CreateContainerInfoQuery(&query));
        return llm::OS::Gaming::XboxLive::Storage::GameSaveContainerInfoQuery{ query, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Gaming::XboxLive::Storage::GameSaveContainerInfoQuery) consume_Windows_Gaming_XboxLive_Storage_IGameSaveProvider<D>::CreateContainerInfoQuery(param::hstring const& containerNamePrefix) const
    {
        void* query{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveProvider)->CreateContainerInfoQueryWithName(*(void**)(&containerNamePrefix), &query));
        return llm::OS::Gaming::XboxLive::Storage::GameSaveContainerInfoQuery{ query, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<int64_t>) consume_Windows_Gaming_XboxLive_Storage_IGameSaveProvider<D>::GetRemainingBytesInQuotaAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveProvider)->GetRemainingBytesInQuotaAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<int64_t>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_Gaming_XboxLive_Storage_IGameSaveProvider<D>::ContainersChangedSinceLastSync() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveProvider)->get_ContainersChangedSinceLastSync(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Gaming::XboxLive::Storage::GameSaveErrorStatus) consume_Windows_Gaming_XboxLive_Storage_IGameSaveProviderGetResult<D>::Status() const
    {
        llm::OS::Gaming::XboxLive::Storage::GameSaveErrorStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveProviderGetResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Gaming::XboxLive::Storage::GameSaveProvider) consume_Windows_Gaming_XboxLive_Storage_IGameSaveProviderGetResult<D>::Value() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveProviderGetResult)->get_Value(&value));
        return llm::OS::Gaming::XboxLive::Storage::GameSaveProvider{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveProviderGetResult>) consume_Windows_Gaming_XboxLive_Storage_IGameSaveProviderStatics<D>::GetForUserAsync(llm::OS::System::User const& user, param::hstring const& serviceConfigId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveProviderStatics)->GetForUserAsync(*(void**)(&user), *(void**)(&serviceConfigId), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveProviderGetResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveProviderGetResult>) consume_Windows_Gaming_XboxLive_Storage_IGameSaveProviderStatics<D>::GetSyncOnDemandForUserAsync(llm::OS::System::User const& user, param::hstring const& serviceConfigId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::XboxLive::Storage::IGameSaveProviderStatics)->GetSyncOnDemandForUserAsync(*(void**)(&user), *(void**)(&serviceConfigId), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveProviderGetResult>{ operation, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Gaming::XboxLive::Storage::IGameSaveBlobGetResult> : produce_base<D, llm::OS::Gaming::XboxLive::Storage::IGameSaveBlobGetResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Gaming::XboxLive::Storage::GameSaveErrorStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Value(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Storage::Streams::IBuffer>>(this->shim().Value());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Gaming::XboxLive::Storage::IGameSaveBlobInfo> : produce_base<D, llm::OS::Gaming::XboxLive::Storage::IGameSaveBlobInfo>
    {
        int32_t __stdcall get_Name(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Name());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Size(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Size());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Gaming::XboxLive::Storage::IGameSaveBlobInfoGetResult> : produce_base<D, llm::OS::Gaming::XboxLive::Storage::IGameSaveBlobInfoGetResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Gaming::XboxLive::Storage::GameSaveErrorStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Value(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Gaming::XboxLive::Storage::GameSaveBlobInfo>>(this->shim().Value());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Gaming::XboxLive::Storage::IGameSaveBlobInfoQuery> : produce_base<D, llm::OS::Gaming::XboxLive::Storage::IGameSaveBlobInfoQuery>
    {
        int32_t __stdcall GetBlobInfoAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveBlobInfoGetResult>>(this->shim().GetBlobInfoAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetBlobInfoWithIndexAndMaxAsync(uint32_t startIndex, uint32_t maxNumberOfItems, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveBlobInfoGetResult>>(this->shim().GetBlobInfoAsync(startIndex, maxNumberOfItems));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetItemCountAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<uint32_t>>(this->shim().GetItemCountAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Gaming::XboxLive::Storage::IGameSaveContainer> : produce_base<D, llm::OS::Gaming::XboxLive::Storage::IGameSaveContainer>
    {
        int32_t __stdcall get_Name(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Name());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Provider(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Gaming::XboxLive::Storage::GameSaveProvider>(this->shim().Provider());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SubmitUpdatesAsync(void* blobsToWrite, void* blobsToDelete, void* displayName, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveOperationResult>>(this->shim().SubmitUpdatesAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Storage::Streams::IBuffer> const*>(&blobsToWrite), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&blobsToDelete), *reinterpret_cast<hstring const*>(&displayName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReadAsync(void* blobsToRead, void** action) noexcept final try
        {
            clear_abi(action);
            typename D::abi_guard guard(this->shim());
            *action = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveOperationResult>>(this->shim().ReadAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Storage::Streams::IBuffer> const*>(&blobsToRead)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAsync(void* blobsToRead, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveBlobGetResult>>(this->shim().GetAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&blobsToRead)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SubmitPropertySetUpdatesAsync(void* blobsToWrite, void* blobsToDelete, void* displayName, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveOperationResult>>(this->shim().SubmitPropertySetUpdatesAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IPropertySet const*>(&blobsToWrite), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&blobsToDelete), *reinterpret_cast<hstring const*>(&displayName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateBlobInfoQuery(void* blobNamePrefix, void** query) noexcept final try
        {
            clear_abi(query);
            typename D::abi_guard guard(this->shim());
            *query = detach_from<llm::OS::Gaming::XboxLive::Storage::GameSaveBlobInfoQuery>(this->shim().CreateBlobInfoQuery(*reinterpret_cast<hstring const*>(&blobNamePrefix)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Gaming::XboxLive::Storage::IGameSaveContainerInfo> : produce_base<D, llm::OS::Gaming::XboxLive::Storage::IGameSaveContainerInfo>
    {
        int32_t __stdcall get_Name(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Name());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TotalSize(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().TotalSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LastModifiedTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().LastModifiedTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NeedsSync(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().NeedsSync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Gaming::XboxLive::Storage::IGameSaveContainerInfoGetResult> : produce_base<D, llm::OS::Gaming::XboxLive::Storage::IGameSaveContainerInfoGetResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Gaming::XboxLive::Storage::GameSaveErrorStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Value(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Gaming::XboxLive::Storage::GameSaveContainerInfo>>(this->shim().Value());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Gaming::XboxLive::Storage::IGameSaveContainerInfoQuery> : produce_base<D, llm::OS::Gaming::XboxLive::Storage::IGameSaveContainerInfoQuery>
    {
        int32_t __stdcall GetContainerInfoAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveContainerInfoGetResult>>(this->shim().GetContainerInfoAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetContainerInfoWithIndexAndMaxAsync(uint32_t startIndex, uint32_t maxNumberOfItems, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveContainerInfoGetResult>>(this->shim().GetContainerInfoAsync(startIndex, maxNumberOfItems));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetItemCountAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<uint32_t>>(this->shim().GetItemCountAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Gaming::XboxLive::Storage::IGameSaveOperationResult> : produce_base<D, llm::OS::Gaming::XboxLive::Storage::IGameSaveOperationResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Gaming::XboxLive::Storage::GameSaveErrorStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Gaming::XboxLive::Storage::IGameSaveProvider> : produce_base<D, llm::OS::Gaming::XboxLive::Storage::IGameSaveProvider>
    {
        int32_t __stdcall get_User(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::User>(this->shim().User());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateContainer(void* name, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Gaming::XboxLive::Storage::GameSaveContainer>(this->shim().CreateContainer(*reinterpret_cast<hstring const*>(&name)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DeleteContainerAsync(void* name, void** action) noexcept final try
        {
            clear_abi(action);
            typename D::abi_guard guard(this->shim());
            *action = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveOperationResult>>(this->shim().DeleteContainerAsync(*reinterpret_cast<hstring const*>(&name)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateContainerInfoQuery(void** query) noexcept final try
        {
            clear_abi(query);
            typename D::abi_guard guard(this->shim());
            *query = detach_from<llm::OS::Gaming::XboxLive::Storage::GameSaveContainerInfoQuery>(this->shim().CreateContainerInfoQuery());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateContainerInfoQueryWithName(void* containerNamePrefix, void** query) noexcept final try
        {
            clear_abi(query);
            typename D::abi_guard guard(this->shim());
            *query = detach_from<llm::OS::Gaming::XboxLive::Storage::GameSaveContainerInfoQuery>(this->shim().CreateContainerInfoQuery(*reinterpret_cast<hstring const*>(&containerNamePrefix)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetRemainingBytesInQuotaAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<int64_t>>(this->shim().GetRemainingBytesInQuotaAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ContainersChangedSinceLastSync(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().ContainersChangedSinceLastSync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Gaming::XboxLive::Storage::IGameSaveProviderGetResult> : produce_base<D, llm::OS::Gaming::XboxLive::Storage::IGameSaveProviderGetResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Gaming::XboxLive::Storage::GameSaveErrorStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Value(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Gaming::XboxLive::Storage::GameSaveProvider>(this->shim().Value());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Gaming::XboxLive::Storage::IGameSaveProviderStatics> : produce_base<D, llm::OS::Gaming::XboxLive::Storage::IGameSaveProviderStatics>
    {
        int32_t __stdcall GetForUserAsync(void* user, void* serviceConfigId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveProviderGetResult>>(this->shim().GetForUserAsync(*reinterpret_cast<llm::OS::System::User const*>(&user), *reinterpret_cast<hstring const*>(&serviceConfigId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSyncOnDemandForUserAsync(void* user, void* serviceConfigId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::XboxLive::Storage::GameSaveProviderGetResult>>(this->shim().GetSyncOnDemandForUserAsync(*reinterpret_cast<llm::OS::System::User const*>(&user), *reinterpret_cast<hstring const*>(&serviceConfigId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Gaming::XboxLive::Storage
{
    inline auto GameSaveProvider::GetForUserAsync(llm::OS::System::User const& user, param::hstring const& serviceConfigId)
    {
        return impl::call_factory<GameSaveProvider, IGameSaveProviderStatics>([&](IGameSaveProviderStatics const& f) { return f.GetForUserAsync(user, serviceConfigId); });
    }
    inline auto GameSaveProvider::GetSyncOnDemandForUserAsync(llm::OS::System::User const& user, param::hstring const& serviceConfigId)
    {
        return impl::call_factory<GameSaveProvider, IGameSaveProviderStatics>([&](IGameSaveProviderStatics const& f) { return f.GetSyncOnDemandForUserAsync(user, serviceConfigId); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Gaming::XboxLive::Storage::IGameSaveBlobGetResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::XboxLive::Storage::IGameSaveBlobInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::XboxLive::Storage::IGameSaveBlobInfoGetResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::XboxLive::Storage::IGameSaveBlobInfoQuery> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::XboxLive::Storage::IGameSaveContainer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::XboxLive::Storage::IGameSaveContainerInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::XboxLive::Storage::IGameSaveContainerInfoGetResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::XboxLive::Storage::IGameSaveContainerInfoQuery> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::XboxLive::Storage::IGameSaveOperationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::XboxLive::Storage::IGameSaveProvider> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::XboxLive::Storage::IGameSaveProviderGetResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::XboxLive::Storage::IGameSaveProviderStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::XboxLive::Storage::GameSaveBlobGetResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::XboxLive::Storage::GameSaveBlobInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::XboxLive::Storage::GameSaveBlobInfoGetResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::XboxLive::Storage::GameSaveBlobInfoQuery> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::XboxLive::Storage::GameSaveContainer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::XboxLive::Storage::GameSaveContainerInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::XboxLive::Storage::GameSaveContainerInfoGetResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::XboxLive::Storage::GameSaveContainerInfoQuery> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::XboxLive::Storage::GameSaveOperationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::XboxLive::Storage::GameSaveProvider> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::XboxLive::Storage::GameSaveProviderGetResult> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
