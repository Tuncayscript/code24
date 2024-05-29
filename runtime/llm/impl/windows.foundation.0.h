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
#ifndef LLM_OS_Foundation_0_H
#define LLM_OS_Foundation_0_H
LLM_EXPORT namespace llm::OS::Foundation
{
    enum class AsyncStatus : int32_t
    {
        Canceled = 2,
        Completed = 1,
        Error = 3,
        Started = 0,
    };
    enum class PropertyType : int32_t
    {
        Empty = 0,
        UInt8 = 1,
        Int16 = 2,
        UInt16 = 3,
        Int32 = 4,
        UInt32 = 5,
        Int64 = 6,
        UInt64 = 7,
        Single = 8,
        Double = 9,
        Char16 = 10,
        Boolean = 11,
        String = 12,
        Inspectable = 13,
        DateTime = 14,
        TimeSpan = 15,
        Guid = 16,
        Point = 17,
        Size = 18,
        Rect = 19,
        OtherType = 20,
        UInt8Array = 1025,
        Int16Array = 1026,
        UInt16Array = 1027,
        Int32Array = 1028,
        UInt32Array = 1029,
        Int64Array = 1030,
        UInt64Array = 1031,
        SingleArray = 1032,
        DoubleArray = 1033,
        Char16Array = 1034,
        BooleanArray = 1035,
        StringArray = 1036,
        InspectableArray = 1037,
        DateTimeArray = 1038,
        TimeSpanArray = 1039,
        GuidArray = 1040,
        PointArray = 1041,
        SizeArray = 1042,
        RectArray = 1043,
        OtherTypeArray = 1044,
    };
    struct IAsyncAction;
    template <typename TProgress> struct __declspec(empty_bases) IAsyncActionWithProgress;
    struct IAsyncInfo;
    template <typename TResult, typename TProgress> struct __declspec(empty_bases) IAsyncOperationWithProgress;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    struct IClosable;
    struct IDeferral;
    struct IDeferralFactory;
    struct IGetActivationFactory;
    struct IGuidHelperStatics;
    struct IMemoryBuffer;
    struct IMemoryBufferFactory;
    struct IMemoryBufferReference;
    struct IPropertyValue;
    struct IPropertyValueStatics;
    template <typename T> struct __declspec(empty_bases) IReferenceArray;
    template <typename T> struct __declspec(empty_bases) IReference;
    struct IStringable;
    struct IUriEscapeStatics;
    struct IUriRuntimeClass;
    struct IUriRuntimeClassFactory;
    struct IUriRuntimeClassWithAbsoluteCanonicalUri;
    struct IWwwFormUrlDecoderEntry;
    struct IWwwFormUrlDecoderRuntimeClass;
    struct IWwwFormUrlDecoderRuntimeClassFactory;
    struct Deferral;
    struct GuidHelper;
    struct MemoryBuffer;
    struct PropertyValue;
    struct Uri;
    struct WwwFormUrlDecoder;
    struct WwwFormUrlDecoderEntry;
    struct AsyncActionCompletedHandler;
    template <typename TProgress> struct __declspec(empty_bases) AsyncActionProgressHandler;
    template <typename TProgress> struct __declspec(empty_bases) AsyncActionWithProgressCompletedHandler;
    template <typename TResult> struct __declspec(empty_bases) AsyncOperationCompletedHandler;
    template <typename TResult, typename TProgress> struct __declspec(empty_bases) AsyncOperationProgressHandler;
    template <typename TResult, typename TProgress> struct __declspec(empty_bases) AsyncOperationWithProgressCompletedHandler;
    struct DeferralCompletedHandler;
    template <typename T> struct __declspec(empty_bases) EventHandler;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
namespace llm::impl
{
    template <> struct category<llm::OS::Foundation::IAsyncAction>{ using type = interface_category; };
    template <typename TProgress> struct category<llm::OS::Foundation::IAsyncActionWithProgress<TProgress>>{ using type = generic_category<TProgress>; };
    template <> struct category<llm::OS::Foundation::IAsyncInfo>{ using type = interface_category; };
    template <typename TResult, typename TProgress> struct category<llm::OS::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>{ using type = generic_category<TResult, TProgress>; };
    template <typename TResult> struct category<llm::OS::Foundation::IAsyncOperation<TResult>>{ using type = generic_category<TResult>; };
    template <> struct category<llm::OS::Foundation::IClosable>{ using type = interface_category; };
    template <> struct category<llm::OS::Foundation::IDeferral>{ using type = interface_category; };
    template <> struct category<llm::OS::Foundation::IDeferralFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::Foundation::IGetActivationFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::Foundation::IGuidHelperStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Foundation::IMemoryBuffer>{ using type = interface_category; };
    template <> struct category<llm::OS::Foundation::IMemoryBufferFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::Foundation::IMemoryBufferReference>{ using type = interface_category; };
    template <> struct category<llm::OS::Foundation::IPropertyValue>{ using type = interface_category; };
    template <> struct category<llm::OS::Foundation::IPropertyValueStatics>{ using type = interface_category; };
    template <typename T> struct category<llm::OS::Foundation::IReferenceArray<T>>{ using type = generic_category<T>; };
    template <typename T> struct category<llm::OS::Foundation::IReference<T>>{ using type = generic_category<T>; };
    template <> struct category<llm::OS::Foundation::IStringable>{ using type = interface_category; };
    template <> struct category<llm::OS::Foundation::IUriEscapeStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Foundation::IUriRuntimeClass>{ using type = interface_category; };
    template <> struct category<llm::OS::Foundation::IUriRuntimeClassFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::Foundation::IUriRuntimeClassWithAbsoluteCanonicalUri>{ using type = interface_category; };
    template <> struct category<llm::OS::Foundation::IWwwFormUrlDecoderEntry>{ using type = interface_category; };
    template <> struct category<llm::OS::Foundation::IWwwFormUrlDecoderRuntimeClass>{ using type = interface_category; };
    template <> struct category<llm::OS::Foundation::IWwwFormUrlDecoderRuntimeClassFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::Foundation::Deferral>{ using type = class_category; };
    template <> struct category<llm::OS::Foundation::GuidHelper>{ using type = class_category; };
    template <> struct category<llm::OS::Foundation::MemoryBuffer>{ using type = class_category; };
    template <> struct category<llm::OS::Foundation::PropertyValue>{ using type = class_category; };
    template <> struct category<llm::OS::Foundation::Uri>{ using type = class_category; };
    template <> struct category<llm::OS::Foundation::WwwFormUrlDecoder>{ using type = class_category; };
    template <> struct category<llm::OS::Foundation::WwwFormUrlDecoderEntry>{ using type = class_category; };
    template <> struct category<llm::OS::Foundation::AsyncStatus>{ using type = enum_category; };
    template <> struct category<llm::OS::Foundation::PropertyType>{ using type = enum_category; };
    template <> struct category<llm::OS::Foundation::AsyncActionCompletedHandler>{ using type = delegate_category; };
    template <typename TProgress> struct category<llm::OS::Foundation::AsyncActionProgressHandler<TProgress>>{ using type = generic_category<TProgress>; };
    template <typename TProgress> struct category<llm::OS::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>>{ using type = generic_category<TProgress>; };
    template <typename TResult> struct category<llm::OS::Foundation::AsyncOperationCompletedHandler<TResult>>{ using type = generic_category<TResult>; };
    template <typename TResult, typename TProgress> struct category<llm::OS::Foundation::AsyncOperationProgressHandler<TResult, TProgress>>{ using type = generic_category<TResult, TProgress>; };
    template <typename TResult, typename TProgress> struct category<llm::OS::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>>{ using type = generic_category<TResult, TProgress>; };
    template <> struct category<llm::OS::Foundation::DeferralCompletedHandler>{ using type = delegate_category; };
    template <typename T> struct category<llm::OS::Foundation::EventHandler<T>>{ using type = generic_category<T>; };
    template <typename TSender, typename TResult> struct category<llm::OS::Foundation::TypedEventHandler<TSender, TResult>>{ using type = generic_category<TSender, TResult>; };
    template <> inline constexpr auto& name_v<llm::OS::Foundation::Deferral> = L"Windows.Foundation.Deferral";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::GuidHelper> = L"Windows.Foundation.GuidHelper";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::MemoryBuffer> = L"Windows.Foundation.MemoryBuffer";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::PropertyValue> = L"Windows.Foundation.PropertyValue";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::Uri> = L"Windows.Foundation.Uri";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::WwwFormUrlDecoder> = L"Windows.Foundation.WwwFormUrlDecoder";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::WwwFormUrlDecoderEntry> = L"Windows.Foundation.WwwFormUrlDecoderEntry";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::AsyncStatus> = L"Windows.Foundation.AsyncStatus";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::PropertyType> = L"Windows.Foundation.PropertyType";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::IAsyncAction> = L"Windows.Foundation.IAsyncAction";
    template <typename TProgress> inline constexpr auto name_v<llm::OS::Foundation::IAsyncActionWithProgress<TProgress>> = zcombine(L"Windows.Foundation.IAsyncActionWithProgress`1<", name_v<TProgress>, L">");
    template <> inline constexpr auto& name_v<llm::OS::Foundation::IAsyncInfo> = L"Windows.Foundation.IAsyncInfo";
    template <typename TResult, typename TProgress> inline constexpr auto name_v<llm::OS::Foundation::IAsyncOperationWithProgress<TResult, TProgress>> = zcombine(L"Windows.Foundation.IAsyncOperationWithProgress`2<", name_v<TResult>, L", ", name_v<TProgress>, L">");
    template <typename TResult> inline constexpr auto name_v<llm::OS::Foundation::IAsyncOperation<TResult>> = zcombine(L"Windows.Foundation.IAsyncOperation`1<", name_v<TResult>, L">");
    template <> inline constexpr auto& name_v<llm::OS::Foundation::IClosable> = L"Windows.Foundation.IClosable";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::IDeferral> = L"Windows.Foundation.IDeferral";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::IDeferralFactory> = L"Windows.Foundation.IDeferralFactory";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::IGetActivationFactory> = L"Windows.Foundation.IGetActivationFactory";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::IGuidHelperStatics> = L"Windows.Foundation.IGuidHelperStatics";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::IMemoryBuffer> = L"Windows.Foundation.IMemoryBuffer";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::IMemoryBufferFactory> = L"Windows.Foundation.IMemoryBufferFactory";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::IMemoryBufferReference> = L"Windows.Foundation.IMemoryBufferReference";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::IPropertyValue> = L"Windows.Foundation.IPropertyValue";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::IPropertyValueStatics> = L"Windows.Foundation.IPropertyValueStatics";
    template <typename T> inline constexpr auto name_v<llm::OS::Foundation::IReferenceArray<T>> = zcombine(L"Windows.Foundation.IReferenceArray`1<", name_v<T>, L">");
    template <typename T> inline constexpr auto name_v<llm::OS::Foundation::IReference<T>> = zcombine(L"Windows.Foundation.IReference`1<", name_v<T>, L">");
    template <> inline constexpr auto& name_v<llm::OS::Foundation::IStringable> = L"Windows.Foundation.IStringable";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::IUriEscapeStatics> = L"Windows.Foundation.IUriEscapeStatics";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::IUriRuntimeClass> = L"Windows.Foundation.IUriRuntimeClass";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::IUriRuntimeClassFactory> = L"Windows.Foundation.IUriRuntimeClassFactory";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::IUriRuntimeClassWithAbsoluteCanonicalUri> = L"Windows.Foundation.IUriRuntimeClassWithAbsoluteCanonicalUri";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::IWwwFormUrlDecoderEntry> = L"Windows.Foundation.IWwwFormUrlDecoderEntry";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::IWwwFormUrlDecoderRuntimeClass> = L"Windows.Foundation.IWwwFormUrlDecoderRuntimeClass";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::IWwwFormUrlDecoderRuntimeClassFactory> = L"Windows.Foundation.IWwwFormUrlDecoderRuntimeClassFactory";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::AsyncActionCompletedHandler> = L"Windows.Foundation.AsyncActionCompletedHandler";
    template <typename TProgress> inline constexpr auto name_v<llm::OS::Foundation::AsyncActionProgressHandler<TProgress>> = zcombine(L"Windows.Foundation.AsyncActionProgressHandler`1<", name_v<TProgress>, L">");
    template <typename TProgress> inline constexpr auto name_v<llm::OS::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>> = zcombine(L"Windows.Foundation.AsyncActionWithProgressCompletedHandler`1<", name_v<TProgress>, L">");
    template <typename TResult> inline constexpr auto name_v<llm::OS::Foundation::AsyncOperationCompletedHandler<TResult>> = zcombine(L"Windows.Foundation.AsyncOperationCompletedHandler`1<", name_v<TResult>, L">");
    template <typename TResult, typename TProgress> inline constexpr auto name_v<llm::OS::Foundation::AsyncOperationProgressHandler<TResult, TProgress>> = zcombine(L"Windows.Foundation.AsyncOperationProgressHandler`2<", name_v<TResult>, L", ", name_v<TProgress>, L">");
    template <typename TResult, typename TProgress> inline constexpr auto name_v<llm::OS::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>> = zcombine(L"Windows.Foundation.AsyncOperationWithProgressCompletedHandler`2<", name_v<TResult>, L", ", name_v<TProgress>, L">");
    template <> inline constexpr auto& name_v<llm::OS::Foundation::DeferralCompletedHandler> = L"Windows.Foundation.DeferralCompletedHandler";
    template <typename T> inline constexpr auto name_v<llm::OS::Foundation::EventHandler<T>> = zcombine(L"Windows.Foundation.EventHandler`1<", name_v<T>, L">");
    template <typename TSender, typename TResult> inline constexpr auto name_v<llm::OS::Foundation::TypedEventHandler<TSender, TResult>> = zcombine(L"Windows.Foundation.TypedEventHandler`2<", name_v<TSender>, L", ", name_v<TResult>, L">");
    template <> inline constexpr guid guid_v<llm::OS::Foundation::IAsyncAction>{ 0x5A648006,0x843A,0x4DA9,{ 0x86,0x5B,0x9D,0x26,0xE5,0xDF,0xAD,0x7B } }; // 5A648006-843A-4DA9-865B-9D26E5DFAD7B
    template <typename TProgress> inline constexpr guid guid_v<llm::OS::Foundation::IAsyncActionWithProgress<TProgress>>{ pinterface_guid<llm::OS::Foundation::IAsyncActionWithProgress<TProgress>>::value };
    template <typename TProgress> inline constexpr guid generic_guid_v<llm::OS::Foundation::IAsyncActionWithProgress<TProgress>>{ 0x1F6DB258,0xE803,0x48A1,{ 0x95,0x46,0xEB,0x73,0x53,0x39,0x88,0x84 } }; // 1F6DB258-E803-48A1-9546-EB7353398884
    template <> inline constexpr guid guid_v<llm::OS::Foundation::IAsyncInfo>{ 0x00000036,0x0000,0x0000,{ 0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46 } }; // 00000036-0000-0000-C000-000000000046
    template <typename TResult, typename TProgress> inline constexpr guid guid_v<llm::OS::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>{ pinterface_guid<llm::OS::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>::value };
    template <typename TResult, typename TProgress> inline constexpr guid generic_guid_v<llm::OS::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>{ 0xB5D036D7,0xE297,0x498F,{ 0xBA,0x60,0x02,0x89,0xE7,0x6E,0x23,0xDD } }; // B5D036D7-E297-498F-BA60-0289E76E23DD
    template <typename TResult> inline constexpr guid guid_v<llm::OS::Foundation::IAsyncOperation<TResult>>{ pinterface_guid<llm::OS::Foundation::IAsyncOperation<TResult>>::value };
    template <typename TResult> inline constexpr guid generic_guid_v<llm::OS::Foundation::IAsyncOperation<TResult>>{ 0x9FC2B0BB,0xE446,0x44E2,{ 0xAA,0x61,0x9C,0xAB,0x8F,0x63,0x6A,0xF2 } }; // 9FC2B0BB-E446-44E2-AA61-9CAB8F636AF2
    template <> inline constexpr guid guid_v<llm::OS::Foundation::IClosable>{ 0x30D5A829,0x7FA4,0x4026,{ 0x83,0xBB,0xD7,0x5B,0xAE,0x4E,0xA9,0x9E } }; // 30D5A829-7FA4-4026-83BB-D75BAE4EA99E
    template <> inline constexpr guid guid_v<llm::OS::Foundation::IDeferral>{ 0xD6269732,0x3B7F,0x46A7,{ 0xB4,0x0B,0x4F,0xDC,0xA2,0xA2,0xC6,0x93 } }; // D6269732-3B7F-46A7-B40B-4FDCA2A2C693
    template <> inline constexpr guid guid_v<llm::OS::Foundation::IDeferralFactory>{ 0x65A1ECC5,0x3FB5,0x4832,{ 0x8C,0xA9,0xF0,0x61,0xB2,0x81,0xD1,0x3A } }; // 65A1ECC5-3FB5-4832-8CA9-F061B281D13A
    template <> inline constexpr guid guid_v<llm::OS::Foundation::IGetActivationFactory>{ 0x4EDB8EE2,0x96DD,0x49A7,{ 0x94,0xF7,0x46,0x07,0xDD,0xAB,0x8E,0x3C } }; // 4EDB8EE2-96DD-49A7-94F7-4607DDAB8E3C
    template <> inline constexpr guid guid_v<llm::OS::Foundation::IGuidHelperStatics>{ 0x59C7966B,0xAE52,0x5283,{ 0xAD,0x7F,0xA1,0xB9,0xE9,0x67,0x8A,0xDD } }; // 59C7966B-AE52-5283-AD7F-A1B9E9678ADD
    template <> inline constexpr guid guid_v<llm::OS::Foundation::IMemoryBuffer>{ 0xFBC4DD2A,0x245B,0x11E4,{ 0xAF,0x98,0x68,0x94,0x23,0x26,0x0C,0xF8 } }; // FBC4DD2A-245B-11E4-AF98-689423260CF8
    template <> inline constexpr guid guid_v<llm::OS::Foundation::IMemoryBufferFactory>{ 0xFBC4DD2B,0x245B,0x11E4,{ 0xAF,0x98,0x68,0x94,0x23,0x26,0x0C,0xF8 } }; // FBC4DD2B-245B-11E4-AF98-689423260CF8
    template <> inline constexpr guid guid_v<llm::OS::Foundation::IMemoryBufferReference>{ 0xFBC4DD29,0x245B,0x11E4,{ 0xAF,0x98,0x68,0x94,0x23,0x26,0x0C,0xF8 } }; // FBC4DD29-245B-11E4-AF98-689423260CF8
    template <> inline constexpr guid guid_v<llm::OS::Foundation::IPropertyValue>{ 0x4BD682DD,0x7554,0x40E9,{ 0x9A,0x9B,0x82,0x65,0x4E,0xDE,0x7E,0x62 } }; // 4BD682DD-7554-40E9-9A9B-82654EDE7E62
    template <> inline constexpr guid guid_v<llm::OS::Foundation::IPropertyValueStatics>{ 0x629BDBC8,0xD932,0x4FF4,{ 0x96,0xB9,0x8D,0x96,0xC5,0xC1,0xE8,0x58 } }; // 629BDBC8-D932-4FF4-96B9-8D96C5C1E858
    template <typename T> inline constexpr guid guid_v<llm::OS::Foundation::IReferenceArray<T>>{ pinterface_guid<llm::OS::Foundation::IReferenceArray<T>>::value };
    template <typename T> inline constexpr guid generic_guid_v<llm::OS::Foundation::IReferenceArray<T>>{ 0x61C17707,0x2D65,0x11E0,{ 0x9A,0xE8,0xD4,0x85,0x64,0x01,0x54,0x72 } }; // 61C17707-2D65-11E0-9AE8-D48564015472
    template <typename T> inline constexpr guid guid_v<llm::OS::Foundation::IReference<T>>{ pinterface_guid<llm::OS::Foundation::IReference<T>>::value };
    template <typename T> inline constexpr guid generic_guid_v<llm::OS::Foundation::IReference<T>>{ 0x61C17706,0x2D65,0x11E0,{ 0x9A,0xE8,0xD4,0x85,0x64,0x01,0x54,0x72 } }; // 61C17706-2D65-11E0-9AE8-D48564015472
    template <> inline constexpr guid guid_v<llm::OS::Foundation::IStringable>{ 0x96369F54,0x8EB6,0x48F0,{ 0xAB,0xCE,0xC1,0xB2,0x11,0xE6,0x27,0xC3 } }; // 96369F54-8EB6-48F0-ABCE-C1B211E627C3
    template <> inline constexpr guid guid_v<llm::OS::Foundation::IUriEscapeStatics>{ 0xC1D432BA,0xC824,0x4452,{ 0xA7,0xFD,0x51,0x2B,0xC3,0xBB,0xE9,0xA1 } }; // C1D432BA-C824-4452-A7FD-512BC3BBE9A1
    template <> inline constexpr guid guid_v<llm::OS::Foundation::IUriRuntimeClass>{ 0x9E365E57,0x48B2,0x4160,{ 0x95,0x6F,0xC7,0x38,0x51,0x20,0xBB,0xFC } }; // 9E365E57-48B2-4160-956F-C7385120BBFC
    template <> inline constexpr guid guid_v<llm::OS::Foundation::IUriRuntimeClassFactory>{ 0x44A9796F,0x723E,0x4FDF,{ 0xA2,0x18,0x03,0x3E,0x75,0xB0,0xC0,0x84 } }; // 44A9796F-723E-4FDF-A218-033E75B0C084
    template <> inline constexpr guid guid_v<llm::OS::Foundation::IUriRuntimeClassWithAbsoluteCanonicalUri>{ 0x758D9661,0x221C,0x480F,{ 0xA3,0x39,0x50,0x65,0x66,0x73,0xF4,0x6F } }; // 758D9661-221C-480F-A339-50656673F46F
    template <> inline constexpr guid guid_v<llm::OS::Foundation::IWwwFormUrlDecoderEntry>{ 0x125E7431,0xF678,0x4E8E,{ 0xB6,0x70,0x20,0xA9,0xB0,0x6C,0x51,0x2D } }; // 125E7431-F678-4E8E-B670-20A9B06C512D
    template <> inline constexpr guid guid_v<llm::OS::Foundation::IWwwFormUrlDecoderRuntimeClass>{ 0xD45A0451,0xF225,0x4542,{ 0x92,0x96,0x0E,0x1D,0xF5,0xD2,0x54,0xDF } }; // D45A0451-F225-4542-9296-0E1DF5D254DF
    template <> inline constexpr guid guid_v<llm::OS::Foundation::IWwwFormUrlDecoderRuntimeClassFactory>{ 0x5B8C6B3D,0x24AE,0x41B5,{ 0xA1,0xBF,0xF0,0xC3,0xD5,0x44,0x84,0x5B } }; // 5B8C6B3D-24AE-41B5-A1BF-F0C3D544845B
    template <> inline constexpr guid guid_v<llm::OS::Foundation::AsyncActionCompletedHandler>{ 0xA4ED5C81,0x76C9,0x40BD,{ 0x8B,0xE6,0xB1,0xD9,0x0F,0xB2,0x0A,0xE7 } }; // A4ED5C81-76C9-40BD-8BE6-B1D90FB20AE7
    template <typename TProgress> inline constexpr guid guid_v<llm::OS::Foundation::AsyncActionProgressHandler<TProgress>>{ pinterface_guid<llm::OS::Foundation::AsyncActionProgressHandler<TProgress>>::value };
    template <typename TProgress> inline constexpr guid generic_guid_v<llm::OS::Foundation::AsyncActionProgressHandler<TProgress>>{ 0x6D844858,0x0CFF,0x4590,{ 0xAE,0x89,0x95,0xA5,0xA5,0xC8,0xB4,0xB8 } }; // 6D844858-0CFF-4590-AE89-95A5A5C8B4B8
    template <typename TProgress> inline constexpr guid guid_v<llm::OS::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>>{ pinterface_guid<llm::OS::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>>::value };
    template <typename TProgress> inline constexpr guid generic_guid_v<llm::OS::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>>{ 0x9C029F91,0xCC84,0x44FD,{ 0xAC,0x26,0x0A,0x6C,0x4E,0x55,0x52,0x81 } }; // 9C029F91-CC84-44FD-AC26-0A6C4E555281
    template <typename TResult> inline constexpr guid guid_v<llm::OS::Foundation::AsyncOperationCompletedHandler<TResult>>{ pinterface_guid<llm::OS::Foundation::AsyncOperationCompletedHandler<TResult>>::value };
    template <typename TResult> inline constexpr guid generic_guid_v<llm::OS::Foundation::AsyncOperationCompletedHandler<TResult>>{ 0xFCDCF02C,0xE5D8,0x4478,{ 0x91,0x5A,0x4D,0x90,0xB7,0x4B,0x83,0xA5 } }; // FCDCF02C-E5D8-4478-915A-4D90B74B83A5
    template <typename TResult, typename TProgress> inline constexpr guid guid_v<llm::OS::Foundation::AsyncOperationProgressHandler<TResult, TProgress>>{ pinterface_guid<llm::OS::Foundation::AsyncOperationProgressHandler<TResult, TProgress>>::value };
    template <typename TResult, typename TProgress> inline constexpr guid generic_guid_v<llm::OS::Foundation::AsyncOperationProgressHandler<TResult, TProgress>>{ 0x55690902,0x0AAB,0x421A,{ 0x87,0x78,0xF8,0xCE,0x50,0x26,0xD7,0x58 } }; // 55690902-0AAB-421A-8778-F8CE5026D758
    template <typename TResult, typename TProgress> inline constexpr guid guid_v<llm::OS::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>>{ pinterface_guid<llm::OS::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>>::value };
    template <typename TResult, typename TProgress> inline constexpr guid generic_guid_v<llm::OS::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>>{ 0xE85DF41D,0x6AA7,0x46E3,{ 0xA8,0xE2,0xF0,0x09,0xD8,0x40,0xC6,0x27 } }; // E85DF41D-6AA7-46E3-A8E2-F009D840C627
    template <> inline constexpr guid guid_v<llm::OS::Foundation::DeferralCompletedHandler>{ 0xED32A372,0xF3C8,0x4FAA,{ 0x9C,0xFB,0x47,0x01,0x48,0xDA,0x38,0x88 } }; // ED32A372-F3C8-4FAA-9CFB-470148DA3888
    template <typename T> inline constexpr guid guid_v<llm::OS::Foundation::EventHandler<T>>{ pinterface_guid<llm::OS::Foundation::EventHandler<T>>::value };
    template <typename T> inline constexpr guid generic_guid_v<llm::OS::Foundation::EventHandler<T>>{ 0x9DE1C535,0x6AE1,0x11E0,{ 0x84,0xE1,0x18,0xA9,0x05,0xBC,0xC5,0x3F } }; // 9DE1C535-6AE1-11E0-84E1-18A905BCC53F
    template <typename TSender, typename TResult> inline constexpr guid guid_v<llm::OS::Foundation::TypedEventHandler<TSender, TResult>>{ pinterface_guid<llm::OS::Foundation::TypedEventHandler<TSender, TResult>>::value };
    template <typename TSender, typename TResult> inline constexpr guid generic_guid_v<llm::OS::Foundation::TypedEventHandler<TSender, TResult>>{ 0x9DE1C534,0x6AE1,0x11E0,{ 0x84,0xE1,0x18,0xA9,0x05,0xBC,0xC5,0x3F } }; // 9DE1C534-6AE1-11E0-84E1-18A905BCC53F
    template <> struct default_interface<llm::OS::Foundation::Deferral>{ using type = llm::OS::Foundation::IDeferral; };
    template <> struct default_interface<llm::OS::Foundation::MemoryBuffer>{ using type = llm::OS::Foundation::IMemoryBuffer; };
    template <> struct default_interface<llm::OS::Foundation::Uri>{ using type = llm::OS::Foundation::IUriRuntimeClass; };
    template <> struct default_interface<llm::OS::Foundation::WwwFormUrlDecoder>{ using type = llm::OS::Foundation::IWwwFormUrlDecoderRuntimeClass; };
    template <> struct default_interface<llm::OS::Foundation::WwwFormUrlDecoderEntry>{ using type = llm::OS::Foundation::IWwwFormUrlDecoderEntry; };
    template <> struct abi<llm::OS::Foundation::IAsyncAction>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall put_Completed(void*) noexcept = 0;
            virtual int32_t __stdcall get_Completed(void**) noexcept = 0;
            virtual int32_t __stdcall GetResults() noexcept = 0;
        };
    };
    template <typename TProgress> struct abi<llm::OS::Foundation::IAsyncActionWithProgress<TProgress>>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall put_Progress(void*) noexcept = 0;
            virtual int32_t __stdcall get_Progress(void**) noexcept = 0;
            virtual int32_t __stdcall put_Completed(void*) noexcept = 0;
            virtual int32_t __stdcall get_Completed(void**) noexcept = 0;
            virtual int32_t __stdcall GetResults() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Foundation::IAsyncInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Id(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ErrorCode(llm::hresult*) noexcept = 0;
            virtual int32_t __stdcall Cancel() noexcept = 0;
            virtual int32_t __stdcall Close() noexcept = 0;
        };
    };
    template <typename TResult, typename TProgress> struct abi<llm::OS::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall put_Progress(void*) noexcept = 0;
            virtual int32_t __stdcall get_Progress(void**) noexcept = 0;
            virtual int32_t __stdcall put_Completed(void*) noexcept = 0;
            virtual int32_t __stdcall get_Completed(void**) noexcept = 0;
            virtual int32_t __stdcall GetResults(arg_out<TResult>) noexcept = 0;
        };
    };
    template <typename TResult> struct abi<llm::OS::Foundation::IAsyncOperation<TResult>>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall put_Completed(void*) noexcept = 0;
            virtual int32_t __stdcall get_Completed(void**) noexcept = 0;
            virtual int32_t __stdcall GetResults(arg_out<TResult>) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Foundation::IClosable>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Close() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Foundation::IDeferral>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Complete() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Foundation::IDeferralFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Foundation::IGetActivationFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetActivationFactory(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Foundation::IGuidHelperStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateNewGuid(llm::guid*) noexcept = 0;
            virtual int32_t __stdcall get_Empty(llm::guid*) noexcept = 0;
            virtual int32_t __stdcall Equals(llm::guid const&, llm::guid const&, bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Foundation::IMemoryBuffer>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateReference(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Foundation::IMemoryBufferFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(uint32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Foundation::IMemoryBufferReference>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Capacity(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall add_Closed(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Closed(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Foundation::IPropertyValue>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Type(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_IsNumericScalar(bool*) noexcept = 0;
            virtual int32_t __stdcall GetUInt8(uint8_t*) noexcept = 0;
            virtual int32_t __stdcall GetInt16(int16_t*) noexcept = 0;
            virtual int32_t __stdcall GetUInt16(uint16_t*) noexcept = 0;
            virtual int32_t __stdcall GetInt32(int32_t*) noexcept = 0;
            virtual int32_t __stdcall GetUInt32(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall GetInt64(int64_t*) noexcept = 0;
            virtual int32_t __stdcall GetUInt64(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall GetSingle(float*) noexcept = 0;
            virtual int32_t __stdcall GetDouble(double*) noexcept = 0;
            virtual int32_t __stdcall GetChar16(char16_t*) noexcept = 0;
            virtual int32_t __stdcall GetBoolean(bool*) noexcept = 0;
            virtual int32_t __stdcall GetString(void**) noexcept = 0;
            virtual int32_t __stdcall GetGuid(llm::guid*) noexcept = 0;
            virtual int32_t __stdcall GetDateTime(int64_t*) noexcept = 0;
            virtual int32_t __stdcall GetTimeSpan(int64_t*) noexcept = 0;
            virtual int32_t __stdcall GetPoint(llm::OS::Foundation::Point*) noexcept = 0;
            virtual int32_t __stdcall GetSize(llm::OS::Foundation::Size*) noexcept = 0;
            virtual int32_t __stdcall GetRect(llm::OS::Foundation::Rect*) noexcept = 0;
            virtual int32_t __stdcall GetUInt8Array(uint32_t*, uint8_t**) noexcept = 0;
            virtual int32_t __stdcall GetInt16Array(uint32_t*, int16_t**) noexcept = 0;
            virtual int32_t __stdcall GetUInt16Array(uint32_t*, uint16_t**) noexcept = 0;
            virtual int32_t __stdcall GetInt32Array(uint32_t*, int32_t**) noexcept = 0;
            virtual int32_t __stdcall GetUInt32Array(uint32_t*, uint32_t**) noexcept = 0;
            virtual int32_t __stdcall GetInt64Array(uint32_t*, int64_t**) noexcept = 0;
            virtual int32_t __stdcall GetUInt64Array(uint32_t*, uint64_t**) noexcept = 0;
            virtual int32_t __stdcall GetSingleArray(uint32_t*, float**) noexcept = 0;
            virtual int32_t __stdcall GetDoubleArray(uint32_t*, double**) noexcept = 0;
            virtual int32_t __stdcall GetChar16Array(uint32_t*, char16_t**) noexcept = 0;
            virtual int32_t __stdcall GetBooleanArray(uint32_t*, bool**) noexcept = 0;
            virtual int32_t __stdcall GetStringArray(uint32_t*, void***) noexcept = 0;
            virtual int32_t __stdcall GetInspectableArray(uint32_t*, void***) noexcept = 0;
            virtual int32_t __stdcall GetGuidArray(uint32_t*, llm::guid**) noexcept = 0;
            virtual int32_t __stdcall GetDateTimeArray(uint32_t*, int64_t**) noexcept = 0;
            virtual int32_t __stdcall GetTimeSpanArray(uint32_t*, int64_t**) noexcept = 0;
            virtual int32_t __stdcall GetPointArray(uint32_t*, llm::OS::Foundation::Point**) noexcept = 0;
            virtual int32_t __stdcall GetSizeArray(uint32_t*, llm::OS::Foundation::Size**) noexcept = 0;
            virtual int32_t __stdcall GetRectArray(uint32_t*, llm::OS::Foundation::Rect**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Foundation::IPropertyValueStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateEmpty(void**) noexcept = 0;
            virtual int32_t __stdcall CreateUInt8(uint8_t, void**) noexcept = 0;
            virtual int32_t __stdcall CreateInt16(int16_t, void**) noexcept = 0;
            virtual int32_t __stdcall CreateUInt16(uint16_t, void**) noexcept = 0;
            virtual int32_t __stdcall CreateInt32(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall CreateUInt32(uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall CreateInt64(int64_t, void**) noexcept = 0;
            virtual int32_t __stdcall CreateUInt64(uint64_t, void**) noexcept = 0;
            virtual int32_t __stdcall CreateSingle(float, void**) noexcept = 0;
            virtual int32_t __stdcall CreateDouble(double, void**) noexcept = 0;
            virtual int32_t __stdcall CreateChar16(char16_t, void**) noexcept = 0;
            virtual int32_t __stdcall CreateBoolean(bool, void**) noexcept = 0;
            virtual int32_t __stdcall CreateString(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateInspectable(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateGuid(llm::guid, void**) noexcept = 0;
            virtual int32_t __stdcall CreateDateTime(int64_t, void**) noexcept = 0;
            virtual int32_t __stdcall CreateTimeSpan(int64_t, void**) noexcept = 0;
            virtual int32_t __stdcall CreatePoint(llm::OS::Foundation::Point, void**) noexcept = 0;
            virtual int32_t __stdcall CreateSize(llm::OS::Foundation::Size, void**) noexcept = 0;
            virtual int32_t __stdcall CreateRect(llm::OS::Foundation::Rect, void**) noexcept = 0;
            virtual int32_t __stdcall CreateUInt8Array(uint32_t, uint8_t*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateInt16Array(uint32_t, int16_t*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateUInt16Array(uint32_t, uint16_t*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateInt32Array(uint32_t, int32_t*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateUInt32Array(uint32_t, uint32_t*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateInt64Array(uint32_t, int64_t*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateUInt64Array(uint32_t, uint64_t*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateSingleArray(uint32_t, float*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateDoubleArray(uint32_t, double*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateChar16Array(uint32_t, char16_t*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateBooleanArray(uint32_t, bool*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateStringArray(uint32_t, void**, void**) noexcept = 0;
            virtual int32_t __stdcall CreateInspectableArray(uint32_t, void**, void**) noexcept = 0;
            virtual int32_t __stdcall CreateGuidArray(uint32_t, llm::guid*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateDateTimeArray(uint32_t, int64_t*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateTimeSpanArray(uint32_t, int64_t*, void**) noexcept = 0;
            virtual int32_t __stdcall CreatePointArray(uint32_t, llm::OS::Foundation::Point*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateSizeArray(uint32_t, llm::OS::Foundation::Size*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateRectArray(uint32_t, llm::OS::Foundation::Rect*, void**) noexcept = 0;
        };
    };
    template <typename T> struct abi<llm::OS::Foundation::IReferenceArray<T>>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Value(uint32_t* __llm_impl_resultSize, T**) noexcept = 0;
        };
    };
    template <typename T> struct abi<llm::OS::Foundation::IReference<T>>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Value(arg_out<T>) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Foundation::IStringable>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall ToString(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Foundation::IUriEscapeStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall UnescapeComponent(void*, void**) noexcept = 0;
            virtual int32_t __stdcall EscapeComponent(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Foundation::IUriRuntimeClass>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AbsoluteUri(void**) noexcept = 0;
            virtual int32_t __stdcall get_DisplayUri(void**) noexcept = 0;
            virtual int32_t __stdcall get_Domain(void**) noexcept = 0;
            virtual int32_t __stdcall get_Extension(void**) noexcept = 0;
            virtual int32_t __stdcall get_Fragment(void**) noexcept = 0;
            virtual int32_t __stdcall get_Host(void**) noexcept = 0;
            virtual int32_t __stdcall get_Password(void**) noexcept = 0;
            virtual int32_t __stdcall get_Path(void**) noexcept = 0;
            virtual int32_t __stdcall get_Query(void**) noexcept = 0;
            virtual int32_t __stdcall get_QueryParsed(void**) noexcept = 0;
            virtual int32_t __stdcall get_RawUri(void**) noexcept = 0;
            virtual int32_t __stdcall get_SchemeName(void**) noexcept = 0;
            virtual int32_t __stdcall get_UserName(void**) noexcept = 0;
            virtual int32_t __stdcall get_Port(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Suspicious(bool*) noexcept = 0;
            virtual int32_t __stdcall Equals(void*, bool*) noexcept = 0;
            virtual int32_t __stdcall CombineUri(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Foundation::IUriRuntimeClassFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateUri(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateWithRelativeUri(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Foundation::IUriRuntimeClassWithAbsoluteCanonicalUri>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AbsoluteCanonicalUri(void**) noexcept = 0;
            virtual int32_t __stdcall get_DisplayIri(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Foundation::IWwwFormUrlDecoderEntry>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall get_Value(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Foundation::IWwwFormUrlDecoderRuntimeClass>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetFirstValueByName(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Foundation::IWwwFormUrlDecoderRuntimeClassFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateWwwFormUrlDecoder(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Foundation::AsyncActionCompletedHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, int32_t) noexcept = 0;
        };
    };
    template <typename TProgress> struct abi<llm::OS::Foundation::AsyncActionProgressHandler<TProgress>>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, arg_in<TProgress>) noexcept = 0;
        };
    };
    template <typename TProgress> struct abi<llm::OS::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, int32_t) noexcept = 0;
        };
    };
    template <typename TResult> struct abi<llm::OS::Foundation::AsyncOperationCompletedHandler<TResult>>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, int32_t) noexcept = 0;
        };
    };
    template <typename TResult, typename TProgress> struct abi<llm::OS::Foundation::AsyncOperationProgressHandler<TResult, TProgress>>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, arg_in<TProgress>) noexcept = 0;
        };
    };
    template <typename TResult, typename TProgress> struct abi<llm::OS::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Foundation::DeferralCompletedHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke() noexcept = 0;
        };
    };
    template <typename T> struct abi<llm::OS::Foundation::EventHandler<T>>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, arg_in<T>) noexcept = 0;
        };
    };
    template <typename TSender, typename TResult> struct abi<llm::OS::Foundation::TypedEventHandler<TSender, TResult>>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(arg_in<TSender>, arg_in<TResult>) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Foundation_IAsyncAction
    {
        LLM_IMPL_AUTO(void) Completed(llm::OS::Foundation::AsyncActionCompletedHandler const& handler) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::AsyncActionCompletedHandler) Completed() const;
        LLM_IMPL_AUTO(void) GetResults() const;
        auto get() const;
        auto wait_for(Windows::Foundation::TimeSpan const& timeout) const;
    };
    template <> struct consume<llm::OS::Foundation::IAsyncAction>
    {
        template <typename D> using type = consume_Windows_Foundation_IAsyncAction<D>;
    };
    template <typename D, typename TProgress>
    struct consume_Windows_Foundation_IAsyncActionWithProgress
    {
        LLM_IMPL_AUTO(void) Progress(llm::OS::Foundation::AsyncActionProgressHandler<TProgress> const& handler) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::AsyncActionProgressHandler<TProgress>) Progress() const;
        LLM_IMPL_AUTO(void) Completed(llm::OS::Foundation::AsyncActionWithProgressCompletedHandler<TProgress> const& handler) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>) Completed() const;
        LLM_IMPL_AUTO(void) GetResults() const;
        auto get() const;
        auto wait_for(Windows::Foundation::TimeSpan const& timeout) const;
    };
    template <typename TProgress> struct consume<llm::OS::Foundation::IAsyncActionWithProgress<TProgress>>
    {
        template <typename D> using type = consume_Windows_Foundation_IAsyncActionWithProgress<D, TProgress>;
    };
    template <typename D>
    struct consume_Windows_Foundation_IAsyncInfo
    {
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) Id() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::AsyncStatus) Status() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) ErrorCode() const;
        LLM_IMPL_AUTO(void) Cancel() const;
        LLM_IMPL_AUTO(void) Close() const;
    };
    template <> struct consume<llm::OS::Foundation::IAsyncInfo>
    {
        template <typename D> using type = consume_Windows_Foundation_IAsyncInfo<D>;
    };
    template <typename D, typename TResult, typename TProgress>
    struct consume_Windows_Foundation_IAsyncOperationWithProgress
    {
        LLM_IMPL_AUTO(void) Progress(llm::OS::Foundation::AsyncOperationProgressHandler<TResult, TProgress> const& handler) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::AsyncOperationProgressHandler<TResult, TProgress>) Progress() const;
        LLM_IMPL_AUTO(void) Completed(llm::OS::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress> const& handler) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>) Completed() const;
        LLM_IMPL_AUTO(TResult) GetResults() const;
        auto get() const;
        auto wait_for(Windows::Foundation::TimeSpan const& timeout) const;
    };
    template <typename TResult, typename TProgress> struct consume<llm::OS::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>
    {
        template <typename D> using type = consume_Windows_Foundation_IAsyncOperationWithProgress<D, TResult, TProgress>;
    };
    template <typename D, typename TResult>
    struct consume_Windows_Foundation_IAsyncOperation
    {
        LLM_IMPL_AUTO(void) Completed(llm::OS::Foundation::AsyncOperationCompletedHandler<TResult> const& handler) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::AsyncOperationCompletedHandler<TResult>) Completed() const;
        LLM_IMPL_AUTO(TResult) GetResults() const;
        auto get() const;
        auto wait_for(Windows::Foundation::TimeSpan const& timeout) const;
    };
    template <typename TResult> struct consume<llm::OS::Foundation::IAsyncOperation<TResult>>
    {
        template <typename D> using type = consume_Windows_Foundation_IAsyncOperation<D, TResult>;
    };
    template <typename D>
    struct consume_Windows_Foundation_IClosable
    {
        LLM_IMPL_AUTO(void) Close() const;
    };
    template <> struct consume<llm::OS::Foundation::IClosable>
    {
        template <typename D> using type = consume_Windows_Foundation_IClosable<D>;
    };
    template <typename D>
    struct consume_Windows_Foundation_IDeferral
    {
        LLM_IMPL_AUTO(void) Complete() const;
    };
    template <> struct consume<llm::OS::Foundation::IDeferral>
    {
        template <typename D> using type = consume_Windows_Foundation_IDeferral<D>;
    };
    template <typename D>
    struct consume_Windows_Foundation_IDeferralFactory
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) Create(llm::OS::Foundation::DeferralCompletedHandler const& handler) const;
    };
    template <> struct consume<llm::OS::Foundation::IDeferralFactory>
    {
        template <typename D> using type = consume_Windows_Foundation_IDeferralFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Foundation_IGetActivationFactory
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) GetActivationFactory(param::hstring const& activatableClassId) const;
    };
    template <> struct consume<llm::OS::Foundation::IGetActivationFactory>
    {
        template <typename D> using type = consume_Windows_Foundation_IGetActivationFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Foundation_IGuidHelperStatics
    {
        LLM_IMPL_AUTO(llm::guid) CreateNewGuid() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::guid) Empty() const;
        LLM_IMPL_AUTO(bool) Equals(llm::guid const& target, llm::guid const& value) const;
    };
    template <> struct consume<llm::OS::Foundation::IGuidHelperStatics>
    {
        template <typename D> using type = consume_Windows_Foundation_IGuidHelperStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Foundation_IMemoryBuffer
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IMemoryBufferReference) CreateReference() const;
    };
    template <> struct consume<llm::OS::Foundation::IMemoryBuffer>
    {
        template <typename D> using type = consume_Windows_Foundation_IMemoryBuffer<D>;
    };
    template <typename D>
    struct consume_Windows_Foundation_IMemoryBufferFactory
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::MemoryBuffer) Create(uint32_t capacity) const;
    };
    template <> struct consume<llm::OS::Foundation::IMemoryBufferFactory>
    {
        template <typename D> using type = consume_Windows_Foundation_IMemoryBufferFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Foundation_IMemoryBufferReference
    {
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) Capacity() const;
        LLM_IMPL_AUTO(llm::event_token) Closed(llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IMemoryBufferReference, llm::OS::Foundation::IInspectable> const& handler) const;
        using Closed_revoker = impl::event_revoker<llm::OS::Foundation::IMemoryBufferReference, &impl::abi_t<llm::OS::Foundation::IMemoryBufferReference>::remove_Closed>;
        [[nodiscard]] Closed_revoker Closed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IMemoryBufferReference, llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) Closed(llm::event_token const& cookie) const noexcept;

        auto data() const
        {
            uint8_t* data{};
            uint32_t capacity{};
            check_hresult(static_cast<D const&>(*this).template as<IMemoryBufferByteAccess>()->GetBuffer(&data, &capacity));
            return data;
        }
    };
    template <> struct consume<llm::OS::Foundation::IMemoryBufferReference>
    {
        template <typename D> using type = consume_Windows_Foundation_IMemoryBufferReference<D>;
    };
    template <typename D>
    struct consume_Windows_Foundation_IPropertyValue
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::PropertyType) Type() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsNumericScalar() const;
        LLM_IMPL_AUTO(uint8_t) GetUInt8() const;
        LLM_IMPL_AUTO(int16_t) GetInt16() const;
        LLM_IMPL_AUTO(uint16_t) GetUInt16() const;
        LLM_IMPL_AUTO(int32_t) GetInt32() const;
        LLM_IMPL_AUTO(uint32_t) GetUInt32() const;
        LLM_IMPL_AUTO(int64_t) GetInt64() const;
        LLM_IMPL_AUTO(uint64_t) GetUInt64() const;
        LLM_IMPL_AUTO(float) GetSingle() const;
        LLM_IMPL_AUTO(double) GetDouble() const;
        LLM_IMPL_AUTO(char16_t) GetChar16() const;
        LLM_IMPL_AUTO(bool) GetBoolean() const;
        LLM_IMPL_AUTO(hstring) GetString() const;
        LLM_IMPL_AUTO(llm::guid) GetGuid() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) GetDateTime() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) GetTimeSpan() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Point) GetPoint() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Size) GetSize() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Rect) GetRect() const;
        LLM_IMPL_AUTO(void) GetUInt8Array(com_array<uint8_t>& value) const;
        LLM_IMPL_AUTO(void) GetInt16Array(com_array<int16_t>& value) const;
        LLM_IMPL_AUTO(void) GetUInt16Array(com_array<uint16_t>& value) const;
        LLM_IMPL_AUTO(void) GetInt32Array(com_array<int32_t>& value) const;
        LLM_IMPL_AUTO(void) GetUInt32Array(com_array<uint32_t>& value) const;
        LLM_IMPL_AUTO(void) GetInt64Array(com_array<int64_t>& value) const;
        LLM_IMPL_AUTO(void) GetUInt64Array(com_array<uint64_t>& value) const;
        LLM_IMPL_AUTO(void) GetSingleArray(com_array<float>& value) const;
        LLM_IMPL_AUTO(void) GetDoubleArray(com_array<double>& value) const;
        LLM_IMPL_AUTO(void) GetChar16Array(com_array<char16_t>& value) const;
        LLM_IMPL_AUTO(void) GetBooleanArray(com_array<bool>& value) const;
        LLM_IMPL_AUTO(void) GetStringArray(com_array<hstring>& value) const;
        LLM_IMPL_AUTO(void) GetInspectableArray(com_array<llm::OS::Foundation::IInspectable>& value) const;
        LLM_IMPL_AUTO(void) GetGuidArray(com_array<llm::guid>& value) const;
        LLM_IMPL_AUTO(void) GetDateTimeArray(com_array<llm::OS::Foundation::DateTime>& value) const;
        LLM_IMPL_AUTO(void) GetTimeSpanArray(com_array<llm::OS::Foundation::TimeSpan>& value) const;
        LLM_IMPL_AUTO(void) GetPointArray(com_array<llm::OS::Foundation::Point>& value) const;
        LLM_IMPL_AUTO(void) GetSizeArray(com_array<llm::OS::Foundation::Size>& value) const;
        LLM_IMPL_AUTO(void) GetRectArray(com_array<llm::OS::Foundation::Rect>& value) const;
    };
    template <> struct consume<llm::OS::Foundation::IPropertyValue>
    {
        template <typename D> using type = consume_Windows_Foundation_IPropertyValue<D>;
    };
    template <typename D>
    struct consume_Windows_Foundation_IPropertyValueStatics
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateEmpty() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateUInt8(uint8_t value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateInt16(int16_t value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateUInt16(uint16_t value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateInt32(int32_t value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateUInt32(uint32_t value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateInt64(int64_t value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateUInt64(uint64_t value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateSingle(float value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateDouble(double value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateChar16(char16_t value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateBoolean(bool value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateString(param::hstring const& value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateInspectable(llm::OS::Foundation::IInspectable const& value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateGuid(llm::guid const& value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateDateTime(llm::OS::Foundation::DateTime const& value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateTimeSpan(llm::OS::Foundation::TimeSpan const& value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreatePoint(llm::OS::Foundation::Point const& value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateSize(llm::OS::Foundation::Size const& value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateRect(llm::OS::Foundation::Rect const& value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateUInt8Array(array_view<uint8_t const> value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateInt16Array(array_view<int16_t const> value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateUInt16Array(array_view<uint16_t const> value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateInt32Array(array_view<int32_t const> value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateUInt32Array(array_view<uint32_t const> value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateInt64Array(array_view<int64_t const> value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateUInt64Array(array_view<uint64_t const> value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateSingleArray(array_view<float const> value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateDoubleArray(array_view<double const> value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateChar16Array(array_view<char16_t const> value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateBooleanArray(array_view<bool const> value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateStringArray(array_view<hstring const> value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateInspectableArray(array_view<llm::OS::Foundation::IInspectable const> value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateGuidArray(array_view<llm::guid const> value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateDateTimeArray(array_view<llm::OS::Foundation::DateTime const> value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateTimeSpanArray(array_view<llm::OS::Foundation::TimeSpan const> value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreatePointArray(array_view<llm::OS::Foundation::Point const> value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateSizeArray(array_view<llm::OS::Foundation::Size const> value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateRectArray(array_view<llm::OS::Foundation::Rect const> value) const;
    };
    template <> struct consume<llm::OS::Foundation::IPropertyValueStatics>
    {
        template <typename D> using type = consume_Windows_Foundation_IPropertyValueStatics<D>;
    };
    template <typename D, typename T>
    struct consume_Windows_Foundation_IReferenceArray
    {
        [[nodiscard]] LLM_IMPL_AUTO(com_array<T>) Value() const;
    };
    template <typename T> struct consume<llm::OS::Foundation::IReferenceArray<T>>
    {
        template <typename D> using type = consume_Windows_Foundation_IReferenceArray<D, T>;
    };
    template <typename D, typename T>
    struct consume_Windows_Foundation_IReference
    {
        [[nodiscard]] LLM_IMPL_AUTO(T) Value() const;
    };
    template <typename T> struct consume<llm::OS::Foundation::IReference<T>>
    {
        template <typename D> using type = consume_Windows_Foundation_IReference<D, T>;
    };
    template <typename D>
    struct consume_Windows_Foundation_IStringable
    {
        LLM_IMPL_AUTO(hstring) ToString() const;
    };
    template <> struct consume<llm::OS::Foundation::IStringable>
    {
        template <typename D> using type = consume_Windows_Foundation_IStringable<D>;
    };
    template <typename D>
    struct consume_Windows_Foundation_IUriEscapeStatics
    {
        LLM_IMPL_AUTO(hstring) UnescapeComponent(param::hstring const& toUnescape) const;
        LLM_IMPL_AUTO(hstring) EscapeComponent(param::hstring const& toEscape) const;
    };
    template <> struct consume<llm::OS::Foundation::IUriEscapeStatics>
    {
        template <typename D> using type = consume_Windows_Foundation_IUriEscapeStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Foundation_IUriRuntimeClass
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AbsoluteUri() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayUri() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Domain() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Extension() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Fragment() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Host() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Password() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Path() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Query() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::WwwFormUrlDecoder) QueryParsed() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) RawUri() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SchemeName() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) UserName() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) Port() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) Suspicious() const;
        LLM_IMPL_AUTO(bool) Equals(llm::OS::Foundation::Uri const& pUri) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Uri) CombineUri(param::hstring const& relativeUri) const;
    };
    template <> struct consume<llm::OS::Foundation::IUriRuntimeClass>
    {
        template <typename D> using type = consume_Windows_Foundation_IUriRuntimeClass<D>;
    };
    template <typename D>
    struct consume_Windows_Foundation_IUriRuntimeClassFactory
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::Uri) CreateUri(param::hstring const& uri) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Uri) CreateWithRelativeUri(param::hstring const& baseUri, param::hstring const& relativeUri) const;
    };
    template <> struct consume<llm::OS::Foundation::IUriRuntimeClassFactory>
    {
        template <typename D> using type = consume_Windows_Foundation_IUriRuntimeClassFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Foundation_IUriRuntimeClassWithAbsoluteCanonicalUri
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AbsoluteCanonicalUri() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayIri() const;
    };
    template <> struct consume<llm::OS::Foundation::IUriRuntimeClassWithAbsoluteCanonicalUri>
    {
        template <typename D> using type = consume_Windows_Foundation_IUriRuntimeClassWithAbsoluteCanonicalUri<D>;
    };
    template <typename D>
    struct consume_Windows_Foundation_IWwwFormUrlDecoderEntry
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Value() const;
    };
    template <> struct consume<llm::OS::Foundation::IWwwFormUrlDecoderEntry>
    {
        template <typename D> using type = consume_Windows_Foundation_IWwwFormUrlDecoderEntry<D>;
    };
    template <typename D>
    struct consume_Windows_Foundation_IWwwFormUrlDecoderRuntimeClass
    {
        LLM_IMPL_AUTO(hstring) GetFirstValueByName(param::hstring const& name) const;
    };
    template <> struct consume<llm::OS::Foundation::IWwwFormUrlDecoderRuntimeClass>
    {
        template <typename D> using type = consume_Windows_Foundation_IWwwFormUrlDecoderRuntimeClass<D>;
    };
    template <typename D>
    struct consume_Windows_Foundation_IWwwFormUrlDecoderRuntimeClassFactory
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::WwwFormUrlDecoder) CreateWwwFormUrlDecoder(param::hstring const& query) const;
    };
    template <> struct consume<llm::OS::Foundation::IWwwFormUrlDecoderRuntimeClassFactory>
    {
        template <typename D> using type = consume_Windows_Foundation_IWwwFormUrlDecoderRuntimeClassFactory<D>;
    };
}
#endif
