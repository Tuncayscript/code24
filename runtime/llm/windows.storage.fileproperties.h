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
#ifndef LLM_OS_Storage_FileProperties_H
#define LLM_OS_Storage_FileProperties_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Storage.h"
#include "llm/impl/Windows.Devices.Geolocation.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Storage.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.Storage.FileProperties.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Storage_FileProperties_IBasicProperties<D>::Size() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IBasicProperties)->get_Size(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Storage_FileProperties_IBasicProperties<D>::DateModified() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IBasicProperties)->get_DateModified(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Storage_FileProperties_IBasicProperties<D>::ItemDate() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IBasicProperties)->get_ItemDate(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Storage_FileProperties_IDocumentProperties<D>::Author() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IDocumentProperties)->get_Author(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_FileProperties_IDocumentProperties<D>::Title() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IDocumentProperties)->get_Title(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_FileProperties_IDocumentProperties<D>::Title(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IDocumentProperties)->put_Title(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Storage_FileProperties_IDocumentProperties<D>::Keywords() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IDocumentProperties)->get_Keywords(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_FileProperties_IDocumentProperties<D>::Comment() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IDocumentProperties)->get_Comment(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_FileProperties_IDocumentProperties<D>::Comment(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IDocumentProperties)->put_Comment(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Geolocation::Geopoint>) consume_Windows_Storage_FileProperties_IGeotagHelperStatics<D>::GetGeotagAsync(llm::OS::Storage::IStorageFile const& file) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IGeotagHelperStatics)->GetGeotagAsync(*(void**)(&file), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Geolocation::Geopoint>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Storage_FileProperties_IGeotagHelperStatics<D>::SetGeotagFromGeolocatorAsync(llm::OS::Storage::IStorageFile const& file, llm::OS::Devices::Geolocation::Geolocator const& geolocator) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IGeotagHelperStatics)->SetGeotagFromGeolocatorAsync(*(void**)(&file), *(void**)(&geolocator), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Storage_FileProperties_IGeotagHelperStatics<D>::SetGeotagAsync(llm::OS::Storage::IStorageFile const& file, llm::OS::Devices::Geolocation::Geopoint const& geopoint) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IGeotagHelperStatics)->SetGeotagAsync(*(void**)(&file), *(void**)(&geopoint), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Storage_FileProperties_IImageProperties<D>::Rating() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IImageProperties)->get_Rating(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_FileProperties_IImageProperties<D>::Rating(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IImageProperties)->put_Rating(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Storage_FileProperties_IImageProperties<D>::Keywords() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IImageProperties)->get_Keywords(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Storage_FileProperties_IImageProperties<D>::DateTaken() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IImageProperties)->get_DateTaken(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_FileProperties_IImageProperties<D>::DateTaken(llm::OS::Foundation::DateTime const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IImageProperties)->put_DateTaken(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Storage_FileProperties_IImageProperties<D>::Width() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IImageProperties)->get_Width(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Storage_FileProperties_IImageProperties<D>::Height() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IImageProperties)->get_Height(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_FileProperties_IImageProperties<D>::Title() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IImageProperties)->get_Title(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_FileProperties_IImageProperties<D>::Title(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IImageProperties)->put_Title(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Storage_FileProperties_IImageProperties<D>::Latitude() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IImageProperties)->get_Latitude(&value));
        return llm::OS::Foundation::IReference<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Storage_FileProperties_IImageProperties<D>::Longitude() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IImageProperties)->get_Longitude(&value));
        return llm::OS::Foundation::IReference<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_FileProperties_IImageProperties<D>::CameraManufacturer() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IImageProperties)->get_CameraManufacturer(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_FileProperties_IImageProperties<D>::CameraManufacturer(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IImageProperties)->put_CameraManufacturer(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_FileProperties_IImageProperties<D>::CameraModel() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IImageProperties)->get_CameraModel(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_FileProperties_IImageProperties<D>::CameraModel(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IImageProperties)->put_CameraModel(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::FileProperties::PhotoOrientation) consume_Windows_Storage_FileProperties_IImageProperties<D>::Orientation() const
    {
        llm::OS::Storage::FileProperties::PhotoOrientation value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IImageProperties)->get_Orientation(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_Storage_FileProperties_IImageProperties<D>::PeopleNames() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IImageProperties)->get_PeopleNames(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_FileProperties_IMusicProperties<D>::Album() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IMusicProperties)->get_Album(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_FileProperties_IMusicProperties<D>::Album(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IMusicProperties)->put_Album(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_FileProperties_IMusicProperties<D>::Artist() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IMusicProperties)->get_Artist(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_FileProperties_IMusicProperties<D>::Artist(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IMusicProperties)->put_Artist(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Storage_FileProperties_IMusicProperties<D>::Genre() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IMusicProperties)->get_Genre(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Storage_FileProperties_IMusicProperties<D>::TrackNumber() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IMusicProperties)->get_TrackNumber(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_FileProperties_IMusicProperties<D>::TrackNumber(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IMusicProperties)->put_TrackNumber(value));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_FileProperties_IMusicProperties<D>::Title() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IMusicProperties)->get_Title(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_FileProperties_IMusicProperties<D>::Title(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IMusicProperties)->put_Title(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Storage_FileProperties_IMusicProperties<D>::Rating() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IMusicProperties)->get_Rating(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_FileProperties_IMusicProperties<D>::Rating(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IMusicProperties)->put_Rating(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Storage_FileProperties_IMusicProperties<D>::Duration() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IMusicProperties)->get_Duration(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Storage_FileProperties_IMusicProperties<D>::Bitrate() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IMusicProperties)->get_Bitrate(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_FileProperties_IMusicProperties<D>::AlbumArtist() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IMusicProperties)->get_AlbumArtist(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_FileProperties_IMusicProperties<D>::AlbumArtist(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IMusicProperties)->put_AlbumArtist(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Storage_FileProperties_IMusicProperties<D>::Composers() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IMusicProperties)->get_Composers(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Storage_FileProperties_IMusicProperties<D>::Conductors() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IMusicProperties)->get_Conductors(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_FileProperties_IMusicProperties<D>::Subtitle() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IMusicProperties)->get_Subtitle(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_FileProperties_IMusicProperties<D>::Subtitle(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IMusicProperties)->put_Subtitle(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Storage_FileProperties_IMusicProperties<D>::Producers() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IMusicProperties)->get_Producers(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_FileProperties_IMusicProperties<D>::Publisher() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IMusicProperties)->get_Publisher(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_FileProperties_IMusicProperties<D>::Publisher(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IMusicProperties)->put_Publisher(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Storage_FileProperties_IMusicProperties<D>::Writers() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IMusicProperties)->get_Writers(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Storage_FileProperties_IMusicProperties<D>::Year() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IMusicProperties)->get_Year(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_FileProperties_IMusicProperties<D>::Year(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IMusicProperties)->put_Year(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::FileProperties::MusicProperties>) consume_Windows_Storage_FileProperties_IStorageItemContentProperties<D>::GetMusicPropertiesAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IStorageItemContentProperties)->GetMusicPropertiesAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::FileProperties::MusicProperties>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::FileProperties::VideoProperties>) consume_Windows_Storage_FileProperties_IStorageItemContentProperties<D>::GetVideoPropertiesAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IStorageItemContentProperties)->GetVideoPropertiesAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::FileProperties::VideoProperties>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::FileProperties::ImageProperties>) consume_Windows_Storage_FileProperties_IStorageItemContentProperties<D>::GetImagePropertiesAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IStorageItemContentProperties)->GetImagePropertiesAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::FileProperties::ImageProperties>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::FileProperties::DocumentProperties>) consume_Windows_Storage_FileProperties_IStorageItemContentProperties<D>::GetDocumentPropertiesAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IStorageItemContentProperties)->GetDocumentPropertiesAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::FileProperties::DocumentProperties>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IMap<hstring, llm::OS::Foundation::IInspectable>>) consume_Windows_Storage_FileProperties_IStorageItemExtraProperties<D>::RetrievePropertiesAsync(param::async_iterable<hstring> const& propertiesToRetrieve) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IStorageItemExtraProperties)->RetrievePropertiesAsync(*(void**)(&propertiesToRetrieve), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IMap<hstring, llm::OS::Foundation::IInspectable>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Storage_FileProperties_IStorageItemExtraProperties<D>::SavePropertiesAsync(param::async_iterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, llm::OS::Foundation::IInspectable>> const& propertiesToSave) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IStorageItemExtraProperties)->SavePropertiesAsync(*(void**)(&propertiesToSave), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Storage_FileProperties_IStorageItemExtraProperties<D>::SavePropertiesAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IStorageItemExtraProperties)->SavePropertiesAsyncOverloadDefault(&operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Storage_FileProperties_IThumbnailProperties<D>::OriginalWidth() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IThumbnailProperties)->get_OriginalWidth(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Storage_FileProperties_IThumbnailProperties<D>::OriginalHeight() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IThumbnailProperties)->get_OriginalHeight(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Storage_FileProperties_IThumbnailProperties<D>::ReturnedSmallerCachedSize() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IThumbnailProperties)->get_ReturnedSmallerCachedSize(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::FileProperties::ThumbnailType) consume_Windows_Storage_FileProperties_IThumbnailProperties<D>::Type() const
    {
        llm::OS::Storage::FileProperties::ThumbnailType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IThumbnailProperties)->get_Type(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Storage_FileProperties_IVideoProperties<D>::Rating() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IVideoProperties)->get_Rating(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_FileProperties_IVideoProperties<D>::Rating(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IVideoProperties)->put_Rating(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Storage_FileProperties_IVideoProperties<D>::Keywords() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IVideoProperties)->get_Keywords(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Storage_FileProperties_IVideoProperties<D>::Width() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IVideoProperties)->get_Width(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Storage_FileProperties_IVideoProperties<D>::Height() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IVideoProperties)->get_Height(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Storage_FileProperties_IVideoProperties<D>::Duration() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IVideoProperties)->get_Duration(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Storage_FileProperties_IVideoProperties<D>::Latitude() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IVideoProperties)->get_Latitude(&value));
        return llm::OS::Foundation::IReference<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Storage_FileProperties_IVideoProperties<D>::Longitude() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IVideoProperties)->get_Longitude(&value));
        return llm::OS::Foundation::IReference<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_FileProperties_IVideoProperties<D>::Title() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IVideoProperties)->get_Title(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_FileProperties_IVideoProperties<D>::Title(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IVideoProperties)->put_Title(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_FileProperties_IVideoProperties<D>::Subtitle() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IVideoProperties)->get_Subtitle(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_FileProperties_IVideoProperties<D>::Subtitle(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IVideoProperties)->put_Subtitle(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Storage_FileProperties_IVideoProperties<D>::Producers() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IVideoProperties)->get_Producers(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_FileProperties_IVideoProperties<D>::Publisher() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IVideoProperties)->get_Publisher(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_FileProperties_IVideoProperties<D>::Publisher(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IVideoProperties)->put_Publisher(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Storage_FileProperties_IVideoProperties<D>::Writers() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IVideoProperties)->get_Writers(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Storage_FileProperties_IVideoProperties<D>::Year() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IVideoProperties)->get_Year(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_FileProperties_IVideoProperties<D>::Year(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IVideoProperties)->put_Year(value));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Storage_FileProperties_IVideoProperties<D>::Bitrate() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IVideoProperties)->get_Bitrate(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Storage_FileProperties_IVideoProperties<D>::Directors() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IVideoProperties)->get_Directors(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::FileProperties::VideoOrientation) consume_Windows_Storage_FileProperties_IVideoProperties<D>::Orientation() const
    {
        llm::OS::Storage::FileProperties::VideoOrientation value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::FileProperties::IVideoProperties)->get_Orientation(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::FileProperties::IBasicProperties> : produce_base<D, llm::OS::Storage::FileProperties::IBasicProperties>
    {
        int32_t __stdcall get_Size(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().Size());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DateModified(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().DateModified());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ItemDate(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().ItemDate());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::FileProperties::IDocumentProperties> : produce_base<D, llm::OS::Storage::FileProperties::IDocumentProperties>
    {
        int32_t __stdcall get_Author(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().Author());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Title(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Title());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Title(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Title(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Keywords(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().Keywords());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Comment(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Comment());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Comment(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Comment(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::FileProperties::IGeotagHelperStatics> : produce_base<D, llm::OS::Storage::FileProperties::IGeotagHelperStatics>
    {
        int32_t __stdcall GetGeotagAsync(void* file, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Geolocation::Geopoint>>(this->shim().GetGeotagAsync(*reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&file)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetGeotagFromGeolocatorAsync(void* file, void* geolocator, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SetGeotagFromGeolocatorAsync(*reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&file), *reinterpret_cast<llm::OS::Devices::Geolocation::Geolocator const*>(&geolocator)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetGeotagAsync(void* file, void* geopoint, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SetGeotagAsync(*reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&file), *reinterpret_cast<llm::OS::Devices::Geolocation::Geopoint const*>(&geopoint)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::FileProperties::IImageProperties> : produce_base<D, llm::OS::Storage::FileProperties::IImageProperties>
    {
        int32_t __stdcall get_Rating(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Rating());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Rating(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Rating(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Keywords(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().Keywords());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DateTaken(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().DateTaken());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DateTaken(int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DateTaken(*reinterpret_cast<llm::OS::Foundation::DateTime const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Width(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Width());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Height(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Height());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Title(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Title());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Title(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Title(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Latitude(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().Latitude());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Longitude(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().Longitude());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CameraManufacturer(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().CameraManufacturer());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CameraManufacturer(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CameraManufacturer(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CameraModel(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().CameraModel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CameraModel(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CameraModel(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Orientation(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::FileProperties::PhotoOrientation>(this->shim().Orientation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PeopleNames(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().PeopleNames());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::FileProperties::IMusicProperties> : produce_base<D, llm::OS::Storage::FileProperties::IMusicProperties>
    {
        int32_t __stdcall get_Album(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Album());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Album(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Album(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Artist(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Artist());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Artist(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Artist(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Genre(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().Genre());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TrackNumber(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().TrackNumber());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TrackNumber(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TrackNumber(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Title(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Title());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Title(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Title(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Rating(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Rating());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Rating(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Rating(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Duration(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().Duration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Bitrate(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Bitrate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AlbumArtist(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AlbumArtist());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AlbumArtist(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AlbumArtist(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Composers(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().Composers());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Conductors(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().Conductors());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Subtitle(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Subtitle());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Subtitle(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Subtitle(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Producers(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().Producers());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Publisher(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Publisher());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Publisher(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Publisher(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Writers(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().Writers());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Year(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Year());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Year(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Year(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::FileProperties::IStorageItemContentProperties> : produce_base<D, llm::OS::Storage::FileProperties::IStorageItemContentProperties>
    {
        int32_t __stdcall GetMusicPropertiesAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::FileProperties::MusicProperties>>(this->shim().GetMusicPropertiesAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetVideoPropertiesAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::FileProperties::VideoProperties>>(this->shim().GetVideoPropertiesAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetImagePropertiesAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::FileProperties::ImageProperties>>(this->shim().GetImagePropertiesAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDocumentPropertiesAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::FileProperties::DocumentProperties>>(this->shim().GetDocumentPropertiesAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Storage::FileProperties::IStorageItemExtraProperties> : produce_base<D, llm::OS::Storage::FileProperties::IStorageItemExtraProperties>
    {
        int32_t __stdcall RetrievePropertiesAsync(void* propertiesToRetrieve, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IMap<hstring, llm::OS::Foundation::IInspectable>>>(this->shim().RetrievePropertiesAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&propertiesToRetrieve)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SavePropertiesAsync(void* propertiesToSave, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SavePropertiesAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, llm::OS::Foundation::IInspectable>> const*>(&propertiesToSave)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SavePropertiesAsyncOverloadDefault(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SavePropertiesAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::FileProperties::IThumbnailProperties> : produce_base<D, llm::OS::Storage::FileProperties::IThumbnailProperties>
    {
        int32_t __stdcall get_OriginalWidth(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().OriginalWidth());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OriginalHeight(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().OriginalHeight());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ReturnedSmallerCachedSize(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().ReturnedSmallerCachedSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Type(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::FileProperties::ThumbnailType>(this->shim().Type());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::FileProperties::IVideoProperties> : produce_base<D, llm::OS::Storage::FileProperties::IVideoProperties>
    {
        int32_t __stdcall get_Rating(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Rating());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Rating(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Rating(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Keywords(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().Keywords());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Width(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Width());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Height(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Height());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Duration(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().Duration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Latitude(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().Latitude());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Longitude(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().Longitude());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Title(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Title());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Title(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Title(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Subtitle(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Subtitle());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Subtitle(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Subtitle(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Producers(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().Producers());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Publisher(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Publisher());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Publisher(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Publisher(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Writers(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().Writers());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Year(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Year());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Year(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Year(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Bitrate(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Bitrate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Directors(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().Directors());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Orientation(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::FileProperties::VideoOrientation>(this->shim().Orientation());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Storage::FileProperties
{
    constexpr auto operator|(PropertyPrefetchOptions const left, PropertyPrefetchOptions const right) noexcept
    {
        return static_cast<PropertyPrefetchOptions>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(PropertyPrefetchOptions& left, PropertyPrefetchOptions const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(PropertyPrefetchOptions const left, PropertyPrefetchOptions const right) noexcept
    {
        return static_cast<PropertyPrefetchOptions>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(PropertyPrefetchOptions& left, PropertyPrefetchOptions const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(PropertyPrefetchOptions const value) noexcept
    {
        return static_cast<PropertyPrefetchOptions>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(PropertyPrefetchOptions const left, PropertyPrefetchOptions const right) noexcept
    {
        return static_cast<PropertyPrefetchOptions>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(PropertyPrefetchOptions& left, PropertyPrefetchOptions const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    constexpr auto operator|(ThumbnailOptions const left, ThumbnailOptions const right) noexcept
    {
        return static_cast<ThumbnailOptions>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(ThumbnailOptions& left, ThumbnailOptions const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(ThumbnailOptions const left, ThumbnailOptions const right) noexcept
    {
        return static_cast<ThumbnailOptions>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(ThumbnailOptions& left, ThumbnailOptions const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(ThumbnailOptions const value) noexcept
    {
        return static_cast<ThumbnailOptions>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(ThumbnailOptions const left, ThumbnailOptions const right) noexcept
    {
        return static_cast<ThumbnailOptions>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(ThumbnailOptions& left, ThumbnailOptions const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    inline auto GeotagHelper::GetGeotagAsync(llm::OS::Storage::IStorageFile const& file)
    {
        return impl::call_factory<GeotagHelper, IGeotagHelperStatics>([&](IGeotagHelperStatics const& f) { return f.GetGeotagAsync(file); });
    }
    inline auto GeotagHelper::SetGeotagFromGeolocatorAsync(llm::OS::Storage::IStorageFile const& file, llm::OS::Devices::Geolocation::Geolocator const& geolocator)
    {
        return impl::call_factory<GeotagHelper, IGeotagHelperStatics>([&](IGeotagHelperStatics const& f) { return f.SetGeotagFromGeolocatorAsync(file, geolocator); });
    }
    inline auto GeotagHelper::SetGeotagAsync(llm::OS::Storage::IStorageFile const& file, llm::OS::Devices::Geolocation::Geopoint const& geopoint)
    {
        return impl::call_factory<GeotagHelper, IGeotagHelperStatics>([&](IGeotagHelperStatics const& f) { return f.SetGeotagAsync(file, geopoint); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Storage::FileProperties::IBasicProperties> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::FileProperties::IDocumentProperties> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::FileProperties::IGeotagHelperStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::FileProperties::IImageProperties> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::FileProperties::IMusicProperties> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::FileProperties::IStorageItemContentProperties> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::FileProperties::IStorageItemExtraProperties> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::FileProperties::IThumbnailProperties> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::FileProperties::IVideoProperties> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::FileProperties::BasicProperties> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::FileProperties::DocumentProperties> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::FileProperties::GeotagHelper> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::FileProperties::ImageProperties> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::FileProperties::MusicProperties> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::FileProperties::StorageItemContentProperties> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::FileProperties::StorageItemThumbnail> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::FileProperties::VideoProperties> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
