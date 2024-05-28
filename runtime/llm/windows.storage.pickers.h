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
#ifndef LLM_OS_Storage_Pickers_H
#define LLM_OS_Storage_Pickers_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Storage.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Storage.2.h"
#include "llm/impl/Windows.System.2.h"
#include "llm/impl/Windows.Storage.Pickers.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Pickers::PickerViewMode) consume_Windows_Storage_Pickers_IFileOpenPicker<D>::ViewMode() const
    {
        llm::OS::Storage::Pickers::PickerViewMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileOpenPicker)->get_ViewMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Pickers_IFileOpenPicker<D>::ViewMode(llm::OS::Storage::Pickers::PickerViewMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileOpenPicker)->put_ViewMode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_Pickers_IFileOpenPicker<D>::SettingsIdentifier() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileOpenPicker)->get_SettingsIdentifier(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Pickers_IFileOpenPicker<D>::SettingsIdentifier(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileOpenPicker)->put_SettingsIdentifier(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Pickers::PickerLocationId) consume_Windows_Storage_Pickers_IFileOpenPicker<D>::SuggestedStartLocation() const
    {
        llm::OS::Storage::Pickers::PickerLocationId value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileOpenPicker)->get_SuggestedStartLocation(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Pickers_IFileOpenPicker<D>::SuggestedStartLocation(llm::OS::Storage::Pickers::PickerLocationId const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileOpenPicker)->put_SuggestedStartLocation(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_Pickers_IFileOpenPicker<D>::CommitButtonText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileOpenPicker)->get_CommitButtonText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Pickers_IFileOpenPicker<D>::CommitButtonText(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileOpenPicker)->put_CommitButtonText(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Storage_Pickers_IFileOpenPicker<D>::FileTypeFilter() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileOpenPicker)->get_FileTypeFilter(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFile>) consume_Windows_Storage_Pickers_IFileOpenPicker<D>::PickSingleFileAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileOpenPicker)->PickSingleFileAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFile>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFile>>) consume_Windows_Storage_Pickers_IFileOpenPicker<D>::PickMultipleFilesAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileOpenPicker)->PickMultipleFilesAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFile>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::ValueSet) consume_Windows_Storage_Pickers_IFileOpenPicker2<D>::ContinuationData() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileOpenPicker2)->get_ContinuationData(&value));
        return llm::OS::Foundation::Collections::ValueSet{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Pickers_IFileOpenPicker2<D>::PickSingleFileAndContinue() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileOpenPicker2)->PickSingleFileAndContinue());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Pickers_IFileOpenPicker2<D>::PickMultipleFilesAndContinue() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileOpenPicker2)->PickMultipleFilesAndContinue());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_Storage_Pickers_IFileOpenPicker3<D>::User() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileOpenPicker3)->get_User(&value));
        return llm::OS::System::User{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFile>) consume_Windows_Storage_Pickers_IFileOpenPickerStatics<D>::ResumePickSingleFileAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileOpenPickerStatics)->ResumePickSingleFileAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFile>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Pickers::FileOpenPicker) consume_Windows_Storage_Pickers_IFileOpenPickerStatics2<D>::CreateForUser(llm::OS::System::User const& user) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileOpenPickerStatics2)->CreateForUser(*(void**)(&user), &result));
        return llm::OS::Storage::Pickers::FileOpenPicker{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFile>) consume_Windows_Storage_Pickers_IFileOpenPickerWithOperationId<D>::PickSingleFileAsync(param::hstring const& pickerOperationId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileOpenPickerWithOperationId)->PickSingleFileAsync(*(void**)(&pickerOperationId), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFile>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_Pickers_IFileSavePicker<D>::SettingsIdentifier() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileSavePicker)->get_SettingsIdentifier(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Pickers_IFileSavePicker<D>::SettingsIdentifier(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileSavePicker)->put_SettingsIdentifier(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Pickers::PickerLocationId) consume_Windows_Storage_Pickers_IFileSavePicker<D>::SuggestedStartLocation() const
    {
        llm::OS::Storage::Pickers::PickerLocationId value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileSavePicker)->get_SuggestedStartLocation(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Pickers_IFileSavePicker<D>::SuggestedStartLocation(llm::OS::Storage::Pickers::PickerLocationId const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileSavePicker)->put_SuggestedStartLocation(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_Pickers_IFileSavePicker<D>::CommitButtonText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileSavePicker)->get_CommitButtonText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Pickers_IFileSavePicker<D>::CommitButtonText(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileSavePicker)->put_CommitButtonText(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMap<hstring, llm::OS::Foundation::Collections::IVector<hstring>>) consume_Windows_Storage_Pickers_IFileSavePicker<D>::FileTypeChoices() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileSavePicker)->get_FileTypeChoices(&value));
        return llm::OS::Foundation::Collections::IMap<hstring, llm::OS::Foundation::Collections::IVector<hstring>>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_Pickers_IFileSavePicker<D>::DefaultFileExtension() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileSavePicker)->get_DefaultFileExtension(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Pickers_IFileSavePicker<D>::DefaultFileExtension(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileSavePicker)->put_DefaultFileExtension(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::StorageFile) consume_Windows_Storage_Pickers_IFileSavePicker<D>::SuggestedSaveFile() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileSavePicker)->get_SuggestedSaveFile(&value));
        return llm::OS::Storage::StorageFile{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Pickers_IFileSavePicker<D>::SuggestedSaveFile(llm::OS::Storage::StorageFile const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileSavePicker)->put_SuggestedSaveFile(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_Pickers_IFileSavePicker<D>::SuggestedFileName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileSavePicker)->get_SuggestedFileName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Pickers_IFileSavePicker<D>::SuggestedFileName(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileSavePicker)->put_SuggestedFileName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFile>) consume_Windows_Storage_Pickers_IFileSavePicker<D>::PickSaveFileAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileSavePicker)->PickSaveFileAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFile>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::ValueSet) consume_Windows_Storage_Pickers_IFileSavePicker2<D>::ContinuationData() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileSavePicker2)->get_ContinuationData(&value));
        return llm::OS::Foundation::Collections::ValueSet{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Pickers_IFileSavePicker2<D>::PickSaveFileAndContinue() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileSavePicker2)->PickSaveFileAndContinue());
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_Pickers_IFileSavePicker3<D>::EnterpriseId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileSavePicker3)->get_EnterpriseId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Pickers_IFileSavePicker3<D>::EnterpriseId(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileSavePicker3)->put_EnterpriseId(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_Storage_Pickers_IFileSavePicker4<D>::User() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileSavePicker4)->get_User(&value));
        return llm::OS::System::User{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Pickers::FileSavePicker) consume_Windows_Storage_Pickers_IFileSavePickerStatics<D>::CreateForUser(llm::OS::System::User const& user) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFileSavePickerStatics)->CreateForUser(*(void**)(&user), &result));
        return llm::OS::Storage::Pickers::FileSavePicker{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Pickers::PickerViewMode) consume_Windows_Storage_Pickers_IFolderPicker<D>::ViewMode() const
    {
        llm::OS::Storage::Pickers::PickerViewMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFolderPicker)->get_ViewMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Pickers_IFolderPicker<D>::ViewMode(llm::OS::Storage::Pickers::PickerViewMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFolderPicker)->put_ViewMode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_Pickers_IFolderPicker<D>::SettingsIdentifier() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFolderPicker)->get_SettingsIdentifier(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Pickers_IFolderPicker<D>::SettingsIdentifier(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFolderPicker)->put_SettingsIdentifier(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Pickers::PickerLocationId) consume_Windows_Storage_Pickers_IFolderPicker<D>::SuggestedStartLocation() const
    {
        llm::OS::Storage::Pickers::PickerLocationId value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFolderPicker)->get_SuggestedStartLocation(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Pickers_IFolderPicker<D>::SuggestedStartLocation(llm::OS::Storage::Pickers::PickerLocationId const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFolderPicker)->put_SuggestedStartLocation(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_Pickers_IFolderPicker<D>::CommitButtonText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFolderPicker)->get_CommitButtonText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Pickers_IFolderPicker<D>::CommitButtonText(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFolderPicker)->put_CommitButtonText(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Storage_Pickers_IFolderPicker<D>::FileTypeFilter() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFolderPicker)->get_FileTypeFilter(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFolder>) consume_Windows_Storage_Pickers_IFolderPicker<D>::PickSingleFolderAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFolderPicker)->PickSingleFolderAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFolder>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::ValueSet) consume_Windows_Storage_Pickers_IFolderPicker2<D>::ContinuationData() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFolderPicker2)->get_ContinuationData(&value));
        return llm::OS::Foundation::Collections::ValueSet{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Pickers_IFolderPicker2<D>::PickFolderAndContinue() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFolderPicker2)->PickFolderAndContinue());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_Storage_Pickers_IFolderPicker3<D>::User() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFolderPicker3)->get_User(&value));
        return llm::OS::System::User{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Pickers::FolderPicker) consume_Windows_Storage_Pickers_IFolderPickerStatics<D>::CreateForUser(llm::OS::System::User const& user) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Pickers::IFolderPickerStatics)->CreateForUser(*(void**)(&user), &result));
        return llm::OS::Storage::Pickers::FolderPicker{ result, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Pickers::IFileOpenPicker> : produce_base<D, llm::OS::Storage::Pickers::IFileOpenPicker>
    {
        int32_t __stdcall get_ViewMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Pickers::PickerViewMode>(this->shim().ViewMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ViewMode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ViewMode(*reinterpret_cast<llm::OS::Storage::Pickers::PickerViewMode const*>(&value));
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
        int32_t __stdcall put_SettingsIdentifier(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SettingsIdentifier(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SuggestedStartLocation(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Pickers::PickerLocationId>(this->shim().SuggestedStartLocation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SuggestedStartLocation(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SuggestedStartLocation(*reinterpret_cast<llm::OS::Storage::Pickers::PickerLocationId const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CommitButtonText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().CommitButtonText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CommitButtonText(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CommitButtonText(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FileTypeFilter(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().FileTypeFilter());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall PickSingleFileAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFile>>(this->shim().PickSingleFileAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall PickMultipleFilesAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFile>>>(this->shim().PickMultipleFilesAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Pickers::IFileOpenPicker2> : produce_base<D, llm::OS::Storage::Pickers::IFileOpenPicker2>
    {
        int32_t __stdcall get_ContinuationData(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::ValueSet>(this->shim().ContinuationData());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall PickSingleFileAndContinue() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PickSingleFileAndContinue();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall PickMultipleFilesAndContinue() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PickMultipleFilesAndContinue();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Pickers::IFileOpenPicker3> : produce_base<D, llm::OS::Storage::Pickers::IFileOpenPicker3>
    {
        int32_t __stdcall get_User(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::User>(this->shim().User());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Pickers::IFileOpenPickerStatics> : produce_base<D, llm::OS::Storage::Pickers::IFileOpenPickerStatics>
    {
        int32_t __stdcall ResumePickSingleFileAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFile>>(this->shim().ResumePickSingleFileAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Pickers::IFileOpenPickerStatics2> : produce_base<D, llm::OS::Storage::Pickers::IFileOpenPickerStatics2>
    {
        int32_t __stdcall CreateForUser(void* user, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Storage::Pickers::FileOpenPicker>(this->shim().CreateForUser(*reinterpret_cast<llm::OS::System::User const*>(&user)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Pickers::IFileOpenPickerWithOperationId> : produce_base<D, llm::OS::Storage::Pickers::IFileOpenPickerWithOperationId>
    {
        int32_t __stdcall PickSingleFileAsync(void* pickerOperationId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFile>>(this->shim().PickSingleFileAsync(*reinterpret_cast<hstring const*>(&pickerOperationId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Pickers::IFileSavePicker> : produce_base<D, llm::OS::Storage::Pickers::IFileSavePicker>
    {
        int32_t __stdcall get_SettingsIdentifier(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SettingsIdentifier());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SettingsIdentifier(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SettingsIdentifier(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SuggestedStartLocation(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Pickers::PickerLocationId>(this->shim().SuggestedStartLocation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SuggestedStartLocation(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SuggestedStartLocation(*reinterpret_cast<llm::OS::Storage::Pickers::PickerLocationId const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CommitButtonText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().CommitButtonText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CommitButtonText(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CommitButtonText(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FileTypeChoices(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMap<hstring, llm::OS::Foundation::Collections::IVector<hstring>>>(this->shim().FileTypeChoices());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DefaultFileExtension(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DefaultFileExtension());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DefaultFileExtension(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DefaultFileExtension(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SuggestedSaveFile(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::StorageFile>(this->shim().SuggestedSaveFile());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SuggestedSaveFile(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SuggestedSaveFile(*reinterpret_cast<llm::OS::Storage::StorageFile const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SuggestedFileName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SuggestedFileName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SuggestedFileName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SuggestedFileName(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall PickSaveFileAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFile>>(this->shim().PickSaveFileAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Pickers::IFileSavePicker2> : produce_base<D, llm::OS::Storage::Pickers::IFileSavePicker2>
    {
        int32_t __stdcall get_ContinuationData(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::ValueSet>(this->shim().ContinuationData());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall PickSaveFileAndContinue() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PickSaveFileAndContinue();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Pickers::IFileSavePicker3> : produce_base<D, llm::OS::Storage::Pickers::IFileSavePicker3>
    {
        int32_t __stdcall get_EnterpriseId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().EnterpriseId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_EnterpriseId(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnterpriseId(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Pickers::IFileSavePicker4> : produce_base<D, llm::OS::Storage::Pickers::IFileSavePicker4>
    {
        int32_t __stdcall get_User(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::User>(this->shim().User());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Pickers::IFileSavePickerStatics> : produce_base<D, llm::OS::Storage::Pickers::IFileSavePickerStatics>
    {
        int32_t __stdcall CreateForUser(void* user, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Storage::Pickers::FileSavePicker>(this->shim().CreateForUser(*reinterpret_cast<llm::OS::System::User const*>(&user)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Pickers::IFolderPicker> : produce_base<D, llm::OS::Storage::Pickers::IFolderPicker>
    {
        int32_t __stdcall get_ViewMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Pickers::PickerViewMode>(this->shim().ViewMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ViewMode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ViewMode(*reinterpret_cast<llm::OS::Storage::Pickers::PickerViewMode const*>(&value));
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
        int32_t __stdcall put_SettingsIdentifier(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SettingsIdentifier(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SuggestedStartLocation(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Pickers::PickerLocationId>(this->shim().SuggestedStartLocation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SuggestedStartLocation(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SuggestedStartLocation(*reinterpret_cast<llm::OS::Storage::Pickers::PickerLocationId const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CommitButtonText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().CommitButtonText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CommitButtonText(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CommitButtonText(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FileTypeFilter(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().FileTypeFilter());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall PickSingleFolderAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFolder>>(this->shim().PickSingleFolderAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Pickers::IFolderPicker2> : produce_base<D, llm::OS::Storage::Pickers::IFolderPicker2>
    {
        int32_t __stdcall get_ContinuationData(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::ValueSet>(this->shim().ContinuationData());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall PickFolderAndContinue() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PickFolderAndContinue();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Pickers::IFolderPicker3> : produce_base<D, llm::OS::Storage::Pickers::IFolderPicker3>
    {
        int32_t __stdcall get_User(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::User>(this->shim().User());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Pickers::IFolderPickerStatics> : produce_base<D, llm::OS::Storage::Pickers::IFolderPickerStatics>
    {
        int32_t __stdcall CreateForUser(void* user, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Storage::Pickers::FolderPicker>(this->shim().CreateForUser(*reinterpret_cast<llm::OS::System::User const*>(&user)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Storage::Pickers
{
    inline FileOpenPicker::FileOpenPicker() :
        FileOpenPicker(impl::call_factory_cast<FileOpenPicker(*)(llm::OS::Foundation::IActivationFactory const&), FileOpenPicker>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<FileOpenPicker>(); }))
    {
    }
    inline auto FileOpenPicker::ResumePickSingleFileAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFile>(*)(IFileOpenPickerStatics const&), FileOpenPicker, IFileOpenPickerStatics>([](IFileOpenPickerStatics const& f) { return f.ResumePickSingleFileAsync(); });
    }
    inline auto FileOpenPicker::CreateForUser(llm::OS::System::User const& user)
    {
        return impl::call_factory<FileOpenPicker, IFileOpenPickerStatics2>([&](IFileOpenPickerStatics2 const& f) { return f.CreateForUser(user); });
    }
    inline FileSavePicker::FileSavePicker() :
        FileSavePicker(impl::call_factory_cast<FileSavePicker(*)(llm::OS::Foundation::IActivationFactory const&), FileSavePicker>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<FileSavePicker>(); }))
    {
    }
    inline auto FileSavePicker::CreateForUser(llm::OS::System::User const& user)
    {
        return impl::call_factory<FileSavePicker, IFileSavePickerStatics>([&](IFileSavePickerStatics const& f) { return f.CreateForUser(user); });
    }
    inline FolderPicker::FolderPicker() :
        FolderPicker(impl::call_factory_cast<FolderPicker(*)(llm::OS::Foundation::IActivationFactory const&), FolderPicker>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<FolderPicker>(); }))
    {
    }
    inline auto FolderPicker::CreateForUser(llm::OS::System::User const& user)
    {
        return impl::call_factory<FolderPicker, IFolderPickerStatics>([&](IFolderPickerStatics const& f) { return f.CreateForUser(user); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Storage::Pickers::IFileOpenPicker> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::IFileOpenPicker2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::IFileOpenPicker3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::IFileOpenPickerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::IFileOpenPickerStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::IFileOpenPickerWithOperationId> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::IFileSavePicker> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::IFileSavePicker2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::IFileSavePicker3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::IFileSavePicker4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::IFileSavePickerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::IFolderPicker> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::IFolderPicker2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::IFolderPicker3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::IFolderPickerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::FileExtensionVector> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::FileOpenPicker> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::FilePickerFileTypesOrderedMap> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::FilePickerSelectedFilesArray> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::FileSavePicker> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Pickers::FolderPicker> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
