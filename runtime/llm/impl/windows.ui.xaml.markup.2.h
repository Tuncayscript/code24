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
#ifndef LLM_OS_UI_Xaml_Markup_2_H
#define LLM_OS_UI_Xaml_Markup_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.UI.Xaml.1.h"
#include "llm/impl/Windows.UI.Xaml.Interop.1.h"
#include "llm/impl/Windows.UI.Xaml.Markup.1.h"
LLM_EXPORT namespace llm::OS::UI::Xaml::Markup
{
    struct XamlBinaryWriterErrorInformation
    {
        uint32_t InputStreamIndex;
        uint32_t LineNumber;
        uint32_t LinePosition;
    };
    inline bool operator==(XamlBinaryWriterErrorInformation const& left, XamlBinaryWriterErrorInformation const& right) noexcept
    {
        return left.InputStreamIndex == right.InputStreamIndex && left.LineNumber == right.LineNumber && left.LinePosition == right.LinePosition;
    }
    inline bool operator!=(XamlBinaryWriterErrorInformation const& left, XamlBinaryWriterErrorInformation const& right) noexcept
    {
        return !(left == right);
    }
    struct XmlnsDefinition
    {
        hstring XmlNamespace;
        hstring Namespace;
    };
    inline bool operator==(XmlnsDefinition const& left, XmlnsDefinition const& right) noexcept
    {
        return left.XmlNamespace == right.XmlNamespace && left.Namespace == right.Namespace;
    }
    inline bool operator!=(XmlnsDefinition const& left, XmlnsDefinition const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) MarkupExtension : llm::OS::UI::Xaml::Markup::IMarkupExtension,
        impl::require<MarkupExtension, llm::OS::UI::Xaml::Markup::IMarkupExtensionOverrides>
    {
        MarkupExtension(std::nullptr_t) noexcept {}
        MarkupExtension(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Markup::IMarkupExtension(ptr, take_ownership_from_abi) {}
        MarkupExtension();
    };
    struct __declspec(empty_bases) XamlBinaryWriter : llm::OS::UI::Xaml::Markup::IXamlBinaryWriter
    {
        XamlBinaryWriter(std::nullptr_t) noexcept {}
        XamlBinaryWriter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Markup::IXamlBinaryWriter(ptr, take_ownership_from_abi) {}
        static auto Write(param::vector<llm::OS::Storage::Streams::IRandomAccessStream> const& inputStreams, param::vector<llm::OS::Storage::Streams::IRandomAccessStream> const& outputStreams, llm::OS::UI::Xaml::Markup::IXamlMetadataProvider const& xamlMetadataProvider);
    };
    struct __declspec(empty_bases) XamlBindingHelper : llm::OS::UI::Xaml::Markup::IXamlBindingHelper
    {
        XamlBindingHelper(std::nullptr_t) noexcept {}
        XamlBindingHelper(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Markup::IXamlBindingHelper(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto DataTemplateComponentProperty();
        static auto GetDataTemplateComponent(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetDataTemplateComponent(llm::OS::UI::Xaml::DependencyObject const& element, llm::OS::UI::Xaml::Markup::IDataTemplateComponent const& value);
        static auto SuspendRendering(llm::OS::UI::Xaml::UIElement const& target);
        static auto ResumeRendering(llm::OS::UI::Xaml::UIElement const& target);
        static auto ConvertValue(llm::OS::UI::Xaml::Interop::TypeName const& type, llm::OS::Foundation::IInspectable const& value);
        static auto SetPropertyFromString(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, param::hstring const& value);
        static auto SetPropertyFromBoolean(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, bool value);
        static auto SetPropertyFromChar16(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, char16_t value);
        static auto SetPropertyFromDateTime(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, llm::OS::Foundation::DateTime const& value);
        static auto SetPropertyFromDouble(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, double value);
        static auto SetPropertyFromInt32(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, int32_t value);
        static auto SetPropertyFromUInt32(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, uint32_t value);
        static auto SetPropertyFromInt64(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, int64_t value);
        static auto SetPropertyFromUInt64(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, uint64_t value);
        static auto SetPropertyFromSingle(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, float value);
        static auto SetPropertyFromPoint(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, llm::OS::Foundation::Point const& value);
        static auto SetPropertyFromRect(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, llm::OS::Foundation::Rect const& value);
        static auto SetPropertyFromSize(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, llm::OS::Foundation::Size const& value);
        static auto SetPropertyFromTimeSpan(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, llm::OS::Foundation::TimeSpan const& value);
        static auto SetPropertyFromByte(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, uint8_t value);
        static auto SetPropertyFromUri(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, llm::OS::Foundation::Uri const& value);
        static auto SetPropertyFromObject(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, llm::OS::Foundation::IInspectable const& value);
    };
    struct __declspec(empty_bases) XamlMarkupHelper : llm::OS::UI::Xaml::Markup::IXamlMarkupHelper
    {
        XamlMarkupHelper(std::nullptr_t) noexcept {}
        XamlMarkupHelper(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Markup::IXamlMarkupHelper(ptr, take_ownership_from_abi) {}
        static auto UnloadObject(llm::OS::UI::Xaml::DependencyObject const& element);
    };
    struct __declspec(empty_bases) XamlReader : llm::OS::UI::Xaml::Markup::IXamlReader
    {
        XamlReader(std::nullptr_t) noexcept {}
        XamlReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Markup::IXamlReader(ptr, take_ownership_from_abi) {}
        static auto Load(param::hstring const& xaml);
        static auto LoadWithInitialTemplateValidation(param::hstring const& xaml);
    };
    template <typename D>
    class IMarkupExtensionOverridesT
    {
        D& shim() noexcept { return *static_cast<D*>(this); }
        D const& shim() const noexcept { return *static_cast<const D*>(this); }
    public:
        using IMarkupExtensionOverrides = llm::OS::UI::Xaml::Markup::IMarkupExtensionOverrides;
        WINRT_IMPL_AUTO(llm::OS::Foundation::IInspectable) ProvideValue() const;
    };
}
#endif
