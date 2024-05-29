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
#ifndef LLM_OS_Data_Html_0_H
#define LLM_OS_Data_Html_0_H
LLM_EXPORT namespace llm::OS::Data::Html
{
    struct IHtmlUtilities;
    struct HtmlUtilities;
}
namespace llm::impl
{
    template <> struct category<llm::OS::Data::Html::IHtmlUtilities>{ using type = interface_category; };
    template <> struct category<llm::OS::Data::Html::HtmlUtilities>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm::OS::Data::Html::HtmlUtilities> = L"Windows.Data.Html.HtmlUtilities";
    template <> inline constexpr auto& name_v<llm::OS::Data::Html::IHtmlUtilities> = L"Windows.Data.Html.IHtmlUtilities";
    template <> inline constexpr guid guid_v<llm::OS::Data::Html::IHtmlUtilities>{ 0xFEC00ADD,0x2399,0x4FAC,{ 0xB5,0xA7,0x05,0xE9,0xAC,0xD7,0x18,0x1D } }; // FEC00ADD-2399-4FAC-B5A7-05E9ACD7181D
    template <> struct abi<llm::OS::Data::Html::IHtmlUtilities>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall ConvertToText(void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Data_Html_IHtmlUtilities
    {
        LLM_IMPL_AUTO(hstring) ConvertToText(param::hstring const& html) const;
    };
    template <> struct consume<llm::OS::Data::Html::IHtmlUtilities>
    {
        template <typename D> using type = consume_Windows_Data_Html_IHtmlUtilities<D>;
    };
}
#endif
