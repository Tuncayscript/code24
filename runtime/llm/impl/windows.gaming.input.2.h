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
#ifndef LLM_OS_Gaming_Input_2_H
#define LLM_OS_Gaming_Input_2_H
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Gaming.Input.1.h"
LLM_EXPORT namespace llm::OS::Gaming::Input
{
    struct ArcadeStickReading
    {
        uint64_t Timestamp;
        llm::OS::Gaming::Input::ArcadeStickButtons Buttons;
    };
    inline bool operator==(ArcadeStickReading const& left, ArcadeStickReading const& right) noexcept
    {
        return left.Timestamp == right.Timestamp && left.Buttons == right.Buttons;
    }
    inline bool operator!=(ArcadeStickReading const& left, ArcadeStickReading const& right) noexcept
    {
        return !(left == right);
    }
    struct FlightStickReading
    {
        uint64_t Timestamp;
        llm::OS::Gaming::Input::FlightStickButtons Buttons;
        llm::OS::Gaming::Input::GameControllerSwitchPosition HatSwitch;
        double Roll;
        double Pitch;
        double Yaw;
        double Throttle;
    };
    inline bool operator==(FlightStickReading const& left, FlightStickReading const& right) noexcept
    {
        return left.Timestamp == right.Timestamp && left.Buttons == right.Buttons && left.HatSwitch == right.HatSwitch && left.Roll == right.Roll && left.Pitch == right.Pitch && left.Yaw == right.Yaw && left.Throttle == right.Throttle;
    }
    inline bool operator!=(FlightStickReading const& left, FlightStickReading const& right) noexcept
    {
        return !(left == right);
    }
    struct GamepadReading
    {
        uint64_t Timestamp;
        llm::OS::Gaming::Input::GamepadButtons Buttons;
        double LeftTrigger;
        double RightTrigger;
        double LeftThumbstickX;
        double LeftThumbstickY;
        double RightThumbstickX;
        double RightThumbstickY;
    };
    inline bool operator==(GamepadReading const& left, GamepadReading const& right) noexcept
    {
        return left.Timestamp == right.Timestamp && left.Buttons == right.Buttons && left.LeftTrigger == right.LeftTrigger && left.RightTrigger == right.RightTrigger && left.LeftThumbstickX == right.LeftThumbstickX && left.LeftThumbstickY == right.LeftThumbstickY && left.RightThumbstickX == right.RightThumbstickX && left.RightThumbstickY == right.RightThumbstickY;
    }
    inline bool operator!=(GamepadReading const& left, GamepadReading const& right) noexcept
    {
        return !(left == right);
    }
    struct GamepadVibration
    {
        double LeftMotor;
        double RightMotor;
        double LeftTrigger;
        double RightTrigger;
    };
    inline bool operator==(GamepadVibration const& left, GamepadVibration const& right) noexcept
    {
        return left.LeftMotor == right.LeftMotor && left.RightMotor == right.RightMotor && left.LeftTrigger == right.LeftTrigger && left.RightTrigger == right.RightTrigger;
    }
    inline bool operator!=(GamepadVibration const& left, GamepadVibration const& right) noexcept
    {
        return !(left == right);
    }
    struct RacingWheelReading
    {
        uint64_t Timestamp;
        llm::OS::Gaming::Input::RacingWheelButtons Buttons;
        int32_t PatternShifterGear;
        double Wheel;
        double Throttle;
        double Brake;
        double Clutch;
        double Handbrake;
    };
    inline bool operator==(RacingWheelReading const& left, RacingWheelReading const& right) noexcept
    {
        return left.Timestamp == right.Timestamp && left.Buttons == right.Buttons && left.PatternShifterGear == right.PatternShifterGear && left.Wheel == right.Wheel && left.Throttle == right.Throttle && left.Brake == right.Brake && left.Clutch == right.Clutch && left.Handbrake == right.Handbrake;
    }
    inline bool operator!=(RacingWheelReading const& left, RacingWheelReading const& right) noexcept
    {
        return !(left == right);
    }
    struct UINavigationReading
    {
        uint64_t Timestamp;
        llm::OS::Gaming::Input::RequiredUINavigationButtons RequiredButtons;
        llm::OS::Gaming::Input::OptionalUINavigationButtons OptionalButtons;
    };
    inline bool operator==(UINavigationReading const& left, UINavigationReading const& right) noexcept
    {
        return left.Timestamp == right.Timestamp && left.RequiredButtons == right.RequiredButtons && left.OptionalButtons == right.OptionalButtons;
    }
    inline bool operator!=(UINavigationReading const& left, UINavigationReading const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) ArcadeStick : llm::OS::Gaming::Input::IArcadeStick,
        impl::require<ArcadeStick, llm::OS::Gaming::Input::IGameControllerBatteryInfo>
    {
        ArcadeStick(std::nullptr_t) noexcept {}
        ArcadeStick(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Gaming::Input::IArcadeStick(ptr, take_ownership_from_abi) {}
        static auto ArcadeStickAdded(llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::ArcadeStick> const& value);
        using ArcadeStickAdded_revoker = impl::factory_event_revoker<llm::OS::Gaming::Input::IArcadeStickStatics, &impl::abi_t<llm::OS::Gaming::Input::IArcadeStickStatics>::remove_ArcadeStickAdded>;
        [[nodiscard]] static ArcadeStickAdded_revoker ArcadeStickAdded(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::ArcadeStick> const& value);
        static auto ArcadeStickAdded(llm::event_token const& token);
        static auto ArcadeStickRemoved(llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::ArcadeStick> const& value);
        using ArcadeStickRemoved_revoker = impl::factory_event_revoker<llm::OS::Gaming::Input::IArcadeStickStatics, &impl::abi_t<llm::OS::Gaming::Input::IArcadeStickStatics>::remove_ArcadeStickRemoved>;
        [[nodiscard]] static ArcadeStickRemoved_revoker ArcadeStickRemoved(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::ArcadeStick> const& value);
        static auto ArcadeStickRemoved(llm::event_token const& token);
        [[nodiscard]] static auto ArcadeSticks();
        static auto FromGameController(llm::OS::Gaming::Input::IGameController const& gameController);
    };
    struct __declspec(empty_bases) FlightStick : llm::OS::Gaming::Input::IFlightStick,
        impl::require<FlightStick, llm::OS::Gaming::Input::IGameControllerBatteryInfo>
    {
        FlightStick(std::nullptr_t) noexcept {}
        FlightStick(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Gaming::Input::IFlightStick(ptr, take_ownership_from_abi) {}
        static auto FlightStickAdded(llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::FlightStick> const& value);
        using FlightStickAdded_revoker = impl::factory_event_revoker<llm::OS::Gaming::Input::IFlightStickStatics, &impl::abi_t<llm::OS::Gaming::Input::IFlightStickStatics>::remove_FlightStickAdded>;
        [[nodiscard]] static FlightStickAdded_revoker FlightStickAdded(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::FlightStick> const& value);
        static auto FlightStickAdded(llm::event_token const& token);
        static auto FlightStickRemoved(llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::FlightStick> const& value);
        using FlightStickRemoved_revoker = impl::factory_event_revoker<llm::OS::Gaming::Input::IFlightStickStatics, &impl::abi_t<llm::OS::Gaming::Input::IFlightStickStatics>::remove_FlightStickRemoved>;
        [[nodiscard]] static FlightStickRemoved_revoker FlightStickRemoved(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::FlightStick> const& value);
        static auto FlightStickRemoved(llm::event_token const& token);
        [[nodiscard]] static auto FlightSticks();
        static auto FromGameController(llm::OS::Gaming::Input::IGameController const& gameController);
    };
    struct __declspec(empty_bases) Gamepad : llm::OS::Gaming::Input::IGamepad,
        impl::require<Gamepad, llm::OS::Gaming::Input::IGamepad2, llm::OS::Gaming::Input::IGameControllerBatteryInfo>
    {
        Gamepad(std::nullptr_t) noexcept {}
        Gamepad(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Gaming::Input::IGamepad(ptr, take_ownership_from_abi) {}
        static auto GamepadAdded(llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::Gamepad> const& value);
        using GamepadAdded_revoker = impl::factory_event_revoker<llm::OS::Gaming::Input::IGamepadStatics, &impl::abi_t<llm::OS::Gaming::Input::IGamepadStatics>::remove_GamepadAdded>;
        [[nodiscard]] static GamepadAdded_revoker GamepadAdded(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::Gamepad> const& value);
        static auto GamepadAdded(llm::event_token const& token);
        static auto GamepadRemoved(llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::Gamepad> const& value);
        using GamepadRemoved_revoker = impl::factory_event_revoker<llm::OS::Gaming::Input::IGamepadStatics, &impl::abi_t<llm::OS::Gaming::Input::IGamepadStatics>::remove_GamepadRemoved>;
        [[nodiscard]] static GamepadRemoved_revoker GamepadRemoved(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::Gamepad> const& value);
        static auto GamepadRemoved(llm::event_token const& token);
        [[nodiscard]] static auto Gamepads();
        static auto FromGameController(llm::OS::Gaming::Input::IGameController const& gameController);
    };
    struct __declspec(empty_bases) Headset : llm::OS::Gaming::Input::IHeadset,
        impl::require<Headset, llm::OS::Gaming::Input::IGameControllerBatteryInfo>
    {
        Headset(std::nullptr_t) noexcept {}
        Headset(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Gaming::Input::IHeadset(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RacingWheel : llm::OS::Gaming::Input::IRacingWheel,
        impl::require<RacingWheel, llm::OS::Gaming::Input::IGameControllerBatteryInfo>
    {
        RacingWheel(std::nullptr_t) noexcept {}
        RacingWheel(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Gaming::Input::IRacingWheel(ptr, take_ownership_from_abi) {}
        static auto RacingWheelAdded(llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::RacingWheel> const& value);
        using RacingWheelAdded_revoker = impl::factory_event_revoker<llm::OS::Gaming::Input::IRacingWheelStatics, &impl::abi_t<llm::OS::Gaming::Input::IRacingWheelStatics>::remove_RacingWheelAdded>;
        [[nodiscard]] static RacingWheelAdded_revoker RacingWheelAdded(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::RacingWheel> const& value);
        static auto RacingWheelAdded(llm::event_token const& token);
        static auto RacingWheelRemoved(llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::RacingWheel> const& value);
        using RacingWheelRemoved_revoker = impl::factory_event_revoker<llm::OS::Gaming::Input::IRacingWheelStatics, &impl::abi_t<llm::OS::Gaming::Input::IRacingWheelStatics>::remove_RacingWheelRemoved>;
        [[nodiscard]] static RacingWheelRemoved_revoker RacingWheelRemoved(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::RacingWheel> const& value);
        static auto RacingWheelRemoved(llm::event_token const& token);
        [[nodiscard]] static auto RacingWheels();
        static auto FromGameController(llm::OS::Gaming::Input::IGameController const& gameController);
    };
    struct __declspec(empty_bases) RawGameController : llm::OS::Gaming::Input::IRawGameController,
        impl::require<RawGameController, llm::OS::Gaming::Input::IGameControllerBatteryInfo, llm::OS::Gaming::Input::IRawGameController2>
    {
        RawGameController(std::nullptr_t) noexcept {}
        RawGameController(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Gaming::Input::IRawGameController(ptr, take_ownership_from_abi) {}
        static auto RawGameControllerAdded(llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::RawGameController> const& value);
        using RawGameControllerAdded_revoker = impl::factory_event_revoker<llm::OS::Gaming::Input::IRawGameControllerStatics, &impl::abi_t<llm::OS::Gaming::Input::IRawGameControllerStatics>::remove_RawGameControllerAdded>;
        [[nodiscard]] static RawGameControllerAdded_revoker RawGameControllerAdded(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::RawGameController> const& value);
        static auto RawGameControllerAdded(llm::event_token const& token);
        static auto RawGameControllerRemoved(llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::RawGameController> const& value);
        using RawGameControllerRemoved_revoker = impl::factory_event_revoker<llm::OS::Gaming::Input::IRawGameControllerStatics, &impl::abi_t<llm::OS::Gaming::Input::IRawGameControllerStatics>::remove_RawGameControllerRemoved>;
        [[nodiscard]] static RawGameControllerRemoved_revoker RawGameControllerRemoved(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::RawGameController> const& value);
        static auto RawGameControllerRemoved(llm::event_token const& token);
        [[nodiscard]] static auto RawGameControllers();
        static auto FromGameController(llm::OS::Gaming::Input::IGameController const& gameController);
    };
    struct __declspec(empty_bases) UINavigationController : llm::OS::Gaming::Input::IUINavigationController,
        impl::require<UINavigationController, llm::OS::Gaming::Input::IGameControllerBatteryInfo>
    {
        UINavigationController(std::nullptr_t) noexcept {}
        UINavigationController(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Gaming::Input::IUINavigationController(ptr, take_ownership_from_abi) {}
        static auto UINavigationControllerAdded(llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::UINavigationController> const& value);
        using UINavigationControllerAdded_revoker = impl::factory_event_revoker<llm::OS::Gaming::Input::IUINavigationControllerStatics, &impl::abi_t<llm::OS::Gaming::Input::IUINavigationControllerStatics>::remove_UINavigationControllerAdded>;
        [[nodiscard]] static UINavigationControllerAdded_revoker UINavigationControllerAdded(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::UINavigationController> const& value);
        static auto UINavigationControllerAdded(llm::event_token const& token);
        static auto UINavigationControllerRemoved(llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::UINavigationController> const& value);
        using UINavigationControllerRemoved_revoker = impl::factory_event_revoker<llm::OS::Gaming::Input::IUINavigationControllerStatics, &impl::abi_t<llm::OS::Gaming::Input::IUINavigationControllerStatics>::remove_UINavigationControllerRemoved>;
        [[nodiscard]] static UINavigationControllerRemoved_revoker UINavigationControllerRemoved(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::UINavigationController> const& value);
        static auto UINavigationControllerRemoved(llm::event_token const& token);
        [[nodiscard]] static auto UINavigationControllers();
        static auto FromGameController(llm::OS::Gaming::Input::IGameController const& gameController);
    };
}
#endif
