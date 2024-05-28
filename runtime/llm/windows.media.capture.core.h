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
#ifndef LLM_OS_Media_Capture_Core_H
#define LLM_OS_Media_Capture_Core_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Media.Capture.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Media.Capture.2.h"
#include "llm/impl/Windows.Media.Capture.Core.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::CapturedFrame) consume_Windows_Media_Capture_Core_IVariablePhotoCapturedEventArgs<D>::Frame() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Core::IVariablePhotoCapturedEventArgs)->get_Frame(&value));
        return llm::OS::Media::Capture::CapturedFrame{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_Capture_Core_IVariablePhotoCapturedEventArgs<D>::CaptureTimeOffset() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Core::IVariablePhotoCapturedEventArgs)->get_CaptureTimeOffset(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<uint32_t>) consume_Windows_Media_Capture_Core_IVariablePhotoCapturedEventArgs<D>::UsedFrameControllerIndex() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Core::IVariablePhotoCapturedEventArgs)->get_UsedFrameControllerIndex(&value));
        return llm::OS::Foundation::IReference<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::CapturedFrameControlValues) consume_Windows_Media_Capture_Core_IVariablePhotoCapturedEventArgs<D>::CapturedFrameControlValues() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Core::IVariablePhotoCapturedEventArgs)->get_CapturedFrameControlValues(&value));
        return llm::OS::Media::Capture::CapturedFrameControlValues{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Media_Capture_Core_IVariablePhotoSequenceCapture<D>::StartAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Core::IVariablePhotoSequenceCapture)->StartAsync(&operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Media_Capture_Core_IVariablePhotoSequenceCapture<D>::StopAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Core::IVariablePhotoSequenceCapture)->StopAsync(&operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Media_Capture_Core_IVariablePhotoSequenceCapture<D>::FinishAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Core::IVariablePhotoSequenceCapture)->FinishAsync(&operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Capture_Core_IVariablePhotoSequenceCapture<D>::PhotoCaptured(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Capture::Core::VariablePhotoSequenceCapture, llm::OS::Media::Capture::Core::VariablePhotoCapturedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Core::IVariablePhotoSequenceCapture)->add_PhotoCaptured(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Capture_Core_IVariablePhotoSequenceCapture<D>::PhotoCaptured_revoker consume_Windows_Media_Capture_Core_IVariablePhotoSequenceCapture<D>::PhotoCaptured(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Capture::Core::VariablePhotoSequenceCapture, llm::OS::Media::Capture::Core::VariablePhotoCapturedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PhotoCaptured_revoker>(this, PhotoCaptured(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Capture_Core_IVariablePhotoSequenceCapture<D>::PhotoCaptured(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Capture::Core::IVariablePhotoSequenceCapture)->remove_PhotoCaptured(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Capture_Core_IVariablePhotoSequenceCapture<D>::Stopped(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Capture::Core::VariablePhotoSequenceCapture, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Core::IVariablePhotoSequenceCapture)->add_Stopped(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Capture_Core_IVariablePhotoSequenceCapture<D>::Stopped_revoker consume_Windows_Media_Capture_Core_IVariablePhotoSequenceCapture<D>::Stopped(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Capture::Core::VariablePhotoSequenceCapture, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, Stopped_revoker>(this, Stopped(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Capture_Core_IVariablePhotoSequenceCapture<D>::Stopped(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Capture::Core::IVariablePhotoSequenceCapture)->remove_Stopped(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Media_Capture_Core_IVariablePhotoSequenceCapture2<D>::UpdateSettingsAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Core::IVariablePhotoSequenceCapture2)->UpdateSettingsAsync(&operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Core::IVariablePhotoCapturedEventArgs> : produce_base<D, llm::OS::Media::Capture::Core::IVariablePhotoCapturedEventArgs>
    {
        int32_t __stdcall get_Frame(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::CapturedFrame>(this->shim().Frame());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CaptureTimeOffset(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().CaptureTimeOffset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UsedFrameControllerIndex(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<uint32_t>>(this->shim().UsedFrameControllerIndex());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CapturedFrameControlValues(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::CapturedFrameControlValues>(this->shim().CapturedFrameControlValues());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Core::IVariablePhotoSequenceCapture> : produce_base<D, llm::OS::Media::Capture::Core::IVariablePhotoSequenceCapture>
    {
        int32_t __stdcall StartAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().StartAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StopAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().StopAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FinishAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().FinishAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_PhotoCaptured(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PhotoCaptured(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Capture::Core::VariablePhotoSequenceCapture, llm::OS::Media::Capture::Core::VariablePhotoCapturedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PhotoCaptured(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PhotoCaptured(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Stopped(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Stopped(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Capture::Core::VariablePhotoSequenceCapture, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Stopped(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stopped(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Core::IVariablePhotoSequenceCapture2> : produce_base<D, llm::OS::Media::Capture::Core::IVariablePhotoSequenceCapture2>
    {
        int32_t __stdcall UpdateSettingsAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().UpdateSettingsAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Media::Capture::Core
{
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Media::Capture::Core::IVariablePhotoCapturedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Core::IVariablePhotoSequenceCapture> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Core::IVariablePhotoSequenceCapture2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Core::VariablePhotoCapturedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Core::VariablePhotoSequenceCapture> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
