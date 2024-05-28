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
#ifndef LLM_OS_Gaming_Input_Custom_H
#define LLM_OS_Gaming_Input_Custom_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Gaming.Input.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Gaming.Input.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.Gaming.Input.Custom.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Gaming_Input_Custom_ICustomGameControllerFactory<D>::CreateGameController(llm::OS::Gaming::Input::Custom::IGameControllerProvider const& provider) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Input::Custom::ICustomGameControllerFactory)->CreateGameController(*(void**)(&provider), &value));
        return llm::OS::Foundation::IInspectable{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_Input_Custom_ICustomGameControllerFactory<D>::OnGameControllerAdded(llm::OS::Gaming::Input::IGameController const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Input::Custom::ICustomGameControllerFactory)->OnGameControllerAdded(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_Input_Custom_ICustomGameControllerFactory<D>::OnGameControllerRemoved(llm::OS::Gaming::Input::IGameController const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Input::Custom::ICustomGameControllerFactory)->OnGameControllerRemoved(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_Input_Custom_IGameControllerFactoryManagerStatics<D>::RegisterCustomFactoryForGipInterface(llm::OS::Gaming::Input::Custom::ICustomGameControllerFactory const& factory, llm::guid const& interfaceId) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Input::Custom::IGameControllerFactoryManagerStatics)->RegisterCustomFactoryForGipInterface(*(void**)(&factory), impl::bind_in(interfaceId)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_Input_Custom_IGameControllerFactoryManagerStatics<D>::RegisterCustomFactoryForHardwareId(llm::OS::Gaming::Input::Custom::ICustomGameControllerFactory const& factory, uint16_t hardwareVendorId, uint16_t hardwareProductId) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Input::Custom::IGameControllerFactoryManagerStatics)->RegisterCustomFactoryForHardwareId(*(void**)(&factory), hardwareVendorId, hardwareProductId));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_Input_Custom_IGameControllerFactoryManagerStatics<D>::RegisterCustomFactoryForXusbType(llm::OS::Gaming::Input::Custom::ICustomGameControllerFactory const& factory, llm::OS::Gaming::Input::Custom::XusbDeviceType const& xusbType, llm::OS::Gaming::Input::Custom::XusbDeviceSubtype const& xusbSubtype) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Input::Custom::IGameControllerFactoryManagerStatics)->RegisterCustomFactoryForXusbType(*(void**)(&factory), static_cast<int32_t>(xusbType), static_cast<int32_t>(xusbSubtype)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Gaming::Input::IGameController) consume_Windows_Gaming_Input_Custom_IGameControllerFactoryManagerStatics2<D>::TryGetFactoryControllerFromGameController(llm::OS::Gaming::Input::Custom::ICustomGameControllerFactory const& factory, llm::OS::Gaming::Input::IGameController const& gameController) const
    {
        void* factoryController{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Input::Custom::IGameControllerFactoryManagerStatics2)->TryGetFactoryControllerFromGameController(*(void**)(&factory), *(void**)(&gameController), &factoryController));
        return llm::OS::Gaming::Input::IGameController{ factoryController, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_Input_Custom_IGameControllerInputSink<D>::OnInputResumed(uint64_t timestamp) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Input::Custom::IGameControllerInputSink)->OnInputResumed(timestamp));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_Input_Custom_IGameControllerInputSink<D>::OnInputSuspended(uint64_t timestamp) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Input::Custom::IGameControllerInputSink)->OnInputSuspended(timestamp));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Gaming::Input::Custom::GameControllerVersionInfo) consume_Windows_Gaming_Input_Custom_IGameControllerProvider<D>::FirmwareVersionInfo() const
    {
        llm::OS::Gaming::Input::Custom::GameControllerVersionInfo value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Input::Custom::IGameControllerProvider)->get_FirmwareVersionInfo(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint16_t) consume_Windows_Gaming_Input_Custom_IGameControllerProvider<D>::HardwareProductId() const
    {
        uint16_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Input::Custom::IGameControllerProvider)->get_HardwareProductId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint16_t) consume_Windows_Gaming_Input_Custom_IGameControllerProvider<D>::HardwareVendorId() const
    {
        uint16_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Input::Custom::IGameControllerProvider)->get_HardwareVendorId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Gaming::Input::Custom::GameControllerVersionInfo) consume_Windows_Gaming_Input_Custom_IGameControllerProvider<D>::HardwareVersionInfo() const
    {
        llm::OS::Gaming::Input::Custom::GameControllerVersionInfo value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Input::Custom::IGameControllerProvider)->get_HardwareVersionInfo(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Gaming_Input_Custom_IGameControllerProvider<D>::IsConnected() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Input::Custom::IGameControllerProvider)->get_IsConnected(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Gaming_Input_Custom_IGipFirmwareUpdateResult<D>::ExtendedErrorCode() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Input::Custom::IGipFirmwareUpdateResult)->get_ExtendedErrorCode(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Gaming_Input_Custom_IGipFirmwareUpdateResult<D>::FinalComponentId() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Input::Custom::IGipFirmwareUpdateResult)->get_FinalComponentId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Gaming::Input::Custom::GipFirmwareUpdateStatus) consume_Windows_Gaming_Input_Custom_IGipFirmwareUpdateResult<D>::Status() const
    {
        llm::OS::Gaming::Input::Custom::GipFirmwareUpdateStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Input::Custom::IGipFirmwareUpdateResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_Input_Custom_IGipGameControllerInputSink<D>::OnKeyReceived(uint64_t timestamp, uint8_t keyCode, bool isPressed) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Input::Custom::IGipGameControllerInputSink)->OnKeyReceived(timestamp, keyCode, isPressed));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_Input_Custom_IGipGameControllerInputSink<D>::OnMessageReceived(uint64_t timestamp, llm::OS::Gaming::Input::Custom::GipMessageClass const& messageClass, uint8_t messageId, uint8_t sequenceId, array_view<uint8_t const> messageBuffer) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Input::Custom::IGipGameControllerInputSink)->OnMessageReceived(timestamp, static_cast<int32_t>(messageClass), messageId, sequenceId, messageBuffer.size(), get_abi(messageBuffer)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_Input_Custom_IGipGameControllerProvider<D>::SendMessage(llm::OS::Gaming::Input::Custom::GipMessageClass const& messageClass, uint8_t messageId, array_view<uint8_t const> messageBuffer) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Input::Custom::IGipGameControllerProvider)->SendMessage(static_cast<int32_t>(messageClass), messageId, messageBuffer.size(), get_abi(messageBuffer)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_Input_Custom_IGipGameControllerProvider<D>::SendReceiveMessage(llm::OS::Gaming::Input::Custom::GipMessageClass const& messageClass, uint8_t messageId, array_view<uint8_t const> requestMessageBuffer, array_view<uint8_t> responseMessageBuffer) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Input::Custom::IGipGameControllerProvider)->SendReceiveMessage(static_cast<int32_t>(messageClass), messageId, requestMessageBuffer.size(), get_abi(requestMessageBuffer), responseMessageBuffer.size(), put_abi(responseMessageBuffer)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Gaming::Input::Custom::GipFirmwareUpdateResult, llm::OS::Gaming::Input::Custom::GipFirmwareUpdateProgress>) consume_Windows_Gaming_Input_Custom_IGipGameControllerProvider<D>::UpdateFirmwareAsync(llm::OS::Storage::Streams::IInputStream const& firmwareImage) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Input::Custom::IGipGameControllerProvider)->UpdateFirmwareAsync(*(void**)(&firmwareImage), &result));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Gaming::Input::Custom::GipFirmwareUpdateResult, llm::OS::Gaming::Input::Custom::GipFirmwareUpdateProgress>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_Input_Custom_IHidGameControllerInputSink<D>::OnInputReportReceived(uint64_t timestamp, uint8_t reportId, array_view<uint8_t const> reportBuffer) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Input::Custom::IHidGameControllerInputSink)->OnInputReportReceived(timestamp, reportId, reportBuffer.size(), get_abi(reportBuffer)));
    }
    template <typename D> LLM_IMPL_AUTO(uint16_t) consume_Windows_Gaming_Input_Custom_IHidGameControllerProvider<D>::UsageId() const
    {
        uint16_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Input::Custom::IHidGameControllerProvider)->get_UsageId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint16_t) consume_Windows_Gaming_Input_Custom_IHidGameControllerProvider<D>::UsagePage() const
    {
        uint16_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Input::Custom::IHidGameControllerProvider)->get_UsagePage(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_Input_Custom_IHidGameControllerProvider<D>::GetFeatureReport(uint8_t reportId, array_view<uint8_t> reportBuffer) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Input::Custom::IHidGameControllerProvider)->GetFeatureReport(reportId, reportBuffer.size(), put_abi(reportBuffer)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_Input_Custom_IHidGameControllerProvider<D>::SendFeatureReport(uint8_t reportId, array_view<uint8_t const> reportBuffer) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Input::Custom::IHidGameControllerProvider)->SendFeatureReport(reportId, reportBuffer.size(), get_abi(reportBuffer)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_Input_Custom_IHidGameControllerProvider<D>::SendOutputReport(uint8_t reportId, array_view<uint8_t const> reportBuffer) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Input::Custom::IHidGameControllerProvider)->SendOutputReport(reportId, reportBuffer.size(), get_abi(reportBuffer)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_Input_Custom_IXusbGameControllerInputSink<D>::OnInputReceived(uint64_t timestamp, uint8_t reportId, array_view<uint8_t const> inputBuffer) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Input::Custom::IXusbGameControllerInputSink)->OnInputReceived(timestamp, reportId, inputBuffer.size(), get_abi(inputBuffer)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_Input_Custom_IXusbGameControllerProvider<D>::SetVibration(double lowFrequencyMotorSpeed, double highFrequencyMotorSpeed) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Input::Custom::IXusbGameControllerProvider)->SetVibration(lowFrequencyMotorSpeed, highFrequencyMotorSpeed));
    }
    template <typename D>
    struct produce<D, llm::OS::Gaming::Input::Custom::ICustomGameControllerFactory> : produce_base<D, llm::OS::Gaming::Input::Custom::ICustomGameControllerFactory>
    {
        int32_t __stdcall CreateGameController(void* provider, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateGameController(*reinterpret_cast<llm::OS::Gaming::Input::Custom::IGameControllerProvider const*>(&provider)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall OnGameControllerAdded(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnGameControllerAdded(*reinterpret_cast<llm::OS::Gaming::Input::IGameController const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall OnGameControllerRemoved(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnGameControllerRemoved(*reinterpret_cast<llm::OS::Gaming::Input::IGameController const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Gaming::Input::Custom::IGameControllerFactoryManagerStatics> : produce_base<D, llm::OS::Gaming::Input::Custom::IGameControllerFactoryManagerStatics>
    {
        int32_t __stdcall RegisterCustomFactoryForGipInterface(void* factory, llm::guid interfaceId) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RegisterCustomFactoryForGipInterface(*reinterpret_cast<llm::OS::Gaming::Input::Custom::ICustomGameControllerFactory const*>(&factory), *reinterpret_cast<llm::guid const*>(&interfaceId));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RegisterCustomFactoryForHardwareId(void* factory, uint16_t hardwareVendorId, uint16_t hardwareProductId) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RegisterCustomFactoryForHardwareId(*reinterpret_cast<llm::OS::Gaming::Input::Custom::ICustomGameControllerFactory const*>(&factory), hardwareVendorId, hardwareProductId);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RegisterCustomFactoryForXusbType(void* factory, int32_t xusbType, int32_t xusbSubtype) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RegisterCustomFactoryForXusbType(*reinterpret_cast<llm::OS::Gaming::Input::Custom::ICustomGameControllerFactory const*>(&factory), *reinterpret_cast<llm::OS::Gaming::Input::Custom::XusbDeviceType const*>(&xusbType), *reinterpret_cast<llm::OS::Gaming::Input::Custom::XusbDeviceSubtype const*>(&xusbSubtype));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Gaming::Input::Custom::IGameControllerFactoryManagerStatics2> : produce_base<D, llm::OS::Gaming::Input::Custom::IGameControllerFactoryManagerStatics2>
    {
        int32_t __stdcall TryGetFactoryControllerFromGameController(void* factory, void* gameController, void** factoryController) noexcept final try
        {
            clear_abi(factoryController);
            typename D::abi_guard guard(this->shim());
            *factoryController = detach_from<llm::OS::Gaming::Input::IGameController>(this->shim().TryGetFactoryControllerFromGameController(*reinterpret_cast<llm::OS::Gaming::Input::Custom::ICustomGameControllerFactory const*>(&factory), *reinterpret_cast<llm::OS::Gaming::Input::IGameController const*>(&gameController)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Gaming::Input::Custom::IGameControllerInputSink> : produce_base<D, llm::OS::Gaming::Input::Custom::IGameControllerInputSink>
    {
        int32_t __stdcall OnInputResumed(uint64_t timestamp) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnInputResumed(timestamp);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall OnInputSuspended(uint64_t timestamp) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnInputSuspended(timestamp);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::Gaming::Input::Custom::IGameControllerProvider> : produce_base<D, llm::OS::Gaming::Input::Custom::IGameControllerProvider>
    {
        int32_t __stdcall get_FirmwareVersionInfo(struct struct_Windows_Gaming_Input_Custom_GameControllerVersionInfo* value) noexcept final try
        {
            zero_abi<llm::OS::Gaming::Input::Custom::GameControllerVersionInfo>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Gaming::Input::Custom::GameControllerVersionInfo>(this->shim().FirmwareVersionInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HardwareProductId(uint16_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint16_t>(this->shim().HardwareProductId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HardwareVendorId(uint16_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint16_t>(this->shim().HardwareVendorId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HardwareVersionInfo(struct struct_Windows_Gaming_Input_Custom_GameControllerVersionInfo* value) noexcept final try
        {
            zero_abi<llm::OS::Gaming::Input::Custom::GameControllerVersionInfo>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Gaming::Input::Custom::GameControllerVersionInfo>(this->shim().HardwareVersionInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsConnected(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsConnected());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Gaming::Input::Custom::IGipFirmwareUpdateResult> : produce_base<D, llm::OS::Gaming::Input::Custom::IGipFirmwareUpdateResult>
    {
        int32_t __stdcall get_ExtendedErrorCode(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().ExtendedErrorCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FinalComponentId(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().FinalComponentId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Gaming::Input::Custom::GipFirmwareUpdateStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Gaming::Input::Custom::IGipGameControllerInputSink> : produce_base<D, llm::OS::Gaming::Input::Custom::IGipGameControllerInputSink>
    {
        int32_t __stdcall OnKeyReceived(uint64_t timestamp, uint8_t keyCode, bool isPressed) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnKeyReceived(timestamp, keyCode, isPressed);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall OnMessageReceived(uint64_t timestamp, int32_t messageClass, uint8_t messageId, uint8_t sequenceId, uint32_t __messageBufferSize, uint8_t* messageBuffer) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnMessageReceived(timestamp, *reinterpret_cast<llm::OS::Gaming::Input::Custom::GipMessageClass const*>(&messageClass), messageId, sequenceId, array_view<uint8_t const>(reinterpret_cast<uint8_t const *>(messageBuffer), reinterpret_cast<uint8_t const *>(messageBuffer) + __messageBufferSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Gaming::Input::Custom::IGipGameControllerProvider> : produce_base<D, llm::OS::Gaming::Input::Custom::IGipGameControllerProvider>
    {
        int32_t __stdcall SendMessage(int32_t messageClass, uint8_t messageId, uint32_t __messageBufferSize, uint8_t* messageBuffer) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SendMessage(*reinterpret_cast<llm::OS::Gaming::Input::Custom::GipMessageClass const*>(&messageClass), messageId, array_view<uint8_t const>(reinterpret_cast<uint8_t const *>(messageBuffer), reinterpret_cast<uint8_t const *>(messageBuffer) + __messageBufferSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SendReceiveMessage(int32_t messageClass, uint8_t messageId, uint32_t __requestMessageBufferSize, uint8_t* requestMessageBuffer, uint32_t __responseMessageBufferSize, uint8_t* responseMessageBuffer) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SendReceiveMessage(*reinterpret_cast<llm::OS::Gaming::Input::Custom::GipMessageClass const*>(&messageClass), messageId, array_view<uint8_t const>(reinterpret_cast<uint8_t const *>(requestMessageBuffer), reinterpret_cast<uint8_t const *>(requestMessageBuffer) + __requestMessageBufferSize), array_view<uint8_t>(reinterpret_cast<uint8_t*>(responseMessageBuffer), reinterpret_cast<uint8_t*>(responseMessageBuffer) + __responseMessageBufferSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UpdateFirmwareAsync(void* firmwareImage, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Gaming::Input::Custom::GipFirmwareUpdateResult, llm::OS::Gaming::Input::Custom::GipFirmwareUpdateProgress>>(this->shim().UpdateFirmwareAsync(*reinterpret_cast<llm::OS::Storage::Streams::IInputStream const*>(&firmwareImage)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Gaming::Input::Custom::IHidGameControllerInputSink> : produce_base<D, llm::OS::Gaming::Input::Custom::IHidGameControllerInputSink>
    {
        int32_t __stdcall OnInputReportReceived(uint64_t timestamp, uint8_t reportId, uint32_t __reportBufferSize, uint8_t* reportBuffer) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnInputReportReceived(timestamp, reportId, array_view<uint8_t const>(reinterpret_cast<uint8_t const *>(reportBuffer), reinterpret_cast<uint8_t const *>(reportBuffer) + __reportBufferSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Gaming::Input::Custom::IHidGameControllerProvider> : produce_base<D, llm::OS::Gaming::Input::Custom::IHidGameControllerProvider>
    {
        int32_t __stdcall get_UsageId(uint16_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint16_t>(this->shim().UsageId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UsagePage(uint16_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint16_t>(this->shim().UsagePage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetFeatureReport(uint8_t reportId, uint32_t __reportBufferSize, uint8_t* reportBuffer) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GetFeatureReport(reportId, array_view<uint8_t>(reinterpret_cast<uint8_t*>(reportBuffer), reinterpret_cast<uint8_t*>(reportBuffer) + __reportBufferSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SendFeatureReport(uint8_t reportId, uint32_t __reportBufferSize, uint8_t* reportBuffer) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SendFeatureReport(reportId, array_view<uint8_t const>(reinterpret_cast<uint8_t const *>(reportBuffer), reinterpret_cast<uint8_t const *>(reportBuffer) + __reportBufferSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SendOutputReport(uint8_t reportId, uint32_t __reportBufferSize, uint8_t* reportBuffer) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SendOutputReport(reportId, array_view<uint8_t const>(reinterpret_cast<uint8_t const *>(reportBuffer), reinterpret_cast<uint8_t const *>(reportBuffer) + __reportBufferSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Gaming::Input::Custom::IXusbGameControllerInputSink> : produce_base<D, llm::OS::Gaming::Input::Custom::IXusbGameControllerInputSink>
    {
        int32_t __stdcall OnInputReceived(uint64_t timestamp, uint8_t reportId, uint32_t __inputBufferSize, uint8_t* inputBuffer) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnInputReceived(timestamp, reportId, array_view<uint8_t const>(reinterpret_cast<uint8_t const *>(inputBuffer), reinterpret_cast<uint8_t const *>(inputBuffer) + __inputBufferSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Gaming::Input::Custom::IXusbGameControllerProvider> : produce_base<D, llm::OS::Gaming::Input::Custom::IXusbGameControllerProvider>
    {
        int32_t __stdcall SetVibration(double lowFrequencyMotorSpeed, double highFrequencyMotorSpeed) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetVibration(lowFrequencyMotorSpeed, highFrequencyMotorSpeed);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Gaming::Input::Custom
{
    inline auto GameControllerFactoryManager::RegisterCustomFactoryForGipInterface(llm::OS::Gaming::Input::Custom::ICustomGameControllerFactory const& factory, llm::guid const& interfaceId)
    {
        impl::call_factory<GameControllerFactoryManager, IGameControllerFactoryManagerStatics>([&](IGameControllerFactoryManagerStatics const& f) { return f.RegisterCustomFactoryForGipInterface(factory, interfaceId); });
    }
    inline auto GameControllerFactoryManager::RegisterCustomFactoryForHardwareId(llm::OS::Gaming::Input::Custom::ICustomGameControllerFactory const& factory, uint16_t hardwareVendorId, uint16_t hardwareProductId)
    {
        impl::call_factory<GameControllerFactoryManager, IGameControllerFactoryManagerStatics>([&](IGameControllerFactoryManagerStatics const& f) { return f.RegisterCustomFactoryForHardwareId(factory, hardwareVendorId, hardwareProductId); });
    }
    inline auto GameControllerFactoryManager::RegisterCustomFactoryForXusbType(llm::OS::Gaming::Input::Custom::ICustomGameControllerFactory const& factory, llm::OS::Gaming::Input::Custom::XusbDeviceType const& xusbType, llm::OS::Gaming::Input::Custom::XusbDeviceSubtype const& xusbSubtype)
    {
        impl::call_factory<GameControllerFactoryManager, IGameControllerFactoryManagerStatics>([&](IGameControllerFactoryManagerStatics const& f) { return f.RegisterCustomFactoryForXusbType(factory, xusbType, xusbSubtype); });
    }
    inline auto GameControllerFactoryManager::TryGetFactoryControllerFromGameController(llm::OS::Gaming::Input::Custom::ICustomGameControllerFactory const& factory, llm::OS::Gaming::Input::IGameController const& gameController)
    {
        return impl::call_factory<GameControllerFactoryManager, IGameControllerFactoryManagerStatics2>([&](IGameControllerFactoryManagerStatics2 const& f) { return f.TryGetFactoryControllerFromGameController(factory, gameController); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Gaming::Input::Custom::ICustomGameControllerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::Input::Custom::IGameControllerFactoryManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::Input::Custom::IGameControllerFactoryManagerStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::Input::Custom::IGameControllerInputSink> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::Input::Custom::IGameControllerProvider> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::Input::Custom::IGipFirmwareUpdateResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::Input::Custom::IGipGameControllerInputSink> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::Input::Custom::IGipGameControllerProvider> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::Input::Custom::IHidGameControllerInputSink> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::Input::Custom::IHidGameControllerProvider> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::Input::Custom::IXusbGameControllerInputSink> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::Input::Custom::IXusbGameControllerProvider> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::Input::Custom::GameControllerFactoryManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::Input::Custom::GipFirmwareUpdateResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::Input::Custom::GipGameControllerProvider> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::Input::Custom::HidGameControllerProvider> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::Input::Custom::XusbGameControllerProvider> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
