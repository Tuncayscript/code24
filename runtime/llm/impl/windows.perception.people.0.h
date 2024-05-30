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
#ifndef LLM_OS_Perception_People_0_H
#define LLM_OS_Perception_People_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename T> struct __declspec(empty_bases) IReference;
}
LLM_EXPORT namespace llm:OS::Foundation::Numerics
{
}
LLM_EXPORT namespace llm:OS::Perception
{
    struct PerceptionTimestamp;
}
LLM_EXPORT namespace llm:OS::Perception::Spatial
{
    struct SpatialCoordinateSystem;
    struct SpatialRay;
}
LLM_EXPORT namespace llm:OS::UI::Input
{
    enum class GazeInputAccessStatus : int32_t;
}
LLM_EXPORT namespace llm:OS::UI::Input::Spatial
{
    struct SpatialInteractionSource;
}
LLM_EXPORT namespace llm:OS::Perception::People
{
    enum class HandJointKind : int32_t
    {
        Palm = 0,
        Wrist = 1,
        ThumbMetacarpal = 2,
        ThumbProximal = 3,
        ThumbDistal = 4,
        ThumbTip = 5,
        IndexMetacarpal = 6,
        IndexProximal = 7,
        IndexIntermediate = 8,
        IndexDistal = 9,
        IndexTip = 10,
        MiddleMetacarpal = 11,
        MiddleProximal = 12,
        MiddleIntermediate = 13,
        MiddleDistal = 14,
        MiddleTip = 15,
        RingMetacarpal = 16,
        RingProximal = 17,
        RingIntermediate = 18,
        RingDistal = 19,
        RingTip = 20,
        LittleMetacarpal = 21,
        LittleProximal = 22,
        LittleIntermediate = 23,
        LittleDistal = 24,
        LittleTip = 25,
    };
    enum class JointPoseAccuracy : int32_t
    {
        High = 0,
        Approximate = 1,
    };
    struct IEyesPose;
    struct IEyesPoseStatics;
    struct IHandMeshObserver;
    struct IHandMeshVertexState;
    struct IHandPose;
    struct IHeadPose;
    struct EyesPose;
    struct HandMeshObserver;
    struct HandMeshVertexState;
    struct HandPose;
    struct HeadPose;
    struct HandMeshVertex;
    struct JointPose;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Perception::People::IEyesPose>{ using type = interface_category; };
    template <> struct category<llm:OS::Perception::People::IEyesPoseStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Perception::People::IHandMeshObserver>{ using type = interface_category; };
    template <> struct category<llm:OS::Perception::People::IHandMeshVertexState>{ using type = interface_category; };
    template <> struct category<llm:OS::Perception::People::IHandPose>{ using type = interface_category; };
    template <> struct category<llm:OS::Perception::People::IHeadPose>{ using type = interface_category; };
    template <> struct category<llm:OS::Perception::People::EyesPose>{ using type = class_category; };
    template <> struct category<llm:OS::Perception::People::HandMeshObserver>{ using type = class_category; };
    template <> struct category<llm:OS::Perception::People::HandMeshVertexState>{ using type = class_category; };
    template <> struct category<llm:OS::Perception::People::HandPose>{ using type = class_category; };
    template <> struct category<llm:OS::Perception::People::HeadPose>{ using type = class_category; };
    template <> struct category<llm:OS::Perception::People::HandJointKind>{ using type = enum_category; };
    template <> struct category<llm:OS::Perception::People::JointPoseAccuracy>{ using type = enum_category; };
    template <> struct category<llm:OS::Perception::People::HandMeshVertex>{ using type = struct_category<llm:OS::Foundation::Numerics::float3, llm:OS::Foundation::Numerics::float3>; };
    template <> struct category<llm:OS::Perception::People::JointPose>{ using type = struct_category<llm:OS::Foundation::Numerics::quaternion, llm:OS::Foundation::Numerics::float3, float, llm:OS::Perception::People::JointPoseAccuracy>; };
    template <> inline constexpr auto& name_v<llm:OS::Perception::People::EyesPose> = L"Windows.Perception.People.EyesPose";
    template <> inline constexpr auto& name_v<llm:OS::Perception::People::HandMeshObserver> = L"Windows.Perception.People.HandMeshObserver";
    template <> inline constexpr auto& name_v<llm:OS::Perception::People::HandMeshVertexState> = L"Windows.Perception.People.HandMeshVertexState";
    template <> inline constexpr auto& name_v<llm:OS::Perception::People::HandPose> = L"Windows.Perception.People.HandPose";
    template <> inline constexpr auto& name_v<llm:OS::Perception::People::HeadPose> = L"Windows.Perception.People.HeadPose";
    template <> inline constexpr auto& name_v<llm:OS::Perception::People::HandJointKind> = L"Windows.Perception.People.HandJointKind";
    template <> inline constexpr auto& name_v<llm:OS::Perception::People::JointPoseAccuracy> = L"Windows.Perception.People.JointPoseAccuracy";
    template <> inline constexpr auto& name_v<llm:OS::Perception::People::HandMeshVertex> = L"Windows.Perception.People.HandMeshVertex";
    template <> inline constexpr auto& name_v<llm:OS::Perception::People::JointPose> = L"Windows.Perception.People.JointPose";
    template <> inline constexpr auto& name_v<llm:OS::Perception::People::IEyesPose> = L"Windows.Perception.People.IEyesPose";
    template <> inline constexpr auto& name_v<llm:OS::Perception::People::IEyesPoseStatics> = L"Windows.Perception.People.IEyesPoseStatics";
    template <> inline constexpr auto& name_v<llm:OS::Perception::People::IHandMeshObserver> = L"Windows.Perception.People.IHandMeshObserver";
    template <> inline constexpr auto& name_v<llm:OS::Perception::People::IHandMeshVertexState> = L"Windows.Perception.People.IHandMeshVertexState";
    template <> inline constexpr auto& name_v<llm:OS::Perception::People::IHandPose> = L"Windows.Perception.People.IHandPose";
    template <> inline constexpr auto& name_v<llm:OS::Perception::People::IHeadPose> = L"Windows.Perception.People.IHeadPose";
    template <> inline constexpr guid guid_v<llm:OS::Perception::People::IEyesPose>{ 0x682A9B23,0x8A1E,0x5B86,{ 0xA0,0x60,0x90,0x6F,0xFA,0xCB,0x62,0xA4 } }; // 682A9B23-8A1E-5B86-A060-906FFACB62A4
    template <> inline constexpr guid guid_v<llm:OS::Perception::People::IEyesPoseStatics>{ 0x1CFF7413,0xB21F,0x54C0,{ 0x80,0xC1,0xE6,0x0D,0x99,0x4C,0xA5,0x8C } }; // 1CFF7413-B21F-54C0-80C1-E60D994CA58C
    template <> inline constexpr guid guid_v<llm:OS::Perception::People::IHandMeshObserver>{ 0x85AE30CB,0x6FC3,0x55C4,{ 0xA7,0xB4,0x29,0xE3,0x38,0x96,0xCA,0x69 } }; // 85AE30CB-6FC3-55C4-A7B4-29E33896CA69
    template <> inline constexpr guid guid_v<llm:OS::Perception::People::IHandMeshVertexState>{ 0x046C5FEF,0x1D8B,0x55DE,{ 0xAB,0x2C,0x1C,0xD4,0x24,0x88,0x6D,0x8F } }; // 046C5FEF-1D8B-55DE-AB2C-1CD424886D8F
    template <> inline constexpr guid guid_v<llm:OS::Perception::People::IHandPose>{ 0x4D98E79A,0xBB08,0x5D09,{ 0x91,0xDE,0xDF,0x0D,0xD3,0xFA,0xE4,0x6C } }; // 4D98E79A-BB08-5D09-91DE-DF0DD3FAE46C
    template <> inline constexpr guid guid_v<llm:OS::Perception::People::IHeadPose>{ 0x7F5AC5A5,0x49DB,0x379F,{ 0x94,0x29,0x32,0xA2,0xFA,0xF3,0x4F,0xA6 } }; // 7F5AC5A5-49DB-379F-9429-32A2FAF34FA6
    template <> struct default_interface<llm:OS::Perception::People::EyesPose>{ using type = llm:OS::Perception::People::IEyesPose; };
    template <> struct default_interface<llm:OS::Perception::People::HandMeshObserver>{ using type = llm:OS::Perception::People::IHandMeshObserver; };
    template <> struct default_interface<llm:OS::Perception::People::HandMeshVertexState>{ using type = llm:OS::Perception::People::IHandMeshVertexState; };
    template <> struct default_interface<llm:OS::Perception::People::HandPose>{ using type = llm:OS::Perception::People::IHandPose; };
    template <> struct default_interface<llm:OS::Perception::People::HeadPose>{ using type = llm:OS::Perception::People::IHeadPose; };
    template <> struct abi<llm:OS::Perception::People::IEyesPose>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsCalibrationValid(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Gaze(void**) noexcept = 0;
            virtual int32_t __stdcall get_UpdateTimestamp(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Perception::People::IEyesPoseStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall IsSupported(bool*) noexcept = 0;
            virtual int32_t __stdcall RequestAccessAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Perception::People::IHandMeshObserver>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Source(void**) noexcept = 0;
            virtual int32_t __stdcall get_TriangleIndexCount(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_VertexCount(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall GetTriangleIndices(uint32_t, uint16_t*) noexcept = 0;
            virtual int32_t __stdcall GetVertexStateForPose(void*, void**) noexcept = 0;
            virtual int32_t __stdcall get_NeutralPose(void**) noexcept = 0;
            virtual int32_t __stdcall get_NeutralPoseVersion(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ModelId(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Perception::People::IHandMeshVertexState>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_CoordinateSystem(void**) noexcept = 0;
            virtual int32_t __stdcall GetVertices(uint32_t, struct struct_Windows_Perception_People_HandMeshVertex*) noexcept = 0;
            virtual int32_t __stdcall get_UpdateTimestamp(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Perception::People::IHandPose>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall TryGetJoint(void*, int32_t, struct struct_Windows_Perception_People_JointPose*, bool*) noexcept = 0;
            virtual int32_t __stdcall TryGetJoints(void*, uint32_t, int32_t*, uint32_t, struct struct_Windows_Perception_People_JointPose*, bool*) noexcept = 0;
            virtual int32_t __stdcall GetRelativeJoint(int32_t, int32_t, struct struct_Windows_Perception_People_JointPose*) noexcept = 0;
            virtual int32_t __stdcall GetRelativeJoints(uint32_t, int32_t*, uint32_t, int32_t*, uint32_t, struct struct_Windows_Perception_People_JointPose*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Perception::People::IHeadPose>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Position(llm:OS::Foundation::Numerics::float3*) noexcept = 0;
            virtual int32_t __stdcall get_ForwardDirection(llm:OS::Foundation::Numerics::float3*) noexcept = 0;
            virtual int32_t __stdcall get_UpDirection(llm:OS::Foundation::Numerics::float3*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Perception_People_IEyesPose
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsCalibrationValid() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IReference<llm:OS::Perception::Spatial::SpatialRay>) Gaze() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Perception::PerceptionTimestamp) UpdateTimestamp() const;
    };
    template <> struct consume<llm:OS::Perception::People::IEyesPose>
    {
        template <typename D> using type = consume_Windows_Perception_People_IEyesPose<D>;
    };
    template <typename D>
    struct consume_Windows_Perception_People_IEyesPoseStatics
    {
        LLM_IMPL_AUTO(bool) IsSupported() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::UI::Input::GazeInputAccessStatus>) RequestAccessAsync() const;
    };
    template <> struct consume<llm:OS::Perception::People::IEyesPoseStatics>
    {
        template <typename D> using type = consume_Windows_Perception_People_IEyesPoseStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Perception_People_IHandMeshObserver
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Input::Spatial::SpatialInteractionSource) Source() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) TriangleIndexCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) VertexCount() const;
        LLM_IMPL_AUTO(void) GetTriangleIndices(array_view<uint16_t> indices) const;
        LLM_IMPL_AUTO(llm:OS::Perception::People::HandMeshVertexState) GetVertexStateForPose(llm:OS::Perception::People::HandPose const& handPose) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Perception::People::HandPose) NeutralPose() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) NeutralPoseVersion() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) ModelId() const;
    };
    template <> struct consume<llm:OS::Perception::People::IHandMeshObserver>
    {
        template <typename D> using type = consume_Windows_Perception_People_IHandMeshObserver<D>;
    };
    template <typename D>
    struct consume_Windows_Perception_People_IHandMeshVertexState
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Perception::Spatial::SpatialCoordinateSystem) CoordinateSystem() const;
        LLM_IMPL_AUTO(void) GetVertices(array_view<llm:OS::Perception::People::HandMeshVertex> vertices) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Perception::PerceptionTimestamp) UpdateTimestamp() const;
    };
    template <> struct consume<llm:OS::Perception::People::IHandMeshVertexState>
    {
        template <typename D> using type = consume_Windows_Perception_People_IHandMeshVertexState<D>;
    };
    template <typename D>
    struct consume_Windows_Perception_People_IHandPose
    {
        LLM_IMPL_AUTO(bool) TryGetJoint(llm:OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm:OS::Perception::People::HandJointKind const& joint, llm:OS::Perception::People::JointPose& jointPose) const;
        LLM_IMPL_AUTO(bool) TryGetJoints(llm:OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, array_view<llm:OS::Perception::People::HandJointKind const> joints, array_view<llm:OS::Perception::People::JointPose> jointPoses) const;
        LLM_IMPL_AUTO(llm:OS::Perception::People::JointPose) GetRelativeJoint(llm:OS::Perception::People::HandJointKind const& joint, llm:OS::Perception::People::HandJointKind const& referenceJoint) const;
        LLM_IMPL_AUTO(void) GetRelativeJoints(array_view<llm:OS::Perception::People::HandJointKind const> joints, array_view<llm:OS::Perception::People::HandJointKind const> referenceJoints, array_view<llm:OS::Perception::People::JointPose> jointPoses) const;
    };
    template <> struct consume<llm:OS::Perception::People::IHandPose>
    {
        template <typename D> using type = consume_Windows_Perception_People_IHandPose<D>;
    };
    template <typename D>
    struct consume_Windows_Perception_People_IHeadPose
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float3) Position() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float3) ForwardDirection() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float3) UpDirection() const;
    };
    template <> struct consume<llm:OS::Perception::People::IHeadPose>
    {
        template <typename D> using type = consume_Windows_Perception_People_IHeadPose<D>;
    };
    struct struct_Windows_Perception_People_HandMeshVertex
    {
        llm:OS::Foundation::Numerics::float3 Position;
        llm:OS::Foundation::Numerics::float3 Normal;
    };
    template <> struct abi<Windows::Perception::People::HandMeshVertex>
    {
        using type = struct_Windows_Perception_People_HandMeshVertex;
    };
    struct struct_Windows_Perception_People_JointPose
    {
        llm:OS::Foundation::Numerics::quaternion Orientation;
        llm:OS::Foundation::Numerics::float3 Position;
        float Radius;
        int32_t Accuracy;
    };
    template <> struct abi<Windows::Perception::People::JointPose>
    {
        using type = struct_Windows_Perception_People_JointPose;
    };
}
#endif
