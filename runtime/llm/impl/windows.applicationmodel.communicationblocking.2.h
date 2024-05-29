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
#ifndef LLM_OS_ApplicationModel_CommunicationBlocking_2_H
#define LLM_OS_ApplicationModel_CommunicationBlocking_2_H
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.ApplicationModel.CommunicationBlocking.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::CommunicationBlocking
{
    struct CommunicationBlockingAccessManager
    {
        CommunicationBlockingAccessManager() = delete;
        [[nodiscard]] static auto IsBlockingActive();
        static auto IsBlockedNumberAsync(param::hstring const& number);
        static auto ShowBlockNumbersUI(param::iterable<hstring> const& phoneNumbers);
        static auto ShowUnblockNumbersUI(param::iterable<hstring> const& phoneNumbers);
        static auto ShowBlockedCallsUI();
        static auto ShowBlockedMessagesUI();
    };
    struct CommunicationBlockingAppManager
    {
        CommunicationBlockingAppManager() = delete;
        [[nodiscard]] static auto IsCurrentAppActiveBlockingApp();
        static auto ShowCommunicationBlockingSettingsUI();
        static auto RequestSetAsActiveBlockingAppAsync();
    };
}
#endif
