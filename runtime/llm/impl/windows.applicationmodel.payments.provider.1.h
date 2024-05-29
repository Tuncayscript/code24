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
#ifndef LLM_OS_ApplicationModel_Payments_Provider_1_H
#define LLM_OS_ApplicationModel_Payments_Provider_1_H
#include "llm/impl/Windows.ApplicationModel.Payments.Provider.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Payments::Provider
{
    struct __declspec(empty_bases) IPaymentAppCanMakePaymentTriggerDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentAppCanMakePaymentTriggerDetails>
    {
        IPaymentAppCanMakePaymentTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IPaymentAppCanMakePaymentTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentAppManager :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentAppManager>
    {
        IPaymentAppManager(std::nullptr_t = nullptr) noexcept {}
        IPaymentAppManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentAppManagerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentAppManagerStatics>
    {
        IPaymentAppManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IPaymentAppManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentTransaction :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentTransaction>
    {
        IPaymentTransaction(std::nullptr_t = nullptr) noexcept {}
        IPaymentTransaction(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentTransactionAcceptResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentTransactionAcceptResult>
    {
        IPaymentTransactionAcceptResult(std::nullptr_t = nullptr) noexcept {}
        IPaymentTransactionAcceptResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaymentTransactionStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaymentTransactionStatics>
    {
        IPaymentTransactionStatics(std::nullptr_t = nullptr) noexcept {}
        IPaymentTransactionStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
