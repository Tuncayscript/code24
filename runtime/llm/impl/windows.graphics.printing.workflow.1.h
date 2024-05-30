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
#ifndef LLM_OS_Graphics_Printing_Workflow_1_H
#define LLM_OS_Graphics_Printing_Workflow_1_H
#include "llm/impl/Windows.ApplicationModel.Activation.0.h"
#include "llm/impl/Windows.Graphics.Printing.Workflow.0.h"
LLM_EXPORT namespace llm:OS::Graphics::Printing::Workflow
{
    struct __declspec(empty_bases) IPrintWorkflowBackgroundSession :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowBackgroundSession>
    {
        IPrintWorkflowBackgroundSession(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowBackgroundSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintWorkflowBackgroundSetupRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowBackgroundSetupRequestedEventArgs>
    {
        IPrintWorkflowBackgroundSetupRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowBackgroundSetupRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintWorkflowConfiguration :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowConfiguration>
    {
        IPrintWorkflowConfiguration(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintWorkflowConfiguration2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowConfiguration2>
    {
        IPrintWorkflowConfiguration2(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowConfiguration2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintWorkflowForegroundSession :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowForegroundSession>
    {
        IPrintWorkflowForegroundSession(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowForegroundSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintWorkflowForegroundSetupRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowForegroundSetupRequestedEventArgs>
    {
        IPrintWorkflowForegroundSetupRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowForegroundSetupRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintWorkflowJobActivatedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowJobActivatedEventArgs>
    {
        IPrintWorkflowJobActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowJobActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintWorkflowJobBackgroundSession :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowJobBackgroundSession>
    {
        IPrintWorkflowJobBackgroundSession(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowJobBackgroundSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintWorkflowJobNotificationEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowJobNotificationEventArgs>
    {
        IPrintWorkflowJobNotificationEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowJobNotificationEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintWorkflowJobStartingEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowJobStartingEventArgs>
    {
        IPrintWorkflowJobStartingEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowJobStartingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintWorkflowJobTriggerDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowJobTriggerDetails>
    {
        IPrintWorkflowJobTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowJobTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintWorkflowJobUISession :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowJobUISession>
    {
        IPrintWorkflowJobUISession(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowJobUISession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintWorkflowObjectModelSourceFileContent :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowObjectModelSourceFileContent>
    {
        IPrintWorkflowObjectModelSourceFileContent(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowObjectModelSourceFileContent(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintWorkflowObjectModelSourceFileContentFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowObjectModelSourceFileContentFactory>
    {
        IPrintWorkflowObjectModelSourceFileContentFactory(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowObjectModelSourceFileContentFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintWorkflowObjectModelTargetPackage :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowObjectModelTargetPackage>
    {
        IPrintWorkflowObjectModelTargetPackage(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowObjectModelTargetPackage(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintWorkflowPdlConverter :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowPdlConverter>
    {
        IPrintWorkflowPdlConverter(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowPdlConverter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintWorkflowPdlConverter2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowPdlConverter2>
    {
        IPrintWorkflowPdlConverter2(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowPdlConverter2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintWorkflowPdlDataAvailableEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowPdlDataAvailableEventArgs>
    {
        IPrintWorkflowPdlDataAvailableEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowPdlDataAvailableEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintWorkflowPdlModificationRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowPdlModificationRequestedEventArgs>
    {
        IPrintWorkflowPdlModificationRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowPdlModificationRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintWorkflowPdlModificationRequestedEventArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowPdlModificationRequestedEventArgs2>
    {
        IPrintWorkflowPdlModificationRequestedEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowPdlModificationRequestedEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintWorkflowPdlSourceContent :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowPdlSourceContent>
    {
        IPrintWorkflowPdlSourceContent(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowPdlSourceContent(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintWorkflowPdlTargetStream :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowPdlTargetStream>
    {
        IPrintWorkflowPdlTargetStream(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowPdlTargetStream(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintWorkflowPrinterJob :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowPrinterJob>
    {
        IPrintWorkflowPrinterJob(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowPrinterJob(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintWorkflowSourceContent :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowSourceContent>
    {
        IPrintWorkflowSourceContent(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowSourceContent(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintWorkflowSpoolStreamContent :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowSpoolStreamContent>
    {
        IPrintWorkflowSpoolStreamContent(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowSpoolStreamContent(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintWorkflowStreamTarget :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowStreamTarget>
    {
        IPrintWorkflowStreamTarget(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowStreamTarget(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintWorkflowSubmittedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowSubmittedEventArgs>
    {
        IPrintWorkflowSubmittedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowSubmittedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintWorkflowSubmittedOperation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowSubmittedOperation>
    {
        IPrintWorkflowSubmittedOperation(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowSubmittedOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintWorkflowTarget :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowTarget>
    {
        IPrintWorkflowTarget(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowTarget(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintWorkflowTriggerDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowTriggerDetails>
    {
        IPrintWorkflowTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintWorkflowUIActivatedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowUIActivatedEventArgs>,
        impl::require<llm:OS::Graphics::Printing::Workflow::IPrintWorkflowUIActivatedEventArgs, llm:OS::ApplicationModel::Activation::IActivatedEventArgs, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        IPrintWorkflowUIActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowUIActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintWorkflowUILauncher :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowUILauncher>
    {
        IPrintWorkflowUILauncher(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowUILauncher(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintWorkflowXpsDataAvailableEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintWorkflowXpsDataAvailableEventArgs>
    {
        IPrintWorkflowXpsDataAvailableEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPrintWorkflowXpsDataAvailableEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
