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
#ifndef LLM_OS_Devices_Printers_1_H
#define LLM_OS_Devices_Printers_1_H
#include "llm/impl/Windows.Devices.Printers.0.h"
LLM_EXPORT namespace llm::OS::Devices::Printers
{
    struct __declspec(empty_bases) IIppAttributeError :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IIppAttributeError>
    {
        IIppAttributeError(std::nullptr_t = nullptr) noexcept {}
        IIppAttributeError(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIppAttributeValue :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IIppAttributeValue>
    {
        IIppAttributeValue(std::nullptr_t = nullptr) noexcept {}
        IIppAttributeValue(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIppAttributeValueStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IIppAttributeValueStatics>
    {
        IIppAttributeValueStatics(std::nullptr_t = nullptr) noexcept {}
        IIppAttributeValueStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIppIntegerRange :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IIppIntegerRange>
    {
        IIppIntegerRange(std::nullptr_t = nullptr) noexcept {}
        IIppIntegerRange(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIppIntegerRangeFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IIppIntegerRangeFactory>
    {
        IIppIntegerRangeFactory(std::nullptr_t = nullptr) noexcept {}
        IIppIntegerRangeFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIppPrintDevice :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IIppPrintDevice>
    {
        IIppPrintDevice(std::nullptr_t = nullptr) noexcept {}
        IIppPrintDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIppPrintDevice2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IIppPrintDevice2>
    {
        IIppPrintDevice2(std::nullptr_t = nullptr) noexcept {}
        IIppPrintDevice2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIppPrintDeviceStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IIppPrintDeviceStatics>
    {
        IIppPrintDeviceStatics(std::nullptr_t = nullptr) noexcept {}
        IIppPrintDeviceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIppResolution :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IIppResolution>
    {
        IIppResolution(std::nullptr_t = nullptr) noexcept {}
        IIppResolution(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIppResolutionFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IIppResolutionFactory>
    {
        IIppResolutionFactory(std::nullptr_t = nullptr) noexcept {}
        IIppResolutionFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIppSetAttributesResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IIppSetAttributesResult>
    {
        IIppSetAttributesResult(std::nullptr_t = nullptr) noexcept {}
        IIppSetAttributesResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIppTextWithLanguage :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IIppTextWithLanguage>
    {
        IIppTextWithLanguage(std::nullptr_t = nullptr) noexcept {}
        IIppTextWithLanguage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIppTextWithLanguageFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IIppTextWithLanguageFactory>
    {
        IIppTextWithLanguageFactory(std::nullptr_t = nullptr) noexcept {}
        IIppTextWithLanguageFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPageConfigurationSettings :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPageConfigurationSettings>
    {
        IPageConfigurationSettings(std::nullptr_t = nullptr) noexcept {}
        IPageConfigurationSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPdlPassthroughProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPdlPassthroughProvider>
    {
        IPdlPassthroughProvider(std::nullptr_t = nullptr) noexcept {}
        IPdlPassthroughProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPdlPassthroughTarget :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPdlPassthroughTarget>
    {
        IPdlPassthroughTarget(std::nullptr_t = nullptr) noexcept {}
        IPdlPassthroughTarget(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrint3DDevice :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrint3DDevice>
    {
        IPrint3DDevice(std::nullptr_t = nullptr) noexcept {}
        IPrint3DDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrint3DDeviceStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrint3DDeviceStatics>
    {
        IPrint3DDeviceStatics(std::nullptr_t = nullptr) noexcept {}
        IPrint3DDeviceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintSchema :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintSchema>
    {
        IPrintSchema(std::nullptr_t = nullptr) noexcept {}
        IPrintSchema(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
