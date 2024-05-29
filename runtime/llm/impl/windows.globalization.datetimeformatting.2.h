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
#ifndef LLM_OS_Globalization_DateTimeFormatting_2_H
#define LLM_OS_Globalization_DateTimeFormatting_2_H
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Globalization.DateTimeFormatting.1.h"
LLM_EXPORT namespace llm:OS::Globalization::DateTimeFormatting
{
    struct __declspec(empty_bases) DateTimeFormatter : llm:OS::Globalization::DateTimeFormatting::IDateTimeFormatter,
        impl::require<DateTimeFormatter, llm:OS::Globalization::DateTimeFormatting::IDateTimeFormatter2>
    {
        DateTimeFormatter(std::nullptr_t) noexcept {}
        DateTimeFormatter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Globalization::DateTimeFormatting::IDateTimeFormatter(ptr, take_ownership_from_abi) {}
        explicit DateTimeFormatter(param::hstring const& formatTemplate);
        DateTimeFormatter(param::hstring const& formatTemplate, param::iterable<hstring> const& languages);
        DateTimeFormatter(param::hstring const& formatTemplate, param::iterable<hstring> const& languages, param::hstring const& geographicRegion, param::hstring const& calendar, param::hstring const& clock);
        DateTimeFormatter(llm:OS::Globalization::DateTimeFormatting::YearFormat const& yearFormat, llm:OS::Globalization::DateTimeFormatting::MonthFormat const& monthFormat, llm:OS::Globalization::DateTimeFormatting::DayFormat const& dayFormat, llm:OS::Globalization::DateTimeFormatting::DayOfWeekFormat const& dayOfWeekFormat);
        DateTimeFormatter(llm:OS::Globalization::DateTimeFormatting::HourFormat const& hourFormat, llm:OS::Globalization::DateTimeFormatting::MinuteFormat const& minuteFormat, llm:OS::Globalization::DateTimeFormatting::SecondFormat const& secondFormat);
        DateTimeFormatter(llm:OS::Globalization::DateTimeFormatting::YearFormat const& yearFormat, llm:OS::Globalization::DateTimeFormatting::MonthFormat const& monthFormat, llm:OS::Globalization::DateTimeFormatting::DayFormat const& dayFormat, llm:OS::Globalization::DateTimeFormatting::DayOfWeekFormat const& dayOfWeekFormat, llm:OS::Globalization::DateTimeFormatting::HourFormat const& hourFormat, llm:OS::Globalization::DateTimeFormatting::MinuteFormat const& minuteFormat, llm:OS::Globalization::DateTimeFormatting::SecondFormat const& secondFormat, param::iterable<hstring> const& languages);
        DateTimeFormatter(llm:OS::Globalization::DateTimeFormatting::YearFormat const& yearFormat, llm:OS::Globalization::DateTimeFormatting::MonthFormat const& monthFormat, llm:OS::Globalization::DateTimeFormatting::DayFormat const& dayFormat, llm:OS::Globalization::DateTimeFormatting::DayOfWeekFormat const& dayOfWeekFormat, llm:OS::Globalization::DateTimeFormatting::HourFormat const& hourFormat, llm:OS::Globalization::DateTimeFormatting::MinuteFormat const& minuteFormat, llm:OS::Globalization::DateTimeFormatting::SecondFormat const& secondFormat, param::iterable<hstring> const& languages, param::hstring const& geographicRegion, param::hstring const& calendar, param::hstring const& clock);
        using llm:OS::Globalization::DateTimeFormatting::IDateTimeFormatter::Format;
        using impl::consume_t<DateTimeFormatter, llm:OS::Globalization::DateTimeFormatting::IDateTimeFormatter2>::Format;
        [[nodiscard]] static auto LongDate();
        [[nodiscard]] static auto LongTime();
        [[nodiscard]] static auto ShortDate();
        [[nodiscard]] static auto ShortTime();
    };
}
#endif
