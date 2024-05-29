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
#ifndef LLM_OS_Data_Json_1_H
#define LLM_OS_Data_Json_1_H
#include "llm/impl/Windows.Data.Json.0.h"
LLM_EXPORT namespace llm::OS::Data::Json
{
    struct __declspec(empty_bases) IJsonArray :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IJsonArray>,
        impl::require<llm::OS::Data::Json::IJsonArray, llm::OS::Data::Json::IJsonValue>
    {
        IJsonArray(std::nullptr_t = nullptr) noexcept {}
        IJsonArray(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IJsonArrayStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IJsonArrayStatics>
    {
        IJsonArrayStatics(std::nullptr_t = nullptr) noexcept {}
        IJsonArrayStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IJsonErrorStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IJsonErrorStatics2>
    {
        IJsonErrorStatics2(std::nullptr_t = nullptr) noexcept {}
        IJsonErrorStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IJsonObject :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IJsonObject>,
        impl::require<llm::OS::Data::Json::IJsonObject, llm::OS::Data::Json::IJsonValue>
    {
        IJsonObject(std::nullptr_t = nullptr) noexcept {}
        IJsonObject(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IJsonObjectStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IJsonObjectStatics>
    {
        IJsonObjectStatics(std::nullptr_t = nullptr) noexcept {}
        IJsonObjectStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IJsonObjectWithDefaultValues :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IJsonObjectWithDefaultValues>,
        impl::require<llm::OS::Data::Json::IJsonObjectWithDefaultValues, llm::OS::Data::Json::IJsonValue, llm::OS::Data::Json::IJsonObject>
    {
        IJsonObjectWithDefaultValues(std::nullptr_t = nullptr) noexcept {}
        IJsonObjectWithDefaultValues(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        using impl::consume_t<IJsonObjectWithDefaultValues, IJsonObjectWithDefaultValues>::GetNamedArray;
        using impl::consume_t<IJsonObjectWithDefaultValues, llm::OS::Data::Json::IJsonObject>::GetNamedArray;
        using impl::consume_t<IJsonObjectWithDefaultValues, IJsonObjectWithDefaultValues>::GetNamedBoolean;
        using impl::consume_t<IJsonObjectWithDefaultValues, llm::OS::Data::Json::IJsonObject>::GetNamedBoolean;
        using impl::consume_t<IJsonObjectWithDefaultValues, IJsonObjectWithDefaultValues>::GetNamedNumber;
        using impl::consume_t<IJsonObjectWithDefaultValues, llm::OS::Data::Json::IJsonObject>::GetNamedNumber;
        using impl::consume_t<IJsonObjectWithDefaultValues, IJsonObjectWithDefaultValues>::GetNamedObject;
        using impl::consume_t<IJsonObjectWithDefaultValues, llm::OS::Data::Json::IJsonObject>::GetNamedObject;
        using impl::consume_t<IJsonObjectWithDefaultValues, IJsonObjectWithDefaultValues>::GetNamedString;
        using impl::consume_t<IJsonObjectWithDefaultValues, llm::OS::Data::Json::IJsonObject>::GetNamedString;
        using impl::consume_t<IJsonObjectWithDefaultValues, IJsonObjectWithDefaultValues>::GetNamedValue;
        using impl::consume_t<IJsonObjectWithDefaultValues, llm::OS::Data::Json::IJsonObject>::GetNamedValue;
    };
    struct __declspec(empty_bases) IJsonValue :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IJsonValue>
    {
        IJsonValue(std::nullptr_t = nullptr) noexcept {}
        IJsonValue(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IJsonValueStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IJsonValueStatics>
    {
        IJsonValueStatics(std::nullptr_t = nullptr) noexcept {}
        IJsonValueStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IJsonValueStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IJsonValueStatics2>
    {
        IJsonValueStatics2(std::nullptr_t = nullptr) noexcept {}
        IJsonValueStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
