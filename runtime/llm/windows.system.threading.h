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
#ifndef LLM_OS_System_Threading_H
#define LLM_OS_System_Threading_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.System.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.System.Threading.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_System_Threading_IThreadPoolStatics<D>::RunAsync(llm::OS::System::Threading::WorkItemHandler const& handler) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Threading::IThreadPoolStatics)->RunAsync(*(void**)(&handler), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_System_Threading_IThreadPoolStatics<D>::RunAsync(llm::OS::System::Threading::WorkItemHandler const& handler, llm::OS::System::Threading::WorkItemPriority const& priority) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Threading::IThreadPoolStatics)->RunWithPriorityAsync(*(void**)(&handler), static_cast<int32_t>(priority), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_System_Threading_IThreadPoolStatics<D>::RunAsync(llm::OS::System::Threading::WorkItemHandler const& handler, llm::OS::System::Threading::WorkItemPriority const& priority, llm::OS::System::Threading::WorkItemOptions const& options) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Threading::IThreadPoolStatics)->RunWithPriorityAndOptionsAsync(*(void**)(&handler), static_cast<int32_t>(priority), static_cast<uint32_t>(options), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_System_Threading_IThreadPoolTimer<D>::Period() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Threading::IThreadPoolTimer)->get_Period(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_System_Threading_IThreadPoolTimer<D>::Delay() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Threading::IThreadPoolTimer)->get_Delay(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_Threading_IThreadPoolTimer<D>::Cancel() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Threading::IThreadPoolTimer)->Cancel());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Threading::ThreadPoolTimer) consume_Windows_System_Threading_IThreadPoolTimerStatics<D>::CreatePeriodicTimer(llm::OS::System::Threading::TimerElapsedHandler const& handler, llm::OS::Foundation::TimeSpan const& period) const
    {
        void* timer{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Threading::IThreadPoolTimerStatics)->CreatePeriodicTimer(*(void**)(&handler), impl::bind_in(period), &timer));
        return llm::OS::System::Threading::ThreadPoolTimer{ timer, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Threading::ThreadPoolTimer) consume_Windows_System_Threading_IThreadPoolTimerStatics<D>::CreateTimer(llm::OS::System::Threading::TimerElapsedHandler const& handler, llm::OS::Foundation::TimeSpan const& delay) const
    {
        void* timer{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Threading::IThreadPoolTimerStatics)->CreateTimer(*(void**)(&handler), impl::bind_in(delay), &timer));
        return llm::OS::System::Threading::ThreadPoolTimer{ timer, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Threading::ThreadPoolTimer) consume_Windows_System_Threading_IThreadPoolTimerStatics<D>::CreatePeriodicTimer(llm::OS::System::Threading::TimerElapsedHandler const& handler, llm::OS::Foundation::TimeSpan const& period, llm::OS::System::Threading::TimerDestroyedHandler const& destroyed) const
    {
        void* timer{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Threading::IThreadPoolTimerStatics)->CreatePeriodicTimerWithCompletion(*(void**)(&handler), impl::bind_in(period), *(void**)(&destroyed), &timer));
        return llm::OS::System::Threading::ThreadPoolTimer{ timer, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Threading::ThreadPoolTimer) consume_Windows_System_Threading_IThreadPoolTimerStatics<D>::CreateTimer(llm::OS::System::Threading::TimerElapsedHandler const& handler, llm::OS::Foundation::TimeSpan const& delay, llm::OS::System::Threading::TimerDestroyedHandler const& destroyed) const
    {
        void* timer{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Threading::IThreadPoolTimerStatics)->CreateTimerWithCompletion(*(void**)(&handler), impl::bind_in(delay), *(void**)(&destroyed), &timer));
        return llm::OS::System::Threading::ThreadPoolTimer{ timer, take_ownership_from_abi };
    }
    template <typename H> struct delegate<llm::OS::System::Threading::TimerDestroyedHandler, H> final : implements_delegate<llm::OS::System::Threading::TimerDestroyedHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::System::Threading::TimerDestroyedHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* timer) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::System::Threading::ThreadPoolTimer const*>(&timer));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename H> struct delegate<llm::OS::System::Threading::TimerElapsedHandler, H> final : implements_delegate<llm::OS::System::Threading::TimerElapsedHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::System::Threading::TimerElapsedHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* timer) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::System::Threading::ThreadPoolTimer const*>(&timer));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename H> struct delegate<llm::OS::System::Threading::WorkItemHandler, H> final : implements_delegate<llm::OS::System::Threading::WorkItemHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::System::Threading::WorkItemHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* operation) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::Foundation::IAsyncAction const*>(&operation));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Threading::IThreadPoolStatics> : produce_base<D, llm::OS::System::Threading::IThreadPoolStatics>
    {
        int32_t __stdcall RunAsync(void* handler, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().RunAsync(*reinterpret_cast<llm::OS::System::Threading::WorkItemHandler const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RunWithPriorityAsync(void* handler, int32_t priority, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().RunAsync(*reinterpret_cast<llm::OS::System::Threading::WorkItemHandler const*>(&handler), *reinterpret_cast<llm::OS::System::Threading::WorkItemPriority const*>(&priority)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RunWithPriorityAndOptionsAsync(void* handler, int32_t priority, uint32_t options, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().RunAsync(*reinterpret_cast<llm::OS::System::Threading::WorkItemHandler const*>(&handler), *reinterpret_cast<llm::OS::System::Threading::WorkItemPriority const*>(&priority), *reinterpret_cast<llm::OS::System::Threading::WorkItemOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Threading::IThreadPoolTimer> : produce_base<D, llm::OS::System::Threading::IThreadPoolTimer>
    {
        int32_t __stdcall get_Period(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().Period());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Delay(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().Delay());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Cancel() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Cancel();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Threading::IThreadPoolTimerStatics> : produce_base<D, llm::OS::System::Threading::IThreadPoolTimerStatics>
    {
        int32_t __stdcall CreatePeriodicTimer(void* handler, int64_t period, void** timer) noexcept final try
        {
            clear_abi(timer);
            typename D::abi_guard guard(this->shim());
            *timer = detach_from<llm::OS::System::Threading::ThreadPoolTimer>(this->shim().CreatePeriodicTimer(*reinterpret_cast<llm::OS::System::Threading::TimerElapsedHandler const*>(&handler), *reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&period)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateTimer(void* handler, int64_t delay, void** timer) noexcept final try
        {
            clear_abi(timer);
            typename D::abi_guard guard(this->shim());
            *timer = detach_from<llm::OS::System::Threading::ThreadPoolTimer>(this->shim().CreateTimer(*reinterpret_cast<llm::OS::System::Threading::TimerElapsedHandler const*>(&handler), *reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&delay)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreatePeriodicTimerWithCompletion(void* handler, int64_t period, void* destroyed, void** timer) noexcept final try
        {
            clear_abi(timer);
            typename D::abi_guard guard(this->shim());
            *timer = detach_from<llm::OS::System::Threading::ThreadPoolTimer>(this->shim().CreatePeriodicTimer(*reinterpret_cast<llm::OS::System::Threading::TimerElapsedHandler const*>(&handler), *reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&period), *reinterpret_cast<llm::OS::System::Threading::TimerDestroyedHandler const*>(&destroyed)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateTimerWithCompletion(void* handler, int64_t delay, void* destroyed, void** timer) noexcept final try
        {
            clear_abi(timer);
            typename D::abi_guard guard(this->shim());
            *timer = detach_from<llm::OS::System::Threading::ThreadPoolTimer>(this->shim().CreateTimer(*reinterpret_cast<llm::OS::System::Threading::TimerElapsedHandler const*>(&handler), *reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&delay), *reinterpret_cast<llm::OS::System::Threading::TimerDestroyedHandler const*>(&destroyed)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::System::Threading
{
    constexpr auto operator|(WorkItemOptions const left, WorkItemOptions const right) noexcept
    {
        return static_cast<WorkItemOptions>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(WorkItemOptions& left, WorkItemOptions const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(WorkItemOptions const left, WorkItemOptions const right) noexcept
    {
        return static_cast<WorkItemOptions>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(WorkItemOptions& left, WorkItemOptions const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(WorkItemOptions const value) noexcept
    {
        return static_cast<WorkItemOptions>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(WorkItemOptions const left, WorkItemOptions const right) noexcept
    {
        return static_cast<WorkItemOptions>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(WorkItemOptions& left, WorkItemOptions const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    inline auto ThreadPool::RunAsync(llm::OS::System::Threading::WorkItemHandler const& handler)
    {
        return impl::call_factory<ThreadPool, IThreadPoolStatics>([&](IThreadPoolStatics const& f) { return f.RunAsync(handler); });
    }
    inline auto ThreadPool::RunAsync(llm::OS::System::Threading::WorkItemHandler const& handler, llm::OS::System::Threading::WorkItemPriority const& priority)
    {
        return impl::call_factory<ThreadPool, IThreadPoolStatics>([&](IThreadPoolStatics const& f) { return f.RunAsync(handler, priority); });
    }
    inline auto ThreadPool::RunAsync(llm::OS::System::Threading::WorkItemHandler const& handler, llm::OS::System::Threading::WorkItemPriority const& priority, llm::OS::System::Threading::WorkItemOptions const& options)
    {
        return impl::call_factory<ThreadPool, IThreadPoolStatics>([&](IThreadPoolStatics const& f) { return f.RunAsync(handler, priority, options); });
    }
    inline auto ThreadPoolTimer::CreatePeriodicTimer(llm::OS::System::Threading::TimerElapsedHandler const& handler, llm::OS::Foundation::TimeSpan const& period)
    {
        return impl::call_factory<ThreadPoolTimer, IThreadPoolTimerStatics>([&](IThreadPoolTimerStatics const& f) { return f.CreatePeriodicTimer(handler, period); });
    }
    inline auto ThreadPoolTimer::CreateTimer(llm::OS::System::Threading::TimerElapsedHandler const& handler, llm::OS::Foundation::TimeSpan const& delay)
    {
        return impl::call_factory<ThreadPoolTimer, IThreadPoolTimerStatics>([&](IThreadPoolTimerStatics const& f) { return f.CreateTimer(handler, delay); });
    }
    inline auto ThreadPoolTimer::CreatePeriodicTimer(llm::OS::System::Threading::TimerElapsedHandler const& handler, llm::OS::Foundation::TimeSpan const& period, llm::OS::System::Threading::TimerDestroyedHandler const& destroyed)
    {
        return impl::call_factory<ThreadPoolTimer, IThreadPoolTimerStatics>([&](IThreadPoolTimerStatics const& f) { return f.CreatePeriodicTimer(handler, period, destroyed); });
    }
    inline auto ThreadPoolTimer::CreateTimer(llm::OS::System::Threading::TimerElapsedHandler const& handler, llm::OS::Foundation::TimeSpan const& delay, llm::OS::System::Threading::TimerDestroyedHandler const& destroyed)
    {
        return impl::call_factory<ThreadPoolTimer, IThreadPoolTimerStatics>([&](IThreadPoolTimerStatics const& f) { return f.CreateTimer(handler, delay, destroyed); });
    }
    template <typename L> TimerDestroyedHandler::TimerDestroyedHandler(L handler) :
        TimerDestroyedHandler(impl::make_delegate<TimerDestroyedHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> TimerDestroyedHandler::TimerDestroyedHandler(F* handler) :
        TimerDestroyedHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> TimerDestroyedHandler::TimerDestroyedHandler(O* object, M method) :
        TimerDestroyedHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> TimerDestroyedHandler::TimerDestroyedHandler(com_ptr<O>&& object, M method) :
        TimerDestroyedHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> TimerDestroyedHandler::TimerDestroyedHandler(weak_ref<O>&& object, M method) :
        TimerDestroyedHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto TimerDestroyedHandler::operator()(llm::OS::System::Threading::ThreadPoolTimer const& timer) const
    {
        check_hresult((*(impl::abi_t<TimerDestroyedHandler>**)this)->Invoke(*(void**)(&timer)));
    }
    template <typename L> TimerElapsedHandler::TimerElapsedHandler(L handler) :
        TimerElapsedHandler(impl::make_delegate<TimerElapsedHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> TimerElapsedHandler::TimerElapsedHandler(F* handler) :
        TimerElapsedHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> TimerElapsedHandler::TimerElapsedHandler(O* object, M method) :
        TimerElapsedHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> TimerElapsedHandler::TimerElapsedHandler(com_ptr<O>&& object, M method) :
        TimerElapsedHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> TimerElapsedHandler::TimerElapsedHandler(weak_ref<O>&& object, M method) :
        TimerElapsedHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto TimerElapsedHandler::operator()(llm::OS::System::Threading::ThreadPoolTimer const& timer) const
    {
        check_hresult((*(impl::abi_t<TimerElapsedHandler>**)this)->Invoke(*(void**)(&timer)));
    }
    template <typename L> WorkItemHandler::WorkItemHandler(L handler) :
        WorkItemHandler(impl::make_delegate<WorkItemHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> WorkItemHandler::WorkItemHandler(F* handler) :
        WorkItemHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> WorkItemHandler::WorkItemHandler(O* object, M method) :
        WorkItemHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> WorkItemHandler::WorkItemHandler(com_ptr<O>&& object, M method) :
        WorkItemHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> WorkItemHandler::WorkItemHandler(weak_ref<O>&& object, M method) :
        WorkItemHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto WorkItemHandler::operator()(llm::OS::Foundation::IAsyncAction const& operation) const
    {
        check_hresult((*(impl::abi_t<WorkItemHandler>**)this)->Invoke(*(void**)(&operation)));
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::System::Threading::IThreadPoolStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Threading::IThreadPoolTimer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Threading::IThreadPoolTimerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Threading::ThreadPool> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Threading::ThreadPoolTimer> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
