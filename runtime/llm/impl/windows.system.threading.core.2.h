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
#ifndef LLM_OS_System_Threading_Core_2_H
#define LLM_OS_System_Threading_Core_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.System.Threading.1.h"
#include "llm/impl/Windows.System.Threading.Core.1.h"
LLM_EXPORT namespace llm:OS::System::Threading::Core
{
    struct SignalHandler : llm:OS::Foundation::IUnknown
    {
        SignalHandler(std::nullptr_t = nullptr) noexcept {}
        SignalHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> SignalHandler(L lambda);
        template <typename F> SignalHandler(F* function);
        template <typename O, typename M> SignalHandler(O* object, M method);
        template <typename O, typename M> SignalHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> SignalHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::System::Threading::Core::SignalNotifier const& signalNotifier, bool timedOut) const;
    };
    struct __declspec(empty_bases) PreallocatedWorkItem : llm:OS::System::Threading::Core::IPreallocatedWorkItem
    {
        PreallocatedWorkItem(std::nullptr_t) noexcept {}
        PreallocatedWorkItem(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Threading::Core::IPreallocatedWorkItem(ptr, take_ownership_from_abi) {}
        explicit PreallocatedWorkItem(llm:OS::System::Threading::WorkItemHandler const& handler);
        PreallocatedWorkItem(llm:OS::System::Threading::WorkItemHandler const& handler, llm:OS::System::Threading::WorkItemPriority const& priority);
        PreallocatedWorkItem(llm:OS::System::Threading::WorkItemHandler const& handler, llm:OS::System::Threading::WorkItemPriority const& priority, llm:OS::System::Threading::WorkItemOptions const& options);
    };
    struct __declspec(empty_bases) SignalNotifier : llm:OS::System::Threading::Core::ISignalNotifier
    {
        SignalNotifier(std::nullptr_t) noexcept {}
        SignalNotifier(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Threading::Core::ISignalNotifier(ptr, take_ownership_from_abi) {}
        static auto AttachToEvent(param::hstring const& name, llm:OS::System::Threading::Core::SignalHandler const& handler);
        static auto AttachToEvent(param::hstring const& name, llm:OS::System::Threading::Core::SignalHandler const& handler, llm:OS::Foundation::TimeSpan const& timeout);
        static auto AttachToSemaphore(param::hstring const& name, llm:OS::System::Threading::Core::SignalHandler const& handler);
        static auto AttachToSemaphore(param::hstring const& name, llm:OS::System::Threading::Core::SignalHandler const& handler, llm:OS::Foundation::TimeSpan const& timeout);
    };
}
#endif
