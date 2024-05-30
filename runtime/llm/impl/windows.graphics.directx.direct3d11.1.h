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
#ifndef LLM_OS_Graphics_DirectX_Direct3D11_1_H
#define LLM_OS_Graphics_DirectX_Direct3D11_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Graphics.DirectX.Direct3D11.0.h"
LLM_EXPORT namespace llm:OS::Graphics::DirectX::Direct3D11
{
    struct __declspec(empty_bases) IDirect3DDevice :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDirect3DDevice>,
        impl::require<llm:OS::Graphics::DirectX::Direct3D11::IDirect3DDevice, llm:OS::Foundation::IClosable>
    {
        IDirect3DDevice(std::nullptr_t = nullptr) noexcept {}
        IDirect3DDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDirect3DSurface :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDirect3DSurface>,
        impl::require<llm:OS::Graphics::DirectX::Direct3D11::IDirect3DSurface, llm:OS::Foundation::IClosable>
    {
        IDirect3DSurface(std::nullptr_t = nullptr) noexcept {}
        IDirect3DSurface(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
