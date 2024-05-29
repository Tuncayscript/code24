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
#ifndef LLM_OS_Graphics_2_H
#define LLM_OS_Graphics_2_H
#include "llm/impl/Windows.Graphics.1.h"
LLM_EXPORT namespace llm:OS::Graphics
{
    struct DisplayAdapterId
    {
        uint32_t LowPart;
        int32_t HighPart;
    };
    inline bool operator==(DisplayAdapterId const& left, DisplayAdapterId const& right) noexcept
    {
        return left.LowPart == right.LowPart && left.HighPart == right.HighPart;
    }
    inline bool operator!=(DisplayAdapterId const& left, DisplayAdapterId const& right) noexcept
    {
        return !(left == right);
    }
    struct DisplayId
    {
        uint64_t Value;
    };
    inline bool operator==(DisplayId const& left, DisplayId const& right) noexcept
    {
        return left.Value == right.Value;
    }
    inline bool operator!=(DisplayId const& left, DisplayId const& right) noexcept
    {
        return !(left == right);
    }
    struct PointInt32
    {
        int32_t X;
        int32_t Y;
    };
    inline bool operator==(PointInt32 const& left, PointInt32 const& right) noexcept
    {
        return left.X == right.X && left.Y == right.Y;
    }
    inline bool operator!=(PointInt32 const& left, PointInt32 const& right) noexcept
    {
        return !(left == right);
    }
    struct RectInt32
    {
        int32_t X;
        int32_t Y;
        int32_t Width;
        int32_t Height;
    };
    inline bool operator==(RectInt32 const& left, RectInt32 const& right) noexcept
    {
        return left.X == right.X && left.Y == right.Y && left.Width == right.Width && left.Height == right.Height;
    }
    inline bool operator!=(RectInt32 const& left, RectInt32 const& right) noexcept
    {
        return !(left == right);
    }
    struct SizeInt32
    {
        int32_t Width;
        int32_t Height;
    };
    inline bool operator==(SizeInt32 const& left, SizeInt32 const& right) noexcept
    {
        return left.Width == right.Width && left.Height == right.Height;
    }
    inline bool operator!=(SizeInt32 const& left, SizeInt32 const& right) noexcept
    {
        return !(left == right);
    }
}
#endif
