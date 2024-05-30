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
#ifndef LLM_OS_Media_ContentRestrictions_1_H
#define LLM_OS_Media_ContentRestrictions_1_H
#include "llm/impl/Windows.Media.ContentRestrictions.0.h"
LLM_EXPORT namespace llm:OS::Media::ContentRestrictions
{
    struct __declspec(empty_bases) IContentRestrictionsBrowsePolicy :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IContentRestrictionsBrowsePolicy>
    {
        IContentRestrictionsBrowsePolicy(std::nullptr_t = nullptr) noexcept {}
        IContentRestrictionsBrowsePolicy(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRatedContentDescription :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRatedContentDescription>
    {
        IRatedContentDescription(std::nullptr_t = nullptr) noexcept {}
        IRatedContentDescription(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRatedContentDescriptionFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRatedContentDescriptionFactory>
    {
        IRatedContentDescriptionFactory(std::nullptr_t = nullptr) noexcept {}
        IRatedContentDescriptionFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRatedContentRestrictions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRatedContentRestrictions>
    {
        IRatedContentRestrictions(std::nullptr_t = nullptr) noexcept {}
        IRatedContentRestrictions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRatedContentRestrictionsFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRatedContentRestrictionsFactory>
    {
        IRatedContentRestrictionsFactory(std::nullptr_t = nullptr) noexcept {}
        IRatedContentRestrictionsFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
