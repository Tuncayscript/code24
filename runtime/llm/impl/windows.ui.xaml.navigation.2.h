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
#ifndef LLM_OS_UI_Xaml_Navigation_2_H
#define LLM_OS_UI_Xaml_Navigation_2_H
#include "llm/impl/Windows.UI.Xaml.1.h"
#include "llm/impl/Windows.UI.Xaml.Interop.1.h"
#include "llm/impl/Windows.UI.Xaml.Media.Animation.1.h"
#include "llm/impl/Windows.UI.Xaml.Navigation.1.h"
LLM_EXPORT namespace llm::OS::UI::Xaml::Navigation
{
    struct LoadCompletedEventHandler : llm::OS::Foundation::IUnknown
    {
        LoadCompletedEventHandler(std::nullptr_t = nullptr) noexcept {}
        LoadCompletedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> LoadCompletedEventHandler(L lambda);
        template <typename F> LoadCompletedEventHandler(F* function);
        template <typename O, typename M> LoadCompletedEventHandler(O* object, M method);
        template <typename O, typename M> LoadCompletedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> LoadCompletedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Navigation::NavigationEventArgs const& e) const;
    };
    struct NavigatedEventHandler : llm::OS::Foundation::IUnknown
    {
        NavigatedEventHandler(std::nullptr_t = nullptr) noexcept {}
        NavigatedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> NavigatedEventHandler(L lambda);
        template <typename F> NavigatedEventHandler(F* function);
        template <typename O, typename M> NavigatedEventHandler(O* object, M method);
        template <typename O, typename M> NavigatedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> NavigatedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Navigation::NavigationEventArgs const& e) const;
    };
    struct NavigatingCancelEventHandler : llm::OS::Foundation::IUnknown
    {
        NavigatingCancelEventHandler(std::nullptr_t = nullptr) noexcept {}
        NavigatingCancelEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> NavigatingCancelEventHandler(L lambda);
        template <typename F> NavigatingCancelEventHandler(F* function);
        template <typename O, typename M> NavigatingCancelEventHandler(O* object, M method);
        template <typename O, typename M> NavigatingCancelEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> NavigatingCancelEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Navigation::NavigatingCancelEventArgs const& e) const;
    };
    struct NavigationFailedEventHandler : llm::OS::Foundation::IUnknown
    {
        NavigationFailedEventHandler(std::nullptr_t = nullptr) noexcept {}
        NavigationFailedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> NavigationFailedEventHandler(L lambda);
        template <typename F> NavigationFailedEventHandler(F* function);
        template <typename O, typename M> NavigationFailedEventHandler(O* object, M method);
        template <typename O, typename M> NavigationFailedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> NavigationFailedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Navigation::NavigationFailedEventArgs const& e) const;
    };
    struct NavigationStoppedEventHandler : llm::OS::Foundation::IUnknown
    {
        NavigationStoppedEventHandler(std::nullptr_t = nullptr) noexcept {}
        NavigationStoppedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> NavigationStoppedEventHandler(L lambda);
        template <typename F> NavigationStoppedEventHandler(F* function);
        template <typename O, typename M> NavigationStoppedEventHandler(O* object, M method);
        template <typename O, typename M> NavigationStoppedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> NavigationStoppedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Navigation::NavigationEventArgs const& e) const;
    };
    struct __declspec(empty_bases) FrameNavigationOptions : llm::OS::UI::Xaml::Navigation::IFrameNavigationOptions
    {
        FrameNavigationOptions(std::nullptr_t) noexcept {}
        FrameNavigationOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Navigation::IFrameNavigationOptions(ptr, take_ownership_from_abi) {}
        FrameNavigationOptions();
    };
    struct __declspec(empty_bases) NavigatingCancelEventArgs : llm::OS::UI::Xaml::Navigation::INavigatingCancelEventArgs,
        impl::require<NavigatingCancelEventArgs, llm::OS::UI::Xaml::Navigation::INavigatingCancelEventArgs2>
    {
        NavigatingCancelEventArgs(std::nullptr_t) noexcept {}
        NavigatingCancelEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Navigation::INavigatingCancelEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) NavigationEventArgs : llm::OS::UI::Xaml::Navigation::INavigationEventArgs,
        impl::require<NavigationEventArgs, llm::OS::UI::Xaml::Navigation::INavigationEventArgs2>
    {
        NavigationEventArgs(std::nullptr_t) noexcept {}
        NavigationEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Navigation::INavigationEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) NavigationFailedEventArgs : llm::OS::UI::Xaml::Navigation::INavigationFailedEventArgs
    {
        NavigationFailedEventArgs(std::nullptr_t) noexcept {}
        NavigationFailedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Navigation::INavigationFailedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PageStackEntry : llm::OS::UI::Xaml::Navigation::IPageStackEntry,
        impl::base<PageStackEntry, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<PageStackEntry, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        PageStackEntry(std::nullptr_t) noexcept {}
        PageStackEntry(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Navigation::IPageStackEntry(ptr, take_ownership_from_abi) {}
        PageStackEntry(llm::OS::UI::Xaml::Interop::TypeName const& sourcePageType, llm::OS::Foundation::IInspectable const& parameter, llm::OS::UI::Xaml::Media::Animation::NavigationTransitionInfo const& navigationTransitionInfo);
        [[nodiscard]] static auto SourcePageTypeProperty();
    };
}
#endif
