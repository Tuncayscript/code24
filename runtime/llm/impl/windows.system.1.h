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
#ifndef LLM_OS_System_1_H
#define LLM_OS_System_1_H
#include "llm/impl/Windows.System.0.h"
LLM_EXPORT namespace llm:OS::System
{
    struct __declspec(empty_bases) IAppActivationResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppActivationResult>
    {
        IAppActivationResult(std::nullptr_t = nullptr) noexcept {}
        IAppActivationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppDiagnosticInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppDiagnosticInfo>
    {
        IAppDiagnosticInfo(std::nullptr_t = nullptr) noexcept {}
        IAppDiagnosticInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppDiagnosticInfo2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppDiagnosticInfo2>
    {
        IAppDiagnosticInfo2(std::nullptr_t = nullptr) noexcept {}
        IAppDiagnosticInfo2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppDiagnosticInfo3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppDiagnosticInfo3>
    {
        IAppDiagnosticInfo3(std::nullptr_t = nullptr) noexcept {}
        IAppDiagnosticInfo3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppDiagnosticInfoStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppDiagnosticInfoStatics>
    {
        IAppDiagnosticInfoStatics(std::nullptr_t = nullptr) noexcept {}
        IAppDiagnosticInfoStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppDiagnosticInfoStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppDiagnosticInfoStatics2>
    {
        IAppDiagnosticInfoStatics2(std::nullptr_t = nullptr) noexcept {}
        IAppDiagnosticInfoStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppDiagnosticInfoWatcher :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppDiagnosticInfoWatcher>
    {
        IAppDiagnosticInfoWatcher(std::nullptr_t = nullptr) noexcept {}
        IAppDiagnosticInfoWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppDiagnosticInfoWatcherEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppDiagnosticInfoWatcherEventArgs>
    {
        IAppDiagnosticInfoWatcherEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppDiagnosticInfoWatcherEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppExecutionStateChangeResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppExecutionStateChangeResult>
    {
        IAppExecutionStateChangeResult(std::nullptr_t = nullptr) noexcept {}
        IAppExecutionStateChangeResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppMemoryReport :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppMemoryReport>
    {
        IAppMemoryReport(std::nullptr_t = nullptr) noexcept {}
        IAppMemoryReport(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppMemoryReport2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppMemoryReport2>
    {
        IAppMemoryReport2(std::nullptr_t = nullptr) noexcept {}
        IAppMemoryReport2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppMemoryUsageLimitChangingEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppMemoryUsageLimitChangingEventArgs>
    {
        IAppMemoryUsageLimitChangingEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppMemoryUsageLimitChangingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppResourceGroupBackgroundTaskReport :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppResourceGroupBackgroundTaskReport>
    {
        IAppResourceGroupBackgroundTaskReport(std::nullptr_t = nullptr) noexcept {}
        IAppResourceGroupBackgroundTaskReport(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppResourceGroupInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppResourceGroupInfo>
    {
        IAppResourceGroupInfo(std::nullptr_t = nullptr) noexcept {}
        IAppResourceGroupInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppResourceGroupInfo2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppResourceGroupInfo2>
    {
        IAppResourceGroupInfo2(std::nullptr_t = nullptr) noexcept {}
        IAppResourceGroupInfo2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppResourceGroupInfoWatcher :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppResourceGroupInfoWatcher>
    {
        IAppResourceGroupInfoWatcher(std::nullptr_t = nullptr) noexcept {}
        IAppResourceGroupInfoWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppResourceGroupInfoWatcherEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppResourceGroupInfoWatcherEventArgs>
    {
        IAppResourceGroupInfoWatcherEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppResourceGroupInfoWatcherEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppResourceGroupInfoWatcherExecutionStateChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppResourceGroupInfoWatcherExecutionStateChangedEventArgs>
    {
        IAppResourceGroupInfoWatcherExecutionStateChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppResourceGroupInfoWatcherExecutionStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppResourceGroupMemoryReport :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppResourceGroupMemoryReport>
    {
        IAppResourceGroupMemoryReport(std::nullptr_t = nullptr) noexcept {}
        IAppResourceGroupMemoryReport(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppResourceGroupStateReport :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppResourceGroupStateReport>
    {
        IAppResourceGroupStateReport(std::nullptr_t = nullptr) noexcept {}
        IAppResourceGroupStateReport(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppUriHandlerHost :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppUriHandlerHost>
    {
        IAppUriHandlerHost(std::nullptr_t = nullptr) noexcept {}
        IAppUriHandlerHost(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppUriHandlerHost2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppUriHandlerHost2>
    {
        IAppUriHandlerHost2(std::nullptr_t = nullptr) noexcept {}
        IAppUriHandlerHost2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppUriHandlerHostFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppUriHandlerHostFactory>
    {
        IAppUriHandlerHostFactory(std::nullptr_t = nullptr) noexcept {}
        IAppUriHandlerHostFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppUriHandlerRegistration :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppUriHandlerRegistration>
    {
        IAppUriHandlerRegistration(std::nullptr_t = nullptr) noexcept {}
        IAppUriHandlerRegistration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppUriHandlerRegistration2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppUriHandlerRegistration2>
    {
        IAppUriHandlerRegistration2(std::nullptr_t = nullptr) noexcept {}
        IAppUriHandlerRegistration2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppUriHandlerRegistrationManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppUriHandlerRegistrationManager>
    {
        IAppUriHandlerRegistrationManager(std::nullptr_t = nullptr) noexcept {}
        IAppUriHandlerRegistrationManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppUriHandlerRegistrationManager2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppUriHandlerRegistrationManager2>
    {
        IAppUriHandlerRegistrationManager2(std::nullptr_t = nullptr) noexcept {}
        IAppUriHandlerRegistrationManager2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppUriHandlerRegistrationManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppUriHandlerRegistrationManagerStatics>
    {
        IAppUriHandlerRegistrationManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IAppUriHandlerRegistrationManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppUriHandlerRegistrationManagerStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppUriHandlerRegistrationManagerStatics2>
    {
        IAppUriHandlerRegistrationManagerStatics2(std::nullptr_t = nullptr) noexcept {}
        IAppUriHandlerRegistrationManagerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDateTimeSettingsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDateTimeSettingsStatics>
    {
        IDateTimeSettingsStatics(std::nullptr_t = nullptr) noexcept {}
        IDateTimeSettingsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDispatcherQueue :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDispatcherQueue>
    {
        IDispatcherQueue(std::nullptr_t = nullptr) noexcept {}
        IDispatcherQueue(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDispatcherQueue2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDispatcherQueue2>
    {
        IDispatcherQueue2(std::nullptr_t = nullptr) noexcept {}
        IDispatcherQueue2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDispatcherQueueController :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDispatcherQueueController>
    {
        IDispatcherQueueController(std::nullptr_t = nullptr) noexcept {}
        IDispatcherQueueController(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDispatcherQueueControllerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDispatcherQueueControllerStatics>
    {
        IDispatcherQueueControllerStatics(std::nullptr_t = nullptr) noexcept {}
        IDispatcherQueueControllerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDispatcherQueueShutdownStartingEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDispatcherQueueShutdownStartingEventArgs>
    {
        IDispatcherQueueShutdownStartingEventArgs(std::nullptr_t = nullptr) noexcept {}
        IDispatcherQueueShutdownStartingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDispatcherQueueStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDispatcherQueueStatics>
    {
        IDispatcherQueueStatics(std::nullptr_t = nullptr) noexcept {}
        IDispatcherQueueStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDispatcherQueueTimer :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDispatcherQueueTimer>
    {
        IDispatcherQueueTimer(std::nullptr_t = nullptr) noexcept {}
        IDispatcherQueueTimer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFolderLauncherOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFolderLauncherOptions>
    {
        IFolderLauncherOptions(std::nullptr_t = nullptr) noexcept {}
        IFolderLauncherOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKnownUserPropertiesStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKnownUserPropertiesStatics>
    {
        IKnownUserPropertiesStatics(std::nullptr_t = nullptr) noexcept {}
        IKnownUserPropertiesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKnownUserPropertiesStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKnownUserPropertiesStatics2>
    {
        IKnownUserPropertiesStatics2(std::nullptr_t = nullptr) noexcept {}
        IKnownUserPropertiesStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILaunchUriResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ILaunchUriResult>
    {
        ILaunchUriResult(std::nullptr_t = nullptr) noexcept {}
        ILaunchUriResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILauncherOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ILauncherOptions>
    {
        ILauncherOptions(std::nullptr_t = nullptr) noexcept {}
        ILauncherOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILauncherOptions2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ILauncherOptions2>
    {
        ILauncherOptions2(std::nullptr_t = nullptr) noexcept {}
        ILauncherOptions2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILauncherOptions3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ILauncherOptions3>
    {
        ILauncherOptions3(std::nullptr_t = nullptr) noexcept {}
        ILauncherOptions3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILauncherOptions4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ILauncherOptions4>
    {
        ILauncherOptions4(std::nullptr_t = nullptr) noexcept {}
        ILauncherOptions4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILauncherStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ILauncherStatics>
    {
        ILauncherStatics(std::nullptr_t = nullptr) noexcept {}
        ILauncherStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILauncherStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ILauncherStatics2>
    {
        ILauncherStatics2(std::nullptr_t = nullptr) noexcept {}
        ILauncherStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILauncherStatics3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ILauncherStatics3>
    {
        ILauncherStatics3(std::nullptr_t = nullptr) noexcept {}
        ILauncherStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILauncherStatics4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ILauncherStatics4>
    {
        ILauncherStatics4(std::nullptr_t = nullptr) noexcept {}
        ILauncherStatics4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILauncherStatics5 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ILauncherStatics5>
    {
        ILauncherStatics5(std::nullptr_t = nullptr) noexcept {}
        ILauncherStatics5(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILauncherUIOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ILauncherUIOptions>
    {
        ILauncherUIOptions(std::nullptr_t = nullptr) noexcept {}
        ILauncherUIOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILauncherViewOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ILauncherViewOptions>
    {
        ILauncherViewOptions(std::nullptr_t = nullptr) noexcept {}
        ILauncherViewOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMemoryManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMemoryManagerStatics>
    {
        IMemoryManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IMemoryManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMemoryManagerStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMemoryManagerStatics2>
    {
        IMemoryManagerStatics2(std::nullptr_t = nullptr) noexcept {}
        IMemoryManagerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMemoryManagerStatics3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMemoryManagerStatics3>
    {
        IMemoryManagerStatics3(std::nullptr_t = nullptr) noexcept {}
        IMemoryManagerStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMemoryManagerStatics4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMemoryManagerStatics4>
    {
        IMemoryManagerStatics4(std::nullptr_t = nullptr) noexcept {}
        IMemoryManagerStatics4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProcessLauncherOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProcessLauncherOptions>
    {
        IProcessLauncherOptions(std::nullptr_t = nullptr) noexcept {}
        IProcessLauncherOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProcessLauncherResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProcessLauncherResult>
    {
        IProcessLauncherResult(std::nullptr_t = nullptr) noexcept {}
        IProcessLauncherResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProcessLauncherStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProcessLauncherStatics>
    {
        IProcessLauncherStatics(std::nullptr_t = nullptr) noexcept {}
        IProcessLauncherStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProcessMemoryReport :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProcessMemoryReport>
    {
        IProcessMemoryReport(std::nullptr_t = nullptr) noexcept {}
        IProcessMemoryReport(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProtocolForResultsOperation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProtocolForResultsOperation>
    {
        IProtocolForResultsOperation(std::nullptr_t = nullptr) noexcept {}
        IProtocolForResultsOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRemoteLauncherOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRemoteLauncherOptions>
    {
        IRemoteLauncherOptions(std::nullptr_t = nullptr) noexcept {}
        IRemoteLauncherOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRemoteLauncherStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRemoteLauncherStatics>
    {
        IRemoteLauncherStatics(std::nullptr_t = nullptr) noexcept {}
        IRemoteLauncherStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IShutdownManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IShutdownManagerStatics>
    {
        IShutdownManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IShutdownManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IShutdownManagerStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IShutdownManagerStatics2>,
        impl::require<llm:OS::System::IShutdownManagerStatics2, llm:OS::System::IShutdownManagerStatics>
    {
        IShutdownManagerStatics2(std::nullptr_t = nullptr) noexcept {}
        IShutdownManagerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITimeZoneSettingsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITimeZoneSettingsStatics>
    {
        ITimeZoneSettingsStatics(std::nullptr_t = nullptr) noexcept {}
        ITimeZoneSettingsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITimeZoneSettingsStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITimeZoneSettingsStatics2>
    {
        ITimeZoneSettingsStatics2(std::nullptr_t = nullptr) noexcept {}
        ITimeZoneSettingsStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUser :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUser>
    {
        IUser(std::nullptr_t = nullptr) noexcept {}
        IUser(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUser2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUser2>
    {
        IUser2(std::nullptr_t = nullptr) noexcept {}
        IUser2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserAuthenticationStatusChangeDeferral :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUserAuthenticationStatusChangeDeferral>
    {
        IUserAuthenticationStatusChangeDeferral(std::nullptr_t = nullptr) noexcept {}
        IUserAuthenticationStatusChangeDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserAuthenticationStatusChangingEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUserAuthenticationStatusChangingEventArgs>
    {
        IUserAuthenticationStatusChangingEventArgs(std::nullptr_t = nullptr) noexcept {}
        IUserAuthenticationStatusChangingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUserChangedEventArgs>
    {
        IUserChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IUserChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserChangedEventArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUserChangedEventArgs2>
    {
        IUserChangedEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IUserChangedEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDeviceAssociationChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUserDeviceAssociationChangedEventArgs>
    {
        IUserDeviceAssociationChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IUserDeviceAssociationChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDeviceAssociationStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUserDeviceAssociationStatics>
    {
        IUserDeviceAssociationStatics(std::nullptr_t = nullptr) noexcept {}
        IUserDeviceAssociationStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserPicker :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUserPicker>
    {
        IUserPicker(std::nullptr_t = nullptr) noexcept {}
        IUserPicker(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserPickerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUserPickerStatics>
    {
        IUserPickerStatics(std::nullptr_t = nullptr) noexcept {}
        IUserPickerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUserStatics>
    {
        IUserStatics(std::nullptr_t = nullptr) noexcept {}
        IUserStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUserStatics2>
    {
        IUserStatics2(std::nullptr_t = nullptr) noexcept {}
        IUserStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserWatcher :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUserWatcher>
    {
        IUserWatcher(std::nullptr_t = nullptr) noexcept {}
        IUserWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
