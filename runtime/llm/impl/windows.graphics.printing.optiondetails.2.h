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
#ifndef LLM_OS_Graphics_Printing_OptionDetails_2_H
#define LLM_OS_Graphics_Printing_OptionDetails_2_H
#include "llm/impl/Windows.Graphics.Printing.1.h"
#include "llm/impl/Windows.Graphics.Printing.OptionDetails.1.h"
LLM_EXPORT namespace llm:OS::Graphics::Printing::OptionDetails
{
    struct __declspec(empty_bases) PrintBindingOptionDetails : llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails,
        impl::require<PrintBindingOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintBindingOptionDetails>
    {
        PrintBindingOptionDetails(std::nullptr_t) noexcept {}
        PrintBindingOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintBorderingOptionDetails : llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails,
        impl::require<PrintBorderingOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintBorderingOptionDetails>
    {
        PrintBorderingOptionDetails(std::nullptr_t) noexcept {}
        PrintBorderingOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintCollationOptionDetails : llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails,
        impl::require<PrintCollationOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintCollationOptionDetails>
    {
        PrintCollationOptionDetails(std::nullptr_t) noexcept {}
        PrintCollationOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintColorModeOptionDetails : llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails,
        impl::require<PrintColorModeOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintColorModeOptionDetails>
    {
        PrintColorModeOptionDetails(std::nullptr_t) noexcept {}
        PrintColorModeOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintCopiesOptionDetails : llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails,
        impl::require<PrintCopiesOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintNumberOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintCopiesOptionDetails>
    {
        PrintCopiesOptionDetails(std::nullptr_t) noexcept {}
        PrintCopiesOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintCustomItemDetails : llm:OS::Graphics::Printing::OptionDetails::IPrintCustomItemDetails
    {
        PrintCustomItemDetails(std::nullptr_t) noexcept {}
        PrintCustomItemDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::OptionDetails::IPrintCustomItemDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintCustomItemListOptionDetails : llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails,
        impl::require<PrintCustomItemListOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintCustomOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintCustomItemListOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintCustomItemListOptionDetails2, llm:OS::Graphics::Printing::OptionDetails::IPrintCustomItemListOptionDetails3>
    {
        PrintCustomItemListOptionDetails(std::nullptr_t) noexcept {}
        PrintCustomItemListOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails(ptr, take_ownership_from_abi) {}
        using impl::consume_t<PrintCustomItemListOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintCustomItemListOptionDetails>::AddItem;
        using impl::consume_t<PrintCustomItemListOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintCustomItemListOptionDetails2>::AddItem;
    };
    struct __declspec(empty_bases) PrintCustomTextOptionDetails : llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails,
        impl::require<PrintCustomTextOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintCustomOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintCustomTextOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintCustomTextOptionDetails2>
    {
        PrintCustomTextOptionDetails(std::nullptr_t) noexcept {}
        PrintCustomTextOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintCustomToggleOptionDetails : llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails,
        impl::require<PrintCustomToggleOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintCustomOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintCustomToggleOptionDetails>
    {
        PrintCustomToggleOptionDetails(std::nullptr_t) noexcept {}
        PrintCustomToggleOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintDuplexOptionDetails : llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails,
        impl::require<PrintDuplexOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintDuplexOptionDetails>
    {
        PrintDuplexOptionDetails(std::nullptr_t) noexcept {}
        PrintDuplexOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintHolePunchOptionDetails : llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails,
        impl::require<PrintHolePunchOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintHolePunchOptionDetails>
    {
        PrintHolePunchOptionDetails(std::nullptr_t) noexcept {}
        PrintHolePunchOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintMediaSizeOptionDetails : llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails,
        impl::require<PrintMediaSizeOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintMediaSizeOptionDetails>
    {
        PrintMediaSizeOptionDetails(std::nullptr_t) noexcept {}
        PrintMediaSizeOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintMediaTypeOptionDetails : llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails,
        impl::require<PrintMediaTypeOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintMediaTypeOptionDetails>
    {
        PrintMediaTypeOptionDetails(std::nullptr_t) noexcept {}
        PrintMediaTypeOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintOrientationOptionDetails : llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails,
        impl::require<PrintOrientationOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintOrientationOptionDetails>
    {
        PrintOrientationOptionDetails(std::nullptr_t) noexcept {}
        PrintOrientationOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintPageRangeOptionDetails : llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails,
        impl::require<PrintPageRangeOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintPageRangeOptionDetails>
    {
        PrintPageRangeOptionDetails(std::nullptr_t) noexcept {}
        PrintPageRangeOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintQualityOptionDetails : llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails,
        impl::require<PrintQualityOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintQualityOptionDetails>
    {
        PrintQualityOptionDetails(std::nullptr_t) noexcept {}
        PrintQualityOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintStapleOptionDetails : llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails,
        impl::require<PrintStapleOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintStapleOptionDetails>
    {
        PrintStapleOptionDetails(std::nullptr_t) noexcept {}
        PrintStapleOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintTaskOptionChangedEventArgs : llm:OS::Graphics::Printing::OptionDetails::IPrintTaskOptionChangedEventArgs
    {
        PrintTaskOptionChangedEventArgs(std::nullptr_t) noexcept {}
        PrintTaskOptionChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::OptionDetails::IPrintTaskOptionChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintTaskOptionDetails : llm:OS::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails,
        impl::require<PrintTaskOptionDetails, llm:OS::Graphics::Printing::IPrintTaskOptionsCore, llm:OS::Graphics::Printing::IPrintTaskOptionsCoreUIConfiguration, llm:OS::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails2>
    {
        PrintTaskOptionDetails(std::nullptr_t) noexcept {}
        PrintTaskOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails(ptr, take_ownership_from_abi) {}
        static auto GetFromPrintTaskOptions(llm:OS::Graphics::Printing::PrintTaskOptions const& printTaskOptions);
    };
}
#endif
