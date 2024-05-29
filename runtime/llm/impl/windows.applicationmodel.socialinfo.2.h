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
#ifndef LLM_OS_ApplicationModel_SocialInfo_2_H
#define LLM_OS_ApplicationModel_SocialInfo_2_H
#include "llm/impl/Windows.ApplicationModel.SocialInfo.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::SocialInfo
{
    struct __declspec(empty_bases) SocialFeedChildItem : llm::OS::ApplicationModel::SocialInfo::ISocialFeedChildItem
    {
        SocialFeedChildItem(std::nullptr_t) noexcept {}
        SocialFeedChildItem(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::SocialInfo::ISocialFeedChildItem(ptr, take_ownership_from_abi) {}
        SocialFeedChildItem();
    };
    struct __declspec(empty_bases) SocialFeedContent : llm::OS::ApplicationModel::SocialInfo::ISocialFeedContent
    {
        SocialFeedContent(std::nullptr_t) noexcept {}
        SocialFeedContent(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::SocialInfo::ISocialFeedContent(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SocialFeedItem : llm::OS::ApplicationModel::SocialInfo::ISocialFeedItem
    {
        SocialFeedItem(std::nullptr_t) noexcept {}
        SocialFeedItem(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::SocialInfo::ISocialFeedItem(ptr, take_ownership_from_abi) {}
        SocialFeedItem();
    };
    struct __declspec(empty_bases) SocialFeedSharedItem : llm::OS::ApplicationModel::SocialInfo::ISocialFeedSharedItem
    {
        SocialFeedSharedItem(std::nullptr_t) noexcept {}
        SocialFeedSharedItem(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::SocialInfo::ISocialFeedSharedItem(ptr, take_ownership_from_abi) {}
        SocialFeedSharedItem();
    };
    struct __declspec(empty_bases) SocialItemThumbnail : llm::OS::ApplicationModel::SocialInfo::ISocialItemThumbnail
    {
        SocialItemThumbnail(std::nullptr_t) noexcept {}
        SocialItemThumbnail(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::SocialInfo::ISocialItemThumbnail(ptr, take_ownership_from_abi) {}
        SocialItemThumbnail();
    };
    struct __declspec(empty_bases) SocialUserInfo : llm::OS::ApplicationModel::SocialInfo::ISocialUserInfo
    {
        SocialUserInfo(std::nullptr_t) noexcept {}
        SocialUserInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::SocialInfo::ISocialUserInfo(ptr, take_ownership_from_abi) {}
    };
}
#endif
