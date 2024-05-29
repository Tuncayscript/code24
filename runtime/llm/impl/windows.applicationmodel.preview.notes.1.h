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
#ifndef LLM_OS_ApplicationModel_Preview_Notes_1_H
#define LLM_OS_ApplicationModel_Preview_Notes_1_H
#include "llm/impl/Windows.ApplicationModel.Preview.Notes.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Preview::Notes
{
    struct __declspec(empty_bases) INotePlacementChangedPreviewEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<INotePlacementChangedPreviewEventArgs>
    {
        INotePlacementChangedPreviewEventArgs(std::nullptr_t = nullptr) noexcept {}
        INotePlacementChangedPreviewEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INoteVisibilityChangedPreviewEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<INoteVisibilityChangedPreviewEventArgs>
    {
        INoteVisibilityChangedPreviewEventArgs(std::nullptr_t = nullptr) noexcept {}
        INoteVisibilityChangedPreviewEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INotesWindowManagerPreview :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<INotesWindowManagerPreview>
    {
        INotesWindowManagerPreview(std::nullptr_t = nullptr) noexcept {}
        INotesWindowManagerPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INotesWindowManagerPreview2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<INotesWindowManagerPreview2>
    {
        INotesWindowManagerPreview2(std::nullptr_t = nullptr) noexcept {}
        INotesWindowManagerPreview2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INotesWindowManagerPreviewShowNoteOptions :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<INotesWindowManagerPreviewShowNoteOptions>
    {
        INotesWindowManagerPreviewShowNoteOptions(std::nullptr_t = nullptr) noexcept {}
        INotesWindowManagerPreviewShowNoteOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INotesWindowManagerPreviewStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<INotesWindowManagerPreviewStatics>
    {
        INotesWindowManagerPreviewStatics(std::nullptr_t = nullptr) noexcept {}
        INotesWindowManagerPreviewStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
