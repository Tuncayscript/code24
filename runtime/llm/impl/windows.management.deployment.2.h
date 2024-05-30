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
#ifndef LLM_OS_Management_Deployment_2_H
#define LLM_OS_Management_Deployment_2_H
#include "llm/impl/Windows.ApplicationModel.2.h"
#include "llm/impl/Windows.Management.Deployment.1.h"
LLM_EXPORT namespace llm:OS::Management::Deployment
{
    struct DeploymentProgress
    {
        llm:OS::Management::Deployment::DeploymentProgressState state;
        uint32_t percentage;
    };
    inline bool operator==(DeploymentProgress const& left, DeploymentProgress const& right) noexcept
    {
        return left.state == right.state && left.percentage == right.percentage;
    }
    inline bool operator!=(DeploymentProgress const& left, DeploymentProgress const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) AddPackageOptions : llm:OS::Management::Deployment::IAddPackageOptions,
        impl::require<AddPackageOptions, llm:OS::Management::Deployment::IAddPackageOptions2>
    {
        AddPackageOptions(std::nullptr_t) noexcept {}
        AddPackageOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Deployment::IAddPackageOptions(ptr, take_ownership_from_abi) {}
        AddPackageOptions();
    };
    struct __declspec(empty_bases) AppInstallerManager : llm:OS::Management::Deployment::IAppInstallerManager
    {
        AppInstallerManager(std::nullptr_t) noexcept {}
        AppInstallerManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Deployment::IAppInstallerManager(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
        static auto GetForSystem();
    };
    struct __declspec(empty_bases) AutoUpdateSettingsOptions : llm:OS::Management::Deployment::IAutoUpdateSettingsOptions
    {
        AutoUpdateSettingsOptions(std::nullptr_t) noexcept {}
        AutoUpdateSettingsOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Deployment::IAutoUpdateSettingsOptions(ptr, take_ownership_from_abi) {}
        AutoUpdateSettingsOptions();
        static auto CreateFromAppInstallerInfo(llm:OS::ApplicationModel::AppInstallerInfo const& appInstallerInfo);
    };
    struct __declspec(empty_bases) CreateSharedPackageContainerOptions : llm:OS::Management::Deployment::ICreateSharedPackageContainerOptions
    {
        CreateSharedPackageContainerOptions(std::nullptr_t) noexcept {}
        CreateSharedPackageContainerOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Deployment::ICreateSharedPackageContainerOptions(ptr, take_ownership_from_abi) {}
        CreateSharedPackageContainerOptions();
    };
    struct __declspec(empty_bases) CreateSharedPackageContainerResult : llm:OS::Management::Deployment::ICreateSharedPackageContainerResult
    {
        CreateSharedPackageContainerResult(std::nullptr_t) noexcept {}
        CreateSharedPackageContainerResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Deployment::ICreateSharedPackageContainerResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DeleteSharedPackageContainerOptions : llm:OS::Management::Deployment::IDeleteSharedPackageContainerOptions
    {
        DeleteSharedPackageContainerOptions(std::nullptr_t) noexcept {}
        DeleteSharedPackageContainerOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Deployment::IDeleteSharedPackageContainerOptions(ptr, take_ownership_from_abi) {}
        DeleteSharedPackageContainerOptions();
    };
    struct __declspec(empty_bases) DeleteSharedPackageContainerResult : llm:OS::Management::Deployment::IDeleteSharedPackageContainerResult
    {
        DeleteSharedPackageContainerResult(std::nullptr_t) noexcept {}
        DeleteSharedPackageContainerResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Deployment::IDeleteSharedPackageContainerResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DeploymentResult : llm:OS::Management::Deployment::IDeploymentResult,
        impl::require<DeploymentResult, llm:OS::Management::Deployment::IDeploymentResult2>
    {
        DeploymentResult(std::nullptr_t) noexcept {}
        DeploymentResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Deployment::IDeploymentResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FindSharedPackageContainerOptions : llm:OS::Management::Deployment::IFindSharedPackageContainerOptions
    {
        FindSharedPackageContainerOptions(std::nullptr_t) noexcept {}
        FindSharedPackageContainerOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Deployment::IFindSharedPackageContainerOptions(ptr, take_ownership_from_abi) {}
        FindSharedPackageContainerOptions();
    };
    struct __declspec(empty_bases) PackageAllUserProvisioningOptions : llm:OS::Management::Deployment::IPackageAllUserProvisioningOptions
    {
        PackageAllUserProvisioningOptions(std::nullptr_t) noexcept {}
        PackageAllUserProvisioningOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Deployment::IPackageAllUserProvisioningOptions(ptr, take_ownership_from_abi) {}
        PackageAllUserProvisioningOptions();
    };
    struct __declspec(empty_bases) PackageManager : llm:OS::Management::Deployment::IPackageManager,
        impl::require<PackageManager, llm:OS::Management::Deployment::IPackageManager2, llm:OS::Management::Deployment::IPackageManager3, llm:OS::Management::Deployment::IPackageManager4, llm:OS::Management::Deployment::IPackageManager5, llm:OS::Management::Deployment::IPackageManager6, llm:OS::Management::Deployment::IPackageManager7, llm:OS::Management::Deployment::IPackageManager8, llm:OS::Management::Deployment::IPackageManager9, llm:OS::Management::Deployment::IPackageManager10>
    {
        PackageManager(std::nullptr_t) noexcept {}
        PackageManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Deployment::IPackageManager(ptr, take_ownership_from_abi) {}
        PackageManager();
        using llm:OS::Management::Deployment::IPackageManager::AddPackageAsync;
        using impl::consume_t<PackageManager, llm:OS::Management::Deployment::IPackageManager3>::AddPackageAsync;
        using impl::consume_t<PackageManager, llm:OS::Management::Deployment::IPackageManager5>::AddPackageAsync;
        using impl::consume_t<PackageManager, llm:OS::Management::Deployment::IPackageManager6>::AddPackageAsync;
        using impl::consume_t<PackageManager, llm:OS::Management::Deployment::IPackageManager10>::ProvisionPackageForAllUsersAsync;
        using impl::consume_t<PackageManager, llm:OS::Management::Deployment::IPackageManager6>::ProvisionPackageForAllUsersAsync;
        using llm:OS::Management::Deployment::IPackageManager::RegisterPackageAsync;
        using impl::consume_t<PackageManager, llm:OS::Management::Deployment::IPackageManager3>::RegisterPackageAsync;
        using llm:OS::Management::Deployment::IPackageManager::RemovePackageAsync;
        using impl::consume_t<PackageManager, llm:OS::Management::Deployment::IPackageManager2>::RemovePackageAsync;
        using impl::consume_t<PackageManager, llm:OS::Management::Deployment::IPackageManager6>::RequestAddPackageAsync;
        using impl::consume_t<PackageManager, llm:OS::Management::Deployment::IPackageManager7>::RequestAddPackageAsync;
        using llm:OS::Management::Deployment::IPackageManager::StagePackageAsync;
        using impl::consume_t<PackageManager, llm:OS::Management::Deployment::IPackageManager2>::StagePackageAsync;
        using impl::consume_t<PackageManager, llm:OS::Management::Deployment::IPackageManager3>::StagePackageAsync;
        using impl::consume_t<PackageManager, llm:OS::Management::Deployment::IPackageManager5>::StagePackageAsync;
        using impl::consume_t<PackageManager, llm:OS::Management::Deployment::IPackageManager6>::StagePackageAsync;
        using impl::consume_t<PackageManager, llm:OS::Management::Deployment::IPackageManager2>::StageUserDataAsync;
        using impl::consume_t<PackageManager, llm:OS::Management::Deployment::IPackageManager3>::StageUserDataAsync;
    };
    struct __declspec(empty_bases) PackageManagerDebugSettings : llm:OS::Management::Deployment::IPackageManagerDebugSettings
    {
        PackageManagerDebugSettings(std::nullptr_t) noexcept {}
        PackageManagerDebugSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Deployment::IPackageManagerDebugSettings(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PackageUserInformation : llm:OS::Management::Deployment::IPackageUserInformation
    {
        PackageUserInformation(std::nullptr_t) noexcept {}
        PackageUserInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Deployment::IPackageUserInformation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PackageVolume : llm:OS::Management::Deployment::IPackageVolume,
        impl::require<PackageVolume, llm:OS::Management::Deployment::IPackageVolume2>
    {
        PackageVolume(std::nullptr_t) noexcept {}
        PackageVolume(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Deployment::IPackageVolume(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RegisterPackageOptions : llm:OS::Management::Deployment::IRegisterPackageOptions,
        impl::require<RegisterPackageOptions, llm:OS::Management::Deployment::IRegisterPackageOptions2>
    {
        RegisterPackageOptions(std::nullptr_t) noexcept {}
        RegisterPackageOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Deployment::IRegisterPackageOptions(ptr, take_ownership_from_abi) {}
        RegisterPackageOptions();
    };
    struct __declspec(empty_bases) SharedPackageContainer : llm:OS::Management::Deployment::ISharedPackageContainer
    {
        SharedPackageContainer(std::nullptr_t) noexcept {}
        SharedPackageContainer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Deployment::ISharedPackageContainer(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SharedPackageContainerManager : llm:OS::Management::Deployment::ISharedPackageContainerManager
    {
        SharedPackageContainerManager(std::nullptr_t) noexcept {}
        SharedPackageContainerManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Deployment::ISharedPackageContainerManager(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
        static auto GetForUser(param::hstring const& userSid);
        static auto GetForProvisioning();
    };
    struct __declspec(empty_bases) SharedPackageContainerMember : llm:OS::Management::Deployment::ISharedPackageContainerMember
    {
        SharedPackageContainerMember(std::nullptr_t) noexcept {}
        SharedPackageContainerMember(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Deployment::ISharedPackageContainerMember(ptr, take_ownership_from_abi) {}
        explicit SharedPackageContainerMember(param::hstring const& packageFamilyName);
    };
    struct __declspec(empty_bases) StagePackageOptions : llm:OS::Management::Deployment::IStagePackageOptions,
        impl::require<StagePackageOptions, llm:OS::Management::Deployment::IStagePackageOptions2>
    {
        StagePackageOptions(std::nullptr_t) noexcept {}
        StagePackageOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Deployment::IStagePackageOptions(ptr, take_ownership_from_abi) {}
        StagePackageOptions();
    };
    struct __declspec(empty_bases) UpdateSharedPackageContainerOptions : llm:OS::Management::Deployment::IUpdateSharedPackageContainerOptions
    {
        UpdateSharedPackageContainerOptions(std::nullptr_t) noexcept {}
        UpdateSharedPackageContainerOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Deployment::IUpdateSharedPackageContainerOptions(ptr, take_ownership_from_abi) {}
        UpdateSharedPackageContainerOptions();
    };
    struct __declspec(empty_bases) UpdateSharedPackageContainerResult : llm:OS::Management::Deployment::IUpdateSharedPackageContainerResult
    {
        UpdateSharedPackageContainerResult(std::nullptr_t) noexcept {}
        UpdateSharedPackageContainerResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Deployment::IUpdateSharedPackageContainerResult(ptr, take_ownership_from_abi) {}
    };
}
#endif
