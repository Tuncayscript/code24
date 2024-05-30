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
#ifndef LLM_OS_Graphics_Capture_1_H
#define LLM_OS_Graphics_Capture_1_H
#include "llm/impl/Windows.Graphics.Capture.0.h"
LLM_EXPORT namespace llm:OS::Graphics::Capture
{
    struct __declspec(empty_bases) IDirect3D11CaptureFrame :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDirect3D11CaptureFrame>
    {
        IDirect3D11CaptureFrame(std::nullptr_t = nullptr) noexcept {}
        IDirect3D11CaptureFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDirect3D11CaptureFramePool :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDirect3D11CaptureFramePool>
    {
        IDirect3D11CaptureFramePool(std::nullptr_t = nullptr) noexcept {}
        IDirect3D11CaptureFramePool(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDirect3D11CaptureFramePoolStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDirect3D11CaptureFramePoolStatics>
    {
        IDirect3D11CaptureFramePoolStatics(std::nullptr_t = nullptr) noexcept {}
        IDirect3D11CaptureFramePoolStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDirect3D11CaptureFramePoolStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDirect3D11CaptureFramePoolStatics2>
    {
        IDirect3D11CaptureFramePoolStatics2(std::nullptr_t = nullptr) noexcept {}
        IDirect3D11CaptureFramePoolStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGraphicsCaptureAccessStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGraphicsCaptureAccessStatics>
    {
        IGraphicsCaptureAccessStatics(std::nullptr_t = nullptr) noexcept {}
        IGraphicsCaptureAccessStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGraphicsCaptureItem :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGraphicsCaptureItem>
    {
        IGraphicsCaptureItem(std::nullptr_t = nullptr) noexcept {}
        IGraphicsCaptureItem(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGraphicsCaptureItemStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGraphicsCaptureItemStatics>
    {
        IGraphicsCaptureItemStatics(std::nullptr_t = nullptr) noexcept {}
        IGraphicsCaptureItemStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGraphicsCaptureItemStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGraphicsCaptureItemStatics2>
    {
        IGraphicsCaptureItemStatics2(std::nullptr_t = nullptr) noexcept {}
        IGraphicsCaptureItemStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGraphicsCapturePicker :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGraphicsCapturePicker>
    {
        IGraphicsCapturePicker(std::nullptr_t = nullptr) noexcept {}
        IGraphicsCapturePicker(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGraphicsCaptureSession :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGraphicsCaptureSession>
    {
        IGraphicsCaptureSession(std::nullptr_t = nullptr) noexcept {}
        IGraphicsCaptureSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGraphicsCaptureSession2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGraphicsCaptureSession2>
    {
        IGraphicsCaptureSession2(std::nullptr_t = nullptr) noexcept {}
        IGraphicsCaptureSession2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGraphicsCaptureSession3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGraphicsCaptureSession3>
    {
        IGraphicsCaptureSession3(std::nullptr_t = nullptr) noexcept {}
        IGraphicsCaptureSession3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGraphicsCaptureSessionStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGraphicsCaptureSessionStatics>
    {
        IGraphicsCaptureSessionStatics(std::nullptr_t = nullptr) noexcept {}
        IGraphicsCaptureSessionStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
