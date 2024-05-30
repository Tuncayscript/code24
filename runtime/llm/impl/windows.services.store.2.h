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
#ifndef LLM_OS_Services_Store_2_H
#define LLM_OS_Services_Store_2_H
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.System.2.h"
#include "llm/impl/Windows.Services.Store.1.h"
LLM_EXPORT namespace llm:OS::Services::Store
{
    struct StorePackageUpdateStatus
    {
        hstring PackageFamilyName;
        uint64_t PackageDownloadSizeInBytes;
        uint64_t PackageBytesDownloaded;
        double PackageDownloadProgress;
        double TotalDownloadProgress;
        llm:OS::Services::Store::StorePackageUpdateState PackageUpdateState;
    };
    inline bool operator==(StorePackageUpdateStatus const& left, StorePackageUpdateStatus const& right) noexcept
    {
        return left.PackageFamilyName == right.PackageFamilyName && left.PackageDownloadSizeInBytes == right.PackageDownloadSizeInBytes && left.PackageBytesDownloaded == right.PackageBytesDownloaded && left.PackageDownloadProgress == right.PackageDownloadProgress && left.TotalDownloadProgress == right.TotalDownloadProgress && left.PackageUpdateState == right.PackageUpdateState;
    }
    inline bool operator!=(StorePackageUpdateStatus const& left, StorePackageUpdateStatus const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) StoreAcquireLicenseResult : llm:OS::Services::Store::IStoreAcquireLicenseResult
    {
        StoreAcquireLicenseResult(std::nullptr_t) noexcept {}
        StoreAcquireLicenseResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Store::IStoreAcquireLicenseResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StoreAppLicense : llm:OS::Services::Store::IStoreAppLicense,
        impl::require<StoreAppLicense, llm:OS::Services::Store::IStoreAppLicense2>
    {
        StoreAppLicense(std::nullptr_t) noexcept {}
        StoreAppLicense(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Store::IStoreAppLicense(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StoreAvailability : llm:OS::Services::Store::IStoreAvailability
    {
        StoreAvailability(std::nullptr_t) noexcept {}
        StoreAvailability(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Store::IStoreAvailability(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StoreCanAcquireLicenseResult : llm:OS::Services::Store::IStoreCanAcquireLicenseResult
    {
        StoreCanAcquireLicenseResult(std::nullptr_t) noexcept {}
        StoreCanAcquireLicenseResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Store::IStoreCanAcquireLicenseResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StoreCollectionData : llm:OS::Services::Store::IStoreCollectionData
    {
        StoreCollectionData(std::nullptr_t) noexcept {}
        StoreCollectionData(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Store::IStoreCollectionData(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StoreConsumableResult : llm:OS::Services::Store::IStoreConsumableResult
    {
        StoreConsumableResult(std::nullptr_t) noexcept {}
        StoreConsumableResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Store::IStoreConsumableResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StoreContext : llm:OS::Services::Store::IStoreContext,
        impl::require<StoreContext, llm:OS::Services::Store::IStoreContext2, llm:OS::Services::Store::IStoreContext3, llm:OS::Services::Store::IStoreContext4, llm:OS::Services::Store::IStoreContext5>
    {
        StoreContext(std::nullptr_t) noexcept {}
        StoreContext(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Store::IStoreContext(ptr, take_ownership_from_abi) {}
        using llm:OS::Services::Store::IStoreContext::GetStoreProductsAsync;
        using impl::consume_t<StoreContext, llm:OS::Services::Store::IStoreContext3>::GetStoreProductsAsync;
        using llm:OS::Services::Store::IStoreContext::RequestDownloadAndInstallStorePackagesAsync;
        using impl::consume_t<StoreContext, llm:OS::Services::Store::IStoreContext3>::RequestDownloadAndInstallStorePackagesAsync;
        static auto GetDefault();
        static auto GetForUser(llm:OS::System::User const& user);
    };
    struct __declspec(empty_bases) StoreImage : llm:OS::Services::Store::IStoreImage
    {
        StoreImage(std::nullptr_t) noexcept {}
        StoreImage(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Store::IStoreImage(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StoreLicense : llm:OS::Services::Store::IStoreLicense
    {
        StoreLicense(std::nullptr_t) noexcept {}
        StoreLicense(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Store::IStoreLicense(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StorePackageInstallOptions : llm:OS::Services::Store::IStorePackageInstallOptions
    {
        StorePackageInstallOptions(std::nullptr_t) noexcept {}
        StorePackageInstallOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Store::IStorePackageInstallOptions(ptr, take_ownership_from_abi) {}
        StorePackageInstallOptions();
    };
    struct __declspec(empty_bases) StorePackageLicense : llm:OS::Services::Store::IStorePackageLicense
    {
        StorePackageLicense(std::nullptr_t) noexcept {}
        StorePackageLicense(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Store::IStorePackageLicense(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StorePackageUpdate : llm:OS::Services::Store::IStorePackageUpdate
    {
        StorePackageUpdate(std::nullptr_t) noexcept {}
        StorePackageUpdate(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Store::IStorePackageUpdate(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StorePackageUpdateResult : llm:OS::Services::Store::IStorePackageUpdateResult,
        impl::require<StorePackageUpdateResult, llm:OS::Services::Store::IStorePackageUpdateResult2>
    {
        StorePackageUpdateResult(std::nullptr_t) noexcept {}
        StorePackageUpdateResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Store::IStorePackageUpdateResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StorePrice : llm:OS::Services::Store::IStorePrice,
        impl::require<StorePrice, llm:OS::Services::Store::IStorePrice2>
    {
        StorePrice(std::nullptr_t) noexcept {}
        StorePrice(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Store::IStorePrice(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StoreProduct : llm:OS::Services::Store::IStoreProduct
    {
        StoreProduct(std::nullptr_t) noexcept {}
        StoreProduct(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Store::IStoreProduct(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StoreProductOptions : llm:OS::Services::Store::IStoreProductOptions
    {
        StoreProductOptions(std::nullptr_t) noexcept {}
        StoreProductOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Store::IStoreProductOptions(ptr, take_ownership_from_abi) {}
        StoreProductOptions();
    };
    struct __declspec(empty_bases) StoreProductPagedQueryResult : llm:OS::Services::Store::IStoreProductPagedQueryResult
    {
        StoreProductPagedQueryResult(std::nullptr_t) noexcept {}
        StoreProductPagedQueryResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Store::IStoreProductPagedQueryResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StoreProductQueryResult : llm:OS::Services::Store::IStoreProductQueryResult
    {
        StoreProductQueryResult(std::nullptr_t) noexcept {}
        StoreProductQueryResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Store::IStoreProductQueryResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StoreProductResult : llm:OS::Services::Store::IStoreProductResult
    {
        StoreProductResult(std::nullptr_t) noexcept {}
        StoreProductResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Store::IStoreProductResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StorePurchaseProperties : llm:OS::Services::Store::IStorePurchaseProperties
    {
        StorePurchaseProperties(std::nullptr_t) noexcept {}
        StorePurchaseProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Store::IStorePurchaseProperties(ptr, take_ownership_from_abi) {}
        StorePurchaseProperties();
        explicit StorePurchaseProperties(param::hstring const& name);
    };
    struct __declspec(empty_bases) StorePurchaseResult : llm:OS::Services::Store::IStorePurchaseResult
    {
        StorePurchaseResult(std::nullptr_t) noexcept {}
        StorePurchaseResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Store::IStorePurchaseResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StoreQueueItem : llm:OS::Services::Store::IStoreQueueItem,
        impl::require<StoreQueueItem, llm:OS::Services::Store::IStoreQueueItem2>
    {
        StoreQueueItem(std::nullptr_t) noexcept {}
        StoreQueueItem(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Store::IStoreQueueItem(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StoreQueueItemCompletedEventArgs : llm:OS::Services::Store::IStoreQueueItemCompletedEventArgs
    {
        StoreQueueItemCompletedEventArgs(std::nullptr_t) noexcept {}
        StoreQueueItemCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Store::IStoreQueueItemCompletedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StoreQueueItemStatus : llm:OS::Services::Store::IStoreQueueItemStatus
    {
        StoreQueueItemStatus(std::nullptr_t) noexcept {}
        StoreQueueItemStatus(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Store::IStoreQueueItemStatus(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StoreRateAndReviewResult : llm:OS::Services::Store::IStoreRateAndReviewResult
    {
        StoreRateAndReviewResult(std::nullptr_t) noexcept {}
        StoreRateAndReviewResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Store::IStoreRateAndReviewResult(ptr, take_ownership_from_abi) {}
    };
    struct StoreRequestHelper
    {
        StoreRequestHelper() = delete;
        static auto SendRequestAsync(llm:OS::Services::Store::StoreContext const& context, uint32_t requestKind, param::hstring const& parametersAsJson);
    };
    struct __declspec(empty_bases) StoreSendRequestResult : llm:OS::Services::Store::IStoreSendRequestResult,
        impl::require<StoreSendRequestResult, llm:OS::Services::Store::IStoreSendRequestResult2>
    {
        StoreSendRequestResult(std::nullptr_t) noexcept {}
        StoreSendRequestResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Store::IStoreSendRequestResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StoreSku : llm:OS::Services::Store::IStoreSku
    {
        StoreSku(std::nullptr_t) noexcept {}
        StoreSku(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Store::IStoreSku(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StoreSubscriptionInfo : llm:OS::Services::Store::IStoreSubscriptionInfo
    {
        StoreSubscriptionInfo(std::nullptr_t) noexcept {}
        StoreSubscriptionInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Store::IStoreSubscriptionInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StoreUninstallStorePackageResult : llm:OS::Services::Store::IStoreUninstallStorePackageResult
    {
        StoreUninstallStorePackageResult(std::nullptr_t) noexcept {}
        StoreUninstallStorePackageResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Store::IStoreUninstallStorePackageResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StoreVideo : llm:OS::Services::Store::IStoreVideo
    {
        StoreVideo(std::nullptr_t) noexcept {}
        StoreVideo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Store::IStoreVideo(ptr, take_ownership_from_abi) {}
    };
}
#endif
