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
#ifndef LLM_OS_ApplicationModel_Wallet_2_H
#define LLM_OS_ApplicationModel_Wallet_2_H
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.ApplicationModel.Wallet.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Wallet
{
    struct __declspec(empty_bases) WalletBarcode : llm::OS::ApplicationModel::Wallet::IWalletBarcode
    {
        WalletBarcode(std::nullptr_t) noexcept {}
        WalletBarcode(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Wallet::IWalletBarcode(ptr, take_ownership_from_abi) {}
        WalletBarcode(llm::OS::ApplicationModel::Wallet::WalletBarcodeSymbology const& symbology, param::hstring const& value);
        explicit WalletBarcode(llm::OS::Storage::Streams::IRandomAccessStreamReference const& streamToBarcodeImage);
    };
    struct __declspec(empty_bases) WalletItem : llm::OS::ApplicationModel::Wallet::IWalletItem
    {
        WalletItem(std::nullptr_t) noexcept {}
        WalletItem(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Wallet::IWalletItem(ptr, take_ownership_from_abi) {}
        WalletItem(llm::OS::ApplicationModel::Wallet::WalletItemKind const& kind, param::hstring const& displayName);
    };
    struct __declspec(empty_bases) WalletItemCustomProperty : llm::OS::ApplicationModel::Wallet::IWalletItemCustomProperty
    {
        WalletItemCustomProperty(std::nullptr_t) noexcept {}
        WalletItemCustomProperty(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Wallet::IWalletItemCustomProperty(ptr, take_ownership_from_abi) {}
        WalletItemCustomProperty(param::hstring const& name, param::hstring const& value);
    };
    struct __declspec(empty_bases) WalletItemStore : llm::OS::ApplicationModel::Wallet::IWalletItemStore
    {
        WalletItemStore(std::nullptr_t) noexcept {}
        WalletItemStore(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Wallet::IWalletItemStore(ptr, take_ownership_from_abi) {}
    };
    struct WalletManager
    {
        WalletManager() = delete;
        static auto RequestStoreAsync();
    };
    struct __declspec(empty_bases) WalletRelevantLocation : llm::OS::ApplicationModel::Wallet::IWalletRelevantLocation
    {
        WalletRelevantLocation(std::nullptr_t) noexcept {}
        WalletRelevantLocation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Wallet::IWalletRelevantLocation(ptr, take_ownership_from_abi) {}
        WalletRelevantLocation();
    };
    struct __declspec(empty_bases) WalletTransaction : llm::OS::ApplicationModel::Wallet::IWalletTransaction
    {
        WalletTransaction(std::nullptr_t) noexcept {}
        WalletTransaction(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Wallet::IWalletTransaction(ptr, take_ownership_from_abi) {}
        WalletTransaction();
    };
    struct __declspec(empty_bases) WalletVerb : llm::OS::ApplicationModel::Wallet::IWalletVerb
    {
        WalletVerb(std::nullptr_t) noexcept {}
        WalletVerb(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Wallet::IWalletVerb(ptr, take_ownership_from_abi) {}
        explicit WalletVerb(param::hstring const& name);
    };
}
#endif
