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
#ifndef LLM_OS_UI_Xaml_Resources_2_H
#define LLM_OS_UI_Xaml_Resources_2_H
#include "llm/impl/Windows.UI.Xaml.Resources.1.h"
LLM_EXPORT namespace llm::OS::UI::Xaml::Resources
{
    struct __declspec(empty_bases) CustomXamlResourceLoader : llm::OS::UI::Xaml::Resources::ICustomXamlResourceLoader,
        impl::require<CustomXamlResourceLoader, llm::OS::UI::Xaml::Resources::ICustomXamlResourceLoaderOverrides>
    {
        CustomXamlResourceLoader(std::nullptr_t) noexcept {}
        CustomXamlResourceLoader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Resources::ICustomXamlResourceLoader(ptr, take_ownership_from_abi) {}
        CustomXamlResourceLoader();
        [[nodiscard]] static auto Current();
        static auto Current(llm::OS::UI::Xaml::Resources::CustomXamlResourceLoader const& value);
    };
    template <typename D>
    class ICustomXamlResourceLoaderOverridesT
    {
        D& shim() noexcept { return *static_cast<D*>(this); }
        D const& shim() const noexcept { return *static_cast<const D*>(this); }
    public:
        using ICustomXamlResourceLoaderOverrides = llm::OS::UI::Xaml::Resources::ICustomXamlResourceLoaderOverrides;
        WINRT_IMPL_AUTO(llm::OS::Foundation::IInspectable) GetResource(param::hstring const& resourceId, param::hstring const& objectType, param::hstring const& propertyName, param::hstring const& propertyType) const;
    };
}
#endif
