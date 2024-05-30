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
#ifndef LLM_OS_UI_Notifications_Management_2_H
#define LLM_OS_UI_Notifications_Management_2_H
#include "llm/impl/Windows.UI.Notifications.Management.1.h"
LLM_EXPORT namespace llm:OS::UI::Notifications::Management
{
    struct __declspec(empty_bases) UserNotificationListener : llm:OS::UI::Notifications::Management::IUserNotificationListener
    {
        UserNotificationListener(std::nullptr_t) noexcept {}
        UserNotificationListener(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Notifications::Management::IUserNotificationListener(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto Current();
    };
}
#endif
