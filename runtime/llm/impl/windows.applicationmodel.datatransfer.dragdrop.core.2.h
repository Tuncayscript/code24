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
#ifndef LLM_OS_ApplicationModel_DataTransfer_DragDrop_Core_2_H
#define LLM_OS_ApplicationModel_DataTransfer_DragDrop_Core_2_H
#include "llm/impl/Windows.ApplicationModel.DataTransfer.DragDrop.Core.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::DataTransfer::DragDrop::Core
{
    struct __declspec(empty_bases) CoreDragDropManager : llm::OS::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragDropManager
    {
        CoreDragDropManager(std::nullptr_t) noexcept {}
        CoreDragDropManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragDropManager(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
    };
    struct __declspec(empty_bases) CoreDragInfo : llm::OS::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragInfo,
        impl::require<CoreDragInfo, llm::OS::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragInfo2>
    {
        CoreDragInfo(std::nullptr_t) noexcept {}
        CoreDragInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CoreDragOperation : llm::OS::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragOperation,
        impl::require<CoreDragOperation, llm::OS::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragOperation2>
    {
        CoreDragOperation(std::nullptr_t) noexcept {}
        CoreDragOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragOperation(ptr, take_ownership_from_abi) {}
        CoreDragOperation();
    };
    struct __declspec(empty_bases) CoreDragUIOverride : llm::OS::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragUIOverride
    {
        CoreDragUIOverride(std::nullptr_t) noexcept {}
        CoreDragUIOverride(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragUIOverride(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CoreDropOperationTargetRequestedEventArgs : llm::OS::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDropOperationTargetRequestedEventArgs
    {
        CoreDropOperationTargetRequestedEventArgs(std::nullptr_t) noexcept {}
        CoreDropOperationTargetRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDropOperationTargetRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
