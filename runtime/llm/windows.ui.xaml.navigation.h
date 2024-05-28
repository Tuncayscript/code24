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
#ifndef LLM_OS_UI_Xaml_Navigation_H
#define LLM_OS_UI_Xaml_Navigation_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.Xaml.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.UI.Xaml.2.h"
#include "llm/impl/Windows.UI.Xaml.Interop.2.h"
#include "llm/impl/Windows.UI.Xaml.Media.Animation.2.h"
#include "llm/impl/Windows.UI.Xaml.Navigation.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Navigation_IFrameNavigationOptions<D>::IsNavigationStackEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Navigation::IFrameNavigationOptions)->get_IsNavigationStackEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Navigation_IFrameNavigationOptions<D>::IsNavigationStackEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Navigation::IFrameNavigationOptions)->put_IsNavigationStackEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Media::Animation::NavigationTransitionInfo) consume_Windows_UI_Xaml_Navigation_IFrameNavigationOptions<D>::TransitionInfoOverride() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Navigation::IFrameNavigationOptions)->get_TransitionInfoOverride(&value));
        return llm::OS::UI::Xaml::Media::Animation::NavigationTransitionInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Navigation_IFrameNavigationOptions<D>::TransitionInfoOverride(llm::OS::UI::Xaml::Media::Animation::NavigationTransitionInfo const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Navigation::IFrameNavigationOptions)->put_TransitionInfoOverride(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Navigation::FrameNavigationOptions) consume_Windows_UI_Xaml_Navigation_IFrameNavigationOptionsFactory<D>::CreateInstance(llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Navigation::IFrameNavigationOptionsFactory)->CreateInstance(*(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Navigation::FrameNavigationOptions{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Navigation_INavigatingCancelEventArgs<D>::Cancel() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Navigation::INavigatingCancelEventArgs)->get_Cancel(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Navigation_INavigatingCancelEventArgs<D>::Cancel(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Navigation::INavigatingCancelEventArgs)->put_Cancel(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Navigation::NavigationMode) consume_Windows_UI_Xaml_Navigation_INavigatingCancelEventArgs<D>::NavigationMode() const
    {
        llm::OS::UI::Xaml::Navigation::NavigationMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Navigation::INavigatingCancelEventArgs)->get_NavigationMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Interop::TypeName) consume_Windows_UI_Xaml_Navigation_INavigatingCancelEventArgs<D>::SourcePageType() const
    {
        llm::OS::UI::Xaml::Interop::TypeName value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Navigation::INavigatingCancelEventArgs)->get_SourcePageType(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_UI_Xaml_Navigation_INavigatingCancelEventArgs2<D>::Parameter() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Navigation::INavigatingCancelEventArgs2)->get_Parameter(&value));
        return llm::OS::Foundation::IInspectable{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Media::Animation::NavigationTransitionInfo) consume_Windows_UI_Xaml_Navigation_INavigatingCancelEventArgs2<D>::NavigationTransitionInfo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Navigation::INavigatingCancelEventArgs2)->get_NavigationTransitionInfo(&value));
        return llm::OS::UI::Xaml::Media::Animation::NavigationTransitionInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_UI_Xaml_Navigation_INavigationEventArgs<D>::Content() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Navigation::INavigationEventArgs)->get_Content(&value));
        return llm::OS::Foundation::IInspectable{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_UI_Xaml_Navigation_INavigationEventArgs<D>::Parameter() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Navigation::INavigationEventArgs)->get_Parameter(&value));
        return llm::OS::Foundation::IInspectable{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Interop::TypeName) consume_Windows_UI_Xaml_Navigation_INavigationEventArgs<D>::SourcePageType() const
    {
        llm::OS::UI::Xaml::Interop::TypeName value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Navigation::INavigationEventArgs)->get_SourcePageType(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Navigation::NavigationMode) consume_Windows_UI_Xaml_Navigation_INavigationEventArgs<D>::NavigationMode() const
    {
        llm::OS::UI::Xaml::Navigation::NavigationMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Navigation::INavigationEventArgs)->get_NavigationMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_UI_Xaml_Navigation_INavigationEventArgs<D>::Uri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Navigation::INavigationEventArgs)->get_Uri(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Navigation_INavigationEventArgs<D>::Uri(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Navigation::INavigationEventArgs)->put_Uri(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Media::Animation::NavigationTransitionInfo) consume_Windows_UI_Xaml_Navigation_INavigationEventArgs2<D>::NavigationTransitionInfo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Navigation::INavigationEventArgs2)->get_NavigationTransitionInfo(&value));
        return llm::OS::UI::Xaml::Media::Animation::NavigationTransitionInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_UI_Xaml_Navigation_INavigationFailedEventArgs<D>::Exception() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Navigation::INavigationFailedEventArgs)->get_Exception(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Navigation_INavigationFailedEventArgs<D>::Handled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Navigation::INavigationFailedEventArgs)->get_Handled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Navigation_INavigationFailedEventArgs<D>::Handled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Navigation::INavigationFailedEventArgs)->put_Handled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Interop::TypeName) consume_Windows_UI_Xaml_Navigation_INavigationFailedEventArgs<D>::SourcePageType() const
    {
        llm::OS::UI::Xaml::Interop::TypeName value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Navigation::INavigationFailedEventArgs)->get_SourcePageType(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Interop::TypeName) consume_Windows_UI_Xaml_Navigation_IPageStackEntry<D>::SourcePageType() const
    {
        llm::OS::UI::Xaml::Interop::TypeName value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Navigation::IPageStackEntry)->get_SourcePageType(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_UI_Xaml_Navigation_IPageStackEntry<D>::Parameter() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Navigation::IPageStackEntry)->get_Parameter(&value));
        return llm::OS::Foundation::IInspectable{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Media::Animation::NavigationTransitionInfo) consume_Windows_UI_Xaml_Navigation_IPageStackEntry<D>::NavigationTransitionInfo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Navigation::IPageStackEntry)->get_NavigationTransitionInfo(&value));
        return llm::OS::UI::Xaml::Media::Animation::NavigationTransitionInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Navigation::PageStackEntry) consume_Windows_UI_Xaml_Navigation_IPageStackEntryFactory<D>::CreateInstance(llm::OS::UI::Xaml::Interop::TypeName const& sourcePageType, llm::OS::Foundation::IInspectable const& parameter, llm::OS::UI::Xaml::Media::Animation::NavigationTransitionInfo const& navigationTransitionInfo) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Navigation::IPageStackEntryFactory)->CreateInstance(impl::bind_in(sourcePageType), *(void**)(&parameter), *(void**)(&navigationTransitionInfo), &value));
        return llm::OS::UI::Xaml::Navigation::PageStackEntry{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) consume_Windows_UI_Xaml_Navigation_IPageStackEntryStatics<D>::SourcePageTypeProperty() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Navigation::IPageStackEntryStatics)->get_SourcePageTypeProperty(&value));
        return llm::OS::UI::Xaml::DependencyProperty{ value, take_ownership_from_abi };
    }
    template <typename H> struct delegate<llm::OS::UI::Xaml::Navigation::LoadCompletedEventHandler, H> final : implements_delegate<llm::OS::UI::Xaml::Navigation::LoadCompletedEventHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::UI::Xaml::Navigation::LoadCompletedEventHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* sender, void* e) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&sender), *reinterpret_cast<llm::OS::UI::Xaml::Navigation::NavigationEventArgs const*>(&e));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename H> struct delegate<llm::OS::UI::Xaml::Navigation::NavigatedEventHandler, H> final : implements_delegate<llm::OS::UI::Xaml::Navigation::NavigatedEventHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::UI::Xaml::Navigation::NavigatedEventHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* sender, void* e) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&sender), *reinterpret_cast<llm::OS::UI::Xaml::Navigation::NavigationEventArgs const*>(&e));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename H> struct delegate<llm::OS::UI::Xaml::Navigation::NavigatingCancelEventHandler, H> final : implements_delegate<llm::OS::UI::Xaml::Navigation::NavigatingCancelEventHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::UI::Xaml::Navigation::NavigatingCancelEventHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* sender, void* e) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&sender), *reinterpret_cast<llm::OS::UI::Xaml::Navigation::NavigatingCancelEventArgs const*>(&e));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename H> struct delegate<llm::OS::UI::Xaml::Navigation::NavigationFailedEventHandler, H> final : implements_delegate<llm::OS::UI::Xaml::Navigation::NavigationFailedEventHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::UI::Xaml::Navigation::NavigationFailedEventHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* sender, void* e) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&sender), *reinterpret_cast<llm::OS::UI::Xaml::Navigation::NavigationFailedEventArgs const*>(&e));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename H> struct delegate<llm::OS::UI::Xaml::Navigation::NavigationStoppedEventHandler, H> final : implements_delegate<llm::OS::UI::Xaml::Navigation::NavigationStoppedEventHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::UI::Xaml::Navigation::NavigationStoppedEventHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* sender, void* e) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&sender), *reinterpret_cast<llm::OS::UI::Xaml::Navigation::NavigationEventArgs const*>(&e));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Navigation::IFrameNavigationOptions> : produce_base<D, llm::OS::UI::Xaml::Navigation::IFrameNavigationOptions>
    {
        int32_t __stdcall get_IsNavigationStackEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsNavigationStackEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsNavigationStackEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsNavigationStackEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TransitionInfoOverride(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Media::Animation::NavigationTransitionInfo>(this->shim().TransitionInfoOverride());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TransitionInfoOverride(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransitionInfoOverride(*reinterpret_cast<llm::OS::UI::Xaml::Media::Animation::NavigationTransitionInfo const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Navigation::IFrameNavigationOptionsFactory> : produce_base<D, llm::OS::UI::Xaml::Navigation::IFrameNavigationOptionsFactory>
    {
        int32_t __stdcall CreateInstance(void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Navigation::FrameNavigationOptions>(this->shim().CreateInstance(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Navigation::INavigatingCancelEventArgs> : produce_base<D, llm::OS::UI::Xaml::Navigation::INavigatingCancelEventArgs>
    {
        int32_t __stdcall get_Cancel(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Cancel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Cancel(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Cancel(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NavigationMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Navigation::NavigationMode>(this->shim().NavigationMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SourcePageType(struct struct_Windows_UI_Xaml_Interop_TypeName* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Xaml::Interop::TypeName>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Interop::TypeName>(this->shim().SourcePageType());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Navigation::INavigatingCancelEventArgs2> : produce_base<D, llm::OS::UI::Xaml::Navigation::INavigatingCancelEventArgs2>
    {
        int32_t __stdcall get_Parameter(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IInspectable>(this->shim().Parameter());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NavigationTransitionInfo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Media::Animation::NavigationTransitionInfo>(this->shim().NavigationTransitionInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Navigation::INavigationEventArgs> : produce_base<D, llm::OS::UI::Xaml::Navigation::INavigationEventArgs>
    {
        int32_t __stdcall get_Content(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IInspectable>(this->shim().Content());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Parameter(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IInspectable>(this->shim().Parameter());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SourcePageType(struct struct_Windows_UI_Xaml_Interop_TypeName* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Xaml::Interop::TypeName>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Interop::TypeName>(this->shim().SourcePageType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NavigationMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Navigation::NavigationMode>(this->shim().NavigationMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Uri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().Uri());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Uri(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Uri(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Navigation::INavigationEventArgs2> : produce_base<D, llm::OS::UI::Xaml::Navigation::INavigationEventArgs2>
    {
        int32_t __stdcall get_NavigationTransitionInfo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Media::Animation::NavigationTransitionInfo>(this->shim().NavigationTransitionInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Navigation::INavigationFailedEventArgs> : produce_base<D, llm::OS::UI::Xaml::Navigation::INavigationFailedEventArgs>
    {
        int32_t __stdcall get_Exception(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().Exception());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Handled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Handled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Handled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SourcePageType(struct struct_Windows_UI_Xaml_Interop_TypeName* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Xaml::Interop::TypeName>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Interop::TypeName>(this->shim().SourcePageType());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Navigation::IPageStackEntry> : produce_base<D, llm::OS::UI::Xaml::Navigation::IPageStackEntry>
    {
        int32_t __stdcall get_SourcePageType(struct struct_Windows_UI_Xaml_Interop_TypeName* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Xaml::Interop::TypeName>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Interop::TypeName>(this->shim().SourcePageType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Parameter(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IInspectable>(this->shim().Parameter());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NavigationTransitionInfo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Media::Animation::NavigationTransitionInfo>(this->shim().NavigationTransitionInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Navigation::IPageStackEntryFactory> : produce_base<D, llm::OS::UI::Xaml::Navigation::IPageStackEntryFactory>
    {
        int32_t __stdcall CreateInstance(struct struct_Windows_UI_Xaml_Interop_TypeName sourcePageType, void* parameter, void* navigationTransitionInfo, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Navigation::PageStackEntry>(this->shim().CreateInstance(*reinterpret_cast<llm::OS::UI::Xaml::Interop::TypeName const*>(&sourcePageType), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&parameter), *reinterpret_cast<llm::OS::UI::Xaml::Media::Animation::NavigationTransitionInfo const*>(&navigationTransitionInfo)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Navigation::IPageStackEntryStatics> : produce_base<D, llm::OS::UI::Xaml::Navigation::IPageStackEntryStatics>
    {
        int32_t __stdcall get_SourcePageTypeProperty(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::DependencyProperty>(this->shim().SourcePageTypeProperty());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::UI::Xaml::Navigation
{
    inline FrameNavigationOptions::FrameNavigationOptions()
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<FrameNavigationOptions, IFrameNavigationOptionsFactory>([&](IFrameNavigationOptionsFactory const& f) { return f.CreateInstance(baseInterface, innerInterface); });
    }
    inline PageStackEntry::PageStackEntry(llm::OS::UI::Xaml::Interop::TypeName const& sourcePageType, llm::OS::Foundation::IInspectable const& parameter, llm::OS::UI::Xaml::Media::Animation::NavigationTransitionInfo const& navigationTransitionInfo) :
        PageStackEntry(impl::call_factory<PageStackEntry, IPageStackEntryFactory>([&](IPageStackEntryFactory const& f) { return f.CreateInstance(sourcePageType, parameter, navigationTransitionInfo); }))
    {
    }
    inline auto PageStackEntry::SourcePageTypeProperty()
    {
        return impl::call_factory_cast<llm::OS::UI::Xaml::DependencyProperty(*)(IPageStackEntryStatics const&), PageStackEntry, IPageStackEntryStatics>([](IPageStackEntryStatics const& f) { return f.SourcePageTypeProperty(); });
    }
    template <typename L> LoadCompletedEventHandler::LoadCompletedEventHandler(L handler) :
        LoadCompletedEventHandler(impl::make_delegate<LoadCompletedEventHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> LoadCompletedEventHandler::LoadCompletedEventHandler(F* handler) :
        LoadCompletedEventHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> LoadCompletedEventHandler::LoadCompletedEventHandler(O* object, M method) :
        LoadCompletedEventHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> LoadCompletedEventHandler::LoadCompletedEventHandler(com_ptr<O>&& object, M method) :
        LoadCompletedEventHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> LoadCompletedEventHandler::LoadCompletedEventHandler(weak_ref<O>&& object, M method) :
        LoadCompletedEventHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto LoadCompletedEventHandler::operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Navigation::NavigationEventArgs const& e) const
    {
        check_hresult((*(impl::abi_t<LoadCompletedEventHandler>**)this)->Invoke(*(void**)(&sender), *(void**)(&e)));
    }
    template <typename L> NavigatedEventHandler::NavigatedEventHandler(L handler) :
        NavigatedEventHandler(impl::make_delegate<NavigatedEventHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> NavigatedEventHandler::NavigatedEventHandler(F* handler) :
        NavigatedEventHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> NavigatedEventHandler::NavigatedEventHandler(O* object, M method) :
        NavigatedEventHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> NavigatedEventHandler::NavigatedEventHandler(com_ptr<O>&& object, M method) :
        NavigatedEventHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> NavigatedEventHandler::NavigatedEventHandler(weak_ref<O>&& object, M method) :
        NavigatedEventHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto NavigatedEventHandler::operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Navigation::NavigationEventArgs const& e) const
    {
        check_hresult((*(impl::abi_t<NavigatedEventHandler>**)this)->Invoke(*(void**)(&sender), *(void**)(&e)));
    }
    template <typename L> NavigatingCancelEventHandler::NavigatingCancelEventHandler(L handler) :
        NavigatingCancelEventHandler(impl::make_delegate<NavigatingCancelEventHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> NavigatingCancelEventHandler::NavigatingCancelEventHandler(F* handler) :
        NavigatingCancelEventHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> NavigatingCancelEventHandler::NavigatingCancelEventHandler(O* object, M method) :
        NavigatingCancelEventHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> NavigatingCancelEventHandler::NavigatingCancelEventHandler(com_ptr<O>&& object, M method) :
        NavigatingCancelEventHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> NavigatingCancelEventHandler::NavigatingCancelEventHandler(weak_ref<O>&& object, M method) :
        NavigatingCancelEventHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto NavigatingCancelEventHandler::operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Navigation::NavigatingCancelEventArgs const& e) const
    {
        check_hresult((*(impl::abi_t<NavigatingCancelEventHandler>**)this)->Invoke(*(void**)(&sender), *(void**)(&e)));
    }
    template <typename L> NavigationFailedEventHandler::NavigationFailedEventHandler(L handler) :
        NavigationFailedEventHandler(impl::make_delegate<NavigationFailedEventHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> NavigationFailedEventHandler::NavigationFailedEventHandler(F* handler) :
        NavigationFailedEventHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> NavigationFailedEventHandler::NavigationFailedEventHandler(O* object, M method) :
        NavigationFailedEventHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> NavigationFailedEventHandler::NavigationFailedEventHandler(com_ptr<O>&& object, M method) :
        NavigationFailedEventHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> NavigationFailedEventHandler::NavigationFailedEventHandler(weak_ref<O>&& object, M method) :
        NavigationFailedEventHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto NavigationFailedEventHandler::operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Navigation::NavigationFailedEventArgs const& e) const
    {
        check_hresult((*(impl::abi_t<NavigationFailedEventHandler>**)this)->Invoke(*(void**)(&sender), *(void**)(&e)));
    }
    template <typename L> NavigationStoppedEventHandler::NavigationStoppedEventHandler(L handler) :
        NavigationStoppedEventHandler(impl::make_delegate<NavigationStoppedEventHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> NavigationStoppedEventHandler::NavigationStoppedEventHandler(F* handler) :
        NavigationStoppedEventHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> NavigationStoppedEventHandler::NavigationStoppedEventHandler(O* object, M method) :
        NavigationStoppedEventHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> NavigationStoppedEventHandler::NavigationStoppedEventHandler(com_ptr<O>&& object, M method) :
        NavigationStoppedEventHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> NavigationStoppedEventHandler::NavigationStoppedEventHandler(weak_ref<O>&& object, M method) :
        NavigationStoppedEventHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto NavigationStoppedEventHandler::operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Navigation::NavigationEventArgs const& e) const
    {
        check_hresult((*(impl::abi_t<NavigationStoppedEventHandler>**)this)->Invoke(*(void**)(&sender), *(void**)(&e)));
    }
    template <typename D, typename... Interfaces>
    struct FrameNavigationOptionsT :
        implements<D, llm::OS::Foundation::IInspectable, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Navigation::IFrameNavigationOptions>,
        impl::base<D, FrameNavigationOptions>
    {
        using composable = FrameNavigationOptions;
    protected:
        FrameNavigationOptionsT()
        {
            impl::call_factory<FrameNavigationOptions, IFrameNavigationOptionsFactory>([&](IFrameNavigationOptionsFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstance(*this, this->m_inner); });
        }
    };
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::Xaml::Navigation::IFrameNavigationOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Navigation::IFrameNavigationOptionsFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Navigation::INavigatingCancelEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Navigation::INavigatingCancelEventArgs2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Navigation::INavigationEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Navigation::INavigationEventArgs2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Navigation::INavigationFailedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Navigation::IPageStackEntry> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Navigation::IPageStackEntryFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Navigation::IPageStackEntryStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Navigation::FrameNavigationOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Navigation::NavigatingCancelEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Navigation::NavigationEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Navigation::NavigationFailedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Navigation::PageStackEntry> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
