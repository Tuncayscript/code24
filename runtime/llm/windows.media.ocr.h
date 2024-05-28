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
#ifndef LLM_OS_Media_Ocr_H
#define LLM_OS_Media_Ocr_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Media.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Globalization.2.h"
#include "llm/impl/Windows.Graphics.Imaging.2.h"
#include "llm/impl/Windows.Media.Ocr.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Ocr::OcrResult>) consume_Windows_Media_Ocr_IOcrEngine<D>::RecognizeAsync(llm::OS::Graphics::Imaging::SoftwareBitmap const& bitmap) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Ocr::IOcrEngine)->RecognizeAsync(*(void**)(&bitmap), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Ocr::OcrResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Globalization::Language) consume_Windows_Media_Ocr_IOcrEngine<D>::RecognizerLanguage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Ocr::IOcrEngine)->get_RecognizerLanguage(&value));
        return llm::OS::Globalization::Language{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Ocr_IOcrEngineStatics<D>::MaxImageDimension() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Ocr::IOcrEngineStatics)->get_MaxImageDimension(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Globalization::Language>) consume_Windows_Media_Ocr_IOcrEngineStatics<D>::AvailableRecognizerLanguages() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Ocr::IOcrEngineStatics)->get_AvailableRecognizerLanguages(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Globalization::Language>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Ocr_IOcrEngineStatics<D>::IsLanguageSupported(llm::OS::Globalization::Language const& language) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Ocr::IOcrEngineStatics)->IsLanguageSupported(*(void**)(&language), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Ocr::OcrEngine) consume_Windows_Media_Ocr_IOcrEngineStatics<D>::TryCreateFromLanguage(llm::OS::Globalization::Language const& language) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Ocr::IOcrEngineStatics)->TryCreateFromLanguage(*(void**)(&language), &result));
        return llm::OS::Media::Ocr::OcrEngine{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Ocr::OcrEngine) consume_Windows_Media_Ocr_IOcrEngineStatics<D>::TryCreateFromUserProfileLanguages() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Ocr::IOcrEngineStatics)->TryCreateFromUserProfileLanguages(&result));
        return llm::OS::Media::Ocr::OcrEngine{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Ocr::OcrWord>) consume_Windows_Media_Ocr_IOcrLine<D>::Words() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Ocr::IOcrLine)->get_Words(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Ocr::OcrWord>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Ocr_IOcrLine<D>::Text() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Ocr::IOcrLine)->get_Text(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Ocr::OcrLine>) consume_Windows_Media_Ocr_IOcrResult<D>::Lines() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Ocr::IOcrResult)->get_Lines(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Ocr::OcrLine>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Media_Ocr_IOcrResult<D>::TextAngle() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Ocr::IOcrResult)->get_TextAngle(&value));
        return llm::OS::Foundation::IReference<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Ocr_IOcrResult<D>::Text() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Ocr::IOcrResult)->get_Text(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_Media_Ocr_IOcrWord<D>::BoundingRect() const
    {
        llm::OS::Foundation::Rect value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Ocr::IOcrWord)->get_BoundingRect(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Ocr_IOcrWord<D>::Text() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Ocr::IOcrWord)->get_Text(&value));
        return hstring{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Ocr::IOcrEngine> : produce_base<D, llm::OS::Media::Ocr::IOcrEngine>
    {
        int32_t __stdcall RecognizeAsync(void* bitmap, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Ocr::OcrResult>>(this->shim().RecognizeAsync(*reinterpret_cast<llm::OS::Graphics::Imaging::SoftwareBitmap const*>(&bitmap)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RecognizerLanguage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Globalization::Language>(this->shim().RecognizerLanguage());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Ocr::IOcrEngineStatics> : produce_base<D, llm::OS::Media::Ocr::IOcrEngineStatics>
    {
        int32_t __stdcall get_MaxImageDimension(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MaxImageDimension());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AvailableRecognizerLanguages(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Globalization::Language>>(this->shim().AvailableRecognizerLanguages());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsLanguageSupported(void* language, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsLanguageSupported(*reinterpret_cast<llm::OS::Globalization::Language const*>(&language)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryCreateFromLanguage(void* language, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Media::Ocr::OcrEngine>(this->shim().TryCreateFromLanguage(*reinterpret_cast<llm::OS::Globalization::Language const*>(&language)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryCreateFromUserProfileLanguages(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Media::Ocr::OcrEngine>(this->shim().TryCreateFromUserProfileLanguages());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Ocr::IOcrLine> : produce_base<D, llm::OS::Media::Ocr::IOcrLine>
    {
        int32_t __stdcall get_Words(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Ocr::OcrWord>>(this->shim().Words());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Text(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Text());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Ocr::IOcrResult> : produce_base<D, llm::OS::Media::Ocr::IOcrResult>
    {
        int32_t __stdcall get_Lines(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Ocr::OcrLine>>(this->shim().Lines());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TextAngle(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().TextAngle());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Text(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Text());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Ocr::IOcrWord> : produce_base<D, llm::OS::Media::Ocr::IOcrWord>
    {
        int32_t __stdcall get_BoundingRect(llm::OS::Foundation::Rect* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Rect>(this->shim().BoundingRect());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Text(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Text());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Media::Ocr
{
    inline auto OcrEngine::MaxImageDimension()
    {
        return impl::call_factory_cast<uint32_t(*)(IOcrEngineStatics const&), OcrEngine, IOcrEngineStatics>([](IOcrEngineStatics const& f) { return f.MaxImageDimension(); });
    }
    inline auto OcrEngine::AvailableRecognizerLanguages()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<llm::OS::Globalization::Language>(*)(IOcrEngineStatics const&), OcrEngine, IOcrEngineStatics>([](IOcrEngineStatics const& f) { return f.AvailableRecognizerLanguages(); });
    }
    inline auto OcrEngine::IsLanguageSupported(llm::OS::Globalization::Language const& language)
    {
        return impl::call_factory<OcrEngine, IOcrEngineStatics>([&](IOcrEngineStatics const& f) { return f.IsLanguageSupported(language); });
    }
    inline auto OcrEngine::TryCreateFromLanguage(llm::OS::Globalization::Language const& language)
    {
        return impl::call_factory<OcrEngine, IOcrEngineStatics>([&](IOcrEngineStatics const& f) { return f.TryCreateFromLanguage(language); });
    }
    inline auto OcrEngine::TryCreateFromUserProfileLanguages()
    {
        return impl::call_factory_cast<llm::OS::Media::Ocr::OcrEngine(*)(IOcrEngineStatics const&), OcrEngine, IOcrEngineStatics>([](IOcrEngineStatics const& f) { return f.TryCreateFromUserProfileLanguages(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Media::Ocr::IOcrEngine> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Ocr::IOcrEngineStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Ocr::IOcrLine> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Ocr::IOcrResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Ocr::IOcrWord> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Ocr::OcrEngine> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Ocr::OcrLine> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Ocr::OcrResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Ocr::OcrWord> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
