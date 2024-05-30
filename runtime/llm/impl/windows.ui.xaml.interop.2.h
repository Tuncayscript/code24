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
#ifndef LLM_OS_UI_Xaml_Interop_2_H
#define LLM_OS_UI_Xaml_Interop_2_H
#include "llm/impl/Windows.UI.Xaml.Interop.1.h"
LLM_EXPORT namespace llm::OS::UI::Xaml::Interop
{
    struct BindableVectorChangedEventHandler : llm::OS::Foundation::IUnknown
    {
        BindableVectorChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
        BindableVectorChangedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> BindableVectorChangedEventHandler(L lambda);
        template <typename F> BindableVectorChangedEventHandler(F* function);
        template <typename O, typename M> BindableVectorChangedEventHandler(O* object, M method);
        template <typename O, typename M> BindableVectorChangedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> BindableVectorChangedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::UI::Xaml::Interop::IBindableObservableVector const& vector, llm::OS::Foundation::IInspectable const& e) const;
    };
    struct NotifyCollectionChangedEventHandler : llm::OS::Foundation::IUnknown
    {
        NotifyCollectionChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
        NotifyCollectionChangedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> NotifyCollectionChangedEventHandler(L lambda);
        template <typename F> NotifyCollectionChangedEventHandler(F* function);
        template <typename O, typename M> NotifyCollectionChangedEventHandler(O* object, M method);
        template <typename O, typename M> NotifyCollectionChangedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> NotifyCollectionChangedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Interop::NotifyCollectionChangedEventArgs const& e) const;
    };
    struct TypeName
    {
        hstring Name;
        llm::OS::UI::Xaml::Interop::TypeKind Kind;
    };
    inline bool operator==(TypeName const& left, TypeName const& right) noexcept
    {
        return left.Name == right.Name && left.Kind == right.Kind;
    }
    inline bool operator!=(TypeName const& left, TypeName const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) NotifyCollectionChangedEventArgs : llm::OS::UI::Xaml::Interop::INotifyCollectionChangedEventArgs
    {
        NotifyCollectionChangedEventArgs(std::nullptr_t) noexcept {}
        NotifyCollectionChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Interop::INotifyCollectionChangedEventArgs(ptr, take_ownership_from_abi) {}
        NotifyCollectionChangedEventArgs(llm::OS::UI::Xaml::Interop::NotifyCollectionChangedAction const& action, llm::OS::UI::Xaml::Interop::IBindableVector const& newItems, llm::OS::UI::Xaml::Interop::IBindableVector const& oldItems, int32_t newIndex, int32_t oldIndex);
    };
}
#endif
