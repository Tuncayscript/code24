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
#ifndef LLM_OS_ApplicationModel_Payments_2_H
#define LLM_OS_ApplicationModel_Payments_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.ApplicationModel.Payments.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Payments
{
    struct PaymentRequestChangedHandler : llm::OS::Foundation::IUnknown
    {
        PaymentRequestChangedHandler(std::nullptr_t = nullptr) noexcept {}
        PaymentRequestChangedHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> PaymentRequestChangedHandler(L lambda);
        template <typename F> PaymentRequestChangedHandler(F* function);
        template <typename O, typename M> PaymentRequestChangedHandler(O* object, M method);
        template <typename O, typename M> PaymentRequestChangedHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> PaymentRequestChangedHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::ApplicationModel::Payments::PaymentRequest const& paymentRequest, llm::OS::ApplicationModel::Payments::PaymentRequestChangedArgs const& args) const;
    };
    struct __declspec(empty_bases) PaymentAddress : llm::OS::ApplicationModel::Payments::IPaymentAddress
    {
        PaymentAddress(std::nullptr_t) noexcept {}
        PaymentAddress(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Payments::IPaymentAddress(ptr, take_ownership_from_abi) {}
        PaymentAddress();
    };
    struct __declspec(empty_bases) PaymentCanMakePaymentResult : llm::OS::ApplicationModel::Payments::IPaymentCanMakePaymentResult
    {
        PaymentCanMakePaymentResult(std::nullptr_t) noexcept {}
        PaymentCanMakePaymentResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Payments::IPaymentCanMakePaymentResult(ptr, take_ownership_from_abi) {}
        explicit PaymentCanMakePaymentResult(llm::OS::ApplicationModel::Payments::PaymentCanMakePaymentResultStatus const& value);
    };
    struct __declspec(empty_bases) PaymentCurrencyAmount : llm::OS::ApplicationModel::Payments::IPaymentCurrencyAmount
    {
        PaymentCurrencyAmount(std::nullptr_t) noexcept {}
        PaymentCurrencyAmount(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Payments::IPaymentCurrencyAmount(ptr, take_ownership_from_abi) {}
        PaymentCurrencyAmount(param::hstring const& value, param::hstring const& currency);
        PaymentCurrencyAmount(param::hstring const& value, param::hstring const& currency, param::hstring const& currencySystem);
    };
    struct __declspec(empty_bases) PaymentDetails : llm::OS::ApplicationModel::Payments::IPaymentDetails
    {
        PaymentDetails(std::nullptr_t) noexcept {}
        PaymentDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Payments::IPaymentDetails(ptr, take_ownership_from_abi) {}
        PaymentDetails();
        explicit PaymentDetails(llm::OS::ApplicationModel::Payments::PaymentItem const& total);
        PaymentDetails(llm::OS::ApplicationModel::Payments::PaymentItem const& total, param::iterable<llm::OS::ApplicationModel::Payments::PaymentItem> const& displayItems);
    };
    struct __declspec(empty_bases) PaymentDetailsModifier : llm::OS::ApplicationModel::Payments::IPaymentDetailsModifier
    {
        PaymentDetailsModifier(std::nullptr_t) noexcept {}
        PaymentDetailsModifier(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Payments::IPaymentDetailsModifier(ptr, take_ownership_from_abi) {}
        PaymentDetailsModifier(param::iterable<hstring> const& supportedMethodIds, llm::OS::ApplicationModel::Payments::PaymentItem const& total);
        PaymentDetailsModifier(param::iterable<hstring> const& supportedMethodIds, llm::OS::ApplicationModel::Payments::PaymentItem const& total, param::iterable<llm::OS::ApplicationModel::Payments::PaymentItem> const& additionalDisplayItems);
        PaymentDetailsModifier(param::iterable<hstring> const& supportedMethodIds, llm::OS::ApplicationModel::Payments::PaymentItem const& total, param::iterable<llm::OS::ApplicationModel::Payments::PaymentItem> const& additionalDisplayItems, param::hstring const& jsonData);
    };
    struct __declspec(empty_bases) PaymentItem : llm::OS::ApplicationModel::Payments::IPaymentItem
    {
        PaymentItem(std::nullptr_t) noexcept {}
        PaymentItem(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Payments::IPaymentItem(ptr, take_ownership_from_abi) {}
        PaymentItem(param::hstring const& label, llm::OS::ApplicationModel::Payments::PaymentCurrencyAmount const& amount);
    };
    struct __declspec(empty_bases) PaymentMediator : llm::OS::ApplicationModel::Payments::IPaymentMediator,
        impl::require<PaymentMediator, llm::OS::ApplicationModel::Payments::IPaymentMediator2>
    {
        PaymentMediator(std::nullptr_t) noexcept {}
        PaymentMediator(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Payments::IPaymentMediator(ptr, take_ownership_from_abi) {}
        PaymentMediator();
    };
    struct __declspec(empty_bases) PaymentMerchantInfo : llm::OS::ApplicationModel::Payments::IPaymentMerchantInfo
    {
        PaymentMerchantInfo(std::nullptr_t) noexcept {}
        PaymentMerchantInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Payments::IPaymentMerchantInfo(ptr, take_ownership_from_abi) {}
        PaymentMerchantInfo();
        explicit PaymentMerchantInfo(llm::OS::Foundation::Uri const& uri);
    };
    struct __declspec(empty_bases) PaymentMethodData : llm::OS::ApplicationModel::Payments::IPaymentMethodData
    {
        PaymentMethodData(std::nullptr_t) noexcept {}
        PaymentMethodData(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Payments::IPaymentMethodData(ptr, take_ownership_from_abi) {}
        explicit PaymentMethodData(param::iterable<hstring> const& supportedMethodIds);
        PaymentMethodData(param::iterable<hstring> const& supportedMethodIds, param::hstring const& jsonData);
    };
    struct __declspec(empty_bases) PaymentOptions : llm::OS::ApplicationModel::Payments::IPaymentOptions
    {
        PaymentOptions(std::nullptr_t) noexcept {}
        PaymentOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Payments::IPaymentOptions(ptr, take_ownership_from_abi) {}
        PaymentOptions();
    };
    struct __declspec(empty_bases) PaymentRequest : llm::OS::ApplicationModel::Payments::IPaymentRequest,
        impl::require<PaymentRequest, llm::OS::ApplicationModel::Payments::IPaymentRequest2>
    {
        PaymentRequest(std::nullptr_t) noexcept {}
        PaymentRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Payments::IPaymentRequest(ptr, take_ownership_from_abi) {}
        PaymentRequest(llm::OS::ApplicationModel::Payments::PaymentDetails const& details, param::iterable<llm::OS::ApplicationModel::Payments::PaymentMethodData> const& methodData);
        PaymentRequest(llm::OS::ApplicationModel::Payments::PaymentDetails const& details, param::iterable<llm::OS::ApplicationModel::Payments::PaymentMethodData> const& methodData, llm::OS::ApplicationModel::Payments::PaymentMerchantInfo const& merchantInfo);
        PaymentRequest(llm::OS::ApplicationModel::Payments::PaymentDetails const& details, param::iterable<llm::OS::ApplicationModel::Payments::PaymentMethodData> const& methodData, llm::OS::ApplicationModel::Payments::PaymentMerchantInfo const& merchantInfo, llm::OS::ApplicationModel::Payments::PaymentOptions const& options);
        PaymentRequest(llm::OS::ApplicationModel::Payments::PaymentDetails const& details, param::iterable<llm::OS::ApplicationModel::Payments::PaymentMethodData> const& methodData, llm::OS::ApplicationModel::Payments::PaymentMerchantInfo const& merchantInfo, llm::OS::ApplicationModel::Payments::PaymentOptions const& options, param::hstring const& id);
    };
    struct __declspec(empty_bases) PaymentRequestChangedArgs : llm::OS::ApplicationModel::Payments::IPaymentRequestChangedArgs
    {
        PaymentRequestChangedArgs(std::nullptr_t) noexcept {}
        PaymentRequestChangedArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Payments::IPaymentRequestChangedArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PaymentRequestChangedResult : llm::OS::ApplicationModel::Payments::IPaymentRequestChangedResult
    {
        PaymentRequestChangedResult(std::nullptr_t) noexcept {}
        PaymentRequestChangedResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Payments::IPaymentRequestChangedResult(ptr, take_ownership_from_abi) {}
        explicit PaymentRequestChangedResult(bool changeAcceptedByMerchant);
        PaymentRequestChangedResult(bool changeAcceptedByMerchant, llm::OS::ApplicationModel::Payments::PaymentDetails const& updatedPaymentDetails);
    };
    struct __declspec(empty_bases) PaymentRequestSubmitResult : llm::OS::ApplicationModel::Payments::IPaymentRequestSubmitResult
    {
        PaymentRequestSubmitResult(std::nullptr_t) noexcept {}
        PaymentRequestSubmitResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Payments::IPaymentRequestSubmitResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PaymentResponse : llm::OS::ApplicationModel::Payments::IPaymentResponse
    {
        PaymentResponse(std::nullptr_t) noexcept {}
        PaymentResponse(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Payments::IPaymentResponse(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PaymentShippingOption : llm::OS::ApplicationModel::Payments::IPaymentShippingOption
    {
        PaymentShippingOption(std::nullptr_t) noexcept {}
        PaymentShippingOption(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Payments::IPaymentShippingOption(ptr, take_ownership_from_abi) {}
        PaymentShippingOption(param::hstring const& label, llm::OS::ApplicationModel::Payments::PaymentCurrencyAmount const& amount);
        PaymentShippingOption(param::hstring const& label, llm::OS::ApplicationModel::Payments::PaymentCurrencyAmount const& amount, bool selected);
        PaymentShippingOption(param::hstring const& label, llm::OS::ApplicationModel::Payments::PaymentCurrencyAmount const& amount, bool selected, param::hstring const& tag);
    };
    struct __declspec(empty_bases) PaymentToken : llm::OS::ApplicationModel::Payments::IPaymentToken
    {
        PaymentToken(std::nullptr_t) noexcept {}
        PaymentToken(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Payments::IPaymentToken(ptr, take_ownership_from_abi) {}
        explicit PaymentToken(param::hstring const& paymentMethodId);
        PaymentToken(param::hstring const& paymentMethodId, param::hstring const& jsonDetails);
    };
}
#endif
