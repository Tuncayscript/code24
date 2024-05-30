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
#ifndef LLM_OS_UI_Xaml_2_H
#define LLM_OS_UI_Xaml_2_H
#include "llm/impl/Windows.ApplicationModel.2.h"
#include "llm/impl/Windows.ApplicationModel.Activation.2.h"
#include "llm/impl/Windows.ApplicationModel.Core.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.UI.Composition.2.h"
#include "llm/impl/Windows.UI.Core.2.h"
#include "llm/impl/Windows.UI.Xaml.Automation.Peers.2.h"
#include "llm/impl/Windows.UI.Xaml.Controls.2.h"
#include "llm/impl/Windows.UI.Xaml.Controls.Primitives.2.h"
#include "llm/impl/Windows.UI.Xaml.Input.2.h"
#include "llm/impl/Windows.UI.Xaml.Interop.2.h"
#include "llm/impl/Windows.UI.Xaml.1.h"
LLM_EXPORT namespace llm::OS::UI::Xaml
{
    struct ApplicationInitializationCallback : llm::OS::Foundation::IUnknown
    {
        ApplicationInitializationCallback(std::nullptr_t = nullptr) noexcept {}
        ApplicationInitializationCallback(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> ApplicationInitializationCallback(L lambda);
        template <typename F> ApplicationInitializationCallback(F* function);
        template <typename O, typename M> ApplicationInitializationCallback(O* object, M method);
        template <typename O, typename M> ApplicationInitializationCallback(com_ptr<O>&& object, M method);
        template <typename O, typename M> ApplicationInitializationCallback(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::UI::Xaml::ApplicationInitializationCallbackParams const& p) const;
    };
    struct BindingFailedEventHandler : llm::OS::Foundation::IUnknown
    {
        BindingFailedEventHandler(std::nullptr_t = nullptr) noexcept {}
        BindingFailedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> BindingFailedEventHandler(L lambda);
        template <typename F> BindingFailedEventHandler(F* function);
        template <typename O, typename M> BindingFailedEventHandler(O* object, M method);
        template <typename O, typename M> BindingFailedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> BindingFailedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::BindingFailedEventArgs const& e) const;
    };
    struct CreateDefaultValueCallback : llm::OS::Foundation::IUnknown
    {
        CreateDefaultValueCallback(std::nullptr_t = nullptr) noexcept {}
        CreateDefaultValueCallback(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> CreateDefaultValueCallback(L lambda);
        template <typename F> CreateDefaultValueCallback(F* function);
        template <typename O, typename M> CreateDefaultValueCallback(O* object, M method);
        template <typename O, typename M> CreateDefaultValueCallback(com_ptr<O>&& object, M method);
        template <typename O, typename M> CreateDefaultValueCallback(weak_ref<O>&& object, M method);
        auto operator()() const;
    };
    struct DependencyPropertyChangedCallback : llm::OS::Foundation::IUnknown
    {
        DependencyPropertyChangedCallback(std::nullptr_t = nullptr) noexcept {}
        DependencyPropertyChangedCallback(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> DependencyPropertyChangedCallback(L lambda);
        template <typename F> DependencyPropertyChangedCallback(F* function);
        template <typename O, typename M> DependencyPropertyChangedCallback(O* object, M method);
        template <typename O, typename M> DependencyPropertyChangedCallback(com_ptr<O>&& object, M method);
        template <typename O, typename M> DependencyPropertyChangedCallback(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::UI::Xaml::DependencyObject const& sender, llm::OS::UI::Xaml::DependencyProperty const& dp) const;
    };
    struct DependencyPropertyChangedEventHandler : llm::OS::Foundation::IUnknown
    {
        DependencyPropertyChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
        DependencyPropertyChangedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> DependencyPropertyChangedEventHandler(L lambda);
        template <typename F> DependencyPropertyChangedEventHandler(F* function);
        template <typename O, typename M> DependencyPropertyChangedEventHandler(O* object, M method);
        template <typename O, typename M> DependencyPropertyChangedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> DependencyPropertyChangedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::DependencyPropertyChangedEventArgs const& e) const;
    };
    struct DragEventHandler : llm::OS::Foundation::IUnknown
    {
        DragEventHandler(std::nullptr_t = nullptr) noexcept {}
        DragEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> DragEventHandler(L lambda);
        template <typename F> DragEventHandler(F* function);
        template <typename O, typename M> DragEventHandler(O* object, M method);
        template <typename O, typename M> DragEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> DragEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::DragEventArgs const& e) const;
    };
    struct EnteredBackgroundEventHandler : llm::OS::Foundation::IUnknown
    {
        EnteredBackgroundEventHandler(std::nullptr_t = nullptr) noexcept {}
        EnteredBackgroundEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> EnteredBackgroundEventHandler(L lambda);
        template <typename F> EnteredBackgroundEventHandler(F* function);
        template <typename O, typename M> EnteredBackgroundEventHandler(O* object, M method);
        template <typename O, typename M> EnteredBackgroundEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> EnteredBackgroundEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::ApplicationModel::EnteredBackgroundEventArgs const& e) const;
    };
    struct ExceptionRoutedEventHandler : llm::OS::Foundation::IUnknown
    {
        ExceptionRoutedEventHandler(std::nullptr_t = nullptr) noexcept {}
        ExceptionRoutedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> ExceptionRoutedEventHandler(L lambda);
        template <typename F> ExceptionRoutedEventHandler(F* function);
        template <typename O, typename M> ExceptionRoutedEventHandler(O* object, M method);
        template <typename O, typename M> ExceptionRoutedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> ExceptionRoutedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::ExceptionRoutedEventArgs const& e) const;
    };
    struct LeavingBackgroundEventHandler : llm::OS::Foundation::IUnknown
    {
        LeavingBackgroundEventHandler(std::nullptr_t = nullptr) noexcept {}
        LeavingBackgroundEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> LeavingBackgroundEventHandler(L lambda);
        template <typename F> LeavingBackgroundEventHandler(F* function);
        template <typename O, typename M> LeavingBackgroundEventHandler(O* object, M method);
        template <typename O, typename M> LeavingBackgroundEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> LeavingBackgroundEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::ApplicationModel::LeavingBackgroundEventArgs const& e) const;
    };
    struct PropertyChangedCallback : llm::OS::Foundation::IUnknown
    {
        PropertyChangedCallback(std::nullptr_t = nullptr) noexcept {}
        PropertyChangedCallback(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> PropertyChangedCallback(L lambda);
        template <typename F> PropertyChangedCallback(F* function);
        template <typename O, typename M> PropertyChangedCallback(O* object, M method);
        template <typename O, typename M> PropertyChangedCallback(com_ptr<O>&& object, M method);
        template <typename O, typename M> PropertyChangedCallback(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::UI::Xaml::DependencyObject const& d, llm::OS::UI::Xaml::DependencyPropertyChangedEventArgs const& e) const;
    };
    struct RoutedEventHandler : llm::OS::Foundation::IUnknown
    {
        RoutedEventHandler(std::nullptr_t = nullptr) noexcept {}
        RoutedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> RoutedEventHandler(L lambda);
        template <typename F> RoutedEventHandler(F* function);
        template <typename O, typename M> RoutedEventHandler(O* object, M method);
        template <typename O, typename M> RoutedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> RoutedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::RoutedEventArgs const& e) const;
    };
    struct SizeChangedEventHandler : llm::OS::Foundation::IUnknown
    {
        SizeChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
        SizeChangedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> SizeChangedEventHandler(L lambda);
        template <typename F> SizeChangedEventHandler(F* function);
        template <typename O, typename M> SizeChangedEventHandler(O* object, M method);
        template <typename O, typename M> SizeChangedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> SizeChangedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::SizeChangedEventArgs const& e) const;
    };
    struct SuspendingEventHandler : llm::OS::Foundation::IUnknown
    {
        SuspendingEventHandler(std::nullptr_t = nullptr) noexcept {}
        SuspendingEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> SuspendingEventHandler(L lambda);
        template <typename F> SuspendingEventHandler(F* function);
        template <typename O, typename M> SuspendingEventHandler(O* object, M method);
        template <typename O, typename M> SuspendingEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> SuspendingEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::ApplicationModel::SuspendingEventArgs const& e) const;
    };
    struct UnhandledExceptionEventHandler : llm::OS::Foundation::IUnknown
    {
        UnhandledExceptionEventHandler(std::nullptr_t = nullptr) noexcept {}
        UnhandledExceptionEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> UnhandledExceptionEventHandler(L lambda);
        template <typename F> UnhandledExceptionEventHandler(F* function);
        template <typename O, typename M> UnhandledExceptionEventHandler(O* object, M method);
        template <typename O, typename M> UnhandledExceptionEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> UnhandledExceptionEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::UnhandledExceptionEventArgs const& e) const;
    };
    struct VisualStateChangedEventHandler : llm::OS::Foundation::IUnknown
    {
        VisualStateChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
        VisualStateChangedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> VisualStateChangedEventHandler(L lambda);
        template <typename F> VisualStateChangedEventHandler(F* function);
        template <typename O, typename M> VisualStateChangedEventHandler(O* object, M method);
        template <typename O, typename M> VisualStateChangedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> VisualStateChangedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::VisualStateChangedEventArgs const& e) const;
    };
    struct WindowActivatedEventHandler : llm::OS::Foundation::IUnknown
    {
        WindowActivatedEventHandler(std::nullptr_t = nullptr) noexcept {}
        WindowActivatedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> WindowActivatedEventHandler(L lambda);
        template <typename F> WindowActivatedEventHandler(F* function);
        template <typename O, typename M> WindowActivatedEventHandler(O* object, M method);
        template <typename O, typename M> WindowActivatedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> WindowActivatedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Core::WindowActivatedEventArgs const& e) const;
    };
    struct WindowClosedEventHandler : llm::OS::Foundation::IUnknown
    {
        WindowClosedEventHandler(std::nullptr_t = nullptr) noexcept {}
        WindowClosedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> WindowClosedEventHandler(L lambda);
        template <typename F> WindowClosedEventHandler(F* function);
        template <typename O, typename M> WindowClosedEventHandler(O* object, M method);
        template <typename O, typename M> WindowClosedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> WindowClosedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Core::CoreWindowEventArgs const& e) const;
    };
    struct WindowSizeChangedEventHandler : llm::OS::Foundation::IUnknown
    {
        WindowSizeChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
        WindowSizeChangedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> WindowSizeChangedEventHandler(L lambda);
        template <typename F> WindowSizeChangedEventHandler(F* function);
        template <typename O, typename M> WindowSizeChangedEventHandler(O* object, M method);
        template <typename O, typename M> WindowSizeChangedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> WindowSizeChangedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Core::WindowSizeChangedEventArgs const& e) const;
    };
    struct WindowVisibilityChangedEventHandler : llm::OS::Foundation::IUnknown
    {
        WindowVisibilityChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
        WindowVisibilityChangedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> WindowVisibilityChangedEventHandler(L lambda);
        template <typename F> WindowVisibilityChangedEventHandler(F* function);
        template <typename O, typename M> WindowVisibilityChangedEventHandler(O* object, M method);
        template <typename O, typename M> WindowVisibilityChangedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> WindowVisibilityChangedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Core::VisibilityChangedEventArgs const& e) const;
    };
    struct CornerRadius
    {
        double TopLeft;
        double TopRight;
        double BottomRight;
        double BottomLeft;
    };
    inline bool operator==(CornerRadius const& left, CornerRadius const& right) noexcept
    {
        return left.TopLeft == right.TopLeft && left.TopRight == right.TopRight && left.BottomRight == right.BottomRight && left.BottomLeft == right.BottomLeft;
    }
    inline bool operator!=(CornerRadius const& left, CornerRadius const& right) noexcept
    {
        return !(left == right);
    }
    struct Duration
    {
        llm::OS::Foundation::TimeSpan TimeSpan;
        llm::OS::UI::Xaml::DurationType Type;
    };
    inline bool operator==(Duration const& left, Duration const& right) noexcept
    {
        return left.TimeSpan == right.TimeSpan && left.Type == right.Type;
    }
    inline bool operator!=(Duration const& left, Duration const& right) noexcept
    {
        return !(left == right);
    }
    struct GridLength
    {
        double Value;
        llm::OS::UI::Xaml::GridUnitType GridUnitType;
    };
    inline bool operator==(GridLength const& left, GridLength const& right) noexcept
    {
        return left.Value == right.Value && left.GridUnitType == right.GridUnitType;
    }
    inline bool operator!=(GridLength const& left, GridLength const& right) noexcept
    {
        return !(left == right);
    }
    struct Thickness
    {
        double Left;
        double Top;
        double Right;
        double Bottom;
    };
    inline bool operator==(Thickness const& left, Thickness const& right) noexcept
    {
        return left.Left == right.Left && left.Top == right.Top && left.Right == right.Right && left.Bottom == right.Bottom;
    }
    inline bool operator!=(Thickness const& left, Thickness const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) AdaptiveTrigger : llm::OS::UI::Xaml::IAdaptiveTrigger,
        impl::base<AdaptiveTrigger, llm::OS::UI::Xaml::StateTriggerBase, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<AdaptiveTrigger, llm::OS::UI::Xaml::IStateTriggerBase, llm::OS::UI::Xaml::IStateTriggerBaseProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        AdaptiveTrigger(std::nullptr_t) noexcept {}
        AdaptiveTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IAdaptiveTrigger(ptr, take_ownership_from_abi) {}
        AdaptiveTrigger();
        [[nodiscard]] static auto MinWindowWidthProperty();
        [[nodiscard]] static auto MinWindowHeightProperty();
    };
    struct __declspec(empty_bases) Application : llm::OS::UI::Xaml::IApplication,
        impl::require<Application, llm::OS::UI::Xaml::IApplication2, llm::OS::UI::Xaml::IApplication3, llm::OS::UI::Xaml::IApplicationOverrides, llm::OS::UI::Xaml::IApplicationOverrides2>
    {
        Application(std::nullptr_t) noexcept {}
        Application(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IApplication(ptr, take_ownership_from_abi) {}
        Application();
        [[nodiscard]] static auto Current();
        static auto Start(llm::OS::UI::Xaml::ApplicationInitializationCallback const& callback);
        static auto LoadComponent(llm::OS::Foundation::IInspectable const& component, llm::OS::Foundation::Uri const& resourceLocator);
        static auto LoadComponent(llm::OS::Foundation::IInspectable const& component, llm::OS::Foundation::Uri const& resourceLocator, llm::OS::UI::Xaml::Controls::Primitives::ComponentResourceLocation const& componentResourceLocation);
    };
    struct __declspec(empty_bases) ApplicationInitializationCallbackParams : llm::OS::UI::Xaml::IApplicationInitializationCallbackParams
    {
        ApplicationInitializationCallbackParams(std::nullptr_t) noexcept {}
        ApplicationInitializationCallbackParams(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IApplicationInitializationCallbackParams(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BindingFailedEventArgs : llm::OS::UI::Xaml::IBindingFailedEventArgs
    {
        BindingFailedEventArgs(std::nullptr_t) noexcept {}
        BindingFailedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IBindingFailedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BringIntoViewOptions : llm::OS::UI::Xaml::IBringIntoViewOptions,
        impl::require<BringIntoViewOptions, llm::OS::UI::Xaml::IBringIntoViewOptions2>
    {
        BringIntoViewOptions(std::nullptr_t) noexcept {}
        BringIntoViewOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IBringIntoViewOptions(ptr, take_ownership_from_abi) {}
        BringIntoViewOptions();
    };
    struct __declspec(empty_bases) BringIntoViewRequestedEventArgs : llm::OS::UI::Xaml::IBringIntoViewRequestedEventArgs,
        impl::base<BringIntoViewRequestedEventArgs, llm::OS::UI::Xaml::RoutedEventArgs>,
        impl::require<BringIntoViewRequestedEventArgs, llm::OS::UI::Xaml::IRoutedEventArgs>
    {
        BringIntoViewRequestedEventArgs(std::nullptr_t) noexcept {}
        BringIntoViewRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IBringIntoViewRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BrushTransition : llm::OS::UI::Xaml::IBrushTransition
    {
        BrushTransition(std::nullptr_t) noexcept {}
        BrushTransition(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IBrushTransition(ptr, take_ownership_from_abi) {}
        BrushTransition();
    };
    struct __declspec(empty_bases) ColorPaletteResources : llm::OS::UI::Xaml::IColorPaletteResources,
        impl::base<ColorPaletteResources, llm::OS::UI::Xaml::ResourceDictionary, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<ColorPaletteResources, llm::OS::UI::Xaml::IResourceDictionary, llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::Collections::IKeyValuePair<llm::OS::Foundation::IInspectable, llm::OS::Foundation::IInspectable>>, llm::OS::Foundation::Collections::IMap<llm::OS::Foundation::IInspectable, llm::OS::Foundation::IInspectable>, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        ColorPaletteResources(std::nullptr_t) noexcept {}
        ColorPaletteResources(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IColorPaletteResources(ptr, take_ownership_from_abi) {}
        ColorPaletteResources();
    };
    struct __declspec(empty_bases) CornerRadiusHelper : llm::OS::UI::Xaml::ICornerRadiusHelper
    {
        CornerRadiusHelper(std::nullptr_t) noexcept {}
        CornerRadiusHelper(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::ICornerRadiusHelper(ptr, take_ownership_from_abi) {}
        static auto FromRadii(double topLeft, double topRight, double bottomRight, double bottomLeft);
        static auto FromUniformRadius(double uniformRadius);
    };
    struct __declspec(empty_bases) DataContextChangedEventArgs : llm::OS::UI::Xaml::IDataContextChangedEventArgs
    {
        DataContextChangedEventArgs(std::nullptr_t) noexcept {}
        DataContextChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IDataContextChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DataTemplate : llm::OS::UI::Xaml::IDataTemplate,
        impl::base<DataTemplate, llm::OS::UI::Xaml::FrameworkTemplate, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<DataTemplate, llm::OS::UI::Xaml::IElementFactory, llm::OS::UI::Xaml::IFrameworkTemplate, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        DataTemplate(std::nullptr_t) noexcept {}
        DataTemplate(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IDataTemplate(ptr, take_ownership_from_abi) {}
        DataTemplate();
        [[nodiscard]] static auto ExtensionInstanceProperty();
        static auto GetExtensionInstance(llm::OS::UI::Xaml::FrameworkElement const& element);
        static auto SetExtensionInstance(llm::OS::UI::Xaml::FrameworkElement const& element, llm::OS::UI::Xaml::IDataTemplateExtension const& value);
    };
    struct __declspec(empty_bases) DataTemplateKey : llm::OS::UI::Xaml::IDataTemplateKey
    {
        DataTemplateKey(std::nullptr_t) noexcept {}
        DataTemplateKey(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IDataTemplateKey(ptr, take_ownership_from_abi) {}
        DataTemplateKey();
        explicit DataTemplateKey(llm::OS::Foundation::IInspectable const& dataType);
    };
    struct __declspec(empty_bases) DebugSettings : llm::OS::UI::Xaml::IDebugSettings,
        impl::require<DebugSettings, llm::OS::UI::Xaml::IDebugSettings2, llm::OS::UI::Xaml::IDebugSettings3, llm::OS::UI::Xaml::IDebugSettings4>
    {
        DebugSettings(std::nullptr_t) noexcept {}
        DebugSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IDebugSettings(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DependencyObject : llm::OS::UI::Xaml::IDependencyObject,
        impl::require<DependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        DependencyObject(std::nullptr_t) noexcept {}
        DependencyObject(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IDependencyObject(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DependencyObjectCollection : llm::OS::Foundation::Collections::IObservableVector<llm::OS::UI::Xaml::DependencyObject>,
        impl::base<DependencyObjectCollection, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<DependencyObjectCollection, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        DependencyObjectCollection(std::nullptr_t) noexcept {}
        DependencyObjectCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Collections::IObservableVector<llm::OS::UI::Xaml::DependencyObject>(ptr, take_ownership_from_abi) {}
        DependencyObjectCollection();
    };
    struct __declspec(empty_bases) DependencyProperty : llm::OS::UI::Xaml::IDependencyProperty
    {
        DependencyProperty(std::nullptr_t) noexcept {}
        DependencyProperty(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IDependencyProperty(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto UnsetValue();
        static auto Register(param::hstring const& name, llm::OS::UI::Xaml::Interop::TypeName const& propertyType, llm::OS::UI::Xaml::Interop::TypeName const& ownerType, llm::OS::UI::Xaml::PropertyMetadata const& typeMetadata);
        static auto RegisterAttached(param::hstring const& name, llm::OS::UI::Xaml::Interop::TypeName const& propertyType, llm::OS::UI::Xaml::Interop::TypeName const& ownerType, llm::OS::UI::Xaml::PropertyMetadata const& defaultMetadata);
    };
    struct __declspec(empty_bases) DependencyPropertyChangedEventArgs : llm::OS::UI::Xaml::IDependencyPropertyChangedEventArgs
    {
        DependencyPropertyChangedEventArgs(std::nullptr_t) noexcept {}
        DependencyPropertyChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IDependencyPropertyChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DispatcherTimer : llm::OS::UI::Xaml::IDispatcherTimer
    {
        DispatcherTimer(std::nullptr_t) noexcept {}
        DispatcherTimer(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IDispatcherTimer(ptr, take_ownership_from_abi) {}
        DispatcherTimer();
    };
    struct __declspec(empty_bases) DragEventArgs : llm::OS::UI::Xaml::IDragEventArgs,
        impl::base<DragEventArgs, llm::OS::UI::Xaml::RoutedEventArgs>,
        impl::require<DragEventArgs, llm::OS::UI::Xaml::IDragEventArgs2, llm::OS::UI::Xaml::IDragEventArgs3, llm::OS::UI::Xaml::IRoutedEventArgs>
    {
        DragEventArgs(std::nullptr_t) noexcept {}
        DragEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IDragEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DragOperationDeferral : llm::OS::UI::Xaml::IDragOperationDeferral
    {
        DragOperationDeferral(std::nullptr_t) noexcept {}
        DragOperationDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IDragOperationDeferral(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DragStartingEventArgs : llm::OS::UI::Xaml::IDragStartingEventArgs,
        impl::base<DragStartingEventArgs, llm::OS::UI::Xaml::RoutedEventArgs>,
        impl::require<DragStartingEventArgs, llm::OS::UI::Xaml::IDragStartingEventArgs2, llm::OS::UI::Xaml::IRoutedEventArgs>
    {
        DragStartingEventArgs(std::nullptr_t) noexcept {}
        DragStartingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IDragStartingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DragUI : llm::OS::UI::Xaml::IDragUI
    {
        DragUI(std::nullptr_t) noexcept {}
        DragUI(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IDragUI(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DragUIOverride : llm::OS::UI::Xaml::IDragUIOverride
    {
        DragUIOverride(std::nullptr_t) noexcept {}
        DragUIOverride(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IDragUIOverride(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DropCompletedEventArgs : llm::OS::UI::Xaml::IDropCompletedEventArgs,
        impl::base<DropCompletedEventArgs, llm::OS::UI::Xaml::RoutedEventArgs>,
        impl::require<DropCompletedEventArgs, llm::OS::UI::Xaml::IRoutedEventArgs>
    {
        DropCompletedEventArgs(std::nullptr_t) noexcept {}
        DropCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IDropCompletedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DurationHelper : llm::OS::UI::Xaml::IDurationHelper
    {
        DurationHelper(std::nullptr_t) noexcept {}
        DurationHelper(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IDurationHelper(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto Automatic();
        [[nodiscard]] static auto Forever();
        static auto Compare(llm::OS::UI::Xaml::Duration const& duration1, llm::OS::UI::Xaml::Duration const& duration2);
        static auto FromTimeSpan(llm::OS::Foundation::TimeSpan const& timeSpan);
        static auto GetHasTimeSpan(llm::OS::UI::Xaml::Duration const& target);
        static auto Add(llm::OS::UI::Xaml::Duration const& target, llm::OS::UI::Xaml::Duration const& duration);
        static auto Equals(llm::OS::UI::Xaml::Duration const& target, llm::OS::UI::Xaml::Duration const& value);
        static auto Subtract(llm::OS::UI::Xaml::Duration const& target, llm::OS::UI::Xaml::Duration const& duration);
    };
    struct __declspec(empty_bases) EffectiveViewportChangedEventArgs : llm::OS::UI::Xaml::IEffectiveViewportChangedEventArgs
    {
        EffectiveViewportChangedEventArgs(std::nullptr_t) noexcept {}
        EffectiveViewportChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IEffectiveViewportChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ElementFactoryGetArgs : llm::OS::UI::Xaml::IElementFactoryGetArgs
    {
        ElementFactoryGetArgs(std::nullptr_t) noexcept {}
        ElementFactoryGetArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IElementFactoryGetArgs(ptr, take_ownership_from_abi) {}
        ElementFactoryGetArgs();
    };
    struct __declspec(empty_bases) ElementFactoryRecycleArgs : llm::OS::UI::Xaml::IElementFactoryRecycleArgs
    {
        ElementFactoryRecycleArgs(std::nullptr_t) noexcept {}
        ElementFactoryRecycleArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IElementFactoryRecycleArgs(ptr, take_ownership_from_abi) {}
        ElementFactoryRecycleArgs();
    };
    struct __declspec(empty_bases) ElementSoundPlayer : llm::OS::UI::Xaml::IElementSoundPlayer
    {
        ElementSoundPlayer(std::nullptr_t) noexcept {}
        ElementSoundPlayer(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IElementSoundPlayer(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto Volume();
        static auto Volume(double value);
        [[nodiscard]] static auto State();
        static auto State(llm::OS::UI::Xaml::ElementSoundPlayerState const& value);
        static auto Play(llm::OS::UI::Xaml::ElementSoundKind const& sound);
        [[nodiscard]] static auto SpatialAudioMode();
        static auto SpatialAudioMode(llm::OS::UI::Xaml::ElementSpatialAudioMode const& value);
    };
    struct __declspec(empty_bases) EventTrigger : llm::OS::UI::Xaml::IEventTrigger,
        impl::base<EventTrigger, llm::OS::UI::Xaml::TriggerBase, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<EventTrigger, llm::OS::UI::Xaml::ITriggerBase, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        EventTrigger(std::nullptr_t) noexcept {}
        EventTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IEventTrigger(ptr, take_ownership_from_abi) {}
        EventTrigger();
    };
    struct __declspec(empty_bases) ExceptionRoutedEventArgs : llm::OS::UI::Xaml::IExceptionRoutedEventArgs,
        impl::base<ExceptionRoutedEventArgs, llm::OS::UI::Xaml::RoutedEventArgs>,
        impl::require<ExceptionRoutedEventArgs, llm::OS::UI::Xaml::IRoutedEventArgs>
    {
        ExceptionRoutedEventArgs(std::nullptr_t) noexcept {}
        ExceptionRoutedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IExceptionRoutedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FrameworkElement : llm::OS::UI::Xaml::IFrameworkElement,
        impl::base<FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<FrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        FrameworkElement(std::nullptr_t) noexcept {}
        FrameworkElement(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IFrameworkElement(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto TagProperty();
        [[nodiscard]] static auto LanguageProperty();
        [[nodiscard]] static auto ActualWidthProperty();
        [[nodiscard]] static auto ActualHeightProperty();
        [[nodiscard]] static auto WidthProperty();
        [[nodiscard]] static auto HeightProperty();
        [[nodiscard]] static auto MinWidthProperty();
        [[nodiscard]] static auto MaxWidthProperty();
        [[nodiscard]] static auto MinHeightProperty();
        [[nodiscard]] static auto MaxHeightProperty();
        [[nodiscard]] static auto HorizontalAlignmentProperty();
        [[nodiscard]] static auto VerticalAlignmentProperty();
        [[nodiscard]] static auto MarginProperty();
        [[nodiscard]] static auto NameProperty();
        [[nodiscard]] static auto DataContextProperty();
        [[nodiscard]] static auto StyleProperty();
        [[nodiscard]] static auto FlowDirectionProperty();
        [[nodiscard]] static auto RequestedThemeProperty();
        [[nodiscard]] static auto AllowFocusOnInteractionProperty();
        [[nodiscard]] static auto FocusVisualMarginProperty();
        [[nodiscard]] static auto FocusVisualSecondaryThicknessProperty();
        [[nodiscard]] static auto FocusVisualPrimaryThicknessProperty();
        [[nodiscard]] static auto FocusVisualSecondaryBrushProperty();
        [[nodiscard]] static auto FocusVisualPrimaryBrushProperty();
        [[nodiscard]] static auto AllowFocusWhenDisabledProperty();
        static auto DeferTree(llm::OS::UI::Xaml::DependencyObject const& element);
        [[nodiscard]] static auto ActualThemeProperty();
    };
    struct __declspec(empty_bases) FrameworkTemplate : llm::OS::UI::Xaml::IFrameworkTemplate,
        impl::base<FrameworkTemplate, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<FrameworkTemplate, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        FrameworkTemplate(std::nullptr_t) noexcept {}
        FrameworkTemplate(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IFrameworkTemplate(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FrameworkView : llm::OS::UI::Xaml::IFrameworkView,
        impl::require<FrameworkView, llm::OS::ApplicationModel::Core::IFrameworkView>
    {
        FrameworkView(std::nullptr_t) noexcept {}
        FrameworkView(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IFrameworkView(ptr, take_ownership_from_abi) {}
        FrameworkView();
    };
    struct __declspec(empty_bases) FrameworkViewSource : llm::OS::UI::Xaml::IFrameworkViewSource,
        impl::require<FrameworkViewSource, llm::OS::ApplicationModel::Core::IFrameworkViewSource>
    {
        FrameworkViewSource(std::nullptr_t) noexcept {}
        FrameworkViewSource(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IFrameworkViewSource(ptr, take_ownership_from_abi) {}
        FrameworkViewSource();
    };
    struct __declspec(empty_bases) GridLengthHelper : llm::OS::UI::Xaml::IGridLengthHelper
    {
        GridLengthHelper(std::nullptr_t) noexcept {}
        GridLengthHelper(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IGridLengthHelper(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto Auto();
        static auto FromPixels(double pixels);
        static auto FromValueAndType(double value, llm::OS::UI::Xaml::GridUnitType const& type);
        static auto GetIsAbsolute(llm::OS::UI::Xaml::GridLength const& target);
        static auto GetIsAuto(llm::OS::UI::Xaml::GridLength const& target);
        static auto GetIsStar(llm::OS::UI::Xaml::GridLength const& target);
        static auto Equals(llm::OS::UI::Xaml::GridLength const& target, llm::OS::UI::Xaml::GridLength const& value);
    };
    struct __declspec(empty_bases) MediaFailedRoutedEventArgs : llm::OS::UI::Xaml::IMediaFailedRoutedEventArgs,
        impl::base<MediaFailedRoutedEventArgs, llm::OS::UI::Xaml::ExceptionRoutedEventArgs, llm::OS::UI::Xaml::RoutedEventArgs>,
        impl::require<MediaFailedRoutedEventArgs, llm::OS::UI::Xaml::IExceptionRoutedEventArgs, llm::OS::UI::Xaml::IRoutedEventArgs>
    {
        MediaFailedRoutedEventArgs(std::nullptr_t) noexcept {}
        MediaFailedRoutedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IMediaFailedRoutedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PointHelper : llm::OS::UI::Xaml::IPointHelper
    {
        PointHelper(std::nullptr_t) noexcept {}
        PointHelper(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IPointHelper(ptr, take_ownership_from_abi) {}
        static auto FromCoordinates(float x, float y);
    };
    struct __declspec(empty_bases) PropertyMetadata : llm::OS::UI::Xaml::IPropertyMetadata
    {
        PropertyMetadata(std::nullptr_t) noexcept {}
        PropertyMetadata(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IPropertyMetadata(ptr, take_ownership_from_abi) {}
        explicit PropertyMetadata(llm::OS::Foundation::IInspectable const& defaultValue);
        PropertyMetadata(llm::OS::Foundation::IInspectable const& defaultValue, llm::OS::UI::Xaml::PropertyChangedCallback const& propertyChangedCallback);
        static auto Create(llm::OS::Foundation::IInspectable const& defaultValue);
        static auto Create(llm::OS::Foundation::IInspectable const& defaultValue, llm::OS::UI::Xaml::PropertyChangedCallback const& propertyChangedCallback);
        static auto Create(llm::OS::UI::Xaml::CreateDefaultValueCallback const& createDefaultValueCallback);
        static auto Create(llm::OS::UI::Xaml::CreateDefaultValueCallback const& createDefaultValueCallback, llm::OS::UI::Xaml::PropertyChangedCallback const& propertyChangedCallback);
    };
    struct __declspec(empty_bases) PropertyPath : llm::OS::UI::Xaml::IPropertyPath,
        impl::base<PropertyPath, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<PropertyPath, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        PropertyPath(std::nullptr_t) noexcept {}
        PropertyPath(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IPropertyPath(ptr, take_ownership_from_abi) {}
        explicit PropertyPath(param::hstring const& path);
    };
    struct __declspec(empty_bases) RectHelper : llm::OS::UI::Xaml::IRectHelper
    {
        RectHelper(std::nullptr_t) noexcept {}
        RectHelper(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IRectHelper(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto Empty();
        static auto FromCoordinatesAndDimensions(float x, float y, float width, float height);
        static auto FromPoints(llm::OS::Foundation::Point const& point1, llm::OS::Foundation::Point const& point2);
        static auto FromLocationAndSize(llm::OS::Foundation::Point const& location, llm::OS::Foundation::Size const& size);
        static auto GetIsEmpty(llm::OS::Foundation::Rect const& target);
        static auto GetBottom(llm::OS::Foundation::Rect const& target);
        static auto GetLeft(llm::OS::Foundation::Rect const& target);
        static auto GetRight(llm::OS::Foundation::Rect const& target);
        static auto GetTop(llm::OS::Foundation::Rect const& target);
        static auto Contains(llm::OS::Foundation::Rect const& target, llm::OS::Foundation::Point const& point);
        static auto Equals(llm::OS::Foundation::Rect const& target, llm::OS::Foundation::Rect const& value);
        static auto Intersect(llm::OS::Foundation::Rect const& target, llm::OS::Foundation::Rect const& rect);
        static auto Union(llm::OS::Foundation::Rect const& target, llm::OS::Foundation::Point const& point);
        static auto Union(llm::OS::Foundation::Rect const& target, llm::OS::Foundation::Rect const& rect);
    };
    struct __declspec(empty_bases) ResourceDictionary : llm::OS::UI::Xaml::IResourceDictionary,
        impl::base<ResourceDictionary, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<ResourceDictionary, llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::Collections::IKeyValuePair<llm::OS::Foundation::IInspectable, llm::OS::Foundation::IInspectable>>, llm::OS::Foundation::Collections::IMap<llm::OS::Foundation::IInspectable, llm::OS::Foundation::IInspectable>, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        ResourceDictionary(std::nullptr_t) noexcept {}
        ResourceDictionary(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IResourceDictionary(ptr, take_ownership_from_abi) {}
        ResourceDictionary();
    };
    struct __declspec(empty_bases) RoutedEvent : llm::OS::UI::Xaml::IRoutedEvent
    {
        RoutedEvent(std::nullptr_t) noexcept {}
        RoutedEvent(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IRoutedEvent(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RoutedEventArgs : llm::OS::UI::Xaml::IRoutedEventArgs
    {
        RoutedEventArgs(std::nullptr_t) noexcept {}
        RoutedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IRoutedEventArgs(ptr, take_ownership_from_abi) {}
        RoutedEventArgs();
    };
    struct __declspec(empty_bases) ScalarTransition : llm::OS::UI::Xaml::IScalarTransition
    {
        ScalarTransition(std::nullptr_t) noexcept {}
        ScalarTransition(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IScalarTransition(ptr, take_ownership_from_abi) {}
        ScalarTransition();
    };
    struct __declspec(empty_bases) Setter : llm::OS::UI::Xaml::ISetter,
        impl::base<Setter, llm::OS::UI::Xaml::SetterBase, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<Setter, llm::OS::UI::Xaml::ISetter2, llm::OS::UI::Xaml::ISetterBase, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        Setter(std::nullptr_t) noexcept {}
        Setter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::ISetter(ptr, take_ownership_from_abi) {}
        Setter();
        Setter(llm::OS::UI::Xaml::DependencyProperty const& targetProperty, llm::OS::Foundation::IInspectable const& value);
    };
    struct __declspec(empty_bases) SetterBase : llm::OS::UI::Xaml::ISetterBase,
        impl::base<SetterBase, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<SetterBase, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        SetterBase(std::nullptr_t) noexcept {}
        SetterBase(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::ISetterBase(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SetterBaseCollection : llm::OS::UI::Xaml::ISetterBaseCollection,
        impl::require<SetterBaseCollection, llm::OS::Foundation::Collections::IIterable<llm::OS::UI::Xaml::SetterBase>, llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::SetterBase>>
    {
        SetterBaseCollection(std::nullptr_t) noexcept {}
        SetterBaseCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::ISetterBaseCollection(ptr, take_ownership_from_abi) {}
        SetterBaseCollection();
    };
    struct __declspec(empty_bases) SizeChangedEventArgs : llm::OS::UI::Xaml::ISizeChangedEventArgs,
        impl::base<SizeChangedEventArgs, llm::OS::UI::Xaml::RoutedEventArgs>,
        impl::require<SizeChangedEventArgs, llm::OS::UI::Xaml::IRoutedEventArgs>
    {
        SizeChangedEventArgs(std::nullptr_t) noexcept {}
        SizeChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::ISizeChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SizeHelper : llm::OS::UI::Xaml::ISizeHelper
    {
        SizeHelper(std::nullptr_t) noexcept {}
        SizeHelper(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::ISizeHelper(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto Empty();
        static auto FromDimensions(float width, float height);
        static auto GetIsEmpty(llm::OS::Foundation::Size const& target);
        static auto Equals(llm::OS::Foundation::Size const& target, llm::OS::Foundation::Size const& value);
    };
    struct __declspec(empty_bases) StateTrigger : llm::OS::UI::Xaml::IStateTrigger,
        impl::base<StateTrigger, llm::OS::UI::Xaml::StateTriggerBase, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<StateTrigger, llm::OS::UI::Xaml::IStateTriggerBase, llm::OS::UI::Xaml::IStateTriggerBaseProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        StateTrigger(std::nullptr_t) noexcept {}
        StateTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IStateTrigger(ptr, take_ownership_from_abi) {}
        StateTrigger();
        [[nodiscard]] static auto IsActiveProperty();
    };
    struct __declspec(empty_bases) StateTriggerBase : llm::OS::UI::Xaml::IStateTriggerBase,
        impl::base<StateTriggerBase, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<StateTriggerBase, llm::OS::UI::Xaml::IStateTriggerBaseProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        StateTriggerBase(std::nullptr_t) noexcept {}
        StateTriggerBase(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IStateTriggerBase(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) Style : llm::OS::UI::Xaml::IStyle,
        impl::base<Style, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<Style, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        Style(std::nullptr_t) noexcept {}
        Style(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IStyle(ptr, take_ownership_from_abi) {}
        Style();
        explicit Style(llm::OS::UI::Xaml::Interop::TypeName const& targetType);
    };
    struct __declspec(empty_bases) TargetPropertyPath : llm::OS::UI::Xaml::ITargetPropertyPath
    {
        TargetPropertyPath(std::nullptr_t) noexcept {}
        TargetPropertyPath(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::ITargetPropertyPath(ptr, take_ownership_from_abi) {}
        TargetPropertyPath();
        explicit TargetPropertyPath(llm::OS::UI::Xaml::DependencyProperty const& targetProperty);
    };
    struct __declspec(empty_bases) ThicknessHelper : llm::OS::UI::Xaml::IThicknessHelper
    {
        ThicknessHelper(std::nullptr_t) noexcept {}
        ThicknessHelper(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IThicknessHelper(ptr, take_ownership_from_abi) {}
        static auto FromLengths(double left, double top, double right, double bottom);
        static auto FromUniformLength(double uniformLength);
    };
    struct __declspec(empty_bases) TriggerAction : llm::OS::UI::Xaml::ITriggerAction,
        impl::base<TriggerAction, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<TriggerAction, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        TriggerAction(std::nullptr_t) noexcept {}
        TriggerAction(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::ITriggerAction(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TriggerActionCollection : llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::TriggerAction>
    {
        TriggerActionCollection(std::nullptr_t) noexcept {}
        TriggerActionCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::TriggerAction>(ptr, take_ownership_from_abi) {}
        TriggerActionCollection();
    };
    struct __declspec(empty_bases) TriggerBase : llm::OS::UI::Xaml::ITriggerBase,
        impl::base<TriggerBase, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<TriggerBase, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        TriggerBase(std::nullptr_t) noexcept {}
        TriggerBase(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::ITriggerBase(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TriggerCollection : llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::TriggerBase>
    {
        TriggerCollection(std::nullptr_t) noexcept {}
        TriggerCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::TriggerBase>(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UIElement : llm::OS::UI::Xaml::IUIElement,
        impl::base<UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<UIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        UIElement(std::nullptr_t) noexcept {}
        UIElement(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IUIElement(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto KeyDownEvent();
        [[nodiscard]] static auto KeyUpEvent();
        [[nodiscard]] static auto PointerEnteredEvent();
        [[nodiscard]] static auto PointerPressedEvent();
        [[nodiscard]] static auto PointerMovedEvent();
        [[nodiscard]] static auto PointerReleasedEvent();
        [[nodiscard]] static auto PointerExitedEvent();
        [[nodiscard]] static auto PointerCaptureLostEvent();
        [[nodiscard]] static auto PointerCanceledEvent();
        [[nodiscard]] static auto PointerWheelChangedEvent();
        [[nodiscard]] static auto TappedEvent();
        [[nodiscard]] static auto DoubleTappedEvent();
        [[nodiscard]] static auto HoldingEvent();
        [[nodiscard]] static auto RightTappedEvent();
        [[nodiscard]] static auto ManipulationStartingEvent();
        [[nodiscard]] static auto ManipulationInertiaStartingEvent();
        [[nodiscard]] static auto ManipulationStartedEvent();
        [[nodiscard]] static auto ManipulationDeltaEvent();
        [[nodiscard]] static auto ManipulationCompletedEvent();
        [[nodiscard]] static auto DragEnterEvent();
        [[nodiscard]] static auto DragLeaveEvent();
        [[nodiscard]] static auto DragOverEvent();
        [[nodiscard]] static auto DropEvent();
        [[nodiscard]] static auto AllowDropProperty();
        [[nodiscard]] static auto OpacityProperty();
        [[nodiscard]] static auto ClipProperty();
        [[nodiscard]] static auto RenderTransformProperty();
        [[nodiscard]] static auto ProjectionProperty();
        [[nodiscard]] static auto RenderTransformOriginProperty();
        [[nodiscard]] static auto IsHitTestVisibleProperty();
        [[nodiscard]] static auto VisibilityProperty();
        [[nodiscard]] static auto UseLayoutRoundingProperty();
        [[nodiscard]] static auto TransitionsProperty();
        [[nodiscard]] static auto CacheModeProperty();
        [[nodiscard]] static auto IsTapEnabledProperty();
        [[nodiscard]] static auto IsDoubleTapEnabledProperty();
        [[nodiscard]] static auto IsRightTapEnabledProperty();
        [[nodiscard]] static auto IsHoldingEnabledProperty();
        [[nodiscard]] static auto ManipulationModeProperty();
        [[nodiscard]] static auto PointerCapturesProperty();
        [[nodiscard]] static auto ShadowProperty();
        [[nodiscard]] static auto CompositeModeProperty();
        [[nodiscard]] static auto Transform3DProperty();
        [[nodiscard]] static auto CanDragProperty();
        static auto TryStartDirectManipulation(llm::OS::UI::Xaml::Input::Pointer const& value);
        [[nodiscard]] static auto ContextFlyoutProperty();
        [[nodiscard]] static auto ExitDisplayModeOnAccessKeyInvokedProperty();
        [[nodiscard]] static auto IsAccessKeyScopeProperty();
        [[nodiscard]] static auto AccessKeyScopeOwnerProperty();
        [[nodiscard]] static auto AccessKeyProperty();
        [[nodiscard]] static auto LightsProperty();
        [[nodiscard]] static auto KeyTipPlacementModeProperty();
        [[nodiscard]] static auto KeyTipHorizontalOffsetProperty();
        [[nodiscard]] static auto KeyTipVerticalOffsetProperty();
        [[nodiscard]] static auto XYFocusKeyboardNavigationProperty();
        [[nodiscard]] static auto XYFocusUpNavigationStrategyProperty();
        [[nodiscard]] static auto XYFocusDownNavigationStrategyProperty();
        [[nodiscard]] static auto XYFocusLeftNavigationStrategyProperty();
        [[nodiscard]] static auto XYFocusRightNavigationStrategyProperty();
        [[nodiscard]] static auto HighContrastAdjustmentProperty();
        [[nodiscard]] static auto TabFocusNavigationProperty();
        [[nodiscard]] static auto GettingFocusEvent();
        [[nodiscard]] static auto LosingFocusEvent();
        [[nodiscard]] static auto NoFocusCandidateFoundEvent();
        [[nodiscard]] static auto PreviewKeyDownEvent();
        [[nodiscard]] static auto CharacterReceivedEvent();
        [[nodiscard]] static auto PreviewKeyUpEvent();
        [[nodiscard]] static auto BringIntoViewRequestedEvent();
        [[nodiscard]] static auto ContextRequestedEvent();
        [[nodiscard]] static auto KeyTipTargetProperty();
        [[nodiscard]] static auto KeyboardAcceleratorPlacementTargetProperty();
        [[nodiscard]] static auto KeyboardAcceleratorPlacementModeProperty();
        static auto RegisterAsScrollPort(llm::OS::UI::Xaml::UIElement const& element);
        [[nodiscard]] static auto CanBeScrollAnchorProperty();
    };
    struct __declspec(empty_bases) UIElementWeakCollection : llm::OS::UI::Xaml::IUIElementWeakCollection,
        impl::require<UIElementWeakCollection, llm::OS::Foundation::Collections::IIterable<llm::OS::UI::Xaml::UIElement>, llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::UIElement>>
    {
        UIElementWeakCollection(std::nullptr_t) noexcept {}
        UIElementWeakCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IUIElementWeakCollection(ptr, take_ownership_from_abi) {}
        UIElementWeakCollection();
    };
    struct __declspec(empty_bases) UnhandledExceptionEventArgs : llm::OS::UI::Xaml::IUnhandledExceptionEventArgs
    {
        UnhandledExceptionEventArgs(std::nullptr_t) noexcept {}
        UnhandledExceptionEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IUnhandledExceptionEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) Vector3Transition : llm::OS::UI::Xaml::IVector3Transition
    {
        Vector3Transition(std::nullptr_t) noexcept {}
        Vector3Transition(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IVector3Transition(ptr, take_ownership_from_abi) {}
        Vector3Transition();
    };
    struct __declspec(empty_bases) VisualState : llm::OS::UI::Xaml::IVisualState,
        impl::base<VisualState, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<VisualState, llm::OS::UI::Xaml::IVisualState2, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        VisualState(std::nullptr_t) noexcept {}
        VisualState(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IVisualState(ptr, take_ownership_from_abi) {}
        VisualState();
    };
    struct __declspec(empty_bases) VisualStateChangedEventArgs : llm::OS::UI::Xaml::IVisualStateChangedEventArgs
    {
        VisualStateChangedEventArgs(std::nullptr_t) noexcept {}
        VisualStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IVisualStateChangedEventArgs(ptr, take_ownership_from_abi) {}
        VisualStateChangedEventArgs();
    };
    struct __declspec(empty_bases) VisualStateGroup : llm::OS::UI::Xaml::IVisualStateGroup,
        impl::base<VisualStateGroup, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<VisualStateGroup, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        VisualStateGroup(std::nullptr_t) noexcept {}
        VisualStateGroup(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IVisualStateGroup(ptr, take_ownership_from_abi) {}
        VisualStateGroup();
    };
    struct __declspec(empty_bases) VisualStateManager : llm::OS::UI::Xaml::IVisualStateManager,
        impl::base<VisualStateManager, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<VisualStateManager, llm::OS::UI::Xaml::IVisualStateManagerProtected, llm::OS::UI::Xaml::IVisualStateManagerOverrides, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        VisualStateManager(std::nullptr_t) noexcept {}
        VisualStateManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IVisualStateManager(ptr, take_ownership_from_abi) {}
        VisualStateManager();
        static auto GetVisualStateGroups(llm::OS::UI::Xaml::FrameworkElement const& obj);
        [[nodiscard]] static auto CustomVisualStateManagerProperty();
        static auto GetCustomVisualStateManager(llm::OS::UI::Xaml::FrameworkElement const& obj);
        static auto SetCustomVisualStateManager(llm::OS::UI::Xaml::FrameworkElement const& obj, llm::OS::UI::Xaml::VisualStateManager const& value);
        static auto GoToState(llm::OS::UI::Xaml::Controls::Control const& control, param::hstring const& stateName, bool useTransitions);
    };
    struct __declspec(empty_bases) VisualTransition : llm::OS::UI::Xaml::IVisualTransition,
        impl::base<VisualTransition, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<VisualTransition, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        VisualTransition(std::nullptr_t) noexcept {}
        VisualTransition(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IVisualTransition(ptr, take_ownership_from_abi) {}
        VisualTransition();
    };
    struct __declspec(empty_bases) Window : llm::OS::UI::Xaml::IWindow,
        impl::require<Window, llm::OS::UI::Xaml::IWindow2, llm::OS::UI::Xaml::IWindow3, llm::OS::UI::Xaml::IWindow4>
    {
        Window(std::nullptr_t) noexcept {}
        Window(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IWindow(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto Current();
    };
    struct __declspec(empty_bases) WindowCreatedEventArgs : llm::OS::UI::Xaml::IWindowCreatedEventArgs
    {
        WindowCreatedEventArgs(std::nullptr_t) noexcept {}
        WindowCreatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IWindowCreatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) XamlRoot : llm::OS::UI::Xaml::IXamlRoot
    {
        XamlRoot(std::nullptr_t) noexcept {}
        XamlRoot(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IXamlRoot(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) XamlRootChangedEventArgs : llm::OS::UI::Xaml::IXamlRootChangedEventArgs
    {
        XamlRootChangedEventArgs(std::nullptr_t) noexcept {}
        XamlRootChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::IXamlRootChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    template <typename D>
    class IApplicationOverridesT
    {
        D& shim() noexcept { return *static_cast<D*>(this); }
        D const& shim() const noexcept { return *static_cast<const D*>(this); }
    public:
        using IApplicationOverrides = llm::OS::UI::Xaml::IApplicationOverrides;
        LLM_IMPL_AUTO(void) OnActivated(llm::OS::ApplicationModel::Activation::IActivatedEventArgs const& args) const;
        LLM_IMPL_AUTO(void) OnLaunched(llm::OS::ApplicationModel::Activation::LaunchActivatedEventArgs const& args) const;
        LLM_IMPL_AUTO(void) OnFileActivated(llm::OS::ApplicationModel::Activation::FileActivatedEventArgs const& args) const;
        LLM_IMPL_AUTO(void) OnSearchActivated(llm::OS::ApplicationModel::Activation::SearchActivatedEventArgs const& args) const;
        LLM_IMPL_AUTO(void) OnShareTargetActivated(llm::OS::ApplicationModel::Activation::ShareTargetActivatedEventArgs const& args) const;
        LLM_IMPL_AUTO(void) OnFileOpenPickerActivated(llm::OS::ApplicationModel::Activation::FileOpenPickerActivatedEventArgs const& args) const;
        LLM_IMPL_AUTO(void) OnFileSavePickerActivated(llm::OS::ApplicationModel::Activation::FileSavePickerActivatedEventArgs const& args) const;
        LLM_IMPL_AUTO(void) OnCachedFileUpdaterActivated(llm::OS::ApplicationModel::Activation::CachedFileUpdaterActivatedEventArgs const& args) const;
        LLM_IMPL_AUTO(void) OnWindowCreated(llm::OS::UI::Xaml::WindowCreatedEventArgs const& args) const;
    };
    template <typename D>
    class IApplicationOverrides2T
    {
        D& shim() noexcept { return *static_cast<D*>(this); }
        D const& shim() const noexcept { return *static_cast<const D*>(this); }
    public:
        using IApplicationOverrides2 = llm::OS::UI::Xaml::IApplicationOverrides2;
        LLM_IMPL_AUTO(void) OnBackgroundActivated(llm::OS::ApplicationModel::Activation::BackgroundActivatedEventArgs const& args) const;
    };
    template <typename D>
    class IFrameworkElementOverridesT
    {
        D& shim() noexcept { return *static_cast<D*>(this); }
        D const& shim() const noexcept { return *static_cast<const D*>(this); }
    public:
        using IFrameworkElementOverrides = llm::OS::UI::Xaml::IFrameworkElementOverrides;
        LLM_IMPL_AUTO(llm::OS::Foundation::Size) MeasureOverride(llm::OS::Foundation::Size const& availableSize) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Size) ArrangeOverride(llm::OS::Foundation::Size const& finalSize) const;
        LLM_IMPL_AUTO(void) OnApplyTemplate() const;
    };
    template <typename D>
    class IFrameworkElementOverrides2T
    {
        D& shim() noexcept { return *static_cast<D*>(this); }
        D const& shim() const noexcept { return *static_cast<const D*>(this); }
    public:
        using IFrameworkElementOverrides2 = llm::OS::UI::Xaml::IFrameworkElementOverrides2;
        LLM_IMPL_AUTO(bool) GoToElementStateCore(param::hstring const& stateName, bool useTransitions) const;
    };
    template <typename D>
    class IUIElementOverridesT
    {
        D& shim() noexcept { return *static_cast<D*>(this); }
        D const& shim() const noexcept { return *static_cast<const D*>(this); }
    public:
        using IUIElementOverrides = llm::OS::UI::Xaml::IUIElementOverrides;
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutomationPeer) OnCreateAutomationPeer() const;
        LLM_IMPL_AUTO(void) OnDisconnectVisualChildren() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::Point>>) FindSubElementsForTouchTargeting(llm::OS::Foundation::Point const& point, llm::OS::Foundation::Rect const& boundingRect) const;
    };
    template <typename D>
    class IUIElementOverrides7T
    {
        D& shim() noexcept { return *static_cast<D*>(this); }
        D const& shim() const noexcept { return *static_cast<const D*>(this); }
    public:
        using IUIElementOverrides7 = llm::OS::UI::Xaml::IUIElementOverrides7;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IIterable<llm::OS::UI::Xaml::DependencyObject>) GetChildrenInTabFocusOrder() const;
        LLM_IMPL_AUTO(void) OnProcessKeyboardAccelerators(llm::OS::UI::Xaml::Input::ProcessKeyboardAcceleratorEventArgs const& args) const;
    };
    template <typename D>
    class IUIElementOverrides8T
    {
        D& shim() noexcept { return *static_cast<D*>(this); }
        D const& shim() const noexcept { return *static_cast<const D*>(this); }
    public:
        using IUIElementOverrides8 = llm::OS::UI::Xaml::IUIElementOverrides8;
        LLM_IMPL_AUTO(void) OnKeyboardAcceleratorInvoked(llm::OS::UI::Xaml::Input::KeyboardAcceleratorInvokedEventArgs const& args) const;
        LLM_IMPL_AUTO(void) OnBringIntoViewRequested(llm::OS::UI::Xaml::BringIntoViewRequestedEventArgs const& e) const;
    };
    template <typename D>
    class IUIElementOverrides9T
    {
        D& shim() noexcept { return *static_cast<D*>(this); }
        D const& shim() const noexcept { return *static_cast<const D*>(this); }
    public:
        using IUIElementOverrides9 = llm::OS::UI::Xaml::IUIElementOverrides9;
        LLM_IMPL_AUTO(void) PopulatePropertyInfoOverride(param::hstring const& propertyName, llm::OS::UI::Composition::AnimationPropertyInfo const& animationPropertyInfo) const;
    };
    template <typename D>
    class IVisualStateManagerOverridesT
    {
        D& shim() noexcept { return *static_cast<D*>(this); }
        D const& shim() const noexcept { return *static_cast<const D*>(this); }
    public:
        using IVisualStateManagerOverrides = llm::OS::UI::Xaml::IVisualStateManagerOverrides;
        LLM_IMPL_AUTO(bool) GoToStateCore(llm::OS::UI::Xaml::Controls::Control const& control, llm::OS::UI::Xaml::FrameworkElement const& templateRoot, param::hstring const& stateName, llm::OS::UI::Xaml::VisualStateGroup const& group, llm::OS::UI::Xaml::VisualState const& state, bool useTransitions) const;
    };
}
#endif
