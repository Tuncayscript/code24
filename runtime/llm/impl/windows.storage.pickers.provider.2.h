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
#ifndef LLM_OS_Storage_Pickers_Provider_2_H
#define LLM_OS_Storage_Pickers_Provider_2_H
#include "llm/impl/Windows.Storage.Pickers.Provider.1.h"
LLM_EXPORT namespace llm:OS::Storage::Pickers::Provider
{
    struct __declspec(empty_bases) FileOpenPickerUI : llm:OS::Storage::Pickers::Provider::IFileOpenPickerUI
    {
        FileOpenPickerUI(std::nullptr_t) noexcept {}
        FileOpenPickerUI(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Pickers::Provider::IFileOpenPickerUI(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FileRemovedEventArgs : llm:OS::Storage::Pickers::Provider::IFileRemovedEventArgs
    {
        FileRemovedEventArgs(std::nullptr_t) noexcept {}
        FileRemovedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Pickers::Provider::IFileRemovedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FileSavePickerUI : llm:OS::Storage::Pickers::Provider::IFileSavePickerUI
    {
        FileSavePickerUI(std::nullptr_t) noexcept {}
        FileSavePickerUI(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Pickers::Provider::IFileSavePickerUI(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PickerClosingDeferral : llm:OS::Storage::Pickers::Provider::IPickerClosingDeferral
    {
        PickerClosingDeferral(std::nullptr_t) noexcept {}
        PickerClosingDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Pickers::Provider::IPickerClosingDeferral(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PickerClosingEventArgs : llm:OS::Storage::Pickers::Provider::IPickerClosingEventArgs
    {
        PickerClosingEventArgs(std::nullptr_t) noexcept {}
        PickerClosingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Pickers::Provider::IPickerClosingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PickerClosingOperation : llm:OS::Storage::Pickers::Provider::IPickerClosingOperation
    {
        PickerClosingOperation(std::nullptr_t) noexcept {}
        PickerClosingOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Pickers::Provider::IPickerClosingOperation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TargetFileRequest : llm:OS::Storage::Pickers::Provider::ITargetFileRequest
    {
        TargetFileRequest(std::nullptr_t) noexcept {}
        TargetFileRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Pickers::Provider::ITargetFileRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TargetFileRequestDeferral : llm:OS::Storage::Pickers::Provider::ITargetFileRequestDeferral
    {
        TargetFileRequestDeferral(std::nullptr_t) noexcept {}
        TargetFileRequestDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Pickers::Provider::ITargetFileRequestDeferral(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TargetFileRequestedEventArgs : llm:OS::Storage::Pickers::Provider::ITargetFileRequestedEventArgs
    {
        TargetFileRequestedEventArgs(std::nullptr_t) noexcept {}
        TargetFileRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Pickers::Provider::ITargetFileRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
