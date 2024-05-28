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
#ifndef LLM_OS_Media_FaceAnalysis_H
#define LLM_OS_Media_FaceAnalysis_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Media.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Graphics.Imaging.2.h"
#include "llm/impl/Windows.Media.2.h"
#include "llm/impl/Windows.Media.FaceAnalysis.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::BitmapBounds) consume_Windows_Media_FaceAnalysis_IDetectedFace<D>::FaceBox() const
    {
        llm::OS::Graphics::Imaging::BitmapBounds returnValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::FaceAnalysis::IDetectedFace)->get_FaceBox(put_abi(returnValue)));
        return returnValue;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::Media::FaceAnalysis::DetectedFace>>) consume_Windows_Media_FaceAnalysis_IFaceDetector<D>::DetectFacesAsync(llm::OS::Graphics::Imaging::SoftwareBitmap const& image) const
    {
        void* returnValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::FaceAnalysis::IFaceDetector)->DetectFacesAsync(*(void**)(&image), &returnValue));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::Media::FaceAnalysis::DetectedFace>>{ returnValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::Media::FaceAnalysis::DetectedFace>>) consume_Windows_Media_FaceAnalysis_IFaceDetector<D>::DetectFacesAsync(llm::OS::Graphics::Imaging::SoftwareBitmap const& image, llm::OS::Graphics::Imaging::BitmapBounds const& searchArea) const
    {
        void* returnValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::FaceAnalysis::IFaceDetector)->DetectFacesWithSearchAreaAsync(*(void**)(&image), impl::bind_in(searchArea), &returnValue));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::Media::FaceAnalysis::DetectedFace>>{ returnValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::BitmapSize) consume_Windows_Media_FaceAnalysis_IFaceDetector<D>::MinDetectableFaceSize() const
    {
        llm::OS::Graphics::Imaging::BitmapSize returnValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::FaceAnalysis::IFaceDetector)->get_MinDetectableFaceSize(put_abi(returnValue)));
        return returnValue;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_FaceAnalysis_IFaceDetector<D>::MinDetectableFaceSize(llm::OS::Graphics::Imaging::BitmapSize const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::FaceAnalysis::IFaceDetector)->put_MinDetectableFaceSize(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::BitmapSize) consume_Windows_Media_FaceAnalysis_IFaceDetector<D>::MaxDetectableFaceSize() const
    {
        llm::OS::Graphics::Imaging::BitmapSize returnValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::FaceAnalysis::IFaceDetector)->get_MaxDetectableFaceSize(put_abi(returnValue)));
        return returnValue;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_FaceAnalysis_IFaceDetector<D>::MaxDetectableFaceSize(llm::OS::Graphics::Imaging::BitmapSize const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::FaceAnalysis::IFaceDetector)->put_MaxDetectableFaceSize(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::FaceAnalysis::FaceDetector>) consume_Windows_Media_FaceAnalysis_IFaceDetectorStatics<D>::CreateAsync() const
    {
        void* returnValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::FaceAnalysis::IFaceDetectorStatics)->CreateAsync(&returnValue));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::FaceAnalysis::FaceDetector>{ returnValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Imaging::BitmapPixelFormat>) consume_Windows_Media_FaceAnalysis_IFaceDetectorStatics<D>::GetSupportedBitmapPixelFormats() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::FaceAnalysis::IFaceDetectorStatics)->GetSupportedBitmapPixelFormats(&result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Imaging::BitmapPixelFormat>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_FaceAnalysis_IFaceDetectorStatics<D>::IsBitmapPixelFormatSupported(llm::OS::Graphics::Imaging::BitmapPixelFormat const& bitmapPixelFormat) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::FaceAnalysis::IFaceDetectorStatics)->IsBitmapPixelFormatSupported(static_cast<int32_t>(bitmapPixelFormat), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_FaceAnalysis_IFaceDetectorStatics<D>::IsSupported() const
    {
        bool returnValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::FaceAnalysis::IFaceDetectorStatics)->get_IsSupported(&returnValue));
        return returnValue;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::Media::FaceAnalysis::DetectedFace>>) consume_Windows_Media_FaceAnalysis_IFaceTracker<D>::ProcessNextFrameAsync(llm::OS::Media::VideoFrame const& videoFrame) const
    {
        void* returnValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::FaceAnalysis::IFaceTracker)->ProcessNextFrameAsync(*(void**)(&videoFrame), &returnValue));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::Media::FaceAnalysis::DetectedFace>>{ returnValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::BitmapSize) consume_Windows_Media_FaceAnalysis_IFaceTracker<D>::MinDetectableFaceSize() const
    {
        llm::OS::Graphics::Imaging::BitmapSize returnValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::FaceAnalysis::IFaceTracker)->get_MinDetectableFaceSize(put_abi(returnValue)));
        return returnValue;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_FaceAnalysis_IFaceTracker<D>::MinDetectableFaceSize(llm::OS::Graphics::Imaging::BitmapSize const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::FaceAnalysis::IFaceTracker)->put_MinDetectableFaceSize(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::BitmapSize) consume_Windows_Media_FaceAnalysis_IFaceTracker<D>::MaxDetectableFaceSize() const
    {
        llm::OS::Graphics::Imaging::BitmapSize returnValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::FaceAnalysis::IFaceTracker)->get_MaxDetectableFaceSize(put_abi(returnValue)));
        return returnValue;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_FaceAnalysis_IFaceTracker<D>::MaxDetectableFaceSize(llm::OS::Graphics::Imaging::BitmapSize const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::FaceAnalysis::IFaceTracker)->put_MaxDetectableFaceSize(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::FaceAnalysis::FaceTracker>) consume_Windows_Media_FaceAnalysis_IFaceTrackerStatics<D>::CreateAsync() const
    {
        void* returnValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::FaceAnalysis::IFaceTrackerStatics)->CreateAsync(&returnValue));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::FaceAnalysis::FaceTracker>{ returnValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Imaging::BitmapPixelFormat>) consume_Windows_Media_FaceAnalysis_IFaceTrackerStatics<D>::GetSupportedBitmapPixelFormats() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::FaceAnalysis::IFaceTrackerStatics)->GetSupportedBitmapPixelFormats(&result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Imaging::BitmapPixelFormat>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_FaceAnalysis_IFaceTrackerStatics<D>::IsBitmapPixelFormatSupported(llm::OS::Graphics::Imaging::BitmapPixelFormat const& bitmapPixelFormat) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::FaceAnalysis::IFaceTrackerStatics)->IsBitmapPixelFormatSupported(static_cast<int32_t>(bitmapPixelFormat), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_FaceAnalysis_IFaceTrackerStatics<D>::IsSupported() const
    {
        bool returnValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::FaceAnalysis::IFaceTrackerStatics)->get_IsSupported(&returnValue));
        return returnValue;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::FaceAnalysis::IDetectedFace> : produce_base<D, llm::OS::Media::FaceAnalysis::IDetectedFace>
    {
        int32_t __stdcall get_FaceBox(struct struct_Windows_Graphics_Imaging_BitmapBounds* returnValue) noexcept final try
        {
            zero_abi<llm::OS::Graphics::Imaging::BitmapBounds>(returnValue);
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_from<llm::OS::Graphics::Imaging::BitmapBounds>(this->shim().FaceBox());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::FaceAnalysis::IFaceDetector> : produce_base<D, llm::OS::Media::FaceAnalysis::IFaceDetector>
    {
        int32_t __stdcall DetectFacesAsync(void* image, void** returnValue) noexcept final try
        {
            clear_abi(returnValue);
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::Media::FaceAnalysis::DetectedFace>>>(this->shim().DetectFacesAsync(*reinterpret_cast<llm::OS::Graphics::Imaging::SoftwareBitmap const*>(&image)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DetectFacesWithSearchAreaAsync(void* image, struct struct_Windows_Graphics_Imaging_BitmapBounds searchArea, void** returnValue) noexcept final try
        {
            clear_abi(returnValue);
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::Media::FaceAnalysis::DetectedFace>>>(this->shim().DetectFacesAsync(*reinterpret_cast<llm::OS::Graphics::Imaging::SoftwareBitmap const*>(&image), *reinterpret_cast<llm::OS::Graphics::Imaging::BitmapBounds const*>(&searchArea)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MinDetectableFaceSize(struct struct_Windows_Graphics_Imaging_BitmapSize* returnValue) noexcept final try
        {
            zero_abi<llm::OS::Graphics::Imaging::BitmapSize>(returnValue);
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_from<llm::OS::Graphics::Imaging::BitmapSize>(this->shim().MinDetectableFaceSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_MinDetectableFaceSize(struct struct_Windows_Graphics_Imaging_BitmapSize value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MinDetectableFaceSize(*reinterpret_cast<llm::OS::Graphics::Imaging::BitmapSize const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxDetectableFaceSize(struct struct_Windows_Graphics_Imaging_BitmapSize* returnValue) noexcept final try
        {
            zero_abi<llm::OS::Graphics::Imaging::BitmapSize>(returnValue);
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_from<llm::OS::Graphics::Imaging::BitmapSize>(this->shim().MaxDetectableFaceSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_MaxDetectableFaceSize(struct struct_Windows_Graphics_Imaging_BitmapSize value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxDetectableFaceSize(*reinterpret_cast<llm::OS::Graphics::Imaging::BitmapSize const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::FaceAnalysis::IFaceDetectorStatics> : produce_base<D, llm::OS::Media::FaceAnalysis::IFaceDetectorStatics>
    {
        int32_t __stdcall CreateAsync(void** returnValue) noexcept final try
        {
            clear_abi(returnValue);
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::FaceAnalysis::FaceDetector>>(this->shim().CreateAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSupportedBitmapPixelFormats(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Imaging::BitmapPixelFormat>>(this->shim().GetSupportedBitmapPixelFormats());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsBitmapPixelFormatSupported(int32_t bitmapPixelFormat, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsBitmapPixelFormatSupported(*reinterpret_cast<llm::OS::Graphics::Imaging::BitmapPixelFormat const*>(&bitmapPixelFormat)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsSupported(bool* returnValue) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_from<bool>(this->shim().IsSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::FaceAnalysis::IFaceTracker> : produce_base<D, llm::OS::Media::FaceAnalysis::IFaceTracker>
    {
        int32_t __stdcall ProcessNextFrameAsync(void* videoFrame, void** returnValue) noexcept final try
        {
            clear_abi(returnValue);
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::Media::FaceAnalysis::DetectedFace>>>(this->shim().ProcessNextFrameAsync(*reinterpret_cast<llm::OS::Media::VideoFrame const*>(&videoFrame)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MinDetectableFaceSize(struct struct_Windows_Graphics_Imaging_BitmapSize* returnValue) noexcept final try
        {
            zero_abi<llm::OS::Graphics::Imaging::BitmapSize>(returnValue);
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_from<llm::OS::Graphics::Imaging::BitmapSize>(this->shim().MinDetectableFaceSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_MinDetectableFaceSize(struct struct_Windows_Graphics_Imaging_BitmapSize value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MinDetectableFaceSize(*reinterpret_cast<llm::OS::Graphics::Imaging::BitmapSize const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxDetectableFaceSize(struct struct_Windows_Graphics_Imaging_BitmapSize* returnValue) noexcept final try
        {
            zero_abi<llm::OS::Graphics::Imaging::BitmapSize>(returnValue);
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_from<llm::OS::Graphics::Imaging::BitmapSize>(this->shim().MaxDetectableFaceSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_MaxDetectableFaceSize(struct struct_Windows_Graphics_Imaging_BitmapSize value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxDetectableFaceSize(*reinterpret_cast<llm::OS::Graphics::Imaging::BitmapSize const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::FaceAnalysis::IFaceTrackerStatics> : produce_base<D, llm::OS::Media::FaceAnalysis::IFaceTrackerStatics>
    {
        int32_t __stdcall CreateAsync(void** returnValue) noexcept final try
        {
            clear_abi(returnValue);
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::FaceAnalysis::FaceTracker>>(this->shim().CreateAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSupportedBitmapPixelFormats(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Imaging::BitmapPixelFormat>>(this->shim().GetSupportedBitmapPixelFormats());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsBitmapPixelFormatSupported(int32_t bitmapPixelFormat, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsBitmapPixelFormatSupported(*reinterpret_cast<llm::OS::Graphics::Imaging::BitmapPixelFormat const*>(&bitmapPixelFormat)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsSupported(bool* returnValue) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_from<bool>(this->shim().IsSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Media::FaceAnalysis
{
    inline auto FaceDetector::CreateAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::FaceAnalysis::FaceDetector>(*)(IFaceDetectorStatics const&), FaceDetector, IFaceDetectorStatics>([](IFaceDetectorStatics const& f) { return f.CreateAsync(); });
    }
    inline auto FaceDetector::GetSupportedBitmapPixelFormats()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Imaging::BitmapPixelFormat>(*)(IFaceDetectorStatics const&), FaceDetector, IFaceDetectorStatics>([](IFaceDetectorStatics const& f) { return f.GetSupportedBitmapPixelFormats(); });
    }
    inline auto FaceDetector::IsBitmapPixelFormatSupported(llm::OS::Graphics::Imaging::BitmapPixelFormat const& bitmapPixelFormat)
    {
        return impl::call_factory<FaceDetector, IFaceDetectorStatics>([&](IFaceDetectorStatics const& f) { return f.IsBitmapPixelFormatSupported(bitmapPixelFormat); });
    }
    inline auto FaceDetector::IsSupported()
    {
        return impl::call_factory_cast<bool(*)(IFaceDetectorStatics const&), FaceDetector, IFaceDetectorStatics>([](IFaceDetectorStatics const& f) { return f.IsSupported(); });
    }
    inline auto FaceTracker::CreateAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::FaceAnalysis::FaceTracker>(*)(IFaceTrackerStatics const&), FaceTracker, IFaceTrackerStatics>([](IFaceTrackerStatics const& f) { return f.CreateAsync(); });
    }
    inline auto FaceTracker::GetSupportedBitmapPixelFormats()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Imaging::BitmapPixelFormat>(*)(IFaceTrackerStatics const&), FaceTracker, IFaceTrackerStatics>([](IFaceTrackerStatics const& f) { return f.GetSupportedBitmapPixelFormats(); });
    }
    inline auto FaceTracker::IsBitmapPixelFormatSupported(llm::OS::Graphics::Imaging::BitmapPixelFormat const& bitmapPixelFormat)
    {
        return impl::call_factory<FaceTracker, IFaceTrackerStatics>([&](IFaceTrackerStatics const& f) { return f.IsBitmapPixelFormatSupported(bitmapPixelFormat); });
    }
    inline auto FaceTracker::IsSupported()
    {
        return impl::call_factory_cast<bool(*)(IFaceTrackerStatics const&), FaceTracker, IFaceTrackerStatics>([](IFaceTrackerStatics const& f) { return f.IsSupported(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Media::FaceAnalysis::IDetectedFace> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::FaceAnalysis::IFaceDetector> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::FaceAnalysis::IFaceDetectorStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::FaceAnalysis::IFaceTracker> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::FaceAnalysis::IFaceTrackerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::FaceAnalysis::DetectedFace> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::FaceAnalysis::FaceDetector> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::FaceAnalysis::FaceTracker> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
