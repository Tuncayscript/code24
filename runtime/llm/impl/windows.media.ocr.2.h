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
#ifndef LLM_OS_Media_Ocr_2_H
#define LLM_OS_Media_Ocr_2_H
#include "llm/impl/Windows.Globalization.1.h"
#include "llm/impl/Windows.Media.Ocr.1.h"
LLM_EXPORT namespace llm:OS::Media::Ocr
{
    struct __declspec(empty_bases) OcrEngine : llm:OS::Media::Ocr::IOcrEngine
    {
        OcrEngine(std::nullptr_t) noexcept {}
        OcrEngine(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Ocr::IOcrEngine(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto MaxImageDimension();
        [[nodiscard]] static auto AvailableRecognizerLanguages();
        static auto IsLanguageSupported(llm:OS::Globalization::Language const& language);
        static auto TryCreateFromLanguage(llm:OS::Globalization::Language const& language);
        static auto TryCreateFromUserProfileLanguages();
    };
    struct __declspec(empty_bases) OcrLine : llm:OS::Media::Ocr::IOcrLine
    {
        OcrLine(std::nullptr_t) noexcept {}
        OcrLine(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Ocr::IOcrLine(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) OcrResult : llm:OS::Media::Ocr::IOcrResult
    {
        OcrResult(std::nullptr_t) noexcept {}
        OcrResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Ocr::IOcrResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) OcrWord : llm:OS::Media::Ocr::IOcrWord
    {
        OcrWord(std::nullptr_t) noexcept {}
        OcrWord(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Ocr::IOcrWord(ptr, take_ownership_from_abi) {}
    };
}
#endif
