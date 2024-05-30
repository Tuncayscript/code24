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
#ifndef LLM_OS_UI_Xaml_Automation_Text_0_H
#define LLM_OS_UI_Xaml_Automation_Text_0_H
LLM_EXPORT namespace llm::OS::UI::Xaml::Automation::Text
{
    enum class TextPatternRangeEndpoint : int32_t
    {
        Start = 0,
        End = 1,
    };
    enum class TextUnit : int32_t
    {
        Character = 0,
        Format = 1,
        Word = 2,
        Line = 3,
        Paragraph = 4,
        Page = 5,
        Document = 6,
    };
}
namespace llm::impl
{
    template <> struct category<llm::OS::UI::Xaml::Automation::Text::TextPatternRangeEndpoint>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::Automation::Text::TextUnit>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Automation::Text::TextPatternRangeEndpoint> = L"Windows.UI.Xaml.Automation.Text.TextPatternRangeEndpoint";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Automation::Text::TextUnit> = L"Windows.UI.Xaml.Automation.Text.TextUnit";
}
#endif
