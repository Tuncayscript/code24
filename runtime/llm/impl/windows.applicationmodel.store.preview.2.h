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
#ifndef LLM_OS_ApplicationModel_Store_Preview_2_H
#define LLM_OS_ApplicationModel_Store_Preview_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Security.Authentication.Web.Core.1.h"
#include "llm/impl/Windows.Security.Credentials.1.h"
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.UI.Xaml.1.h"
#include "llm/impl/Windows.ApplicationModel.Store.Preview.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Store::Preview
{
    struct __declspec(empty_bases) DeliveryOptimizationSettings : llm::OS::ApplicationModel::Store::Preview::IDeliveryOptimizationSettings
    {
        DeliveryOptimizationSettings(std::nullptr_t) noexcept {}
        DeliveryOptimizationSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Store::Preview::IDeliveryOptimizationSettings(ptr, take_ownership_from_abi) {}
        static auto GetCurrentSettings();
    };
    struct StoreConfiguration
    {
        StoreConfiguration() = delete;
        static auto SetSystemConfiguration(param::hstring const& catalogHardwareManufacturerId, param::hstring const& catalogStoreContentModifierId, llm::OS::Foundation::DateTime const& systemConfigurationExpiration, param::hstring const& catalogHardwareDescriptor);
        static auto SetMobileOperatorConfiguration(param::hstring const& mobileOperatorId, uint32_t appDownloadLimitInMegabytes, uint32_t updateDownloadLimitInMegabytes);
        static auto SetStoreWebAccountId(param::hstring const& webAccountId);
        static auto IsStoreWebAccountId(param::hstring const& webAccountId);
        [[nodiscard]] static auto HardwareManufacturerInfo();
        static auto FilterUnsupportedSystemFeaturesAsync(param::async_iterable<llm::OS::ApplicationModel::Store::Preview::StoreSystemFeature> const& systemFeatures);
        [[nodiscard]] static auto PurchasePromptingPolicy();
        static auto PurchasePromptingPolicy(llm::OS::Foundation::IReference<uint32_t> const& value);
        static auto HasStoreWebAccount();
        static auto HasStoreWebAccountForUser(llm::OS::System::User const& user);
        static auto GetStoreLogDataAsync(llm::OS::ApplicationModel::Store::Preview::StoreLogOptions const& options);
        static auto SetStoreWebAccountIdForUser(llm::OS::System::User const& user, param::hstring const& webAccountId);
        static auto IsStoreWebAccountIdForUser(llm::OS::System::User const& user, param::hstring const& webAccountId);
        static auto GetPurchasePromptingPolicyForUser(llm::OS::System::User const& user);
        static auto SetPurchasePromptingPolicyForUser(llm::OS::System::User const& user, llm::OS::Foundation::IReference<uint32_t> const& value);
        static auto GetStoreWebAccountId();
        static auto GetStoreWebAccountIdForUser(llm::OS::System::User const& user);
        static auto SetEnterpriseStoreWebAccountId(param::hstring const& webAccountId);
        static auto SetEnterpriseStoreWebAccountIdForUser(llm::OS::System::User const& user, param::hstring const& webAccountId);
        static auto GetEnterpriseStoreWebAccountId();
        static auto GetEnterpriseStoreWebAccountIdForUser(llm::OS::System::User const& user);
        static auto ShouldRestrictToEnterpriseStoreOnly();
        static auto ShouldRestrictToEnterpriseStoreOnlyForUser(llm::OS::System::User const& user);
        static auto IsPinToDesktopSupported();
        static auto IsPinToTaskbarSupported();
        static auto IsPinToStartSupported();
        static auto PinToDesktop(param::hstring const& appPackageFamilyName);
        static auto PinToDesktopForUser(llm::OS::System::User const& user, param::hstring const& appPackageFamilyName);
    };
    struct __declspec(empty_bases) StoreHardwareManufacturerInfo : llm::OS::ApplicationModel::Store::Preview::IStoreHardwareManufacturerInfo
    {
        StoreHardwareManufacturerInfo(std::nullptr_t) noexcept {}
        StoreHardwareManufacturerInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Store::Preview::IStoreHardwareManufacturerInfo(ptr, take_ownership_from_abi) {}
    };
    struct StorePreview
    {
        StorePreview() = delete;
        static auto RequestProductPurchaseByProductIdAndSkuIdAsync(param::hstring const& productId, param::hstring const& skuId);
        static auto LoadAddOnProductInfosAsync();
    };
    struct __declspec(empty_bases) StorePreviewProductInfo : llm::OS::ApplicationModel::Store::Preview::IStorePreviewProductInfo
    {
        StorePreviewProductInfo(std::nullptr_t) noexcept {}
        StorePreviewProductInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Store::Preview::IStorePreviewProductInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StorePreviewPurchaseResults : llm::OS::ApplicationModel::Store::Preview::IStorePreviewPurchaseResults
    {
        StorePreviewPurchaseResults(std::nullptr_t) noexcept {}
        StorePreviewPurchaseResults(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Store::Preview::IStorePreviewPurchaseResults(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StorePreviewSkuInfo : llm::OS::ApplicationModel::Store::Preview::IStorePreviewSkuInfo
    {
        StorePreviewSkuInfo(std::nullptr_t) noexcept {}
        StorePreviewSkuInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Store::Preview::IStorePreviewSkuInfo(ptr, take_ownership_from_abi) {}
    };
    struct WebAuthenticationCoreManagerHelper
    {
        WebAuthenticationCoreManagerHelper() = delete;
        static auto RequestTokenWithUIElementHostingAsync(llm::OS::Security::Authentication::Web::Core::WebTokenRequest const& request, llm::OS::UI::Xaml::UIElement const& uiElement);
        static auto RequestTokenWithUIElementHostingAsync(llm::OS::Security::Authentication::Web::Core::WebTokenRequest const& request, llm::OS::Security::Credentials::WebAccount const& webAccount, llm::OS::UI::Xaml::UIElement const& uiElement);
    };
}
#endif
