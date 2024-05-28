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
#ifndef LLM_OS_Devices_Bluetooth_Background_H
#define LLM_OS_Devices_Bluetooth_Background_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Devices.Bluetooth.h"
#include "llm/impl/Windows.Devices.Bluetooth.2.h"
#include "llm/impl/Windows.Devices.Bluetooth.Advertisement.2.h"
#include "llm/impl/Windows.Devices.Bluetooth.GenericAttributeProfile.2.h"
#include "llm/impl/Windows.Devices.Bluetooth.Rfcomm.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Networking.Sockets.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.Devices.Bluetooth.Background.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatus) consume_Windows_Devices_Bluetooth_Background_IBluetoothLEAdvertisementPublisherTriggerDetails<D>::Status() const
    {
        llm::OS::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Background::IBluetoothLEAdvertisementPublisherTriggerDetails)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::BluetoothError) consume_Windows_Devices_Bluetooth_Background_IBluetoothLEAdvertisementPublisherTriggerDetails<D>::Error() const
    {
        llm::OS::Devices::Bluetooth::BluetoothError value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Background::IBluetoothLEAdvertisementPublisherTriggerDetails)->get_Error(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int16_t>) consume_Windows_Devices_Bluetooth_Background_IBluetoothLEAdvertisementPublisherTriggerDetails2<D>::SelectedTransmitPowerLevelInDBm() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Background::IBluetoothLEAdvertisementPublisherTriggerDetails2)->get_SelectedTransmitPowerLevelInDBm(&value));
        return llm::OS::Foundation::IReference<int16_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::BluetoothError) consume_Windows_Devices_Bluetooth_Background_IBluetoothLEAdvertisementWatcherTriggerDetails<D>::Error() const
    {
        llm::OS::Devices::Bluetooth::BluetoothError value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Background::IBluetoothLEAdvertisementWatcherTriggerDetails)->get_Error(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs>) consume_Windows_Devices_Bluetooth_Background_IBluetoothLEAdvertisementWatcherTriggerDetails<D>::Advertisements() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Background::IBluetoothLEAdvertisementWatcherTriggerDetails)->get_Advertisements(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::BluetoothSignalStrengthFilter) consume_Windows_Devices_Bluetooth_Background_IBluetoothLEAdvertisementWatcherTriggerDetails<D>::SignalStrengthFilter() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Background::IBluetoothLEAdvertisementWatcherTriggerDetails)->get_SignalStrengthFilter(&value));
        return llm::OS::Devices::Bluetooth::BluetoothSignalStrengthFilter{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic) consume_Windows_Devices_Bluetooth_Background_IGattCharacteristicNotificationTriggerDetails<D>::Characteristic() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Background::IGattCharacteristicNotificationTriggerDetails)->get_Characteristic(&value));
        return llm::OS::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) consume_Windows_Devices_Bluetooth_Background_IGattCharacteristicNotificationTriggerDetails<D>::Value() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Background::IGattCharacteristicNotificationTriggerDetails)->get_Value(&value));
        return llm::OS::Storage::Streams::IBuffer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::BluetoothError) consume_Windows_Devices_Bluetooth_Background_IGattCharacteristicNotificationTriggerDetails2<D>::Error() const
    {
        llm::OS::Devices::Bluetooth::BluetoothError value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Background::IGattCharacteristicNotificationTriggerDetails2)->get_Error(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::Background::BluetoothEventTriggeringMode) consume_Windows_Devices_Bluetooth_Background_IGattCharacteristicNotificationTriggerDetails2<D>::EventTriggeringMode() const
    {
        llm::OS::Devices::Bluetooth::Background::BluetoothEventTriggeringMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Background::IGattCharacteristicNotificationTriggerDetails2)->get_EventTriggeringMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Bluetooth::GenericAttributeProfile::GattValueChangedEventArgs>) consume_Windows_Devices_Bluetooth_Background_IGattCharacteristicNotificationTriggerDetails2<D>::ValueChangedEvents() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Background::IGattCharacteristicNotificationTriggerDetails2)->get_ValueChangedEvents(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Bluetooth::GenericAttributeProfile::GattValueChangedEventArgs>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Bluetooth_Background_IGattServiceProviderConnection<D>::TriggerId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Background::IGattServiceProviderConnection)->get_TriggerId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::GenericAttributeProfile::GattLocalService) consume_Windows_Devices_Bluetooth_Background_IGattServiceProviderConnection<D>::Service() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Background::IGattServiceProviderConnection)->get_Service(&value));
        return llm::OS::Devices::Bluetooth::GenericAttributeProfile::GattLocalService{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Bluetooth_Background_IGattServiceProviderConnection<D>::Start() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Background::IGattServiceProviderConnection)->Start());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Devices::Bluetooth::Background::GattServiceProviderConnection>) consume_Windows_Devices_Bluetooth_Background_IGattServiceProviderConnectionStatics<D>::AllServices() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Background::IGattServiceProviderConnectionStatics)->get_AllServices(&value));
        return llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Devices::Bluetooth::Background::GattServiceProviderConnection>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::Background::GattServiceProviderConnection) consume_Windows_Devices_Bluetooth_Background_IGattServiceProviderTriggerDetails<D>::Connection() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Background::IGattServiceProviderTriggerDetails)->get_Connection(&value));
        return llm::OS::Devices::Bluetooth::Background::GattServiceProviderConnection{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Sockets::StreamSocket) consume_Windows_Devices_Bluetooth_Background_IRfcommConnectionTriggerDetails<D>::Socket() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Background::IRfcommConnectionTriggerDetails)->get_Socket(&value));
        return llm::OS::Networking::Sockets::StreamSocket{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Bluetooth_Background_IRfcommConnectionTriggerDetails<D>::Incoming() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Background::IRfcommConnectionTriggerDetails)->get_Incoming(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::BluetoothDevice) consume_Windows_Devices_Bluetooth_Background_IRfcommConnectionTriggerDetails<D>::RemoteDevice() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Background::IRfcommConnectionTriggerDetails)->get_RemoteDevice(&value));
        return llm::OS::Devices::Bluetooth::BluetoothDevice{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) consume_Windows_Devices_Bluetooth_Background_IRfcommInboundConnectionInformation<D>::SdpRecord() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Background::IRfcommInboundConnectionInformation)->get_SdpRecord(&value));
        return llm::OS::Storage::Streams::IBuffer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Bluetooth_Background_IRfcommInboundConnectionInformation<D>::SdpRecord(llm::OS::Storage::Streams::IBuffer const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Background::IRfcommInboundConnectionInformation)->put_SdpRecord(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId) consume_Windows_Devices_Bluetooth_Background_IRfcommInboundConnectionInformation<D>::LocalServiceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Background::IRfcommInboundConnectionInformation)->get_LocalServiceId(&value));
        return llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Bluetooth_Background_IRfcommInboundConnectionInformation<D>::LocalServiceId(llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Background::IRfcommInboundConnectionInformation)->put_LocalServiceId(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::BluetoothServiceCapabilities) consume_Windows_Devices_Bluetooth_Background_IRfcommInboundConnectionInformation<D>::ServiceCapabilities() const
    {
        llm::OS::Devices::Bluetooth::BluetoothServiceCapabilities value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Background::IRfcommInboundConnectionInformation)->get_ServiceCapabilities(reinterpret_cast<uint32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Bluetooth_Background_IRfcommInboundConnectionInformation<D>::ServiceCapabilities(llm::OS::Devices::Bluetooth::BluetoothServiceCapabilities const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Background::IRfcommInboundConnectionInformation)->put_ServiceCapabilities(static_cast<uint32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId) consume_Windows_Devices_Bluetooth_Background_IRfcommOutboundConnectionInformation<D>::RemoteServiceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Background::IRfcommOutboundConnectionInformation)->get_RemoteServiceId(&value));
        return llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Bluetooth_Background_IRfcommOutboundConnectionInformation<D>::RemoteServiceId(llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Bluetooth::Background::IRfcommOutboundConnectionInformation)->put_RemoteServiceId(*(void**)(&value)));
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Bluetooth::Background::IBluetoothLEAdvertisementPublisherTriggerDetails> : produce_base<D, llm::OS::Devices::Bluetooth::Background::IBluetoothLEAdvertisementPublisherTriggerDetails>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Error(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Bluetooth::BluetoothError>(this->shim().Error());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Bluetooth::Background::IBluetoothLEAdvertisementPublisherTriggerDetails2> : produce_base<D, llm::OS::Devices::Bluetooth::Background::IBluetoothLEAdvertisementPublisherTriggerDetails2>
    {
        int32_t __stdcall get_SelectedTransmitPowerLevelInDBm(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int16_t>>(this->shim().SelectedTransmitPowerLevelInDBm());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Bluetooth::Background::IBluetoothLEAdvertisementWatcherTriggerDetails> : produce_base<D, llm::OS::Devices::Bluetooth::Background::IBluetoothLEAdvertisementWatcherTriggerDetails>
    {
        int32_t __stdcall get_Error(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Bluetooth::BluetoothError>(this->shim().Error());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Advertisements(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs>>(this->shim().Advertisements());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SignalStrengthFilter(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Bluetooth::BluetoothSignalStrengthFilter>(this->shim().SignalStrengthFilter());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Bluetooth::Background::IGattCharacteristicNotificationTriggerDetails> : produce_base<D, llm::OS::Devices::Bluetooth::Background::IGattCharacteristicNotificationTriggerDetails>
    {
        int32_t __stdcall get_Characteristic(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic>(this->shim().Characteristic());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Value(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IBuffer>(this->shim().Value());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Bluetooth::Background::IGattCharacteristicNotificationTriggerDetails2> : produce_base<D, llm::OS::Devices::Bluetooth::Background::IGattCharacteristicNotificationTriggerDetails2>
    {
        int32_t __stdcall get_Error(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Bluetooth::BluetoothError>(this->shim().Error());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EventTriggeringMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Bluetooth::Background::BluetoothEventTriggeringMode>(this->shim().EventTriggeringMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ValueChangedEvents(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Bluetooth::GenericAttributeProfile::GattValueChangedEventArgs>>(this->shim().ValueChangedEvents());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Bluetooth::Background::IGattServiceProviderConnection> : produce_base<D, llm::OS::Devices::Bluetooth::Background::IGattServiceProviderConnection>
    {
        int32_t __stdcall get_TriggerId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().TriggerId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Service(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Bluetooth::GenericAttributeProfile::GattLocalService>(this->shim().Service());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Start() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Bluetooth::Background::IGattServiceProviderConnectionStatics> : produce_base<D, llm::OS::Devices::Bluetooth::Background::IGattServiceProviderConnectionStatics>
    {
        int32_t __stdcall get_AllServices(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Devices::Bluetooth::Background::GattServiceProviderConnection>>(this->shim().AllServices());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Bluetooth::Background::IGattServiceProviderTriggerDetails> : produce_base<D, llm::OS::Devices::Bluetooth::Background::IGattServiceProviderTriggerDetails>
    {
        int32_t __stdcall get_Connection(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Bluetooth::Background::GattServiceProviderConnection>(this->shim().Connection());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Bluetooth::Background::IRfcommConnectionTriggerDetails> : produce_base<D, llm::OS::Devices::Bluetooth::Background::IRfcommConnectionTriggerDetails>
    {
        int32_t __stdcall get_Socket(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::Sockets::StreamSocket>(this->shim().Socket());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Incoming(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Incoming());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RemoteDevice(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Bluetooth::BluetoothDevice>(this->shim().RemoteDevice());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Bluetooth::Background::IRfcommInboundConnectionInformation> : produce_base<D, llm::OS::Devices::Bluetooth::Background::IRfcommInboundConnectionInformation>
    {
        int32_t __stdcall get_SdpRecord(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IBuffer>(this->shim().SdpRecord());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SdpRecord(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SdpRecord(*reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LocalServiceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId>(this->shim().LocalServiceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_LocalServiceId(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LocalServiceId(*reinterpret_cast<llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ServiceCapabilities(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Bluetooth::BluetoothServiceCapabilities>(this->shim().ServiceCapabilities());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ServiceCapabilities(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ServiceCapabilities(*reinterpret_cast<llm::OS::Devices::Bluetooth::BluetoothServiceCapabilities const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Bluetooth::Background::IRfcommOutboundConnectionInformation> : produce_base<D, llm::OS::Devices::Bluetooth::Background::IRfcommOutboundConnectionInformation>
    {
        int32_t __stdcall get_RemoteServiceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId>(this->shim().RemoteServiceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RemoteServiceId(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoteServiceId(*reinterpret_cast<llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Devices::Bluetooth::Background
{
    inline auto GattServiceProviderConnection::AllServices()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Devices::Bluetooth::Background::GattServiceProviderConnection>(*)(IGattServiceProviderConnectionStatics const&), GattServiceProviderConnection, IGattServiceProviderConnectionStatics>([](IGattServiceProviderConnectionStatics const& f) { return f.AllServices(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Devices::Bluetooth::Background::IBluetoothLEAdvertisementPublisherTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Bluetooth::Background::IBluetoothLEAdvertisementPublisherTriggerDetails2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Bluetooth::Background::IBluetoothLEAdvertisementWatcherTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Bluetooth::Background::IGattCharacteristicNotificationTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Bluetooth::Background::IGattCharacteristicNotificationTriggerDetails2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Bluetooth::Background::IGattServiceProviderConnection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Bluetooth::Background::IGattServiceProviderConnectionStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Bluetooth::Background::IGattServiceProviderTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Bluetooth::Background::IRfcommConnectionTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Bluetooth::Background::IRfcommInboundConnectionInformation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Bluetooth::Background::IRfcommOutboundConnectionInformation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Bluetooth::Background::BluetoothLEAdvertisementPublisherTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Bluetooth::Background::BluetoothLEAdvertisementWatcherTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Bluetooth::Background::GattCharacteristicNotificationTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Bluetooth::Background::GattServiceProviderConnection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Bluetooth::Background::GattServiceProviderTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Bluetooth::Background::RfcommConnectionTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Bluetooth::Background::RfcommInboundConnectionInformation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Bluetooth::Background::RfcommOutboundConnectionInformation> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
