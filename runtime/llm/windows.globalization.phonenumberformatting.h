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
#ifndef LLM_OS_Globalization_PhoneNumberFormatting_H
#define LLM_OS_Globalization_PhoneNumberFormatting_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Globalization.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Globalization.PhoneNumberFormatting.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Globalization_PhoneNumberFormatting_IPhoneNumberFormatter<D>::Format(llm::OS::Globalization::PhoneNumberFormatting::PhoneNumberInfo const& number) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberFormatter)->Format(*(void**)(&number), &result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Globalization_PhoneNumberFormatting_IPhoneNumberFormatter<D>::Format(llm::OS::Globalization::PhoneNumberFormatting::PhoneNumberInfo const& number, llm::OS::Globalization::PhoneNumberFormatting::PhoneNumberFormat const& numberFormat) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberFormatter)->FormatWithOutputFormat(*(void**)(&number), static_cast<int32_t>(numberFormat), &result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Globalization_PhoneNumberFormatting_IPhoneNumberFormatter<D>::FormatPartialString(param::hstring const& number) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberFormatter)->FormatPartialString(*(void**)(&number), &result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Globalization_PhoneNumberFormatting_IPhoneNumberFormatter<D>::FormatString(param::hstring const& number) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberFormatter)->FormatString(*(void**)(&number), &result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Globalization_PhoneNumberFormatting_IPhoneNumberFormatter<D>::FormatStringWithLeftToRightMarkers(param::hstring const& number) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberFormatter)->FormatStringWithLeftToRightMarkers(*(void**)(&number), &result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Globalization_PhoneNumberFormatting_IPhoneNumberFormatterStatics<D>::TryCreate(param::hstring const& regionCode, llm::OS::Globalization::PhoneNumberFormatting::PhoneNumberFormatter& phoneNumber) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberFormatterStatics)->TryCreate(*(void**)(&regionCode), impl::bind_out(phoneNumber)));
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Globalization_PhoneNumberFormatting_IPhoneNumberFormatterStatics<D>::GetCountryCodeForRegion(param::hstring const& regionCode) const
    {
        int32_t result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberFormatterStatics)->GetCountryCodeForRegion(*(void**)(&regionCode), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Globalization_PhoneNumberFormatting_IPhoneNumberFormatterStatics<D>::GetNationalDirectDialingPrefixForRegion(param::hstring const& regionCode, bool stripNonDigit) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberFormatterStatics)->GetNationalDirectDialingPrefixForRegion(*(void**)(&regionCode), stripNonDigit, &result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Globalization_PhoneNumberFormatting_IPhoneNumberFormatterStatics<D>::WrapWithLeftToRightMarkers(param::hstring const& number) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberFormatterStatics)->WrapWithLeftToRightMarkers(*(void**)(&number), &result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Globalization_PhoneNumberFormatting_IPhoneNumberInfo<D>::CountryCode() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberInfo)->get_CountryCode(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Globalization_PhoneNumberFormatting_IPhoneNumberInfo<D>::PhoneNumber() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberInfo)->get_PhoneNumber(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Globalization_PhoneNumberFormatting_IPhoneNumberInfo<D>::GetLengthOfGeographicalAreaCode() const
    {
        int32_t result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberInfo)->GetLengthOfGeographicalAreaCode(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Globalization_PhoneNumberFormatting_IPhoneNumberInfo<D>::GetNationalSignificantNumber() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberInfo)->GetNationalSignificantNumber(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Globalization_PhoneNumberFormatting_IPhoneNumberInfo<D>::GetLengthOfNationalDestinationCode() const
    {
        int32_t result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberInfo)->GetLengthOfNationalDestinationCode(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Globalization::PhoneNumberFormatting::PredictedPhoneNumberKind) consume_Windows_Globalization_PhoneNumberFormatting_IPhoneNumberInfo<D>::PredictNumberKind() const
    {
        llm::OS::Globalization::PhoneNumberFormatting::PredictedPhoneNumberKind result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberInfo)->PredictNumberKind(reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Globalization_PhoneNumberFormatting_IPhoneNumberInfo<D>::GetGeographicRegionCode() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberInfo)->GetGeographicRegionCode(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Globalization::PhoneNumberFormatting::PhoneNumberMatchResult) consume_Windows_Globalization_PhoneNumberFormatting_IPhoneNumberInfo<D>::CheckNumberMatch(llm::OS::Globalization::PhoneNumberFormatting::PhoneNumberInfo const& otherNumber) const
    {
        llm::OS::Globalization::PhoneNumberFormatting::PhoneNumberMatchResult result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberInfo)->CheckNumberMatch(*(void**)(&otherNumber), reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Globalization::PhoneNumberFormatting::PhoneNumberInfo) consume_Windows_Globalization_PhoneNumberFormatting_IPhoneNumberInfoFactory<D>::Create(param::hstring const& number) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberInfoFactory)->Create(*(void**)(&number), &result));
        return llm::OS::Globalization::PhoneNumberFormatting::PhoneNumberInfo{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Globalization::PhoneNumberFormatting::PhoneNumberParseResult) consume_Windows_Globalization_PhoneNumberFormatting_IPhoneNumberInfoStatics<D>::TryParse(param::hstring const& input, llm::OS::Globalization::PhoneNumberFormatting::PhoneNumberInfo& phoneNumber) const
    {
        llm::OS::Globalization::PhoneNumberFormatting::PhoneNumberParseResult result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberInfoStatics)->TryParse(*(void**)(&input), impl::bind_out(phoneNumber), reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Globalization::PhoneNumberFormatting::PhoneNumberParseResult) consume_Windows_Globalization_PhoneNumberFormatting_IPhoneNumberInfoStatics<D>::TryParse(param::hstring const& input, param::hstring const& regionCode, llm::OS::Globalization::PhoneNumberFormatting::PhoneNumberInfo& phoneNumber) const
    {
        llm::OS::Globalization::PhoneNumberFormatting::PhoneNumberParseResult result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberInfoStatics)->TryParseWithRegion(*(void**)(&input), *(void**)(&regionCode), impl::bind_out(phoneNumber), reinterpret_cast<int32_t*>(&result)));
        return result;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberFormatter> : produce_base<D, llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberFormatter>
    {
        int32_t __stdcall Format(void* number, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().Format(*reinterpret_cast<llm::OS::Globalization::PhoneNumberFormatting::PhoneNumberInfo const*>(&number)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FormatWithOutputFormat(void* number, int32_t numberFormat, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().Format(*reinterpret_cast<llm::OS::Globalization::PhoneNumberFormatting::PhoneNumberInfo const*>(&number), *reinterpret_cast<llm::OS::Globalization::PhoneNumberFormatting::PhoneNumberFormat const*>(&numberFormat)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FormatPartialString(void* number, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().FormatPartialString(*reinterpret_cast<hstring const*>(&number)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FormatString(void* number, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().FormatString(*reinterpret_cast<hstring const*>(&number)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FormatStringWithLeftToRightMarkers(void* number, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().FormatStringWithLeftToRightMarkers(*reinterpret_cast<hstring const*>(&number)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberFormatterStatics> : produce_base<D, llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberFormatterStatics>
    {
        int32_t __stdcall TryCreate(void* regionCode, void** phoneNumber) noexcept final try
        {
            clear_abi(phoneNumber);
            typename D::abi_guard guard(this->shim());
            this->shim().TryCreate(*reinterpret_cast<hstring const*>(&regionCode), *reinterpret_cast<llm::OS::Globalization::PhoneNumberFormatting::PhoneNumberFormatter*>(phoneNumber));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetCountryCodeForRegion(void* regionCode, int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<int32_t>(this->shim().GetCountryCodeForRegion(*reinterpret_cast<hstring const*>(&regionCode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetNationalDirectDialingPrefixForRegion(void* regionCode, bool stripNonDigit, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetNationalDirectDialingPrefixForRegion(*reinterpret_cast<hstring const*>(&regionCode), stripNonDigit));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall WrapWithLeftToRightMarkers(void* number, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().WrapWithLeftToRightMarkers(*reinterpret_cast<hstring const*>(&number)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberInfo> : produce_base<D, llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberInfo>
    {
        int32_t __stdcall get_CountryCode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().CountryCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PhoneNumber(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().PhoneNumber());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetLengthOfGeographicalAreaCode(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<int32_t>(this->shim().GetLengthOfGeographicalAreaCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetNationalSignificantNumber(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetNationalSignificantNumber());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetLengthOfNationalDestinationCode(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<int32_t>(this->shim().GetLengthOfNationalDestinationCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall PredictNumberKind(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Globalization::PhoneNumberFormatting::PredictedPhoneNumberKind>(this->shim().PredictNumberKind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetGeographicRegionCode(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetGeographicRegionCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CheckNumberMatch(void* otherNumber, int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Globalization::PhoneNumberFormatting::PhoneNumberMatchResult>(this->shim().CheckNumberMatch(*reinterpret_cast<llm::OS::Globalization::PhoneNumberFormatting::PhoneNumberInfo const*>(&otherNumber)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberInfoFactory> : produce_base<D, llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberInfoFactory>
    {
        int32_t __stdcall Create(void* number, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Globalization::PhoneNumberFormatting::PhoneNumberInfo>(this->shim().Create(*reinterpret_cast<hstring const*>(&number)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberInfoStatics> : produce_base<D, llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberInfoStatics>
    {
        int32_t __stdcall TryParse(void* input, void** phoneNumber, int32_t* result) noexcept final try
        {
            clear_abi(phoneNumber);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Globalization::PhoneNumberFormatting::PhoneNumberParseResult>(this->shim().TryParse(*reinterpret_cast<hstring const*>(&input), *reinterpret_cast<llm::OS::Globalization::PhoneNumberFormatting::PhoneNumberInfo*>(phoneNumber)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryParseWithRegion(void* input, void* regionCode, void** phoneNumber, int32_t* result) noexcept final try
        {
            clear_abi(phoneNumber);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Globalization::PhoneNumberFormatting::PhoneNumberParseResult>(this->shim().TryParse(*reinterpret_cast<hstring const*>(&input), *reinterpret_cast<hstring const*>(&regionCode), *reinterpret_cast<llm::OS::Globalization::PhoneNumberFormatting::PhoneNumberInfo*>(phoneNumber)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Globalization::PhoneNumberFormatting
{
    inline PhoneNumberFormatter::PhoneNumberFormatter() :
        PhoneNumberFormatter(impl::call_factory_cast<PhoneNumberFormatter(*)(llm::OS::Foundation::IActivationFactory const&), PhoneNumberFormatter>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<PhoneNumberFormatter>(); }))
    {
    }
    inline auto PhoneNumberFormatter::TryCreate(param::hstring const& regionCode, llm::OS::Globalization::PhoneNumberFormatting::PhoneNumberFormatter& phoneNumber)
    {
        impl::call_factory<PhoneNumberFormatter, IPhoneNumberFormatterStatics>([&](IPhoneNumberFormatterStatics const& f) { return f.TryCreate(regionCode, phoneNumber); });
    }
    inline auto PhoneNumberFormatter::GetCountryCodeForRegion(param::hstring const& regionCode)
    {
        return impl::call_factory<PhoneNumberFormatter, IPhoneNumberFormatterStatics>([&](IPhoneNumberFormatterStatics const& f) { return f.GetCountryCodeForRegion(regionCode); });
    }
    inline auto PhoneNumberFormatter::GetNationalDirectDialingPrefixForRegion(param::hstring const& regionCode, bool stripNonDigit)
    {
        return impl::call_factory<PhoneNumberFormatter, IPhoneNumberFormatterStatics>([&](IPhoneNumberFormatterStatics const& f) { return f.GetNationalDirectDialingPrefixForRegion(regionCode, stripNonDigit); });
    }
    inline auto PhoneNumberFormatter::WrapWithLeftToRightMarkers(param::hstring const& number)
    {
        return impl::call_factory<PhoneNumberFormatter, IPhoneNumberFormatterStatics>([&](IPhoneNumberFormatterStatics const& f) { return f.WrapWithLeftToRightMarkers(number); });
    }
    inline PhoneNumberInfo::PhoneNumberInfo(param::hstring const& number) :
        PhoneNumberInfo(impl::call_factory<PhoneNumberInfo, IPhoneNumberInfoFactory>([&](IPhoneNumberInfoFactory const& f) { return f.Create(number); }))
    {
    }
    inline auto PhoneNumberInfo::TryParse(param::hstring const& input, llm::OS::Globalization::PhoneNumberFormatting::PhoneNumberInfo& phoneNumber)
    {
        return impl::call_factory<PhoneNumberInfo, IPhoneNumberInfoStatics>([&](IPhoneNumberInfoStatics const& f) { return f.TryParse(input, phoneNumber); });
    }
    inline auto PhoneNumberInfo::TryParse(param::hstring const& input, param::hstring const& regionCode, llm::OS::Globalization::PhoneNumberFormatting::PhoneNumberInfo& phoneNumber)
    {
        return impl::call_factory<PhoneNumberInfo, IPhoneNumberInfoStatics>([&](IPhoneNumberInfoStatics const& f) { return f.TryParse(input, regionCode, phoneNumber); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberFormatter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberFormatterStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberInfoFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Globalization::PhoneNumberFormatting::IPhoneNumberInfoStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Globalization::PhoneNumberFormatting::PhoneNumberFormatter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Globalization::PhoneNumberFormatting::PhoneNumberInfo> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
    template<> struct formatter<llm::OS::Globalization::PhoneNumberFormatting::PhoneNumberInfo, wchar_t> : formatter<llm::OS::Foundation::IStringable, wchar_t> {};
#endif
}
#endif
