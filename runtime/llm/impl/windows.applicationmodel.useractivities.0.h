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
#ifndef LLM_OS_ApplicationModel_UserActivities_0_H
#define LLM_OS_ApplicationModel_UserActivities_0_H
LLM_EXPORT namespace llm::OS::Foundation
{
    struct Deferral;
    struct EventRegistrationToken;
    struct IAsyncAction;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename T> struct __declspec(empty_bases) IReference;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
    struct Uri;
}
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IIterable;
    template <typename T> struct __declspec(empty_bases) IVector;
}
LLM_EXPORT namespace llm::OS::Security::Credentials
{
    struct WebAccount;
}
LLM_EXPORT namespace llm::OS::System
{
    struct User;
}
LLM_EXPORT namespace llm::OS::UI
{
    struct Color;
}
LLM_EXPORT namespace llm::OS::UI::Shell
{
    struct IAdaptiveCard;
}
LLM_EXPORT namespace llm::OS::ApplicationModel::UserActivities
{
    enum class UserActivityState : int32_t
    {
        New = 0,
        Published = 1,
    };
    struct IUserActivity;
    struct IUserActivity2;
    struct IUserActivity3;
    struct IUserActivityAttribution;
    struct IUserActivityAttributionFactory;
    struct IUserActivityChannel;
    struct IUserActivityChannel2;
    struct IUserActivityChannelStatics;
    struct IUserActivityChannelStatics2;
    struct IUserActivityChannelStatics3;
    struct IUserActivityContentInfo;
    struct IUserActivityContentInfoStatics;
    struct IUserActivityFactory;
    struct IUserActivityRequest;
    struct IUserActivityRequestManager;
    struct IUserActivityRequestManagerStatics;
    struct IUserActivityRequestedEventArgs;
    struct IUserActivitySession;
    struct IUserActivitySessionHistoryItem;
    struct IUserActivityStatics;
    struct IUserActivityVisualElements;
    struct IUserActivityVisualElements2;
    struct UserActivity;
    struct UserActivityAttribution;
    struct UserActivityChannel;
    struct UserActivityContentInfo;
    struct UserActivityRequest;
    struct UserActivityRequestManager;
    struct UserActivityRequestedEventArgs;
    struct UserActivitySession;
    struct UserActivitySessionHistoryItem;
    struct UserActivityVisualElements;
}
namespace llm::impl
{
    template <> struct category<llm::OS::ApplicationModel::UserActivities::IUserActivity>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::IUserActivity2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::IUserActivity3>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::IUserActivityAttribution>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::IUserActivityAttributionFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::IUserActivityChannel>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::IUserActivityChannel2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::IUserActivityChannelStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::IUserActivityChannelStatics2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::IUserActivityChannelStatics3>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::IUserActivityContentInfo>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::IUserActivityContentInfoStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::IUserActivityFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::IUserActivityRequest>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::IUserActivityRequestManager>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::IUserActivityRequestManagerStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::IUserActivityRequestedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::IUserActivitySession>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::IUserActivitySessionHistoryItem>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::IUserActivityStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::IUserActivityVisualElements>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::IUserActivityVisualElements2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::UserActivity>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::UserActivityAttribution>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::UserActivityChannel>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::UserActivityContentInfo>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::UserActivityRequest>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::UserActivityRequestManager>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::UserActivityRequestedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::UserActivitySession>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::UserActivitySessionHistoryItem>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::UserActivityVisualElements>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::UserActivityState>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::UserActivity> = L"Windows.ApplicationModel.UserActivities.UserActivity";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::UserActivityAttribution> = L"Windows.ApplicationModel.UserActivities.UserActivityAttribution";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::UserActivityChannel> = L"Windows.ApplicationModel.UserActivities.UserActivityChannel";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::UserActivityContentInfo> = L"Windows.ApplicationModel.UserActivities.UserActivityContentInfo";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::UserActivityRequest> = L"Windows.ApplicationModel.UserActivities.UserActivityRequest";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::UserActivityRequestManager> = L"Windows.ApplicationModel.UserActivities.UserActivityRequestManager";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::UserActivityRequestedEventArgs> = L"Windows.ApplicationModel.UserActivities.UserActivityRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::UserActivitySession> = L"Windows.ApplicationModel.UserActivities.UserActivitySession";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::UserActivitySessionHistoryItem> = L"Windows.ApplicationModel.UserActivities.UserActivitySessionHistoryItem";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::UserActivityVisualElements> = L"Windows.ApplicationModel.UserActivities.UserActivityVisualElements";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::UserActivityState> = L"Windows.ApplicationModel.UserActivities.UserActivityState";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::IUserActivity> = L"Windows.ApplicationModel.UserActivities.IUserActivity";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::IUserActivity2> = L"Windows.ApplicationModel.UserActivities.IUserActivity2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::IUserActivity3> = L"Windows.ApplicationModel.UserActivities.IUserActivity3";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::IUserActivityAttribution> = L"Windows.ApplicationModel.UserActivities.IUserActivityAttribution";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::IUserActivityAttributionFactory> = L"Windows.ApplicationModel.UserActivities.IUserActivityAttributionFactory";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::IUserActivityChannel> = L"Windows.ApplicationModel.UserActivities.IUserActivityChannel";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::IUserActivityChannel2> = L"Windows.ApplicationModel.UserActivities.IUserActivityChannel2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::IUserActivityChannelStatics> = L"Windows.ApplicationModel.UserActivities.IUserActivityChannelStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::IUserActivityChannelStatics2> = L"Windows.ApplicationModel.UserActivities.IUserActivityChannelStatics2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::IUserActivityChannelStatics3> = L"Windows.ApplicationModel.UserActivities.IUserActivityChannelStatics3";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::IUserActivityContentInfo> = L"Windows.ApplicationModel.UserActivities.IUserActivityContentInfo";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::IUserActivityContentInfoStatics> = L"Windows.ApplicationModel.UserActivities.IUserActivityContentInfoStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::IUserActivityFactory> = L"Windows.ApplicationModel.UserActivities.IUserActivityFactory";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::IUserActivityRequest> = L"Windows.ApplicationModel.UserActivities.IUserActivityRequest";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::IUserActivityRequestManager> = L"Windows.ApplicationModel.UserActivities.IUserActivityRequestManager";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::IUserActivityRequestManagerStatics> = L"Windows.ApplicationModel.UserActivities.IUserActivityRequestManagerStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::IUserActivityRequestedEventArgs> = L"Windows.ApplicationModel.UserActivities.IUserActivityRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::IUserActivitySession> = L"Windows.ApplicationModel.UserActivities.IUserActivitySession";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::IUserActivitySessionHistoryItem> = L"Windows.ApplicationModel.UserActivities.IUserActivitySessionHistoryItem";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::IUserActivityStatics> = L"Windows.ApplicationModel.UserActivities.IUserActivityStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::IUserActivityVisualElements> = L"Windows.ApplicationModel.UserActivities.IUserActivityVisualElements";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::IUserActivityVisualElements2> = L"Windows.ApplicationModel.UserActivities.IUserActivityVisualElements2";
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::UserActivities::IUserActivity>{ 0xFC103E9E,0x2CAB,0x4D36,{ 0xAE,0xA2,0xB4,0xBB,0x55,0x6C,0xEF,0x0F } }; // FC103E9E-2CAB-4D36-AEA2-B4BB556CEF0F
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::UserActivities::IUserActivity2>{ 0x9DC40C62,0x08C4,0x47AC,{ 0xAA,0x9C,0x2B,0xB2,0x22,0x1C,0x55,0xFD } }; // 9DC40C62-08C4-47AC-AA9C-2BB2221C55FD
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::UserActivities::IUserActivity3>{ 0xE7697744,0xE1A2,0x5147,{ 0x8E,0x06,0x55,0xF1,0xEE,0xEF,0x27,0x1C } }; // E7697744-E1A2-5147-8E06-55F1EEEF271C
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::UserActivities::IUserActivityAttribution>{ 0x34A5C8B5,0x86DD,0x4AEC,{ 0xA4,0x91,0x6A,0x4F,0xAE,0xA5,0xD2,0x2E } }; // 34A5C8B5-86DD-4AEC-A491-6A4FAEA5D22E
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::UserActivities::IUserActivityAttributionFactory>{ 0xE62BD252,0xC566,0x4F42,{ 0x99,0x74,0x91,0x6C,0x4D,0x76,0x37,0x7E } }; // E62BD252-C566-4F42-9974-916C4D76377E
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::UserActivities::IUserActivityChannel>{ 0xBAC0F8B8,0xA0E4,0x483B,{ 0xB9,0x48,0x9C,0xBA,0xBD,0x06,0x07,0x0C } }; // BAC0F8B8-A0E4-483B-B948-9CBABD06070C
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::UserActivities::IUserActivityChannel2>{ 0x1698E35B,0xEB7E,0x4EA0,{ 0xBF,0x17,0xA4,0x59,0xE8,0xBE,0x70,0x6C } }; // 1698E35B-EB7E-4EA0-BF17-A459E8BE706C
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::UserActivities::IUserActivityChannelStatics>{ 0xC8C005AB,0x198D,0x4D80,{ 0xAB,0xB2,0xC9,0x77,0x5E,0xC4,0xA7,0x29 } }; // C8C005AB-198D-4D80-ABB2-C9775EC4A729
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::UserActivities::IUserActivityChannelStatics2>{ 0x8E87DE30,0xAA4F,0x4624,{ 0x9A,0xD0,0xD4,0x0F,0x3B,0xA0,0x31,0x7C } }; // 8E87DE30-AA4F-4624-9AD0-D40F3BA0317C
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::UserActivities::IUserActivityChannelStatics3>{ 0x53BC4DDB,0xBBDF,0x5984,{ 0x80,0x2A,0x53,0x05,0x87,0x4E,0x20,0x5C } }; // 53BC4DDB-BBDF-5984-802A-5305874E205C
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::UserActivities::IUserActivityContentInfo>{ 0xB399E5AD,0x137F,0x409D,{ 0x82,0x2D,0xE1,0xAF,0x27,0xCE,0x08,0xDC } }; // B399E5AD-137F-409D-822D-E1AF27CE08DC
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::UserActivities::IUserActivityContentInfoStatics>{ 0x9988C34B,0x0386,0x4BC9,{ 0x96,0x8A,0x82,0x00,0xB0,0x04,0x14,0x4F } }; // 9988C34B-0386-4BC9-968A-8200B004144F
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::UserActivities::IUserActivityFactory>{ 0x7C385758,0x361D,0x4A67,{ 0x8A,0x3B,0x34,0xCA,0x29,0x78,0xF9,0xA3 } }; // 7C385758-361D-4A67-8A3B-34CA2978F9A3
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::UserActivities::IUserActivityRequest>{ 0xA0EF6355,0xCF35,0x4FF0,{ 0x88,0x33,0x50,0xCB,0x4B,0x72,0xE0,0x6D } }; // A0EF6355-CF35-4FF0-8833-50CB4B72E06D
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::UserActivities::IUserActivityRequestManager>{ 0x0C30BE4E,0x903D,0x48D6,{ 0x82,0xD4,0x40,0x43,0xED,0x57,0x79,0x1B } }; // 0C30BE4E-903D-48D6-82D4-4043ED57791B
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::UserActivities::IUserActivityRequestManagerStatics>{ 0xC0392DF1,0x224A,0x432C,{ 0x81,0xE5,0x0C,0x76,0xB4,0xC4,0xCE,0xFA } }; // C0392DF1-224A-432C-81E5-0C76B4C4CEFA
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::UserActivities::IUserActivityRequestedEventArgs>{ 0xA4CC7A4C,0x8229,0x4CFD,{ 0xA3,0xBC,0xC6,0x1D,0x31,0x85,0x75,0xA4 } }; // A4CC7A4C-8229-4CFD-A3BC-C61D318575A4
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::UserActivities::IUserActivitySession>{ 0xAE434D78,0x24FA,0x44A3,{ 0xAD,0x48,0x6E,0xDA,0x61,0xAA,0x19,0x24 } }; // AE434D78-24FA-44A3-AD48-6EDA61AA1924
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::UserActivities::IUserActivitySessionHistoryItem>{ 0xE8D59BD3,0x3E5D,0x49FD,{ 0x98,0xD7,0x6D,0xA9,0x75,0x21,0xE2,0x55 } }; // E8D59BD3-3E5D-49FD-98D7-6DA97521E255
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::UserActivities::IUserActivityStatics>{ 0x8C8FD333,0x0E09,0x47F6,{ 0x9A,0xC7,0x95,0xCF,0x5C,0x39,0x36,0x7B } }; // 8C8FD333-0E09-47F6-9AC7-95CF5C39367B
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::UserActivities::IUserActivityVisualElements>{ 0x94757513,0x262F,0x49EF,{ 0xBB,0xBF,0x9B,0x75,0xD2,0xE8,0x52,0x50 } }; // 94757513-262F-49EF-BBBF-9B75D2E85250
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::UserActivities::IUserActivityVisualElements2>{ 0xCAAE7FC7,0x3EEF,0x4359,{ 0x82,0x5C,0x9D,0x51,0xB9,0x22,0x0D,0xE3 } }; // CAAE7FC7-3EEF-4359-825C-9D51B9220DE3
    template <> struct default_interface<llm::OS::ApplicationModel::UserActivities::UserActivity>{ using type = llm::OS::ApplicationModel::UserActivities::IUserActivity; };
    template <> struct default_interface<llm::OS::ApplicationModel::UserActivities::UserActivityAttribution>{ using type = llm::OS::ApplicationModel::UserActivities::IUserActivityAttribution; };
    template <> struct default_interface<llm::OS::ApplicationModel::UserActivities::UserActivityChannel>{ using type = llm::OS::ApplicationModel::UserActivities::IUserActivityChannel; };
    template <> struct default_interface<llm::OS::ApplicationModel::UserActivities::UserActivityContentInfo>{ using type = llm::OS::ApplicationModel::UserActivities::IUserActivityContentInfo; };
    template <> struct default_interface<llm::OS::ApplicationModel::UserActivities::UserActivityRequest>{ using type = llm::OS::ApplicationModel::UserActivities::IUserActivityRequest; };
    template <> struct default_interface<llm::OS::ApplicationModel::UserActivities::UserActivityRequestManager>{ using type = llm::OS::ApplicationModel::UserActivities::IUserActivityRequestManager; };
    template <> struct default_interface<llm::OS::ApplicationModel::UserActivities::UserActivityRequestedEventArgs>{ using type = llm::OS::ApplicationModel::UserActivities::IUserActivityRequestedEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::UserActivities::UserActivitySession>{ using type = llm::OS::ApplicationModel::UserActivities::IUserActivitySession; };
    template <> struct default_interface<llm::OS::ApplicationModel::UserActivities::UserActivitySessionHistoryItem>{ using type = llm::OS::ApplicationModel::UserActivities::IUserActivitySessionHistoryItem; };
    template <> struct default_interface<llm::OS::ApplicationModel::UserActivities::UserActivityVisualElements>{ using type = llm::OS::ApplicationModel::UserActivities::IUserActivityVisualElements; };
    template <> struct abi<llm::OS::ApplicationModel::UserActivities::IUserActivity>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_State(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ActivityId(void**) noexcept = 0;
            virtual int32_t __stdcall get_VisualElements(void**) noexcept = 0;
            virtual int32_t __stdcall get_ContentUri(void**) noexcept = 0;
            virtual int32_t __stdcall put_ContentUri(void*) noexcept = 0;
            virtual int32_t __stdcall get_ContentType(void**) noexcept = 0;
            virtual int32_t __stdcall put_ContentType(void*) noexcept = 0;
            virtual int32_t __stdcall get_FallbackUri(void**) noexcept = 0;
            virtual int32_t __stdcall put_FallbackUri(void*) noexcept = 0;
            virtual int32_t __stdcall get_ActivationUri(void**) noexcept = 0;
            virtual int32_t __stdcall put_ActivationUri(void*) noexcept = 0;
            virtual int32_t __stdcall get_ContentInfo(void**) noexcept = 0;
            virtual int32_t __stdcall put_ContentInfo(void*) noexcept = 0;
            virtual int32_t __stdcall SaveAsync(void**) noexcept = 0;
            virtual int32_t __stdcall CreateSession(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::UserActivities::IUserActivity2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall ToJson(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::UserActivities::IUserActivity3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsRoamable(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsRoamable(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::UserActivities::IUserActivityAttribution>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IconUri(void**) noexcept = 0;
            virtual int32_t __stdcall put_IconUri(void*) noexcept = 0;
            virtual int32_t __stdcall get_AlternateText(void**) noexcept = 0;
            virtual int32_t __stdcall put_AlternateText(void*) noexcept = 0;
            virtual int32_t __stdcall get_AddImageQuery(bool*) noexcept = 0;
            virtual int32_t __stdcall put_AddImageQuery(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::UserActivities::IUserActivityAttributionFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateWithUri(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::UserActivities::IUserActivityChannel>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetOrCreateUserActivityAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall DeleteActivityAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall DeleteAllActivitiesAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::UserActivities::IUserActivityChannel2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetRecentUserActivitiesAsync(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall GetSessionHistoryItemsForUserActivityAsync(void*, int64_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::UserActivities::IUserActivityChannelStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDefault(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::UserActivities::IUserActivityChannelStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall DisableAutoSessionCreation() noexcept = 0;
            virtual int32_t __stdcall TryGetForWebAccount(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::UserActivities::IUserActivityChannelStatics3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetForUser(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::UserActivities::IUserActivityContentInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall ToJson(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::UserActivities::IUserActivityContentInfoStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FromJson(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::UserActivities::IUserActivityFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateWithActivityId(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::UserActivities::IUserActivityRequest>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SetUserActivity(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::UserActivities::IUserActivityRequestManager>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_UserActivityRequested(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_UserActivityRequested(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::UserActivities::IUserActivityRequestManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetForCurrentView(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::UserActivities::IUserActivityRequestedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Request(void**) noexcept = 0;
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::UserActivities::IUserActivitySession>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ActivityId(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::UserActivities::IUserActivitySessionHistoryItem>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_UserActivity(void**) noexcept = 0;
            virtual int32_t __stdcall get_StartTime(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_EndTime(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::UserActivities::IUserActivityStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall TryParseFromJson(void*, void**) noexcept = 0;
            virtual int32_t __stdcall TryParseFromJsonArray(void*, void**) noexcept = 0;
            virtual int32_t __stdcall ToJsonArray(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::UserActivities::IUserActivityVisualElements>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DisplayText(void**) noexcept = 0;
            virtual int32_t __stdcall put_DisplayText(void*) noexcept = 0;
            virtual int32_t __stdcall get_Description(void**) noexcept = 0;
            virtual int32_t __stdcall put_Description(void*) noexcept = 0;
            virtual int32_t __stdcall get_BackgroundColor(struct struct_Windows_UI_Color*) noexcept = 0;
            virtual int32_t __stdcall put_BackgroundColor(struct struct_Windows_UI_Color) noexcept = 0;
            virtual int32_t __stdcall get_Attribution(void**) noexcept = 0;
            virtual int32_t __stdcall put_Attribution(void*) noexcept = 0;
            virtual int32_t __stdcall put_Content(void*) noexcept = 0;
            virtual int32_t __stdcall get_Content(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::UserActivities::IUserActivityVisualElements2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AttributionDisplayText(void**) noexcept = 0;
            virtual int32_t __stdcall put_AttributionDisplayText(void*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_UserActivities_IUserActivity
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::UserActivities::UserActivityState) State() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ActivityId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::UserActivities::UserActivityVisualElements) VisualElements() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Uri) ContentUri() const;
        LLM_IMPL_AUTO(void) ContentUri(llm::OS::Foundation::Uri const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ContentType() const;
        LLM_IMPL_AUTO(void) ContentType(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Uri) FallbackUri() const;
        LLM_IMPL_AUTO(void) FallbackUri(llm::OS::Foundation::Uri const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Uri) ActivationUri() const;
        LLM_IMPL_AUTO(void) ActivationUri(llm::OS::Foundation::Uri const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::UserActivities::IUserActivityContentInfo) ContentInfo() const;
        LLM_IMPL_AUTO(void) ContentInfo(llm::OS::ApplicationModel::UserActivities::IUserActivityContentInfo const& value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) SaveAsync() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::UserActivities::UserActivitySession) CreateSession() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::UserActivities::IUserActivity>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_UserActivities_IUserActivity<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_UserActivities_IUserActivity2
    {
        LLM_IMPL_AUTO(hstring) ToJson() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::UserActivities::IUserActivity2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_UserActivities_IUserActivity2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_UserActivities_IUserActivity3
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsRoamable() const;
        LLM_IMPL_AUTO(void) IsRoamable(bool value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::UserActivities::IUserActivity3>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_UserActivities_IUserActivity3<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_UserActivities_IUserActivityAttribution
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Uri) IconUri() const;
        LLM_IMPL_AUTO(void) IconUri(llm::OS::Foundation::Uri const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AlternateText() const;
        LLM_IMPL_AUTO(void) AlternateText(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) AddImageQuery() const;
        LLM_IMPL_AUTO(void) AddImageQuery(bool value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::UserActivities::IUserActivityAttribution>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_UserActivities_IUserActivityAttribution<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_UserActivities_IUserActivityAttributionFactory
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::UserActivities::UserActivityAttribution) CreateWithUri(llm::OS::Foundation::Uri const& iconUri) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::UserActivities::IUserActivityAttributionFactory>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_UserActivities_IUserActivityAttributionFactory<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_UserActivities_IUserActivityChannel
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::UserActivities::UserActivity>) GetOrCreateUserActivityAsync(param::hstring const& activityId) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) DeleteActivityAsync(param::hstring const& activityId) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) DeleteAllActivitiesAsync() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::UserActivities::IUserActivityChannel>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_UserActivities_IUserActivityChannel<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_UserActivities_IUserActivityChannel2
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::UserActivities::UserActivitySessionHistoryItem>>) GetRecentUserActivitiesAsync(int32_t maxUniqueActivities) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::UserActivities::UserActivitySessionHistoryItem>>) GetSessionHistoryItemsForUserActivityAsync(param::hstring const& activityId, llm::OS::Foundation::DateTime const& startTime) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::UserActivities::IUserActivityChannel2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_UserActivities_IUserActivityChannel2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_UserActivities_IUserActivityChannelStatics
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::UserActivities::UserActivityChannel) GetDefault() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::UserActivities::IUserActivityChannelStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_UserActivities_IUserActivityChannelStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_UserActivities_IUserActivityChannelStatics2
    {
        LLM_IMPL_AUTO(void) DisableAutoSessionCreation() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::UserActivities::UserActivityChannel) TryGetForWebAccount(llm::OS::Security::Credentials::WebAccount const& account) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::UserActivities::IUserActivityChannelStatics2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_UserActivities_IUserActivityChannelStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_UserActivities_IUserActivityChannelStatics3
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::UserActivities::UserActivityChannel) GetForUser(llm::OS::System::User const& user) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::UserActivities::IUserActivityChannelStatics3>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_UserActivities_IUserActivityChannelStatics3<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_UserActivities_IUserActivityContentInfo
    {
        LLM_IMPL_AUTO(hstring) ToJson() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::UserActivities::IUserActivityContentInfo>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_UserActivities_IUserActivityContentInfo<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_UserActivities_IUserActivityContentInfoStatics
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::UserActivities::UserActivityContentInfo) FromJson(param::hstring const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::UserActivities::IUserActivityContentInfoStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_UserActivities_IUserActivityContentInfoStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_UserActivities_IUserActivityFactory
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::UserActivities::UserActivity) CreateWithActivityId(param::hstring const& activityId) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::UserActivities::IUserActivityFactory>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_UserActivities_IUserActivityFactory<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_UserActivities_IUserActivityRequest
    {
        LLM_IMPL_AUTO(void) SetUserActivity(llm::OS::ApplicationModel::UserActivities::UserActivity const& activity) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::UserActivities::IUserActivityRequest>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_UserActivities_IUserActivityRequest<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_UserActivities_IUserActivityRequestManager
    {
        LLM_IMPL_AUTO(llm::event_token) UserActivityRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::UserActivities::UserActivityRequestManager, llm::OS::ApplicationModel::UserActivities::UserActivityRequestedEventArgs> const& handler) const;
        using UserActivityRequested_revoker = impl::event_revoker<llm::OS::ApplicationModel::UserActivities::IUserActivityRequestManager, &impl::abi_t<llm::OS::ApplicationModel::UserActivities::IUserActivityRequestManager>::remove_UserActivityRequested>;
        [[nodiscard]] UserActivityRequested_revoker UserActivityRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::UserActivities::UserActivityRequestManager, llm::OS::ApplicationModel::UserActivities::UserActivityRequestedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) UserActivityRequested(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm::OS::ApplicationModel::UserActivities::IUserActivityRequestManager>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_UserActivities_IUserActivityRequestManager<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_UserActivities_IUserActivityRequestManagerStatics
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::UserActivities::UserActivityRequestManager) GetForCurrentView() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::UserActivities::IUserActivityRequestManagerStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_UserActivities_IUserActivityRequestManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_UserActivities_IUserActivityRequestedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::UserActivities::UserActivityRequest) Request() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) GetDeferral() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::UserActivities::IUserActivityRequestedEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_UserActivities_IUserActivityRequestedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_UserActivities_IUserActivitySession
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ActivityId() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::UserActivities::IUserActivitySession>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_UserActivities_IUserActivitySession<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_UserActivities_IUserActivitySessionHistoryItem
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::UserActivities::UserActivity) UserActivity() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) StartTime() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>) EndTime() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::UserActivities::IUserActivitySessionHistoryItem>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_UserActivities_IUserActivitySessionHistoryItem<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_UserActivities_IUserActivityStatics
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::UserActivities::UserActivity) TryParseFromJson(param::hstring const& json) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::UserActivities::UserActivity>) TryParseFromJsonArray(param::hstring const& json) const;
        LLM_IMPL_AUTO(hstring) ToJsonArray(param::iterable<llm::OS::ApplicationModel::UserActivities::UserActivity> const& activities) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::UserActivities::IUserActivityStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_UserActivities_IUserActivityStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_UserActivities_IUserActivityVisualElements
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayText() const;
        LLM_IMPL_AUTO(void) DisplayText(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Description() const;
        LLM_IMPL_AUTO(void) Description(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Color) BackgroundColor() const;
        LLM_IMPL_AUTO(void) BackgroundColor(llm::OS::UI::Color const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::UserActivities::UserActivityAttribution) Attribution() const;
        LLM_IMPL_AUTO(void) Attribution(llm::OS::ApplicationModel::UserActivities::UserActivityAttribution const& value) const;
        LLM_IMPL_AUTO(void) Content(llm::OS::UI::Shell::IAdaptiveCard const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Shell::IAdaptiveCard) Content() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::UserActivities::IUserActivityVisualElements>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_UserActivities_IUserActivityVisualElements<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_UserActivities_IUserActivityVisualElements2
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AttributionDisplayText() const;
        LLM_IMPL_AUTO(void) AttributionDisplayText(param::hstring const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::UserActivities::IUserActivityVisualElements2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_UserActivities_IUserActivityVisualElements2<D>;
    };
}
#endif
