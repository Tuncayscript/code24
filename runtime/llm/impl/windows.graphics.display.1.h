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
#ifndef LLM_OS_Graphics_Display_1_H
#define LLM_OS_Graphics_Display_1_H
#include "llm/impl/Windows.Graphics.Display.0.h"
LLM_EXPORT namespace llm:OS::Graphics::Display
{
    struct __declspec(empty_bases) IAdvancedColorInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdvancedColorInfo>
    {
        IAdvancedColorInfo(std::nullptr_t = nullptr) noexcept {}
        IAdvancedColorInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBrightnessOverride :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBrightnessOverride>
    {
        IBrightnessOverride(std::nullptr_t = nullptr) noexcept {}
        IBrightnessOverride(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBrightnessOverrideSettings :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBrightnessOverrideSettings>
    {
        IBrightnessOverrideSettings(std::nullptr_t = nullptr) noexcept {}
        IBrightnessOverrideSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBrightnessOverrideSettingsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBrightnessOverrideSettingsStatics>
    {
        IBrightnessOverrideSettingsStatics(std::nullptr_t = nullptr) noexcept {}
        IBrightnessOverrideSettingsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBrightnessOverrideStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBrightnessOverrideStatics>
    {
        IBrightnessOverrideStatics(std::nullptr_t = nullptr) noexcept {}
        IBrightnessOverrideStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IColorOverrideSettings :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IColorOverrideSettings>
    {
        IColorOverrideSettings(std::nullptr_t = nullptr) noexcept {}
        IColorOverrideSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IColorOverrideSettingsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IColorOverrideSettingsStatics>
    {
        IColorOverrideSettingsStatics(std::nullptr_t = nullptr) noexcept {}
        IColorOverrideSettingsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayEnhancementOverride :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDisplayEnhancementOverride>
    {
        IDisplayEnhancementOverride(std::nullptr_t = nullptr) noexcept {}
        IDisplayEnhancementOverride(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayEnhancementOverrideCapabilities :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDisplayEnhancementOverrideCapabilities>
    {
        IDisplayEnhancementOverrideCapabilities(std::nullptr_t = nullptr) noexcept {}
        IDisplayEnhancementOverrideCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayEnhancementOverrideCapabilitiesChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDisplayEnhancementOverrideCapabilitiesChangedEventArgs>
    {
        IDisplayEnhancementOverrideCapabilitiesChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IDisplayEnhancementOverrideCapabilitiesChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayEnhancementOverrideStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDisplayEnhancementOverrideStatics>
    {
        IDisplayEnhancementOverrideStatics(std::nullptr_t = nullptr) noexcept {}
        IDisplayEnhancementOverrideStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayInformation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDisplayInformation>
    {
        IDisplayInformation(std::nullptr_t = nullptr) noexcept {}
        IDisplayInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayInformation2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDisplayInformation2>,
        impl::require<llm:OS::Graphics::Display::IDisplayInformation2, llm:OS::Graphics::Display::IDisplayInformation>
    {
        IDisplayInformation2(std::nullptr_t = nullptr) noexcept {}
        IDisplayInformation2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayInformation3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDisplayInformation3>
    {
        IDisplayInformation3(std::nullptr_t = nullptr) noexcept {}
        IDisplayInformation3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayInformation4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDisplayInformation4>
    {
        IDisplayInformation4(std::nullptr_t = nullptr) noexcept {}
        IDisplayInformation4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayInformation5 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDisplayInformation5>
    {
        IDisplayInformation5(std::nullptr_t = nullptr) noexcept {}
        IDisplayInformation5(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayInformationStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDisplayInformationStatics>
    {
        IDisplayInformationStatics(std::nullptr_t = nullptr) noexcept {}
        IDisplayInformationStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayPropertiesStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDisplayPropertiesStatics>
    {
        IDisplayPropertiesStatics(std::nullptr_t = nullptr) noexcept {}
        IDisplayPropertiesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayServices :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDisplayServices>
    {
        IDisplayServices(std::nullptr_t = nullptr) noexcept {}
        IDisplayServices(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayServicesStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDisplayServicesStatics>
    {
        IDisplayServicesStatics(std::nullptr_t = nullptr) noexcept {}
        IDisplayServicesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
