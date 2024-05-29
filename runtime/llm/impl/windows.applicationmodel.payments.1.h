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
#ifndef LLM_OS_ApplicationModel_Payments_1_H
#define LLM_OS_ApplicationModel_Payments_1_H
#include "llm/impl/Windows.ApplicationModel.Payments.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Payments
{
    struct __declspec(empty_bases) IPaymentAddress :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentAddress>
    {
        IPaymentAddress(std::nullptr_t = nullptr) noexcept {}
        IPaymentAddress(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentCanMakePaymentResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentCanMakePaymentResult>
    {
        IPaymentCanMakePaymentResult(std::nullptr_t = nullptr) noexcept {}
        IPaymentCanMakePaymentResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentCanMakePaymentResultFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentCanMakePaymentResultFactory>
    {
        IPaymentCanMakePaymentResultFactory(std::nullptr_t = nullptr) noexcept {}
        IPaymentCanMakePaymentResultFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentCurrencyAmount :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentCurrencyAmount>
    {
        IPaymentCurrencyAmount(std::nullptr_t = nullptr) noexcept {}
        IPaymentCurrencyAmount(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentCurrencyAmountFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentCurrencyAmountFactory>
    {
        IPaymentCurrencyAmountFactory(std::nullptr_t = nullptr) noexcept {}
        IPaymentCurrencyAmountFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentDetails>
    {
        IPaymentDetails(std::nullptr_t = nullptr) noexcept {}
        IPaymentDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentDetailsFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentDetailsFactory>
    {
        IPaymentDetailsFactory(std::nullptr_t = nullptr) noexcept {}
        IPaymentDetailsFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentDetailsModifier :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentDetailsModifier>
    {
        IPaymentDetailsModifier(std::nullptr_t = nullptr) noexcept {}
        IPaymentDetailsModifier(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentDetailsModifierFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentDetailsModifierFactory>
    {
        IPaymentDetailsModifierFactory(std::nullptr_t = nullptr) noexcept {}
        IPaymentDetailsModifierFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentItem :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentItem>
    {
        IPaymentItem(std::nullptr_t = nullptr) noexcept {}
        IPaymentItem(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentItemFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentItemFactory>
    {
        IPaymentItemFactory(std::nullptr_t = nullptr) noexcept {}
        IPaymentItemFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentMediator :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentMediator>
    {
        IPaymentMediator(std::nullptr_t = nullptr) noexcept {}
        IPaymentMediator(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentMediator2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentMediator2>
    {
        IPaymentMediator2(std::nullptr_t = nullptr) noexcept {}
        IPaymentMediator2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentMerchantInfo :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentMerchantInfo>
    {
        IPaymentMerchantInfo(std::nullptr_t = nullptr) noexcept {}
        IPaymentMerchantInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentMerchantInfoFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentMerchantInfoFactory>
    {
        IPaymentMerchantInfoFactory(std::nullptr_t = nullptr) noexcept {}
        IPaymentMerchantInfoFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentMethodData :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentMethodData>
    {
        IPaymentMethodData(std::nullptr_t = nullptr) noexcept {}
        IPaymentMethodData(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentMethodDataFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentMethodDataFactory>
    {
        IPaymentMethodDataFactory(std::nullptr_t = nullptr) noexcept {}
        IPaymentMethodDataFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentOptions :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentOptions>
    {
        IPaymentOptions(std::nullptr_t = nullptr) noexcept {}
        IPaymentOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentRequest>
    {
        IPaymentRequest(std::nullptr_t = nullptr) noexcept {}
        IPaymentRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentRequest2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentRequest2>
    {
        IPaymentRequest2(std::nullptr_t = nullptr) noexcept {}
        IPaymentRequest2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentRequestChangedArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentRequestChangedArgs>
    {
        IPaymentRequestChangedArgs(std::nullptr_t = nullptr) noexcept {}
        IPaymentRequestChangedArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentRequestChangedResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentRequestChangedResult>
    {
        IPaymentRequestChangedResult(std::nullptr_t = nullptr) noexcept {}
        IPaymentRequestChangedResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentRequestChangedResultFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentRequestChangedResultFactory>
    {
        IPaymentRequestChangedResultFactory(std::nullptr_t = nullptr) noexcept {}
        IPaymentRequestChangedResultFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentRequestFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentRequestFactory>
    {
        IPaymentRequestFactory(std::nullptr_t = nullptr) noexcept {}
        IPaymentRequestFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentRequestFactory2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentRequestFactory2>
    {
        IPaymentRequestFactory2(std::nullptr_t = nullptr) noexcept {}
        IPaymentRequestFactory2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentRequestSubmitResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentRequestSubmitResult>
    {
        IPaymentRequestSubmitResult(std::nullptr_t = nullptr) noexcept {}
        IPaymentRequestSubmitResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentResponse :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentResponse>
    {
        IPaymentResponse(std::nullptr_t = nullptr) noexcept {}
        IPaymentResponse(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentShippingOption :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentShippingOption>
    {
        IPaymentShippingOption(std::nullptr_t = nullptr) noexcept {}
        IPaymentShippingOption(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentShippingOptionFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentShippingOptionFactory>
    {
        IPaymentShippingOptionFactory(std::nullptr_t = nullptr) noexcept {}
        IPaymentShippingOptionFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentToken :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentToken>
    {
        IPaymentToken(std::nullptr_t = nullptr) noexcept {}
        IPaymentToken(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentTokenFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentTokenFactory>
    {
        IPaymentTokenFactory(std::nullptr_t = nullptr) noexcept {}
        IPaymentTokenFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
