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
#ifndef LLM_OS_UI_Input_Core_H
#define LLM_OS_UI_Input_Core_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.Input.h"
#include "llm/impl/Windows.ApplicationModel.Core.2.h"
#include "llm/impl/Windows.System.2.h"
#include "llm/impl/Windows.UI.Core.2.h"
#include "llm/impl/Windows.UI.Input.2.h"
#include "llm/impl/Windows.UI.Input.Core.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Input::RadialController) consume_Windows_UI_Input_Core_IRadialControllerIndependentInputSource<D>::Controller() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Core::IRadialControllerIndependentInputSource)->get_Controller(&value));
        return llm::OS::UI::Input::RadialController{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::CoreDispatcher) consume_Windows_UI_Input_Core_IRadialControllerIndependentInputSource<D>::Dispatcher() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Core::IRadialControllerIndependentInputSource)->get_Dispatcher(&value));
        return llm::OS::UI::Core::CoreDispatcher{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::DispatcherQueue) consume_Windows_UI_Input_Core_IRadialControllerIndependentInputSource2<D>::DispatcherQueue() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Core::IRadialControllerIndependentInputSource2)->get_DispatcherQueue(&value));
        return llm::OS::System::DispatcherQueue{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Input::Core::RadialControllerIndependentInputSource) consume_Windows_UI_Input_Core_IRadialControllerIndependentInputSourceStatics<D>::CreateForView(llm::OS::ApplicationModel::Core::CoreApplicationView const& view) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Core::IRadialControllerIndependentInputSourceStatics)->CreateForView(*(void**)(&view), &result));
        return llm::OS::UI::Input::Core::RadialControllerIndependentInputSource{ result, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Input::Core::IRadialControllerIndependentInputSource> : produce_base<D, llm::OS::UI::Input::Core::IRadialControllerIndependentInputSource>
    {
        int32_t __stdcall get_Controller(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Input::RadialController>(this->shim().Controller());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Dispatcher(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Core::CoreDispatcher>(this->shim().Dispatcher());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Input::Core::IRadialControllerIndependentInputSource2> : produce_base<D, llm::OS::UI::Input::Core::IRadialControllerIndependentInputSource2>
    {
        int32_t __stdcall get_DispatcherQueue(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::DispatcherQueue>(this->shim().DispatcherQueue());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Input::Core::IRadialControllerIndependentInputSourceStatics> : produce_base<D, llm::OS::UI::Input::Core::IRadialControllerIndependentInputSourceStatics>
    {
        int32_t __stdcall CreateForView(void* view, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Input::Core::RadialControllerIndependentInputSource>(this->shim().CreateForView(*reinterpret_cast<llm::OS::ApplicationModel::Core::CoreApplicationView const*>(&view)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::UI::Input::Core
{
    inline auto RadialControllerIndependentInputSource::CreateForView(llm::OS::ApplicationModel::Core::CoreApplicationView const& view)
    {
        return impl::call_factory<RadialControllerIndependentInputSource, IRadialControllerIndependentInputSourceStatics>([&](IRadialControllerIndependentInputSourceStatics const& f) { return f.CreateForView(view); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::Input::Core::IRadialControllerIndependentInputSource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Input::Core::IRadialControllerIndependentInputSource2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Input::Core::IRadialControllerIndependentInputSourceStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Input::Core::RadialControllerIndependentInputSource> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
