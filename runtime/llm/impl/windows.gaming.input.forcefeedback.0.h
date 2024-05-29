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
#ifndef LLM_OS_Gaming_Input_ForceFeedback_0_H
#define LLM_OS_Gaming_Input_ForceFeedback_0_H
LLM_EXPORT namespace llm::OS::Foundation
{
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
}
LLM_EXPORT namespace llm::OS::Foundation::Numerics
{
}
LLM_EXPORT namespace llm::OS::Gaming::Input::ForceFeedback
{
    enum class ConditionForceEffectKind : int32_t
    {
        Spring = 0,
        Damper = 1,
        Inertia = 2,
        Friction = 3,
    };
    enum class ForceFeedbackEffectAxes : uint32_t
    {
        None = 0,
        X = 0x1,
        Y = 0x2,
        Z = 0x4,
    };
    enum class ForceFeedbackEffectState : int32_t
    {
        Stopped = 0,
        Running = 1,
        Paused = 2,
        Faulted = 3,
    };
    enum class ForceFeedbackLoadEffectResult : int32_t
    {
        Succeeded = 0,
        EffectStorageFull = 1,
        EffectNotSupported = 2,
    };
    enum class PeriodicForceEffectKind : int32_t
    {
        SquareWave = 0,
        SineWave = 1,
        TriangleWave = 2,
        SawtoothWaveUp = 3,
        SawtoothWaveDown = 4,
    };
    struct IConditionForceEffect;
    struct IConditionForceEffectFactory;
    struct IConstantForceEffect;
    struct IForceFeedbackEffect;
    struct IForceFeedbackMotor;
    struct IPeriodicForceEffect;
    struct IPeriodicForceEffectFactory;
    struct IRampForceEffect;
    struct ConditionForceEffect;
    struct ConstantForceEffect;
    struct ForceFeedbackMotor;
    struct PeriodicForceEffect;
    struct RampForceEffect;
}
namespace llm::impl
{
    template <> struct category<llm::OS::Gaming::Input::ForceFeedback::IConditionForceEffect>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::ForceFeedback::IConditionForceEffectFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::ForceFeedback::IConstantForceEffect>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::ForceFeedback::IForceFeedbackEffect>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::ForceFeedback::IForceFeedbackMotor>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::ForceFeedback::IPeriodicForceEffect>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::ForceFeedback::IPeriodicForceEffectFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::ForceFeedback::IRampForceEffect>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::ForceFeedback::ConditionForceEffect>{ using type = class_category; };
    template <> struct category<llm::OS::Gaming::Input::ForceFeedback::ConstantForceEffect>{ using type = class_category; };
    template <> struct category<llm::OS::Gaming::Input::ForceFeedback::ForceFeedbackMotor>{ using type = class_category; };
    template <> struct category<llm::OS::Gaming::Input::ForceFeedback::PeriodicForceEffect>{ using type = class_category; };
    template <> struct category<llm::OS::Gaming::Input::ForceFeedback::RampForceEffect>{ using type = class_category; };
    template <> struct category<llm::OS::Gaming::Input::ForceFeedback::ConditionForceEffectKind>{ using type = enum_category; };
    template <> struct category<llm::OS::Gaming::Input::ForceFeedback::ForceFeedbackEffectAxes>{ using type = enum_category; };
    template <> struct category<llm::OS::Gaming::Input::ForceFeedback::ForceFeedbackEffectState>{ using type = enum_category; };
    template <> struct category<llm::OS::Gaming::Input::ForceFeedback::ForceFeedbackLoadEffectResult>{ using type = enum_category; };
    template <> struct category<llm::OS::Gaming::Input::ForceFeedback::PeriodicForceEffectKind>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::ForceFeedback::ConditionForceEffect> = L"Windows.Gaming.Input.ForceFeedback.ConditionForceEffect";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::ForceFeedback::ConstantForceEffect> = L"Windows.Gaming.Input.ForceFeedback.ConstantForceEffect";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::ForceFeedback::ForceFeedbackMotor> = L"Windows.Gaming.Input.ForceFeedback.ForceFeedbackMotor";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::ForceFeedback::PeriodicForceEffect> = L"Windows.Gaming.Input.ForceFeedback.PeriodicForceEffect";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::ForceFeedback::RampForceEffect> = L"Windows.Gaming.Input.ForceFeedback.RampForceEffect";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::ForceFeedback::ConditionForceEffectKind> = L"Windows.Gaming.Input.ForceFeedback.ConditionForceEffectKind";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::ForceFeedback::ForceFeedbackEffectAxes> = L"Windows.Gaming.Input.ForceFeedback.ForceFeedbackEffectAxes";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::ForceFeedback::ForceFeedbackEffectState> = L"Windows.Gaming.Input.ForceFeedback.ForceFeedbackEffectState";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::ForceFeedback::ForceFeedbackLoadEffectResult> = L"Windows.Gaming.Input.ForceFeedback.ForceFeedbackLoadEffectResult";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::ForceFeedback::PeriodicForceEffectKind> = L"Windows.Gaming.Input.ForceFeedback.PeriodicForceEffectKind";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::ForceFeedback::IConditionForceEffect> = L"Windows.Gaming.Input.ForceFeedback.IConditionForceEffect";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::ForceFeedback::IConditionForceEffectFactory> = L"Windows.Gaming.Input.ForceFeedback.IConditionForceEffectFactory";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::ForceFeedback::IConstantForceEffect> = L"Windows.Gaming.Input.ForceFeedback.IConstantForceEffect";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::ForceFeedback::IForceFeedbackEffect> = L"Windows.Gaming.Input.ForceFeedback.IForceFeedbackEffect";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::ForceFeedback::IForceFeedbackMotor> = L"Windows.Gaming.Input.ForceFeedback.IForceFeedbackMotor";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::ForceFeedback::IPeriodicForceEffect> = L"Windows.Gaming.Input.ForceFeedback.IPeriodicForceEffect";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::ForceFeedback::IPeriodicForceEffectFactory> = L"Windows.Gaming.Input.ForceFeedback.IPeriodicForceEffectFactory";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::ForceFeedback::IRampForceEffect> = L"Windows.Gaming.Input.ForceFeedback.IRampForceEffect";
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::ForceFeedback::IConditionForceEffect>{ 0x32D1EA68,0x3695,0x4E69,{ 0x85,0xC0,0xCD,0x19,0x44,0x18,0x91,0x40 } }; // 32D1EA68-3695-4E69-85C0-CD1944189140
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::ForceFeedback::IConditionForceEffectFactory>{ 0x91A99264,0x1810,0x4EB6,{ 0xA7,0x73,0xBF,0xD3,0xB8,0xCD,0xDB,0xAB } }; // 91A99264-1810-4EB6-A773-BFD3B8CDDBAB
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::ForceFeedback::IConstantForceEffect>{ 0x9BFA0140,0xF3C7,0x415C,{ 0xB0,0x68,0x0F,0x06,0x87,0x34,0xBC,0xE0 } }; // 9BFA0140-F3C7-415C-B068-0F068734BCE0
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::ForceFeedback::IForceFeedbackEffect>{ 0xA17FBA0C,0x2AE4,0x48C2,{ 0x80,0x63,0xEA,0xBD,0x07,0x77,0xCB,0x89 } }; // A17FBA0C-2AE4-48C2-8063-EABD0777CB89
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::ForceFeedback::IForceFeedbackMotor>{ 0x8D3D417C,0xA5EA,0x4516,{ 0x80,0x26,0x2B,0x00,0xF7,0x4E,0xF6,0xE5 } }; // 8D3D417C-A5EA-4516-8026-2B00F74EF6E5
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::ForceFeedback::IPeriodicForceEffect>{ 0x5C5138D7,0xFC75,0x4D52,{ 0x9A,0x0A,0xEF,0xE4,0xCA,0xB5,0xFE,0x64 } }; // 5C5138D7-FC75-4D52-9A0A-EFE4CAB5FE64
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::ForceFeedback::IPeriodicForceEffectFactory>{ 0x6F62EB1A,0x9851,0x477B,{ 0xB3,0x18,0x35,0xEC,0xAA,0x15,0x07,0x0F } }; // 6F62EB1A-9851-477B-B318-35ECAA15070F
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::ForceFeedback::IRampForceEffect>{ 0xF1F81259,0x1CA6,0x4080,{ 0xB5,0x6D,0xB4,0x3F,0x33,0x54,0xD0,0x52 } }; // F1F81259-1CA6-4080-B56D-B43F3354D052
    template <> struct default_interface<llm::OS::Gaming::Input::ForceFeedback::ConditionForceEffect>{ using type = llm::OS::Gaming::Input::ForceFeedback::IForceFeedbackEffect; };
    template <> struct default_interface<llm::OS::Gaming::Input::ForceFeedback::ConstantForceEffect>{ using type = llm::OS::Gaming::Input::ForceFeedback::IForceFeedbackEffect; };
    template <> struct default_interface<llm::OS::Gaming::Input::ForceFeedback::ForceFeedbackMotor>{ using type = llm::OS::Gaming::Input::ForceFeedback::IForceFeedbackMotor; };
    template <> struct default_interface<llm::OS::Gaming::Input::ForceFeedback::PeriodicForceEffect>{ using type = llm::OS::Gaming::Input::ForceFeedback::IForceFeedbackEffect; };
    template <> struct default_interface<llm::OS::Gaming::Input::ForceFeedback::RampForceEffect>{ using type = llm::OS::Gaming::Input::ForceFeedback::IForceFeedbackEffect; };
    template <> struct abi<llm::OS::Gaming::Input::ForceFeedback::IConditionForceEffect>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Kind(int32_t*) noexcept = 0;
            virtual int32_t __stdcall SetParameters(llm::OS::Foundation::Numerics::float3, float, float, float, float, float, float) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::ForceFeedback::IConditionForceEffectFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::ForceFeedback::IConstantForceEffect>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SetParameters(llm::OS::Foundation::Numerics::float3, int64_t) noexcept = 0;
            virtual int32_t __stdcall SetParametersWithEnvelope(llm::OS::Foundation::Numerics::float3, float, float, float, int64_t, int64_t, int64_t, int64_t, uint32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::ForceFeedback::IForceFeedbackEffect>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Gain(double*) noexcept = 0;
            virtual int32_t __stdcall put_Gain(double) noexcept = 0;
            virtual int32_t __stdcall get_State(int32_t*) noexcept = 0;
            virtual int32_t __stdcall Start() noexcept = 0;
            virtual int32_t __stdcall Stop() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::ForceFeedback::IForceFeedbackMotor>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AreEffectsPaused(bool*) noexcept = 0;
            virtual int32_t __stdcall get_MasterGain(double*) noexcept = 0;
            virtual int32_t __stdcall put_MasterGain(double) noexcept = 0;
            virtual int32_t __stdcall get_IsEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall get_SupportedAxes(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall LoadEffectAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall PauseAllEffects() noexcept = 0;
            virtual int32_t __stdcall ResumeAllEffects() noexcept = 0;
            virtual int32_t __stdcall StopAllEffects() noexcept = 0;
            virtual int32_t __stdcall TryDisableAsync(void**) noexcept = 0;
            virtual int32_t __stdcall TryEnableAsync(void**) noexcept = 0;
            virtual int32_t __stdcall TryResetAsync(void**) noexcept = 0;
            virtual int32_t __stdcall TryUnloadEffectAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::ForceFeedback::IPeriodicForceEffect>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Kind(int32_t*) noexcept = 0;
            virtual int32_t __stdcall SetParameters(llm::OS::Foundation::Numerics::float3, float, float, float, int64_t) noexcept = 0;
            virtual int32_t __stdcall SetParametersWithEnvelope(llm::OS::Foundation::Numerics::float3, float, float, float, float, float, float, int64_t, int64_t, int64_t, int64_t, uint32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::ForceFeedback::IPeriodicForceEffectFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::ForceFeedback::IRampForceEffect>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SetParameters(llm::OS::Foundation::Numerics::float3, llm::OS::Foundation::Numerics::float3, int64_t) noexcept = 0;
            virtual int32_t __stdcall SetParametersWithEnvelope(llm::OS::Foundation::Numerics::float3, llm::OS::Foundation::Numerics::float3, float, float, float, int64_t, int64_t, int64_t, int64_t, uint32_t) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_ForceFeedback_IConditionForceEffect
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Gaming::Input::ForceFeedback::ConditionForceEffectKind) Kind() const;
        LLM_IMPL_AUTO(void) SetParameters(llm::OS::Foundation::Numerics::float3 const& direction, float positiveCoefficient, float negativeCoefficient, float maxPositiveMagnitude, float maxNegativeMagnitude, float deadZone, float bias) const;
    };
    template <> struct consume<llm::OS::Gaming::Input::ForceFeedback::IConditionForceEffect>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_ForceFeedback_IConditionForceEffect<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_ForceFeedback_IConditionForceEffectFactory
    {
        LLM_IMPL_AUTO(llm::OS::Gaming::Input::ForceFeedback::ConditionForceEffect) CreateInstance(llm::OS::Gaming::Input::ForceFeedback::ConditionForceEffectKind const& effectKind) const;
    };
    template <> struct consume<llm::OS::Gaming::Input::ForceFeedback::IConditionForceEffectFactory>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_ForceFeedback_IConditionForceEffectFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_ForceFeedback_IConstantForceEffect
    {
        LLM_IMPL_AUTO(void) SetParameters(llm::OS::Foundation::Numerics::float3 const& vector, llm::OS::Foundation::TimeSpan const& duration) const;
        LLM_IMPL_AUTO(void) SetParametersWithEnvelope(llm::OS::Foundation::Numerics::float3 const& vector, float attackGain, float sustainGain, float releaseGain, llm::OS::Foundation::TimeSpan const& startDelay, llm::OS::Foundation::TimeSpan const& attackDuration, llm::OS::Foundation::TimeSpan const& sustainDuration, llm::OS::Foundation::TimeSpan const& releaseDuration, uint32_t repeatCount) const;
    };
    template <> struct consume<llm::OS::Gaming::Input::ForceFeedback::IConstantForceEffect>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_ForceFeedback_IConstantForceEffect<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_ForceFeedback_IForceFeedbackEffect
    {
        [[nodiscard]] LLM_IMPL_AUTO(double) Gain() const;
        LLM_IMPL_AUTO(void) Gain(double value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Gaming::Input::ForceFeedback::ForceFeedbackEffectState) State() const;
        LLM_IMPL_AUTO(void) Start() const;
        LLM_IMPL_AUTO(void) Stop() const;
    };
    template <> struct consume<llm::OS::Gaming::Input::ForceFeedback::IForceFeedbackEffect>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_ForceFeedback_IForceFeedbackEffect<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_ForceFeedback_IForceFeedbackMotor
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) AreEffectsPaused() const;
        [[nodiscard]] LLM_IMPL_AUTO(double) MasterGain() const;
        LLM_IMPL_AUTO(void) MasterGain(double value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsEnabled() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Gaming::Input::ForceFeedback::ForceFeedbackEffectAxes) SupportedAxes() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Gaming::Input::ForceFeedback::ForceFeedbackLoadEffectResult>) LoadEffectAsync(llm::OS::Gaming::Input::ForceFeedback::IForceFeedbackEffect const& effect) const;
        LLM_IMPL_AUTO(void) PauseAllEffects() const;
        LLM_IMPL_AUTO(void) ResumeAllEffects() const;
        LLM_IMPL_AUTO(void) StopAllEffects() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) TryDisableAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) TryEnableAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) TryResetAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) TryUnloadEffectAsync(llm::OS::Gaming::Input::ForceFeedback::IForceFeedbackEffect const& effect) const;
    };
    template <> struct consume<llm::OS::Gaming::Input::ForceFeedback::IForceFeedbackMotor>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_ForceFeedback_IForceFeedbackMotor<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_ForceFeedback_IPeriodicForceEffect
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Gaming::Input::ForceFeedback::PeriodicForceEffectKind) Kind() const;
        LLM_IMPL_AUTO(void) SetParameters(llm::OS::Foundation::Numerics::float3 const& vector, float frequency, float phase, float bias, llm::OS::Foundation::TimeSpan const& duration) const;
        LLM_IMPL_AUTO(void) SetParametersWithEnvelope(llm::OS::Foundation::Numerics::float3 const& vector, float frequency, float phase, float bias, float attackGain, float sustainGain, float releaseGain, llm::OS::Foundation::TimeSpan const& startDelay, llm::OS::Foundation::TimeSpan const& attackDuration, llm::OS::Foundation::TimeSpan const& sustainDuration, llm::OS::Foundation::TimeSpan const& releaseDuration, uint32_t repeatCount) const;
    };
    template <> struct consume<llm::OS::Gaming::Input::ForceFeedback::IPeriodicForceEffect>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_ForceFeedback_IPeriodicForceEffect<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_ForceFeedback_IPeriodicForceEffectFactory
    {
        LLM_IMPL_AUTO(llm::OS::Gaming::Input::ForceFeedback::PeriodicForceEffect) CreateInstance(llm::OS::Gaming::Input::ForceFeedback::PeriodicForceEffectKind const& effectKind) const;
    };
    template <> struct consume<llm::OS::Gaming::Input::ForceFeedback::IPeriodicForceEffectFactory>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_ForceFeedback_IPeriodicForceEffectFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_ForceFeedback_IRampForceEffect
    {
        LLM_IMPL_AUTO(void) SetParameters(llm::OS::Foundation::Numerics::float3 const& startVector, llm::OS::Foundation::Numerics::float3 const& endVector, llm::OS::Foundation::TimeSpan const& duration) const;
        LLM_IMPL_AUTO(void) SetParametersWithEnvelope(llm::OS::Foundation::Numerics::float3 const& startVector, llm::OS::Foundation::Numerics::float3 const& endVector, float attackGain, float sustainGain, float releaseGain, llm::OS::Foundation::TimeSpan const& startDelay, llm::OS::Foundation::TimeSpan const& attackDuration, llm::OS::Foundation::TimeSpan const& sustainDuration, llm::OS::Foundation::TimeSpan const& releaseDuration, uint32_t repeatCount) const;
    };
    template <> struct consume<llm::OS::Gaming::Input::ForceFeedback::IRampForceEffect>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_ForceFeedback_IRampForceEffect<D>;
    };
}
#endif
