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
#ifndef LLM_OS_System_Threading_Core_H
#define LLM_OS_System_Threading_Core_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.System.Threading.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.System.Threading.2.h"
#include "llm/impl/Windows.System.Threading.Core.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_System_Threading_Core_IPreallocatedWorkItem<D>::RunAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Threading::Core::IPreallocatedWorkItem)->RunAsync(&operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Threading::Core::PreallocatedWorkItem) consume_Windows_System_Threading_Core_IPreallocatedWorkItemFactory<D>::CreateWorkItem(llm::OS::System::Threading::WorkItemHandler const& handler) const
    {
        void* workItem{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Threading::Core::IPreallocatedWorkItemFactory)->CreateWorkItem(*(void**)(&handler), &workItem));
        return llm::OS::System::Threading::Core::PreallocatedWorkItem{ workItem, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Threading::Core::PreallocatedWorkItem) consume_Windows_System_Threading_Core_IPreallocatedWorkItemFactory<D>::CreateWorkItemWithPriority(llm::OS::System::Threading::WorkItemHandler const& handler, llm::OS::System::Threading::WorkItemPriority const& priority) const
    {
        void* WorkItem{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Threading::Core::IPreallocatedWorkItemFactory)->CreateWorkItemWithPriority(*(void**)(&handler), static_cast<int32_t>(priority), &WorkItem));
        return llm::OS::System::Threading::Core::PreallocatedWorkItem{ WorkItem, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Threading::Core::PreallocatedWorkItem) consume_Windows_System_Threading_Core_IPreallocatedWorkItemFactory<D>::CreateWorkItemWithPriorityAndOptions(llm::OS::System::Threading::WorkItemHandler const& handler, llm::OS::System::Threading::WorkItemPriority const& priority, llm::OS::System::Threading::WorkItemOptions const& options) const
    {
        void* WorkItem{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Threading::Core::IPreallocatedWorkItemFactory)->CreateWorkItemWithPriorityAndOptions(*(void**)(&handler), static_cast<int32_t>(priority), static_cast<uint32_t>(options), &WorkItem));
        return llm::OS::System::Threading::Core::PreallocatedWorkItem{ WorkItem, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_Threading_Core_ISignalNotifier<D>::Enable() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Threading::Core::ISignalNotifier)->Enable());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_Threading_Core_ISignalNotifier<D>::Terminate() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Threading::Core::ISignalNotifier)->Terminate());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Threading::Core::SignalNotifier) consume_Windows_System_Threading_Core_ISignalNotifierStatics<D>::AttachToEvent(param::hstring const& name, llm::OS::System::Threading::Core::SignalHandler const& handler) const
    {
        void* signalNotifier{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Threading::Core::ISignalNotifierStatics)->AttachToEvent(*(void**)(&name), *(void**)(&handler), &signalNotifier));
        return llm::OS::System::Threading::Core::SignalNotifier{ signalNotifier, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Threading::Core::SignalNotifier) consume_Windows_System_Threading_Core_ISignalNotifierStatics<D>::AttachToEvent(param::hstring const& name, llm::OS::System::Threading::Core::SignalHandler const& handler, llm::OS::Foundation::TimeSpan const& timeout) const
    {
        void* signalNotifier{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Threading::Core::ISignalNotifierStatics)->AttachToEventWithTimeout(*(void**)(&name), *(void**)(&handler), impl::bind_in(timeout), &signalNotifier));
        return llm::OS::System::Threading::Core::SignalNotifier{ signalNotifier, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Threading::Core::SignalNotifier) consume_Windows_System_Threading_Core_ISignalNotifierStatics<D>::AttachToSemaphore(param::hstring const& name, llm::OS::System::Threading::Core::SignalHandler const& handler) const
    {
        void* signalNotifier{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Threading::Core::ISignalNotifierStatics)->AttachToSemaphore(*(void**)(&name), *(void**)(&handler), &signalNotifier));
        return llm::OS::System::Threading::Core::SignalNotifier{ signalNotifier, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Threading::Core::SignalNotifier) consume_Windows_System_Threading_Core_ISignalNotifierStatics<D>::AttachToSemaphore(param::hstring const& name, llm::OS::System::Threading::Core::SignalHandler const& handler, llm::OS::Foundation::TimeSpan const& timeout) const
    {
        void* signalNotifier{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Threading::Core::ISignalNotifierStatics)->AttachToSemaphoreWithTimeout(*(void**)(&name), *(void**)(&handler), impl::bind_in(timeout), &signalNotifier));
        return llm::OS::System::Threading::Core::SignalNotifier{ signalNotifier, take_ownership_from_abi };
    }
    template <typename H> struct delegate<llm::OS::System::Threading::Core::SignalHandler, H> final : implements_delegate<llm::OS::System::Threading::Core::SignalHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::System::Threading::Core::SignalHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* signalNotifier, bool timedOut) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::System::Threading::Core::SignalNotifier const*>(&signalNotifier), timedOut);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Threading::Core::IPreallocatedWorkItem> : produce_base<D, llm::OS::System::Threading::Core::IPreallocatedWorkItem>
    {
        int32_t __stdcall RunAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().RunAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Threading::Core::IPreallocatedWorkItemFactory> : produce_base<D, llm::OS::System::Threading::Core::IPreallocatedWorkItemFactory>
    {
        int32_t __stdcall CreateWorkItem(void* handler, void** workItem) noexcept final try
        {
            clear_abi(workItem);
            typename D::abi_guard guard(this->shim());
            *workItem = detach_from<llm::OS::System::Threading::Core::PreallocatedWorkItem>(this->shim().CreateWorkItem(*reinterpret_cast<llm::OS::System::Threading::WorkItemHandler const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWorkItemWithPriority(void* handler, int32_t priority, void** WorkItem) noexcept final try
        {
            clear_abi(WorkItem);
            typename D::abi_guard guard(this->shim());
            *WorkItem = detach_from<llm::OS::System::Threading::Core::PreallocatedWorkItem>(this->shim().CreateWorkItemWithPriority(*reinterpret_cast<llm::OS::System::Threading::WorkItemHandler const*>(&handler), *reinterpret_cast<llm::OS::System::Threading::WorkItemPriority const*>(&priority)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWorkItemWithPriorityAndOptions(void* handler, int32_t priority, uint32_t options, void** WorkItem) noexcept final try
        {
            clear_abi(WorkItem);
            typename D::abi_guard guard(this->shim());
            *WorkItem = detach_from<llm::OS::System::Threading::Core::PreallocatedWorkItem>(this->shim().CreateWorkItemWithPriorityAndOptions(*reinterpret_cast<llm::OS::System::Threading::WorkItemHandler const*>(&handler), *reinterpret_cast<llm::OS::System::Threading::WorkItemPriority const*>(&priority), *reinterpret_cast<llm::OS::System::Threading::WorkItemOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Threading::Core::ISignalNotifier> : produce_base<D, llm::OS::System::Threading::Core::ISignalNotifier>
    {
        int32_t __stdcall Enable() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Enable();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Terminate() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Terminate();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Threading::Core::ISignalNotifierStatics> : produce_base<D, llm::OS::System::Threading::Core::ISignalNotifierStatics>
    {
        int32_t __stdcall AttachToEvent(void* name, void* handler, void** signalNotifier) noexcept final try
        {
            clear_abi(signalNotifier);
            typename D::abi_guard guard(this->shim());
            *signalNotifier = detach_from<llm::OS::System::Threading::Core::SignalNotifier>(this->shim().AttachToEvent(*reinterpret_cast<hstring const*>(&name), *reinterpret_cast<llm::OS::System::Threading::Core::SignalHandler const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AttachToEventWithTimeout(void* name, void* handler, int64_t timeout, void** signalNotifier) noexcept final try
        {
            clear_abi(signalNotifier);
            typename D::abi_guard guard(this->shim());
            *signalNotifier = detach_from<llm::OS::System::Threading::Core::SignalNotifier>(this->shim().AttachToEvent(*reinterpret_cast<hstring const*>(&name), *reinterpret_cast<llm::OS::System::Threading::Core::SignalHandler const*>(&handler), *reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&timeout)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AttachToSemaphore(void* name, void* handler, void** signalNotifier) noexcept final try
        {
            clear_abi(signalNotifier);
            typename D::abi_guard guard(this->shim());
            *signalNotifier = detach_from<llm::OS::System::Threading::Core::SignalNotifier>(this->shim().AttachToSemaphore(*reinterpret_cast<hstring const*>(&name), *reinterpret_cast<llm::OS::System::Threading::Core::SignalHandler const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AttachToSemaphoreWithTimeout(void* name, void* handler, int64_t timeout, void** signalNotifier) noexcept final try
        {
            clear_abi(signalNotifier);
            typename D::abi_guard guard(this->shim());
            *signalNotifier = detach_from<llm::OS::System::Threading::Core::SignalNotifier>(this->shim().AttachToSemaphore(*reinterpret_cast<hstring const*>(&name), *reinterpret_cast<llm::OS::System::Threading::Core::SignalHandler const*>(&handler), *reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&timeout)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::System::Threading::Core
{
    inline PreallocatedWorkItem::PreallocatedWorkItem(llm::OS::System::Threading::WorkItemHandler const& handler) :
        PreallocatedWorkItem(impl::call_factory<PreallocatedWorkItem, IPreallocatedWorkItemFactory>([&](IPreallocatedWorkItemFactory const& f) { return f.CreateWorkItem(handler); }))
    {
    }
    inline PreallocatedWorkItem::PreallocatedWorkItem(llm::OS::System::Threading::WorkItemHandler const& handler, llm::OS::System::Threading::WorkItemPriority const& priority) :
        PreallocatedWorkItem(impl::call_factory<PreallocatedWorkItem, IPreallocatedWorkItemFactory>([&](IPreallocatedWorkItemFactory const& f) { return f.CreateWorkItemWithPriority(handler, priority); }))
    {
    }
    inline PreallocatedWorkItem::PreallocatedWorkItem(llm::OS::System::Threading::WorkItemHandler const& handler, llm::OS::System::Threading::WorkItemPriority const& priority, llm::OS::System::Threading::WorkItemOptions const& options) :
        PreallocatedWorkItem(impl::call_factory<PreallocatedWorkItem, IPreallocatedWorkItemFactory>([&](IPreallocatedWorkItemFactory const& f) { return f.CreateWorkItemWithPriorityAndOptions(handler, priority, options); }))
    {
    }
    inline auto SignalNotifier::AttachToEvent(param::hstring const& name, llm::OS::System::Threading::Core::SignalHandler const& handler)
    {
        return impl::call_factory<SignalNotifier, ISignalNotifierStatics>([&](ISignalNotifierStatics const& f) { return f.AttachToEvent(name, handler); });
    }
    inline auto SignalNotifier::AttachToEvent(param::hstring const& name, llm::OS::System::Threading::Core::SignalHandler const& handler, llm::OS::Foundation::TimeSpan const& timeout)
    {
        return impl::call_factory<SignalNotifier, ISignalNotifierStatics>([&](ISignalNotifierStatics const& f) { return f.AttachToEvent(name, handler, timeout); });
    }
    inline auto SignalNotifier::AttachToSemaphore(param::hstring const& name, llm::OS::System::Threading::Core::SignalHandler const& handler)
    {
        return impl::call_factory<SignalNotifier, ISignalNotifierStatics>([&](ISignalNotifierStatics const& f) { return f.AttachToSemaphore(name, handler); });
    }
    inline auto SignalNotifier::AttachToSemaphore(param::hstring const& name, llm::OS::System::Threading::Core::SignalHandler const& handler, llm::OS::Foundation::TimeSpan const& timeout)
    {
        return impl::call_factory<SignalNotifier, ISignalNotifierStatics>([&](ISignalNotifierStatics const& f) { return f.AttachToSemaphore(name, handler, timeout); });
    }
    template <typename L> SignalHandler::SignalHandler(L handler) :
        SignalHandler(impl::make_delegate<SignalHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> SignalHandler::SignalHandler(F* handler) :
        SignalHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> SignalHandler::SignalHandler(O* object, M method) :
        SignalHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> SignalHandler::SignalHandler(com_ptr<O>&& object, M method) :
        SignalHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> SignalHandler::SignalHandler(weak_ref<O>&& object, M method) :
        SignalHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto SignalHandler::operator()(llm::OS::System::Threading::Core::SignalNotifier const& signalNotifier, bool timedOut) const
    {
        check_hresult((*(impl::abi_t<SignalHandler>**)this)->Invoke(*(void**)(&signalNotifier), timedOut));
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::System::Threading::Core::IPreallocatedWorkItem> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Threading::Core::IPreallocatedWorkItemFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Threading::Core::ISignalNotifier> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Threading::Core::ISignalNotifierStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Threading::Core::PreallocatedWorkItem> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Threading::Core::SignalNotifier> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
