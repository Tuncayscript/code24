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
#ifndef LLM_OS_Graphics_DirectX_Direct3D11_H
#define LLM_OS_Graphics_DirectX_Direct3D11_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Graphics.DirectX.h"
#include "llm/impl/Windows.Graphics.DirectX.Direct3D11.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_DirectX_Direct3D11_IDirect3DDevice<D>::Trim() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::DirectX::Direct3D11::IDirect3DDevice)->Trim());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::DirectX::Direct3D11::Direct3DSurfaceDescription) consume_Windows_Graphics_DirectX_Direct3D11_IDirect3DSurface<D>::Description() const
    {
        llm::OS::Graphics::DirectX::Direct3D11::Direct3DSurfaceDescription value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface)->get_Description(put_abi(value)));
        return value;
    }
    template <typename D>
    struct produce<D, llm::OS::Graphics::DirectX::Direct3D11::IDirect3DDevice> : produce_base<D, llm::OS::Graphics::DirectX::Direct3D11::IDirect3DDevice>
    {
        int32_t __stdcall Trim() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Trim();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface> : produce_base<D, llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface>
    {
        int32_t __stdcall get_Description(struct struct_Windows_Graphics_DirectX_Direct3D11_Direct3DSurfaceDescription* value) noexcept final try
        {
            zero_abi<llm::OS::Graphics::DirectX::Direct3D11::Direct3DSurfaceDescription>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::DirectX::Direct3D11::Direct3DSurfaceDescription>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
}
LLM_EXPORT namespace llm::OS::Graphics::DirectX::Direct3D11
{
    constexpr auto operator|(Direct3DBindings const left, Direct3DBindings const right) noexcept
    {
        return static_cast<Direct3DBindings>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(Direct3DBindings& left, Direct3DBindings const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(Direct3DBindings const left, Direct3DBindings const right) noexcept
    {
        return static_cast<Direct3DBindings>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(Direct3DBindings& left, Direct3DBindings const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(Direct3DBindings const value) noexcept
    {
        return static_cast<Direct3DBindings>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(Direct3DBindings const left, Direct3DBindings const right) noexcept
    {
        return static_cast<Direct3DBindings>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(Direct3DBindings& left, Direct3DBindings const right) noexcept
    {
        left = left ^ right;
        return left;
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Graphics::DirectX::Direct3D11::IDirect3DDevice> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
