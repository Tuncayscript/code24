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
#ifndef LLM_OS_Graphics_Display_H
#define LLM_OS_Graphics_Display_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Graphics.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Graphics.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.Graphics.Display.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Display::AdvancedColorKind) consume_Windows_Graphics_Display_IAdvancedColorInfo<D>::CurrentAdvancedColorKind() const
    {
        llm::OS::Graphics::Display::AdvancedColorKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IAdvancedColorInfo)->get_CurrentAdvancedColorKind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Point) consume_Windows_Graphics_Display_IAdvancedColorInfo<D>::RedPrimary() const
    {
        llm::OS::Foundation::Point value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IAdvancedColorInfo)->get_RedPrimary(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Point) consume_Windows_Graphics_Display_IAdvancedColorInfo<D>::GreenPrimary() const
    {
        llm::OS::Foundation::Point value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IAdvancedColorInfo)->get_GreenPrimary(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Point) consume_Windows_Graphics_Display_IAdvancedColorInfo<D>::BluePrimary() const
    {
        llm::OS::Foundation::Point value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IAdvancedColorInfo)->get_BluePrimary(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Point) consume_Windows_Graphics_Display_IAdvancedColorInfo<D>::WhitePoint() const
    {
        llm::OS::Foundation::Point value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IAdvancedColorInfo)->get_WhitePoint(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_Graphics_Display_IAdvancedColorInfo<D>::MaxLuminanceInNits() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IAdvancedColorInfo)->get_MaxLuminanceInNits(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_Graphics_Display_IAdvancedColorInfo<D>::MinLuminanceInNits() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IAdvancedColorInfo)->get_MinLuminanceInNits(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_Graphics_Display_IAdvancedColorInfo<D>::MaxAverageFullFrameLuminanceInNits() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IAdvancedColorInfo)->get_MaxAverageFullFrameLuminanceInNits(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_Graphics_Display_IAdvancedColorInfo<D>::SdrWhiteLevelInNits() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IAdvancedColorInfo)->get_SdrWhiteLevelInNits(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Display_IAdvancedColorInfo<D>::IsHdrMetadataFormatCurrentlySupported(llm::OS::Graphics::Display::HdrMetadataFormat const& format) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IAdvancedColorInfo)->IsHdrMetadataFormatCurrentlySupported(static_cast<int32_t>(format), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Display_IAdvancedColorInfo<D>::IsAdvancedColorKindAvailable(llm::OS::Graphics::Display::AdvancedColorKind const& kind) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IAdvancedColorInfo)->IsAdvancedColorKindAvailable(static_cast<int32_t>(kind), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Display_IBrightnessOverride<D>::IsSupported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IBrightnessOverride)->get_IsSupported(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Display_IBrightnessOverride<D>::IsOverrideActive() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IBrightnessOverride)->get_IsOverrideActive(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Graphics_Display_IBrightnessOverride<D>::BrightnessLevel() const
    {
        double level{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IBrightnessOverride)->get_BrightnessLevel(&level));
        return level;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Display_IBrightnessOverride<D>::SetBrightnessLevel(double brightnessLevel, llm::OS::Graphics::Display::DisplayBrightnessOverrideOptions const& options) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IBrightnessOverride)->SetBrightnessLevel(brightnessLevel, static_cast<uint32_t>(options)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Display_IBrightnessOverride<D>::SetBrightnessScenario(llm::OS::Graphics::Display::DisplayBrightnessScenario const& scenario, llm::OS::Graphics::Display::DisplayBrightnessOverrideOptions const& options) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IBrightnessOverride)->SetBrightnessScenario(static_cast<int32_t>(scenario), static_cast<uint32_t>(options)));
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Graphics_Display_IBrightnessOverride<D>::GetLevelForScenario(llm::OS::Graphics::Display::DisplayBrightnessScenario const& scenario) const
    {
        double brightnessLevel{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IBrightnessOverride)->GetLevelForScenario(static_cast<int32_t>(scenario), &brightnessLevel));
        return brightnessLevel;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Display_IBrightnessOverride<D>::StartOverride() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IBrightnessOverride)->StartOverride());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Display_IBrightnessOverride<D>::StopOverride() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IBrightnessOverride)->StopOverride());
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Graphics_Display_IBrightnessOverride<D>::IsSupportedChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::BrightnessOverride, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IBrightnessOverride)->add_IsSupportedChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Graphics_Display_IBrightnessOverride<D>::IsSupportedChanged_revoker consume_Windows_Graphics_Display_IBrightnessOverride<D>::IsSupportedChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::BrightnessOverride, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, IsSupportedChanged_revoker>(this, IsSupportedChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Display_IBrightnessOverride<D>::IsSupportedChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Graphics::Display::IBrightnessOverride)->remove_IsSupportedChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Graphics_Display_IBrightnessOverride<D>::IsOverrideActiveChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::BrightnessOverride, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IBrightnessOverride)->add_IsOverrideActiveChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Graphics_Display_IBrightnessOverride<D>::IsOverrideActiveChanged_revoker consume_Windows_Graphics_Display_IBrightnessOverride<D>::IsOverrideActiveChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::BrightnessOverride, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, IsOverrideActiveChanged_revoker>(this, IsOverrideActiveChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Display_IBrightnessOverride<D>::IsOverrideActiveChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Graphics::Display::IBrightnessOverride)->remove_IsOverrideActiveChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Graphics_Display_IBrightnessOverride<D>::BrightnessLevelChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::BrightnessOverride, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IBrightnessOverride)->add_BrightnessLevelChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Graphics_Display_IBrightnessOverride<D>::BrightnessLevelChanged_revoker consume_Windows_Graphics_Display_IBrightnessOverride<D>::BrightnessLevelChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::BrightnessOverride, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, BrightnessLevelChanged_revoker>(this, BrightnessLevelChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Display_IBrightnessOverride<D>::BrightnessLevelChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Graphics::Display::IBrightnessOverride)->remove_BrightnessLevelChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Graphics_Display_IBrightnessOverrideSettings<D>::DesiredLevel() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IBrightnessOverrideSettings)->get_DesiredLevel(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_Graphics_Display_IBrightnessOverrideSettings<D>::DesiredNits() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IBrightnessOverrideSettings)->get_DesiredNits(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Display::BrightnessOverrideSettings) consume_Windows_Graphics_Display_IBrightnessOverrideSettingsStatics<D>::CreateFromLevel(double level) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IBrightnessOverrideSettingsStatics)->CreateFromLevel(level, &result));
        return llm::OS::Graphics::Display::BrightnessOverrideSettings{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Display::BrightnessOverrideSettings) consume_Windows_Graphics_Display_IBrightnessOverrideSettingsStatics<D>::CreateFromNits(float nits) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IBrightnessOverrideSettingsStatics)->CreateFromNits(nits, &result));
        return llm::OS::Graphics::Display::BrightnessOverrideSettings{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Display::BrightnessOverrideSettings) consume_Windows_Graphics_Display_IBrightnessOverrideSettingsStatics<D>::CreateFromDisplayBrightnessOverrideScenario(llm::OS::Graphics::Display::DisplayBrightnessOverrideScenario const& overrideScenario) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IBrightnessOverrideSettingsStatics)->CreateFromDisplayBrightnessOverrideScenario(static_cast<int32_t>(overrideScenario), &result));
        return llm::OS::Graphics::Display::BrightnessOverrideSettings{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Display::BrightnessOverride) consume_Windows_Graphics_Display_IBrightnessOverrideStatics<D>::GetDefaultForSystem() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IBrightnessOverrideStatics)->GetDefaultForSystem(&value));
        return llm::OS::Graphics::Display::BrightnessOverride{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Display::BrightnessOverride) consume_Windows_Graphics_Display_IBrightnessOverrideStatics<D>::GetForCurrentView() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IBrightnessOverrideStatics)->GetForCurrentView(&value));
        return llm::OS::Graphics::Display::BrightnessOverride{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Graphics_Display_IBrightnessOverrideStatics<D>::SaveForSystemAsync(llm::OS::Graphics::Display::BrightnessOverride const& value) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IBrightnessOverrideStatics)->SaveForSystemAsync(*(void**)(&value), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Display::DisplayColorOverrideScenario) consume_Windows_Graphics_Display_IColorOverrideSettings<D>::DesiredDisplayColorOverrideScenario() const
    {
        llm::OS::Graphics::Display::DisplayColorOverrideScenario value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IColorOverrideSettings)->get_DesiredDisplayColorOverrideScenario(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Display::ColorOverrideSettings) consume_Windows_Graphics_Display_IColorOverrideSettingsStatics<D>::CreateFromDisplayColorOverrideScenario(llm::OS::Graphics::Display::DisplayColorOverrideScenario const& overrideScenario) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IColorOverrideSettingsStatics)->CreateFromDisplayColorOverrideScenario(static_cast<int32_t>(overrideScenario), &result));
        return llm::OS::Graphics::Display::ColorOverrideSettings{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Display::ColorOverrideSettings) consume_Windows_Graphics_Display_IDisplayEnhancementOverride<D>::ColorOverrideSettings() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayEnhancementOverride)->get_ColorOverrideSettings(&value));
        return llm::OS::Graphics::Display::ColorOverrideSettings{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Display_IDisplayEnhancementOverride<D>::ColorOverrideSettings(llm::OS::Graphics::Display::ColorOverrideSettings const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayEnhancementOverride)->put_ColorOverrideSettings(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Display::BrightnessOverrideSettings) consume_Windows_Graphics_Display_IDisplayEnhancementOverride<D>::BrightnessOverrideSettings() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayEnhancementOverride)->get_BrightnessOverrideSettings(&value));
        return llm::OS::Graphics::Display::BrightnessOverrideSettings{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Display_IDisplayEnhancementOverride<D>::BrightnessOverrideSettings(llm::OS::Graphics::Display::BrightnessOverrideSettings const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayEnhancementOverride)->put_BrightnessOverrideSettings(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Display_IDisplayEnhancementOverride<D>::CanOverride() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayEnhancementOverride)->get_CanOverride(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Display_IDisplayEnhancementOverride<D>::IsOverrideActive() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayEnhancementOverride)->get_IsOverrideActive(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Display::DisplayEnhancementOverrideCapabilities) consume_Windows_Graphics_Display_IDisplayEnhancementOverride<D>::GetCurrentDisplayEnhancementOverrideCapabilities() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayEnhancementOverride)->GetCurrentDisplayEnhancementOverrideCapabilities(&value));
        return llm::OS::Graphics::Display::DisplayEnhancementOverrideCapabilities{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Display_IDisplayEnhancementOverride<D>::RequestOverride() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayEnhancementOverride)->RequestOverride());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Display_IDisplayEnhancementOverride<D>::StopOverride() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayEnhancementOverride)->StopOverride());
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Graphics_Display_IDisplayEnhancementOverride<D>::CanOverrideChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::DisplayEnhancementOverride, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayEnhancementOverride)->add_CanOverrideChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Graphics_Display_IDisplayEnhancementOverride<D>::CanOverrideChanged_revoker consume_Windows_Graphics_Display_IDisplayEnhancementOverride<D>::CanOverrideChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::DisplayEnhancementOverride, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, CanOverrideChanged_revoker>(this, CanOverrideChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Display_IDisplayEnhancementOverride<D>::CanOverrideChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayEnhancementOverride)->remove_CanOverrideChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Graphics_Display_IDisplayEnhancementOverride<D>::IsOverrideActiveChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::DisplayEnhancementOverride, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayEnhancementOverride)->add_IsOverrideActiveChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Graphics_Display_IDisplayEnhancementOverride<D>::IsOverrideActiveChanged_revoker consume_Windows_Graphics_Display_IDisplayEnhancementOverride<D>::IsOverrideActiveChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::DisplayEnhancementOverride, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, IsOverrideActiveChanged_revoker>(this, IsOverrideActiveChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Display_IDisplayEnhancementOverride<D>::IsOverrideActiveChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayEnhancementOverride)->remove_IsOverrideActiveChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Graphics_Display_IDisplayEnhancementOverride<D>::DisplayEnhancementOverrideCapabilitiesChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::DisplayEnhancementOverride, llm::OS::Graphics::Display::DisplayEnhancementOverrideCapabilitiesChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayEnhancementOverride)->add_DisplayEnhancementOverrideCapabilitiesChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Graphics_Display_IDisplayEnhancementOverride<D>::DisplayEnhancementOverrideCapabilitiesChanged_revoker consume_Windows_Graphics_Display_IDisplayEnhancementOverride<D>::DisplayEnhancementOverrideCapabilitiesChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::DisplayEnhancementOverride, llm::OS::Graphics::Display::DisplayEnhancementOverrideCapabilitiesChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, DisplayEnhancementOverrideCapabilitiesChanged_revoker>(this, DisplayEnhancementOverrideCapabilitiesChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Display_IDisplayEnhancementOverride<D>::DisplayEnhancementOverrideCapabilitiesChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayEnhancementOverride)->remove_DisplayEnhancementOverrideCapabilitiesChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Display_IDisplayEnhancementOverrideCapabilities<D>::IsBrightnessControlSupported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayEnhancementOverrideCapabilities)->get_IsBrightnessControlSupported(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Display_IDisplayEnhancementOverrideCapabilities<D>::IsBrightnessNitsControlSupported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayEnhancementOverrideCapabilities)->get_IsBrightnessNitsControlSupported(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Display::NitRange>) consume_Windows_Graphics_Display_IDisplayEnhancementOverrideCapabilities<D>::GetSupportedNitRanges() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayEnhancementOverrideCapabilities)->GetSupportedNitRanges(&result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Display::NitRange>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Display::DisplayEnhancementOverrideCapabilities) consume_Windows_Graphics_Display_IDisplayEnhancementOverrideCapabilitiesChangedEventArgs<D>::Capabilities() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayEnhancementOverrideCapabilitiesChangedEventArgs)->get_Capabilities(&value));
        return llm::OS::Graphics::Display::DisplayEnhancementOverrideCapabilities{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Display::DisplayEnhancementOverride) consume_Windows_Graphics_Display_IDisplayEnhancementOverrideStatics<D>::GetForCurrentView() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayEnhancementOverrideStatics)->GetForCurrentView(&result));
        return llm::OS::Graphics::Display::DisplayEnhancementOverride{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Display::DisplayOrientations) consume_Windows_Graphics_Display_IDisplayInformation<D>::CurrentOrientation() const
    {
        llm::OS::Graphics::Display::DisplayOrientations value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayInformation)->get_CurrentOrientation(reinterpret_cast<uint32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Display::DisplayOrientations) consume_Windows_Graphics_Display_IDisplayInformation<D>::NativeOrientation() const
    {
        llm::OS::Graphics::Display::DisplayOrientations value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayInformation)->get_NativeOrientation(reinterpret_cast<uint32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Graphics_Display_IDisplayInformation<D>::OrientationChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::DisplayInformation, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayInformation)->add_OrientationChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Graphics_Display_IDisplayInformation<D>::OrientationChanged_revoker consume_Windows_Graphics_Display_IDisplayInformation<D>::OrientationChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::DisplayInformation, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, OrientationChanged_revoker>(this, OrientationChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Display_IDisplayInformation<D>::OrientationChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayInformation)->remove_OrientationChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Display::ResolutionScale) consume_Windows_Graphics_Display_IDisplayInformation<D>::ResolutionScale() const
    {
        llm::OS::Graphics::Display::ResolutionScale value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayInformation)->get_ResolutionScale(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_Graphics_Display_IDisplayInformation<D>::LogicalDpi() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayInformation)->get_LogicalDpi(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_Graphics_Display_IDisplayInformation<D>::RawDpiX() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayInformation)->get_RawDpiX(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_Graphics_Display_IDisplayInformation<D>::RawDpiY() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayInformation)->get_RawDpiY(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Graphics_Display_IDisplayInformation<D>::DpiChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::DisplayInformation, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayInformation)->add_DpiChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Graphics_Display_IDisplayInformation<D>::DpiChanged_revoker consume_Windows_Graphics_Display_IDisplayInformation<D>::DpiChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::DisplayInformation, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, DpiChanged_revoker>(this, DpiChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Display_IDisplayInformation<D>::DpiChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayInformation)->remove_DpiChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Display_IDisplayInformation<D>::StereoEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayInformation)->get_StereoEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Graphics_Display_IDisplayInformation<D>::StereoEnabledChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::DisplayInformation, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayInformation)->add_StereoEnabledChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Graphics_Display_IDisplayInformation<D>::StereoEnabledChanged_revoker consume_Windows_Graphics_Display_IDisplayInformation<D>::StereoEnabledChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::DisplayInformation, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, StereoEnabledChanged_revoker>(this, StereoEnabledChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Display_IDisplayInformation<D>::StereoEnabledChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayInformation)->remove_StereoEnabledChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IRandomAccessStream>) consume_Windows_Graphics_Display_IDisplayInformation<D>::GetColorProfileAsync() const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayInformation)->GetColorProfileAsync(&asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IRandomAccessStream>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Graphics_Display_IDisplayInformation<D>::ColorProfileChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::DisplayInformation, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayInformation)->add_ColorProfileChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Graphics_Display_IDisplayInformation<D>::ColorProfileChanged_revoker consume_Windows_Graphics_Display_IDisplayInformation<D>::ColorProfileChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::DisplayInformation, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, ColorProfileChanged_revoker>(this, ColorProfileChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Display_IDisplayInformation<D>::ColorProfileChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayInformation)->remove_ColorProfileChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Graphics_Display_IDisplayInformation2<D>::RawPixelsPerViewPixel() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayInformation2)->get_RawPixelsPerViewPixel(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Graphics_Display_IDisplayInformation3<D>::DiagonalSizeInInches() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayInformation3)->get_DiagonalSizeInInches(&value));
        return llm::OS::Foundation::IReference<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Graphics_Display_IDisplayInformation4<D>::ScreenWidthInRawPixels() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayInformation4)->get_ScreenWidthInRawPixels(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Graphics_Display_IDisplayInformation4<D>::ScreenHeightInRawPixels() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayInformation4)->get_ScreenHeightInRawPixels(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Display::AdvancedColorInfo) consume_Windows_Graphics_Display_IDisplayInformation5<D>::GetAdvancedColorInfo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayInformation5)->GetAdvancedColorInfo(&value));
        return llm::OS::Graphics::Display::AdvancedColorInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Graphics_Display_IDisplayInformation5<D>::AdvancedColorInfoChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::DisplayInformation, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayInformation5)->add_AdvancedColorInfoChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Graphics_Display_IDisplayInformation5<D>::AdvancedColorInfoChanged_revoker consume_Windows_Graphics_Display_IDisplayInformation5<D>::AdvancedColorInfoChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::DisplayInformation, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, AdvancedColorInfoChanged_revoker>(this, AdvancedColorInfoChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Display_IDisplayInformation5<D>::AdvancedColorInfoChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayInformation5)->remove_AdvancedColorInfoChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Display::DisplayInformation) consume_Windows_Graphics_Display_IDisplayInformationStatics<D>::GetForCurrentView() const
    {
        void* current{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayInformationStatics)->GetForCurrentView(&current));
        return llm::OS::Graphics::Display::DisplayInformation{ current, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Display::DisplayOrientations) consume_Windows_Graphics_Display_IDisplayInformationStatics<D>::AutoRotationPreferences() const
    {
        llm::OS::Graphics::Display::DisplayOrientations value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayInformationStatics)->get_AutoRotationPreferences(reinterpret_cast<uint32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Display_IDisplayInformationStatics<D>::AutoRotationPreferences(llm::OS::Graphics::Display::DisplayOrientations const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayInformationStatics)->put_AutoRotationPreferences(static_cast<uint32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Graphics_Display_IDisplayInformationStatics<D>::DisplayContentsInvalidated(llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::DisplayInformation, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayInformationStatics)->add_DisplayContentsInvalidated(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Graphics_Display_IDisplayInformationStatics<D>::DisplayContentsInvalidated_revoker consume_Windows_Graphics_Display_IDisplayInformationStatics<D>::DisplayContentsInvalidated(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::DisplayInformation, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, DisplayContentsInvalidated_revoker>(this, DisplayContentsInvalidated(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Display_IDisplayInformationStatics<D>::DisplayContentsInvalidated(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayInformationStatics)->remove_DisplayContentsInvalidated(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Display::DisplayOrientations) consume_Windows_Graphics_Display_IDisplayPropertiesStatics<D>::CurrentOrientation() const
    {
        llm::OS::Graphics::Display::DisplayOrientations value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayPropertiesStatics)->get_CurrentOrientation(reinterpret_cast<uint32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Display::DisplayOrientations) consume_Windows_Graphics_Display_IDisplayPropertiesStatics<D>::NativeOrientation() const
    {
        llm::OS::Graphics::Display::DisplayOrientations value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayPropertiesStatics)->get_NativeOrientation(reinterpret_cast<uint32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Display::DisplayOrientations) consume_Windows_Graphics_Display_IDisplayPropertiesStatics<D>::AutoRotationPreferences() const
    {
        llm::OS::Graphics::Display::DisplayOrientations value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayPropertiesStatics)->get_AutoRotationPreferences(reinterpret_cast<uint32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Display_IDisplayPropertiesStatics<D>::AutoRotationPreferences(llm::OS::Graphics::Display::DisplayOrientations const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayPropertiesStatics)->put_AutoRotationPreferences(static_cast<uint32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Graphics_Display_IDisplayPropertiesStatics<D>::OrientationChanged(llm::OS::Graphics::Display::DisplayPropertiesEventHandler const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayPropertiesStatics)->add_OrientationChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Graphics_Display_IDisplayPropertiesStatics<D>::OrientationChanged_revoker consume_Windows_Graphics_Display_IDisplayPropertiesStatics<D>::OrientationChanged(auto_revoke_t, llm::OS::Graphics::Display::DisplayPropertiesEventHandler const& handler) const
    {
        return impl::make_event_revoker<D, OrientationChanged_revoker>(this, OrientationChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Display_IDisplayPropertiesStatics<D>::OrientationChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayPropertiesStatics)->remove_OrientationChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Display::ResolutionScale) consume_Windows_Graphics_Display_IDisplayPropertiesStatics<D>::ResolutionScale() const
    {
        llm::OS::Graphics::Display::ResolutionScale value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayPropertiesStatics)->get_ResolutionScale(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_Graphics_Display_IDisplayPropertiesStatics<D>::LogicalDpi() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayPropertiesStatics)->get_LogicalDpi(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Graphics_Display_IDisplayPropertiesStatics<D>::LogicalDpiChanged(llm::OS::Graphics::Display::DisplayPropertiesEventHandler const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayPropertiesStatics)->add_LogicalDpiChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Graphics_Display_IDisplayPropertiesStatics<D>::LogicalDpiChanged_revoker consume_Windows_Graphics_Display_IDisplayPropertiesStatics<D>::LogicalDpiChanged(auto_revoke_t, llm::OS::Graphics::Display::DisplayPropertiesEventHandler const& handler) const
    {
        return impl::make_event_revoker<D, LogicalDpiChanged_revoker>(this, LogicalDpiChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Display_IDisplayPropertiesStatics<D>::LogicalDpiChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayPropertiesStatics)->remove_LogicalDpiChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Display_IDisplayPropertiesStatics<D>::StereoEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayPropertiesStatics)->get_StereoEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Graphics_Display_IDisplayPropertiesStatics<D>::StereoEnabledChanged(llm::OS::Graphics::Display::DisplayPropertiesEventHandler const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayPropertiesStatics)->add_StereoEnabledChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Graphics_Display_IDisplayPropertiesStatics<D>::StereoEnabledChanged_revoker consume_Windows_Graphics_Display_IDisplayPropertiesStatics<D>::StereoEnabledChanged(auto_revoke_t, llm::OS::Graphics::Display::DisplayPropertiesEventHandler const& handler) const
    {
        return impl::make_event_revoker<D, StereoEnabledChanged_revoker>(this, StereoEnabledChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Display_IDisplayPropertiesStatics<D>::StereoEnabledChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayPropertiesStatics)->remove_StereoEnabledChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IRandomAccessStream>) consume_Windows_Graphics_Display_IDisplayPropertiesStatics<D>::GetColorProfileAsync() const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayPropertiesStatics)->GetColorProfileAsync(&asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IRandomAccessStream>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Graphics_Display_IDisplayPropertiesStatics<D>::ColorProfileChanged(llm::OS::Graphics::Display::DisplayPropertiesEventHandler const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayPropertiesStatics)->add_ColorProfileChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Graphics_Display_IDisplayPropertiesStatics<D>::ColorProfileChanged_revoker consume_Windows_Graphics_Display_IDisplayPropertiesStatics<D>::ColorProfileChanged(auto_revoke_t, llm::OS::Graphics::Display::DisplayPropertiesEventHandler const& handler) const
    {
        return impl::make_event_revoker<D, ColorProfileChanged_revoker>(this, ColorProfileChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Display_IDisplayPropertiesStatics<D>::ColorProfileChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayPropertiesStatics)->remove_ColorProfileChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Graphics_Display_IDisplayPropertiesStatics<D>::DisplayContentsInvalidated(llm::OS::Graphics::Display::DisplayPropertiesEventHandler const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayPropertiesStatics)->add_DisplayContentsInvalidated(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Graphics_Display_IDisplayPropertiesStatics<D>::DisplayContentsInvalidated_revoker consume_Windows_Graphics_Display_IDisplayPropertiesStatics<D>::DisplayContentsInvalidated(auto_revoke_t, llm::OS::Graphics::Display::DisplayPropertiesEventHandler const& handler) const
    {
        return impl::make_event_revoker<D, DisplayContentsInvalidated_revoker>(this, DisplayContentsInvalidated(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Display_IDisplayPropertiesStatics<D>::DisplayContentsInvalidated(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayPropertiesStatics)->remove_DisplayContentsInvalidated(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(com_array<llm::OS::Graphics::DisplayId>) consume_Windows_Graphics_Display_IDisplayServicesStatics<D>::FindAll() const
    {
        uint32_t result_impl_size{};
        struct struct_Windows_Graphics_DisplayId* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::IDisplayServicesStatics)->FindAll(&result_impl_size, &result));
        return com_array<llm::OS::Graphics::DisplayId>{ result, result_impl_size, take_ownership_from_abi };
    }
    template <typename H> struct delegate<llm::OS::Graphics::Display::DisplayPropertiesEventHandler, H> final : implements_delegate<llm::OS::Graphics::Display::DisplayPropertiesEventHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::Graphics::Display::DisplayPropertiesEventHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* sender) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&sender));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Display::IAdvancedColorInfo> : produce_base<D, llm::OS::Graphics::Display::IAdvancedColorInfo>
    {
        int32_t __stdcall get_CurrentAdvancedColorKind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Display::AdvancedColorKind>(this->shim().CurrentAdvancedColorKind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RedPrimary(llm::OS::Foundation::Point* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Point>(this->shim().RedPrimary());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_GreenPrimary(llm::OS::Foundation::Point* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Point>(this->shim().GreenPrimary());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BluePrimary(llm::OS::Foundation::Point* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Point>(this->shim().BluePrimary());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WhitePoint(llm::OS::Foundation::Point* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Point>(this->shim().WhitePoint());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxLuminanceInNits(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().MaxLuminanceInNits());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MinLuminanceInNits(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().MinLuminanceInNits());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxAverageFullFrameLuminanceInNits(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().MaxAverageFullFrameLuminanceInNits());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SdrWhiteLevelInNits(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().SdrWhiteLevelInNits());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsHdrMetadataFormatCurrentlySupported(int32_t format, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsHdrMetadataFormatCurrentlySupported(*reinterpret_cast<llm::OS::Graphics::Display::HdrMetadataFormat const*>(&format)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsAdvancedColorKindAvailable(int32_t kind, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsAdvancedColorKindAvailable(*reinterpret_cast<llm::OS::Graphics::Display::AdvancedColorKind const*>(&kind)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Display::IBrightnessOverride> : produce_base<D, llm::OS::Graphics::Display::IBrightnessOverride>
    {
        int32_t __stdcall get_IsSupported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsOverrideActive(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsOverrideActive());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BrightnessLevel(double* level) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *level = detach_from<double>(this->shim().BrightnessLevel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetBrightnessLevel(double brightnessLevel, uint32_t options) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetBrightnessLevel(brightnessLevel, *reinterpret_cast<llm::OS::Graphics::Display::DisplayBrightnessOverrideOptions const*>(&options));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetBrightnessScenario(int32_t scenario, uint32_t options) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetBrightnessScenario(*reinterpret_cast<llm::OS::Graphics::Display::DisplayBrightnessScenario const*>(&scenario), *reinterpret_cast<llm::OS::Graphics::Display::DisplayBrightnessOverrideOptions const*>(&options));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetLevelForScenario(int32_t scenario, double* brightnessLevel) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *brightnessLevel = detach_from<double>(this->shim().GetLevelForScenario(*reinterpret_cast<llm::OS::Graphics::Display::DisplayBrightnessScenario const*>(&scenario)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StartOverride() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartOverride();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StopOverride() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StopOverride();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_IsSupportedChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().IsSupportedChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::BrightnessOverride, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_IsSupportedChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsSupportedChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_IsOverrideActiveChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().IsOverrideActiveChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::BrightnessOverride, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_IsOverrideActiveChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsOverrideActiveChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_BrightnessLevelChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().BrightnessLevelChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::BrightnessOverride, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_BrightnessLevelChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BrightnessLevelChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Display::IBrightnessOverrideSettings> : produce_base<D, llm::OS::Graphics::Display::IBrightnessOverrideSettings>
    {
        int32_t __stdcall get_DesiredLevel(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().DesiredLevel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DesiredNits(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().DesiredNits());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Display::IBrightnessOverrideSettingsStatics> : produce_base<D, llm::OS::Graphics::Display::IBrightnessOverrideSettingsStatics>
    {
        int32_t __stdcall CreateFromLevel(double level, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Graphics::Display::BrightnessOverrideSettings>(this->shim().CreateFromLevel(level));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromNits(float nits, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Graphics::Display::BrightnessOverrideSettings>(this->shim().CreateFromNits(nits));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromDisplayBrightnessOverrideScenario(int32_t overrideScenario, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Graphics::Display::BrightnessOverrideSettings>(this->shim().CreateFromDisplayBrightnessOverrideScenario(*reinterpret_cast<llm::OS::Graphics::Display::DisplayBrightnessOverrideScenario const*>(&overrideScenario)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Display::IBrightnessOverrideStatics> : produce_base<D, llm::OS::Graphics::Display::IBrightnessOverrideStatics>
    {
        int32_t __stdcall GetDefaultForSystem(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Display::BrightnessOverride>(this->shim().GetDefaultForSystem());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetForCurrentView(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Display::BrightnessOverride>(this->shim().GetForCurrentView());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SaveForSystemAsync(void* value, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().SaveForSystemAsync(*reinterpret_cast<llm::OS::Graphics::Display::BrightnessOverride const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Display::IColorOverrideSettings> : produce_base<D, llm::OS::Graphics::Display::IColorOverrideSettings>
    {
        int32_t __stdcall get_DesiredDisplayColorOverrideScenario(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Display::DisplayColorOverrideScenario>(this->shim().DesiredDisplayColorOverrideScenario());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Display::IColorOverrideSettingsStatics> : produce_base<D, llm::OS::Graphics::Display::IColorOverrideSettingsStatics>
    {
        int32_t __stdcall CreateFromDisplayColorOverrideScenario(int32_t overrideScenario, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Graphics::Display::ColorOverrideSettings>(this->shim().CreateFromDisplayColorOverrideScenario(*reinterpret_cast<llm::OS::Graphics::Display::DisplayColorOverrideScenario const*>(&overrideScenario)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Display::IDisplayEnhancementOverride> : produce_base<D, llm::OS::Graphics::Display::IDisplayEnhancementOverride>
    {
        int32_t __stdcall get_ColorOverrideSettings(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Display::ColorOverrideSettings>(this->shim().ColorOverrideSettings());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ColorOverrideSettings(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ColorOverrideSettings(*reinterpret_cast<llm::OS::Graphics::Display::ColorOverrideSettings const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BrightnessOverrideSettings(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Display::BrightnessOverrideSettings>(this->shim().BrightnessOverrideSettings());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BrightnessOverrideSettings(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BrightnessOverrideSettings(*reinterpret_cast<llm::OS::Graphics::Display::BrightnessOverrideSettings const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CanOverride(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CanOverride());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsOverrideActive(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsOverrideActive());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetCurrentDisplayEnhancementOverrideCapabilities(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Display::DisplayEnhancementOverrideCapabilities>(this->shim().GetCurrentDisplayEnhancementOverrideCapabilities());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestOverride() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestOverride();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StopOverride() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StopOverride();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_CanOverrideChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().CanOverrideChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::DisplayEnhancementOverride, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_CanOverrideChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanOverrideChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_IsOverrideActiveChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().IsOverrideActiveChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::DisplayEnhancementOverride, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_IsOverrideActiveChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsOverrideActiveChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_DisplayEnhancementOverrideCapabilitiesChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().DisplayEnhancementOverrideCapabilitiesChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::DisplayEnhancementOverride, llm::OS::Graphics::Display::DisplayEnhancementOverrideCapabilitiesChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_DisplayEnhancementOverrideCapabilitiesChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayEnhancementOverrideCapabilitiesChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Display::IDisplayEnhancementOverrideCapabilities> : produce_base<D, llm::OS::Graphics::Display::IDisplayEnhancementOverrideCapabilities>
    {
        int32_t __stdcall get_IsBrightnessControlSupported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsBrightnessControlSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsBrightnessNitsControlSupported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsBrightnessNitsControlSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSupportedNitRanges(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Display::NitRange>>(this->shim().GetSupportedNitRanges());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Display::IDisplayEnhancementOverrideCapabilitiesChangedEventArgs> : produce_base<D, llm::OS::Graphics::Display::IDisplayEnhancementOverrideCapabilitiesChangedEventArgs>
    {
        int32_t __stdcall get_Capabilities(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Display::DisplayEnhancementOverrideCapabilities>(this->shim().Capabilities());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Display::IDisplayEnhancementOverrideStatics> : produce_base<D, llm::OS::Graphics::Display::IDisplayEnhancementOverrideStatics>
    {
        int32_t __stdcall GetForCurrentView(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Graphics::Display::DisplayEnhancementOverride>(this->shim().GetForCurrentView());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Display::IDisplayInformation> : produce_base<D, llm::OS::Graphics::Display::IDisplayInformation>
    {
        int32_t __stdcall get_CurrentOrientation(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Display::DisplayOrientations>(this->shim().CurrentOrientation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NativeOrientation(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Display::DisplayOrientations>(this->shim().NativeOrientation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_OrientationChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().OrientationChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::DisplayInformation, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_OrientationChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OrientationChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_ResolutionScale(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Display::ResolutionScale>(this->shim().ResolutionScale());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LogicalDpi(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().LogicalDpi());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RawDpiX(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().RawDpiX());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RawDpiY(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().RawDpiY());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_DpiChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().DpiChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::DisplayInformation, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_DpiChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DpiChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_StereoEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().StereoEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_StereoEnabledChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().StereoEnabledChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::DisplayInformation, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_StereoEnabledChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StereoEnabledChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall GetColorProfileAsync(void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IRandomAccessStream>>(this->shim().GetColorProfileAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_ColorProfileChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ColorProfileChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::DisplayInformation, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ColorProfileChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ColorProfileChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Display::IDisplayInformation2> : produce_base<D, llm::OS::Graphics::Display::IDisplayInformation2>
    {
        int32_t __stdcall get_RawPixelsPerViewPixel(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().RawPixelsPerViewPixel());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Display::IDisplayInformation3> : produce_base<D, llm::OS::Graphics::Display::IDisplayInformation3>
    {
        int32_t __stdcall get_DiagonalSizeInInches(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().DiagonalSizeInInches());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Display::IDisplayInformation4> : produce_base<D, llm::OS::Graphics::Display::IDisplayInformation4>
    {
        int32_t __stdcall get_ScreenWidthInRawPixels(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().ScreenWidthInRawPixels());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ScreenHeightInRawPixels(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().ScreenHeightInRawPixels());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Display::IDisplayInformation5> : produce_base<D, llm::OS::Graphics::Display::IDisplayInformation5>
    {
        int32_t __stdcall GetAdvancedColorInfo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Display::AdvancedColorInfo>(this->shim().GetAdvancedColorInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_AdvancedColorInfoChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().AdvancedColorInfoChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::DisplayInformation, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AdvancedColorInfoChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AdvancedColorInfoChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Display::IDisplayInformationStatics> : produce_base<D, llm::OS::Graphics::Display::IDisplayInformationStatics>
    {
        int32_t __stdcall GetForCurrentView(void** current) noexcept final try
        {
            clear_abi(current);
            typename D::abi_guard guard(this->shim());
            *current = detach_from<llm::OS::Graphics::Display::DisplayInformation>(this->shim().GetForCurrentView());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AutoRotationPreferences(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Display::DisplayOrientations>(this->shim().AutoRotationPreferences());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AutoRotationPreferences(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutoRotationPreferences(*reinterpret_cast<llm::OS::Graphics::Display::DisplayOrientations const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_DisplayContentsInvalidated(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().DisplayContentsInvalidated(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::DisplayInformation, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_DisplayContentsInvalidated(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayContentsInvalidated(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Display::IDisplayPropertiesStatics> : produce_base<D, llm::OS::Graphics::Display::IDisplayPropertiesStatics>
    {
        int32_t __stdcall get_CurrentOrientation(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Display::DisplayOrientations>(this->shim().CurrentOrientation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NativeOrientation(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Display::DisplayOrientations>(this->shim().NativeOrientation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AutoRotationPreferences(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Display::DisplayOrientations>(this->shim().AutoRotationPreferences());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AutoRotationPreferences(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutoRotationPreferences(*reinterpret_cast<llm::OS::Graphics::Display::DisplayOrientations const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_OrientationChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().OrientationChanged(*reinterpret_cast<llm::OS::Graphics::Display::DisplayPropertiesEventHandler const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_OrientationChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OrientationChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_ResolutionScale(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Display::ResolutionScale>(this->shim().ResolutionScale());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LogicalDpi(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().LogicalDpi());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_LogicalDpiChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().LogicalDpiChanged(*reinterpret_cast<llm::OS::Graphics::Display::DisplayPropertiesEventHandler const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_LogicalDpiChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LogicalDpiChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_StereoEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().StereoEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_StereoEnabledChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().StereoEnabledChanged(*reinterpret_cast<llm::OS::Graphics::Display::DisplayPropertiesEventHandler const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_StereoEnabledChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StereoEnabledChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall GetColorProfileAsync(void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IRandomAccessStream>>(this->shim().GetColorProfileAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_ColorProfileChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ColorProfileChanged(*reinterpret_cast<llm::OS::Graphics::Display::DisplayPropertiesEventHandler const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ColorProfileChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ColorProfileChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_DisplayContentsInvalidated(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().DisplayContentsInvalidated(*reinterpret_cast<llm::OS::Graphics::Display::DisplayPropertiesEventHandler const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_DisplayContentsInvalidated(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayContentsInvalidated(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Display::IDisplayServices> : produce_base<D, llm::OS::Graphics::Display::IDisplayServices>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Display::IDisplayServicesStatics> : produce_base<D, llm::OS::Graphics::Display::IDisplayServicesStatics>
    {
        int32_t __stdcall FindAll(uint32_t* __resultSize, struct struct_Windows_Graphics_DisplayId** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            std::tie(*__resultSize, *result) = detach_abi(this->shim().FindAll());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Graphics::Display
{
    constexpr auto operator|(DisplayBrightnessOverrideOptions const left, DisplayBrightnessOverrideOptions const right) noexcept
    {
        return static_cast<DisplayBrightnessOverrideOptions>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(DisplayBrightnessOverrideOptions& left, DisplayBrightnessOverrideOptions const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(DisplayBrightnessOverrideOptions const left, DisplayBrightnessOverrideOptions const right) noexcept
    {
        return static_cast<DisplayBrightnessOverrideOptions>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(DisplayBrightnessOverrideOptions& left, DisplayBrightnessOverrideOptions const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(DisplayBrightnessOverrideOptions const value) noexcept
    {
        return static_cast<DisplayBrightnessOverrideOptions>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(DisplayBrightnessOverrideOptions const left, DisplayBrightnessOverrideOptions const right) noexcept
    {
        return static_cast<DisplayBrightnessOverrideOptions>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(DisplayBrightnessOverrideOptions& left, DisplayBrightnessOverrideOptions const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    constexpr auto operator|(DisplayOrientations const left, DisplayOrientations const right) noexcept
    {
        return static_cast<DisplayOrientations>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(DisplayOrientations& left, DisplayOrientations const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(DisplayOrientations const left, DisplayOrientations const right) noexcept
    {
        return static_cast<DisplayOrientations>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(DisplayOrientations& left, DisplayOrientations const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(DisplayOrientations const value) noexcept
    {
        return static_cast<DisplayOrientations>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(DisplayOrientations const left, DisplayOrientations const right) noexcept
    {
        return static_cast<DisplayOrientations>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(DisplayOrientations& left, DisplayOrientations const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    inline auto BrightnessOverride::GetDefaultForSystem()
    {
        return impl::call_factory_cast<llm::OS::Graphics::Display::BrightnessOverride(*)(IBrightnessOverrideStatics const&), BrightnessOverride, IBrightnessOverrideStatics>([](IBrightnessOverrideStatics const& f) { return f.GetDefaultForSystem(); });
    }
    inline auto BrightnessOverride::GetForCurrentView()
    {
        return impl::call_factory_cast<llm::OS::Graphics::Display::BrightnessOverride(*)(IBrightnessOverrideStatics const&), BrightnessOverride, IBrightnessOverrideStatics>([](IBrightnessOverrideStatics const& f) { return f.GetForCurrentView(); });
    }
    inline auto BrightnessOverride::SaveForSystemAsync(llm::OS::Graphics::Display::BrightnessOverride const& value)
    {
        return impl::call_factory<BrightnessOverride, IBrightnessOverrideStatics>([&](IBrightnessOverrideStatics const& f) { return f.SaveForSystemAsync(value); });
    }
    inline auto BrightnessOverrideSettings::CreateFromLevel(double level)
    {
        return impl::call_factory<BrightnessOverrideSettings, IBrightnessOverrideSettingsStatics>([&](IBrightnessOverrideSettingsStatics const& f) { return f.CreateFromLevel(level); });
    }
    inline auto BrightnessOverrideSettings::CreateFromNits(float nits)
    {
        return impl::call_factory<BrightnessOverrideSettings, IBrightnessOverrideSettingsStatics>([&](IBrightnessOverrideSettingsStatics const& f) { return f.CreateFromNits(nits); });
    }
    inline auto BrightnessOverrideSettings::CreateFromDisplayBrightnessOverrideScenario(llm::OS::Graphics::Display::DisplayBrightnessOverrideScenario const& overrideScenario)
    {
        return impl::call_factory<BrightnessOverrideSettings, IBrightnessOverrideSettingsStatics>([&](IBrightnessOverrideSettingsStatics const& f) { return f.CreateFromDisplayBrightnessOverrideScenario(overrideScenario); });
    }
    inline auto ColorOverrideSettings::CreateFromDisplayColorOverrideScenario(llm::OS::Graphics::Display::DisplayColorOverrideScenario const& overrideScenario)
    {
        return impl::call_factory<ColorOverrideSettings, IColorOverrideSettingsStatics>([&](IColorOverrideSettingsStatics const& f) { return f.CreateFromDisplayColorOverrideScenario(overrideScenario); });
    }
    inline auto DisplayEnhancementOverride::GetForCurrentView()
    {
        return impl::call_factory_cast<llm::OS::Graphics::Display::DisplayEnhancementOverride(*)(IDisplayEnhancementOverrideStatics const&), DisplayEnhancementOverride, IDisplayEnhancementOverrideStatics>([](IDisplayEnhancementOverrideStatics const& f) { return f.GetForCurrentView(); });
    }
    inline auto DisplayInformation::GetForCurrentView()
    {
        return impl::call_factory_cast<llm::OS::Graphics::Display::DisplayInformation(*)(IDisplayInformationStatics const&), DisplayInformation, IDisplayInformationStatics>([](IDisplayInformationStatics const& f) { return f.GetForCurrentView(); });
    }
    inline auto DisplayInformation::AutoRotationPreferences()
    {
        return impl::call_factory_cast<llm::OS::Graphics::Display::DisplayOrientations(*)(IDisplayInformationStatics const&), DisplayInformation, IDisplayInformationStatics>([](IDisplayInformationStatics const& f) { return f.AutoRotationPreferences(); });
    }
    inline auto DisplayInformation::AutoRotationPreferences(llm::OS::Graphics::Display::DisplayOrientations const& value)
    {
        impl::call_factory<DisplayInformation, IDisplayInformationStatics>([&](IDisplayInformationStatics const& f) { return f.AutoRotationPreferences(value); });
    }
    inline auto DisplayInformation::DisplayContentsInvalidated(llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::DisplayInformation, llm::OS::Foundation::IInspectable> const& handler)
    {
        return impl::call_factory<DisplayInformation, IDisplayInformationStatics>([&](IDisplayInformationStatics const& f) { return f.DisplayContentsInvalidated(handler); });
    }
    inline DisplayInformation::DisplayContentsInvalidated_revoker DisplayInformation::DisplayContentsInvalidated(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::DisplayInformation, llm::OS::Foundation::IInspectable> const& handler)
    {
        auto f = get_activation_factory<DisplayInformation, llm::OS::Graphics::Display::IDisplayInformationStatics>();
        return { f, f.DisplayContentsInvalidated(handler) };
    }
    inline auto DisplayInformation::DisplayContentsInvalidated(llm::event_token const& token)
    {
        impl::call_factory<DisplayInformation, IDisplayInformationStatics>([&](IDisplayInformationStatics const& f) { return f.DisplayContentsInvalidated(token); });
    }
    inline auto DisplayProperties::CurrentOrientation()
    {
        return impl::call_factory_cast<llm::OS::Graphics::Display::DisplayOrientations(*)(IDisplayPropertiesStatics const&), DisplayProperties, IDisplayPropertiesStatics>([](IDisplayPropertiesStatics const& f) { return f.CurrentOrientation(); });
    }
    inline auto DisplayProperties::NativeOrientation()
    {
        return impl::call_factory_cast<llm::OS::Graphics::Display::DisplayOrientations(*)(IDisplayPropertiesStatics const&), DisplayProperties, IDisplayPropertiesStatics>([](IDisplayPropertiesStatics const& f) { return f.NativeOrientation(); });
    }
    inline auto DisplayProperties::AutoRotationPreferences()
    {
        return impl::call_factory_cast<llm::OS::Graphics::Display::DisplayOrientations(*)(IDisplayPropertiesStatics const&), DisplayProperties, IDisplayPropertiesStatics>([](IDisplayPropertiesStatics const& f) { return f.AutoRotationPreferences(); });
    }
    inline auto DisplayProperties::AutoRotationPreferences(llm::OS::Graphics::Display::DisplayOrientations const& value)
    {
        impl::call_factory<DisplayProperties, IDisplayPropertiesStatics>([&](IDisplayPropertiesStatics const& f) { return f.AutoRotationPreferences(value); });
    }
    inline auto DisplayProperties::OrientationChanged(llm::OS::Graphics::Display::DisplayPropertiesEventHandler const& handler)
    {
        return impl::call_factory<DisplayProperties, IDisplayPropertiesStatics>([&](IDisplayPropertiesStatics const& f) { return f.OrientationChanged(handler); });
    }
    inline DisplayProperties::OrientationChanged_revoker DisplayProperties::OrientationChanged(auto_revoke_t, llm::OS::Graphics::Display::DisplayPropertiesEventHandler const& handler)
    {
        auto f = get_activation_factory<DisplayProperties, llm::OS::Graphics::Display::IDisplayPropertiesStatics>();
        return { f, f.OrientationChanged(handler) };
    }
    inline auto DisplayProperties::OrientationChanged(llm::event_token const& token)
    {
        impl::call_factory<DisplayProperties, IDisplayPropertiesStatics>([&](IDisplayPropertiesStatics const& f) { return f.OrientationChanged(token); });
    }
    inline auto DisplayProperties::ResolutionScale()
    {
        return impl::call_factory_cast<llm::OS::Graphics::Display::ResolutionScale(*)(IDisplayPropertiesStatics const&), DisplayProperties, IDisplayPropertiesStatics>([](IDisplayPropertiesStatics const& f) { return f.ResolutionScale(); });
    }
    inline auto DisplayProperties::LogicalDpi()
    {
        return impl::call_factory_cast<float(*)(IDisplayPropertiesStatics const&), DisplayProperties, IDisplayPropertiesStatics>([](IDisplayPropertiesStatics const& f) { return f.LogicalDpi(); });
    }
    inline auto DisplayProperties::LogicalDpiChanged(llm::OS::Graphics::Display::DisplayPropertiesEventHandler const& handler)
    {
        return impl::call_factory<DisplayProperties, IDisplayPropertiesStatics>([&](IDisplayPropertiesStatics const& f) { return f.LogicalDpiChanged(handler); });
    }
    inline DisplayProperties::LogicalDpiChanged_revoker DisplayProperties::LogicalDpiChanged(auto_revoke_t, llm::OS::Graphics::Display::DisplayPropertiesEventHandler const& handler)
    {
        auto f = get_activation_factory<DisplayProperties, llm::OS::Graphics::Display::IDisplayPropertiesStatics>();
        return { f, f.LogicalDpiChanged(handler) };
    }
    inline auto DisplayProperties::LogicalDpiChanged(llm::event_token const& token)
    {
        impl::call_factory<DisplayProperties, IDisplayPropertiesStatics>([&](IDisplayPropertiesStatics const& f) { return f.LogicalDpiChanged(token); });
    }
    inline auto DisplayProperties::StereoEnabled()
    {
        return impl::call_factory_cast<bool(*)(IDisplayPropertiesStatics const&), DisplayProperties, IDisplayPropertiesStatics>([](IDisplayPropertiesStatics const& f) { return f.StereoEnabled(); });
    }
    inline auto DisplayProperties::StereoEnabledChanged(llm::OS::Graphics::Display::DisplayPropertiesEventHandler const& handler)
    {
        return impl::call_factory<DisplayProperties, IDisplayPropertiesStatics>([&](IDisplayPropertiesStatics const& f) { return f.StereoEnabledChanged(handler); });
    }
    inline DisplayProperties::StereoEnabledChanged_revoker DisplayProperties::StereoEnabledChanged(auto_revoke_t, llm::OS::Graphics::Display::DisplayPropertiesEventHandler const& handler)
    {
        auto f = get_activation_factory<DisplayProperties, llm::OS::Graphics::Display::IDisplayPropertiesStatics>();
        return { f, f.StereoEnabledChanged(handler) };
    }
    inline auto DisplayProperties::StereoEnabledChanged(llm::event_token const& token)
    {
        impl::call_factory<DisplayProperties, IDisplayPropertiesStatics>([&](IDisplayPropertiesStatics const& f) { return f.StereoEnabledChanged(token); });
    }
    inline auto DisplayProperties::GetColorProfileAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IRandomAccessStream>(*)(IDisplayPropertiesStatics const&), DisplayProperties, IDisplayPropertiesStatics>([](IDisplayPropertiesStatics const& f) { return f.GetColorProfileAsync(); });
    }
    inline auto DisplayProperties::ColorProfileChanged(llm::OS::Graphics::Display::DisplayPropertiesEventHandler const& handler)
    {
        return impl::call_factory<DisplayProperties, IDisplayPropertiesStatics>([&](IDisplayPropertiesStatics const& f) { return f.ColorProfileChanged(handler); });
    }
    inline DisplayProperties::ColorProfileChanged_revoker DisplayProperties::ColorProfileChanged(auto_revoke_t, llm::OS::Graphics::Display::DisplayPropertiesEventHandler const& handler)
    {
        auto f = get_activation_factory<DisplayProperties, llm::OS::Graphics::Display::IDisplayPropertiesStatics>();
        return { f, f.ColorProfileChanged(handler) };
    }
    inline auto DisplayProperties::ColorProfileChanged(llm::event_token const& token)
    {
        impl::call_factory<DisplayProperties, IDisplayPropertiesStatics>([&](IDisplayPropertiesStatics const& f) { return f.ColorProfileChanged(token); });
    }
    inline auto DisplayProperties::DisplayContentsInvalidated(llm::OS::Graphics::Display::DisplayPropertiesEventHandler const& handler)
    {
        return impl::call_factory<DisplayProperties, IDisplayPropertiesStatics>([&](IDisplayPropertiesStatics const& f) { return f.DisplayContentsInvalidated(handler); });
    }
    inline DisplayProperties::DisplayContentsInvalidated_revoker DisplayProperties::DisplayContentsInvalidated(auto_revoke_t, llm::OS::Graphics::Display::DisplayPropertiesEventHandler const& handler)
    {
        auto f = get_activation_factory<DisplayProperties, llm::OS::Graphics::Display::IDisplayPropertiesStatics>();
        return { f, f.DisplayContentsInvalidated(handler) };
    }
    inline auto DisplayProperties::DisplayContentsInvalidated(llm::event_token const& token)
    {
        impl::call_factory<DisplayProperties, IDisplayPropertiesStatics>([&](IDisplayPropertiesStatics const& f) { return f.DisplayContentsInvalidated(token); });
    }
    inline auto DisplayServices::FindAll()
    {
        return impl::call_factory_cast<com_array<llm::OS::Graphics::DisplayId>(*)(IDisplayServicesStatics const&), DisplayServices, IDisplayServicesStatics>([](IDisplayServicesStatics const& f) { return f.FindAll(); });
    }
    template <typename L> DisplayPropertiesEventHandler::DisplayPropertiesEventHandler(L handler) :
        DisplayPropertiesEventHandler(impl::make_delegate<DisplayPropertiesEventHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> DisplayPropertiesEventHandler::DisplayPropertiesEventHandler(F* handler) :
        DisplayPropertiesEventHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> DisplayPropertiesEventHandler::DisplayPropertiesEventHandler(O* object, M method) :
        DisplayPropertiesEventHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> DisplayPropertiesEventHandler::DisplayPropertiesEventHandler(com_ptr<O>&& object, M method) :
        DisplayPropertiesEventHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> DisplayPropertiesEventHandler::DisplayPropertiesEventHandler(weak_ref<O>&& object, M method) :
        DisplayPropertiesEventHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto DisplayPropertiesEventHandler::operator()(llm::OS::Foundation::IInspectable const& sender) const
    {
        check_hresult((*(impl::abi_t<DisplayPropertiesEventHandler>**)this)->Invoke(*(void**)(&sender)));
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Graphics::Display::IAdvancedColorInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::IBrightnessOverride> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::IBrightnessOverrideSettings> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::IBrightnessOverrideSettingsStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::IBrightnessOverrideStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::IColorOverrideSettings> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::IColorOverrideSettingsStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::IDisplayEnhancementOverride> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::IDisplayEnhancementOverrideCapabilities> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::IDisplayEnhancementOverrideCapabilitiesChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::IDisplayEnhancementOverrideStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::IDisplayInformation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::IDisplayInformation2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::IDisplayInformation3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::IDisplayInformation4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::IDisplayInformation5> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::IDisplayInformationStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::IDisplayPropertiesStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::IDisplayServices> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::IDisplayServicesStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::AdvancedColorInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::BrightnessOverride> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::BrightnessOverrideSettings> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::ColorOverrideSettings> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::DisplayEnhancementOverride> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::DisplayEnhancementOverrideCapabilities> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::DisplayEnhancementOverrideCapabilitiesChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::DisplayInformation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::DisplayProperties> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::DisplayServices> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
