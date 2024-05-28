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
#ifndef LLM_OS_Devices_Input_H
#define LLM_OS_Devices_Input_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Devices.h"
#include "llm/impl/Windows.Devices.Haptics.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Devices.Input.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Input_IKeyboardCapabilities<D>::KeyboardPresent() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::IKeyboardCapabilities)->get_KeyboardPresent(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Input_IMouseCapabilities<D>::MousePresent() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::IMouseCapabilities)->get_MousePresent(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Input_IMouseCapabilities<D>::VerticalWheelPresent() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::IMouseCapabilities)->get_VerticalWheelPresent(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Input_IMouseCapabilities<D>::HorizontalWheelPresent() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::IMouseCapabilities)->get_HorizontalWheelPresent(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Input_IMouseCapabilities<D>::SwapButtons() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::IMouseCapabilities)->get_SwapButtons(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_Input_IMouseCapabilities<D>::NumberOfButtons() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::IMouseCapabilities)->get_NumberOfButtons(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Input_IMouseDevice<D>::MouseMoved(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::MouseDevice, llm::OS::Devices::Input::MouseEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::IMouseDevice)->add_MouseMoved(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_Devices_Input_IMouseDevice<D>::MouseMoved_revoker consume_Windows_Devices_Input_IMouseDevice<D>::MouseMoved(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::MouseDevice, llm::OS::Devices::Input::MouseEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, MouseMoved_revoker>(this, MouseMoved(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Input_IMouseDevice<D>::MouseMoved(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Input::IMouseDevice)->remove_MouseMoved(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Input::MouseDevice) consume_Windows_Devices_Input_IMouseDeviceStatics<D>::GetForCurrentView() const
    {
        void* mouseDevice{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::IMouseDeviceStatics)->GetForCurrentView(&mouseDevice));
        return llm::OS::Devices::Input::MouseDevice{ mouseDevice, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Input::MouseDelta) consume_Windows_Devices_Input_IMouseEventArgs<D>::MouseDelta() const
    {
        llm::OS::Devices::Input::MouseDelta value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::IMouseEventArgs)->get_MouseDelta(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Input_IPenButtonListener<D>::IsSupported() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::IPenButtonListener)->IsSupported(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Input_IPenButtonListener<D>::IsSupportedChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::PenButtonListener, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::IPenButtonListener)->add_IsSupportedChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Input_IPenButtonListener<D>::IsSupportedChanged_revoker consume_Windows_Devices_Input_IPenButtonListener<D>::IsSupportedChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::PenButtonListener, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, IsSupportedChanged_revoker>(this, IsSupportedChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Input_IPenButtonListener<D>::IsSupportedChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Input::IPenButtonListener)->remove_IsSupportedChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Input_IPenButtonListener<D>::TailButtonClicked(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::PenButtonListener, llm::OS::Devices::Input::PenTailButtonClickedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::IPenButtonListener)->add_TailButtonClicked(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Input_IPenButtonListener<D>::TailButtonClicked_revoker consume_Windows_Devices_Input_IPenButtonListener<D>::TailButtonClicked(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::PenButtonListener, llm::OS::Devices::Input::PenTailButtonClickedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, TailButtonClicked_revoker>(this, TailButtonClicked(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Input_IPenButtonListener<D>::TailButtonClicked(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Input::IPenButtonListener)->remove_TailButtonClicked(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Input_IPenButtonListener<D>::TailButtonDoubleClicked(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::PenButtonListener, llm::OS::Devices::Input::PenTailButtonDoubleClickedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::IPenButtonListener)->add_TailButtonDoubleClicked(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Input_IPenButtonListener<D>::TailButtonDoubleClicked_revoker consume_Windows_Devices_Input_IPenButtonListener<D>::TailButtonDoubleClicked(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::PenButtonListener, llm::OS::Devices::Input::PenTailButtonDoubleClickedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, TailButtonDoubleClicked_revoker>(this, TailButtonDoubleClicked(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Input_IPenButtonListener<D>::TailButtonDoubleClicked(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Input::IPenButtonListener)->remove_TailButtonDoubleClicked(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Input_IPenButtonListener<D>::TailButtonLongPressed(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::PenButtonListener, llm::OS::Devices::Input::PenTailButtonLongPressedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::IPenButtonListener)->add_TailButtonLongPressed(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Input_IPenButtonListener<D>::TailButtonLongPressed_revoker consume_Windows_Devices_Input_IPenButtonListener<D>::TailButtonLongPressed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::PenButtonListener, llm::OS::Devices::Input::PenTailButtonLongPressedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, TailButtonLongPressed_revoker>(this, TailButtonLongPressed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Input_IPenButtonListener<D>::TailButtonLongPressed(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Input::IPenButtonListener)->remove_TailButtonLongPressed(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Input::PenButtonListener) consume_Windows_Devices_Input_IPenButtonListenerStatics<D>::GetDefault() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::IPenButtonListenerStatics)->GetDefault(&result));
        return llm::OS::Devices::Input::PenButtonListener{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Devices_Input_IPenDevice<D>::PenId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::IPenDevice)->get_PenId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Haptics::SimpleHapticsController) consume_Windows_Devices_Input_IPenDevice2<D>::SimpleHapticsController() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::IPenDevice2)->get_SimpleHapticsController(&value));
        return llm::OS::Devices::Haptics::SimpleHapticsController{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Input::PenDevice) consume_Windows_Devices_Input_IPenDeviceStatics<D>::GetFromPointerId(uint32_t pointerId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::IPenDeviceStatics)->GetFromPointerId(pointerId, &result));
        return llm::OS::Devices::Input::PenDevice{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Input_IPenDockListener<D>::IsSupported() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::IPenDockListener)->IsSupported(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Input_IPenDockListener<D>::IsSupportedChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::PenDockListener, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::IPenDockListener)->add_IsSupportedChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Input_IPenDockListener<D>::IsSupportedChanged_revoker consume_Windows_Devices_Input_IPenDockListener<D>::IsSupportedChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::PenDockListener, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, IsSupportedChanged_revoker>(this, IsSupportedChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Input_IPenDockListener<D>::IsSupportedChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Input::IPenDockListener)->remove_IsSupportedChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Input_IPenDockListener<D>::Docked(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::PenDockListener, llm::OS::Devices::Input::PenDockedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::IPenDockListener)->add_Docked(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Input_IPenDockListener<D>::Docked_revoker consume_Windows_Devices_Input_IPenDockListener<D>::Docked(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::PenDockListener, llm::OS::Devices::Input::PenDockedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Docked_revoker>(this, Docked(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Input_IPenDockListener<D>::Docked(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Input::IPenDockListener)->remove_Docked(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Input_IPenDockListener<D>::Undocked(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::PenDockListener, llm::OS::Devices::Input::PenUndockedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::IPenDockListener)->add_Undocked(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Input_IPenDockListener<D>::Undocked_revoker consume_Windows_Devices_Input_IPenDockListener<D>::Undocked(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::PenDockListener, llm::OS::Devices::Input::PenUndockedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Undocked_revoker>(this, Undocked(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Input_IPenDockListener<D>::Undocked(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Input::IPenDockListener)->remove_Undocked(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Input::PenDockListener) consume_Windows_Devices_Input_IPenDockListenerStatics<D>::GetDefault() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::IPenDockListenerStatics)->GetDefault(&result));
        return llm::OS::Devices::Input::PenDockListener{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Input::PointerDeviceType) consume_Windows_Devices_Input_IPointerDevice<D>::PointerDeviceType() const
    {
        llm::OS::Devices::Input::PointerDeviceType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::IPointerDevice)->get_PointerDeviceType(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Input_IPointerDevice<D>::IsIntegrated() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::IPointerDevice)->get_IsIntegrated(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_Input_IPointerDevice<D>::MaxContacts() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::IPointerDevice)->get_MaxContacts(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_Devices_Input_IPointerDevice<D>::PhysicalDeviceRect() const
    {
        llm::OS::Foundation::Rect value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::IPointerDevice)->get_PhysicalDeviceRect(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_Devices_Input_IPointerDevice<D>::ScreenRect() const
    {
        llm::OS::Foundation::Rect value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::IPointerDevice)->get_ScreenRect(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Input::PointerDeviceUsage>) consume_Windows_Devices_Input_IPointerDevice<D>::SupportedUsages() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::IPointerDevice)->get_SupportedUsages(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Input::PointerDeviceUsage>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_Input_IPointerDevice2<D>::MaxPointersWithZDistance() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::IPointerDevice2)->get_MaxPointersWithZDistance(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Input::PointerDevice) consume_Windows_Devices_Input_IPointerDeviceStatics<D>::GetPointerDevice(uint32_t pointerId) const
    {
        void* pointerDevice{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::IPointerDeviceStatics)->GetPointerDevice(pointerId, &pointerDevice));
        return llm::OS::Devices::Input::PointerDevice{ pointerDevice, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Input::PointerDevice>) consume_Windows_Devices_Input_IPointerDeviceStatics<D>::GetPointerDevices() const
    {
        void* pointerDevices{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::IPointerDeviceStatics)->GetPointerDevices(&pointerDevices));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Input::PointerDevice>{ pointerDevices, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Input_ITouchCapabilities<D>::TouchPresent() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::ITouchCapabilities)->get_TouchPresent(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_Input_ITouchCapabilities<D>::Contacts() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Input::ITouchCapabilities)->get_Contacts(&value));
        return value;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Input::IKeyboardCapabilities> : produce_base<D, llm::OS::Devices::Input::IKeyboardCapabilities>
    {
        int32_t __stdcall get_KeyboardPresent(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().KeyboardPresent());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Input::IMouseCapabilities> : produce_base<D, llm::OS::Devices::Input::IMouseCapabilities>
    {
        int32_t __stdcall get_MousePresent(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().MousePresent());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VerticalWheelPresent(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().VerticalWheelPresent());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HorizontalWheelPresent(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().HorizontalWheelPresent());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SwapButtons(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().SwapButtons());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NumberOfButtons(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().NumberOfButtons());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Input::IMouseDevice> : produce_base<D, llm::OS::Devices::Input::IMouseDevice>
    {
        int32_t __stdcall add_MouseMoved(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().MouseMoved(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::MouseDevice, llm::OS::Devices::Input::MouseEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_MouseMoved(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MouseMoved(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Input::IMouseDeviceStatics> : produce_base<D, llm::OS::Devices::Input::IMouseDeviceStatics>
    {
        int32_t __stdcall GetForCurrentView(void** mouseDevice) noexcept final try
        {
            clear_abi(mouseDevice);
            typename D::abi_guard guard(this->shim());
            *mouseDevice = detach_from<llm::OS::Devices::Input::MouseDevice>(this->shim().GetForCurrentView());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Input::IMouseEventArgs> : produce_base<D, llm::OS::Devices::Input::IMouseEventArgs>
    {
        int32_t __stdcall get_MouseDelta(struct struct_Windows_Devices_Input_MouseDelta* value) noexcept final try
        {
            zero_abi<llm::OS::Devices::Input::MouseDelta>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Input::MouseDelta>(this->shim().MouseDelta());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Input::IPenButtonListener> : produce_base<D, llm::OS::Devices::Input::IPenButtonListener>
    {
        int32_t __stdcall IsSupported(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_IsSupportedChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().IsSupportedChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::PenButtonListener, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_IsSupportedChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsSupportedChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_TailButtonClicked(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().TailButtonClicked(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::PenButtonListener, llm::OS::Devices::Input::PenTailButtonClickedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_TailButtonClicked(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TailButtonClicked(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_TailButtonDoubleClicked(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().TailButtonDoubleClicked(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::PenButtonListener, llm::OS::Devices::Input::PenTailButtonDoubleClickedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_TailButtonDoubleClicked(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TailButtonDoubleClicked(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_TailButtonLongPressed(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().TailButtonLongPressed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::PenButtonListener, llm::OS::Devices::Input::PenTailButtonLongPressedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_TailButtonLongPressed(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TailButtonLongPressed(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Input::IPenButtonListenerStatics> : produce_base<D, llm::OS::Devices::Input::IPenButtonListenerStatics>
    {
        int32_t __stdcall GetDefault(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Input::PenButtonListener>(this->shim().GetDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Input::IPenDevice> : produce_base<D, llm::OS::Devices::Input::IPenDevice>
    {
        int32_t __stdcall get_PenId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().PenId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Input::IPenDevice2> : produce_base<D, llm::OS::Devices::Input::IPenDevice2>
    {
        int32_t __stdcall get_SimpleHapticsController(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Haptics::SimpleHapticsController>(this->shim().SimpleHapticsController());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Input::IPenDeviceStatics> : produce_base<D, llm::OS::Devices::Input::IPenDeviceStatics>
    {
        int32_t __stdcall GetFromPointerId(uint32_t pointerId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Input::PenDevice>(this->shim().GetFromPointerId(pointerId));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Input::IPenDockListener> : produce_base<D, llm::OS::Devices::Input::IPenDockListener>
    {
        int32_t __stdcall IsSupported(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_IsSupportedChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().IsSupportedChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::PenDockListener, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_IsSupportedChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsSupportedChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Docked(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Docked(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::PenDockListener, llm::OS::Devices::Input::PenDockedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Docked(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Docked(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Undocked(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Undocked(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Input::PenDockListener, llm::OS::Devices::Input::PenUndockedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Undocked(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Undocked(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Input::IPenDockListenerStatics> : produce_base<D, llm::OS::Devices::Input::IPenDockListenerStatics>
    {
        int32_t __stdcall GetDefault(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Input::PenDockListener>(this->shim().GetDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Input::IPenDockedEventArgs> : produce_base<D, llm::OS::Devices::Input::IPenDockedEventArgs>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Input::IPenTailButtonClickedEventArgs> : produce_base<D, llm::OS::Devices::Input::IPenTailButtonClickedEventArgs>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Input::IPenTailButtonDoubleClickedEventArgs> : produce_base<D, llm::OS::Devices::Input::IPenTailButtonDoubleClickedEventArgs>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Input::IPenTailButtonLongPressedEventArgs> : produce_base<D, llm::OS::Devices::Input::IPenTailButtonLongPressedEventArgs>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Input::IPenUndockedEventArgs> : produce_base<D, llm::OS::Devices::Input::IPenUndockedEventArgs>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Input::IPointerDevice> : produce_base<D, llm::OS::Devices::Input::IPointerDevice>
    {
        int32_t __stdcall get_PointerDeviceType(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Input::PointerDeviceType>(this->shim().PointerDeviceType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsIntegrated(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsIntegrated());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxContacts(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MaxContacts());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PhysicalDeviceRect(llm::OS::Foundation::Rect* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Rect>(this->shim().PhysicalDeviceRect());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ScreenRect(llm::OS::Foundation::Rect* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Rect>(this->shim().ScreenRect());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportedUsages(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Input::PointerDeviceUsage>>(this->shim().SupportedUsages());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Input::IPointerDevice2> : produce_base<D, llm::OS::Devices::Input::IPointerDevice2>
    {
        int32_t __stdcall get_MaxPointersWithZDistance(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MaxPointersWithZDistance());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Input::IPointerDeviceStatics> : produce_base<D, llm::OS::Devices::Input::IPointerDeviceStatics>
    {
        int32_t __stdcall GetPointerDevice(uint32_t pointerId, void** pointerDevice) noexcept final try
        {
            clear_abi(pointerDevice);
            typename D::abi_guard guard(this->shim());
            *pointerDevice = detach_from<llm::OS::Devices::Input::PointerDevice>(this->shim().GetPointerDevice(pointerId));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetPointerDevices(void** pointerDevices) noexcept final try
        {
            clear_abi(pointerDevices);
            typename D::abi_guard guard(this->shim());
            *pointerDevices = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Input::PointerDevice>>(this->shim().GetPointerDevices());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Input::ITouchCapabilities> : produce_base<D, llm::OS::Devices::Input::ITouchCapabilities>
    {
        int32_t __stdcall get_TouchPresent(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().TouchPresent());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Contacts(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Contacts());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Devices::Input
{
    inline KeyboardCapabilities::KeyboardCapabilities() :
        KeyboardCapabilities(impl::call_factory_cast<KeyboardCapabilities(*)(llm::OS::Foundation::IActivationFactory const&), KeyboardCapabilities>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<KeyboardCapabilities>(); }))
    {
    }
    inline MouseCapabilities::MouseCapabilities() :
        MouseCapabilities(impl::call_factory_cast<MouseCapabilities(*)(llm::OS::Foundation::IActivationFactory const&), MouseCapabilities>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<MouseCapabilities>(); }))
    {
    }
    inline auto MouseDevice::GetForCurrentView()
    {
        return impl::call_factory_cast<llm::OS::Devices::Input::MouseDevice(*)(IMouseDeviceStatics const&), MouseDevice, IMouseDeviceStatics>([](IMouseDeviceStatics const& f) { return f.GetForCurrentView(); });
    }
    inline auto PenButtonListener::GetDefault()
    {
        return impl::call_factory_cast<llm::OS::Devices::Input::PenButtonListener(*)(IPenButtonListenerStatics const&), PenButtonListener, IPenButtonListenerStatics>([](IPenButtonListenerStatics const& f) { return f.GetDefault(); });
    }
    inline auto PenDevice::GetFromPointerId(uint32_t pointerId)
    {
        return impl::call_factory<PenDevice, IPenDeviceStatics>([&](IPenDeviceStatics const& f) { return f.GetFromPointerId(pointerId); });
    }
    inline auto PenDockListener::GetDefault()
    {
        return impl::call_factory_cast<llm::OS::Devices::Input::PenDockListener(*)(IPenDockListenerStatics const&), PenDockListener, IPenDockListenerStatics>([](IPenDockListenerStatics const& f) { return f.GetDefault(); });
    }
    inline auto PointerDevice::GetPointerDevice(uint32_t pointerId)
    {
        return impl::call_factory<PointerDevice, IPointerDeviceStatics>([&](IPointerDeviceStatics const& f) { return f.GetPointerDevice(pointerId); });
    }
    inline auto PointerDevice::GetPointerDevices()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Input::PointerDevice>(*)(IPointerDeviceStatics const&), PointerDevice, IPointerDeviceStatics>([](IPointerDeviceStatics const& f) { return f.GetPointerDevices(); });
    }
    inline TouchCapabilities::TouchCapabilities() :
        TouchCapabilities(impl::call_factory_cast<TouchCapabilities(*)(llm::OS::Foundation::IActivationFactory const&), TouchCapabilities>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<TouchCapabilities>(); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Devices::Input::IKeyboardCapabilities> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::IMouseCapabilities> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::IMouseDevice> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::IMouseDeviceStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::IMouseEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::IPenButtonListener> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::IPenButtonListenerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::IPenDevice> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::IPenDevice2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::IPenDeviceStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::IPenDockListener> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::IPenDockListenerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::IPenDockedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::IPenTailButtonClickedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::IPenTailButtonDoubleClickedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::IPenTailButtonLongPressedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::IPenUndockedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::IPointerDevice> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::IPointerDevice2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::IPointerDeviceStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::ITouchCapabilities> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::KeyboardCapabilities> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::MouseCapabilities> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::MouseDevice> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::MouseEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::PenButtonListener> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::PenDevice> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::PenDockListener> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::PenDockedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::PenTailButtonClickedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::PenTailButtonDoubleClickedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::PenTailButtonLongPressedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::PenUndockedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::PointerDevice> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Input::TouchCapabilities> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
