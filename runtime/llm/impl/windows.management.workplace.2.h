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
#ifndef LLM_OS_Management_Workplace_2_H
#define LLM_OS_Management_Workplace_2_H
#include "llm/impl/Windows.Management.Workplace.1.h"
LLM_EXPORT namespace llm:OS::Management::Workplace
{
    struct MdmPolicy
    {
        MdmPolicy() = delete;
        static auto IsBrowserAllowed();
        static auto IsCameraAllowed();
        static auto IsMicrosoftAccountAllowed();
        static auto IsStoreAllowed();
        static auto GetMessagingSyncPolicy();
    };
    struct WorkplaceSettings
    {
        WorkplaceSettings() = delete;
        [[nodiscard]] static auto IsMicrosoftAccountOptional();
    };
}
#endif
