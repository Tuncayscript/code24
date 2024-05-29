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
#ifndef LLM_OS_AI_MachineLearning_2_H
#define LLM_OS_AI_MachineLearning_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Graphics.DirectX.Direct3D11.1.h"
#include "llm/impl/Windows.Media.1.h"
#include "llm/impl/Windows.Storage.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.AI.MachineLearning.1.h"
LLM_EXPORT namespace llm::OS::AI::MachineLearning
{
    struct __declspec(empty_bases) ImageFeatureDescriptor : llm::OS::AI::MachineLearning::IImageFeatureDescriptor,
        impl::require<ImageFeatureDescriptor, llm::OS::AI::MachineLearning::IImageFeatureDescriptor2, llm::OS::AI::MachineLearning::ILearningModelFeatureDescriptor>
    {
        ImageFeatureDescriptor(std::nullptr_t) noexcept {}
        ImageFeatureDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::IImageFeatureDescriptor(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ImageFeatureValue : llm::OS::AI::MachineLearning::IImageFeatureValue,
        impl::require<ImageFeatureValue, llm::OS::AI::MachineLearning::ILearningModelFeatureValue>
    {
        ImageFeatureValue(std::nullptr_t) noexcept {}
        ImageFeatureValue(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::IImageFeatureValue(ptr, take_ownership_from_abi) {}
        static auto CreateFromVideoFrame(llm::OS::Media::VideoFrame const& image);
    };
    struct __declspec(empty_bases) LearningModel : llm::OS::AI::MachineLearning::ILearningModel,
        impl::require<LearningModel, llm::OS::Foundation::IClosable>
    {
        LearningModel(std::nullptr_t) noexcept {}
        LearningModel(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::ILearningModel(ptr, take_ownership_from_abi) {}
        static auto LoadFromStorageFileAsync(llm::OS::Storage::IStorageFile const& modelFile);
        static auto LoadFromStreamAsync(llm::OS::Storage::Streams::IRandomAccessStreamReference const& modelStream);
        static auto LoadFromFilePath(param::hstring const& filePath);
        static auto LoadFromStream(llm::OS::Storage::Streams::IRandomAccessStreamReference const& modelStream);
        static auto LoadFromStorageFileAsync(llm::OS::Storage::IStorageFile const& modelFile, llm::OS::AI::MachineLearning::ILearningModelOperatorProvider const& operatorProvider);
        static auto LoadFromStreamAsync(llm::OS::Storage::Streams::IRandomAccessStreamReference const& modelStream, llm::OS::AI::MachineLearning::ILearningModelOperatorProvider const& operatorProvider);
        static auto LoadFromFilePath(param::hstring const& filePath, llm::OS::AI::MachineLearning::ILearningModelOperatorProvider const& operatorProvider);
        static auto LoadFromStream(llm::OS::Storage::Streams::IRandomAccessStreamReference const& modelStream, llm::OS::AI::MachineLearning::ILearningModelOperatorProvider const& operatorProvider);
    };
    struct __declspec(empty_bases) LearningModelBinding : llm::OS::AI::MachineLearning::ILearningModelBinding,
        impl::require<LearningModelBinding, llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, llm::OS::Foundation::IInspectable>>, llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>>
    {
        LearningModelBinding(std::nullptr_t) noexcept {}
        LearningModelBinding(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::ILearningModelBinding(ptr, take_ownership_from_abi) {}
        explicit LearningModelBinding(llm::OS::AI::MachineLearning::LearningModelSession const& session);
    };
    struct __declspec(empty_bases) LearningModelDevice : llm::OS::AI::MachineLearning::ILearningModelDevice
    {
        LearningModelDevice(std::nullptr_t) noexcept {}
        LearningModelDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::ILearningModelDevice(ptr, take_ownership_from_abi) {}
        explicit LearningModelDevice(llm::OS::AI::MachineLearning::LearningModelDeviceKind const& deviceKind);
        static auto CreateFromDirect3D11Device(llm::OS::Graphics::DirectX::Direct3D11::IDirect3DDevice const& device);
    };
    struct __declspec(empty_bases) LearningModelEvaluationResult : llm::OS::AI::MachineLearning::ILearningModelEvaluationResult
    {
        LearningModelEvaluationResult(std::nullptr_t) noexcept {}
        LearningModelEvaluationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::ILearningModelEvaluationResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LearningModelSession : llm::OS::AI::MachineLearning::ILearningModelSession,
        impl::require<LearningModelSession, llm::OS::Foundation::IClosable>
    {
        LearningModelSession(std::nullptr_t) noexcept {}
        LearningModelSession(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::ILearningModelSession(ptr, take_ownership_from_abi) {}
        explicit LearningModelSession(llm::OS::AI::MachineLearning::LearningModel const& model);
        LearningModelSession(llm::OS::AI::MachineLearning::LearningModel const& model, llm::OS::AI::MachineLearning::LearningModelDevice const& deviceToRunOn);
        LearningModelSession(llm::OS::AI::MachineLearning::LearningModel const& model, llm::OS::AI::MachineLearning::LearningModelDevice const& deviceToRunOn, llm::OS::AI::MachineLearning::LearningModelSessionOptions const& learningModelSessionOptions);
    };
    struct __declspec(empty_bases) LearningModelSessionOptions : llm::OS::AI::MachineLearning::ILearningModelSessionOptions,
        impl::require<LearningModelSessionOptions, llm::OS::AI::MachineLearning::ILearningModelSessionOptions2, llm::OS::AI::MachineLearning::ILearningModelSessionOptions3>
    {
        LearningModelSessionOptions(std::nullptr_t) noexcept {}
        LearningModelSessionOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::ILearningModelSessionOptions(ptr, take_ownership_from_abi) {}
        LearningModelSessionOptions();
    };
    struct __declspec(empty_bases) MapFeatureDescriptor : llm::OS::AI::MachineLearning::IMapFeatureDescriptor,
        impl::require<MapFeatureDescriptor, llm::OS::AI::MachineLearning::ILearningModelFeatureDescriptor>
    {
        MapFeatureDescriptor(std::nullptr_t) noexcept {}
        MapFeatureDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::IMapFeatureDescriptor(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SequenceFeatureDescriptor : llm::OS::AI::MachineLearning::ISequenceFeatureDescriptor,
        impl::require<SequenceFeatureDescriptor, llm::OS::AI::MachineLearning::ILearningModelFeatureDescriptor>
    {
        SequenceFeatureDescriptor(std::nullptr_t) noexcept {}
        SequenceFeatureDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::ISequenceFeatureDescriptor(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TensorBoolean : llm::OS::AI::MachineLearning::ITensorBoolean,
        impl::require<TensorBoolean, llm::OS::AI::MachineLearning::ILearningModelFeatureValue, llm::OS::AI::MachineLearning::ITensor, llm::OS::Foundation::IClosable, llm::OS::Foundation::IMemoryBuffer>
    {
        TensorBoolean(std::nullptr_t) noexcept {}
        TensorBoolean(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::ITensorBoolean(ptr, take_ownership_from_abi) {}
        static auto Create();
        static auto Create(param::iterable<int64_t> const& shape);
        static auto CreateFromArray(param::iterable<int64_t> const& shape, array_view<bool const> data);
        static auto CreateFromIterable(param::iterable<int64_t> const& shape, param::iterable<bool> const& data);
        static auto CreateFromShapeArrayAndDataArray(array_view<int64_t const> shape, array_view<bool const> data);
        static auto CreateFromBuffer(array_view<int64_t const> shape, llm::OS::Storage::Streams::IBuffer const& buffer);
    };
    struct __declspec(empty_bases) TensorDouble : llm::OS::AI::MachineLearning::ITensorDouble,
        impl::require<TensorDouble, llm::OS::AI::MachineLearning::ILearningModelFeatureValue, llm::OS::AI::MachineLearning::ITensor, llm::OS::Foundation::IClosable, llm::OS::Foundation::IMemoryBuffer>
    {
        TensorDouble(std::nullptr_t) noexcept {}
        TensorDouble(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::ITensorDouble(ptr, take_ownership_from_abi) {}
        static auto Create();
        static auto Create(param::iterable<int64_t> const& shape);
        static auto CreateFromArray(param::iterable<int64_t> const& shape, array_view<double const> data);
        static auto CreateFromIterable(param::iterable<int64_t> const& shape, param::iterable<double> const& data);
        static auto CreateFromShapeArrayAndDataArray(array_view<int64_t const> shape, array_view<double const> data);
        static auto CreateFromBuffer(array_view<int64_t const> shape, llm::OS::Storage::Streams::IBuffer const& buffer);
    };
    struct __declspec(empty_bases) TensorFeatureDescriptor : llm::OS::AI::MachineLearning::ITensorFeatureDescriptor,
        impl::require<TensorFeatureDescriptor, llm::OS::AI::MachineLearning::ILearningModelFeatureDescriptor>
    {
        TensorFeatureDescriptor(std::nullptr_t) noexcept {}
        TensorFeatureDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::ITensorFeatureDescriptor(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TensorFloat : llm::OS::AI::MachineLearning::ITensorFloat,
        impl::require<TensorFloat, llm::OS::AI::MachineLearning::ILearningModelFeatureValue, llm::OS::AI::MachineLearning::ITensor, llm::OS::Foundation::IClosable, llm::OS::Foundation::IMemoryBuffer>
    {
        TensorFloat(std::nullptr_t) noexcept {}
        TensorFloat(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::ITensorFloat(ptr, take_ownership_from_abi) {}
        static auto Create();
        static auto Create(param::iterable<int64_t> const& shape);
        static auto CreateFromArray(param::iterable<int64_t> const& shape, array_view<float const> data);
        static auto CreateFromIterable(param::iterable<int64_t> const& shape, param::iterable<float> const& data);
        static auto CreateFromShapeArrayAndDataArray(array_view<int64_t const> shape, array_view<float const> data);
        static auto CreateFromBuffer(array_view<int64_t const> shape, llm::OS::Storage::Streams::IBuffer const& buffer);
    };
    struct __declspec(empty_bases) TensorFloat16Bit : llm::OS::AI::MachineLearning::ITensorFloat16Bit,
        impl::require<TensorFloat16Bit, llm::OS::AI::MachineLearning::ILearningModelFeatureValue, llm::OS::AI::MachineLearning::ITensor, llm::OS::Foundation::IClosable, llm::OS::Foundation::IMemoryBuffer>
    {
        TensorFloat16Bit(std::nullptr_t) noexcept {}
        TensorFloat16Bit(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::ITensorFloat16Bit(ptr, take_ownership_from_abi) {}
        static auto Create();
        static auto Create(param::iterable<int64_t> const& shape);
        static auto CreateFromArray(param::iterable<int64_t> const& shape, array_view<float const> data);
        static auto CreateFromIterable(param::iterable<int64_t> const& shape, param::iterable<float> const& data);
        static auto CreateFromShapeArrayAndDataArray(array_view<int64_t const> shape, array_view<float const> data);
        static auto CreateFromBuffer(array_view<int64_t const> shape, llm::OS::Storage::Streams::IBuffer const& buffer);
    };
    struct __declspec(empty_bases) TensorInt16Bit : llm::OS::AI::MachineLearning::ITensorInt16Bit,
        impl::require<TensorInt16Bit, llm::OS::AI::MachineLearning::ILearningModelFeatureValue, llm::OS::AI::MachineLearning::ITensor, llm::OS::Foundation::IClosable, llm::OS::Foundation::IMemoryBuffer>
    {
        TensorInt16Bit(std::nullptr_t) noexcept {}
        TensorInt16Bit(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::ITensorInt16Bit(ptr, take_ownership_from_abi) {}
        static auto Create();
        static auto Create(param::iterable<int64_t> const& shape);
        static auto CreateFromArray(param::iterable<int64_t> const& shape, array_view<int16_t const> data);
        static auto CreateFromIterable(param::iterable<int64_t> const& shape, param::iterable<int16_t> const& data);
        static auto CreateFromShapeArrayAndDataArray(array_view<int64_t const> shape, array_view<int16_t const> data);
        static auto CreateFromBuffer(array_view<int64_t const> shape, llm::OS::Storage::Streams::IBuffer const& buffer);
    };
    struct __declspec(empty_bases) TensorInt32Bit : llm::OS::AI::MachineLearning::ITensorInt32Bit,
        impl::require<TensorInt32Bit, llm::OS::AI::MachineLearning::ILearningModelFeatureValue, llm::OS::AI::MachineLearning::ITensor, llm::OS::Foundation::IClosable, llm::OS::Foundation::IMemoryBuffer>
    {
        TensorInt32Bit(std::nullptr_t) noexcept {}
        TensorInt32Bit(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::ITensorInt32Bit(ptr, take_ownership_from_abi) {}
        static auto Create();
        static auto Create(param::iterable<int64_t> const& shape);
        static auto CreateFromArray(param::iterable<int64_t> const& shape, array_view<int32_t const> data);
        static auto CreateFromIterable(param::iterable<int64_t> const& shape, param::iterable<int32_t> const& data);
        static auto CreateFromShapeArrayAndDataArray(array_view<int64_t const> shape, array_view<int32_t const> data);
        static auto CreateFromBuffer(array_view<int64_t const> shape, llm::OS::Storage::Streams::IBuffer const& buffer);
    };
    struct __declspec(empty_bases) TensorInt64Bit : llm::OS::AI::MachineLearning::ITensorInt64Bit,
        impl::require<TensorInt64Bit, llm::OS::AI::MachineLearning::ILearningModelFeatureValue, llm::OS::AI::MachineLearning::ITensor, llm::OS::Foundation::IClosable, llm::OS::Foundation::IMemoryBuffer>
    {
        TensorInt64Bit(std::nullptr_t) noexcept {}
        TensorInt64Bit(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::ITensorInt64Bit(ptr, take_ownership_from_abi) {}
        static auto Create();
        static auto Create(param::iterable<int64_t> const& shape);
        static auto CreateFromArray(param::iterable<int64_t> const& shape, array_view<int64_t const> data);
        static auto CreateFromIterable(param::iterable<int64_t> const& shape, param::iterable<int64_t> const& data);
        static auto CreateFromShapeArrayAndDataArray(array_view<int64_t const> shape, array_view<int64_t const> data);
        static auto CreateFromBuffer(array_view<int64_t const> shape, llm::OS::Storage::Streams::IBuffer const& buffer);
    };
    struct __declspec(empty_bases) TensorInt8Bit : llm::OS::AI::MachineLearning::ITensorInt8Bit,
        impl::require<TensorInt8Bit, llm::OS::AI::MachineLearning::ILearningModelFeatureValue, llm::OS::AI::MachineLearning::ITensor, llm::OS::Foundation::IClosable, llm::OS::Foundation::IMemoryBuffer>
    {
        TensorInt8Bit(std::nullptr_t) noexcept {}
        TensorInt8Bit(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::ITensorInt8Bit(ptr, take_ownership_from_abi) {}
        static auto Create();
        static auto Create(param::iterable<int64_t> const& shape);
        static auto CreateFromArray(param::iterable<int64_t> const& shape, array_view<uint8_t const> data);
        static auto CreateFromIterable(param::iterable<int64_t> const& shape, param::iterable<uint8_t> const& data);
        static auto CreateFromShapeArrayAndDataArray(array_view<int64_t const> shape, array_view<uint8_t const> data);
        static auto CreateFromBuffer(array_view<int64_t const> shape, llm::OS::Storage::Streams::IBuffer const& buffer);
    };
    struct __declspec(empty_bases) TensorString : llm::OS::AI::MachineLearning::ITensorString,
        impl::require<TensorString, llm::OS::AI::MachineLearning::ILearningModelFeatureValue, llm::OS::AI::MachineLearning::ITensor, llm::OS::Foundation::IClosable, llm::OS::Foundation::IMemoryBuffer>
    {
        TensorString(std::nullptr_t) noexcept {}
        TensorString(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::ITensorString(ptr, take_ownership_from_abi) {}
        static auto Create();
        static auto Create(param::iterable<int64_t> const& shape);
        static auto CreateFromArray(param::iterable<int64_t> const& shape, array_view<hstring const> data);
        static auto CreateFromIterable(param::iterable<int64_t> const& shape, param::iterable<hstring> const& data);
        static auto CreateFromShapeArrayAndDataArray(array_view<int64_t const> shape, array_view<hstring const> data);
    };
    struct __declspec(empty_bases) TensorUInt16Bit : llm::OS::AI::MachineLearning::ITensorUInt16Bit,
        impl::require<TensorUInt16Bit, llm::OS::AI::MachineLearning::ILearningModelFeatureValue, llm::OS::AI::MachineLearning::ITensor, llm::OS::Foundation::IClosable, llm::OS::Foundation::IMemoryBuffer>
    {
        TensorUInt16Bit(std::nullptr_t) noexcept {}
        TensorUInt16Bit(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::ITensorUInt16Bit(ptr, take_ownership_from_abi) {}
        static auto Create();
        static auto Create(param::iterable<int64_t> const& shape);
        static auto CreateFromArray(param::iterable<int64_t> const& shape, array_view<uint16_t const> data);
        static auto CreateFromIterable(param::iterable<int64_t> const& shape, param::iterable<uint16_t> const& data);
        static auto CreateFromShapeArrayAndDataArray(array_view<int64_t const> shape, array_view<uint16_t const> data);
        static auto CreateFromBuffer(array_view<int64_t const> shape, llm::OS::Storage::Streams::IBuffer const& buffer);
    };
    struct __declspec(empty_bases) TensorUInt32Bit : llm::OS::AI::MachineLearning::ITensorUInt32Bit,
        impl::require<TensorUInt32Bit, llm::OS::AI::MachineLearning::ILearningModelFeatureValue, llm::OS::AI::MachineLearning::ITensor, llm::OS::Foundation::IClosable, llm::OS::Foundation::IMemoryBuffer>
    {
        TensorUInt32Bit(std::nullptr_t) noexcept {}
        TensorUInt32Bit(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::ITensorUInt32Bit(ptr, take_ownership_from_abi) {}
        static auto Create();
        static auto Create(param::iterable<int64_t> const& shape);
        static auto CreateFromArray(param::iterable<int64_t> const& shape, array_view<uint32_t const> data);
        static auto CreateFromIterable(param::iterable<int64_t> const& shape, param::iterable<uint32_t> const& data);
        static auto CreateFromShapeArrayAndDataArray(array_view<int64_t const> shape, array_view<uint32_t const> data);
        static auto CreateFromBuffer(array_view<int64_t const> shape, llm::OS::Storage::Streams::IBuffer const& buffer);
    };
    struct __declspec(empty_bases) TensorUInt64Bit : llm::OS::AI::MachineLearning::ITensorUInt64Bit,
        impl::require<TensorUInt64Bit, llm::OS::AI::MachineLearning::ILearningModelFeatureValue, llm::OS::AI::MachineLearning::ITensor, llm::OS::Foundation::IClosable, llm::OS::Foundation::IMemoryBuffer>
    {
        TensorUInt64Bit(std::nullptr_t) noexcept {}
        TensorUInt64Bit(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::ITensorUInt64Bit(ptr, take_ownership_from_abi) {}
        static auto Create();
        static auto Create(param::iterable<int64_t> const& shape);
        static auto CreateFromArray(param::iterable<int64_t> const& shape, array_view<uint64_t const> data);
        static auto CreateFromIterable(param::iterable<int64_t> const& shape, param::iterable<uint64_t> const& data);
        static auto CreateFromShapeArrayAndDataArray(array_view<int64_t const> shape, array_view<uint64_t const> data);
        static auto CreateFromBuffer(array_view<int64_t const> shape, llm::OS::Storage::Streams::IBuffer const& buffer);
    };
    struct __declspec(empty_bases) TensorUInt8Bit : llm::OS::AI::MachineLearning::ITensorUInt8Bit,
        impl::require<TensorUInt8Bit, llm::OS::AI::MachineLearning::ILearningModelFeatureValue, llm::OS::AI::MachineLearning::ITensor, llm::OS::Foundation::IClosable, llm::OS::Foundation::IMemoryBuffer>
    {
        TensorUInt8Bit(std::nullptr_t) noexcept {}
        TensorUInt8Bit(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::AI::MachineLearning::ITensorUInt8Bit(ptr, take_ownership_from_abi) {}
        static auto Create();
        static auto Create(param::iterable<int64_t> const& shape);
        static auto CreateFromArray(param::iterable<int64_t> const& shape, array_view<uint8_t const> data);
        static auto CreateFromIterable(param::iterable<int64_t> const& shape, param::iterable<uint8_t> const& data);
        static auto CreateFromShapeArrayAndDataArray(array_view<int64_t const> shape, array_view<uint8_t const> data);
        static auto CreateFromBuffer(array_view<int64_t const> shape, llm::OS::Storage::Streams::IBuffer const& buffer);
    };
}
#endif
