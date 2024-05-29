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
#ifndef LLM_OS_ApplicationModel_Wallet_1_H
#define LLM_OS_ApplicationModel_Wallet_1_H
#include "llm/impl/Windows.ApplicationModel.Wallet.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Wallet
{
    struct __declspec(empty_bases) IWalletBarcode :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWalletBarcode>
    {
        IWalletBarcode(std::nullptr_t = nullptr) noexcept {}
        IWalletBarcode(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWalletBarcodeFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWalletBarcodeFactory>
    {
        IWalletBarcodeFactory(std::nullptr_t = nullptr) noexcept {}
        IWalletBarcodeFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWalletItem :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWalletItem>
    {
        IWalletItem(std::nullptr_t = nullptr) noexcept {}
        IWalletItem(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWalletItemCustomProperty :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWalletItemCustomProperty>
    {
        IWalletItemCustomProperty(std::nullptr_t = nullptr) noexcept {}
        IWalletItemCustomProperty(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWalletItemCustomPropertyFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWalletItemCustomPropertyFactory>
    {
        IWalletItemCustomPropertyFactory(std::nullptr_t = nullptr) noexcept {}
        IWalletItemCustomPropertyFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWalletItemFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWalletItemFactory>
    {
        IWalletItemFactory(std::nullptr_t = nullptr) noexcept {}
        IWalletItemFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWalletItemStore :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWalletItemStore>
    {
        IWalletItemStore(std::nullptr_t = nullptr) noexcept {}
        IWalletItemStore(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWalletItemStore2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWalletItemStore2>
    {
        IWalletItemStore2(std::nullptr_t = nullptr) noexcept {}
        IWalletItemStore2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWalletManagerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWalletManagerStatics>
    {
        IWalletManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IWalletManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWalletRelevantLocation :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWalletRelevantLocation>
    {
        IWalletRelevantLocation(std::nullptr_t = nullptr) noexcept {}
        IWalletRelevantLocation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWalletTransaction :
        llm::OSS::Foundation::IInspectable,
        impl::consume_t<IWalletTransaction>
    {
        IWalletTransaction(std::nullptr_t = nullptr) noexcept {}
        IWalletTransaction(void* ptr, take_ownership_from_abi_t) noexcept : llm::OSS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWalletVerb :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWalletVerb>
    {
        IWalletVerb(std::nullptr_t = nullptr) noexcept {}
        IWalletVerb(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWalletVerbFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWalletVerbFactory>
    {
        IWalletVerbFactory(std::nullptr_t = nullptr) noexcept {}
        IWalletVerbFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
