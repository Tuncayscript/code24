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
#ifndef LLM_OS_Gaming_Input_ForceFeedback_1_H
#define LLM_OS_Gaming_Input_ForceFeedback_1_H
#include "llm/impl/Windows.Gaming.Input.ForceFeedback.0.h"
LLM_EXPORT namespace llm::OS::Gaming::Input::ForceFeedback
{
    struct __declspec(empty_bases) IConditionForceEffect :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IConditionForceEffect>,
        impl::require<llm::OS::Gaming::Input::ForceFeedback::IConditionForceEffect, llm::OS::Gaming::Input::ForceFeedback::IForceFeedbackEffect>
    {
        IConditionForceEffect(std::nullptr_t = nullptr) noexcept {}
        IConditionForceEffect(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IConditionForceEffectFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IConditionForceEffectFactory>
    {
        IConditionForceEffectFactory(std::nullptr_t = nullptr) noexcept {}
        IConditionForceEffectFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IConstantForceEffect :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IConstantForceEffect>,
        impl::require<llm::OS::Gaming::Input::ForceFeedback::IConstantForceEffect, llm::OS::Gaming::Input::ForceFeedback::IForceFeedbackEffect>
    {
        IConstantForceEffect(std::nullptr_t = nullptr) noexcept {}
        IConstantForceEffect(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IForceFeedbackEffect :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IForceFeedbackEffect>
    {
        IForceFeedbackEffect(std::nullptr_t = nullptr) noexcept {}
        IForceFeedbackEffect(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IForceFeedbackMotor :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IForceFeedbackMotor>
    {
        IForceFeedbackMotor(std::nullptr_t = nullptr) noexcept {}
        IForceFeedbackMotor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPeriodicForceEffect :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPeriodicForceEffect>,
        impl::require<llm::OS::Gaming::Input::ForceFeedback::IPeriodicForceEffect, llm::OS::Gaming::Input::ForceFeedback::IForceFeedbackEffect>
    {
        IPeriodicForceEffect(std::nullptr_t = nullptr) noexcept {}
        IPeriodicForceEffect(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPeriodicForceEffectFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPeriodicForceEffectFactory>
    {
        IPeriodicForceEffectFactory(std::nullptr_t = nullptr) noexcept {}
        IPeriodicForceEffectFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRampForceEffect :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IRampForceEffect>,
        impl::require<llm::OS::Gaming::Input::ForceFeedback::IRampForceEffect, llm::OS::Gaming::Input::ForceFeedback::IForceFeedbackEffect>
    {
        IRampForceEffect(std::nullptr_t = nullptr) noexcept {}
        IRampForceEffect(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
