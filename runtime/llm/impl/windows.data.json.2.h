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
#ifndef LLM_OS_Data_Json_2_H
#define LLM_OS_Data_Json_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Data.Json.1.h"
LLM_EXPORT namespace llm::OS::Data::Json
{
    struct __declspec(empty_bases) JsonArray : llm::OS::Data::Json::IJsonArray,
        impl::require<JsonArray, llm::OS::Foundation::Collections::IIterable<llm::OS::Data::Json::IJsonValue>, llm::OS::Foundation::Collections::IVector<llm::OS::Data::Json::IJsonValue>, llm::OS::Foundation::IStringable>
    {
        JsonArray(std::nullptr_t) noexcept {}
        JsonArray(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Json::IJsonArray(ptr, take_ownership_from_abi) {}
        JsonArray();
        static auto Parse(param::hstring const& input);
        static auto TryParse(param::hstring const& input, llm::OS::Data::Json::JsonArray& result);
    };
    struct JsonError
    {
        JsonError() = delete;
        static auto GetJsonStatus(int32_t hresult);
    };
    struct __declspec(empty_bases) JsonObject : llm::OS::Data::Json::IJsonObject,
        impl::require<JsonObject, llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, llm::OS::Data::Json::IJsonValue>>, llm::OS::Foundation::Collections::IMap<hstring, llm::OS::Data::Json::IJsonValue>, llm::OS::Data::Json::IJsonObjectWithDefaultValues, llm::OS::Foundation::IStringable>
    {
        JsonObject(std::nullptr_t) noexcept {}
        JsonObject(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Json::IJsonObject(ptr, take_ownership_from_abi) {}
        JsonObject();
        using llm::OS::Data::Json::IJsonObject::GetNamedArray;
        using impl::consume_t<JsonObject, llm::OS::Data::Json::IJsonObjectWithDefaultValues>::GetNamedArray;
        using llm::OS::Data::Json::IJsonObject::GetNamedBoolean;
        using impl::consume_t<JsonObject, llm::OS::Data::Json::IJsonObjectWithDefaultValues>::GetNamedBoolean;
        using llm::OS::Data::Json::IJsonObject::GetNamedNumber;
        using impl::consume_t<JsonObject, llm::OS::Data::Json::IJsonObjectWithDefaultValues>::GetNamedNumber;
        using llm::OS::Data::Json::IJsonObject::GetNamedObject;
        using impl::consume_t<JsonObject, llm::OS::Data::Json::IJsonObjectWithDefaultValues>::GetNamedObject;
        using llm::OS::Data::Json::IJsonObject::GetNamedString;
        using impl::consume_t<JsonObject, llm::OS::Data::Json::IJsonObjectWithDefaultValues>::GetNamedString;
        using llm::OS::Data::Json::IJsonObject::GetNamedValue;
        using impl::consume_t<JsonObject, llm::OS::Data::Json::IJsonObjectWithDefaultValues>::GetNamedValue;
        static auto Parse(param::hstring const& input);
        static auto TryParse(param::hstring const& input, llm::OS::Data::Json::JsonObject& result);
    };
    struct __declspec(empty_bases) JsonValue : llm::OS::Data::Json::IJsonValue,
        impl::require<JsonValue, llm::OS::Foundation::IStringable>
    {
        JsonValue(std::nullptr_t) noexcept {}
        JsonValue(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Json::IJsonValue(ptr, take_ownership_from_abi) {}
        static auto Parse(param::hstring const& input);
        static auto TryParse(param::hstring const& input, llm::OS::Data::Json::JsonValue& result);
        static auto CreateBooleanValue(bool input);
        static auto CreateNumberValue(double input);
        static auto CreateStringValue(param::hstring const& input);
        static auto CreateNullValue();
    };
}
#endif
