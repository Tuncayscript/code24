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
#ifndef LLM_OS_UI_Xaml_Media_Media3D_1_H
#define LLM_OS_UI_Xaml_Media_Media3D_1_H
#include "llm/impl/Windows.UI.Xaml.Media.Media3D.0.h"
LLM_EXPORT namespace llm::OS::UI::Xaml::Media::Media3D
{
    struct __declspec(empty_bases) ICompositeTransform3D :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICompositeTransform3D>
    {
        ICompositeTransform3D(std::nullptr_t = nullptr) noexcept {}
        ICompositeTransform3D(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICompositeTransform3DStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICompositeTransform3DStatics>
    {
        ICompositeTransform3DStatics(std::nullptr_t = nullptr) noexcept {}
        ICompositeTransform3DStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMatrix3DHelper :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IMatrix3DHelper>
    {
        IMatrix3DHelper(std::nullptr_t = nullptr) noexcept {}
        IMatrix3DHelper(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMatrix3DHelperStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IMatrix3DHelperStatics>
    {
        IMatrix3DHelperStatics(std::nullptr_t = nullptr) noexcept {}
        IMatrix3DHelperStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerspectiveTransform3D :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerspectiveTransform3D>
    {
        IPerspectiveTransform3D(std::nullptr_t = nullptr) noexcept {}
        IPerspectiveTransform3D(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerspectiveTransform3DStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerspectiveTransform3DStatics>
    {
        IPerspectiveTransform3DStatics(std::nullptr_t = nullptr) noexcept {}
        IPerspectiveTransform3DStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITransform3D :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITransform3D>
    {
        ITransform3D(std::nullptr_t = nullptr) noexcept {}
        ITransform3D(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITransform3DFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITransform3DFactory>
    {
        ITransform3DFactory(std::nullptr_t = nullptr) noexcept {}
        ITransform3DFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
