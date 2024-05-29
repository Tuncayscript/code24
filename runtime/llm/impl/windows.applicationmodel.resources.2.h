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
#ifndef LLM_OS_ApplicationModel_Resources_2_H
#define LLM_OS_ApplicationModel_Resources_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.UI.1.h"
#include "llm/impl/Windows.ApplicationModel.Resources.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Resources
{
    struct __declspec(empty_bases) ResourceLoader : llm::OS::ApplicationModel::Resources::IResourceLoader,
        impl::require<ResourceLoader, llm::OS::ApplicationModel::Resources::IResourceLoader2>
    {
        ResourceLoader(std::nullptr_t) noexcept {}
        ResourceLoader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Resources::IResourceLoader(ptr, take_ownership_from_abi) {}
        ResourceLoader();
        explicit ResourceLoader(param::hstring const& name);
        static auto GetStringForReference(llm::OS::Foundation::Uri const& uri);
        static auto GetForCurrentView();
        static auto GetForCurrentView(param::hstring const& name);
        static auto GetForViewIndependentUse();
        static auto GetForViewIndependentUse(param::hstring const& name);
        static auto GetForUIContext(llm::OS::UI::UIContext const& context);
        static auto GetDefaultPriPath(param::hstring const& packageFullName);
    };
}
#endif
