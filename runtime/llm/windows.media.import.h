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
#ifndef LLM_OS_Media_Import_H
#define LLM_OS_Media_Import_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Media.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Storage.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.Media.Import.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Import::PhotoImportSession) consume_Windows_Media_Import_IPhotoImportDeleteImportedItemsFromSourceResult<D>::Session() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult)->get_Session(&value));
        return llm::OS::Media::Import::PhotoImportSession{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Import_IPhotoImportDeleteImportedItemsFromSourceResult<D>::HasSucceeded() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult)->get_HasSucceeded(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Import::PhotoImportItem>) consume_Windows_Media_Import_IPhotoImportDeleteImportedItemsFromSourceResult<D>::DeletedItems() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult)->get_DeletedItems(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Import::PhotoImportItem>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Import_IPhotoImportDeleteImportedItemsFromSourceResult<D>::PhotosCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult)->get_PhotosCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Media_Import_IPhotoImportDeleteImportedItemsFromSourceResult<D>::PhotosSizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult)->get_PhotosSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Import_IPhotoImportDeleteImportedItemsFromSourceResult<D>::VideosCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult)->get_VideosCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Media_Import_IPhotoImportDeleteImportedItemsFromSourceResult<D>::VideosSizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult)->get_VideosSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Import_IPhotoImportDeleteImportedItemsFromSourceResult<D>::SidecarsCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult)->get_SidecarsCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Media_Import_IPhotoImportDeleteImportedItemsFromSourceResult<D>::SidecarsSizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult)->get_SidecarsSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Import_IPhotoImportDeleteImportedItemsFromSourceResult<D>::SiblingsCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult)->get_SiblingsCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Media_Import_IPhotoImportDeleteImportedItemsFromSourceResult<D>::SiblingsSizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult)->get_SiblingsSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Import_IPhotoImportDeleteImportedItemsFromSourceResult<D>::TotalCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult)->get_TotalCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Media_Import_IPhotoImportDeleteImportedItemsFromSourceResult<D>::TotalSizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult)->get_TotalSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Import::PhotoImportSession) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::Session() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->get_Session(&value));
        return llm::OS::Media::Import::PhotoImportSession{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::HasSucceeded() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->get_HasSucceeded(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Import::PhotoImportItem>) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::FoundItems() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->get_FoundItems(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Import::PhotoImportItem>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::PhotosCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->get_PhotosCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::PhotosSizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->get_PhotosSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::VideosCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->get_VideosCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::VideosSizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->get_VideosSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::SidecarsCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->get_SidecarsCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::SidecarsSizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->get_SidecarsSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::SiblingsCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->get_SiblingsCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::SiblingsSizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->get_SiblingsSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::TotalCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->get_TotalCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::TotalSizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->get_TotalSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::SelectAll() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->SelectAll());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::SelectNone() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->SelectNone());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::SelectNewAsync() const
    {
        void* action{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->SelectNewAsync(&action));
        return llm::OS::Foundation::IAsyncAction{ action, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::SetImportMode(llm::OS::Media::Import::PhotoImportImportMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->SetImportMode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Import::PhotoImportImportMode) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::ImportMode() const
    {
        llm::OS::Media::Import::PhotoImportImportMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->get_ImportMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::SelectedPhotosCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->get_SelectedPhotosCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::SelectedPhotosSizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->get_SelectedPhotosSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::SelectedVideosCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->get_SelectedVideosCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::SelectedVideosSizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->get_SelectedVideosSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::SelectedSidecarsCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->get_SelectedSidecarsCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::SelectedSidecarsSizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->get_SelectedSidecarsSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::SelectedSiblingsCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->get_SelectedSiblingsCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::SelectedSiblingsSizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->get_SelectedSiblingsSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::SelectedTotalCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->get_SelectedTotalCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::SelectedTotalSizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->get_SelectedTotalSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::SelectionChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Import::PhotoImportFindItemsResult, llm::OS::Media::Import::PhotoImportSelectionChangedEventArgs> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->add_SelectionChanged(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::SelectionChanged_revoker consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::SelectionChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Import::PhotoImportFindItemsResult, llm::OS::Media::Import::PhotoImportSelectionChangedEventArgs> const& value) const
    {
        return impl::make_event_revoker<D, SelectionChanged_revoker>(this, SelectionChanged(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::SelectionChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->remove_SelectionChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Media::Import::PhotoImportImportItemsResult, llm::OS::Media::Import::PhotoImportProgress>) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::ImportItemsAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->ImportItemsAsync(&operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Media::Import::PhotoImportImportItemsResult, llm::OS::Media::Import::PhotoImportProgress>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::ItemImported(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Import::PhotoImportFindItemsResult, llm::OS::Media::Import::PhotoImportItemImportedEventArgs> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->add_ItemImported(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::ItemImported_revoker consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::ItemImported(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Import::PhotoImportFindItemsResult, llm::OS::Media::Import::PhotoImportItemImportedEventArgs> const& value) const
    {
        return impl::make_event_revoker<D, ItemImported_revoker>(this, ItemImported(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>::ItemImported(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult)->remove_ItemImported(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Import_IPhotoImportFindItemsResult2<D>::AddItemsInDateRangeToSelection(llm::OS::Foundation::DateTime const& rangeStart, llm::OS::Foundation::TimeSpan const& rangeLength) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportFindItemsResult2)->AddItemsInDateRangeToSelection(impl::bind_in(rangeStart), impl::bind_in(rangeLength)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Import::PhotoImportSession) consume_Windows_Media_Import_IPhotoImportImportItemsResult<D>::Session() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportImportItemsResult)->get_Session(&value));
        return llm::OS::Media::Import::PhotoImportSession{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Import_IPhotoImportImportItemsResult<D>::HasSucceeded() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportImportItemsResult)->get_HasSucceeded(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Import::PhotoImportItem>) consume_Windows_Media_Import_IPhotoImportImportItemsResult<D>::ImportedItems() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportImportItemsResult)->get_ImportedItems(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Import::PhotoImportItem>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Import_IPhotoImportImportItemsResult<D>::PhotosCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportImportItemsResult)->get_PhotosCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Media_Import_IPhotoImportImportItemsResult<D>::PhotosSizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportImportItemsResult)->get_PhotosSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Import_IPhotoImportImportItemsResult<D>::VideosCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportImportItemsResult)->get_VideosCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Media_Import_IPhotoImportImportItemsResult<D>::VideosSizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportImportItemsResult)->get_VideosSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Import_IPhotoImportImportItemsResult<D>::SidecarsCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportImportItemsResult)->get_SidecarsCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Media_Import_IPhotoImportImportItemsResult<D>::SidecarsSizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportImportItemsResult)->get_SidecarsSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Import_IPhotoImportImportItemsResult<D>::SiblingsCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportImportItemsResult)->get_SiblingsCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Media_Import_IPhotoImportImportItemsResult<D>::SiblingsSizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportImportItemsResult)->get_SiblingsSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Import_IPhotoImportImportItemsResult<D>::TotalCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportImportItemsResult)->get_TotalCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Media_Import_IPhotoImportImportItemsResult<D>::TotalSizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportImportItemsResult)->get_TotalSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Media::Import::PhotoImportDeleteImportedItemsFromSourceResult, double>) consume_Windows_Media_Import_IPhotoImportImportItemsResult<D>::DeleteImportedItemsFromSourceAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportImportItemsResult)->DeleteImportedItemsFromSourceAsync(&result));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Media::Import::PhotoImportDeleteImportedItemsFromSourceResult, double>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Import_IPhotoImportItem<D>::Name() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportItem)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Media_Import_IPhotoImportItem<D>::ItemKey() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportItem)->get_ItemKey(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Import::PhotoImportContentType) consume_Windows_Media_Import_IPhotoImportItem<D>::ContentType() const
    {
        llm::OS::Media::Import::PhotoImportContentType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportItem)->get_ContentType(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Media_Import_IPhotoImportItem<D>::SizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportItem)->get_SizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Media_Import_IPhotoImportItem<D>::Date() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportItem)->get_Date(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Import::PhotoImportSidecar) consume_Windows_Media_Import_IPhotoImportItem<D>::Sibling() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportItem)->get_Sibling(&value));
        return llm::OS::Media::Import::PhotoImportSidecar{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Import::PhotoImportSidecar>) consume_Windows_Media_Import_IPhotoImportItem<D>::Sidecars() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportItem)->get_Sidecars(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Import::PhotoImportSidecar>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Import::PhotoImportVideoSegment>) consume_Windows_Media_Import_IPhotoImportItem<D>::VideoSegments() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportItem)->get_VideoSegments(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Import::PhotoImportVideoSegment>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Import_IPhotoImportItem<D>::IsSelected() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportItem)->get_IsSelected(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Import_IPhotoImportItem<D>::IsSelected(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportItem)->put_IsSelected(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStreamReference) consume_Windows_Media_Import_IPhotoImportItem<D>::Thumbnail() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportItem)->get_Thumbnail(&value));
        return llm::OS::Storage::Streams::IRandomAccessStreamReference{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_Media_Import_IPhotoImportItem<D>::ImportedFileNames() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportItem)->get_ImportedFileNames(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_Media_Import_IPhotoImportItem<D>::DeletedFileNames() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportItem)->get_DeletedFileNames(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Import_IPhotoImportItem2<D>::Path() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportItem2)->get_Path(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Import::PhotoImportItem) consume_Windows_Media_Import_IPhotoImportItemImportedEventArgs<D>::ImportedItem() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportItemImportedEventArgs)->get_ImportedItem(&value));
        return llm::OS::Media::Import::PhotoImportItem{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Media_Import_IPhotoImportManagerStatics<D>::IsSupportedAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportManagerStatics)->IsSupportedAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Import::PhotoImportSource>>) consume_Windows_Media_Import_IPhotoImportManagerStatics<D>::FindAllSourcesAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportManagerStatics)->FindAllSourcesAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Import::PhotoImportSource>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Import::PhotoImportOperation>) consume_Windows_Media_Import_IPhotoImportManagerStatics<D>::GetPendingOperations() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportManagerStatics)->GetPendingOperations(&result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Import::PhotoImportOperation>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Import::PhotoImportStage) consume_Windows_Media_Import_IPhotoImportOperation<D>::Stage() const
    {
        llm::OS::Media::Import::PhotoImportStage value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportOperation)->get_Stage(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Import::PhotoImportSession) consume_Windows_Media_Import_IPhotoImportOperation<D>::Session() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportOperation)->get_Session(&value));
        return llm::OS::Media::Import::PhotoImportSession{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Media::Import::PhotoImportFindItemsResult, uint32_t>) consume_Windows_Media_Import_IPhotoImportOperation<D>::ContinueFindingItemsAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportOperation)->get_ContinueFindingItemsAsync(&operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Media::Import::PhotoImportFindItemsResult, uint32_t>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Media::Import::PhotoImportImportItemsResult, llm::OS::Media::Import::PhotoImportProgress>) consume_Windows_Media_Import_IPhotoImportOperation<D>::ContinueImportingItemsAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportOperation)->get_ContinueImportingItemsAsync(&operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Media::Import::PhotoImportImportItemsResult, llm::OS::Media::Import::PhotoImportProgress>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Media::Import::PhotoImportDeleteImportedItemsFromSourceResult, double>) consume_Windows_Media_Import_IPhotoImportOperation<D>::ContinueDeletingImportedItemsFromSourceAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportOperation)->get_ContinueDeletingImportedItemsFromSourceAsync(&operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Media::Import::PhotoImportDeleteImportedItemsFromSourceResult, double>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Import_IPhotoImportSelectionChangedEventArgs<D>::IsSelectionEmpty() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSelectionChangedEventArgs)->get_IsSelectionEmpty(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Import::PhotoImportSource) consume_Windows_Media_Import_IPhotoImportSession<D>::Source() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSession)->get_Source(&value));
        return llm::OS::Media::Import::PhotoImportSource{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Media_Import_IPhotoImportSession<D>::SessionId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSession)->get_SessionId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Import_IPhotoImportSession<D>::DestinationFolder(llm::OS::Storage::IStorageFolder const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSession)->put_DestinationFolder(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::IStorageFolder) consume_Windows_Media_Import_IPhotoImportSession<D>::DestinationFolder() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSession)->get_DestinationFolder(&value));
        return llm::OS::Storage::IStorageFolder{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Import_IPhotoImportSession<D>::AppendSessionDateToDestinationFolder(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSession)->put_AppendSessionDateToDestinationFolder(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Import_IPhotoImportSession<D>::AppendSessionDateToDestinationFolder() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSession)->get_AppendSessionDateToDestinationFolder(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Import_IPhotoImportSession<D>::SubfolderCreationMode(llm::OS::Media::Import::PhotoImportSubfolderCreationMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSession)->put_SubfolderCreationMode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Import::PhotoImportSubfolderCreationMode) consume_Windows_Media_Import_IPhotoImportSession<D>::SubfolderCreationMode() const
    {
        llm::OS::Media::Import::PhotoImportSubfolderCreationMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSession)->get_SubfolderCreationMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Import_IPhotoImportSession<D>::DestinationFileNamePrefix(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSession)->put_DestinationFileNamePrefix(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Import_IPhotoImportSession<D>::DestinationFileNamePrefix() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSession)->get_DestinationFileNamePrefix(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Media::Import::PhotoImportFindItemsResult, uint32_t>) consume_Windows_Media_Import_IPhotoImportSession<D>::FindItemsAsync(llm::OS::Media::Import::PhotoImportContentTypeFilter const& contentTypeFilter, llm::OS::Media::Import::PhotoImportItemSelectionMode const& itemSelectionMode) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSession)->FindItemsAsync(static_cast<int32_t>(contentTypeFilter), static_cast<int32_t>(itemSelectionMode), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Media::Import::PhotoImportFindItemsResult, uint32_t>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Import_IPhotoImportSession2<D>::SubfolderDateFormat(llm::OS::Media::Import::PhotoImportSubfolderDateFormat const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSession2)->put_SubfolderDateFormat(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Import::PhotoImportSubfolderDateFormat) consume_Windows_Media_Import_IPhotoImportSession2<D>::SubfolderDateFormat() const
    {
        llm::OS::Media::Import::PhotoImportSubfolderDateFormat value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSession2)->get_SubfolderDateFormat(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Import_IPhotoImportSession2<D>::RememberDeselectedItems(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSession2)->put_RememberDeselectedItems(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Import_IPhotoImportSession2<D>::RememberDeselectedItems() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSession2)->get_RememberDeselectedItems(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Import_IPhotoImportSidecar<D>::Name() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSidecar)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Media_Import_IPhotoImportSidecar<D>::SizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSidecar)->get_SizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Media_Import_IPhotoImportSidecar<D>::Date() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSidecar)->get_Date(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Import_IPhotoImportSource<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSource)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Import_IPhotoImportSource<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSource)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Import_IPhotoImportSource<D>::Description() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSource)->get_Description(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Import_IPhotoImportSource<D>::Manufacturer() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSource)->get_Manufacturer(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Import_IPhotoImportSource<D>::Model() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSource)->get_Model(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Import_IPhotoImportSource<D>::SerialNumber() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSource)->get_SerialNumber(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Import_IPhotoImportSource<D>::ConnectionProtocol() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSource)->get_ConnectionProtocol(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Import::PhotoImportConnectionTransport) consume_Windows_Media_Import_IPhotoImportSource<D>::ConnectionTransport() const
    {
        llm::OS::Media::Import::PhotoImportConnectionTransport value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSource)->get_ConnectionTransport(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Import::PhotoImportSourceType) consume_Windows_Media_Import_IPhotoImportSource<D>::Type() const
    {
        llm::OS::Media::Import::PhotoImportSourceType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSource)->get_Type(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Import::PhotoImportPowerSource) consume_Windows_Media_Import_IPhotoImportSource<D>::PowerSource() const
    {
        llm::OS::Media::Import::PhotoImportPowerSource value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSource)->get_PowerSource(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<uint32_t>) consume_Windows_Media_Import_IPhotoImportSource<D>::BatteryLevelPercent() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSource)->get_BatteryLevelPercent(&value));
        return llm::OS::Foundation::IReference<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>) consume_Windows_Media_Import_IPhotoImportSource<D>::DateTime() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSource)->get_DateTime(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Import::PhotoImportStorageMedium>) consume_Windows_Media_Import_IPhotoImportSource<D>::StorageMedia() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSource)->get_StorageMedia(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Import::PhotoImportStorageMedium>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<bool>) consume_Windows_Media_Import_IPhotoImportSource<D>::IsLocked() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSource)->get_IsLocked(&value));
        return llm::OS::Foundation::IReference<bool>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Import_IPhotoImportSource<D>::IsMassStorage() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSource)->get_IsMassStorage(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStreamReference) consume_Windows_Media_Import_IPhotoImportSource<D>::Thumbnail() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSource)->get_Thumbnail(&value));
        return llm::OS::Storage::Streams::IRandomAccessStreamReference{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Import::PhotoImportSession) consume_Windows_Media_Import_IPhotoImportSource<D>::CreateImportSession() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSource)->CreateImportSession(&result));
        return llm::OS::Media::Import::PhotoImportSession{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Import::PhotoImportSource>) consume_Windows_Media_Import_IPhotoImportSourceStatics<D>::FromIdAsync(param::hstring const& sourceId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSourceStatics)->FromIdAsync(*(void**)(&sourceId), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Import::PhotoImportSource>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Import::PhotoImportSource>) consume_Windows_Media_Import_IPhotoImportSourceStatics<D>::FromFolderAsync(llm::OS::Storage::IStorageFolder const& sourceRootFolder) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportSourceStatics)->FromFolderAsync(*(void**)(&sourceRootFolder), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Import::PhotoImportSource>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Import_IPhotoImportStorageMedium<D>::Name() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportStorageMedium)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Import_IPhotoImportStorageMedium<D>::Description() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportStorageMedium)->get_Description(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Import_IPhotoImportStorageMedium<D>::SerialNumber() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportStorageMedium)->get_SerialNumber(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Import::PhotoImportStorageMediumType) consume_Windows_Media_Import_IPhotoImportStorageMedium<D>::StorageMediumType() const
    {
        llm::OS::Media::Import::PhotoImportStorageMediumType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportStorageMedium)->get_StorageMediumType(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Import::PhotoImportAccessMode) consume_Windows_Media_Import_IPhotoImportStorageMedium<D>::SupportedAccessMode() const
    {
        llm::OS::Media::Import::PhotoImportAccessMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportStorageMedium)->get_SupportedAccessMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Media_Import_IPhotoImportStorageMedium<D>::CapacityInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportStorageMedium)->get_CapacityInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Media_Import_IPhotoImportStorageMedium<D>::AvailableSpaceInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportStorageMedium)->get_AvailableSpaceInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Import_IPhotoImportStorageMedium<D>::Refresh() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportStorageMedium)->Refresh());
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Import_IPhotoImportVideoSegment<D>::Name() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportVideoSegment)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Media_Import_IPhotoImportVideoSegment<D>::SizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportVideoSegment)->get_SizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Media_Import_IPhotoImportVideoSegment<D>::Date() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportVideoSegment)->get_Date(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Import::PhotoImportSidecar) consume_Windows_Media_Import_IPhotoImportVideoSegment<D>::Sibling() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportVideoSegment)->get_Sibling(&value));
        return llm::OS::Media::Import::PhotoImportSidecar{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Import::PhotoImportSidecar>) consume_Windows_Media_Import_IPhotoImportVideoSegment<D>::Sidecars() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Import::IPhotoImportVideoSegment)->get_Sidecars(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Import::PhotoImportSidecar>{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult> : produce_base<D, llm::OS::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult>
    {
        int32_t __stdcall get_Session(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Import::PhotoImportSession>(this->shim().Session());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HasSucceeded(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().HasSucceeded());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeletedItems(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Import::PhotoImportItem>>(this->shim().DeletedItems());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PhotosCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().PhotosCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PhotosSizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().PhotosSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VideosCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().VideosCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VideosSizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().VideosSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SidecarsCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().SidecarsCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SidecarsSizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().SidecarsSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SiblingsCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().SiblingsCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SiblingsSizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().SiblingsSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TotalCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().TotalCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TotalSizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().TotalSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Import::IPhotoImportFindItemsResult> : produce_base<D, llm::OS::Media::Import::IPhotoImportFindItemsResult>
    {
        int32_t __stdcall get_Session(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Import::PhotoImportSession>(this->shim().Session());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HasSucceeded(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().HasSucceeded());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FoundItems(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Import::PhotoImportItem>>(this->shim().FoundItems());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PhotosCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().PhotosCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PhotosSizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().PhotosSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VideosCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().VideosCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VideosSizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().VideosSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SidecarsCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().SidecarsCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SidecarsSizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().SidecarsSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SiblingsCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().SiblingsCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SiblingsSizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().SiblingsSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TotalCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().TotalCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TotalSizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().TotalSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SelectAll() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SelectAll();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SelectNone() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SelectNone();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SelectNewAsync(void** action) noexcept final try
        {
            clear_abi(action);
            typename D::abi_guard guard(this->shim());
            *action = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SelectNewAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetImportMode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetImportMode(*reinterpret_cast<llm::OS::Media::Import::PhotoImportImportMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ImportMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Import::PhotoImportImportMode>(this->shim().ImportMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SelectedPhotosCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().SelectedPhotosCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SelectedPhotosSizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().SelectedPhotosSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SelectedVideosCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().SelectedVideosCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SelectedVideosSizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().SelectedVideosSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SelectedSidecarsCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().SelectedSidecarsCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SelectedSidecarsSizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().SelectedSidecarsSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SelectedSiblingsCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().SelectedSiblingsCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SelectedSiblingsSizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().SelectedSiblingsSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SelectedTotalCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().SelectedTotalCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SelectedTotalSizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().SelectedTotalSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_SelectionChanged(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().SelectionChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Import::PhotoImportFindItemsResult, llm::OS::Media::Import::PhotoImportSelectionChangedEventArgs> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_SelectionChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SelectionChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall ImportItemsAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Media::Import::PhotoImportImportItemsResult, llm::OS::Media::Import::PhotoImportProgress>>(this->shim().ImportItemsAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_ItemImported(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ItemImported(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Import::PhotoImportFindItemsResult, llm::OS::Media::Import::PhotoImportItemImportedEventArgs> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ItemImported(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ItemImported(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Import::IPhotoImportFindItemsResult2> : produce_base<D, llm::OS::Media::Import::IPhotoImportFindItemsResult2>
    {
        int32_t __stdcall AddItemsInDateRangeToSelection(int64_t rangeStart, int64_t rangeLength) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddItemsInDateRangeToSelection(*reinterpret_cast<llm::OS::Foundation::DateTime const*>(&rangeStart), *reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&rangeLength));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Import::IPhotoImportImportItemsResult> : produce_base<D, llm::OS::Media::Import::IPhotoImportImportItemsResult>
    {
        int32_t __stdcall get_Session(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Import::PhotoImportSession>(this->shim().Session());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HasSucceeded(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().HasSucceeded());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ImportedItems(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Import::PhotoImportItem>>(this->shim().ImportedItems());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PhotosCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().PhotosCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PhotosSizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().PhotosSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VideosCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().VideosCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VideosSizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().VideosSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SidecarsCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().SidecarsCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SidecarsSizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().SidecarsSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SiblingsCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().SiblingsCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SiblingsSizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().SiblingsSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TotalCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().TotalCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TotalSizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().TotalSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DeleteImportedItemsFromSourceAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Media::Import::PhotoImportDeleteImportedItemsFromSourceResult, double>>(this->shim().DeleteImportedItemsFromSourceAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Import::IPhotoImportItem> : produce_base<D, llm::OS::Media::Import::IPhotoImportItem>
    {
        int32_t __stdcall get_Name(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Name());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ItemKey(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().ItemKey());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ContentType(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Import::PhotoImportContentType>(this->shim().ContentType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().SizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Date(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().Date());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Sibling(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Import::PhotoImportSidecar>(this->shim().Sibling());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Sidecars(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Import::PhotoImportSidecar>>(this->shim().Sidecars());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VideoSegments(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Import::PhotoImportVideoSegment>>(this->shim().VideoSegments());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsSelected(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsSelected());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsSelected(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsSelected(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Thumbnail(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IRandomAccessStreamReference>(this->shim().Thumbnail());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ImportedFileNames(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().ImportedFileNames());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeletedFileNames(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().DeletedFileNames());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Import::IPhotoImportItem2> : produce_base<D, llm::OS::Media::Import::IPhotoImportItem2>
    {
        int32_t __stdcall get_Path(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Path());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Import::IPhotoImportItemImportedEventArgs> : produce_base<D, llm::OS::Media::Import::IPhotoImportItemImportedEventArgs>
    {
        int32_t __stdcall get_ImportedItem(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Import::PhotoImportItem>(this->shim().ImportedItem());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Import::IPhotoImportManagerStatics> : produce_base<D, llm::OS::Media::Import::IPhotoImportManagerStatics>
    {
        int32_t __stdcall IsSupportedAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().IsSupportedAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindAllSourcesAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Import::PhotoImportSource>>>(this->shim().FindAllSourcesAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetPendingOperations(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Import::PhotoImportOperation>>(this->shim().GetPendingOperations());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Import::IPhotoImportOperation> : produce_base<D, llm::OS::Media::Import::IPhotoImportOperation>
    {
        int32_t __stdcall get_Stage(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Import::PhotoImportStage>(this->shim().Stage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Session(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Import::PhotoImportSession>(this->shim().Session());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ContinueFindingItemsAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Media::Import::PhotoImportFindItemsResult, uint32_t>>(this->shim().ContinueFindingItemsAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ContinueImportingItemsAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Media::Import::PhotoImportImportItemsResult, llm::OS::Media::Import::PhotoImportProgress>>(this->shim().ContinueImportingItemsAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ContinueDeletingImportedItemsFromSourceAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Media::Import::PhotoImportDeleteImportedItemsFromSourceResult, double>>(this->shim().ContinueDeletingImportedItemsFromSourceAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Import::IPhotoImportSelectionChangedEventArgs> : produce_base<D, llm::OS::Media::Import::IPhotoImportSelectionChangedEventArgs>
    {
        int32_t __stdcall get_IsSelectionEmpty(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsSelectionEmpty());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Import::IPhotoImportSession> : produce_base<D, llm::OS::Media::Import::IPhotoImportSession>
    {
        int32_t __stdcall get_Source(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Import::PhotoImportSource>(this->shim().Source());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SessionId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().SessionId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DestinationFolder(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DestinationFolder(*reinterpret_cast<llm::OS::Storage::IStorageFolder const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DestinationFolder(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::IStorageFolder>(this->shim().DestinationFolder());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AppendSessionDateToDestinationFolder(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppendSessionDateToDestinationFolder(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AppendSessionDateToDestinationFolder(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().AppendSessionDateToDestinationFolder());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SubfolderCreationMode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SubfolderCreationMode(*reinterpret_cast<llm::OS::Media::Import::PhotoImportSubfolderCreationMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SubfolderCreationMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Import::PhotoImportSubfolderCreationMode>(this->shim().SubfolderCreationMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DestinationFileNamePrefix(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DestinationFileNamePrefix(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DestinationFileNamePrefix(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DestinationFileNamePrefix());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindItemsAsync(int32_t contentTypeFilter, int32_t itemSelectionMode, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Media::Import::PhotoImportFindItemsResult, uint32_t>>(this->shim().FindItemsAsync(*reinterpret_cast<llm::OS::Media::Import::PhotoImportContentTypeFilter const*>(&contentTypeFilter), *reinterpret_cast<llm::OS::Media::Import::PhotoImportItemSelectionMode const*>(&itemSelectionMode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Import::IPhotoImportSession2> : produce_base<D, llm::OS::Media::Import::IPhotoImportSession2>
    {
        int32_t __stdcall put_SubfolderDateFormat(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SubfolderDateFormat(*reinterpret_cast<llm::OS::Media::Import::PhotoImportSubfolderDateFormat const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SubfolderDateFormat(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Import::PhotoImportSubfolderDateFormat>(this->shim().SubfolderDateFormat());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RememberDeselectedItems(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RememberDeselectedItems(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RememberDeselectedItems(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().RememberDeselectedItems());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Import::IPhotoImportSidecar> : produce_base<D, llm::OS::Media::Import::IPhotoImportSidecar>
    {
        int32_t __stdcall get_Name(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Name());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().SizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Date(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().Date());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Import::IPhotoImportSource> : produce_base<D, llm::OS::Media::Import::IPhotoImportSource>
    {
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
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
        int32_t __stdcall get_Description(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Manufacturer(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Manufacturer());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Model(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Model());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SerialNumber(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SerialNumber());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ConnectionProtocol(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ConnectionProtocol());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ConnectionTransport(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Import::PhotoImportConnectionTransport>(this->shim().ConnectionTransport());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Type(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Import::PhotoImportSourceType>(this->shim().Type());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PowerSource(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Import::PhotoImportPowerSource>(this->shim().PowerSource());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BatteryLevelPercent(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<uint32_t>>(this->shim().BatteryLevelPercent());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DateTime(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>>(this->shim().DateTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StorageMedia(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Import::PhotoImportStorageMedium>>(this->shim().StorageMedia());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsLocked(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<bool>>(this->shim().IsLocked());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsMassStorage(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsMassStorage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Thumbnail(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IRandomAccessStreamReference>(this->shim().Thumbnail());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateImportSession(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Media::Import::PhotoImportSession>(this->shim().CreateImportSession());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Import::IPhotoImportSourceStatics> : produce_base<D, llm::OS::Media::Import::IPhotoImportSourceStatics>
    {
        int32_t __stdcall FromIdAsync(void* sourceId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Import::PhotoImportSource>>(this->shim().FromIdAsync(*reinterpret_cast<hstring const*>(&sourceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FromFolderAsync(void* sourceRootFolder, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Import::PhotoImportSource>>(this->shim().FromFolderAsync(*reinterpret_cast<llm::OS::Storage::IStorageFolder const*>(&sourceRootFolder)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Import::IPhotoImportStorageMedium> : produce_base<D, llm::OS::Media::Import::IPhotoImportStorageMedium>
    {
        int32_t __stdcall get_Name(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Name());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Description(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SerialNumber(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SerialNumber());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StorageMediumType(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Import::PhotoImportStorageMediumType>(this->shim().StorageMediumType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportedAccessMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Import::PhotoImportAccessMode>(this->shim().SupportedAccessMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CapacityInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().CapacityInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AvailableSpaceInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().AvailableSpaceInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Refresh() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Refresh();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Import::IPhotoImportVideoSegment> : produce_base<D, llm::OS::Media::Import::IPhotoImportVideoSegment>
    {
        int32_t __stdcall get_Name(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Name());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().SizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Date(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().Date());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Sibling(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Import::PhotoImportSidecar>(this->shim().Sibling());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Sidecars(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Import::PhotoImportSidecar>>(this->shim().Sidecars());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Media::Import
{
    inline auto PhotoImportManager::IsSupportedAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<bool>(*)(IPhotoImportManagerStatics const&), PhotoImportManager, IPhotoImportManagerStatics>([](IPhotoImportManagerStatics const& f) { return f.IsSupportedAsync(); });
    }
    inline auto PhotoImportManager::FindAllSourcesAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Import::PhotoImportSource>>(*)(IPhotoImportManagerStatics const&), PhotoImportManager, IPhotoImportManagerStatics>([](IPhotoImportManagerStatics const& f) { return f.FindAllSourcesAsync(); });
    }
    inline auto PhotoImportManager::GetPendingOperations()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Import::PhotoImportOperation>(*)(IPhotoImportManagerStatics const&), PhotoImportManager, IPhotoImportManagerStatics>([](IPhotoImportManagerStatics const& f) { return f.GetPendingOperations(); });
    }
    inline auto PhotoImportSource::FromIdAsync(param::hstring const& sourceId)
    {
        return impl::call_factory<PhotoImportSource, IPhotoImportSourceStatics>([&](IPhotoImportSourceStatics const& f) { return f.FromIdAsync(sourceId); });
    }
    inline auto PhotoImportSource::FromFolderAsync(llm::OS::Storage::IStorageFolder const& sourceRootFolder)
    {
        return impl::call_factory<PhotoImportSource, IPhotoImportSourceStatics>([&](IPhotoImportSourceStatics const& f) { return f.FromFolderAsync(sourceRootFolder); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Import::IPhotoImportFindItemsResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Import::IPhotoImportFindItemsResult2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Import::IPhotoImportImportItemsResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Import::IPhotoImportItem> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Import::IPhotoImportItem2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Import::IPhotoImportItemImportedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Import::IPhotoImportManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Import::IPhotoImportOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Import::IPhotoImportSelectionChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Import::IPhotoImportSession> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Import::IPhotoImportSession2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Import::IPhotoImportSidecar> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Import::IPhotoImportSource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Import::IPhotoImportSourceStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Import::IPhotoImportStorageMedium> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Import::IPhotoImportVideoSegment> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Import::PhotoImportDeleteImportedItemsFromSourceResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Import::PhotoImportFindItemsResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Import::PhotoImportImportItemsResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Import::PhotoImportItem> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Import::PhotoImportItemImportedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Import::PhotoImportManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Import::PhotoImportOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Import::PhotoImportSelectionChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Import::PhotoImportSession> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Import::PhotoImportSidecar> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Import::PhotoImportSource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Import::PhotoImportStorageMedium> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Import::PhotoImportVideoSegment> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
