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
#ifndef LLM_OS_Media_Capture_Core_1_H
#define LLM_OS_Media_Capture_Core_1_H
#include "llm/impl/Windows.Media.Capture.Core.0.h"
LLM_EXPORT namespace llm:OS::Media::Capture::Core
{
    struct __declspec(empty_bases) IVariablePhotoCapturedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVariablePhotoCapturedEventArgs>
    {
        IVariablePhotoCapturedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IVariablePhotoCapturedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVariablePhotoSequenceCapture :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVariablePhotoSequenceCapture>
    {
        IVariablePhotoSequenceCapture(std::nullptr_t = nullptr) noexcept {}
        IVariablePhotoSequenceCapture(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVariablePhotoSequenceCapture2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVariablePhotoSequenceCapture2>
    {
        IVariablePhotoSequenceCapture2(std::nullptr_t = nullptr) noexcept {}
        IVariablePhotoSequenceCapture2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
