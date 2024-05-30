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
#ifndef LLM_OS_UI_Input_Inking_1_H
#define LLM_OS_UI_Input_Inking_1_H
#include "llm/impl/Windows.UI.Input.Inking.0.h"
LLM_EXPORT namespace llm:OS::UI::Input::Inking
{
    struct __declspec(empty_bases) IInkDrawingAttributes :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkDrawingAttributes>
    {
        IInkDrawingAttributes(std::nullptr_t = nullptr) noexcept {}
        IInkDrawingAttributes(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkDrawingAttributes2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkDrawingAttributes2>
    {
        IInkDrawingAttributes2(std::nullptr_t = nullptr) noexcept {}
        IInkDrawingAttributes2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkDrawingAttributes3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkDrawingAttributes3>
    {
        IInkDrawingAttributes3(std::nullptr_t = nullptr) noexcept {}
        IInkDrawingAttributes3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkDrawingAttributes4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkDrawingAttributes4>
    {
        IInkDrawingAttributes4(std::nullptr_t = nullptr) noexcept {}
        IInkDrawingAttributes4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkDrawingAttributes5 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkDrawingAttributes5>
    {
        IInkDrawingAttributes5(std::nullptr_t = nullptr) noexcept {}
        IInkDrawingAttributes5(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkDrawingAttributesPencilProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkDrawingAttributesPencilProperties>
    {
        IInkDrawingAttributesPencilProperties(std::nullptr_t = nullptr) noexcept {}
        IInkDrawingAttributesPencilProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkDrawingAttributesStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkDrawingAttributesStatics>
    {
        IInkDrawingAttributesStatics(std::nullptr_t = nullptr) noexcept {}
        IInkDrawingAttributesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkInputConfiguration :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkInputConfiguration>
    {
        IInkInputConfiguration(std::nullptr_t = nullptr) noexcept {}
        IInkInputConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkInputConfiguration2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkInputConfiguration2>
    {
        IInkInputConfiguration2(std::nullptr_t = nullptr) noexcept {}
        IInkInputConfiguration2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkInputProcessingConfiguration :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkInputProcessingConfiguration>
    {
        IInkInputProcessingConfiguration(std::nullptr_t = nullptr) noexcept {}
        IInkInputProcessingConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkManager>,
        impl::require<llm:OS::UI::Input::Inking::IInkManager, llm:OS::UI::Input::Inking::IInkStrokeContainer, llm:OS::UI::Input::Inking::IInkRecognizerContainer>
    {
        IInkManager(std::nullptr_t = nullptr) noexcept {}
        IInkManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        using impl::consume_t<IInkManager, IInkManager>::RecognizeAsync;
        using impl::consume_t<IInkManager, llm:OS::UI::Input::Inking::IInkRecognizerContainer>::RecognizeAsync;
    };
    struct __declspec(empty_bases) IInkModelerAttributes :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkModelerAttributes>
    {
        IInkModelerAttributes(std::nullptr_t = nullptr) noexcept {}
        IInkModelerAttributes(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkModelerAttributes2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkModelerAttributes2>
    {
        IInkModelerAttributes2(std::nullptr_t = nullptr) noexcept {}
        IInkModelerAttributes2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkPoint :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkPoint>
    {
        IInkPoint(std::nullptr_t = nullptr) noexcept {}
        IInkPoint(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkPoint2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkPoint2>
    {
        IInkPoint2(std::nullptr_t = nullptr) noexcept {}
        IInkPoint2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkPointFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkPointFactory>
    {
        IInkPointFactory(std::nullptr_t = nullptr) noexcept {}
        IInkPointFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkPointFactory2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkPointFactory2>
    {
        IInkPointFactory2(std::nullptr_t = nullptr) noexcept {}
        IInkPointFactory2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkPresenter :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkPresenter>
    {
        IInkPresenter(std::nullptr_t = nullptr) noexcept {}
        IInkPresenter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkPresenter2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkPresenter2>,
        impl::require<llm:OS::UI::Input::Inking::IInkPresenter2, llm:OS::UI::Input::Inking::IInkPresenter>
    {
        IInkPresenter2(std::nullptr_t = nullptr) noexcept {}
        IInkPresenter2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkPresenter3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkPresenter3>
    {
        IInkPresenter3(std::nullptr_t = nullptr) noexcept {}
        IInkPresenter3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkPresenterProtractor :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkPresenterProtractor>,
        impl::require<llm:OS::UI::Input::Inking::IInkPresenterProtractor, llm:OS::UI::Input::Inking::IInkPresenterStencil>
    {
        IInkPresenterProtractor(std::nullptr_t = nullptr) noexcept {}
        IInkPresenterProtractor(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkPresenterProtractorFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkPresenterProtractorFactory>
    {
        IInkPresenterProtractorFactory(std::nullptr_t = nullptr) noexcept {}
        IInkPresenterProtractorFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkPresenterRuler :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkPresenterRuler>,
        impl::require<llm:OS::UI::Input::Inking::IInkPresenterRuler, llm:OS::UI::Input::Inking::IInkPresenterStencil>
    {
        IInkPresenterRuler(std::nullptr_t = nullptr) noexcept {}
        IInkPresenterRuler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkPresenterRuler2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkPresenterRuler2>
    {
        IInkPresenterRuler2(std::nullptr_t = nullptr) noexcept {}
        IInkPresenterRuler2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkPresenterRulerFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkPresenterRulerFactory>
    {
        IInkPresenterRulerFactory(std::nullptr_t = nullptr) noexcept {}
        IInkPresenterRulerFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkPresenterStencil :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkPresenterStencil>
    {
        IInkPresenterStencil(std::nullptr_t = nullptr) noexcept {}
        IInkPresenterStencil(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkRecognitionResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkRecognitionResult>
    {
        IInkRecognitionResult(std::nullptr_t = nullptr) noexcept {}
        IInkRecognitionResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkRecognizer :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkRecognizer>
    {
        IInkRecognizer(std::nullptr_t = nullptr) noexcept {}
        IInkRecognizer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkRecognizerContainer :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkRecognizerContainer>
    {
        IInkRecognizerContainer(std::nullptr_t = nullptr) noexcept {}
        IInkRecognizerContainer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkStroke :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkStroke>
    {
        IInkStroke(std::nullptr_t = nullptr) noexcept {}
        IInkStroke(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkStroke2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkStroke2>
    {
        IInkStroke2(std::nullptr_t = nullptr) noexcept {}
        IInkStroke2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkStroke3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkStroke3>
    {
        IInkStroke3(std::nullptr_t = nullptr) noexcept {}
        IInkStroke3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkStroke4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkStroke4>
    {
        IInkStroke4(std::nullptr_t = nullptr) noexcept {}
        IInkStroke4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkStrokeBuilder :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkStrokeBuilder>
    {
        IInkStrokeBuilder(std::nullptr_t = nullptr) noexcept {}
        IInkStrokeBuilder(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkStrokeBuilder2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkStrokeBuilder2>
    {
        IInkStrokeBuilder2(std::nullptr_t = nullptr) noexcept {}
        IInkStrokeBuilder2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkStrokeBuilder3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkStrokeBuilder3>
    {
        IInkStrokeBuilder3(std::nullptr_t = nullptr) noexcept {}
        IInkStrokeBuilder3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkStrokeContainer :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkStrokeContainer>
    {
        IInkStrokeContainer(std::nullptr_t = nullptr) noexcept {}
        IInkStrokeContainer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkStrokeContainer2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkStrokeContainer2>
    {
        IInkStrokeContainer2(std::nullptr_t = nullptr) noexcept {}
        IInkStrokeContainer2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkStrokeContainer3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkStrokeContainer3>
    {
        IInkStrokeContainer3(std::nullptr_t = nullptr) noexcept {}
        IInkStrokeContainer3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkStrokeInput :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkStrokeInput>
    {
        IInkStrokeInput(std::nullptr_t = nullptr) noexcept {}
        IInkStrokeInput(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkStrokeRenderingSegment :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkStrokeRenderingSegment>
    {
        IInkStrokeRenderingSegment(std::nullptr_t = nullptr) noexcept {}
        IInkStrokeRenderingSegment(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkStrokesCollectedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkStrokesCollectedEventArgs>
    {
        IInkStrokesCollectedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IInkStrokesCollectedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkStrokesErasedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkStrokesErasedEventArgs>
    {
        IInkStrokesErasedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IInkStrokesErasedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkSynchronizer :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkSynchronizer>
    {
        IInkSynchronizer(std::nullptr_t = nullptr) noexcept {}
        IInkSynchronizer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInkUnprocessedInput :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInkUnprocessedInput>
    {
        IInkUnprocessedInput(std::nullptr_t = nullptr) noexcept {}
        IInkUnprocessedInput(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPenAndInkSettings :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPenAndInkSettings>
    {
        IPenAndInkSettings(std::nullptr_t = nullptr) noexcept {}
        IPenAndInkSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPenAndInkSettings2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPenAndInkSettings2>
    {
        IPenAndInkSettings2(std::nullptr_t = nullptr) noexcept {}
        IPenAndInkSettings2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPenAndInkSettingsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPenAndInkSettingsStatics>
    {
        IPenAndInkSettingsStatics(std::nullptr_t = nullptr) noexcept {}
        IPenAndInkSettingsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
