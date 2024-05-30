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
#ifndef LLM_OS_Perception_Spatial_Preview_2_H
#define LLM_OS_Perception_Spatial_Preview_2_H
#include "llm/impl/Windows.Foundation.Numerics.1.h"
#include "llm/impl/Windows.Perception.Spatial.1.h"
#include "llm/impl/Windows.Perception.Spatial.Preview.1.h"
LLM_EXPORT namespace llm:OS::Perception::Spatial::Preview
{
    struct __declspec(empty_bases) SpatialGraphInteropFrameOfReferencePreview : llm:OS::Perception::Spatial::Preview::ISpatialGraphInteropFrameOfReferencePreview
    {
        SpatialGraphInteropFrameOfReferencePreview(std::nullptr_t) noexcept {}
        SpatialGraphInteropFrameOfReferencePreview(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Perception::Spatial::Preview::ISpatialGraphInteropFrameOfReferencePreview(ptr, take_ownership_from_abi) {}
    };
    struct SpatialGraphInteropPreview
    {
        SpatialGraphInteropPreview() = delete;
        static auto CreateCoordinateSystemForNode(llm::guid const& nodeId);
        static auto CreateCoordinateSystemForNode(llm::guid const& nodeId, llm:OS::Foundation::Numerics::float3 const& relativePosition);
        static auto CreateCoordinateSystemForNode(llm::guid const& nodeId, llm:OS::Foundation::Numerics::float3 const& relativePosition, llm:OS::Foundation::Numerics::quaternion const& relativeOrientation);
        static auto CreateLocatorForNode(llm::guid const& nodeId);
        static auto TryCreateFrameOfReference(llm:OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem);
        static auto TryCreateFrameOfReference(llm:OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm:OS::Foundation::Numerics::float3 const& relativePosition);
        static auto TryCreateFrameOfReference(llm:OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm:OS::Foundation::Numerics::float3 const& relativePosition, llm:OS::Foundation::Numerics::quaternion const& relativeOrientation);
    };
}
#endif
