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
#ifndef LLM_OS_Services_Store_H
#define LLM_OS_Services_Store_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/impl/Windows.ApplicationModel.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.System.2.h"
#include "llm/impl/Windows.Web.Http.2.h"
#include "llm/impl/Windows.Services.Store.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Store::StorePackageLicense) consume_Windows_Services_Store_IStoreAcquireLicenseResult<D>::StorePackageLicense() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreAcquireLicenseResult)->get_StorePackageLicense(&value));
        return llm::OS::Services::Store::StorePackageLicense{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Services_Store_IStoreAcquireLicenseResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreAcquireLicenseResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreAppLicense<D>::SkuStoreId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreAppLicense)->get_SkuStoreId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Services_Store_IStoreAppLicense<D>::IsActive() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreAppLicense)->get_IsActive(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Services_Store_IStoreAppLicense<D>::IsTrial() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreAppLicense)->get_IsTrial(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Services_Store_IStoreAppLicense<D>::ExpirationDate() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreAppLicense)->get_ExpirationDate(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreAppLicense<D>::ExtendedJsonData() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreAppLicense)->get_ExtendedJsonData(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Services::Store::StoreLicense>) consume_Windows_Services_Store_IStoreAppLicense<D>::AddOnLicenses() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreAppLicense)->get_AddOnLicenses(&value));
        return llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Services::Store::StoreLicense>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Services_Store_IStoreAppLicense<D>::TrialTimeRemaining() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreAppLicense)->get_TrialTimeRemaining(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Services_Store_IStoreAppLicense<D>::IsTrialOwnedByThisUser() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreAppLicense)->get_IsTrialOwnedByThisUser(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreAppLicense<D>::TrialUniqueId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreAppLicense)->get_TrialUniqueId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Services_Store_IStoreAppLicense2<D>::IsDiscLicense() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreAppLicense2)->get_IsDiscLicense(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreAvailability<D>::StoreId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreAvailability)->get_StoreId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Services_Store_IStoreAvailability<D>::EndDate() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreAvailability)->get_EndDate(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Store::StorePrice) consume_Windows_Services_Store_IStoreAvailability<D>::Price() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreAvailability)->get_Price(&value));
        return llm::OS::Services::Store::StorePrice{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreAvailability<D>::ExtendedJsonData() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreAvailability)->get_ExtendedJsonData(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StorePurchaseResult>) consume_Windows_Services_Store_IStoreAvailability<D>::RequestPurchaseAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreAvailability)->RequestPurchaseAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StorePurchaseResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StorePurchaseResult>) consume_Windows_Services_Store_IStoreAvailability<D>::RequestPurchaseAsync(llm::OS::Services::Store::StorePurchaseProperties const& storePurchaseProperties) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreAvailability)->RequestPurchaseWithPurchasePropertiesAsync(*(void**)(&storePurchaseProperties), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StorePurchaseResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Services_Store_IStoreCanAcquireLicenseResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreCanAcquireLicenseResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreCanAcquireLicenseResult<D>::LicensableSku() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreCanAcquireLicenseResult)->get_LicensableSku(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Store::StoreCanLicenseStatus) consume_Windows_Services_Store_IStoreCanAcquireLicenseResult<D>::Status() const
    {
        llm::OS::Services::Store::StoreCanLicenseStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreCanAcquireLicenseResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Services_Store_IStoreCollectionData<D>::IsTrial() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreCollectionData)->get_IsTrial(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreCollectionData<D>::CampaignId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreCollectionData)->get_CampaignId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreCollectionData<D>::DeveloperOfferId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreCollectionData)->get_DeveloperOfferId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Services_Store_IStoreCollectionData<D>::AcquiredDate() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreCollectionData)->get_AcquiredDate(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Services_Store_IStoreCollectionData<D>::StartDate() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreCollectionData)->get_StartDate(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Services_Store_IStoreCollectionData<D>::EndDate() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreCollectionData)->get_EndDate(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Services_Store_IStoreCollectionData<D>::TrialTimeRemaining() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreCollectionData)->get_TrialTimeRemaining(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreCollectionData<D>::ExtendedJsonData() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreCollectionData)->get_ExtendedJsonData(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Store::StoreConsumableStatus) consume_Windows_Services_Store_IStoreConsumableResult<D>::Status() const
    {
        llm::OS::Services::Store::StoreConsumableStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreConsumableResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Services_Store_IStoreConsumableResult<D>::TrackingId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreConsumableResult)->get_TrackingId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Services_Store_IStoreConsumableResult<D>::BalanceRemaining() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreConsumableResult)->get_BalanceRemaining(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Services_Store_IStoreConsumableResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreConsumableResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_Services_Store_IStoreContext<D>::User() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext)->get_User(&value));
        return llm::OS::System::User{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Services_Store_IStoreContext<D>::OfflineLicensesChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Services::Store::StoreContext, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext)->add_OfflineLicensesChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Services_Store_IStoreContext<D>::OfflineLicensesChanged_revoker consume_Windows_Services_Store_IStoreContext<D>::OfflineLicensesChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Services::Store::StoreContext, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, OfflineLicensesChanged_revoker>(this, OfflineLicensesChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Services_Store_IStoreContext<D>::OfflineLicensesChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext)->remove_OfflineLicensesChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<hstring>) consume_Windows_Services_Store_IStoreContext<D>::GetCustomerPurchaseIdAsync(param::hstring const& serviceTicket, param::hstring const& publisherUserId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext)->GetCustomerPurchaseIdAsync(*(void**)(&serviceTicket), *(void**)(&publisherUserId), &operation));
        return llm::OS::Foundation::IAsyncOperation<hstring>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<hstring>) consume_Windows_Services_Store_IStoreContext<D>::GetCustomerCollectionsIdAsync(param::hstring const& serviceTicket, param::hstring const& publisherUserId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext)->GetCustomerCollectionsIdAsync(*(void**)(&serviceTicket), *(void**)(&publisherUserId), &operation));
        return llm::OS::Foundation::IAsyncOperation<hstring>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreAppLicense>) consume_Windows_Services_Store_IStoreContext<D>::GetAppLicenseAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext)->GetAppLicenseAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreAppLicense>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductResult>) consume_Windows_Services_Store_IStoreContext<D>::GetStoreProductForCurrentAppAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext)->GetStoreProductForCurrentAppAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductQueryResult>) consume_Windows_Services_Store_IStoreContext<D>::GetStoreProductsAsync(param::async_iterable<hstring> const& productKinds, param::async_iterable<hstring> const& storeIds) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext)->GetStoreProductsAsync(*(void**)(&productKinds), *(void**)(&storeIds), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductQueryResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductQueryResult>) consume_Windows_Services_Store_IStoreContext<D>::GetAssociatedStoreProductsAsync(param::async_iterable<hstring> const& productKinds) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext)->GetAssociatedStoreProductsAsync(*(void**)(&productKinds), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductQueryResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductPagedQueryResult>) consume_Windows_Services_Store_IStoreContext<D>::GetAssociatedStoreProductsWithPagingAsync(param::async_iterable<hstring> const& productKinds, uint32_t maxItemsToRetrievePerPage) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext)->GetAssociatedStoreProductsWithPagingAsync(*(void**)(&productKinds), maxItemsToRetrievePerPage, &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductPagedQueryResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductQueryResult>) consume_Windows_Services_Store_IStoreContext<D>::GetUserCollectionAsync(param::async_iterable<hstring> const& productKinds) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext)->GetUserCollectionAsync(*(void**)(&productKinds), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductQueryResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductPagedQueryResult>) consume_Windows_Services_Store_IStoreContext<D>::GetUserCollectionWithPagingAsync(param::async_iterable<hstring> const& productKinds, uint32_t maxItemsToRetrievePerPage) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext)->GetUserCollectionWithPagingAsync(*(void**)(&productKinds), maxItemsToRetrievePerPage, &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductPagedQueryResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreConsumableResult>) consume_Windows_Services_Store_IStoreContext<D>::ReportConsumableFulfillmentAsync(param::hstring const& productStoreId, uint32_t quantity, llm::guid const& trackingId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext)->ReportConsumableFulfillmentAsync(*(void**)(&productStoreId), quantity, impl::bind_in(trackingId), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreConsumableResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreConsumableResult>) consume_Windows_Services_Store_IStoreContext<D>::GetConsumableBalanceRemainingAsync(param::hstring const& productStoreId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext)->GetConsumableBalanceRemainingAsync(*(void**)(&productStoreId), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreConsumableResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreAcquireLicenseResult>) consume_Windows_Services_Store_IStoreContext<D>::AcquireStoreLicenseForOptionalPackageAsync(llm::OS::ApplicationModel::Package const& optionalPackage) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext)->AcquireStoreLicenseForOptionalPackageAsync(*(void**)(&optionalPackage), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreAcquireLicenseResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StorePurchaseResult>) consume_Windows_Services_Store_IStoreContext<D>::RequestPurchaseAsync(param::hstring const& storeId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext)->RequestPurchaseAsync(*(void**)(&storeId), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StorePurchaseResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StorePurchaseResult>) consume_Windows_Services_Store_IStoreContext<D>::RequestPurchaseAsync(param::hstring const& storeId, llm::OS::Services::Store::StorePurchaseProperties const& storePurchaseProperties) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext)->RequestPurchaseWithPurchasePropertiesAsync(*(void**)(&storeId), *(void**)(&storePurchaseProperties), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StorePurchaseResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StorePackageUpdate>>) consume_Windows_Services_Store_IStoreContext<D>::GetAppAndOptionalStorePackageUpdatesAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext)->GetAppAndOptionalStorePackageUpdatesAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StorePackageUpdate>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Services::Store::StorePackageUpdateResult, llm::OS::Services::Store::StorePackageUpdateStatus>) consume_Windows_Services_Store_IStoreContext<D>::RequestDownloadStorePackageUpdatesAsync(param::async_iterable<llm::OS::Services::Store::StorePackageUpdate> const& storePackageUpdates) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext)->RequestDownloadStorePackageUpdatesAsync(*(void**)(&storePackageUpdates), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Services::Store::StorePackageUpdateResult, llm::OS::Services::Store::StorePackageUpdateStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Services::Store::StorePackageUpdateResult, llm::OS::Services::Store::StorePackageUpdateStatus>) consume_Windows_Services_Store_IStoreContext<D>::RequestDownloadAndInstallStorePackageUpdatesAsync(param::async_iterable<llm::OS::Services::Store::StorePackageUpdate> const& storePackageUpdates) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext)->RequestDownloadAndInstallStorePackageUpdatesAsync(*(void**)(&storePackageUpdates), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Services::Store::StorePackageUpdateResult, llm::OS::Services::Store::StorePackageUpdateStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Services::Store::StorePackageUpdateResult, llm::OS::Services::Store::StorePackageUpdateStatus>) consume_Windows_Services_Store_IStoreContext<D>::RequestDownloadAndInstallStorePackagesAsync(param::async_iterable<hstring> const& storeIds) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext)->RequestDownloadAndInstallStorePackagesAsync(*(void**)(&storeIds), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Services::Store::StorePackageUpdateResult, llm::OS::Services::Store::StorePackageUpdateStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductResult>) consume_Windows_Services_Store_IStoreContext2<D>::FindStoreProductForPackageAsync(param::async_iterable<hstring> const& productKinds, llm::OS::ApplicationModel::Package const& package) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext2)->FindStoreProductForPackageAsync(*(void**)(&productKinds), *(void**)(&package), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Services_Store_IStoreContext3<D>::CanSilentlyDownloadStorePackageUpdates() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext3)->get_CanSilentlyDownloadStorePackageUpdates(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Services::Store::StorePackageUpdateResult, llm::OS::Services::Store::StorePackageUpdateStatus>) consume_Windows_Services_Store_IStoreContext3<D>::TrySilentDownloadStorePackageUpdatesAsync(param::async_iterable<llm::OS::Services::Store::StorePackageUpdate> const& storePackageUpdates) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext3)->TrySilentDownloadStorePackageUpdatesAsync(*(void**)(&storePackageUpdates), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Services::Store::StorePackageUpdateResult, llm::OS::Services::Store::StorePackageUpdateStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Services::Store::StorePackageUpdateResult, llm::OS::Services::Store::StorePackageUpdateStatus>) consume_Windows_Services_Store_IStoreContext3<D>::TrySilentDownloadAndInstallStorePackageUpdatesAsync(param::async_iterable<llm::OS::Services::Store::StorePackageUpdate> const& storePackageUpdates) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext3)->TrySilentDownloadAndInstallStorePackageUpdatesAsync(*(void**)(&storePackageUpdates), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Services::Store::StorePackageUpdateResult, llm::OS::Services::Store::StorePackageUpdateStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreCanAcquireLicenseResult>) consume_Windows_Services_Store_IStoreContext3<D>::CanAcquireStoreLicenseForOptionalPackageAsync(llm::OS::ApplicationModel::Package const& optionalPackage) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext3)->CanAcquireStoreLicenseForOptionalPackageAsync(*(void**)(&optionalPackage), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreCanAcquireLicenseResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreCanAcquireLicenseResult>) consume_Windows_Services_Store_IStoreContext3<D>::CanAcquireStoreLicenseAsync(param::hstring const& productStoreId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext3)->CanAcquireStoreLicenseAsync(*(void**)(&productStoreId), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreCanAcquireLicenseResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductQueryResult>) consume_Windows_Services_Store_IStoreContext3<D>::GetStoreProductsAsync(param::async_iterable<hstring> const& productKinds, param::async_iterable<hstring> const& storeIds, llm::OS::Services::Store::StoreProductOptions const& storeProductOptions) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext3)->GetStoreProductsWithOptionsAsync(*(void**)(&productKinds), *(void**)(&storeIds), *(void**)(&storeProductOptions), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductQueryResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StoreQueueItem>>) consume_Windows_Services_Store_IStoreContext3<D>::GetAssociatedStoreQueueItemsAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext3)->GetAssociatedStoreQueueItemsAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StoreQueueItem>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StoreQueueItem>>) consume_Windows_Services_Store_IStoreContext3<D>::GetStoreQueueItemsAsync(param::async_iterable<hstring> const& storeIds) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext3)->GetStoreQueueItemsAsync(*(void**)(&storeIds), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StoreQueueItem>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Services::Store::StorePackageUpdateResult, llm::OS::Services::Store::StorePackageUpdateStatus>) consume_Windows_Services_Store_IStoreContext3<D>::RequestDownloadAndInstallStorePackagesAsync(param::async_iterable<hstring> const& storeIds, llm::OS::Services::Store::StorePackageInstallOptions const& storePackageInstallOptions) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext3)->RequestDownloadAndInstallStorePackagesWithInstallOptionsAsync(*(void**)(&storeIds), *(void**)(&storePackageInstallOptions), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Services::Store::StorePackageUpdateResult, llm::OS::Services::Store::StorePackageUpdateStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Services::Store::StorePackageUpdateResult, llm::OS::Services::Store::StorePackageUpdateStatus>) consume_Windows_Services_Store_IStoreContext3<D>::DownloadAndInstallStorePackagesAsync(param::async_iterable<hstring> const& storeIds) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext3)->DownloadAndInstallStorePackagesAsync(*(void**)(&storeIds), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Services::Store::StorePackageUpdateResult, llm::OS::Services::Store::StorePackageUpdateStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreUninstallStorePackageResult>) consume_Windows_Services_Store_IStoreContext3<D>::RequestUninstallStorePackageAsync(llm::OS::ApplicationModel::Package const& package) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext3)->RequestUninstallStorePackageAsync(*(void**)(&package), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreUninstallStorePackageResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreUninstallStorePackageResult>) consume_Windows_Services_Store_IStoreContext3<D>::RequestUninstallStorePackageByStoreIdAsync(param::hstring const& storeId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext3)->RequestUninstallStorePackageByStoreIdAsync(*(void**)(&storeId), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreUninstallStorePackageResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreUninstallStorePackageResult>) consume_Windows_Services_Store_IStoreContext3<D>::UninstallStorePackageAsync(llm::OS::ApplicationModel::Package const& package) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext3)->UninstallStorePackageAsync(*(void**)(&package), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreUninstallStorePackageResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreUninstallStorePackageResult>) consume_Windows_Services_Store_IStoreContext3<D>::UninstallStorePackageByStoreIdAsync(param::hstring const& storeId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext3)->UninstallStorePackageByStoreIdAsync(*(void**)(&storeId), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreUninstallStorePackageResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreRateAndReviewResult>) consume_Windows_Services_Store_IStoreContext4<D>::RequestRateAndReviewAppAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext4)->RequestRateAndReviewAppAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreRateAndReviewResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StoreQueueItem>>) consume_Windows_Services_Store_IStoreContext4<D>::SetInstallOrderForAssociatedStoreQueueItemsAsync(param::async_iterable<llm::OS::Services::Store::StoreQueueItem> const& items) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext4)->SetInstallOrderForAssociatedStoreQueueItemsAsync(*(void**)(&items), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StoreQueueItem>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductQueryResult>) consume_Windows_Services_Store_IStoreContext5<D>::GetUserPurchaseHistoryAsync(param::async_iterable<hstring> const& productKinds) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext5)->GetUserPurchaseHistoryAsync(*(void**)(&productKinds), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductQueryResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductQueryResult>) consume_Windows_Services_Store_IStoreContext5<D>::GetAssociatedStoreProductsByInAppOfferTokenAsync(param::async_iterable<hstring> const& inAppOfferTokens) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext5)->GetAssociatedStoreProductsByInAppOfferTokenAsync(*(void**)(&inAppOfferTokens), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductQueryResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StorePurchaseResult>) consume_Windows_Services_Store_IStoreContext5<D>::RequestPurchaseByInAppOfferTokenAsync(param::hstring const& inAppOfferToken) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContext5)->RequestPurchaseByInAppOfferTokenAsync(*(void**)(&inAppOfferToken), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StorePurchaseResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Store::StoreContext) consume_Windows_Services_Store_IStoreContextStatics<D>::GetDefault() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContextStatics)->GetDefault(&value));
        return llm::OS::Services::Store::StoreContext{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Store::StoreContext) consume_Windows_Services_Store_IStoreContextStatics<D>::GetForUser(llm::OS::System::User const& user) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreContextStatics)->GetForUser(*(void**)(&user), &value));
        return llm::OS::Services::Store::StoreContext{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_Services_Store_IStoreImage<D>::Uri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreImage)->get_Uri(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreImage<D>::ImagePurposeTag() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreImage)->get_ImagePurposeTag(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Services_Store_IStoreImage<D>::Width() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreImage)->get_Width(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Services_Store_IStoreImage<D>::Height() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreImage)->get_Height(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreImage<D>::Caption() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreImage)->get_Caption(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreLicense<D>::SkuStoreId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreLicense)->get_SkuStoreId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Services_Store_IStoreLicense<D>::IsActive() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreLicense)->get_IsActive(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Services_Store_IStoreLicense<D>::ExpirationDate() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreLicense)->get_ExpirationDate(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreLicense<D>::ExtendedJsonData() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreLicense)->get_ExtendedJsonData(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreLicense<D>::InAppOfferToken() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreLicense)->get_InAppOfferToken(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Services_Store_IStorePackageInstallOptions<D>::AllowForcedAppRestart() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStorePackageInstallOptions)->get_AllowForcedAppRestart(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Services_Store_IStorePackageInstallOptions<D>::AllowForcedAppRestart(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStorePackageInstallOptions)->put_AllowForcedAppRestart(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Services_Store_IStorePackageLicense<D>::LicenseLost(llm::OS::Foundation::TypedEventHandler<llm::OS::Services::Store::StorePackageLicense, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStorePackageLicense)->add_LicenseLost(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Services_Store_IStorePackageLicense<D>::LicenseLost_revoker consume_Windows_Services_Store_IStorePackageLicense<D>::LicenseLost(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Services::Store::StorePackageLicense, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, LicenseLost_revoker>(this, LicenseLost(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Services_Store_IStorePackageLicense<D>::LicenseLost(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Services::Store::IStorePackageLicense)->remove_LicenseLost(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) consume_Windows_Services_Store_IStorePackageLicense<D>::Package() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStorePackageLicense)->get_Package(&value));
        return llm::OS::ApplicationModel::Package{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Services_Store_IStorePackageLicense<D>::IsValid() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStorePackageLicense)->get_IsValid(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Services_Store_IStorePackageLicense<D>::ReleaseLicense() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStorePackageLicense)->ReleaseLicense());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) consume_Windows_Services_Store_IStorePackageUpdate<D>::Package() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStorePackageUpdate)->get_Package(&value));
        return llm::OS::ApplicationModel::Package{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Services_Store_IStorePackageUpdate<D>::Mandatory() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStorePackageUpdate)->get_Mandatory(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Store::StorePackageUpdateState) consume_Windows_Services_Store_IStorePackageUpdateResult<D>::OverallState() const
    {
        llm::OS::Services::Store::StorePackageUpdateState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStorePackageUpdateResult)->get_OverallState(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StorePackageUpdateStatus>) consume_Windows_Services_Store_IStorePackageUpdateResult<D>::StorePackageUpdateStatuses() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStorePackageUpdateResult)->get_StorePackageUpdateStatuses(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StorePackageUpdateStatus>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StoreQueueItem>) consume_Windows_Services_Store_IStorePackageUpdateResult2<D>::StoreQueueItems() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStorePackageUpdateResult2)->get_StoreQueueItems(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StoreQueueItem>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStorePrice<D>::FormattedBasePrice() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStorePrice)->get_FormattedBasePrice(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStorePrice<D>::FormattedPrice() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStorePrice)->get_FormattedPrice(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Services_Store_IStorePrice<D>::IsOnSale() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStorePrice)->get_IsOnSale(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Services_Store_IStorePrice<D>::SaleEndDate() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStorePrice)->get_SaleEndDate(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStorePrice<D>::CurrencyCode() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStorePrice)->get_CurrencyCode(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStorePrice<D>::FormattedRecurrencePrice() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStorePrice)->get_FormattedRecurrencePrice(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStorePrice2<D>::UnformattedBasePrice() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStorePrice2)->get_UnformattedBasePrice(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStorePrice2<D>::UnformattedPrice() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStorePrice2)->get_UnformattedPrice(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStorePrice2<D>::UnformattedRecurrencePrice() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStorePrice2)->get_UnformattedRecurrencePrice(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreProduct<D>::StoreId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreProduct)->get_StoreId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreProduct<D>::Language() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreProduct)->get_Language(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreProduct<D>::Title() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreProduct)->get_Title(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreProduct<D>::Description() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreProduct)->get_Description(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreProduct<D>::ProductKind() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreProduct)->get_ProductKind(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Services_Store_IStoreProduct<D>::HasDigitalDownload() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreProduct)->get_HasDigitalDownload(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_Services_Store_IStoreProduct<D>::Keywords() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreProduct)->get_Keywords(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StoreImage>) consume_Windows_Services_Store_IStoreProduct<D>::Images() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreProduct)->get_Images(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StoreImage>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StoreVideo>) consume_Windows_Services_Store_IStoreProduct<D>::Videos() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreProduct)->get_Videos(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StoreVideo>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StoreSku>) consume_Windows_Services_Store_IStoreProduct<D>::Skus() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreProduct)->get_Skus(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StoreSku>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Services_Store_IStoreProduct<D>::IsInUserCollection() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreProduct)->get_IsInUserCollection(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Store::StorePrice) consume_Windows_Services_Store_IStoreProduct<D>::Price() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreProduct)->get_Price(&value));
        return llm::OS::Services::Store::StorePrice{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreProduct<D>::ExtendedJsonData() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreProduct)->get_ExtendedJsonData(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_Services_Store_IStoreProduct<D>::LinkUri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreProduct)->get_LinkUri(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Services_Store_IStoreProduct<D>::GetIsAnySkuInstalledAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreProduct)->GetIsAnySkuInstalledAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StorePurchaseResult>) consume_Windows_Services_Store_IStoreProduct<D>::RequestPurchaseAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreProduct)->RequestPurchaseAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StorePurchaseResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StorePurchaseResult>) consume_Windows_Services_Store_IStoreProduct<D>::RequestPurchaseAsync(llm::OS::Services::Store::StorePurchaseProperties const& storePurchaseProperties) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreProduct)->RequestPurchaseWithPurchasePropertiesAsync(*(void**)(&storePurchaseProperties), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StorePurchaseResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreProduct<D>::InAppOfferToken() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreProduct)->get_InAppOfferToken(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Services_Store_IStoreProductOptions<D>::ActionFilters() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreProductOptions)->get_ActionFilters(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Services::Store::StoreProduct>) consume_Windows_Services_Store_IStoreProductPagedQueryResult<D>::Products() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreProductPagedQueryResult)->get_Products(&value));
        return llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Services::Store::StoreProduct>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Services_Store_IStoreProductPagedQueryResult<D>::HasMoreResults() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreProductPagedQueryResult)->get_HasMoreResults(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Services_Store_IStoreProductPagedQueryResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreProductPagedQueryResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductPagedQueryResult>) consume_Windows_Services_Store_IStoreProductPagedQueryResult<D>::GetNextAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreProductPagedQueryResult)->GetNextAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductPagedQueryResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Services::Store::StoreProduct>) consume_Windows_Services_Store_IStoreProductQueryResult<D>::Products() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreProductQueryResult)->get_Products(&value));
        return llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Services::Store::StoreProduct>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Services_Store_IStoreProductQueryResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreProductQueryResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Store::StoreProduct) consume_Windows_Services_Store_IStoreProductResult<D>::Product() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreProductResult)->get_Product(&value));
        return llm::OS::Services::Store::StoreProduct{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Services_Store_IStoreProductResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreProductResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStorePurchaseProperties<D>::Name() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStorePurchaseProperties)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Services_Store_IStorePurchaseProperties<D>::Name(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStorePurchaseProperties)->put_Name(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStorePurchaseProperties<D>::ExtendedJsonData() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStorePurchaseProperties)->get_ExtendedJsonData(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Services_Store_IStorePurchaseProperties<D>::ExtendedJsonData(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStorePurchaseProperties)->put_ExtendedJsonData(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Store::StorePurchaseProperties) consume_Windows_Services_Store_IStorePurchasePropertiesFactory<D>::Create(param::hstring const& name) const
    {
        void* storePurchaseProperties{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStorePurchasePropertiesFactory)->Create(*(void**)(&name), &storePurchaseProperties));
        return llm::OS::Services::Store::StorePurchaseProperties{ storePurchaseProperties, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Store::StorePurchaseStatus) consume_Windows_Services_Store_IStorePurchaseResult<D>::Status() const
    {
        llm::OS::Services::Store::StorePurchaseStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStorePurchaseResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Services_Store_IStorePurchaseResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStorePurchaseResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreQueueItem<D>::ProductId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreQueueItem)->get_ProductId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreQueueItem<D>::PackageFamilyName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreQueueItem)->get_PackageFamilyName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Store::StoreQueueItemKind) consume_Windows_Services_Store_IStoreQueueItem<D>::InstallKind() const
    {
        llm::OS::Services::Store::StoreQueueItemKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreQueueItem)->get_InstallKind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Store::StoreQueueItemStatus) consume_Windows_Services_Store_IStoreQueueItem<D>::GetCurrentStatus() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreQueueItem)->GetCurrentStatus(&result));
        return llm::OS::Services::Store::StoreQueueItemStatus{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Services_Store_IStoreQueueItem<D>::Completed(llm::OS::Foundation::TypedEventHandler<llm::OS::Services::Store::StoreQueueItem, llm::OS::Services::Store::StoreQueueItemCompletedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreQueueItem)->add_Completed(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Services_Store_IStoreQueueItem<D>::Completed_revoker consume_Windows_Services_Store_IStoreQueueItem<D>::Completed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Services::Store::StoreQueueItem, llm::OS::Services::Store::StoreQueueItemCompletedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Completed_revoker>(this, Completed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Services_Store_IStoreQueueItem<D>::Completed(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreQueueItem)->remove_Completed(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Services_Store_IStoreQueueItem<D>::StatusChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Services::Store::StoreQueueItem, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreQueueItem)->add_StatusChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Services_Store_IStoreQueueItem<D>::StatusChanged_revoker consume_Windows_Services_Store_IStoreQueueItem<D>::StatusChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Services::Store::StoreQueueItem, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, StatusChanged_revoker>(this, StatusChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Services_Store_IStoreQueueItem<D>::StatusChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreQueueItem)->remove_StatusChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Services_Store_IStoreQueueItem2<D>::CancelInstallAsync() const
    {
        void* action{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreQueueItem2)->CancelInstallAsync(&action));
        return llm::OS::Foundation::IAsyncAction{ action, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Services_Store_IStoreQueueItem2<D>::PauseInstallAsync() const
    {
        void* action{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreQueueItem2)->PauseInstallAsync(&action));
        return llm::OS::Foundation::IAsyncAction{ action, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Services_Store_IStoreQueueItem2<D>::ResumeInstallAsync() const
    {
        void* action{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreQueueItem2)->ResumeInstallAsync(&action));
        return llm::OS::Foundation::IAsyncAction{ action, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Store::StoreQueueItemStatus) consume_Windows_Services_Store_IStoreQueueItemCompletedEventArgs<D>::Status() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreQueueItemCompletedEventArgs)->get_Status(&value));
        return llm::OS::Services::Store::StoreQueueItemStatus{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Store::StoreQueueItemState) consume_Windows_Services_Store_IStoreQueueItemStatus<D>::PackageInstallState() const
    {
        llm::OS::Services::Store::StoreQueueItemState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreQueueItemStatus)->get_PackageInstallState(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Store::StoreQueueItemExtendedState) consume_Windows_Services_Store_IStoreQueueItemStatus<D>::PackageInstallExtendedState() const
    {
        llm::OS::Services::Store::StoreQueueItemExtendedState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreQueueItemStatus)->get_PackageInstallExtendedState(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Store::StorePackageUpdateStatus) consume_Windows_Services_Store_IStoreQueueItemStatus<D>::UpdateStatus() const
    {
        llm::OS::Services::Store::StorePackageUpdateStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreQueueItemStatus)->get_UpdateStatus(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Services_Store_IStoreQueueItemStatus<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreQueueItemStatus)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Services_Store_IStoreRateAndReviewResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreRateAndReviewResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreRateAndReviewResult<D>::ExtendedJsonData() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreRateAndReviewResult)->get_ExtendedJsonData(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Services_Store_IStoreRateAndReviewResult<D>::WasUpdated() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreRateAndReviewResult)->get_WasUpdated(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Store::StoreRateAndReviewStatus) consume_Windows_Services_Store_IStoreRateAndReviewResult<D>::Status() const
    {
        llm::OS::Services::Store::StoreRateAndReviewStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreRateAndReviewResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreSendRequestResult>) consume_Windows_Services_Store_IStoreRequestHelperStatics<D>::SendRequestAsync(llm::OS::Services::Store::StoreContext const& context, uint32_t requestKind, param::hstring const& parametersAsJson) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreRequestHelperStatics)->SendRequestAsync(*(void**)(&context), requestKind, *(void**)(&parametersAsJson), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreSendRequestResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreSendRequestResult<D>::Response() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreSendRequestResult)->get_Response(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Services_Store_IStoreSendRequestResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreSendRequestResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpStatusCode) consume_Windows_Services_Store_IStoreSendRequestResult2<D>::HttpStatusCode() const
    {
        llm::OS::Web::Http::HttpStatusCode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreSendRequestResult2)->get_HttpStatusCode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreSku<D>::StoreId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreSku)->get_StoreId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreSku<D>::Language() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreSku)->get_Language(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreSku<D>::Title() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreSku)->get_Title(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreSku<D>::Description() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreSku)->get_Description(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Services_Store_IStoreSku<D>::IsTrial() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreSku)->get_IsTrial(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreSku<D>::CustomDeveloperData() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreSku)->get_CustomDeveloperData(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StoreImage>) consume_Windows_Services_Store_IStoreSku<D>::Images() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreSku)->get_Images(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StoreImage>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StoreVideo>) consume_Windows_Services_Store_IStoreSku<D>::Videos() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreSku)->get_Videos(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StoreVideo>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StoreAvailability>) consume_Windows_Services_Store_IStoreSku<D>::Availabilities() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreSku)->get_Availabilities(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StoreAvailability>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Store::StorePrice) consume_Windows_Services_Store_IStoreSku<D>::Price() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreSku)->get_Price(&value));
        return llm::OS::Services::Store::StorePrice{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreSku<D>::ExtendedJsonData() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreSku)->get_ExtendedJsonData(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Services_Store_IStoreSku<D>::IsInUserCollection() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreSku)->get_IsInUserCollection(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_Services_Store_IStoreSku<D>::BundledSkus() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreSku)->get_BundledSkus(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Store::StoreCollectionData) consume_Windows_Services_Store_IStoreSku<D>::CollectionData() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreSku)->get_CollectionData(&value));
        return llm::OS::Services::Store::StoreCollectionData{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Services_Store_IStoreSku<D>::GetIsInstalledAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreSku)->GetIsInstalledAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StorePurchaseResult>) consume_Windows_Services_Store_IStoreSku<D>::RequestPurchaseAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreSku)->RequestPurchaseAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StorePurchaseResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StorePurchaseResult>) consume_Windows_Services_Store_IStoreSku<D>::RequestPurchaseAsync(llm::OS::Services::Store::StorePurchaseProperties const& storePurchaseProperties) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreSku)->RequestPurchaseWithPurchasePropertiesAsync(*(void**)(&storePurchaseProperties), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StorePurchaseResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Services_Store_IStoreSku<D>::IsSubscription() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreSku)->get_IsSubscription(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Store::StoreSubscriptionInfo) consume_Windows_Services_Store_IStoreSku<D>::SubscriptionInfo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreSku)->get_SubscriptionInfo(&value));
        return llm::OS::Services::Store::StoreSubscriptionInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Services_Store_IStoreSubscriptionInfo<D>::BillingPeriod() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreSubscriptionInfo)->get_BillingPeriod(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Store::StoreDurationUnit) consume_Windows_Services_Store_IStoreSubscriptionInfo<D>::BillingPeriodUnit() const
    {
        llm::OS::Services::Store::StoreDurationUnit value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreSubscriptionInfo)->get_BillingPeriodUnit(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Services_Store_IStoreSubscriptionInfo<D>::HasTrialPeriod() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreSubscriptionInfo)->get_HasTrialPeriod(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Services_Store_IStoreSubscriptionInfo<D>::TrialPeriod() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreSubscriptionInfo)->get_TrialPeriod(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Store::StoreDurationUnit) consume_Windows_Services_Store_IStoreSubscriptionInfo<D>::TrialPeriodUnit() const
    {
        llm::OS::Services::Store::StoreDurationUnit value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreSubscriptionInfo)->get_TrialPeriodUnit(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Services_Store_IStoreUninstallStorePackageResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreUninstallStorePackageResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Store::StoreUninstallStorePackageStatus) consume_Windows_Services_Store_IStoreUninstallStorePackageResult<D>::Status() const
    {
        llm::OS::Services::Store::StoreUninstallStorePackageStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreUninstallStorePackageResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_Services_Store_IStoreVideo<D>::Uri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreVideo)->get_Uri(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreVideo<D>::VideoPurposeTag() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreVideo)->get_VideoPurposeTag(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Services_Store_IStoreVideo<D>::Width() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreVideo)->get_Width(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Services_Store_IStoreVideo<D>::Height() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreVideo)->get_Height(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Store_IStoreVideo<D>::Caption() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreVideo)->get_Caption(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Store::StoreImage) consume_Windows_Services_Store_IStoreVideo<D>::PreviewImage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Store::IStoreVideo)->get_PreviewImage(&value));
        return llm::OS::Services::Store::StoreImage{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStoreAcquireLicenseResult> : produce_base<D, llm::OS::Services::Store::IStoreAcquireLicenseResult>
    {
        int32_t __stdcall get_StorePackageLicense(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Store::StorePackageLicense>(this->shim().StorePackageLicense());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStoreAppLicense> : produce_base<D, llm::OS::Services::Store::IStoreAppLicense>
    {
        int32_t __stdcall get_SkuStoreId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SkuStoreId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsActive(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsActive());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsTrial(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsTrial());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExpirationDate(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().ExpirationDate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedJsonData(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ExtendedJsonData());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AddOnLicenses(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Services::Store::StoreLicense>>(this->shim().AddOnLicenses());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TrialTimeRemaining(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().TrialTimeRemaining());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsTrialOwnedByThisUser(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsTrialOwnedByThisUser());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TrialUniqueId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().TrialUniqueId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStoreAppLicense2> : produce_base<D, llm::OS::Services::Store::IStoreAppLicense2>
    {
        int32_t __stdcall get_IsDiscLicense(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsDiscLicense());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStoreAvailability> : produce_base<D, llm::OS::Services::Store::IStoreAvailability>
    {
        int32_t __stdcall get_StoreId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().StoreId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EndDate(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().EndDate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Price(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Store::StorePrice>(this->shim().Price());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedJsonData(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ExtendedJsonData());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestPurchaseAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StorePurchaseResult>>(this->shim().RequestPurchaseAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestPurchaseWithPurchasePropertiesAsync(void* storePurchaseProperties, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StorePurchaseResult>>(this->shim().RequestPurchaseAsync(*reinterpret_cast<llm::OS::Services::Store::StorePurchaseProperties const*>(&storePurchaseProperties)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStoreCanAcquireLicenseResult> : produce_base<D, llm::OS::Services::Store::IStoreCanAcquireLicenseResult>
    {
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LicensableSku(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().LicensableSku());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Store::StoreCanLicenseStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStoreCollectionData> : produce_base<D, llm::OS::Services::Store::IStoreCollectionData>
    {
        int32_t __stdcall get_IsTrial(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsTrial());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CampaignId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().CampaignId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeveloperOfferId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeveloperOfferId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AcquiredDate(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().AcquiredDate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StartDate(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().StartDate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EndDate(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().EndDate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TrialTimeRemaining(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().TrialTimeRemaining());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedJsonData(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ExtendedJsonData());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStoreConsumableResult> : produce_base<D, llm::OS::Services::Store::IStoreConsumableResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Store::StoreConsumableStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TrackingId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().TrackingId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BalanceRemaining(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().BalanceRemaining());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStoreContext> : produce_base<D, llm::OS::Services::Store::IStoreContext>
    {
        int32_t __stdcall get_User(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::User>(this->shim().User());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_OfflineLicensesChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().OfflineLicensesChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Services::Store::StoreContext, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_OfflineLicensesChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OfflineLicensesChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall GetCustomerPurchaseIdAsync(void* serviceTicket, void* publisherUserId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<hstring>>(this->shim().GetCustomerPurchaseIdAsync(*reinterpret_cast<hstring const*>(&serviceTicket), *reinterpret_cast<hstring const*>(&publisherUserId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetCustomerCollectionsIdAsync(void* serviceTicket, void* publisherUserId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<hstring>>(this->shim().GetCustomerCollectionsIdAsync(*reinterpret_cast<hstring const*>(&serviceTicket), *reinterpret_cast<hstring const*>(&publisherUserId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAppLicenseAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreAppLicense>>(this->shim().GetAppLicenseAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetStoreProductForCurrentAppAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductResult>>(this->shim().GetStoreProductForCurrentAppAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetStoreProductsAsync(void* productKinds, void* storeIds, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductQueryResult>>(this->shim().GetStoreProductsAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&productKinds), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&storeIds)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAssociatedStoreProductsAsync(void* productKinds, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductQueryResult>>(this->shim().GetAssociatedStoreProductsAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&productKinds)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAssociatedStoreProductsWithPagingAsync(void* productKinds, uint32_t maxItemsToRetrievePerPage, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductPagedQueryResult>>(this->shim().GetAssociatedStoreProductsWithPagingAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&productKinds), maxItemsToRetrievePerPage));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetUserCollectionAsync(void* productKinds, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductQueryResult>>(this->shim().GetUserCollectionAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&productKinds)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetUserCollectionWithPagingAsync(void* productKinds, uint32_t maxItemsToRetrievePerPage, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductPagedQueryResult>>(this->shim().GetUserCollectionWithPagingAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&productKinds), maxItemsToRetrievePerPage));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportConsumableFulfillmentAsync(void* productStoreId, uint32_t quantity, llm::guid trackingId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreConsumableResult>>(this->shim().ReportConsumableFulfillmentAsync(*reinterpret_cast<hstring const*>(&productStoreId), quantity, *reinterpret_cast<llm::guid const*>(&trackingId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetConsumableBalanceRemainingAsync(void* productStoreId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreConsumableResult>>(this->shim().GetConsumableBalanceRemainingAsync(*reinterpret_cast<hstring const*>(&productStoreId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AcquireStoreLicenseForOptionalPackageAsync(void* optionalPackage, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreAcquireLicenseResult>>(this->shim().AcquireStoreLicenseForOptionalPackageAsync(*reinterpret_cast<llm::OS::ApplicationModel::Package const*>(&optionalPackage)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestPurchaseAsync(void* storeId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StorePurchaseResult>>(this->shim().RequestPurchaseAsync(*reinterpret_cast<hstring const*>(&storeId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestPurchaseWithPurchasePropertiesAsync(void* storeId, void* storePurchaseProperties, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StorePurchaseResult>>(this->shim().RequestPurchaseAsync(*reinterpret_cast<hstring const*>(&storeId), *reinterpret_cast<llm::OS::Services::Store::StorePurchaseProperties const*>(&storePurchaseProperties)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAppAndOptionalStorePackageUpdatesAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StorePackageUpdate>>>(this->shim().GetAppAndOptionalStorePackageUpdatesAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestDownloadStorePackageUpdatesAsync(void* storePackageUpdates, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Services::Store::StorePackageUpdateResult, llm::OS::Services::Store::StorePackageUpdateStatus>>(this->shim().RequestDownloadStorePackageUpdatesAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Services::Store::StorePackageUpdate> const*>(&storePackageUpdates)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestDownloadAndInstallStorePackageUpdatesAsync(void* storePackageUpdates, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Services::Store::StorePackageUpdateResult, llm::OS::Services::Store::StorePackageUpdateStatus>>(this->shim().RequestDownloadAndInstallStorePackageUpdatesAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Services::Store::StorePackageUpdate> const*>(&storePackageUpdates)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestDownloadAndInstallStorePackagesAsync(void* storeIds, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Services::Store::StorePackageUpdateResult, llm::OS::Services::Store::StorePackageUpdateStatus>>(this->shim().RequestDownloadAndInstallStorePackagesAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&storeIds)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStoreContext2> : produce_base<D, llm::OS::Services::Store::IStoreContext2>
    {
        int32_t __stdcall FindStoreProductForPackageAsync(void* productKinds, void* package, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductResult>>(this->shim().FindStoreProductForPackageAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&productKinds), *reinterpret_cast<llm::OS::ApplicationModel::Package const*>(&package)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStoreContext3> : produce_base<D, llm::OS::Services::Store::IStoreContext3>
    {
        int32_t __stdcall get_CanSilentlyDownloadStorePackageUpdates(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CanSilentlyDownloadStorePackageUpdates());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TrySilentDownloadStorePackageUpdatesAsync(void* storePackageUpdates, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Services::Store::StorePackageUpdateResult, llm::OS::Services::Store::StorePackageUpdateStatus>>(this->shim().TrySilentDownloadStorePackageUpdatesAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Services::Store::StorePackageUpdate> const*>(&storePackageUpdates)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TrySilentDownloadAndInstallStorePackageUpdatesAsync(void* storePackageUpdates, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Services::Store::StorePackageUpdateResult, llm::OS::Services::Store::StorePackageUpdateStatus>>(this->shim().TrySilentDownloadAndInstallStorePackageUpdatesAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Services::Store::StorePackageUpdate> const*>(&storePackageUpdates)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CanAcquireStoreLicenseForOptionalPackageAsync(void* optionalPackage, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreCanAcquireLicenseResult>>(this->shim().CanAcquireStoreLicenseForOptionalPackageAsync(*reinterpret_cast<llm::OS::ApplicationModel::Package const*>(&optionalPackage)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CanAcquireStoreLicenseAsync(void* productStoreId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreCanAcquireLicenseResult>>(this->shim().CanAcquireStoreLicenseAsync(*reinterpret_cast<hstring const*>(&productStoreId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetStoreProductsWithOptionsAsync(void* productKinds, void* storeIds, void* storeProductOptions, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductQueryResult>>(this->shim().GetStoreProductsAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&productKinds), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&storeIds), *reinterpret_cast<llm::OS::Services::Store::StoreProductOptions const*>(&storeProductOptions)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAssociatedStoreQueueItemsAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StoreQueueItem>>>(this->shim().GetAssociatedStoreQueueItemsAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetStoreQueueItemsAsync(void* storeIds, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StoreQueueItem>>>(this->shim().GetStoreQueueItemsAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&storeIds)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestDownloadAndInstallStorePackagesWithInstallOptionsAsync(void* storeIds, void* storePackageInstallOptions, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Services::Store::StorePackageUpdateResult, llm::OS::Services::Store::StorePackageUpdateStatus>>(this->shim().RequestDownloadAndInstallStorePackagesAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&storeIds), *reinterpret_cast<llm::OS::Services::Store::StorePackageInstallOptions const*>(&storePackageInstallOptions)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DownloadAndInstallStorePackagesAsync(void* storeIds, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Services::Store::StorePackageUpdateResult, llm::OS::Services::Store::StorePackageUpdateStatus>>(this->shim().DownloadAndInstallStorePackagesAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&storeIds)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestUninstallStorePackageAsync(void* package, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreUninstallStorePackageResult>>(this->shim().RequestUninstallStorePackageAsync(*reinterpret_cast<llm::OS::ApplicationModel::Package const*>(&package)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestUninstallStorePackageByStoreIdAsync(void* storeId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreUninstallStorePackageResult>>(this->shim().RequestUninstallStorePackageByStoreIdAsync(*reinterpret_cast<hstring const*>(&storeId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UninstallStorePackageAsync(void* package, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreUninstallStorePackageResult>>(this->shim().UninstallStorePackageAsync(*reinterpret_cast<llm::OS::ApplicationModel::Package const*>(&package)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UninstallStorePackageByStoreIdAsync(void* storeId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreUninstallStorePackageResult>>(this->shim().UninstallStorePackageByStoreIdAsync(*reinterpret_cast<hstring const*>(&storeId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStoreContext4> : produce_base<D, llm::OS::Services::Store::IStoreContext4>
    {
        int32_t __stdcall RequestRateAndReviewAppAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreRateAndReviewResult>>(this->shim().RequestRateAndReviewAppAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetInstallOrderForAssociatedStoreQueueItemsAsync(void* items, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StoreQueueItem>>>(this->shim().SetInstallOrderForAssociatedStoreQueueItemsAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Services::Store::StoreQueueItem> const*>(&items)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStoreContext5> : produce_base<D, llm::OS::Services::Store::IStoreContext5>
    {
        int32_t __stdcall GetUserPurchaseHistoryAsync(void* productKinds, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductQueryResult>>(this->shim().GetUserPurchaseHistoryAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&productKinds)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAssociatedStoreProductsByInAppOfferTokenAsync(void* inAppOfferTokens, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductQueryResult>>(this->shim().GetAssociatedStoreProductsByInAppOfferTokenAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&inAppOfferTokens)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestPurchaseByInAppOfferTokenAsync(void* inAppOfferToken, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StorePurchaseResult>>(this->shim().RequestPurchaseByInAppOfferTokenAsync(*reinterpret_cast<hstring const*>(&inAppOfferToken)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStoreContextStatics> : produce_base<D, llm::OS::Services::Store::IStoreContextStatics>
    {
        int32_t __stdcall GetDefault(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Store::StoreContext>(this->shim().GetDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetForUser(void* user, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Store::StoreContext>(this->shim().GetForUser(*reinterpret_cast<llm::OS::System::User const*>(&user)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStoreImage> : produce_base<D, llm::OS::Services::Store::IStoreImage>
    {
        int32_t __stdcall get_Uri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().Uri());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ImagePurposeTag(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ImagePurposeTag());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Width(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Width());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Height(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Height());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Caption(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Caption());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStoreLicense> : produce_base<D, llm::OS::Services::Store::IStoreLicense>
    {
        int32_t __stdcall get_SkuStoreId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SkuStoreId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsActive(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsActive());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExpirationDate(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().ExpirationDate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedJsonData(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ExtendedJsonData());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InAppOfferToken(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().InAppOfferToken());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStorePackageInstallOptions> : produce_base<D, llm::OS::Services::Store::IStorePackageInstallOptions>
    {
        int32_t __stdcall get_AllowForcedAppRestart(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().AllowForcedAppRestart());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AllowForcedAppRestart(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowForcedAppRestart(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStorePackageLicense> : produce_base<D, llm::OS::Services::Store::IStorePackageLicense>
    {
        int32_t __stdcall add_LicenseLost(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().LicenseLost(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Services::Store::StorePackageLicense, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_LicenseLost(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LicenseLost(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_Package(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Package>(this->shim().Package());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsValid(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsValid());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReleaseLicense() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReleaseLicense();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStorePackageUpdate> : produce_base<D, llm::OS::Services::Store::IStorePackageUpdate>
    {
        int32_t __stdcall get_Package(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Package>(this->shim().Package());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Mandatory(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Mandatory());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStorePackageUpdateResult> : produce_base<D, llm::OS::Services::Store::IStorePackageUpdateResult>
    {
        int32_t __stdcall get_OverallState(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Store::StorePackageUpdateState>(this->shim().OverallState());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StorePackageUpdateStatuses(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StorePackageUpdateStatus>>(this->shim().StorePackageUpdateStatuses());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStorePackageUpdateResult2> : produce_base<D, llm::OS::Services::Store::IStorePackageUpdateResult2>
    {
        int32_t __stdcall get_StoreQueueItems(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StoreQueueItem>>(this->shim().StoreQueueItems());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStorePrice> : produce_base<D, llm::OS::Services::Store::IStorePrice>
    {
        int32_t __stdcall get_FormattedBasePrice(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().FormattedBasePrice());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FormattedPrice(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().FormattedPrice());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsOnSale(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsOnSale());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SaleEndDate(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().SaleEndDate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CurrencyCode(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().CurrencyCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FormattedRecurrencePrice(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().FormattedRecurrencePrice());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStorePrice2> : produce_base<D, llm::OS::Services::Store::IStorePrice2>
    {
        int32_t __stdcall get_UnformattedBasePrice(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().UnformattedBasePrice());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UnformattedPrice(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().UnformattedPrice());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UnformattedRecurrencePrice(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().UnformattedRecurrencePrice());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStoreProduct> : produce_base<D, llm::OS::Services::Store::IStoreProduct>
    {
        int32_t __stdcall get_StoreId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().StoreId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Language(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Language());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Title(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Title());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Description(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProductKind(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ProductKind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HasDigitalDownload(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().HasDigitalDownload());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Keywords(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().Keywords());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Images(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StoreImage>>(this->shim().Images());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Videos(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StoreVideo>>(this->shim().Videos());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Skus(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StoreSku>>(this->shim().Skus());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsInUserCollection(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsInUserCollection());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Price(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Store::StorePrice>(this->shim().Price());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedJsonData(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ExtendedJsonData());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LinkUri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().LinkUri());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetIsAnySkuInstalledAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().GetIsAnySkuInstalledAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestPurchaseAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StorePurchaseResult>>(this->shim().RequestPurchaseAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestPurchaseWithPurchasePropertiesAsync(void* storePurchaseProperties, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StorePurchaseResult>>(this->shim().RequestPurchaseAsync(*reinterpret_cast<llm::OS::Services::Store::StorePurchaseProperties const*>(&storePurchaseProperties)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InAppOfferToken(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().InAppOfferToken());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStoreProductOptions> : produce_base<D, llm::OS::Services::Store::IStoreProductOptions>
    {
        int32_t __stdcall get_ActionFilters(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().ActionFilters());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStoreProductPagedQueryResult> : produce_base<D, llm::OS::Services::Store::IStoreProductPagedQueryResult>
    {
        int32_t __stdcall get_Products(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Services::Store::StoreProduct>>(this->shim().Products());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HasMoreResults(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().HasMoreResults());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetNextAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreProductPagedQueryResult>>(this->shim().GetNextAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStoreProductQueryResult> : produce_base<D, llm::OS::Services::Store::IStoreProductQueryResult>
    {
        int32_t __stdcall get_Products(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Services::Store::StoreProduct>>(this->shim().Products());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStoreProductResult> : produce_base<D, llm::OS::Services::Store::IStoreProductResult>
    {
        int32_t __stdcall get_Product(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Store::StoreProduct>(this->shim().Product());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStorePurchaseProperties> : produce_base<D, llm::OS::Services::Store::IStorePurchaseProperties>
    {
        int32_t __stdcall get_Name(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Name());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Name(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Name(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedJsonData(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ExtendedJsonData());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ExtendedJsonData(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExtendedJsonData(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStorePurchasePropertiesFactory> : produce_base<D, llm::OS::Services::Store::IStorePurchasePropertiesFactory>
    {
        int32_t __stdcall Create(void* name, void** storePurchaseProperties) noexcept final try
        {
            clear_abi(storePurchaseProperties);
            typename D::abi_guard guard(this->shim());
            *storePurchaseProperties = detach_from<llm::OS::Services::Store::StorePurchaseProperties>(this->shim().Create(*reinterpret_cast<hstring const*>(&name)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStorePurchaseResult> : produce_base<D, llm::OS::Services::Store::IStorePurchaseResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Store::StorePurchaseStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStoreQueueItem> : produce_base<D, llm::OS::Services::Store::IStoreQueueItem>
    {
        int32_t __stdcall get_ProductId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ProductId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PackageFamilyName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().PackageFamilyName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InstallKind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Store::StoreQueueItemKind>(this->shim().InstallKind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetCurrentStatus(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Services::Store::StoreQueueItemStatus>(this->shim().GetCurrentStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_Completed(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Completed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Services::Store::StoreQueueItem, llm::OS::Services::Store::StoreQueueItemCompletedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Completed(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Completed(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_StatusChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().StatusChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Services::Store::StoreQueueItem, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_StatusChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StatusChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStoreQueueItem2> : produce_base<D, llm::OS::Services::Store::IStoreQueueItem2>
    {
        int32_t __stdcall CancelInstallAsync(void** action) noexcept final try
        {
            clear_abi(action);
            typename D::abi_guard guard(this->shim());
            *action = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().CancelInstallAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall PauseInstallAsync(void** action) noexcept final try
        {
            clear_abi(action);
            typename D::abi_guard guard(this->shim());
            *action = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().PauseInstallAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ResumeInstallAsync(void** action) noexcept final try
        {
            clear_abi(action);
            typename D::abi_guard guard(this->shim());
            *action = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ResumeInstallAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStoreQueueItemCompletedEventArgs> : produce_base<D, llm::OS::Services::Store::IStoreQueueItemCompletedEventArgs>
    {
        int32_t __stdcall get_Status(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Store::StoreQueueItemStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStoreQueueItemStatus> : produce_base<D, llm::OS::Services::Store::IStoreQueueItemStatus>
    {
        int32_t __stdcall get_PackageInstallState(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Store::StoreQueueItemState>(this->shim().PackageInstallState());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PackageInstallExtendedState(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Store::StoreQueueItemExtendedState>(this->shim().PackageInstallExtendedState());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UpdateStatus(struct struct_Windows_Services_Store_StorePackageUpdateStatus* value) noexcept final try
        {
            zero_abi<llm::OS::Services::Store::StorePackageUpdateStatus>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Store::StorePackageUpdateStatus>(this->shim().UpdateStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStoreRateAndReviewResult> : produce_base<D, llm::OS::Services::Store::IStoreRateAndReviewResult>
    {
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedJsonData(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ExtendedJsonData());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WasUpdated(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().WasUpdated());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Store::StoreRateAndReviewStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStoreRequestHelperStatics> : produce_base<D, llm::OS::Services::Store::IStoreRequestHelperStatics>
    {
        int32_t __stdcall SendRequestAsync(void* context, uint32_t requestKind, void* parametersAsJson, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StoreSendRequestResult>>(this->shim().SendRequestAsync(*reinterpret_cast<llm::OS::Services::Store::StoreContext const*>(&context), requestKind, *reinterpret_cast<hstring const*>(&parametersAsJson)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStoreSendRequestResult> : produce_base<D, llm::OS::Services::Store::IStoreSendRequestResult>
    {
        int32_t __stdcall get_Response(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Response());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStoreSendRequestResult2> : produce_base<D, llm::OS::Services::Store::IStoreSendRequestResult2>
    {
        int32_t __stdcall get_HttpStatusCode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpStatusCode>(this->shim().HttpStatusCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStoreSku> : produce_base<D, llm::OS::Services::Store::IStoreSku>
    {
        int32_t __stdcall get_StoreId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().StoreId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Language(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Language());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Title(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Title());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Description(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsTrial(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsTrial());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CustomDeveloperData(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().CustomDeveloperData());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Images(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StoreImage>>(this->shim().Images());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Videos(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StoreVideo>>(this->shim().Videos());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Availabilities(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Store::StoreAvailability>>(this->shim().Availabilities());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Price(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Store::StorePrice>(this->shim().Price());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedJsonData(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ExtendedJsonData());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsInUserCollection(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsInUserCollection());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BundledSkus(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().BundledSkus());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CollectionData(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Store::StoreCollectionData>(this->shim().CollectionData());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetIsInstalledAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().GetIsInstalledAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestPurchaseAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StorePurchaseResult>>(this->shim().RequestPurchaseAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestPurchaseWithPurchasePropertiesAsync(void* storePurchaseProperties, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Store::StorePurchaseResult>>(this->shim().RequestPurchaseAsync(*reinterpret_cast<llm::OS::Services::Store::StorePurchaseProperties const*>(&storePurchaseProperties)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsSubscription(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsSubscription());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SubscriptionInfo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Store::StoreSubscriptionInfo>(this->shim().SubscriptionInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStoreSubscriptionInfo> : produce_base<D, llm::OS::Services::Store::IStoreSubscriptionInfo>
    {
        int32_t __stdcall get_BillingPeriod(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().BillingPeriod());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BillingPeriodUnit(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Store::StoreDurationUnit>(this->shim().BillingPeriodUnit());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HasTrialPeriod(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().HasTrialPeriod());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TrialPeriod(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().TrialPeriod());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TrialPeriodUnit(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Store::StoreDurationUnit>(this->shim().TrialPeriodUnit());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStoreUninstallStorePackageResult> : produce_base<D, llm::OS::Services::Store::IStoreUninstallStorePackageResult>
    {
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Store::StoreUninstallStorePackageStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Store::IStoreVideo> : produce_base<D, llm::OS::Services::Store::IStoreVideo>
    {
        int32_t __stdcall get_Uri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().Uri());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VideoPurposeTag(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().VideoPurposeTag());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Width(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Width());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Height(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Height());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Caption(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Caption());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PreviewImage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Store::StoreImage>(this->shim().PreviewImage());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Services::Store
{
    inline auto StoreContext::GetDefault()
    {
        return impl::call_factory_cast<llm::OS::Services::Store::StoreContext(*)(IStoreContextStatics const&), StoreContext, IStoreContextStatics>([](IStoreContextStatics const& f) { return f.GetDefault(); });
    }
    inline auto StoreContext::GetForUser(llm::OS::System::User const& user)
    {
        return impl::call_factory<StoreContext, IStoreContextStatics>([&](IStoreContextStatics const& f) { return f.GetForUser(user); });
    }
    inline StorePackageInstallOptions::StorePackageInstallOptions() :
        StorePackageInstallOptions(impl::call_factory_cast<StorePackageInstallOptions(*)(llm::OS::Foundation::IActivationFactory const&), StorePackageInstallOptions>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<StorePackageInstallOptions>(); }))
    {
    }
    inline StoreProductOptions::StoreProductOptions() :
        StoreProductOptions(impl::call_factory_cast<StoreProductOptions(*)(llm::OS::Foundation::IActivationFactory const&), StoreProductOptions>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<StoreProductOptions>(); }))
    {
    }
    inline StorePurchaseProperties::StorePurchaseProperties() :
        StorePurchaseProperties(impl::call_factory_cast<StorePurchaseProperties(*)(llm::OS::Foundation::IActivationFactory const&), StorePurchaseProperties>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<StorePurchaseProperties>(); }))
    {
    }
    inline StorePurchaseProperties::StorePurchaseProperties(param::hstring const& name) :
        StorePurchaseProperties(impl::call_factory<StorePurchaseProperties, IStorePurchasePropertiesFactory>([&](IStorePurchasePropertiesFactory const& f) { return f.Create(name); }))
    {
    }
    inline auto StoreRequestHelper::SendRequestAsync(llm::OS::Services::Store::StoreContext const& context, uint32_t requestKind, param::hstring const& parametersAsJson)
    {
        return impl::call_factory<StoreRequestHelper, IStoreRequestHelperStatics>([&](IStoreRequestHelperStatics const& f) { return f.SendRequestAsync(context, requestKind, parametersAsJson); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Services::Store::IStoreAcquireLicenseResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStoreAppLicense> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStoreAppLicense2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStoreAvailability> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStoreCanAcquireLicenseResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStoreCollectionData> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStoreConsumableResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStoreContext> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStoreContext2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStoreContext3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStoreContext4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStoreContext5> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStoreContextStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStoreImage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStoreLicense> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStorePackageInstallOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStorePackageLicense> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStorePackageUpdate> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStorePackageUpdateResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStorePackageUpdateResult2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStorePrice> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStorePrice2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStoreProduct> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStoreProductOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStoreProductPagedQueryResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStoreProductQueryResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStoreProductResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStorePurchaseProperties> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStorePurchasePropertiesFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStorePurchaseResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStoreQueueItem> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStoreQueueItem2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStoreQueueItemCompletedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStoreQueueItemStatus> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStoreRateAndReviewResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStoreRequestHelperStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStoreSendRequestResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStoreSendRequestResult2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStoreSku> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStoreSubscriptionInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStoreUninstallStorePackageResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::IStoreVideo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::StoreAcquireLicenseResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::StoreAppLicense> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::StoreAvailability> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::StoreCanAcquireLicenseResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::StoreCollectionData> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::StoreConsumableResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::StoreContext> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::StoreImage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::StoreLicense> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::StorePackageInstallOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::StorePackageLicense> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::StorePackageUpdate> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::StorePackageUpdateResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::StorePrice> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::StoreProduct> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::StoreProductOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::StoreProductPagedQueryResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::StoreProductQueryResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::StoreProductResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::StorePurchaseProperties> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::StorePurchaseResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::StoreQueueItem> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::StoreQueueItemCompletedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::StoreQueueItemStatus> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::StoreRateAndReviewResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::StoreRequestHelper> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::StoreSendRequestResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::StoreSku> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::StoreSubscriptionInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::StoreUninstallStorePackageResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Store::StoreVideo> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
