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
#ifndef LLM_OS_UI_Xaml_Interop_1_H
#define LLM_OS_UI_Xaml_Interop_1_H
#include "llm/impl/Windows.UI.Xaml.Interop.0.h"
LLM_EXPORT namespace llm::OS::UI::Xaml::Interop
{
    struct __declspec(empty_bases) IBindableIterable :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBindableIterable>
    {
        IBindableIterable(std::nullptr_t = nullptr) noexcept {}
        IBindableIterable(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBindableIterator :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBindableIterator>
    {
        IBindableIterator(std::nullptr_t = nullptr) noexcept {}
        IBindableIterator(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}

        using iterator_concept = std::input_iterator_tag;
        using iterator_category = std::input_iterator_tag;
        using value_type = Windows::Foundation::IInspectable;
        using difference_type = ptrdiff_t;
        using pointer = void;
        using reference = Windows::Foundation::IInspectable;
    };
    struct __declspec(empty_bases) IBindableObservableVector :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBindableObservableVector>,
        impl::require<llm::OS::UI::Xaml::Interop::IBindableObservableVector, llm::OS::UI::Xaml::Interop::IBindableIterable, llm::OS::UI::Xaml::Interop::IBindableVector>
    {
        IBindableObservableVector(std::nullptr_t = nullptr) noexcept {}
        IBindableObservableVector(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBindableVector :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBindableVector>,
        impl::require<llm::OS::UI::Xaml::Interop::IBindableVector, llm::OS::UI::Xaml::Interop::IBindableIterable>
    {
        IBindableVector(std::nullptr_t = nullptr) noexcept {}
        IBindableVector(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBindableVectorView :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBindableVectorView>,
        impl::require<llm::OS::UI::Xaml::Interop::IBindableVectorView, llm::OS::UI::Xaml::Interop::IBindableIterable>
    {
        IBindableVectorView(std::nullptr_t = nullptr) noexcept {}
        IBindableVectorView(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INotifyCollectionChanged :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<INotifyCollectionChanged>
    {
        INotifyCollectionChanged(std::nullptr_t = nullptr) noexcept {}
        INotifyCollectionChanged(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INotifyCollectionChangedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<INotifyCollectionChangedEventArgs>
    {
        INotifyCollectionChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        INotifyCollectionChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INotifyCollectionChangedEventArgsFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<INotifyCollectionChangedEventArgsFactory>
    {
        INotifyCollectionChangedEventArgsFactory(std::nullptr_t = nullptr) noexcept {}
        INotifyCollectionChangedEventArgsFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
