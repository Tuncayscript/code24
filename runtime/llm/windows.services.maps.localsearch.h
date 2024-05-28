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
#ifndef LLM_OS_Services_Maps_LocalSearch_H
#define LLM_OS_Services_Maps_LocalSearch_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Services.Maps.h"
#include "llm/impl/Windows.Devices.Geolocation.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Globalization.2.h"
#include "llm/impl/Windows.Services.Maps.2.h"
#include "llm/impl/Windows.Services.Maps.LocalSearch.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_LocalSearch_ILocalCategoriesStatics<D>::BankAndCreditUnions() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::LocalSearch::ILocalCategoriesStatics)->get_BankAndCreditUnions(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_LocalSearch_ILocalCategoriesStatics<D>::EatDrink() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::LocalSearch::ILocalCategoriesStatics)->get_EatDrink(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_LocalSearch_ILocalCategoriesStatics<D>::Hospitals() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::LocalSearch::ILocalCategoriesStatics)->get_Hospitals(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_LocalSearch_ILocalCategoriesStatics<D>::HotelsAndMotels() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::LocalSearch::ILocalCategoriesStatics)->get_HotelsAndMotels(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_LocalSearch_ILocalCategoriesStatics<D>::All() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::LocalSearch::ILocalCategoriesStatics)->get_All(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_LocalSearch_ILocalCategoriesStatics<D>::Parking() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::LocalSearch::ILocalCategoriesStatics)->get_Parking(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_LocalSearch_ILocalCategoriesStatics<D>::SeeDo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::LocalSearch::ILocalCategoriesStatics)->get_SeeDo(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_LocalSearch_ILocalCategoriesStatics<D>::Shop() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::LocalSearch::ILocalCategoriesStatics)->get_Shop(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Maps::MapAddress) consume_Windows_Services_Maps_LocalSearch_ILocalLocation<D>::Address() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::LocalSearch::ILocalLocation)->get_Address(&value));
        return llm::OS::Services::Maps::MapAddress{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_LocalSearch_ILocalLocation<D>::Identifier() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::LocalSearch::ILocalLocation)->get_Identifier(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_LocalSearch_ILocalLocation<D>::Description() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::LocalSearch::ILocalLocation)->get_Description(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_LocalSearch_ILocalLocation<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::LocalSearch::ILocalLocation)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Geopoint) consume_Windows_Services_Maps_LocalSearch_ILocalLocation<D>::Point() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::LocalSearch::ILocalLocation)->get_Point(&value));
        return llm::OS::Devices::Geolocation::Geopoint{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_LocalSearch_ILocalLocation<D>::PhoneNumber() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::LocalSearch::ILocalLocation)->get_PhoneNumber(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_LocalSearch_ILocalLocation<D>::DataAttribution() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::LocalSearch::ILocalLocation)->get_DataAttribution(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_LocalSearch_ILocalLocation2<D>::Category() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::LocalSearch::ILocalLocation2)->get_Category(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Maps::LocalSearch::LocalLocationRatingInfo) consume_Windows_Services_Maps_LocalSearch_ILocalLocation2<D>::RatingInfo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::LocalSearch::ILocalLocation2)->get_RatingInfo(&value));
        return llm::OS::Services::Maps::LocalSearch::LocalLocationRatingInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Maps::LocalSearch::LocalLocationHoursOfOperationItem>) consume_Windows_Services_Maps_LocalSearch_ILocalLocation2<D>::HoursOfOperation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::LocalSearch::ILocalLocation2)->get_HoursOfOperation(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Maps::LocalSearch::LocalLocationHoursOfOperationItem>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Maps::LocalSearch::LocalLocation>) consume_Windows_Services_Maps_LocalSearch_ILocalLocationFinderResult<D>::LocalLocations() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::LocalSearch::ILocalLocationFinderResult)->get_LocalLocations(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Maps::LocalSearch::LocalLocation>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Maps::LocalSearch::LocalLocationFinderStatus) consume_Windows_Services_Maps_LocalSearch_ILocalLocationFinderResult<D>::Status() const
    {
        llm::OS::Services::Maps::LocalSearch::LocalLocationFinderStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::LocalSearch::ILocalLocationFinderResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::LocalSearch::LocalLocationFinderResult>) consume_Windows_Services_Maps_LocalSearch_ILocalLocationFinderStatics<D>::FindLocalLocationsAsync(param::hstring const& searchTerm, llm::OS::Devices::Geolocation::Geocircle const& searchArea, param::hstring const& localCategory, uint32_t maxResults) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::LocalSearch::ILocalLocationFinderStatics)->FindLocalLocationsAsync(*(void**)(&searchTerm), *(void**)(&searchArea), *(void**)(&localCategory), maxResults, &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::LocalSearch::LocalLocationFinderResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Globalization::DayOfWeek) consume_Windows_Services_Maps_LocalSearch_ILocalLocationHoursOfOperationItem<D>::Day() const
    {
        llm::OS::Globalization::DayOfWeek value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::LocalSearch::ILocalLocationHoursOfOperationItem)->get_Day(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Services_Maps_LocalSearch_ILocalLocationHoursOfOperationItem<D>::Start() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::LocalSearch::ILocalLocationHoursOfOperationItem)->get_Start(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Services_Maps_LocalSearch_ILocalLocationHoursOfOperationItem<D>::Span() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::LocalSearch::ILocalLocationHoursOfOperationItem)->get_Span(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Services_Maps_LocalSearch_ILocalLocationRatingInfo<D>::AggregateRating() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::LocalSearch::ILocalLocationRatingInfo)->get_AggregateRating(&value));
        return llm::OS::Foundation::IReference<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Services_Maps_LocalSearch_ILocalLocationRatingInfo<D>::RatingCount() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::LocalSearch::ILocalLocationRatingInfo)->get_RatingCount(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_LocalSearch_ILocalLocationRatingInfo<D>::ProviderIdentifier() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::LocalSearch::ILocalLocationRatingInfo)->get_ProviderIdentifier(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Maps::PlaceInfo) consume_Windows_Services_Maps_LocalSearch_IPlaceInfoHelperStatics<D>::CreateFromLocalLocation(llm::OS::Services::Maps::LocalSearch::LocalLocation const& location) const
    {
        void* resultValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::LocalSearch::IPlaceInfoHelperStatics)->CreateFromLocalLocation(*(void**)(&location), &resultValue));
        return llm::OS::Services::Maps::PlaceInfo{ resultValue, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::LocalSearch::ILocalCategoriesStatics> : produce_base<D, llm::OS::Services::Maps::LocalSearch::ILocalCategoriesStatics>
    {
        int32_t __stdcall get_BankAndCreditUnions(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().BankAndCreditUnions());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EatDrink(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().EatDrink());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Hospitals(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Hospitals());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HotelsAndMotels(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().HotelsAndMotels());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_All(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().All());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Parking(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Parking());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SeeDo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SeeDo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Shop(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Shop());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::LocalSearch::ILocalLocation> : produce_base<D, llm::OS::Services::Maps::LocalSearch::ILocalLocation>
    {
        int32_t __stdcall get_Address(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Maps::MapAddress>(this->shim().Address());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Identifier(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Identifier());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Description(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Point(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::Geopoint>(this->shim().Point());
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
        int32_t __stdcall get_DataAttribution(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DataAttribution());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::LocalSearch::ILocalLocation2> : produce_base<D, llm::OS::Services::Maps::LocalSearch::ILocalLocation2>
    {
        int32_t __stdcall get_Category(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Category());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RatingInfo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Maps::LocalSearch::LocalLocationRatingInfo>(this->shim().RatingInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HoursOfOperation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Maps::LocalSearch::LocalLocationHoursOfOperationItem>>(this->shim().HoursOfOperation());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::LocalSearch::ILocalLocationFinderResult> : produce_base<D, llm::OS::Services::Maps::LocalSearch::ILocalLocationFinderResult>
    {
        int32_t __stdcall get_LocalLocations(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Maps::LocalSearch::LocalLocation>>(this->shim().LocalLocations());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Maps::LocalSearch::LocalLocationFinderStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::LocalSearch::ILocalLocationFinderStatics> : produce_base<D, llm::OS::Services::Maps::LocalSearch::ILocalLocationFinderStatics>
    {
        int32_t __stdcall FindLocalLocationsAsync(void* searchTerm, void* searchArea, void* localCategory, uint32_t maxResults, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::LocalSearch::LocalLocationFinderResult>>(this->shim().FindLocalLocationsAsync(*reinterpret_cast<hstring const*>(&searchTerm), *reinterpret_cast<llm::OS::Devices::Geolocation::Geocircle const*>(&searchArea), *reinterpret_cast<hstring const*>(&localCategory), maxResults));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::LocalSearch::ILocalLocationHoursOfOperationItem> : produce_base<D, llm::OS::Services::Maps::LocalSearch::ILocalLocationHoursOfOperationItem>
    {
        int32_t __stdcall get_Day(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Globalization::DayOfWeek>(this->shim().Day());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Start(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().Start());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Span(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().Span());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::LocalSearch::ILocalLocationRatingInfo> : produce_base<D, llm::OS::Services::Maps::LocalSearch::ILocalLocationRatingInfo>
    {
        int32_t __stdcall get_AggregateRating(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().AggregateRating());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RatingCount(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().RatingCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProviderIdentifier(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ProviderIdentifier());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::LocalSearch::IPlaceInfoHelperStatics> : produce_base<D, llm::OS::Services::Maps::LocalSearch::IPlaceInfoHelperStatics>
    {
        int32_t __stdcall CreateFromLocalLocation(void* location, void** resultValue) noexcept final try
        {
            clear_abi(resultValue);
            typename D::abi_guard guard(this->shim());
            *resultValue = detach_from<llm::OS::Services::Maps::PlaceInfo>(this->shim().CreateFromLocalLocation(*reinterpret_cast<llm::OS::Services::Maps::LocalSearch::LocalLocation const*>(&location)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Services::Maps::LocalSearch
{
    inline auto LocalCategories::BankAndCreditUnions()
    {
        return impl::call_factory_cast<hstring(*)(ILocalCategoriesStatics const&), LocalCategories, ILocalCategoriesStatics>([](ILocalCategoriesStatics const& f) { return f.BankAndCreditUnions(); });
    }
    inline auto LocalCategories::EatDrink()
    {
        return impl::call_factory_cast<hstring(*)(ILocalCategoriesStatics const&), LocalCategories, ILocalCategoriesStatics>([](ILocalCategoriesStatics const& f) { return f.EatDrink(); });
    }
    inline auto LocalCategories::Hospitals()
    {
        return impl::call_factory_cast<hstring(*)(ILocalCategoriesStatics const&), LocalCategories, ILocalCategoriesStatics>([](ILocalCategoriesStatics const& f) { return f.Hospitals(); });
    }
    inline auto LocalCategories::HotelsAndMotels()
    {
        return impl::call_factory_cast<hstring(*)(ILocalCategoriesStatics const&), LocalCategories, ILocalCategoriesStatics>([](ILocalCategoriesStatics const& f) { return f.HotelsAndMotels(); });
    }
    inline auto LocalCategories::All()
    {
        return impl::call_factory_cast<hstring(*)(ILocalCategoriesStatics const&), LocalCategories, ILocalCategoriesStatics>([](ILocalCategoriesStatics const& f) { return f.All(); });
    }
    inline auto LocalCategories::Parking()
    {
        return impl::call_factory_cast<hstring(*)(ILocalCategoriesStatics const&), LocalCategories, ILocalCategoriesStatics>([](ILocalCategoriesStatics const& f) { return f.Parking(); });
    }
    inline auto LocalCategories::SeeDo()
    {
        return impl::call_factory_cast<hstring(*)(ILocalCategoriesStatics const&), LocalCategories, ILocalCategoriesStatics>([](ILocalCategoriesStatics const& f) { return f.SeeDo(); });
    }
    inline auto LocalCategories::Shop()
    {
        return impl::call_factory_cast<hstring(*)(ILocalCategoriesStatics const&), LocalCategories, ILocalCategoriesStatics>([](ILocalCategoriesStatics const& f) { return f.Shop(); });
    }
    inline auto LocalLocationFinder::FindLocalLocationsAsync(param::hstring const& searchTerm, llm::OS::Devices::Geolocation::Geocircle const& searchArea, param::hstring const& localCategory, uint32_t maxResults)
    {
        return impl::call_factory<LocalLocationFinder, ILocalLocationFinderStatics>([&](ILocalLocationFinderStatics const& f) { return f.FindLocalLocationsAsync(searchTerm, searchArea, localCategory, maxResults); });
    }
    inline auto PlaceInfoHelper::CreateFromLocalLocation(llm::OS::Services::Maps::LocalSearch::LocalLocation const& location)
    {
        return impl::call_factory<PlaceInfoHelper, IPlaceInfoHelperStatics>([&](IPlaceInfoHelperStatics const& f) { return f.CreateFromLocalLocation(location); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Services::Maps::LocalSearch::ILocalCategoriesStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::LocalSearch::ILocalLocation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::LocalSearch::ILocalLocation2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::LocalSearch::ILocalLocationFinderResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::LocalSearch::ILocalLocationFinderStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::LocalSearch::ILocalLocationHoursOfOperationItem> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::LocalSearch::ILocalLocationRatingInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::LocalSearch::IPlaceInfoHelperStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::LocalSearch::LocalCategories> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::LocalSearch::LocalLocation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::LocalSearch::LocalLocationFinder> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::LocalSearch::LocalLocationFinderResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::LocalSearch::LocalLocationHoursOfOperationItem> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::LocalSearch::LocalLocationRatingInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::LocalSearch::PlaceInfoHelper> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
