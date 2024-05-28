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
#ifndef LLM_OS_Storage_Pickers_Provider_H
#define LLM_OS_Storage_Pickers_Provider_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Storage.Pickers.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Storage.2.h"
#include "llm/impl/Windows.Storage.Pickers.Provider.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Pickers::Provider::AddFileResult) consume_Windows_Storage_Pickers_Provider_IFileOpenPickerUI<D>::AddFile(param::hstring const& id, llm::OS::Storage::IStorageFile const& file) const
    {
        llm::OS::Storage::Pickers::Provider::AddFileResult addResult{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::IFileOpenPickerUI)->AddFile(*(void**)(&id), *(void**)(&file), reinterpret_cast<int32_t*>(&addResult)));
        return addResult;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Pickers_Provider_IFileOpenPickerUI<D>::RemoveFile(param::hstring const& id) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::IFileOpenPickerUI)->RemoveFile(*(void**)(&id)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Storage_Pickers_Provider_IFileOpenPickerUI<D>::ContainsFile(param::hstring const& id) const
    {
        bool isContained{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::IFileOpenPickerUI)->ContainsFile(*(void**)(&id), &isContained));
        return isContained;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Storage_Pickers_Provider_IFileOpenPickerUI<D>::CanAddFile(llm::OS::Storage::IStorageFile const& file) const
    {
        bool canAdd{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::IFileOpenPickerUI)->CanAddFile(*(void**)(&file), &canAdd));
        return canAdd;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_Storage_Pickers_Provider_IFileOpenPickerUI<D>::AllowedFileTypes() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::IFileOpenPickerUI)->get_AllowedFileTypes(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Pickers::Provider::FileSelectionMode) consume_Windows_Storage_Pickers_Provider_IFileOpenPickerUI<D>::SelectionMode() const
    {
        llm::OS::Storage::Pickers::Provider::FileSelectionMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::IFileOpenPickerUI)->get_SelectionMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_Pickers_Provider_IFileOpenPickerUI<D>::SettingsIdentifier() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::IFileOpenPickerUI)->get_SettingsIdentifier(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_Pickers_Provider_IFileOpenPickerUI<D>::Title() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::IFileOpenPickerUI)->get_Title(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Pickers_Provider_IFileOpenPickerUI<D>::Title(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::IFileOpenPickerUI)->put_Title(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Storage_Pickers_Provider_IFileOpenPickerUI<D>::FileRemoved(llm::OS::Foundation::TypedEventHandler<llm::OS::Storage::Pickers::Provider::FileOpenPickerUI, llm::OS::Storage::Pickers::Provider::FileRemovedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::IFileOpenPickerUI)->add_FileRemoved(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Storage_Pickers_Provider_IFileOpenPickerUI<D>::FileRemoved_revoker consume_Windows_Storage_Pickers_Provider_IFileOpenPickerUI<D>::FileRemoved(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Storage::Pickers::Provider::FileOpenPickerUI, llm::OS::Storage::Pickers::Provider::FileRemovedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, FileRemoved_revoker>(this, FileRemoved(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Pickers_Provider_IFileOpenPickerUI<D>::FileRemoved(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::IFileOpenPickerUI)->remove_FileRemoved(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Storage_Pickers_Provider_IFileOpenPickerUI<D>::Closing(llm::OS::Foundation::TypedEventHandler<llm::OS::Storage::Pickers::Provider::FileOpenPickerUI, llm::OS::Storage::Pickers::Provider::PickerClosingEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::IFileOpenPickerUI)->add_Closing(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Storage_Pickers_Provider_IFileOpenPickerUI<D>::Closing_revoker consume_Windows_Storage_Pickers_Provider_IFileOpenPickerUI<D>::Closing(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Storage::Pickers::Provider::FileOpenPickerUI, llm::OS::Storage::Pickers::Provider::PickerClosingEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Closing_revoker>(this, Closing(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Pickers_Provider_IFileOpenPickerUI<D>::Closing(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::IFileOpenPickerUI)->remove_Closing(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_Pickers_Provider_IFileRemovedEventArgs<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::IFileRemovedEventArgs)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_Pickers_Provider_IFileSavePickerUI<D>::Title() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::IFileSavePickerUI)->get_Title(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Pickers_Provider_IFileSavePickerUI<D>::Title(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::IFileSavePickerUI)->put_Title(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_Storage_Pickers_Provider_IFileSavePickerUI<D>::AllowedFileTypes() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::IFileSavePickerUI)->get_AllowedFileTypes(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_Pickers_Provider_IFileSavePickerUI<D>::SettingsIdentifier() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::IFileSavePickerUI)->get_SettingsIdentifier(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_Pickers_Provider_IFileSavePickerUI<D>::FileName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::IFileSavePickerUI)->get_FileName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Pickers::Provider::SetFileNameResult) consume_Windows_Storage_Pickers_Provider_IFileSavePickerUI<D>::TrySetFileName(param::hstring const& value) const
    {
        llm::OS::Storage::Pickers::Provider::SetFileNameResult result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::IFileSavePickerUI)->TrySetFileName(*(void**)(&value), reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Storage_Pickers_Provider_IFileSavePickerUI<D>::FileNameChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Storage::Pickers::Provider::FileSavePickerUI, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::IFileSavePickerUI)->add_FileNameChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Storage_Pickers_Provider_IFileSavePickerUI<D>::FileNameChanged_revoker consume_Windows_Storage_Pickers_Provider_IFileSavePickerUI<D>::FileNameChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Storage::Pickers::Provider::FileSavePickerUI, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, FileNameChanged_revoker>(this, FileNameChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Pickers_Provider_IFileSavePickerUI<D>::FileNameChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::IFileSavePickerUI)->remove_FileNameChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Storage_Pickers_Provider_IFileSavePickerUI<D>::TargetFileRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::Storage::Pickers::Provider::FileSavePickerUI, llm::OS::Storage::Pickers::Provider::TargetFileRequestedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::IFileSavePickerUI)->add_TargetFileRequested(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Storage_Pickers_Provider_IFileSavePickerUI<D>::TargetFileRequested_revoker consume_Windows_Storage_Pickers_Provider_IFileSavePickerUI<D>::TargetFileRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Storage::Pickers::Provider::FileSavePickerUI, llm::OS::Storage::Pickers::Provider::TargetFileRequestedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, TargetFileRequested_revoker>(this, TargetFileRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Pickers_Provider_IFileSavePickerUI<D>::TargetFileRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::IFileSavePickerUI)->remove_TargetFileRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Pickers_Provider_IPickerClosingDeferral<D>::Complete() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::IPickerClosingDeferral)->Complete());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Pickers::Provider::PickerClosingOperation) consume_Windows_Storage_Pickers_Provider_IPickerClosingEventArgs<D>::ClosingOperation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::IPickerClosingEventArgs)->get_ClosingOperation(&value));
        return llm::OS::Storage::Pickers::Provider::PickerClosingOperation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Storage_Pickers_Provider_IPickerClosingEventArgs<D>::IsCanceled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::IPickerClosingEventArgs)->get_IsCanceled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Pickers::Provider::PickerClosingDeferral) consume_Windows_Storage_Pickers_Provider_IPickerClosingOperation<D>::GetDeferral() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::IPickerClosingOperation)->GetDeferral(&value));
        return llm::OS::Storage::Pickers::Provider::PickerClosingDeferral{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Storage_Pickers_Provider_IPickerClosingOperation<D>::Deadline() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::IPickerClosingOperation)->get_Deadline(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::IStorageFile) consume_Windows_Storage_Pickers_Provider_ITargetFileRequest<D>::TargetFile() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::ITargetFileRequest)->get_TargetFile(&value));
        return llm::OS::Storage::IStorageFile{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Pickers_Provider_ITargetFileRequest<D>::TargetFile(llm::OS::Storage::IStorageFile const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::ITargetFileRequest)->put_TargetFile(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Pickers::Provider::TargetFileRequestDeferral) consume_Windows_Storage_Pickers_Provider_ITargetFileRequest<D>::GetDeferral() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::ITargetFileRequest)->GetDeferral(&value));
        return llm::OS::Storage::Pickers::Provider::TargetFileRequestDeferral{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Pickers_Provider_ITargetFileRequestDeferral<D>::Complete() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::ITargetFileRequestDeferral)->Complete());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Pickers::Provider::TargetFileRequest) consume_Windows_Storage_Pickers_Provider_ITargetFileRequestedEventArgs<D>::Request() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::Provider::ITargetFileRequestedEventArgs)->get_Request(&value));
        return llm::OS::Storage::Pickers::Provider::TargetFileRequest{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Pickers::Provider::IFileOpenPickerUI> : produce_base<D, llm::OS::Storage::Pickers::Provider::IFileOpenPickerUI>
    {
        int32_t __stdcall AddFile(void* id, void* file, int32_t* addResult) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *addResult = detach_from<llm::OS::Storage::Pickers::Provider::AddFileResult>(this->shim().AddFile(*reinterpret_cast<hstring const*>(&id), *reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&file)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RemoveFile(void* id) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveFile(*reinterpret_cast<hstring const*>(&id));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ContainsFile(void* id, bool* isContained) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *isContained = detach_from<bool>(this->shim().ContainsFile(*reinterpret_cast<hstring const*>(&id)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CanAddFile(void* file, bool* canAdd) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *canAdd = detach_from<bool>(this->shim().CanAddFile(*reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&file)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AllowedFileTypes(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().AllowedFileTypes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SelectionMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Pickers::Provider::FileSelectionMode>(this->shim().SelectionMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SettingsIdentifier(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SettingsIdentifier());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Title(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Title());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Title(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Title(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_FileRemoved(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().FileRemoved(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Storage::Pickers::Provider::FileOpenPickerUI, llm::OS::Storage::Pickers::Provider::FileRemovedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_FileRemoved(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FileRemoved(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Closing(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Closing(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Storage::Pickers::Provider::FileOpenPickerUI, llm::OS::Storage::Pickers::Provider::PickerClosingEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Closing(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Closing(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Pickers::Provider::IFileRemovedEventArgs> : produce_base<D, llm::OS::Storage::Pickers::Provider::IFileRemovedEventArgs>
    {
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Pickers::Provider::IFileSavePickerUI> : produce_base<D, llm::OS::Storage::Pickers::Provider::IFileSavePickerUI>
    {
        int32_t __stdcall get_Title(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Title());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Title(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Title(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AllowedFileTypes(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().AllowedFileTypes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SettingsIdentifier(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SettingsIdentifier());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FileName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().FileName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TrySetFileName(void* value, int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Storage::Pickers::Provider::SetFileNameResult>(this->shim().TrySetFileName(*reinterpret_cast<hstring const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_FileNameChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().FileNameChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Storage::Pickers::Provider::FileSavePickerUI, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_FileNameChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FileNameChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_TargetFileRequested(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().TargetFileRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Storage::Pickers::Provider::FileSavePickerUI, llm::OS::Storage::Pickers::Provider::TargetFileRequestedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_TargetFileRequested(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TargetFileRequested(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Pickers::Provider::IPickerClosingDeferral> : produce_base<D, llm::OS::Storage::Pickers::Provider::IPickerClosingDeferral>
    {
        int32_t __stdcall Complete() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Complete();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Pickers::Provider::IPickerClosingEventArgs> : produce_base<D, llm::OS::Storage::Pickers::Provider::IPickerClosingEventArgs>
    {
        int32_t __stdcall get_ClosingOperation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Pickers::Provider::PickerClosingOperation>(this->shim().ClosingOperation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsCanceled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsCanceled());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Pickers::Provider::IPickerClosingOperation> : produce_base<D, llm::OS::Storage::Pickers::Provider::IPickerClosingOperation>
    {
        int32_t __stdcall GetDeferral(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Pickers::Provider::PickerClosingDeferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Deadline(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().Deadline());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Pickers::Provider::ITargetFileRequest> : produce_base<D, llm::OS::Storage::Pickers::Provider::ITargetFileRequest>
    {
        int32_t __stdcall get_TargetFile(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::IStorageFile>(this->shim().TargetFile());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TargetFile(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TargetFile(*reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Pickers::Provider::TargetFileRequestDeferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Pickers::Provider::ITargetFileRequestDeferral> : produce_base<D, llm::OS::Storage::Pickers::Provider::ITargetFileRequestDeferral>
    {
        int32_t __stdcall Complete() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Complete();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Pickers::Provider::ITargetFileRequestedEventArgs> : produce_base<D, llm::OS::Storage::Pickers::Provider::ITargetFileRequestedEventArgs>
    {
        int32_t __stdcall get_Request(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Pickers::Provider::TargetFileRequest>(this->shim().Request());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Storage::Pickers::Provider
{
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Storage::Pickers::Provider::IFileOpenPickerUI> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::Provider::IFileRemovedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::Provider::IFileSavePickerUI> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::Provider::IPickerClosingDeferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::Provider::IPickerClosingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::Provider::IPickerClosingOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::Provider::ITargetFileRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::Provider::ITargetFileRequestDeferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::Provider::ITargetFileRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::Provider::FileOpenPickerUI> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::Provider::FileRemovedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::Provider::FileSavePickerUI> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::Provider::PickerClosingDeferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::Provider::PickerClosingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::Provider::PickerClosingOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::Provider::TargetFileRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::Provider::TargetFileRequestDeferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::Provider::TargetFileRequestedEventArgs> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
