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
#ifndef LLM_OS_ApplicationModel_DataTransfer_0_H
#define LLM_OS_ApplicationModel_DataTransfer_0_H
LLM_EXPORT namespace llm::OS::Foundation
{
    struct Deferral;
    template <typename T> struct __declspec(empty_bases) EventHandler;
    struct EventRegistrationToken;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename T> struct __declspec(empty_bases) IReference;
    struct Rect;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
    struct Uri;
}
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IIterable;
    template <typename K, typename V> struct __declspec(empty_bases) IMapView;
    template <typename K, typename V> struct __declspec(empty_bases) IMap;
    template <typename T> struct __declspec(empty_bases) IVectorView;
    template <typename T> struct __declspec(empty_bases) IVector;
}
LLM_EXPORT namespace llm::OS::Security::EnterpriseData
{
    enum class ProtectionPolicyEvaluationResult : int32_t;
}
LLM_EXPORT namespace llm::OS::Storage
{
    struct IStorageFile;
    struct IStorageItem;
    struct StorageFile;
}
LLM_EXPORT namespace llm::OS::Storage::Streams
{
    struct IRandomAccessStreamReference;
    struct RandomAccessStreamReference;
}
LLM_EXPORT namespace llm::OS::UI
{
    struct Color;
}
LLM_EXPORT namespace llm::OS::ApplicationModel::DataTransfer
{
    enum class ClipboardHistoryItemsResultStatus : int32_t
    {
        Success = 0,
        AccessDenied = 1,
        ClipboardHistoryDisabled = 2,
    };
    enum class DataPackageOperation : uint32_t
    {
        None = 0,
        Copy = 0x1,
        Move = 0x2,
        Link = 0x4,
    };
    enum class SetHistoryItemAsContentStatus : int32_t
    {
        Success = 0,
        AccessDenied = 1,
        ItemDeleted = 2,
    };
    enum class ShareUITheme : int32_t
    {
        Default = 0,
        Light = 1,
        Dark = 2,
    };
    struct IClipboardContentOptions;
    struct IClipboardHistoryChangedEventArgs;
    struct IClipboardHistoryItem;
    struct IClipboardHistoryItemsResult;
    struct IClipboardStatics;
    struct IClipboardStatics2;
    struct IDataPackage;
    struct IDataPackage2;
    struct IDataPackage3;
    struct IDataPackage4;
    struct IDataPackagePropertySet;
    struct IDataPackagePropertySet2;
    struct IDataPackagePropertySet3;
    struct IDataPackagePropertySet4;
    struct IDataPackagePropertySetView;
    struct IDataPackagePropertySetView2;
    struct IDataPackagePropertySetView3;
    struct IDataPackagePropertySetView4;
    struct IDataPackagePropertySetView5;
    struct IDataPackageView;
    struct IDataPackageView2;
    struct IDataPackageView3;
    struct IDataPackageView4;
    struct IDataProviderDeferral;
    struct IDataProviderRequest;
    struct IDataRequest;
    struct IDataRequestDeferral;
    struct IDataRequestedEventArgs;
    struct IDataTransferManager;
    struct IDataTransferManager2;
    struct IDataTransferManagerStatics;
    struct IDataTransferManagerStatics2;
    struct IDataTransferManagerStatics3;
    struct IHtmlFormatHelperStatics;
    struct IOperationCompletedEventArgs;
    struct IOperationCompletedEventArgs2;
    struct IShareCompletedEventArgs;
    struct IShareProvider;
    struct IShareProviderFactory;
    struct IShareProviderOperation;
    struct IShareProvidersRequestedEventArgs;
    struct IShareTargetInfo;
    struct IShareUIOptions;
    struct ISharedStorageAccessManagerStatics;
    struct IStandardDataFormatsStatics;
    struct IStandardDataFormatsStatics2;
    struct IStandardDataFormatsStatics3;
    struct ITargetApplicationChosenEventArgs;
    struct Clipboard;
    struct ClipboardContentOptions;
    struct ClipboardHistoryChangedEventArgs;
    struct ClipboardHistoryItem;
    struct ClipboardHistoryItemsResult;
    struct DataPackage;
    struct DataPackagePropertySet;
    struct DataPackagePropertySetView;
    struct DataPackageView;
    struct DataProviderDeferral;
    struct DataProviderRequest;
    struct DataRequest;
    struct DataRequestDeferral;
    struct DataRequestedEventArgs;
    struct DataTransferManager;
    struct HtmlFormatHelper;
    struct OperationCompletedEventArgs;
    struct ShareCompletedEventArgs;
    struct ShareProvider;
    struct ShareProviderOperation;
    struct ShareProvidersRequestedEventArgs;
    struct ShareTargetInfo;
    struct ShareUIOptions;
    struct SharedStorageAccessManager;
    struct StandardDataFormats;
    struct TargetApplicationChosenEventArgs;
    struct DataProviderHandler;
    struct ShareProviderHandler;
}
namespace llm::impl
{
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IClipboardContentOptions>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IClipboardHistoryChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IClipboardHistoryItem>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IClipboardHistoryItemsResult>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IClipboardStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IClipboardStatics2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IDataPackage>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IDataPackage2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IDataPackage3>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IDataPackage4>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySet>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySet2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySet3>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySet4>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySetView>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySetView2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySetView3>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySetView4>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySetView5>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IDataPackageView>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IDataPackageView2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IDataPackageView3>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IDataPackageView4>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IDataProviderDeferral>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IDataProviderRequest>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IDataRequest>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IDataRequestDeferral>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IDataRequestedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IDataTransferManager>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IDataTransferManager2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IDataTransferManagerStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IDataTransferManagerStatics2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IDataTransferManagerStatics3>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IHtmlFormatHelperStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IOperationCompletedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IOperationCompletedEventArgs2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IShareCompletedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IShareProvider>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IShareProviderFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IShareProviderOperation>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IShareProvidersRequestedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IShareTargetInfo>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IShareUIOptions>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::ISharedStorageAccessManagerStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IStandardDataFormatsStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IStandardDataFormatsStatics2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::IStandardDataFormatsStatics3>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::ITargetApplicationChosenEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::Clipboard>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::ClipboardContentOptions>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::ClipboardHistoryChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::ClipboardHistoryItem>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::ClipboardHistoryItemsResult>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::DataPackage>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::DataPackagePropertySet>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::DataPackagePropertySetView>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::DataPackageView>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::DataProviderDeferral>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::DataProviderRequest>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::DataRequest>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::DataRequestDeferral>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::DataRequestedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::DataTransferManager>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::HtmlFormatHelper>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::OperationCompletedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::ShareCompletedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::ShareProvider>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::ShareProviderOperation>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::ShareProvidersRequestedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::ShareTargetInfo>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::ShareUIOptions>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::SharedStorageAccessManager>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::StandardDataFormats>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::TargetApplicationChosenEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::ClipboardHistoryItemsResultStatus>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::DataPackageOperation>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::SetHistoryItemAsContentStatus>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::ShareUITheme>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::DataProviderHandler>{ using type = delegate_category; };
    template <> struct category<llm::OS::ApplicationModel::DataTransfer::ShareProviderHandler>{ using type = delegate_category; };
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::Clipboard> = L"Windows.ApplicationModel.DataTransfer.Clipboard";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::ClipboardContentOptions> = L"Windows.ApplicationModel.DataTransfer.ClipboardContentOptions";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::ClipboardHistoryChangedEventArgs> = L"Windows.ApplicationModel.DataTransfer.ClipboardHistoryChangedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::ClipboardHistoryItem> = L"Windows.ApplicationModel.DataTransfer.ClipboardHistoryItem";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::ClipboardHistoryItemsResult> = L"Windows.ApplicationModel.DataTransfer.ClipboardHistoryItemsResult";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::DataPackage> = L"Windows.ApplicationModel.DataTransfer.DataPackage";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::DataPackagePropertySet> = L"Windows.ApplicationModel.DataTransfer.DataPackagePropertySet";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::DataPackagePropertySetView> = L"Windows.ApplicationModel.DataTransfer.DataPackagePropertySetView";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::DataPackageView> = L"Windows.ApplicationModel.DataTransfer.DataPackageView";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::DataProviderDeferral> = L"Windows.ApplicationModel.DataTransfer.DataProviderDeferral";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::DataProviderRequest> = L"Windows.ApplicationModel.DataTransfer.DataProviderRequest";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::DataRequest> = L"Windows.ApplicationModel.DataTransfer.DataRequest";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::DataRequestDeferral> = L"Windows.ApplicationModel.DataTransfer.DataRequestDeferral";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::DataRequestedEventArgs> = L"Windows.ApplicationModel.DataTransfer.DataRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::DataTransferManager> = L"Windows.ApplicationModel.DataTransfer.DataTransferManager";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::HtmlFormatHelper> = L"Windows.ApplicationModel.DataTransfer.HtmlFormatHelper";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::OperationCompletedEventArgs> = L"Windows.ApplicationModel.DataTransfer.OperationCompletedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::ShareCompletedEventArgs> = L"Windows.ApplicationModel.DataTransfer.ShareCompletedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::ShareProvider> = L"Windows.ApplicationModel.DataTransfer.ShareProvider";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::ShareProviderOperation> = L"Windows.ApplicationModel.DataTransfer.ShareProviderOperation";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::ShareProvidersRequestedEventArgs> = L"Windows.ApplicationModel.DataTransfer.ShareProvidersRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::ShareTargetInfo> = L"Windows.ApplicationModel.DataTransfer.ShareTargetInfo";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::ShareUIOptions> = L"Windows.ApplicationModel.DataTransfer.ShareUIOptions";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::SharedStorageAccessManager> = L"Windows.ApplicationModel.DataTransfer.SharedStorageAccessManager";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::StandardDataFormats> = L"Windows.ApplicationModel.DataTransfer.StandardDataFormats";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::TargetApplicationChosenEventArgs> = L"Windows.ApplicationModel.DataTransfer.TargetApplicationChosenEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::ClipboardHistoryItemsResultStatus> = L"Windows.ApplicationModel.DataTransfer.ClipboardHistoryItemsResultStatus";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::DataPackageOperation> = L"Windows.ApplicationModel.DataTransfer.DataPackageOperation";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::SetHistoryItemAsContentStatus> = L"Windows.ApplicationModel.DataTransfer.SetHistoryItemAsContentStatus";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::ShareUITheme> = L"Windows.ApplicationModel.DataTransfer.ShareUITheme";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IClipboardContentOptions> = L"Windows.ApplicationModel.DataTransfer.IClipboardContentOptions";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IClipboardHistoryChangedEventArgs> = L"Windows.ApplicationModel.DataTransfer.IClipboardHistoryChangedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IClipboardHistoryItem> = L"Windows.ApplicationModel.DataTransfer.IClipboardHistoryItem";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IClipboardHistoryItemsResult> = L"Windows.ApplicationModel.DataTransfer.IClipboardHistoryItemsResult";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IClipboardStatics> = L"Windows.ApplicationModel.DataTransfer.IClipboardStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IClipboardStatics2> = L"Windows.ApplicationModel.DataTransfer.IClipboardStatics2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IDataPackage> = L"Windows.ApplicationModel.DataTransfer.IDataPackage";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IDataPackage2> = L"Windows.ApplicationModel.DataTransfer.IDataPackage2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IDataPackage3> = L"Windows.ApplicationModel.DataTransfer.IDataPackage3";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IDataPackage4> = L"Windows.ApplicationModel.DataTransfer.IDataPackage4";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySet> = L"Windows.ApplicationModel.DataTransfer.IDataPackagePropertySet";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySet2> = L"Windows.ApplicationModel.DataTransfer.IDataPackagePropertySet2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySet3> = L"Windows.ApplicationModel.DataTransfer.IDataPackagePropertySet3";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySet4> = L"Windows.ApplicationModel.DataTransfer.IDataPackagePropertySet4";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySetView> = L"Windows.ApplicationModel.DataTransfer.IDataPackagePropertySetView";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySetView2> = L"Windows.ApplicationModel.DataTransfer.IDataPackagePropertySetView2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySetView3> = L"Windows.ApplicationModel.DataTransfer.IDataPackagePropertySetView3";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySetView4> = L"Windows.ApplicationModel.DataTransfer.IDataPackagePropertySetView4";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySetView5> = L"Windows.ApplicationModel.DataTransfer.IDataPackagePropertySetView5";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IDataPackageView> = L"Windows.ApplicationModel.DataTransfer.IDataPackageView";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IDataPackageView2> = L"Windows.ApplicationModel.DataTransfer.IDataPackageView2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IDataPackageView3> = L"Windows.ApplicationModel.DataTransfer.IDataPackageView3";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IDataPackageView4> = L"Windows.ApplicationModel.DataTransfer.IDataPackageView4";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IDataProviderDeferral> = L"Windows.ApplicationModel.DataTransfer.IDataProviderDeferral";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IDataProviderRequest> = L"Windows.ApplicationModel.DataTransfer.IDataProviderRequest";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IDataRequest> = L"Windows.ApplicationModel.DataTransfer.IDataRequest";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IDataRequestDeferral> = L"Windows.ApplicationModel.DataTransfer.IDataRequestDeferral";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IDataRequestedEventArgs> = L"Windows.ApplicationModel.DataTransfer.IDataRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IDataTransferManager> = L"Windows.ApplicationModel.DataTransfer.IDataTransferManager";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IDataTransferManager2> = L"Windows.ApplicationModel.DataTransfer.IDataTransferManager2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IDataTransferManagerStatics> = L"Windows.ApplicationModel.DataTransfer.IDataTransferManagerStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IDataTransferManagerStatics2> = L"Windows.ApplicationModel.DataTransfer.IDataTransferManagerStatics2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IDataTransferManagerStatics3> = L"Windows.ApplicationModel.DataTransfer.IDataTransferManagerStatics3";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IHtmlFormatHelperStatics> = L"Windows.ApplicationModel.DataTransfer.IHtmlFormatHelperStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IOperationCompletedEventArgs> = L"Windows.ApplicationModel.DataTransfer.IOperationCompletedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IOperationCompletedEventArgs2> = L"Windows.ApplicationModel.DataTransfer.IOperationCompletedEventArgs2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IShareCompletedEventArgs> = L"Windows.ApplicationModel.DataTransfer.IShareCompletedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IShareProvider> = L"Windows.ApplicationModel.DataTransfer.IShareProvider";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IShareProviderFactory> = L"Windows.ApplicationModel.DataTransfer.IShareProviderFactory";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IShareProviderOperation> = L"Windows.ApplicationModel.DataTransfer.IShareProviderOperation";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IShareProvidersRequestedEventArgs> = L"Windows.ApplicationModel.DataTransfer.IShareProvidersRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IShareTargetInfo> = L"Windows.ApplicationModel.DataTransfer.IShareTargetInfo";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IShareUIOptions> = L"Windows.ApplicationModel.DataTransfer.IShareUIOptions";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::ISharedStorageAccessManagerStatics> = L"Windows.ApplicationModel.DataTransfer.ISharedStorageAccessManagerStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IStandardDataFormatsStatics> = L"Windows.ApplicationModel.DataTransfer.IStandardDataFormatsStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IStandardDataFormatsStatics2> = L"Windows.ApplicationModel.DataTransfer.IStandardDataFormatsStatics2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::IStandardDataFormatsStatics3> = L"Windows.ApplicationModel.DataTransfer.IStandardDataFormatsStatics3";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::ITargetApplicationChosenEventArgs> = L"Windows.ApplicationModel.DataTransfer.ITargetApplicationChosenEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::DataProviderHandler> = L"Windows.ApplicationModel.DataTransfer.DataProviderHandler";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DataTransfer::ShareProviderHandler> = L"Windows.ApplicationModel.DataTransfer.ShareProviderHandler";
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IClipboardContentOptions>{ 0xE888A98C,0xAD4B,0x5447,{ 0xA0,0x56,0xAB,0x35,0x56,0x27,0x6D,0x2B } }; // E888A98C-AD4B-5447-A056-AB3556276D2B
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IClipboardHistoryChangedEventArgs>{ 0xC0BE453F,0x8EA2,0x53CE,{ 0x9A,0xBA,0x8D,0x22,0x12,0x57,0x34,0x52 } }; // C0BE453F-8EA2-53CE-9ABA-8D2212573452
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IClipboardHistoryItem>{ 0x0173BD8A,0xAFFF,0x5C50,{ 0xAB,0x92,0x3D,0x19,0xF4,0x81,0xEC,0x58 } }; // 0173BD8A-AFFF-5C50-AB92-3D19F481EC58
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IClipboardHistoryItemsResult>{ 0xE6DFDEE6,0x0EE2,0x52E3,{ 0x85,0x2B,0xF2,0x95,0xDB,0x65,0x93,0x9A } }; // E6DFDEE6-0EE2-52E3-852B-F295DB65939A
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IClipboardStatics>{ 0xC627E291,0x34E2,0x4963,{ 0x8E,0xED,0x93,0xCB,0xB0,0xEA,0x3D,0x70 } }; // C627E291-34E2-4963-8EED-93CBB0EA3D70
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IClipboardStatics2>{ 0xD2AC1B6A,0xD29F,0x554B,{ 0xB3,0x03,0xF0,0x45,0x23,0x45,0xFE,0x02 } }; // D2AC1B6A-D29F-554B-B303-F0452345FE02
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IDataPackage>{ 0x61EBF5C7,0xEFEA,0x4346,{ 0x95,0x54,0x98,0x1D,0x7E,0x19,0x8F,0xFE } }; // 61EBF5C7-EFEA-4346-9554-981D7E198FFE
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IDataPackage2>{ 0x041C1FE9,0x2409,0x45E1,{ 0xA5,0x38,0x4C,0x53,0xEE,0xEE,0x04,0xA7 } }; // 041C1FE9-2409-45E1-A538-4C53EEEE04A7
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IDataPackage3>{ 0x88F31F5D,0x787B,0x4D32,{ 0x96,0x5A,0xA9,0x83,0x81,0x05,0xA0,0x56 } }; // 88F31F5D-787B-4D32-965A-A9838105A056
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IDataPackage4>{ 0x13A24EC8,0x9382,0x536F,{ 0x85,0x2A,0x30,0x45,0xE1,0xB2,0x9A,0x3B } }; // 13A24EC8-9382-536F-852A-3045E1B29A3B
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySet>{ 0xCD1C93EB,0x4C4C,0x443A,{ 0xA8,0xD3,0xF5,0xC2,0x41,0xE9,0x16,0x89 } }; // CD1C93EB-4C4C-443A-A8D3-F5C241E91689
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySet2>{ 0xEB505D4A,0x9800,0x46AA,{ 0xB1,0x81,0x7B,0x6F,0x0F,0x2B,0x91,0x9A } }; // EB505D4A-9800-46AA-B181-7B6F0F2B919A
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySet3>{ 0x9E87FD9B,0x5205,0x401B,{ 0x87,0x4A,0x45,0x56,0x53,0xBD,0x39,0xE8 } }; // 9E87FD9B-5205-401B-874A-455653BD39E8
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySet4>{ 0x6390EBF5,0x1739,0x4C74,{ 0xB2,0x2F,0x86,0x5F,0xAB,0x5E,0x85,0x45 } }; // 6390EBF5-1739-4C74-B22F-865FAB5E8545
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySetView>{ 0xB94CEC01,0x0C1A,0x4C57,{ 0xBE,0x55,0x75,0xD0,0x12,0x89,0x73,0x5D } }; // B94CEC01-0C1A-4C57-BE55-75D01289735D
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySetView2>{ 0x6054509B,0x8EBE,0x4FEB,{ 0x9C,0x1E,0x75,0xE6,0x9D,0xE5,0x4B,0x84 } }; // 6054509B-8EBE-4FEB-9C1E-75E69DE54B84
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySetView3>{ 0xDB764CE5,0xD174,0x495C,{ 0x84,0xFC,0x1A,0x51,0xF6,0xAB,0x45,0xD7 } }; // DB764CE5-D174-495C-84FC-1A51F6AB45D7
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySetView4>{ 0x4474C80D,0xD16F,0x40AE,{ 0x95,0x80,0x6F,0x85,0x62,0xB9,0x42,0x35 } }; // 4474C80D-D16F-40AE-9580-6F8562B94235
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySetView5>{ 0x6F0A9445,0x3760,0x50BB,{ 0x85,0x23,0xC4,0x20,0x2D,0xED,0x7D,0x78 } }; // 6F0A9445-3760-50BB-8523-C4202DED7D78
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IDataPackageView>{ 0x7B840471,0x5900,0x4D85,{ 0xA9,0x0B,0x10,0xCB,0x85,0xFE,0x35,0x52 } }; // 7B840471-5900-4D85-A90B-10CB85FE3552
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IDataPackageView2>{ 0x40ECBA95,0x2450,0x4C1D,{ 0xB6,0xB4,0xED,0x45,0x46,0x3D,0xEE,0x9C } }; // 40ECBA95-2450-4C1D-B6B4-ED45463DEE9C
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IDataPackageView3>{ 0xD37771A8,0xDDAD,0x4288,{ 0x84,0x28,0xD1,0xCA,0xE3,0x94,0x12,0x8B } }; // D37771A8-DDAD-4288-8428-D1CAE394128B
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IDataPackageView4>{ 0xDFE96F1F,0xE042,0x4433,{ 0xA0,0x9F,0x26,0xD6,0xFF,0xDA,0x8B,0x85 } }; // DFE96F1F-E042-4433-A09F-26D6FFDA8B85
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IDataProviderDeferral>{ 0xC2CF2373,0x2D26,0x43D9,{ 0xB6,0x9D,0xDC,0xB8,0x6D,0x03,0xF6,0xDA } }; // C2CF2373-2D26-43D9-B69D-DCB86D03F6DA
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IDataProviderRequest>{ 0xEBBC7157,0xD3C8,0x47DA,{ 0xAC,0xDE,0xF8,0x23,0x88,0xD5,0xF7,0x16 } }; // EBBC7157-D3C8-47DA-ACDE-F82388D5F716
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IDataRequest>{ 0x4341AE3B,0xFC12,0x4E53,{ 0x8C,0x02,0xAC,0x71,0x4C,0x41,0x5A,0x27 } }; // 4341AE3B-FC12-4E53-8C02-AC714C415A27
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IDataRequestDeferral>{ 0x6DC4B89F,0x0386,0x4263,{ 0x87,0xC1,0xED,0x7D,0xCE,0x30,0x89,0x0E } }; // 6DC4B89F-0386-4263-87C1-ED7DCE30890E
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IDataRequestedEventArgs>{ 0xCB8BA807,0x6AC5,0x43C9,{ 0x8A,0xC5,0x9B,0xA2,0x32,0x16,0x31,0x82 } }; // CB8BA807-6AC5-43C9-8AC5-9BA232163182
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IDataTransferManager>{ 0xA5CAEE9B,0x8708,0x49D1,{ 0x8D,0x36,0x67,0xD2,0x5A,0x8D,0xA0,0x0C } }; // A5CAEE9B-8708-49D1-8D36-67D25A8DA00C
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IDataTransferManager2>{ 0x30AE7D71,0x8BA8,0x4C02,{ 0x8E,0x3F,0xDD,0xB2,0x3B,0x38,0x87,0x15 } }; // 30AE7D71-8BA8-4C02-8E3F-DDB23B388715
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IDataTransferManagerStatics>{ 0xA9DA01AA,0xE00E,0x4CFE,{ 0xAA,0x44,0x2D,0xD9,0x32,0xDC,0xA3,0xD8 } }; // A9DA01AA-E00E-4CFE-AA44-2DD932DCA3D8
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IDataTransferManagerStatics2>{ 0xC54EC2EC,0x9F97,0x4D63,{ 0x98,0x68,0x39,0x5E,0x27,0x1A,0xD8,0xF5 } }; // C54EC2EC-9F97-4D63-9868-395E271AD8F5
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IDataTransferManagerStatics3>{ 0x05845473,0x6C82,0x4F5C,{ 0xAC,0x23,0x62,0xE4,0x58,0x36,0x1F,0xAC } }; // 05845473-6C82-4F5C-AC23-62E458361FAC
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IHtmlFormatHelperStatics>{ 0xE22E7749,0xDD70,0x446F,{ 0xAE,0xFC,0x61,0xCE,0xE5,0x9F,0x65,0x5E } }; // E22E7749-DD70-446F-AEFC-61CEE59F655E
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IOperationCompletedEventArgs>{ 0xE7AF329D,0x051D,0x4FAB,{ 0xB1,0xA9,0x47,0xFD,0x77,0xF7,0x0A,0x41 } }; // E7AF329D-051D-4FAB-B1A9-47FD77F70A41
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IOperationCompletedEventArgs2>{ 0x858FA073,0x1E19,0x4105,{ 0xB2,0xF7,0xC8,0x47,0x88,0x08,0xD5,0x62 } }; // 858FA073-1E19-4105-B2F7-C8478808D562
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IShareCompletedEventArgs>{ 0x4574C442,0xF913,0x4F60,{ 0x9D,0xF7,0xCC,0x40,0x60,0xAB,0x19,0x16 } }; // 4574C442-F913-4F60-9DF7-CC4060AB1916
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IShareProvider>{ 0x2FABE026,0x443E,0x4CDA,{ 0xAF,0x25,0x8D,0x81,0x07,0x0E,0xFD,0x80 } }; // 2FABE026-443E-4CDA-AF25-8D81070EFD80
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IShareProviderFactory>{ 0x172A174C,0xE79E,0x4F6D,{ 0xB0,0x7D,0x12,0x8F,0x46,0x9E,0x02,0x96 } }; // 172A174C-E79E-4F6D-B07D-128F469E0296
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IShareProviderOperation>{ 0x19CEF937,0xD435,0x4179,{ 0xB6,0xAF,0x14,0xE0,0x49,0x2B,0x69,0xF6 } }; // 19CEF937-D435-4179-B6AF-14E0492B69F6
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IShareProvidersRequestedEventArgs>{ 0xF888F356,0xA3F8,0x4FCE,{ 0x85,0xE4,0x88,0x26,0xE6,0x3B,0xE7,0x99 } }; // F888F356-A3F8-4FCE-85E4-8826E63BE799
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IShareTargetInfo>{ 0x385BE607,0xC6E8,0x4114,{ 0xB2,0x94,0x28,0xF3,0xBB,0x6F,0x99,0x04 } }; // 385BE607-C6E8-4114-B294-28F3BB6F9904
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IShareUIOptions>{ 0x72FA8A80,0x342F,0x4D90,{ 0x95,0x51,0x2A,0xE0,0x4E,0x37,0x68,0x0C } }; // 72FA8A80-342F-4D90-9551-2AE04E37680C
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::ISharedStorageAccessManagerStatics>{ 0xC6132ADA,0x34B1,0x4849,{ 0xBD,0x5F,0xD0,0x9F,0xEE,0x31,0x58,0xC5 } }; // C6132ADA-34B1-4849-BD5F-D09FEE3158C5
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IStandardDataFormatsStatics>{ 0x7ED681A1,0xA880,0x40C9,{ 0xB4,0xED,0x0B,0xEE,0x1E,0x15,0xF5,0x49 } }; // 7ED681A1-A880-40C9-B4ED-0BEE1E15F549
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IStandardDataFormatsStatics2>{ 0x42A254F4,0x9D76,0x42E8,{ 0x86,0x1B,0x47,0xC2,0x5D,0xD0,0xCF,0x71 } }; // 42A254F4-9D76-42E8-861B-47C25DD0CF71
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::IStandardDataFormatsStatics3>{ 0x3B57B069,0x01D4,0x474C,{ 0x8B,0x5F,0xBC,0x8E,0x27,0xF3,0x8B,0x21 } }; // 3B57B069-01D4-474C-8B5F-BC8E27F38B21
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::ITargetApplicationChosenEventArgs>{ 0xCA6FB8AC,0x2987,0x4EE3,{ 0x9C,0x54,0xD8,0xAF,0xBC,0xB8,0x6C,0x1D } }; // CA6FB8AC-2987-4EE3-9C54-D8AFBCB86C1D
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::DataProviderHandler>{ 0xE7ECD720,0xF2F4,0x4A2D,{ 0x92,0x0E,0x17,0x0A,0x2F,0x48,0x2A,0x27 } }; // E7ECD720-F2F4-4A2D-920E-170A2F482A27
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::DataTransfer::ShareProviderHandler>{ 0xE7F9D9BA,0xE1BA,0x4E4D,{ 0xBD,0x65,0xD4,0x38,0x45,0xD3,0x21,0x2F } }; // E7F9D9BA-E1BA-4E4D-BD65-D43845D3212F
    template <> struct default_interface<llm::OS::ApplicationModel::DataTransfer::ClipboardContentOptions>{ using type = llm::OS::ApplicationModel::DataTransfer::IClipboardContentOptions; };
    template <> struct default_interface<llm::OS::ApplicationModel::DataTransfer::ClipboardHistoryChangedEventArgs>{ using type = llm::OS::ApplicationModel::DataTransfer::IClipboardHistoryChangedEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::DataTransfer::ClipboardHistoryItem>{ using type = llm::OS::ApplicationModel::DataTransfer::IClipboardHistoryItem; };
    template <> struct default_interface<llm::OS::ApplicationModel::DataTransfer::ClipboardHistoryItemsResult>{ using type = llm::OS::ApplicationModel::DataTransfer::IClipboardHistoryItemsResult; };
    template <> struct default_interface<llm::OS::ApplicationModel::DataTransfer::DataPackage>{ using type = llm::OS::ApplicationModel::DataTransfer::IDataPackage; };
    template <> struct default_interface<llm::OS::ApplicationModel::DataTransfer::DataPackagePropertySet>{ using type = llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySet; };
    template <> struct default_interface<llm::OS::ApplicationModel::DataTransfer::DataPackagePropertySetView>{ using type = llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySetView; };
    template <> struct default_interface<llm::OS::ApplicationModel::DataTransfer::DataPackageView>{ using type = llm::OS::ApplicationModel::DataTransfer::IDataPackageView; };
    template <> struct default_interface<llm::OS::ApplicationModel::DataTransfer::DataProviderDeferral>{ using type = llm::OS::ApplicationModel::DataTransfer::IDataProviderDeferral; };
    template <> struct default_interface<llm::OS::ApplicationModel::DataTransfer::DataProviderRequest>{ using type = llm::OS::ApplicationModel::DataTransfer::IDataProviderRequest; };
    template <> struct default_interface<llm::OS::ApplicationModel::DataTransfer::DataRequest>{ using type = llm::OS::ApplicationModel::DataTransfer::IDataRequest; };
    template <> struct default_interface<llm::OS::ApplicationModel::DataTransfer::DataRequestDeferral>{ using type = llm::OS::ApplicationModel::DataTransfer::IDataRequestDeferral; };
    template <> struct default_interface<llm::OS::ApplicationModel::DataTransfer::DataRequestedEventArgs>{ using type = llm::OS::ApplicationModel::DataTransfer::IDataRequestedEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::DataTransfer::DataTransferManager>{ using type = llm::OS::ApplicationModel::DataTransfer::IDataTransferManager; };
    template <> struct default_interface<llm::OS::ApplicationModel::DataTransfer::OperationCompletedEventArgs>{ using type = llm::OS::ApplicationModel::DataTransfer::IOperationCompletedEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::DataTransfer::ShareCompletedEventArgs>{ using type = llm::OS::ApplicationModel::DataTransfer::IShareCompletedEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::DataTransfer::ShareProvider>{ using type = llm::OS::ApplicationModel::DataTransfer::IShareProvider; };
    template <> struct default_interface<llm::OS::ApplicationModel::DataTransfer::ShareProviderOperation>{ using type = llm::OS::ApplicationModel::DataTransfer::IShareProviderOperation; };
    template <> struct default_interface<llm::OS::ApplicationModel::DataTransfer::ShareProvidersRequestedEventArgs>{ using type = llm::OS::ApplicationModel::DataTransfer::IShareProvidersRequestedEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::DataTransfer::ShareTargetInfo>{ using type = llm::OS::ApplicationModel::DataTransfer::IShareTargetInfo; };
    template <> struct default_interface<llm::OS::ApplicationModel::DataTransfer::ShareUIOptions>{ using type = llm::OS::ApplicationModel::DataTransfer::IShareUIOptions; };
    template <> struct default_interface<llm::OS::ApplicationModel::DataTransfer::TargetApplicationChosenEventArgs>{ using type = llm::OS::ApplicationModel::DataTransfer::ITargetApplicationChosenEventArgs; };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IClipboardContentOptions>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsRoamable(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsRoamable(bool) noexcept = 0;
            virtual int32_t __stdcall get_IsAllowedInHistory(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsAllowedInHistory(bool) noexcept = 0;
            virtual int32_t __stdcall get_RoamingFormats(void**) noexcept = 0;
            virtual int32_t __stdcall get_HistoryFormats(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IClipboardHistoryChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IClipboardHistoryItem>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Id(void**) noexcept = 0;
            virtual int32_t __stdcall get_Timestamp(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_Content(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IClipboardHistoryItemsResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Items(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IClipboardStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetContent(void**) noexcept = 0;
            virtual int32_t __stdcall SetContent(void*) noexcept = 0;
            virtual int32_t __stdcall Flush() noexcept = 0;
            virtual int32_t __stdcall Clear() noexcept = 0;
            virtual int32_t __stdcall add_ContentChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ContentChanged(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IClipboardStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetHistoryItemsAsync(void**) noexcept = 0;
            virtual int32_t __stdcall ClearHistory(bool*) noexcept = 0;
            virtual int32_t __stdcall DeleteItemFromHistory(void*, bool*) noexcept = 0;
            virtual int32_t __stdcall SetHistoryItemAsContent(void*, int32_t*) noexcept = 0;
            virtual int32_t __stdcall IsHistoryEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall IsRoamingEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall SetContentWithOptions(void*, void*, bool*) noexcept = 0;
            virtual int32_t __stdcall add_HistoryChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_HistoryChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_RoamingEnabledChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_RoamingEnabledChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_HistoryEnabledChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_HistoryEnabledChanged(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IDataPackage>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetView(void**) noexcept = 0;
            virtual int32_t __stdcall get_Properties(void**) noexcept = 0;
            virtual int32_t __stdcall get_RequestedOperation(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_RequestedOperation(uint32_t) noexcept = 0;
            virtual int32_t __stdcall add_OperationCompleted(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_OperationCompleted(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Destroyed(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Destroyed(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall SetData(void*, void*) noexcept = 0;
            virtual int32_t __stdcall SetDataProvider(void*, void*) noexcept = 0;
            virtual int32_t __stdcall SetText(void*) noexcept = 0;
            virtual int32_t __stdcall SetUri(void*) noexcept = 0;
            virtual int32_t __stdcall SetHtmlFormat(void*) noexcept = 0;
            virtual int32_t __stdcall get_ResourceMap(void**) noexcept = 0;
            virtual int32_t __stdcall SetRtf(void*) noexcept = 0;
            virtual int32_t __stdcall SetBitmap(void*) noexcept = 0;
            virtual int32_t __stdcall SetStorageItemsReadOnly(void*) noexcept = 0;
            virtual int32_t __stdcall SetStorageItems(void*, bool) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IDataPackage2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SetApplicationLink(void*) noexcept = 0;
            virtual int32_t __stdcall SetWebLink(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IDataPackage3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_ShareCompleted(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ShareCompleted(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IDataPackage4>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_ShareCanceled(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ShareCanceled(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySet>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Title(void**) noexcept = 0;
            virtual int32_t __stdcall put_Title(void*) noexcept = 0;
            virtual int32_t __stdcall get_Description(void**) noexcept = 0;
            virtual int32_t __stdcall put_Description(void*) noexcept = 0;
            virtual int32_t __stdcall get_Thumbnail(void**) noexcept = 0;
            virtual int32_t __stdcall put_Thumbnail(void*) noexcept = 0;
            virtual int32_t __stdcall get_FileTypes(void**) noexcept = 0;
            virtual int32_t __stdcall get_ApplicationName(void**) noexcept = 0;
            virtual int32_t __stdcall put_ApplicationName(void*) noexcept = 0;
            virtual int32_t __stdcall get_ApplicationListingUri(void**) noexcept = 0;
            virtual int32_t __stdcall put_ApplicationListingUri(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySet2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ContentSourceWebLink(void**) noexcept = 0;
            virtual int32_t __stdcall put_ContentSourceWebLink(void*) noexcept = 0;
            virtual int32_t __stdcall get_ContentSourceApplicationLink(void**) noexcept = 0;
            virtual int32_t __stdcall put_ContentSourceApplicationLink(void*) noexcept = 0;
            virtual int32_t __stdcall get_PackageFamilyName(void**) noexcept = 0;
            virtual int32_t __stdcall put_PackageFamilyName(void*) noexcept = 0;
            virtual int32_t __stdcall get_Square30x30Logo(void**) noexcept = 0;
            virtual int32_t __stdcall put_Square30x30Logo(void*) noexcept = 0;
            virtual int32_t __stdcall get_LogoBackgroundColor(struct struct_Windows_UI_Color*) noexcept = 0;
            virtual int32_t __stdcall put_LogoBackgroundColor(struct struct_Windows_UI_Color) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySet3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_EnterpriseId(void**) noexcept = 0;
            virtual int32_t __stdcall put_EnterpriseId(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySet4>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ContentSourceUserActivityJson(void**) noexcept = 0;
            virtual int32_t __stdcall put_ContentSourceUserActivityJson(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySetView>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Title(void**) noexcept = 0;
            virtual int32_t __stdcall get_Description(void**) noexcept = 0;
            virtual int32_t __stdcall get_Thumbnail(void**) noexcept = 0;
            virtual int32_t __stdcall get_FileTypes(void**) noexcept = 0;
            virtual int32_t __stdcall get_ApplicationName(void**) noexcept = 0;
            virtual int32_t __stdcall get_ApplicationListingUri(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySetView2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_PackageFamilyName(void**) noexcept = 0;
            virtual int32_t __stdcall get_ContentSourceWebLink(void**) noexcept = 0;
            virtual int32_t __stdcall get_ContentSourceApplicationLink(void**) noexcept = 0;
            virtual int32_t __stdcall get_Square30x30Logo(void**) noexcept = 0;
            virtual int32_t __stdcall get_LogoBackgroundColor(struct struct_Windows_UI_Color*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySetView3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_EnterpriseId(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySetView4>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ContentSourceUserActivityJson(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySetView5>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsFromRoamingClipboard(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IDataPackageView>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Properties(void**) noexcept = 0;
            virtual int32_t __stdcall get_RequestedOperation(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall ReportOperationCompleted(uint32_t) noexcept = 0;
            virtual int32_t __stdcall get_AvailableFormats(void**) noexcept = 0;
            virtual int32_t __stdcall Contains(void*, bool*) noexcept = 0;
            virtual int32_t __stdcall GetDataAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetTextAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetCustomTextAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetUriAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetHtmlFormatAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetResourceMapAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetRtfAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetBitmapAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetStorageItemsAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IDataPackageView2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetApplicationLinkAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetWebLinkAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IDataPackageView3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RequestAccessAsync(void**) noexcept = 0;
            virtual int32_t __stdcall RequestAccessWithEnterpriseIdAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall UnlockAndAssumeEnterpriseIdentity(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IDataPackageView4>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SetAcceptedFormatId(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IDataProviderDeferral>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Complete() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IDataProviderRequest>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_FormatId(void**) noexcept = 0;
            virtual int32_t __stdcall get_Deadline(int64_t*) noexcept = 0;
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
            virtual int32_t __stdcall SetData(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IDataRequest>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Data(void**) noexcept = 0;
            virtual int32_t __stdcall put_Data(void*) noexcept = 0;
            virtual int32_t __stdcall get_Deadline(int64_t*) noexcept = 0;
            virtual int32_t __stdcall FailWithDisplayText(void*) noexcept = 0;
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IDataRequestDeferral>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Complete() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IDataRequestedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Request(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IDataTransferManager>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_DataRequested(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_DataRequested(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_TargetApplicationChosen(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_TargetApplicationChosen(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IDataTransferManager2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_ShareProvidersRequested(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ShareProvidersRequested(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IDataTransferManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall ShowShareUI() noexcept = 0;
            virtual int32_t __stdcall GetForCurrentView(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IDataTransferManagerStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall IsSupported(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IDataTransferManagerStatics3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall ShowShareUIWithOptions(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IHtmlFormatHelperStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetStaticFragment(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateHtmlFormat(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IOperationCompletedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Operation(uint32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IOperationCompletedEventArgs2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AcceptedFormatId(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IShareCompletedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ShareTarget(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IShareProvider>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Title(void**) noexcept = 0;
            virtual int32_t __stdcall get_DisplayIcon(void**) noexcept = 0;
            virtual int32_t __stdcall get_BackgroundColor(struct struct_Windows_UI_Color*) noexcept = 0;
            virtual int32_t __stdcall get_Tag(void**) noexcept = 0;
            virtual int32_t __stdcall put_Tag(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IShareProviderFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(void*, void*, struct struct_Windows_UI_Color, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IShareProviderOperation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Data(void**) noexcept = 0;
            virtual int32_t __stdcall get_Provider(void**) noexcept = 0;
            virtual int32_t __stdcall ReportCompleted() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IShareProvidersRequestedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Providers(void**) noexcept = 0;
            virtual int32_t __stdcall get_Data(void**) noexcept = 0;
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IShareTargetInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AppUserModelId(void**) noexcept = 0;
            virtual int32_t __stdcall get_ShareProvider(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IShareUIOptions>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Theme(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Theme(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_SelectionRect(void**) noexcept = 0;
            virtual int32_t __stdcall put_SelectionRect(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::ISharedStorageAccessManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall AddFile(void*, void**) noexcept = 0;
            virtual int32_t __stdcall RedeemTokenForFileAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall RemoveFile(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IStandardDataFormatsStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Text(void**) noexcept = 0;
            virtual int32_t __stdcall get_Uri(void**) noexcept = 0;
            virtual int32_t __stdcall get_Html(void**) noexcept = 0;
            virtual int32_t __stdcall get_Rtf(void**) noexcept = 0;
            virtual int32_t __stdcall get_Bitmap(void**) noexcept = 0;
            virtual int32_t __stdcall get_StorageItems(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IStandardDataFormatsStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_WebLink(void**) noexcept = 0;
            virtual int32_t __stdcall get_ApplicationLink(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::IStandardDataFormatsStatics3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_UserActivityJsonArray(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::ITargetApplicationChosenEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ApplicationName(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::DataProviderHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::DataTransfer::ShareProviderHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IClipboardContentOptions
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsRoamable() const;
        LLM_IMPL_AUTO(void) IsRoamable(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsAllowedInHistory() const;
        LLM_IMPL_AUTO(void) IsAllowedInHistory(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) RoamingFormats() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) HistoryFormats() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IClipboardContentOptions>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IClipboardContentOptions<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IClipboardHistoryChangedEventArgs
    {
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IClipboardHistoryChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IClipboardHistoryChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IClipboardHistoryItem
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Id() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) Timestamp() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::DataTransfer::DataPackageView) Content() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IClipboardHistoryItem>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IClipboardHistoryItem<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IClipboardHistoryItemsResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::DataTransfer::ClipboardHistoryItemsResultStatus) Status() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::DataTransfer::ClipboardHistoryItem>) Items() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IClipboardHistoryItemsResult>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IClipboardHistoryItemsResult<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IClipboardStatics
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::DataTransfer::DataPackageView) GetContent() const;
        LLM_IMPL_AUTO(void) SetContent(llm::OS::ApplicationModel::DataTransfer::DataPackage const& content) const;
        LLM_IMPL_AUTO(void) Flush() const;
        LLM_IMPL_AUTO(void) Clear() const;
        LLM_IMPL_AUTO(llm::event_token) ContentChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const;
        using ContentChanged_revoker = impl::event_revoker<llm::OS::ApplicationModel::DataTransfer::IClipboardStatics, &impl::abi_t<llm::OS::ApplicationModel::DataTransfer::IClipboardStatics>::remove_ContentChanged>;
        [[nodiscard]] ContentChanged_revoker ContentChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) ContentChanged(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IClipboardStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IClipboardStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IClipboardStatics2
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::DataTransfer::ClipboardHistoryItemsResult>) GetHistoryItemsAsync() const;
        LLM_IMPL_AUTO(bool) ClearHistory() const;
        LLM_IMPL_AUTO(bool) DeleteItemFromHistory(llm::OS::ApplicationModel::DataTransfer::ClipboardHistoryItem const& item) const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::DataTransfer::SetHistoryItemAsContentStatus) SetHistoryItemAsContent(llm::OS::ApplicationModel::DataTransfer::ClipboardHistoryItem const& item) const;
        LLM_IMPL_AUTO(bool) IsHistoryEnabled() const;
        LLM_IMPL_AUTO(bool) IsRoamingEnabled() const;
        LLM_IMPL_AUTO(bool) SetContentWithOptions(llm::OS::ApplicationModel::DataTransfer::DataPackage const& content, llm::OS::ApplicationModel::DataTransfer::ClipboardContentOptions const& options) const;
        LLM_IMPL_AUTO(llm::event_token) HistoryChanged(llm::OS::Foundation::EventHandler<llm::OS::ApplicationModel::DataTransfer::ClipboardHistoryChangedEventArgs> const& handler) const;
        using HistoryChanged_revoker = impl::event_revoker<llm::OS::ApplicationModel::DataTransfer::IClipboardStatics2, &impl::abi_t<llm::OS::ApplicationModel::DataTransfer::IClipboardStatics2>::remove_HistoryChanged>;
        [[nodiscard]] HistoryChanged_revoker HistoryChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::ApplicationModel::DataTransfer::ClipboardHistoryChangedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) HistoryChanged(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) RoamingEnabledChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const;
        using RoamingEnabledChanged_revoker = impl::event_revoker<llm::OS::ApplicationModel::DataTransfer::IClipboardStatics2, &impl::abi_t<llm::OS::ApplicationModel::DataTransfer::IClipboardStatics2>::remove_RoamingEnabledChanged>;
        [[nodiscard]] RoamingEnabledChanged_revoker RoamingEnabledChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) RoamingEnabledChanged(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) HistoryEnabledChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const;
        using HistoryEnabledChanged_revoker = impl::event_revoker<llm::OS::ApplicationModel::DataTransfer::IClipboardStatics2, &impl::abi_t<llm::OS::ApplicationModel::DataTransfer::IClipboardStatics2>::remove_HistoryEnabledChanged>;
        [[nodiscard]] HistoryEnabledChanged_revoker HistoryEnabledChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) HistoryEnabledChanged(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IClipboardStatics2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IClipboardStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IDataPackage
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::DataTransfer::DataPackageView) GetView() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::DataTransfer::DataPackagePropertySet) Properties() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::DataTransfer::DataPackageOperation) RequestedOperation() const;
        LLM_IMPL_AUTO(void) RequestedOperation(llm::OS::ApplicationModel::DataTransfer::DataPackageOperation const& value) const;
        LLM_IMPL_AUTO(llm::event_token) OperationCompleted(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::DataTransfer::DataPackage, llm::OS::ApplicationModel::DataTransfer::OperationCompletedEventArgs> const& handler) const;
        using OperationCompleted_revoker = impl::event_revoker<llm::OS::ApplicationModel::DataTransfer::IDataPackage, &impl::abi_t<llm::OS::ApplicationModel::DataTransfer::IDataPackage>::remove_OperationCompleted>;
        [[nodiscard]] OperationCompleted_revoker OperationCompleted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::DataTransfer::DataPackage, llm::OS::ApplicationModel::DataTransfer::OperationCompletedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) OperationCompleted(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) Destroyed(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::DataTransfer::DataPackage, llm::OS::Foundation::IInspectable> const& handler) const;
        using Destroyed_revoker = impl::event_revoker<llm::OS::ApplicationModel::DataTransfer::IDataPackage, &impl::abi_t<llm::OS::ApplicationModel::DataTransfer::IDataPackage>::remove_Destroyed>;
        [[nodiscard]] Destroyed_revoker Destroyed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::DataTransfer::DataPackage, llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) Destroyed(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(void) SetData(param::hstring const& formatId, llm::OS::Foundation::IInspectable const& value) const;
        LLM_IMPL_AUTO(void) SetDataProvider(param::hstring const& formatId, llm::OS::ApplicationModel::DataTransfer::DataProviderHandler const& delayRenderer) const;
        LLM_IMPL_AUTO(void) SetText(param::hstring const& value) const;
        LLM_IMPL_AUTO(void) SetUri(llm::OS::Foundation::Uri const& value) const;
        LLM_IMPL_AUTO(void) SetHtmlFormat(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMap<hstring, llm::OS::Storage::Streams::RandomAccessStreamReference>) ResourceMap() const;
        LLM_IMPL_AUTO(void) SetRtf(param::hstring const& value) const;
        LLM_IMPL_AUTO(void) SetBitmap(llm::OS::Storage::Streams::RandomAccessStreamReference const& value) const;
        LLM_IMPL_AUTO(void) SetStorageItems(param::iterable<llm::OS::Storage::IStorageItem> const& value) const;
        LLM_IMPL_AUTO(void) SetStorageItems(param::iterable<llm::OS::Storage::IStorageItem> const& value, bool readOnly) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IDataPackage>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IDataPackage<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IDataPackage2
    {
        LLM_IMPL_AUTO(void) SetApplicationLink(llm::OS::Foundation::Uri const& value) const;
        LLM_IMPL_AUTO(void) SetWebLink(llm::OS::Foundation::Uri const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IDataPackage2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IDataPackage2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IDataPackage3
    {
        LLM_IMPL_AUTO(llm::event_token) ShareCompleted(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::DataTransfer::DataPackage, llm::OS::ApplicationModel::DataTransfer::ShareCompletedEventArgs> const& handler) const;
        using ShareCompleted_revoker = impl::event_revoker<llm::OS::ApplicationModel::DataTransfer::IDataPackage3, &impl::abi_t<llm::OS::ApplicationModel::DataTransfer::IDataPackage3>::remove_ShareCompleted>;
        [[nodiscard]] ShareCompleted_revoker ShareCompleted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::DataTransfer::DataPackage, llm::OS::ApplicationModel::DataTransfer::ShareCompletedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) ShareCompleted(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IDataPackage3>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IDataPackage3<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IDataPackage4
    {
        LLM_IMPL_AUTO(llm::event_token) ShareCanceled(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::DataTransfer::DataPackage, llm::OS::Foundation::IInspectable> const& handler) const;
        using ShareCanceled_revoker = impl::event_revoker<llm::OS::ApplicationModel::DataTransfer::IDataPackage4, &impl::abi_t<llm::OS::ApplicationModel::DataTransfer::IDataPackage4>::remove_ShareCanceled>;
        [[nodiscard]] ShareCanceled_revoker ShareCanceled(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::DataTransfer::DataPackage, llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) ShareCanceled(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IDataPackage4>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IDataPackage4<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IDataPackagePropertySet
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Title() const;
        LLM_IMPL_AUTO(void) Title(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Description() const;
        LLM_IMPL_AUTO(void) Description(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStreamReference) Thumbnail() const;
        LLM_IMPL_AUTO(void) Thumbnail(llm::OS::Storage::Streams::IRandomAccessStreamReference const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) FileTypes() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ApplicationName() const;
        LLM_IMPL_AUTO(void) ApplicationName(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Uri) ApplicationListingUri() const;
        LLM_IMPL_AUTO(void) ApplicationListingUri(llm::OS::Foundation::Uri const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySet>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IDataPackagePropertySet<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IDataPackagePropertySet2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Uri) ContentSourceWebLink() const;
        LLM_IMPL_AUTO(void) ContentSourceWebLink(llm::OS::Foundation::Uri const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Uri) ContentSourceApplicationLink() const;
        LLM_IMPL_AUTO(void) ContentSourceApplicationLink(llm::OS::Foundation::Uri const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) PackageFamilyName() const;
        LLM_IMPL_AUTO(void) PackageFamilyName(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStreamReference) Square30x30Logo() const;
        LLM_IMPL_AUTO(void) Square30x30Logo(llm::OS::Storage::Streams::IRandomAccessStreamReference const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Color) LogoBackgroundColor() const;
        LLM_IMPL_AUTO(void) LogoBackgroundColor(llm::OS::UI::Color const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySet2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IDataPackagePropertySet2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IDataPackagePropertySet3
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) EnterpriseId() const;
        LLM_IMPL_AUTO(void) EnterpriseId(param::hstring const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySet3>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IDataPackagePropertySet3<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IDataPackagePropertySet4
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ContentSourceUserActivityJson() const;
        LLM_IMPL_AUTO(void) ContentSourceUserActivityJson(param::hstring const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySet4>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IDataPackagePropertySet4<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IDataPackagePropertySetView
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Title() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Description() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::RandomAccessStreamReference) Thumbnail() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) FileTypes() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ApplicationName() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Uri) ApplicationListingUri() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySetView>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IDataPackagePropertySetView<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IDataPackagePropertySetView2
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) PackageFamilyName() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Uri) ContentSourceWebLink() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Uri) ContentSourceApplicationLink() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStreamReference) Square30x30Logo() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Color) LogoBackgroundColor() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySetView2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IDataPackagePropertySetView2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IDataPackagePropertySetView3
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) EnterpriseId() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySetView3>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IDataPackagePropertySetView3<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IDataPackagePropertySetView4
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ContentSourceUserActivityJson() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySetView4>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IDataPackagePropertySetView4<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IDataPackagePropertySetView5
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsFromRoamingClipboard() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySetView5>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IDataPackagePropertySetView5<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IDataPackageView
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::DataTransfer::DataPackagePropertySetView) Properties() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::DataTransfer::DataPackageOperation) RequestedOperation() const;
        LLM_IMPL_AUTO(void) ReportOperationCompleted(llm::OS::ApplicationModel::DataTransfer::DataPackageOperation const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) AvailableFormats() const;
        LLM_IMPL_AUTO(bool) Contains(param::hstring const& formatId) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::IInspectable>) GetDataAsync(param::hstring const& formatId) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<hstring>) GetTextAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<hstring>) GetTextAsync(param::hstring const& formatId) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Uri>) GetUriAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<hstring>) GetHtmlFormatAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Storage::Streams::RandomAccessStreamReference>>) GetResourceMapAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<hstring>) GetRtfAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::RandomAccessStreamReference>) GetBitmapAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::IStorageItem>>) GetStorageItemsAsync() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IDataPackageView>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IDataPackageView<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IDataPackageView2
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Uri>) GetApplicationLinkAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Uri>) GetWebLinkAsync() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IDataPackageView2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IDataPackageView2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IDataPackageView3
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::EnterpriseData::ProtectionPolicyEvaluationResult>) RequestAccessAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::EnterpriseData::ProtectionPolicyEvaluationResult>) RequestAccessAsync(param::hstring const& enterpriseId) const;
        LLM_IMPL_AUTO(llm::OS::Security::EnterpriseData::ProtectionPolicyEvaluationResult) UnlockAndAssumeEnterpriseIdentity() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IDataPackageView3>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IDataPackageView3<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IDataPackageView4
    {
        LLM_IMPL_AUTO(void) SetAcceptedFormatId(param::hstring const& formatId) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IDataPackageView4>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IDataPackageView4<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IDataProviderDeferral
    {
        LLM_IMPL_AUTO(void) Complete() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IDataProviderDeferral>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IDataProviderDeferral<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IDataProviderRequest
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) FormatId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) Deadline() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::DataTransfer::DataProviderDeferral) GetDeferral() const;
        LLM_IMPL_AUTO(void) SetData(llm::OS::Foundation::IInspectable const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IDataProviderRequest>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IDataProviderRequest<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IDataRequest
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::DataTransfer::DataPackage) Data() const;
        LLM_IMPL_AUTO(void) Data(llm::OS::ApplicationModel::DataTransfer::DataPackage const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) Deadline() const;
        LLM_IMPL_AUTO(void) FailWithDisplayText(param::hstring const& value) const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::DataTransfer::DataRequestDeferral) GetDeferral() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IDataRequest>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IDataRequest<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IDataRequestDeferral
    {
        LLM_IMPL_AUTO(void) Complete() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IDataRequestDeferral>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IDataRequestDeferral<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IDataRequestedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::DataTransfer::DataRequest) Request() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IDataRequestedEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IDataRequestedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IDataTransferManager
    {
        LLM_IMPL_AUTO(llm::event_token) DataRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::DataTransfer::DataTransferManager, llm::OS::ApplicationModel::DataTransfer::DataRequestedEventArgs> const& handler) const;
        using DataRequested_revoker = impl::event_revoker<llm::OS::ApplicationModel::DataTransfer::IDataTransferManager, &impl::abi_t<llm::OS::ApplicationModel::DataTransfer::IDataTransferManager>::remove_DataRequested>;
        [[nodiscard]] DataRequested_revoker DataRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::DataTransfer::DataTransferManager, llm::OS::ApplicationModel::DataTransfer::DataRequestedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) DataRequested(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) TargetApplicationChosen(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::DataTransfer::DataTransferManager, llm::OS::ApplicationModel::DataTransfer::TargetApplicationChosenEventArgs> const& handler) const;
        using TargetApplicationChosen_revoker = impl::event_revoker<llm::OS::ApplicationModel::DataTransfer::IDataTransferManager, &impl::abi_t<llm::OS::ApplicationModel::DataTransfer::IDataTransferManager>::remove_TargetApplicationChosen>;
        [[nodiscard]] TargetApplicationChosen_revoker TargetApplicationChosen(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::DataTransfer::DataTransferManager, llm::OS::ApplicationModel::DataTransfer::TargetApplicationChosenEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) TargetApplicationChosen(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IDataTransferManager>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IDataTransferManager<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IDataTransferManager2
    {
        LLM_IMPL_AUTO(llm::event_token) ShareProvidersRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::DataTransfer::DataTransferManager, llm::OS::ApplicationModel::DataTransfer::ShareProvidersRequestedEventArgs> const& handler) const;
        using ShareProvidersRequested_revoker = impl::event_revoker<llm::OS::ApplicationModel::DataTransfer::IDataTransferManager2, &impl::abi_t<llm::OS::ApplicationModel::DataTransfer::IDataTransferManager2>::remove_ShareProvidersRequested>;
        [[nodiscard]] ShareProvidersRequested_revoker ShareProvidersRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::DataTransfer::DataTransferManager, llm::OS::ApplicationModel::DataTransfer::ShareProvidersRequestedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) ShareProvidersRequested(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IDataTransferManager2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IDataTransferManager2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IDataTransferManagerStatics
    {
        LLM_IMPL_AUTO(void) ShowShareUI() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::DataTransfer::DataTransferManager) GetForCurrentView() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IDataTransferManagerStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IDataTransferManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IDataTransferManagerStatics2
    {
        LLM_IMPL_AUTO(bool) IsSupported() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IDataTransferManagerStatics2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IDataTransferManagerStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IDataTransferManagerStatics3
    {
        LLM_IMPL_AUTO(void) ShowShareUI(llm::OS::ApplicationModel::DataTransfer::ShareUIOptions const& options) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IDataTransferManagerStatics3>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IDataTransferManagerStatics3<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IHtmlFormatHelperStatics
    {
        LLM_IMPL_AUTO(hstring) GetStaticFragment(param::hstring const& htmlFormat) const;
        LLM_IMPL_AUTO(hstring) CreateHtmlFormat(param::hstring const& htmlFragment) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IHtmlFormatHelperStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IHtmlFormatHelperStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IOperationCompletedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::DataTransfer::DataPackageOperation) Operation() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IOperationCompletedEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IOperationCompletedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IOperationCompletedEventArgs2
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AcceptedFormatId() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IOperationCompletedEventArgs2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IOperationCompletedEventArgs2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IShareCompletedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::DataTransfer::ShareTargetInfo) ShareTarget() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IShareCompletedEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IShareCompletedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IShareProvider
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Title() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::RandomAccessStreamReference) DisplayIcon() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Color) BackgroundColor() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) Tag() const;
        LLM_IMPL_AUTO(void) Tag(llm::OS::Foundation::IInspectable const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IShareProvider>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IShareProvider<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IShareProviderFactory
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::DataTransfer::ShareProvider) Create(param::hstring const& title, llm::OS::Storage::Streams::RandomAccessStreamReference const& displayIcon, llm::OS::UI::Color const& backgroundColor, llm::OS::ApplicationModel::DataTransfer::ShareProviderHandler const& handler) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IShareProviderFactory>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IShareProviderFactory<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IShareProviderOperation
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::DataTransfer::DataPackageView) Data() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::DataTransfer::ShareProvider) Provider() const;
        LLM_IMPL_AUTO(void) ReportCompleted() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IShareProviderOperation>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IShareProviderOperation<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IShareProvidersRequestedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::DataTransfer::ShareProvider>) Providers() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::DataTransfer::DataPackageView) Data() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) GetDeferral() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IShareProvidersRequestedEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IShareProvidersRequestedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IShareTargetInfo
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AppUserModelId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::DataTransfer::ShareProvider) ShareProvider() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IShareTargetInfo>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IShareTargetInfo<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IShareUIOptions
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::DataTransfer::ShareUITheme) Theme() const;
        LLM_IMPL_AUTO(void) Theme(llm::OS::ApplicationModel::DataTransfer::ShareUITheme const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::Rect>) SelectionRect() const;
        LLM_IMPL_AUTO(void) SelectionRect(llm::OS::Foundation::IReference<llm::OS::Foundation::Rect> const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IShareUIOptions>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IShareUIOptions<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_ISharedStorageAccessManagerStatics
    {
        LLM_IMPL_AUTO(hstring) AddFile(llm::OS::Storage::IStorageFile const& file) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFile>) RedeemTokenForFileAsync(param::hstring const& token) const;
        LLM_IMPL_AUTO(void) RemoveFile(param::hstring const& token) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::ISharedStorageAccessManagerStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_ISharedStorageAccessManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IStandardDataFormatsStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Text() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Uri() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Html() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Rtf() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Bitmap() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) StorageItems() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IStandardDataFormatsStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IStandardDataFormatsStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IStandardDataFormatsStatics2
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) WebLink() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ApplicationLink() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IStandardDataFormatsStatics2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IStandardDataFormatsStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_IStandardDataFormatsStatics3
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) UserActivityJsonArray() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::IStandardDataFormatsStatics3>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_IStandardDataFormatsStatics3<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_DataTransfer_ITargetApplicationChosenEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ApplicationName() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::DataTransfer::ITargetApplicationChosenEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_DataTransfer_ITargetApplicationChosenEventArgs<D>;
    };
}
#endif
