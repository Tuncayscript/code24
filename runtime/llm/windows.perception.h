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
#ifndef LLM_OS_Perception_H
#define LLM_OS_Perception_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Perception.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Perception_IPerceptionTimestamp<D>::TargetTime() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::IPerceptionTimestamp)->get_TargetTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Perception_IPerceptionTimestamp<D>::PredictionAmount() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::IPerceptionTimestamp)->get_PredictionAmount(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Perception_IPerceptionTimestamp2<D>::SystemRelativeTargetTime() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::IPerceptionTimestamp2)->get_SystemRelativeTargetTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::PerceptionTimestamp) consume_Windows_Perception_IPerceptionTimestampHelperStatics<D>::FromHistoricalTargetTime(llm::OS::Foundation::DateTime const& targetTime) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::IPerceptionTimestampHelperStatics)->FromHistoricalTargetTime(impl::bind_in(targetTime), &value));
        return llm::OS::Perception::PerceptionTimestamp{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::PerceptionTimestamp) consume_Windows_Perception_IPerceptionTimestampHelperStatics2<D>::FromSystemRelativeTargetTime(llm::OS::Foundation::TimeSpan const& targetTime) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::IPerceptionTimestampHelperStatics2)->FromSystemRelativeTargetTime(impl::bind_in(targetTime), &value));
        return llm::OS::Perception::PerceptionTimestamp{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::IPerceptionTimestamp> : produce_base<D, llm::OS::Perception::IPerceptionTimestamp>
    {
        int32_t __stdcall get_TargetTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().TargetTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PredictionAmount(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().PredictionAmount());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::IPerceptionTimestamp2> : produce_base<D, llm::OS::Perception::IPerceptionTimestamp2>
    {
        int32_t __stdcall get_SystemRelativeTargetTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().SystemRelativeTargetTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::IPerceptionTimestampHelperStatics> : produce_base<D, llm::OS::Perception::IPerceptionTimestampHelperStatics>
    {
        int32_t __stdcall FromHistoricalTargetTime(int64_t targetTime, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::PerceptionTimestamp>(this->shim().FromHistoricalTargetTime(*reinterpret_cast<llm::OS::Foundation::DateTime const*>(&targetTime)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::IPerceptionTimestampHelperStatics2> : produce_base<D, llm::OS::Perception::IPerceptionTimestampHelperStatics2>
    {
        int32_t __stdcall FromSystemRelativeTargetTime(int64_t targetTime, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::PerceptionTimestamp>(this->shim().FromSystemRelativeTargetTime(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&targetTime)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Perception
{
    inline auto PerceptionTimestampHelper::FromHistoricalTargetTime(llm::OS::Foundation::DateTime const& targetTime)
    {
        return impl::call_factory<PerceptionTimestampHelper, IPerceptionTimestampHelperStatics>([&](IPerceptionTimestampHelperStatics const& f) { return f.FromHistoricalTargetTime(targetTime); });
    }
    inline auto PerceptionTimestampHelper::FromSystemRelativeTargetTime(llm::OS::Foundation::TimeSpan const& targetTime)
    {
        return impl::call_factory<PerceptionTimestampHelper, IPerceptionTimestampHelperStatics2>([&](IPerceptionTimestampHelperStatics2 const& f) { return f.FromSystemRelativeTargetTime(targetTime); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Perception::IPerceptionTimestamp> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::IPerceptionTimestamp2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::IPerceptionTimestampHelperStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::IPerceptionTimestampHelperStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::PerceptionTimestamp> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::PerceptionTimestampHelper> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
