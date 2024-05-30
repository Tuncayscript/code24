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
#ifndef LLM_OS_UI_Xaml_Printing_1_H
#define LLM_OS_UI_Xaml_Printing_1_H
#include "llm/impl/Windows.UI.Xaml.Printing.0.h"
LLM_EXPORT namespace llm::OS::UI::Xaml::Printing
{
    struct __declspec(empty_bases) IAddPagesEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAddPagesEventArgs>
    {
        IAddPagesEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAddPagesEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGetPreviewPageEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGetPreviewPageEventArgs>
    {
        IGetPreviewPageEventArgs(std::nullptr_t = nullptr) noexcept {}
        IGetPreviewPageEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPaginateEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPaginateEventArgs>
    {
        IPaginateEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPaginateEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintDocument :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintDocument>
    {
        IPrintDocument(std::nullptr_t = nullptr) noexcept {}
        IPrintDocument(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintDocumentFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintDocumentFactory>
    {
        IPrintDocumentFactory(std::nullptr_t = nullptr) noexcept {}
        IPrintDocumentFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintDocumentStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintDocumentStatics>
    {
        IPrintDocumentStatics(std::nullptr_t = nullptr) noexcept {}
        IPrintDocumentStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
