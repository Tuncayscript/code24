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
#ifndef LLM_OS_Management_2_H
#define LLM_OS_Management_2_H
#include "llm/impl/Windows.Management.1.h"
LLM_EXPORT namespace llm:OS::Management
{
    struct __declspec(empty_bases) MdmAlert : llm:OS::Management::IMdmAlert
    {
        MdmAlert(std::nullptr_t) noexcept {}
        MdmAlert(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::IMdmAlert(ptr, take_ownership_from_abi) {}
        MdmAlert();
    };
    struct __declspec(empty_bases) MdmSession : llm:OS::Management::IMdmSession
    {
        MdmSession(std::nullptr_t) noexcept {}
        MdmSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::IMdmSession(ptr, take_ownership_from_abi) {}
    };
    struct MdmSessionManager
    {
        MdmSessionManager() = delete;
        [[nodiscard]] static auto SessionIds();
        static auto TryCreateSession();
        static auto DeleteSessionById(param::hstring const& sessionId);
        static auto GetSessionById(param::hstring const& sessionId);
    };
}
#endif
