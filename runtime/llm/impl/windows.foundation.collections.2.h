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
#ifndef LLM_OS_Foundation_Collections_2_H
#define LLM_OS_Foundation_Collections_2_H
#include "llm/impl/Windows.Foundation.Collections.1.h"
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename K, typename V>
    struct MapChangedEventHandler : llm::OS::Foundation::IUnknown
    {
        static_assert(impl::has_category_v<K>, "K must be WinRT type.");
        static_assert(impl::has_category_v<V>, "V must be WinRT type.");
        MapChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
        MapChangedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> MapChangedEventHandler(L lambda);
        template <typename F> MapChangedEventHandler(F* function);
        template <typename O, typename M> MapChangedEventHandler(O* object, M method);
        template <typename O, typename M> MapChangedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> MapChangedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::Collections::IObservableMap<K, V> const& sender, llm::OS::Foundation::Collections::IMapChangedEventArgs<K> const& event) const;
    };
    template <typename T>
    struct VectorChangedEventHandler : llm::OS::Foundation::IUnknown
    {
        static_assert(impl::has_category_v<T>, "T must be WinRT type.");
        VectorChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
        VectorChangedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> VectorChangedEventHandler(L lambda);
        template <typename F> VectorChangedEventHandler(F* function);
        template <typename O, typename M> VectorChangedEventHandler(O* object, M method);
        template <typename O, typename M> VectorChangedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> VectorChangedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::Collections::IObservableVector<T> const& sender, llm::OS::Foundation::Collections::IVectorChangedEventArgs const& event) const;
    };
    struct __declspec(empty_bases) PropertySet : llm::OS::Foundation::Collections::IPropertySet
    {
        PropertySet(std::nullptr_t) noexcept {}
        PropertySet(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Collections::IPropertySet(ptr, take_ownership_from_abi) {}
        PropertySet();
    };
    struct __declspec(empty_bases) StringMap : llm::OS::Foundation::Collections::IMap<hstring, hstring>,
        impl::require<StringMap, llm::OS::Foundation::Collections::IObservableMap<hstring, hstring>>
    {
        StringMap(std::nullptr_t) noexcept {}
        StringMap(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Collections::IMap<hstring, hstring>(ptr, take_ownership_from_abi) {}
        StringMap();
    };
    struct __declspec(empty_bases) ValueSet : llm::OS::Foundation::Collections::IPropertySet
    {
        ValueSet(std::nullptr_t) noexcept {}
        ValueSet(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Collections::IPropertySet(ptr, take_ownership_from_abi) {}
        ValueSet();
    };
}
#endif
