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
#ifndef LLM_OS_Graphics_Display_Core_H
#define LLM_OS_Graphics_Display_Core_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Graphics.Display.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Graphics.Display.Core.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Display::Core::HdmiDisplayMode>) consume_Windows_Graphics_Display_Core_IHdmiDisplayInformation<D>::GetSupportedDisplayModes() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::Core::IHdmiDisplayInformation)->GetSupportedDisplayModes(&result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Display::Core::HdmiDisplayMode>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Display::Core::HdmiDisplayMode) consume_Windows_Graphics_Display_Core_IHdmiDisplayInformation<D>::GetCurrentDisplayMode() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::Core::IHdmiDisplayInformation)->GetCurrentDisplayMode(&result));
        return llm::OS::Graphics::Display::Core::HdmiDisplayMode{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Graphics_Display_Core_IHdmiDisplayInformation<D>::SetDefaultDisplayModeAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::Core::IHdmiDisplayInformation)->SetDefaultDisplayModeAsync(&operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Graphics_Display_Core_IHdmiDisplayInformation<D>::RequestSetCurrentDisplayModeAsync(llm::OS::Graphics::Display::Core::HdmiDisplayMode const& mode) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::Core::IHdmiDisplayInformation)->RequestSetCurrentDisplayModeAsync(*(void**)(&mode), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Graphics_Display_Core_IHdmiDisplayInformation<D>::RequestSetCurrentDisplayModeAsync(llm::OS::Graphics::Display::Core::HdmiDisplayMode const& mode, llm::OS::Graphics::Display::Core::HdmiDisplayHdrOption const& hdrOption) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::Core::IHdmiDisplayInformation)->RequestSetCurrentDisplayModeWithHdrAsync(*(void**)(&mode), static_cast<int32_t>(hdrOption), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Graphics_Display_Core_IHdmiDisplayInformation<D>::RequestSetCurrentDisplayModeAsync(llm::OS::Graphics::Display::Core::HdmiDisplayMode const& mode, llm::OS::Graphics::Display::Core::HdmiDisplayHdrOption const& hdrOption, llm::OS::Graphics::Display::Core::HdmiDisplayHdr2086Metadata const& hdrMetadata) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::Core::IHdmiDisplayInformation)->RequestSetCurrentDisplayModeWithHdrAndMetadataAsync(*(void**)(&mode), static_cast<int32_t>(hdrOption), impl::bind_in(hdrMetadata), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Graphics_Display_Core_IHdmiDisplayInformation<D>::DisplayModesChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::Core::HdmiDisplayInformation, llm::OS::Foundation::IInspectable> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::Core::IHdmiDisplayInformation)->add_DisplayModesChanged(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Graphics_Display_Core_IHdmiDisplayInformation<D>::DisplayModesChanged_revoker consume_Windows_Graphics_Display_Core_IHdmiDisplayInformation<D>::DisplayModesChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::Core::HdmiDisplayInformation, llm::OS::Foundation::IInspectable> const& value) const
    {
        return impl::make_event_revoker<D, DisplayModesChanged_revoker>(this, DisplayModesChanged(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Display_Core_IHdmiDisplayInformation<D>::DisplayModesChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Graphics::Display::Core::IHdmiDisplayInformation)->remove_DisplayModesChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Display::Core::HdmiDisplayInformation) consume_Windows_Graphics_Display_Core_IHdmiDisplayInformationStatics<D>::GetForCurrentView() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::Core::IHdmiDisplayInformationStatics)->GetForCurrentView(&result));
        return llm::OS::Graphics::Display::Core::HdmiDisplayInformation{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Graphics_Display_Core_IHdmiDisplayMode<D>::ResolutionWidthInRawPixels() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::Core::IHdmiDisplayMode)->get_ResolutionWidthInRawPixels(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Graphics_Display_Core_IHdmiDisplayMode<D>::ResolutionHeightInRawPixels() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::Core::IHdmiDisplayMode)->get_ResolutionHeightInRawPixels(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Graphics_Display_Core_IHdmiDisplayMode<D>::RefreshRate() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::Core::IHdmiDisplayMode)->get_RefreshRate(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Display_Core_IHdmiDisplayMode<D>::StereoEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::Core::IHdmiDisplayMode)->get_StereoEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint16_t) consume_Windows_Graphics_Display_Core_IHdmiDisplayMode<D>::BitsPerPixel() const
    {
        uint16_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::Core::IHdmiDisplayMode)->get_BitsPerPixel(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Display_Core_IHdmiDisplayMode<D>::IsEqual(llm::OS::Graphics::Display::Core::HdmiDisplayMode const& mode) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::Core::IHdmiDisplayMode)->IsEqual(*(void**)(&mode), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Display::Core::HdmiDisplayColorSpace) consume_Windows_Graphics_Display_Core_IHdmiDisplayMode<D>::ColorSpace() const
    {
        llm::OS::Graphics::Display::Core::HdmiDisplayColorSpace value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::Core::IHdmiDisplayMode)->get_ColorSpace(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Display::Core::HdmiDisplayPixelEncoding) consume_Windows_Graphics_Display_Core_IHdmiDisplayMode<D>::PixelEncoding() const
    {
        llm::OS::Graphics::Display::Core::HdmiDisplayPixelEncoding value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::Core::IHdmiDisplayMode)->get_PixelEncoding(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Display_Core_IHdmiDisplayMode<D>::IsSdrLuminanceSupported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::Core::IHdmiDisplayMode)->get_IsSdrLuminanceSupported(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Display_Core_IHdmiDisplayMode<D>::IsSmpte2084Supported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::Core::IHdmiDisplayMode)->get_IsSmpte2084Supported(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Display_Core_IHdmiDisplayMode<D>::Is2086MetadataSupported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::Core::IHdmiDisplayMode)->get_Is2086MetadataSupported(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Display_Core_IHdmiDisplayMode2<D>::IsDolbyVisionLowLatencySupported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Display::Core::IHdmiDisplayMode2)->get_IsDolbyVisionLowLatencySupported(&value));
        return value;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Display::Core::IHdmiDisplayInformation> : produce_base<D, llm::OS::Graphics::Display::Core::IHdmiDisplayInformation>
    {
        int32_t __stdcall GetSupportedDisplayModes(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Display::Core::HdmiDisplayMode>>(this->shim().GetSupportedDisplayModes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetCurrentDisplayMode(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Graphics::Display::Core::HdmiDisplayMode>(this->shim().GetCurrentDisplayMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetDefaultDisplayModeAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SetDefaultDisplayModeAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestSetCurrentDisplayModeAsync(void* mode, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().RequestSetCurrentDisplayModeAsync(*reinterpret_cast<llm::OS::Graphics::Display::Core::HdmiDisplayMode const*>(&mode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestSetCurrentDisplayModeWithHdrAsync(void* mode, int32_t hdrOption, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().RequestSetCurrentDisplayModeAsync(*reinterpret_cast<llm::OS::Graphics::Display::Core::HdmiDisplayMode const*>(&mode), *reinterpret_cast<llm::OS::Graphics::Display::Core::HdmiDisplayHdrOption const*>(&hdrOption)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestSetCurrentDisplayModeWithHdrAndMetadataAsync(void* mode, int32_t hdrOption, struct struct_Windows_Graphics_Display_Core_HdmiDisplayHdr2086Metadata hdrMetadata, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().RequestSetCurrentDisplayModeAsync(*reinterpret_cast<llm::OS::Graphics::Display::Core::HdmiDisplayMode const*>(&mode), *reinterpret_cast<llm::OS::Graphics::Display::Core::HdmiDisplayHdrOption const*>(&hdrOption), *reinterpret_cast<llm::OS::Graphics::Display::Core::HdmiDisplayHdr2086Metadata const*>(&hdrMetadata)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_DisplayModesChanged(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().DisplayModesChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Display::Core::HdmiDisplayInformation, llm::OS::Foundation::IInspectable> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_DisplayModesChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayModesChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Display::Core::IHdmiDisplayInformationStatics> : produce_base<D, llm::OS::Graphics::Display::Core::IHdmiDisplayInformationStatics>
    {
        int32_t __stdcall GetForCurrentView(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Graphics::Display::Core::HdmiDisplayInformation>(this->shim().GetForCurrentView());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Display::Core::IHdmiDisplayMode> : produce_base<D, llm::OS::Graphics::Display::Core::IHdmiDisplayMode>
    {
        int32_t __stdcall get_ResolutionWidthInRawPixels(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().ResolutionWidthInRawPixels());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResolutionHeightInRawPixels(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().ResolutionHeightInRawPixels());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RefreshRate(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().RefreshRate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StereoEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().StereoEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BitsPerPixel(uint16_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint16_t>(this->shim().BitsPerPixel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsEqual(void* mode, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsEqual(*reinterpret_cast<llm::OS::Graphics::Display::Core::HdmiDisplayMode const*>(&mode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ColorSpace(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Display::Core::HdmiDisplayColorSpace>(this->shim().ColorSpace());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PixelEncoding(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Display::Core::HdmiDisplayPixelEncoding>(this->shim().PixelEncoding());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsSdrLuminanceSupported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsSdrLuminanceSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsSmpte2084Supported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsSmpte2084Supported());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Is2086MetadataSupported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Is2086MetadataSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Display::Core::IHdmiDisplayMode2> : produce_base<D, llm::OS::Graphics::Display::Core::IHdmiDisplayMode2>
    {
        int32_t __stdcall get_IsDolbyVisionLowLatencySupported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsDolbyVisionLowLatencySupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Graphics::Display::Core
{
    inline auto HdmiDisplayInformation::GetForCurrentView()
    {
        return impl::call_factory_cast<llm::OS::Graphics::Display::Core::HdmiDisplayInformation(*)(IHdmiDisplayInformationStatics const&), HdmiDisplayInformation, IHdmiDisplayInformationStatics>([](IHdmiDisplayInformationStatics const& f) { return f.GetForCurrentView(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Graphics::Display::Core::IHdmiDisplayInformation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::Core::IHdmiDisplayInformationStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::Core::IHdmiDisplayMode> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::Core::IHdmiDisplayMode2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::Core::HdmiDisplayInformation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Display::Core::HdmiDisplayMode> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
