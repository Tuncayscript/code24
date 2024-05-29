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
#ifndef LLM_OS_Devices_Sensors_2_H
#define LLM_OS_Devices_Sensors_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Devices.Sensors.1.h"
LLM_EXPORT namespace llm::OS::Devices::Sensors
{
    struct __declspec(empty_bases) Accelerometer : llm::OS::Devices::Sensors::IAccelerometer,
        impl::require<Accelerometer, llm::OS::Devices::Sensors::IAccelerometerDeviceId, llm::OS::Devices::Sensors::IAccelerometer2, llm::OS::Devices::Sensors::IAccelerometer3, llm::OS::Devices::Sensors::IAccelerometer4, llm::OS::Devices::Sensors::IAccelerometer5>
    {
        Accelerometer(std::nullptr_t) noexcept {}
        Accelerometer(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IAccelerometer(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
        static auto GetDefault(llm::OS::Devices::Sensors::AccelerometerReadingType const& readingType);
        static auto FromIdAsync(param::hstring const& deviceId);
        static auto GetDeviceSelector(llm::OS::Devices::Sensors::AccelerometerReadingType const& readingType);
    };
    struct __declspec(empty_bases) AccelerometerDataThreshold : llm::OS::Devices::Sensors::IAccelerometerDataThreshold
    {
        AccelerometerDataThreshold(std::nullptr_t) noexcept {}
        AccelerometerDataThreshold(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IAccelerometerDataThreshold(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AccelerometerReading : llm::OS::Devices::Sensors::IAccelerometerReading,
        impl::require<AccelerometerReading, llm::OS::Devices::Sensors::IAccelerometerReading2>
    {
        AccelerometerReading(std::nullptr_t) noexcept {}
        AccelerometerReading(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IAccelerometerReading(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AccelerometerReadingChangedEventArgs : llm::OS::Devices::Sensors::IAccelerometerReadingChangedEventArgs
    {
        AccelerometerReadingChangedEventArgs(std::nullptr_t) noexcept {}
        AccelerometerReadingChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IAccelerometerReadingChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AccelerometerShakenEventArgs : llm::OS::Devices::Sensors::IAccelerometerShakenEventArgs
    {
        AccelerometerShakenEventArgs(std::nullptr_t) noexcept {}
        AccelerometerShakenEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IAccelerometerShakenEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ActivitySensor : llm::OS::Devices::Sensors::IActivitySensor
    {
        ActivitySensor(std::nullptr_t) noexcept {}
        ActivitySensor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IActivitySensor(ptr, take_ownership_from_abi) {}
        static auto GetDefaultAsync();
        static auto GetDeviceSelector();
        static auto FromIdAsync(param::hstring const& deviceId);
        static auto GetSystemHistoryAsync(llm::OS::Foundation::DateTime const& fromTime);
        static auto GetSystemHistoryAsync(llm::OS::Foundation::DateTime const& fromTime, llm::OS::Foundation::TimeSpan const& duration);
    };
    struct __declspec(empty_bases) ActivitySensorReading : llm::OS::Devices::Sensors::IActivitySensorReading
    {
        ActivitySensorReading(std::nullptr_t) noexcept {}
        ActivitySensorReading(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IActivitySensorReading(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ActivitySensorReadingChangeReport : llm::OS::Devices::Sensors::IActivitySensorReadingChangeReport
    {
        ActivitySensorReadingChangeReport(std::nullptr_t) noexcept {}
        ActivitySensorReadingChangeReport(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IActivitySensorReadingChangeReport(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ActivitySensorReadingChangedEventArgs : llm::OS::Devices::Sensors::IActivitySensorReadingChangedEventArgs
    {
        ActivitySensorReadingChangedEventArgs(std::nullptr_t) noexcept {}
        ActivitySensorReadingChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IActivitySensorReadingChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ActivitySensorTriggerDetails : llm::OS::Devices::Sensors::IActivitySensorTriggerDetails
    {
        ActivitySensorTriggerDetails(std::nullptr_t) noexcept {}
        ActivitySensorTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IActivitySensorTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AdaptiveDimmingOptions : llm::OS::Devices::Sensors::IAdaptiveDimmingOptions
    {
        AdaptiveDimmingOptions(std::nullptr_t) noexcept {}
        AdaptiveDimmingOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IAdaptiveDimmingOptions(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) Altimeter : llm::OS::Devices::Sensors::IAltimeter,
        impl::require<Altimeter, llm::OS::Devices::Sensors::IAltimeter2>
    {
        Altimeter(std::nullptr_t) noexcept {}
        Altimeter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IAltimeter(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
    };
    struct __declspec(empty_bases) AltimeterReading : llm::OS::Devices::Sensors::IAltimeterReading,
        impl::require<AltimeterReading, llm::OS::Devices::Sensors::IAltimeterReading2>
    {
        AltimeterReading(std::nullptr_t) noexcept {}
        AltimeterReading(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IAltimeterReading(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AltimeterReadingChangedEventArgs : llm::OS::Devices::Sensors::IAltimeterReadingChangedEventArgs
    {
        AltimeterReadingChangedEventArgs(std::nullptr_t) noexcept {}
        AltimeterReadingChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IAltimeterReadingChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) Barometer : llm::OS::Devices::Sensors::IBarometer,
        impl::require<Barometer, llm::OS::Devices::Sensors::IBarometer2, llm::OS::Devices::Sensors::IBarometer3>
    {
        Barometer(std::nullptr_t) noexcept {}
        Barometer(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IBarometer(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
        static auto FromIdAsync(param::hstring const& deviceId);
        static auto GetDeviceSelector();
    };
    struct __declspec(empty_bases) BarometerDataThreshold : llm::OS::Devices::Sensors::IBarometerDataThreshold
    {
        BarometerDataThreshold(std::nullptr_t) noexcept {}
        BarometerDataThreshold(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IBarometerDataThreshold(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BarometerReading : llm::OS::Devices::Sensors::IBarometerReading,
        impl::require<BarometerReading, llm::OS::Devices::Sensors::IBarometerReading2>
    {
        BarometerReading(std::nullptr_t) noexcept {}
        BarometerReading(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IBarometerReading(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BarometerReadingChangedEventArgs : llm::OS::Devices::Sensors::IBarometerReadingChangedEventArgs
    {
        BarometerReadingChangedEventArgs(std::nullptr_t) noexcept {}
        BarometerReadingChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IBarometerReadingChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) Compass : llm::OS::Devices::Sensors::ICompass,
        impl::require<Compass, llm::OS::Devices::Sensors::ICompassDeviceId, llm::OS::Devices::Sensors::ICompass2, llm::OS::Devices::Sensors::ICompass3, llm::OS::Devices::Sensors::ICompass4>
    {
        Compass(std::nullptr_t) noexcept {}
        Compass(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::ICompass(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
        static auto GetDeviceSelector();
        static auto FromIdAsync(param::hstring const& deviceId);
    };
    struct __declspec(empty_bases) CompassDataThreshold : llm::OS::Devices::Sensors::ICompassDataThreshold
    {
        CompassDataThreshold(std::nullptr_t) noexcept {}
        CompassDataThreshold(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::ICompassDataThreshold(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CompassReading : llm::OS::Devices::Sensors::ICompassReading,
        impl::require<CompassReading, llm::OS::Devices::Sensors::ICompassReadingHeadingAccuracy, llm::OS::Devices::Sensors::ICompassReading2>
    {
        CompassReading(std::nullptr_t) noexcept {}
        CompassReading(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::ICompassReading(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CompassReadingChangedEventArgs : llm::OS::Devices::Sensors::ICompassReadingChangedEventArgs
    {
        CompassReadingChangedEventArgs(std::nullptr_t) noexcept {}
        CompassReadingChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::ICompassReadingChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) Gyrometer : llm::OS::Devices::Sensors::IGyrometer,
        impl::require<Gyrometer, llm::OS::Devices::Sensors::IGyrometerDeviceId, llm::OS::Devices::Sensors::IGyrometer2, llm::OS::Devices::Sensors::IGyrometer3, llm::OS::Devices::Sensors::IGyrometer4>
    {
        Gyrometer(std::nullptr_t) noexcept {}
        Gyrometer(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IGyrometer(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
        static auto GetDeviceSelector();
        static auto FromIdAsync(param::hstring const& deviceId);
    };
    struct __declspec(empty_bases) GyrometerDataThreshold : llm::OS::Devices::Sensors::IGyrometerDataThreshold
    {
        GyrometerDataThreshold(std::nullptr_t) noexcept {}
        GyrometerDataThreshold(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IGyrometerDataThreshold(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GyrometerReading : llm::OS::Devices::Sensors::IGyrometerReading,
        impl::require<GyrometerReading, llm::OS::Devices::Sensors::IGyrometerReading2>
    {
        GyrometerReading(std::nullptr_t) noexcept {}
        GyrometerReading(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IGyrometerReading(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GyrometerReadingChangedEventArgs : llm::OS::Devices::Sensors::IGyrometerReadingChangedEventArgs
    {
        GyrometerReadingChangedEventArgs(std::nullptr_t) noexcept {}
        GyrometerReadingChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IGyrometerReadingChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HingeAngleReading : llm::OS::Devices::Sensors::IHingeAngleReading
    {
        HingeAngleReading(std::nullptr_t) noexcept {}
        HingeAngleReading(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IHingeAngleReading(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HingeAngleSensor : llm::OS::Devices::Sensors::IHingeAngleSensor
    {
        HingeAngleSensor(std::nullptr_t) noexcept {}
        HingeAngleSensor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IHingeAngleSensor(ptr, take_ownership_from_abi) {}
        static auto GetDeviceSelector();
        static auto GetDefaultAsync();
        static auto GetRelatedToAdjacentPanelsAsync(param::hstring const& firstPanelId, param::hstring const& secondPanelId);
        static auto FromIdAsync(param::hstring const& deviceId);
    };
    struct __declspec(empty_bases) HingeAngleSensorReadingChangedEventArgs : llm::OS::Devices::Sensors::IHingeAngleSensorReadingChangedEventArgs
    {
        HingeAngleSensorReadingChangedEventArgs(std::nullptr_t) noexcept {}
        HingeAngleSensorReadingChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IHingeAngleSensorReadingChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HumanPresenceFeatures : llm::OS::Devices::Sensors::IHumanPresenceFeatures,
        impl::require<HumanPresenceFeatures, llm::OS::Devices::Sensors::IHumanPresenceFeatures2>
    {
        HumanPresenceFeatures(std::nullptr_t) noexcept {}
        HumanPresenceFeatures(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IHumanPresenceFeatures(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HumanPresenceSensor : llm::OS::Devices::Sensors::IHumanPresenceSensor,
        impl::require<HumanPresenceSensor, llm::OS::Devices::Sensors::IHumanPresenceSensor2>
    {
        HumanPresenceSensor(std::nullptr_t) noexcept {}
        HumanPresenceSensor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IHumanPresenceSensor(ptr, take_ownership_from_abi) {}
        static auto GetDeviceSelector();
        static auto FromIdAsync(param::hstring const& sensorId);
        static auto GetDefaultAsync();
        static auto FromId(param::hstring const& sensorId);
        static auto GetDefault();
    };
    struct __declspec(empty_bases) HumanPresenceSensorReading : llm::OS::Devices::Sensors::IHumanPresenceSensorReading,
        impl::require<HumanPresenceSensorReading, llm::OS::Devices::Sensors::IHumanPresenceSensorReading2>
    {
        HumanPresenceSensorReading(std::nullptr_t) noexcept {}
        HumanPresenceSensorReading(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IHumanPresenceSensorReading(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HumanPresenceSensorReadingChangedEventArgs : llm::OS::Devices::Sensors::IHumanPresenceSensorReadingChangedEventArgs
    {
        HumanPresenceSensorReadingChangedEventArgs(std::nullptr_t) noexcept {}
        HumanPresenceSensorReadingChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IHumanPresenceSensorReadingChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HumanPresenceSensorReadingUpdate : llm::OS::Devices::Sensors::IHumanPresenceSensorReadingUpdate
    {
        HumanPresenceSensorReadingUpdate(std::nullptr_t) noexcept {}
        HumanPresenceSensorReadingUpdate(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IHumanPresenceSensorReadingUpdate(ptr, take_ownership_from_abi) {}
        HumanPresenceSensorReadingUpdate();
    };
    struct __declspec(empty_bases) HumanPresenceSettings : llm::OS::Devices::Sensors::IHumanPresenceSettings,
        impl::require<HumanPresenceSettings, llm::OS::Devices::Sensors::IHumanPresenceSettings2>
    {
        HumanPresenceSettings(std::nullptr_t) noexcept {}
        HumanPresenceSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IHumanPresenceSettings(ptr, take_ownership_from_abi) {}
        static auto GetCurrentSettingsAsync();
        static auto GetCurrentSettings();
        static auto UpdateSettingsAsync(llm::OS::Devices::Sensors::HumanPresenceSettings const& settings);
        static auto UpdateSettings(llm::OS::Devices::Sensors::HumanPresenceSettings const& settings);
        static auto GetSupportedFeaturesForSensorIdAsync(param::hstring const& sensorId);
        static auto GetSupportedFeaturesForSensorId(param::hstring const& sensorId);
        static auto GetSupportedLockOnLeaveTimeouts();
        static auto SettingsChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler);
        using SettingsChanged_revoker = impl::factory_event_revoker<llm::OS::Devices::Sensors::IHumanPresenceSettingsStatics, &impl::abi_t<llm::OS::Devices::Sensors::IHumanPresenceSettingsStatics>::remove_SettingsChanged>;
        [[nodiscard]] static SettingsChanged_revoker SettingsChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler);
        static auto SettingsChanged(llm::event_token const& token);
    };
    struct __declspec(empty_bases) Inclinometer : llm::OS::Devices::Sensors::IInclinometer,
        impl::require<Inclinometer, llm::OS::Devices::Sensors::IInclinometerDeviceId, llm::OS::Devices::Sensors::IInclinometer2, llm::OS::Devices::Sensors::IInclinometer3, llm::OS::Devices::Sensors::IInclinometer4>
    {
        Inclinometer(std::nullptr_t) noexcept {}
        Inclinometer(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IInclinometer(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
        static auto GetDefaultForRelativeReadings();
        static auto GetDefault(llm::OS::Devices::Sensors::SensorReadingType const& sensorReadingtype);
        static auto GetDeviceSelector(llm::OS::Devices::Sensors::SensorReadingType const& readingType);
        static auto FromIdAsync(param::hstring const& deviceId);
    };
    struct __declspec(empty_bases) InclinometerDataThreshold : llm::OS::Devices::Sensors::IInclinometerDataThreshold
    {
        InclinometerDataThreshold(std::nullptr_t) noexcept {}
        InclinometerDataThreshold(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IInclinometerDataThreshold(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InclinometerReading : llm::OS::Devices::Sensors::IInclinometerReading,
        impl::require<InclinometerReading, llm::OS::Devices::Sensors::IInclinometerReadingYawAccuracy, llm::OS::Devices::Sensors::IInclinometerReading2>
    {
        InclinometerReading(std::nullptr_t) noexcept {}
        InclinometerReading(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IInclinometerReading(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InclinometerReadingChangedEventArgs : llm::OS::Devices::Sensors::IInclinometerReadingChangedEventArgs
    {
        InclinometerReadingChangedEventArgs(std::nullptr_t) noexcept {}
        InclinometerReadingChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IInclinometerReadingChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LightSensor : llm::OS::Devices::Sensors::ILightSensor,
        impl::require<LightSensor, llm::OS::Devices::Sensors::ILightSensorDeviceId, llm::OS::Devices::Sensors::ILightSensor2, llm::OS::Devices::Sensors::ILightSensor3>
    {
        LightSensor(std::nullptr_t) noexcept {}
        LightSensor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::ILightSensor(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
        static auto GetDeviceSelector();
        static auto FromIdAsync(param::hstring const& deviceId);
    };
    struct __declspec(empty_bases) LightSensorDataThreshold : llm::OS::Devices::Sensors::ILightSensorDataThreshold
    {
        LightSensorDataThreshold(std::nullptr_t) noexcept {}
        LightSensorDataThreshold(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::ILightSensorDataThreshold(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LightSensorReading : llm::OS::Devices::Sensors::ILightSensorReading,
        impl::require<LightSensorReading, llm::OS::Devices::Sensors::ILightSensorReading2>
    {
        LightSensorReading(std::nullptr_t) noexcept {}
        LightSensorReading(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::ILightSensorReading(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LightSensorReadingChangedEventArgs : llm::OS::Devices::Sensors::ILightSensorReadingChangedEventArgs
    {
        LightSensorReadingChangedEventArgs(std::nullptr_t) noexcept {}
        LightSensorReadingChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::ILightSensorReadingChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LockOnLeaveOptions : llm::OS::Devices::Sensors::ILockOnLeaveOptions
    {
        LockOnLeaveOptions(std::nullptr_t) noexcept {}
        LockOnLeaveOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::ILockOnLeaveOptions(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) Magnetometer : llm::OS::Devices::Sensors::IMagnetometer,
        impl::require<Magnetometer, llm::OS::Devices::Sensors::IMagnetometerDeviceId, llm::OS::Devices::Sensors::IMagnetometer2, llm::OS::Devices::Sensors::IMagnetometer3, llm::OS::Devices::Sensors::IMagnetometer4>
    {
        Magnetometer(std::nullptr_t) noexcept {}
        Magnetometer(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IMagnetometer(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
        static auto GetDeviceSelector();
        static auto FromIdAsync(param::hstring const& deviceId);
    };
    struct __declspec(empty_bases) MagnetometerDataThreshold : llm::OS::Devices::Sensors::IMagnetometerDataThreshold
    {
        MagnetometerDataThreshold(std::nullptr_t) noexcept {}
        MagnetometerDataThreshold(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IMagnetometerDataThreshold(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MagnetometerReading : llm::OS::Devices::Sensors::IMagnetometerReading,
        impl::require<MagnetometerReading, llm::OS::Devices::Sensors::IMagnetometerReading2>
    {
        MagnetometerReading(std::nullptr_t) noexcept {}
        MagnetometerReading(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IMagnetometerReading(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MagnetometerReadingChangedEventArgs : llm::OS::Devices::Sensors::IMagnetometerReadingChangedEventArgs
    {
        MagnetometerReadingChangedEventArgs(std::nullptr_t) noexcept {}
        MagnetometerReadingChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IMagnetometerReadingChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) OrientationSensor : llm::OS::Devices::Sensors::IOrientationSensor,
        impl::require<OrientationSensor, llm::OS::Devices::Sensors::IOrientationSensorDeviceId, llm::OS::Devices::Sensors::IOrientationSensor2, llm::OS::Devices::Sensors::IOrientationSensor3>
    {
        OrientationSensor(std::nullptr_t) noexcept {}
        OrientationSensor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IOrientationSensor(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
        static auto GetDefaultForRelativeReadings();
        static auto GetDefault(llm::OS::Devices::Sensors::SensorReadingType const& sensorReadingtype);
        static auto GetDefault(llm::OS::Devices::Sensors::SensorReadingType const& sensorReadingType, llm::OS::Devices::Sensors::SensorOptimizationGoal const& optimizationGoal);
        static auto GetDeviceSelector(llm::OS::Devices::Sensors::SensorReadingType const& readingType);
        static auto GetDeviceSelector(llm::OS::Devices::Sensors::SensorReadingType const& readingType, llm::OS::Devices::Sensors::SensorOptimizationGoal const& optimizationGoal);
        static auto FromIdAsync(param::hstring const& deviceId);
    };
    struct __declspec(empty_bases) OrientationSensorReading : llm::OS::Devices::Sensors::IOrientationSensorReading,
        impl::require<OrientationSensorReading, llm::OS::Devices::Sensors::IOrientationSensorReadingYawAccuracy, llm::OS::Devices::Sensors::IOrientationSensorReading2>
    {
        OrientationSensorReading(std::nullptr_t) noexcept {}
        OrientationSensorReading(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IOrientationSensorReading(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) OrientationSensorReadingChangedEventArgs : llm::OS::Devices::Sensors::IOrientationSensorReadingChangedEventArgs
    {
        OrientationSensorReadingChangedEventArgs(std::nullptr_t) noexcept {}
        OrientationSensorReadingChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IOrientationSensorReadingChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) Pedometer : llm::OS::Devices::Sensors::IPedometer,
        impl::require<Pedometer, llm::OS::Devices::Sensors::IPedometer2>
    {
        Pedometer(std::nullptr_t) noexcept {}
        Pedometer(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IPedometer(ptr, take_ownership_from_abi) {}
        static auto FromIdAsync(param::hstring const& deviceId);
        static auto GetDefaultAsync();
        static auto GetDeviceSelector();
        static auto GetSystemHistoryAsync(llm::OS::Foundation::DateTime const& fromTime);
        static auto GetSystemHistoryAsync(llm::OS::Foundation::DateTime const& fromTime, llm::OS::Foundation::TimeSpan const& duration);
        static auto GetReadingsFromTriggerDetails(llm::OS::Devices::Sensors::SensorDataThresholdTriggerDetails const& triggerDetails);
    };
    struct __declspec(empty_bases) PedometerDataThreshold : llm::OS::Devices::Sensors::ISensorDataThreshold
    {
        PedometerDataThreshold(std::nullptr_t) noexcept {}
        PedometerDataThreshold(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::ISensorDataThreshold(ptr, take_ownership_from_abi) {}
        PedometerDataThreshold(llm::OS::Devices::Sensors::Pedometer const& sensor, int32_t stepGoal);
    };
    struct __declspec(empty_bases) PedometerReading : llm::OS::Devices::Sensors::IPedometerReading
    {
        PedometerReading(std::nullptr_t) noexcept {}
        PedometerReading(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IPedometerReading(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PedometerReadingChangedEventArgs : llm::OS::Devices::Sensors::IPedometerReadingChangedEventArgs
    {
        PedometerReadingChangedEventArgs(std::nullptr_t) noexcept {}
        PedometerReadingChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IPedometerReadingChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ProximitySensor : llm::OS::Devices::Sensors::IProximitySensor
    {
        ProximitySensor(std::nullptr_t) noexcept {}
        ProximitySensor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IProximitySensor(ptr, take_ownership_from_abi) {}
        static auto GetDeviceSelector();
        static auto FromId(param::hstring const& sensorId);
        static auto GetReadingsFromTriggerDetails(llm::OS::Devices::Sensors::SensorDataThresholdTriggerDetails const& triggerDetails);
    };
    struct __declspec(empty_bases) ProximitySensorDataThreshold : llm::OS::Devices::Sensors::ISensorDataThreshold
    {
        ProximitySensorDataThreshold(std::nullptr_t) noexcept {}
        ProximitySensorDataThreshold(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::ISensorDataThreshold(ptr, take_ownership_from_abi) {}
        explicit ProximitySensorDataThreshold(llm::OS::Devices::Sensors::ProximitySensor const& sensor);
    };
    struct __declspec(empty_bases) ProximitySensorDisplayOnOffController : llm::OS::Foundation::IClosable
    {
        ProximitySensorDisplayOnOffController(std::nullptr_t) noexcept {}
        ProximitySensorDisplayOnOffController(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IClosable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ProximitySensorReading : llm::OS::Devices::Sensors::IProximitySensorReading
    {
        ProximitySensorReading(std::nullptr_t) noexcept {}
        ProximitySensorReading(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IProximitySensorReading(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ProximitySensorReadingChangedEventArgs : llm::OS::Devices::Sensors::IProximitySensorReadingChangedEventArgs
    {
        ProximitySensorReadingChangedEventArgs(std::nullptr_t) noexcept {}
        ProximitySensorReadingChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IProximitySensorReadingChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SensorDataThresholdTriggerDetails : llm::OS::Devices::Sensors::ISensorDataThresholdTriggerDetails
    {
        SensorDataThresholdTriggerDetails(std::nullptr_t) noexcept {}
        SensorDataThresholdTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::ISensorDataThresholdTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SensorQuaternion : llm::OS::Devices::Sensors::ISensorQuaternion
    {
        SensorQuaternion(std::nullptr_t) noexcept {}
        SensorQuaternion(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::ISensorQuaternion(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SensorRotationMatrix : llm::OS::Devices::Sensors::ISensorRotationMatrix
    {
        SensorRotationMatrix(std::nullptr_t) noexcept {}
        SensorRotationMatrix(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::ISensorRotationMatrix(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SimpleOrientationSensor : llm::OS::Devices::Sensors::ISimpleOrientationSensor,
        impl::require<SimpleOrientationSensor, llm::OS::Devices::Sensors::ISimpleOrientationSensorDeviceId, llm::OS::Devices::Sensors::ISimpleOrientationSensor2>
    {
        SimpleOrientationSensor(std::nullptr_t) noexcept {}
        SimpleOrientationSensor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::ISimpleOrientationSensor(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
        static auto GetDeviceSelector();
        static auto FromIdAsync(param::hstring const& deviceId);
    };
    struct __declspec(empty_bases) SimpleOrientationSensorOrientationChangedEventArgs : llm::OS::Devices::Sensors::ISimpleOrientationSensorOrientationChangedEventArgs
    {
        SimpleOrientationSensorOrientationChangedEventArgs(std::nullptr_t) noexcept {}
        SimpleOrientationSensorOrientationChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::ISimpleOrientationSensorOrientationChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WakeOnApproachOptions : llm::OS::Devices::Sensors::IWakeOnApproachOptions
    {
        WakeOnApproachOptions(std::nullptr_t) noexcept {}
        WakeOnApproachOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::IWakeOnApproachOptions(ptr, take_ownership_from_abi) {}
    };
}
#endif
