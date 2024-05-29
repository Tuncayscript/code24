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
#ifndef LLM_OS_ApplicationModel_Preview_Notes_2_H
#define LLM_OS_ApplicationModel_Preview_Notes_2_H
#include "llm/impl/Windows.ApplicationModel.Preview.Notes.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Preview::Notes
{
    struct __declspec(empty_bases) NotePlacementChangedPreviewEventArgs : llm::OS::ApplicationModel::Preview::Notes::INotePlacementChangedPreviewEventArgs
    {
        NotePlacementChangedPreviewEventArgs(std::nullptr_t) noexcept {}
        NotePlacementChangedPreviewEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Preview::Notes::INotePlacementChangedPreviewEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) NoteVisibilityChangedPreviewEventArgs : llm::OS::ApplicationModel::Preview::Notes::INoteVisibilityChangedPreviewEventArgs
    {
        NoteVisibilityChangedPreviewEventArgs(std::nullptr_t) noexcept {}
        NoteVisibilityChangedPreviewEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Preview::Notes::INoteVisibilityChangedPreviewEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) NotesWindowManagerPreview : llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreview,
        impl::require<NotesWindowManagerPreview, llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreview2>
    {
        NotesWindowManagerPreview(std::nullptr_t) noexcept {}
        NotesWindowManagerPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreview(ptr, take_ownership_from_abi) {}
        using llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreview::ShowNoteRelativeTo;
        using impl::consume_t<NotesWindowManagerPreview, llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreview2>::ShowNoteRelativeTo;
        using llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreview::ShowNoteWithPlacement;
        using impl::consume_t<NotesWindowManagerPreview, llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreview2>::ShowNoteWithPlacement;
        static auto GetForCurrentApp();
    };
    struct __declspec(empty_bases) NotesWindowManagerPreviewShowNoteOptions : llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreviewShowNoteOptions
    {
        NotesWindowManagerPreviewShowNoteOptions(std::nullptr_t) noexcept {}
        NotesWindowManagerPreviewShowNoteOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreviewShowNoteOptions(ptr, take_ownership_from_abi) {}
        NotesWindowManagerPreviewShowNoteOptions();
    };
}
#endif
