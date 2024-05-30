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
#ifndef LLM_OS_Perception_0_H
#define LLM_OS_Perception_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
}
LLM_EXPORT namespace llm:OS::Perception
{
    struct IPerceptionTimestamp;
    struct IPerceptionTimestamp2;
    struct IPerceptionTimestampHelperStatics;
    struct IPerceptionTimestampHelperStatics2;
    struct PerceptionTimestamp;
    struct PerceptionTimestampHelper;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Perception::IPerceptionTimestamp>{ using type = interface_category; };
    template <> struct category<llm:OS::Perception::IPerceptionTimestamp2>{ using type = interface_category; };
    template <> struct category<llm:OS::Perception::IPerceptionTimestampHelperStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Perception::IPerceptionTimestampHelperStatics2>{ using type = interface_category; };
    template <> struct category<llm:OS::Perception::PerceptionTimestamp>{ using type = class_category; };
    template <> struct category<llm:OS::Perception::PerceptionTimestampHelper>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm:OS::Perception::PerceptionTimestamp> = L"Windows.Perception.PerceptionTimestamp";
    template <> inline constexpr auto& name_v<llm:OS::Perception::PerceptionTimestampHelper> = L"Windows.Perception.PerceptionTimestampHelper";
    template <> inline constexpr auto& name_v<llm:OS::Perception::IPerceptionTimestamp> = L"Windows.Perception.IPerceptionTimestamp";
    template <> inline constexpr auto& name_v<llm:OS::Perception::IPerceptionTimestamp2> = L"Windows.Perception.IPerceptionTimestamp2";
    template <> inline constexpr auto& name_v<llm:OS::Perception::IPerceptionTimestampHelperStatics> = L"Windows.Perception.IPerceptionTimestampHelperStatics";
    template <> inline constexpr auto& name_v<llm:OS::Perception::IPerceptionTimestampHelperStatics2> = L"Windows.Perception.IPerceptionTimestampHelperStatics2";
    template <> inline constexpr guid guid_v<llm:OS::Perception::IPerceptionTimestamp>{ 0x87C24804,0xA22E,0x4ADB,{ 0xBA,0x26,0xD7,0x8E,0xF6,0x39,0xBC,0xF4 } }; // 87C24804-A22E-4ADB-BA26-D78EF639BCF4
    template <> inline constexpr guid guid_v<llm:OS::Perception::IPerceptionTimestamp2>{ 0xE354B7ED,0x2BD1,0x41B7,{ 0x9E,0xD0,0x74,0xA1,0x5C,0x35,0x45,0x37 } }; // E354B7ED-2BD1-41B7-9ED0-74A15C354537
    template <> inline constexpr guid guid_v<llm:OS::Perception::IPerceptionTimestampHelperStatics>{ 0x47A611D4,0xA9DF,0x4EDC,{ 0x85,0x5D,0xF4,0xD3,0x39,0xD9,0x67,0xAC } }; // 47A611D4-A9DF-4EDC-855D-F4D339D967AC
    template <> inline constexpr guid guid_v<llm:OS::Perception::IPerceptionTimestampHelperStatics2>{ 0x73D1A7FE,0x3FB9,0x4571,{ 0x87,0xD4,0x3C,0x92,0x0A,0x5E,0x86,0xEB } }; // 73D1A7FE-3FB9-4571-87D4-3C920A5E86EB
    template <> struct default_interface<llm:OS::Perception::PerceptionTimestamp>{ using type = llm:OS::Perception::IPerceptionTimestamp; };
    template <> struct abi<llm:OS::Perception::IPerceptionTimestamp>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_TargetTime(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_PredictionAmount(int64_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Perception::IPerceptionTimestamp2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SystemRelativeTargetTime(int64_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Perception::IPerceptionTimestampHelperStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FromHistoricalTargetTime(int64_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Perception::IPerceptionTimestampHelperStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FromSystemRelativeTargetTime(int64_t, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Perception_IPerceptionTimestamp
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::DateTime) TargetTime() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) PredictionAmount() const;
    };
    template <> struct consume<llm:OS::Perception::IPerceptionTimestamp>
    {
        template <typename D> using type = consume_Windows_Perception_IPerceptionTimestamp<D>;
    };
    template <typename D>
    struct consume_Windows_Perception_IPerceptionTimestamp2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) SystemRelativeTargetTime() const;
    };
    template <> struct consume<llm:OS::Perception::IPerceptionTimestamp2>
    {
        template <typename D> using type = consume_Windows_Perception_IPerceptionTimestamp2<D>;
    };
    template <typename D>
    struct consume_Windows_Perception_IPerceptionTimestampHelperStatics
    {
        LLM_IMPL_AUTO(llm:OS::Perception::PerceptionTimestamp) FromHistoricalTargetTime(llm:OS::Foundation::DateTime const& targetTime) const;
    };
    template <> struct consume<llm:OS::Perception::IPerceptionTimestampHelperStatics>
    {
        template <typename D> using type = consume_Windows_Perception_IPerceptionTimestampHelperStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Perception_IPerceptionTimestampHelperStatics2
    {
        LLM_IMPL_AUTO(llm:OS::Perception::PerceptionTimestamp) FromSystemRelativeTargetTime(llm:OS::Foundation::TimeSpan const& targetTime) const;
    };
    template <> struct consume<llm:OS::Perception::IPerceptionTimestampHelperStatics2>
    {
        template <typename D> using type = consume_Windows_Perception_IPerceptionTimestampHelperStatics2<D>;
    };
}
#endif
