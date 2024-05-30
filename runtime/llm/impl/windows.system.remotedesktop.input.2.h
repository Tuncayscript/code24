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
#ifndef LLM_OS_System_RemoteDesktop_Input_2_H
#define LLM_OS_System_RemoteDesktop_Input_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.System.RemoteDesktop.Input.1.h"
LLM_EXPORT namespace llm:OS::System::RemoteDesktop::Input
{
    struct RemoteTextConnectionDataHandler : llm:OS::Foundation::IUnknown
    {
        RemoteTextConnectionDataHandler(std::nullptr_t = nullptr) noexcept {}
        RemoteTextConnectionDataHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> RemoteTextConnectionDataHandler(L lambda);
        template <typename F> RemoteTextConnectionDataHandler(F* function);
        template <typename O, typename M> RemoteTextConnectionDataHandler(O* object, M method);
        template <typename O, typename M> RemoteTextConnectionDataHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> RemoteTextConnectionDataHandler(weak_ref<O>&& object, M method);
        auto operator()(array_view<uint8_t const> pduData) const;
    };
    struct __declspec(empty_bases) RemoteTextConnection : llm:OS::System::RemoteDesktop::Input::IRemoteTextConnection,
        impl::require<RemoteTextConnection, llm:OS::Foundation::IClosable>
    {
        RemoteTextConnection(std::nullptr_t) noexcept {}
        RemoteTextConnection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteDesktop::Input::IRemoteTextConnection(ptr, take_ownership_from_abi) {}
        RemoteTextConnection(llm::guid const& connectionId, llm:OS::System::RemoteDesktop::Input::RemoteTextConnectionDataHandler const& pduForwarder);
    };
}
#endif
