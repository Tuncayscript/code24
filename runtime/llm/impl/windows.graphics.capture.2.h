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
#ifndef LLM_OS_Graphics_Capture_2_H
#define LLM_OS_Graphics_Capture_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Graphics.1.h"
#include "llm/impl/Windows.Graphics.DirectX.1.h"
#include "llm/impl/Windows.Graphics.DirectX.Direct3D11.1.h"
#include "llm/impl/Windows.UI.1.h"
#include "llm/impl/Windows.UI.Composition.1.h"
#include "llm/impl/Windows.Graphics.Capture.1.h"
LLM_EXPORT namespace llm:OS::Graphics::Capture
{
    struct __declspec(empty_bases) Direct3D11CaptureFrame : llm:OS::Graphics::Capture::IDirect3D11CaptureFrame,
        impl::require<Direct3D11CaptureFrame, llm:OS::Foundation::IClosable>
    {
        Direct3D11CaptureFrame(std::nullptr_t) noexcept {}
        Direct3D11CaptureFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Capture::IDirect3D11CaptureFrame(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) Direct3D11CaptureFramePool : llm:OS::Graphics::Capture::IDirect3D11CaptureFramePool,
        impl::require<Direct3D11CaptureFramePool, llm:OS::Foundation::IClosable>
    {
        Direct3D11CaptureFramePool(std::nullptr_t) noexcept {}
        Direct3D11CaptureFramePool(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Capture::IDirect3D11CaptureFramePool(ptr, take_ownership_from_abi) {}
        static auto Create(llm:OS::Graphics::DirectX::Direct3D11::IDirect3DDevice const& device, llm:OS::Graphics::DirectX::DirectXPixelFormat const& pixelFormat, int32_t numberOfBuffers, llm:OS::Graphics::SizeInt32 const& size);
        static auto CreateFreeThreaded(llm:OS::Graphics::DirectX::Direct3D11::IDirect3DDevice const& device, llm:OS::Graphics::DirectX::DirectXPixelFormat const& pixelFormat, int32_t numberOfBuffers, llm:OS::Graphics::SizeInt32 const& size);
    };
    struct GraphicsCaptureAccess
    {
        GraphicsCaptureAccess() = delete;
        static auto RequestAccessAsync(llm:OS::Graphics::Capture::GraphicsCaptureAccessKind const& request);
    };
    struct __declspec(empty_bases) GraphicsCaptureItem : llm:OS::Graphics::Capture::IGraphicsCaptureItem
    {
        GraphicsCaptureItem(std::nullptr_t) noexcept {}
        GraphicsCaptureItem(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Capture::IGraphicsCaptureItem(ptr, take_ownership_from_abi) {}
        static auto CreateFromVisual(llm:OS::UI::Composition::Visual const& visual);
        static auto TryCreateFromWindowId(llm:OS::UI::WindowId const& windowId);
        static auto TryCreateFromDisplayId(llm:OS::Graphics::DisplayId const& displayId);
    };
    struct __declspec(empty_bases) GraphicsCapturePicker : llm:OS::Graphics::Capture::IGraphicsCapturePicker
    {
        GraphicsCapturePicker(std::nullptr_t) noexcept {}
        GraphicsCapturePicker(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Capture::IGraphicsCapturePicker(ptr, take_ownership_from_abi) {}
        GraphicsCapturePicker();
    };
    struct __declspec(empty_bases) GraphicsCaptureSession : llm:OS::Graphics::Capture::IGraphicsCaptureSession,
        impl::require<GraphicsCaptureSession, llm:OS::Graphics::Capture::IGraphicsCaptureSession2, llm:OS::Graphics::Capture::IGraphicsCaptureSession3, llm:OS::Foundation::IClosable>
    {
        GraphicsCaptureSession(std::nullptr_t) noexcept {}
        GraphicsCaptureSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Capture::IGraphicsCaptureSession(ptr, take_ownership_from_abi) {}
        static auto IsSupported();
    };
}
#endif
