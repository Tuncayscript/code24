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
#ifndef LLM_OS_Devices_Portable_2_H
#define LLM_OS_Devices_Portable_2_H
#include "llm/impl/Windows.Devices.Portable.1.h"
LLM_EXPORT namespace llm::OS::Devices::Portable
{
    struct ServiceDevice
    {
        ServiceDevice() = delete;
        static auto GetDeviceSelector(llm::OS::Devices::Portable::ServiceDeviceType const& serviceType);
        static auto GetDeviceSelectorFromServiceId(llm::guid const& serviceId);
    };
    struct StorageDevice
    {
        StorageDevice() = delete;
        static auto FromId(param::hstring const& deviceId);
        static auto GetDeviceSelector();
    };
}
#endif
