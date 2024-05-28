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
#ifndef LLM_OS_Storage_BulkAccess_H
#define LLM_OS_Storage_BulkAccess_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Storage.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Storage.2.h"
#include "llm/impl/Windows.Storage.FileProperties.2.h"
#include "llm/impl/Windows.Storage.Search.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.Storage.BulkAccess.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::BulkAccess::IStorageItemInformation>>) consume_Windows_Storage_BulkAccess_IFileInformationFactory<D>::GetItemsAsync(uint32_t startIndex, uint32_t maxItemsToRetrieve) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::BulkAccess::IFileInformationFactory)->GetItemsAsync(startIndex, maxItemsToRetrieve, &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::BulkAccess::IStorageItemInformation>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::BulkAccess::IStorageItemInformation>>) consume_Windows_Storage_BulkAccess_IFileInformationFactory<D>::GetItemsAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::BulkAccess::IFileInformationFactory)->GetItemsAsyncDefaultStartAndCount(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::BulkAccess::IStorageItemInformation>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::BulkAccess::FileInformation>>) consume_Windows_Storage_BulkAccess_IFileInformationFactory<D>::GetFilesAsync(uint32_t startIndex, uint32_t maxItemsToRetrieve) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::BulkAccess::IFileInformationFactory)->GetFilesAsync(startIndex, maxItemsToRetrieve, &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::BulkAccess::FileInformation>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::BulkAccess::FileInformation>>) consume_Windows_Storage_BulkAccess_IFileInformationFactory<D>::GetFilesAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::BulkAccess::IFileInformationFactory)->GetFilesAsyncDefaultStartAndCount(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::BulkAccess::FileInformation>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::BulkAccess::FolderInformation>>) consume_Windows_Storage_BulkAccess_IFileInformationFactory<D>::GetFoldersAsync(uint32_t startIndex, uint32_t maxItemsToRetrieve) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::BulkAccess::IFileInformationFactory)->GetFoldersAsync(startIndex, maxItemsToRetrieve, &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::BulkAccess::FolderInformation>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::BulkAccess::FolderInformation>>) consume_Windows_Storage_BulkAccess_IFileInformationFactory<D>::GetFoldersAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::BulkAccess::IFileInformationFactory)->GetFoldersAsyncDefaultStartAndCount(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::BulkAccess::FolderInformation>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Storage_BulkAccess_IFileInformationFactory<D>::GetVirtualizedItemsVector() const
    {
        void* vector{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::BulkAccess::IFileInformationFactory)->GetVirtualizedItemsVector(&vector));
        return llm::OS::Foundation::IInspectable{ vector, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Storage_BulkAccess_IFileInformationFactory<D>::GetVirtualizedFilesVector() const
    {
        void* vector{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::BulkAccess::IFileInformationFactory)->GetVirtualizedFilesVector(&vector));
        return llm::OS::Foundation::IInspectable{ vector, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Storage_BulkAccess_IFileInformationFactory<D>::GetVirtualizedFoldersVector() const
    {
        void* vector{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::BulkAccess::IFileInformationFactory)->GetVirtualizedFoldersVector(&vector));
        return llm::OS::Foundation::IInspectable{ vector, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::BulkAccess::FileInformationFactory) consume_Windows_Storage_BulkAccess_IFileInformationFactoryFactory<D>::CreateWithMode(llm::OS::Storage::Search::IStorageQueryResultBase const& queryResult, llm::OS::Storage::FileProperties::ThumbnailMode const& mode) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::BulkAccess::IFileInformationFactoryFactory)->CreateWithMode(*(void**)(&queryResult), static_cast<int32_t>(mode), &value));
        return llm::OS::Storage::BulkAccess::FileInformationFactory{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::BulkAccess::FileInformationFactory) consume_Windows_Storage_BulkAccess_IFileInformationFactoryFactory<D>::CreateWithModeAndSize(llm::OS::Storage::Search::IStorageQueryResultBase const& queryResult, llm::OS::Storage::FileProperties::ThumbnailMode const& mode, uint32_t requestedThumbnailSize) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::BulkAccess::IFileInformationFactoryFactory)->CreateWithModeAndSize(*(void**)(&queryResult), static_cast<int32_t>(mode), requestedThumbnailSize, &value));
        return llm::OS::Storage::BulkAccess::FileInformationFactory{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::BulkAccess::FileInformationFactory) consume_Windows_Storage_BulkAccess_IFileInformationFactoryFactory<D>::CreateWithModeAndSizeAndOptions(llm::OS::Storage::Search::IStorageQueryResultBase const& queryResult, llm::OS::Storage::FileProperties::ThumbnailMode const& mode, uint32_t requestedThumbnailSize, llm::OS::Storage::FileProperties::ThumbnailOptions const& thumbnailOptions) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::BulkAccess::IFileInformationFactoryFactory)->CreateWithModeAndSizeAndOptions(*(void**)(&queryResult), static_cast<int32_t>(mode), requestedThumbnailSize, static_cast<uint32_t>(thumbnailOptions), &value));
        return llm::OS::Storage::BulkAccess::FileInformationFactory{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::BulkAccess::FileInformationFactory) consume_Windows_Storage_BulkAccess_IFileInformationFactoryFactory<D>::CreateWithModeAndSizeAndOptionsAndFlags(llm::OS::Storage::Search::IStorageQueryResultBase const& queryResult, llm::OS::Storage::FileProperties::ThumbnailMode const& mode, uint32_t requestedThumbnailSize, llm::OS::Storage::FileProperties::ThumbnailOptions const& thumbnailOptions, bool delayLoad) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::BulkAccess::IFileInformationFactoryFactory)->CreateWithModeAndSizeAndOptionsAndFlags(*(void**)(&queryResult), static_cast<int32_t>(mode), requestedThumbnailSize, static_cast<uint32_t>(thumbnailOptions), delayLoad, &value));
        return llm::OS::Storage::BulkAccess::FileInformationFactory{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::FileProperties::MusicProperties) consume_Windows_Storage_BulkAccess_IStorageItemInformation<D>::MusicProperties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::BulkAccess::IStorageItemInformation)->get_MusicProperties(&value));
        return llm::OS::Storage::FileProperties::MusicProperties{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::FileProperties::VideoProperties) consume_Windows_Storage_BulkAccess_IStorageItemInformation<D>::VideoProperties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::BulkAccess::IStorageItemInformation)->get_VideoProperties(&value));
        return llm::OS::Storage::FileProperties::VideoProperties{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::FileProperties::ImageProperties) consume_Windows_Storage_BulkAccess_IStorageItemInformation<D>::ImageProperties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::BulkAccess::IStorageItemInformation)->get_ImageProperties(&value));
        return llm::OS::Storage::FileProperties::ImageProperties{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::FileProperties::DocumentProperties) consume_Windows_Storage_BulkAccess_IStorageItemInformation<D>::DocumentProperties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::BulkAccess::IStorageItemInformation)->get_DocumentProperties(&value));
        return llm::OS::Storage::FileProperties::DocumentProperties{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::FileProperties::BasicProperties) consume_Windows_Storage_BulkAccess_IStorageItemInformation<D>::BasicProperties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::BulkAccess::IStorageItemInformation)->get_BasicProperties(&value));
        return llm::OS::Storage::FileProperties::BasicProperties{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::FileProperties::StorageItemThumbnail) consume_Windows_Storage_BulkAccess_IStorageItemInformation<D>::Thumbnail() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::BulkAccess::IStorageItemInformation)->get_Thumbnail(&value));
        return llm::OS::Storage::FileProperties::StorageItemThumbnail{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Storage_BulkAccess_IStorageItemInformation<D>::ThumbnailUpdated(llm::OS::Foundation::TypedEventHandler<llm::OS::Storage::BulkAccess::IStorageItemInformation, llm::OS::Foundation::IInspectable> const& changedHandler) const
    {
        llm::event_token eventCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::BulkAccess::IStorageItemInformation)->add_ThumbnailUpdated(*(void**)(&changedHandler), put_abi(eventCookie)));
        return eventCookie;
    }
    template <typename D> typename consume_Windows_Storage_BulkAccess_IStorageItemInformation<D>::ThumbnailUpdated_revoker consume_Windows_Storage_BulkAccess_IStorageItemInformation<D>::ThumbnailUpdated(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Storage::BulkAccess::IStorageItemInformation, llm::OS::Foundation::IInspectable> const& changedHandler) const
    {
        return impl::make_event_revoker<D, ThumbnailUpdated_revoker>(this, ThumbnailUpdated(changedHandler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_BulkAccess_IStorageItemInformation<D>::ThumbnailUpdated(llm::event_token const& eventCookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Storage::BulkAccess::IStorageItemInformation)->remove_ThumbnailUpdated(impl::bind_in(eventCookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Storage_BulkAccess_IStorageItemInformation<D>::PropertiesUpdated(llm::OS::Foundation::TypedEventHandler<llm::OS::Storage::BulkAccess::IStorageItemInformation, llm::OS::Foundation::IInspectable> const& changedHandler) const
    {
        llm::event_token eventCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::BulkAccess::IStorageItemInformation)->add_PropertiesUpdated(*(void**)(&changedHandler), put_abi(eventCookie)));
        return eventCookie;
    }
    template <typename D> typename consume_Windows_Storage_BulkAccess_IStorageItemInformation<D>::PropertiesUpdated_revoker consume_Windows_Storage_BulkAccess_IStorageItemInformation<D>::PropertiesUpdated(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Storage::BulkAccess::IStorageItemInformation, llm::OS::Foundation::IInspectable> const& changedHandler) const
    {
        return impl::make_event_revoker<D, PropertiesUpdated_revoker>(this, PropertiesUpdated(changedHandler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_BulkAccess_IStorageItemInformation<D>::PropertiesUpdated(llm::event_token const& eventCookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Storage::BulkAccess::IStorageItemInformation)->remove_PropertiesUpdated(impl::bind_in(eventCookie));
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::BulkAccess::IFileInformationFactory> : produce_base<D, llm::OS::Storage::BulkAccess::IFileInformationFactory>
    {
        int32_t __stdcall GetItemsAsync(uint32_t startIndex, uint32_t maxItemsToRetrieve, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::BulkAccess::IStorageItemInformation>>>(this->shim().GetItemsAsync(startIndex, maxItemsToRetrieve));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetItemsAsyncDefaultStartAndCount(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::BulkAccess::IStorageItemInformation>>>(this->shim().GetItemsAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetFilesAsync(uint32_t startIndex, uint32_t maxItemsToRetrieve, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::BulkAccess::FileInformation>>>(this->shim().GetFilesAsync(startIndex, maxItemsToRetrieve));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetFilesAsyncDefaultStartAndCount(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::BulkAccess::FileInformation>>>(this->shim().GetFilesAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetFoldersAsync(uint32_t startIndex, uint32_t maxItemsToRetrieve, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::BulkAccess::FolderInformation>>>(this->shim().GetFoldersAsync(startIndex, maxItemsToRetrieve));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetFoldersAsyncDefaultStartAndCount(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::BulkAccess::FolderInformation>>>(this->shim().GetFoldersAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetVirtualizedItemsVector(void** vector) noexcept final try
        {
            clear_abi(vector);
            typename D::abi_guard guard(this->shim());
            *vector = detach_from<llm::OS::Foundation::IInspectable>(this->shim().GetVirtualizedItemsVector());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetVirtualizedFilesVector(void** vector) noexcept final try
        {
            clear_abi(vector);
            typename D::abi_guard guard(this->shim());
            *vector = detach_from<llm::OS::Foundation::IInspectable>(this->shim().GetVirtualizedFilesVector());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetVirtualizedFoldersVector(void** vector) noexcept final try
        {
            clear_abi(vector);
            typename D::abi_guard guard(this->shim());
            *vector = detach_from<llm::OS::Foundation::IInspectable>(this->shim().GetVirtualizedFoldersVector());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::BulkAccess::IFileInformationFactoryFactory> : produce_base<D, llm::OS::Storage::BulkAccess::IFileInformationFactoryFactory>
    {
        int32_t __stdcall CreateWithMode(void* queryResult, int32_t mode, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::BulkAccess::FileInformationFactory>(this->shim().CreateWithMode(*reinterpret_cast<llm::OS::Storage::Search::IStorageQueryResultBase const*>(&queryResult), *reinterpret_cast<llm::OS::Storage::FileProperties::ThumbnailMode const*>(&mode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithModeAndSize(void* queryResult, int32_t mode, uint32_t requestedThumbnailSize, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::BulkAccess::FileInformationFactory>(this->shim().CreateWithModeAndSize(*reinterpret_cast<llm::OS::Storage::Search::IStorageQueryResultBase const*>(&queryResult), *reinterpret_cast<llm::OS::Storage::FileProperties::ThumbnailMode const*>(&mode), requestedThumbnailSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithModeAndSizeAndOptions(void* queryResult, int32_t mode, uint32_t requestedThumbnailSize, uint32_t thumbnailOptions, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::BulkAccess::FileInformationFactory>(this->shim().CreateWithModeAndSizeAndOptions(*reinterpret_cast<llm::OS::Storage::Search::IStorageQueryResultBase const*>(&queryResult), *reinterpret_cast<llm::OS::Storage::FileProperties::ThumbnailMode const*>(&mode), requestedThumbnailSize, *reinterpret_cast<llm::OS::Storage::FileProperties::ThumbnailOptions const*>(&thumbnailOptions)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithModeAndSizeAndOptionsAndFlags(void* queryResult, int32_t mode, uint32_t requestedThumbnailSize, uint32_t thumbnailOptions, bool delayLoad, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::BulkAccess::FileInformationFactory>(this->shim().CreateWithModeAndSizeAndOptionsAndFlags(*reinterpret_cast<llm::OS::Storage::Search::IStorageQueryResultBase const*>(&queryResult), *reinterpret_cast<llm::OS::Storage::FileProperties::ThumbnailMode const*>(&mode), requestedThumbnailSize, *reinterpret_cast<llm::OS::Storage::FileProperties::ThumbnailOptions const*>(&thumbnailOptions), delayLoad));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Storage::BulkAccess::IStorageItemInformation> : produce_base<D, llm::OS::Storage::BulkAccess::IStorageItemInformation>
    {
        int32_t __stdcall get_MusicProperties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::FileProperties::MusicProperties>(this->shim().MusicProperties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VideoProperties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::FileProperties::VideoProperties>(this->shim().VideoProperties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ImageProperties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::FileProperties::ImageProperties>(this->shim().ImageProperties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DocumentProperties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::FileProperties::DocumentProperties>(this->shim().DocumentProperties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BasicProperties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::FileProperties::BasicProperties>(this->shim().BasicProperties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Thumbnail(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::FileProperties::StorageItemThumbnail>(this->shim().Thumbnail());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_ThumbnailUpdated(void* changedHandler, llm::event_token* eventCookie) noexcept final try
        {
            zero_abi<llm::event_token>(eventCookie);
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_from<llm::event_token>(this->shim().ThumbnailUpdated(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Storage::BulkAccess::IStorageItemInformation, llm::OS::Foundation::IInspectable> const*>(&changedHandler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ThumbnailUpdated(llm::event_token eventCookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ThumbnailUpdated(*reinterpret_cast<llm::event_token const*>(&eventCookie));
            return 0;
        }
        int32_t __stdcall add_PropertiesUpdated(void* changedHandler, llm::event_token* eventCookie) noexcept final try
        {
            zero_abi<llm::event_token>(eventCookie);
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_from<llm::event_token>(this->shim().PropertiesUpdated(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Storage::BulkAccess::IStorageItemInformation, llm::OS::Foundation::IInspectable> const*>(&changedHandler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PropertiesUpdated(llm::event_token eventCookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PropertiesUpdated(*reinterpret_cast<llm::event_token const*>(&eventCookie));
            return 0;
        }
    };
}
LLM_EXPORT namespace llm::OS::Storage::BulkAccess
{
    inline FileInformationFactory::FileInformationFactory(llm::OS::Storage::Search::IStorageQueryResultBase const& queryResult, llm::OS::Storage::FileProperties::ThumbnailMode const& mode) :
        FileInformationFactory(impl::call_factory<FileInformationFactory, IFileInformationFactoryFactory>([&](IFileInformationFactoryFactory const& f) { return f.CreateWithMode(queryResult, mode); }))
    {
    }
    inline FileInformationFactory::FileInformationFactory(llm::OS::Storage::Search::IStorageQueryResultBase const& queryResult, llm::OS::Storage::FileProperties::ThumbnailMode const& mode, uint32_t requestedThumbnailSize) :
        FileInformationFactory(impl::call_factory<FileInformationFactory, IFileInformationFactoryFactory>([&](IFileInformationFactoryFactory const& f) { return f.CreateWithModeAndSize(queryResult, mode, requestedThumbnailSize); }))
    {
    }
    inline FileInformationFactory::FileInformationFactory(llm::OS::Storage::Search::IStorageQueryResultBase const& queryResult, llm::OS::Storage::FileProperties::ThumbnailMode const& mode, uint32_t requestedThumbnailSize, llm::OS::Storage::FileProperties::ThumbnailOptions const& thumbnailOptions) :
        FileInformationFactory(impl::call_factory<FileInformationFactory, IFileInformationFactoryFactory>([&](IFileInformationFactoryFactory const& f) { return f.CreateWithModeAndSizeAndOptions(queryResult, mode, requestedThumbnailSize, thumbnailOptions); }))
    {
    }
    inline FileInformationFactory::FileInformationFactory(llm::OS::Storage::Search::IStorageQueryResultBase const& queryResult, llm::OS::Storage::FileProperties::ThumbnailMode const& mode, uint32_t requestedThumbnailSize, llm::OS::Storage::FileProperties::ThumbnailOptions const& thumbnailOptions, bool delayLoad) :
        FileInformationFactory(impl::call_factory<FileInformationFactory, IFileInformationFactoryFactory>([&](IFileInformationFactoryFactory const& f) { return f.CreateWithModeAndSizeAndOptionsAndFlags(queryResult, mode, requestedThumbnailSize, thumbnailOptions, delayLoad); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Storage::BulkAccess::IFileInformationFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::BulkAccess::IFileInformationFactoryFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::BulkAccess::IStorageItemInformation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::BulkAccess::FileInformation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::BulkAccess::FileInformationFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::BulkAccess::FolderInformation> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
