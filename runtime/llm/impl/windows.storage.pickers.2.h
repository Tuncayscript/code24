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
#ifndef LLM_OS_Storage_Pickers_2_H
#define LLM_OS_Storage_Pickers_2_H
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Storage.1.h"
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.Storage.Pickers.1.h"
LLM_EXPORT namespace llm:OS::Storage::Pickers
{
    struct __declspec(empty_bases) FileExtensionVector : llm:OS::Foundation::Collections::IVector<hstring>
    {
        FileExtensionVector(std::nullptr_t) noexcept {}
        FileExtensionVector(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::Collections::IVector<hstring>(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FileOpenPicker : llm:OS::Storage::Pickers::IFileOpenPicker,
        impl::require<FileOpenPicker, llm:OS::Storage::Pickers::IFileOpenPicker2, llm:OS::Storage::Pickers::IFileOpenPickerWithOperationId, llm:OS::Storage::Pickers::IFileOpenPicker3>
    {
        FileOpenPicker(std::nullptr_t) noexcept {}
        FileOpenPicker(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Pickers::IFileOpenPicker(ptr, take_ownership_from_abi) {}
        FileOpenPicker();
        using llm:OS::Storage::Pickers::IFileOpenPicker::PickSingleFileAsync;
        using impl::consume_t<FileOpenPicker, llm:OS::Storage::Pickers::IFileOpenPickerWithOperationId>::PickSingleFileAsync;
        static auto ResumePickSingleFileAsync();
        static auto CreateForUser(llm:OS::System::User const& user);
    };
    struct __declspec(empty_bases) FilePickerFileTypesOrderedMap : llm:OS::Foundation::Collections::IMap<hstring, llm:OS::Foundation::Collections::IVector<hstring>>
    {
        FilePickerFileTypesOrderedMap(std::nullptr_t) noexcept {}
        FilePickerFileTypesOrderedMap(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::Collections::IMap<hstring, llm:OS::Foundation::Collections::IVector<hstring>>(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FilePickerSelectedFilesArray : llm:OS::Foundation::Collections::IVectorView<llm:OS::Storage::StorageFile>
    {
        FilePickerSelectedFilesArray(std::nullptr_t) noexcept {}
        FilePickerSelectedFilesArray(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::Collections::IVectorView<llm:OS::Storage::StorageFile>(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FileSavePicker : llm:OS::Storage::Pickers::IFileSavePicker,
        impl::require<FileSavePicker, llm:OS::Storage::Pickers::IFileSavePicker2, llm:OS::Storage::Pickers::IFileSavePicker3, llm:OS::Storage::Pickers::IFileSavePicker4>
    {
        FileSavePicker(std::nullptr_t) noexcept {}
        FileSavePicker(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Pickers::IFileSavePicker(ptr, take_ownership_from_abi) {}
        FileSavePicker();
        static auto CreateForUser(llm:OS::System::User const& user);
    };
    struct __declspec(empty_bases) FolderPicker : llm:OS::Storage::Pickers::IFolderPicker,
        impl::require<FolderPicker, llm:OS::Storage::Pickers::IFolderPicker2, llm:OS::Storage::Pickers::IFolderPicker3>
    {
        FolderPicker(std::nullptr_t) noexcept {}
        FolderPicker(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Pickers::IFolderPicker(ptr, take_ownership_from_abi) {}
        FolderPicker();
        static auto CreateForUser(llm:OS::System::User const& user);
    };
}
#endif
