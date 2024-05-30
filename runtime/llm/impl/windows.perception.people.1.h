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
#ifndef LLM_OS_Perception_People_1_H
#define LLM_OS_Perception_People_1_H
#include "llm/impl/Windows.Perception.People.0.h"
LLM_EXPORT namespace llm:OS::Perception::People
{
    struct __declspec(empty_bases) IEyesPose :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IEyesPose>
    {
        IEyesPose(std::nullptr_t = nullptr) noexcept {}
        IEyesPose(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEyesPoseStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IEyesPoseStatics>
    {
        IEyesPoseStatics(std::nullptr_t = nullptr) noexcept {}
        IEyesPoseStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHandMeshObserver :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHandMeshObserver>
    {
        IHandMeshObserver(std::nullptr_t = nullptr) noexcept {}
        IHandMeshObserver(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHandMeshVertexState :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHandMeshVertexState>
    {
        IHandMeshVertexState(std::nullptr_t = nullptr) noexcept {}
        IHandMeshVertexState(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHandPose :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHandPose>
    {
        IHandPose(std::nullptr_t = nullptr) noexcept {}
        IHandPose(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHeadPose :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHeadPose>
    {
        IHeadPose(std::nullptr_t = nullptr) noexcept {}
        IHeadPose(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
