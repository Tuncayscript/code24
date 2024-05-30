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
#ifndef LLM_OS_Media_FaceAnalysis_2_H
#define LLM_OS_Media_FaceAnalysis_2_H
#include "llm/impl/Windows.Graphics.Imaging.1.h"
#include "llm/impl/Windows.Media.FaceAnalysis.1.h"
LLM_EXPORT namespace llm:OS::Media::FaceAnalysis
{
    struct __declspec(empty_bases) DetectedFace : llm:OS::Media::FaceAnalysis::IDetectedFace
    {
        DetectedFace(std::nullptr_t) noexcept {}
        DetectedFace(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::FaceAnalysis::IDetectedFace(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FaceDetector : llm:OS::Media::FaceAnalysis::IFaceDetector
    {
        FaceDetector(std::nullptr_t) noexcept {}
        FaceDetector(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::FaceAnalysis::IFaceDetector(ptr, take_ownership_from_abi) {}
        static auto CreateAsync();
        static auto GetSupportedBitmapPixelFormats();
        static auto IsBitmapPixelFormatSupported(llm:OS::Graphics::Imaging::BitmapPixelFormat const& bitmapPixelFormat);
        [[nodiscard]] static auto IsSupported();
    };
    struct __declspec(empty_bases) FaceTracker : llm:OS::Media::FaceAnalysis::IFaceTracker
    {
        FaceTracker(std::nullptr_t) noexcept {}
        FaceTracker(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::FaceAnalysis::IFaceTracker(ptr, take_ownership_from_abi) {}
        static auto CreateAsync();
        static auto GetSupportedBitmapPixelFormats();
        static auto IsBitmapPixelFormatSupported(llm:OS::Graphics::Imaging::BitmapPixelFormat const& bitmapPixelFormat);
        [[nodiscard]] static auto IsSupported();
    };
}
#endif
