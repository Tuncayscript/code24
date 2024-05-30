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
#ifndef LLM_OS_Graphics_Printing_Workflow_2_H
#define LLM_OS_Graphics_Printing_Workflow_2_H
#include "llm/impl/Windows.ApplicationModel.Activation.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.Graphics.Printing.Workflow.1.h"
LLM_EXPORT namespace llm:OS::Graphics::Printing::Workflow
{
    struct __declspec(empty_bases) PrintWorkflowBackgroundSession : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowBackgroundSession
    {
        PrintWorkflowBackgroundSession(std::nullptr_t) noexcept {}
        PrintWorkflowBackgroundSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowBackgroundSession(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintWorkflowBackgroundSetupRequestedEventArgs : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowBackgroundSetupRequestedEventArgs
    {
        PrintWorkflowBackgroundSetupRequestedEventArgs(std::nullptr_t) noexcept {}
        PrintWorkflowBackgroundSetupRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowBackgroundSetupRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintWorkflowConfiguration : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowConfiguration,
        impl::require<PrintWorkflowConfiguration, llm:OS::Graphics::Printing::Workflow::IPrintWorkflowConfiguration2>
    {
        PrintWorkflowConfiguration(std::nullptr_t) noexcept {}
        PrintWorkflowConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowConfiguration(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintWorkflowForegroundSession : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowForegroundSession
    {
        PrintWorkflowForegroundSession(std::nullptr_t) noexcept {}
        PrintWorkflowForegroundSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowForegroundSession(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintWorkflowForegroundSetupRequestedEventArgs : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowForegroundSetupRequestedEventArgs
    {
        PrintWorkflowForegroundSetupRequestedEventArgs(std::nullptr_t) noexcept {}
        PrintWorkflowForegroundSetupRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowForegroundSetupRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintWorkflowJobActivatedEventArgs : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowJobActivatedEventArgs,
        impl::require<PrintWorkflowJobActivatedEventArgs, llm:OS::ApplicationModel::Activation::IActivatedEventArgs, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        PrintWorkflowJobActivatedEventArgs(std::nullptr_t) noexcept {}
        PrintWorkflowJobActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowJobActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintWorkflowJobBackgroundSession : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowJobBackgroundSession
    {
        PrintWorkflowJobBackgroundSession(std::nullptr_t) noexcept {}
        PrintWorkflowJobBackgroundSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowJobBackgroundSession(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintWorkflowJobNotificationEventArgs : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowJobNotificationEventArgs
    {
        PrintWorkflowJobNotificationEventArgs(std::nullptr_t) noexcept {}
        PrintWorkflowJobNotificationEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowJobNotificationEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintWorkflowJobStartingEventArgs : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowJobStartingEventArgs
    {
        PrintWorkflowJobStartingEventArgs(std::nullptr_t) noexcept {}
        PrintWorkflowJobStartingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowJobStartingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintWorkflowJobTriggerDetails : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowJobTriggerDetails
    {
        PrintWorkflowJobTriggerDetails(std::nullptr_t) noexcept {}
        PrintWorkflowJobTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowJobTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintWorkflowJobUISession : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowJobUISession
    {
        PrintWorkflowJobUISession(std::nullptr_t) noexcept {}
        PrintWorkflowJobUISession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowJobUISession(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintWorkflowObjectModelSourceFileContent : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowObjectModelSourceFileContent
    {
        PrintWorkflowObjectModelSourceFileContent(std::nullptr_t) noexcept {}
        PrintWorkflowObjectModelSourceFileContent(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowObjectModelSourceFileContent(ptr, take_ownership_from_abi) {}
        explicit PrintWorkflowObjectModelSourceFileContent(llm:OS::Storage::Streams::IInputStream const& xpsStream);
    };
    struct __declspec(empty_bases) PrintWorkflowObjectModelTargetPackage : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowObjectModelTargetPackage
    {
        PrintWorkflowObjectModelTargetPackage(std::nullptr_t) noexcept {}
        PrintWorkflowObjectModelTargetPackage(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowObjectModelTargetPackage(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintWorkflowPdlConverter : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowPdlConverter,
        impl::require<PrintWorkflowPdlConverter, llm:OS::Graphics::Printing::Workflow::IPrintWorkflowPdlConverter2>
    {
        PrintWorkflowPdlConverter(std::nullptr_t) noexcept {}
        PrintWorkflowPdlConverter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowPdlConverter(ptr, take_ownership_from_abi) {}
        using llm:OS::Graphics::Printing::Workflow::IPrintWorkflowPdlConverter::ConvertPdlAsync;
        using impl::consume_t<PrintWorkflowPdlConverter, llm:OS::Graphics::Printing::Workflow::IPrintWorkflowPdlConverter2>::ConvertPdlAsync;
    };
    struct __declspec(empty_bases) PrintWorkflowPdlDataAvailableEventArgs : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowPdlDataAvailableEventArgs
    {
        PrintWorkflowPdlDataAvailableEventArgs(std::nullptr_t) noexcept {}
        PrintWorkflowPdlDataAvailableEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowPdlDataAvailableEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintWorkflowPdlModificationRequestedEventArgs : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowPdlModificationRequestedEventArgs,
        impl::require<PrintWorkflowPdlModificationRequestedEventArgs, llm:OS::Graphics::Printing::Workflow::IPrintWorkflowPdlModificationRequestedEventArgs2>
    {
        PrintWorkflowPdlModificationRequestedEventArgs(std::nullptr_t) noexcept {}
        PrintWorkflowPdlModificationRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowPdlModificationRequestedEventArgs(ptr, take_ownership_from_abi) {}
        using llm:OS::Graphics::Printing::Workflow::IPrintWorkflowPdlModificationRequestedEventArgs::CreateJobOnPrinterWithAttributes;
        using impl::consume_t<PrintWorkflowPdlModificationRequestedEventArgs, llm:OS::Graphics::Printing::Workflow::IPrintWorkflowPdlModificationRequestedEventArgs2>::CreateJobOnPrinterWithAttributes;
        using llm:OS::Graphics::Printing::Workflow::IPrintWorkflowPdlModificationRequestedEventArgs::CreateJobOnPrinterWithAttributesBuffer;
        using impl::consume_t<PrintWorkflowPdlModificationRequestedEventArgs, llm:OS::Graphics::Printing::Workflow::IPrintWorkflowPdlModificationRequestedEventArgs2>::CreateJobOnPrinterWithAttributesBuffer;
    };
    struct __declspec(empty_bases) PrintWorkflowPdlSourceContent : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowPdlSourceContent
    {
        PrintWorkflowPdlSourceContent(std::nullptr_t) noexcept {}
        PrintWorkflowPdlSourceContent(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowPdlSourceContent(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintWorkflowPdlTargetStream : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowPdlTargetStream
    {
        PrintWorkflowPdlTargetStream(std::nullptr_t) noexcept {}
        PrintWorkflowPdlTargetStream(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowPdlTargetStream(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintWorkflowPrinterJob : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowPrinterJob
    {
        PrintWorkflowPrinterJob(std::nullptr_t) noexcept {}
        PrintWorkflowPrinterJob(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowPrinterJob(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintWorkflowSourceContent : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowSourceContent
    {
        PrintWorkflowSourceContent(std::nullptr_t) noexcept {}
        PrintWorkflowSourceContent(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowSourceContent(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintWorkflowSpoolStreamContent : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowSpoolStreamContent
    {
        PrintWorkflowSpoolStreamContent(std::nullptr_t) noexcept {}
        PrintWorkflowSpoolStreamContent(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowSpoolStreamContent(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintWorkflowStreamTarget : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowStreamTarget
    {
        PrintWorkflowStreamTarget(std::nullptr_t) noexcept {}
        PrintWorkflowStreamTarget(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowStreamTarget(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintWorkflowSubmittedEventArgs : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowSubmittedEventArgs
    {
        PrintWorkflowSubmittedEventArgs(std::nullptr_t) noexcept {}
        PrintWorkflowSubmittedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowSubmittedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintWorkflowSubmittedOperation : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowSubmittedOperation
    {
        PrintWorkflowSubmittedOperation(std::nullptr_t) noexcept {}
        PrintWorkflowSubmittedOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowSubmittedOperation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintWorkflowTarget : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowTarget
    {
        PrintWorkflowTarget(std::nullptr_t) noexcept {}
        PrintWorkflowTarget(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowTarget(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintWorkflowTriggerDetails : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowTriggerDetails
    {
        PrintWorkflowTriggerDetails(std::nullptr_t) noexcept {}
        PrintWorkflowTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintWorkflowUIActivatedEventArgs : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowUIActivatedEventArgs
    {
        PrintWorkflowUIActivatedEventArgs(std::nullptr_t) noexcept {}
        PrintWorkflowUIActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowUIActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintWorkflowUILauncher : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowUILauncher
    {
        PrintWorkflowUILauncher(std::nullptr_t) noexcept {}
        PrintWorkflowUILauncher(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowUILauncher(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintWorkflowXpsDataAvailableEventArgs : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowXpsDataAvailableEventArgs
    {
        PrintWorkflowXpsDataAvailableEventArgs(std::nullptr_t) noexcept {}
        PrintWorkflowXpsDataAvailableEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::Workflow::IPrintWorkflowXpsDataAvailableEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
