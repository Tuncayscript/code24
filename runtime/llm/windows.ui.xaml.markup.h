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
#ifndef LLM_OS_UI_Xaml_Markup_H
#define LLM_OS_UI_Xaml_Markup_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.Xaml.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.UI.Xaml.2.h"
#include "llm/impl/Windows.UI.Xaml.Interop.2.h"
#include "llm/impl/Windows.UI.Xaml.Markup.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Markup_IComponentConnector<D>::Connect(int32_t connectionId, llm::OS::Foundation::IInspectable const& target) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IComponentConnector)->Connect(connectionId, *(void**)(&target)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Markup::IComponentConnector) consume_Windows_UI_Xaml_Markup_IComponentConnector2<D>::GetBindingConnector(int32_t connectionId, llm::OS::Foundation::IInspectable const& target) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IComponentConnector2)->GetBindingConnector(connectionId, *(void**)(&target), &result));
        return llm::OS::UI::Xaml::Markup::IComponentConnector{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Markup_IDataTemplateComponent<D>::Recycle() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IDataTemplateComponent)->Recycle());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Markup_IDataTemplateComponent<D>::ProcessBindings(llm::OS::Foundation::IInspectable const& item, int32_t itemIndex, int32_t phase, int32_t& nextPhase) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IDataTemplateComponent)->ProcessBindings(*(void**)(&item), itemIndex, phase, &nextPhase));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Markup::MarkupExtension) consume_Windows_UI_Xaml_Markup_IMarkupExtensionFactory<D>::CreateInstance(llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IMarkupExtensionFactory)->CreateInstance(*(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Markup::MarkupExtension{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_UI_Xaml_Markup_IMarkupExtensionOverrides<D>::ProvideValue() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IMarkupExtensionOverrides)->ProvideValue(&result));
        return llm::OS::Foundation::IInspectable{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Markup::XamlBinaryWriterErrorInformation) consume_Windows_UI_Xaml_Markup_IXamlBinaryWriterStatics<D>::Write(param::vector<llm::OS::Storage::Streams::IRandomAccessStream> const& inputStreams, param::vector<llm::OS::Storage::Streams::IRandomAccessStream> const& outputStreams, llm::OS::UI::Xaml::Markup::IXamlMetadataProvider const& xamlMetadataProvider) const
    {
        llm::OS::UI::Xaml::Markup::XamlBinaryWriterErrorInformation result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlBinaryWriterStatics)->Write(*(void**)(&inputStreams), *(void**)(&outputStreams), *(void**)(&xamlMetadataProvider), put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Markup_IXamlBindScopeDiagnostics<D>::Disable(int32_t lineNumber, int32_t columnNumber) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlBindScopeDiagnostics)->Disable(lineNumber, columnNumber));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) consume_Windows_UI_Xaml_Markup_IXamlBindingHelperStatics<D>::DataTemplateComponentProperty() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlBindingHelperStatics)->get_DataTemplateComponentProperty(&value));
        return llm::OS::UI::Xaml::DependencyProperty{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Markup::IDataTemplateComponent) consume_Windows_UI_Xaml_Markup_IXamlBindingHelperStatics<D>::GetDataTemplateComponent(llm::OS::UI::Xaml::DependencyObject const& element) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlBindingHelperStatics)->GetDataTemplateComponent(*(void**)(&element), &result));
        return llm::OS::UI::Xaml::Markup::IDataTemplateComponent{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Markup_IXamlBindingHelperStatics<D>::SetDataTemplateComponent(llm::OS::UI::Xaml::DependencyObject const& element, llm::OS::UI::Xaml::Markup::IDataTemplateComponent const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlBindingHelperStatics)->SetDataTemplateComponent(*(void**)(&element), *(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Markup_IXamlBindingHelperStatics<D>::SuspendRendering(llm::OS::UI::Xaml::UIElement const& target) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlBindingHelperStatics)->SuspendRendering(*(void**)(&target)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Markup_IXamlBindingHelperStatics<D>::ResumeRendering(llm::OS::UI::Xaml::UIElement const& target) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlBindingHelperStatics)->ResumeRendering(*(void**)(&target)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_UI_Xaml_Markup_IXamlBindingHelperStatics<D>::ConvertValue(llm::OS::UI::Xaml::Interop::TypeName const& type, llm::OS::Foundation::IInspectable const& value) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlBindingHelperStatics)->ConvertValue(impl::bind_in(type), *(void**)(&value), &result));
        return llm::OS::Foundation::IInspectable{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Markup_IXamlBindingHelperStatics<D>::SetPropertyFromString(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlBindingHelperStatics)->SetPropertyFromString(*(void**)(&dependencyObject), *(void**)(&propertyToSet), *(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Markup_IXamlBindingHelperStatics<D>::SetPropertyFromBoolean(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlBindingHelperStatics)->SetPropertyFromBoolean(*(void**)(&dependencyObject), *(void**)(&propertyToSet), value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Markup_IXamlBindingHelperStatics<D>::SetPropertyFromChar16(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, char16_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlBindingHelperStatics)->SetPropertyFromChar16(*(void**)(&dependencyObject), *(void**)(&propertyToSet), value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Markup_IXamlBindingHelperStatics<D>::SetPropertyFromDateTime(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, llm::OS::Foundation::DateTime const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlBindingHelperStatics)->SetPropertyFromDateTime(*(void**)(&dependencyObject), *(void**)(&propertyToSet), impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Markup_IXamlBindingHelperStatics<D>::SetPropertyFromDouble(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, double value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlBindingHelperStatics)->SetPropertyFromDouble(*(void**)(&dependencyObject), *(void**)(&propertyToSet), value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Markup_IXamlBindingHelperStatics<D>::SetPropertyFromInt32(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, int32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlBindingHelperStatics)->SetPropertyFromInt32(*(void**)(&dependencyObject), *(void**)(&propertyToSet), value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Markup_IXamlBindingHelperStatics<D>::SetPropertyFromUInt32(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlBindingHelperStatics)->SetPropertyFromUInt32(*(void**)(&dependencyObject), *(void**)(&propertyToSet), value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Markup_IXamlBindingHelperStatics<D>::SetPropertyFromInt64(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, int64_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlBindingHelperStatics)->SetPropertyFromInt64(*(void**)(&dependencyObject), *(void**)(&propertyToSet), value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Markup_IXamlBindingHelperStatics<D>::SetPropertyFromUInt64(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, uint64_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlBindingHelperStatics)->SetPropertyFromUInt64(*(void**)(&dependencyObject), *(void**)(&propertyToSet), value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Markup_IXamlBindingHelperStatics<D>::SetPropertyFromSingle(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlBindingHelperStatics)->SetPropertyFromSingle(*(void**)(&dependencyObject), *(void**)(&propertyToSet), value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Markup_IXamlBindingHelperStatics<D>::SetPropertyFromPoint(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, llm::OS::Foundation::Point const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlBindingHelperStatics)->SetPropertyFromPoint(*(void**)(&dependencyObject), *(void**)(&propertyToSet), impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Markup_IXamlBindingHelperStatics<D>::SetPropertyFromRect(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, llm::OS::Foundation::Rect const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlBindingHelperStatics)->SetPropertyFromRect(*(void**)(&dependencyObject), *(void**)(&propertyToSet), impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Markup_IXamlBindingHelperStatics<D>::SetPropertyFromSize(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, llm::OS::Foundation::Size const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlBindingHelperStatics)->SetPropertyFromSize(*(void**)(&dependencyObject), *(void**)(&propertyToSet), impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Markup_IXamlBindingHelperStatics<D>::SetPropertyFromTimeSpan(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, llm::OS::Foundation::TimeSpan const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlBindingHelperStatics)->SetPropertyFromTimeSpan(*(void**)(&dependencyObject), *(void**)(&propertyToSet), impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Markup_IXamlBindingHelperStatics<D>::SetPropertyFromByte(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, uint8_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlBindingHelperStatics)->SetPropertyFromByte(*(void**)(&dependencyObject), *(void**)(&propertyToSet), value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Markup_IXamlBindingHelperStatics<D>::SetPropertyFromUri(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlBindingHelperStatics)->SetPropertyFromUri(*(void**)(&dependencyObject), *(void**)(&propertyToSet), *(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Markup_IXamlBindingHelperStatics<D>::SetPropertyFromObject(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, llm::OS::Foundation::IInspectable const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlBindingHelperStatics)->SetPropertyFromObject(*(void**)(&dependencyObject), *(void**)(&propertyToSet), *(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Markup_IXamlMarkupHelperStatics<D>::UnloadObject(llm::OS::UI::Xaml::DependencyObject const& element) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlMarkupHelperStatics)->UnloadObject(*(void**)(&element)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Markup_IXamlMember<D>::IsAttachable() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlMember)->get_IsAttachable(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Markup_IXamlMember<D>::IsDependencyProperty() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlMember)->get_IsDependencyProperty(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Markup_IXamlMember<D>::IsReadOnly() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlMember)->get_IsReadOnly(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Xaml_Markup_IXamlMember<D>::Name() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlMember)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Markup::IXamlType) consume_Windows_UI_Xaml_Markup_IXamlMember<D>::TargetType() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlMember)->get_TargetType(&value));
        return llm::OS::UI::Xaml::Markup::IXamlType{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Markup::IXamlType) consume_Windows_UI_Xaml_Markup_IXamlMember<D>::Type() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlMember)->get_Type(&value));
        return llm::OS::UI::Xaml::Markup::IXamlType{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_UI_Xaml_Markup_IXamlMember<D>::GetValue(llm::OS::Foundation::IInspectable const& instance) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlMember)->GetValue(*(void**)(&instance), &result));
        return llm::OS::Foundation::IInspectable{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Markup_IXamlMember<D>::SetValue(llm::OS::Foundation::IInspectable const& instance, llm::OS::Foundation::IInspectable const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlMember)->SetValue(*(void**)(&instance), *(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Markup::IXamlType) consume_Windows_UI_Xaml_Markup_IXamlMetadataProvider<D>::GetXamlType(llm::OS::UI::Xaml::Interop::TypeName const& type) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlMetadataProvider)->GetXamlType(impl::bind_in(type), &result));
        return llm::OS::UI::Xaml::Markup::IXamlType{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Markup::IXamlType) consume_Windows_UI_Xaml_Markup_IXamlMetadataProvider<D>::GetXamlType(param::hstring const& fullName) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlMetadataProvider)->GetXamlTypeByFullName(*(void**)(&fullName), &result));
        return llm::OS::UI::Xaml::Markup::IXamlType{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(com_array<llm::OS::UI::Xaml::Markup::XmlnsDefinition>) consume_Windows_UI_Xaml_Markup_IXamlMetadataProvider<D>::GetXmlnsDefinitions() const
    {
        uint32_t result_impl_size{};
        struct struct_Windows_UI_Xaml_Markup_XmlnsDefinition* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlMetadataProvider)->GetXmlnsDefinitions(&result_impl_size, &result));
        return com_array<llm::OS::UI::Xaml::Markup::XmlnsDefinition>{ result, result_impl_size, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_UI_Xaml_Markup_IXamlReaderStatics<D>::Load(param::hstring const& xaml) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlReaderStatics)->Load(*(void**)(&xaml), &result));
        return llm::OS::Foundation::IInspectable{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_UI_Xaml_Markup_IXamlReaderStatics<D>::LoadWithInitialTemplateValidation(param::hstring const& xaml) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlReaderStatics)->LoadWithInitialTemplateValidation(*(void**)(&xaml), &result));
        return llm::OS::Foundation::IInspectable{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Markup::IXamlType) consume_Windows_UI_Xaml_Markup_IXamlType<D>::BaseType() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlType)->get_BaseType(&value));
        return llm::OS::UI::Xaml::Markup::IXamlType{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Markup::IXamlMember) consume_Windows_UI_Xaml_Markup_IXamlType<D>::ContentProperty() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlType)->get_ContentProperty(&value));
        return llm::OS::UI::Xaml::Markup::IXamlMember{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Xaml_Markup_IXamlType<D>::FullName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlType)->get_FullName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Markup_IXamlType<D>::IsArray() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlType)->get_IsArray(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Markup_IXamlType<D>::IsCollection() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlType)->get_IsCollection(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Markup_IXamlType<D>::IsConstructible() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlType)->get_IsConstructible(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Markup_IXamlType<D>::IsDictionary() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlType)->get_IsDictionary(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Markup_IXamlType<D>::IsMarkupExtension() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlType)->get_IsMarkupExtension(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Markup_IXamlType<D>::IsBindable() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlType)->get_IsBindable(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Markup::IXamlType) consume_Windows_UI_Xaml_Markup_IXamlType<D>::ItemType() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlType)->get_ItemType(&value));
        return llm::OS::UI::Xaml::Markup::IXamlType{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Markup::IXamlType) consume_Windows_UI_Xaml_Markup_IXamlType<D>::KeyType() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlType)->get_KeyType(&value));
        return llm::OS::UI::Xaml::Markup::IXamlType{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Interop::TypeName) consume_Windows_UI_Xaml_Markup_IXamlType<D>::UnderlyingType() const
    {
        llm::OS::UI::Xaml::Interop::TypeName value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlType)->get_UnderlyingType(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_UI_Xaml_Markup_IXamlType<D>::ActivateInstance() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlType)->ActivateInstance(&result));
        return llm::OS::Foundation::IInspectable{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_UI_Xaml_Markup_IXamlType<D>::CreateFromString(param::hstring const& value) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlType)->CreateFromString(*(void**)(&value), &result));
        return llm::OS::Foundation::IInspectable{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Markup::IXamlMember) consume_Windows_UI_Xaml_Markup_IXamlType<D>::GetMember(param::hstring const& name) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlType)->GetMember(*(void**)(&name), &result));
        return llm::OS::UI::Xaml::Markup::IXamlMember{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Markup_IXamlType<D>::AddToVector(llm::OS::Foundation::IInspectable const& instance, llm::OS::Foundation::IInspectable const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlType)->AddToVector(*(void**)(&instance), *(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Markup_IXamlType<D>::AddToMap(llm::OS::Foundation::IInspectable const& instance, llm::OS::Foundation::IInspectable const& key, llm::OS::Foundation::IInspectable const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlType)->AddToMap(*(void**)(&instance), *(void**)(&key), *(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Markup_IXamlType<D>::RunInitializer() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlType)->RunInitializer());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Markup::IXamlType) consume_Windows_UI_Xaml_Markup_IXamlType2<D>::BoxedType() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Markup::IXamlType2)->get_BoxedType(&value));
        return llm::OS::UI::Xaml::Markup::IXamlType{ value, take_ownership_from_abi };
    }
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Markup::IComponentConnector> : produce_base<D, llm::OS::UI::Xaml::Markup::IComponentConnector>
    {
        int32_t __stdcall Connect(int32_t connectionId, void* target) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Connect(connectionId, *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&target));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Markup::IComponentConnector2> : produce_base<D, llm::OS::UI::Xaml::Markup::IComponentConnector2>
    {
        int32_t __stdcall GetBindingConnector(int32_t connectionId, void* target, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Markup::IComponentConnector>(this->shim().GetBindingConnector(connectionId, *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&target)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Markup::IDataTemplateComponent> : produce_base<D, llm::OS::UI::Xaml::Markup::IDataTemplateComponent>
    {
        int32_t __stdcall Recycle() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Recycle();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ProcessBindings(void* item, int32_t itemIndex, int32_t phase, int32_t* nextPhase) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProcessBindings(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&item), itemIndex, phase, *nextPhase);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Markup::IMarkupExtension> : produce_base<D, llm::OS::UI::Xaml::Markup::IMarkupExtension>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Markup::IMarkupExtensionFactory> : produce_base<D, llm::OS::UI::Xaml::Markup::IMarkupExtensionFactory>
    {
        int32_t __stdcall CreateInstance(void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Markup::MarkupExtension>(this->shim().CreateInstance(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Markup::IMarkupExtensionOverrides> : produce_base<D, llm::OS::UI::Xaml::Markup::IMarkupExtensionOverrides>
    {
        int32_t __stdcall ProvideValue(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IInspectable>(this->shim().ProvideValue());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Markup::IXamlBinaryWriter> : produce_base<D, llm::OS::UI::Xaml::Markup::IXamlBinaryWriter>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Markup::IXamlBinaryWriterStatics> : produce_base<D, llm::OS::UI::Xaml::Markup::IXamlBinaryWriterStatics>
    {
        int32_t __stdcall Write(void* inputStreams, void* outputStreams, void* xamlMetadataProvider, struct struct_Windows_UI_Xaml_Markup_XamlBinaryWriterErrorInformation* result) noexcept final try
        {
            zero_abi<llm::OS::UI::Xaml::Markup::XamlBinaryWriterErrorInformation>(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Markup::XamlBinaryWriterErrorInformation>(this->shim().Write(*reinterpret_cast<llm::OS::Foundation::Collections::IVector<llm::OS::Storage::Streams::IRandomAccessStream> const*>(&inputStreams), *reinterpret_cast<llm::OS::Foundation::Collections::IVector<llm::OS::Storage::Streams::IRandomAccessStream> const*>(&outputStreams), *reinterpret_cast<llm::OS::UI::Xaml::Markup::IXamlMetadataProvider const*>(&xamlMetadataProvider)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Markup::IXamlBindScopeDiagnostics> : produce_base<D, llm::OS::UI::Xaml::Markup::IXamlBindScopeDiagnostics>
    {
        int32_t __stdcall Disable(int32_t lineNumber, int32_t columnNumber) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Disable(lineNumber, columnNumber);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Markup::IXamlBindingHelper> : produce_base<D, llm::OS::UI::Xaml::Markup::IXamlBindingHelper>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Markup::IXamlBindingHelperStatics> : produce_base<D, llm::OS::UI::Xaml::Markup::IXamlBindingHelperStatics>
    {
        int32_t __stdcall get_DataTemplateComponentProperty(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::DependencyProperty>(this->shim().DataTemplateComponentProperty());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDataTemplateComponent(void* element, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Markup::IDataTemplateComponent>(this->shim().GetDataTemplateComponent(*reinterpret_cast<llm::OS::UI::Xaml::DependencyObject const*>(&element)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetDataTemplateComponent(void* element, void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetDataTemplateComponent(*reinterpret_cast<llm::OS::UI::Xaml::DependencyObject const*>(&element), *reinterpret_cast<llm::OS::UI::Xaml::Markup::IDataTemplateComponent const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SuspendRendering(void* target) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SuspendRendering(*reinterpret_cast<llm::OS::UI::Xaml::UIElement const*>(&target));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ResumeRendering(void* target) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ResumeRendering(*reinterpret_cast<llm::OS::UI::Xaml::UIElement const*>(&target));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ConvertValue(struct struct_Windows_UI_Xaml_Interop_TypeName type, void* value, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IInspectable>(this->shim().ConvertValue(*reinterpret_cast<llm::OS::UI::Xaml::Interop::TypeName const*>(&type), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPropertyFromString(void* dependencyObject, void* propertyToSet, void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromString(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&dependencyObject), *reinterpret_cast<llm::OS::UI::Xaml::DependencyProperty const*>(&propertyToSet), *reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPropertyFromBoolean(void* dependencyObject, void* propertyToSet, bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromBoolean(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&dependencyObject), *reinterpret_cast<llm::OS::UI::Xaml::DependencyProperty const*>(&propertyToSet), value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPropertyFromChar16(void* dependencyObject, void* propertyToSet, char16_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromChar16(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&dependencyObject), *reinterpret_cast<llm::OS::UI::Xaml::DependencyProperty const*>(&propertyToSet), value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPropertyFromDateTime(void* dependencyObject, void* propertyToSet, int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromDateTime(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&dependencyObject), *reinterpret_cast<llm::OS::UI::Xaml::DependencyProperty const*>(&propertyToSet), *reinterpret_cast<llm::OS::Foundation::DateTime const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPropertyFromDouble(void* dependencyObject, void* propertyToSet, double value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromDouble(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&dependencyObject), *reinterpret_cast<llm::OS::UI::Xaml::DependencyProperty const*>(&propertyToSet), value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPropertyFromInt32(void* dependencyObject, void* propertyToSet, int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromInt32(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&dependencyObject), *reinterpret_cast<llm::OS::UI::Xaml::DependencyProperty const*>(&propertyToSet), value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPropertyFromUInt32(void* dependencyObject, void* propertyToSet, uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromUInt32(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&dependencyObject), *reinterpret_cast<llm::OS::UI::Xaml::DependencyProperty const*>(&propertyToSet), value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPropertyFromInt64(void* dependencyObject, void* propertyToSet, int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromInt64(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&dependencyObject), *reinterpret_cast<llm::OS::UI::Xaml::DependencyProperty const*>(&propertyToSet), value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPropertyFromUInt64(void* dependencyObject, void* propertyToSet, uint64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromUInt64(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&dependencyObject), *reinterpret_cast<llm::OS::UI::Xaml::DependencyProperty const*>(&propertyToSet), value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPropertyFromSingle(void* dependencyObject, void* propertyToSet, float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromSingle(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&dependencyObject), *reinterpret_cast<llm::OS::UI::Xaml::DependencyProperty const*>(&propertyToSet), value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPropertyFromPoint(void* dependencyObject, void* propertyToSet, llm::OS::Foundation::Point value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromPoint(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&dependencyObject), *reinterpret_cast<llm::OS::UI::Xaml::DependencyProperty const*>(&propertyToSet), *reinterpret_cast<llm::OS::Foundation::Point const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPropertyFromRect(void* dependencyObject, void* propertyToSet, llm::OS::Foundation::Rect value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromRect(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&dependencyObject), *reinterpret_cast<llm::OS::UI::Xaml::DependencyProperty const*>(&propertyToSet), *reinterpret_cast<llm::OS::Foundation::Rect const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPropertyFromSize(void* dependencyObject, void* propertyToSet, llm::OS::Foundation::Size value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromSize(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&dependencyObject), *reinterpret_cast<llm::OS::UI::Xaml::DependencyProperty const*>(&propertyToSet), *reinterpret_cast<llm::OS::Foundation::Size const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPropertyFromTimeSpan(void* dependencyObject, void* propertyToSet, int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromTimeSpan(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&dependencyObject), *reinterpret_cast<llm::OS::UI::Xaml::DependencyProperty const*>(&propertyToSet), *reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPropertyFromByte(void* dependencyObject, void* propertyToSet, uint8_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromByte(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&dependencyObject), *reinterpret_cast<llm::OS::UI::Xaml::DependencyProperty const*>(&propertyToSet), value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPropertyFromUri(void* dependencyObject, void* propertyToSet, void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromUri(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&dependencyObject), *reinterpret_cast<llm::OS::UI::Xaml::DependencyProperty const*>(&propertyToSet), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPropertyFromObject(void* dependencyObject, void* propertyToSet, void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromObject(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&dependencyObject), *reinterpret_cast<llm::OS::UI::Xaml::DependencyProperty const*>(&propertyToSet), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Markup::IXamlMarkupHelper> : produce_base<D, llm::OS::UI::Xaml::Markup::IXamlMarkupHelper>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Markup::IXamlMarkupHelperStatics> : produce_base<D, llm::OS::UI::Xaml::Markup::IXamlMarkupHelperStatics>
    {
        int32_t __stdcall UnloadObject(void* element) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UnloadObject(*reinterpret_cast<llm::OS::UI::Xaml::DependencyObject const*>(&element));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Markup::IXamlMember> : produce_base<D, llm::OS::UI::Xaml::Markup::IXamlMember>
    {
        int32_t __stdcall get_IsAttachable(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsAttachable());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsDependencyProperty(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsDependencyProperty());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsReadOnly(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsReadOnly());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Name(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Name());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TargetType(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Markup::IXamlType>(this->shim().TargetType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Type(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Markup::IXamlType>(this->shim().Type());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetValue(void* instance, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IInspectable>(this->shim().GetValue(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&instance)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetValue(void* instance, void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetValue(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&instance), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Markup::IXamlMetadataProvider> : produce_base<D, llm::OS::UI::Xaml::Markup::IXamlMetadataProvider>
    {
        int32_t __stdcall GetXamlType(struct struct_Windows_UI_Xaml_Interop_TypeName type, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Markup::IXamlType>(this->shim().GetXamlType(*reinterpret_cast<llm::OS::UI::Xaml::Interop::TypeName const*>(&type)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetXamlTypeByFullName(void* fullName, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Markup::IXamlType>(this->shim().GetXamlType(*reinterpret_cast<hstring const*>(&fullName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetXmlnsDefinitions(uint32_t* __resultSize, struct struct_Windows_UI_Xaml_Markup_XmlnsDefinition** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            std::tie(*__resultSize, *result) = detach_abi(this->shim().GetXmlnsDefinitions());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Markup::IXamlReader> : produce_base<D, llm::OS::UI::Xaml::Markup::IXamlReader>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Markup::IXamlReaderStatics> : produce_base<D, llm::OS::UI::Xaml::Markup::IXamlReaderStatics>
    {
        int32_t __stdcall Load(void* xaml, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IInspectable>(this->shim().Load(*reinterpret_cast<hstring const*>(&xaml)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LoadWithInitialTemplateValidation(void* xaml, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IInspectable>(this->shim().LoadWithInitialTemplateValidation(*reinterpret_cast<hstring const*>(&xaml)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Markup::IXamlType> : produce_base<D, llm::OS::UI::Xaml::Markup::IXamlType>
    {
        int32_t __stdcall get_BaseType(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Markup::IXamlType>(this->shim().BaseType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ContentProperty(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Markup::IXamlMember>(this->shim().ContentProperty());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FullName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().FullName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsArray(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsArray());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsCollection(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsCollection());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsConstructible(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsConstructible());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsDictionary(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsDictionary());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsMarkupExtension(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsMarkupExtension());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsBindable(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsBindable());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ItemType(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Markup::IXamlType>(this->shim().ItemType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_KeyType(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Markup::IXamlType>(this->shim().KeyType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UnderlyingType(struct struct_Windows_UI_Xaml_Interop_TypeName* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Xaml::Interop::TypeName>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Interop::TypeName>(this->shim().UnderlyingType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ActivateInstance(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IInspectable>(this->shim().ActivateInstance());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromString(void* value, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CreateFromString(*reinterpret_cast<hstring const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetMember(void* name, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Markup::IXamlMember>(this->shim().GetMember(*reinterpret_cast<hstring const*>(&name)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AddToVector(void* instance, void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddToVector(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&instance), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AddToMap(void* instance, void* key, void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddToMap(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&instance), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&key), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RunInitializer() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RunInitializer();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Markup::IXamlType2> : produce_base<D, llm::OS::UI::Xaml::Markup::IXamlType2>
    {
        int32_t __stdcall get_BoxedType(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Markup::IXamlType>(this->shim().BoxedType());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
template <typename T, typename D>
struct __declspec(empty_bases) produce_dispatch_to_overridable<T, D, llm::OS::UI::Xaml::Markup::IMarkupExtensionOverrides>
    : produce_dispatch_to_overridable_base<T, D, llm::OS::UI::Xaml::Markup::IMarkupExtensionOverrides>
{
    auto ProvideValue()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.ProvideValue();
        }

        return this->shim().ProvideValue();
    }
};
}
LLM_EXPORT namespace llm::OS::UI::Xaml::Markup
{
    inline MarkupExtension::MarkupExtension()
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<MarkupExtension, IMarkupExtensionFactory>([&](IMarkupExtensionFactory const& f) { return f.CreateInstance(baseInterface, innerInterface); });
    }
    inline auto XamlBinaryWriter::Write(param::vector<llm::OS::Storage::Streams::IRandomAccessStream> const& inputStreams, param::vector<llm::OS::Storage::Streams::IRandomAccessStream> const& outputStreams, llm::OS::UI::Xaml::Markup::IXamlMetadataProvider const& xamlMetadataProvider)
    {
        return impl::call_factory<XamlBinaryWriter, IXamlBinaryWriterStatics>([&](IXamlBinaryWriterStatics const& f) { return f.Write(inputStreams, outputStreams, xamlMetadataProvider); });
    }
    inline auto XamlBindingHelper::DataTemplateComponentProperty()
    {
        return impl::call_factory_cast<llm::OS::UI::Xaml::DependencyProperty(*)(IXamlBindingHelperStatics const&), XamlBindingHelper, IXamlBindingHelperStatics>([](IXamlBindingHelperStatics const& f) { return f.DataTemplateComponentProperty(); });
    }
    inline auto XamlBindingHelper::GetDataTemplateComponent(llm::OS::UI::Xaml::DependencyObject const& element)
    {
        return impl::call_factory<XamlBindingHelper, IXamlBindingHelperStatics>([&](IXamlBindingHelperStatics const& f) { return f.GetDataTemplateComponent(element); });
    }
    inline auto XamlBindingHelper::SetDataTemplateComponent(llm::OS::UI::Xaml::DependencyObject const& element, llm::OS::UI::Xaml::Markup::IDataTemplateComponent const& value)
    {
        impl::call_factory<XamlBindingHelper, IXamlBindingHelperStatics>([&](IXamlBindingHelperStatics const& f) { return f.SetDataTemplateComponent(element, value); });
    }
    inline auto XamlBindingHelper::SuspendRendering(llm::OS::UI::Xaml::UIElement const& target)
    {
        impl::call_factory<XamlBindingHelper, IXamlBindingHelperStatics>([&](IXamlBindingHelperStatics const& f) { return f.SuspendRendering(target); });
    }
    inline auto XamlBindingHelper::ResumeRendering(llm::OS::UI::Xaml::UIElement const& target)
    {
        impl::call_factory<XamlBindingHelper, IXamlBindingHelperStatics>([&](IXamlBindingHelperStatics const& f) { return f.ResumeRendering(target); });
    }
    inline auto XamlBindingHelper::ConvertValue(llm::OS::UI::Xaml::Interop::TypeName const& type, llm::OS::Foundation::IInspectable const& value)
    {
        return impl::call_factory<XamlBindingHelper, IXamlBindingHelperStatics>([&](IXamlBindingHelperStatics const& f) { return f.ConvertValue(type, value); });
    }
    inline auto XamlBindingHelper::SetPropertyFromString(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, param::hstring const& value)
    {
        impl::call_factory<XamlBindingHelper, IXamlBindingHelperStatics>([&](IXamlBindingHelperStatics const& f) { return f.SetPropertyFromString(dependencyObject, propertyToSet, value); });
    }
    inline auto XamlBindingHelper::SetPropertyFromBoolean(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, bool value)
    {
        impl::call_factory<XamlBindingHelper, IXamlBindingHelperStatics>([&](IXamlBindingHelperStatics const& f) { return f.SetPropertyFromBoolean(dependencyObject, propertyToSet, value); });
    }
    inline auto XamlBindingHelper::SetPropertyFromChar16(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, char16_t value)
    {
        impl::call_factory<XamlBindingHelper, IXamlBindingHelperStatics>([&](IXamlBindingHelperStatics const& f) { return f.SetPropertyFromChar16(dependencyObject, propertyToSet, value); });
    }
    inline auto XamlBindingHelper::SetPropertyFromDateTime(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, llm::OS::Foundation::DateTime const& value)
    {
        impl::call_factory<XamlBindingHelper, IXamlBindingHelperStatics>([&](IXamlBindingHelperStatics const& f) { return f.SetPropertyFromDateTime(dependencyObject, propertyToSet, value); });
    }
    inline auto XamlBindingHelper::SetPropertyFromDouble(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, double value)
    {
        impl::call_factory<XamlBindingHelper, IXamlBindingHelperStatics>([&](IXamlBindingHelperStatics const& f) { return f.SetPropertyFromDouble(dependencyObject, propertyToSet, value); });
    }
    inline auto XamlBindingHelper::SetPropertyFromInt32(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, int32_t value)
    {
        impl::call_factory<XamlBindingHelper, IXamlBindingHelperStatics>([&](IXamlBindingHelperStatics const& f) { return f.SetPropertyFromInt32(dependencyObject, propertyToSet, value); });
    }
    inline auto XamlBindingHelper::SetPropertyFromUInt32(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, uint32_t value)
    {
        impl::call_factory<XamlBindingHelper, IXamlBindingHelperStatics>([&](IXamlBindingHelperStatics const& f) { return f.SetPropertyFromUInt32(dependencyObject, propertyToSet, value); });
    }
    inline auto XamlBindingHelper::SetPropertyFromInt64(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, int64_t value)
    {
        impl::call_factory<XamlBindingHelper, IXamlBindingHelperStatics>([&](IXamlBindingHelperStatics const& f) { return f.SetPropertyFromInt64(dependencyObject, propertyToSet, value); });
    }
    inline auto XamlBindingHelper::SetPropertyFromUInt64(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, uint64_t value)
    {
        impl::call_factory<XamlBindingHelper, IXamlBindingHelperStatics>([&](IXamlBindingHelperStatics const& f) { return f.SetPropertyFromUInt64(dependencyObject, propertyToSet, value); });
    }
    inline auto XamlBindingHelper::SetPropertyFromSingle(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, float value)
    {
        impl::call_factory<XamlBindingHelper, IXamlBindingHelperStatics>([&](IXamlBindingHelperStatics const& f) { return f.SetPropertyFromSingle(dependencyObject, propertyToSet, value); });
    }
    inline auto XamlBindingHelper::SetPropertyFromPoint(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, llm::OS::Foundation::Point const& value)
    {
        impl::call_factory<XamlBindingHelper, IXamlBindingHelperStatics>([&](IXamlBindingHelperStatics const& f) { return f.SetPropertyFromPoint(dependencyObject, propertyToSet, value); });
    }
    inline auto XamlBindingHelper::SetPropertyFromRect(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, llm::OS::Foundation::Rect const& value)
    {
        impl::call_factory<XamlBindingHelper, IXamlBindingHelperStatics>([&](IXamlBindingHelperStatics const& f) { return f.SetPropertyFromRect(dependencyObject, propertyToSet, value); });
    }
    inline auto XamlBindingHelper::SetPropertyFromSize(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, llm::OS::Foundation::Size const& value)
    {
        impl::call_factory<XamlBindingHelper, IXamlBindingHelperStatics>([&](IXamlBindingHelperStatics const& f) { return f.SetPropertyFromSize(dependencyObject, propertyToSet, value); });
    }
    inline auto XamlBindingHelper::SetPropertyFromTimeSpan(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, llm::OS::Foundation::TimeSpan const& value)
    {
        impl::call_factory<XamlBindingHelper, IXamlBindingHelperStatics>([&](IXamlBindingHelperStatics const& f) { return f.SetPropertyFromTimeSpan(dependencyObject, propertyToSet, value); });
    }
    inline auto XamlBindingHelper::SetPropertyFromByte(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, uint8_t value)
    {
        impl::call_factory<XamlBindingHelper, IXamlBindingHelperStatics>([&](IXamlBindingHelperStatics const& f) { return f.SetPropertyFromByte(dependencyObject, propertyToSet, value); });
    }
    inline auto XamlBindingHelper::SetPropertyFromUri(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, llm::OS::Foundation::Uri const& value)
    {
        impl::call_factory<XamlBindingHelper, IXamlBindingHelperStatics>([&](IXamlBindingHelperStatics const& f) { return f.SetPropertyFromUri(dependencyObject, propertyToSet, value); });
    }
    inline auto XamlBindingHelper::SetPropertyFromObject(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, llm::OS::Foundation::IInspectable const& value)
    {
        impl::call_factory<XamlBindingHelper, IXamlBindingHelperStatics>([&](IXamlBindingHelperStatics const& f) { return f.SetPropertyFromObject(dependencyObject, propertyToSet, value); });
    }
    inline auto XamlMarkupHelper::UnloadObject(llm::OS::UI::Xaml::DependencyObject const& element)
    {
        impl::call_factory<XamlMarkupHelper, IXamlMarkupHelperStatics>([&](IXamlMarkupHelperStatics const& f) { return f.UnloadObject(element); });
    }
    inline auto XamlReader::Load(param::hstring const& xaml)
    {
        return impl::call_factory<XamlReader, IXamlReaderStatics>([&](IXamlReaderStatics const& f) { return f.Load(xaml); });
    }
    inline auto XamlReader::LoadWithInitialTemplateValidation(param::hstring const& xaml)
    {
        return impl::call_factory<XamlReader, IXamlReaderStatics>([&](IXamlReaderStatics const& f) { return f.LoadWithInitialTemplateValidation(xaml); });
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) IMarkupExtensionOverridesT<D>::ProvideValue() const
    {
        return shim().template try_as<IMarkupExtensionOverrides>().ProvideValue();
    }
    template <typename D, typename... Interfaces>
    struct MarkupExtensionT :
        implements<D, llm::OS::UI::Xaml::Markup::IMarkupExtensionOverrides, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Markup::IMarkupExtension>,
        impl::base<D, MarkupExtension>,
        llm::OS::UI::Xaml::Markup::IMarkupExtensionOverridesT<D>
    {
        using composable = MarkupExtension;
    protected:
        MarkupExtensionT()
        {
            impl::call_factory<MarkupExtension, IMarkupExtensionFactory>([&](IMarkupExtensionFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstance(*this, this->m_inner); });
        }
    };
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::Xaml::Markup::IComponentConnector> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Markup::IComponentConnector2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Markup::IDataTemplateComponent> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Markup::IMarkupExtension> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Markup::IMarkupExtensionFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Markup::IMarkupExtensionOverrides> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Markup::IXamlBinaryWriter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Markup::IXamlBinaryWriterStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Markup::IXamlBindScopeDiagnostics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Markup::IXamlBindingHelper> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Markup::IXamlBindingHelperStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Markup::IXamlMarkupHelper> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Markup::IXamlMarkupHelperStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Markup::IXamlMember> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Markup::IXamlMetadataProvider> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Markup::IXamlReader> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Markup::IXamlReaderStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Markup::IXamlType> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Markup::IXamlType2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Markup::MarkupExtension> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Markup::XamlBinaryWriter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Markup::XamlBindingHelper> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Markup::XamlMarkupHelper> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Markup::XamlReader> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
