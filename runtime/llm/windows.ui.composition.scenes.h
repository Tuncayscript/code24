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
#ifndef LLM_OS_UI_Composition_Scenes_H
#define LLM_OS_UI_Composition_Scenes_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.Composition.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Foundation.Numerics.2.h"
#include "llm/impl/Windows.Graphics.DirectX.2.h"
#include "llm/impl/Windows.UI.Composition.2.h"
#include "llm/impl/Windows.UI.Composition.Scenes.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_UI_Composition_Scenes_ISceneBoundingBox<D>::Center() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneBoundingBox)->get_Center(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_UI_Composition_Scenes_ISceneBoundingBox<D>::Extents() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneBoundingBox)->get_Extents(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_UI_Composition_Scenes_ISceneBoundingBox<D>::Max() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneBoundingBox)->get_Max(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_UI_Composition_Scenes_ISceneBoundingBox<D>::Min() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneBoundingBox)->get_Min(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_UI_Composition_Scenes_ISceneBoundingBox<D>::Size() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneBoundingBox)->get_Size(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Scenes::SceneComponentType) consume_Windows_UI_Composition_Scenes_ISceneComponent<D>::ComponentType() const
    {
        llm::OS::UI::Composition::Scenes::SceneComponentType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneComponent)->get_ComponentType(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Scenes::SceneBoundingBox) consume_Windows_UI_Composition_Scenes_ISceneMesh<D>::Bounds() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneMesh)->get_Bounds(&value));
        return llm::OS::UI::Composition::Scenes::SceneBoundingBox{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::DirectX::DirectXPrimitiveTopology) consume_Windows_UI_Composition_Scenes_ISceneMesh<D>::PrimitiveTopology() const
    {
        llm::OS::Graphics::DirectX::DirectXPrimitiveTopology value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneMesh)->get_PrimitiveTopology(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Scenes_ISceneMesh<D>::PrimitiveTopology(llm::OS::Graphics::DirectX::DirectXPrimitiveTopology const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneMesh)->put_PrimitiveTopology(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Scenes_ISceneMesh<D>::FillMeshAttribute(llm::OS::UI::Composition::Scenes::SceneAttributeSemantic const& semantic, llm::OS::Graphics::DirectX::DirectXPixelFormat const& format, llm::OS::Foundation::MemoryBuffer const& memory) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneMesh)->FillMeshAttribute(static_cast<int32_t>(semantic), static_cast<int32_t>(format), *(void**)(&memory)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Scenes::SceneMaterial) consume_Windows_UI_Composition_Scenes_ISceneMeshRendererComponent<D>::Material() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneMeshRendererComponent)->get_Material(&value));
        return llm::OS::UI::Composition::Scenes::SceneMaterial{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Scenes_ISceneMeshRendererComponent<D>::Material(llm::OS::UI::Composition::Scenes::SceneMaterial const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneMeshRendererComponent)->put_Material(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Scenes::SceneMesh) consume_Windows_UI_Composition_Scenes_ISceneMeshRendererComponent<D>::Mesh() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneMeshRendererComponent)->get_Mesh(&value));
        return llm::OS::UI::Composition::Scenes::SceneMesh{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Scenes_ISceneMeshRendererComponent<D>::Mesh(llm::OS::UI::Composition::Scenes::SceneMesh const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneMeshRendererComponent)->put_Mesh(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Scenes::SceneMeshMaterialAttributeMap) consume_Windows_UI_Composition_Scenes_ISceneMeshRendererComponent<D>::UVMappings() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneMeshRendererComponent)->get_UVMappings(&value));
        return llm::OS::UI::Composition::Scenes::SceneMeshMaterialAttributeMap{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Scenes::SceneMeshRendererComponent) consume_Windows_UI_Composition_Scenes_ISceneMeshRendererComponentStatics<D>::Create(llm::OS::UI::Composition::Compositor const& compositor) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneMeshRendererComponentStatics)->Create(*(void**)(&compositor), &result));
        return llm::OS::UI::Composition::Scenes::SceneMeshRendererComponent{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Scenes::SceneMesh) consume_Windows_UI_Composition_Scenes_ISceneMeshStatics<D>::Create(llm::OS::UI::Composition::Compositor const& compositor) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneMeshStatics)->Create(*(void**)(&compositor), &result));
        return llm::OS::UI::Composition::Scenes::SceneMesh{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Scenes::SceneMaterialInput) consume_Windows_UI_Composition_Scenes_ISceneMetallicRoughnessMaterial<D>::BaseColorInput() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneMetallicRoughnessMaterial)->get_BaseColorInput(&value));
        return llm::OS::UI::Composition::Scenes::SceneMaterialInput{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Scenes_ISceneMetallicRoughnessMaterial<D>::BaseColorInput(llm::OS::UI::Composition::Scenes::SceneMaterialInput const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneMetallicRoughnessMaterial)->put_BaseColorInput(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float4) consume_Windows_UI_Composition_Scenes_ISceneMetallicRoughnessMaterial<D>::BaseColorFactor() const
    {
        llm::OS::Foundation::Numerics::float4 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneMetallicRoughnessMaterial)->get_BaseColorFactor(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Scenes_ISceneMetallicRoughnessMaterial<D>::BaseColorFactor(llm::OS::Foundation::Numerics::float4 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneMetallicRoughnessMaterial)->put_BaseColorFactor(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_Scenes_ISceneMetallicRoughnessMaterial<D>::MetallicFactor() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneMetallicRoughnessMaterial)->get_MetallicFactor(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Scenes_ISceneMetallicRoughnessMaterial<D>::MetallicFactor(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneMetallicRoughnessMaterial)->put_MetallicFactor(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Scenes::SceneMaterialInput) consume_Windows_UI_Composition_Scenes_ISceneMetallicRoughnessMaterial<D>::MetallicRoughnessInput() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneMetallicRoughnessMaterial)->get_MetallicRoughnessInput(&value));
        return llm::OS::UI::Composition::Scenes::SceneMaterialInput{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Scenes_ISceneMetallicRoughnessMaterial<D>::MetallicRoughnessInput(llm::OS::UI::Composition::Scenes::SceneMaterialInput const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneMetallicRoughnessMaterial)->put_MetallicRoughnessInput(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_Scenes_ISceneMetallicRoughnessMaterial<D>::RoughnessFactor() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneMetallicRoughnessMaterial)->get_RoughnessFactor(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Scenes_ISceneMetallicRoughnessMaterial<D>::RoughnessFactor(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneMetallicRoughnessMaterial)->put_RoughnessFactor(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Scenes::SceneMetallicRoughnessMaterial) consume_Windows_UI_Composition_Scenes_ISceneMetallicRoughnessMaterialStatics<D>::Create(llm::OS::UI::Composition::Compositor const& compositor) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneMetallicRoughnessMaterialStatics)->Create(*(void**)(&compositor), &result));
        return llm::OS::UI::Composition::Scenes::SceneMetallicRoughnessMaterial{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::quaternion) consume_Windows_UI_Composition_Scenes_ISceneModelTransform<D>::Orientation() const
    {
        llm::OS::Foundation::Numerics::quaternion value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneModelTransform)->get_Orientation(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Scenes_ISceneModelTransform<D>::Orientation(llm::OS::Foundation::Numerics::quaternion const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneModelTransform)->put_Orientation(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_Scenes_ISceneModelTransform<D>::RotationAngle() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneModelTransform)->get_RotationAngle(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Scenes_ISceneModelTransform<D>::RotationAngle(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneModelTransform)->put_RotationAngle(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_Scenes_ISceneModelTransform<D>::RotationAngleInDegrees() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneModelTransform)->get_RotationAngleInDegrees(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Scenes_ISceneModelTransform<D>::RotationAngleInDegrees(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneModelTransform)->put_RotationAngleInDegrees(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_UI_Composition_Scenes_ISceneModelTransform<D>::RotationAxis() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneModelTransform)->get_RotationAxis(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Scenes_ISceneModelTransform<D>::RotationAxis(llm::OS::Foundation::Numerics::float3 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneModelTransform)->put_RotationAxis(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_UI_Composition_Scenes_ISceneModelTransform<D>::Scale() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneModelTransform)->get_Scale(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Scenes_ISceneModelTransform<D>::Scale(llm::OS::Foundation::Numerics::float3 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneModelTransform)->put_Scale(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_UI_Composition_Scenes_ISceneModelTransform<D>::Translation() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneModelTransform)->get_Translation(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Scenes_ISceneModelTransform<D>::Translation(llm::OS::Foundation::Numerics::float3 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneModelTransform)->put_Translation(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Scenes::SceneNodeCollection) consume_Windows_UI_Composition_Scenes_ISceneNode<D>::Children() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneNode)->get_Children(&value));
        return llm::OS::UI::Composition::Scenes::SceneNodeCollection{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Scenes::SceneComponentCollection) consume_Windows_UI_Composition_Scenes_ISceneNode<D>::Components() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneNode)->get_Components(&value));
        return llm::OS::UI::Composition::Scenes::SceneComponentCollection{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Scenes::SceneNode) consume_Windows_UI_Composition_Scenes_ISceneNode<D>::Parent() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneNode)->get_Parent(&value));
        return llm::OS::UI::Composition::Scenes::SceneNode{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Scenes::SceneModelTransform) consume_Windows_UI_Composition_Scenes_ISceneNode<D>::Transform() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneNode)->get_Transform(&value));
        return llm::OS::UI::Composition::Scenes::SceneModelTransform{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Scenes::SceneComponent) consume_Windows_UI_Composition_Scenes_ISceneNode<D>::FindFirstComponentOfType(llm::OS::UI::Composition::Scenes::SceneComponentType const& value) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneNode)->FindFirstComponentOfType(static_cast<int32_t>(value), &result));
        return llm::OS::UI::Composition::Scenes::SceneComponent{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Scenes::SceneNode) consume_Windows_UI_Composition_Scenes_ISceneNodeStatics<D>::Create(llm::OS::UI::Composition::Compositor const& compositor) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneNodeStatics)->Create(*(void**)(&compositor), &result));
        return llm::OS::UI::Composition::Scenes::SceneNode{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_Scenes_IScenePbrMaterial<D>::AlphaCutoff() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::IScenePbrMaterial)->get_AlphaCutoff(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Scenes_IScenePbrMaterial<D>::AlphaCutoff(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::IScenePbrMaterial)->put_AlphaCutoff(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Scenes::SceneAlphaMode) consume_Windows_UI_Composition_Scenes_IScenePbrMaterial<D>::AlphaMode() const
    {
        llm::OS::UI::Composition::Scenes::SceneAlphaMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::IScenePbrMaterial)->get_AlphaMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Scenes_IScenePbrMaterial<D>::AlphaMode(llm::OS::UI::Composition::Scenes::SceneAlphaMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::IScenePbrMaterial)->put_AlphaMode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Scenes::SceneMaterialInput) consume_Windows_UI_Composition_Scenes_IScenePbrMaterial<D>::EmissiveInput() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::IScenePbrMaterial)->get_EmissiveInput(&value));
        return llm::OS::UI::Composition::Scenes::SceneMaterialInput{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Scenes_IScenePbrMaterial<D>::EmissiveInput(llm::OS::UI::Composition::Scenes::SceneMaterialInput const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::IScenePbrMaterial)->put_EmissiveInput(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_UI_Composition_Scenes_IScenePbrMaterial<D>::EmissiveFactor() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::IScenePbrMaterial)->get_EmissiveFactor(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Scenes_IScenePbrMaterial<D>::EmissiveFactor(llm::OS::Foundation::Numerics::float3 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::IScenePbrMaterial)->put_EmissiveFactor(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Composition_Scenes_IScenePbrMaterial<D>::IsDoubleSided() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::IScenePbrMaterial)->get_IsDoubleSided(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Scenes_IScenePbrMaterial<D>::IsDoubleSided(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::IScenePbrMaterial)->put_IsDoubleSided(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Scenes::SceneMaterialInput) consume_Windows_UI_Composition_Scenes_IScenePbrMaterial<D>::NormalInput() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::IScenePbrMaterial)->get_NormalInput(&value));
        return llm::OS::UI::Composition::Scenes::SceneMaterialInput{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Scenes_IScenePbrMaterial<D>::NormalInput(llm::OS::UI::Composition::Scenes::SceneMaterialInput const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::IScenePbrMaterial)->put_NormalInput(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_Scenes_IScenePbrMaterial<D>::NormalScale() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::IScenePbrMaterial)->get_NormalScale(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Scenes_IScenePbrMaterial<D>::NormalScale(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::IScenePbrMaterial)->put_NormalScale(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Scenes::SceneMaterialInput) consume_Windows_UI_Composition_Scenes_IScenePbrMaterial<D>::OcclusionInput() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::IScenePbrMaterial)->get_OcclusionInput(&value));
        return llm::OS::UI::Composition::Scenes::SceneMaterialInput{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Scenes_IScenePbrMaterial<D>::OcclusionInput(llm::OS::UI::Composition::Scenes::SceneMaterialInput const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::IScenePbrMaterial)->put_OcclusionInput(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_Scenes_IScenePbrMaterial<D>::OcclusionStrength() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::IScenePbrMaterial)->get_OcclusionStrength(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Scenes_IScenePbrMaterial<D>::OcclusionStrength(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::IScenePbrMaterial)->put_OcclusionStrength(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionBitmapInterpolationMode) consume_Windows_UI_Composition_Scenes_ISceneSurfaceMaterialInput<D>::BitmapInterpolationMode() const
    {
        llm::OS::UI::Composition::CompositionBitmapInterpolationMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneSurfaceMaterialInput)->get_BitmapInterpolationMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Scenes_ISceneSurfaceMaterialInput<D>::BitmapInterpolationMode(llm::OS::UI::Composition::CompositionBitmapInterpolationMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneSurfaceMaterialInput)->put_BitmapInterpolationMode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::ICompositionSurface) consume_Windows_UI_Composition_Scenes_ISceneSurfaceMaterialInput<D>::Surface() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneSurfaceMaterialInput)->get_Surface(&value));
        return llm::OS::UI::Composition::ICompositionSurface{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Scenes_ISceneSurfaceMaterialInput<D>::Surface(llm::OS::UI::Composition::ICompositionSurface const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneSurfaceMaterialInput)->put_Surface(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Scenes::SceneWrappingMode) consume_Windows_UI_Composition_Scenes_ISceneSurfaceMaterialInput<D>::WrappingUMode() const
    {
        llm::OS::UI::Composition::Scenes::SceneWrappingMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneSurfaceMaterialInput)->get_WrappingUMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Scenes_ISceneSurfaceMaterialInput<D>::WrappingUMode(llm::OS::UI::Composition::Scenes::SceneWrappingMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneSurfaceMaterialInput)->put_WrappingUMode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Scenes::SceneWrappingMode) consume_Windows_UI_Composition_Scenes_ISceneSurfaceMaterialInput<D>::WrappingVMode() const
    {
        llm::OS::UI::Composition::Scenes::SceneWrappingMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneSurfaceMaterialInput)->get_WrappingVMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Scenes_ISceneSurfaceMaterialInput<D>::WrappingVMode(llm::OS::UI::Composition::Scenes::SceneWrappingMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneSurfaceMaterialInput)->put_WrappingVMode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Scenes::SceneSurfaceMaterialInput) consume_Windows_UI_Composition_Scenes_ISceneSurfaceMaterialInputStatics<D>::Create(llm::OS::UI::Composition::Compositor const& compositor) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneSurfaceMaterialInputStatics)->Create(*(void**)(&compositor), &result));
        return llm::OS::UI::Composition::Scenes::SceneSurfaceMaterialInput{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Scenes::SceneNode) consume_Windows_UI_Composition_Scenes_ISceneVisual<D>::Root() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneVisual)->get_Root(&value));
        return llm::OS::UI::Composition::Scenes::SceneNode{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Scenes_ISceneVisual<D>::Root(llm::OS::UI::Composition::Scenes::SceneNode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneVisual)->put_Root(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Scenes::SceneVisual) consume_Windows_UI_Composition_Scenes_ISceneVisualStatics<D>::Create(llm::OS::UI::Composition::Compositor const& compositor) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Scenes::ISceneVisualStatics)->Create(*(void**)(&compositor), &result));
        return llm::OS::UI::Composition::Scenes::SceneVisual{ result, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Scenes::ISceneBoundingBox> : produce_base<D, llm::OS::UI::Composition::Scenes::ISceneBoundingBox>
    {
        int32_t __stdcall get_Center(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().Center());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Extents(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().Extents());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Max(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().Max());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Min(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().Min());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Size(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().Size());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Scenes::ISceneComponent> : produce_base<D, llm::OS::UI::Composition::Scenes::ISceneComponent>
    {
        int32_t __stdcall get_ComponentType(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::Scenes::SceneComponentType>(this->shim().ComponentType());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Scenes::ISceneComponentCollection> : produce_base<D, llm::OS::UI::Composition::Scenes::ISceneComponentCollection>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Scenes::ISceneComponentFactory> : produce_base<D, llm::OS::UI::Composition::Scenes::ISceneComponentFactory>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Scenes::ISceneMaterial> : produce_base<D, llm::OS::UI::Composition::Scenes::ISceneMaterial>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Scenes::ISceneMaterialFactory> : produce_base<D, llm::OS::UI::Composition::Scenes::ISceneMaterialFactory>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Scenes::ISceneMaterialInput> : produce_base<D, llm::OS::UI::Composition::Scenes::ISceneMaterialInput>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Scenes::ISceneMaterialInputFactory> : produce_base<D, llm::OS::UI::Composition::Scenes::ISceneMaterialInputFactory>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Scenes::ISceneMesh> : produce_base<D, llm::OS::UI::Composition::Scenes::ISceneMesh>
    {
        int32_t __stdcall get_Bounds(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::Scenes::SceneBoundingBox>(this->shim().Bounds());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PrimitiveTopology(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::DirectX::DirectXPrimitiveTopology>(this->shim().PrimitiveTopology());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PrimitiveTopology(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PrimitiveTopology(*reinterpret_cast<llm::OS::Graphics::DirectX::DirectXPrimitiveTopology const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FillMeshAttribute(int32_t semantic, int32_t format, void* memory) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FillMeshAttribute(*reinterpret_cast<llm::OS::UI::Composition::Scenes::SceneAttributeSemantic const*>(&semantic), *reinterpret_cast<llm::OS::Graphics::DirectX::DirectXPixelFormat const*>(&format), *reinterpret_cast<llm::OS::Foundation::MemoryBuffer const*>(&memory));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Scenes::ISceneMeshMaterialAttributeMap> : produce_base<D, llm::OS::UI::Composition::Scenes::ISceneMeshMaterialAttributeMap>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Scenes::ISceneMeshRendererComponent> : produce_base<D, llm::OS::UI::Composition::Scenes::ISceneMeshRendererComponent>
    {
        int32_t __stdcall get_Material(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::Scenes::SceneMaterial>(this->shim().Material());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Material(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Material(*reinterpret_cast<llm::OS::UI::Composition::Scenes::SceneMaterial const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Mesh(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::Scenes::SceneMesh>(this->shim().Mesh());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Mesh(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Mesh(*reinterpret_cast<llm::OS::UI::Composition::Scenes::SceneMesh const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UVMappings(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::Scenes::SceneMeshMaterialAttributeMap>(this->shim().UVMappings());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Scenes::ISceneMeshRendererComponentStatics> : produce_base<D, llm::OS::UI::Composition::Scenes::ISceneMeshRendererComponentStatics>
    {
        int32_t __stdcall Create(void* compositor, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::Scenes::SceneMeshRendererComponent>(this->shim().Create(*reinterpret_cast<llm::OS::UI::Composition::Compositor const*>(&compositor)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Scenes::ISceneMeshStatics> : produce_base<D, llm::OS::UI::Composition::Scenes::ISceneMeshStatics>
    {
        int32_t __stdcall Create(void* compositor, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::Scenes::SceneMesh>(this->shim().Create(*reinterpret_cast<llm::OS::UI::Composition::Compositor const*>(&compositor)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Scenes::ISceneMetallicRoughnessMaterial> : produce_base<D, llm::OS::UI::Composition::Scenes::ISceneMetallicRoughnessMaterial>
    {
        int32_t __stdcall get_BaseColorInput(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::Scenes::SceneMaterialInput>(this->shim().BaseColorInput());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BaseColorInput(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BaseColorInput(*reinterpret_cast<llm::OS::UI::Composition::Scenes::SceneMaterialInput const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BaseColorFactor(llm::OS::Foundation::Numerics::float4* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float4>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float4>(this->shim().BaseColorFactor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BaseColorFactor(llm::OS::Foundation::Numerics::float4 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BaseColorFactor(*reinterpret_cast<llm::OS::Foundation::Numerics::float4 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MetallicFactor(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().MetallicFactor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_MetallicFactor(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MetallicFactor(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MetallicRoughnessInput(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::Scenes::SceneMaterialInput>(this->shim().MetallicRoughnessInput());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_MetallicRoughnessInput(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MetallicRoughnessInput(*reinterpret_cast<llm::OS::UI::Composition::Scenes::SceneMaterialInput const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RoughnessFactor(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().RoughnessFactor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RoughnessFactor(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RoughnessFactor(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Scenes::ISceneMetallicRoughnessMaterialStatics> : produce_base<D, llm::OS::UI::Composition::Scenes::ISceneMetallicRoughnessMaterialStatics>
    {
        int32_t __stdcall Create(void* compositor, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::Scenes::SceneMetallicRoughnessMaterial>(this->shim().Create(*reinterpret_cast<llm::OS::UI::Composition::Compositor const*>(&compositor)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Scenes::ISceneModelTransform> : produce_base<D, llm::OS::UI::Composition::Scenes::ISceneModelTransform>
    {
        int32_t __stdcall get_Orientation(llm::OS::Foundation::Numerics::quaternion* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::quaternion>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::quaternion>(this->shim().Orientation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Orientation(llm::OS::Foundation::Numerics::quaternion value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Orientation(*reinterpret_cast<llm::OS::Foundation::Numerics::quaternion const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RotationAngle(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().RotationAngle());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RotationAngle(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RotationAngle(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RotationAngleInDegrees(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().RotationAngleInDegrees());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RotationAngleInDegrees(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RotationAngleInDegrees(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RotationAxis(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().RotationAxis());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RotationAxis(llm::OS::Foundation::Numerics::float3 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RotationAxis(*reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Scale(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().Scale());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Scale(llm::OS::Foundation::Numerics::float3 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Scale(*reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Translation(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().Translation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Translation(llm::OS::Foundation::Numerics::float3 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Translation(*reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Scenes::ISceneNode> : produce_base<D, llm::OS::UI::Composition::Scenes::ISceneNode>
    {
        int32_t __stdcall get_Children(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::Scenes::SceneNodeCollection>(this->shim().Children());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Components(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::Scenes::SceneComponentCollection>(this->shim().Components());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Parent(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::Scenes::SceneNode>(this->shim().Parent());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Transform(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::Scenes::SceneModelTransform>(this->shim().Transform());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindFirstComponentOfType(int32_t value, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::Scenes::SceneComponent>(this->shim().FindFirstComponentOfType(*reinterpret_cast<llm::OS::UI::Composition::Scenes::SceneComponentType const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Scenes::ISceneNodeCollection> : produce_base<D, llm::OS::UI::Composition::Scenes::ISceneNodeCollection>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Scenes::ISceneNodeStatics> : produce_base<D, llm::OS::UI::Composition::Scenes::ISceneNodeStatics>
    {
        int32_t __stdcall Create(void* compositor, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::Scenes::SceneNode>(this->shim().Create(*reinterpret_cast<llm::OS::UI::Composition::Compositor const*>(&compositor)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Scenes::ISceneObject> : produce_base<D, llm::OS::UI::Composition::Scenes::ISceneObject>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Scenes::ISceneObjectFactory> : produce_base<D, llm::OS::UI::Composition::Scenes::ISceneObjectFactory>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Scenes::IScenePbrMaterial> : produce_base<D, llm::OS::UI::Composition::Scenes::IScenePbrMaterial>
    {
        int32_t __stdcall get_AlphaCutoff(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().AlphaCutoff());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AlphaCutoff(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AlphaCutoff(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AlphaMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::Scenes::SceneAlphaMode>(this->shim().AlphaMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AlphaMode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AlphaMode(*reinterpret_cast<llm::OS::UI::Composition::Scenes::SceneAlphaMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EmissiveInput(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::Scenes::SceneMaterialInput>(this->shim().EmissiveInput());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_EmissiveInput(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EmissiveInput(*reinterpret_cast<llm::OS::UI::Composition::Scenes::SceneMaterialInput const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EmissiveFactor(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().EmissiveFactor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_EmissiveFactor(llm::OS::Foundation::Numerics::float3 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EmissiveFactor(*reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsDoubleSided(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsDoubleSided());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsDoubleSided(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsDoubleSided(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NormalInput(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::Scenes::SceneMaterialInput>(this->shim().NormalInput());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_NormalInput(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NormalInput(*reinterpret_cast<llm::OS::UI::Composition::Scenes::SceneMaterialInput const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NormalScale(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().NormalScale());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_NormalScale(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NormalScale(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OcclusionInput(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::Scenes::SceneMaterialInput>(this->shim().OcclusionInput());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_OcclusionInput(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OcclusionInput(*reinterpret_cast<llm::OS::UI::Composition::Scenes::SceneMaterialInput const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OcclusionStrength(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().OcclusionStrength());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_OcclusionStrength(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OcclusionStrength(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Scenes::IScenePbrMaterialFactory> : produce_base<D, llm::OS::UI::Composition::Scenes::IScenePbrMaterialFactory>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Scenes::ISceneRendererComponent> : produce_base<D, llm::OS::UI::Composition::Scenes::ISceneRendererComponent>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Scenes::ISceneRendererComponentFactory> : produce_base<D, llm::OS::UI::Composition::Scenes::ISceneRendererComponentFactory>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Scenes::ISceneSurfaceMaterialInput> : produce_base<D, llm::OS::UI::Composition::Scenes::ISceneSurfaceMaterialInput>
    {
        int32_t __stdcall get_BitmapInterpolationMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionBitmapInterpolationMode>(this->shim().BitmapInterpolationMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BitmapInterpolationMode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BitmapInterpolationMode(*reinterpret_cast<llm::OS::UI::Composition::CompositionBitmapInterpolationMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Surface(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::ICompositionSurface>(this->shim().Surface());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Surface(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Surface(*reinterpret_cast<llm::OS::UI::Composition::ICompositionSurface const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WrappingUMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::Scenes::SceneWrappingMode>(this->shim().WrappingUMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_WrappingUMode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WrappingUMode(*reinterpret_cast<llm::OS::UI::Composition::Scenes::SceneWrappingMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WrappingVMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::Scenes::SceneWrappingMode>(this->shim().WrappingVMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_WrappingVMode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WrappingVMode(*reinterpret_cast<llm::OS::UI::Composition::Scenes::SceneWrappingMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Scenes::ISceneSurfaceMaterialInputStatics> : produce_base<D, llm::OS::UI::Composition::Scenes::ISceneSurfaceMaterialInputStatics>
    {
        int32_t __stdcall Create(void* compositor, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::Scenes::SceneSurfaceMaterialInput>(this->shim().Create(*reinterpret_cast<llm::OS::UI::Composition::Compositor const*>(&compositor)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Scenes::ISceneVisual> : produce_base<D, llm::OS::UI::Composition::Scenes::ISceneVisual>
    {
        int32_t __stdcall get_Root(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::Scenes::SceneNode>(this->shim().Root());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Root(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Root(*reinterpret_cast<llm::OS::UI::Composition::Scenes::SceneNode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Scenes::ISceneVisualStatics> : produce_base<D, llm::OS::UI::Composition::Scenes::ISceneVisualStatics>
    {
        int32_t __stdcall Create(void* compositor, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::Scenes::SceneVisual>(this->shim().Create(*reinterpret_cast<llm::OS::UI::Composition::Compositor const*>(&compositor)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::UI::Composition::Scenes
{
    inline auto SceneMesh::Create(llm::OS::UI::Composition::Compositor const& compositor)
    {
        return impl::call_factory<SceneMesh, ISceneMeshStatics>([&](ISceneMeshStatics const& f) { return f.Create(compositor); });
    }
    inline auto SceneMeshRendererComponent::Create(llm::OS::UI::Composition::Compositor const& compositor)
    {
        return impl::call_factory<SceneMeshRendererComponent, ISceneMeshRendererComponentStatics>([&](ISceneMeshRendererComponentStatics const& f) { return f.Create(compositor); });
    }
    inline auto SceneMetallicRoughnessMaterial::Create(llm::OS::UI::Composition::Compositor const& compositor)
    {
        return impl::call_factory<SceneMetallicRoughnessMaterial, ISceneMetallicRoughnessMaterialStatics>([&](ISceneMetallicRoughnessMaterialStatics const& f) { return f.Create(compositor); });
    }
    inline auto SceneNode::Create(llm::OS::UI::Composition::Compositor const& compositor)
    {
        return impl::call_factory<SceneNode, ISceneNodeStatics>([&](ISceneNodeStatics const& f) { return f.Create(compositor); });
    }
    inline auto SceneSurfaceMaterialInput::Create(llm::OS::UI::Composition::Compositor const& compositor)
    {
        return impl::call_factory<SceneSurfaceMaterialInput, ISceneSurfaceMaterialInputStatics>([&](ISceneSurfaceMaterialInputStatics const& f) { return f.Create(compositor); });
    }
    inline auto SceneVisual::Create(llm::OS::UI::Composition::Compositor const& compositor)
    {
        return impl::call_factory<SceneVisual, ISceneVisualStatics>([&](ISceneVisualStatics const& f) { return f.Create(compositor); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::Composition::Scenes::ISceneBoundingBox> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::ISceneComponent> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::ISceneComponentCollection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::ISceneComponentFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::ISceneMaterial> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::ISceneMaterialFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::ISceneMaterialInput> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::ISceneMaterialInputFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::ISceneMesh> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::ISceneMeshMaterialAttributeMap> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::ISceneMeshRendererComponent> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::ISceneMeshRendererComponentStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::ISceneMeshStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::ISceneMetallicRoughnessMaterial> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::ISceneMetallicRoughnessMaterialStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::ISceneModelTransform> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::ISceneNode> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::ISceneNodeCollection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::ISceneNodeStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::ISceneObject> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::ISceneObjectFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::IScenePbrMaterial> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::IScenePbrMaterialFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::ISceneRendererComponent> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::ISceneRendererComponentFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::ISceneSurfaceMaterialInput> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::ISceneSurfaceMaterialInputStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::ISceneVisual> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::ISceneVisualStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::SceneBoundingBox> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::SceneComponent> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::SceneComponentCollection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::SceneMaterial> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::SceneMaterialInput> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::SceneMesh> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::SceneMeshMaterialAttributeMap> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::SceneMeshRendererComponent> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::SceneMetallicRoughnessMaterial> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::SceneModelTransform> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::SceneNode> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::SceneNodeCollection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::SceneObject> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::ScenePbrMaterial> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::SceneRendererComponent> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::SceneSurfaceMaterialInput> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Scenes::SceneVisual> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
