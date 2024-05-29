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
#ifndef LLM_OS_AI_MachineLearning_1_H
#define LLM_OS_AI_MachineLearning_1_H
#include "llm/impl/Windows.AI.MachineLearning.0.h"
LLM_EXPORT namespace llm::OS::AI::MachineLearning
{
    struct __declspec(empty_bases) IImageFeatureDescriptor :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IImageFeatureDescriptor>
    {
        IImageFeatureDescriptor(std::nullptr_t = nullptr) noexcept {}
        IImageFeatureDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IImageFeatureDescriptor2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IImageFeatureDescriptor2>
    {
        IImageFeatureDescriptor2(std::nullptr_t = nullptr) noexcept {}
        IImageFeatureDescriptor2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IImageFeatureValue :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IImageFeatureValue>
    {
        IImageFeatureValue(std::nullptr_t = nullptr) noexcept {}
        IImageFeatureValue(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IImageFeatureValueStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IImageFeatureValueStatics>
    {
        IImageFeatureValueStatics(std::nullptr_t = nullptr) noexcept {}
        IImageFeatureValueStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILearningModel :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILearningModel>
    {
        ILearningModel(std::nullptr_t = nullptr) noexcept {}
        ILearningModel(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILearningModelBinding :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILearningModelBinding>
    {
        ILearningModelBinding(std::nullptr_t = nullptr) noexcept {}
        ILearningModelBinding(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILearningModelBindingFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILearningModelBindingFactory>
    {
        ILearningModelBindingFactory(std::nullptr_t = nullptr) noexcept {}
        ILearningModelBindingFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILearningModelDevice :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILearningModelDevice>
    {
        ILearningModelDevice(std::nullptr_t = nullptr) noexcept {}
        ILearningModelDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILearningModelDeviceFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILearningModelDeviceFactory>
    {
        ILearningModelDeviceFactory(std::nullptr_t = nullptr) noexcept {}
        ILearningModelDeviceFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILearningModelDeviceStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILearningModelDeviceStatics>
    {
        ILearningModelDeviceStatics(std::nullptr_t = nullptr) noexcept {}
        ILearningModelDeviceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILearningModelEvaluationResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILearningModelEvaluationResult>
    {
        ILearningModelEvaluationResult(std::nullptr_t = nullptr) noexcept {}
        ILearningModelEvaluationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILearningModelFeatureDescriptor :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILearningModelFeatureDescriptor>
    {
        ILearningModelFeatureDescriptor(std::nullptr_t = nullptr) noexcept {}
        ILearningModelFeatureDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILearningModelFeatureValue :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILearningModelFeatureValue>
    {
        ILearningModelFeatureValue(std::nullptr_t = nullptr) noexcept {}
        ILearningModelFeatureValue(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILearningModelOperatorProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILearningModelOperatorProvider>
    {
        ILearningModelOperatorProvider(std::nullptr_t = nullptr) noexcept {}
        ILearningModelOperatorProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILearningModelSession :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILearningModelSession>
    {
        ILearningModelSession(std::nullptr_t = nullptr) noexcept {}
        ILearningModelSession(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILearningModelSessionFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILearningModelSessionFactory>
    {
        ILearningModelSessionFactory(std::nullptr_t = nullptr) noexcept {}
        ILearningModelSessionFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILearningModelSessionFactory2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILearningModelSessionFactory2>
    {
        ILearningModelSessionFactory2(std::nullptr_t = nullptr) noexcept {}
        ILearningModelSessionFactory2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILearningModelSessionOptions :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILearningModelSessionOptions>
    {
        ILearningModelSessionOptions(std::nullptr_t = nullptr) noexcept {}
        ILearningModelSessionOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILearningModelSessionOptions2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILearningModelSessionOptions2>
    {
        ILearningModelSessionOptions2(std::nullptr_t = nullptr) noexcept {}
        ILearningModelSessionOptions2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILearningModelSessionOptions3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILearningModelSessionOptions3>
    {
        ILearningModelSessionOptions3(std::nullptr_t = nullptr) noexcept {}
        ILearningModelSessionOptions3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILearningModelStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILearningModelStatics>
    {
        ILearningModelStatics(std::nullptr_t = nullptr) noexcept {}
        ILearningModelStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMapFeatureDescriptor :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IMapFeatureDescriptor>
    {
        IMapFeatureDescriptor(std::nullptr_t = nullptr) noexcept {}
        IMapFeatureDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISequenceFeatureDescriptor :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISequenceFeatureDescriptor>
    {
        ISequenceFeatureDescriptor(std::nullptr_t = nullptr) noexcept {}
        ISequenceFeatureDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensor :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensor>,
        impl::require<llm::OS::AI::MachineLearning::ITensor, llm::OS::AI::MachineLearning::ILearningModelFeatureValue>
    {
        ITensor(std::nullptr_t = nullptr) noexcept {}
        ITensor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorBoolean :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorBoolean>
    {
        ITensorBoolean(std::nullptr_t = nullptr) noexcept {}
        ITensorBoolean(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorBooleanStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorBooleanStatics>
    {
        ITensorBooleanStatics(std::nullptr_t = nullptr) noexcept {}
        ITensorBooleanStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorBooleanStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorBooleanStatics2>
    {
        ITensorBooleanStatics2(std::nullptr_t = nullptr) noexcept {}
        ITensorBooleanStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorDouble :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorDouble>
    {
        ITensorDouble(std::nullptr_t = nullptr) noexcept {}
        ITensorDouble(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorDoubleStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorDoubleStatics>
    {
        ITensorDoubleStatics(std::nullptr_t = nullptr) noexcept {}
        ITensorDoubleStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorDoubleStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorDoubleStatics2>
    {
        ITensorDoubleStatics2(std::nullptr_t = nullptr) noexcept {}
        ITensorDoubleStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorFeatureDescriptor :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorFeatureDescriptor>
    {
        ITensorFeatureDescriptor(std::nullptr_t = nullptr) noexcept {}
        ITensorFeatureDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorFloat :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorFloat>
    {
        ITensorFloat(std::nullptr_t = nullptr) noexcept {}
        ITensorFloat(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorFloat16Bit :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorFloat16Bit>
    {
        ITensorFloat16Bit(std::nullptr_t = nullptr) noexcept {}
        ITensorFloat16Bit(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorFloat16BitStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorFloat16BitStatics>
    {
        ITensorFloat16BitStatics(std::nullptr_t = nullptr) noexcept {}
        ITensorFloat16BitStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorFloat16BitStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorFloat16BitStatics2>
    {
        ITensorFloat16BitStatics2(std::nullptr_t = nullptr) noexcept {}
        ITensorFloat16BitStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorFloatStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorFloatStatics>
    {
        ITensorFloatStatics(std::nullptr_t = nullptr) noexcept {}
        ITensorFloatStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorFloatStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorFloatStatics2>
    {
        ITensorFloatStatics2(std::nullptr_t = nullptr) noexcept {}
        ITensorFloatStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorInt16Bit :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorInt16Bit>
    {
        ITensorInt16Bit(std::nullptr_t = nullptr) noexcept {}
        ITensorInt16Bit(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorInt16BitStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorInt16BitStatics>
    {
        ITensorInt16BitStatics(std::nullptr_t = nullptr) noexcept {}
        ITensorInt16BitStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorInt16BitStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorInt16BitStatics2>
    {
        ITensorInt16BitStatics2(std::nullptr_t = nullptr) noexcept {}
        ITensorInt16BitStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorInt32Bit :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorInt32Bit>
    {
        ITensorInt32Bit(std::nullptr_t = nullptr) noexcept {}
        ITensorInt32Bit(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorInt32BitStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorInt32BitStatics>
    {
        ITensorInt32BitStatics(std::nullptr_t = nullptr) noexcept {}
        ITensorInt32BitStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorInt32BitStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorInt32BitStatics2>
    {
        ITensorInt32BitStatics2(std::nullptr_t = nullptr) noexcept {}
        ITensorInt32BitStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorInt64Bit :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorInt64Bit>
    {
        ITensorInt64Bit(std::nullptr_t = nullptr) noexcept {}
        ITensorInt64Bit(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorInt64BitStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorInt64BitStatics>
    {
        ITensorInt64BitStatics(std::nullptr_t = nullptr) noexcept {}
        ITensorInt64BitStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorInt64BitStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorInt64BitStatics2>
    {
        ITensorInt64BitStatics2(std::nullptr_t = nullptr) noexcept {}
        ITensorInt64BitStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorInt8Bit :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorInt8Bit>
    {
        ITensorInt8Bit(std::nullptr_t = nullptr) noexcept {}
        ITensorInt8Bit(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorInt8BitStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorInt8BitStatics>
    {
        ITensorInt8BitStatics(std::nullptr_t = nullptr) noexcept {}
        ITensorInt8BitStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorInt8BitStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorInt8BitStatics2>
    {
        ITensorInt8BitStatics2(std::nullptr_t = nullptr) noexcept {}
        ITensorInt8BitStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorString :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorString>
    {
        ITensorString(std::nullptr_t = nullptr) noexcept {}
        ITensorString(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorStringStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorStringStatics>
    {
        ITensorStringStatics(std::nullptr_t = nullptr) noexcept {}
        ITensorStringStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorStringStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorStringStatics2>
    {
        ITensorStringStatics2(std::nullptr_t = nullptr) noexcept {}
        ITensorStringStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorUInt16Bit :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorUInt16Bit>
    {
        ITensorUInt16Bit(std::nullptr_t = nullptr) noexcept {}
        ITensorUInt16Bit(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorUInt16BitStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorUInt16BitStatics>
    {
        ITensorUInt16BitStatics(std::nullptr_t = nullptr) noexcept {}
        ITensorUInt16BitStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorUInt16BitStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorUInt16BitStatics2>
    {
        ITensorUInt16BitStatics2(std::nullptr_t = nullptr) noexcept {}
        ITensorUInt16BitStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorUInt32Bit :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorUInt32Bit>
    {
        ITensorUInt32Bit(std::nullptr_t = nullptr) noexcept {}
        ITensorUInt32Bit(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorUInt32BitStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorUInt32BitStatics>
    {
        ITensorUInt32BitStatics(std::nullptr_t = nullptr) noexcept {}
        ITensorUInt32BitStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorUInt32BitStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorUInt32BitStatics2>
    {
        ITensorUInt32BitStatics2(std::nullptr_t = nullptr) noexcept {}
        ITensorUInt32BitStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorUInt64Bit :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorUInt64Bit>
    {
        ITensorUInt64Bit(std::nullptr_t = nullptr) noexcept {}
        ITensorUInt64Bit(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorUInt64BitStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorUInt64BitStatics>
    {
        ITensorUInt64BitStatics(std::nullptr_t = nullptr) noexcept {}
        ITensorUInt64BitStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorUInt64BitStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorUInt64BitStatics2>
    {
        ITensorUInt64BitStatics2(std::nullptr_t = nullptr) noexcept {}
        ITensorUInt64BitStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorUInt8Bit :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorUInt8Bit>
    {
        ITensorUInt8Bit(std::nullptr_t = nullptr) noexcept {}
        ITensorUInt8Bit(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorUInt8BitStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorUInt8BitStatics>
    {
        ITensorUInt8BitStatics(std::nullptr_t = nullptr) noexcept {}
        ITensorUInt8BitStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITensorUInt8BitStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITensorUInt8BitStatics2>
    {
        ITensorUInt8BitStatics2(std::nullptr_t = nullptr) noexcept {}
        ITensorUInt8BitStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
