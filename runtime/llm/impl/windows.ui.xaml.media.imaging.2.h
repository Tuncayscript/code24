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
#ifndef LLM_OS_UI_Xaml_Media_Imaging_2_H
#define LLM_OS_UI_Xaml_Media_Imaging_2_H
#include "llm/impl/Windows.ApplicationModel.Background.1.h"
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.UI.Xaml.1.h"
#include "llm/impl/Windows.UI.Xaml.Media.1.h"
#include "llm/impl/Windows.UI.Xaml.Media.Imaging.1.h"
LLM_EXPORT namespace llm::OS::UI::Xaml::Media::Imaging
{
    struct DownloadProgressEventHandler : llm::OS::Foundation::IUnknown
    {
        DownloadProgressEventHandler(std::nullptr_t = nullptr) noexcept {}
        DownloadProgressEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> DownloadProgressEventHandler(L lambda);
        template <typename F> DownloadProgressEventHandler(F* function);
        template <typename O, typename M> DownloadProgressEventHandler(O* object, M method);
        template <typename O, typename M> DownloadProgressEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> DownloadProgressEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Media::Imaging::DownloadProgressEventArgs const& e) const;
    };
    struct __declspec(empty_bases) BitmapImage : llm::OS::UI::Xaml::Media::Imaging::IBitmapImage,
        impl::base<BitmapImage, llm::OS::UI::Xaml::Media::Imaging::BitmapSource, llm::OS::UI::Xaml::Media::ImageSource, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<BitmapImage, llm::OS::UI::Xaml::Media::Imaging::IBitmapImage2, llm::OS::UI::Xaml::Media::Imaging::IBitmapImage3, llm::OS::UI::Xaml::Media::Imaging::IBitmapSource, llm::OS::UI::Xaml::Media::IImageSource, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        BitmapImage(std::nullptr_t) noexcept {}
        BitmapImage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Imaging::IBitmapImage(ptr, take_ownership_from_abi) {}
        BitmapImage();
        explicit BitmapImage(llm::OS::Foundation::Uri const& uriSource);
        [[nodiscard]] static auto CreateOptionsProperty();
        [[nodiscard]] static auto UriSourceProperty();
        [[nodiscard]] static auto DecodePixelWidthProperty();
        [[nodiscard]] static auto DecodePixelHeightProperty();
        [[nodiscard]] static auto DecodePixelTypeProperty();
        [[nodiscard]] static auto IsAnimatedBitmapProperty();
        [[nodiscard]] static auto IsPlayingProperty();
        [[nodiscard]] static auto AutoPlayProperty();
    };
    struct __declspec(empty_bases) BitmapSource : llm::OS::UI::Xaml::Media::Imaging::IBitmapSource,
        impl::base<BitmapSource, llm::OS::UI::Xaml::Media::ImageSource, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<BitmapSource, llm::OS::UI::Xaml::Media::IImageSource, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        BitmapSource(std::nullptr_t) noexcept {}
        BitmapSource(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Imaging::IBitmapSource(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto PixelWidthProperty();
        [[nodiscard]] static auto PixelHeightProperty();
    };
    struct __declspec(empty_bases) DownloadProgressEventArgs : llm::OS::UI::Xaml::Media::Imaging::IDownloadProgressEventArgs
    {
        DownloadProgressEventArgs(std::nullptr_t) noexcept {}
        DownloadProgressEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Imaging::IDownloadProgressEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RenderTargetBitmap : llm::OS::UI::Xaml::Media::Imaging::IRenderTargetBitmap,
        impl::base<RenderTargetBitmap, llm::OS::UI::Xaml::Media::ImageSource, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<RenderTargetBitmap, llm::OS::UI::Xaml::Media::IImageSource, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        RenderTargetBitmap(std::nullptr_t) noexcept {}
        RenderTargetBitmap(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Imaging::IRenderTargetBitmap(ptr, take_ownership_from_abi) {}
        RenderTargetBitmap();
        [[nodiscard]] static auto PixelWidthProperty();
        [[nodiscard]] static auto PixelHeightProperty();
    };
    struct __declspec(empty_bases) SoftwareBitmapSource : llm::OS::UI::Xaml::Media::Imaging::ISoftwareBitmapSource,
        impl::base<SoftwareBitmapSource, llm::OS::UI::Xaml::Media::ImageSource, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<SoftwareBitmapSource, llm::OS::Foundation::IClosable, llm::OS::UI::Xaml::Media::IImageSource, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        SoftwareBitmapSource(std::nullptr_t) noexcept {}
        SoftwareBitmapSource(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Imaging::ISoftwareBitmapSource(ptr, take_ownership_from_abi) {}
        SoftwareBitmapSource();
    };
    struct __declspec(empty_bases) SurfaceImageSource : llm::OS::UI::Xaml::Media::Imaging::ISurfaceImageSource,
        impl::base<SurfaceImageSource, llm::OS::UI::Xaml::Media::ImageSource, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<SurfaceImageSource, llm::OS::UI::Xaml::Media::IImageSource, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        SurfaceImageSource(std::nullptr_t) noexcept {}
        SurfaceImageSource(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Imaging::ISurfaceImageSource(ptr, take_ownership_from_abi) {}
        SurfaceImageSource(int32_t pixelWidth, int32_t pixelHeight);
        SurfaceImageSource(int32_t pixelWidth, int32_t pixelHeight, bool isOpaque);
    };
    struct __declspec(empty_bases) SvgImageSource : llm::OS::UI::Xaml::Media::Imaging::ISvgImageSource,
        impl::base<SvgImageSource, llm::OS::UI::Xaml::Media::ImageSource, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<SvgImageSource, llm::OS::UI::Xaml::Media::IImageSource, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        SvgImageSource(std::nullptr_t) noexcept {}
        SvgImageSource(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Imaging::ISvgImageSource(ptr, take_ownership_from_abi) {}
        SvgImageSource();
        explicit SvgImageSource(llm::OS::Foundation::Uri const& uriSource);
        [[nodiscard]] static auto UriSourceProperty();
        [[nodiscard]] static auto RasterizePixelWidthProperty();
        [[nodiscard]] static auto RasterizePixelHeightProperty();
    };
    struct __declspec(empty_bases) SvgImageSourceFailedEventArgs : llm::OS::UI::Xaml::Media::Imaging::ISvgImageSourceFailedEventArgs
    {
        SvgImageSourceFailedEventArgs(std::nullptr_t) noexcept {}
        SvgImageSourceFailedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Imaging::ISvgImageSourceFailedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SvgImageSourceOpenedEventArgs : llm::OS::UI::Xaml::Media::Imaging::ISvgImageSourceOpenedEventArgs
    {
        SvgImageSourceOpenedEventArgs(std::nullptr_t) noexcept {}
        SvgImageSourceOpenedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Imaging::ISvgImageSourceOpenedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VirtualSurfaceImageSource : llm::OS::UI::Xaml::Media::Imaging::IVirtualSurfaceImageSource,
        impl::base<VirtualSurfaceImageSource, llm::OS::UI::Xaml::Media::Imaging::SurfaceImageSource, llm::OS::UI::Xaml::Media::ImageSource, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<VirtualSurfaceImageSource, llm::OS::UI::Xaml::Media::Imaging::ISurfaceImageSource, llm::OS::UI::Xaml::Media::IImageSource, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        VirtualSurfaceImageSource(std::nullptr_t) noexcept {}
        VirtualSurfaceImageSource(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Imaging::IVirtualSurfaceImageSource(ptr, take_ownership_from_abi) {}
        VirtualSurfaceImageSource(int32_t pixelWidth, int32_t pixelHeight);
        VirtualSurfaceImageSource(int32_t pixelWidth, int32_t pixelHeight, bool isOpaque);
    };
    struct __declspec(empty_bases) WriteableBitmap : llm::OS::UI::Xaml::Media::Imaging::IWriteableBitmap,
        impl::base<WriteableBitmap, llm::OS::UI::Xaml::Media::Imaging::BitmapSource, llm::OS::UI::Xaml::Media::ImageSource, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<WriteableBitmap, llm::OS::UI::Xaml::Media::Imaging::IBitmapSource, llm::OS::UI::Xaml::Media::IImageSource, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        WriteableBitmap(std::nullptr_t) noexcept {}
        WriteableBitmap(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Imaging::IWriteableBitmap(ptr, take_ownership_from_abi) {}
        WriteableBitmap(int32_t pixelWidth, int32_t pixelHeight);
    };
    struct __declspec(empty_bases) XamlRenderingBackgroundTask : llm::OS::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTask,
        impl::require<XamlRenderingBackgroundTask, llm::OS::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTaskOverrides>
    {
        XamlRenderingBackgroundTask(std::nullptr_t) noexcept {}
        XamlRenderingBackgroundTask(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTask(ptr, take_ownership_from_abi) {}
    };
    template <typename D>
    class IXamlRenderingBackgroundTaskOverridesT
    {
        D& shim() noexcept { return *static_cast<D*>(this); }
        D const& shim() const noexcept { return *static_cast<const D*>(this); }
    public:
        using IXamlRenderingBackgroundTaskOverrides = llm::OS::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTaskOverrides;
        WINRT_IMPL_AUTO(void) OnRun(llm::OS::ApplicationModel::Background::IBackgroundTaskInstance const& taskInstance) const;
    };
}
#endif
