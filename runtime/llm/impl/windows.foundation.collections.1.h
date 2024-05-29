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
#ifndef LLM_OS_Foundation_Collections_1_H
#define LLM_OS_Foundation_Collections_1_H
#include "llm/impl/Windows.Foundation.Collections.0.h"
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename T>
    struct __declspec(empty_bases) IIterable :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<llm::OS::Foundation::Collections::IIterable<T>>
    {
        static_assert(impl::has_category_v<T>, "T must be WinRT type.");
        IIterable(std::nullptr_t = nullptr) noexcept {}
        IIterable(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    template <typename T>
    struct __declspec(empty_bases) IIterator :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<llm::OS::Foundation::Collections::IIterator<T>>
    {
        static_assert(impl::has_category_v<T>, "T must be WinRT type.");
        IIterator(std::nullptr_t = nullptr) noexcept {}
        IIterator(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}

        using iterator_concept = std::input_iterator_tag;
        using iterator_category = std::input_iterator_tag;
        using value_type = T;
        using difference_type = ptrdiff_t;
        using pointer = void;
        using reference = T;
    };
    template <typename K, typename V>
    struct __declspec(empty_bases) IKeyValuePair :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<llm::OS::Foundation::Collections::IKeyValuePair<K, V>>
    {
        static_assert(impl::has_category_v<K>, "K must be WinRT type.");
        static_assert(impl::has_category_v<V>, "V must be WinRT type.");
        IKeyValuePair(std::nullptr_t = nullptr) noexcept {}
        IKeyValuePair(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    template <typename K>
    struct __declspec(empty_bases) IMapChangedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<llm::OS::Foundation::Collections::IMapChangedEventArgs<K>>
    {
        static_assert(impl::has_category_v<K>, "K must be WinRT type.");
        IMapChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMapChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    template <typename K, typename V>
    struct __declspec(empty_bases) IMapView :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<llm::OS::Foundation::Collections::IMapView<K, V>>,
        impl::require<llm::OS::Foundation::Collections::IMapView<K, V>, llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::Collections::IKeyValuePair<K, V>>>
    {
        static_assert(impl::has_category_v<K>, "K must be WinRT type.");
        static_assert(impl::has_category_v<V>, "V must be WinRT type.");
        IMapView(std::nullptr_t = nullptr) noexcept {}
        IMapView(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    template <typename K, typename V>
    struct __declspec(empty_bases) IMap :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<llm::OS::Foundation::Collections::IMap<K, V>>,
        impl::require<llm::OS::Foundation::Collections::IMap<K, V>, llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::Collections::IKeyValuePair<K, V>>>
    {
        static_assert(impl::has_category_v<K>, "K must be WinRT type.");
        static_assert(impl::has_category_v<V>, "V must be WinRT type.");
        IMap(std::nullptr_t = nullptr) noexcept {}
        IMap(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    template <typename K, typename V>
    struct __declspec(empty_bases) IObservableMap :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<llm::OS::Foundation::Collections::IObservableMap<K, V>>,
        impl::require<llm::OS::Foundation::Collections::IObservableMap<K, V>, llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::Collections::IKeyValuePair<K, V>>, llm::OS::Foundation::Collections::IMap<K, V>>
    {
        static_assert(impl::has_category_v<K>, "K must be WinRT type.");
        static_assert(impl::has_category_v<V>, "V must be WinRT type.");
        IObservableMap(std::nullptr_t = nullptr) noexcept {}
        IObservableMap(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    template <typename T>
    struct __declspec(empty_bases) IObservableVector :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<llm::OS::Foundation::Collections::IObservableVector<T>>,
        impl::require<llm::OS::Foundation::Collections::IObservableVector<T>, llm::OS::Foundation::Collections::IIterable<T>, llm::OS::Foundation::Collections::IVector<T>>
    {
        static_assert(impl::has_category_v<T>, "T must be WinRT type.");
        IObservableVector(std::nullptr_t = nullptr) noexcept {}
        IObservableVector(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPropertySet :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPropertySet>,
        impl::require<llm::OS::Foundation::Collections::IPropertySet, llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, llm::OS::Foundation::IInspectable>>, llm::OS::Foundation::Collections::IMap<hstring, llm::OS::Foundation::IInspectable>, llm::OS::Foundation::Collections::IObservableMap<hstring, llm::OS::Foundation::IInspectable>>
    {
        IPropertySet(std::nullptr_t = nullptr) noexcept {}
        IPropertySet(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVectorChangedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IVectorChangedEventArgs>
    {
        IVectorChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IVectorChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    template <typename T>
    struct __declspec(empty_bases) IVectorView :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<llm::OS::Foundation::Collections::IVectorView<T>>,
        impl::require<llm::OS::Foundation::Collections::IVectorView<T>, llm::OS::Foundation::Collections::IIterable<T>>
    {
        static_assert(impl::has_category_v<T>, "T must be WinRT type.");
        IVectorView(std::nullptr_t = nullptr) noexcept {}
        IVectorView(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    template <typename T>
    struct __declspec(empty_bases) IVector :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<llm::OS::Foundation::Collections::IVector<T>>,
        impl::require<llm::OS::Foundation::Collections::IVector<T>, llm::OS::Foundation::Collections::IIterable<T>>
    {
        static_assert(impl::has_category_v<T>, "T must be WinRT type.");
        IVector(std::nullptr_t = nullptr) noexcept {}
        IVector(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
