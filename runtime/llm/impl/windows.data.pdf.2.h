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
#ifndef LLM_OS_Data_Pdf_2_H
#define LLM_OS_Data_Pdf_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Storage.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.Data.Pdf.1.h"
LLM_EXPORT namespace llm::OS::Data::Pdf
{
    struct __declspec(empty_bases) PdfDocument : llm::OS::Data::Pdf::IPdfDocument
    {
        PdfDocument(std::nullptr_t) noexcept {}
        PdfDocument(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Pdf::IPdfDocument(ptr, take_ownership_from_abi) {}
        static auto LoadFromFileAsync(llm::OS::Storage::IStorageFile const& file);
        static auto LoadFromFileAsync(llm::OS::Storage::IStorageFile const& file, param::hstring const& password);
        static auto LoadFromStreamAsync(llm::OS::Storage::Streams::IRandomAccessStream const& inputStream);
        static auto LoadFromStreamAsync(llm::OS::Storage::Streams::IRandomAccessStream const& inputStream, param::hstring const& password);
    };
    struct __declspec(empty_bases) PdfPage : llm::OS::Data::Pdf::IPdfPage,
        impl::require<PdfPage, llm::OS::Foundation::IClosable>
    {
        PdfPage(std::nullptr_t) noexcept {}
        PdfPage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Pdf::IPdfPage(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PdfPageDimensions : llm::OS::Data::Pdf::IPdfPageDimensions
    {
        PdfPageDimensions(std::nullptr_t) noexcept {}
        PdfPageDimensions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Pdf::IPdfPageDimensions(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PdfPageRenderOptions : llm::OS::Data::Pdf::IPdfPageRenderOptions
    {
        PdfPageRenderOptions(std::nullptr_t) noexcept {}
        PdfPageRenderOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Pdf::IPdfPageRenderOptions(ptr, take_ownership_from_abi) {}
        PdfPageRenderOptions();
    };
}
#endif
