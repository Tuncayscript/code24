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
#ifndef LLM_OS_Data_Pdf_H
#define LLM_OS_Data_Pdf_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Storage.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.UI.2.h"
#include "llm/impl/Windows.Data.Pdf.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Data::Pdf::PdfPage) consume_Windows_Data_Pdf_IPdfDocument<D>::GetPage(uint32_t pageIndex) const
    {
        void* pdfPage{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Pdf::IPdfDocument)->GetPage(pageIndex, &pdfPage));
        return llm::OS::Data::Pdf::PdfPage{ pdfPage, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Data_Pdf_IPdfDocument<D>::PageCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Pdf::IPdfDocument)->get_PageCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Data_Pdf_IPdfDocument<D>::IsPasswordProtected() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Pdf::IPdfDocument)->get_IsPasswordProtected(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Data::Pdf::PdfDocument>) consume_Windows_Data_Pdf_IPdfDocumentStatics<D>::LoadFromFileAsync(llm::OS::Storage::IStorageFile const& file) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Pdf::IPdfDocumentStatics)->LoadFromFileAsync(*(void**)(&file), &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Data::Pdf::PdfDocument>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Data::Pdf::PdfDocument>) consume_Windows_Data_Pdf_IPdfDocumentStatics<D>::LoadFromFileAsync(llm::OS::Storage::IStorageFile const& file, param::hstring const& password) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Pdf::IPdfDocumentStatics)->LoadFromFileWithPasswordAsync(*(void**)(&file), *(void**)(&password), &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Data::Pdf::PdfDocument>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Data::Pdf::PdfDocument>) consume_Windows_Data_Pdf_IPdfDocumentStatics<D>::LoadFromStreamAsync(llm::OS::Storage::Streams::IRandomAccessStream const& inputStream) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Pdf::IPdfDocumentStatics)->LoadFromStreamAsync(*(void**)(&inputStream), &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Data::Pdf::PdfDocument>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Data::Pdf::PdfDocument>) consume_Windows_Data_Pdf_IPdfDocumentStatics<D>::LoadFromStreamAsync(llm::OS::Storage::Streams::IRandomAccessStream const& inputStream, param::hstring const& password) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Pdf::IPdfDocumentStatics)->LoadFromStreamWithPasswordAsync(*(void**)(&inputStream), *(void**)(&password), &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Data::Pdf::PdfDocument>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Data_Pdf_IPdfPage<D>::RenderToStreamAsync(llm::OS::Storage::Streams::IRandomAccessStream const& outputStream) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Pdf::IPdfPage)->RenderToStreamAsync(*(void**)(&outputStream), &asyncInfo));
        return llm::OS::Foundation::IAsyncAction{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Data_Pdf_IPdfPage<D>::RenderToStreamAsync(llm::OS::Storage::Streams::IRandomAccessStream const& outputStream, llm::OS::Data::Pdf::PdfPageRenderOptions const& options) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Pdf::IPdfPage)->RenderWithOptionsToStreamAsync(*(void**)(&outputStream), *(void**)(&options), &asyncInfo));
        return llm::OS::Foundation::IAsyncAction{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Data_Pdf_IPdfPage<D>::PreparePageAsync() const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Pdf::IPdfPage)->PreparePageAsync(&asyncInfo));
        return llm::OS::Foundation::IAsyncAction{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Data_Pdf_IPdfPage<D>::Index() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Pdf::IPdfPage)->get_Index(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Size) consume_Windows_Data_Pdf_IPdfPage<D>::Size() const
    {
        llm::OS::Foundation::Size value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Pdf::IPdfPage)->get_Size(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Data::Pdf::PdfPageDimensions) consume_Windows_Data_Pdf_IPdfPage<D>::Dimensions() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Pdf::IPdfPage)->get_Dimensions(&value));
        return llm::OS::Data::Pdf::PdfPageDimensions{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Data::Pdf::PdfPageRotation) consume_Windows_Data_Pdf_IPdfPage<D>::Rotation() const
    {
        llm::OS::Data::Pdf::PdfPageRotation value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Pdf::IPdfPage)->get_Rotation(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_Data_Pdf_IPdfPage<D>::PreferredZoom() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Pdf::IPdfPage)->get_PreferredZoom(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_Data_Pdf_IPdfPageDimensions<D>::MediaBox() const
    {
        llm::OS::Foundation::Rect value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Pdf::IPdfPageDimensions)->get_MediaBox(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_Data_Pdf_IPdfPageDimensions<D>::CropBox() const
    {
        llm::OS::Foundation::Rect value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Pdf::IPdfPageDimensions)->get_CropBox(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_Data_Pdf_IPdfPageDimensions<D>::BleedBox() const
    {
        llm::OS::Foundation::Rect value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Pdf::IPdfPageDimensions)->get_BleedBox(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_Data_Pdf_IPdfPageDimensions<D>::TrimBox() const
    {
        llm::OS::Foundation::Rect value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Pdf::IPdfPageDimensions)->get_TrimBox(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_Data_Pdf_IPdfPageDimensions<D>::ArtBox() const
    {
        llm::OS::Foundation::Rect value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Pdf::IPdfPageDimensions)->get_ArtBox(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_Data_Pdf_IPdfPageRenderOptions<D>::SourceRect() const
    {
        llm::OS::Foundation::Rect value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Pdf::IPdfPageRenderOptions)->get_SourceRect(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Data_Pdf_IPdfPageRenderOptions<D>::SourceRect(llm::OS::Foundation::Rect const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Pdf::IPdfPageRenderOptions)->put_SourceRect(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Data_Pdf_IPdfPageRenderOptions<D>::DestinationWidth() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Pdf::IPdfPageRenderOptions)->get_DestinationWidth(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Data_Pdf_IPdfPageRenderOptions<D>::DestinationWidth(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Pdf::IPdfPageRenderOptions)->put_DestinationWidth(value));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Data_Pdf_IPdfPageRenderOptions<D>::DestinationHeight() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Pdf::IPdfPageRenderOptions)->get_DestinationHeight(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Data_Pdf_IPdfPageRenderOptions<D>::DestinationHeight(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Pdf::IPdfPageRenderOptions)->put_DestinationHeight(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Color) consume_Windows_Data_Pdf_IPdfPageRenderOptions<D>::BackgroundColor() const
    {
        llm::OS::UI::Color value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Pdf::IPdfPageRenderOptions)->get_BackgroundColor(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Data_Pdf_IPdfPageRenderOptions<D>::BackgroundColor(llm::OS::UI::Color const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Pdf::IPdfPageRenderOptions)->put_BackgroundColor(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Data_Pdf_IPdfPageRenderOptions<D>::IsIgnoringHighContrast() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Pdf::IPdfPageRenderOptions)->get_IsIgnoringHighContrast(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Data_Pdf_IPdfPageRenderOptions<D>::IsIgnoringHighContrast(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Pdf::IPdfPageRenderOptions)->put_IsIgnoringHighContrast(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Data_Pdf_IPdfPageRenderOptions<D>::BitmapEncoderId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Pdf::IPdfPageRenderOptions)->get_BitmapEncoderId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Data_Pdf_IPdfPageRenderOptions<D>::BitmapEncoderId(llm::guid const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Pdf::IPdfPageRenderOptions)->put_BitmapEncoderId(impl::bind_in(value)));
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Data::Pdf::IPdfDocument> : produce_base<D, llm::OS::Data::Pdf::IPdfDocument>
    {
        int32_t __stdcall GetPage(uint32_t pageIndex, void** pdfPage) noexcept final try
        {
            clear_abi(pdfPage);
            typename D::abi_guard guard(this->shim());
            *pdfPage = detach_from<llm::OS::Data::Pdf::PdfPage>(this->shim().GetPage(pageIndex));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PageCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().PageCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsPasswordProtected(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsPasswordProtected());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Data::Pdf::IPdfDocumentStatics> : produce_base<D, llm::OS::Data::Pdf::IPdfDocumentStatics>
    {
        int32_t __stdcall LoadFromFileAsync(void* file, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Data::Pdf::PdfDocument>>(this->shim().LoadFromFileAsync(*reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&file)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LoadFromFileWithPasswordAsync(void* file, void* password, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Data::Pdf::PdfDocument>>(this->shim().LoadFromFileAsync(*reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&file), *reinterpret_cast<hstring const*>(&password)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LoadFromStreamAsync(void* inputStream, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Data::Pdf::PdfDocument>>(this->shim().LoadFromStreamAsync(*reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStream const*>(&inputStream)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LoadFromStreamWithPasswordAsync(void* inputStream, void* password, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Data::Pdf::PdfDocument>>(this->shim().LoadFromStreamAsync(*reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStream const*>(&inputStream), *reinterpret_cast<hstring const*>(&password)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Data::Pdf::IPdfPage> : produce_base<D, llm::OS::Data::Pdf::IPdfPage>
    {
        int32_t __stdcall RenderToStreamAsync(void* outputStream, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().RenderToStreamAsync(*reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStream const*>(&outputStream)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RenderWithOptionsToStreamAsync(void* outputStream, void* options, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().RenderToStreamAsync(*reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStream const*>(&outputStream), *reinterpret_cast<llm::OS::Data::Pdf::PdfPageRenderOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall PreparePageAsync(void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().PreparePageAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Index(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Index());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Size(llm::OS::Foundation::Size* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Size>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Size>(this->shim().Size());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Dimensions(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Data::Pdf::PdfPageDimensions>(this->shim().Dimensions());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Rotation(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Data::Pdf::PdfPageRotation>(this->shim().Rotation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PreferredZoom(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().PreferredZoom());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Data::Pdf::IPdfPageDimensions> : produce_base<D, llm::OS::Data::Pdf::IPdfPageDimensions>
    {
        int32_t __stdcall get_MediaBox(llm::OS::Foundation::Rect* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Rect>(this->shim().MediaBox());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CropBox(llm::OS::Foundation::Rect* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Rect>(this->shim().CropBox());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BleedBox(llm::OS::Foundation::Rect* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Rect>(this->shim().BleedBox());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TrimBox(llm::OS::Foundation::Rect* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Rect>(this->shim().TrimBox());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ArtBox(llm::OS::Foundation::Rect* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Rect>(this->shim().ArtBox());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Data::Pdf::IPdfPageRenderOptions> : produce_base<D, llm::OS::Data::Pdf::IPdfPageRenderOptions>
    {
        int32_t __stdcall get_SourceRect(llm::OS::Foundation::Rect* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Rect>(this->shim().SourceRect());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SourceRect(llm::OS::Foundation::Rect value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceRect(*reinterpret_cast<llm::OS::Foundation::Rect const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DestinationWidth(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().DestinationWidth());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DestinationWidth(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DestinationWidth(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DestinationHeight(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().DestinationHeight());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DestinationHeight(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DestinationHeight(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BackgroundColor(struct struct_Windows_UI_Color* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Color>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Color>(this->shim().BackgroundColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BackgroundColor(struct struct_Windows_UI_Color value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BackgroundColor(*reinterpret_cast<llm::OS::UI::Color const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsIgnoringHighContrast(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsIgnoringHighContrast());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsIgnoringHighContrast(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsIgnoringHighContrast(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BitmapEncoderId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().BitmapEncoderId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BitmapEncoderId(llm::guid value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BitmapEncoderId(*reinterpret_cast<llm::guid const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Data::Pdf
{
    inline auto PdfDocument::LoadFromFileAsync(llm::OS::Storage::IStorageFile const& file)
    {
        return impl::call_factory<PdfDocument, IPdfDocumentStatics>([&](IPdfDocumentStatics const& f) { return f.LoadFromFileAsync(file); });
    }
    inline auto PdfDocument::LoadFromFileAsync(llm::OS::Storage::IStorageFile const& file, param::hstring const& password)
    {
        return impl::call_factory<PdfDocument, IPdfDocumentStatics>([&](IPdfDocumentStatics const& f) { return f.LoadFromFileAsync(file, password); });
    }
    inline auto PdfDocument::LoadFromStreamAsync(llm::OS::Storage::Streams::IRandomAccessStream const& inputStream)
    {
        return impl::call_factory<PdfDocument, IPdfDocumentStatics>([&](IPdfDocumentStatics const& f) { return f.LoadFromStreamAsync(inputStream); });
    }
    inline auto PdfDocument::LoadFromStreamAsync(llm::OS::Storage::Streams::IRandomAccessStream const& inputStream, param::hstring const& password)
    {
        return impl::call_factory<PdfDocument, IPdfDocumentStatics>([&](IPdfDocumentStatics const& f) { return f.LoadFromStreamAsync(inputStream, password); });
    }
    inline PdfPageRenderOptions::PdfPageRenderOptions() :
        PdfPageRenderOptions(impl::call_factory_cast<PdfPageRenderOptions(*)(llm::OS::Foundation::IActivationFactory const&), PdfPageRenderOptions>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<PdfPageRenderOptions>(); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Data::Pdf::IPdfDocument> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Data::Pdf::IPdfDocumentStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Data::Pdf::IPdfPage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Data::Pdf::IPdfPageDimensions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Data::Pdf::IPdfPageRenderOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Data::Pdf::PdfDocument> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Data::Pdf::PdfPage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Data::Pdf::PdfPageDimensions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Data::Pdf::PdfPageRenderOptions> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
