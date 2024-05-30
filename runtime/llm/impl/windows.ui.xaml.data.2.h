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
#ifndef LLM_OS_UI_Xaml_Data_2_H
#define LLM_OS_UI_Xaml_Data_2_H
#include "llm/impl/Windows.UI.Xaml.1.h"
#include "llm/impl/Windows.UI.Xaml.Data.1.h"
LLM_EXPORT namespace llm::OS::UI::Xaml::Data
{
    struct CurrentChangingEventHandler : llm::OS::Foundation::IUnknown
    {
        CurrentChangingEventHandler(std::nullptr_t = nullptr) noexcept {}
        CurrentChangingEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> CurrentChangingEventHandler(L lambda);
        template <typename F> CurrentChangingEventHandler(F* function);
        template <typename O, typename M> CurrentChangingEventHandler(O* object, M method);
        template <typename O, typename M> CurrentChangingEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> CurrentChangingEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Data::CurrentChangingEventArgs const& e) const;
    };
    struct PropertyChangedEventHandler : llm::OS::Foundation::IUnknown
    {
        PropertyChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
        PropertyChangedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> PropertyChangedEventHandler(L lambda);
        template <typename F> PropertyChangedEventHandler(F* function);
        template <typename O, typename M> PropertyChangedEventHandler(O* object, M method);
        template <typename O, typename M> PropertyChangedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> PropertyChangedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Data::PropertyChangedEventArgs const& e) const;
    };
    struct LoadMoreItemsResult
    {
        uint32_t Count;
    };
    inline bool operator==(LoadMoreItemsResult const& left, LoadMoreItemsResult const& right) noexcept
    {
        return left.Count == right.Count;
    }
    inline bool operator!=(LoadMoreItemsResult const& left, LoadMoreItemsResult const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) Binding : llm::OS::UI::Xaml::Data::IBinding,
        impl::base<Binding, llm::OS::UI::Xaml::Data::BindingBase, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<Binding, llm::OS::UI::Xaml::Data::IBinding2, llm::OS::UI::Xaml::Data::IBindingBase, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        Binding(std::nullptr_t) noexcept {}
        Binding(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Data::IBinding(ptr, take_ownership_from_abi) {}
        Binding();
    };
    struct __declspec(empty_bases) BindingBase : llm::OS::UI::Xaml::Data::IBindingBase,
        impl::base<BindingBase, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<BindingBase, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        BindingBase(std::nullptr_t) noexcept {}
        BindingBase(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Data::IBindingBase(ptr, take_ownership_from_abi) {}
        BindingBase();
    };
    struct __declspec(empty_bases) BindingExpression : llm::OS::UI::Xaml::Data::IBindingExpression,
        impl::base<BindingExpression, llm::OS::UI::Xaml::Data::BindingExpressionBase>,
        impl::require<BindingExpression, llm::OS::UI::Xaml::Data::IBindingExpressionBase>
    {
        BindingExpression(std::nullptr_t) noexcept {}
        BindingExpression(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Data::IBindingExpression(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BindingExpressionBase : llm::OS::UI::Xaml::Data::IBindingExpressionBase
    {
        BindingExpressionBase(std::nullptr_t) noexcept {}
        BindingExpressionBase(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Data::IBindingExpressionBase(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BindingOperations : llm::OS::UI::Xaml::Data::IBindingOperations
    {
        BindingOperations(std::nullptr_t) noexcept {}
        BindingOperations(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Data::IBindingOperations(ptr, take_ownership_from_abi) {}
        static auto SetBinding(llm::OS::UI::Xaml::DependencyObject const& target, llm::OS::UI::Xaml::DependencyProperty const& dp, llm::OS::UI::Xaml::Data::BindingBase const& binding);
    };
    struct __declspec(empty_bases) CollectionViewSource : llm::OS::UI::Xaml::Data::ICollectionViewSource,
        impl::base<CollectionViewSource, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<CollectionViewSource, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        CollectionViewSource(std::nullptr_t) noexcept {}
        CollectionViewSource(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Data::ICollectionViewSource(ptr, take_ownership_from_abi) {}
        CollectionViewSource();
        [[nodiscard]] static auto SourceProperty();
        [[nodiscard]] static auto ViewProperty();
        [[nodiscard]] static auto IsSourceGroupedProperty();
        [[nodiscard]] static auto ItemsPathProperty();
    };
    struct __declspec(empty_bases) CurrentChangingEventArgs : llm::OS::UI::Xaml::Data::ICurrentChangingEventArgs
    {
        CurrentChangingEventArgs(std::nullptr_t) noexcept {}
        CurrentChangingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Data::ICurrentChangingEventArgs(ptr, take_ownership_from_abi) {}
        CurrentChangingEventArgs();
        explicit CurrentChangingEventArgs(bool isCancelable);
    };
    struct __declspec(empty_bases) ItemIndexRange : llm::OS::UI::Xaml::Data::IItemIndexRange
    {
        ItemIndexRange(std::nullptr_t) noexcept {}
        ItemIndexRange(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Data::IItemIndexRange(ptr, take_ownership_from_abi) {}
        ItemIndexRange(int32_t firstIndex, uint32_t length);
    };
    struct __declspec(empty_bases) PropertyChangedEventArgs : llm::OS::UI::Xaml::Data::IPropertyChangedEventArgs
    {
        PropertyChangedEventArgs(std::nullptr_t) noexcept {}
        PropertyChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Data::IPropertyChangedEventArgs(ptr, take_ownership_from_abi) {}
        explicit PropertyChangedEventArgs(param::hstring const& name);
    };
    struct __declspec(empty_bases) RelativeSource : llm::OS::UI::Xaml::Data::IRelativeSource,
        impl::base<RelativeSource, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<RelativeSource, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        RelativeSource(std::nullptr_t) noexcept {}
        RelativeSource(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Data::IRelativeSource(ptr, take_ownership_from_abi) {}
        RelativeSource();
    };
}
#endif
