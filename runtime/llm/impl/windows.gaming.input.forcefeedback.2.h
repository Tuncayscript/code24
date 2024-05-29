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
#ifndef LLM_OS_Gaming_Input_ForceFeedback_2_H
#define LLM_OS_Gaming_Input_ForceFeedback_2_H
#include "llm/impl/Windows.Gaming.Input.ForceFeedback.1.h"
LLM_EXPORT namespace llm::OS::Gaming::Input::ForceFeedback
{
    struct __declspec(empty_bases) ConditionForceEffect : llm::OS::Gaming::Input::ForceFeedback::IForceFeedbackEffect,
        impl::require<ConditionForceEffect, llm::OS::Gaming::Input::ForceFeedback::IConditionForceEffect>
    {
        ConditionForceEffect(std::nullptr_t) noexcept {}
        ConditionForceEffect(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Gaming::Input::ForceFeedback::IForceFeedbackEffect(ptr, take_ownership_from_abi) {}
        explicit ConditionForceEffect(llm::OS::Gaming::Input::ForceFeedback::ConditionForceEffectKind const& effectKind);
    };
    struct __declspec(empty_bases) ConstantForceEffect : llm::OS::Gaming::Input::ForceFeedback::IForceFeedbackEffect,
        impl::require<ConstantForceEffect, llm::OS::Gaming::Input::ForceFeedback::IConstantForceEffect>
    {
        ConstantForceEffect(std::nullptr_t) noexcept {}
        ConstantForceEffect(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Gaming::Input::ForceFeedback::IForceFeedbackEffect(ptr, take_ownership_from_abi) {}
        ConstantForceEffect();
    };
    struct __declspec(empty_bases) ForceFeedbackMotor : llm::OS::Gaming::Input::ForceFeedback::IForceFeedbackMotor
    {
        ForceFeedbackMotor(std::nullptr_t) noexcept {}
        ForceFeedbackMotor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Gaming::Input::ForceFeedback::IForceFeedbackMotor(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PeriodicForceEffect : llm::OS::Gaming::Input::ForceFeedback::IForceFeedbackEffect,
        impl::require<PeriodicForceEffect, llm::OS::Gaming::Input::ForceFeedback::IPeriodicForceEffect>
    {
        PeriodicForceEffect(std::nullptr_t) noexcept {}
        PeriodicForceEffect(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Gaming::Input::ForceFeedback::IForceFeedbackEffect(ptr, take_ownership_from_abi) {}
        explicit PeriodicForceEffect(llm::OS::Gaming::Input::ForceFeedback::PeriodicForceEffectKind const& effectKind);
    };
    struct __declspec(empty_bases) RampForceEffect : llm::OS::Gaming::Input::ForceFeedback::IForceFeedbackEffect,
        impl::require<RampForceEffect, llm::OS::Gaming::Input::ForceFeedback::IRampForceEffect>
    {
        RampForceEffect(std::nullptr_t) noexcept {}
        RampForceEffect(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Gaming::Input::ForceFeedback::IForceFeedbackEffect(ptr, take_ownership_from_abi) {}
        RampForceEffect();
    };
}
#endif
