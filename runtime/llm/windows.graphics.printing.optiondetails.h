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
#ifndef LLM_OS_Graphics_Printing_OptionDetails_H
#define LLM_OS_Graphics_Printing_OptionDetails_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Graphics.Printing.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Graphics.Printing.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.Graphics.Printing.OptionDetails.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintBindingOptionDetails<D>::WarningText(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintBindingOptionDetails)->put_WarningText(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintBindingOptionDetails<D>::WarningText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintBindingOptionDetails)->get_WarningText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintBindingOptionDetails<D>::Description(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintBindingOptionDetails)->put_Description(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintBindingOptionDetails<D>::Description() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintBindingOptionDetails)->get_Description(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintBorderingOptionDetails<D>::WarningText(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintBorderingOptionDetails)->put_WarningText(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintBorderingOptionDetails<D>::WarningText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintBorderingOptionDetails)->get_WarningText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintBorderingOptionDetails<D>::Description(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintBorderingOptionDetails)->put_Description(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintBorderingOptionDetails<D>::Description() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintBorderingOptionDetails)->get_Description(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintCollationOptionDetails<D>::WarningText(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintCollationOptionDetails)->put_WarningText(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintCollationOptionDetails<D>::WarningText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintCollationOptionDetails)->get_WarningText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintCollationOptionDetails<D>::Description(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintCollationOptionDetails)->put_Description(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintCollationOptionDetails<D>::Description() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintCollationOptionDetails)->get_Description(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintColorModeOptionDetails<D>::WarningText(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintColorModeOptionDetails)->put_WarningText(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintColorModeOptionDetails<D>::WarningText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintColorModeOptionDetails)->get_WarningText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintColorModeOptionDetails<D>::Description(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintColorModeOptionDetails)->put_Description(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintColorModeOptionDetails<D>::Description() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintColorModeOptionDetails)->get_Description(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintCopiesOptionDetails<D>::WarningText(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintCopiesOptionDetails)->put_WarningText(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintCopiesOptionDetails<D>::WarningText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintCopiesOptionDetails)->get_WarningText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintCopiesOptionDetails<D>::Description(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintCopiesOptionDetails)->put_Description(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintCopiesOptionDetails<D>::Description() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintCopiesOptionDetails)->get_Description(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintCustomItemDetails<D>::ItemId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintCustomItemDetails)->get_ItemId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintCustomItemDetails<D>::ItemDisplayName(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintCustomItemDetails)->put_ItemDisplayName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintCustomItemDetails<D>::ItemDisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintCustomItemDetails)->get_ItemDisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintCustomItemListOptionDetails<D>::AddItem(param::hstring const& itemId, param::hstring const& displayName) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintCustomItemListOptionDetails)->AddItem(*(void**)(&itemId), *(void**)(&displayName)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintCustomItemListOptionDetails2<D>::AddItem(param::hstring const& itemId, param::hstring const& displayName, param::hstring const& description, llm::OS::Storage::Streams::IRandomAccessStreamWithContentType const& icon) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintCustomItemListOptionDetails2)->AddItem(*(void**)(&itemId), *(void**)(&displayName), *(void**)(&description), *(void**)(&icon)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintCustomItemListOptionDetails3<D>::WarningText(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintCustomItemListOptionDetails3)->put_WarningText(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintCustomItemListOptionDetails3<D>::WarningText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintCustomItemListOptionDetails3)->get_WarningText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintCustomItemListOptionDetails3<D>::Description(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintCustomItemListOptionDetails3)->put_Description(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintCustomItemListOptionDetails3<D>::Description() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintCustomItemListOptionDetails3)->get_Description(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintCustomOptionDetails<D>::DisplayName(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintCustomOptionDetails)->put_DisplayName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintCustomOptionDetails<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintCustomOptionDetails)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintCustomTextOptionDetails<D>::MaxCharacters(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintCustomTextOptionDetails)->put_MaxCharacters(value));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Graphics_Printing_OptionDetails_IPrintCustomTextOptionDetails<D>::MaxCharacters() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintCustomTextOptionDetails)->get_MaxCharacters(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintCustomTextOptionDetails2<D>::WarningText(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintCustomTextOptionDetails2)->put_WarningText(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintCustomTextOptionDetails2<D>::WarningText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintCustomTextOptionDetails2)->get_WarningText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintCustomTextOptionDetails2<D>::Description(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintCustomTextOptionDetails2)->put_Description(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintCustomTextOptionDetails2<D>::Description() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintCustomTextOptionDetails2)->get_Description(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintCustomToggleOptionDetails<D>::WarningText(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintCustomToggleOptionDetails)->put_WarningText(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintCustomToggleOptionDetails<D>::WarningText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintCustomToggleOptionDetails)->get_WarningText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintCustomToggleOptionDetails<D>::Description(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintCustomToggleOptionDetails)->put_Description(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintCustomToggleOptionDetails<D>::Description() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintCustomToggleOptionDetails)->get_Description(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintDuplexOptionDetails<D>::WarningText(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintDuplexOptionDetails)->put_WarningText(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintDuplexOptionDetails<D>::WarningText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintDuplexOptionDetails)->get_WarningText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintDuplexOptionDetails<D>::Description(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintDuplexOptionDetails)->put_Description(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintDuplexOptionDetails<D>::Description() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintDuplexOptionDetails)->get_Description(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintHolePunchOptionDetails<D>::WarningText(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintHolePunchOptionDetails)->put_WarningText(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintHolePunchOptionDetails<D>::WarningText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintHolePunchOptionDetails)->get_WarningText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintHolePunchOptionDetails<D>::Description(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintHolePunchOptionDetails)->put_Description(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintHolePunchOptionDetails<D>::Description() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintHolePunchOptionDetails)->get_Description(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Foundation::IInspectable>) consume_Windows_Graphics_Printing_OptionDetails_IPrintItemListOptionDetails<D>::Items() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails)->get_Items(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Foundation::IInspectable>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintMediaSizeOptionDetails<D>::WarningText(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintMediaSizeOptionDetails)->put_WarningText(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintMediaSizeOptionDetails<D>::WarningText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintMediaSizeOptionDetails)->get_WarningText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintMediaSizeOptionDetails<D>::Description(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintMediaSizeOptionDetails)->put_Description(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintMediaSizeOptionDetails<D>::Description() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintMediaSizeOptionDetails)->get_Description(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintMediaTypeOptionDetails<D>::WarningText(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintMediaTypeOptionDetails)->put_WarningText(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintMediaTypeOptionDetails<D>::WarningText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintMediaTypeOptionDetails)->get_WarningText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintMediaTypeOptionDetails<D>::Description(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintMediaTypeOptionDetails)->put_Description(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintMediaTypeOptionDetails<D>::Description() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintMediaTypeOptionDetails)->get_Description(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Graphics_Printing_OptionDetails_IPrintNumberOptionDetails<D>::MinValue() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintNumberOptionDetails)->get_MinValue(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Graphics_Printing_OptionDetails_IPrintNumberOptionDetails<D>::MaxValue() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintNumberOptionDetails)->get_MaxValue(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintOptionDetails<D>::OptionId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintOptionDetails)->get_OptionId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing::OptionDetails::PrintOptionType) consume_Windows_Graphics_Printing_OptionDetails_IPrintOptionDetails<D>::OptionType() const
    {
        llm::OS::Graphics::Printing::OptionDetails::PrintOptionType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintOptionDetails)->get_OptionType(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintOptionDetails<D>::ErrorText(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintOptionDetails)->put_ErrorText(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintOptionDetails<D>::ErrorText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintOptionDetails)->get_ErrorText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintOptionDetails<D>::State(llm::OS::Graphics::Printing::OptionDetails::PrintOptionStates const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintOptionDetails)->put_State(static_cast<uint32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing::OptionDetails::PrintOptionStates) consume_Windows_Graphics_Printing_OptionDetails_IPrintOptionDetails<D>::State() const
    {
        llm::OS::Graphics::Printing::OptionDetails::PrintOptionStates value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintOptionDetails)->get_State(reinterpret_cast<uint32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Graphics_Printing_OptionDetails_IPrintOptionDetails<D>::Value() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintOptionDetails)->get_Value(&value));
        return llm::OS::Foundation::IInspectable{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Printing_OptionDetails_IPrintOptionDetails<D>::TrySetValue(llm::OS::Foundation::IInspectable const& value) const
    {
        bool succeeded{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintOptionDetails)->TrySetValue(*(void**)(&value), &succeeded));
        return succeeded;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintOrientationOptionDetails<D>::WarningText(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintOrientationOptionDetails)->put_WarningText(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintOrientationOptionDetails<D>::WarningText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintOrientationOptionDetails)->get_WarningText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintOrientationOptionDetails<D>::Description(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintOrientationOptionDetails)->put_Description(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintOrientationOptionDetails<D>::Description() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintOrientationOptionDetails)->get_Description(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintPageRangeOptionDetails<D>::WarningText(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintPageRangeOptionDetails)->put_WarningText(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintPageRangeOptionDetails<D>::WarningText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintPageRangeOptionDetails)->get_WarningText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintPageRangeOptionDetails<D>::Description(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintPageRangeOptionDetails)->put_Description(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintPageRangeOptionDetails<D>::Description() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintPageRangeOptionDetails)->get_Description(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintQualityOptionDetails<D>::WarningText(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintQualityOptionDetails)->put_WarningText(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintQualityOptionDetails<D>::WarningText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintQualityOptionDetails)->get_WarningText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintQualityOptionDetails<D>::Description(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintQualityOptionDetails)->put_Description(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintQualityOptionDetails<D>::Description() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintQualityOptionDetails)->get_Description(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintStapleOptionDetails<D>::WarningText(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintStapleOptionDetails)->put_WarningText(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintStapleOptionDetails<D>::WarningText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintStapleOptionDetails)->get_WarningText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintStapleOptionDetails<D>::Description(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintStapleOptionDetails)->put_Description(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing_OptionDetails_IPrintStapleOptionDetails<D>::Description() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintStapleOptionDetails)->get_Description(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Graphics_Printing_OptionDetails_IPrintTaskOptionChangedEventArgs<D>::OptionId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintTaskOptionChangedEventArgs)->get_OptionId(&value));
        return llm::OS::Foundation::IInspectable{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Graphics::Printing::OptionDetails::IPrintOptionDetails>) consume_Windows_Graphics_Printing_OptionDetails_IPrintTaskOptionDetails<D>::Options() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails)->get_Options(&value));
        return llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Graphics::Printing::OptionDetails::IPrintOptionDetails>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing::OptionDetails::PrintCustomItemListOptionDetails) consume_Windows_Graphics_Printing_OptionDetails_IPrintTaskOptionDetails<D>::CreateItemListOption(param::hstring const& optionId, param::hstring const& displayName) const
    {
        void* itemListOption{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails)->CreateItemListOption(*(void**)(&optionId), *(void**)(&displayName), &itemListOption));
        return llm::OS::Graphics::Printing::OptionDetails::PrintCustomItemListOptionDetails{ itemListOption, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing::OptionDetails::PrintCustomTextOptionDetails) consume_Windows_Graphics_Printing_OptionDetails_IPrintTaskOptionDetails<D>::CreateTextOption(param::hstring const& optionId, param::hstring const& displayName) const
    {
        void* textOption{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails)->CreateTextOption(*(void**)(&optionId), *(void**)(&displayName), &textOption));
        return llm::OS::Graphics::Printing::OptionDetails::PrintCustomTextOptionDetails{ textOption, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Graphics_Printing_OptionDetails_IPrintTaskOptionDetails<D>::OptionChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Printing::OptionDetails::PrintTaskOptionDetails, llm::OS::Graphics::Printing::OptionDetails::PrintTaskOptionChangedEventArgs> const& eventHandler) const
    {
        llm::event_token eventCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails)->add_OptionChanged(*(void**)(&eventHandler), put_abi(eventCookie)));
        return eventCookie;
    }
    template <typename D> typename consume_Windows_Graphics_Printing_OptionDetails_IPrintTaskOptionDetails<D>::OptionChanged_revoker consume_Windows_Graphics_Printing_OptionDetails_IPrintTaskOptionDetails<D>::OptionChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Printing::OptionDetails::PrintTaskOptionDetails, llm::OS::Graphics::Printing::OptionDetails::PrintTaskOptionChangedEventArgs> const& eventHandler) const
    {
        return impl::make_event_revoker<D, OptionChanged_revoker>(this, OptionChanged(eventHandler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintTaskOptionDetails<D>::OptionChanged(llm::event_token const& eventCookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails)->remove_OptionChanged(impl::bind_in(eventCookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Graphics_Printing_OptionDetails_IPrintTaskOptionDetails<D>::BeginValidation(llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Printing::OptionDetails::PrintTaskOptionDetails, llm::OS::Foundation::IInspectable> const& eventHandler) const
    {
        llm::event_token eventCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails)->add_BeginValidation(*(void**)(&eventHandler), put_abi(eventCookie)));
        return eventCookie;
    }
    template <typename D> typename consume_Windows_Graphics_Printing_OptionDetails_IPrintTaskOptionDetails<D>::BeginValidation_revoker consume_Windows_Graphics_Printing_OptionDetails_IPrintTaskOptionDetails<D>::BeginValidation(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Printing::OptionDetails::PrintTaskOptionDetails, llm::OS::Foundation::IInspectable> const& eventHandler) const
    {
        return impl::make_event_revoker<D, BeginValidation_revoker>(this, BeginValidation(eventHandler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing_OptionDetails_IPrintTaskOptionDetails<D>::BeginValidation(llm::event_token const& eventCookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails)->remove_BeginValidation(impl::bind_in(eventCookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing::OptionDetails::PrintCustomToggleOptionDetails) consume_Windows_Graphics_Printing_OptionDetails_IPrintTaskOptionDetails2<D>::CreateToggleOption(param::hstring const& optionId, param::hstring const& displayName) const
    {
        void* toggleOption{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails2)->CreateToggleOption(*(void**)(&optionId), *(void**)(&displayName), &toggleOption));
        return llm::OS::Graphics::Printing::OptionDetails::PrintCustomToggleOptionDetails{ toggleOption, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing::OptionDetails::PrintTaskOptionDetails) consume_Windows_Graphics_Printing_OptionDetails_IPrintTaskOptionDetailsStatic<D>::GetFromPrintTaskOptions(llm::OS::Graphics::Printing::PrintTaskOptions const& printTaskOptions) const
    {
        void* printTaskOptionDetails{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintTaskOptionDetailsStatic)->GetFromPrintTaskOptions(*(void**)(&printTaskOptions), &printTaskOptionDetails));
        return llm::OS::Graphics::Printing::OptionDetails::PrintTaskOptionDetails{ printTaskOptionDetails, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Graphics_Printing_OptionDetails_IPrintTextOptionDetails<D>::MaxCharacters() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing::OptionDetails::IPrintTextOptionDetails)->get_MaxCharacters(&value));
        return value;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing::OptionDetails::IPrintBindingOptionDetails> : produce_base<D, llm::OS::Graphics::Printing::OptionDetails::IPrintBindingOptionDetails>
    {
        int32_t __stdcall put_WarningText(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WarningText(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WarningText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().WarningText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Description(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Description(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Description(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing::OptionDetails::IPrintBorderingOptionDetails> : produce_base<D, llm::OS::Graphics::Printing::OptionDetails::IPrintBorderingOptionDetails>
    {
        int32_t __stdcall put_WarningText(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WarningText(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WarningText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().WarningText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Description(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Description(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Description(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing::OptionDetails::IPrintCollationOptionDetails> : produce_base<D, llm::OS::Graphics::Printing::OptionDetails::IPrintCollationOptionDetails>
    {
        int32_t __stdcall put_WarningText(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WarningText(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WarningText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().WarningText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Description(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Description(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Description(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing::OptionDetails::IPrintColorModeOptionDetails> : produce_base<D, llm::OS::Graphics::Printing::OptionDetails::IPrintColorModeOptionDetails>
    {
        int32_t __stdcall put_WarningText(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WarningText(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WarningText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().WarningText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Description(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Description(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Description(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing::OptionDetails::IPrintCopiesOptionDetails> : produce_base<D, llm::OS::Graphics::Printing::OptionDetails::IPrintCopiesOptionDetails>
    {
        int32_t __stdcall put_WarningText(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WarningText(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WarningText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().WarningText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Description(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Description(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Description(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing::OptionDetails::IPrintCustomItemDetails> : produce_base<D, llm::OS::Graphics::Printing::OptionDetails::IPrintCustomItemDetails>
    {
        int32_t __stdcall get_ItemId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ItemId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ItemDisplayName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ItemDisplayName(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ItemDisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ItemDisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing::OptionDetails::IPrintCustomItemListOptionDetails> : produce_base<D, llm::OS::Graphics::Printing::OptionDetails::IPrintCustomItemListOptionDetails>
    {
        int32_t __stdcall AddItem(void* itemId, void* displayName) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddItem(*reinterpret_cast<hstring const*>(&itemId), *reinterpret_cast<hstring const*>(&displayName));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing::OptionDetails::IPrintCustomItemListOptionDetails2> : produce_base<D, llm::OS::Graphics::Printing::OptionDetails::IPrintCustomItemListOptionDetails2>
    {
        int32_t __stdcall AddItem(void* itemId, void* displayName, void* description, void* icon) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddItem(*reinterpret_cast<hstring const*>(&itemId), *reinterpret_cast<hstring const*>(&displayName), *reinterpret_cast<hstring const*>(&description), *reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStreamWithContentType const*>(&icon));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing::OptionDetails::IPrintCustomItemListOptionDetails3> : produce_base<D, llm::OS::Graphics::Printing::OptionDetails::IPrintCustomItemListOptionDetails3>
    {
        int32_t __stdcall put_WarningText(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WarningText(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WarningText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().WarningText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Description(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Description(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Description(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing::OptionDetails::IPrintCustomOptionDetails> : produce_base<D, llm::OS::Graphics::Printing::OptionDetails::IPrintCustomOptionDetails>
    {
        int32_t __stdcall put_DisplayName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayName(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing::OptionDetails::IPrintCustomTextOptionDetails> : produce_base<D, llm::OS::Graphics::Printing::OptionDetails::IPrintCustomTextOptionDetails>
    {
        int32_t __stdcall put_MaxCharacters(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxCharacters(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxCharacters(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MaxCharacters());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing::OptionDetails::IPrintCustomTextOptionDetails2> : produce_base<D, llm::OS::Graphics::Printing::OptionDetails::IPrintCustomTextOptionDetails2>
    {
        int32_t __stdcall put_WarningText(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WarningText(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WarningText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().WarningText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Description(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Description(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Description(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing::OptionDetails::IPrintCustomToggleOptionDetails> : produce_base<D, llm::OS::Graphics::Printing::OptionDetails::IPrintCustomToggleOptionDetails>
    {
        int32_t __stdcall put_WarningText(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WarningText(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WarningText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().WarningText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Description(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Description(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Description(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing::OptionDetails::IPrintDuplexOptionDetails> : produce_base<D, llm::OS::Graphics::Printing::OptionDetails::IPrintDuplexOptionDetails>
    {
        int32_t __stdcall put_WarningText(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WarningText(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WarningText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().WarningText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Description(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Description(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Description(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing::OptionDetails::IPrintHolePunchOptionDetails> : produce_base<D, llm::OS::Graphics::Printing::OptionDetails::IPrintHolePunchOptionDetails>
    {
        int32_t __stdcall put_WarningText(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WarningText(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WarningText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().WarningText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Description(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Description(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Description(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails> : produce_base<D, llm::OS::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails>
    {
        int32_t __stdcall get_Items(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Foundation::IInspectable>>(this->shim().Items());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing::OptionDetails::IPrintMediaSizeOptionDetails> : produce_base<D, llm::OS::Graphics::Printing::OptionDetails::IPrintMediaSizeOptionDetails>
    {
        int32_t __stdcall put_WarningText(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WarningText(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WarningText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().WarningText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Description(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Description(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Description(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing::OptionDetails::IPrintMediaTypeOptionDetails> : produce_base<D, llm::OS::Graphics::Printing::OptionDetails::IPrintMediaTypeOptionDetails>
    {
        int32_t __stdcall put_WarningText(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WarningText(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WarningText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().WarningText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Description(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Description(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Description(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing::OptionDetails::IPrintNumberOptionDetails> : produce_base<D, llm::OS::Graphics::Printing::OptionDetails::IPrintNumberOptionDetails>
    {
        int32_t __stdcall get_MinValue(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MinValue());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxValue(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MaxValue());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing::OptionDetails::IPrintOptionDetails> : produce_base<D, llm::OS::Graphics::Printing::OptionDetails::IPrintOptionDetails>
    {
        int32_t __stdcall get_OptionId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().OptionId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OptionType(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing::OptionDetails::PrintOptionType>(this->shim().OptionType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ErrorText(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ErrorText(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ErrorText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ErrorText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_State(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().State(*reinterpret_cast<llm::OS::Graphics::Printing::OptionDetails::PrintOptionStates const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_State(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing::OptionDetails::PrintOptionStates>(this->shim().State());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Value(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IInspectable>(this->shim().Value());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TrySetValue(void* value, bool* succeeded) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_from<bool>(this->shim().TrySetValue(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing::OptionDetails::IPrintOrientationOptionDetails> : produce_base<D, llm::OS::Graphics::Printing::OptionDetails::IPrintOrientationOptionDetails>
    {
        int32_t __stdcall put_WarningText(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WarningText(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WarningText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().WarningText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Description(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Description(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Description(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing::OptionDetails::IPrintPageRangeOptionDetails> : produce_base<D, llm::OS::Graphics::Printing::OptionDetails::IPrintPageRangeOptionDetails>
    {
        int32_t __stdcall put_WarningText(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WarningText(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WarningText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().WarningText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Description(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Description(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Description(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing::OptionDetails::IPrintQualityOptionDetails> : produce_base<D, llm::OS::Graphics::Printing::OptionDetails::IPrintQualityOptionDetails>
    {
        int32_t __stdcall put_WarningText(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WarningText(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WarningText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().WarningText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Description(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Description(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Description(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing::OptionDetails::IPrintStapleOptionDetails> : produce_base<D, llm::OS::Graphics::Printing::OptionDetails::IPrintStapleOptionDetails>
    {
        int32_t __stdcall put_WarningText(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WarningText(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WarningText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().WarningText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Description(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Description(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Description(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing::OptionDetails::IPrintTaskOptionChangedEventArgs> : produce_base<D, llm::OS::Graphics::Printing::OptionDetails::IPrintTaskOptionChangedEventArgs>
    {
        int32_t __stdcall get_OptionId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IInspectable>(this->shim().OptionId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails> : produce_base<D, llm::OS::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails>
    {
        int32_t __stdcall get_Options(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Graphics::Printing::OptionDetails::IPrintOptionDetails>>(this->shim().Options());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateItemListOption(void* optionId, void* displayName, void** itemListOption) noexcept final try
        {
            clear_abi(itemListOption);
            typename D::abi_guard guard(this->shim());
            *itemListOption = detach_from<llm::OS::Graphics::Printing::OptionDetails::PrintCustomItemListOptionDetails>(this->shim().CreateItemListOption(*reinterpret_cast<hstring const*>(&optionId), *reinterpret_cast<hstring const*>(&displayName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateTextOption(void* optionId, void* displayName, void** textOption) noexcept final try
        {
            clear_abi(textOption);
            typename D::abi_guard guard(this->shim());
            *textOption = detach_from<llm::OS::Graphics::Printing::OptionDetails::PrintCustomTextOptionDetails>(this->shim().CreateTextOption(*reinterpret_cast<hstring const*>(&optionId), *reinterpret_cast<hstring const*>(&displayName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_OptionChanged(void* eventHandler, llm::event_token* eventCookie) noexcept final try
        {
            zero_abi<llm::event_token>(eventCookie);
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_from<llm::event_token>(this->shim().OptionChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Printing::OptionDetails::PrintTaskOptionDetails, llm::OS::Graphics::Printing::OptionDetails::PrintTaskOptionChangedEventArgs> const*>(&eventHandler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_OptionChanged(llm::event_token eventCookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OptionChanged(*reinterpret_cast<llm::event_token const*>(&eventCookie));
            return 0;
        }
        int32_t __stdcall add_BeginValidation(void* eventHandler, llm::event_token* eventCookie) noexcept final try
        {
            zero_abi<llm::event_token>(eventCookie);
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_from<llm::event_token>(this->shim().BeginValidation(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Printing::OptionDetails::PrintTaskOptionDetails, llm::OS::Foundation::IInspectable> const*>(&eventHandler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_BeginValidation(llm::event_token eventCookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BeginValidation(*reinterpret_cast<llm::event_token const*>(&eventCookie));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails2> : produce_base<D, llm::OS::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails2>
    {
        int32_t __stdcall CreateToggleOption(void* optionId, void* displayName, void** toggleOption) noexcept final try
        {
            clear_abi(toggleOption);
            typename D::abi_guard guard(this->shim());
            *toggleOption = detach_from<llm::OS::Graphics::Printing::OptionDetails::PrintCustomToggleOptionDetails>(this->shim().CreateToggleOption(*reinterpret_cast<hstring const*>(&optionId), *reinterpret_cast<hstring const*>(&displayName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing::OptionDetails::IPrintTaskOptionDetailsStatic> : produce_base<D, llm::OS::Graphics::Printing::OptionDetails::IPrintTaskOptionDetailsStatic>
    {
        int32_t __stdcall GetFromPrintTaskOptions(void* printTaskOptions, void** printTaskOptionDetails) noexcept final try
        {
            clear_abi(printTaskOptionDetails);
            typename D::abi_guard guard(this->shim());
            *printTaskOptionDetails = detach_from<llm::OS::Graphics::Printing::OptionDetails::PrintTaskOptionDetails>(this->shim().GetFromPrintTaskOptions(*reinterpret_cast<llm::OS::Graphics::Printing::PrintTaskOptions const*>(&printTaskOptions)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing::OptionDetails::IPrintTextOptionDetails> : produce_base<D, llm::OS::Graphics::Printing::OptionDetails::IPrintTextOptionDetails>
    {
        int32_t __stdcall get_MaxCharacters(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MaxCharacters());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
}
LLM_EXPORT namespace llm::OS::Graphics::Printing::OptionDetails
{
    constexpr auto operator|(PrintOptionStates const left, PrintOptionStates const right) noexcept
    {
        return static_cast<PrintOptionStates>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(PrintOptionStates& left, PrintOptionStates const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(PrintOptionStates const left, PrintOptionStates const right) noexcept
    {
        return static_cast<PrintOptionStates>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(PrintOptionStates& left, PrintOptionStates const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(PrintOptionStates const value) noexcept
    {
        return static_cast<PrintOptionStates>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(PrintOptionStates const left, PrintOptionStates const right) noexcept
    {
        return static_cast<PrintOptionStates>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(PrintOptionStates& left, PrintOptionStates const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    inline auto PrintTaskOptionDetails::GetFromPrintTaskOptions(llm::OS::Graphics::Printing::PrintTaskOptions const& printTaskOptions)
    {
        return impl::call_factory<PrintTaskOptionDetails, IPrintTaskOptionDetailsStatic>([&](IPrintTaskOptionDetailsStatic const& f) { return f.GetFromPrintTaskOptions(printTaskOptions); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::IPrintBindingOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::IPrintBorderingOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::IPrintCollationOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::IPrintColorModeOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::IPrintCopiesOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::IPrintCustomItemDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::IPrintCustomItemListOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::IPrintCustomItemListOptionDetails2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::IPrintCustomItemListOptionDetails3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::IPrintCustomOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::IPrintCustomTextOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::IPrintCustomTextOptionDetails2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::IPrintCustomToggleOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::IPrintDuplexOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::IPrintHolePunchOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::IPrintMediaSizeOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::IPrintMediaTypeOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::IPrintNumberOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::IPrintOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::IPrintOrientationOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::IPrintPageRangeOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::IPrintQualityOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::IPrintStapleOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::IPrintTaskOptionChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::IPrintTaskOptionDetailsStatic> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::IPrintTextOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::PrintBindingOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::PrintBorderingOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::PrintCollationOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::PrintColorModeOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::PrintCopiesOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::PrintCustomItemDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::PrintCustomItemListOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::PrintCustomTextOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::PrintCustomToggleOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::PrintDuplexOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::PrintHolePunchOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::PrintMediaSizeOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::PrintMediaTypeOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::PrintOrientationOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::PrintPageRangeOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::PrintQualityOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::PrintStapleOptionDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::PrintTaskOptionChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing::OptionDetails::PrintTaskOptionDetails> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
