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
#ifndef LLM_OS_ApplicationModel_DataTransfer_DragDrop_Core_1_H
#define LLM_OS_ApplicationModel_DataTransfer_DragDrop_Core_1_H
#include "llm/impl/Windows.ApplicationModel.DataTransfer.DragDrop.Core.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::DataTransfer::DragDrop::Core
{
    struct __declspec(empty_bases) ICoreDragDropManager :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICoreDragDropManager>
    {
        ICoreDragDropManager(std::nullptr_t = nullptr) noexcept {}
        ICoreDragDropManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreDragDropManagerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICoreDragDropManagerStatics>
    {
        ICoreDragDropManagerStatics(std::nullptr_t = nullptr) noexcept {}
        ICoreDragDropManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreDragInfo :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICoreDragInfo>
    {
        ICoreDragInfo(std::nullptr_t = nullptr) noexcept {}
        ICoreDragInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreDragInfo2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICoreDragInfo2>,
        impl::require<llm::OS::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragInfo2, llm::OS::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragInfo>
    {
        ICoreDragInfo2(std::nullptr_t = nullptr) noexcept {}
        ICoreDragInfo2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreDragOperation :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICoreDragOperation>
    {
        ICoreDragOperation(std::nullptr_t = nullptr) noexcept {}
        ICoreDragOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreDragOperation2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICoreDragOperation2>,
        impl::require<llm::OS::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragOperation2, llm::OS::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragOperation>
    {
        ICoreDragOperation2(std::nullptr_t = nullptr) noexcept {}
        ICoreDragOperation2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreDragUIOverride :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICoreDragUIOverride>
    {
        ICoreDragUIOverride(std::nullptr_t = nullptr) noexcept {}
        ICoreDragUIOverride(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreDropOperationTarget :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICoreDropOperationTarget>
    {
        ICoreDropOperationTarget(std::nullptr_t = nullptr) noexcept {}
        ICoreDropOperationTarget(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreDropOperationTargetRequestedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICoreDropOperationTargetRequestedEventArgs>
    {
        ICoreDropOperationTargetRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICoreDropOperationTargetRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
