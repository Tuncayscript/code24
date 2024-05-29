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
#ifndef LLM_OS_ApplicationModel_Holographic_0_H
#define LLM_OS_ApplicationModel_Holographic_0_H
LLM_EXPORT namespace llm::OS::Foundation::Numerics
{
}
LLM_EXPORT namespace llm::OS::Perception::Spatial
{
    struct SpatialCoordinateSystem;
}
LLM_EXPORT namespace llm::OS::ApplicationModel::Holographic
{
    struct IHolographicKeyboard;
    struct IHolographicKeyboardStatics;
    struct HolographicKeyboard;
}
namespace llm::impl
{
    template <> struct category<llm::OS::ApplicationModel::Holographic::IHolographicKeyboard>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Holographic::IHolographicKeyboardStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Holographic::HolographicKeyboard>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Holographic::HolographicKeyboard> = L"Windows.ApplicationModel.Holographic.HolographicKeyboard";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Holographic::IHolographicKeyboard> = L"Windows.ApplicationModel.Holographic.IHolographicKeyboard";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Holographic::IHolographicKeyboardStatics> = L"Windows.ApplicationModel.Holographic.IHolographicKeyboardStatics";
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Holographic::IHolographicKeyboard>{ 0x07DD0893,0xAA21,0x5E6F,{ 0xA9,0x1B,0x11,0xB2,0xB3,0xFD,0x7B,0xE3 } }; // 07DD0893-AA21-5E6F-A91B-11B2B3FD7BE3
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Holographic::IHolographicKeyboardStatics>{ 0xB676C624,0x63D7,0x58CF,{ 0xB0,0x6B,0x08,0xBA,0xA0,0x32,0xA2,0x3F } }; // B676C624-63D7-58CF-B06B-08BAA032A23F
    template <> struct default_interface<llm::OS::ApplicationModel::Holographic::HolographicKeyboard>{ using type = llm::OS::ApplicationModel::Holographic::IHolographicKeyboard; };
    template <> struct abi<llm::OS::ApplicationModel::Holographic::IHolographicKeyboard>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SetPlacementOverride(void*, llm::OS::Foundation::Numerics::float3, llm::OS::Foundation::Numerics::quaternion) noexcept = 0;
            virtual int32_t __stdcall SetPlacementOverrideWithMaxSize(void*, llm::OS::Foundation::Numerics::float3, llm::OS::Foundation::Numerics::quaternion, llm::OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall ResetPlacementOverride() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Holographic::IHolographicKeyboardStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDefault(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Holographic_IHolographicKeyboard
    {
        LLM_IMPL_AUTO(void) SetPlacementOverride(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm::OS::Foundation::Numerics::float3 const& topCenterPosition, llm::OS::Foundation::Numerics::quaternion const& orientation) const;
        LLM_IMPL_AUTO(void) SetPlacementOverride(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm::OS::Foundation::Numerics::float3 const& topCenterPosition, llm::OS::Foundation::Numerics::quaternion const& orientation, llm::OS::Foundation::Numerics::float2 const& maxSize) const;
        LLM_IMPL_AUTO(void) ResetPlacementOverride() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Holographic::IHolographicKeyboard>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Holographic_IHolographicKeyboard<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Holographic_IHolographicKeyboardStatics
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Holographic::HolographicKeyboard) GetDefault() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Holographic::IHolographicKeyboardStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Holographic_IHolographicKeyboardStatics<D>;
    };
}
#endif
