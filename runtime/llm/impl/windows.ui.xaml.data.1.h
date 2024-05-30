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
#ifndef LLM_OS_UI_Xaml_Data_1_H
#define LLM_OS_UI_Xaml_Data_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Foundation.Collections.0.h"
#include "llm/impl/Windows.UI.Xaml.Data.0.h"
LLM_EXPORT namespace llm::OS::UI::Xaml::Data
{
    struct __declspec(empty_bases) IBinding :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBinding>
    {
        IBinding(std::nullptr_t = nullptr) noexcept {}
        IBinding(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBinding2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBinding2>
    {
        IBinding2(std::nullptr_t = nullptr) noexcept {}
        IBinding2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBindingBase :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBindingBase>
    {
        IBindingBase(std::nullptr_t = nullptr) noexcept {}
        IBindingBase(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBindingBaseFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBindingBaseFactory>
    {
        IBindingBaseFactory(std::nullptr_t = nullptr) noexcept {}
        IBindingBaseFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBindingExpression :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBindingExpression>
    {
        IBindingExpression(std::nullptr_t = nullptr) noexcept {}
        IBindingExpression(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBindingExpressionBase :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBindingExpressionBase>
    {
        IBindingExpressionBase(std::nullptr_t = nullptr) noexcept {}
        IBindingExpressionBase(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBindingExpressionBaseFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBindingExpressionBaseFactory>
    {
        IBindingExpressionBaseFactory(std::nullptr_t = nullptr) noexcept {}
        IBindingExpressionBaseFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBindingExpressionFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBindingExpressionFactory>
    {
        IBindingExpressionFactory(std::nullptr_t = nullptr) noexcept {}
        IBindingExpressionFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBindingFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBindingFactory>
    {
        IBindingFactory(std::nullptr_t = nullptr) noexcept {}
        IBindingFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBindingOperations :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBindingOperations>
    {
        IBindingOperations(std::nullptr_t = nullptr) noexcept {}
        IBindingOperations(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBindingOperationsStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBindingOperationsStatics>
    {
        IBindingOperationsStatics(std::nullptr_t = nullptr) noexcept {}
        IBindingOperationsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICollectionView :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICollectionView>,
        impl::require<llm::OS::UI::Xaml::Data::ICollectionView, llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::IInspectable>, llm::OS::Foundation::Collections::IVector<llm::OS::Foundation::IInspectable>, llm::OS::Foundation::Collections::IObservableVector<llm::OS::Foundation::IInspectable>>
    {
        ICollectionView(std::nullptr_t = nullptr) noexcept {}
        ICollectionView(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICollectionViewFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICollectionViewFactory>
    {
        ICollectionViewFactory(std::nullptr_t = nullptr) noexcept {}
        ICollectionViewFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICollectionViewGroup :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICollectionViewGroup>
    {
        ICollectionViewGroup(std::nullptr_t = nullptr) noexcept {}
        ICollectionViewGroup(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICollectionViewSource :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICollectionViewSource>
    {
        ICollectionViewSource(std::nullptr_t = nullptr) noexcept {}
        ICollectionViewSource(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICollectionViewSourceStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICollectionViewSourceStatics>
    {
        ICollectionViewSourceStatics(std::nullptr_t = nullptr) noexcept {}
        ICollectionViewSourceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICurrentChangingEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICurrentChangingEventArgs>
    {
        ICurrentChangingEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICurrentChangingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICurrentChangingEventArgsFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICurrentChangingEventArgsFactory>
    {
        ICurrentChangingEventArgsFactory(std::nullptr_t = nullptr) noexcept {}
        ICurrentChangingEventArgsFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICustomProperty :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICustomProperty>
    {
        ICustomProperty(std::nullptr_t = nullptr) noexcept {}
        ICustomProperty(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICustomPropertyProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICustomPropertyProvider>
    {
        ICustomPropertyProvider(std::nullptr_t = nullptr) noexcept {}
        ICustomPropertyProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IItemIndexRange :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IItemIndexRange>
    {
        IItemIndexRange(std::nullptr_t = nullptr) noexcept {}
        IItemIndexRange(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IItemIndexRangeFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IItemIndexRangeFactory>
    {
        IItemIndexRangeFactory(std::nullptr_t = nullptr) noexcept {}
        IItemIndexRangeFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IItemsRangeInfo :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IItemsRangeInfo>,
        impl::require<llm::OS::UI::Xaml::Data::IItemsRangeInfo, llm::OS::Foundation::IClosable>
    {
        IItemsRangeInfo(std::nullptr_t = nullptr) noexcept {}
        IItemsRangeInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INotifyPropertyChanged :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<INotifyPropertyChanged>
    {
        INotifyPropertyChanged(std::nullptr_t = nullptr) noexcept {}
        INotifyPropertyChanged(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPropertyChangedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPropertyChangedEventArgs>
    {
        IPropertyChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPropertyChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPropertyChangedEventArgsFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPropertyChangedEventArgsFactory>
    {
        IPropertyChangedEventArgsFactory(std::nullptr_t = nullptr) noexcept {}
        IPropertyChangedEventArgsFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRelativeSource :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IRelativeSource>
    {
        IRelativeSource(std::nullptr_t = nullptr) noexcept {}
        IRelativeSource(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRelativeSourceFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IRelativeSourceFactory>
    {
        IRelativeSourceFactory(std::nullptr_t = nullptr) noexcept {}
        IRelativeSourceFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISelectionInfo :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISelectionInfo>
    {
        ISelectionInfo(std::nullptr_t = nullptr) noexcept {}
        ISelectionInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISupportIncrementalLoading :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISupportIncrementalLoading>
    {
        ISupportIncrementalLoading(std::nullptr_t = nullptr) noexcept {}
        ISupportIncrementalLoading(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IValueConverter :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IValueConverter>
    {
        IValueConverter(std::nullptr_t = nullptr) noexcept {}
        IValueConverter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
