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
#ifndef LLM_OS_Graphics_Display_2_H
#define LLM_OS_Graphics_Display_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Graphics.Display.1.h"
LLM_EXPORT namespace llm:OS::Graphics::Display
{
    struct DisplayPropertiesEventHandler : llm:OS::Foundation::IUnknown
    {
        DisplayPropertiesEventHandler(std::nullptr_t = nullptr) noexcept {}
        DisplayPropertiesEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> DisplayPropertiesEventHandler(L lambda);
        template <typename F> DisplayPropertiesEventHandler(F* function);
        template <typename O, typename M> DisplayPropertiesEventHandler(O* object, M method);
        template <typename O, typename M> DisplayPropertiesEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> DisplayPropertiesEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::Foundation::IInspectable const& sender) const;
    };
    struct NitRange
    {
        float MinNits;
        float MaxNits;
        float StepSizeNits;
    };
    inline bool operator==(NitRange const& left, NitRange const& right) noexcept
    {
        return left.MinNits == right.MinNits && left.MaxNits == right.MaxNits && left.StepSizeNits == right.StepSizeNits;
    }
    inline bool operator!=(NitRange const& left, NitRange const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) AdvancedColorInfo : llm:OS::Graphics::Display::IAdvancedColorInfo
    {
        AdvancedColorInfo(std::nullptr_t) noexcept {}
        AdvancedColorInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Display::IAdvancedColorInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BrightnessOverride : llm:OS::Graphics::Display::IBrightnessOverride
    {
        BrightnessOverride(std::nullptr_t) noexcept {}
        BrightnessOverride(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Display::IBrightnessOverride(ptr, take_ownership_from_abi) {}
        static auto GetDefaultForSystem();
        static auto GetForCurrentView();
        static auto SaveForSystemAsync(llm:OS::Graphics::Display::BrightnessOverride const& value);
    };
    struct __declspec(empty_bases) BrightnessOverrideSettings : llm:OS::Graphics::Display::IBrightnessOverrideSettings
    {
        BrightnessOverrideSettings(std::nullptr_t) noexcept {}
        BrightnessOverrideSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Display::IBrightnessOverrideSettings(ptr, take_ownership_from_abi) {}
        static auto CreateFromLevel(double level);
        static auto CreateFromNits(float nits);
        static auto CreateFromDisplayBrightnessOverrideScenario(llm:OS::Graphics::Display::DisplayBrightnessOverrideScenario const& overrideScenario);
    };
    struct __declspec(empty_bases) ColorOverrideSettings : llm:OS::Graphics::Display::IColorOverrideSettings
    {
        ColorOverrideSettings(std::nullptr_t) noexcept {}
        ColorOverrideSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Display::IColorOverrideSettings(ptr, take_ownership_from_abi) {}
        static auto CreateFromDisplayColorOverrideScenario(llm:OS::Graphics::Display::DisplayColorOverrideScenario const& overrideScenario);
    };
    struct __declspec(empty_bases) DisplayEnhancementOverride : llm:OS::Graphics::Display::IDisplayEnhancementOverride
    {
        DisplayEnhancementOverride(std::nullptr_t) noexcept {}
        DisplayEnhancementOverride(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Display::IDisplayEnhancementOverride(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
    };
    struct __declspec(empty_bases) DisplayEnhancementOverrideCapabilities : llm:OS::Graphics::Display::IDisplayEnhancementOverrideCapabilities
    {
        DisplayEnhancementOverrideCapabilities(std::nullptr_t) noexcept {}
        DisplayEnhancementOverrideCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Display::IDisplayEnhancementOverrideCapabilities(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DisplayEnhancementOverrideCapabilitiesChangedEventArgs : llm:OS::Graphics::Display::IDisplayEnhancementOverrideCapabilitiesChangedEventArgs
    {
        DisplayEnhancementOverrideCapabilitiesChangedEventArgs(std::nullptr_t) noexcept {}
        DisplayEnhancementOverrideCapabilitiesChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Display::IDisplayEnhancementOverrideCapabilitiesChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DisplayInformation : llm:OS::Graphics::Display::IDisplayInformation,
        impl::require<DisplayInformation, llm:OS::Graphics::Display::IDisplayInformation2, llm:OS::Graphics::Display::IDisplayInformation3, llm:OS::Graphics::Display::IDisplayInformation4, llm:OS::Graphics::Display::IDisplayInformation5>
    {
        DisplayInformation(std::nullptr_t) noexcept {}
        DisplayInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Display::IDisplayInformation(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
        [[nodiscard]] static auto AutoRotationPreferences();
        static auto AutoRotationPreferences(llm:OS::Graphics::Display::DisplayOrientations const& value);
        static auto DisplayContentsInvalidated(llm:OS::Foundation::TypedEventHandler<llm:OS::Graphics::Display::DisplayInformation, llm:OS::Foundation::IInspectable> const& handler);
        using DisplayContentsInvalidated_revoker = impl::factory_event_revoker<llm:OS::Graphics::Display::IDisplayInformationStatics, &impl::abi_t<llm:OS::Graphics::Display::IDisplayInformationStatics>::remove_DisplayContentsInvalidated>;
        [[nodiscard]] static DisplayContentsInvalidated_revoker DisplayContentsInvalidated(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Graphics::Display::DisplayInformation, llm:OS::Foundation::IInspectable> const& handler);
        static auto DisplayContentsInvalidated(llm::event_token const& token);
    };
    struct DisplayProperties
    {
        DisplayProperties() = delete;
        [[nodiscard]] static auto CurrentOrientation();
        [[nodiscard]] static auto NativeOrientation();
        [[nodiscard]] static auto AutoRotationPreferences();
        static auto AutoRotationPreferences(llm:OS::Graphics::Display::DisplayOrientations const& value);
        static auto OrientationChanged(llm:OS::Graphics::Display::DisplayPropertiesEventHandler const& handler);
        using OrientationChanged_revoker = impl::factory_event_revoker<llm:OS::Graphics::Display::IDisplayPropertiesStatics, &impl::abi_t<llm:OS::Graphics::Display::IDisplayPropertiesStatics>::remove_OrientationChanged>;
        [[nodiscard]] static OrientationChanged_revoker OrientationChanged(auto_revoke_t, llm:OS::Graphics::Display::DisplayPropertiesEventHandler const& handler);
        static auto OrientationChanged(llm::event_token const& token);
        [[nodiscard]] static auto ResolutionScale();
        [[nodiscard]] static auto LogicalDpi();
        static auto LogicalDpiChanged(llm:OS::Graphics::Display::DisplayPropertiesEventHandler const& handler);
        using LogicalDpiChanged_revoker = impl::factory_event_revoker<llm:OS::Graphics::Display::IDisplayPropertiesStatics, &impl::abi_t<llm:OS::Graphics::Display::IDisplayPropertiesStatics>::remove_LogicalDpiChanged>;
        [[nodiscard]] static LogicalDpiChanged_revoker LogicalDpiChanged(auto_revoke_t, llm:OS::Graphics::Display::DisplayPropertiesEventHandler const& handler);
        static auto LogicalDpiChanged(llm::event_token const& token);
        [[nodiscard]] static auto StereoEnabled();
        static auto StereoEnabledChanged(llm:OS::Graphics::Display::DisplayPropertiesEventHandler const& handler);
        using StereoEnabledChanged_revoker = impl::factory_event_revoker<llm:OS::Graphics::Display::IDisplayPropertiesStatics, &impl::abi_t<llm:OS::Graphics::Display::IDisplayPropertiesStatics>::remove_StereoEnabledChanged>;
        [[nodiscard]] static StereoEnabledChanged_revoker StereoEnabledChanged(auto_revoke_t, llm:OS::Graphics::Display::DisplayPropertiesEventHandler const& handler);
        static auto StereoEnabledChanged(llm::event_token const& token);
        static auto GetColorProfileAsync();
        static auto ColorProfileChanged(llm:OS::Graphics::Display::DisplayPropertiesEventHandler const& handler);
        using ColorProfileChanged_revoker = impl::factory_event_revoker<llm:OS::Graphics::Display::IDisplayPropertiesStatics, &impl::abi_t<llm:OS::Graphics::Display::IDisplayPropertiesStatics>::remove_ColorProfileChanged>;
        [[nodiscard]] static ColorProfileChanged_revoker ColorProfileChanged(auto_revoke_t, llm:OS::Graphics::Display::DisplayPropertiesEventHandler const& handler);
        static auto ColorProfileChanged(llm::event_token const& token);
        static auto DisplayContentsInvalidated(llm:OS::Graphics::Display::DisplayPropertiesEventHandler const& handler);
        using DisplayContentsInvalidated_revoker = impl::factory_event_revoker<llm:OS::Graphics::Display::IDisplayPropertiesStatics, &impl::abi_t<llm:OS::Graphics::Display::IDisplayPropertiesStatics>::remove_DisplayContentsInvalidated>;
        [[nodiscard]] static DisplayContentsInvalidated_revoker DisplayContentsInvalidated(auto_revoke_t, llm:OS::Graphics::Display::DisplayPropertiesEventHandler const& handler);
        static auto DisplayContentsInvalidated(llm::event_token const& token);
    };
    struct __declspec(empty_bases) DisplayServices : llm:OS::Graphics::Display::IDisplayServices
    {
        DisplayServices(std::nullptr_t) noexcept {}
        DisplayServices(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Display::IDisplayServices(ptr, take_ownership_from_abi) {}
        static auto FindAll();
    };
}
#endif
