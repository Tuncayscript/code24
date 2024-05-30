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
#ifndef LLM_OS_Services_Store_1_H
#define LLM_OS_Services_Store_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Services.Store.0.h"
LLM_EXPORT namespace llm:OS::Services::Store
{
    struct __declspec(empty_bases) IStoreAcquireLicenseResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStoreAcquireLicenseResult>
    {
        IStoreAcquireLicenseResult(std::nullptr_t = nullptr) noexcept {}
        IStoreAcquireLicenseResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreAppLicense :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStoreAppLicense>
    {
        IStoreAppLicense(std::nullptr_t = nullptr) noexcept {}
        IStoreAppLicense(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreAppLicense2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStoreAppLicense2>
    {
        IStoreAppLicense2(std::nullptr_t = nullptr) noexcept {}
        IStoreAppLicense2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreAvailability :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStoreAvailability>
    {
        IStoreAvailability(std::nullptr_t = nullptr) noexcept {}
        IStoreAvailability(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreCanAcquireLicenseResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStoreCanAcquireLicenseResult>
    {
        IStoreCanAcquireLicenseResult(std::nullptr_t = nullptr) noexcept {}
        IStoreCanAcquireLicenseResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreCollectionData :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStoreCollectionData>
    {
        IStoreCollectionData(std::nullptr_t = nullptr) noexcept {}
        IStoreCollectionData(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreConsumableResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStoreConsumableResult>
    {
        IStoreConsumableResult(std::nullptr_t = nullptr) noexcept {}
        IStoreConsumableResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreContext :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStoreContext>
    {
        IStoreContext(std::nullptr_t = nullptr) noexcept {}
        IStoreContext(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreContext2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStoreContext2>
    {
        IStoreContext2(std::nullptr_t = nullptr) noexcept {}
        IStoreContext2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreContext3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStoreContext3>
    {
        IStoreContext3(std::nullptr_t = nullptr) noexcept {}
        IStoreContext3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreContext4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStoreContext4>
    {
        IStoreContext4(std::nullptr_t = nullptr) noexcept {}
        IStoreContext4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreContext5 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStoreContext5>
    {
        IStoreContext5(std::nullptr_t = nullptr) noexcept {}
        IStoreContext5(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreContextStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStoreContextStatics>
    {
        IStoreContextStatics(std::nullptr_t = nullptr) noexcept {}
        IStoreContextStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreImage :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStoreImage>
    {
        IStoreImage(std::nullptr_t = nullptr) noexcept {}
        IStoreImage(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreLicense :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStoreLicense>
    {
        IStoreLicense(std::nullptr_t = nullptr) noexcept {}
        IStoreLicense(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorePackageInstallOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorePackageInstallOptions>
    {
        IStorePackageInstallOptions(std::nullptr_t = nullptr) noexcept {}
        IStorePackageInstallOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorePackageLicense :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorePackageLicense>,
        impl::require<llm:OS::Services::Store::IStorePackageLicense, llm:OS::Foundation::IClosable>
    {
        IStorePackageLicense(std::nullptr_t = nullptr) noexcept {}
        IStorePackageLicense(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorePackageUpdate :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorePackageUpdate>
    {
        IStorePackageUpdate(std::nullptr_t = nullptr) noexcept {}
        IStorePackageUpdate(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorePackageUpdateResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorePackageUpdateResult>
    {
        IStorePackageUpdateResult(std::nullptr_t = nullptr) noexcept {}
        IStorePackageUpdateResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorePackageUpdateResult2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorePackageUpdateResult2>
    {
        IStorePackageUpdateResult2(std::nullptr_t = nullptr) noexcept {}
        IStorePackageUpdateResult2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorePrice :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorePrice>
    {
        IStorePrice(std::nullptr_t = nullptr) noexcept {}
        IStorePrice(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorePrice2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorePrice2>
    {
        IStorePrice2(std::nullptr_t = nullptr) noexcept {}
        IStorePrice2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreProduct :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStoreProduct>
    {
        IStoreProduct(std::nullptr_t = nullptr) noexcept {}
        IStoreProduct(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreProductOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStoreProductOptions>
    {
        IStoreProductOptions(std::nullptr_t = nullptr) noexcept {}
        IStoreProductOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreProductPagedQueryResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStoreProductPagedQueryResult>
    {
        IStoreProductPagedQueryResult(std::nullptr_t = nullptr) noexcept {}
        IStoreProductPagedQueryResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreProductQueryResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStoreProductQueryResult>
    {
        IStoreProductQueryResult(std::nullptr_t = nullptr) noexcept {}
        IStoreProductQueryResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreProductResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStoreProductResult>
    {
        IStoreProductResult(std::nullptr_t = nullptr) noexcept {}
        IStoreProductResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorePurchaseProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorePurchaseProperties>
    {
        IStorePurchaseProperties(std::nullptr_t = nullptr) noexcept {}
        IStorePurchaseProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorePurchasePropertiesFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorePurchasePropertiesFactory>
    {
        IStorePurchasePropertiesFactory(std::nullptr_t = nullptr) noexcept {}
        IStorePurchasePropertiesFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorePurchaseResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorePurchaseResult>
    {
        IStorePurchaseResult(std::nullptr_t = nullptr) noexcept {}
        IStorePurchaseResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreQueueItem :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStoreQueueItem>
    {
        IStoreQueueItem(std::nullptr_t = nullptr) noexcept {}
        IStoreQueueItem(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreQueueItem2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStoreQueueItem2>
    {
        IStoreQueueItem2(std::nullptr_t = nullptr) noexcept {}
        IStoreQueueItem2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreQueueItemCompletedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStoreQueueItemCompletedEventArgs>
    {
        IStoreQueueItemCompletedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IStoreQueueItemCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreQueueItemStatus :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStoreQueueItemStatus>
    {
        IStoreQueueItemStatus(std::nullptr_t = nullptr) noexcept {}
        IStoreQueueItemStatus(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreRateAndReviewResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStoreRateAndReviewResult>
    {
        IStoreRateAndReviewResult(std::nullptr_t = nullptr) noexcept {}
        IStoreRateAndReviewResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreRequestHelperStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStoreRequestHelperStatics>
    {
        IStoreRequestHelperStatics(std::nullptr_t = nullptr) noexcept {}
        IStoreRequestHelperStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreSendRequestResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStoreSendRequestResult>
    {
        IStoreSendRequestResult(std::nullptr_t = nullptr) noexcept {}
        IStoreSendRequestResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreSendRequestResult2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStoreSendRequestResult2>
    {
        IStoreSendRequestResult2(std::nullptr_t = nullptr) noexcept {}
        IStoreSendRequestResult2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreSku :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStoreSku>
    {
        IStoreSku(std::nullptr_t = nullptr) noexcept {}
        IStoreSku(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreSubscriptionInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStoreSubscriptionInfo>
    {
        IStoreSubscriptionInfo(std::nullptr_t = nullptr) noexcept {}
        IStoreSubscriptionInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreUninstallStorePackageResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStoreUninstallStorePackageResult>
    {
        IStoreUninstallStorePackageResult(std::nullptr_t = nullptr) noexcept {}
        IStoreUninstallStorePackageResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStoreVideo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStoreVideo>
    {
        IStoreVideo(std::nullptr_t = nullptr) noexcept {}
        IStoreVideo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
