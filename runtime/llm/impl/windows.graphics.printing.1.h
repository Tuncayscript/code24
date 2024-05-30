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
#ifndef LLM_OS_Graphics_Printing_1_H
#define LLM_OS_Graphics_Printing_1_H
#include "llm/impl/Windows.Graphics.Printing.0.h"
LLM_EXPORT namespace llm::OS::Graphics::Printing
{
    struct __declspec(empty_bases) IPrintDocumentSource :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintDocumentSource>
    {
        IPrintDocumentSource(std::nullptr_t = nullptr) noexcept {}
        IPrintDocumentSource(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintManager :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintManager>
    {
        IPrintManager(std::nullptr_t = nullptr) noexcept {}
        IPrintManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintManagerStatic :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintManagerStatic>
    {
        IPrintManagerStatic(std::nullptr_t = nullptr) noexcept {}
        IPrintManagerStatic(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintManagerStatic2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintManagerStatic2>
    {
        IPrintManagerStatic2(std::nullptr_t = nullptr) noexcept {}
        IPrintManagerStatic2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintPageInfo :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintPageInfo>
    {
        IPrintPageInfo(std::nullptr_t = nullptr) noexcept {}
        IPrintPageInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintPageRange :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintPageRange>
    {
        IPrintPageRange(std::nullptr_t = nullptr) noexcept {}
        IPrintPageRange(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintPageRangeFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintPageRangeFactory>
    {
        IPrintPageRangeFactory(std::nullptr_t = nullptr) noexcept {}
        IPrintPageRangeFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintPageRangeOptions :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintPageRangeOptions>
    {
        IPrintPageRangeOptions(std::nullptr_t = nullptr) noexcept {}
        IPrintPageRangeOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintTask :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintTask>
    {
        IPrintTask(std::nullptr_t = nullptr) noexcept {}
        IPrintTask(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintTask2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintTask2>
    {
        IPrintTask2(std::nullptr_t = nullptr) noexcept {}
        IPrintTask2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintTaskCompletedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintTaskCompletedEventArgs>
    {
        IPrintTaskCompletedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPrintTaskCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintTaskOptions :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintTaskOptions>
    {
        IPrintTaskOptions(std::nullptr_t = nullptr) noexcept {}
        IPrintTaskOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintTaskOptions2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintTaskOptions2>
    {
        IPrintTaskOptions2(std::nullptr_t = nullptr) noexcept {}
        IPrintTaskOptions2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintTaskOptionsCore :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintTaskOptionsCore>
    {
        IPrintTaskOptionsCore(std::nullptr_t = nullptr) noexcept {}
        IPrintTaskOptionsCore(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintTaskOptionsCoreProperties :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintTaskOptionsCoreProperties>
    {
        IPrintTaskOptionsCoreProperties(std::nullptr_t = nullptr) noexcept {}
        IPrintTaskOptionsCoreProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintTaskOptionsCoreUIConfiguration :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintTaskOptionsCoreUIConfiguration>
    {
        IPrintTaskOptionsCoreUIConfiguration(std::nullptr_t = nullptr) noexcept {}
        IPrintTaskOptionsCoreUIConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintTaskProgressingEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintTaskProgressingEventArgs>
    {
        IPrintTaskProgressingEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPrintTaskProgressingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintTaskRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintTaskRequest>
    {
        IPrintTaskRequest(std::nullptr_t = nullptr) noexcept {}
        IPrintTaskRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintTaskRequestedDeferral :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintTaskRequestedDeferral>
    {
        IPrintTaskRequestedDeferral(std::nullptr_t = nullptr) noexcept {}
        IPrintTaskRequestedDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintTaskRequestedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintTaskRequestedEventArgs>
    {
        IPrintTaskRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPrintTaskRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintTaskSourceRequestedArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintTaskSourceRequestedArgs>
    {
        IPrintTaskSourceRequestedArgs(std::nullptr_t = nullptr) noexcept {}
        IPrintTaskSourceRequestedArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintTaskSourceRequestedDeferral :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintTaskSourceRequestedDeferral>
    {
        IPrintTaskSourceRequestedDeferral(std::nullptr_t = nullptr) noexcept {}
        IPrintTaskSourceRequestedDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintTaskTargetDeviceSupport :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintTaskTargetDeviceSupport>
    {
        IPrintTaskTargetDeviceSupport(std::nullptr_t = nullptr) noexcept {}
        IPrintTaskTargetDeviceSupport(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStandardPrintTaskOptionsStatic :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IStandardPrintTaskOptionsStatic>
    {
        IStandardPrintTaskOptionsStatic(std::nullptr_t = nullptr) noexcept {}
        IStandardPrintTaskOptionsStatic(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStandardPrintTaskOptionsStatic2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IStandardPrintTaskOptionsStatic2>
    {
        IStandardPrintTaskOptionsStatic2(std::nullptr_t = nullptr) noexcept {}
        IStandardPrintTaskOptionsStatic2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStandardPrintTaskOptionsStatic3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IStandardPrintTaskOptionsStatic3>
    {
        IStandardPrintTaskOptionsStatic3(std::nullptr_t = nullptr) noexcept {}
        IStandardPrintTaskOptionsStatic3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
