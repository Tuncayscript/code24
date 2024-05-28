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
#ifndef LLM_OS_Devices_Spi_H
#define LLM_OS_Devices_Spi_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Devices.h"
#include "llm/impl/Windows.Devices.Spi.Provider.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Devices.Spi.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Spi_ISpiBusInfo<D>::ChipSelectLineCount() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Spi::ISpiBusInfo)->get_ChipSelectLineCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Spi_ISpiBusInfo<D>::MinClockFrequency() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Spi::ISpiBusInfo)->get_MinClockFrequency(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Spi_ISpiBusInfo<D>::MaxClockFrequency() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Spi::ISpiBusInfo)->get_MaxClockFrequency(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<int32_t>) consume_Windows_Devices_Spi_ISpiBusInfo<D>::SupportedDataBitLengths() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Spi::ISpiBusInfo)->get_SupportedDataBitLengths(&value));
        return llm::OS::Foundation::Collections::IVectorView<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Spi_ISpiConnectionSettings<D>::ChipSelectLine() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Spi::ISpiConnectionSettings)->get_ChipSelectLine(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Spi_ISpiConnectionSettings<D>::ChipSelectLine(int32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Spi::ISpiConnectionSettings)->put_ChipSelectLine(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Spi::SpiMode) consume_Windows_Devices_Spi_ISpiConnectionSettings<D>::Mode() const
    {
        llm::OS::Devices::Spi::SpiMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Spi::ISpiConnectionSettings)->get_Mode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Spi_ISpiConnectionSettings<D>::Mode(llm::OS::Devices::Spi::SpiMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Spi::ISpiConnectionSettings)->put_Mode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Spi_ISpiConnectionSettings<D>::DataBitLength() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Spi::ISpiConnectionSettings)->get_DataBitLength(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Spi_ISpiConnectionSettings<D>::DataBitLength(int32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Spi::ISpiConnectionSettings)->put_DataBitLength(value));
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Spi_ISpiConnectionSettings<D>::ClockFrequency() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Spi::ISpiConnectionSettings)->get_ClockFrequency(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Spi_ISpiConnectionSettings<D>::ClockFrequency(int32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Spi::ISpiConnectionSettings)->put_ClockFrequency(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Spi::SpiSharingMode) consume_Windows_Devices_Spi_ISpiConnectionSettings<D>::SharingMode() const
    {
        llm::OS::Devices::Spi::SpiSharingMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Spi::ISpiConnectionSettings)->get_SharingMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Spi_ISpiConnectionSettings<D>::SharingMode(llm::OS::Devices::Spi::SpiSharingMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Spi::ISpiConnectionSettings)->put_SharingMode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Spi::SpiConnectionSettings) consume_Windows_Devices_Spi_ISpiConnectionSettingsFactory<D>::Create(int32_t chipSelectLine) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Spi::ISpiConnectionSettingsFactory)->Create(chipSelectLine, &value));
        return llm::OS::Devices::Spi::SpiConnectionSettings{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Spi::SpiDevice) consume_Windows_Devices_Spi_ISpiController<D>::GetDevice(llm::OS::Devices::Spi::SpiConnectionSettings const& settings) const
    {
        void* device{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Spi::ISpiController)->GetDevice(*(void**)(&settings), &device));
        return llm::OS::Devices::Spi::SpiDevice{ device, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Spi::SpiController>) consume_Windows_Devices_Spi_ISpiControllerStatics<D>::GetDefaultAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Spi::ISpiControllerStatics)->GetDefaultAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Spi::SpiController>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Spi::SpiController>>) consume_Windows_Devices_Spi_ISpiControllerStatics<D>::GetControllersAsync(llm::OS::Devices::Spi::Provider::ISpiProvider const& provider) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Spi::ISpiControllerStatics)->GetControllersAsync(*(void**)(&provider), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Spi::SpiController>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Spi_ISpiDevice<D>::DeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Spi::ISpiDevice)->get_DeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Spi::SpiConnectionSettings) consume_Windows_Devices_Spi_ISpiDevice<D>::ConnectionSettings() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Spi::ISpiDevice)->get_ConnectionSettings(&value));
        return llm::OS::Devices::Spi::SpiConnectionSettings{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Spi_ISpiDevice<D>::Write(array_view<uint8_t const> buffer) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Spi::ISpiDevice)->Write(buffer.size(), get_abi(buffer)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Spi_ISpiDevice<D>::Read(array_view<uint8_t> buffer) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Spi::ISpiDevice)->Read(buffer.size(), put_abi(buffer)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Spi_ISpiDevice<D>::TransferSequential(array_view<uint8_t const> writeBuffer, array_view<uint8_t> readBuffer) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Spi::ISpiDevice)->TransferSequential(writeBuffer.size(), get_abi(writeBuffer), readBuffer.size(), put_abi(readBuffer)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Spi_ISpiDevice<D>::TransferFullDuplex(array_view<uint8_t const> writeBuffer, array_view<uint8_t> readBuffer) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Spi::ISpiDevice)->TransferFullDuplex(writeBuffer.size(), get_abi(writeBuffer), readBuffer.size(), put_abi(readBuffer)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Spi_ISpiDeviceStatics<D>::GetDeviceSelector() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Spi::ISpiDeviceStatics)->GetDeviceSelector(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Spi_ISpiDeviceStatics<D>::GetDeviceSelector(param::hstring const& friendlyName) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Spi::ISpiDeviceStatics)->GetDeviceSelectorFromFriendlyName(*(void**)(&friendlyName), &value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Spi::SpiBusInfo) consume_Windows_Devices_Spi_ISpiDeviceStatics<D>::GetBusInfo(param::hstring const& busId) const
    {
        void* busInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Spi::ISpiDeviceStatics)->GetBusInfo(*(void**)(&busId), &busInfo));
        return llm::OS::Devices::Spi::SpiBusInfo{ busInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Spi::SpiDevice>) consume_Windows_Devices_Spi_ISpiDeviceStatics<D>::FromIdAsync(param::hstring const& busId, llm::OS::Devices::Spi::SpiConnectionSettings const& settings) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Spi::ISpiDeviceStatics)->FromIdAsync(*(void**)(&busId), *(void**)(&settings), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Spi::SpiDevice>{ operation, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Spi::ISpiBusInfo> : produce_base<D, llm::OS::Devices::Spi::ISpiBusInfo>
    {
        int32_t __stdcall get_ChipSelectLineCount(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().ChipSelectLineCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MinClockFrequency(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().MinClockFrequency());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxClockFrequency(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().MaxClockFrequency());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportedDataBitLengths(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<int32_t>>(this->shim().SupportedDataBitLengths());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Spi::ISpiConnectionSettings> : produce_base<D, llm::OS::Devices::Spi::ISpiConnectionSettings>
    {
        int32_t __stdcall get_ChipSelectLine(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().ChipSelectLine());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ChipSelectLine(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ChipSelectLine(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Mode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Spi::SpiMode>(this->shim().Mode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Mode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Mode(*reinterpret_cast<llm::OS::Devices::Spi::SpiMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DataBitLength(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().DataBitLength());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DataBitLength(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DataBitLength(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ClockFrequency(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().ClockFrequency());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ClockFrequency(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClockFrequency(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SharingMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Spi::SpiSharingMode>(this->shim().SharingMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SharingMode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SharingMode(*reinterpret_cast<llm::OS::Devices::Spi::SpiSharingMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Spi::ISpiConnectionSettingsFactory> : produce_base<D, llm::OS::Devices::Spi::ISpiConnectionSettingsFactory>
    {
        int32_t __stdcall Create(int32_t chipSelectLine, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Spi::SpiConnectionSettings>(this->shim().Create(chipSelectLine));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Spi::ISpiController> : produce_base<D, llm::OS::Devices::Spi::ISpiController>
    {
        int32_t __stdcall GetDevice(void* settings, void** device) noexcept final try
        {
            clear_abi(device);
            typename D::abi_guard guard(this->shim());
            *device = detach_from<llm::OS::Devices::Spi::SpiDevice>(this->shim().GetDevice(*reinterpret_cast<llm::OS::Devices::Spi::SpiConnectionSettings const*>(&settings)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Spi::ISpiControllerStatics> : produce_base<D, llm::OS::Devices::Spi::ISpiControllerStatics>
    {
        int32_t __stdcall GetDefaultAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Spi::SpiController>>(this->shim().GetDefaultAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetControllersAsync(void* provider, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Spi::SpiController>>>(this->shim().GetControllersAsync(*reinterpret_cast<llm::OS::Devices::Spi::Provider::ISpiProvider const*>(&provider)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Spi::ISpiDevice> : produce_base<D, llm::OS::Devices::Spi::ISpiDevice>
    {
        int32_t __stdcall get_DeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ConnectionSettings(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Spi::SpiConnectionSettings>(this->shim().ConnectionSettings());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Write(uint32_t __bufferSize, uint8_t* buffer) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Write(array_view<uint8_t const>(reinterpret_cast<uint8_t const *>(buffer), reinterpret_cast<uint8_t const *>(buffer) + __bufferSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Read(uint32_t __bufferSize, uint8_t* buffer) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Read(array_view<uint8_t>(reinterpret_cast<uint8_t*>(buffer), reinterpret_cast<uint8_t*>(buffer) + __bufferSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TransferSequential(uint32_t __writeBufferSize, uint8_t* writeBuffer, uint32_t __readBufferSize, uint8_t* readBuffer) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransferSequential(array_view<uint8_t const>(reinterpret_cast<uint8_t const *>(writeBuffer), reinterpret_cast<uint8_t const *>(writeBuffer) + __writeBufferSize), array_view<uint8_t>(reinterpret_cast<uint8_t*>(readBuffer), reinterpret_cast<uint8_t*>(readBuffer) + __readBufferSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TransferFullDuplex(uint32_t __writeBufferSize, uint8_t* writeBuffer, uint32_t __readBufferSize, uint8_t* readBuffer) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransferFullDuplex(array_view<uint8_t const>(reinterpret_cast<uint8_t const *>(writeBuffer), reinterpret_cast<uint8_t const *>(writeBuffer) + __writeBufferSize), array_view<uint8_t>(reinterpret_cast<uint8_t*>(readBuffer), reinterpret_cast<uint8_t*>(readBuffer) + __readBufferSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Devices::Spi::ISpiDeviceStatics> : produce_base<D, llm::OS::Devices::Spi::ISpiDeviceStatics>
    {
        int32_t __stdcall GetDeviceSelector(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().GetDeviceSelector());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeviceSelectorFromFriendlyName(void* friendlyName, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().GetDeviceSelector(*reinterpret_cast<hstring const*>(&friendlyName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetBusInfo(void* busId, void** busInfo) noexcept final try
        {
            clear_abi(busInfo);
            typename D::abi_guard guard(this->shim());
            *busInfo = detach_from<llm::OS::Devices::Spi::SpiBusInfo>(this->shim().GetBusInfo(*reinterpret_cast<hstring const*>(&busId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FromIdAsync(void* busId, void* settings, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Spi::SpiDevice>>(this->shim().FromIdAsync(*reinterpret_cast<hstring const*>(&busId), *reinterpret_cast<llm::OS::Devices::Spi::SpiConnectionSettings const*>(&settings)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
}
LLM_EXPORT namespace llm::OS::Devices::Spi
{
    inline SpiConnectionSettings::SpiConnectionSettings(int32_t chipSelectLine) :
        SpiConnectionSettings(impl::call_factory<SpiConnectionSettings, ISpiConnectionSettingsFactory>([&](ISpiConnectionSettingsFactory const& f) { return f.Create(chipSelectLine); }))
    {
    }
    inline auto SpiController::GetDefaultAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Spi::SpiController>(*)(ISpiControllerStatics const&), SpiController, ISpiControllerStatics>([](ISpiControllerStatics const& f) { return f.GetDefaultAsync(); });
    }
    inline auto SpiController::GetControllersAsync(llm::OS::Devices::Spi::Provider::ISpiProvider const& provider)
    {
        return impl::call_factory<SpiController, ISpiControllerStatics>([&](ISpiControllerStatics const& f) { return f.GetControllersAsync(provider); });
    }
    inline auto SpiDevice::GetDeviceSelector()
    {
        return impl::call_factory_cast<hstring(*)(ISpiDeviceStatics const&), SpiDevice, ISpiDeviceStatics>([](ISpiDeviceStatics const& f) { return f.GetDeviceSelector(); });
    }
    inline auto SpiDevice::GetDeviceSelector(param::hstring const& friendlyName)
    {
        return impl::call_factory<SpiDevice, ISpiDeviceStatics>([&](ISpiDeviceStatics const& f) { return f.GetDeviceSelector(friendlyName); });
    }
    inline auto SpiDevice::GetBusInfo(param::hstring const& busId)
    {
        return impl::call_factory<SpiDevice, ISpiDeviceStatics>([&](ISpiDeviceStatics const& f) { return f.GetBusInfo(busId); });
    }
    inline auto SpiDevice::FromIdAsync(param::hstring const& busId, llm::OS::Devices::Spi::SpiConnectionSettings const& settings)
    {
        return impl::call_factory<SpiDevice, ISpiDeviceStatics>([&](ISpiDeviceStatics const& f) { return f.FromIdAsync(busId, settings); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Devices::Spi::ISpiBusInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Spi::ISpiConnectionSettings> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Spi::ISpiConnectionSettingsFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Spi::ISpiController> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Spi::ISpiControllerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Spi::ISpiDevice> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Spi::ISpiDeviceStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Spi::SpiBusInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Spi::SpiConnectionSettings> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Spi::SpiController> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Spi::SpiDevice> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
