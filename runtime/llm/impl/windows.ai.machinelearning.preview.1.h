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
#ifndef LLM_OS_AI_MachineLearning_Preview_1_H
#define LLM_OS_AI_MachineLearning_Preview_1_H
#include "llm/impl/Windows.Foundation.Collections.0.h"
#include "llm/impl/Windows.AI.MachineLearning.Preview.0.h"
LLM_EXPORT namespace llm::OS::AI::MachineLearning::Preview
{
    struct __declspec(empty_bases) IImageVariableDescriptorPreview :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IImageVariableDescriptorPreview>,
        impl::require<llm::OS::AI::MachineLearning::Preview::IImageVariableDescriptorPreview, llm::OS::AI::MachineLearning::Preview::ILearningModelVariableDescriptorPreview>
    {
        IImageVariableDescriptorPreview(std::nullptr_t = nullptr) noexcept {}
        IImageVariableDescriptorPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInferencingOptionsPreview :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IInferencingOptionsPreview>
    {
        IInferencingOptionsPreview(std::nullptr_t = nullptr) noexcept {}
        IInferencingOptionsPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILearningModelBindingPreview :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILearningModelBindingPreview>,
        impl::require<llm::OS::AI::MachineLearning::Preview::ILearningModelBindingPreview, llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, llm::OS::Foundation::IInspectable>>, llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>>
    {
        ILearningModelBindingPreview(std::nullptr_t = nullptr) noexcept {}
        ILearningModelBindingPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILearningModelBindingPreviewFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILearningModelBindingPreviewFactory>
    {
        ILearningModelBindingPreviewFactory(std::nullptr_t = nullptr) noexcept {}
        ILearningModelBindingPreviewFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILearningModelDescriptionPreview :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILearningModelDescriptionPreview>
    {
        ILearningModelDescriptionPreview(std::nullptr_t = nullptr) noexcept {}
        ILearningModelDescriptionPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILearningModelEvaluationResultPreview :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILearningModelEvaluationResultPreview>
    {
        ILearningModelEvaluationResultPreview(std::nullptr_t = nullptr) noexcept {}
        ILearningModelEvaluationResultPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILearningModelPreview :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILearningModelPreview>
    {
        ILearningModelPreview(std::nullptr_t = nullptr) noexcept {}
        ILearningModelPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILearningModelPreviewStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILearningModelPreviewStatics>
    {
        ILearningModelPreviewStatics(std::nullptr_t = nullptr) noexcept {}
        ILearningModelPreviewStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILearningModelVariableDescriptorPreview :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILearningModelVariableDescriptorPreview>
    {
        ILearningModelVariableDescriptorPreview(std::nullptr_t = nullptr) noexcept {}
        ILearningModelVariableDescriptorPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMapVariableDescriptorPreview :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IMapVariableDescriptorPreview>,
        impl::require<llm::OS::AI::MachineLearning::Preview::IMapVariableDescriptorPreview, llm::OS::AI::MachineLearning::Preview::ILearningModelVariableDescriptorPreview>
    {
        IMapVariableDescriptorPreview(std::nullptr_t = nullptr) noexcept {}
        IMapVariableDescriptorPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISequenceVariableDescriptorPreview :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISequenceVariableDescriptorPreview>,
        impl::require<llm::OS::AI::MachineLearning::Preview::ISequenceVariableDescriptorPreview, llm::OS::AI::MachineLearning::Preview::ILearningModelVariableDescriptorPreview>
    {
        ISequenceVariableDescriptorPreview(std::nullptr_t = nullptr) noexcept {}
        ISequenceVariableDescriptorPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorVariableDescriptorPreview :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorVariableDescriptorPreview>,
        impl::require<llm::OS::AI::MachineLearning::Preview::ITensorVariableDescriptorPreview, llm::OS::AI::MachineLearning::Preview::ILearningModelVariableDescriptorPreview>
    {
        ITensorVariableDescriptorPreview(std::nullptr_t = nullptr) noexcept {}
        ITensorVariableDescriptorPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases)IMatrixVariableDecriptorPreview :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IMatrixVariableDecriptorPreview>,
        impl::consume_t<llm::OS::AI::MachineLearning::Preview::IMatrixVariableDecriptorPreview, llm::OS::AI::MachineLearning::Preview::ILearningModelVariableDescriptorPreview>
    {
        IMatrixVariableDecriptorPreview(std:nullptr_t = nullptr) noexcept {}
        IMatrixVariableDecriptorPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
