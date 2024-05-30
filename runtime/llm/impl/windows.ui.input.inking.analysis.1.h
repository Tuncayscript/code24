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
#ifndef LLM_OS_UI_Input_Inking_Analysis_1_H
#define LLM_OS_UI_Input_Inking_Analysis_1_H
#include "llm/impl/Windows.UI.Input.Inking.Analysis.0.h"
LLM_EXPORT namespace llm:OS::UI::Input::Inking::Analysis
{
    struct __declspec(empty_bases) IInkAnalysisInkBullet :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkAnalysisInkBullet>,
        impl::require<llm:OS::UI::Input::Inking::Analysis::IInkAnalysisInkBullet, llm:OS::UI::Input::Inking::Analysis::IInkAnalysisNode>
    {
        IInkAnalysisInkBullet(std::nullptr_t = nullptr) noexcept {}
        IInkAnalysisInkBullet(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkAnalysisInkDrawing :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkAnalysisInkDrawing>,
        impl::require<llm:OS::UI::Input::Inking::Analysis::IInkAnalysisInkDrawing, llm:OS::UI::Input::Inking::Analysis::IInkAnalysisNode>
    {
        IInkAnalysisInkDrawing(std::nullptr_t = nullptr) noexcept {}
        IInkAnalysisInkDrawing(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkAnalysisInkWord :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkAnalysisInkWord>,
        impl::require<llm:OS::UI::Input::Inking::Analysis::IInkAnalysisInkWord, llm:OS::UI::Input::Inking::Analysis::IInkAnalysisNode>
    {
        IInkAnalysisInkWord(std::nullptr_t = nullptr) noexcept {}
        IInkAnalysisInkWord(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkAnalysisLine :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkAnalysisLine>,
        impl::require<llm:OS::UI::Input::Inking::Analysis::IInkAnalysisLine, llm:OS::UI::Input::Inking::Analysis::IInkAnalysisNode>
    {
        IInkAnalysisLine(std::nullptr_t = nullptr) noexcept {}
        IInkAnalysisLine(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkAnalysisListItem :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkAnalysisListItem>,
        impl::require<llm:OS::UI::Input::Inking::Analysis::IInkAnalysisListItem, llm:OS::UI::Input::Inking::Analysis::IInkAnalysisNode>
    {
        IInkAnalysisListItem(std::nullptr_t = nullptr) noexcept {}
        IInkAnalysisListItem(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkAnalysisNode :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkAnalysisNode>
    {
        IInkAnalysisNode(std::nullptr_t = nullptr) noexcept {}
        IInkAnalysisNode(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkAnalysisParagraph :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkAnalysisParagraph>,
        impl::require<llm:OS::UI::Input::Inking::Analysis::IInkAnalysisParagraph, llm:OS::UI::Input::Inking::Analysis::IInkAnalysisNode>
    {
        IInkAnalysisParagraph(std::nullptr_t = nullptr) noexcept {}
        IInkAnalysisParagraph(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkAnalysisResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkAnalysisResult>
    {
        IInkAnalysisResult(std::nullptr_t = nullptr) noexcept {}
        IInkAnalysisResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkAnalysisRoot :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkAnalysisRoot>,
        impl::require<llm:OS::UI::Input::Inking::Analysis::IInkAnalysisRoot, llm:OS::UI::Input::Inking::Analysis::IInkAnalysisNode>
    {
        IInkAnalysisRoot(std::nullptr_t = nullptr) noexcept {}
        IInkAnalysisRoot(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkAnalysisWritingRegion :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkAnalysisWritingRegion>,
        impl::require<llm:OS::UI::Input::Inking::Analysis::IInkAnalysisWritingRegion, llm:OS::UI::Input::Inking::Analysis::IInkAnalysisNode>
    {
        IInkAnalysisWritingRegion(std::nullptr_t = nullptr) noexcept {}
        IInkAnalysisWritingRegion(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkAnalyzer :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkAnalyzer>
    {
        IInkAnalyzer(std::nullptr_t = nullptr) noexcept {}
        IInkAnalyzer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkAnalyzerFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkAnalyzerFactory>
    {
        IInkAnalyzerFactory(std::nullptr_t = nullptr) noexcept {}
        IInkAnalyzerFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
