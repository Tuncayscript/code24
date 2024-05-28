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
#ifndef LLM_OS_Globalization_DateTimeFormatting_H
#define LLM_OS_Globalization_DateTimeFormatting_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Globalization.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Globalization.DateTimeFormatting.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_Globalization_DateTimeFormatting_IDateTimeFormatter<D>::Languages() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatter)->get_Languages(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Globalization_DateTimeFormatting_IDateTimeFormatter<D>::GeographicRegion() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatter)->get_GeographicRegion(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Globalization_DateTimeFormatting_IDateTimeFormatter<D>::Calendar() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatter)->get_Calendar(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Globalization_DateTimeFormatting_IDateTimeFormatter<D>::Clock() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatter)->get_Clock(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Globalization_DateTimeFormatting_IDateTimeFormatter<D>::NumeralSystem() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatter)->get_NumeralSystem(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Globalization_DateTimeFormatting_IDateTimeFormatter<D>::NumeralSystem(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatter)->put_NumeralSystem(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_Globalization_DateTimeFormatting_IDateTimeFormatter<D>::Patterns() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatter)->get_Patterns(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Globalization_DateTimeFormatting_IDateTimeFormatter<D>::Template() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatter)->get_Template(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Globalization_DateTimeFormatting_IDateTimeFormatter<D>::Format(llm::OS::Foundation::DateTime const& value) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatter)->Format(impl::bind_in(value), &result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Globalization::DateTimeFormatting::YearFormat) consume_Windows_Globalization_DateTimeFormatting_IDateTimeFormatter<D>::IncludeYear() const
    {
        llm::OS::Globalization::DateTimeFormatting::YearFormat value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatter)->get_IncludeYear(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Globalization::DateTimeFormatting::MonthFormat) consume_Windows_Globalization_DateTimeFormatting_IDateTimeFormatter<D>::IncludeMonth() const
    {
        llm::OS::Globalization::DateTimeFormatting::MonthFormat value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatter)->get_IncludeMonth(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Globalization::DateTimeFormatting::DayOfWeekFormat) consume_Windows_Globalization_DateTimeFormatting_IDateTimeFormatter<D>::IncludeDayOfWeek() const
    {
        llm::OS::Globalization::DateTimeFormatting::DayOfWeekFormat value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatter)->get_IncludeDayOfWeek(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Globalization::DateTimeFormatting::DayFormat) consume_Windows_Globalization_DateTimeFormatting_IDateTimeFormatter<D>::IncludeDay() const
    {
        llm::OS::Globalization::DateTimeFormatting::DayFormat value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatter)->get_IncludeDay(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Globalization::DateTimeFormatting::HourFormat) consume_Windows_Globalization_DateTimeFormatting_IDateTimeFormatter<D>::IncludeHour() const
    {
        llm::OS::Globalization::DateTimeFormatting::HourFormat value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatter)->get_IncludeHour(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Globalization::DateTimeFormatting::MinuteFormat) consume_Windows_Globalization_DateTimeFormatting_IDateTimeFormatter<D>::IncludeMinute() const
    {
        llm::OS::Globalization::DateTimeFormatting::MinuteFormat value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatter)->get_IncludeMinute(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Globalization::DateTimeFormatting::SecondFormat) consume_Windows_Globalization_DateTimeFormatting_IDateTimeFormatter<D>::IncludeSecond() const
    {
        llm::OS::Globalization::DateTimeFormatting::SecondFormat value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatter)->get_IncludeSecond(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Globalization_DateTimeFormatting_IDateTimeFormatter<D>::ResolvedLanguage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatter)->get_ResolvedLanguage(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Globalization_DateTimeFormatting_IDateTimeFormatter<D>::ResolvedGeographicRegion() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatter)->get_ResolvedGeographicRegion(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Globalization_DateTimeFormatting_IDateTimeFormatter2<D>::Format(llm::OS::Foundation::DateTime const& datetime, param::hstring const& timeZoneId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatter2)->FormatUsingTimeZone(impl::bind_in(datetime), *(void**)(&timeZoneId), &result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter) consume_Windows_Globalization_DateTimeFormatting_IDateTimeFormatterFactory<D>::CreateDateTimeFormatter(param::hstring const& formatTemplate) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatterFactory)->CreateDateTimeFormatter(*(void**)(&formatTemplate), &result));
        return llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter) consume_Windows_Globalization_DateTimeFormatting_IDateTimeFormatterFactory<D>::CreateDateTimeFormatterLanguages(param::hstring const& formatTemplate, param::iterable<hstring> const& languages) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatterFactory)->CreateDateTimeFormatterLanguages(*(void**)(&formatTemplate), *(void**)(&languages), &result));
        return llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter) consume_Windows_Globalization_DateTimeFormatting_IDateTimeFormatterFactory<D>::CreateDateTimeFormatterContext(param::hstring const& formatTemplate, param::iterable<hstring> const& languages, param::hstring const& geographicRegion, param::hstring const& calendar, param::hstring const& clock) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatterFactory)->CreateDateTimeFormatterContext(*(void**)(&formatTemplate), *(void**)(&languages), *(void**)(&geographicRegion), *(void**)(&calendar), *(void**)(&clock), &result));
        return llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter) consume_Windows_Globalization_DateTimeFormatting_IDateTimeFormatterFactory<D>::CreateDateTimeFormatterDate(llm::OS::Globalization::DateTimeFormatting::YearFormat const& yearFormat, llm::OS::Globalization::DateTimeFormatting::MonthFormat const& monthFormat, llm::OS::Globalization::DateTimeFormatting::DayFormat const& dayFormat, llm::OS::Globalization::DateTimeFormatting::DayOfWeekFormat const& dayOfWeekFormat) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatterFactory)->CreateDateTimeFormatterDate(static_cast<int32_t>(yearFormat), static_cast<int32_t>(monthFormat), static_cast<int32_t>(dayFormat), static_cast<int32_t>(dayOfWeekFormat), &result));
        return llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter) consume_Windows_Globalization_DateTimeFormatting_IDateTimeFormatterFactory<D>::CreateDateTimeFormatterTime(llm::OS::Globalization::DateTimeFormatting::HourFormat const& hourFormat, llm::OS::Globalization::DateTimeFormatting::MinuteFormat const& minuteFormat, llm::OS::Globalization::DateTimeFormatting::SecondFormat const& secondFormat) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatterFactory)->CreateDateTimeFormatterTime(static_cast<int32_t>(hourFormat), static_cast<int32_t>(minuteFormat), static_cast<int32_t>(secondFormat), &result));
        return llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter) consume_Windows_Globalization_DateTimeFormatting_IDateTimeFormatterFactory<D>::CreateDateTimeFormatterDateTimeLanguages(llm::OS::Globalization::DateTimeFormatting::YearFormat const& yearFormat, llm::OS::Globalization::DateTimeFormatting::MonthFormat const& monthFormat, llm::OS::Globalization::DateTimeFormatting::DayFormat const& dayFormat, llm::OS::Globalization::DateTimeFormatting::DayOfWeekFormat const& dayOfWeekFormat, llm::OS::Globalization::DateTimeFormatting::HourFormat const& hourFormat, llm::OS::Globalization::DateTimeFormatting::MinuteFormat const& minuteFormat, llm::OS::Globalization::DateTimeFormatting::SecondFormat const& secondFormat, param::iterable<hstring> const& languages) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatterFactory)->CreateDateTimeFormatterDateTimeLanguages(static_cast<int32_t>(yearFormat), static_cast<int32_t>(monthFormat), static_cast<int32_t>(dayFormat), static_cast<int32_t>(dayOfWeekFormat), static_cast<int32_t>(hourFormat), static_cast<int32_t>(minuteFormat), static_cast<int32_t>(secondFormat), *(void**)(&languages), &result));
        return llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter) consume_Windows_Globalization_DateTimeFormatting_IDateTimeFormatterFactory<D>::CreateDateTimeFormatterDateTimeContext(llm::OS::Globalization::DateTimeFormatting::YearFormat const& yearFormat, llm::OS::Globalization::DateTimeFormatting::MonthFormat const& monthFormat, llm::OS::Globalization::DateTimeFormatting::DayFormat const& dayFormat, llm::OS::Globalization::DateTimeFormatting::DayOfWeekFormat const& dayOfWeekFormat, llm::OS::Globalization::DateTimeFormatting::HourFormat const& hourFormat, llm::OS::Globalization::DateTimeFormatting::MinuteFormat const& minuteFormat, llm::OS::Globalization::DateTimeFormatting::SecondFormat const& secondFormat, param::iterable<hstring> const& languages, param::hstring const& geographicRegion, param::hstring const& calendar, param::hstring const& clock) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatterFactory)->CreateDateTimeFormatterDateTimeContext(static_cast<int32_t>(yearFormat), static_cast<int32_t>(monthFormat), static_cast<int32_t>(dayFormat), static_cast<int32_t>(dayOfWeekFormat), static_cast<int32_t>(hourFormat), static_cast<int32_t>(minuteFormat), static_cast<int32_t>(secondFormat), *(void**)(&languages), *(void**)(&geographicRegion), *(void**)(&calendar), *(void**)(&clock), &result));
        return llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter) consume_Windows_Globalization_DateTimeFormatting_IDateTimeFormatterStatics<D>::LongDate() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatterStatics)->get_LongDate(&value));
        return llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter) consume_Windows_Globalization_DateTimeFormatting_IDateTimeFormatterStatics<D>::LongTime() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatterStatics)->get_LongTime(&value));
        return llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter) consume_Windows_Globalization_DateTimeFormatting_IDateTimeFormatterStatics<D>::ShortDate() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatterStatics)->get_ShortDate(&value));
        return llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter) consume_Windows_Globalization_DateTimeFormatting_IDateTimeFormatterStatics<D>::ShortTime() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatterStatics)->get_ShortTime(&value));
        return llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatter> : produce_base<D, llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatter>
    {
        int32_t __stdcall get_Languages(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().Languages());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_GeographicRegion(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().GeographicRegion());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Calendar(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Calendar());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Clock(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Clock());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NumeralSystem(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().NumeralSystem());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_NumeralSystem(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NumeralSystem(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Patterns(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().Patterns());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Template(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Template());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Format(int64_t value, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().Format(*reinterpret_cast<llm::OS::Foundation::DateTime const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IncludeYear(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Globalization::DateTimeFormatting::YearFormat>(this->shim().IncludeYear());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IncludeMonth(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Globalization::DateTimeFormatting::MonthFormat>(this->shim().IncludeMonth());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IncludeDayOfWeek(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Globalization::DateTimeFormatting::DayOfWeekFormat>(this->shim().IncludeDayOfWeek());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IncludeDay(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Globalization::DateTimeFormatting::DayFormat>(this->shim().IncludeDay());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IncludeHour(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Globalization::DateTimeFormatting::HourFormat>(this->shim().IncludeHour());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IncludeMinute(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Globalization::DateTimeFormatting::MinuteFormat>(this->shim().IncludeMinute());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IncludeSecond(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Globalization::DateTimeFormatting::SecondFormat>(this->shim().IncludeSecond());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResolvedLanguage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ResolvedLanguage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResolvedGeographicRegion(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ResolvedGeographicRegion());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatter2> : produce_base<D, llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatter2>
    {
        int32_t __stdcall FormatUsingTimeZone(int64_t datetime, void* timeZoneId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().Format(*reinterpret_cast<llm::OS::Foundation::DateTime const*>(&datetime), *reinterpret_cast<hstring const*>(&timeZoneId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatterFactory> : produce_base<D, llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatterFactory>
    {
        int32_t __stdcall CreateDateTimeFormatter(void* formatTemplate, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter>(this->shim().CreateDateTimeFormatter(*reinterpret_cast<hstring const*>(&formatTemplate)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateDateTimeFormatterLanguages(void* formatTemplate, void* languages, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter>(this->shim().CreateDateTimeFormatterLanguages(*reinterpret_cast<hstring const*>(&formatTemplate), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&languages)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateDateTimeFormatterContext(void* formatTemplate, void* languages, void* geographicRegion, void* calendar, void* clock, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter>(this->shim().CreateDateTimeFormatterContext(*reinterpret_cast<hstring const*>(&formatTemplate), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&languages), *reinterpret_cast<hstring const*>(&geographicRegion), *reinterpret_cast<hstring const*>(&calendar), *reinterpret_cast<hstring const*>(&clock)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateDateTimeFormatterDate(int32_t yearFormat, int32_t monthFormat, int32_t dayFormat, int32_t dayOfWeekFormat, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter>(this->shim().CreateDateTimeFormatterDate(*reinterpret_cast<llm::OS::Globalization::DateTimeFormatting::YearFormat const*>(&yearFormat), *reinterpret_cast<llm::OS::Globalization::DateTimeFormatting::MonthFormat const*>(&monthFormat), *reinterpret_cast<llm::OS::Globalization::DateTimeFormatting::DayFormat const*>(&dayFormat), *reinterpret_cast<llm::OS::Globalization::DateTimeFormatting::DayOfWeekFormat const*>(&dayOfWeekFormat)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateDateTimeFormatterTime(int32_t hourFormat, int32_t minuteFormat, int32_t secondFormat, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter>(this->shim().CreateDateTimeFormatterTime(*reinterpret_cast<llm::OS::Globalization::DateTimeFormatting::HourFormat const*>(&hourFormat), *reinterpret_cast<llm::OS::Globalization::DateTimeFormatting::MinuteFormat const*>(&minuteFormat), *reinterpret_cast<llm::OS::Globalization::DateTimeFormatting::SecondFormat const*>(&secondFormat)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateDateTimeFormatterDateTimeLanguages(int32_t yearFormat, int32_t monthFormat, int32_t dayFormat, int32_t dayOfWeekFormat, int32_t hourFormat, int32_t minuteFormat, int32_t secondFormat, void* languages, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter>(this->shim().CreateDateTimeFormatterDateTimeLanguages(*reinterpret_cast<llm::OS::Globalization::DateTimeFormatting::YearFormat const*>(&yearFormat), *reinterpret_cast<llm::OS::Globalization::DateTimeFormatting::MonthFormat const*>(&monthFormat), *reinterpret_cast<llm::OS::Globalization::DateTimeFormatting::DayFormat const*>(&dayFormat), *reinterpret_cast<llm::OS::Globalization::DateTimeFormatting::DayOfWeekFormat const*>(&dayOfWeekFormat), *reinterpret_cast<llm::OS::Globalization::DateTimeFormatting::HourFormat const*>(&hourFormat), *reinterpret_cast<llm::OS::Globalization::DateTimeFormatting::MinuteFormat const*>(&minuteFormat), *reinterpret_cast<llm::OS::Globalization::DateTimeFormatting::SecondFormat const*>(&secondFormat), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&languages)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateDateTimeFormatterDateTimeContext(int32_t yearFormat, int32_t monthFormat, int32_t dayFormat, int32_t dayOfWeekFormat, int32_t hourFormat, int32_t minuteFormat, int32_t secondFormat, void* languages, void* geographicRegion, void* calendar, void* clock, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter>(this->shim().CreateDateTimeFormatterDateTimeContext(*reinterpret_cast<llm::OS::Globalization::DateTimeFormatting::YearFormat const*>(&yearFormat), *reinterpret_cast<llm::OS::Globalization::DateTimeFormatting::MonthFormat const*>(&monthFormat), *reinterpret_cast<llm::OS::Globalization::DateTimeFormatting::DayFormat const*>(&dayFormat), *reinterpret_cast<llm::OS::Globalization::DateTimeFormatting::DayOfWeekFormat const*>(&dayOfWeekFormat), *reinterpret_cast<llm::OS::Globalization::DateTimeFormatting::HourFormat const*>(&hourFormat), *reinterpret_cast<llm::OS::Globalization::DateTimeFormatting::MinuteFormat const*>(&minuteFormat), *reinterpret_cast<llm::OS::Globalization::DateTimeFormatting::SecondFormat const*>(&secondFormat), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&languages), *reinterpret_cast<hstring const*>(&geographicRegion), *reinterpret_cast<hstring const*>(&calendar), *reinterpret_cast<hstring const*>(&clock)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatterStatics> : produce_base<D, llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatterStatics>
    {
        int32_t __stdcall get_LongDate(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter>(this->shim().LongDate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LongTime(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter>(this->shim().LongTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ShortDate(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter>(this->shim().ShortDate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ShortTime(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter>(this->shim().ShortTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Globalization::DateTimeFormatting
{
    inline DateTimeFormatter::DateTimeFormatter(param::hstring const& formatTemplate) :
        DateTimeFormatter(impl::call_factory<DateTimeFormatter, IDateTimeFormatterFactory>([&](IDateTimeFormatterFactory const& f) { return f.CreateDateTimeFormatter(formatTemplate); }))
    {
    }
    inline DateTimeFormatter::DateTimeFormatter(param::hstring const& formatTemplate, param::iterable<hstring> const& languages) :
        DateTimeFormatter(impl::call_factory<DateTimeFormatter, IDateTimeFormatterFactory>([&](IDateTimeFormatterFactory const& f) { return f.CreateDateTimeFormatterLanguages(formatTemplate, languages); }))
    {
    }
    inline DateTimeFormatter::DateTimeFormatter(param::hstring const& formatTemplate, param::iterable<hstring> const& languages, param::hstring const& geographicRegion, param::hstring const& calendar, param::hstring const& clock) :
        DateTimeFormatter(impl::call_factory<DateTimeFormatter, IDateTimeFormatterFactory>([&](IDateTimeFormatterFactory const& f) { return f.CreateDateTimeFormatterContext(formatTemplate, languages, geographicRegion, calendar, clock); }))
    {
    }
    inline DateTimeFormatter::DateTimeFormatter(llm::OS::Globalization::DateTimeFormatting::YearFormat const& yearFormat, llm::OS::Globalization::DateTimeFormatting::MonthFormat const& monthFormat, llm::OS::Globalization::DateTimeFormatting::DayFormat const& dayFormat, llm::OS::Globalization::DateTimeFormatting::DayOfWeekFormat const& dayOfWeekFormat) :
        DateTimeFormatter(impl::call_factory<DateTimeFormatter, IDateTimeFormatterFactory>([&](IDateTimeFormatterFactory const& f) { return f.CreateDateTimeFormatterDate(yearFormat, monthFormat, dayFormat, dayOfWeekFormat); }))
    {
    }
    inline DateTimeFormatter::DateTimeFormatter(llm::OS::Globalization::DateTimeFormatting::HourFormat const& hourFormat, llm::OS::Globalization::DateTimeFormatting::MinuteFormat const& minuteFormat, llm::OS::Globalization::DateTimeFormatting::SecondFormat const& secondFormat) :
        DateTimeFormatter(impl::call_factory<DateTimeFormatter, IDateTimeFormatterFactory>([&](IDateTimeFormatterFactory const& f) { return f.CreateDateTimeFormatterTime(hourFormat, minuteFormat, secondFormat); }))
    {
    }
    inline DateTimeFormatter::DateTimeFormatter(llm::OS::Globalization::DateTimeFormatting::YearFormat const& yearFormat, llm::OS::Globalization::DateTimeFormatting::MonthFormat const& monthFormat, llm::OS::Globalization::DateTimeFormatting::DayFormat const& dayFormat, llm::OS::Globalization::DateTimeFormatting::DayOfWeekFormat const& dayOfWeekFormat, llm::OS::Globalization::DateTimeFormatting::HourFormat const& hourFormat, llm::OS::Globalization::DateTimeFormatting::MinuteFormat const& minuteFormat, llm::OS::Globalization::DateTimeFormatting::SecondFormat const& secondFormat, param::iterable<hstring> const& languages) :
        DateTimeFormatter(impl::call_factory<DateTimeFormatter, IDateTimeFormatterFactory>([&](IDateTimeFormatterFactory const& f) { return f.CreateDateTimeFormatterDateTimeLanguages(yearFormat, monthFormat, dayFormat, dayOfWeekFormat, hourFormat, minuteFormat, secondFormat, languages); }))
    {
    }
    inline DateTimeFormatter::DateTimeFormatter(llm::OS::Globalization::DateTimeFormatting::YearFormat const& yearFormat, llm::OS::Globalization::DateTimeFormatting::MonthFormat const& monthFormat, llm::OS::Globalization::DateTimeFormatting::DayFormat const& dayFormat, llm::OS::Globalization::DateTimeFormatting::DayOfWeekFormat const& dayOfWeekFormat, llm::OS::Globalization::DateTimeFormatting::HourFormat const& hourFormat, llm::OS::Globalization::DateTimeFormatting::MinuteFormat const& minuteFormat, llm::OS::Globalization::DateTimeFormatting::SecondFormat const& secondFormat, param::iterable<hstring> const& languages, param::hstring const& geographicRegion, param::hstring const& calendar, param::hstring const& clock) :
        DateTimeFormatter(impl::call_factory<DateTimeFormatter, IDateTimeFormatterFactory>([&](IDateTimeFormatterFactory const& f) { return f.CreateDateTimeFormatterDateTimeContext(yearFormat, monthFormat, dayFormat, dayOfWeekFormat, hourFormat, minuteFormat, secondFormat, languages, geographicRegion, calendar, clock); }))
    {
    }
    inline auto DateTimeFormatter::LongDate()
    {
        return impl::call_factory_cast<llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter(*)(IDateTimeFormatterStatics const&), DateTimeFormatter, IDateTimeFormatterStatics>([](IDateTimeFormatterStatics const& f) { return f.LongDate(); });
    }
    inline auto DateTimeFormatter::LongTime()
    {
        return impl::call_factory_cast<llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter(*)(IDateTimeFormatterStatics const&), DateTimeFormatter, IDateTimeFormatterStatics>([](IDateTimeFormatterStatics const& f) { return f.LongTime(); });
    }
    inline auto DateTimeFormatter::ShortDate()
    {
        return impl::call_factory_cast<llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter(*)(IDateTimeFormatterStatics const&), DateTimeFormatter, IDateTimeFormatterStatics>([](IDateTimeFormatterStatics const& f) { return f.ShortDate(); });
    }
    inline auto DateTimeFormatter::ShortTime()
    {
        return impl::call_factory_cast<llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter(*)(IDateTimeFormatterStatics const&), DateTimeFormatter, IDateTimeFormatterStatics>([](IDateTimeFormatterStatics const& f) { return f.ShortTime(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatter2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatterFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Globalization::DateTimeFormatting::IDateTimeFormatterStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Globalization::DateTimeFormatting::DateTimeFormatter> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
