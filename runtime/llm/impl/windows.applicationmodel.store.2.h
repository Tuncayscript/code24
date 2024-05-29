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
#ifndef LLM_OS_ApplicationModel_Store_2_H
#define LLM_OS_ApplicationModel_Store_2_H
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Storage.1.h"
#include "llm/impl/Windows.ApplicationModel.Store.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Store
{
    struct LicenseChangedEventHandler : llm::OS::Foundation::IUnknown
    {
        LicenseChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
        LicenseChangedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> LicenseChangedEventHandler(L lambda);
        template <typename F> LicenseChangedEventHandler(F* function);
        template <typename O, typename M> LicenseChangedEventHandler(O* object, M method);
        template <typename O, typename M> LicenseChangedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> LicenseChangedEventHandler(weak_ref<O>&& object, M method);
        auto operator()() const;
    };
    struct CurrentApp
    {
        CurrentApp() = delete;
        [[nodiscard]] static auto LicenseInformation();
        [[nodiscard]] static auto LinkUri();
        [[nodiscard]] static auto AppId();
        static auto RequestAppPurchaseAsync(bool includeReceipt);
        static auto RequestProductPurchaseAsync(param::hstring const& productId, bool includeReceipt);
        static auto LoadListingInformationAsync();
        static auto GetAppReceiptAsync();
        static auto GetProductReceiptAsync(param::hstring const& productId);
        static auto GetCustomerPurchaseIdAsync(param::hstring const& serviceTicket, param::hstring const& publisherUserId);
        static auto GetCustomerCollectionsIdAsync(param::hstring const& serviceTicket, param::hstring const& publisherUserId);
        static auto LoadListingInformationByProductIdsAsync(param::async_iterable<hstring> const& productIds);
        static auto LoadListingInformationByKeywordsAsync(param::async_iterable<hstring> const& keywords);
        static auto ReportProductFulfillment(param::hstring const& productId);
        static auto GetAppPurchaseCampaignIdAsync();
        static auto ReportConsumableFulfillmentAsync(param::hstring const& productId, llm::guid const& transactionId);
        static auto RequestProductPurchaseAsync(param::hstring const& productId);
        static auto RequestProductPurchaseAsync(param::hstring const& productId, param::hstring const& offerId, llm::OS::ApplicationModel::Store::ProductPurchaseDisplayProperties const& displayProperties);
        static auto GetUnfulfilledConsumablesAsync();
    };
    struct CurrentAppSimulator
    {
        CurrentAppSimulator() = delete;
        [[nodiscard]] static auto LicenseInformation();
        [[nodiscard]] static auto LinkUri();
        [[nodiscard]] static auto AppId();
        static auto RequestAppPurchaseAsync(bool includeReceipt);
        static auto RequestProductPurchaseAsync(param::hstring const& productId, bool includeReceipt);
        static auto LoadListingInformationAsync();
        static auto GetAppReceiptAsync();
        static auto GetProductReceiptAsync(param::hstring const& productId);
        static auto ReloadSimulatorAsync(llm::OS::Storage::StorageFile const& simulatorSettingsFile);
        static auto LoadListingInformationByProductIdsAsync(param::async_iterable<hstring> const& productIds);
        static auto LoadListingInformationByKeywordsAsync(param::async_iterable<hstring> const& keywords);
        static auto GetAppPurchaseCampaignIdAsync();
        static auto ReportConsumableFulfillmentAsync(param::hstring const& productId, llm::guid const& transactionId);
        static auto RequestProductPurchaseAsync(param::hstring const& productId);
        static auto RequestProductPurchaseAsync(param::hstring const& productId, param::hstring const& offerId, llm::OS::ApplicationModel::Store::ProductPurchaseDisplayProperties const& displayProperties);
        static auto GetUnfulfilledConsumablesAsync();
    };
    struct __declspec(empty_bases) LicenseInformation : llm::OS::ApplicationModel::Store::ILicenseInformation
    {
        LicenseInformation(std::nullptr_t) noexcept {}
        LicenseInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Store::ILicenseInformation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ListingInformation : llm::OS::ApplicationModel::Store::IListingInformation,
        impl::require<ListingInformation, llm::OS::ApplicationModel::Store::IListingInformation2>
    {
        ListingInformation(std::nullptr_t) noexcept {}
        ListingInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Store::IListingInformation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ProductLicense : llm::OS::ApplicationModel::Store::IProductLicense,
        impl::require<ProductLicense, llm::OS::ApplicationModel::Store::IProductLicenseWithFulfillment>
    {
        ProductLicense(std::nullptr_t) noexcept {}
        ProductLicense(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Store::IProductLicense(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ProductListing : llm::OS::ApplicationModel::Store::IProductListing,
        impl::require<ProductListing, llm::OS::ApplicationModel::Store::IProductListingWithMetadata, llm::OS::ApplicationModel::Store::IProductListing2>
    {
        ProductListing(std::nullptr_t) noexcept {}
        ProductListing(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Store::IProductListing(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ProductPurchaseDisplayProperties : llm::OS::ApplicationModel::Store::IProductPurchaseDisplayProperties
    {
        ProductPurchaseDisplayProperties(std::nullptr_t) noexcept {}
        ProductPurchaseDisplayProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Store::IProductPurchaseDisplayProperties(ptr, take_ownership_from_abi) {}
        ProductPurchaseDisplayProperties();
        explicit ProductPurchaseDisplayProperties(param::hstring const& name);
    };
    struct __declspec(empty_bases) PurchaseResults : llm::OS::ApplicationModel::Store::IPurchaseResults
    {
        PurchaseResults(std::nullptr_t) noexcept {}
        PurchaseResults(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Store::IPurchaseResults(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UnfulfilledConsumable : llm::OS::ApplicationModel::Store::IUnfulfilledConsumable
    {
        UnfulfilledConsumable(std::nullptr_t) noexcept {}
        UnfulfilledConsumable(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Store::IUnfulfilledConsumable(ptr, take_ownership_from_abi) {}
    };
}
#endif
