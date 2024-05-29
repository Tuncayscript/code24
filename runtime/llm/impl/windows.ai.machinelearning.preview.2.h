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
#ifndef LLM_OS_AI_MachineLearning_Preview_2_H
#define LLM_OS_AI_MachineLearning_Preview_2_H
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Storage.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.AI.MachineLearning.Preview.1.h"
LLM_EXPORT namespace llm::OS::AI::MachineLearning::Preview
{
    struct __declspec(empty_bases) ImageVariableDescriptorPreview : llm::OS::AI::MachineLearning::Preview::IImageVariableDescriptorPreview
    {
        ImageVariableDescriptorPreview(std::nullptr_t) noexcept {}
        ImageVariableDescriptorPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::Preview::IImageVariableDescriptorPreview(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InferencingOptionsPreview : llm::OS::AI::MachineLearning::Preview::IInferencingOptionsPreview
    {
        InferencingOptionsPreview(std::nullptr_t) noexcept {}
        InferencingOptionsPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::Preview::IInferencingOptionsPreview(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LearningModelBindingPreview : llm::OS::AI::MachineLearning::Preview::ILearningModelBindingPreview
    {
        LearningModelBindingPreview(std::nullptr_t) noexcept {}
        LearningModelBindingPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::Preview::ILearningModelBindingPreview(ptr, take_ownership_from_abi) {}
        explicit LearningModelBindingPreview(llm::OS::AI::MachineLearning::Preview::LearningModelPreview const& model);
    };
    struct __declspec(empty_bases) LearningModelDescriptionPreview : llm::OS::AI::MachineLearning::Preview::ILearningModelDescriptionPreview
    {
        LearningModelDescriptionPreview(std::nullptr_t) noexcept {}
        LearningModelDescriptionPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::Preview::ILearningModelDescriptionPreview(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LearningModelEvaluationResultPreview : llm::OS::AI::MachineLearning::Preview::ILearningModelEvaluationResultPreview
    {
        LearningModelEvaluationResultPreview(std::nullptr_t) noexcept {}
        LearningModelEvaluationResultPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::Preview::ILearningModelEvaluationResultPreview(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LearningModelPreview : llm::OS::AI::MachineLearning::Preview::ILearningModelPreview
    {
        LearningModelPreview(std::nullptr_t) noexcept {}
        LearningModelPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::Preview::ILearningModelPreview(ptr, take_ownership_from_abi) {}
        static auto LoadModelFromStorageFileAsync(llm::OS::Storage::IStorageFile const& modelFile);
        static auto LoadModelFromStreamAsync(llm::OS::Storage::Streams::IRandomAccessStreamReference const& modelStream);
    };
    struct __declspec(empty_bases) LearningModelVariableDescriptorPreview : llm::OS::AI::MachineLearning::Preview::ILearningModelVariableDescriptorPreview
    {
        LearningModelVariableDescriptorPreview(std::nullptr_t) noexcept {}
        LearningModelVariableDescriptorPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::Preview::ILearningModelVariableDescriptorPreview(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MapVariableDescriptorPreview : llm::OS::AI::MachineLearning::Preview::IMapVariableDescriptorPreview
    {
        MapVariableDescriptorPreview(std::nullptr_t) noexcept {}
        MapVariableDescriptorPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::Preview::IMapVariableDescriptorPreview(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SequenceVariableDescriptorPreview : llm::OS::AI::MachineLearning::Preview::ISequenceVariableDescriptorPreview
    {
        SequenceVariableDescriptorPreview(std::nullptr_t) noexcept {}
        SequenceVariableDescriptorPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::Preview::ISequenceVariableDescriptorPreview(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TensorVariableDescriptorPreview : llm::OS::AI::MachineLearning::Preview::ITensorVariableDescriptorPreview
    {
        TensorVariableDescriptorPreview(std::nullptr_t) noexcept {}
        TensorVariableDescriptorPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::Preview::ITensorVariableDescriptorPreview(ptr, take_ownership_from_abi) {}
    };
}
#endif
