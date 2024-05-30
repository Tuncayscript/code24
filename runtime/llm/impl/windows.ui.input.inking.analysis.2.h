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
#ifndef LLM_OS_UI_Input_Inking_Analysis_2_H
#define LLM_OS_UI_Input_Inking_Analysis_2_H
#include "llm/impl/Windows.UI.Input.Inking.Analysis.1.h"
LLM_EXPORT namespace llm:OS::UI::Input::Inking::Analysis
{
    struct __declspec(empty_bases) InkAnalysisInkBullet : llm:OS::UI::Input::Inking::Analysis::IInkAnalysisInkBullet
    {
        InkAnalysisInkBullet(std::nullptr_t) noexcept {}
        InkAnalysisInkBullet(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::Analysis::IInkAnalysisInkBullet(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InkAnalysisInkDrawing : llm:OS::UI::Input::Inking::Analysis::IInkAnalysisInkDrawing
    {
        InkAnalysisInkDrawing(std::nullptr_t) noexcept {}
        InkAnalysisInkDrawing(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::Analysis::IInkAnalysisInkDrawing(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InkAnalysisInkWord : llm:OS::UI::Input::Inking::Analysis::IInkAnalysisInkWord
    {
        InkAnalysisInkWord(std::nullptr_t) noexcept {}
        InkAnalysisInkWord(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::Analysis::IInkAnalysisInkWord(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InkAnalysisLine : llm:OS::UI::Input::Inking::Analysis::IInkAnalysisLine
    {
        InkAnalysisLine(std::nullptr_t) noexcept {}
        InkAnalysisLine(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::Analysis::IInkAnalysisLine(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InkAnalysisListItem : llm:OS::UI::Input::Inking::Analysis::IInkAnalysisListItem
    {
        InkAnalysisListItem(std::nullptr_t) noexcept {}
        InkAnalysisListItem(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::Analysis::IInkAnalysisListItem(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InkAnalysisNode : llm:OS::UI::Input::Inking::Analysis::IInkAnalysisNode
    {
        InkAnalysisNode(std::nullptr_t) noexcept {}
        InkAnalysisNode(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::Analysis::IInkAnalysisNode(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InkAnalysisParagraph : llm:OS::UI::Input::Inking::Analysis::IInkAnalysisParagraph
    {
        InkAnalysisParagraph(std::nullptr_t) noexcept {}
        InkAnalysisParagraph(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::Analysis::IInkAnalysisParagraph(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InkAnalysisResult : llm:OS::UI::Input::Inking::Analysis::IInkAnalysisResult
    {
        InkAnalysisResult(std::nullptr_t) noexcept {}
        InkAnalysisResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::Analysis::IInkAnalysisResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InkAnalysisRoot : llm:OS::UI::Input::Inking::Analysis::IInkAnalysisRoot
    {
        InkAnalysisRoot(std::nullptr_t) noexcept {}
        InkAnalysisRoot(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::Analysis::IInkAnalysisRoot(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InkAnalysisWritingRegion : llm:OS::UI::Input::Inking::Analysis::IInkAnalysisWritingRegion
    {
        InkAnalysisWritingRegion(std::nullptr_t) noexcept {}
        InkAnalysisWritingRegion(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::Analysis::IInkAnalysisWritingRegion(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InkAnalyzer : llm:OS::UI::Input::Inking::Analysis::IInkAnalyzer
    {
        InkAnalyzer(std::nullptr_t) noexcept {}
        InkAnalyzer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::Analysis::IInkAnalyzer(ptr, take_ownership_from_abi) {}
        InkAnalyzer();
    };
}
#endif
