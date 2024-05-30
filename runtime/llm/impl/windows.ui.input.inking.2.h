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
#ifndef LLM_OS_UI_Input_Inking_2_H
#define LLM_OS_UI_Input_Inking_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.UI.Input.Inking.1.h"
LLM_EXPORT namespace llm:OS::UI::Input::Inking
{
    struct __declspec(empty_bases) InkDrawingAttributes : llm:OS::UI::Input::Inking::IInkDrawingAttributes,
        impl::require<InkDrawingAttributes, llm:OS::UI::Input::Inking::IInkDrawingAttributes2, llm:OS::UI::Input::Inking::IInkDrawingAttributes3, llm:OS::UI::Input::Inking::IInkDrawingAttributes4, llm:OS::UI::Input::Inking::IInkDrawingAttributes5>
    {
        InkDrawingAttributes(std::nullptr_t) noexcept {}
        InkDrawingAttributes(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::IInkDrawingAttributes(ptr, take_ownership_from_abi) {}
        InkDrawingAttributes();
        static auto CreateForPencil();
    };
    struct __declspec(empty_bases) InkDrawingAttributesPencilProperties : llm:OS::UI::Input::Inking::IInkDrawingAttributesPencilProperties
    {
        InkDrawingAttributesPencilProperties(std::nullptr_t) noexcept {}
        InkDrawingAttributesPencilProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::IInkDrawingAttributesPencilProperties(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InkInputConfiguration : llm:OS::UI::Input::Inking::IInkInputConfiguration,
        impl::require<InkInputConfiguration, llm:OS::UI::Input::Inking::IInkInputConfiguration2>
    {
        InkInputConfiguration(std::nullptr_t) noexcept {}
        InkInputConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::IInkInputConfiguration(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InkInputProcessingConfiguration : llm:OS::UI::Input::Inking::IInkInputProcessingConfiguration
    {
        InkInputProcessingConfiguration(std::nullptr_t) noexcept {}
        InkInputProcessingConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::IInkInputProcessingConfiguration(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InkManager : llm:OS::UI::Input::Inking::IInkManager
    {
        InkManager(std::nullptr_t) noexcept {}
        InkManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::IInkManager(ptr, take_ownership_from_abi) {}
        InkManager();
    };
    struct __declspec(empty_bases) InkModelerAttributes : llm:OS::UI::Input::Inking::IInkModelerAttributes,
        impl::require<InkModelerAttributes, llm:OS::UI::Input::Inking::IInkModelerAttributes2>
    {
        InkModelerAttributes(std::nullptr_t) noexcept {}
        InkModelerAttributes(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::IInkModelerAttributes(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InkPoint : llm:OS::UI::Input::Inking::IInkPoint,
        impl::require<InkPoint, llm:OS::UI::Input::Inking::IInkPoint2>
    {
        InkPoint(std::nullptr_t) noexcept {}
        InkPoint(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::IInkPoint(ptr, take_ownership_from_abi) {}
        InkPoint(llm:OS::Foundation::Point const& position, float pressure);
        InkPoint(llm:OS::Foundation::Point const& position, float pressure, float tiltX, float tiltY, uint64_t timestamp);
    };
    struct __declspec(empty_bases) InkPresenter : llm:OS::UI::Input::Inking::IInkPresenter,
        impl::require<InkPresenter, llm:OS::UI::Input::Inking::IInkPresenter2, llm:OS::UI::Input::Inking::IInkPresenter3>
    {
        InkPresenter(std::nullptr_t) noexcept {}
        InkPresenter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::IInkPresenter(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InkPresenterProtractor : llm:OS::UI::Input::Inking::IInkPresenterProtractor
    {
        InkPresenterProtractor(std::nullptr_t) noexcept {}
        InkPresenterProtractor(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::IInkPresenterProtractor(ptr, take_ownership_from_abi) {}
        explicit InkPresenterProtractor(llm:OS::UI::Input::Inking::InkPresenter const& inkPresenter);
    };
    struct __declspec(empty_bases) InkPresenterRuler : llm:OS::UI::Input::Inking::IInkPresenterRuler,
        impl::require<InkPresenterRuler, llm:OS::UI::Input::Inking::IInkPresenterRuler2>
    {
        InkPresenterRuler(std::nullptr_t) noexcept {}
        InkPresenterRuler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::IInkPresenterRuler(ptr, take_ownership_from_abi) {}
        explicit InkPresenterRuler(llm:OS::UI::Input::Inking::InkPresenter const& inkPresenter);
    };
    struct __declspec(empty_bases) InkRecognitionResult : llm:OS::UI::Input::Inking::IInkRecognitionResult
    {
        InkRecognitionResult(std::nullptr_t) noexcept {}
        InkRecognitionResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::IInkRecognitionResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InkRecognizer : llm:OS::UI::Input::Inking::IInkRecognizer
    {
        InkRecognizer(std::nullptr_t) noexcept {}
        InkRecognizer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::IInkRecognizer(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InkRecognizerContainer : llm:OS::UI::Input::Inking::IInkRecognizerContainer
    {
        InkRecognizerContainer(std::nullptr_t) noexcept {}
        InkRecognizerContainer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::IInkRecognizerContainer(ptr, take_ownership_from_abi) {}
        InkRecognizerContainer();
    };
    struct __declspec(empty_bases) InkStroke : llm:OS::UI::Input::Inking::IInkStroke,
        impl::require<InkStroke, llm:OS::UI::Input::Inking::IInkStroke2, llm:OS::UI::Input::Inking::IInkStroke3, llm:OS::UI::Input::Inking::IInkStroke4>
    {
        InkStroke(std::nullptr_t) noexcept {}
        InkStroke(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::IInkStroke(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InkStrokeBuilder : llm:OS::UI::Input::Inking::IInkStrokeBuilder,
        impl::require<InkStrokeBuilder, llm:OS::UI::Input::Inking::IInkStrokeBuilder2, llm:OS::UI::Input::Inking::IInkStrokeBuilder3>
    {
        InkStrokeBuilder(std::nullptr_t) noexcept {}
        InkStrokeBuilder(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::IInkStrokeBuilder(ptr, take_ownership_from_abi) {}
        InkStrokeBuilder();
        using impl::consume_t<InkStrokeBuilder, llm:OS::UI::Input::Inking::IInkStrokeBuilder2>::CreateStrokeFromInkPoints;
        using impl::consume_t<InkStrokeBuilder, llm:OS::UI::Input::Inking::IInkStrokeBuilder3>::CreateStrokeFromInkPoints;
    };
    struct __declspec(empty_bases) InkStrokeContainer : llm:OS::UI::Input::Inking::IInkStrokeContainer,
        impl::require<InkStrokeContainer, llm:OS::UI::Input::Inking::IInkStrokeContainer2, llm:OS::UI::Input::Inking::IInkStrokeContainer3>
    {
        InkStrokeContainer(std::nullptr_t) noexcept {}
        InkStrokeContainer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::IInkStrokeContainer(ptr, take_ownership_from_abi) {}
        InkStrokeContainer();
        using llm:OS::UI::Input::Inking::IInkStrokeContainer::SaveAsync;
        using impl::consume_t<InkStrokeContainer, llm:OS::UI::Input::Inking::IInkStrokeContainer3>::SaveAsync;
    };
    struct __declspec(empty_bases) InkStrokeInput : llm:OS::UI::Input::Inking::IInkStrokeInput
    {
        InkStrokeInput(std::nullptr_t) noexcept {}
        InkStrokeInput(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::IInkStrokeInput(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InkStrokeRenderingSegment : llm:OS::UI::Input::Inking::IInkStrokeRenderingSegment
    {
        InkStrokeRenderingSegment(std::nullptr_t) noexcept {}
        InkStrokeRenderingSegment(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::IInkStrokeRenderingSegment(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InkStrokesCollectedEventArgs : llm:OS::UI::Input::Inking::IInkStrokesCollectedEventArgs
    {
        InkStrokesCollectedEventArgs(std::nullptr_t) noexcept {}
        InkStrokesCollectedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::IInkStrokesCollectedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InkStrokesErasedEventArgs : llm:OS::UI::Input::Inking::IInkStrokesErasedEventArgs
    {
        InkStrokesErasedEventArgs(std::nullptr_t) noexcept {}
        InkStrokesErasedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::IInkStrokesErasedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InkSynchronizer : llm:OS::UI::Input::Inking::IInkSynchronizer
    {
        InkSynchronizer(std::nullptr_t) noexcept {}
        InkSynchronizer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::IInkSynchronizer(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InkUnprocessedInput : llm:OS::UI::Input::Inking::IInkUnprocessedInput
    {
        InkUnprocessedInput(std::nullptr_t) noexcept {}
        InkUnprocessedInput(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::IInkUnprocessedInput(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PenAndInkSettings : llm:OS::UI::Input::Inking::IPenAndInkSettings,
        impl::require<PenAndInkSettings, llm:OS::UI::Input::Inking::IPenAndInkSettings2>
    {
        PenAndInkSettings(std::nullptr_t) noexcept {}
        PenAndInkSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::IPenAndInkSettings(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
    };
}
#endif
