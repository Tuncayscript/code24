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
#ifndef LLM_OS_Graphics_Printing_OptionDetails_1_H
#define LLM_OS_Graphics_Printing_OptionDetails_1_H
#include "llm/impl/Windows.Graphics.Printing.OptionDetails.0.h"
LLM_EXPORT namespace llm:OS::Graphics::Printing::OptionDetails
{
    struct __declspec(empty_bases) IPrintBindingOptionDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintBindingOptionDetails>
    {
        IPrintBindingOptionDetails(std::nullptr_t = nullptr) noexcept {}
        IPrintBindingOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintBorderingOptionDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintBorderingOptionDetails>
    {
        IPrintBorderingOptionDetails(std::nullptr_t = nullptr) noexcept {}
        IPrintBorderingOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintCollationOptionDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintCollationOptionDetails>
    {
        IPrintCollationOptionDetails(std::nullptr_t = nullptr) noexcept {}
        IPrintCollationOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintColorModeOptionDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintColorModeOptionDetails>
    {
        IPrintColorModeOptionDetails(std::nullptr_t = nullptr) noexcept {}
        IPrintColorModeOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintCopiesOptionDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintCopiesOptionDetails>
    {
        IPrintCopiesOptionDetails(std::nullptr_t = nullptr) noexcept {}
        IPrintCopiesOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintCustomItemDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintCustomItemDetails>
    {
        IPrintCustomItemDetails(std::nullptr_t = nullptr) noexcept {}
        IPrintCustomItemDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintCustomItemListOptionDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintCustomItemListOptionDetails>,
        impl::require<llm:OS::Graphics::Printing::OptionDetails::IPrintCustomItemListOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintCustomOptionDetails>
    {
        IPrintCustomItemListOptionDetails(std::nullptr_t = nullptr) noexcept {}
        IPrintCustomItemListOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintCustomItemListOptionDetails2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintCustomItemListOptionDetails2>
    {
        IPrintCustomItemListOptionDetails2(std::nullptr_t = nullptr) noexcept {}
        IPrintCustomItemListOptionDetails2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintCustomItemListOptionDetails3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintCustomItemListOptionDetails3>
    {
        IPrintCustomItemListOptionDetails3(std::nullptr_t = nullptr) noexcept {}
        IPrintCustomItemListOptionDetails3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintCustomOptionDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintCustomOptionDetails>,
        impl::require<llm:OS::Graphics::Printing::OptionDetails::IPrintCustomOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails>
    {
        IPrintCustomOptionDetails(std::nullptr_t = nullptr) noexcept {}
        IPrintCustomOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintCustomTextOptionDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintCustomTextOptionDetails>,
        impl::require<llm:OS::Graphics::Printing::OptionDetails::IPrintCustomTextOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintCustomOptionDetails>
    {
        IPrintCustomTextOptionDetails(std::nullptr_t = nullptr) noexcept {}
        IPrintCustomTextOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintCustomTextOptionDetails2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintCustomTextOptionDetails2>
    {
        IPrintCustomTextOptionDetails2(std::nullptr_t = nullptr) noexcept {}
        IPrintCustomTextOptionDetails2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintCustomToggleOptionDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintCustomToggleOptionDetails>
    {
        IPrintCustomToggleOptionDetails(std::nullptr_t = nullptr) noexcept {}
        IPrintCustomToggleOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintDuplexOptionDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintDuplexOptionDetails>
    {
        IPrintDuplexOptionDetails(std::nullptr_t = nullptr) noexcept {}
        IPrintDuplexOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintHolePunchOptionDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintHolePunchOptionDetails>
    {
        IPrintHolePunchOptionDetails(std::nullptr_t = nullptr) noexcept {}
        IPrintHolePunchOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintItemListOptionDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintItemListOptionDetails>,
        impl::require<llm:OS::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails>
    {
        IPrintItemListOptionDetails(std::nullptr_t = nullptr) noexcept {}
        IPrintItemListOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintMediaSizeOptionDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintMediaSizeOptionDetails>
    {
        IPrintMediaSizeOptionDetails(std::nullptr_t = nullptr) noexcept {}
        IPrintMediaSizeOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintMediaTypeOptionDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintMediaTypeOptionDetails>
    {
        IPrintMediaTypeOptionDetails(std::nullptr_t = nullptr) noexcept {}
        IPrintMediaTypeOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintNumberOptionDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintNumberOptionDetails>,
        impl::require<llm:OS::Graphics::Printing::OptionDetails::IPrintNumberOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails>
    {
        IPrintNumberOptionDetails(std::nullptr_t = nullptr) noexcept {}
        IPrintNumberOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintOptionDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintOptionDetails>
    {
        IPrintOptionDetails(std::nullptr_t = nullptr) noexcept {}
        IPrintOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintOrientationOptionDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintOrientationOptionDetails>
    {
        IPrintOrientationOptionDetails(std::nullptr_t = nullptr) noexcept {}
        IPrintOrientationOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintPageRangeOptionDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintPageRangeOptionDetails>
    {
        IPrintPageRangeOptionDetails(std::nullptr_t = nullptr) noexcept {}
        IPrintPageRangeOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintQualityOptionDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintQualityOptionDetails>
    {
        IPrintQualityOptionDetails(std::nullptr_t = nullptr) noexcept {}
        IPrintQualityOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintStapleOptionDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintStapleOptionDetails>
    {
        IPrintStapleOptionDetails(std::nullptr_t = nullptr) noexcept {}
        IPrintStapleOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintTaskOptionChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintTaskOptionChangedEventArgs>
    {
        IPrintTaskOptionChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPrintTaskOptionChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintTaskOptionDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintTaskOptionDetails>
    {
        IPrintTaskOptionDetails(std::nullptr_t = nullptr) noexcept {}
        IPrintTaskOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintTaskOptionDetails2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintTaskOptionDetails2>
    {
        IPrintTaskOptionDetails2(std::nullptr_t = nullptr) noexcept {}
        IPrintTaskOptionDetails2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintTaskOptionDetailsStatic :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintTaskOptionDetailsStatic>
    {
        IPrintTaskOptionDetailsStatic(std::nullptr_t = nullptr) noexcept {}
        IPrintTaskOptionDetailsStatic(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintTextOptionDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintTextOptionDetails>,
        impl::require<llm:OS::Graphics::Printing::OptionDetails::IPrintTextOptionDetails, llm:OS::Graphics::Printing::OptionDetails::IPrintOptionDetails>
    {
        IPrintTextOptionDetails(std::nullptr_t = nullptr) noexcept {}
        IPrintTextOptionDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
