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
#ifndef LLM_OS_Graphics_DirectX_Direct3D11_2_H
#define LLM_OS_Graphics_DirectX_Direct3D11_2_H
#include "llm/impl/Windows.Graphics.DirectX.2.h"
#include "llm/impl/Windows.Graphics.DirectX.Direct3D11.1.h"
LLM_EXPORT namespace llm:OS::Graphics::DirectX::Direct3D11
{
    struct Direct3DMultisampleDescription
    {
        int32_t Count;
        int32_t Quality;
    };
    inline bool operator==(Direct3DMultisampleDescription const& left, Direct3DMultisampleDescription const& right) noexcept
    {
        return left.Count == right.Count && left.Quality == right.Quality;
    }
    inline bool operator!=(Direct3DMultisampleDescription const& left, Direct3DMultisampleDescription const& right) noexcept
    {
        return !(left == right);
    }
    struct Direct3DSurfaceDescription
    {
        int32_t Width;
        int32_t Height;
        llm:OS::Graphics::DirectX::DirectXPixelFormat Format;
        llm:OS::Graphics::DirectX::Direct3D11::Direct3DMultisampleDescription MultisampleDescription;
    };
    inline bool operator==(Direct3DSurfaceDescription const& left, Direct3DSurfaceDescription const& right) noexcept
    {
        return left.Width == right.Width && left.Height == right.Height && left.Format == right.Format && left.MultisampleDescription == right.MultisampleDescription;
    }
    inline bool operator!=(Direct3DSurfaceDescription const& left, Direct3DSurfaceDescription const& right) noexcept
    {
        return !(left == right);
    }
}
#endif
