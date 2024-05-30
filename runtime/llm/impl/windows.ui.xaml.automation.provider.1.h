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
#ifndef LLM_OS_UI_Xaml_Automation_Provider_1_H
#define LLM_OS_UI_Xaml_Automation_Provider_1_H
#include "llm/impl/Windows.UI.Xaml.Automation.Provider.0.h"
LLM_EXPORT namespace llm::OS::UI::Xaml::Automation::Provider
{
    struct __declspec(empty_bases) IAnnotationProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAnnotationProvider>
    {
        IAnnotationProvider(std::nullptr_t = nullptr) noexcept {}
        IAnnotationProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICustomNavigationProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICustomNavigationProvider>
    {
        ICustomNavigationProvider(std::nullptr_t = nullptr) noexcept {}
        ICustomNavigationProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDockProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDockProvider>
    {
        IDockProvider(std::nullptr_t = nullptr) noexcept {}
        IDockProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDragProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDragProvider>
    {
        IDragProvider(std::nullptr_t = nullptr) noexcept {}
        IDragProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDropTargetProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDropTargetProvider>
    {
        IDropTargetProvider(std::nullptr_t = nullptr) noexcept {}
        IDropTargetProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IExpandCollapseProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IExpandCollapseProvider>
    {
        IExpandCollapseProvider(std::nullptr_t = nullptr) noexcept {}
        IExpandCollapseProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGridItemProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGridItemProvider>
    {
        IGridItemProvider(std::nullptr_t = nullptr) noexcept {}
        IGridItemProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGridProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGridProvider>
    {
        IGridProvider(std::nullptr_t = nullptr) noexcept {}
        IGridProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIRawElementProviderSimple :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IIRawElementProviderSimple>
    {
        IIRawElementProviderSimple(std::nullptr_t = nullptr) noexcept {}
        IIRawElementProviderSimple(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInvokeProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IInvokeProvider>
    {
        IInvokeProvider(std::nullptr_t = nullptr) noexcept {}
        IInvokeProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IItemContainerProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IItemContainerProvider>
    {
        IItemContainerProvider(std::nullptr_t = nullptr) noexcept {}
        IItemContainerProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMultipleViewProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IMultipleViewProvider>
    {
        IMultipleViewProvider(std::nullptr_t = nullptr) noexcept {}
        IMultipleViewProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IObjectModelProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IObjectModelProvider>
    {
        IObjectModelProvider(std::nullptr_t = nullptr) noexcept {}
        IObjectModelProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRangeValueProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IRangeValueProvider>
    {
        IRangeValueProvider(std::nullptr_t = nullptr) noexcept {}
        IRangeValueProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IScrollItemProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IScrollItemProvider>
    {
        IScrollItemProvider(std::nullptr_t = nullptr) noexcept {}
        IScrollItemProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IScrollProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IScrollProvider>
    {
        IScrollProvider(std::nullptr_t = nullptr) noexcept {}
        IScrollProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISelectionItemProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISelectionItemProvider>
    {
        ISelectionItemProvider(std::nullptr_t = nullptr) noexcept {}
        ISelectionItemProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISelectionProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISelectionProvider>
    {
        ISelectionProvider(std::nullptr_t = nullptr) noexcept {}
        ISelectionProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpreadsheetItemProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISpreadsheetItemProvider>
    {
        ISpreadsheetItemProvider(std::nullptr_t = nullptr) noexcept {}
        ISpreadsheetItemProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpreadsheetProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISpreadsheetProvider>
    {
        ISpreadsheetProvider(std::nullptr_t = nullptr) noexcept {}
        ISpreadsheetProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStylesProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IStylesProvider>
    {
        IStylesProvider(std::nullptr_t = nullptr) noexcept {}
        IStylesProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISynchronizedInputProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISynchronizedInputProvider>
    {
        ISynchronizedInputProvider(std::nullptr_t = nullptr) noexcept {}
        ISynchronizedInputProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITableItemProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITableItemProvider>
    {
        ITableItemProvider(std::nullptr_t = nullptr) noexcept {}
        ITableItemProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITableProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITableProvider>
    {
        ITableProvider(std::nullptr_t = nullptr) noexcept {}
        ITableProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITextChildProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITextChildProvider>
    {
        ITextChildProvider(std::nullptr_t = nullptr) noexcept {}
        ITextChildProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITextEditProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITextEditProvider>,
        impl::require<llm::OS::UI::Xaml::Automation::Provider::ITextEditProvider, llm::OS::UI::Xaml::Automation::Provider::ITextProvider>
    {
        ITextEditProvider(std::nullptr_t = nullptr) noexcept {}
        ITextEditProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITextProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITextProvider>
    {
        ITextProvider(std::nullptr_t = nullptr) noexcept {}
        ITextProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITextProvider2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITextProvider2>,
        impl::require<llm::OS::UI::Xaml::Automation::Provider::ITextProvider2, llm::OS::UI::Xaml::Automation::Provider::ITextProvider>
    {
        ITextProvider2(std::nullptr_t = nullptr) noexcept {}
        ITextProvider2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITextRangeProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITextRangeProvider>
    {
        ITextRangeProvider(std::nullptr_t = nullptr) noexcept {}
        ITextRangeProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITextRangeProvider2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITextRangeProvider2>,
        impl::require<llm::OS::UI::Xaml::Automation::Provider::ITextRangeProvider2, llm::OS::UI::Xaml::Automation::Provider::ITextRangeProvider>
    {
        ITextRangeProvider2(std::nullptr_t = nullptr) noexcept {}
        ITextRangeProvider2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToggleProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IToggleProvider>
    {
        IToggleProvider(std::nullptr_t = nullptr) noexcept {}
        IToggleProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITransformProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITransformProvider>
    {
        ITransformProvider(std::nullptr_t = nullptr) noexcept {}
        ITransformProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITransformProvider2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITransformProvider2>,
        impl::require<llm::OS::UI::Xaml::Automation::Provider::ITransformProvider2, llm::OS::UI::Xaml::Automation::Provider::ITransformProvider>
    {
        ITransformProvider2(std::nullptr_t = nullptr) noexcept {}
        ITransformProvider2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IValueProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IValueProvider>
    {
        IValueProvider(std::nullptr_t = nullptr) noexcept {}
        IValueProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVirtualizedItemProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IVirtualizedItemProvider>
    {
        IVirtualizedItemProvider(std::nullptr_t = nullptr) noexcept {}
        IVirtualizedItemProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWindowProvider>
    {
        IWindowProvider(std::nullptr_t = nullptr) noexcept {}
        IWindowProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
