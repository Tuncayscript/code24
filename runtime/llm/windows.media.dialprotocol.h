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
#ifndef LLM_OS_Media_DialProtocol_H
#define LLM_OS_Media_DialProtocol_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Media.h"
#include "llm/impl/Windows.Devices.Enumeration.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.UI.Popups.2.h"
#include "llm/impl/Windows.Media.DialProtocol.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_DialProtocol_IDialApp<D>::AppName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialApp)->get_AppName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::DialProtocol::DialAppLaunchResult>) consume_Windows_Media_DialProtocol_IDialApp<D>::RequestLaunchAsync(param::hstring const& appArgument) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialApp)->RequestLaunchAsync(*(void**)(&appArgument), &value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::DialProtocol::DialAppLaunchResult>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::DialProtocol::DialAppStopResult>) consume_Windows_Media_DialProtocol_IDialApp<D>::StopAsync() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialApp)->StopAsync(&value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::DialProtocol::DialAppStopResult>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::DialProtocol::DialAppStateDetails>) consume_Windows_Media_DialProtocol_IDialApp<D>::GetAppStateAsync() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialApp)->GetAppStateAsync(&value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::DialProtocol::DialAppStateDetails>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::DialProtocol::DialAppState) consume_Windows_Media_DialProtocol_IDialAppStateDetails<D>::State() const
    {
        llm::OS::Media::DialProtocol::DialAppState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialAppStateDetails)->get_State(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_DialProtocol_IDialAppStateDetails<D>::FullXml() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialAppStateDetails)->get_FullXml(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_DialProtocol_IDialDevice<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialDevice)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::DialProtocol::DialApp) consume_Windows_Media_DialProtocol_IDialDevice<D>::GetDialApp(param::hstring const& appName) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialDevice)->GetDialApp(*(void**)(&appName), &value));
        return llm::OS::Media::DialProtocol::DialApp{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_DialProtocol_IDialDevice2<D>::FriendlyName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialDevice2)->get_FriendlyName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStreamReference) consume_Windows_Media_DialProtocol_IDialDevice2<D>::Thumbnail() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialDevice2)->get_Thumbnail(&value));
        return llm::OS::Storage::Streams::IRandomAccessStreamReference{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::DialProtocol::DialDevicePickerFilter) consume_Windows_Media_DialProtocol_IDialDevicePicker<D>::Filter() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialDevicePicker)->get_Filter(&value));
        return llm::OS::Media::DialProtocol::DialDevicePickerFilter{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DevicePickerAppearance) consume_Windows_Media_DialProtocol_IDialDevicePicker<D>::Appearance() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialDevicePicker)->get_Appearance(&value));
        return llm::OS::Devices::Enumeration::DevicePickerAppearance{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_DialProtocol_IDialDevicePicker<D>::DialDeviceSelected(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::DialProtocol::DialDevicePicker, llm::OS::Media::DialProtocol::DialDeviceSelectedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialDevicePicker)->add_DialDeviceSelected(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_DialProtocol_IDialDevicePicker<D>::DialDeviceSelected_revoker consume_Windows_Media_DialProtocol_IDialDevicePicker<D>::DialDeviceSelected(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::DialProtocol::DialDevicePicker, llm::OS::Media::DialProtocol::DialDeviceSelectedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, DialDeviceSelected_revoker>(this, DialDeviceSelected(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_DialProtocol_IDialDevicePicker<D>::DialDeviceSelected(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialDevicePicker)->remove_DialDeviceSelected(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_DialProtocol_IDialDevicePicker<D>::DisconnectButtonClicked(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::DialProtocol::DialDevicePicker, llm::OS::Media::DialProtocol::DialDisconnectButtonClickedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialDevicePicker)->add_DisconnectButtonClicked(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_DialProtocol_IDialDevicePicker<D>::DisconnectButtonClicked_revoker consume_Windows_Media_DialProtocol_IDialDevicePicker<D>::DisconnectButtonClicked(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::DialProtocol::DialDevicePicker, llm::OS::Media::DialProtocol::DialDisconnectButtonClickedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, DisconnectButtonClicked_revoker>(this, DisconnectButtonClicked(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_DialProtocol_IDialDevicePicker<D>::DisconnectButtonClicked(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialDevicePicker)->remove_DisconnectButtonClicked(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_DialProtocol_IDialDevicePicker<D>::DialDevicePickerDismissed(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::DialProtocol::DialDevicePicker, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialDevicePicker)->add_DialDevicePickerDismissed(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_DialProtocol_IDialDevicePicker<D>::DialDevicePickerDismissed_revoker consume_Windows_Media_DialProtocol_IDialDevicePicker<D>::DialDevicePickerDismissed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::DialProtocol::DialDevicePicker, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, DialDevicePickerDismissed_revoker>(this, DialDevicePickerDismissed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_DialProtocol_IDialDevicePicker<D>::DialDevicePickerDismissed(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialDevicePicker)->remove_DialDevicePickerDismissed(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_DialProtocol_IDialDevicePicker<D>::Show(llm::OS::Foundation::Rect const& selection) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialDevicePicker)->Show(impl::bind_in(selection)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_DialProtocol_IDialDevicePicker<D>::Show(llm::OS::Foundation::Rect const& selection, llm::OS::UI::Popups::Placement const& preferredPlacement) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialDevicePicker)->ShowWithPlacement(impl::bind_in(selection), static_cast<int32_t>(preferredPlacement)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::DialProtocol::DialDevice>) consume_Windows_Media_DialProtocol_IDialDevicePicker<D>::PickSingleDialDeviceAsync(llm::OS::Foundation::Rect const& selection) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialDevicePicker)->PickSingleDialDeviceAsync(impl::bind_in(selection), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::DialProtocol::DialDevice>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::DialProtocol::DialDevice>) consume_Windows_Media_DialProtocol_IDialDevicePicker<D>::PickSingleDialDeviceAsync(llm::OS::Foundation::Rect const& selection, llm::OS::UI::Popups::Placement const& preferredPlacement) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialDevicePicker)->PickSingleDialDeviceAsyncWithPlacement(impl::bind_in(selection), static_cast<int32_t>(preferredPlacement), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::DialProtocol::DialDevice>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_DialProtocol_IDialDevicePicker<D>::Hide() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialDevicePicker)->Hide());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_DialProtocol_IDialDevicePicker<D>::SetDisplayStatus(llm::OS::Media::DialProtocol::DialDevice const& device, llm::OS::Media::DialProtocol::DialDeviceDisplayStatus const& status) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialDevicePicker)->SetDisplayStatus(*(void**)(&device), static_cast<int32_t>(status)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Media_DialProtocol_IDialDevicePickerFilter<D>::SupportedAppNames() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialDevicePickerFilter)->get_SupportedAppNames(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::DialProtocol::DialDevice) consume_Windows_Media_DialProtocol_IDialDeviceSelectedEventArgs<D>::SelectedDialDevice() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialDeviceSelectedEventArgs)->get_SelectedDialDevice(&value));
        return llm::OS::Media::DialProtocol::DialDevice{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_DialProtocol_IDialDeviceStatics<D>::GetDeviceSelector(param::hstring const& appName) const
    {
        void* selector{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialDeviceStatics)->GetDeviceSelector(*(void**)(&appName), &selector));
        return hstring{ selector, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::DialProtocol::DialDevice>) consume_Windows_Media_DialProtocol_IDialDeviceStatics<D>::FromIdAsync(param::hstring const& value) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialDeviceStatics)->FromIdAsync(*(void**)(&value), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::DialProtocol::DialDevice>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Media_DialProtocol_IDialDeviceStatics<D>::DeviceInfoSupportsDialAsync(llm::OS::Devices::Enumeration::DeviceInformation const& device) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialDeviceStatics)->DeviceInfoSupportsDialAsync(*(void**)(&device), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::DialProtocol::DialDevice) consume_Windows_Media_DialProtocol_IDialDisconnectButtonClickedEventArgs<D>::Device() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialDisconnectButtonClickedEventArgs)->get_Device(&value));
        return llm::OS::Media::DialProtocol::DialDevice{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IMap<hstring, hstring>>) consume_Windows_Media_DialProtocol_IDialReceiverApp<D>::GetAdditionalDataAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialReceiverApp)->GetAdditionalDataAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IMap<hstring, hstring>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Media_DialProtocol_IDialReceiverApp<D>::SetAdditionalDataAsync(param::async_iterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, hstring>> const& additionalData) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialReceiverApp)->SetAdditionalDataAsync(*(void**)(&additionalData), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<hstring>) consume_Windows_Media_DialProtocol_IDialReceiverApp2<D>::GetUniqueDeviceNameAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialReceiverApp2)->GetUniqueDeviceNameAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<hstring>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::DialProtocol::DialReceiverApp) consume_Windows_Media_DialProtocol_IDialReceiverAppStatics<D>::Current() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::DialProtocol::IDialReceiverAppStatics)->get_Current(&value));
        return llm::OS::Media::DialProtocol::DialReceiverApp{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::DialProtocol::IDialApp> : produce_base<D, llm::OS::Media::DialProtocol::IDialApp>
    {
        int32_t __stdcall get_AppName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AppName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestLaunchAsync(void* appArgument, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::DialProtocol::DialAppLaunchResult>>(this->shim().RequestLaunchAsync(*reinterpret_cast<hstring const*>(&appArgument)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StopAsync(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::DialProtocol::DialAppStopResult>>(this->shim().StopAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAppStateAsync(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::DialProtocol::DialAppStateDetails>>(this->shim().GetAppStateAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::DialProtocol::IDialAppStateDetails> : produce_base<D, llm::OS::Media::DialProtocol::IDialAppStateDetails>
    {
        int32_t __stdcall get_State(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::DialProtocol::DialAppState>(this->shim().State());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FullXml(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().FullXml());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::DialProtocol::IDialDevice> : produce_base<D, llm::OS::Media::DialProtocol::IDialDevice>
    {
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDialApp(void* appName, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::DialProtocol::DialApp>(this->shim().GetDialApp(*reinterpret_cast<hstring const*>(&appName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::DialProtocol::IDialDevice2> : produce_base<D, llm::OS::Media::DialProtocol::IDialDevice2>
    {
        int32_t __stdcall get_FriendlyName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().FriendlyName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Thumbnail(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IRandomAccessStreamReference>(this->shim().Thumbnail());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::DialProtocol::IDialDevicePicker> : produce_base<D, llm::OS::Media::DialProtocol::IDialDevicePicker>
    {
        int32_t __stdcall get_Filter(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::DialProtocol::DialDevicePickerFilter>(this->shim().Filter());
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
        int32_t __stdcall add_DialDeviceSelected(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().DialDeviceSelected(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::DialProtocol::DialDevicePicker, llm::OS::Media::DialProtocol::DialDeviceSelectedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_DialDeviceSelected(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DialDeviceSelected(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_DisconnectButtonClicked(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().DisconnectButtonClicked(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::DialProtocol::DialDevicePicker, llm::OS::Media::DialProtocol::DialDisconnectButtonClickedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_DisconnectButtonClicked(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisconnectButtonClicked(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_DialDevicePickerDismissed(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().DialDevicePickerDismissed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::DialProtocol::DialDevicePicker, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_DialDevicePickerDismissed(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DialDevicePickerDismissed(*reinterpret_cast<llm::event_token const*>(&token));
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
        int32_t __stdcall PickSingleDialDeviceAsync(llm::OS::Foundation::Rect selection, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::DialProtocol::DialDevice>>(this->shim().PickSingleDialDeviceAsync(*reinterpret_cast<llm::OS::Foundation::Rect const*>(&selection)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall PickSingleDialDeviceAsyncWithPlacement(llm::OS::Foundation::Rect selection, int32_t preferredPlacement, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::DialProtocol::DialDevice>>(this->shim().PickSingleDialDeviceAsync(*reinterpret_cast<llm::OS::Foundation::Rect const*>(&selection), *reinterpret_cast<llm::OS::UI::Popups::Placement const*>(&preferredPlacement)));
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
        int32_t __stdcall SetDisplayStatus(void* device, int32_t status) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetDisplayStatus(*reinterpret_cast<llm::OS::Media::DialProtocol::DialDevice const*>(&device), *reinterpret_cast<llm::OS::Media::DialProtocol::DialDeviceDisplayStatus const*>(&status));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::DialProtocol::IDialDevicePickerFilter> : produce_base<D, llm::OS::Media::DialProtocol::IDialDevicePickerFilter>
    {
        int32_t __stdcall get_SupportedAppNames(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().SupportedAppNames());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::DialProtocol::IDialDeviceSelectedEventArgs> : produce_base<D, llm::OS::Media::DialProtocol::IDialDeviceSelectedEventArgs>
    {
        int32_t __stdcall get_SelectedDialDevice(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::DialProtocol::DialDevice>(this->shim().SelectedDialDevice());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::DialProtocol::IDialDeviceStatics> : produce_base<D, llm::OS::Media::DialProtocol::IDialDeviceStatics>
    {
        int32_t __stdcall GetDeviceSelector(void* appName, void** selector) noexcept final try
        {
            clear_abi(selector);
            typename D::abi_guard guard(this->shim());
            *selector = detach_from<hstring>(this->shim().GetDeviceSelector(*reinterpret_cast<hstring const*>(&appName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FromIdAsync(void* value, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::DialProtocol::DialDevice>>(this->shim().FromIdAsync(*reinterpret_cast<hstring const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DeviceInfoSupportsDialAsync(void* device, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().DeviceInfoSupportsDialAsync(*reinterpret_cast<llm::OS::Devices::Enumeration::DeviceInformation const*>(&device)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::DialProtocol::IDialDisconnectButtonClickedEventArgs> : produce_base<D, llm::OS::Media::DialProtocol::IDialDisconnectButtonClickedEventArgs>
    {
        int32_t __stdcall get_Device(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::DialProtocol::DialDevice>(this->shim().Device());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::DialProtocol::IDialReceiverApp> : produce_base<D, llm::OS::Media::DialProtocol::IDialReceiverApp>
    {
        int32_t __stdcall GetAdditionalDataAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IMap<hstring, hstring>>>(this->shim().GetAdditionalDataAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetAdditionalDataAsync(void* additionalData, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SetAdditionalDataAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, hstring>> const*>(&additionalData)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::DialProtocol::IDialReceiverApp2> : produce_base<D, llm::OS::Media::DialProtocol::IDialReceiverApp2>
    {
        int32_t __stdcall GetUniqueDeviceNameAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<hstring>>(this->shim().GetUniqueDeviceNameAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::DialProtocol::IDialReceiverAppStatics> : produce_base<D, llm::OS::Media::DialProtocol::IDialReceiverAppStatics>
    {
        int32_t __stdcall get_Current(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::DialProtocol::DialReceiverApp>(this->shim().Current());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Media::DialProtocol
{
    inline auto DialDevice::GetDeviceSelector(param::hstring const& appName)
    {
        return impl::call_factory<DialDevice, IDialDeviceStatics>([&](IDialDeviceStatics const& f) { return f.GetDeviceSelector(appName); });
    }
    inline auto DialDevice::FromIdAsync(param::hstring const& value)
    {
        return impl::call_factory<DialDevice, IDialDeviceStatics>([&](IDialDeviceStatics const& f) { return f.FromIdAsync(value); });
    }
    inline auto DialDevice::DeviceInfoSupportsDialAsync(llm::OS::Devices::Enumeration::DeviceInformation const& device)
    {
        return impl::call_factory<DialDevice, IDialDeviceStatics>([&](IDialDeviceStatics const& f) { return f.DeviceInfoSupportsDialAsync(device); });
    }
    inline DialDevicePicker::DialDevicePicker() :
        DialDevicePicker(impl::call_factory_cast<DialDevicePicker(*)(llm::OS::Foundation::IActivationFactory const&), DialDevicePicker>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<DialDevicePicker>(); }))
    {
    }
    inline auto DialReceiverApp::Current()
    {
        return impl::call_factory_cast<llm::OS::Media::DialProtocol::DialReceiverApp(*)(IDialReceiverAppStatics const&), DialReceiverApp, IDialReceiverAppStatics>([](IDialReceiverAppStatics const& f) { return f.Current(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Media::DialProtocol::IDialApp> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::DialProtocol::IDialAppStateDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::DialProtocol::IDialDevice> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::DialProtocol::IDialDevice2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::DialProtocol::IDialDevicePicker> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::DialProtocol::IDialDevicePickerFilter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::DialProtocol::IDialDeviceSelectedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::DialProtocol::IDialDeviceStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::DialProtocol::IDialDisconnectButtonClickedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::DialProtocol::IDialReceiverApp> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::DialProtocol::IDialReceiverApp2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::DialProtocol::IDialReceiverAppStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::DialProtocol::DialApp> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::DialProtocol::DialAppStateDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::DialProtocol::DialDevice> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::DialProtocol::DialDevicePicker> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::DialProtocol::DialDevicePickerFilter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::DialProtocol::DialDeviceSelectedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::DialProtocol::DialDisconnectButtonClickedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::DialProtocol::DialReceiverApp> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
