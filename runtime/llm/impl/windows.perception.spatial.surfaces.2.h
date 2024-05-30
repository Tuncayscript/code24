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
#ifndef LLM_OS_Perception_Spatial_Surfaces_2_H
#define LLM_OS_Perception_Spatial_Surfaces_2_H
#include "llm/impl/Windows.Perception.Spatial.Surfaces.1.h"
LLM_EXPORT namespace llm:OS::Perception::Spatial::Surfaces
{
    struct __declspec(empty_bases) SpatialSurfaceInfo : llm:OS::Perception::Spatial::Surfaces::ISpatialSurfaceInfo
    {
        SpatialSurfaceInfo(std::nullptr_t) noexcept {}
        SpatialSurfaceInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Perception::Spatial::Surfaces::ISpatialSurfaceInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialSurfaceMesh : llm:OS::Perception::Spatial::Surfaces::ISpatialSurfaceMesh
    {
        SpatialSurfaceMesh(std::nullptr_t) noexcept {}
        SpatialSurfaceMesh(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Perception::Spatial::Surfaces::ISpatialSurfaceMesh(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialSurfaceMeshBuffer : llm:OS::Perception::Spatial::Surfaces::ISpatialSurfaceMeshBuffer
    {
        SpatialSurfaceMeshBuffer(std::nullptr_t) noexcept {}
        SpatialSurfaceMeshBuffer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Perception::Spatial::Surfaces::ISpatialSurfaceMeshBuffer(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialSurfaceMeshOptions : llm:OS::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptions
    {
        SpatialSurfaceMeshOptions(std::nullptr_t) noexcept {}
        SpatialSurfaceMeshOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptions(ptr, take_ownership_from_abi) {}
        SpatialSurfaceMeshOptions();
        [[nodiscard]] static auto SupportedVertexPositionFormats();
        [[nodiscard]] static auto SupportedTriangleIndexFormats();
        [[nodiscard]] static auto SupportedVertexNormalFormats();
    };
    struct __declspec(empty_bases) SpatialSurfaceObserver : llm:OS::Perception::Spatial::Surfaces::ISpatialSurfaceObserver
    {
        SpatialSurfaceObserver(std::nullptr_t) noexcept {}
        SpatialSurfaceObserver(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Perception::Spatial::Surfaces::ISpatialSurfaceObserver(ptr, take_ownership_from_abi) {}
        SpatialSurfaceObserver();
        static auto RequestAccessAsync();
        static auto IsSupported();
    };
}
#endif
