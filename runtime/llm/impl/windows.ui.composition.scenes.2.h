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
#ifndef LLM_OS_UI_Composition_Scenes_2_H
#define LLM_OS_UI_Composition_Scenes_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.UI.Composition.1.h"
#include "llm/impl/Windows.UI.Composition.Scenes.1.h"
LLM_EXPORT namespace llm:OS::UI::Composition::Scenes
{
    struct __declspec(empty_bases) SceneBoundingBox : llm:OS::UI::Composition::Scenes::ISceneBoundingBox,
        impl::base<SceneBoundingBox, llm:OS::UI::Composition::Scenes::SceneObject, llm:OS::UI::Composition::CompositionObject>,
        impl::require<SceneBoundingBox, llm:OS::UI::Composition::Scenes::ISceneObject, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        SceneBoundingBox(std::nullptr_t) noexcept {}
        SceneBoundingBox(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Scenes::ISceneBoundingBox(ptr, take_ownership_from_abi) {}
        using impl::consume_t<SceneBoundingBox, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<SceneBoundingBox, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) SceneComponent : llm:OS::UI::Composition::Scenes::ISceneComponent,
        impl::base<SceneComponent, llm:OS::UI::Composition::Scenes::SceneObject, llm:OS::UI::Composition::CompositionObject>,
        impl::require<SceneComponent, llm:OS::UI::Composition::Scenes::ISceneObject, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        SceneComponent(std::nullptr_t) noexcept {}
        SceneComponent(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Scenes::ISceneComponent(ptr, take_ownership_from_abi) {}
        using impl::consume_t<SceneComponent, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<SceneComponent, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) SceneComponentCollection : llm:OS::Foundation::Collections::IVector<llm:OS::UI::Composition::Scenes::SceneComponent>,
        impl::base<SceneComponentCollection, llm:OS::UI::Composition::Scenes::SceneObject, llm:OS::UI::Composition::CompositionObject>,
        impl::require<SceneComponentCollection, llm:OS::UI::Composition::Scenes::ISceneComponentCollection, llm:OS::UI::Composition::Scenes::ISceneObject, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        SceneComponentCollection(std::nullptr_t) noexcept {}
        SceneComponentCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::Collections::IVector<llm:OS::UI::Composition::Scenes::SceneComponent>(ptr, take_ownership_from_abi) {}
        using impl::consume_t<SceneComponentCollection, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<SceneComponentCollection, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) SceneMaterial : llm:OS::UI::Composition::Scenes::ISceneMaterial,
        impl::base<SceneMaterial, llm:OS::UI::Composition::Scenes::SceneObject, llm:OS::UI::Composition::CompositionObject>,
        impl::require<SceneMaterial, llm:OS::UI::Composition::Scenes::ISceneObject, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        SceneMaterial(std::nullptr_t) noexcept {}
        SceneMaterial(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Scenes::ISceneMaterial(ptr, take_ownership_from_abi) {}
        using impl::consume_t<SceneMaterial, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<SceneMaterial, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) SceneMaterialInput : llm:OS::UI::Composition::Scenes::ISceneMaterialInput,
        impl::base<SceneMaterialInput, llm:OS::UI::Composition::Scenes::SceneObject, llm:OS::UI::Composition::CompositionObject>,
        impl::require<SceneMaterialInput, llm:OS::UI::Composition::Scenes::ISceneObject, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        SceneMaterialInput(std::nullptr_t) noexcept {}
        SceneMaterialInput(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Scenes::ISceneMaterialInput(ptr, take_ownership_from_abi) {}
        using impl::consume_t<SceneMaterialInput, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<SceneMaterialInput, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) SceneMesh : llm:OS::UI::Composition::Scenes::ISceneMesh,
        impl::base<SceneMesh, llm:OS::UI::Composition::Scenes::SceneObject, llm:OS::UI::Composition::CompositionObject>,
        impl::require<SceneMesh, llm:OS::UI::Composition::Scenes::ISceneObject, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        SceneMesh(std::nullptr_t) noexcept {}
        SceneMesh(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Scenes::ISceneMesh(ptr, take_ownership_from_abi) {}
        using impl::consume_t<SceneMesh, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<SceneMesh, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
        static auto Create(llm:OS::UI::Composition::Compositor const& compositor);
    };
    struct __declspec(empty_bases) SceneMeshMaterialAttributeMap : llm:OS::UI::Composition::Scenes::ISceneMeshMaterialAttributeMap,
        impl::base<SceneMeshMaterialAttributeMap, llm:OS::UI::Composition::Scenes::SceneObject, llm:OS::UI::Composition::CompositionObject>,
        impl::require<SceneMeshMaterialAttributeMap, llm:OS::Foundation::Collections::IIterable<llm:OS::Foundation::Collections::IKeyValuePair<hstring, llm:OS::UI::Composition::Scenes::SceneAttributeSemantic>>, llm:OS::Foundation::Collections::IMap<hstring, llm:OS::UI::Composition::Scenes::SceneAttributeSemantic>, llm:OS::UI::Composition::Scenes::ISceneObject, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        SceneMeshMaterialAttributeMap(std::nullptr_t) noexcept {}
        SceneMeshMaterialAttributeMap(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Scenes::ISceneMeshMaterialAttributeMap(ptr, take_ownership_from_abi) {}
        using impl::consume_t<SceneMeshMaterialAttributeMap, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<SceneMeshMaterialAttributeMap, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) SceneMeshRendererComponent : llm:OS::UI::Composition::Scenes::ISceneMeshRendererComponent,
        impl::base<SceneMeshRendererComponent, llm:OS::UI::Composition::Scenes::SceneRendererComponent, llm:OS::UI::Composition::Scenes::SceneComponent, llm:OS::UI::Composition::Scenes::SceneObject, llm:OS::UI::Composition::CompositionObject>,
        impl::require<SceneMeshRendererComponent, llm:OS::UI::Composition::Scenes::ISceneRendererComponent, llm:OS::UI::Composition::Scenes::ISceneComponent, llm:OS::UI::Composition::Scenes::ISceneObject, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        SceneMeshRendererComponent(std::nullptr_t) noexcept {}
        SceneMeshRendererComponent(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Scenes::ISceneMeshRendererComponent(ptr, take_ownership_from_abi) {}
        using impl::consume_t<SceneMeshRendererComponent, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<SceneMeshRendererComponent, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
        static auto Create(llm:OS::UI::Composition::Compositor const& compositor);
    };
    struct __declspec(empty_bases) SceneMetallicRoughnessMaterial : llm:OS::UI::Composition::Scenes::ISceneMetallicRoughnessMaterial,
        impl::base<SceneMetallicRoughnessMaterial, llm:OS::UI::Composition::Scenes::ScenePbrMaterial, llm:OS::UI::Composition::Scenes::SceneMaterial, llm:OS::UI::Composition::Scenes::SceneObject, llm:OS::UI::Composition::CompositionObject>,
        impl::require<SceneMetallicRoughnessMaterial, llm:OS::UI::Composition::Scenes::IScenePbrMaterial, llm:OS::UI::Composition::Scenes::ISceneMaterial, llm:OS::UI::Composition::Scenes::ISceneObject, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        SceneMetallicRoughnessMaterial(std::nullptr_t) noexcept {}
        SceneMetallicRoughnessMaterial(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Scenes::ISceneMetallicRoughnessMaterial(ptr, take_ownership_from_abi) {}
        using impl::consume_t<SceneMetallicRoughnessMaterial, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<SceneMetallicRoughnessMaterial, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
        static auto Create(llm:OS::UI::Composition::Compositor const& compositor);
    };
    struct __declspec(empty_bases) SceneModelTransform : llm:OS::UI::Composition::Scenes::ISceneModelTransform,
        impl::base<SceneModelTransform, llm:OS::UI::Composition::CompositionTransform, llm:OS::UI::Composition::CompositionObject>,
        impl::require<SceneModelTransform, llm:OS::UI::Composition::ICompositionTransform, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        SceneModelTransform(std::nullptr_t) noexcept {}
        SceneModelTransform(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Scenes::ISceneModelTransform(ptr, take_ownership_from_abi) {}
        using impl::consume_t<SceneModelTransform, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<SceneModelTransform, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) SceneNode : llm:OS::UI::Composition::Scenes::ISceneNode,
        impl::base<SceneNode, llm:OS::UI::Composition::Scenes::SceneObject, llm:OS::UI::Composition::CompositionObject>,
        impl::require<SceneNode, llm:OS::UI::Composition::Scenes::ISceneObject, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        SceneNode(std::nullptr_t) noexcept {}
        SceneNode(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Scenes::ISceneNode(ptr, take_ownership_from_abi) {}
        using impl::consume_t<SceneNode, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<SceneNode, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
        static auto Create(llm:OS::UI::Composition::Compositor const& compositor);
    };
    struct __declspec(empty_bases) SceneNodeCollection : llm:OS::Foundation::Collections::IVector<llm:OS::UI::Composition::Scenes::SceneNode>,
        impl::base<SceneNodeCollection, llm:OS::UI::Composition::Scenes::SceneObject, llm:OS::UI::Composition::CompositionObject>,
        impl::require<SceneNodeCollection, llm:OS::UI::Composition::Scenes::ISceneNodeCollection, llm:OS::UI::Composition::Scenes::ISceneObject, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        SceneNodeCollection(std::nullptr_t) noexcept {}
        SceneNodeCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::Collections::IVector<llm:OS::UI::Composition::Scenes::SceneNode>(ptr, take_ownership_from_abi) {}
        using impl::consume_t<SceneNodeCollection, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<SceneNodeCollection, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) SceneObject : llm:OS::UI::Composition::Scenes::ISceneObject,
        impl::base<SceneObject, llm:OS::UI::Composition::CompositionObject>,
        impl::require<SceneObject, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        SceneObject(std::nullptr_t) noexcept {}
        SceneObject(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Scenes::ISceneObject(ptr, take_ownership_from_abi) {}
        using impl::consume_t<SceneObject, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<SceneObject, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) ScenePbrMaterial : llm:OS::UI::Composition::Scenes::IScenePbrMaterial,
        impl::base<ScenePbrMaterial, llm:OS::UI::Composition::Scenes::SceneMaterial, llm:OS::UI::Composition::Scenes::SceneObject, llm:OS::UI::Composition::CompositionObject>,
        impl::require<ScenePbrMaterial, llm:OS::UI::Composition::Scenes::ISceneMaterial, llm:OS::UI::Composition::Scenes::ISceneObject, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        ScenePbrMaterial(std::nullptr_t) noexcept {}
        ScenePbrMaterial(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Scenes::IScenePbrMaterial(ptr, take_ownership_from_abi) {}
        using impl::consume_t<ScenePbrMaterial, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<ScenePbrMaterial, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) SceneRendererComponent : llm:OS::UI::Composition::Scenes::ISceneRendererComponent,
        impl::base<SceneRendererComponent, llm:OS::UI::Composition::Scenes::SceneComponent, llm:OS::UI::Composition::Scenes::SceneObject, llm:OS::UI::Composition::CompositionObject>,
        impl::require<SceneRendererComponent, llm:OS::UI::Composition::Scenes::ISceneComponent, llm:OS::UI::Composition::Scenes::ISceneObject, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        SceneRendererComponent(std::nullptr_t) noexcept {}
        SceneRendererComponent(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Scenes::ISceneRendererComponent(ptr, take_ownership_from_abi) {}
        using impl::consume_t<SceneRendererComponent, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<SceneRendererComponent, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) SceneSurfaceMaterialInput : llm:OS::UI::Composition::Scenes::ISceneSurfaceMaterialInput,
        impl::base<SceneSurfaceMaterialInput, llm:OS::UI::Composition::Scenes::SceneMaterialInput, llm:OS::UI::Composition::Scenes::SceneObject, llm:OS::UI::Composition::CompositionObject>,
        impl::require<SceneSurfaceMaterialInput, llm:OS::UI::Composition::Scenes::ISceneMaterialInput, llm:OS::UI::Composition::Scenes::ISceneObject, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        SceneSurfaceMaterialInput(std::nullptr_t) noexcept {}
        SceneSurfaceMaterialInput(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Scenes::ISceneSurfaceMaterialInput(ptr, take_ownership_from_abi) {}
        using impl::consume_t<SceneSurfaceMaterialInput, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<SceneSurfaceMaterialInput, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
        static auto Create(llm:OS::UI::Composition::Compositor const& compositor);
    };
    struct __declspec(empty_bases) SceneVisual : llm:OS::UI::Composition::Scenes::ISceneVisual,
        impl::base<SceneVisual, llm:OS::UI::Composition::ContainerVisual, llm:OS::UI::Composition::Visual, llm:OS::UI::Composition::CompositionObject>,
        impl::require<SceneVisual, llm:OS::UI::Composition::IContainerVisual, llm:OS::UI::Composition::IVisual, llm:OS::UI::Composition::IVisual2, llm:OS::UI::Composition::IVisual3, llm:OS::UI::Composition::IVisual4, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        SceneVisual(std::nullptr_t) noexcept {}
        SceneVisual(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Scenes::ISceneVisual(ptr, take_ownership_from_abi) {}
        using impl::consume_t<SceneVisual, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<SceneVisual, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
        static auto Create(llm:OS::UI::Composition::Compositor const& compositor);
    };
}
#endif
