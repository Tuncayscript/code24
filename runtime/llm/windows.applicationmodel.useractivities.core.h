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
#ifndef LLM_OS_ApplicationModel_UserActivities_Core_H
#define LLM_OS_ApplicationModel_UserActivities_Core_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.ApplicationModel.UserActivities.h"
#include "llm/impl/Windows.ApplicationModel.UserActivities.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.ApplicationModel.UserActivities.Core.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::UserActivities::UserActivitySession) consume_Windows_ApplicationModel_UserActivities_Core_ICoreUserActivityManagerStatics<D>::CreateUserActivitySessionInBackground(llm::OS::ApplicationModel::UserActivities::UserActivity const& activity) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserActivities::Core::ICoreUserActivityManagerStatics)->CreateUserActivitySessionInBackground(*(void**)(&activity), &result));
        return llm::OS::ApplicationModel::UserActivities::UserActivitySession{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_UserActivities_Core_ICoreUserActivityManagerStatics<D>::DeleteUserActivitySessionsInTimeRangeAsync(llm::OS::ApplicationModel::UserActivities::UserActivityChannel const& channel, llm::OS::Foundation::DateTime const& startTime, llm::OS::Foundation::DateTime const& endTime) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserActivities::Core::ICoreUserActivityManagerStatics)->DeleteUserActivitySessionsInTimeRangeAsync(*(void**)(&channel), impl::bind_in(startTime), impl::bind_in(endTime), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::UserActivities::Core::ICoreUserActivityManagerStatics> : produce_base<D, llm::OS::ApplicationModel::UserActivities::Core::ICoreUserActivityManagerStatics>
    {
        int32_t __stdcall CreateUserActivitySessionInBackground(void* activity, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::UserActivities::UserActivitySession>(this->shim().CreateUserActivitySessionInBackground(*reinterpret_cast<llm::OS::ApplicationModel::UserActivities::UserActivity const*>(&activity)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DeleteUserActivitySessionsInTimeRangeAsync(void* channel, int64_t startTime, int64_t endTime, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().DeleteUserActivitySessionsInTimeRangeAsync(*reinterpret_cast<llm::OS::ApplicationModel::UserActivities::UserActivityChannel const*>(&channel), *reinterpret_cast<llm::OS::Foundation::DateTime const*>(&startTime), *reinterpret_cast<llm::OS::Foundation::DateTime const*>(&endTime)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::ApplicationModel::UserActivities::Core
{
    inline auto CoreUserActivityManager::CreateUserActivitySessionInBackground(llm::OS::ApplicationModel::UserActivities::UserActivity const& activity)
    {
        return impl::call_factory<CoreUserActivityManager, ICoreUserActivityManagerStatics>([&](ICoreUserActivityManagerStatics const& f) { return f.CreateUserActivitySessionInBackground(activity); });
    }
    inline auto CoreUserActivityManager::DeleteUserActivitySessionsInTimeRangeAsync(llm::OS::ApplicationModel::UserActivities::UserActivityChannel const& channel, llm::OS::Foundation::DateTime const& startTime, llm::OS::Foundation::DateTime const& endTime)
    {
        return impl::call_factory<CoreUserActivityManager, ICoreUserActivityManagerStatics>([&](ICoreUserActivityManagerStatics const& f) { return f.DeleteUserActivitySessionsInTimeRangeAsync(channel, startTime, endTime); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::ApplicationModel::UserActivities::Core::ICoreUserActivityManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::UserActivities::Core::CoreUserActivityManager> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
