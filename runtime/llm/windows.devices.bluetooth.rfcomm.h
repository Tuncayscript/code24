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
#ifndef LLM_OS_Devices_Bluetooth_Rfcomm_H
#define LLM_OS_Devices_Bluetooth_Rfcomm_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Devices.Bluetooth.h"
#include "llm/impl/Windows.Devices.Bluetooth.2.h"
#include "llm/impl/Windows.Devices.Enumeration.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Networking.2.h"
#include "llm/impl/Windows.Networking.Sockets.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.Devices.Bluetooth.Rfcomm.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::HostName) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommDeviceService<D>::ConnectionHostName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceService)->get_ConnectionHostName(&value));
        return llm::OS::Networking::HostName{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommDeviceService<D>::ConnectionServiceName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceService)->get_ConnectionServiceName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommDeviceService<D>::ServiceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceService)->get_ServiceId(&value));
        return llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Sockets::SocketProtectionLevel) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommDeviceService<D>::ProtectionLevel() const
    {
        llm::OS::Networking::Sockets::SocketProtectionLevel value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceService)->get_ProtectionLevel(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Sockets::SocketProtectionLevel) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommDeviceService<D>::MaxProtectionLevel() const
    {
        llm::OS::Networking::Sockets::SocketProtectionLevel value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceService)->get_MaxProtectionLevel(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IMapView<uint32_t, llm::OS::Storage::Streams::IBuffer>>) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommDeviceService<D>::GetSdpRawAttributesAsync() const
    {
        void* asyncOp{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceService)->GetSdpRawAttributesAsync(&asyncOp));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IMapView<uint32_t, llm::OS::Storage::Streams::IBuffer>>{ asyncOp, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IMapView<uint32_t, llm::OS::Storage::Streams::IBuffer>>) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommDeviceService<D>::GetSdpRawAttributesAsync(llm::OS::Devices::Bluetooth::BluetoothCacheMode const& cacheMode) const
    {
        void* asyncOp{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceService)->GetSdpRawAttributesWithCacheModeAsync(static_cast<int32_t>(cacheMode), &asyncOp));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IMapView<uint32_t, llm::OS::Storage::Streams::IBuffer>>{ asyncOp, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::BluetoothDevice) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommDeviceService2<D>::Device() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceService2)->get_Device(&value));
        return llm::OS::Devices::Bluetooth::BluetoothDevice{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DeviceAccessInformation) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommDeviceService3<D>::DeviceAccessInformation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceService3)->get_DeviceAccessInformation(&value));
        return llm::OS::Devices::Enumeration::DeviceAccessInformation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceAccessStatus>) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommDeviceService3<D>::RequestAccessAsync() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceService3)->RequestAccessAsync(&value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceAccessStatus>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Bluetooth::Rfcomm::RfcommDeviceService>) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommDeviceServiceStatics<D>::FromIdAsync(param::hstring const& deviceId) const
    {
        void* asyncOp{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceServiceStatics)->FromIdAsync(*(void**)(&deviceId), &asyncOp));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Bluetooth::Rfcomm::RfcommDeviceService>{ asyncOp, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommDeviceServiceStatics<D>::GetDeviceSelector(llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId const& serviceId) const
    {
        void* selector{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceServiceStatics)->GetDeviceSelector(*(void**)(&serviceId), &selector));
        return hstring{ selector, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommDeviceServiceStatics2<D>::GetDeviceSelectorForBluetoothDevice(llm::OS::Devices::Bluetooth::BluetoothDevice const& bluetoothDevice) const
    {
        void* selector{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceServiceStatics2)->GetDeviceSelectorForBluetoothDevice(*(void**)(&bluetoothDevice), &selector));
        return hstring{ selector, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommDeviceServiceStatics2<D>::GetDeviceSelectorForBluetoothDevice(llm::OS::Devices::Bluetooth::BluetoothDevice const& bluetoothDevice, llm::OS::Devices::Bluetooth::BluetoothCacheMode const& cacheMode) const
    {
        void* selector{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceServiceStatics2)->GetDeviceSelectorForBluetoothDeviceWithCacheMode(*(void**)(&bluetoothDevice), static_cast<int32_t>(cacheMode), &selector));
        return hstring{ selector, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommDeviceServiceStatics2<D>::GetDeviceSelectorForBluetoothDeviceAndServiceId(llm::OS::Devices::Bluetooth::BluetoothDevice const& bluetoothDevice, llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId const& serviceId) const
    {
        void* selector{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceServiceStatics2)->GetDeviceSelectorForBluetoothDeviceAndServiceId(*(void**)(&bluetoothDevice), *(void**)(&serviceId), &selector));
        return hstring{ selector, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommDeviceServiceStatics2<D>::GetDeviceSelectorForBluetoothDeviceAndServiceId(llm::OS::Devices::Bluetooth::BluetoothDevice const& bluetoothDevice, llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId const& serviceId, llm::OS::Devices::Bluetooth::BluetoothCacheMode const& cacheMode) const
    {
        void* selector{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceServiceStatics2)->GetDeviceSelectorForBluetoothDeviceAndServiceIdWithCacheMode(*(void**)(&bluetoothDevice), *(void**)(&serviceId), static_cast<int32_t>(cacheMode), &selector));
        return hstring{ selector, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::BluetoothError) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommDeviceServicesResult<D>::Error() const
    {
        llm::OS::Devices::Bluetooth::BluetoothError value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceServicesResult)->get_Error(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Bluetooth::Rfcomm::RfcommDeviceService>) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommDeviceServicesResult<D>::Services() const
    {
        void* services{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceServicesResult)->get_Services(&services));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Bluetooth::Rfcomm::RfcommDeviceService>{ services, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommServiceId<D>::Uuid() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceId)->get_Uuid(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommServiceId<D>::AsShortId() const
    {
        uint32_t shortId{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceId)->AsShortId(&shortId));
        return shortId;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommServiceId<D>::AsString() const
    {
        void* id{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceId)->AsString(&id));
        return hstring{ id, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommServiceIdStatics<D>::FromUuid(llm::guid const& uuid) const
    {
        void* serviceId{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceIdStatics)->FromUuid(impl::bind_in(uuid), &serviceId));
        return llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId{ serviceId, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommServiceIdStatics<D>::FromShortId(uint32_t shortId) const
    {
        void* serviceId{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceIdStatics)->FromShortId(shortId, &serviceId));
        return llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId{ serviceId, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommServiceIdStatics<D>::SerialPort() const
    {
        void* serviceId{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceIdStatics)->get_SerialPort(&serviceId));
        return llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId{ serviceId, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommServiceIdStatics<D>::ObexObjectPush() const
    {
        void* serviceId{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceIdStatics)->get_ObexObjectPush(&serviceId));
        return llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId{ serviceId, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommServiceIdStatics<D>::ObexFileTransfer() const
    {
        void* serviceId{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceIdStatics)->get_ObexFileTransfer(&serviceId));
        return llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId{ serviceId, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommServiceIdStatics<D>::PhoneBookAccessPce() const
    {
        void* serviceId{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceIdStatics)->get_PhoneBookAccessPce(&serviceId));
        return llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId{ serviceId, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommServiceIdStatics<D>::PhoneBookAccessPse() const
    {
        void* serviceId{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceIdStatics)->get_PhoneBookAccessPse(&serviceId));
        return llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId{ serviceId, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommServiceIdStatics<D>::GenericFileTransfer() const
    {
        void* serviceId{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceIdStatics)->get_GenericFileTransfer(&serviceId));
        return llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId{ serviceId, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommServiceProvider<D>::ServiceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider)->get_ServiceId(&value));
        return llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMap<uint32_t, llm::OS::Storage::Streams::IBuffer>) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommServiceProvider<D>::SdpRawAttributes() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider)->get_SdpRawAttributes(&value));
        return llm::OS::Foundation::Collections::IMap<uint32_t, llm::OS::Storage::Streams::IBuffer>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommServiceProvider<D>::StartAdvertising(llm::OS::Networking::Sockets::StreamSocketListener const& listener) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider)->StartAdvertising(*(void**)(&listener)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommServiceProvider<D>::StopAdvertising() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider)->StopAdvertising());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommServiceProvider2<D>::StartAdvertising(llm::OS::Networking::Sockets::StreamSocketListener const& listener, bool radioDiscoverable) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider2)->StartAdvertisingWithRadioDiscoverability(*(void**)(&listener), radioDiscoverable));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceProvider>) consume_Windows_Devices_Bluetooth_Rfcomm_IRfcommServiceProviderStatics<D>::CreateAsync(llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId const& serviceId) const
    {
        void* asyncOp{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceProviderStatics)->CreateAsync(*(void**)(&serviceId), &asyncOp));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceProvider>{ asyncOp, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceService> : produce_base<D, llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceService>
    {
        int32_t __stdcall get_ConnectionHostName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::HostName>(this->shim().ConnectionHostName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ConnectionServiceName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ConnectionServiceName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ServiceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId>(this->shim().ServiceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProtectionLevel(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::Sockets::SocketProtectionLevel>(this->shim().ProtectionLevel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxProtectionLevel(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::Sockets::SocketProtectionLevel>(this->shim().MaxProtectionLevel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSdpRawAttributesAsync(void** asyncOp) noexcept final try
        {
            clear_abi(asyncOp);
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IMapView<uint32_t, llm::OS::Storage::Streams::IBuffer>>>(this->shim().GetSdpRawAttributesAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSdpRawAttributesWithCacheModeAsync(int32_t cacheMode, void** asyncOp) noexcept final try
        {
            clear_abi(asyncOp);
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IMapView<uint32_t, llm::OS::Storage::Streams::IBuffer>>>(this->shim().GetSdpRawAttributesAsync(*reinterpret_cast<llm::OS::Devices::Bluetooth::BluetoothCacheMode const*>(&cacheMode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceService2> : produce_base<D, llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceService2>
    {
        int32_t __stdcall get_Device(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Bluetooth::BluetoothDevice>(this->shim().Device());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceService3> : produce_base<D, llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceService3>
    {
        int32_t __stdcall get_DeviceAccessInformation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Enumeration::DeviceAccessInformation>(this->shim().DeviceAccessInformation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestAccessAsync(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceAccessStatus>>(this->shim().RequestAccessAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceServiceStatics> : produce_base<D, llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceServiceStatics>
    {
        int32_t __stdcall FromIdAsync(void* deviceId, void** asyncOp) noexcept final try
        {
            clear_abi(asyncOp);
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Bluetooth::Rfcomm::RfcommDeviceService>>(this->shim().FromIdAsync(*reinterpret_cast<hstring const*>(&deviceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeviceSelector(void* serviceId, void** selector) noexcept final try
        {
            clear_abi(selector);
            typename D::abi_guard guard(this->shim());
            *selector = detach_from<hstring>(this->shim().GetDeviceSelector(*reinterpret_cast<llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId const*>(&serviceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceServiceStatics2> : produce_base<D, llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceServiceStatics2>
    {
        int32_t __stdcall GetDeviceSelectorForBluetoothDevice(void* bluetoothDevice, void** selector) noexcept final try
        {
            clear_abi(selector);
            typename D::abi_guard guard(this->shim());
            *selector = detach_from<hstring>(this->shim().GetDeviceSelectorForBluetoothDevice(*reinterpret_cast<llm::OS::Devices::Bluetooth::BluetoothDevice const*>(&bluetoothDevice)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeviceSelectorForBluetoothDeviceWithCacheMode(void* bluetoothDevice, int32_t cacheMode, void** selector) noexcept final try
        {
            clear_abi(selector);
            typename D::abi_guard guard(this->shim());
            *selector = detach_from<hstring>(this->shim().GetDeviceSelectorForBluetoothDevice(*reinterpret_cast<llm::OS::Devices::Bluetooth::BluetoothDevice const*>(&bluetoothDevice), *reinterpret_cast<llm::OS::Devices::Bluetooth::BluetoothCacheMode const*>(&cacheMode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeviceSelectorForBluetoothDeviceAndServiceId(void* bluetoothDevice, void* serviceId, void** selector) noexcept final try
        {
            clear_abi(selector);
            typename D::abi_guard guard(this->shim());
            *selector = detach_from<hstring>(this->shim().GetDeviceSelectorForBluetoothDeviceAndServiceId(*reinterpret_cast<llm::OS::Devices::Bluetooth::BluetoothDevice const*>(&bluetoothDevice), *reinterpret_cast<llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId const*>(&serviceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeviceSelectorForBluetoothDeviceAndServiceIdWithCacheMode(void* bluetoothDevice, void* serviceId, int32_t cacheMode, void** selector) noexcept final try
        {
            clear_abi(selector);
            typename D::abi_guard guard(this->shim());
            *selector = detach_from<hstring>(this->shim().GetDeviceSelectorForBluetoothDeviceAndServiceId(*reinterpret_cast<llm::OS::Devices::Bluetooth::BluetoothDevice const*>(&bluetoothDevice), *reinterpret_cast<llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId const*>(&serviceId), *reinterpret_cast<llm::OS::Devices::Bluetooth::BluetoothCacheMode const*>(&cacheMode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceServicesResult> : produce_base<D, llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceServicesResult>
    {
        int32_t __stdcall get_Error(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Bluetooth::BluetoothError>(this->shim().Error());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Services(void** services) noexcept final try
        {
            clear_abi(services);
            typename D::abi_guard guard(this->shim());
            *services = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Bluetooth::Rfcomm::RfcommDeviceService>>(this->shim().Services());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceId> : produce_base<D, llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceId>
    {
        int32_t __stdcall get_Uuid(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().Uuid());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AsShortId(uint32_t* shortId) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *shortId = detach_from<uint32_t>(this->shim().AsShortId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AsString(void** id) noexcept final try
        {
            clear_abi(id);
            typename D::abi_guard guard(this->shim());
            *id = detach_from<hstring>(this->shim().AsString());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceIdStatics> : produce_base<D, llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceIdStatics>
    {
        int32_t __stdcall FromUuid(llm::guid uuid, void** serviceId) noexcept final try
        {
            clear_abi(serviceId);
            typename D::abi_guard guard(this->shim());
            *serviceId = detach_from<llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId>(this->shim().FromUuid(*reinterpret_cast<llm::guid const*>(&uuid)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FromShortId(uint32_t shortId, void** serviceId) noexcept final try
        {
            clear_abi(serviceId);
            typename D::abi_guard guard(this->shim());
            *serviceId = detach_from<llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId>(this->shim().FromShortId(shortId));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SerialPort(void** serviceId) noexcept final try
        {
            clear_abi(serviceId);
            typename D::abi_guard guard(this->shim());
            *serviceId = detach_from<llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId>(this->shim().SerialPort());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ObexObjectPush(void** serviceId) noexcept final try
        {
            clear_abi(serviceId);
            typename D::abi_guard guard(this->shim());
            *serviceId = detach_from<llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId>(this->shim().ObexObjectPush());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ObexFileTransfer(void** serviceId) noexcept final try
        {
            clear_abi(serviceId);
            typename D::abi_guard guard(this->shim());
            *serviceId = detach_from<llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId>(this->shim().ObexFileTransfer());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PhoneBookAccessPce(void** serviceId) noexcept final try
        {
            clear_abi(serviceId);
            typename D::abi_guard guard(this->shim());
            *serviceId = detach_from<llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId>(this->shim().PhoneBookAccessPce());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PhoneBookAccessPse(void** serviceId) noexcept final try
        {
            clear_abi(serviceId);
            typename D::abi_guard guard(this->shim());
            *serviceId = detach_from<llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId>(this->shim().PhoneBookAccessPse());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_GenericFileTransfer(void** serviceId) noexcept final try
        {
            clear_abi(serviceId);
            typename D::abi_guard guard(this->shim());
            *serviceId = detach_from<llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId>(this->shim().GenericFileTransfer());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider> : produce_base<D, llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider>
    {
        int32_t __stdcall get_ServiceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId>(this->shim().ServiceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SdpRawAttributes(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMap<uint32_t, llm::OS::Storage::Streams::IBuffer>>(this->shim().SdpRawAttributes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StartAdvertising(void* listener) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartAdvertising(*reinterpret_cast<llm::OS::Networking::Sockets::StreamSocketListener const*>(&listener));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StopAdvertising() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StopAdvertising();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider2> : produce_base<D, llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider2>
    {
        int32_t __stdcall StartAdvertisingWithRadioDiscoverability(void* listener, bool radioDiscoverable) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartAdvertising(*reinterpret_cast<llm::OS::Networking::Sockets::StreamSocketListener const*>(&listener), radioDiscoverable);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceProviderStatics> : produce_base<D, llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceProviderStatics>
    {
        int32_t __stdcall CreateAsync(void* serviceId, void** asyncOp) noexcept final try
        {
            clear_abi(asyncOp);
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceProvider>>(this->shim().CreateAsync(*reinterpret_cast<llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId const*>(&serviceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Devices::Bluetooth::Rfcomm
{
    inline auto RfcommDeviceService::FromIdAsync(param::hstring const& deviceId)
    {
        return impl::call_factory<RfcommDeviceService, IRfcommDeviceServiceStatics>([&](IRfcommDeviceServiceStatics const& f) { return f.FromIdAsync(deviceId); });
    }
    inline auto RfcommDeviceService::GetDeviceSelector(llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId const& serviceId)
    {
        return impl::call_factory<RfcommDeviceService, IRfcommDeviceServiceStatics>([&](IRfcommDeviceServiceStatics const& f) { return f.GetDeviceSelector(serviceId); });
    }
    inline auto RfcommDeviceService::GetDeviceSelectorForBluetoothDevice(llm::OS::Devices::Bluetooth::BluetoothDevice const& bluetoothDevice)
    {
        return impl::call_factory<RfcommDeviceService, IRfcommDeviceServiceStatics2>([&](IRfcommDeviceServiceStatics2 const& f) { return f.GetDeviceSelectorForBluetoothDevice(bluetoothDevice); });
    }
    inline auto RfcommDeviceService::GetDeviceSelectorForBluetoothDevice(llm::OS::Devices::Bluetooth::BluetoothDevice const& bluetoothDevice, llm::OS::Devices::Bluetooth::BluetoothCacheMode const& cacheMode)
    {
        return impl::call_factory<RfcommDeviceService, IRfcommDeviceServiceStatics2>([&](IRfcommDeviceServiceStatics2 const& f) { return f.GetDeviceSelectorForBluetoothDevice(bluetoothDevice, cacheMode); });
    }
    inline auto RfcommDeviceService::GetDeviceSelectorForBluetoothDeviceAndServiceId(llm::OS::Devices::Bluetooth::BluetoothDevice const& bluetoothDevice, llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId const& serviceId)
    {
        return impl::call_factory<RfcommDeviceService, IRfcommDeviceServiceStatics2>([&](IRfcommDeviceServiceStatics2 const& f) { return f.GetDeviceSelectorForBluetoothDeviceAndServiceId(bluetoothDevice, serviceId); });
    }
    inline auto RfcommDeviceService::GetDeviceSelectorForBluetoothDeviceAndServiceId(llm::OS::Devices::Bluetooth::BluetoothDevice const& bluetoothDevice, llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId const& serviceId, llm::OS::Devices::Bluetooth::BluetoothCacheMode const& cacheMode)
    {
        return impl::call_factory<RfcommDeviceService, IRfcommDeviceServiceStatics2>([&](IRfcommDeviceServiceStatics2 const& f) { return f.GetDeviceSelectorForBluetoothDeviceAndServiceId(bluetoothDevice, serviceId, cacheMode); });
    }
    inline auto RfcommServiceId::FromUuid(llm::guid const& uuid)
    {
        return impl::call_factory<RfcommServiceId, IRfcommServiceIdStatics>([&](IRfcommServiceIdStatics const& f) { return f.FromUuid(uuid); });
    }
    inline auto RfcommServiceId::FromShortId(uint32_t shortId)
    {
        return impl::call_factory<RfcommServiceId, IRfcommServiceIdStatics>([&](IRfcommServiceIdStatics const& f) { return f.FromShortId(shortId); });
    }
    inline auto RfcommServiceId::SerialPort()
    {
        return impl::call_factory_cast<llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId(*)(IRfcommServiceIdStatics const&), RfcommServiceId, IRfcommServiceIdStatics>([](IRfcommServiceIdStatics const& f) { return f.SerialPort(); });
    }
    inline auto RfcommServiceId::ObexObjectPush()
    {
        return impl::call_factory_cast<llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId(*)(IRfcommServiceIdStatics const&), RfcommServiceId, IRfcommServiceIdStatics>([](IRfcommServiceIdStatics const& f) { return f.ObexObjectPush(); });
    }
    inline auto RfcommServiceId::ObexFileTransfer()
    {
        return impl::call_factory_cast<llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId(*)(IRfcommServiceIdStatics const&), RfcommServiceId, IRfcommServiceIdStatics>([](IRfcommServiceIdStatics const& f) { return f.ObexFileTransfer(); });
    }
    inline auto RfcommServiceId::PhoneBookAccessPce()
    {
        return impl::call_factory_cast<llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId(*)(IRfcommServiceIdStatics const&), RfcommServiceId, IRfcommServiceIdStatics>([](IRfcommServiceIdStatics const& f) { return f.PhoneBookAccessPce(); });
    }
    inline auto RfcommServiceId::PhoneBookAccessPse()
    {
        return impl::call_factory_cast<llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId(*)(IRfcommServiceIdStatics const&), RfcommServiceId, IRfcommServiceIdStatics>([](IRfcommServiceIdStatics const& f) { return f.PhoneBookAccessPse(); });
    }
    inline auto RfcommServiceId::GenericFileTransfer()
    {
        return impl::call_factory_cast<llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId(*)(IRfcommServiceIdStatics const&), RfcommServiceId, IRfcommServiceIdStatics>([](IRfcommServiceIdStatics const& f) { return f.GenericFileTransfer(); });
    }
    inline auto RfcommServiceProvider::CreateAsync(llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId const& serviceId)
    {
        return impl::call_factory<RfcommServiceProvider, IRfcommServiceProviderStatics>([&](IRfcommServiceProviderStatics const& f) { return f.CreateAsync(serviceId); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceService> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceService2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceService3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceServiceStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceServiceStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceServicesResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceId> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceIdStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceProviderStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Bluetooth::Rfcomm::RfcommDeviceService> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceProvider> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
