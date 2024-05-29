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
#ifndef LLM_OS_ApplicationModel_Store_Preview_1_H
#define LLM_OS_ApplicationModel_Store_Preview_1_H
#include "llm/impl/Windows.ApplicationModel.Store.Preview.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Store::Preview
{
    struct __declspec(empty_bases) IDeliveryOptimizationSettings :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeliveryOptimizationSettings>
    {
        IDeliveryOptimizationSettings(std::nullptr_t = nullptr) noexcept {}
        IDeliveryOptimizationSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeliveryOptimizationSettingsStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeliveryOptimizationSettingsStatics>
    {
        IDeliveryOptimizationSettingsStatics(std::nullptr_t = nullptr) noexcept {}
        IDeliveryOptimizationSettingsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreConfigurationStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IStoreConfigurationStatics>
    {
        IStoreConfigurationStatics(std::nullptr_t = nullptr) noexcept {}
        IStoreConfigurationStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreConfigurationStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IStoreConfigurationStatics2>
    {
        IStoreConfigurationStatics2(std::nullptr_t = nullptr) noexcept {}
        IStoreConfigurationStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreConfigurationStatics3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IStoreConfigurationStatics3>
    {
        IStoreConfigurationStatics3(std::nullptr_t = nullptr) noexcept {}
        IStoreConfigurationStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreConfigurationStatics4 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IStoreConfigurationStatics4>
    {
        IStoreConfigurationStatics4(std::nullptr_t = nullptr) noexcept {}
        IStoreConfigurationStatics4(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreConfigurationStatics5 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IStoreConfigurationStatics5>
    {
        IStoreConfigurationStatics5(std::nullptr_t = nullptr) noexcept {}
        IStoreConfigurationStatics5(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreHardwareManufacturerInfo :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IStoreHardwareManufacturerInfo>
    {
        IStoreHardwareManufacturerInfo(std::nullptr_t = nullptr) noexcept {}
        IStoreHardwareManufacturerInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorePreview :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IStorePreview>
    {
        IStorePreview(std::nullptr_t = nullptr) noexcept {}
        IStorePreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorePreviewProductInfo :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IStorePreviewProductInfo>
    {
        IStorePreviewProductInfo(std::nullptr_t = nullptr) noexcept {}
        IStorePreviewProductInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorePreviewPurchaseResults :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IStorePreviewPurchaseResults>
    {
        IStorePreviewPurchaseResults(std::nullptr_t = nullptr) noexcept {}
        IStorePreviewPurchaseResults(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorePreviewSkuInfo :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IStorePreviewSkuInfo>
    {
        IStorePreviewSkuInfo(std::nullptr_t = nullptr) noexcept {}
        IStorePreviewSkuInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAuthenticationCoreManagerHelper :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebAuthenticationCoreManagerHelper>
    {
        IWebAuthenticationCoreManagerHelper(std::nullptr_t = nullptr) noexcept {}
        IWebAuthenticationCoreManagerHelper(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
