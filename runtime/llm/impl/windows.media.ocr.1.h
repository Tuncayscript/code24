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
#ifndef LLM_OS_Media_Ocr_1_H
#define LLM_OS_Media_Ocr_1_H
#include "llm/impl/Windows.Media.Ocr.0.h"
LLM_EXPORT namespace llm:OS::Media::Ocr
{
    struct __declspec(empty_bases) IOcrEngine :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IOcrEngine>
    {
        IOcrEngine(std::nullptr_t = nullptr) noexcept {}
        IOcrEngine(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IOcrEngineStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IOcrEngineStatics>
    {
        IOcrEngineStatics(std::nullptr_t = nullptr) noexcept {}
        IOcrEngineStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IOcrLine :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IOcrLine>
    {
        IOcrLine(std::nullptr_t = nullptr) noexcept {}
        IOcrLine(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IOcrResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IOcrResult>
    {
        IOcrResult(std::nullptr_t = nullptr) noexcept {}
        IOcrResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IOcrWord :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IOcrWord>
    {
        IOcrWord(std::nullptr_t = nullptr) noexcept {}
        IOcrWord(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
