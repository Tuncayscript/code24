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
#ifndef LLM_OS_ApplicationModel_Payments_Provider_2_H
#define LLM_OS_ApplicationModel_Payments_Provider_2_H
#include "llm/impl/Windows.ApplicationModel.Payments.Provider.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Payments::Provider
{
    struct __declspec(empty_bases) PaymentAppCanMakePaymentTriggerDetails : llm::OS::ApplicationModel::Payments::Provider::IPaymentAppCanMakePaymentTriggerDetails
    {
        PaymentAppCanMakePaymentTriggerDetails(std::nullptr_t) noexcept {}
        PaymentAppCanMakePaymentTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Payments::Provider::IPaymentAppCanMakePaymentTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PaymentAppManager : llm::OS::ApplicationModel::Payments::Provider::IPaymentAppManager
    {
        PaymentAppManager(std::nullptr_t) noexcept {}
        PaymentAppManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Payments::Provider::IPaymentAppManager(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto Current();
    };
    struct __declspec(empty_bases) PaymentTransaction : llm::OS::ApplicationModel::Payments::Provider::IPaymentTransaction
    {
        PaymentTransaction(std::nullptr_t) noexcept {}
        PaymentTransaction(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Payments::Provider::IPaymentTransaction(ptr, take_ownership_from_abi) {}
        static auto FromIdAsync(param::hstring const& id);
    };
    struct __declspec(empty_bases) PaymentTransactionAcceptResult : llm::OS::ApplicationModel::Payments::Provider::IPaymentTransactionAcceptResult
    {
        PaymentTransactionAcceptResult(std::nullptr_t) noexcept {}
        PaymentTransactionAcceptResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Payments::Provider::IPaymentTransactionAcceptResult(ptr, take_ownership_from_abi) {}
    };
}
#endif
