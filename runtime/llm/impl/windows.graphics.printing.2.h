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
#ifndef LLM_OS_Graphics_Printing_2_H
#define LLM_OS_Graphics_Printing_2_H
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Graphics.Printing.1.h"
LLM_EXPORT namespace llm:OS::Graphics::Printing
{
    struct PrintTaskSourceRequestedHandler : llm:OS::Foundation::IUnknown
    {
        PrintTaskSourceRequestedHandler(std::nullptr_t = nullptr) noexcept {}
        PrintTaskSourceRequestedHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> PrintTaskSourceRequestedHandler(L lambda);
        template <typename F> PrintTaskSourceRequestedHandler(F* function);
        template <typename O, typename M> PrintTaskSourceRequestedHandler(O* object, M method);
        template <typename O, typename M> PrintTaskSourceRequestedHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> PrintTaskSourceRequestedHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::Graphics::Printing::PrintTaskSourceRequestedArgs const& args) const;
    };
    struct PrintPageDescription
    {
        llm:OS::Foundation::Size PageSize;
        llm:OS::Foundation::Rect ImageableRect;
        uint32_t DpiX;
        uint32_t DpiY;
    };
    inline bool operator==(PrintPageDescription const& left, PrintPageDescription const& right) noexcept
    {
        return left.PageSize == right.PageSize && left.ImageableRect == right.ImageableRect && left.DpiX == right.DpiX && left.DpiY == right.DpiY;
    }
    inline bool operator!=(PrintPageDescription const& left, PrintPageDescription const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) PrintManager : llm:OS::Graphics::Printing::IPrintManager
    {
        PrintManager(std::nullptr_t) noexcept {}
        PrintManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::IPrintManager(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
        static auto ShowPrintUIAsync();
        static auto IsSupported();
    };
    struct __declspec(empty_bases) PrintPageInfo : llm:OS::Graphics::Printing::IPrintPageInfo
    {
        PrintPageInfo(std::nullptr_t) noexcept {}
        PrintPageInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::IPrintPageInfo(ptr, take_ownership_from_abi) {}
        PrintPageInfo();
    };
    struct __declspec(empty_bases) PrintPageRange : llm:OS::Graphics::Printing::IPrintPageRange
    {
        PrintPageRange(std::nullptr_t) noexcept {}
        PrintPageRange(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::IPrintPageRange(ptr, take_ownership_from_abi) {}
        PrintPageRange(int32_t firstPage, int32_t lastPage);
        explicit PrintPageRange(int32_t page);
    };
    struct __declspec(empty_bases) PrintPageRangeOptions : llm:OS::Graphics::Printing::IPrintPageRangeOptions
    {
        PrintPageRangeOptions(std::nullptr_t) noexcept {}
        PrintPageRangeOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::IPrintPageRangeOptions(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintTask : llm:OS::Graphics::Printing::IPrintTask,
        impl::require<PrintTask, llm:OS::Graphics::Printing::IPrintTaskTargetDeviceSupport, llm:OS::Graphics::Printing::IPrintTask2>
    {
        PrintTask(std::nullptr_t) noexcept {}
        PrintTask(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::IPrintTask(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintTaskCompletedEventArgs : llm:OS::Graphics::Printing::IPrintTaskCompletedEventArgs
    {
        PrintTaskCompletedEventArgs(std::nullptr_t) noexcept {}
        PrintTaskCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::IPrintTaskCompletedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintTaskOptions : llm:OS::Graphics::Printing::IPrintTaskOptionsCore,
        impl::require<PrintTaskOptions, llm:OS::Graphics::Printing::IPrintTaskOptionsCoreProperties, llm:OS::Graphics::Printing::IPrintTaskOptionsCoreUIConfiguration, llm:OS::Graphics::Printing::IPrintTaskOptions, llm:OS::Graphics::Printing::IPrintTaskOptions2>
    {
        PrintTaskOptions(std::nullptr_t) noexcept {}
        PrintTaskOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::IPrintTaskOptionsCore(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintTaskProgressingEventArgs : llm:OS::Graphics::Printing::IPrintTaskProgressingEventArgs
    {
        PrintTaskProgressingEventArgs(std::nullptr_t) noexcept {}
        PrintTaskProgressingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::IPrintTaskProgressingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintTaskRequest : llm:OS::Graphics::Printing::IPrintTaskRequest
    {
        PrintTaskRequest(std::nullptr_t) noexcept {}
        PrintTaskRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::IPrintTaskRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintTaskRequestedDeferral : llm:OS::Graphics::Printing::IPrintTaskRequestedDeferral
    {
        PrintTaskRequestedDeferral(std::nullptr_t) noexcept {}
        PrintTaskRequestedDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::IPrintTaskRequestedDeferral(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintTaskRequestedEventArgs : llm:OS::Graphics::Printing::IPrintTaskRequestedEventArgs
    {
        PrintTaskRequestedEventArgs(std::nullptr_t) noexcept {}
        PrintTaskRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::IPrintTaskRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintTaskSourceRequestedArgs : llm:OS::Graphics::Printing::IPrintTaskSourceRequestedArgs
    {
        PrintTaskSourceRequestedArgs(std::nullptr_t) noexcept {}
        PrintTaskSourceRequestedArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::IPrintTaskSourceRequestedArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintTaskSourceRequestedDeferral : llm:OS::Graphics::Printing::IPrintTaskSourceRequestedDeferral
    {
        PrintTaskSourceRequestedDeferral(std::nullptr_t) noexcept {}
        PrintTaskSourceRequestedDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::IPrintTaskSourceRequestedDeferral(ptr, take_ownership_from_abi) {}
    };
    struct StandardPrintTaskOptions
    {
        StandardPrintTaskOptions() = delete;
        [[nodiscard]] static auto MediaSize();
        [[nodiscard]] static auto MediaType();
        [[nodiscard]] static auto Orientation();
        [[nodiscard]] static auto PrintQuality();
        [[nodiscard]] static auto ColorMode();
        [[nodiscard]] static auto Duplex();
        [[nodiscard]] static auto Collation();
        [[nodiscard]] static auto Staple();
        [[nodiscard]] static auto HolePunch();
        [[nodiscard]] static auto Binding();
        [[nodiscard]] static auto Copies();
        [[nodiscard]] static auto NUp();
        [[nodiscard]] static auto InputBin();
        [[nodiscard]] static auto Bordering();
        [[nodiscard]] static auto CustomPageRanges();
    };
}
#endif
