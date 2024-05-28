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
#ifndef LLM_OS_Perception_People_H
#define LLM_OS_Perception_People_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Perception.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Numerics.2.h"
#include "llm/impl/Windows.Perception.2.h"
#include "llm/impl/Windows.Perception.Spatial.2.h"
#include "llm/impl/Windows.UI.Input.2.h"
#include "llm/impl/Windows.UI.Input.Spatial.2.h"
#include "llm/impl/Windows.Perception.People.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Perception_People_IEyesPose<D>::IsCalibrationValid() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::People::IEyesPose)->get_IsCalibrationValid(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Perception::Spatial::SpatialRay>) consume_Windows_Perception_People_IEyesPose<D>::Gaze() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::People::IEyesPose)->get_Gaze(&value));
        return llm::OS::Foundation::IReference<llm::OS::Perception::Spatial::SpatialRay>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::PerceptionTimestamp) consume_Windows_Perception_People_IEyesPose<D>::UpdateTimestamp() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::People::IEyesPose)->get_UpdateTimestamp(&value));
        return llm::OS::Perception::PerceptionTimestamp{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Perception_People_IEyesPoseStatics<D>::IsSupported() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::People::IEyesPoseStatics)->IsSupported(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::UI::Input::GazeInputAccessStatus>) consume_Windows_Perception_People_IEyesPoseStatics<D>::RequestAccessAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::People::IEyesPoseStatics)->RequestAccessAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::UI::Input::GazeInputAccessStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Input::Spatial::SpatialInteractionSource) consume_Windows_Perception_People_IHandMeshObserver<D>::Source() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::People::IHandMeshObserver)->get_Source(&value));
        return llm::OS::UI::Input::Spatial::SpatialInteractionSource{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Perception_People_IHandMeshObserver<D>::TriangleIndexCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::People::IHandMeshObserver)->get_TriangleIndexCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Perception_People_IHandMeshObserver<D>::VertexCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::People::IHandMeshObserver)->get_VertexCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Perception_People_IHandMeshObserver<D>::GetTriangleIndices(array_view<uint16_t> indices) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::People::IHandMeshObserver)->GetTriangleIndices(indices.size(), put_abi(indices)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::People::HandMeshVertexState) consume_Windows_Perception_People_IHandMeshObserver<D>::GetVertexStateForPose(llm::OS::Perception::People::HandPose const& handPose) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::People::IHandMeshObserver)->GetVertexStateForPose(*(void**)(&handPose), &result));
        return llm::OS::Perception::People::HandMeshVertexState{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::People::HandPose) consume_Windows_Perception_People_IHandMeshObserver<D>::NeutralPose() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::People::IHandMeshObserver)->get_NeutralPose(&value));
        return llm::OS::Perception::People::HandPose{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Perception_People_IHandMeshObserver<D>::NeutralPoseVersion() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::People::IHandMeshObserver)->get_NeutralPoseVersion(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Perception_People_IHandMeshObserver<D>::ModelId() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::People::IHandMeshObserver)->get_ModelId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialCoordinateSystem) consume_Windows_Perception_People_IHandMeshVertexState<D>::CoordinateSystem() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::People::IHandMeshVertexState)->get_CoordinateSystem(&value));
        return llm::OS::Perception::Spatial::SpatialCoordinateSystem{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Perception_People_IHandMeshVertexState<D>::GetVertices(array_view<llm::OS::Perception::People::HandMeshVertex> vertices) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::People::IHandMeshVertexState)->GetVertices(vertices.size(), put_abi(vertices)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::PerceptionTimestamp) consume_Windows_Perception_People_IHandMeshVertexState<D>::UpdateTimestamp() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::People::IHandMeshVertexState)->get_UpdateTimestamp(&value));
        return llm::OS::Perception::PerceptionTimestamp{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Perception_People_IHandPose<D>::TryGetJoint(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm::OS::Perception::People::HandJointKind const& joint, llm::OS::Perception::People::JointPose& jointPose) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::People::IHandPose)->TryGetJoint(*(void**)(&coordinateSystem), static_cast<int32_t>(joint), impl::bind_out(jointPose), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Perception_People_IHandPose<D>::TryGetJoints(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, array_view<llm::OS::Perception::People::HandJointKind const> joints, array_view<llm::OS::Perception::People::JointPose> jointPoses) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::People::IHandPose)->TryGetJoints(*(void**)(&coordinateSystem), joints.size(), get_abi(joints), jointPoses.size(), put_abi(jointPoses), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::People::JointPose) consume_Windows_Perception_People_IHandPose<D>::GetRelativeJoint(llm::OS::Perception::People::HandJointKind const& joint, llm::OS::Perception::People::HandJointKind const& referenceJoint) const
    {
        llm::OS::Perception::People::JointPose result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::People::IHandPose)->GetRelativeJoint(static_cast<int32_t>(joint), static_cast<int32_t>(referenceJoint), put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Perception_People_IHandPose<D>::GetRelativeJoints(array_view<llm::OS::Perception::People::HandJointKind const> joints, array_view<llm::OS::Perception::People::HandJointKind const> referenceJoints, array_view<llm::OS::Perception::People::JointPose> jointPoses) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::People::IHandPose)->GetRelativeJoints(joints.size(), get_abi(joints), referenceJoints.size(), get_abi(referenceJoints), jointPoses.size(), put_abi(jointPoses)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_Perception_People_IHeadPose<D>::Position() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::People::IHeadPose)->get_Position(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_Perception_People_IHeadPose<D>::ForwardDirection() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::People::IHeadPose)->get_ForwardDirection(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_Perception_People_IHeadPose<D>::UpDirection() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::People::IHeadPose)->get_UpDirection(put_abi(value)));
        return value;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::People::IEyesPose> : produce_base<D, llm::OS::Perception::People::IEyesPose>
    {
        int32_t __stdcall get_IsCalibrationValid(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsCalibrationValid());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Gaze(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Perception::Spatial::SpatialRay>>(this->shim().Gaze());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UpdateTimestamp(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::PerceptionTimestamp>(this->shim().UpdateTimestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::People::IEyesPoseStatics> : produce_base<D, llm::OS::Perception::People::IEyesPoseStatics>
    {
        int32_t __stdcall IsSupported(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestAccessAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::UI::Input::GazeInputAccessStatus>>(this->shim().RequestAccessAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::People::IHandMeshObserver> : produce_base<D, llm::OS::Perception::People::IHandMeshObserver>
    {
        int32_t __stdcall get_Source(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Input::Spatial::SpatialInteractionSource>(this->shim().Source());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TriangleIndexCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().TriangleIndexCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VertexCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().VertexCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetTriangleIndices(uint32_t __indicesSize, uint16_t* indices) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GetTriangleIndices(array_view<uint16_t>(reinterpret_cast<uint16_t*>(indices), reinterpret_cast<uint16_t*>(indices) + __indicesSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetVertexStateForPose(void* handPose, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Perception::People::HandMeshVertexState>(this->shim().GetVertexStateForPose(*reinterpret_cast<llm::OS::Perception::People::HandPose const*>(&handPose)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NeutralPose(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::People::HandPose>(this->shim().NeutralPose());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NeutralPoseVersion(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().NeutralPoseVersion());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ModelId(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().ModelId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::People::IHandMeshVertexState> : produce_base<D, llm::OS::Perception::People::IHandMeshVertexState>
    {
        int32_t __stdcall get_CoordinateSystem(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialCoordinateSystem>(this->shim().CoordinateSystem());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetVertices(uint32_t __verticesSize, struct struct_Windows_Perception_People_HandMeshVertex* vertices) noexcept final try
        {
            zero_abi<llm::OS::Perception::People::HandMeshVertex>(vertices, __verticesSize);
            typename D::abi_guard guard(this->shim());
            this->shim().GetVertices(array_view<llm::OS::Perception::People::HandMeshVertex>(reinterpret_cast<llm::OS::Perception::People::HandMeshVertex*>(vertices), reinterpret_cast<llm::OS::Perception::People::HandMeshVertex*>(vertices) + __verticesSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UpdateTimestamp(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::PerceptionTimestamp>(this->shim().UpdateTimestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::People::IHandPose> : produce_base<D, llm::OS::Perception::People::IHandPose>
    {
        int32_t __stdcall TryGetJoint(void* coordinateSystem, int32_t joint, struct struct_Windows_Perception_People_JointPose* jointPose, bool* result) noexcept final try
        {
            zero_abi<llm::OS::Perception::People::JointPose>(jointPose);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().TryGetJoint(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&coordinateSystem), *reinterpret_cast<llm::OS::Perception::People::HandJointKind const*>(&joint), *reinterpret_cast<llm::OS::Perception::People::JointPose*>(jointPose)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetJoints(void* coordinateSystem, uint32_t __jointsSize, int32_t* joints, uint32_t __jointPosesSize, struct struct_Windows_Perception_People_JointPose* jointPoses, bool* result) noexcept final try
        {
            zero_abi<llm::OS::Perception::People::JointPose>(jointPoses, __jointPosesSize);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().TryGetJoints(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&coordinateSystem), array_view<llm::OS::Perception::People::HandJointKind const>(reinterpret_cast<llm::OS::Perception::People::HandJointKind const *>(joints), reinterpret_cast<llm::OS::Perception::People::HandJointKind const *>(joints) + __jointsSize), array_view<llm::OS::Perception::People::JointPose>(reinterpret_cast<llm::OS::Perception::People::JointPose*>(jointPoses), reinterpret_cast<llm::OS::Perception::People::JointPose*>(jointPoses) + __jointPosesSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetRelativeJoint(int32_t joint, int32_t referenceJoint, struct struct_Windows_Perception_People_JointPose* result) noexcept final try
        {
            zero_abi<llm::OS::Perception::People::JointPose>(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Perception::People::JointPose>(this->shim().GetRelativeJoint(*reinterpret_cast<llm::OS::Perception::People::HandJointKind const*>(&joint), *reinterpret_cast<llm::OS::Perception::People::HandJointKind const*>(&referenceJoint)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetRelativeJoints(uint32_t __jointsSize, int32_t* joints, uint32_t __referenceJointsSize, int32_t* referenceJoints, uint32_t __jointPosesSize, struct struct_Windows_Perception_People_JointPose* jointPoses) noexcept final try
        {
            zero_abi<llm::OS::Perception::People::JointPose>(jointPoses, __jointPosesSize);
            typename D::abi_guard guard(this->shim());
            this->shim().GetRelativeJoints(array_view<llm::OS::Perception::People::HandJointKind const>(reinterpret_cast<llm::OS::Perception::People::HandJointKind const *>(joints), reinterpret_cast<llm::OS::Perception::People::HandJointKind const *>(joints) + __jointsSize), array_view<llm::OS::Perception::People::HandJointKind const>(reinterpret_cast<llm::OS::Perception::People::HandJointKind const *>(referenceJoints), reinterpret_cast<llm::OS::Perception::People::HandJointKind const *>(referenceJoints) + __referenceJointsSize), array_view<llm::OS::Perception::People::JointPose>(reinterpret_cast<llm::OS::Perception::People::JointPose*>(jointPoses), reinterpret_cast<llm::OS::Perception::People::JointPose*>(jointPoses) + __jointPosesSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::People::IHeadPose> : produce_base<D, llm::OS::Perception::People::IHeadPose>
    {
        int32_t __stdcall get_Position(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().Position());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ForwardDirection(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().ForwardDirection());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UpDirection(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().UpDirection());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Perception::People
{
    inline auto EyesPose::IsSupported()
    {
        return impl::call_factory_cast<bool(*)(IEyesPoseStatics const&), EyesPose, IEyesPoseStatics>([](IEyesPoseStatics const& f) { return f.IsSupported(); });
    }
    inline auto EyesPose::RequestAccessAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::UI::Input::GazeInputAccessStatus>(*)(IEyesPoseStatics const&), EyesPose, IEyesPoseStatics>([](IEyesPoseStatics const& f) { return f.RequestAccessAsync(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Perception::People::IEyesPose> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::People::IEyesPoseStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::People::IHandMeshObserver> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::People::IHandMeshVertexState> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::People::IHandPose> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::People::IHeadPose> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::People::EyesPose> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::People::HandMeshObserver> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::People::HandMeshVertexState> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::People::HandPose> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::People::HeadPose> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
