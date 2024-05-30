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
#ifndef LLM_OS_UI_Xaml_Printing_2_H
#define LLM_OS_UI_Xaml_Printing_2_H
#include "llm/impl/Windows.UI.Xaml.1.h"
#include "llm/impl/Windows.UI.Xaml.Printing.1.h"
LLM_EXPORT namespace llm::OS::UI::Xaml::Printing
{
    struct AddPagesEventHandler : llm::OS::Foundation::IUnknown
    {
        AddPagesEventHandler(std::nullptr_t = nullptr) noexcept {}
        AddPagesEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> AddPagesEventHandler(L lambda);
        template <typename F> AddPagesEventHandler(F* function);
        template <typename O, typename M> AddPagesEventHandler(O* object, M method);
        template <typename O, typename M> AddPagesEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> AddPagesEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Printing::AddPagesEventArgs const& e) const;
    };
    struct GetPreviewPageEventHandler : llm::OS::Foundation::IUnknown
    {
        GetPreviewPageEventHandler(std::nullptr_t = nullptr) noexcept {}
        GetPreviewPageEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> GetPreviewPageEventHandler(L lambda);
        template <typename F> GetPreviewPageEventHandler(F* function);
        template <typename O, typename M> GetPreviewPageEventHandler(O* object, M method);
        template <typename O, typename M> GetPreviewPageEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> GetPreviewPageEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Printing::GetPreviewPageEventArgs const& e) const;
    };
    struct PaginateEventHandler : llm::OS::Foundation::IUnknown
    {
        PaginateEventHandler(std::nullptr_t = nullptr) noexcept {}
        PaginateEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> PaginateEventHandler(L lambda);
        template <typename F> PaginateEventHandler(F* function);
        template <typename O, typename M> PaginateEventHandler(O* object, M method);
        template <typename O, typename M> PaginateEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> PaginateEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Printing::PaginateEventArgs const& e) const;
    };
    struct __declspec(empty_bases) AddPagesEventArgs : llm::OS::UI::Xaml::Printing::IAddPagesEventArgs
    {
        AddPagesEventArgs(std::nullptr_t) noexcept {}
        AddPagesEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Printing::IAddPagesEventArgs(ptr, take_ownership_from_abi) {}
        AddPagesEventArgs();
    };
    struct __declspec(empty_bases) GetPreviewPageEventArgs : llm::OS::UI::Xaml::Printing::IGetPreviewPageEventArgs
    {
        GetPreviewPageEventArgs(std::nullptr_t) noexcept {}
        GetPreviewPageEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Printing::IGetPreviewPageEventArgs(ptr, take_ownership_from_abi) {}
        GetPreviewPageEventArgs();
    };
    struct __declspec(empty_bases) PaginateEventArgs : llm::OS::UI::Xaml::Printing::IPaginateEventArgs
    {
        PaginateEventArgs(std::nullptr_t) noexcept {}
        PaginateEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Printing::IPaginateEventArgs(ptr, take_ownership_from_abi) {}
        PaginateEventArgs();
    };
    struct __declspec(empty_bases) PrintDocument : llm::OS::UI::Xaml::Printing::IPrintDocument,
        impl::base<PrintDocument, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<PrintDocument, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        PrintDocument(std::nullptr_t) noexcept {}
        PrintDocument(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Printing::IPrintDocument(ptr, take_ownership_from_abi) {}
        PrintDocument();
        [[nodiscard]] static auto DocumentSourceProperty();
    };
}
#endif
