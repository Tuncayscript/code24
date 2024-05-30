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
#ifndef LLM_OS_System_Profile_2_H
#define LLM_OS_System_Profile_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.System.Profile.1.h"
LLM_EXPORT namespace llm:OS::System::Profile
{
    struct AnalyticsInfo
    {
        AnalyticsInfo() = delete;
        [[nodiscard]] static auto VersionInfo();
        [[nodiscard]] static auto DeviceForm();
        static auto GetSystemPropertiesAsync(param::async_iterable<hstring> const& attributeNames);
    };
    struct __declspec(empty_bases) AnalyticsVersionInfo : llm:OS::System::Profile::IAnalyticsVersionInfo,
        impl::require<AnalyticsVersionInfo, llm:OS::System::Profile::IAnalyticsVersionInfo2>
    {
        AnalyticsVersionInfo(std::nullptr_t) noexcept {}
        AnalyticsVersionInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Profile::IAnalyticsVersionInfo(ptr, take_ownership_from_abi) {}
    };
    struct AppApplicability
    {
        AppApplicability() = delete;
        static auto GetUnsupportedAppRequirements(param::iterable<hstring> const& capabilities);
    };
    struct EducationSettings
    {
        EducationSettings() = delete;
        [[nodiscard]] static auto IsEducationEnvironment();
    };
    struct HardwareIdentification
    {
        HardwareIdentification() = delete;
        static auto GetPackageSpecificToken(llm:OS::Storage::Streams::IBuffer const& nonce);
    };
    struct __declspec(empty_bases) HardwareToken : llm:OS::System::Profile::IHardwareToken
    {
        HardwareToken(std::nullptr_t) noexcept {}
        HardwareToken(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Profile::IHardwareToken(ptr, take_ownership_from_abi) {}
    };
    struct KnownRetailInfoProperties
    {
        KnownRetailInfoProperties() = delete;
        [[nodiscard]] static auto RetailAccessCode();
        [[nodiscard]] static auto ManufacturerName();
        [[nodiscard]] static auto ModelName();
        [[nodiscard]] static auto DisplayModelName();
        [[nodiscard]] static auto Price();
        [[nodiscard]] static auto IsFeatured();
        [[nodiscard]] static auto FormFactor();
        [[nodiscard]] static auto ScreenSize();
        [[nodiscard]] static auto Weight();
        [[nodiscard]] static auto DisplayDescription();
        [[nodiscard]] static auto BatteryLifeDescription();
        [[nodiscard]] static auto ProcessorDescription();
        [[nodiscard]] static auto Memory();
        [[nodiscard]] static auto StorageDescription();
        [[nodiscard]] static auto GraphicsDescription();
        [[nodiscard]] static auto FrontCameraDescription();
        [[nodiscard]] static auto RearCameraDescription();
        [[nodiscard]] static auto HasNfc();
        [[nodiscard]] static auto HasSdSlot();
        [[nodiscard]] static auto HasOpticalDrive();
        [[nodiscard]] static auto IsOfficeInstalled();
        [[nodiscard]] static auto WindowsEdition();
    };
    struct PlatformDiagnosticsAndUsageDataSettings
    {
        PlatformDiagnosticsAndUsageDataSettings() = delete;
        [[nodiscard]] static auto CollectionLevel();
        static auto CollectionLevelChanged(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using CollectionLevelChanged_revoker = impl::factory_event_revoker<llm:OS::System::Profile::IPlatformDiagnosticsAndUsageDataSettingsStatics, &impl::abi_t<llm:OS::System::Profile::IPlatformDiagnosticsAndUsageDataSettingsStatics>::remove_CollectionLevelChanged>;
        [[nodiscard]] static CollectionLevelChanged_revoker CollectionLevelChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto CollectionLevelChanged(llm::event_token const& token);
        static auto CanCollectDiagnostics(llm:OS::System::Profile::PlatformDataCollectionLevel const& level);
    };
    struct RetailInfo
    {
        RetailInfo() = delete;
        [[nodiscard]] static auto IsDemoModeEnabled();
        [[nodiscard]] static auto Properties();
    };
    struct SharedModeSettings
    {
        SharedModeSettings() = delete;
        [[nodiscard]] static auto IsEnabled();
        [[nodiscard]] static auto ShouldAvoidLocalStorage();
    };
    struct SmartAppControlPolicy
    {
        SmartAppControlPolicy() = delete;
        [[nodiscard]] static auto IsEnabled();
        static auto Changed(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using Changed_revoker = impl::factory_event_revoker<llm:OS::System::Profile::ISmartAppControlPolicyStatics, &impl::abi_t<llm:OS::System::Profile::ISmartAppControlPolicyStatics>::remove_Changed>;
        [[nodiscard]] static Changed_revoker Changed(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto Changed(llm::event_token const& token);
    };
    struct SystemIdentification
    {
        SystemIdentification() = delete;
        static auto GetSystemIdForPublisher();
        static auto GetSystemIdForUser(llm:OS::System::User const& user);
    };
    struct __declspec(empty_bases) SystemIdentificationInfo : llm:OS::System::Profile::ISystemIdentificationInfo
    {
        SystemIdentificationInfo(std::nullptr_t) noexcept {}
        SystemIdentificationInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Profile::ISystemIdentificationInfo(ptr, take_ownership_from_abi) {}
    };
    struct SystemSetupInfo
    {
        SystemSetupInfo() = delete;
        [[nodiscard]] static auto OutOfBoxExperienceState();
        static auto OutOfBoxExperienceStateChanged(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using OutOfBoxExperienceStateChanged_revoker = impl::factory_event_revoker<llm:OS::System::Profile::ISystemSetupInfoStatics, &impl::abi_t<llm:OS::System::Profile::ISystemSetupInfoStatics>::remove_OutOfBoxExperienceStateChanged>;
        [[nodiscard]] static OutOfBoxExperienceStateChanged_revoker OutOfBoxExperienceStateChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto OutOfBoxExperienceStateChanged(llm::event_token const& token);
    };
    struct __declspec(empty_bases) UnsupportedAppRequirement : llm:OS::System::Profile::IUnsupportedAppRequirement
    {
        UnsupportedAppRequirement(std::nullptr_t) noexcept {}
        UnsupportedAppRequirement(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Profile::IUnsupportedAppRequirement(ptr, take_ownership_from_abi) {}
    };
    struct WindowsIntegrityPolicy
    {
        WindowsIntegrityPolicy() = delete;
        [[nodiscard]] static auto IsEnabled();
        [[nodiscard]] static auto IsEnabledForTrial();
        [[nodiscard]] static auto CanDisable();
        [[nodiscard]] static auto IsDisableSupported();
        static auto PolicyChanged(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using PolicyChanged_revoker = impl::factory_event_revoker<llm:OS::System::Profile::IWindowsIntegrityPolicyStatics, &impl::abi_t<llm:OS::System::Profile::IWindowsIntegrityPolicyStatics>::remove_PolicyChanged>;
        [[nodiscard]] static PolicyChanged_revoker PolicyChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto PolicyChanged(llm::event_token const& token);
    };
}
#endif
