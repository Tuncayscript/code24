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
#ifndef LLM_OS_Graphics_Printing3D_1_H
#define LLM_OS_Graphics_Printing3D_1_H
#include "llm/impl/Windows.Graphics.Printing3D.0.h"
LLM_EXPORT namespace llm:OS::Graphics::Printing3D
{
    struct __declspec(empty_bases) IPrint3DManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrint3DManager>
    {
        IPrint3DManager(std::nullptr_t = nullptr) noexcept {}
        IPrint3DManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrint3DManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrint3DManagerStatics>
    {
        IPrint3DManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IPrint3DManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrint3DTask :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrint3DTask>
    {
        IPrint3DTask(std::nullptr_t = nullptr) noexcept {}
        IPrint3DTask(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrint3DTaskCompletedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrint3DTaskCompletedEventArgs>
    {
        IPrint3DTaskCompletedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPrint3DTaskCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrint3DTaskRequest :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrint3DTaskRequest>
    {
        IPrint3DTaskRequest(std::nullptr_t = nullptr) noexcept {}
        IPrint3DTaskRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrint3DTaskRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrint3DTaskRequestedEventArgs>
    {
        IPrint3DTaskRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPrint3DTaskRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrint3DTaskSourceChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrint3DTaskSourceChangedEventArgs>
    {
        IPrint3DTaskSourceChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPrint3DTaskSourceChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrint3DTaskSourceRequestedArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrint3DTaskSourceRequestedArgs>
    {
        IPrint3DTaskSourceRequestedArgs(std::nullptr_t = nullptr) noexcept {}
        IPrint3DTaskSourceRequestedArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrinting3D3MFPackage :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrinting3D3MFPackage>
    {
        IPrinting3D3MFPackage(std::nullptr_t = nullptr) noexcept {}
        IPrinting3D3MFPackage(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrinting3D3MFPackage2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrinting3D3MFPackage2>
    {
        IPrinting3D3MFPackage2(std::nullptr_t = nullptr) noexcept {}
        IPrinting3D3MFPackage2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrinting3D3MFPackageStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrinting3D3MFPackageStatics>
    {
        IPrinting3D3MFPackageStatics(std::nullptr_t = nullptr) noexcept {}
        IPrinting3D3MFPackageStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrinting3DBaseMaterial :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrinting3DBaseMaterial>
    {
        IPrinting3DBaseMaterial(std::nullptr_t = nullptr) noexcept {}
        IPrinting3DBaseMaterial(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrinting3DBaseMaterialGroup :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrinting3DBaseMaterialGroup>
    {
        IPrinting3DBaseMaterialGroup(std::nullptr_t = nullptr) noexcept {}
        IPrinting3DBaseMaterialGroup(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrinting3DBaseMaterialGroupFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrinting3DBaseMaterialGroupFactory>
    {
        IPrinting3DBaseMaterialGroupFactory(std::nullptr_t = nullptr) noexcept {}
        IPrinting3DBaseMaterialGroupFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrinting3DBaseMaterialStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrinting3DBaseMaterialStatics>
    {
        IPrinting3DBaseMaterialStatics(std::nullptr_t = nullptr) noexcept {}
        IPrinting3DBaseMaterialStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrinting3DColorMaterial :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrinting3DColorMaterial>
    {
        IPrinting3DColorMaterial(std::nullptr_t = nullptr) noexcept {}
        IPrinting3DColorMaterial(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrinting3DColorMaterial2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrinting3DColorMaterial2>
    {
        IPrinting3DColorMaterial2(std::nullptr_t = nullptr) noexcept {}
        IPrinting3DColorMaterial2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrinting3DColorMaterialGroup :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrinting3DColorMaterialGroup>
    {
        IPrinting3DColorMaterialGroup(std::nullptr_t = nullptr) noexcept {}
        IPrinting3DColorMaterialGroup(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrinting3DColorMaterialGroupFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrinting3DColorMaterialGroupFactory>
    {
        IPrinting3DColorMaterialGroupFactory(std::nullptr_t = nullptr) noexcept {}
        IPrinting3DColorMaterialGroupFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrinting3DComponent :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrinting3DComponent>
    {
        IPrinting3DComponent(std::nullptr_t = nullptr) noexcept {}
        IPrinting3DComponent(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrinting3DComponentWithMatrix :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrinting3DComponentWithMatrix>
    {
        IPrinting3DComponentWithMatrix(std::nullptr_t = nullptr) noexcept {}
        IPrinting3DComponentWithMatrix(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrinting3DCompositeMaterial :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrinting3DCompositeMaterial>
    {
        IPrinting3DCompositeMaterial(std::nullptr_t = nullptr) noexcept {}
        IPrinting3DCompositeMaterial(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrinting3DCompositeMaterialGroup :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrinting3DCompositeMaterialGroup>
    {
        IPrinting3DCompositeMaterialGroup(std::nullptr_t = nullptr) noexcept {}
        IPrinting3DCompositeMaterialGroup(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrinting3DCompositeMaterialGroup2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrinting3DCompositeMaterialGroup2>
    {
        IPrinting3DCompositeMaterialGroup2(std::nullptr_t = nullptr) noexcept {}
        IPrinting3DCompositeMaterialGroup2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrinting3DCompositeMaterialGroupFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrinting3DCompositeMaterialGroupFactory>
    {
        IPrinting3DCompositeMaterialGroupFactory(std::nullptr_t = nullptr) noexcept {}
        IPrinting3DCompositeMaterialGroupFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrinting3DFaceReductionOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrinting3DFaceReductionOptions>
    {
        IPrinting3DFaceReductionOptions(std::nullptr_t = nullptr) noexcept {}
        IPrinting3DFaceReductionOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrinting3DMaterial :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrinting3DMaterial>
    {
        IPrinting3DMaterial(std::nullptr_t = nullptr) noexcept {}
        IPrinting3DMaterial(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrinting3DMesh :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrinting3DMesh>
    {
        IPrinting3DMesh(std::nullptr_t = nullptr) noexcept {}
        IPrinting3DMesh(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrinting3DMeshVerificationResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrinting3DMeshVerificationResult>
    {
        IPrinting3DMeshVerificationResult(std::nullptr_t = nullptr) noexcept {}
        IPrinting3DMeshVerificationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrinting3DModel :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrinting3DModel>
    {
        IPrinting3DModel(std::nullptr_t = nullptr) noexcept {}
        IPrinting3DModel(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrinting3DModel2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrinting3DModel2>
    {
        IPrinting3DModel2(std::nullptr_t = nullptr) noexcept {}
        IPrinting3DModel2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrinting3DModelTexture :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrinting3DModelTexture>
    {
        IPrinting3DModelTexture(std::nullptr_t = nullptr) noexcept {}
        IPrinting3DModelTexture(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrinting3DMultiplePropertyMaterial :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrinting3DMultiplePropertyMaterial>
    {
        IPrinting3DMultiplePropertyMaterial(std::nullptr_t = nullptr) noexcept {}
        IPrinting3DMultiplePropertyMaterial(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrinting3DMultiplePropertyMaterialGroup :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrinting3DMultiplePropertyMaterialGroup>
    {
        IPrinting3DMultiplePropertyMaterialGroup(std::nullptr_t = nullptr) noexcept {}
        IPrinting3DMultiplePropertyMaterialGroup(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrinting3DMultiplePropertyMaterialGroupFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrinting3DMultiplePropertyMaterialGroupFactory>
    {
        IPrinting3DMultiplePropertyMaterialGroupFactory(std::nullptr_t = nullptr) noexcept {}
        IPrinting3DMultiplePropertyMaterialGroupFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrinting3DTexture2CoordMaterial :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrinting3DTexture2CoordMaterial>
    {
        IPrinting3DTexture2CoordMaterial(std::nullptr_t = nullptr) noexcept {}
        IPrinting3DTexture2CoordMaterial(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrinting3DTexture2CoordMaterialGroup :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrinting3DTexture2CoordMaterialGroup>
    {
        IPrinting3DTexture2CoordMaterialGroup(std::nullptr_t = nullptr) noexcept {}
        IPrinting3DTexture2CoordMaterialGroup(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrinting3DTexture2CoordMaterialGroup2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrinting3DTexture2CoordMaterialGroup2>
    {
        IPrinting3DTexture2CoordMaterialGroup2(std::nullptr_t = nullptr) noexcept {}
        IPrinting3DTexture2CoordMaterialGroup2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrinting3DTexture2CoordMaterialGroupFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrinting3DTexture2CoordMaterialGroupFactory>
    {
        IPrinting3DTexture2CoordMaterialGroupFactory(std::nullptr_t = nullptr) noexcept {}
        IPrinting3DTexture2CoordMaterialGroupFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrinting3DTextureResource :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrinting3DTextureResource>
    {
        IPrinting3DTextureResource(std::nullptr_t = nullptr) noexcept {}
        IPrinting3DTextureResource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
