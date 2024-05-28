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
#ifndef LLM_OS_ApplicationModel_SocialInfo_H
#define LLM_OS_ApplicationModel_SocialInfo_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.ApplicationModel.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Graphics.Imaging.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.ApplicationModel.SocialInfo.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::SocialInfo::SocialUserInfo) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedChildItem<D>::Author() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedChildItem)->get_Author(&value));
        return llm::OS::ApplicationModel::SocialInfo::SocialUserInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::SocialInfo::SocialFeedContent) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedChildItem<D>::PrimaryContent() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedChildItem)->get_PrimaryContent(&value));
        return llm::OS::ApplicationModel::SocialInfo::SocialFeedContent{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::SocialInfo::SocialFeedContent) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedChildItem<D>::SecondaryContent() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedChildItem)->get_SecondaryContent(&value));
        return llm::OS::ApplicationModel::SocialInfo::SocialFeedContent{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedChildItem<D>::Timestamp() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedChildItem)->get_Timestamp(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedChildItem<D>::Timestamp(llm::OS::Foundation::DateTime const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedChildItem)->put_Timestamp(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedChildItem<D>::TargetUri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedChildItem)->get_TargetUri(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedChildItem<D>::TargetUri(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedChildItem)->put_TargetUri(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::SocialInfo::SocialItemThumbnail>) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedChildItem<D>::Thumbnails() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedChildItem)->get_Thumbnails(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::SocialInfo::SocialItemThumbnail>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::SocialInfo::SocialFeedSharedItem) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedChildItem<D>::SharedItem() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedChildItem)->get_SharedItem(&value));
        return llm::OS::ApplicationModel::SocialInfo::SocialFeedSharedItem{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedChildItem<D>::SharedItem(llm::OS::ApplicationModel::SocialInfo::SocialFeedSharedItem const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedChildItem)->put_SharedItem(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedContent<D>::Title() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedContent)->get_Title(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedContent<D>::Title(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedContent)->put_Title(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedContent<D>::Message() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedContent)->get_Message(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedContent<D>::Message(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedContent)->put_Message(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedContent<D>::TargetUri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedContent)->get_TargetUri(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedContent<D>::TargetUri(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedContent)->put_TargetUri(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::SocialInfo::SocialUserInfo) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedItem<D>::Author() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedItem)->get_Author(&value));
        return llm::OS::ApplicationModel::SocialInfo::SocialUserInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::SocialInfo::SocialFeedContent) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedItem<D>::PrimaryContent() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedItem)->get_PrimaryContent(&value));
        return llm::OS::ApplicationModel::SocialInfo::SocialFeedContent{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::SocialInfo::SocialFeedContent) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedItem<D>::SecondaryContent() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedItem)->get_SecondaryContent(&value));
        return llm::OS::ApplicationModel::SocialInfo::SocialFeedContent{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedItem<D>::Timestamp() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedItem)->get_Timestamp(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedItem<D>::Timestamp(llm::OS::Foundation::DateTime const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedItem)->put_Timestamp(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedItem<D>::TargetUri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedItem)->get_TargetUri(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedItem<D>::TargetUri(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedItem)->put_TargetUri(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::SocialInfo::SocialItemThumbnail>) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedItem<D>::Thumbnails() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedItem)->get_Thumbnails(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::SocialInfo::SocialItemThumbnail>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::SocialInfo::SocialFeedSharedItem) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedItem<D>::SharedItem() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedItem)->get_SharedItem(&value));
        return llm::OS::ApplicationModel::SocialInfo::SocialFeedSharedItem{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedItem<D>::SharedItem(llm::OS::ApplicationModel::SocialInfo::SocialFeedSharedItem const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedItem)->put_SharedItem(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::SocialInfo::SocialItemBadgeStyle) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedItem<D>::BadgeStyle() const
    {
        llm::OS::ApplicationModel::SocialInfo::SocialItemBadgeStyle value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedItem)->get_BadgeStyle(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedItem<D>::BadgeStyle(llm::OS::ApplicationModel::SocialInfo::SocialItemBadgeStyle const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedItem)->put_BadgeStyle(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedItem<D>::BadgeCountValue() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedItem)->get_BadgeCountValue(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedItem<D>::BadgeCountValue(int32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedItem)->put_BadgeCountValue(value));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedItem<D>::RemoteId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedItem)->get_RemoteId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedItem<D>::RemoteId(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedItem)->put_RemoteId(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::SocialInfo::SocialFeedChildItem) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedItem<D>::ChildItem() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedItem)->get_ChildItem(&value));
        return llm::OS::ApplicationModel::SocialInfo::SocialFeedChildItem{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedItem<D>::ChildItem(llm::OS::ApplicationModel::SocialInfo::SocialFeedChildItem const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedItem)->put_ChildItem(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::SocialInfo::SocialFeedItemStyle) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedItem<D>::Style() const
    {
        llm::OS::ApplicationModel::SocialInfo::SocialFeedItemStyle value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedItem)->get_Style(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedItem<D>::Style(llm::OS::ApplicationModel::SocialInfo::SocialFeedItemStyle const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedItem)->put_Style(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedSharedItem<D>::OriginalSource() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedSharedItem)->get_OriginalSource(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedSharedItem<D>::OriginalSource(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedSharedItem)->put_OriginalSource(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::SocialInfo::SocialFeedContent) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedSharedItem<D>::Content() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedSharedItem)->get_Content(&value));
        return llm::OS::ApplicationModel::SocialInfo::SocialFeedContent{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedSharedItem<D>::Timestamp() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedSharedItem)->get_Timestamp(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedSharedItem<D>::Timestamp(llm::OS::Foundation::DateTime const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedSharedItem)->put_Timestamp(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedSharedItem<D>::TargetUri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedSharedItem)->get_TargetUri(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedSharedItem<D>::TargetUri(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedSharedItem)->put_TargetUri(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedSharedItem<D>::Thumbnail(llm::OS::ApplicationModel::SocialInfo::SocialItemThumbnail const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedSharedItem)->put_Thumbnail(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::SocialInfo::SocialItemThumbnail) consume_Windows_ApplicationModel_SocialInfo_ISocialFeedSharedItem<D>::Thumbnail() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialFeedSharedItem)->get_Thumbnail(&value));
        return llm::OS::ApplicationModel::SocialInfo::SocialItemThumbnail{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_ApplicationModel_SocialInfo_ISocialItemThumbnail<D>::TargetUri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialItemThumbnail)->get_TargetUri(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_SocialInfo_ISocialItemThumbnail<D>::TargetUri(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialItemThumbnail)->put_TargetUri(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_ApplicationModel_SocialInfo_ISocialItemThumbnail<D>::ImageUri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialItemThumbnail)->get_ImageUri(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_SocialInfo_ISocialItemThumbnail<D>::ImageUri(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialItemThumbnail)->put_ImageUri(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::BitmapSize) consume_Windows_ApplicationModel_SocialInfo_ISocialItemThumbnail<D>::BitmapSize() const
    {
        llm::OS::Graphics::Imaging::BitmapSize value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialItemThumbnail)->get_BitmapSize(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_SocialInfo_ISocialItemThumbnail<D>::BitmapSize(llm::OS::Graphics::Imaging::BitmapSize const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialItemThumbnail)->put_BitmapSize(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_SocialInfo_ISocialItemThumbnail<D>::SetImageAsync(llm::OS::Storage::Streams::IInputStream const& image) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialItemThumbnail)->SetImageAsync(*(void**)(&image), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_SocialInfo_ISocialUserInfo<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialUserInfo)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_SocialInfo_ISocialUserInfo<D>::DisplayName(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialUserInfo)->put_DisplayName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_SocialInfo_ISocialUserInfo<D>::UserName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialUserInfo)->get_UserName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_SocialInfo_ISocialUserInfo<D>::UserName(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialUserInfo)->put_UserName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_SocialInfo_ISocialUserInfo<D>::RemoteId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialUserInfo)->get_RemoteId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_SocialInfo_ISocialUserInfo<D>::RemoteId(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialUserInfo)->put_RemoteId(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_ApplicationModel_SocialInfo_ISocialUserInfo<D>::TargetUri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialUserInfo)->get_TargetUri(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_SocialInfo_ISocialUserInfo<D>::TargetUri(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::SocialInfo::ISocialUserInfo)->put_TargetUri(*(void**)(&value)));
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::SocialInfo::ISocialFeedChildItem> : produce_base<D, llm::OS::ApplicationModel::SocialInfo::ISocialFeedChildItem>
    {
        int32_t __stdcall get_Author(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::SocialInfo::SocialUserInfo>(this->shim().Author());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PrimaryContent(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::SocialInfo::SocialFeedContent>(this->shim().PrimaryContent());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SecondaryContent(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::SocialInfo::SocialFeedContent>(this->shim().SecondaryContent());
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
        int32_t __stdcall get_Thumbnails(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::SocialInfo::SocialItemThumbnail>>(this->shim().Thumbnails());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SharedItem(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::SocialInfo::SocialFeedSharedItem>(this->shim().SharedItem());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SharedItem(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SharedItem(*reinterpret_cast<llm::OS::ApplicationModel::SocialInfo::SocialFeedSharedItem const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::SocialInfo::ISocialFeedContent> : produce_base<D, llm::OS::ApplicationModel::SocialInfo::ISocialFeedContent>
    {
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
        int32_t __stdcall get_Message(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Message());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Message(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Message(*reinterpret_cast<hstring const*>(&value));
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
    struct produce<D, llm::OS::ApplicationModel::SocialInfo::ISocialFeedItem> : produce_base<D, llm::OS::ApplicationModel::SocialInfo::ISocialFeedItem>
    {
        int32_t __stdcall get_Author(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::SocialInfo::SocialUserInfo>(this->shim().Author());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PrimaryContent(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::SocialInfo::SocialFeedContent>(this->shim().PrimaryContent());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SecondaryContent(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::SocialInfo::SocialFeedContent>(this->shim().SecondaryContent());
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
        int32_t __stdcall get_Thumbnails(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::SocialInfo::SocialItemThumbnail>>(this->shim().Thumbnails());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SharedItem(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::SocialInfo::SocialFeedSharedItem>(this->shim().SharedItem());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SharedItem(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SharedItem(*reinterpret_cast<llm::OS::ApplicationModel::SocialInfo::SocialFeedSharedItem const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BadgeStyle(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::SocialInfo::SocialItemBadgeStyle>(this->shim().BadgeStyle());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BadgeStyle(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BadgeStyle(*reinterpret_cast<llm::OS::ApplicationModel::SocialInfo::SocialItemBadgeStyle const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BadgeCountValue(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().BadgeCountValue());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BadgeCountValue(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BadgeCountValue(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RemoteId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().RemoteId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RemoteId(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoteId(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ChildItem(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::SocialInfo::SocialFeedChildItem>(this->shim().ChildItem());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ChildItem(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ChildItem(*reinterpret_cast<llm::OS::ApplicationModel::SocialInfo::SocialFeedChildItem const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Style(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::SocialInfo::SocialFeedItemStyle>(this->shim().Style());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Style(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Style(*reinterpret_cast<llm::OS::ApplicationModel::SocialInfo::SocialFeedItemStyle const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::SocialInfo::ISocialFeedSharedItem> : produce_base<D, llm::OS::ApplicationModel::SocialInfo::ISocialFeedSharedItem>
    {
        int32_t __stdcall get_OriginalSource(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().OriginalSource());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_OriginalSource(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OriginalSource(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&value));
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
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::SocialInfo::ISocialItemThumbnail> : produce_base<D, llm::OS::ApplicationModel::SocialInfo::ISocialItemThumbnail>
    {
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
        int32_t __stdcall get_ImageUri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().ImageUri());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ImageUri(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ImageUri(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BitmapSize(struct struct_Windows_Graphics_Imaging_BitmapSize* value) noexcept final try
        {
            zero_abi<llm::OS::Graphics::Imaging::BitmapSize>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Imaging::BitmapSize>(this->shim().BitmapSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BitmapSize(struct struct_Windows_Graphics_Imaging_BitmapSize value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BitmapSize(*reinterpret_cast<llm::OS::Graphics::Imaging::BitmapSize const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetImageAsync(void* image, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SetImageAsync(*reinterpret_cast<llm::OS::Storage::Streams::IInputStream const*>(&image)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::SocialInfo::ISocialUserInfo> : produce_base<D, llm::OS::ApplicationModel::SocialInfo::ISocialUserInfo>
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
        int32_t __stdcall get_UserName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().UserName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_UserName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UserName(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RemoteId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().RemoteId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RemoteId(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoteId(*reinterpret_cast<hstring const*>(&value));
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
}
LLM_EXPORT namespace llm::OS::ApplicationModel::SocialInfo
{
    inline SocialFeedChildItem::SocialFeedChildItem() :
        SocialFeedChildItem(impl::call_factory_cast<SocialFeedChildItem(*)(llm::OS::Foundation::IActivationFactory const&), SocialFeedChildItem>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<SocialFeedChildItem>(); }))
    {
    }
    inline SocialFeedItem::SocialFeedItem() :
        SocialFeedItem(impl::call_factory_cast<SocialFeedItem(*)(llm::OS::Foundation::IActivationFactory const&), SocialFeedItem>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<SocialFeedItem>(); }))
    {
    }
    inline SocialFeedSharedItem::SocialFeedSharedItem() :
        SocialFeedSharedItem(impl::call_factory_cast<SocialFeedSharedItem(*)(llm::OS::Foundation::IActivationFactory const&), SocialFeedSharedItem>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<SocialFeedSharedItem>(); }))
    {
    }
    inline SocialItemThumbnail::SocialItemThumbnail() :
        SocialItemThumbnail(impl::call_factory_cast<SocialItemThumbnail(*)(llm::OS::Foundation::IActivationFactory const&), SocialItemThumbnail>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<SocialItemThumbnail>(); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::ApplicationModel::SocialInfo::ISocialFeedChildItem> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::SocialInfo::ISocialFeedContent> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::SocialInfo::ISocialFeedItem> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::SocialInfo::ISocialFeedSharedItem> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::SocialInfo::ISocialItemThumbnail> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::SocialInfo::ISocialUserInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::SocialInfo::SocialFeedChildItem> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::SocialInfo::SocialFeedContent> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::SocialInfo::SocialFeedItem> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::SocialInfo::SocialFeedSharedItem> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::SocialInfo::SocialItemThumbnail> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::SocialInfo::SocialUserInfo> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
