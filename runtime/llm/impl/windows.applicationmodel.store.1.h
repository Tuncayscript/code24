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
#ifndef LLM_OS_ApplicationModel_Store_1_H
#define LLM_OS_ApplicationModel_Store_1_H
#include "llm/impl/Windows.ApplicationModel.Store.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Store
{
    struct __declspec(empty_bases) ICurrentApp :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICurrentApp>
    {
        ICurrentApp(std::nullptr_t = nullptr) noexcept {}
        ICurrentApp(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICurrentApp2Statics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICurrentApp2Statics>
    {
        ICurrentApp2Statics(std::nullptr_t = nullptr) noexcept {}
        ICurrentApp2Statics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICurrentAppSimulator :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICurrentAppSimulator>
    {
        ICurrentAppSimulator(std::nullptr_t = nullptr) noexcept {}
        ICurrentAppSimulator(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICurrentAppSimulatorStaticsWithFiltering :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICurrentAppSimulatorStaticsWithFiltering>
    {
        ICurrentAppSimulatorStaticsWithFiltering(std::nullptr_t = nullptr) noexcept {}
        ICurrentAppSimulatorStaticsWithFiltering(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICurrentAppSimulatorWithCampaignId :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICurrentAppSimulatorWithCampaignId>
    {
        ICurrentAppSimulatorWithCampaignId(std::nullptr_t = nullptr) noexcept {}
        ICurrentAppSimulatorWithCampaignId(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICurrentAppSimulatorWithConsumables :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICurrentAppSimulatorWithConsumables>
    {
        ICurrentAppSimulatorWithConsumables(std::nullptr_t = nullptr) noexcept {}
        ICurrentAppSimulatorWithConsumables(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICurrentAppStaticsWithFiltering :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICurrentAppStaticsWithFiltering>
    {
        ICurrentAppStaticsWithFiltering(std::nullptr_t = nullptr) noexcept {}
        ICurrentAppStaticsWithFiltering(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICurrentAppWithCampaignId :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICurrentAppWithCampaignId>
    {
        ICurrentAppWithCampaignId(std::nullptr_t = nullptr) noexcept {}
        ICurrentAppWithCampaignId(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICurrentAppWithConsumables :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICurrentAppWithConsumables>
    {
        ICurrentAppWithConsumables(std::nullptr_t = nullptr) noexcept {}
        ICurrentAppWithConsumables(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILicenseInformation :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILicenseInformation>
    {
        ILicenseInformation(std::nullptr_t = nullptr) noexcept {}
        ILicenseInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IListingInformation :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IListingInformation>
    {
        IListingInformation(std::nullptr_t = nullptr) noexcept {}
        IListingInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IListingInformation2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IListingInformation2>
    {
        IListingInformation2(std::nullptr_t = nullptr) noexcept {}
        IListingInformation2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProductLicense :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IProductLicense>
    {
        IProductLicense(std::nullptr_t = nullptr) noexcept {}
        IProductLicense(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProductLicenseWithFulfillment :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IProductLicenseWithFulfillment>,
        impl::require<llm::OS::ApplicationModel::Store::IProductLicenseWithFulfillment, llm::OS::ApplicationModel::Store::IProductLicense>
    {
        IProductLicenseWithFulfillment(std::nullptr_t = nullptr) noexcept {}
        IProductLicenseWithFulfillment(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProductListing :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IProductListing>
    {
        IProductListing(std::nullptr_t = nullptr) noexcept {}
        IProductListing(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProductListing2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IProductListing2>
    {
        IProductListing2(std::nullptr_t = nullptr) noexcept {}
        IProductListing2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProductListingWithConsumables :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IProductListingWithConsumables>
    {
        IProductListingWithConsumables(std::nullptr_t = nullptr) noexcept {}
        IProductListingWithConsumables(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProductListingWithMetadata :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IProductListingWithMetadata>,
        impl::require<llm::OS::ApplicationModel::Store::IProductListingWithMetadata, llm::OS::ApplicationModel::Store::IProductListing>
    {
        IProductListingWithMetadata(std::nullptr_t = nullptr) noexcept {}
        IProductListingWithMetadata(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProductPurchaseDisplayProperties :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IProductPurchaseDisplayProperties>
    {
        IProductPurchaseDisplayProperties(std::nullptr_t = nullptr) noexcept {}
        IProductPurchaseDisplayProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProductPurchaseDisplayPropertiesFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IProductPurchaseDisplayPropertiesFactory>
    {
        IProductPurchaseDisplayPropertiesFactory(std::nullptr_t = nullptr) noexcept {}
        IProductPurchaseDisplayPropertiesFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPurchaseResults :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPurchaseResults>
    {
        IPurchaseResults(std::nullptr_t = nullptr) noexcept {}
        IPurchaseResults(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUnfulfilledConsumable :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUnfulfilledConsumable>
    {
        IUnfulfilledConsumable(std::nullptr_t = nullptr) noexcept {}
        IUnfulfilledConsumable(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
