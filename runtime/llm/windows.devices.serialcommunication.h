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
#ifndef LLM_OS_Devices_SerialCommunication_H
#define LLM_OS_Devices_SerialCommunication_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Devices.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.Devices.SerialCommunication.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::SerialCommunication::SerialError) consume_Windows_Devices_SerialCommunication_IErrorReceivedEventArgs<D>::Error() const
    {
        llm::OS::Devices::SerialCommunication::SerialError value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::IErrorReceivedEventArgs)->get_Error(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::SerialCommunication::SerialPinChange) consume_Windows_Devices_SerialCommunication_IPinChangedEventArgs<D>::PinChange() const
    {
        llm::OS::Devices::SerialCommunication::SerialPinChange value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::IPinChangedEventArgs)->get_PinChange(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::BaudRate() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->get_BaudRate(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::BaudRate(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->put_BaudRate(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::BreakSignalState() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->get_BreakSignalState(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::BreakSignalState(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->put_BreakSignalState(value));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::BytesReceived() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->get_BytesReceived(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::CarrierDetectState() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->get_CarrierDetectState(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::ClearToSendState() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->get_ClearToSendState(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint16_t) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::DataBits() const
    {
        uint16_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->get_DataBits(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::DataBits(uint16_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->put_DataBits(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::DataSetReadyState() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->get_DataSetReadyState(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::SerialCommunication::SerialHandshake) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::Handshake() const
    {
        llm::OS::Devices::SerialCommunication::SerialHandshake value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->get_Handshake(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::Handshake(llm::OS::Devices::SerialCommunication::SerialHandshake const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->put_Handshake(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::IsDataTerminalReadyEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->get_IsDataTerminalReadyEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::IsDataTerminalReadyEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->put_IsDataTerminalReadyEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::IsRequestToSendEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->get_IsRequestToSendEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::IsRequestToSendEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->put_IsRequestToSendEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::SerialCommunication::SerialParity) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::Parity() const
    {
        llm::OS::Devices::SerialCommunication::SerialParity value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->get_Parity(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::Parity(llm::OS::Devices::SerialCommunication::SerialParity const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->put_Parity(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::PortName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->get_PortName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::ReadTimeout() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->get_ReadTimeout(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::ReadTimeout(llm::OS::Foundation::TimeSpan const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->put_ReadTimeout(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::SerialCommunication::SerialStopBitCount) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::StopBits() const
    {
        llm::OS::Devices::SerialCommunication::SerialStopBitCount value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->get_StopBits(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::StopBits(llm::OS::Devices::SerialCommunication::SerialStopBitCount const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->put_StopBits(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(uint16_t) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::UsbVendorId() const
    {
        uint16_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->get_UsbVendorId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint16_t) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::UsbProductId() const
    {
        uint16_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->get_UsbProductId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::WriteTimeout() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->get_WriteTimeout(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::WriteTimeout(llm::OS::Foundation::TimeSpan const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->put_WriteTimeout(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IInputStream) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::InputStream() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->get_InputStream(&value));
        return llm::OS::Storage::Streams::IInputStream{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IOutputStream) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::OutputStream() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->get_OutputStream(&value));
        return llm::OS::Storage::Streams::IOutputStream{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::ErrorReceived(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::SerialCommunication::SerialDevice, llm::OS::Devices::SerialCommunication::ErrorReceivedEventArgs> const& reportHandler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->add_ErrorReceived(*(void**)(&reportHandler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::ErrorReceived_revoker consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::ErrorReceived(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::SerialCommunication::SerialDevice, llm::OS::Devices::SerialCommunication::ErrorReceivedEventArgs> const& reportHandler) const
    {
        return impl::make_event_revoker<D, ErrorReceived_revoker>(this, ErrorReceived(reportHandler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::ErrorReceived(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->remove_ErrorReceived(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::PinChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::SerialCommunication::SerialDevice, llm::OS::Devices::SerialCommunication::PinChangedEventArgs> const& reportHandler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->add_PinChanged(*(void**)(&reportHandler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::PinChanged_revoker consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::PinChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::SerialCommunication::SerialDevice, llm::OS::Devices::SerialCommunication::PinChangedEventArgs> const& reportHandler) const
    {
        return impl::make_event_revoker<D, PinChanged_revoker>(this, PinChanged(reportHandler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_SerialCommunication_ISerialDevice<D>::PinChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDevice)->remove_PinChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_SerialCommunication_ISerialDeviceStatics<D>::GetDeviceSelector() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDeviceStatics)->GetDeviceSelector(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_SerialCommunication_ISerialDeviceStatics<D>::GetDeviceSelector(param::hstring const& portName) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDeviceStatics)->GetDeviceSelectorFromPortName(*(void**)(&portName), &result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_SerialCommunication_ISerialDeviceStatics<D>::GetDeviceSelectorFromUsbVidPid(uint16_t vendorId, uint16_t productId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDeviceStatics)->GetDeviceSelectorFromUsbVidPid(vendorId, productId, &result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::SerialCommunication::SerialDevice>) consume_Windows_Devices_SerialCommunication_ISerialDeviceStatics<D>::FromIdAsync(param::hstring const& deviceId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::SerialCommunication::ISerialDeviceStatics)->FromIdAsync(*(void**)(&deviceId), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::SerialCommunication::SerialDevice>{ result, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::SerialCommunication::IErrorReceivedEventArgs> : produce_base<D, llm::OS::Devices::SerialCommunication::IErrorReceivedEventArgs>
    {
        int32_t __stdcall get_Error(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::SerialCommunication::SerialError>(this->shim().Error());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::SerialCommunication::IPinChangedEventArgs> : produce_base<D, llm::OS::Devices::SerialCommunication::IPinChangedEventArgs>
    {
        int32_t __stdcall get_PinChange(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::SerialCommunication::SerialPinChange>(this->shim().PinChange());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::SerialCommunication::ISerialDevice> : produce_base<D, llm::OS::Devices::SerialCommunication::ISerialDevice>
    {
        int32_t __stdcall get_BaudRate(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().BaudRate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BaudRate(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BaudRate(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BreakSignalState(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().BreakSignalState());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BreakSignalState(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BreakSignalState(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BytesReceived(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().BytesReceived());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CarrierDetectState(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CarrierDetectState());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ClearToSendState(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().ClearToSendState());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DataBits(uint16_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint16_t>(this->shim().DataBits());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DataBits(uint16_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DataBits(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DataSetReadyState(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().DataSetReadyState());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Handshake(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::SerialCommunication::SerialHandshake>(this->shim().Handshake());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Handshake(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handshake(*reinterpret_cast<llm::OS::Devices::SerialCommunication::SerialHandshake const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsDataTerminalReadyEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsDataTerminalReadyEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsDataTerminalReadyEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsDataTerminalReadyEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsRequestToSendEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsRequestToSendEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsRequestToSendEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsRequestToSendEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Parity(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::SerialCommunication::SerialParity>(this->shim().Parity());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Parity(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Parity(*reinterpret_cast<llm::OS::Devices::SerialCommunication::SerialParity const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PortName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().PortName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ReadTimeout(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().ReadTimeout());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ReadTimeout(int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReadTimeout(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StopBits(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::SerialCommunication::SerialStopBitCount>(this->shim().StopBits());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_StopBits(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StopBits(*reinterpret_cast<llm::OS::Devices::SerialCommunication::SerialStopBitCount const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UsbVendorId(uint16_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint16_t>(this->shim().UsbVendorId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UsbProductId(uint16_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint16_t>(this->shim().UsbProductId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WriteTimeout(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().WriteTimeout());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_WriteTimeout(int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WriteTimeout(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InputStream(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IInputStream>(this->shim().InputStream());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OutputStream(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IOutputStream>(this->shim().OutputStream());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_ErrorReceived(void* reportHandler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ErrorReceived(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::SerialCommunication::SerialDevice, llm::OS::Devices::SerialCommunication::ErrorReceivedEventArgs> const*>(&reportHandler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ErrorReceived(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ErrorReceived(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_PinChanged(void* reportHandler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PinChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::SerialCommunication::SerialDevice, llm::OS::Devices::SerialCommunication::PinChangedEventArgs> const*>(&reportHandler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PinChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PinChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::SerialCommunication::ISerialDeviceStatics> : produce_base<D, llm::OS::Devices::SerialCommunication::ISerialDeviceStatics>
    {
        int32_t __stdcall GetDeviceSelector(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().GetDeviceSelector());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeviceSelectorFromPortName(void* portName, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetDeviceSelector(*reinterpret_cast<hstring const*>(&portName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeviceSelectorFromUsbVidPid(uint16_t vendorId, uint16_t productId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetDeviceSelectorFromUsbVidPid(vendorId, productId));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FromIdAsync(void* deviceId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::SerialCommunication::SerialDevice>>(this->shim().FromIdAsync(*reinterpret_cast<hstring const*>(&deviceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Devices::SerialCommunication
{
    inline auto SerialDevice::GetDeviceSelector()
    {
        return impl::call_factory_cast<hstring(*)(ISerialDeviceStatics const&), SerialDevice, ISerialDeviceStatics>([](ISerialDeviceStatics const& f) { return f.GetDeviceSelector(); });
    }
    inline auto SerialDevice::GetDeviceSelector(param::hstring const& portName)
    {
        return impl::call_factory<SerialDevice, ISerialDeviceStatics>([&](ISerialDeviceStatics const& f) { return f.GetDeviceSelector(portName); });
    }
    inline auto SerialDevice::GetDeviceSelectorFromUsbVidPid(uint16_t vendorId, uint16_t productId)
    {
        return impl::call_factory<SerialDevice, ISerialDeviceStatics>([&](ISerialDeviceStatics const& f) { return f.GetDeviceSelectorFromUsbVidPid(vendorId, productId); });
    }
    inline auto SerialDevice::FromIdAsync(param::hstring const& deviceId)
    {
        return impl::call_factory<SerialDevice, ISerialDeviceStatics>([&](ISerialDeviceStatics const& f) { return f.FromIdAsync(deviceId); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Devices::SerialCommunication::IErrorReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::SerialCommunication::IPinChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::SerialCommunication::ISerialDevice> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::SerialCommunication::ISerialDeviceStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::SerialCommunication::ErrorReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::SerialCommunication::PinChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::SerialCommunication::SerialDevice> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
