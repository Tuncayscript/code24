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
#ifndef LLM_OS_Perception_People_2_H
#define LLM_OS_Perception_People_2_H
#include "llm/impl/Windows.Foundation.Numerics.2.h"
#include "llm/impl/Windows.Perception.People.1.h"
LLM_EXPORT namespace llm:OS::Perception::People
{
    struct HandMeshVertex
    {
        llm:OS::Foundation::Numerics::float3 Position;
        llm:OS::Foundation::Numerics::float3 Normal;
    };
    inline bool operator==(HandMeshVertex const& left, HandMeshVertex const& right) noexcept
    {
        return left.Position == right.Position && left.Normal == right.Normal;
    }
    inline bool operator!=(HandMeshVertex const& left, HandMeshVertex const& right) noexcept
    {
        return !(left == right);
    }
    struct JointPose
    {
        llm:OS::Foundation::Numerics::quaternion Orientation;
        llm:OS::Foundation::Numerics::float3 Position;
        float Radius;
        llm:OS::Perception::People::JointPoseAccuracy Accuracy;
    };
    inline bool operator==(JointPose const& left, JointPose const& right) noexcept
    {
        return left.Orientation == right.Orientation && left.Position == right.Position && left.Radius == right.Radius && left.Accuracy == right.Accuracy;
    }
    inline bool operator!=(JointPose const& left, JointPose const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) EyesPose : llm:OS::Perception::People::IEyesPose
    {
        EyesPose(std::nullptr_t) noexcept {}
        EyesPose(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Perception::People::IEyesPose(ptr, take_ownership_from_abi) {}
        static auto IsSupported();
        static auto RequestAccessAsync();
    };
    struct __declspec(empty_bases) HandMeshObserver : llm:OS::Perception::People::IHandMeshObserver
    {
        HandMeshObserver(std::nullptr_t) noexcept {}
        HandMeshObserver(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Perception::People::IHandMeshObserver(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HandMeshVertexState : llm:OS::Perception::People::IHandMeshVertexState
    {
        HandMeshVertexState(std::nullptr_t) noexcept {}
        HandMeshVertexState(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Perception::People::IHandMeshVertexState(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HandPose : llm:OS::Perception::People::IHandPose
    {
        HandPose(std::nullptr_t) noexcept {}
        HandPose(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Perception::People::IHandPose(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HeadPose : llm:OS::Perception::People::IHeadPose
    {
        HeadPose(std::nullptr_t) noexcept {}
        HeadPose(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Perception::People::IHeadPose(ptr, take_ownership_from_abi) {}
    };
}
#endif
