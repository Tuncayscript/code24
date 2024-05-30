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
#ifndef LLM_OS_UI_Composition_Scenes_1_H
#define LLM_OS_UI_Composition_Scenes_1_H
#include "llm/impl/Windows.UI.Composition.Scenes.0.h"
LLM_EXPORT namespace llm:OS::UI::Composition::Scenes
{
    struct __declspec(empty_bases) ISceneBoundingBox :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISceneBoundingBox>
    {
        ISceneBoundingBox(std::nullptr_t = nullptr) noexcept {}
        ISceneBoundingBox(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISceneComponent :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISceneComponent>
    {
        ISceneComponent(std::nullptr_t = nullptr) noexcept {}
        ISceneComponent(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISceneComponentCollection :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISceneComponentCollection>
    {
        ISceneComponentCollection(std::nullptr_t = nullptr) noexcept {}
        ISceneComponentCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISceneComponentFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISceneComponentFactory>
    {
        ISceneComponentFactory(std::nullptr_t = nullptr) noexcept {}
        ISceneComponentFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISceneMaterial :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISceneMaterial>
    {
        ISceneMaterial(std::nullptr_t = nullptr) noexcept {}
        ISceneMaterial(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISceneMaterialFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISceneMaterialFactory>
    {
        ISceneMaterialFactory(std::nullptr_t = nullptr) noexcept {}
        ISceneMaterialFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISceneMaterialInput :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISceneMaterialInput>
    {
        ISceneMaterialInput(std::nullptr_t = nullptr) noexcept {}
        ISceneMaterialInput(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISceneMaterialInputFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISceneMaterialInputFactory>
    {
        ISceneMaterialInputFactory(std::nullptr_t = nullptr) noexcept {}
        ISceneMaterialInputFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISceneMesh :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISceneMesh>
    {
        ISceneMesh(std::nullptr_t = nullptr) noexcept {}
        ISceneMesh(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISceneMeshMaterialAttributeMap :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISceneMeshMaterialAttributeMap>
    {
        ISceneMeshMaterialAttributeMap(std::nullptr_t = nullptr) noexcept {}
        ISceneMeshMaterialAttributeMap(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISceneMeshRendererComponent :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISceneMeshRendererComponent>
    {
        ISceneMeshRendererComponent(std::nullptr_t = nullptr) noexcept {}
        ISceneMeshRendererComponent(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISceneMeshRendererComponentStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISceneMeshRendererComponentStatics>
    {
        ISceneMeshRendererComponentStatics(std::nullptr_t = nullptr) noexcept {}
        ISceneMeshRendererComponentStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISceneMeshStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISceneMeshStatics>
    {
        ISceneMeshStatics(std::nullptr_t = nullptr) noexcept {}
        ISceneMeshStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISceneMetallicRoughnessMaterial :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISceneMetallicRoughnessMaterial>
    {
        ISceneMetallicRoughnessMaterial(std::nullptr_t = nullptr) noexcept {}
        ISceneMetallicRoughnessMaterial(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISceneMetallicRoughnessMaterialStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISceneMetallicRoughnessMaterialStatics>
    {
        ISceneMetallicRoughnessMaterialStatics(std::nullptr_t = nullptr) noexcept {}
        ISceneMetallicRoughnessMaterialStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISceneModelTransform :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISceneModelTransform>
    {
        ISceneModelTransform(std::nullptr_t = nullptr) noexcept {}
        ISceneModelTransform(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISceneNode :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISceneNode>
    {
        ISceneNode(std::nullptr_t = nullptr) noexcept {}
        ISceneNode(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISceneNodeCollection :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISceneNodeCollection>
    {
        ISceneNodeCollection(std::nullptr_t = nullptr) noexcept {}
        ISceneNodeCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISceneNodeStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISceneNodeStatics>
    {
        ISceneNodeStatics(std::nullptr_t = nullptr) noexcept {}
        ISceneNodeStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISceneObject :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISceneObject>
    {
        ISceneObject(std::nullptr_t = nullptr) noexcept {}
        ISceneObject(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISceneObjectFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISceneObjectFactory>
    {
        ISceneObjectFactory(std::nullptr_t = nullptr) noexcept {}
        ISceneObjectFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IScenePbrMaterial :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IScenePbrMaterial>
    {
        IScenePbrMaterial(std::nullptr_t = nullptr) noexcept {}
        IScenePbrMaterial(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IScenePbrMaterialFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IScenePbrMaterialFactory>
    {
        IScenePbrMaterialFactory(std::nullptr_t = nullptr) noexcept {}
        IScenePbrMaterialFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISceneRendererComponent :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISceneRendererComponent>
    {
        ISceneRendererComponent(std::nullptr_t = nullptr) noexcept {}
        ISceneRendererComponent(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISceneRendererComponentFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISceneRendererComponentFactory>
    {
        ISceneRendererComponentFactory(std::nullptr_t = nullptr) noexcept {}
        ISceneRendererComponentFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISceneSurfaceMaterialInput :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISceneSurfaceMaterialInput>
    {
        ISceneSurfaceMaterialInput(std::nullptr_t = nullptr) noexcept {}
        ISceneSurfaceMaterialInput(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISceneSurfaceMaterialInputStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISceneSurfaceMaterialInputStatics>
    {
        ISceneSurfaceMaterialInputStatics(std::nullptr_t = nullptr) noexcept {}
        ISceneSurfaceMaterialInputStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISceneVisual :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISceneVisual>
    {
        ISceneVisual(std::nullptr_t = nullptr) noexcept {}
        ISceneVisual(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISceneVisualStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISceneVisualStatics>
    {
        ISceneVisualStatics(std::nullptr_t = nullptr) noexcept {}
        ISceneVisualStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
