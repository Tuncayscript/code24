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
#ifndef LLM_OS_Media_Casting_H
#define LLM_OS_Media_Casting_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Media.h"
#include "llm/impl/Windows.Devices.Enumeration.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.UI.Popups.2.h"
#include "llm/impl/Windows.Media.Casting.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Casting::CastingConnectionState) consume_Windows_Media_Casting_ICastingConnection<D>::State() const
    {
        llm::OS::Media::Casting::CastingConnectionState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingConnection)->get_State(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Casting::CastingDevice) consume_Windows_Media_Casting_ICastingConnection<D>::Device() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingConnection)->get_Device(&value));
        return llm::OS::Media::Casting::CastingDevice{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Casting::CastingSource) consume_Windows_Media_Casting_ICastingConnection<D>::Source() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingConnection)->get_Source(&value));
        return llm::OS::Media::Casting::CastingSource{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Casting_ICastingConnection<D>::Source(llm::OS::Media::Casting::CastingSource const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingConnection)->put_Source(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Casting_ICastingConnection<D>::StateChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Casting::CastingConnection, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingConnection)->add_StateChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Casting_ICastingConnection<D>::StateChanged_revoker consume_Windows_Media_Casting_ICastingConnection<D>::StateChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Casting::CastingConnection, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, StateChanged_revoker>(this, StateChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Casting_ICastingConnection<D>::StateChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingConnection)->remove_StateChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Casting_ICastingConnection<D>::ErrorOccurred(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Casting::CastingConnection, llm::OS::Media::Casting::CastingConnectionErrorOccurredEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingConnection)->add_ErrorOccurred(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Casting_ICastingConnection<D>::ErrorOccurred_revoker consume_Windows_Media_Casting_ICastingConnection<D>::ErrorOccurred(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Casting::CastingConnection, llm::OS::Media::Casting::CastingConnectionErrorOccurredEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, ErrorOccurred_revoker>(this, ErrorOccurred(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Casting_ICastingConnection<D>::ErrorOccurred(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingConnection)->remove_ErrorOccurred(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Casting::CastingConnectionErrorStatus>) consume_Windows_Media_Casting_ICastingConnection<D>::RequestStartCastingAsync(llm::OS::Media::Casting::CastingSource const& value) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingConnection)->RequestStartCastingAsync(*(void**)(&value), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Casting::CastingConnectionErrorStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Casting::CastingConnectionErrorStatus>) consume_Windows_Media_Casting_ICastingConnection<D>::DisconnectAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingConnection)->DisconnectAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Casting::CastingConnectionErrorStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Casting::CastingConnectionErrorStatus) consume_Windows_Media_Casting_ICastingConnectionErrorOccurredEventArgs<D>::ErrorStatus() const
    {
        llm::OS::Media::Casting::CastingConnectionErrorStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingConnectionErrorOccurredEventArgs)->get_ErrorStatus(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Casting_ICastingConnectionErrorOccurredEventArgs<D>::Message() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingConnectionErrorOccurredEventArgs)->get_Message(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Casting_ICastingDevice<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingDevice)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Casting_ICastingDevice<D>::FriendlyName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingDevice)->get_FriendlyName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStreamWithContentType) consume_Windows_Media_Casting_ICastingDevice<D>::Icon() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingDevice)->get_Icon(&value));
        return llm::OS::Storage::Streams::IRandomAccessStreamWithContentType{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Casting::CastingPlaybackTypes>) consume_Windows_Media_Casting_ICastingDevice<D>::GetSupportedCastingPlaybackTypesAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingDevice)->GetSupportedCastingPlaybackTypesAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Casting::CastingPlaybackTypes>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Casting::CastingConnection) consume_Windows_Media_Casting_ICastingDevice<D>::CreateCastingConnection() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingDevice)->CreateCastingConnection(&value));
        return llm::OS::Media::Casting::CastingConnection{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Casting::CastingDevicePickerFilter) consume_Windows_Media_Casting_ICastingDevicePicker<D>::Filter() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingDevicePicker)->get_Filter(&value));
        return llm::OS::Media::Casting::CastingDevicePickerFilter{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DevicePickerAppearance) consume_Windows_Media_Casting_ICastingDevicePicker<D>::Appearance() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingDevicePicker)->get_Appearance(&value));
        return llm::OS::Devices::Enumeration::DevicePickerAppearance{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Casting_ICastingDevicePicker<D>::CastingDeviceSelected(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Casting::CastingDevicePicker, llm::OS::Media::Casting::CastingDeviceSelectedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingDevicePicker)->add_CastingDeviceSelected(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Casting_ICastingDevicePicker<D>::CastingDeviceSelected_revoker consume_Windows_Media_Casting_ICastingDevicePicker<D>::CastingDeviceSelected(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Casting::CastingDevicePicker, llm::OS::Media::Casting::CastingDeviceSelectedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, CastingDeviceSelected_revoker>(this, CastingDeviceSelected(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Casting_ICastingDevicePicker<D>::CastingDeviceSelected(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingDevicePicker)->remove_CastingDeviceSelected(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Casting_ICastingDevicePicker<D>::CastingDevicePickerDismissed(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Casting::CastingDevicePicker, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingDevicePicker)->add_CastingDevicePickerDismissed(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Casting_ICastingDevicePicker<D>::CastingDevicePickerDismissed_revoker consume_Windows_Media_Casting_ICastingDevicePicker<D>::CastingDevicePickerDismissed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Casting::CastingDevicePicker, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, CastingDevicePickerDismissed_revoker>(this, CastingDevicePickerDismissed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Casting_ICastingDevicePicker<D>::CastingDevicePickerDismissed(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingDevicePicker)->remove_CastingDevicePickerDismissed(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Casting_ICastingDevicePicker<D>::Show(llm::OS::Foundation::Rect const& selection) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingDevicePicker)->Show(impl::bind_in(selection)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Casting_ICastingDevicePicker<D>::Show(llm::OS::Foundation::Rect const& selection, llm::OS::UI::Popups::Placement const& preferredPlacement) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingDevicePicker)->ShowWithPlacement(impl::bind_in(selection), static_cast<int32_t>(preferredPlacement)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Casting_ICastingDevicePicker<D>::Hide() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingDevicePicker)->Hide());
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Casting_ICastingDevicePickerFilter<D>::SupportsAudio() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingDevicePickerFilter)->get_SupportsAudio(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Casting_ICastingDevicePickerFilter<D>::SupportsAudio(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingDevicePickerFilter)->put_SupportsAudio(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Casting_ICastingDevicePickerFilter<D>::SupportsVideo() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingDevicePickerFilter)->get_SupportsVideo(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Casting_ICastingDevicePickerFilter<D>::SupportsVideo(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingDevicePickerFilter)->put_SupportsVideo(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Casting_ICastingDevicePickerFilter<D>::SupportsPictures() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingDevicePickerFilter)->get_SupportsPictures(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Casting_ICastingDevicePickerFilter<D>::SupportsPictures(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingDevicePickerFilter)->put_SupportsPictures(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Media::Casting::CastingSource>) consume_Windows_Media_Casting_ICastingDevicePickerFilter<D>::SupportedCastingSources() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingDevicePickerFilter)->get_SupportedCastingSources(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Media::Casting::CastingSource>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Casting::CastingDevice) consume_Windows_Media_Casting_ICastingDeviceSelectedEventArgs<D>::SelectedCastingDevice() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingDeviceSelectedEventArgs)->get_SelectedCastingDevice(&value));
        return llm::OS::Media::Casting::CastingDevice{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Casting_ICastingDeviceStatics<D>::GetDeviceSelector(llm::OS::Media::Casting::CastingPlaybackTypes const& type) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingDeviceStatics)->GetDeviceSelector(static_cast<uint32_t>(type), &value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<hstring>) consume_Windows_Media_Casting_ICastingDeviceStatics<D>::GetDeviceSelectorFromCastingSourceAsync(llm::OS::Media::Casting::CastingSource const& castingSource) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingDeviceStatics)->GetDeviceSelectorFromCastingSourceAsync(*(void**)(&castingSource), &operation));
        return llm::OS::Foundation::IAsyncOperation<hstring>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Casting::CastingDevice>) consume_Windows_Media_Casting_ICastingDeviceStatics<D>::FromIdAsync(param::hstring const& value) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingDeviceStatics)->FromIdAsync(*(void**)(&value), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Casting::CastingDevice>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Media_Casting_ICastingDeviceStatics<D>::DeviceInfoSupportsCastingAsync(llm::OS::Devices::Enumeration::DeviceInformation const& device) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingDeviceStatics)->DeviceInfoSupportsCastingAsync(*(void**)(&device), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_Media_Casting_ICastingSource<D>::PreferredSourceUri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingSource)->get_PreferredSourceUri(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Casting_ICastingSource<D>::PreferredSourceUri(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Casting::ICastingSource)->put_PreferredSourceUri(*(void**)(&value)));
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Casting::ICastingConnection> : produce_base<D, llm::OS::Media::Casting::ICastingConnection>
    {
        int32_t __stdcall get_State(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Casting::CastingConnectionState>(this->shim().State());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Device(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Casting::CastingDevice>(this->shim().Device());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Source(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Casting::CastingSource>(this->shim().Source());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Source(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Source(*reinterpret_cast<llm::OS::Media::Casting::CastingSource const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_StateChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().StateChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Casting::CastingConnection, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_StateChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StateChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_ErrorOccurred(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ErrorOccurred(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Casting::CastingConnection, llm::OS::Media::Casting::CastingConnectionErrorOccurredEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ErrorOccurred(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ErrorOccurred(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall RequestStartCastingAsync(void* value, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Casting::CastingConnectionErrorStatus>>(this->shim().RequestStartCastingAsync(*reinterpret_cast<llm::OS::Media::Casting::CastingSource const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DisconnectAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Casting::CastingConnectionErrorStatus>>(this->shim().DisconnectAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Casting::ICastingConnectionErrorOccurredEventArgs> : produce_base<D, llm::OS::Media::Casting::ICastingConnectionErrorOccurredEventArgs>
    {
        int32_t __stdcall get_ErrorStatus(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Casting::CastingConnectionErrorStatus>(this->shim().ErrorStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Message(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Message());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Casting::ICastingDevice> : produce_base<D, llm::OS::Media::Casting::ICastingDevice>
    {
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FriendlyName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().FriendlyName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Icon(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IRandomAccessStreamWithContentType>(this->shim().Icon());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSupportedCastingPlaybackTypesAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Casting::CastingPlaybackTypes>>(this->shim().GetSupportedCastingPlaybackTypesAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateCastingConnection(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Casting::CastingConnection>(this->shim().CreateCastingConnection());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Casting::ICastingDevicePicker> : produce_base<D, llm::OS::Media::Casting::ICastingDevicePicker>
    {
        int32_t __stdcall get_Filter(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Casting::CastingDevicePickerFilter>(this->shim().Filter());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Appearance(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Enumeration::DevicePickerAppearance>(this->shim().Appearance());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_CastingDeviceSelected(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().CastingDeviceSelected(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Casting::CastingDevicePicker, llm::OS::Media::Casting::CastingDeviceSelectedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_CastingDeviceSelected(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CastingDeviceSelected(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_CastingDevicePickerDismissed(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().CastingDevicePickerDismissed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Casting::CastingDevicePicker, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_CastingDevicePickerDismissed(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CastingDevicePickerDismissed(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall Show(llm::OS::Foundation::Rect selection) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Show(*reinterpret_cast<llm::OS::Foundation::Rect const*>(&selection));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowWithPlacement(llm::OS::Foundation::Rect selection, int32_t preferredPlacement) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Show(*reinterpret_cast<llm::OS::Foundation::Rect const*>(&selection), *reinterpret_cast<llm::OS::UI::Popups::Placement const*>(&preferredPlacement));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Hide() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Hide();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Casting::ICastingDevicePickerFilter> : produce_base<D, llm::OS::Media::Casting::ICastingDevicePickerFilter>
    {
        int32_t __stdcall get_SupportsAudio(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().SupportsAudio());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SupportsAudio(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SupportsAudio(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportsVideo(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().SupportsVideo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SupportsVideo(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SupportsVideo(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportsPictures(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().SupportsPictures());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SupportsPictures(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SupportsPictures(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportedCastingSources(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Media::Casting::CastingSource>>(this->shim().SupportedCastingSources());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Casting::ICastingDeviceSelectedEventArgs> : produce_base<D, llm::OS::Media::Casting::ICastingDeviceSelectedEventArgs>
    {
        int32_t __stdcall get_SelectedCastingDevice(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Casting::CastingDevice>(this->shim().SelectedCastingDevice());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Casting::ICastingDeviceStatics> : produce_base<D, llm::OS::Media::Casting::ICastingDeviceStatics>
    {
        int32_t __stdcall GetDeviceSelector(uint32_t type, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().GetDeviceSelector(*reinterpret_cast<llm::OS::Media::Casting::CastingPlaybackTypes const*>(&type)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeviceSelectorFromCastingSourceAsync(void* castingSource, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<hstring>>(this->shim().GetDeviceSelectorFromCastingSourceAsync(*reinterpret_cast<llm::OS::Media::Casting::CastingSource const*>(&castingSource)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FromIdAsync(void* value, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Casting::CastingDevice>>(this->shim().FromIdAsync(*reinterpret_cast<hstring const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DeviceInfoSupportsCastingAsync(void* device, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().DeviceInfoSupportsCastingAsync(*reinterpret_cast<llm::OS::Devices::Enumeration::DeviceInformation const*>(&device)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Casting::ICastingSource> : produce_base<D, llm::OS::Media::Casting::ICastingSource>
    {
        int32_t __stdcall get_PreferredSourceUri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().PreferredSourceUri());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PreferredSourceUri(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PreferredSourceUri(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Media::Casting
{
    constexpr auto operator|(CastingPlaybackTypes const left, CastingPlaybackTypes const right) noexcept
    {
        return static_cast<CastingPlaybackTypes>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(CastingPlaybackTypes& left, CastingPlaybackTypes const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(CastingPlaybackTypes const left, CastingPlaybackTypes const right) noexcept
    {
        return static_cast<CastingPlaybackTypes>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(CastingPlaybackTypes& left, CastingPlaybackTypes const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(CastingPlaybackTypes const value) noexcept
    {
        return static_cast<CastingPlaybackTypes>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(CastingPlaybackTypes const left, CastingPlaybackTypes const right) noexcept
    {
        return static_cast<CastingPlaybackTypes>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(CastingPlaybackTypes& left, CastingPlaybackTypes const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    inline auto CastingDevice::GetDeviceSelector(llm::OS::Media::Casting::CastingPlaybackTypes const& type)
    {
        return impl::call_factory<CastingDevice, ICastingDeviceStatics>([&](ICastingDeviceStatics const& f) { return f.GetDeviceSelector(type); });
    }
    inline auto CastingDevice::GetDeviceSelectorFromCastingSourceAsync(llm::OS::Media::Casting::CastingSource const& castingSource)
    {
        return impl::call_factory<CastingDevice, ICastingDeviceStatics>([&](ICastingDeviceStatics const& f) { return f.GetDeviceSelectorFromCastingSourceAsync(castingSource); });
    }
    inline auto CastingDevice::FromIdAsync(param::hstring const& value)
    {
        return impl::call_factory<CastingDevice, ICastingDeviceStatics>([&](ICastingDeviceStatics const& f) { return f.FromIdAsync(value); });
    }
    inline auto CastingDevice::DeviceInfoSupportsCastingAsync(llm::OS::Devices::Enumeration::DeviceInformation const& device)
    {
        return impl::call_factory<CastingDevice, ICastingDeviceStatics>([&](ICastingDeviceStatics const& f) { return f.DeviceInfoSupportsCastingAsync(device); });
    }
    inline CastingDevicePicker::CastingDevicePicker() :
        CastingDevicePicker(impl::call_factory_cast<CastingDevicePicker(*)(llm::OS::Foundation::IActivationFactory const&), CastingDevicePicker>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<CastingDevicePicker>(); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Media::Casting::ICastingConnection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Casting::ICastingConnectionErrorOccurredEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Casting::ICastingDevice> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Casting::ICastingDevicePicker> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Casting::ICastingDevicePickerFilter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Casting::ICastingDeviceSelectedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Casting::ICastingDeviceStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Casting::ICastingSource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Casting::CastingConnection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Casting::CastingConnectionErrorOccurredEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Casting::CastingDevice> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Casting::CastingDevicePicker> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Casting::CastingDevicePickerFilter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Casting::CastingDeviceSelectedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Casting::CastingSource> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
