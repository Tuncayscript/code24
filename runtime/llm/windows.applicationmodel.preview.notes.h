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
#ifndef LLM_OS_ApplicationModel_Preview_Notes_H
#define LLM_OS_ApplicationModel_Preview_Notes_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.ApplicationModel.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Graphics.Imaging.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.ApplicationModel.Preview.Notes.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_ApplicationModel_Preview_Notes_INotePlacementChangedPreviewEventArgs<D>::ViewId() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::Notes::INotePlacementChangedPreviewEventArgs)->get_ViewId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_ApplicationModel_Preview_Notes_INoteVisibilityChangedPreviewEventArgs<D>::ViewId() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::Notes::INoteVisibilityChangedPreviewEventArgs)->get_ViewId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Preview_Notes_INoteVisibilityChangedPreviewEventArgs<D>::IsVisible() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::Notes::INoteVisibilityChangedPreviewEventArgs)->get_IsVisible(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Preview_Notes_INotesWindowManagerPreview<D>::IsScreenLocked() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreview)->get_IsScreenLocked(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Preview_Notes_INotesWindowManagerPreview<D>::ShowNote(int32_t noteViewId) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreview)->ShowNote(noteViewId));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Preview_Notes_INotesWindowManagerPreview<D>::ShowNoteRelativeTo(int32_t noteViewId, int32_t anchorNoteViewId) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreview)->ShowNoteRelativeTo(noteViewId, anchorNoteViewId));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Preview_Notes_INotesWindowManagerPreview<D>::ShowNoteWithPlacement(int32_t noteViewId, llm::OS::Storage::Streams::IBuffer const& data) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreview)->ShowNoteWithPlacement(noteViewId, *(void**)(&data)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Preview_Notes_INotesWindowManagerPreview<D>::HideNote(int32_t noteViewId) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreview)->HideNote(noteViewId));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) consume_Windows_ApplicationModel_Preview_Notes_INotesWindowManagerPreview<D>::GetNotePlacement(int32_t noteViewId) const
    {
        void* data{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreview)->GetNotePlacement(noteViewId, &data));
        return llm::OS::Storage::Streams::IBuffer{ data, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Preview_Notes_INotesWindowManagerPreview<D>::TrySetNoteSize(int32_t noteViewId, llm::OS::Foundation::Size const& size) const
    {
        bool succeeded{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreview)->TrySetNoteSize(noteViewId, impl::bind_in(size), &succeeded));
        return succeeded;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Preview_Notes_INotesWindowManagerPreview<D>::SetFocusToNextView() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreview)->SetFocusToNextView());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_Preview_Notes_INotesWindowManagerPreview<D>::SetNotesThumbnailAsync(llm::OS::Storage::Streams::IBuffer const& thumbnail) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreview)->SetNotesThumbnailAsync(*(void**)(&thumbnail), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Preview_Notes_INotesWindowManagerPreview<D>::SystemLockStateChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreview)->add_SystemLockStateChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Preview_Notes_INotesWindowManagerPreview<D>::SystemLockStateChanged_revoker consume_Windows_ApplicationModel_Preview_Notes_INotesWindowManagerPreview<D>::SystemLockStateChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, SystemLockStateChanged_revoker>(this, SystemLockStateChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Preview_Notes_INotesWindowManagerPreview<D>::SystemLockStateChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreview)->remove_SystemLockStateChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Preview_Notes_INotesWindowManagerPreview<D>::NotePlacementChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, llm::OS::ApplicationModel::Preview::Notes::NotePlacementChangedPreviewEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreview)->add_NotePlacementChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Preview_Notes_INotesWindowManagerPreview<D>::NotePlacementChanged_revoker consume_Windows_ApplicationModel_Preview_Notes_INotesWindowManagerPreview<D>::NotePlacementChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, llm::OS::ApplicationModel::Preview::Notes::NotePlacementChangedPreviewEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, NotePlacementChanged_revoker>(this, NotePlacementChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Preview_Notes_INotesWindowManagerPreview<D>::NotePlacementChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreview)->remove_NotePlacementChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Preview_Notes_INotesWindowManagerPreview<D>::NoteVisibilityChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, llm::OS::ApplicationModel::Preview::Notes::NoteVisibilityChangedPreviewEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreview)->add_NoteVisibilityChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Preview_Notes_INotesWindowManagerPreview<D>::NoteVisibilityChanged_revoker consume_Windows_ApplicationModel_Preview_Notes_INotesWindowManagerPreview<D>::NoteVisibilityChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, llm::OS::ApplicationModel::Preview::Notes::NoteVisibilityChangedPreviewEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, NoteVisibilityChanged_revoker>(this, NoteVisibilityChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Preview_Notes_INotesWindowManagerPreview<D>::NoteVisibilityChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreview)->remove_NoteVisibilityChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Preview_Notes_INotesWindowManagerPreview2<D>::ShowNoteRelativeTo(int32_t noteViewId, int32_t anchorNoteViewId, llm::OS::ApplicationModel::Preview::Notes::NotesWindowManagerPreviewShowNoteOptions const& options) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreview2)->ShowNoteRelativeToWithOptions(noteViewId, anchorNoteViewId, *(void**)(&options)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Preview_Notes_INotesWindowManagerPreview2<D>::ShowNoteWithPlacement(int32_t noteViewId, llm::OS::Storage::Streams::IBuffer const& data, llm::OS::ApplicationModel::Preview::Notes::NotesWindowManagerPreviewShowNoteOptions const& options) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreview2)->ShowNoteWithPlacementWithOptions(noteViewId, *(void**)(&data), *(void**)(&options)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Preview_Notes_INotesWindowManagerPreview2<D>::SetFocusToPreviousView() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreview2)->SetFocusToPreviousView());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_Preview_Notes_INotesWindowManagerPreview2<D>::SetThumbnailImageForTaskSwitcherAsync(llm::OS::Graphics::Imaging::SoftwareBitmap const& bitmap) const
    {
        void* action{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreview2)->SetThumbnailImageForTaskSwitcherAsync(*(void**)(&bitmap), &action));
        return llm::OS::Foundation::IAsyncAction{ action, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Preview_Notes_INotesWindowManagerPreviewShowNoteOptions<D>::ShowWithFocus() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreviewShowNoteOptions)->get_ShowWithFocus(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Preview_Notes_INotesWindowManagerPreviewShowNoteOptions<D>::ShowWithFocus(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreviewShowNoteOptions)->put_ShowWithFocus(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Preview::Notes::NotesWindowManagerPreview) consume_Windows_ApplicationModel_Preview_Notes_INotesWindowManagerPreviewStatics<D>::GetForCurrentApp() const
    {
        void* current{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreviewStatics)->GetForCurrentApp(&current));
        return llm::OS::ApplicationModel::Preview::Notes::NotesWindowManagerPreview{ current, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Preview::Notes::INotePlacementChangedPreviewEventArgs> : produce_base<D, llm::OS::ApplicationModel::Preview::Notes::INotePlacementChangedPreviewEventArgs>
    {
        int32_t __stdcall get_ViewId(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().ViewId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Preview::Notes::INoteVisibilityChangedPreviewEventArgs> : produce_base<D, llm::OS::ApplicationModel::Preview::Notes::INoteVisibilityChangedPreviewEventArgs>
    {
        int32_t __stdcall get_ViewId(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().ViewId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsVisible(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsVisible());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreview> : produce_base<D, llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreview>
    {
        int32_t __stdcall get_IsScreenLocked(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsScreenLocked());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowNote(int32_t noteViewId) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowNote(noteViewId);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowNoteRelativeTo(int32_t noteViewId, int32_t anchorNoteViewId) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowNoteRelativeTo(noteViewId, anchorNoteViewId);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowNoteWithPlacement(int32_t noteViewId, void* data) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowNoteWithPlacement(noteViewId, *reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&data));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall HideNote(int32_t noteViewId) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HideNote(noteViewId);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetNotePlacement(int32_t noteViewId, void** data) noexcept final try
        {
            clear_abi(data);
            typename D::abi_guard guard(this->shim());
            *data = detach_from<llm::OS::Storage::Streams::IBuffer>(this->shim().GetNotePlacement(noteViewId));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TrySetNoteSize(int32_t noteViewId, llm::OS::Foundation::Size size, bool* succeeded) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_from<bool>(this->shim().TrySetNoteSize(noteViewId, *reinterpret_cast<llm::OS::Foundation::Size const*>(&size)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetFocusToNextView() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetFocusToNextView();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetNotesThumbnailAsync(void* thumbnail, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SetNotesThumbnailAsync(*reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&thumbnail)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_SystemLockStateChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().SystemLockStateChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_SystemLockStateChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SystemLockStateChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_NotePlacementChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().NotePlacementChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, llm::OS::ApplicationModel::Preview::Notes::NotePlacementChangedPreviewEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_NotePlacementChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotePlacementChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_NoteVisibilityChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().NoteVisibilityChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Preview::Notes::NotesWindowManagerPreview, llm::OS::ApplicationModel::Preview::Notes::NoteVisibilityChangedPreviewEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_NoteVisibilityChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NoteVisibilityChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreview2> : produce_base<D, llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreview2>
    {
        int32_t __stdcall ShowNoteRelativeToWithOptions(int32_t noteViewId, int32_t anchorNoteViewId, void* options) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowNoteRelativeTo(noteViewId, anchorNoteViewId, *reinterpret_cast<llm::OS::ApplicationModel::Preview::Notes::NotesWindowManagerPreviewShowNoteOptions const*>(&options));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowNoteWithPlacementWithOptions(int32_t noteViewId, void* data, void* options) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowNoteWithPlacement(noteViewId, *reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&data), *reinterpret_cast<llm::OS::ApplicationModel::Preview::Notes::NotesWindowManagerPreviewShowNoteOptions const*>(&options));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetFocusToPreviousView() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetFocusToPreviousView();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetThumbnailImageForTaskSwitcherAsync(void* bitmap, void** action) noexcept final try
        {
            clear_abi(action);
            typename D::abi_guard guard(this->shim());
            *action = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SetThumbnailImageForTaskSwitcherAsync(*reinterpret_cast<llm::OS::Graphics::Imaging::SoftwareBitmap const*>(&bitmap)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreviewShowNoteOptions> : produce_base<D, llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreviewShowNoteOptions>
    {
        int32_t __stdcall get_ShowWithFocus(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().ShowWithFocus());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ShowWithFocus(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowWithFocus(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreviewStatics> : produce_base<D, llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreviewStatics>
    {
        int32_t __stdcall GetForCurrentApp(void** current) noexcept final try
        {
            clear_abi(current);
            typename D::abi_guard guard(this->shim());
            *current = detach_from<llm::OS::ApplicationModel::Preview::Notes::NotesWindowManagerPreview>(this->shim().GetForCurrentApp());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::ApplicationModel::Preview::Notes
{
    inline auto NotesWindowManagerPreview::GetForCurrentApp()
    {
        return impl::call_factory_cast<llm::OS::ApplicationModel::Preview::Notes::NotesWindowManagerPreview(*)(INotesWindowManagerPreviewStatics const&), NotesWindowManagerPreview, INotesWindowManagerPreviewStatics>([](INotesWindowManagerPreviewStatics const& f) { return f.GetForCurrentApp(); });
    }
    inline NotesWindowManagerPreviewShowNoteOptions::NotesWindowManagerPreviewShowNoteOptions() :
        NotesWindowManagerPreviewShowNoteOptions(impl::call_factory_cast<NotesWindowManagerPreviewShowNoteOptions(*)(llm::OS::Foundation::IActivationFactory const&), NotesWindowManagerPreviewShowNoteOptions>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<NotesWindowManagerPreviewShowNoteOptions>(); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::ApplicationModel::Preview::Notes::INotePlacementChangedPreviewEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Preview::Notes::INoteVisibilityChangedPreviewEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreview> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreview2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreviewShowNoteOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Preview::Notes::INotesWindowManagerPreviewStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Preview::Notes::NotePlacementChangedPreviewEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Preview::Notes::NoteVisibilityChangedPreviewEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Preview::Notes::NotesWindowManagerPreview> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Preview::Notes::NotesWindowManagerPreviewShowNoteOptions> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
