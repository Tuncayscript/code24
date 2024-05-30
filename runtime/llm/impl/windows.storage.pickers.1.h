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
#ifndef LLM_OS_Storage_Pickers_1_H
#define LLM_OS_Storage_Pickers_1_H
#include "llm/impl/Windows.Storage.Pickers.0.h"
LLM_EXPORT namespace llm:OS::Storage::Pickers
{
    struct __declspec(empty_bases) IFileOpenPicker :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFileOpenPicker>
    {
        IFileOpenPicker(std::nullptr_t = nullptr) noexcept {}
        IFileOpenPicker(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileOpenPicker2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFileOpenPicker2>
    {
        IFileOpenPicker2(std::nullptr_t = nullptr) noexcept {}
        IFileOpenPicker2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileOpenPicker3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFileOpenPicker3>
    {
        IFileOpenPicker3(std::nullptr_t = nullptr) noexcept {}
        IFileOpenPicker3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileOpenPickerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFileOpenPickerStatics>
    {
        IFileOpenPickerStatics(std::nullptr_t = nullptr) noexcept {}
        IFileOpenPickerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileOpenPickerStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFileOpenPickerStatics2>
    {
        IFileOpenPickerStatics2(std::nullptr_t = nullptr) noexcept {}
        IFileOpenPickerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileOpenPickerWithOperationId :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFileOpenPickerWithOperationId>
    {
        IFileOpenPickerWithOperationId(std::nullptr_t = nullptr) noexcept {}
        IFileOpenPickerWithOperationId(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileSavePicker :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFileSavePicker>
    {
        IFileSavePicker(std::nullptr_t = nullptr) noexcept {}
        IFileSavePicker(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileSavePicker2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFileSavePicker2>
    {
        IFileSavePicker2(std::nullptr_t = nullptr) noexcept {}
        IFileSavePicker2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileSavePicker3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFileSavePicker3>
    {
        IFileSavePicker3(std::nullptr_t = nullptr) noexcept {}
        IFileSavePicker3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileSavePicker4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFileSavePicker4>
    {
        IFileSavePicker4(std::nullptr_t = nullptr) noexcept {}
        IFileSavePicker4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileSavePickerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFileSavePickerStatics>
    {
        IFileSavePickerStatics(std::nullptr_t = nullptr) noexcept {}
        IFileSavePickerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFolderPicker :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFolderPicker>
    {
        IFolderPicker(std::nullptr_t = nullptr) noexcept {}
        IFolderPicker(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFolderPicker2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFolderPicker2>
    {
        IFolderPicker2(std::nullptr_t = nullptr) noexcept {}
        IFolderPicker2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFolderPicker3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFolderPicker3>
    {
        IFolderPicker3(std::nullptr_t = nullptr) noexcept {}
        IFolderPicker3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFolderPickerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFolderPickerStatics>
    {
        IFolderPickerStatics(std::nullptr_t = nullptr) noexcept {}
        IFolderPickerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
