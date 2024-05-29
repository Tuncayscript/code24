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
#ifndef LLM_OS_ApplicationModel_DataTransfer_DragDrop_0_H
#define LLM_OS_ApplicationModel_DataTransfer_DragDrop_0_H
LLM_EXPORT namespace llm::OS::ApplicationModel::DataTransfer::DragDrop
{
    enum class DragDropModifiers : uint32_t
    {
        None = 0,
        Shift = 0x1,
        Control = 0x2,
        Alt = 0x4,
        LeftButton = 0x8,
        MiddleButton = 0x10,
        RightButton = 0x20,
    };
}
namespace llm::impl
{
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::DragDrop::DragDropModifiers>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::DragDrop::DragDropModifiers> = L"Windows.ApplicationModel.DataTransfer.DragDrop.DragDropModifiers";
}
#endif
