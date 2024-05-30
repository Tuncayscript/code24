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
#ifndef LLM_OS_Management_Deployment_1_H
#define LLM_OS_Management_Deployment_1_H
#include "llm/impl/Windows.Management.Deployment.0.h"
LLM_EXPORT namespace llm:OS::Management::Deployment
{
    struct __declspec(empty_bases) IAddPackageOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAddPackageOptions>
    {
        IAddPackageOptions(std::nullptr_t = nullptr) noexcept {}
        IAddPackageOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAddPackageOptions2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAddPackageOptions2>
    {
        IAddPackageOptions2(std::nullptr_t = nullptr) noexcept {}
        IAddPackageOptions2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppInstallerManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppInstallerManager>
    {
        IAppInstallerManager(std::nullptr_t = nullptr) noexcept {}
        IAppInstallerManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppInstallerManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppInstallerManagerStatics>
    {
        IAppInstallerManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IAppInstallerManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAutoUpdateSettingsOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAutoUpdateSettingsOptions>
    {
        IAutoUpdateSettingsOptions(std::nullptr_t = nullptr) noexcept {}
        IAutoUpdateSettingsOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAutoUpdateSettingsOptionsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAutoUpdateSettingsOptionsStatics>
    {
        IAutoUpdateSettingsOptionsStatics(std::nullptr_t = nullptr) noexcept {}
        IAutoUpdateSettingsOptionsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICreateSharedPackageContainerOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICreateSharedPackageContainerOptions>
    {
        ICreateSharedPackageContainerOptions(std::nullptr_t = nullptr) noexcept {}
        ICreateSharedPackageContainerOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICreateSharedPackageContainerResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICreateSharedPackageContainerResult>
    {
        ICreateSharedPackageContainerResult(std::nullptr_t = nullptr) noexcept {}
        ICreateSharedPackageContainerResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeleteSharedPackageContainerOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDeleteSharedPackageContainerOptions>
    {
        IDeleteSharedPackageContainerOptions(std::nullptr_t = nullptr) noexcept {}
        IDeleteSharedPackageContainerOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeleteSharedPackageContainerResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDeleteSharedPackageContainerResult>
    {
        IDeleteSharedPackageContainerResult(std::nullptr_t = nullptr) noexcept {}
        IDeleteSharedPackageContainerResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeploymentResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDeploymentResult>
    {
        IDeploymentResult(std::nullptr_t = nullptr) noexcept {}
        IDeploymentResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeploymentResult2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDeploymentResult2>
    {
        IDeploymentResult2(std::nullptr_t = nullptr) noexcept {}
        IDeploymentResult2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFindSharedPackageContainerOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFindSharedPackageContainerOptions>
    {
        IFindSharedPackageContainerOptions(std::nullptr_t = nullptr) noexcept {}
        IFindSharedPackageContainerOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageAllUserProvisioningOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPackageAllUserProvisioningOptions>
    {
        IPackageAllUserProvisioningOptions(std::nullptr_t = nullptr) noexcept {}
        IPackageAllUserProvisioningOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPackageManager>
    {
        IPackageManager(std::nullptr_t = nullptr) noexcept {}
        IPackageManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageManager10 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPackageManager10>
    {
        IPackageManager10(std::nullptr_t = nullptr) noexcept {}
        IPackageManager10(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageManager2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPackageManager2>
    {
        IPackageManager2(std::nullptr_t = nullptr) noexcept {}
        IPackageManager2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageManager3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPackageManager3>
    {
        IPackageManager3(std::nullptr_t = nullptr) noexcept {}
        IPackageManager3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageManager4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPackageManager4>
    {
        IPackageManager4(std::nullptr_t = nullptr) noexcept {}
        IPackageManager4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageManager5 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPackageManager5>
    {
        IPackageManager5(std::nullptr_t = nullptr) noexcept {}
        IPackageManager5(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageManager6 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPackageManager6>
    {
        IPackageManager6(std::nullptr_t = nullptr) noexcept {}
        IPackageManager6(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageManager7 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPackageManager7>
    {
        IPackageManager7(std::nullptr_t = nullptr) noexcept {}
        IPackageManager7(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageManager8 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPackageManager8>
    {
        IPackageManager8(std::nullptr_t = nullptr) noexcept {}
        IPackageManager8(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageManager9 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPackageManager9>
    {
        IPackageManager9(std::nullptr_t = nullptr) noexcept {}
        IPackageManager9(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageManagerDebugSettings :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPackageManagerDebugSettings>
    {
        IPackageManagerDebugSettings(std::nullptr_t = nullptr) noexcept {}
        IPackageManagerDebugSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageUserInformation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPackageUserInformation>
    {
        IPackageUserInformation(std::nullptr_t = nullptr) noexcept {}
        IPackageUserInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageVolume :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPackageVolume>
    {
        IPackageVolume(std::nullptr_t = nullptr) noexcept {}
        IPackageVolume(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageVolume2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPackageVolume2>
    {
        IPackageVolume2(std::nullptr_t = nullptr) noexcept {}
        IPackageVolume2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRegisterPackageOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRegisterPackageOptions>
    {
        IRegisterPackageOptions(std::nullptr_t = nullptr) noexcept {}
        IRegisterPackageOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRegisterPackageOptions2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRegisterPackageOptions2>
    {
        IRegisterPackageOptions2(std::nullptr_t = nullptr) noexcept {}
        IRegisterPackageOptions2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISharedPackageContainer :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISharedPackageContainer>
    {
        ISharedPackageContainer(std::nullptr_t = nullptr) noexcept {}
        ISharedPackageContainer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISharedPackageContainerManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISharedPackageContainerManager>
    {
        ISharedPackageContainerManager(std::nullptr_t = nullptr) noexcept {}
        ISharedPackageContainerManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISharedPackageContainerManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISharedPackageContainerManagerStatics>
    {
        ISharedPackageContainerManagerStatics(std::nullptr_t = nullptr) noexcept {}
        ISharedPackageContainerManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISharedPackageContainerMember :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISharedPackageContainerMember>
    {
        ISharedPackageContainerMember(std::nullptr_t = nullptr) noexcept {}
        ISharedPackageContainerMember(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISharedPackageContainerMemberFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISharedPackageContainerMemberFactory>
    {
        ISharedPackageContainerMemberFactory(std::nullptr_t = nullptr) noexcept {}
        ISharedPackageContainerMemberFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStagePackageOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStagePackageOptions>
    {
        IStagePackageOptions(std::nullptr_t = nullptr) noexcept {}
        IStagePackageOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStagePackageOptions2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStagePackageOptions2>
    {
        IStagePackageOptions2(std::nullptr_t = nullptr) noexcept {}
        IStagePackageOptions2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUpdateSharedPackageContainerOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUpdateSharedPackageContainerOptions>
    {
        IUpdateSharedPackageContainerOptions(std::nullptr_t = nullptr) noexcept {}
        IUpdateSharedPackageContainerOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUpdateSharedPackageContainerResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUpdateSharedPackageContainerResult>
    {
        IUpdateSharedPackageContainerResult(std::nullptr_t = nullptr) noexcept {}
        IUpdateSharedPackageContainerResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
