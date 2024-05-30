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
#ifndef LLM_OS_Perception_Spatial_Preview_0_H
#define LLM_OS_Perception_Spatial_Preview_0_H
LLM_EXPORT namespace llm:OS::Foundation::Numerics
{
}
LLM_EXPORT namespace llm:OS::Perception::Spatial
{
    struct SpatialCoordinateSystem;
    struct SpatialLocator;
}
LLM_EXPORT namespace llm:OS::Perception::Spatial::Preview
{
    struct ISpatialGraphInteropFrameOfReferencePreview;
    struct ISpatialGraphInteropPreviewStatics;
    struct ISpatialGraphInteropPreviewStatics2;
    struct SpatialGraphInteropFrameOfReferencePreview;
    struct SpatialGraphInteropPreview;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Perception::Spatial::Preview::ISpatialGraphInteropFrameOfReferencePreview>{ using type = interface_category; };
    template <> struct category<llm:OS::Perception::Spatial::Preview::ISpatialGraphInteropPreviewStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Perception::Spatial::Preview::ISpatialGraphInteropPreviewStatics2>{ using type = interface_category; };
    template <> struct category<llm:OS::Perception::Spatial::Preview::SpatialGraphInteropFrameOfReferencePreview>{ using type = class_category; };
    template <> struct category<llm:OS::Perception::Spatial::Preview::SpatialGraphInteropPreview>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm:OS::Perception::Spatial::Preview::SpatialGraphInteropFrameOfReferencePreview> = L"Windows.Perception.Spatial.Preview.SpatialGraphInteropFrameOfReferencePreview";
    template <> inline constexpr auto& name_v<llm:OS::Perception::Spatial::Preview::SpatialGraphInteropPreview> = L"Windows.Perception.Spatial.Preview.SpatialGraphInteropPreview";
    template <> inline constexpr auto& name_v<llm:OS::Perception::Spatial::Preview::ISpatialGraphInteropFrameOfReferencePreview> = L"Windows.Perception.Spatial.Preview.ISpatialGraphInteropFrameOfReferencePreview";
    template <> inline constexpr auto& name_v<llm:OS::Perception::Spatial::Preview::ISpatialGraphInteropPreviewStatics> = L"Windows.Perception.Spatial.Preview.ISpatialGraphInteropPreviewStatics";
    template <> inline constexpr auto& name_v<llm:OS::Perception::Spatial::Preview::ISpatialGraphInteropPreviewStatics2> = L"Windows.Perception.Spatial.Preview.ISpatialGraphInteropPreviewStatics2";
    template <> inline constexpr guid guid_v<llm:OS::Perception::Spatial::Preview::ISpatialGraphInteropFrameOfReferencePreview>{ 0xA8271B23,0x735F,0x5729,{ 0xA9,0x8E,0xE6,0x4E,0xD1,0x89,0xAB,0xC5 } }; // A8271B23-735F-5729-A98E-E64ED189ABC5
    template <> inline constexpr guid guid_v<llm:OS::Perception::Spatial::Preview::ISpatialGraphInteropPreviewStatics>{ 0xC042644C,0x20D8,0x4ED0,{ 0xAE,0xF7,0x68,0x05,0xB8,0xE5,0x3F,0x55 } }; // C042644C-20D8-4ED0-AEF7-6805B8E53F55
    template <> inline constexpr guid guid_v<llm:OS::Perception::Spatial::Preview::ISpatialGraphInteropPreviewStatics2>{ 0x2490B15F,0x6CBD,0x4B1E,{ 0xB7,0x65,0x31,0xE4,0x62,0xA3,0x2D,0xF2 } }; // 2490B15F-6CBD-4B1E-B765-31E462A32DF2
    template <> struct default_interface<llm:OS::Perception::Spatial::Preview::SpatialGraphInteropFrameOfReferencePreview>{ using type = llm:OS::Perception::Spatial::Preview::ISpatialGraphInteropFrameOfReferencePreview; };
    template <> struct abi<llm:OS::Perception::Spatial::Preview::ISpatialGraphInteropFrameOfReferencePreview>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_CoordinateSystem(void**) noexcept = 0;
            virtual int32_t __stdcall get_NodeId(llm::guid*) noexcept = 0;
            virtual int32_t __stdcall get_CoordinateSystemToNodeTransform(llm:OS::Foundation::Numerics::float4x4*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Perception::Spatial::Preview::ISpatialGraphInteropPreviewStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateCoordinateSystemForNode(llm::guid, void**) noexcept = 0;
            virtual int32_t __stdcall CreateCoordinateSystemForNodeWithPosition(llm::guid, llm:OS::Foundation::Numerics::float3, void**) noexcept = 0;
            virtual int32_t __stdcall CreateCoordinateSystemForNodeWithPositionAndOrientation(llm::guid, llm:OS::Foundation::Numerics::float3, llm:OS::Foundation::Numerics::quaternion, void**) noexcept = 0;
            virtual int32_t __stdcall CreateLocatorForNode(llm::guid, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Perception::Spatial::Preview::ISpatialGraphInteropPreviewStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall TryCreateFrameOfReference(void*, void**) noexcept = 0;
            virtual int32_t __stdcall TryCreateFrameOfReferenceWithPosition(void*, llm:OS::Foundation::Numerics::float3, void**) noexcept = 0;
            virtual int32_t __stdcall TryCreateFrameOfReferenceWithPositionAndOrientation(void*, llm:OS::Foundation::Numerics::float3, llm:OS::Foundation::Numerics::quaternion, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Perception_Spatial_Preview_ISpatialGraphInteropFrameOfReferencePreview
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Perception::Spatial::SpatialCoordinateSystem) CoordinateSystem() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::guid) NodeId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float4x4) CoordinateSystemToNodeTransform() const;
    };
    template <> struct consume<llm:OS::Perception::Spatial::Preview::ISpatialGraphInteropFrameOfReferencePreview>
    {
        template <typename D> using type = consume_Windows_Perception_Spatial_Preview_ISpatialGraphInteropFrameOfReferencePreview<D>;
    };
    template <typename D>
    struct consume_Windows_Perception_Spatial_Preview_ISpatialGraphInteropPreviewStatics
    {
        LLM_IMPL_AUTO(llm:OS::Perception::Spatial::SpatialCoordinateSystem) CreateCoordinateSystemForNode(llm::guid const& nodeId) const;
        LLM_IMPL_AUTO(llm:OS::Perception::Spatial::SpatialCoordinateSystem) CreateCoordinateSystemForNode(llm::guid const& nodeId, llm:OS::Foundation::Numerics::float3 const& relativePosition) const;
        LLM_IMPL_AUTO(llm:OS::Perception::Spatial::SpatialCoordinateSystem) CreateCoordinateSystemForNode(llm::guid const& nodeId, llm:OS::Foundation::Numerics::float3 const& relativePosition, llm:OS::Foundation::Numerics::quaternion const& relativeOrientation) const;
        LLM_IMPL_AUTO(llm:OS::Perception::Spatial::SpatialLocator) CreateLocatorForNode(llm::guid const& nodeId) const;
    };
    template <> struct consume<llm:OS::Perception::Spatial::Preview::ISpatialGraphInteropPreviewStatics>
    {
        template <typename D> using type = consume_Windows_Perception_Spatial_Preview_ISpatialGraphInteropPreviewStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Perception_Spatial_Preview_ISpatialGraphInteropPreviewStatics2
    {
        LLM_IMPL_AUTO(llm:OS::Perception::Spatial::Preview::SpatialGraphInteropFrameOfReferencePreview) TryCreateFrameOfReference(llm:OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem) const;
        LLM_IMPL_AUTO(llm:OS::Perception::Spatial::Preview::SpatialGraphInteropFrameOfReferencePreview) TryCreateFrameOfReference(llm:OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm:OS::Foundation::Numerics::float3 const& relativePosition) const;
        LLM_IMPL_AUTO(llm:OS::Perception::Spatial::Preview::SpatialGraphInteropFrameOfReferencePreview) TryCreateFrameOfReference(llm:OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm:OS::Foundation::Numerics::float3 const& relativePosition, llm:OS::Foundation::Numerics::quaternion const& relativeOrientation) const;
    };
    template <> struct consume<llm:OS::Perception::Spatial::Preview::ISpatialGraphInteropPreviewStatics2>
    {
        template <typename D> using type = consume_Windows_Perception_Spatial_Preview_ISpatialGraphInteropPreviewStatics2<D>;
    };
}
#endif
