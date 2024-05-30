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
#ifndef LLM_OS_System_Threading_2_H
#define LLM_OS_System_Threading_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.System.Threading.1.h"
LLM_EXPORT namespace llm:OS::System::Threading
{
    struct TimerDestroyedHandler : llm:OS::Foundation::IUnknown
    {
        TimerDestroyedHandler(std::nullptr_t = nullptr) noexcept {}
        TimerDestroyedHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> TimerDestroyedHandler(L lambda);
        template <typename F> TimerDestroyedHandler(F* function);
        template <typename O, typename M> TimerDestroyedHandler(O* object, M method);
        template <typename O, typename M> TimerDestroyedHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> TimerDestroyedHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::System::Threading::ThreadPoolTimer const& timer) const;
    };
    struct TimerElapsedHandler : llm:OS::Foundation::IUnknown
    {
        TimerElapsedHandler(std::nullptr_t = nullptr) noexcept {}
        TimerElapsedHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> TimerElapsedHandler(L lambda);
        template <typename F> TimerElapsedHandler(F* function);
        template <typename O, typename M> TimerElapsedHandler(O* object, M method);
        template <typename O, typename M> TimerElapsedHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> TimerElapsedHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::System::Threading::ThreadPoolTimer const& timer) const;
    };
    struct WorkItemHandler : llm:OS::Foundation::IUnknown
    {
        WorkItemHandler(std::nullptr_t = nullptr) noexcept {}
        WorkItemHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> WorkItemHandler(L lambda);
        template <typename F> WorkItemHandler(F* function);
        template <typename O, typename M> WorkItemHandler(O* object, M method);
        template <typename O, typename M> WorkItemHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> WorkItemHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::Foundation::IAsyncAction const& operation) const;
    };
    struct ThreadPool
    {
        ThreadPool() = delete;
        static auto RunAsync(llm:OS::System::Threading::WorkItemHandler const& handler);
        static auto RunAsync(llm:OS::System::Threading::WorkItemHandler const& handler, llm:OS::System::Threading::WorkItemPriority const& priority);
        static auto RunAsync(llm:OS::System::Threading::WorkItemHandler const& handler, llm:OS::System::Threading::WorkItemPriority const& priority, llm:OS::System::Threading::WorkItemOptions const& options);
    };
    struct __declspec(empty_bases) ThreadPoolTimer : llm:OS::System::Threading::IThreadPoolTimer
    {
        ThreadPoolTimer(std::nullptr_t) noexcept {}
        ThreadPoolTimer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Threading::IThreadPoolTimer(ptr, take_ownership_from_abi) {}
        static auto CreatePeriodicTimer(llm:OS::System::Threading::TimerElapsedHandler const& handler, llm:OS::Foundation::TimeSpan const& period);
        static auto CreateTimer(llm:OS::System::Threading::TimerElapsedHandler const& handler, llm:OS::Foundation::TimeSpan const& delay);
        static auto CreatePeriodicTimer(llm:OS::System::Threading::TimerElapsedHandler const& handler, llm:OS::Foundation::TimeSpan const& period, llm:OS::System::Threading::TimerDestroyedHandler const& destroyed);
        static auto CreateTimer(llm:OS::System::Threading::TimerElapsedHandler const& handler, llm:OS::Foundation::TimeSpan const& delay, llm:OS::System::Threading::TimerDestroyedHandler const& destroyed);
    };
}
#endif
