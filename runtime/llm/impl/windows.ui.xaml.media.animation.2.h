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
#ifndef LLM_OS_UI_Xaml_Media_Animation_2_H
#define LLM_OS_UI_Xaml_Media_Animation_2_H
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.UI.Xaml.2.h"
#include "llm/impl/Windows.UI.Xaml.Controls.2.h"
#include "llm/impl/Windows.UI.Xaml.Media.Animation.1.h"
LLM_EXPORT namespace llm::OS::UI::Xaml::Media::Animation
{
    struct KeyTime
    {
        llm::OS::Foundation::TimeSpan TimeSpan;
    };
    inline bool operator==(KeyTime const& left, KeyTime const& right) noexcept
    {
        return left.TimeSpan == right.TimeSpan;
    }
    inline bool operator!=(KeyTime const& left, KeyTime const& right) noexcept
    {
        return !(left == right);
    }
    struct RepeatBehavior
    {
        double Count;
        llm::OS::Foundation::TimeSpan Duration;
        llm::OS::UI::Xaml::Media::Animation::RepeatBehaviorType Type;
    };
    inline bool operator==(RepeatBehavior const& left, RepeatBehavior const& right) noexcept
    {
        return left.Count == right.Count && left.Duration == right.Duration && left.Type == right.Type;
    }
    inline bool operator!=(RepeatBehavior const& left, RepeatBehavior const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) AddDeleteThemeTransition : llm::OS::UI::Xaml::Media::Animation::IAddDeleteThemeTransition,
        impl::base<AddDeleteThemeTransition, llm::OS::UI::Xaml::Media::Animation::Transition, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<AddDeleteThemeTransition, llm::OS::UI::Xaml::Media::Animation::ITransition, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        AddDeleteThemeTransition(std::nullptr_t) noexcept {}
        AddDeleteThemeTransition(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IAddDeleteThemeTransition(ptr, take_ownership_from_abi) {}
        AddDeleteThemeTransition();
    };
    struct __declspec(empty_bases) BackEase : llm::OS::UI::Xaml::Media::Animation::IBackEase,
        impl::base<BackEase, llm::OS::UI::Xaml::Media::Animation::EasingFunctionBase, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<BackEase, llm::OS::UI::Xaml::Media::Animation::IEasingFunctionBase, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        BackEase(std::nullptr_t) noexcept {}
        BackEase(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IBackEase(ptr, take_ownership_from_abi) {}
        BackEase();
        [[nodiscard]] static auto AmplitudeProperty();
    };
    struct __declspec(empty_bases) BasicConnectedAnimationConfiguration : llm::OS::UI::Xaml::Media::Animation::IBasicConnectedAnimationConfiguration,
        impl::base<BasicConnectedAnimationConfiguration, llm::OS::UI::Xaml::Media::Animation::ConnectedAnimationConfiguration>,
        impl::require<BasicConnectedAnimationConfiguration, llm::OS::UI::Xaml::Media::Animation::IConnectedAnimationConfiguration>
    {
        BasicConnectedAnimationConfiguration(std::nullptr_t) noexcept {}
        BasicConnectedAnimationConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IBasicConnectedAnimationConfiguration(ptr, take_ownership_from_abi) {}
        BasicConnectedAnimationConfiguration();
    };
    struct __declspec(empty_bases) BeginStoryboard : llm::OS::UI::Xaml::Media::Animation::IBeginStoryboard,
        impl::base<BeginStoryboard, llm::OS::UI::Xaml::TriggerAction, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<BeginStoryboard, llm::OS::UI::Xaml::ITriggerAction, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        BeginStoryboard(std::nullptr_t) noexcept {}
        BeginStoryboard(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IBeginStoryboard(ptr, take_ownership_from_abi) {}
        BeginStoryboard();
        [[nodiscard]] static auto StoryboardProperty();
    };
    struct __declspec(empty_bases) BounceEase : llm::OS::UI::Xaml::Media::Animation::IBounceEase,
        impl::base<BounceEase, llm::OS::UI::Xaml::Media::Animation::EasingFunctionBase, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<BounceEase, llm::OS::UI::Xaml::Media::Animation::IEasingFunctionBase, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        BounceEase(std::nullptr_t) noexcept {}
        BounceEase(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IBounceEase(ptr, take_ownership_from_abi) {}
        BounceEase();
        [[nodiscard]] static auto BouncesProperty();
        [[nodiscard]] static auto BouncinessProperty();
    };
    struct __declspec(empty_bases) CircleEase : llm::OS::UI::Xaml::Media::Animation::ICircleEase,
        impl::base<CircleEase, llm::OS::UI::Xaml::Media::Animation::EasingFunctionBase, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<CircleEase, llm::OS::UI::Xaml::Media::Animation::IEasingFunctionBase, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        CircleEase(std::nullptr_t) noexcept {}
        CircleEase(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::ICircleEase(ptr, take_ownership_from_abi) {}
        CircleEase();
    };
    struct __declspec(empty_bases) ColorAnimation : llm::OS::UI::Xaml::Media::Animation::IColorAnimation,
        impl::base<ColorAnimation, llm::OS::UI::Xaml::Media::Animation::Timeline, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<ColorAnimation, llm::OS::UI::Xaml::Media::Animation::ITimeline, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        ColorAnimation(std::nullptr_t) noexcept {}
        ColorAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IColorAnimation(ptr, take_ownership_from_abi) {}
        ColorAnimation();
        [[nodiscard]] static auto FromProperty();
        [[nodiscard]] static auto ToProperty();
        [[nodiscard]] static auto ByProperty();
        [[nodiscard]] static auto EasingFunctionProperty();
        [[nodiscard]] static auto EnableDependentAnimationProperty();
    };
    struct __declspec(empty_bases) ColorAnimationUsingKeyFrames : llm::OS::UI::Xaml::Media::Animation::IColorAnimationUsingKeyFrames,
        impl::base<ColorAnimationUsingKeyFrames, llm::OS::UI::Xaml::Media::Animation::Timeline, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<ColorAnimationUsingKeyFrames, llm::OS::UI::Xaml::Media::Animation::ITimeline, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        ColorAnimationUsingKeyFrames(std::nullptr_t) noexcept {}
        ColorAnimationUsingKeyFrames(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IColorAnimationUsingKeyFrames(ptr, take_ownership_from_abi) {}
        ColorAnimationUsingKeyFrames();
        [[nodiscard]] static auto EnableDependentAnimationProperty();
    };
    struct __declspec(empty_bases) ColorKeyFrame : llm::OS::UI::Xaml::Media::Animation::IColorKeyFrame,
        impl::base<ColorKeyFrame, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<ColorKeyFrame, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        ColorKeyFrame(std::nullptr_t) noexcept {}
        ColorKeyFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IColorKeyFrame(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto ValueProperty();
        [[nodiscard]] static auto KeyTimeProperty();
    };
    struct __declspec(empty_bases) ColorKeyFrameCollection : llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Media::Animation::ColorKeyFrame>
    {
        ColorKeyFrameCollection(std::nullptr_t) noexcept {}
        ColorKeyFrameCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Media::Animation::ColorKeyFrame>(ptr, take_ownership_from_abi) {}
        ColorKeyFrameCollection();
    };
    struct __declspec(empty_bases) CommonNavigationTransitionInfo : llm::OS::UI::Xaml::Media::Animation::ICommonNavigationTransitionInfo,
        impl::base<CommonNavigationTransitionInfo, llm::OS::UI::Xaml::Media::Animation::NavigationTransitionInfo, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<CommonNavigationTransitionInfo, llm::OS::UI::Xaml::Media::Animation::INavigationTransitionInfo, llm::OS::UI::Xaml::Media::Animation::INavigationTransitionInfoOverrides, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        CommonNavigationTransitionInfo(std::nullptr_t) noexcept {}
        CommonNavigationTransitionInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::ICommonNavigationTransitionInfo(ptr, take_ownership_from_abi) {}
        CommonNavigationTransitionInfo();
        [[nodiscard]] static auto IsStaggeringEnabledProperty();
        [[nodiscard]] static auto IsStaggerElementProperty();
        static auto GetIsStaggerElement(llm::OS::UI::Xaml::UIElement const& element);
        static auto SetIsStaggerElement(llm::OS::UI::Xaml::UIElement const& element, bool value);
    };
    struct __declspec(empty_bases) ConnectedAnimation : llm::OS::UI::Xaml::Media::Animation::IConnectedAnimation,
        impl::require<ConnectedAnimation, llm::OS::UI::Xaml::Media::Animation::IConnectedAnimation2, llm::OS::UI::Xaml::Media::Animation::IConnectedAnimation3>
    {
        ConnectedAnimation(std::nullptr_t) noexcept {}
        ConnectedAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IConnectedAnimation(ptr, take_ownership_from_abi) {}
        using llm::OS::UI::Xaml::Media::Animation::IConnectedAnimation::TryStart;
        using impl::consume_t<ConnectedAnimation, llm::OS::UI::Xaml::Media::Animation::IConnectedAnimation2>::TryStart;
    };
    struct __declspec(empty_bases) ConnectedAnimationConfiguration : llm::OS::UI::Xaml::Media::Animation::IConnectedAnimationConfiguration
    {
        ConnectedAnimationConfiguration(std::nullptr_t) noexcept {}
        ConnectedAnimationConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IConnectedAnimationConfiguration(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ConnectedAnimationService : llm::OS::UI::Xaml::Media::Animation::IConnectedAnimationService
    {
        ConnectedAnimationService(std::nullptr_t) noexcept {}
        ConnectedAnimationService(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IConnectedAnimationService(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
    };
    struct __declspec(empty_bases) ContentThemeTransition : llm::OS::UI::Xaml::Media::Animation::IContentThemeTransition,
        impl::base<ContentThemeTransition, llm::OS::UI::Xaml::Media::Animation::Transition, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<ContentThemeTransition, llm::OS::UI::Xaml::Media::Animation::ITransition, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        ContentThemeTransition(std::nullptr_t) noexcept {}
        ContentThemeTransition(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IContentThemeTransition(ptr, take_ownership_from_abi) {}
        ContentThemeTransition();
        [[nodiscard]] static auto HorizontalOffsetProperty();
        [[nodiscard]] static auto VerticalOffsetProperty();
    };
    struct __declspec(empty_bases) ContinuumNavigationTransitionInfo : llm::OS::UI::Xaml::Media::Animation::IContinuumNavigationTransitionInfo,
        impl::base<ContinuumNavigationTransitionInfo, llm::OS::UI::Xaml::Media::Animation::NavigationTransitionInfo, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<ContinuumNavigationTransitionInfo, llm::OS::UI::Xaml::Media::Animation::INavigationTransitionInfo, llm::OS::UI::Xaml::Media::Animation::INavigationTransitionInfoOverrides, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        ContinuumNavigationTransitionInfo(std::nullptr_t) noexcept {}
        ContinuumNavigationTransitionInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IContinuumNavigationTransitionInfo(ptr, take_ownership_from_abi) {}
        ContinuumNavigationTransitionInfo();
        [[nodiscard]] static auto ExitElementProperty();
        [[nodiscard]] static auto IsEntranceElementProperty();
        static auto GetIsEntranceElement(llm::OS::UI::Xaml::UIElement const& element);
        static auto SetIsEntranceElement(llm::OS::UI::Xaml::UIElement const& element, bool value);
        [[nodiscard]] static auto IsExitElementProperty();
        static auto GetIsExitElement(llm::OS::UI::Xaml::UIElement const& element);
        static auto SetIsExitElement(llm::OS::UI::Xaml::UIElement const& element, bool value);
        [[nodiscard]] static auto ExitElementContainerProperty();
        static auto GetExitElementContainer(llm::OS::UI::Xaml::Controls::ListViewBase const& element);
        static auto SetExitElementContainer(llm::OS::UI::Xaml::Controls::ListViewBase const& element, bool value);
    };
    struct __declspec(empty_bases) CubicEase : llm::OS::UI::Xaml::Media::Animation::ICubicEase,
        impl::base<CubicEase, llm::OS::UI::Xaml::Media::Animation::EasingFunctionBase, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<CubicEase, llm::OS::UI::Xaml::Media::Animation::IEasingFunctionBase, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        CubicEase(std::nullptr_t) noexcept {}
        CubicEase(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::ICubicEase(ptr, take_ownership_from_abi) {}
        CubicEase();
    };
    struct __declspec(empty_bases) DirectConnectedAnimationConfiguration : llm::OS::UI::Xaml::Media::Animation::IDirectConnectedAnimationConfiguration,
        impl::base<DirectConnectedAnimationConfiguration, llm::OS::UI::Xaml::Media::Animation::ConnectedAnimationConfiguration>,
        impl::require<DirectConnectedAnimationConfiguration, llm::OS::UI::Xaml::Media::Animation::IConnectedAnimationConfiguration>
    {
        DirectConnectedAnimationConfiguration(std::nullptr_t) noexcept {}
        DirectConnectedAnimationConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IDirectConnectedAnimationConfiguration(ptr, take_ownership_from_abi) {}
        DirectConnectedAnimationConfiguration();
    };
    struct __declspec(empty_bases) DiscreteColorKeyFrame : llm::OS::UI::Xaml::Media::Animation::IDiscreteColorKeyFrame,
        impl::base<DiscreteColorKeyFrame, llm::OS::UI::Xaml::Media::Animation::ColorKeyFrame, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<DiscreteColorKeyFrame, llm::OS::UI::Xaml::Media::Animation::IColorKeyFrame, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        DiscreteColorKeyFrame(std::nullptr_t) noexcept {}
        DiscreteColorKeyFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IDiscreteColorKeyFrame(ptr, take_ownership_from_abi) {}
        DiscreteColorKeyFrame();
    };
    struct __declspec(empty_bases) DiscreteDoubleKeyFrame : llm::OS::UI::Xaml::Media::Animation::IDiscreteDoubleKeyFrame,
        impl::base<DiscreteDoubleKeyFrame, llm::OS::UI::Xaml::Media::Animation::DoubleKeyFrame, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<DiscreteDoubleKeyFrame, llm::OS::UI::Xaml::Media::Animation::IDoubleKeyFrame, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        DiscreteDoubleKeyFrame(std::nullptr_t) noexcept {}
        DiscreteDoubleKeyFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IDiscreteDoubleKeyFrame(ptr, take_ownership_from_abi) {}
        DiscreteDoubleKeyFrame();
    };
    struct __declspec(empty_bases) DiscreteObjectKeyFrame : llm::OS::UI::Xaml::Media::Animation::IDiscreteObjectKeyFrame,
        impl::base<DiscreteObjectKeyFrame, llm::OS::UI::Xaml::Media::Animation::ObjectKeyFrame, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<DiscreteObjectKeyFrame, llm::OS::UI::Xaml::Media::Animation::IObjectKeyFrame, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        DiscreteObjectKeyFrame(std::nullptr_t) noexcept {}
        DiscreteObjectKeyFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IDiscreteObjectKeyFrame(ptr, take_ownership_from_abi) {}
        DiscreteObjectKeyFrame();
    };
    struct __declspec(empty_bases) DiscretePointKeyFrame : llm::OS::UI::Xaml::Media::Animation::IDiscretePointKeyFrame,
        impl::base<DiscretePointKeyFrame, llm::OS::UI::Xaml::Media::Animation::PointKeyFrame, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<DiscretePointKeyFrame, llm::OS::UI::Xaml::Media::Animation::IPointKeyFrame, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        DiscretePointKeyFrame(std::nullptr_t) noexcept {}
        DiscretePointKeyFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IDiscretePointKeyFrame(ptr, take_ownership_from_abi) {}
        DiscretePointKeyFrame();
    };
    struct __declspec(empty_bases) DoubleAnimation : llm::OS::UI::Xaml::Media::Animation::IDoubleAnimation,
        impl::base<DoubleAnimation, llm::OS::UI::Xaml::Media::Animation::Timeline, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<DoubleAnimation, llm::OS::UI::Xaml::Media::Animation::ITimeline, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        DoubleAnimation(std::nullptr_t) noexcept {}
        DoubleAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IDoubleAnimation(ptr, take_ownership_from_abi) {}
        DoubleAnimation();
        [[nodiscard]] static auto FromProperty();
        [[nodiscard]] static auto ToProperty();
        [[nodiscard]] static auto ByProperty();
        [[nodiscard]] static auto EasingFunctionProperty();
        [[nodiscard]] static auto EnableDependentAnimationProperty();
    };
    struct __declspec(empty_bases) DoubleAnimationUsingKeyFrames : llm::OS::UI::Xaml::Media::Animation::IDoubleAnimationUsingKeyFrames,
        impl::base<DoubleAnimationUsingKeyFrames, llm::OS::UI::Xaml::Media::Animation::Timeline, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<DoubleAnimationUsingKeyFrames, llm::OS::UI::Xaml::Media::Animation::ITimeline, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        DoubleAnimationUsingKeyFrames(std::nullptr_t) noexcept {}
        DoubleAnimationUsingKeyFrames(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IDoubleAnimationUsingKeyFrames(ptr, take_ownership_from_abi) {}
        DoubleAnimationUsingKeyFrames();
        [[nodiscard]] static auto EnableDependentAnimationProperty();
    };
    struct __declspec(empty_bases) DoubleKeyFrame : llm::OS::UI::Xaml::Media::Animation::IDoubleKeyFrame,
        impl::base<DoubleKeyFrame, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<DoubleKeyFrame, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        DoubleKeyFrame(std::nullptr_t) noexcept {}
        DoubleKeyFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IDoubleKeyFrame(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto ValueProperty();
        [[nodiscard]] static auto KeyTimeProperty();
    };
    struct __declspec(empty_bases) DoubleKeyFrameCollection : llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Media::Animation::DoubleKeyFrame>
    {
        DoubleKeyFrameCollection(std::nullptr_t) noexcept {}
        DoubleKeyFrameCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Media::Animation::DoubleKeyFrame>(ptr, take_ownership_from_abi) {}
        DoubleKeyFrameCollection();
    };
    struct __declspec(empty_bases) DragItemThemeAnimation : llm::OS::UI::Xaml::Media::Animation::IDragItemThemeAnimation,
        impl::base<DragItemThemeAnimation, llm::OS::UI::Xaml::Media::Animation::Timeline, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<DragItemThemeAnimation, llm::OS::UI::Xaml::Media::Animation::ITimeline, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        DragItemThemeAnimation(std::nullptr_t) noexcept {}
        DragItemThemeAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IDragItemThemeAnimation(ptr, take_ownership_from_abi) {}
        DragItemThemeAnimation();
        [[nodiscard]] static auto TargetNameProperty();
    };
    struct __declspec(empty_bases) DragOverThemeAnimation : llm::OS::UI::Xaml::Media::Animation::IDragOverThemeAnimation,
        impl::base<DragOverThemeAnimation, llm::OS::UI::Xaml::Media::Animation::Timeline, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<DragOverThemeAnimation, llm::OS::UI::Xaml::Media::Animation::ITimeline, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        DragOverThemeAnimation(std::nullptr_t) noexcept {}
        DragOverThemeAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IDragOverThemeAnimation(ptr, take_ownership_from_abi) {}
        DragOverThemeAnimation();
        [[nodiscard]] static auto TargetNameProperty();
        [[nodiscard]] static auto ToOffsetProperty();
        [[nodiscard]] static auto DirectionProperty();
    };
    struct __declspec(empty_bases) DrillInNavigationTransitionInfo : llm::OS::UI::Xaml::Media::Animation::IDrillInNavigationTransitionInfo,
        impl::base<DrillInNavigationTransitionInfo, llm::OS::UI::Xaml::Media::Animation::NavigationTransitionInfo, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<DrillInNavigationTransitionInfo, llm::OS::UI::Xaml::Media::Animation::INavigationTransitionInfo, llm::OS::UI::Xaml::Media::Animation::INavigationTransitionInfoOverrides, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        DrillInNavigationTransitionInfo(std::nullptr_t) noexcept {}
        DrillInNavigationTransitionInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IDrillInNavigationTransitionInfo(ptr, take_ownership_from_abi) {}
        DrillInNavigationTransitionInfo();
    };
    struct __declspec(empty_bases) DrillInThemeAnimation : llm::OS::UI::Xaml::Media::Animation::IDrillInThemeAnimation,
        impl::base<DrillInThemeAnimation, llm::OS::UI::Xaml::Media::Animation::Timeline, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<DrillInThemeAnimation, llm::OS::UI::Xaml::Media::Animation::ITimeline, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        DrillInThemeAnimation(std::nullptr_t) noexcept {}
        DrillInThemeAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IDrillInThemeAnimation(ptr, take_ownership_from_abi) {}
        DrillInThemeAnimation();
        [[nodiscard]] static auto EntranceTargetNameProperty();
        [[nodiscard]] static auto EntranceTargetProperty();
        [[nodiscard]] static auto ExitTargetNameProperty();
        [[nodiscard]] static auto ExitTargetProperty();
    };
    struct __declspec(empty_bases) DrillOutThemeAnimation : llm::OS::UI::Xaml::Media::Animation::IDrillOutThemeAnimation,
        impl::base<DrillOutThemeAnimation, llm::OS::UI::Xaml::Media::Animation::Timeline, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<DrillOutThemeAnimation, llm::OS::UI::Xaml::Media::Animation::ITimeline, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        DrillOutThemeAnimation(std::nullptr_t) noexcept {}
        DrillOutThemeAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IDrillOutThemeAnimation(ptr, take_ownership_from_abi) {}
        DrillOutThemeAnimation();
        [[nodiscard]] static auto EntranceTargetNameProperty();
        [[nodiscard]] static auto EntranceTargetProperty();
        [[nodiscard]] static auto ExitTargetNameProperty();
        [[nodiscard]] static auto ExitTargetProperty();
    };
    struct __declspec(empty_bases) DropTargetItemThemeAnimation : llm::OS::UI::Xaml::Media::Animation::IDropTargetItemThemeAnimation,
        impl::base<DropTargetItemThemeAnimation, llm::OS::UI::Xaml::Media::Animation::Timeline, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<DropTargetItemThemeAnimation, llm::OS::UI::Xaml::Media::Animation::ITimeline, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        DropTargetItemThemeAnimation(std::nullptr_t) noexcept {}
        DropTargetItemThemeAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IDropTargetItemThemeAnimation(ptr, take_ownership_from_abi) {}
        DropTargetItemThemeAnimation();
        [[nodiscard]] static auto TargetNameProperty();
    };
    struct __declspec(empty_bases) EasingColorKeyFrame : llm::OS::UI::Xaml::Media::Animation::IEasingColorKeyFrame,
        impl::base<EasingColorKeyFrame, llm::OS::UI::Xaml::Media::Animation::ColorKeyFrame, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<EasingColorKeyFrame, llm::OS::UI::Xaml::Media::Animation::IColorKeyFrame, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        EasingColorKeyFrame(std::nullptr_t) noexcept {}
        EasingColorKeyFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IEasingColorKeyFrame(ptr, take_ownership_from_abi) {}
        EasingColorKeyFrame();
        [[nodiscard]] static auto EasingFunctionProperty();
    };
    struct __declspec(empty_bases) EasingDoubleKeyFrame : llm::OS::UI::Xaml::Media::Animation::IEasingDoubleKeyFrame,
        impl::base<EasingDoubleKeyFrame, llm::OS::UI::Xaml::Media::Animation::DoubleKeyFrame, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<EasingDoubleKeyFrame, llm::OS::UI::Xaml::Media::Animation::IDoubleKeyFrame, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        EasingDoubleKeyFrame(std::nullptr_t) noexcept {}
        EasingDoubleKeyFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IEasingDoubleKeyFrame(ptr, take_ownership_from_abi) {}
        EasingDoubleKeyFrame();
        [[nodiscard]] static auto EasingFunctionProperty();
    };
    struct __declspec(empty_bases) EasingFunctionBase : llm::OS::UI::Xaml::Media::Animation::IEasingFunctionBase,
        impl::base<EasingFunctionBase, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<EasingFunctionBase, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        EasingFunctionBase(std::nullptr_t) noexcept {}
        EasingFunctionBase(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IEasingFunctionBase(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto EasingModeProperty();
    };
    struct __declspec(empty_bases) EasingPointKeyFrame : llm::OS::UI::Xaml::Media::Animation::IEasingPointKeyFrame,
        impl::base<EasingPointKeyFrame, llm::OS::UI::Xaml::Media::Animation::PointKeyFrame, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<EasingPointKeyFrame, llm::OS::UI::Xaml::Media::Animation::IPointKeyFrame, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        EasingPointKeyFrame(std::nullptr_t) noexcept {}
        EasingPointKeyFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IEasingPointKeyFrame(ptr, take_ownership_from_abi) {}
        EasingPointKeyFrame();
        [[nodiscard]] static auto EasingFunctionProperty();
    };
    struct __declspec(empty_bases) EdgeUIThemeTransition : llm::OS::UI::Xaml::Media::Animation::IEdgeUIThemeTransition,
        impl::base<EdgeUIThemeTransition, llm::OS::UI::Xaml::Media::Animation::Transition, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<EdgeUIThemeTransition, llm::OS::UI::Xaml::Media::Animation::ITransition, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        EdgeUIThemeTransition(std::nullptr_t) noexcept {}
        EdgeUIThemeTransition(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IEdgeUIThemeTransition(ptr, take_ownership_from_abi) {}
        EdgeUIThemeTransition();
        [[nodiscard]] static auto EdgeProperty();
    };
    struct __declspec(empty_bases) ElasticEase : llm::OS::UI::Xaml::Media::Animation::IElasticEase,
        impl::base<ElasticEase, llm::OS::UI::Xaml::Media::Animation::EasingFunctionBase, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<ElasticEase, llm::OS::UI::Xaml::Media::Animation::IEasingFunctionBase, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        ElasticEase(std::nullptr_t) noexcept {}
        ElasticEase(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IElasticEase(ptr, take_ownership_from_abi) {}
        ElasticEase();
        [[nodiscard]] static auto OscillationsProperty();
        [[nodiscard]] static auto SpringinessProperty();
    };
    struct __declspec(empty_bases) EntranceNavigationTransitionInfo : llm::OS::UI::Xaml::Media::Animation::IEntranceNavigationTransitionInfo,
        impl::base<EntranceNavigationTransitionInfo, llm::OS::UI::Xaml::Media::Animation::NavigationTransitionInfo, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<EntranceNavigationTransitionInfo, llm::OS::UI::Xaml::Media::Animation::INavigationTransitionInfo, llm::OS::UI::Xaml::Media::Animation::INavigationTransitionInfoOverrides, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        EntranceNavigationTransitionInfo(std::nullptr_t) noexcept {}
        EntranceNavigationTransitionInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IEntranceNavigationTransitionInfo(ptr, take_ownership_from_abi) {}
        EntranceNavigationTransitionInfo();
        [[nodiscard]] static auto IsTargetElementProperty();
        static auto GetIsTargetElement(llm::OS::UI::Xaml::UIElement const& element);
        static auto SetIsTargetElement(llm::OS::UI::Xaml::UIElement const& element, bool value);
    };
    struct __declspec(empty_bases) EntranceThemeTransition : llm::OS::UI::Xaml::Media::Animation::IEntranceThemeTransition,
        impl::base<EntranceThemeTransition, llm::OS::UI::Xaml::Media::Animation::Transition, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<EntranceThemeTransition, llm::OS::UI::Xaml::Media::Animation::ITransition, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        EntranceThemeTransition(std::nullptr_t) noexcept {}
        EntranceThemeTransition(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IEntranceThemeTransition(ptr, take_ownership_from_abi) {}
        EntranceThemeTransition();
        [[nodiscard]] static auto FromHorizontalOffsetProperty();
        [[nodiscard]] static auto FromVerticalOffsetProperty();
        [[nodiscard]] static auto IsStaggeringEnabledProperty();
    };
    struct __declspec(empty_bases) ExponentialEase : llm::OS::UI::Xaml::Media::Animation::IExponentialEase,
        impl::base<ExponentialEase, llm::OS::UI::Xaml::Media::Animation::EasingFunctionBase, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<ExponentialEase, llm::OS::UI::Xaml::Media::Animation::IEasingFunctionBase, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        ExponentialEase(std::nullptr_t) noexcept {}
        ExponentialEase(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IExponentialEase(ptr, take_ownership_from_abi) {}
        ExponentialEase();
        [[nodiscard]] static auto ExponentProperty();
    };
    struct __declspec(empty_bases) FadeInThemeAnimation : llm::OS::UI::Xaml::Media::Animation::IFadeInThemeAnimation,
        impl::base<FadeInThemeAnimation, llm::OS::UI::Xaml::Media::Animation::Timeline, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<FadeInThemeAnimation, llm::OS::UI::Xaml::Media::Animation::ITimeline, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        FadeInThemeAnimation(std::nullptr_t) noexcept {}
        FadeInThemeAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IFadeInThemeAnimation(ptr, take_ownership_from_abi) {}
        FadeInThemeAnimation();
        [[nodiscard]] static auto TargetNameProperty();
    };
    struct __declspec(empty_bases) FadeOutThemeAnimation : llm::OS::UI::Xaml::Media::Animation::IFadeOutThemeAnimation,
        impl::base<FadeOutThemeAnimation, llm::OS::UI::Xaml::Media::Animation::Timeline, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<FadeOutThemeAnimation, llm::OS::UI::Xaml::Media::Animation::ITimeline, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        FadeOutThemeAnimation(std::nullptr_t) noexcept {}
        FadeOutThemeAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IFadeOutThemeAnimation(ptr, take_ownership_from_abi) {}
        FadeOutThemeAnimation();
        [[nodiscard]] static auto TargetNameProperty();
    };
    struct __declspec(empty_bases) GravityConnectedAnimationConfiguration : llm::OS::UI::Xaml::Media::Animation::IGravityConnectedAnimationConfiguration,
        impl::base<GravityConnectedAnimationConfiguration, llm::OS::UI::Xaml::Media::Animation::ConnectedAnimationConfiguration>,
        impl::require<GravityConnectedAnimationConfiguration, llm::OS::UI::Xaml::Media::Animation::IGravityConnectedAnimationConfiguration2, llm::OS::UI::Xaml::Media::Animation::IConnectedAnimationConfiguration>
    {
        GravityConnectedAnimationConfiguration(std::nullptr_t) noexcept {}
        GravityConnectedAnimationConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IGravityConnectedAnimationConfiguration(ptr, take_ownership_from_abi) {}
        GravityConnectedAnimationConfiguration();
    };
    struct __declspec(empty_bases) KeySpline : llm::OS::UI::Xaml::Media::Animation::IKeySpline,
        impl::base<KeySpline, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<KeySpline, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        KeySpline(std::nullptr_t) noexcept {}
        KeySpline(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IKeySpline(ptr, take_ownership_from_abi) {}
        KeySpline();
    };
    struct __declspec(empty_bases) KeyTimeHelper : llm::OS::UI::Xaml::Media::Animation::IKeyTimeHelper
    {
        KeyTimeHelper(std::nullptr_t) noexcept {}
        KeyTimeHelper(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IKeyTimeHelper(ptr, take_ownership_from_abi) {}
        static auto FromTimeSpan(llm::OS::Foundation::TimeSpan const& timeSpan);
    };
    struct __declspec(empty_bases) LinearColorKeyFrame : llm::OS::UI::Xaml::Media::Animation::ILinearColorKeyFrame,
        impl::base<LinearColorKeyFrame, llm::OS::UI::Xaml::Media::Animation::ColorKeyFrame, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<LinearColorKeyFrame, llm::OS::UI::Xaml::Media::Animation::IColorKeyFrame, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        LinearColorKeyFrame(std::nullptr_t) noexcept {}
        LinearColorKeyFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::ILinearColorKeyFrame(ptr, take_ownership_from_abi) {}
        LinearColorKeyFrame();
    };
    struct __declspec(empty_bases) LinearDoubleKeyFrame : llm::OS::UI::Xaml::Media::Animation::ILinearDoubleKeyFrame,
        impl::base<LinearDoubleKeyFrame, llm::OS::UI::Xaml::Media::Animation::DoubleKeyFrame, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<LinearDoubleKeyFrame, llm::OS::UI::Xaml::Media::Animation::IDoubleKeyFrame, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        LinearDoubleKeyFrame(std::nullptr_t) noexcept {}
        LinearDoubleKeyFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::ILinearDoubleKeyFrame(ptr, take_ownership_from_abi) {}
        LinearDoubleKeyFrame();
    };
    struct __declspec(empty_bases) LinearPointKeyFrame : llm::OS::UI::Xaml::Media::Animation::ILinearPointKeyFrame,
        impl::base<LinearPointKeyFrame, llm::OS::UI::Xaml::Media::Animation::PointKeyFrame, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<LinearPointKeyFrame, llm::OS::UI::Xaml::Media::Animation::IPointKeyFrame, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        LinearPointKeyFrame(std::nullptr_t) noexcept {}
        LinearPointKeyFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::ILinearPointKeyFrame(ptr, take_ownership_from_abi) {}
        LinearPointKeyFrame();
    };
    struct __declspec(empty_bases) NavigationThemeTransition : llm::OS::UI::Xaml::Media::Animation::INavigationThemeTransition,
        impl::base<NavigationThemeTransition, llm::OS::UI::Xaml::Media::Animation::Transition, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<NavigationThemeTransition, llm::OS::UI::Xaml::Media::Animation::ITransition, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        NavigationThemeTransition(std::nullptr_t) noexcept {}
        NavigationThemeTransition(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::INavigationThemeTransition(ptr, take_ownership_from_abi) {}
        NavigationThemeTransition();
        [[nodiscard]] static auto DefaultNavigationTransitionInfoProperty();
    };
    struct __declspec(empty_bases) NavigationTransitionInfo : llm::OS::UI::Xaml::Media::Animation::INavigationTransitionInfo,
        impl::base<NavigationTransitionInfo, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<NavigationTransitionInfo, llm::OS::UI::Xaml::Media::Animation::INavigationTransitionInfoOverrides, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        NavigationTransitionInfo(std::nullptr_t) noexcept {}
        NavigationTransitionInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::INavigationTransitionInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ObjectAnimationUsingKeyFrames : llm::OS::UI::Xaml::Media::Animation::IObjectAnimationUsingKeyFrames,
        impl::base<ObjectAnimationUsingKeyFrames, llm::OS::UI::Xaml::Media::Animation::Timeline, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<ObjectAnimationUsingKeyFrames, llm::OS::UI::Xaml::Media::Animation::ITimeline, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        ObjectAnimationUsingKeyFrames(std::nullptr_t) noexcept {}
        ObjectAnimationUsingKeyFrames(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IObjectAnimationUsingKeyFrames(ptr, take_ownership_from_abi) {}
        ObjectAnimationUsingKeyFrames();
        [[nodiscard]] static auto EnableDependentAnimationProperty();
    };
    struct __declspec(empty_bases) ObjectKeyFrame : llm::OS::UI::Xaml::Media::Animation::IObjectKeyFrame,
        impl::base<ObjectKeyFrame, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<ObjectKeyFrame, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        ObjectKeyFrame(std::nullptr_t) noexcept {}
        ObjectKeyFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IObjectKeyFrame(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto ValueProperty();
        [[nodiscard]] static auto KeyTimeProperty();
    };
    struct __declspec(empty_bases) ObjectKeyFrameCollection : llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Media::Animation::ObjectKeyFrame>
    {
        ObjectKeyFrameCollection(std::nullptr_t) noexcept {}
        ObjectKeyFrameCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Media::Animation::ObjectKeyFrame>(ptr, take_ownership_from_abi) {}
        ObjectKeyFrameCollection();
    };
    struct __declspec(empty_bases) PaneThemeTransition : llm::OS::UI::Xaml::Media::Animation::IPaneThemeTransition,
        impl::base<PaneThemeTransition, llm::OS::UI::Xaml::Media::Animation::Transition, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<PaneThemeTransition, llm::OS::UI::Xaml::Media::Animation::ITransition, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        PaneThemeTransition(std::nullptr_t) noexcept {}
        PaneThemeTransition(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IPaneThemeTransition(ptr, take_ownership_from_abi) {}
        PaneThemeTransition();
        [[nodiscard]] static auto EdgeProperty();
    };
    struct __declspec(empty_bases) PointAnimation : llm::OS::UI::Xaml::Media::Animation::IPointAnimation,
        impl::base<PointAnimation, llm::OS::UI::Xaml::Media::Animation::Timeline, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<PointAnimation, llm::OS::UI::Xaml::Media::Animation::ITimeline, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        PointAnimation(std::nullptr_t) noexcept {}
        PointAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IPointAnimation(ptr, take_ownership_from_abi) {}
        PointAnimation();
        [[nodiscard]] static auto FromProperty();
        [[nodiscard]] static auto ToProperty();
        [[nodiscard]] static auto ByProperty();
        [[nodiscard]] static auto EasingFunctionProperty();
        [[nodiscard]] static auto EnableDependentAnimationProperty();
    };
    struct __declspec(empty_bases) PointAnimationUsingKeyFrames : llm::OS::UI::Xaml::Media::Animation::IPointAnimationUsingKeyFrames,
        impl::base<PointAnimationUsingKeyFrames, llm::OS::UI::Xaml::Media::Animation::Timeline, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<PointAnimationUsingKeyFrames, llm::OS::UI::Xaml::Media::Animation::ITimeline, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        PointAnimationUsingKeyFrames(std::nullptr_t) noexcept {}
        PointAnimationUsingKeyFrames(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IPointAnimationUsingKeyFrames(ptr, take_ownership_from_abi) {}
        PointAnimationUsingKeyFrames();
        [[nodiscard]] static auto EnableDependentAnimationProperty();
    };
    struct __declspec(empty_bases) PointKeyFrame : llm::OS::UI::Xaml::Media::Animation::IPointKeyFrame,
        impl::base<PointKeyFrame, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<PointKeyFrame, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        PointKeyFrame(std::nullptr_t) noexcept {}
        PointKeyFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IPointKeyFrame(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto ValueProperty();
        [[nodiscard]] static auto KeyTimeProperty();
    };
    struct __declspec(empty_bases) PointKeyFrameCollection : llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Media::Animation::PointKeyFrame>
    {
        PointKeyFrameCollection(std::nullptr_t) noexcept {}
        PointKeyFrameCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Media::Animation::PointKeyFrame>(ptr, take_ownership_from_abi) {}
        PointKeyFrameCollection();
    };
    struct __declspec(empty_bases) PointerDownThemeAnimation : llm::OS::UI::Xaml::Media::Animation::IPointerDownThemeAnimation,
        impl::base<PointerDownThemeAnimation, llm::OS::UI::Xaml::Media::Animation::Timeline, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<PointerDownThemeAnimation, llm::OS::UI::Xaml::Media::Animation::ITimeline, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        PointerDownThemeAnimation(std::nullptr_t) noexcept {}
        PointerDownThemeAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IPointerDownThemeAnimation(ptr, take_ownership_from_abi) {}
        PointerDownThemeAnimation();
        [[nodiscard]] static auto TargetNameProperty();
    };
    struct __declspec(empty_bases) PointerUpThemeAnimation : llm::OS::UI::Xaml::Media::Animation::IPointerUpThemeAnimation,
        impl::base<PointerUpThemeAnimation, llm::OS::UI::Xaml::Media::Animation::Timeline, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<PointerUpThemeAnimation, llm::OS::UI::Xaml::Media::Animation::ITimeline, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        PointerUpThemeAnimation(std::nullptr_t) noexcept {}
        PointerUpThemeAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IPointerUpThemeAnimation(ptr, take_ownership_from_abi) {}
        PointerUpThemeAnimation();
        [[nodiscard]] static auto TargetNameProperty();
    };
    struct __declspec(empty_bases) PopInThemeAnimation : llm::OS::UI::Xaml::Media::Animation::IPopInThemeAnimation,
        impl::base<PopInThemeAnimation, llm::OS::UI::Xaml::Media::Animation::Timeline, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<PopInThemeAnimation, llm::OS::UI::Xaml::Media::Animation::ITimeline, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        PopInThemeAnimation(std::nullptr_t) noexcept {}
        PopInThemeAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IPopInThemeAnimation(ptr, take_ownership_from_abi) {}
        PopInThemeAnimation();
        [[nodiscard]] static auto TargetNameProperty();
        [[nodiscard]] static auto FromHorizontalOffsetProperty();
        [[nodiscard]] static auto FromVerticalOffsetProperty();
    };
    struct __declspec(empty_bases) PopOutThemeAnimation : llm::OS::UI::Xaml::Media::Animation::IPopOutThemeAnimation,
        impl::base<PopOutThemeAnimation, llm::OS::UI::Xaml::Media::Animation::Timeline, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<PopOutThemeAnimation, llm::OS::UI::Xaml::Media::Animation::ITimeline, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        PopOutThemeAnimation(std::nullptr_t) noexcept {}
        PopOutThemeAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IPopOutThemeAnimation(ptr, take_ownership_from_abi) {}
        PopOutThemeAnimation();
        [[nodiscard]] static auto TargetNameProperty();
    };
    struct __declspec(empty_bases) PopupThemeTransition : llm::OS::UI::Xaml::Media::Animation::IPopupThemeTransition,
        impl::base<PopupThemeTransition, llm::OS::UI::Xaml::Media::Animation::Transition, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<PopupThemeTransition, llm::OS::UI::Xaml::Media::Animation::ITransition, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        PopupThemeTransition(std::nullptr_t) noexcept {}
        PopupThemeTransition(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IPopupThemeTransition(ptr, take_ownership_from_abi) {}
        PopupThemeTransition();
        [[nodiscard]] static auto FromHorizontalOffsetProperty();
        [[nodiscard]] static auto FromVerticalOffsetProperty();
    };
    struct __declspec(empty_bases) PowerEase : llm::OS::UI::Xaml::Media::Animation::IPowerEase,
        impl::base<PowerEase, llm::OS::UI::Xaml::Media::Animation::EasingFunctionBase, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<PowerEase, llm::OS::UI::Xaml::Media::Animation::IEasingFunctionBase, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        PowerEase(std::nullptr_t) noexcept {}
        PowerEase(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IPowerEase(ptr, take_ownership_from_abi) {}
        PowerEase();
        [[nodiscard]] static auto PowerProperty();
    };
    struct __declspec(empty_bases) QuadraticEase : llm::OS::UI::Xaml::Media::Animation::IQuadraticEase,
        impl::base<QuadraticEase, llm::OS::UI::Xaml::Media::Animation::EasingFunctionBase, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<QuadraticEase, llm::OS::UI::Xaml::Media::Animation::IEasingFunctionBase, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        QuadraticEase(std::nullptr_t) noexcept {}
        QuadraticEase(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IQuadraticEase(ptr, take_ownership_from_abi) {}
        QuadraticEase();
    };
    struct __declspec(empty_bases) QuarticEase : llm::OS::UI::Xaml::Media::Animation::IQuarticEase,
        impl::base<QuarticEase, llm::OS::UI::Xaml::Media::Animation::EasingFunctionBase, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<QuarticEase, llm::OS::UI::Xaml::Media::Animation::IEasingFunctionBase, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        QuarticEase(std::nullptr_t) noexcept {}
        QuarticEase(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IQuarticEase(ptr, take_ownership_from_abi) {}
        QuarticEase();
    };
    struct __declspec(empty_bases) QuinticEase : llm::OS::UI::Xaml::Media::Animation::IQuinticEase,
        impl::base<QuinticEase, llm::OS::UI::Xaml::Media::Animation::EasingFunctionBase, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<QuinticEase, llm::OS::UI::Xaml::Media::Animation::IEasingFunctionBase, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        QuinticEase(std::nullptr_t) noexcept {}
        QuinticEase(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IQuinticEase(ptr, take_ownership_from_abi) {}
        QuinticEase();
    };
    struct __declspec(empty_bases) ReorderThemeTransition : llm::OS::UI::Xaml::Media::Animation::IReorderThemeTransition,
        impl::base<ReorderThemeTransition, llm::OS::UI::Xaml::Media::Animation::Transition, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<ReorderThemeTransition, llm::OS::UI::Xaml::Media::Animation::ITransition, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        ReorderThemeTransition(std::nullptr_t) noexcept {}
        ReorderThemeTransition(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IReorderThemeTransition(ptr, take_ownership_from_abi) {}
        ReorderThemeTransition();
    };
    struct __declspec(empty_bases) RepeatBehaviorHelper : llm::OS::UI::Xaml::Media::Animation::IRepeatBehaviorHelper
    {
        RepeatBehaviorHelper(std::nullptr_t) noexcept {}
        RepeatBehaviorHelper(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IRepeatBehaviorHelper(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto Forever();
        static auto FromCount(double count);
        static auto FromDuration(llm::OS::Foundation::TimeSpan const& duration);
        static auto GetHasCount(llm::OS::UI::Xaml::Media::Animation::RepeatBehavior const& target);
        static auto GetHasDuration(llm::OS::UI::Xaml::Media::Animation::RepeatBehavior const& target);
        static auto Equals(llm::OS::UI::Xaml::Media::Animation::RepeatBehavior const& target, llm::OS::UI::Xaml::Media::Animation::RepeatBehavior const& value);
    };
    struct __declspec(empty_bases) RepositionThemeAnimation : llm::OS::UI::Xaml::Media::Animation::IRepositionThemeAnimation,
        impl::base<RepositionThemeAnimation, llm::OS::UI::Xaml::Media::Animation::Timeline, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<RepositionThemeAnimation, llm::OS::UI::Xaml::Media::Animation::ITimeline, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        RepositionThemeAnimation(std::nullptr_t) noexcept {}
        RepositionThemeAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IRepositionThemeAnimation(ptr, take_ownership_from_abi) {}
        RepositionThemeAnimation();
        [[nodiscard]] static auto TargetNameProperty();
        [[nodiscard]] static auto FromHorizontalOffsetProperty();
        [[nodiscard]] static auto FromVerticalOffsetProperty();
    };
    struct __declspec(empty_bases) RepositionThemeTransition : llm::OS::UI::Xaml::Media::Animation::IRepositionThemeTransition,
        impl::base<RepositionThemeTransition, llm::OS::UI::Xaml::Media::Animation::Transition, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<RepositionThemeTransition, llm::OS::UI::Xaml::Media::Animation::IRepositionThemeTransition2, llm::OS::UI::Xaml::Media::Animation::ITransition, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        RepositionThemeTransition(std::nullptr_t) noexcept {}
        RepositionThemeTransition(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IRepositionThemeTransition(ptr, take_ownership_from_abi) {}
        RepositionThemeTransition();
        [[nodiscard]] static auto IsStaggeringEnabledProperty();
    };
    struct __declspec(empty_bases) SineEase : llm::OS::UI::Xaml::Media::Animation::ISineEase,
        impl::base<SineEase, llm::OS::UI::Xaml::Media::Animation::EasingFunctionBase, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<SineEase, llm::OS::UI::Xaml::Media::Animation::IEasingFunctionBase, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        SineEase(std::nullptr_t) noexcept {}
        SineEase(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::ISineEase(ptr, take_ownership_from_abi) {}
        SineEase();
    };
    struct __declspec(empty_bases) SlideNavigationTransitionInfo : llm::OS::UI::Xaml::Media::Animation::ISlideNavigationTransitionInfo,
        impl::base<SlideNavigationTransitionInfo, llm::OS::UI::Xaml::Media::Animation::NavigationTransitionInfo, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<SlideNavigationTransitionInfo, llm::OS::UI::Xaml::Media::Animation::ISlideNavigationTransitionInfo2, llm::OS::UI::Xaml::Media::Animation::INavigationTransitionInfo, llm::OS::UI::Xaml::Media::Animation::INavigationTransitionInfoOverrides, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        SlideNavigationTransitionInfo(std::nullptr_t) noexcept {}
        SlideNavigationTransitionInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::ISlideNavigationTransitionInfo(ptr, take_ownership_from_abi) {}
        SlideNavigationTransitionInfo();
        [[nodiscard]] static auto EffectProperty();
    };
    struct __declspec(empty_bases) SplineColorKeyFrame : llm::OS::UI::Xaml::Media::Animation::ISplineColorKeyFrame,
        impl::base<SplineColorKeyFrame, llm::OS::UI::Xaml::Media::Animation::ColorKeyFrame, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<SplineColorKeyFrame, llm::OS::UI::Xaml::Media::Animation::IColorKeyFrame, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        SplineColorKeyFrame(std::nullptr_t) noexcept {}
        SplineColorKeyFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::ISplineColorKeyFrame(ptr, take_ownership_from_abi) {}
        SplineColorKeyFrame();
        [[nodiscard]] static auto KeySplineProperty();
    };
    struct __declspec(empty_bases) SplineDoubleKeyFrame : llm::OS::UI::Xaml::Media::Animation::ISplineDoubleKeyFrame,
        impl::base<SplineDoubleKeyFrame, llm::OS::UI::Xaml::Media::Animation::DoubleKeyFrame, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<SplineDoubleKeyFrame, llm::OS::UI::Xaml::Media::Animation::IDoubleKeyFrame, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        SplineDoubleKeyFrame(std::nullptr_t) noexcept {}
        SplineDoubleKeyFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::ISplineDoubleKeyFrame(ptr, take_ownership_from_abi) {}
        SplineDoubleKeyFrame();
        [[nodiscard]] static auto KeySplineProperty();
    };
    struct __declspec(empty_bases) SplinePointKeyFrame : llm::OS::UI::Xaml::Media::Animation::ISplinePointKeyFrame,
        impl::base<SplinePointKeyFrame, llm::OS::UI::Xaml::Media::Animation::PointKeyFrame, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<SplinePointKeyFrame, llm::OS::UI::Xaml::Media::Animation::IPointKeyFrame, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        SplinePointKeyFrame(std::nullptr_t) noexcept {}
        SplinePointKeyFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::ISplinePointKeyFrame(ptr, take_ownership_from_abi) {}
        SplinePointKeyFrame();
        [[nodiscard]] static auto KeySplineProperty();
    };
    struct __declspec(empty_bases) SplitCloseThemeAnimation : llm::OS::UI::Xaml::Media::Animation::ISplitCloseThemeAnimation,
        impl::base<SplitCloseThemeAnimation, llm::OS::UI::Xaml::Media::Animation::Timeline, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<SplitCloseThemeAnimation, llm::OS::UI::Xaml::Media::Animation::ITimeline, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        SplitCloseThemeAnimation(std::nullptr_t) noexcept {}
        SplitCloseThemeAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::ISplitCloseThemeAnimation(ptr, take_ownership_from_abi) {}
        SplitCloseThemeAnimation();
        [[nodiscard]] static auto OpenedTargetNameProperty();
        [[nodiscard]] static auto OpenedTargetProperty();
        [[nodiscard]] static auto ClosedTargetNameProperty();
        [[nodiscard]] static auto ClosedTargetProperty();
        [[nodiscard]] static auto ContentTargetNameProperty();
        [[nodiscard]] static auto ContentTargetProperty();
        [[nodiscard]] static auto OpenedLengthProperty();
        [[nodiscard]] static auto ClosedLengthProperty();
        [[nodiscard]] static auto OffsetFromCenterProperty();
        [[nodiscard]] static auto ContentTranslationDirectionProperty();
        [[nodiscard]] static auto ContentTranslationOffsetProperty();
    };
    struct __declspec(empty_bases) SplitOpenThemeAnimation : llm::OS::UI::Xaml::Media::Animation::ISplitOpenThemeAnimation,
        impl::base<SplitOpenThemeAnimation, llm::OS::UI::Xaml::Media::Animation::Timeline, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<SplitOpenThemeAnimation, llm::OS::UI::Xaml::Media::Animation::ITimeline, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        SplitOpenThemeAnimation(std::nullptr_t) noexcept {}
        SplitOpenThemeAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::ISplitOpenThemeAnimation(ptr, take_ownership_from_abi) {}
        SplitOpenThemeAnimation();
        [[nodiscard]] static auto OpenedTargetNameProperty();
        [[nodiscard]] static auto OpenedTargetProperty();
        [[nodiscard]] static auto ClosedTargetNameProperty();
        [[nodiscard]] static auto ClosedTargetProperty();
        [[nodiscard]] static auto ContentTargetNameProperty();
        [[nodiscard]] static auto ContentTargetProperty();
        [[nodiscard]] static auto OpenedLengthProperty();
        [[nodiscard]] static auto ClosedLengthProperty();
        [[nodiscard]] static auto OffsetFromCenterProperty();
        [[nodiscard]] static auto ContentTranslationDirectionProperty();
        [[nodiscard]] static auto ContentTranslationOffsetProperty();
    };
    struct __declspec(empty_bases) Storyboard : llm::OS::UI::Xaml::Media::Animation::IStoryboard,
        impl::base<Storyboard, llm::OS::UI::Xaml::Media::Animation::Timeline, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<Storyboard, llm::OS::UI::Xaml::Media::Animation::ITimeline, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        Storyboard(std::nullptr_t) noexcept {}
        Storyboard(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::IStoryboard(ptr, take_ownership_from_abi) {}
        Storyboard();
        [[nodiscard]] static auto TargetPropertyProperty();
        static auto GetTargetProperty(llm::OS::UI::Xaml::Media::Animation::Timeline const& element);
        static auto SetTargetProperty(llm::OS::UI::Xaml::Media::Animation::Timeline const& element, param::hstring const& path);
        [[nodiscard]] static auto TargetNameProperty();
        static auto GetTargetName(llm::OS::UI::Xaml::Media::Animation::Timeline const& element);
        static auto SetTargetName(llm::OS::UI::Xaml::Media::Animation::Timeline const& element, param::hstring const& name);
        static auto SetTarget(llm::OS::UI::Xaml::Media::Animation::Timeline const& timeline, llm::OS::UI::Xaml::DependencyObject const& target);
    };
    struct __declspec(empty_bases) SuppressNavigationTransitionInfo : llm::OS::UI::Xaml::Media::Animation::ISuppressNavigationTransitionInfo,
        impl::base<SuppressNavigationTransitionInfo, llm::OS::UI::Xaml::Media::Animation::NavigationTransitionInfo, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<SuppressNavigationTransitionInfo, llm::OS::UI::Xaml::Media::Animation::INavigationTransitionInfo, llm::OS::UI::Xaml::Media::Animation::INavigationTransitionInfoOverrides, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        SuppressNavigationTransitionInfo(std::nullptr_t) noexcept {}
        SuppressNavigationTransitionInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::ISuppressNavigationTransitionInfo(ptr, take_ownership_from_abi) {}
        SuppressNavigationTransitionInfo();
    };
    struct __declspec(empty_bases) SwipeBackThemeAnimation : llm::OS::UI::Xaml::Media::Animation::ISwipeBackThemeAnimation,
        impl::base<SwipeBackThemeAnimation, llm::OS::UI::Xaml::Media::Animation::Timeline, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<SwipeBackThemeAnimation, llm::OS::UI::Xaml::Media::Animation::ITimeline, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        SwipeBackThemeAnimation(std::nullptr_t) noexcept {}
        SwipeBackThemeAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::ISwipeBackThemeAnimation(ptr, take_ownership_from_abi) {}
        SwipeBackThemeAnimation();
        [[nodiscard]] static auto TargetNameProperty();
        [[nodiscard]] static auto FromHorizontalOffsetProperty();
        [[nodiscard]] static auto FromVerticalOffsetProperty();
    };
    struct __declspec(empty_bases) SwipeHintThemeAnimation : llm::OS::UI::Xaml::Media::Animation::ISwipeHintThemeAnimation,
        impl::base<SwipeHintThemeAnimation, llm::OS::UI::Xaml::Media::Animation::Timeline, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<SwipeHintThemeAnimation, llm::OS::UI::Xaml::Media::Animation::ITimeline, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        SwipeHintThemeAnimation(std::nullptr_t) noexcept {}
        SwipeHintThemeAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::ISwipeHintThemeAnimation(ptr, take_ownership_from_abi) {}
        SwipeHintThemeAnimation();
        [[nodiscard]] static auto TargetNameProperty();
        [[nodiscard]] static auto ToHorizontalOffsetProperty();
        [[nodiscard]] static auto ToVerticalOffsetProperty();
    };
    struct __declspec(empty_bases) Timeline : llm::OS::UI::Xaml::Media::Animation::ITimeline,
        impl::base<Timeline, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<Timeline, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        Timeline(std::nullptr_t) noexcept {}
        Timeline(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::ITimeline(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto AllowDependentAnimations();
        static auto AllowDependentAnimations(bool value);
        [[nodiscard]] static auto AutoReverseProperty();
        [[nodiscard]] static auto BeginTimeProperty();
        [[nodiscard]] static auto DurationProperty();
        [[nodiscard]] static auto SpeedRatioProperty();
        [[nodiscard]] static auto FillBehaviorProperty();
        [[nodiscard]] static auto RepeatBehaviorProperty();
    };
    struct __declspec(empty_bases) TimelineCollection : llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Media::Animation::Timeline>
    {
        TimelineCollection(std::nullptr_t) noexcept {}
        TimelineCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Media::Animation::Timeline>(ptr, take_ownership_from_abi) {}
        TimelineCollection();
    };
    struct __declspec(empty_bases) Transition : llm::OS::UI::Xaml::Media::Animation::ITransition,
        impl::base<Transition, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<Transition, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        Transition(std::nullptr_t) noexcept {}
        Transition(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Media::Animation::ITransition(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TransitionCollection : llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Media::Animation::Transition>
    {
        TransitionCollection(std::nullptr_t) noexcept {}
        TransitionCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Media::Animation::Transition>(ptr, take_ownership_from_abi) {}
        TransitionCollection();
    };
    template <typename D>
    class INavigationTransitionInfoOverridesT
    {
        D& shim() noexcept { return *static_cast<D*>(this); }
        D const& shim() const noexcept { return *static_cast<const D*>(this); }
    public:
        using INavigationTransitionInfoOverrides = llm::OS::UI::Xaml::Media::Animation::INavigationTransitionInfoOverrides;
        WINRT_IMPL_AUTO(hstring) GetNavigationStateCore() const;
        WINRT_IMPL_AUTO(void) SetNavigationStateCore(param::hstring const& navigationState) const;
    };
}
#endif
