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
#ifndef LLM_OS_Storage_Pickers_Provider_1_H
#define LLM_OS_Storage_Pickers_Provider_1_H
#include "llm/impl/Windows.Storage.Pickers.Provider.0.h"
LLM_EXPORT namespace llm:OS::Storage::Pickers::Provider
{
    struct __declspec(empty_bases) IFileOpenPickerUI :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFileOpenPickerUI>
    {
        IFileOpenPickerUI(std::nullptr_t = nullptr) noexcept {}
        IFileOpenPickerUI(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileRemovedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFileRemovedEventArgs>
    {
        IFileRemovedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IFileRemovedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileSavePickerUI :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFileSavePickerUI>
    {
        IFileSavePickerUI(std::nullptr_t = nullptr) noexcept {}
        IFileSavePickerUI(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPickerClosingDeferral :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPickerClosingDeferral>
    {
        IPickerClosingDeferral(std::nullptr_t = nullptr) noexcept {}
        IPickerClosingDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPickerClosingEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPickerClosingEventArgs>
    {
        IPickerClosingEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPickerClosingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPickerClosingOperation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPickerClosingOperation>
    {
        IPickerClosingOperation(std::nullptr_t = nullptr) noexcept {}
        IPickerClosingOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITargetFileRequest :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITargetFileRequest>
    {
        ITargetFileRequest(std::nullptr_t = nullptr) noexcept {}
        ITargetFileRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITargetFileRequestDeferral :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITargetFileRequestDeferral>
    {
        ITargetFileRequestDeferral(std::nullptr_t = nullptr) noexcept {}
        ITargetFileRequestDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITargetFileRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITargetFileRequestedEventArgs>
    {
        ITargetFileRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ITargetFileRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
