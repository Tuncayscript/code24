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
#ifndef LLM_OS_Media_AppRecording_H
#define LLM_OS_Media_AppRecording_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Media.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Storage.2.h"
#include "llm/impl/Windows.Media.AppRecording.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::AppRecording::AppRecordingStatus) consume_Windows_Media_AppRecording_IAppRecordingManager<D>::GetStatus() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppRecording::IAppRecordingManager)->GetStatus(&result));
        return llm::OS::Media::AppRecording::AppRecordingStatus{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::AppRecording::AppRecordingResult>) consume_Windows_Media_AppRecording_IAppRecordingManager<D>::StartRecordingToFileAsync(llm::OS::Storage::StorageFile const& file) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppRecording::IAppRecordingManager)->StartRecordingToFileAsync(*(void**)(&file), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::AppRecording::AppRecordingResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::AppRecording::AppRecordingResult>) consume_Windows_Media_AppRecording_IAppRecordingManager<D>::RecordTimeSpanToFileAsync(llm::OS::Foundation::DateTime const& startTime, llm::OS::Foundation::TimeSpan const& duration, llm::OS::Storage::StorageFile const& file) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppRecording::IAppRecordingManager)->RecordTimeSpanToFileAsync(impl::bind_in(startTime), impl::bind_in(duration), *(void**)(&file), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::AppRecording::AppRecordingResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_Media_AppRecording_IAppRecordingManager<D>::SupportedScreenshotMediaEncodingSubtypes() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppRecording::IAppRecordingManager)->get_SupportedScreenshotMediaEncodingSubtypes(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::AppRecording::AppRecordingSaveScreenshotResult>) consume_Windows_Media_AppRecording_IAppRecordingManager<D>::SaveScreenshotToFilesAsync(llm::OS::Storage::StorageFolder const& folder, param::hstring const& filenamePrefix, llm::OS::Media::AppRecording::AppRecordingSaveScreenshotOption const& option, param::async_iterable<hstring> const& requestedFormats) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppRecording::IAppRecordingManager)->SaveScreenshotToFilesAsync(*(void**)(&folder), *(void**)(&filenamePrefix), static_cast<int32_t>(option), *(void**)(&requestedFormats), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::AppRecording::AppRecordingSaveScreenshotResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::AppRecording::AppRecordingManager) consume_Windows_Media_AppRecording_IAppRecordingManagerStatics<D>::GetDefault() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppRecording::IAppRecordingManagerStatics)->GetDefault(&result));
        return llm::OS::Media::AppRecording::AppRecordingManager{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_AppRecording_IAppRecordingResult<D>::Succeeded() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppRecording::IAppRecordingResult)->get_Succeeded(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Media_AppRecording_IAppRecordingResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppRecording::IAppRecordingResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_AppRecording_IAppRecordingResult<D>::Duration() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppRecording::IAppRecordingResult)->get_Duration(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_AppRecording_IAppRecordingResult<D>::IsFileTruncated() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppRecording::IAppRecordingResult)->get_IsFileTruncated(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_AppRecording_IAppRecordingSaveScreenshotResult<D>::Succeeded() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppRecording::IAppRecordingSaveScreenshotResult)->get_Succeeded(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Media_AppRecording_IAppRecordingSaveScreenshotResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppRecording::IAppRecordingSaveScreenshotResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::AppRecording::AppRecordingSavedScreenshotInfo>) consume_Windows_Media_AppRecording_IAppRecordingSaveScreenshotResult<D>::SavedScreenshotInfos() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppRecording::IAppRecordingSaveScreenshotResult)->get_SavedScreenshotInfos(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::AppRecording::AppRecordingSavedScreenshotInfo>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::StorageFile) consume_Windows_Media_AppRecording_IAppRecordingSavedScreenshotInfo<D>::File() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppRecording::IAppRecordingSavedScreenshotInfo)->get_File(&value));
        return llm::OS::Storage::StorageFile{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_AppRecording_IAppRecordingSavedScreenshotInfo<D>::MediaEncodingSubtype() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppRecording::IAppRecordingSavedScreenshotInfo)->get_MediaEncodingSubtype(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_AppRecording_IAppRecordingStatus<D>::CanRecord() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppRecording::IAppRecordingStatus)->get_CanRecord(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_AppRecording_IAppRecordingStatus<D>::CanRecordTimeSpan() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppRecording::IAppRecordingStatus)->get_CanRecordTimeSpan(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_AppRecording_IAppRecordingStatus<D>::HistoricalBufferDuration() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppRecording::IAppRecordingStatus)->get_HistoricalBufferDuration(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::AppRecording::AppRecordingStatusDetails) consume_Windows_Media_AppRecording_IAppRecordingStatus<D>::Details() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppRecording::IAppRecordingStatus)->get_Details(&value));
        return llm::OS::Media::AppRecording::AppRecordingStatusDetails{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_AppRecording_IAppRecordingStatusDetails<D>::IsAnyAppBroadcasting() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppRecording::IAppRecordingStatusDetails)->get_IsAnyAppBroadcasting(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_AppRecording_IAppRecordingStatusDetails<D>::IsCaptureResourceUnavailable() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppRecording::IAppRecordingStatusDetails)->get_IsCaptureResourceUnavailable(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_AppRecording_IAppRecordingStatusDetails<D>::IsGameStreamInProgress() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppRecording::IAppRecordingStatusDetails)->get_IsGameStreamInProgress(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_AppRecording_IAppRecordingStatusDetails<D>::IsTimeSpanRecordingDisabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppRecording::IAppRecordingStatusDetails)->get_IsTimeSpanRecordingDisabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_AppRecording_IAppRecordingStatusDetails<D>::IsGpuConstrained() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppRecording::IAppRecordingStatusDetails)->get_IsGpuConstrained(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_AppRecording_IAppRecordingStatusDetails<D>::IsAppInactive() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppRecording::IAppRecordingStatusDetails)->get_IsAppInactive(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_AppRecording_IAppRecordingStatusDetails<D>::IsBlockedForApp() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppRecording::IAppRecordingStatusDetails)->get_IsBlockedForApp(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_AppRecording_IAppRecordingStatusDetails<D>::IsDisabledByUser() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppRecording::IAppRecordingStatusDetails)->get_IsDisabledByUser(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_AppRecording_IAppRecordingStatusDetails<D>::IsDisabledBySystem() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppRecording::IAppRecordingStatusDetails)->get_IsDisabledBySystem(&value));
        return value;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::AppRecording::IAppRecordingManager> : produce_base<D, llm::OS::Media::AppRecording::IAppRecordingManager>
    {
        int32_t __stdcall GetStatus(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Media::AppRecording::AppRecordingStatus>(this->shim().GetStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StartRecordingToFileAsync(void* file, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::AppRecording::AppRecordingResult>>(this->shim().StartRecordingToFileAsync(*reinterpret_cast<llm::OS::Storage::StorageFile const*>(&file)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RecordTimeSpanToFileAsync(int64_t startTime, int64_t duration, void* file, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::AppRecording::AppRecordingResult>>(this->shim().RecordTimeSpanToFileAsync(*reinterpret_cast<llm::OS::Foundation::DateTime const*>(&startTime), *reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&duration), *reinterpret_cast<llm::OS::Storage::StorageFile const*>(&file)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportedScreenshotMediaEncodingSubtypes(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().SupportedScreenshotMediaEncodingSubtypes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SaveScreenshotToFilesAsync(void* folder, void* filenamePrefix, int32_t option, void* requestedFormats, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::AppRecording::AppRecordingSaveScreenshotResult>>(this->shim().SaveScreenshotToFilesAsync(*reinterpret_cast<llm::OS::Storage::StorageFolder const*>(&folder), *reinterpret_cast<hstring const*>(&filenamePrefix), *reinterpret_cast<llm::OS::Media::AppRecording::AppRecordingSaveScreenshotOption const*>(&option), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&requestedFormats)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::AppRecording::IAppRecordingManagerStatics> : produce_base<D, llm::OS::Media::AppRecording::IAppRecordingManagerStatics>
    {
        int32_t __stdcall GetDefault(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Media::AppRecording::AppRecordingManager>(this->shim().GetDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::AppRecording::IAppRecordingResult> : produce_base<D, llm::OS::Media::AppRecording::IAppRecordingResult>
    {
        int32_t __stdcall get_Succeeded(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Succeeded());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Duration(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().Duration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsFileTruncated(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsFileTruncated());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::AppRecording::IAppRecordingSaveScreenshotResult> : produce_base<D, llm::OS::Media::AppRecording::IAppRecordingSaveScreenshotResult>
    {
        int32_t __stdcall get_Succeeded(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Succeeded());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SavedScreenshotInfos(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::AppRecording::AppRecordingSavedScreenshotInfo>>(this->shim().SavedScreenshotInfos());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::AppRecording::IAppRecordingSavedScreenshotInfo> : produce_base<D, llm::OS::Media::AppRecording::IAppRecordingSavedScreenshotInfo>
    {
        int32_t __stdcall get_File(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::StorageFile>(this->shim().File());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MediaEncodingSubtype(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().MediaEncodingSubtype());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::AppRecording::IAppRecordingStatus> : produce_base<D, llm::OS::Media::AppRecording::IAppRecordingStatus>
    {
        int32_t __stdcall get_CanRecord(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CanRecord());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CanRecordTimeSpan(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CanRecordTimeSpan());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HistoricalBufferDuration(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().HistoricalBufferDuration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Details(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::AppRecording::AppRecordingStatusDetails>(this->shim().Details());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::AppRecording::IAppRecordingStatusDetails> : produce_base<D, llm::OS::Media::AppRecording::IAppRecordingStatusDetails>
    {
        int32_t __stdcall get_IsAnyAppBroadcasting(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsAnyAppBroadcasting());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsCaptureResourceUnavailable(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsCaptureResourceUnavailable());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsGameStreamInProgress(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsGameStreamInProgress());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsTimeSpanRecordingDisabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsTimeSpanRecordingDisabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsGpuConstrained(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsGpuConstrained());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsAppInactive(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsAppInactive());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsBlockedForApp(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsBlockedForApp());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsDisabledByUser(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsDisabledByUser());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsDisabledBySystem(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsDisabledBySystem());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Media::AppRecording
{
    inline auto AppRecordingManager::GetDefault()
    {
        return impl::call_factory_cast<llm::OS::Media::AppRecording::AppRecordingManager(*)(IAppRecordingManagerStatics const&), AppRecordingManager, IAppRecordingManagerStatics>([](IAppRecordingManagerStatics const& f) { return f.GetDefault(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Media::AppRecording::IAppRecordingManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::AppRecording::IAppRecordingManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::AppRecording::IAppRecordingResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::AppRecording::IAppRecordingSaveScreenshotResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::AppRecording::IAppRecordingSavedScreenshotInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::AppRecording::IAppRecordingStatus> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::AppRecording::IAppRecordingStatusDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::AppRecording::AppRecordingManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::AppRecording::AppRecordingResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::AppRecording::AppRecordingSaveScreenshotResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::AppRecording::AppRecordingSavedScreenshotInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::AppRecording::AppRecordingStatus> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::AppRecording::AppRecordingStatusDetails> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
