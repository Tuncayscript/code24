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
#ifndef LLM_OS_UI_Xaml_0_H
#define LLM_OS_UI_Xaml_0_H
LLM_EXPORT namespace llm::OS::ApplicationModel
{
    struct EnteredBackgroundEventArgs;
    struct LeavingBackgroundEventArgs;
    struct SuspendingEventArgs;
}
LLM_EXPORT namespace llm::OS::ApplicationModel::Activation
{
    struct BackgroundActivatedEventArgs;
    struct CachedFileUpdaterActivatedEventArgs;
    struct FileActivatedEventArgs;
    struct FileOpenPickerActivatedEventArgs;
    struct FileSavePickerActivatedEventArgs;
    struct IActivatedEventArgs;
    struct LaunchActivatedEventArgs;
    struct SearchActivatedEventArgs;
    struct ShareTargetActivatedEventArgs;
}
LLM_EXPORT namespace llm::OS::ApplicationModel::DataTransfer
{
    struct DataPackage;
    enum class DataPackageOperation : uint32_t;
    struct DataPackageView;
}
LLM_EXPORT namespace llm::OS::ApplicationModel::DataTransfer::DragDrop
{
    enum class DragDropModifiers : uint32_t;
}
LLM_EXPORT namespace llm::OS::Foundation
{
    template <typename T> struct __declspec(empty_bases) EventHandler;
    struct EventRegistrationToken;
    struct HResult;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename T> struct __declspec(empty_bases) IReference;
    struct Point;
    struct Rect;
    struct Size;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
    struct Uri;
}
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IIterable;
    template <typename K, typename V> struct __declspec(empty_bases) IMap;
    template <typename T> struct __declspec(empty_bases) IObservableVector;
    template <typename T> struct __declspec(empty_bases) IVectorView;
    template <typename T> struct __declspec(empty_bases) IVector;
}
LLM_EXPORT namespace llm::OS::Foundation::Numerics
{
}
LLM_EXPORT namespace llm::OS::Graphics::Imaging
{
    struct SoftwareBitmap;
}
LLM_EXPORT namespace llm::OS::UI
{
    struct Color;
    struct UIContext;
}
LLM_EXPORT namespace llm::OS::UI::Composition
{
    struct AnimationPropertyInfo;
    struct Compositor;
    struct ICompositionAnimationBase;
}
LLM_EXPORT namespace llm::OS::UI::Core
{
    struct CoreDispatcher;
    struct CoreWindow;
    struct CoreWindowEventArgs;
    struct VisibilityChangedEventArgs;
    struct WindowActivatedEventArgs;
    struct WindowSizeChangedEventArgs;
}
LLM_EXPORT namespace llm::OS::UI::Input
{
    struct PointerPoint;
}
LLM_EXPORT namespace llm::OS::UI::Xaml::Automation::Peers
{
    struct AutomationPeer;
}
LLM_EXPORT namespace llm::OS::UI::Xaml::Controls
{
    struct ContainerContentChangingEventArgs;
    struct Control;
}
LLM_EXPORT namespace llm::OS::UI::Xaml::Controls::Primitives
{
    enum class ComponentResourceLocation : int32_t;
    struct FlyoutBase;
}
LLM_EXPORT namespace llm::OS::UI::Xaml::Data
{
    struct BindingBase;
    struct BindingExpression;
}
LLM_EXPORT namespace llm::OS::UI::Xaml::Input
{
    struct AccessKeyDisplayDismissedEventArgs;
    struct AccessKeyDisplayRequestedEventArgs;
    struct AccessKeyInvokedEventArgs;
    struct CharacterReceivedRoutedEventArgs;
    struct ContextRequestedEventArgs;
    struct DoubleTappedEventHandler;
    struct GettingFocusEventArgs;
    struct HoldingEventHandler;
    struct KeyEventHandler;
    enum class KeyTipPlacementMode : int32_t;
    struct KeyboardAccelerator;
    struct KeyboardAcceleratorInvokedEventArgs;
    enum class KeyboardAcceleratorPlacementMode : int32_t;
    enum class KeyboardNavigationMode : int32_t;
    struct LosingFocusEventArgs;
    struct ManipulationCompletedEventHandler;
    struct ManipulationDeltaEventHandler;
    struct ManipulationInertiaStartingEventHandler;
    enum class ManipulationModes : uint32_t;
    struct ManipulationStartedEventHandler;
    struct ManipulationStartingEventHandler;
    struct NoFocusCandidateFoundEventArgs;
    struct Pointer;
    struct PointerEventHandler;
    struct ProcessKeyboardAcceleratorEventArgs;
    struct RightTappedEventHandler;
    struct TappedEventHandler;
    enum class XYFocusKeyboardNavigationMode : int32_t;
    enum class XYFocusNavigationStrategy : int32_t;
}
LLM_EXPORT namespace llm::OS::UI::Xaml::Interop
{
    struct TypeName;
}
LLM_EXPORT namespace llm::OS::UI::Xaml::Media
{
    struct Brush;
    struct CacheMode;
    enum class ElementCompositeMode : int32_t;
    struct GeneralTransform;
    struct Projection;
    struct RectangleGeometry;
    struct Shadow;
    struct Transform;
    struct XamlLight;
}
LLM_EXPORT namespace llm::OS::UI::Xaml::Media::Animation
{
    struct EasingFunctionBase;
    struct Storyboard;
    struct TransitionCollection;
}
LLM_EXPORT namespace llm::OS::UI::Xaml::Media::Imaging
{
    struct BitmapImage;
}
LLM_EXPORT namespace llm::OS::UI::Xaml::Media::Media3D
{
    struct Transform3D;
}
LLM_EXPORT namespace llm::OS::UI::Xaml
{
    enum class ApplicationHighContrastAdjustment : uint32_t
    {
        None = 0,
        Auto = 0xffffffff,
    };
    enum class ApplicationRequiresPointerMode : int32_t
    {
        Auto = 0,
        WhenRequested = 1,
    };
    enum class ApplicationTheme : int32_t
    {
        Light = 0,
        Dark = 1,
    };
    enum class AutomationTextAttributesEnum : int32_t
    {
        AnimationStyleAttribute = 40000,
        BackgroundColorAttribute = 40001,
        BulletStyleAttribute = 40002,
        CapStyleAttribute = 40003,
        CultureAttribute = 40004,
        FontNameAttribute = 40005,
        FontSizeAttribute = 40006,
        FontWeightAttribute = 40007,
        ForegroundColorAttribute = 40008,
        HorizontalTextAlignmentAttribute = 40009,
        IndentationFirstLineAttribute = 40010,
        IndentationLeadingAttribute = 40011,
        IndentationTrailingAttribute = 40012,
        IsHiddenAttribute = 40013,
        IsItalicAttribute = 40014,
        IsReadOnlyAttribute = 40015,
        IsSubscriptAttribute = 40016,
        IsSuperscriptAttribute = 40017,
        MarginBottomAttribute = 40018,
        MarginLeadingAttribute = 40019,
        MarginTopAttribute = 40020,
        MarginTrailingAttribute = 40021,
        OutlineStylesAttribute = 40022,
        OverlineColorAttribute = 40023,
        OverlineStyleAttribute = 40024,
        StrikethroughColorAttribute = 40025,
        StrikethroughStyleAttribute = 40026,
        TabsAttribute = 40027,
        TextFlowDirectionsAttribute = 40028,
        UnderlineColorAttribute = 40029,
        UnderlineStyleAttribute = 40030,
        AnnotationTypesAttribute = 40031,
        AnnotationObjectsAttribute = 40032,
        StyleNameAttribute = 40033,
        StyleIdAttribute = 40034,
        LinkAttribute = 40035,
        IsActiveAttribute = 40036,
        SelectionActiveEndAttribute = 40037,
        CaretPositionAttribute = 40038,
        CaretBidiModeAttribute = 40039,
    };
    enum class DurationType : int32_t
    {
        Automatic = 0,
        TimeSpan = 1,
        Forever = 2,
    };
    enum class ElementHighContrastAdjustment : uint32_t
    {
        None = 0,
        Application = 0x80000000,
        Auto = 0xffffffff,
    };
    enum class ElementSoundKind : int32_t
    {
        Focus = 0,
        Invoke = 1,
        Show = 2,
        Hide = 3,
        MovePrevious = 4,
        MoveNext = 5,
        GoBack = 6,
    };
    enum class ElementSoundMode : int32_t
    {
        Default = 0,
        FocusOnly = 1,
        Off = 2,
    };
    enum class ElementSoundPlayerState : int32_t
    {
        Auto = 0,
        Off = 1,
        On = 2,
    };
    enum class ElementSpatialAudioMode : int32_t
    {
        Auto = 0,
        Off = 1,
        On = 2,
    };
    enum class ElementTheme : int32_t
    {
        Default = 0,
        Light = 1,
        Dark = 2,
    };
    enum class FlowDirection : int32_t
    {
        LeftToRight = 0,
        RightToLeft = 1,
    };
    enum class FocusState : int32_t
    {
        Unfocused = 0,
        Pointer = 1,
        Keyboard = 2,
        Programmatic = 3,
    };
    enum class FocusVisualKind : int32_t
    {
        DottedLine = 0,
        HighVisibility = 1,
        Reveal = 2,
    };
    enum class FontCapitals : int32_t
    {
        Normal = 0,
        AllSmallCaps = 1,
        SmallCaps = 2,
        AllPetiteCaps = 3,
        PetiteCaps = 4,
        Unicase = 5,
        Titling = 6,
    };
    enum class FontEastAsianLanguage : int32_t
    {
        Normal = 0,
        HojoKanji = 1,
        Jis04 = 2,
        Jis78 = 3,
        Jis83 = 4,
        Jis90 = 5,
        NlcKanji = 6,
        Simplified = 7,
        Traditional = 8,
        TraditionalNames = 9,
    };
    enum class FontEastAsianWidths : int32_t
    {
        Normal = 0,
        Full = 1,
        Half = 2,
        Proportional = 3,
        Quarter = 4,
        Third = 5,
    };
    enum class FontFraction : int32_t
    {
        Normal = 0,
        Stacked = 1,
        Slashed = 2,
    };
    enum class FontNumeralAlignment : int32_t
    {
        Normal = 0,
        Proportional = 1,
        Tabular = 2,
    };
    enum class FontNumeralStyle : int32_t
    {
        Normal = 0,
        Lining = 1,
        OldStyle = 2,
    };
    enum class FontVariants : int32_t
    {
        Normal = 0,
        Superscript = 1,
        Subscript = 2,
        Ordinal = 3,
        Inferior = 4,
        Ruby = 5,
    };
    enum class GridUnitType : int32_t
    {
        Auto = 0,
        Pixel = 1,
        Star = 2,
    };
    enum class HorizontalAlignment : int32_t
    {
        Left = 0,
        Center = 1,
        Right = 2,
        Stretch = 3,
    };
    enum class LineStackingStrategy : int32_t
    {
        MaxHeight = 0,
        BlockLineHeight = 1,
        BaselineToBaseline = 2,
    };
    enum class OpticalMarginAlignment : int32_t
    {
        None = 0,
        TrimSideBearings = 1,
    };
    enum class TextAlignment : int32_t
    {
        Center = 0,
        Left = 1,
        Start = 1,
        Right = 2,
        End = 2,
        Justify = 3,
        DetectFromContent = 4,
    };
    enum class TextLineBounds : int32_t
    {
        Full = 0,
        TrimToCapHeight = 1,
        TrimToBaseline = 2,
        Tight = 3,
    };
    enum class TextReadingOrder : int32_t
    {
        Default = 0,
        UseFlowDirection = 0,
        DetectFromContent = 1,
    };
    enum class TextTrimming : int32_t
    {
        None = 0,
        CharacterEllipsis = 1,
        WordEllipsis = 2,
        Clip = 3,
    };
    enum class TextWrapping : int32_t
    {
        NoWrap = 1,
        Wrap = 2,
        WrapWholeWords = 3,
    };
    enum class Vector3TransitionComponents : uint32_t
    {
        X = 0x1,
        Y = 0x2,
        Z = 0x4,
    };
    enum class VerticalAlignment : int32_t
    {
        Top = 0,
        Center = 1,
        Bottom = 2,
        Stretch = 3,
    };
    enum class Visibility : int32_t
    {
        Visible = 0,
        Collapsed = 1,
    };
    struct IAdaptiveTrigger;
    struct IAdaptiveTriggerFactory;
    struct IAdaptiveTriggerStatics;
    struct IApplication;
    struct IApplication2;
    struct IApplication3;
    struct IApplicationFactory;
    struct IApplicationInitializationCallbackParams;
    struct IApplicationOverrides;
    struct IApplicationOverrides2;
    struct IApplicationStatics;
    struct IBindingFailedEventArgs;
    struct IBringIntoViewOptions;
    struct IBringIntoViewOptions2;
    struct IBringIntoViewRequestedEventArgs;
    struct IBrushTransition;
    struct IBrushTransitionFactory;
    struct IColorPaletteResources;
    struct IColorPaletteResourcesFactory;
    struct ICornerRadiusHelper;
    struct ICornerRadiusHelperStatics;
    struct IDataContextChangedEventArgs;
    struct IDataTemplate;
    struct IDataTemplateExtension;
    struct IDataTemplateFactory;
    struct IDataTemplateKey;
    struct IDataTemplateKeyFactory;
    struct IDataTemplateStatics2;
    struct IDebugSettings;
    struct IDebugSettings2;
    struct IDebugSettings3;
    struct IDebugSettings4;
    struct IDependencyObject;
    struct IDependencyObject2;
    struct IDependencyObjectCollectionFactory;
    struct IDependencyObjectFactory;
    struct IDependencyProperty;
    struct IDependencyPropertyChangedEventArgs;
    struct IDependencyPropertyStatics;
    struct IDispatcherTimer;
    struct IDispatcherTimerFactory;
    struct IDragEventArgs;
    struct IDragEventArgs2;
    struct IDragEventArgs3;
    struct IDragOperationDeferral;
    struct IDragStartingEventArgs;
    struct IDragStartingEventArgs2;
    struct IDragUI;
    struct IDragUIOverride;
    struct IDropCompletedEventArgs;
    struct IDurationHelper;
    struct IDurationHelperStatics;
    struct IEffectiveViewportChangedEventArgs;
    struct IElementFactory;
    struct IElementFactoryGetArgs;
    struct IElementFactoryGetArgsFactory;
    struct IElementFactoryRecycleArgs;
    struct IElementFactoryRecycleArgsFactory;
    struct IElementSoundPlayer;
    struct IElementSoundPlayerStatics;
    struct IElementSoundPlayerStatics2;
    struct IEventTrigger;
    struct IExceptionRoutedEventArgs;
    struct IExceptionRoutedEventArgsFactory;
    struct IFrameworkElement;
    struct IFrameworkElement2;
    struct IFrameworkElement3;
    struct IFrameworkElement4;
    struct IFrameworkElement6;
    struct IFrameworkElement7;
    struct IFrameworkElementFactory;
    struct IFrameworkElementOverrides;
    struct IFrameworkElementOverrides2;
    struct IFrameworkElementProtected7;
    struct IFrameworkElementStatics;
    struct IFrameworkElementStatics2;
    struct IFrameworkElementStatics4;
    struct IFrameworkElementStatics5;
    struct IFrameworkElementStatics6;
    struct IFrameworkTemplate;
    struct IFrameworkTemplateFactory;
    struct IFrameworkView;
    struct IFrameworkViewSource;
    struct IGridLengthHelper;
    struct IGridLengthHelperStatics;
    struct IMediaFailedRoutedEventArgs;
    struct IPointHelper;
    struct IPointHelperStatics;
    struct IPropertyMetadata;
    struct IPropertyMetadataFactory;
    struct IPropertyMetadataStatics;
    struct IPropertyPath;
    struct IPropertyPathFactory;
    struct IRectHelper;
    struct IRectHelperStatics;
    struct IResourceDictionary;
    struct IResourceDictionaryFactory;
    struct IRoutedEvent;
    struct IRoutedEventArgs;
    struct IRoutedEventArgsFactory;
    struct IScalarTransition;
    struct IScalarTransitionFactory;
    struct ISetter;
    struct ISetter2;
    struct ISetterBase;
    struct ISetterBaseCollection;
    struct ISetterBaseFactory;
    struct ISetterFactory;
    struct ISizeChangedEventArgs;
    struct ISizeHelper;
    struct ISizeHelperStatics;
    struct IStateTrigger;
    struct IStateTriggerBase;
    struct IStateTriggerBaseFactory;
    struct IStateTriggerBaseProtected;
    struct IStateTriggerStatics;
    struct IStyle;
    struct IStyleFactory;
    struct ITargetPropertyPath;
    struct ITargetPropertyPathFactory;
    struct IThicknessHelper;
    struct IThicknessHelperStatics;
    struct ITriggerAction;
    struct ITriggerActionFactory;
    struct ITriggerBase;
    struct ITriggerBaseFactory;
    struct IUIElement;
    struct IUIElement10;
    struct IUIElement2;
    struct IUIElement3;
    struct IUIElement4;
    struct IUIElement5;
    struct IUIElement7;
    struct IUIElement8;
    struct IUIElement9;
    struct IUIElementFactory;
    struct IUIElementOverrides;
    struct IUIElementOverrides7;
    struct IUIElementOverrides8;
    struct IUIElementOverrides9;
    struct IUIElementStatics;
    struct IUIElementStatics10;
    struct IUIElementStatics2;
    struct IUIElementStatics3;
    struct IUIElementStatics4;
    struct IUIElementStatics5;
    struct IUIElementStatics6;
    struct IUIElementStatics7;
    struct IUIElementStatics8;
    struct IUIElementStatics9;
    struct IUIElementWeakCollection;
    struct IUIElementWeakCollectionFactory;
    struct IUnhandledExceptionEventArgs;
    struct IVector3Transition;
    struct IVector3TransitionFactory;
    struct IVisualState;
    struct IVisualState2;
    struct IVisualStateChangedEventArgs;
    struct IVisualStateGroup;
    struct IVisualStateManager;
    struct IVisualStateManagerFactory;
    struct IVisualStateManagerOverrides;
    struct IVisualStateManagerProtected;
    struct IVisualStateManagerStatics;
    struct IVisualTransition;
    struct IVisualTransitionFactory;
    struct IWindow;
    struct IWindow2;
    struct IWindow3;
    struct IWindow4;
    struct IWindowCreatedEventArgs;
    struct IWindowStatics;
    struct IXamlRoot;
    struct IXamlRootChangedEventArgs;
    struct AdaptiveTrigger;
    struct Application;
    struct ApplicationInitializationCallbackParams;
    struct BindingFailedEventArgs;
    struct BringIntoViewOptions;
    struct BringIntoViewRequestedEventArgs;
    struct BrushTransition;
    struct ColorPaletteResources;
    struct CornerRadiusHelper;
    struct DataContextChangedEventArgs;
    struct DataTemplate;
    struct DataTemplateKey;
    struct DebugSettings;
    struct DependencyObject;
    struct DependencyObjectCollection;
    struct DependencyProperty;
    struct DependencyPropertyChangedEventArgs;
    struct DispatcherTimer;
    struct DragEventArgs;
    struct DragOperationDeferral;
    struct DragStartingEventArgs;
    struct DragUI;
    struct DragUIOverride;
    struct DropCompletedEventArgs;
    struct DurationHelper;
    struct EffectiveViewportChangedEventArgs;
    struct ElementFactoryGetArgs;
    struct ElementFactoryRecycleArgs;
    struct ElementSoundPlayer;
    struct EventTrigger;
    struct ExceptionRoutedEventArgs;
    struct FrameworkElement;
    struct FrameworkTemplate;
    struct FrameworkView;
    struct FrameworkViewSource;
    struct GridLengthHelper;
    struct MediaFailedRoutedEventArgs;
    struct PointHelper;
    struct PropertyMetadata;
    struct PropertyPath;
    struct RectHelper;
    struct ResourceDictionary;
    struct RoutedEvent;
    struct RoutedEventArgs;
    struct ScalarTransition;
    struct Setter;
    struct SetterBase;
    struct SetterBaseCollection;
    struct SizeChangedEventArgs;
    struct SizeHelper;
    struct StateTrigger;
    struct StateTriggerBase;
    struct Style;
    struct TargetPropertyPath;
    struct ThicknessHelper;
    struct TriggerAction;
    struct TriggerActionCollection;
    struct TriggerBase;
    struct TriggerCollection;
    struct UIElement;
    struct UIElementWeakCollection;
    struct UnhandledExceptionEventArgs;
    struct Vector3Transition;
    struct VisualState;
    struct VisualStateChangedEventArgs;
    struct VisualStateGroup;
    struct VisualStateManager;
    struct VisualTransition;
    struct Window;
    struct WindowCreatedEventArgs;
    struct XamlRoot;
    struct XamlRootChangedEventArgs;
    struct CornerRadius;
    struct Duration;
    struct GridLength;
    struct Thickness;
    struct ApplicationInitializationCallback;
    struct BindingFailedEventHandler;
    struct CreateDefaultValueCallback;
    struct DependencyPropertyChangedCallback;
    struct DependencyPropertyChangedEventHandler;
    struct DragEventHandler;
    struct EnteredBackgroundEventHandler;
    struct ExceptionRoutedEventHandler;
    struct LeavingBackgroundEventHandler;
    struct PropertyChangedCallback;
    struct RoutedEventHandler;
    struct SizeChangedEventHandler;
    struct SuspendingEventHandler;
    struct UnhandledExceptionEventHandler;
    struct VisualStateChangedEventHandler;
    struct WindowActivatedEventHandler;
    struct WindowClosedEventHandler;
    struct WindowSizeChangedEventHandler;
    struct WindowVisibilityChangedEventHandler;
}
namespace llm::impl
{
    template <> struct category<llm::OS::UI::Xaml::IAdaptiveTrigger>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IAdaptiveTriggerFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IAdaptiveTriggerStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IApplication>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IApplication2>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IApplication3>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IApplicationFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IApplicationInitializationCallbackParams>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IApplicationOverrides>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IApplicationOverrides2>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IApplicationStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IBindingFailedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IBringIntoViewOptions>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IBringIntoViewOptions2>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IBringIntoViewRequestedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IBrushTransition>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IBrushTransitionFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IColorPaletteResources>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IColorPaletteResourcesFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::ICornerRadiusHelper>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::ICornerRadiusHelperStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IDataContextChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IDataTemplate>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IDataTemplateExtension>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IDataTemplateFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IDataTemplateKey>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IDataTemplateKeyFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IDataTemplateStatics2>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IDebugSettings>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IDebugSettings2>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IDebugSettings3>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IDebugSettings4>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IDependencyObject>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IDependencyObject2>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IDependencyObjectCollectionFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IDependencyObjectFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IDependencyProperty>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IDependencyPropertyChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IDependencyPropertyStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IDispatcherTimer>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IDispatcherTimerFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IDragEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IDragEventArgs2>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IDragEventArgs3>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IDragOperationDeferral>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IDragStartingEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IDragStartingEventArgs2>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IDragUI>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IDragUIOverride>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IDropCompletedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IDurationHelper>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IDurationHelperStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IEffectiveViewportChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IElementFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IElementFactoryGetArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IElementFactoryGetArgsFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IElementFactoryRecycleArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IElementFactoryRecycleArgsFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IElementSoundPlayer>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IElementSoundPlayerStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IElementSoundPlayerStatics2>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IEventTrigger>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IExceptionRoutedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IExceptionRoutedEventArgsFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IFrameworkElement>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IFrameworkElement2>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IFrameworkElement3>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IFrameworkElement4>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IFrameworkElement6>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IFrameworkElement7>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IFrameworkElementFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IFrameworkElementOverrides>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IFrameworkElementOverrides2>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IFrameworkElementProtected7>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IFrameworkElementStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IFrameworkElementStatics2>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IFrameworkElementStatics4>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IFrameworkElementStatics5>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IFrameworkElementStatics6>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IFrameworkTemplate>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IFrameworkTemplateFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IFrameworkView>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IFrameworkViewSource>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IGridLengthHelper>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IGridLengthHelperStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IMediaFailedRoutedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IPointHelper>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IPointHelperStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IPropertyMetadata>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IPropertyMetadataFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IPropertyMetadataStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IPropertyPath>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IPropertyPathFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IRectHelper>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IRectHelperStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IResourceDictionary>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IResourceDictionaryFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IRoutedEvent>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IRoutedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IRoutedEventArgsFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IScalarTransition>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IScalarTransitionFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::ISetter>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::ISetter2>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::ISetterBase>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::ISetterBaseCollection>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::ISetterBaseFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::ISetterFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::ISizeChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::ISizeHelper>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::ISizeHelperStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IStateTrigger>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IStateTriggerBase>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IStateTriggerBaseFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IStateTriggerBaseProtected>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IStateTriggerStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IStyle>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IStyleFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::ITargetPropertyPath>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::ITargetPropertyPathFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IThicknessHelper>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IThicknessHelperStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::ITriggerAction>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::ITriggerActionFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::ITriggerBase>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::ITriggerBaseFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IUIElement>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IUIElement10>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IUIElement2>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IUIElement3>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IUIElement4>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IUIElement5>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IUIElement7>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IUIElement8>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IUIElement9>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IUIElementFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IUIElementOverrides>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IUIElementOverrides7>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IUIElementOverrides8>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IUIElementOverrides9>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IUIElementStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IUIElementStatics10>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IUIElementStatics2>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IUIElementStatics3>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IUIElementStatics4>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IUIElementStatics5>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IUIElementStatics6>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IUIElementStatics7>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IUIElementStatics8>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IUIElementStatics9>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IUIElementWeakCollection>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IUIElementWeakCollectionFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IUnhandledExceptionEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IVector3Transition>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IVector3TransitionFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IVisualState>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IVisualState2>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IVisualStateChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IVisualStateGroup>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IVisualStateManager>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IVisualStateManagerFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IVisualStateManagerOverrides>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IVisualStateManagerProtected>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IVisualStateManagerStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IVisualTransition>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IVisualTransitionFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IWindow>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IWindow2>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IWindow3>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IWindow4>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IWindowCreatedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IWindowStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IXamlRoot>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::IXamlRootChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::AdaptiveTrigger>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::Application>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::ApplicationInitializationCallbackParams>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::BindingFailedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::BringIntoViewOptions>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::BringIntoViewRequestedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::BrushTransition>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::ColorPaletteResources>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::CornerRadiusHelper>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::DataContextChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::DataTemplate>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::DataTemplateKey>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::DebugSettings>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::DependencyObject>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::DependencyObjectCollection>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::DependencyProperty>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::DependencyPropertyChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::DispatcherTimer>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::DragEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::DragOperationDeferral>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::DragStartingEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::DragUI>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::DragUIOverride>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::DropCompletedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::DurationHelper>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::EffectiveViewportChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::ElementFactoryGetArgs>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::ElementFactoryRecycleArgs>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::ElementSoundPlayer>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::EventTrigger>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::ExceptionRoutedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::FrameworkElement>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::FrameworkTemplate>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::FrameworkView>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::FrameworkViewSource>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::GridLengthHelper>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::MediaFailedRoutedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::PointHelper>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::PropertyMetadata>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::PropertyPath>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::RectHelper>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::ResourceDictionary>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::RoutedEvent>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::RoutedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::ScalarTransition>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::Setter>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::SetterBase>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::SetterBaseCollection>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::SizeChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::SizeHelper>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::StateTrigger>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::StateTriggerBase>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::Style>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::TargetPropertyPath>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::ThicknessHelper>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::TriggerAction>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::TriggerActionCollection>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::TriggerBase>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::TriggerCollection>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::UIElement>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::UIElementWeakCollection>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::UnhandledExceptionEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::Vector3Transition>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::VisualState>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::VisualStateChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::VisualStateGroup>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::VisualStateManager>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::VisualTransition>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::Window>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::WindowCreatedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::XamlRoot>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::XamlRootChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::ApplicationHighContrastAdjustment>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::ApplicationRequiresPointerMode>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::ApplicationTheme>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::AutomationTextAttributesEnum>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::DurationType>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::ElementHighContrastAdjustment>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::ElementSoundKind>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::ElementSoundMode>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::ElementSoundPlayerState>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::ElementSpatialAudioMode>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::ElementTheme>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::FlowDirection>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::FocusState>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::FocusVisualKind>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::FontCapitals>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::FontEastAsianLanguage>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::FontEastAsianWidths>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::FontFraction>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::FontNumeralAlignment>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::FontNumeralStyle>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::FontVariants>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::GridUnitType>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::HorizontalAlignment>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::LineStackingStrategy>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::OpticalMarginAlignment>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::TextAlignment>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::TextLineBounds>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::TextReadingOrder>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::TextTrimming>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::TextWrapping>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::Vector3TransitionComponents>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::VerticalAlignment>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::Visibility>{ using type = enum_category; };
    template <> struct category<llm::OS::UI::Xaml::CornerRadius>{ using type = struct_category<double, double, double, double>; };
    template <> struct category<llm::OS::UI::Xaml::Duration>{ using type = struct_category<llm::OS::Foundation::TimeSpan, llm::OS::UI::Xaml::DurationType>; };
    template <> struct category<llm::OS::UI::Xaml::GridLength>{ using type = struct_category<double, llm::OS::UI::Xaml::GridUnitType>; };
    template <> struct category<llm::OS::UI::Xaml::Thickness>{ using type = struct_category<double, double, double, double>; };
    template <> struct category<llm::OS::UI::Xaml::ApplicationInitializationCallback>{ using type = delegate_category; };
    template <> struct category<llm::OS::UI::Xaml::BindingFailedEventHandler>{ using type = delegate_category; };
    template <> struct category<llm::OS::UI::Xaml::CreateDefaultValueCallback>{ using type = delegate_category; };
    template <> struct category<llm::OS::UI::Xaml::DependencyPropertyChangedCallback>{ using type = delegate_category; };
    template <> struct category<llm::OS::UI::Xaml::DependencyPropertyChangedEventHandler>{ using type = delegate_category; };
    template <> struct category<llm::OS::UI::Xaml::DragEventHandler>{ using type = delegate_category; };
    template <> struct category<llm::OS::UI::Xaml::EnteredBackgroundEventHandler>{ using type = delegate_category; };
    template <> struct category<llm::OS::UI::Xaml::ExceptionRoutedEventHandler>{ using type = delegate_category; };
    template <> struct category<llm::OS::UI::Xaml::LeavingBackgroundEventHandler>{ using type = delegate_category; };
    template <> struct category<llm::OS::UI::Xaml::PropertyChangedCallback>{ using type = delegate_category; };
    template <> struct category<llm::OS::UI::Xaml::RoutedEventHandler>{ using type = delegate_category; };
    template <> struct category<llm::OS::UI::Xaml::SizeChangedEventHandler>{ using type = delegate_category; };
    template <> struct category<llm::OS::UI::Xaml::SuspendingEventHandler>{ using type = delegate_category; };
    template <> struct category<llm::OS::UI::Xaml::UnhandledExceptionEventHandler>{ using type = delegate_category; };
    template <> struct category<llm::OS::UI::Xaml::VisualStateChangedEventHandler>{ using type = delegate_category; };
    template <> struct category<llm::OS::UI::Xaml::WindowActivatedEventHandler>{ using type = delegate_category; };
    template <> struct category<llm::OS::UI::Xaml::WindowClosedEventHandler>{ using type = delegate_category; };
    template <> struct category<llm::OS::UI::Xaml::WindowSizeChangedEventHandler>{ using type = delegate_category; };
    template <> struct category<llm::OS::UI::Xaml::WindowVisibilityChangedEventHandler>{ using type = delegate_category; };
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::AdaptiveTrigger> = L"Windows.UI.Xaml.AdaptiveTrigger";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Application> = L"Windows.UI.Xaml.Application";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ApplicationInitializationCallbackParams> = L"Windows.UI.Xaml.ApplicationInitializationCallbackParams";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::BindingFailedEventArgs> = L"Windows.UI.Xaml.BindingFailedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::BringIntoViewOptions> = L"Windows.UI.Xaml.BringIntoViewOptions";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::BringIntoViewRequestedEventArgs> = L"Windows.UI.Xaml.BringIntoViewRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::BrushTransition> = L"Windows.UI.Xaml.BrushTransition";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ColorPaletteResources> = L"Windows.UI.Xaml.ColorPaletteResources";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::CornerRadiusHelper> = L"Windows.UI.Xaml.CornerRadiusHelper";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::DataContextChangedEventArgs> = L"Windows.UI.Xaml.DataContextChangedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::DataTemplate> = L"Windows.UI.Xaml.DataTemplate";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::DataTemplateKey> = L"Windows.UI.Xaml.DataTemplateKey";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::DebugSettings> = L"Windows.UI.Xaml.DebugSettings";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::DependencyObject> = L"Windows.UI.Xaml.DependencyObject";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::DependencyObjectCollection> = L"Windows.UI.Xaml.DependencyObjectCollection";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::DependencyProperty> = L"Windows.UI.Xaml.DependencyProperty";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::DependencyPropertyChangedEventArgs> = L"Windows.UI.Xaml.DependencyPropertyChangedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::DispatcherTimer> = L"Windows.UI.Xaml.DispatcherTimer";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::DragEventArgs> = L"Windows.UI.Xaml.DragEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::DragOperationDeferral> = L"Windows.UI.Xaml.DragOperationDeferral";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::DragStartingEventArgs> = L"Windows.UI.Xaml.DragStartingEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::DragUI> = L"Windows.UI.Xaml.DragUI";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::DragUIOverride> = L"Windows.UI.Xaml.DragUIOverride";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::DropCompletedEventArgs> = L"Windows.UI.Xaml.DropCompletedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::DurationHelper> = L"Windows.UI.Xaml.DurationHelper";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::EffectiveViewportChangedEventArgs> = L"Windows.UI.Xaml.EffectiveViewportChangedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ElementFactoryGetArgs> = L"Windows.UI.Xaml.ElementFactoryGetArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ElementFactoryRecycleArgs> = L"Windows.UI.Xaml.ElementFactoryRecycleArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ElementSoundPlayer> = L"Windows.UI.Xaml.ElementSoundPlayer";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::EventTrigger> = L"Windows.UI.Xaml.EventTrigger";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ExceptionRoutedEventArgs> = L"Windows.UI.Xaml.ExceptionRoutedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::FrameworkElement> = L"Windows.UI.Xaml.FrameworkElement";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::FrameworkTemplate> = L"Windows.UI.Xaml.FrameworkTemplate";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::FrameworkView> = L"Windows.UI.Xaml.FrameworkView";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::FrameworkViewSource> = L"Windows.UI.Xaml.FrameworkViewSource";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::GridLengthHelper> = L"Windows.UI.Xaml.GridLengthHelper";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::MediaFailedRoutedEventArgs> = L"Windows.UI.Xaml.MediaFailedRoutedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::PointHelper> = L"Windows.UI.Xaml.PointHelper";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::PropertyMetadata> = L"Windows.UI.Xaml.PropertyMetadata";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::PropertyPath> = L"Windows.UI.Xaml.PropertyPath";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::RectHelper> = L"Windows.UI.Xaml.RectHelper";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ResourceDictionary> = L"Windows.UI.Xaml.ResourceDictionary";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::RoutedEvent> = L"Windows.UI.Xaml.RoutedEvent";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::RoutedEventArgs> = L"Windows.UI.Xaml.RoutedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ScalarTransition> = L"Windows.UI.Xaml.ScalarTransition";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Setter> = L"Windows.UI.Xaml.Setter";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::SetterBase> = L"Windows.UI.Xaml.SetterBase";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::SetterBaseCollection> = L"Windows.UI.Xaml.SetterBaseCollection";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::SizeChangedEventArgs> = L"Windows.UI.Xaml.SizeChangedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::SizeHelper> = L"Windows.UI.Xaml.SizeHelper";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::StateTrigger> = L"Windows.UI.Xaml.StateTrigger";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::StateTriggerBase> = L"Windows.UI.Xaml.StateTriggerBase";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Style> = L"Windows.UI.Xaml.Style";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::TargetPropertyPath> = L"Windows.UI.Xaml.TargetPropertyPath";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ThicknessHelper> = L"Windows.UI.Xaml.ThicknessHelper";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::TriggerAction> = L"Windows.UI.Xaml.TriggerAction";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::TriggerActionCollection> = L"Windows.UI.Xaml.TriggerActionCollection";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::TriggerBase> = L"Windows.UI.Xaml.TriggerBase";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::TriggerCollection> = L"Windows.UI.Xaml.TriggerCollection";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::UIElement> = L"Windows.UI.Xaml.UIElement";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::UIElementWeakCollection> = L"Windows.UI.Xaml.UIElementWeakCollection";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::UnhandledExceptionEventArgs> = L"Windows.UI.Xaml.UnhandledExceptionEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Vector3Transition> = L"Windows.UI.Xaml.Vector3Transition";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::VisualState> = L"Windows.UI.Xaml.VisualState";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::VisualStateChangedEventArgs> = L"Windows.UI.Xaml.VisualStateChangedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::VisualStateGroup> = L"Windows.UI.Xaml.VisualStateGroup";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::VisualStateManager> = L"Windows.UI.Xaml.VisualStateManager";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::VisualTransition> = L"Windows.UI.Xaml.VisualTransition";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Window> = L"Windows.UI.Xaml.Window";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::WindowCreatedEventArgs> = L"Windows.UI.Xaml.WindowCreatedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::XamlRoot> = L"Windows.UI.Xaml.XamlRoot";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::XamlRootChangedEventArgs> = L"Windows.UI.Xaml.XamlRootChangedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ApplicationHighContrastAdjustment> = L"Windows.UI.Xaml.ApplicationHighContrastAdjustment";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ApplicationRequiresPointerMode> = L"Windows.UI.Xaml.ApplicationRequiresPointerMode";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ApplicationTheme> = L"Windows.UI.Xaml.ApplicationTheme";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::AutomationTextAttributesEnum> = L"Windows.UI.Xaml.AutomationTextAttributesEnum";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::DurationType> = L"Windows.UI.Xaml.DurationType";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ElementHighContrastAdjustment> = L"Windows.UI.Xaml.ElementHighContrastAdjustment";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ElementSoundKind> = L"Windows.UI.Xaml.ElementSoundKind";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ElementSoundMode> = L"Windows.UI.Xaml.ElementSoundMode";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ElementSoundPlayerState> = L"Windows.UI.Xaml.ElementSoundPlayerState";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ElementSpatialAudioMode> = L"Windows.UI.Xaml.ElementSpatialAudioMode";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ElementTheme> = L"Windows.UI.Xaml.ElementTheme";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::FlowDirection> = L"Windows.UI.Xaml.FlowDirection";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::FocusState> = L"Windows.UI.Xaml.FocusState";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::FocusVisualKind> = L"Windows.UI.Xaml.FocusVisualKind";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::FontCapitals> = L"Windows.UI.Xaml.FontCapitals";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::FontEastAsianLanguage> = L"Windows.UI.Xaml.FontEastAsianLanguage";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::FontEastAsianWidths> = L"Windows.UI.Xaml.FontEastAsianWidths";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::FontFraction> = L"Windows.UI.Xaml.FontFraction";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::FontNumeralAlignment> = L"Windows.UI.Xaml.FontNumeralAlignment";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::FontNumeralStyle> = L"Windows.UI.Xaml.FontNumeralStyle";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::FontVariants> = L"Windows.UI.Xaml.FontVariants";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::GridUnitType> = L"Windows.UI.Xaml.GridUnitType";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::HorizontalAlignment> = L"Windows.UI.Xaml.HorizontalAlignment";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::LineStackingStrategy> = L"Windows.UI.Xaml.LineStackingStrategy";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::OpticalMarginAlignment> = L"Windows.UI.Xaml.OpticalMarginAlignment";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::TextAlignment> = L"Windows.UI.Xaml.TextAlignment";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::TextLineBounds> = L"Windows.UI.Xaml.TextLineBounds";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::TextReadingOrder> = L"Windows.UI.Xaml.TextReadingOrder";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::TextTrimming> = L"Windows.UI.Xaml.TextTrimming";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::TextWrapping> = L"Windows.UI.Xaml.TextWrapping";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Vector3TransitionComponents> = L"Windows.UI.Xaml.Vector3TransitionComponents";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::VerticalAlignment> = L"Windows.UI.Xaml.VerticalAlignment";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Visibility> = L"Windows.UI.Xaml.Visibility";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::CornerRadius> = L"Windows.UI.Xaml.CornerRadius";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Duration> = L"Windows.UI.Xaml.Duration";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::GridLength> = L"Windows.UI.Xaml.GridLength";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Thickness> = L"Windows.UI.Xaml.Thickness";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IAdaptiveTrigger> = L"Windows.UI.Xaml.IAdaptiveTrigger";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IAdaptiveTriggerFactory> = L"Windows.UI.Xaml.IAdaptiveTriggerFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IAdaptiveTriggerStatics> = L"Windows.UI.Xaml.IAdaptiveTriggerStatics";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IApplication> = L"Windows.UI.Xaml.IApplication";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IApplication2> = L"Windows.UI.Xaml.IApplication2";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IApplication3> = L"Windows.UI.Xaml.IApplication3";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IApplicationFactory> = L"Windows.UI.Xaml.IApplicationFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IApplicationInitializationCallbackParams> = L"Windows.UI.Xaml.IApplicationInitializationCallbackParams";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IApplicationOverrides> = L"Windows.UI.Xaml.IApplicationOverrides";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IApplicationOverrides2> = L"Windows.UI.Xaml.IApplicationOverrides2";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IApplicationStatics> = L"Windows.UI.Xaml.IApplicationStatics";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IBindingFailedEventArgs> = L"Windows.UI.Xaml.IBindingFailedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IBringIntoViewOptions> = L"Windows.UI.Xaml.IBringIntoViewOptions";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IBringIntoViewOptions2> = L"Windows.UI.Xaml.IBringIntoViewOptions2";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IBringIntoViewRequestedEventArgs> = L"Windows.UI.Xaml.IBringIntoViewRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IBrushTransition> = L"Windows.UI.Xaml.IBrushTransition";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IBrushTransitionFactory> = L"Windows.UI.Xaml.IBrushTransitionFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IColorPaletteResources> = L"Windows.UI.Xaml.IColorPaletteResources";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IColorPaletteResourcesFactory> = L"Windows.UI.Xaml.IColorPaletteResourcesFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ICornerRadiusHelper> = L"Windows.UI.Xaml.ICornerRadiusHelper";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ICornerRadiusHelperStatics> = L"Windows.UI.Xaml.ICornerRadiusHelperStatics";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IDataContextChangedEventArgs> = L"Windows.UI.Xaml.IDataContextChangedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IDataTemplate> = L"Windows.UI.Xaml.IDataTemplate";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IDataTemplateExtension> = L"Windows.UI.Xaml.IDataTemplateExtension";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IDataTemplateFactory> = L"Windows.UI.Xaml.IDataTemplateFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IDataTemplateKey> = L"Windows.UI.Xaml.IDataTemplateKey";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IDataTemplateKeyFactory> = L"Windows.UI.Xaml.IDataTemplateKeyFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IDataTemplateStatics2> = L"Windows.UI.Xaml.IDataTemplateStatics2";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IDebugSettings> = L"Windows.UI.Xaml.IDebugSettings";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IDebugSettings2> = L"Windows.UI.Xaml.IDebugSettings2";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IDebugSettings3> = L"Windows.UI.Xaml.IDebugSettings3";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IDebugSettings4> = L"Windows.UI.Xaml.IDebugSettings4";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IDependencyObject> = L"Windows.UI.Xaml.IDependencyObject";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IDependencyObject2> = L"Windows.UI.Xaml.IDependencyObject2";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IDependencyObjectCollectionFactory> = L"Windows.UI.Xaml.IDependencyObjectCollectionFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IDependencyObjectFactory> = L"Windows.UI.Xaml.IDependencyObjectFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IDependencyProperty> = L"Windows.UI.Xaml.IDependencyProperty";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IDependencyPropertyChangedEventArgs> = L"Windows.UI.Xaml.IDependencyPropertyChangedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IDependencyPropertyStatics> = L"Windows.UI.Xaml.IDependencyPropertyStatics";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IDispatcherTimer> = L"Windows.UI.Xaml.IDispatcherTimer";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IDispatcherTimerFactory> = L"Windows.UI.Xaml.IDispatcherTimerFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IDragEventArgs> = L"Windows.UI.Xaml.IDragEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IDragEventArgs2> = L"Windows.UI.Xaml.IDragEventArgs2";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IDragEventArgs3> = L"Windows.UI.Xaml.IDragEventArgs3";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IDragOperationDeferral> = L"Windows.UI.Xaml.IDragOperationDeferral";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IDragStartingEventArgs> = L"Windows.UI.Xaml.IDragStartingEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IDragStartingEventArgs2> = L"Windows.UI.Xaml.IDragStartingEventArgs2";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IDragUI> = L"Windows.UI.Xaml.IDragUI";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IDragUIOverride> = L"Windows.UI.Xaml.IDragUIOverride";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IDropCompletedEventArgs> = L"Windows.UI.Xaml.IDropCompletedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IDurationHelper> = L"Windows.UI.Xaml.IDurationHelper";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IDurationHelperStatics> = L"Windows.UI.Xaml.IDurationHelperStatics";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IEffectiveViewportChangedEventArgs> = L"Windows.UI.Xaml.IEffectiveViewportChangedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IElementFactory> = L"Windows.UI.Xaml.IElementFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IElementFactoryGetArgs> = L"Windows.UI.Xaml.IElementFactoryGetArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IElementFactoryGetArgsFactory> = L"Windows.UI.Xaml.IElementFactoryGetArgsFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IElementFactoryRecycleArgs> = L"Windows.UI.Xaml.IElementFactoryRecycleArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IElementFactoryRecycleArgsFactory> = L"Windows.UI.Xaml.IElementFactoryRecycleArgsFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IElementSoundPlayer> = L"Windows.UI.Xaml.IElementSoundPlayer";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IElementSoundPlayerStatics> = L"Windows.UI.Xaml.IElementSoundPlayerStatics";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IElementSoundPlayerStatics2> = L"Windows.UI.Xaml.IElementSoundPlayerStatics2";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IEventTrigger> = L"Windows.UI.Xaml.IEventTrigger";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IExceptionRoutedEventArgs> = L"Windows.UI.Xaml.IExceptionRoutedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IExceptionRoutedEventArgsFactory> = L"Windows.UI.Xaml.IExceptionRoutedEventArgsFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IFrameworkElement> = L"Windows.UI.Xaml.IFrameworkElement";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IFrameworkElement2> = L"Windows.UI.Xaml.IFrameworkElement2";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IFrameworkElement3> = L"Windows.UI.Xaml.IFrameworkElement3";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IFrameworkElement4> = L"Windows.UI.Xaml.IFrameworkElement4";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IFrameworkElement6> = L"Windows.UI.Xaml.IFrameworkElement6";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IFrameworkElement7> = L"Windows.UI.Xaml.IFrameworkElement7";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IFrameworkElementFactory> = L"Windows.UI.Xaml.IFrameworkElementFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IFrameworkElementOverrides> = L"Windows.UI.Xaml.IFrameworkElementOverrides";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IFrameworkElementOverrides2> = L"Windows.UI.Xaml.IFrameworkElementOverrides2";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IFrameworkElementProtected7> = L"Windows.UI.Xaml.IFrameworkElementProtected7";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IFrameworkElementStatics> = L"Windows.UI.Xaml.IFrameworkElementStatics";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IFrameworkElementStatics2> = L"Windows.UI.Xaml.IFrameworkElementStatics2";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IFrameworkElementStatics4> = L"Windows.UI.Xaml.IFrameworkElementStatics4";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IFrameworkElementStatics5> = L"Windows.UI.Xaml.IFrameworkElementStatics5";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IFrameworkElementStatics6> = L"Windows.UI.Xaml.IFrameworkElementStatics6";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IFrameworkTemplate> = L"Windows.UI.Xaml.IFrameworkTemplate";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IFrameworkTemplateFactory> = L"Windows.UI.Xaml.IFrameworkTemplateFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IFrameworkView> = L"Windows.UI.Xaml.IFrameworkView";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IFrameworkViewSource> = L"Windows.UI.Xaml.IFrameworkViewSource";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IGridLengthHelper> = L"Windows.UI.Xaml.IGridLengthHelper";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IGridLengthHelperStatics> = L"Windows.UI.Xaml.IGridLengthHelperStatics";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IMediaFailedRoutedEventArgs> = L"Windows.UI.Xaml.IMediaFailedRoutedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IPointHelper> = L"Windows.UI.Xaml.IPointHelper";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IPointHelperStatics> = L"Windows.UI.Xaml.IPointHelperStatics";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IPropertyMetadata> = L"Windows.UI.Xaml.IPropertyMetadata";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IPropertyMetadataFactory> = L"Windows.UI.Xaml.IPropertyMetadataFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IPropertyMetadataStatics> = L"Windows.UI.Xaml.IPropertyMetadataStatics";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IPropertyPath> = L"Windows.UI.Xaml.IPropertyPath";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IPropertyPathFactory> = L"Windows.UI.Xaml.IPropertyPathFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IRectHelper> = L"Windows.UI.Xaml.IRectHelper";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IRectHelperStatics> = L"Windows.UI.Xaml.IRectHelperStatics";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IResourceDictionary> = L"Windows.UI.Xaml.IResourceDictionary";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IResourceDictionaryFactory> = L"Windows.UI.Xaml.IResourceDictionaryFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IRoutedEvent> = L"Windows.UI.Xaml.IRoutedEvent";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IRoutedEventArgs> = L"Windows.UI.Xaml.IRoutedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IRoutedEventArgsFactory> = L"Windows.UI.Xaml.IRoutedEventArgsFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IScalarTransition> = L"Windows.UI.Xaml.IScalarTransition";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IScalarTransitionFactory> = L"Windows.UI.Xaml.IScalarTransitionFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ISetter> = L"Windows.UI.Xaml.ISetter";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ISetter2> = L"Windows.UI.Xaml.ISetter2";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ISetterBase> = L"Windows.UI.Xaml.ISetterBase";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ISetterBaseCollection> = L"Windows.UI.Xaml.ISetterBaseCollection";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ISetterBaseFactory> = L"Windows.UI.Xaml.ISetterBaseFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ISetterFactory> = L"Windows.UI.Xaml.ISetterFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ISizeChangedEventArgs> = L"Windows.UI.Xaml.ISizeChangedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ISizeHelper> = L"Windows.UI.Xaml.ISizeHelper";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ISizeHelperStatics> = L"Windows.UI.Xaml.ISizeHelperStatics";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IStateTrigger> = L"Windows.UI.Xaml.IStateTrigger";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IStateTriggerBase> = L"Windows.UI.Xaml.IStateTriggerBase";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IStateTriggerBaseFactory> = L"Windows.UI.Xaml.IStateTriggerBaseFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IStateTriggerBaseProtected> = L"Windows.UI.Xaml.IStateTriggerBaseProtected";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IStateTriggerStatics> = L"Windows.UI.Xaml.IStateTriggerStatics";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IStyle> = L"Windows.UI.Xaml.IStyle";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IStyleFactory> = L"Windows.UI.Xaml.IStyleFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ITargetPropertyPath> = L"Windows.UI.Xaml.ITargetPropertyPath";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ITargetPropertyPathFactory> = L"Windows.UI.Xaml.ITargetPropertyPathFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IThicknessHelper> = L"Windows.UI.Xaml.IThicknessHelper";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IThicknessHelperStatics> = L"Windows.UI.Xaml.IThicknessHelperStatics";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ITriggerAction> = L"Windows.UI.Xaml.ITriggerAction";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ITriggerActionFactory> = L"Windows.UI.Xaml.ITriggerActionFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ITriggerBase> = L"Windows.UI.Xaml.ITriggerBase";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ITriggerBaseFactory> = L"Windows.UI.Xaml.ITriggerBaseFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IUIElement> = L"Windows.UI.Xaml.IUIElement";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IUIElement10> = L"Windows.UI.Xaml.IUIElement10";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IUIElement2> = L"Windows.UI.Xaml.IUIElement2";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IUIElement3> = L"Windows.UI.Xaml.IUIElement3";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IUIElement4> = L"Windows.UI.Xaml.IUIElement4";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IUIElement5> = L"Windows.UI.Xaml.IUIElement5";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IUIElement7> = L"Windows.UI.Xaml.IUIElement7";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IUIElement8> = L"Windows.UI.Xaml.IUIElement8";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IUIElement9> = L"Windows.UI.Xaml.IUIElement9";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IUIElementFactory> = L"Windows.UI.Xaml.IUIElementFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IUIElementOverrides> = L"Windows.UI.Xaml.IUIElementOverrides";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IUIElementOverrides7> = L"Windows.UI.Xaml.IUIElementOverrides7";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IUIElementOverrides8> = L"Windows.UI.Xaml.IUIElementOverrides8";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IUIElementOverrides9> = L"Windows.UI.Xaml.IUIElementOverrides9";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IUIElementStatics> = L"Windows.UI.Xaml.IUIElementStatics";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IUIElementStatics10> = L"Windows.UI.Xaml.IUIElementStatics10";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IUIElementStatics2> = L"Windows.UI.Xaml.IUIElementStatics2";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IUIElementStatics3> = L"Windows.UI.Xaml.IUIElementStatics3";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IUIElementStatics4> = L"Windows.UI.Xaml.IUIElementStatics4";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IUIElementStatics5> = L"Windows.UI.Xaml.IUIElementStatics5";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IUIElementStatics6> = L"Windows.UI.Xaml.IUIElementStatics6";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IUIElementStatics7> = L"Windows.UI.Xaml.IUIElementStatics7";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IUIElementStatics8> = L"Windows.UI.Xaml.IUIElementStatics8";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IUIElementStatics9> = L"Windows.UI.Xaml.IUIElementStatics9";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IUIElementWeakCollection> = L"Windows.UI.Xaml.IUIElementWeakCollection";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IUIElementWeakCollectionFactory> = L"Windows.UI.Xaml.IUIElementWeakCollectionFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IUnhandledExceptionEventArgs> = L"Windows.UI.Xaml.IUnhandledExceptionEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IVector3Transition> = L"Windows.UI.Xaml.IVector3Transition";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IVector3TransitionFactory> = L"Windows.UI.Xaml.IVector3TransitionFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IVisualState> = L"Windows.UI.Xaml.IVisualState";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IVisualState2> = L"Windows.UI.Xaml.IVisualState2";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IVisualStateChangedEventArgs> = L"Windows.UI.Xaml.IVisualStateChangedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IVisualStateGroup> = L"Windows.UI.Xaml.IVisualStateGroup";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IVisualStateManager> = L"Windows.UI.Xaml.IVisualStateManager";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IVisualStateManagerFactory> = L"Windows.UI.Xaml.IVisualStateManagerFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IVisualStateManagerOverrides> = L"Windows.UI.Xaml.IVisualStateManagerOverrides";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IVisualStateManagerProtected> = L"Windows.UI.Xaml.IVisualStateManagerProtected";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IVisualStateManagerStatics> = L"Windows.UI.Xaml.IVisualStateManagerStatics";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IVisualTransition> = L"Windows.UI.Xaml.IVisualTransition";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IVisualTransitionFactory> = L"Windows.UI.Xaml.IVisualTransitionFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IWindow> = L"Windows.UI.Xaml.IWindow";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IWindow2> = L"Windows.UI.Xaml.IWindow2";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IWindow3> = L"Windows.UI.Xaml.IWindow3";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IWindow4> = L"Windows.UI.Xaml.IWindow4";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IWindowCreatedEventArgs> = L"Windows.UI.Xaml.IWindowCreatedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IWindowStatics> = L"Windows.UI.Xaml.IWindowStatics";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IXamlRoot> = L"Windows.UI.Xaml.IXamlRoot";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::IXamlRootChangedEventArgs> = L"Windows.UI.Xaml.IXamlRootChangedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ApplicationInitializationCallback> = L"Windows.UI.Xaml.ApplicationInitializationCallback";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::BindingFailedEventHandler> = L"Windows.UI.Xaml.BindingFailedEventHandler";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::CreateDefaultValueCallback> = L"Windows.UI.Xaml.CreateDefaultValueCallback";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::DependencyPropertyChangedCallback> = L"Windows.UI.Xaml.DependencyPropertyChangedCallback";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::DependencyPropertyChangedEventHandler> = L"Windows.UI.Xaml.DependencyPropertyChangedEventHandler";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::DragEventHandler> = L"Windows.UI.Xaml.DragEventHandler";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::EnteredBackgroundEventHandler> = L"Windows.UI.Xaml.EnteredBackgroundEventHandler";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::ExceptionRoutedEventHandler> = L"Windows.UI.Xaml.ExceptionRoutedEventHandler";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::LeavingBackgroundEventHandler> = L"Windows.UI.Xaml.LeavingBackgroundEventHandler";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::PropertyChangedCallback> = L"Windows.UI.Xaml.PropertyChangedCallback";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::RoutedEventHandler> = L"Windows.UI.Xaml.RoutedEventHandler";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::SizeChangedEventHandler> = L"Windows.UI.Xaml.SizeChangedEventHandler";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::SuspendingEventHandler> = L"Windows.UI.Xaml.SuspendingEventHandler";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::UnhandledExceptionEventHandler> = L"Windows.UI.Xaml.UnhandledExceptionEventHandler";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::VisualStateChangedEventHandler> = L"Windows.UI.Xaml.VisualStateChangedEventHandler";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::WindowActivatedEventHandler> = L"Windows.UI.Xaml.WindowActivatedEventHandler";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::WindowClosedEventHandler> = L"Windows.UI.Xaml.WindowClosedEventHandler";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::WindowSizeChangedEventHandler> = L"Windows.UI.Xaml.WindowSizeChangedEventHandler";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::WindowVisibilityChangedEventHandler> = L"Windows.UI.Xaml.WindowVisibilityChangedEventHandler";
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IAdaptiveTrigger>{ 0xA5F04119,0x0CD9,0x49F1,{ 0xA2,0x3F,0x44,0xE5,0x47,0xAB,0x9F,0x1A } }; // A5F04119-0CD9-49F1-A23F-44E547AB9F1A
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IAdaptiveTriggerFactory>{ 0xC966D482,0x5AEB,0x4841,{ 0x92,0x47,0xC1,0xA0,0xBD,0xD6,0xF5,0x9F } }; // C966D482-5AEB-4841-9247-C1A0BDD6F59F
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IAdaptiveTriggerStatics>{ 0xB92E29EA,0x1615,0x4350,{ 0x9C,0x3B,0x92,0xB2,0x98,0x6B,0xF4,0x44 } }; // B92E29EA-1615-4350-9C3B-92B2986BF444
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IApplication>{ 0x74B861A1,0x7487,0x46A9,{ 0x9A,0x6E,0xC7,0x8B,0x51,0x27,0x26,0xC5 } }; // 74B861A1-7487-46A9-9A6E-C78B512726C5
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IApplication2>{ 0x019104BE,0x522A,0x5904,{ 0xF5,0x2F,0xDE,0x72,0x01,0x04,0x29,0xE0 } }; // 019104BE-522A-5904-F52F-DE72010429E0
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IApplication3>{ 0xB775AD7C,0x18B8,0x45CA,{ 0xA1,0xB0,0xDC,0x48,0x3E,0x4B,0x10,0x28 } }; // B775AD7C-18B8-45CA-A1B0-DC483E4B1028
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IApplicationFactory>{ 0x93BBE361,0xBE5A,0x4EE3,{ 0xB4,0xA3,0x95,0x11,0x8D,0xC9,0x7A,0x89 } }; // 93BBE361-BE5A-4EE3-B4A3-95118DC97A89
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IApplicationInitializationCallbackParams>{ 0x751B792E,0x5772,0x4488,{ 0x8B,0x87,0xF5,0x47,0xFA,0xA6,0x44,0x74 } }; // 751B792E-5772-4488-8B87-F547FAA64474
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IApplicationOverrides>{ 0x25F99FF7,0x9347,0x459A,{ 0x9F,0xAC,0xB2,0xD0,0xE1,0x1C,0x1A,0x0F } }; // 25F99FF7-9347-459A-9FAC-B2D0E11C1A0F
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IApplicationOverrides2>{ 0xDB5CD2B9,0xD3B4,0x558C,{ 0xC6,0x4E,0x04,0x34,0xFD,0x1B,0xD8,0x89 } }; // DB5CD2B9-D3B4-558C-C64E-0434FD1BD889
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IApplicationStatics>{ 0x06499997,0xF7B4,0x45FE,{ 0xB7,0x63,0x75,0x77,0xD1,0xD3,0xCB,0x4A } }; // 06499997-F7B4-45FE-B763-7577D1D3CB4A
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IBindingFailedEventArgs>{ 0x32C1D013,0x4DBD,0x446D,{ 0xBB,0xB8,0x0D,0xE3,0x50,0x48,0xA4,0x49 } }; // 32C1D013-4DBD-446D-BBB8-0DE35048A449
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IBringIntoViewOptions>{ 0x19BDD1B5,0xC7CB,0x46D9,{ 0xA4,0xDD,0xA1,0xBB,0xE8,0x3E,0xF2,0xFB } }; // 19BDD1B5-C7CB-46D9-A4DD-A1BBE83EF2FB
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IBringIntoViewOptions2>{ 0xE855E08E,0x64B6,0x1211,{ 0xBD,0xDB,0x1F,0xDD,0xBB,0x6E,0x82,0x31 } }; // E855E08E-64B6-1211-BDDB-1FDDBB6E8231
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IBringIntoViewRequestedEventArgs>{ 0x0E629EC4,0x2206,0x4C8B,{ 0x94,0xAE,0xBD,0xB6,0x6A,0x4E,0xBF,0xD1 } }; // 0E629EC4-2206-4C8B-94AE-BDB66A4EBFD1
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IBrushTransition>{ 0x1116972C,0x9DAD,0x5429,{ 0xA7,0xDD,0xB2,0xB7,0xD0,0x61,0xAB,0x8E } }; // 1116972C-9DAD-5429-A7DD-B2B7D061AB8E
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IBrushTransitionFactory>{ 0x3DBE7368,0x13D4,0x510C,{ 0xA2,0x15,0x75,0x39,0xF4,0x78,0x7B,0x52 } }; // 3DBE7368-13D4-510C-A215-7539F4787B52
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IColorPaletteResources>{ 0x258088C4,0xAEF2,0x5D3F,{ 0x83,0x3B,0xC3,0x6D,0xB6,0x27,0x8E,0xD9 } }; // 258088C4-AEF2-5D3F-833B-C36DB6278ED9
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IColorPaletteResourcesFactory>{ 0xA57F0783,0x1876,0x5CC0,{ 0x8E,0xA5,0xBC,0x77,0xB1,0x7E,0x0F,0x7E } }; // A57F0783-1876-5CC0-8EA5-BC77B17E0F7E
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::ICornerRadiusHelper>{ 0xFD7BE182,0x1CDB,0x4288,{ 0xB8,0xC8,0x85,0xEE,0x79,0x29,0x7B,0xFC } }; // FD7BE182-1CDB-4288-B8C8-85EE79297BFC
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::ICornerRadiusHelperStatics>{ 0xF4A1F659,0xD4D4,0x451F,{ 0xA3,0x87,0xD6,0xBF,0x4B,0x24,0x51,0xD4 } }; // F4A1F659-D4D4-451F-A387-D6BF4B2451D4
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IDataContextChangedEventArgs>{ 0x7DA68E21,0x0B8F,0x4F9F,{ 0xA1,0x43,0xF8,0xE7,0x78,0x01,0x36,0xA2 } }; // 7DA68E21-0B8F-4F9F-A143-F8E7780136A2
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IDataTemplate>{ 0x9910AEC7,0x8AB5,0x4118,{ 0x9B,0xC6,0x09,0xF4,0x5A,0x35,0x07,0x3D } }; // 9910AEC7-8AB5-4118-9BC6-09F45A35073D
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IDataTemplateExtension>{ 0x595E9547,0xCDFF,0x4B92,{ 0xB7,0x73,0xAB,0x39,0x68,0x78,0xF3,0x53 } }; // 595E9547-CDFF-4B92-B773-AB396878F353
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IDataTemplateFactory>{ 0x51ED9D7E,0x2B53,0x475B,{ 0x9C,0x88,0x0C,0x18,0x32,0xC8,0x35,0x1A } }; // 51ED9D7E-2B53-475B-9C88-0C1832C8351A
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IDataTemplateKey>{ 0x873B6C28,0xCCEB,0x4B61,{ 0x86,0xFA,0xB2,0xCE,0xC3,0x9C,0xC2,0xFA } }; // 873B6C28-CCEB-4B61-86FA-B2CEC39CC2FA
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IDataTemplateKeyFactory>{ 0xE96B2959,0xD982,0x4152,{ 0x91,0xCB,0xDE,0x0E,0x4D,0xFD,0x76,0x93 } }; // E96B2959-D982-4152-91CB-DE0E4DFD7693
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IDataTemplateStatics2>{ 0x8AF77D73,0xAA01,0x471E,{ 0xBE,0xDD,0x8B,0xAD,0x86,0x21,0x9B,0x77 } }; // 8AF77D73-AA01-471E-BEDD-8BAD86219B77
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IDebugSettings>{ 0x3D451F98,0xC6A7,0x4D17,{ 0x83,0x98,0xD8,0x3A,0x06,0x71,0x83,0xD8 } }; // 3D451F98-C6A7-4D17-8398-D83A067183D8
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IDebugSettings2>{ 0x48D37585,0xE1A6,0x469B,{ 0x83,0xC8,0x30,0x82,0x50,0x37,0x11,0x9E } }; // 48D37585-E1A6-469B-83C8-30825037119E
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IDebugSettings3>{ 0xE6BB5022,0x0625,0x479F,{ 0x8E,0x32,0x4B,0x58,0x3D,0x73,0xB7,0xAC } }; // E6BB5022-0625-479F-8E32-4B583D73B7AC
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IDebugSettings4>{ 0xC9001E45,0xE824,0x5A5F,{ 0x86,0x6C,0xE2,0x0C,0xEC,0x88,0xA8,0xFC } }; // C9001E45-E824-5A5F-866C-E20CEC88A8FC
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IDependencyObject>{ 0x5C526665,0xF60E,0x4912,{ 0xAF,0x59,0x5F,0xE0,0x68,0x0F,0x08,0x9D } }; // 5C526665-F60E-4912-AF59-5FE0680F089D
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IDependencyObject2>{ 0x29FED85D,0x3D22,0x43A1,{ 0xAD,0xD0,0x17,0x02,0x7C,0x08,0xB2,0x12 } }; // 29FED85D-3D22-43A1-ADD0-17027C08B212
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IDependencyObjectCollectionFactory>{ 0x051E79FF,0xB3A8,0x49EE,{ 0xB5,0xAF,0xAC,0x8F,0x68,0xB6,0x49,0xE4 } }; // 051E79FF-B3A8-49EE-B5AF-AC8F68B649E4
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IDependencyObjectFactory>{ 0x9A03AF92,0x7D8A,0x4937,{ 0x88,0x4F,0xEC,0xF3,0x4F,0xE0,0x2A,0xCB } }; // 9A03AF92-7D8A-4937-884F-ECF34FE02ACB
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IDependencyProperty>{ 0x85B13970,0x9BC4,0x4E96,{ 0xAC,0xF1,0x30,0xC8,0xFD,0x3D,0x55,0xC8 } }; // 85B13970-9BC4-4E96-ACF1-30C8FD3D55C8
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IDependencyPropertyChangedEventArgs>{ 0x81212C2B,0x24D0,0x4957,{ 0xAB,0xC3,0x22,0x44,0x70,0xA9,0x3A,0x4E } }; // 81212C2B-24D0-4957-ABC3-224470A93A4E
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IDependencyPropertyStatics>{ 0x49E5F28F,0x8259,0x4D5C,{ 0xAA,0xE0,0x83,0xD5,0x6D,0xBB,0x68,0xD9 } }; // 49E5F28F-8259-4D5C-AAE0-83D56DBB68D9
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IDispatcherTimer>{ 0xD160CE46,0xCD22,0x4F5F,{ 0x8C,0x97,0x40,0xE6,0x1D,0xA3,0xE2,0xDC } }; // D160CE46-CD22-4F5F-8C97-40E61DA3E2DC
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IDispatcherTimerFactory>{ 0xE9961E6E,0x3626,0x403A,{ 0xAF,0xE0,0x04,0x0D,0x58,0x16,0x56,0x32 } }; // E9961E6E-3626-403A-AFE0-040D58165632
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IDragEventArgs>{ 0xB440C7C3,0x02B4,0x4980,{ 0x93,0x42,0x25,0xDA,0xE1,0xC0,0xF1,0x88 } }; // B440C7C3-02B4-4980-9342-25DAE1C0F188
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IDragEventArgs2>{ 0x26336658,0x2917,0x411D,{ 0xBF,0xC3,0x2F,0x22,0x47,0x1C,0xBB,0xE7 } }; // 26336658-2917-411D-BFC3-2F22471CBBE7
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IDragEventArgs3>{ 0xD04FC3C6,0x8119,0x427A,{ 0x81,0x52,0x5F,0x95,0x50,0xCC,0x04,0x16 } }; // D04FC3C6-8119-427A-8152-5F9550CC0416
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IDragOperationDeferral>{ 0xBA73ECBA,0x1B73,0x4086,{ 0xB3,0xD3,0xC2,0x23,0xBE,0xEA,0x16,0x33 } }; // BA73ECBA-1B73-4086-B3D3-C223BEEA1633
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IDragStartingEventArgs>{ 0x6800D3FA,0x90B8,0x46F9,{ 0x8E,0x30,0x5A,0xC2,0x5F,0x73,0xF0,0xF9 } }; // 6800D3FA-90B8-46F9-8E30-5AC25F73F0F9
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IDragStartingEventArgs2>{ 0xD855E08E,0x44B6,0x4211,{ 0xBD,0x0B,0x7F,0xDD,0xBB,0x6E,0x82,0x31 } }; // D855E08E-44B6-4211-BD0B-7FDDBB6E8231
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IDragUI>{ 0x2D9BD838,0x7C60,0x4842,{ 0x91,0x70,0x34,0x6F,0xE1,0x0A,0x22,0x6A } }; // 2D9BD838-7C60-4842-9170-346FE10A226A
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IDragUIOverride>{ 0xBD6C9DFA,0xC961,0x4861,{ 0xB7,0xA5,0xBF,0x4F,0xE4,0xA8,0xA6,0xEF } }; // BD6C9DFA-C961-4861-B7A5-BF4FE4A8A6EF
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IDropCompletedEventArgs>{ 0x6C4FC188,0x95BC,0x4261,{ 0x9E,0xC5,0x21,0xCA,0xB6,0x77,0xB7,0x34 } }; // 6C4FC188-95BC-4261-9EC5-21CAB677B734
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IDurationHelper>{ 0x25C1659F,0x4497,0x4135,{ 0x94,0x0F,0xEE,0x96,0xF4,0xD6,0xE9,0x34 } }; // 25C1659F-4497-4135-940F-EE96F4D6E934
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IDurationHelperStatics>{ 0xBC88093E,0x3547,0x4EC0,{ 0xB5,0x19,0xFF,0xA8,0xF9,0xC4,0x83,0x8C } }; // BC88093E-3547-4EC0-B519-FFA8F9C4838C
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IEffectiveViewportChangedEventArgs>{ 0x55EE2E81,0x1C18,0x59ED,{ 0xBD,0x3D,0xC4,0xCA,0x8F,0xA7,0xD1,0x90 } }; // 55EE2E81-1C18-59ED-BD3D-C4CA8FA7D190
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IElementFactory>{ 0x17D2AD90,0x1370,0x55C8,{ 0x80,0xE1,0x78,0xB4,0x90,0x04,0xA9,0xE1 } }; // 17D2AD90-1370-55C8-80E1-78B49004A9E1
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IElementFactoryGetArgs>{ 0xFB508774,0x41A3,0x5829,{ 0x92,0x55,0xCF,0x45,0x2D,0x04,0x1D,0xF4 } }; // FB508774-41A3-5829-9255-CF452D041DF4
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IElementFactoryGetArgsFactory>{ 0xC3B6DAE7,0x883B,0x5FD7,{ 0xBE,0x80,0x20,0x59,0xD8,0x77,0xE7,0x83 } }; // C3B6DAE7-883B-5FD7-BE80-2059D877E783
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IElementFactoryRecycleArgs>{ 0x86F16B14,0x37E8,0x5DD8,{ 0xA9,0x0C,0x25,0xD3,0x71,0x03,0x18,0xB0 } }; // 86F16B14-37E8-5DD8-A90C-25D3710318B0
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IElementFactoryRecycleArgsFactory>{ 0x8D926509,0xEA0D,0x541B,{ 0x82,0x71,0xF9,0xE9,0x11,0x8F,0x5E,0x7C } }; // 8D926509-EA0D-541B-8271-F9E9118F5E7C
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IElementSoundPlayer>{ 0x387773A5,0xF036,0x460C,{ 0x9B,0x81,0xF3,0xD6,0xEA,0x43,0xF6,0xF2 } }; // 387773A5-F036-460C-9B81-F3D6EA43F6F2
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IElementSoundPlayerStatics>{ 0x217A9004,0x981D,0x41C9,{ 0xB1,0x52,0xAD,0xA9,0x11,0xA4,0xB1,0x3A } }; // 217A9004-981D-41C9-B152-ADA911A4B13A
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IElementSoundPlayerStatics2>{ 0xF2505956,0xED41,0x48D7,{ 0xAA,0xE8,0xF2,0xAB,0xCB,0x44,0x49,0x29 } }; // F2505956-ED41-48D7-AAE8-F2ABCB444929
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IEventTrigger>{ 0xDEF8F855,0x0B49,0x4087,{ 0xB1,0xA9,0xB8,0xB3,0x84,0x88,0xF7,0x86 } }; // DEF8F855-0B49-4087-B1A9-B8B38488F786
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IExceptionRoutedEventArgs>{ 0xDD9FF16A,0x4B62,0x4A6C,{ 0xA4,0x9D,0x06,0x71,0xEF,0x61,0x36,0xBE } }; // DD9FF16A-4B62-4A6C-A49D-0671EF6136BE
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IExceptionRoutedEventArgsFactory>{ 0xBBA9826D,0x5D7A,0x44E7,{ 0xB8,0x93,0xB2,0xAE,0x0D,0xD2,0x42,0x73 } }; // BBA9826D-5D7A-44E7-B893-B2AE0DD24273
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IFrameworkElement>{ 0xA391D09B,0x4A99,0x4B7C,{ 0x9D,0x8D,0x6F,0xA5,0xD0,0x1F,0x6F,0xBF } }; // A391D09B-4A99-4B7C-9D8D-6FA5D01F6FBF
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IFrameworkElement2>{ 0xF19104BE,0x422A,0x4904,{ 0xA5,0x2F,0xEE,0x72,0x01,0x04,0x29,0xE5 } }; // F19104BE-422A-4904-A52F-EE72010429E5
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IFrameworkElement3>{ 0xC81C2720,0x5C52,0x4BBE,{ 0xA1,0x99,0x2B,0x1E,0x34,0xF0,0x0F,0x70 } }; // C81C2720-5C52-4BBE-A199-2B1E34F00F70
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IFrameworkElement4>{ 0x6B765BB3,0xFBA3,0x4404,{ 0xBD,0xEE,0x1A,0x45,0xD1,0xCA,0x5F,0x21 } }; // 6B765BB3-FBA3-4404-BDEE-1A45D1CA5F21
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IFrameworkElement6>{ 0x792A5D91,0x62A1,0x40BF,{ 0xA0,0xCE,0xF9,0xC1,0x31,0xFC,0xB7,0xA7 } }; // 792A5D91-62A1-40BF-A0CE-F9C131FCB7A7
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IFrameworkElement7>{ 0x2263886C,0xC069,0x570F,{ 0xB9,0xCC,0x9E,0x21,0xDD,0x02,0x8D,0x8E } }; // 2263886C-C069-570F-B9CC-9E21DD028D8E
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IFrameworkElementFactory>{ 0xDEAEE126,0x03CA,0x4966,{ 0xB5,0x76,0x60,0x4C,0xCE,0x93,0xB5,0xE8 } }; // DEAEE126-03CA-4966-B576-604CCE93B5E8
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IFrameworkElementOverrides>{ 0xDA007E54,0xB3C2,0x4B9A,{ 0xAA,0x8E,0xD3,0xF0,0x71,0x26,0x2B,0x97 } }; // DA007E54-B3C2-4B9A-AA8E-D3F071262B97
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IFrameworkElementOverrides2>{ 0xCB5CD2B9,0xE3B4,0x458C,{ 0xB6,0x4E,0x14,0x34,0xFD,0x1B,0xD8,0x8A } }; // CB5CD2B9-E3B4-458C-B64E-1434FD1BD88A
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IFrameworkElementProtected7>{ 0x65AA0480,0x22E3,0x5103,{ 0xAD,0x2A,0xB6,0x26,0xF8,0x8C,0xA5,0xAE } }; // 65AA0480-22E3-5103-AD2A-B626F88CA5AE
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IFrameworkElementStatics>{ 0x48383032,0xFBEB,0x4F8A,{ 0xAE,0xD2,0xEE,0x21,0xFB,0x27,0xA5,0x7B } }; // 48383032-FBEB-4F8A-AED2-EE21FB27A57B
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IFrameworkElementStatics2>{ 0x9695DB02,0xC0D8,0x4FA2,{ 0xB1,0x00,0x3F,0xA2,0xDF,0x8B,0x95,0x38 } }; // 9695DB02-C0D8-4FA2-B100-3FA2DF8B9538
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IFrameworkElementStatics4>{ 0x9C41B155,0xC5D8,0x4663,{ 0xBF,0xF2,0xD8,0xD5,0x4F,0xB5,0xDB,0xB3 } }; // 9C41B155-C5D8-4663-BFF2-D8D54FB5DBB3
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IFrameworkElementStatics5>{ 0x525D3941,0x0B3C,0x4BE6,{ 0x99,0x78,0x19,0xA8,0x02,0x5C,0x09,0xD8 } }; // 525D3941-0B3C-4BE6-9978-19A8025C09D8
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IFrameworkElementStatics6>{ 0xFCC1529A,0x69DB,0x4582,{ 0xA7,0xBE,0xCF,0x6A,0x1C,0xFD,0xAC,0xD0 } }; // FCC1529A-69DB-4582-A7BE-CF6A1CFDACD0
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IFrameworkTemplate>{ 0xA1E254D8,0xA446,0x4A27,{ 0x9A,0x9D,0xA0,0xF5,0x9E,0x12,0x58,0xA5 } }; // A1E254D8-A446-4A27-9A9D-A0F59E1258A5
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IFrameworkTemplateFactory>{ 0x1A78A0A5,0x937D,0x46D4,{ 0x83,0x2B,0x94,0xFF,0x14,0xDA,0xB0,0x61 } }; // 1A78A0A5-937D-46D4-832B-94FF14DAB061
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IFrameworkView>{ 0xDDBA664B,0xB603,0x47AA,{ 0x94,0x2D,0x38,0x33,0x17,0x4F,0x0D,0x80 } }; // DDBA664B-B603-47AA-942D-3833174F0D80
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IFrameworkViewSource>{ 0xE3B077DA,0x35AD,0x4B09,{ 0xB5,0xB2,0x27,0x42,0x00,0x41,0xBA,0x9F } }; // E3B077DA-35AD-4B09-B5B2-27420041BA9F
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IGridLengthHelper>{ 0x7A826CE1,0x07A0,0x4083,{ 0xB6,0xD1,0xB1,0xD9,0x17,0xB9,0x76,0xAC } }; // 7A826CE1-07A0-4083-B6D1-B1D917B976AC
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IGridLengthHelperStatics>{ 0x9D457B9B,0x019F,0x4266,{ 0x88,0x72,0x21,0x5F,0x19,0x8F,0x6A,0x9D } }; // 9D457B9B-019F-4266-8872-215F198F6A9D
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IMediaFailedRoutedEventArgs>{ 0x46D1FA8D,0x5149,0x4153,{ 0xBA,0x3C,0xB0,0x3E,0x64,0xEE,0x53,0x1E } }; // 46D1FA8D-5149-4153-BA3C-B03E64EE531E
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IPointHelper>{ 0x727BDD92,0x64B0,0x49CF,{ 0xA3,0x21,0xA9,0x79,0x3E,0x73,0xE2,0xE7 } }; // 727BDD92-64B0-49CF-A321-A9793E73E2E7
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IPointHelperStatics>{ 0x015ACA75,0x76D8,0x4B7E,{ 0x8A,0x33,0x7D,0x79,0x20,0x46,0x91,0xEE } }; // 015ACA75-76D8-4B7E-8A33-7D79204691EE
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IPropertyMetadata>{ 0x814EF30D,0x8D18,0x448A,{ 0x86,0x44,0xF2,0xCB,0x51,0xE7,0x03,0x80 } }; // 814EF30D-8D18-448A-8644-F2CB51E70380
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IPropertyMetadataFactory>{ 0xC1B81CC0,0x57CD,0x4F2F,{ 0xB0,0xA9,0xE1,0x80,0x1B,0x28,0xF7,0x6B } }; // C1B81CC0-57CD-4F2F-B0A9-E1801B28F76B
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IPropertyMetadataStatics>{ 0x3B01077A,0x6E06,0x45E9,{ 0x8B,0x5C,0xAF,0x24,0x34,0x58,0xC0,0x62 } }; // 3B01077A-6E06-45E9-8B5C-AF243458C062
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IPropertyPath>{ 0x300E5D8A,0x1FF3,0x4D2C,{ 0x95,0xEC,0x27,0xF8,0x1D,0xEB,0xAC,0xB8 } }; // 300E5D8A-1FF3-4D2C-95EC-27F81DEBACB8
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IPropertyPathFactory>{ 0x4E4CDF99,0x9826,0x4E56,{ 0x84,0x7C,0xCA,0x05,0x5F,0x16,0x29,0x05 } }; // 4E4CDF99-9826-4E56-847C-CA055F162905
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IRectHelper>{ 0xA38781E2,0x4BFB,0x4EE2,{ 0xAF,0xE5,0x89,0xF3,0x1B,0x37,0x47,0x8D } }; // A38781E2-4BFB-4EE2-AFE5-89F31B37478D
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IRectHelperStatics>{ 0x5EE163E4,0xC17E,0x494F,{ 0xB5,0x80,0x2F,0x05,0x74,0xFC,0x3A,0x15 } }; // 5EE163E4-C17E-494F-B580-2F0574FC3A15
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IResourceDictionary>{ 0xC1EA4F24,0xD6DE,0x4191,{ 0x8E,0x3A,0xF4,0x86,0x01,0xF7,0x48,0x9C } }; // C1EA4F24-D6DE-4191-8E3A-F48601F7489C
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IResourceDictionaryFactory>{ 0xEA3639B5,0x31B7,0x4271,{ 0x92,0xC9,0x7C,0x95,0x84,0xA9,0x1C,0x22 } }; // EA3639B5-31B7-4271-92C9-7C9584A91C22
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IRoutedEvent>{ 0xA6B25818,0x43C1,0x4C70,{ 0x86,0x5C,0x7B,0xDD,0x5A,0x32,0xE3,0x27 } }; // A6B25818-43C1-4C70-865C-7BDD5A32E327
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IRoutedEventArgs>{ 0x5C985AC6,0xD802,0x4B38,{ 0xA2,0x23,0xBF,0x07,0x0C,0x43,0xFE,0xDF } }; // 5C985AC6-D802-4B38-A223-BF070C43FEDF
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IRoutedEventArgsFactory>{ 0xB61C4D87,0x70E5,0x412E,{ 0xB5,0x20,0x1A,0x41,0xEE,0x76,0xBB,0xF4 } }; // B61C4D87-70E5-412E-B520-1A41EE76BBF4
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IScalarTransition>{ 0x4CB68238,0xE15D,0x524E,{ 0xA7,0x3C,0x9D,0x4D,0xCF,0xBE,0xA2,0x26 } }; // 4CB68238-E15D-524E-A73C-9D4DCFBEA226
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IScalarTransitionFactory>{ 0xC9B1E9EE,0x90DA,0x5DDD,{ 0xBE,0x64,0x3E,0x47,0x97,0x7E,0xA2,0x80 } }; // C9B1E9EE-90DA-5DDD-BE64-3E47977EA280
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::ISetter>{ 0xA73DED29,0xB4AE,0x4A81,{ 0xBE,0x85,0xE6,0x90,0xBA,0x0D,0x3B,0x6E } }; // A73DED29-B4AE-4A81-BE85-E690BA0D3B6E
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::ISetter2>{ 0x70169561,0x05B1,0x4FA3,{ 0x9D,0x53,0x8E,0x0C,0x8C,0x74,0x7A,0xFC } }; // 70169561-05B1-4FA3-9D53-8E0C8C747AFC
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::ISetterBase>{ 0x418BE27C,0x2AC4,0x4F22,{ 0x80,0x97,0xDE,0xA3,0xAE,0xEB,0x2F,0xB3 } }; // 418BE27C-2AC4-4F22-8097-DEA3AEEB2FB3
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::ISetterBaseCollection>{ 0x03C40CA8,0x909E,0x4117,{ 0x81,0x1C,0xA4,0x52,0x94,0x96,0xBD,0xF1 } }; // 03C40CA8-909E-4117-811C-A4529496BDF1
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::ISetterBaseFactory>{ 0x81F8AD60,0x1CE8,0x469D,{ 0xA6,0x67,0x16,0xE3,0x7C,0xEF,0x8B,0xA9 } }; // 81F8AD60-1CE8-469D-A667-16E37CEF8BA9
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::ISetterFactory>{ 0xD3CA3D42,0x09B1,0x49D5,{ 0x88,0x91,0xE7,0xB5,0x64,0x8E,0x02,0xA2 } }; // D3CA3D42-09B1-49D5-8891-E7B5648E02A2
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::ISizeChangedEventArgs>{ 0xD5312E60,0x5CC1,0x42A1,{ 0x92,0x0C,0x1A,0xF4,0x6B,0xE2,0xF9,0x86 } }; // D5312E60-5CC1-42A1-920C-1AF46BE2F986
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::ISizeHelper>{ 0xE7225A94,0x5D03,0x4A03,{ 0xBA,0x94,0x96,0x7F,0xC6,0x8F,0xCE,0xFE } }; // E7225A94-5D03-4A03-BA94-967FC68FCEFE
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::ISizeHelperStatics>{ 0x6286C5B2,0xCF78,0x4915,{ 0xAA,0x40,0x76,0x00,0x4A,0x16,0x5F,0x5E } }; // 6286C5B2-CF78-4915-AA40-76004A165F5E
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IStateTrigger>{ 0x67ADEF2E,0xD8D9,0x49F7,{ 0xA1,0xFD,0x2E,0x35,0xEE,0xDD,0x23,0xCD } }; // 67ADEF2E-D8D9-49F7-A1FD-2E35EEDD23CD
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IStateTriggerBase>{ 0x48B20698,0xAF06,0x466C,{ 0x80,0x52,0x93,0x66,0x6D,0xDE,0x0E,0x49 } }; // 48B20698-AF06-466C-8052-93666DDE0E49
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IStateTriggerBaseFactory>{ 0x970E2C4B,0xBFAF,0x47B0,{ 0xBE,0x42,0xC1,0xD7,0x11,0xBB,0x2E,0x9F } }; // 970E2C4B-BFAF-47B0-BE42-C1D711BB2E9F
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IStateTriggerBaseProtected>{ 0x3C41E253,0x8D14,0x4216,{ 0x99,0x4C,0xF9,0x93,0x04,0x29,0xF6,0xE5 } }; // 3C41E253-8D14-4216-994C-F9930429F6E5
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IStateTriggerStatics>{ 0x71E95C90,0xB3FE,0x4DD3,{ 0xA8,0xA8,0x44,0xA2,0xCE,0x25,0xE0,0xB8 } }; // 71E95C90-B3FE-4DD3-A8A8-44A2CE25E0B8
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IStyle>{ 0xC4A9F225,0x9DB7,0x4A7D,{ 0xB6,0xD1,0xF7,0x4E,0xDB,0x92,0x93,0xC2 } }; // C4A9F225-9DB7-4A7D-B6D1-F74EDB9293C2
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IStyleFactory>{ 0xA36824E3,0x3D81,0x4CE5,{ 0xAA,0x51,0x8B,0x41,0x0F,0x60,0x2F,0xCD } }; // A36824E3-3D81-4CE5-AA51-8B410F602FCD
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::ITargetPropertyPath>{ 0x40740F8E,0x085F,0x4CED,{ 0xBE,0x70,0x6F,0x47,0xAC,0xF1,0x5A,0xD0 } }; // 40740F8E-085F-4CED-BE70-6F47ACF15AD0
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::ITargetPropertyPathFactory>{ 0x88EECCC8,0x99E2,0x4A44,{ 0x99,0x07,0xB4,0x4B,0xC8,0x6E,0x2B,0xBE } }; // 88EECCC8-99E2-4A44-9907-B44BC86E2BBE
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IThicknessHelper>{ 0xA86BAE4B,0x1E8F,0x4EEB,{ 0x90,0x13,0x0B,0x28,0x38,0xA9,0x7B,0x34 } }; // A86BAE4B-1E8F-4EEB-9013-0B2838A97B34
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IThicknessHelperStatics>{ 0xC0991A7C,0x070C,0x4DA6,{ 0x87,0x84,0x01,0xCA,0x80,0x0E,0xB7,0x3A } }; // C0991A7C-070C-4DA6-8784-01CA800EB73A
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::ITriggerAction>{ 0xA2C0DF02,0x63D5,0x4B46,{ 0x9B,0x83,0x08,0x68,0xD3,0x07,0x96,0x21 } }; // A2C0DF02-63D5-4B46-9B83-0868D3079621
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::ITriggerActionFactory>{ 0x68D2C0B9,0x3289,0x414F,{ 0x8F,0x6E,0xC6,0xB9,0x7A,0xED,0xDA,0x03 } }; // 68D2C0B9-3289-414F-8F6E-C6B97AEDDA03
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::ITriggerBase>{ 0xE7EA222F,0xDEE6,0x4393,{ 0xA8,0xB2,0x89,0x23,0xD6,0x41,0xF3,0x95 } }; // E7EA222F-DEE6-4393-A8B2-8923D641F395
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::ITriggerBaseFactory>{ 0x6A3B9E57,0xFC5D,0x42D0,{ 0x8C,0xB9,0xCA,0x50,0x66,0x7A,0xF7,0x46 } }; // 6A3B9E57-FC5D-42D0-8CB9-CA50667AF746
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IUIElement>{ 0x676D0BE9,0xB65C,0x41C6,{ 0xBA,0x40,0x58,0xCF,0x87,0xF2,0x01,0xC1 } }; // 676D0BE9-B65C-41C6-BA40-58CF87F201C1
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IUIElement10>{ 0xD531C629,0xAD2C,0x5F6B,{ 0xAD,0xCF,0xFB,0x87,0x28,0x7D,0x18,0xD7 } }; // D531C629-AD2C-5F6B-ADCF-FB87287D18D7
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IUIElement2>{ 0x676D0BF9,0xB66C,0x41D6,{ 0xBA,0x50,0x58,0xCF,0x87,0xF2,0x01,0xD1 } }; // 676D0BF9-B66C-41D6-BA50-58CF87F201D1
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IUIElement3>{ 0xBC2B28F1,0x26F2,0x4AAB,{ 0xB2,0x56,0x3B,0x53,0x50,0x88,0x1E,0x37 } }; // BC2B28F1-26F2-4AAB-B256-3B5350881E37
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IUIElement4>{ 0x69145CD4,0x199A,0x4657,{ 0x9E,0x57,0xE9,0x9E,0x8F,0x13,0x67,0x12 } }; // 69145CD4-199A-4657-9E57-E99E8F136712
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IUIElement5>{ 0x8EED9BC2,0xA58C,0x4453,{ 0xAF,0x0F,0xA9,0x2E,0xE0,0x6D,0x03,0x17 } }; // 8EED9BC2-A58C-4453-AF0F-A92EE06D0317
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IUIElement7>{ 0xCAFC4968,0x6369,0x4249,{ 0x80,0xF9,0x3D,0x65,0x63,0x19,0xE8,0x11 } }; // CAFC4968-6369-4249-80F9-3D656319E811
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IUIElement8>{ 0x3AB70E85,0xD508,0x4477,{ 0xB6,0xF8,0x0E,0x43,0x57,0x01,0xC8,0x36 } }; // 3AB70E85-D508-4477-B6F8-0E435701C836
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IUIElement9>{ 0xB4A04776,0x4E88,0x50CA,{ 0x8F,0x2B,0x08,0x94,0x0D,0x6C,0x5F,0x94 } }; // B4A04776-4E88-50CA-8F2B-08940D6C5F94
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IUIElementFactory>{ 0xB9EE93FE,0xA338,0x419F,{ 0xAC,0x32,0x91,0xDC,0xAA,0xDF,0x5D,0x08 } }; // B9EE93FE-A338-419F-AC32-91DCAADF5D08
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IUIElementOverrides>{ 0x608D2F1D,0x7858,0x4AEB,{ 0x89,0xE4,0xB5,0x4E,0x2C,0x7E,0xD3,0xD3 } }; // 608D2F1D-7858-4AEB-89E4-B54E2C7ED3D3
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IUIElementOverrides7>{ 0xB97F7F68,0xC29B,0x4C99,{ 0xA1,0xC3,0x95,0x26,0x19,0xD6,0xE7,0x20 } }; // B97F7F68-C29B-4C99-A1C3-952619D6E720
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IUIElementOverrides8>{ 0x4A5A645C,0x548D,0x48CF,{ 0xB9,0x98,0x78,0x44,0xD6,0xE2,0x35,0xA1 } }; // 4A5A645C-548D-48CF-B998-7844D6E235A1
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IUIElementOverrides9>{ 0x9A6E5973,0x6D63,0x54F2,{ 0x90,0xFA,0x62,0x81,0x3B,0x20,0xB7,0xB9 } }; // 9A6E5973-6D63-54F2-90FA-62813B20B7B9
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IUIElementStatics>{ 0x58D3573B,0xF52C,0x45BE,{ 0x98,0x8B,0xA5,0x86,0x95,0x64,0x87,0x3C } }; // 58D3573B-F52C-45BE-988B-A5869564873C
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IUIElementStatics10>{ 0x60D25362,0x4B3E,0x53DA,{ 0x8B,0x78,0x38,0xDB,0x94,0xAE,0x8F,0x26 } }; // 60D25362-4B3E-53DA-8B78-38DB94AE8F26
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IUIElementStatics2>{ 0x58D3574B,0xF53C,0x45BE,{ 0x98,0x9B,0xA5,0x86,0x95,0x64,0x87,0x4C } }; // 58D3574B-F53C-45BE-989B-A5869564874C
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IUIElementStatics3>{ 0xD1F87ADE,0xECA1,0x4561,{ 0xA3,0x2B,0x64,0x60,0x1B,0x4E,0x05,0x97 } }; // D1F87ADE-ECA1-4561-A32B-64601B4E0597
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IUIElementStatics4>{ 0x1D157D61,0x16AF,0x411F,{ 0xB7,0x74,0x27,0x23,0x75,0xA4,0xAC,0x2C } }; // 1D157D61-16AF-411F-B774-272375A4AC2C
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IUIElementStatics5>{ 0x59BD7D91,0x8FA3,0x4C65,{ 0xBA,0x1B,0x40,0xDF,0x38,0x55,0x6C,0xBB } }; // 59BD7D91-8FA3-4C65-BA1B-40DF38556CBB
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IUIElementStatics6>{ 0x647E03B7,0x036A,0x4DEA,{ 0x95,0x40,0x1D,0xD7,0xFD,0x12,0x66,0xF1 } }; // 647E03B7-036A-4DEA-9540-1DD7FD1266F1
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IUIElementStatics7>{ 0xDA9B4493,0xA695,0x4145,{ 0xAE,0x93,0x88,0x80,0x24,0x39,0x6A,0x0F } }; // DA9B4493-A695-4145-AE93-888024396A0F
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IUIElementStatics8>{ 0x17BE3487,0x4875,0x4915,{ 0xB0,0xB1,0xA4,0xC0,0xF8,0x51,0xDF,0x3F } }; // 17BE3487-4875-4915-B0B1-A4C0F851DF3F
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IUIElementStatics9>{ 0x71467E77,0x8CA3,0x5ED7,{ 0x95,0xDB,0xD5,0x1C,0xDA,0xD7,0x7F,0x81 } }; // 71467E77-8CA3-5ED7-95DB-D51CDAD77F81
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IUIElementWeakCollection>{ 0x10341223,0xE66D,0x519E,{ 0xAC,0xF8,0x55,0x6B,0xD2,0x44,0xEA,0xC3 } }; // 10341223-E66D-519E-ACF8-556BD244EAC3
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IUIElementWeakCollectionFactory>{ 0x57242561,0x188A,0x5304,{ 0x87,0x92,0xA4,0x3F,0x35,0xD9,0x0F,0x99 } }; // 57242561-188A-5304-8792-A43F35D90F99
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IUnhandledExceptionEventArgs>{ 0x7230269C,0x054E,0x4CF3,{ 0x86,0xC5,0xBE,0x90,0xEB,0x68,0x63,0xD5 } }; // 7230269C-054E-4CF3-86C5-BE90EB6863D5
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IVector3Transition>{ 0xD2E209DC,0xC4A2,0x5101,{ 0x9A,0x68,0xFA,0x01,0x50,0x50,0x55,0x89 } }; // D2E209DC-C4A2-5101-9A68-FA0150505589
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IVector3TransitionFactory>{ 0xC3706699,0xEE9B,0x50DC,{ 0x88,0x07,0xF5,0x1D,0x5A,0x75,0x94,0x95 } }; // C3706699-EE9B-50DC-8807-F51D5A759495
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IVisualState>{ 0x6320AFFC,0xC31A,0x4450,{ 0xAF,0xDE,0xF6,0xEA,0x7B,0xD1,0xF5,0x86 } }; // 6320AFFC-C31A-4450-AFDE-F6EA7BD1F586
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IVisualState2>{ 0x0FA0F896,0x64C0,0x45FB,{ 0x8D,0x24,0xFB,0x83,0x29,0x8C,0x0D,0x93 } }; // 0FA0F896-64C0-45FB-8D24-FB83298C0D93
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IVisualStateChangedEventArgs>{ 0xFE216AB1,0xF31F,0x4791,{ 0x89,0x89,0xC7,0x0E,0x1D,0x9B,0x59,0xFF } }; // FE216AB1-F31F-4791-8989-C70E1D9B59FF
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IVisualStateGroup>{ 0xE4F9D9A4,0xE028,0x44DE,{ 0x9B,0x15,0x49,0x29,0xAE,0x0A,0x26,0xC2 } }; // E4F9D9A4-E028-44DE-9B15-4929AE0A26C2
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IVisualStateManager>{ 0x6FDA9F9A,0x6FAB,0x4112,{ 0x92,0x58,0x10,0x06,0xA3,0xC3,0x47,0x6E } }; // 6FDA9F9A-6FAB-4112-9258-1006A3C3476E
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IVisualStateManagerFactory>{ 0x85E598FD,0xA575,0x47B6,{ 0x9E,0x30,0x38,0x3C,0xD0,0x85,0x85,0xF2 } }; // 85E598FD-A575-47B6-9E30-383CD08585F2
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IVisualStateManagerOverrides>{ 0x4A66910E,0x7979,0x43C8,{ 0x8F,0xF4,0xEC,0x61,0x22,0x75,0x00,0x06 } }; // 4A66910E-7979-43C8-8FF4-EC6122750006
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IVisualStateManagerProtected>{ 0x4B3B8640,0xB0B7,0x404C,{ 0x9E,0xF4,0xD9,0x49,0x64,0x0E,0x24,0x5D } }; // 4B3B8640-B0B7-404C-9EF4-D949640E245D
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IVisualStateManagerStatics>{ 0x01D0E9E0,0xD713,0x414E,{ 0xA7,0x4E,0xE6,0x3E,0xC7,0xAC,0x8C,0x3D } }; // 01D0E9E0-D713-414E-A74E-E63EC7AC8C3D
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IVisualTransition>{ 0x55C5905E,0x2BC7,0x400D,{ 0xAA,0xA4,0x1A,0x29,0x81,0x49,0x1E,0xE0 } }; // 55C5905E-2BC7-400D-AAA4-1A2981491EE0
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IVisualTransitionFactory>{ 0xEA75864F,0xD1E0,0x4DAE,{ 0xB4,0x29,0x89,0xFC,0x32,0x27,0x24,0xF4 } }; // EA75864F-D1E0-4DAE-B429-89FC322724F4
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IWindow>{ 0x3276167D,0xC9F6,0x462D,{ 0x9D,0xE2,0xAE,0x4C,0x1F,0xD8,0xC2,0xE5 } }; // 3276167D-C9F6-462D-9DE2-AE4C1FD8C2E5
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IWindow2>{ 0xD384759F,0x34F6,0x4482,{ 0x84,0x35,0xF5,0x52,0xF9,0xB2,0x4C,0xC8 } }; // D384759F-34F6-4482-8435-F552F9B24CC8
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IWindow3>{ 0xB70BDC9D,0x1C35,0x462A,{ 0x9B,0x97,0x80,0x8D,0x5A,0xF9,0xF2,0x8E } }; // B70BDC9D-1C35-462A-9B97-808D5AF9F28E
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IWindow4>{ 0xBFE1B8CE,0x6C40,0x50F9,{ 0x85,0x4C,0x70,0x21,0xD2,0xBC,0x9D,0xE6 } }; // BFE1B8CE-6C40-50F9-854C-7021D2BC9DE6
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IWindowCreatedEventArgs>{ 0x31B71470,0xFEFF,0x4654,{ 0xAF,0x48,0x9B,0x39,0x8A,0xB5,0x77,0x2B } }; // 31B71470-FEFF-4654-AF48-9B398AB5772B
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IWindowStatics>{ 0x93328409,0x4EA1,0x4AFA,{ 0x83,0xDC,0x0C,0x4E,0x73,0xE8,0x8B,0xB1 } }; // 93328409-4EA1-4AFA-83DC-0C4E73E88BB1
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IXamlRoot>{ 0x34B50756,0x1696,0x5B6D,{ 0x8E,0x9B,0xC7,0x14,0x64,0xCC,0xAD,0x5A } }; // 34B50756-1696-5B6D-8E9B-C71464CCAD5A
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::IXamlRootChangedEventArgs>{ 0x92D71C21,0xD23C,0x5A17,{ 0xBC,0xB8,0x00,0x15,0x04,0xB6,0xBB,0x19 } }; // 92D71C21-D23C-5A17-BCB8-001504B6BB19
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::ApplicationInitializationCallback>{ 0xB6351C55,0xC284,0x46E4,{ 0x83,0x10,0xFB,0x09,0x67,0xFA,0xB7,0x6F } }; // B6351C55-C284-46E4-8310-FB0967FAB76F
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::BindingFailedEventHandler>{ 0x136B1782,0x54BA,0x420D,{ 0xA1,0xAA,0x82,0x82,0x87,0x21,0xCD,0xE6 } }; // 136B1782-54BA-420D-A1AA-82828721CDE6
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::CreateDefaultValueCallback>{ 0xD6ECB12C,0x15B5,0x4EC8,{ 0xB9,0x5C,0xCD,0xD2,0x08,0xF0,0x81,0x53 } }; // D6ECB12C-15B5-4EC8-B95C-CDD208F08153
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::DependencyPropertyChangedCallback>{ 0x45883D16,0x27BF,0x4BC1,{ 0xAC,0x26,0x94,0xC1,0x60,0x1F,0x3A,0x49 } }; // 45883D16-27BF-4BC1-AC26-94C1601F3A49
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::DependencyPropertyChangedEventHandler>{ 0x09223E5A,0x75BE,0x4499,{ 0x81,0x80,0x1D,0xDC,0x00,0x54,0x21,0xC0 } }; // 09223E5A-75BE-4499-8180-1DDC005421C0
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::DragEventHandler>{ 0x2AB1A205,0x1E73,0x4BCF,{ 0xAA,0xBC,0x57,0xB9,0x7E,0x21,0x96,0x1D } }; // 2AB1A205-1E73-4BCF-AABC-57B97E21961D
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::EnteredBackgroundEventHandler>{ 0x93A956AE,0x1D7F,0x438B,{ 0xB7,0xB8,0x22,0x7D,0x96,0xB6,0x09,0xC0 } }; // 93A956AE-1D7F-438B-B7B8-227D96B609C0
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::ExceptionRoutedEventHandler>{ 0x68E0E810,0xF6EA,0x42BC,{ 0x85,0x5B,0x5D,0x9B,0x67,0xE6,0xA2,0x62 } }; // 68E0E810-F6EA-42BC-855B-5D9B67E6A262
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::LeavingBackgroundEventHandler>{ 0xAAAD5DAD,0x4FC6,0x4AA4,{ 0xB7,0xCF,0x87,0x7E,0x36,0xAD,0xA4,0xF6 } }; // AAAD5DAD-4FC6-4AA4-B7CF-877E36ADA4F6
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::PropertyChangedCallback>{ 0x5A9F8A25,0xD142,0x44A4,{ 0x82,0x31,0xFD,0x67,0x67,0x24,0xF2,0x9B } }; // 5A9F8A25-D142-44A4-8231-FD676724F29B
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::RoutedEventHandler>{ 0xA856E674,0xB0B6,0x4BC3,{ 0xBB,0xA8,0x1B,0xA0,0x6E,0x40,0xD4,0xB5 } }; // A856E674-B0B6-4BC3-BBA8-1BA06E40D4B5
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::SizeChangedEventHandler>{ 0x1115B13C,0x25D2,0x480B,{ 0x89,0xDC,0xEB,0x3D,0xCB,0xD6,0xB7,0xFA } }; // 1115B13C-25D2-480B-89DC-EB3DCBD6B7FA
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::SuspendingEventHandler>{ 0x23429465,0xE36A,0x40E2,{ 0xB1,0x39,0xA4,0x70,0x46,0x02,0xA6,0xE1 } }; // 23429465-E36A-40E2-B139-A4704602A6E1
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::UnhandledExceptionEventHandler>{ 0x9274E6BD,0x49A1,0x4958,{ 0xBE,0xEE,0xD0,0xE1,0x95,0x87,0xB6,0xE3 } }; // 9274E6BD-49A1-4958-BEEE-D0E19587B6E3
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::VisualStateChangedEventHandler>{ 0xE6D5BBD5,0xE029,0x43A6,{ 0xB3,0x6D,0x84,0xA8,0x10,0x42,0xD7,0x74 } }; // E6D5BBD5-E029-43A6-B36D-84A81042D774
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::WindowActivatedEventHandler>{ 0x18026348,0x8619,0x4C7B,{ 0xB5,0x34,0xCE,0xD4,0x5D,0x9D,0xE2,0x19 } }; // 18026348-8619-4C7B-B534-CED45D9DE219
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::WindowClosedEventHandler>{ 0x0DB89161,0x20D7,0x45DF,{ 0x91,0x22,0xBA,0x89,0x57,0x67,0x03,0xBA } }; // 0DB89161-20D7-45DF-9122-BA89576703BA
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::WindowSizeChangedEventHandler>{ 0x5C21C742,0x2CED,0x4FD9,{ 0xBA,0x38,0x71,0x18,0xD4,0x0E,0x96,0x6B } }; // 5C21C742-2CED-4FD9-BA38-7118D40E966B
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::WindowVisibilityChangedEventHandler>{ 0x10406AD6,0xB090,0x4A4A,{ 0xB2,0xAD,0xD6,0x82,0xDF,0x27,0x13,0x0F } }; // 10406AD6-B090-4A4A-B2AD-D682DF27130F
    template <> struct default_interface<llm::OS::UI::Xaml::AdaptiveTrigger>{ using type = llm::OS::UI::Xaml::IAdaptiveTrigger; };
    template <> struct default_interface<llm::OS::UI::Xaml::Application>{ using type = llm::OS::UI::Xaml::IApplication; };
    template <> struct default_interface<llm::OS::UI::Xaml::ApplicationInitializationCallbackParams>{ using type = llm::OS::UI::Xaml::IApplicationInitializationCallbackParams; };
    template <> struct default_interface<llm::OS::UI::Xaml::BindingFailedEventArgs>{ using type = llm::OS::UI::Xaml::IBindingFailedEventArgs; };
    template <> struct default_interface<llm::OS::UI::Xaml::BringIntoViewOptions>{ using type = llm::OS::UI::Xaml::IBringIntoViewOptions; };
    template <> struct default_interface<llm::OS::UI::Xaml::BringIntoViewRequestedEventArgs>{ using type = llm::OS::UI::Xaml::IBringIntoViewRequestedEventArgs; };
    template <> struct default_interface<llm::OS::UI::Xaml::BrushTransition>{ using type = llm::OS::UI::Xaml::IBrushTransition; };
    template <> struct default_interface<llm::OS::UI::Xaml::ColorPaletteResources>{ using type = llm::OS::UI::Xaml::IColorPaletteResources; };
    template <> struct default_interface<llm::OS::UI::Xaml::CornerRadiusHelper>{ using type = llm::OS::UI::Xaml::ICornerRadiusHelper; };
    template <> struct default_interface<llm::OS::UI::Xaml::DataContextChangedEventArgs>{ using type = llm::OS::UI::Xaml::IDataContextChangedEventArgs; };
    template <> struct default_interface<llm::OS::UI::Xaml::DataTemplate>{ using type = llm::OS::UI::Xaml::IDataTemplate; };
    template <> struct default_interface<llm::OS::UI::Xaml::DataTemplateKey>{ using type = llm::OS::UI::Xaml::IDataTemplateKey; };
    template <> struct default_interface<llm::OS::UI::Xaml::DebugSettings>{ using type = llm::OS::UI::Xaml::IDebugSettings; };
    template <> struct default_interface<llm::OS::UI::Xaml::DependencyObject>{ using type = llm::OS::UI::Xaml::IDependencyObject; };
    template <> struct default_interface<llm::OS::UI::Xaml::DependencyObjectCollection>{ using type = llm::OS::Foundation::Collections::IObservableVector<llm::OS::UI::Xaml::DependencyObject>; };
    template <> struct default_interface<llm::OS::UI::Xaml::DependencyProperty>{ using type = llm::OS::UI::Xaml::IDependencyProperty; };
    template <> struct default_interface<llm::OS::UI::Xaml::DependencyPropertyChangedEventArgs>{ using type = llm::OS::UI::Xaml::IDependencyPropertyChangedEventArgs; };
    template <> struct default_interface<llm::OS::UI::Xaml::DispatcherTimer>{ using type = llm::OS::UI::Xaml::IDispatcherTimer; };
    template <> struct default_interface<llm::OS::UI::Xaml::DragEventArgs>{ using type = llm::OS::UI::Xaml::IDragEventArgs; };
    template <> struct default_interface<llm::OS::UI::Xaml::DragOperationDeferral>{ using type = llm::OS::UI::Xaml::IDragOperationDeferral; };
    template <> struct default_interface<llm::OS::UI::Xaml::DragStartingEventArgs>{ using type = llm::OS::UI::Xaml::IDragStartingEventArgs; };
    template <> struct default_interface<llm::OS::UI::Xaml::DragUI>{ using type = llm::OS::UI::Xaml::IDragUI; };
    template <> struct default_interface<llm::OS::UI::Xaml::DragUIOverride>{ using type = llm::OS::UI::Xaml::IDragUIOverride; };
    template <> struct default_interface<llm::OS::UI::Xaml::DropCompletedEventArgs>{ using type = llm::OS::UI::Xaml::IDropCompletedEventArgs; };
    template <> struct default_interface<llm::OS::UI::Xaml::DurationHelper>{ using type = llm::OS::UI::Xaml::IDurationHelper; };
    template <> struct default_interface<llm::OS::UI::Xaml::EffectiveViewportChangedEventArgs>{ using type = llm::OS::UI::Xaml::IEffectiveViewportChangedEventArgs; };
    template <> struct default_interface<llm::OS::UI::Xaml::ElementFactoryGetArgs>{ using type = llm::OS::UI::Xaml::IElementFactoryGetArgs; };
    template <> struct default_interface<llm::OS::UI::Xaml::ElementFactoryRecycleArgs>{ using type = llm::OS::UI::Xaml::IElementFactoryRecycleArgs; };
    template <> struct default_interface<llm::OS::UI::Xaml::ElementSoundPlayer>{ using type = llm::OS::UI::Xaml::IElementSoundPlayer; };
    template <> struct default_interface<llm::OS::UI::Xaml::EventTrigger>{ using type = llm::OS::UI::Xaml::IEventTrigger; };
    template <> struct default_interface<llm::OS::UI::Xaml::ExceptionRoutedEventArgs>{ using type = llm::OS::UI::Xaml::IExceptionRoutedEventArgs; };
    template <> struct default_interface<llm::OS::UI::Xaml::FrameworkElement>{ using type = llm::OS::UI::Xaml::IFrameworkElement; };
    template <> struct default_interface<llm::OS::UI::Xaml::FrameworkTemplate>{ using type = llm::OS::UI::Xaml::IFrameworkTemplate; };
    template <> struct default_interface<llm::OS::UI::Xaml::FrameworkView>{ using type = llm::OS::UI::Xaml::IFrameworkView; };
    template <> struct default_interface<llm::OS::UI::Xaml::FrameworkViewSource>{ using type = llm::OS::UI::Xaml::IFrameworkViewSource; };
    template <> struct default_interface<llm::OS::UI::Xaml::GridLengthHelper>{ using type = llm::OS::UI::Xaml::IGridLengthHelper; };
    template <> struct default_interface<llm::OS::UI::Xaml::MediaFailedRoutedEventArgs>{ using type = llm::OS::UI::Xaml::IMediaFailedRoutedEventArgs; };
    template <> struct default_interface<llm::OS::UI::Xaml::PointHelper>{ using type = llm::OS::UI::Xaml::IPointHelper; };
    template <> struct default_interface<llm::OS::UI::Xaml::PropertyMetadata>{ using type = llm::OS::UI::Xaml::IPropertyMetadata; };
    template <> struct default_interface<llm::OS::UI::Xaml::PropertyPath>{ using type = llm::OS::UI::Xaml::IPropertyPath; };
    template <> struct default_interface<llm::OS::UI::Xaml::RectHelper>{ using type = llm::OS::UI::Xaml::IRectHelper; };
    template <> struct default_interface<llm::OS::UI::Xaml::ResourceDictionary>{ using type = llm::OS::UI::Xaml::IResourceDictionary; };
    template <> struct default_interface<llm::OS::UI::Xaml::RoutedEvent>{ using type = llm::OS::UI::Xaml::IRoutedEvent; };
    template <> struct default_interface<llm::OS::UI::Xaml::RoutedEventArgs>{ using type = llm::OS::UI::Xaml::IRoutedEventArgs; };
    template <> struct default_interface<llm::OS::UI::Xaml::ScalarTransition>{ using type = llm::OS::UI::Xaml::IScalarTransition; };
    template <> struct default_interface<llm::OS::UI::Xaml::Setter>{ using type = llm::OS::UI::Xaml::ISetter; };
    template <> struct default_interface<llm::OS::UI::Xaml::SetterBase>{ using type = llm::OS::UI::Xaml::ISetterBase; };
    template <> struct default_interface<llm::OS::UI::Xaml::SetterBaseCollection>{ using type = llm::OS::UI::Xaml::ISetterBaseCollection; };
    template <> struct default_interface<llm::OS::UI::Xaml::SizeChangedEventArgs>{ using type = llm::OS::UI::Xaml::ISizeChangedEventArgs; };
    template <> struct default_interface<llm::OS::UI::Xaml::SizeHelper>{ using type = llm::OS::UI::Xaml::ISizeHelper; };
    template <> struct default_interface<llm::OS::UI::Xaml::StateTrigger>{ using type = llm::OS::UI::Xaml::IStateTrigger; };
    template <> struct default_interface<llm::OS::UI::Xaml::StateTriggerBase>{ using type = llm::OS::UI::Xaml::IStateTriggerBase; };
    template <> struct default_interface<llm::OS::UI::Xaml::Style>{ using type = llm::OS::UI::Xaml::IStyle; };
    template <> struct default_interface<llm::OS::UI::Xaml::TargetPropertyPath>{ using type = llm::OS::UI::Xaml::ITargetPropertyPath; };
    template <> struct default_interface<llm::OS::UI::Xaml::ThicknessHelper>{ using type = llm::OS::UI::Xaml::IThicknessHelper; };
    template <> struct default_interface<llm::OS::UI::Xaml::TriggerAction>{ using type = llm::OS::UI::Xaml::ITriggerAction; };
    template <> struct default_interface<llm::OS::UI::Xaml::TriggerActionCollection>{ using type = llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::TriggerAction>; };
    template <> struct default_interface<llm::OS::UI::Xaml::TriggerBase>{ using type = llm::OS::UI::Xaml::ITriggerBase; };
    template <> struct default_interface<llm::OS::UI::Xaml::TriggerCollection>{ using type = llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::TriggerBase>; };
    template <> struct default_interface<llm::OS::UI::Xaml::UIElement>{ using type = llm::OS::UI::Xaml::IUIElement; };
    template <> struct default_interface<llm::OS::UI::Xaml::UIElementWeakCollection>{ using type = llm::OS::UI::Xaml::IUIElementWeakCollection; };
    template <> struct default_interface<llm::OS::UI::Xaml::UnhandledExceptionEventArgs>{ using type = llm::OS::UI::Xaml::IUnhandledExceptionEventArgs; };
    template <> struct default_interface<llm::OS::UI::Xaml::Vector3Transition>{ using type = llm::OS::UI::Xaml::IVector3Transition; };
    template <> struct default_interface<llm::OS::UI::Xaml::VisualState>{ using type = llm::OS::UI::Xaml::IVisualState; };
    template <> struct default_interface<llm::OS::UI::Xaml::VisualStateChangedEventArgs>{ using type = llm::OS::UI::Xaml::IVisualStateChangedEventArgs; };
    template <> struct default_interface<llm::OS::UI::Xaml::VisualStateGroup>{ using type = llm::OS::UI::Xaml::IVisualStateGroup; };
    template <> struct default_interface<llm::OS::UI::Xaml::VisualStateManager>{ using type = llm::OS::UI::Xaml::IVisualStateManager; };
    template <> struct default_interface<llm::OS::UI::Xaml::VisualTransition>{ using type = llm::OS::UI::Xaml::IVisualTransition; };
    template <> struct default_interface<llm::OS::UI::Xaml::Window>{ using type = llm::OS::UI::Xaml::IWindow; };
    template <> struct default_interface<llm::OS::UI::Xaml::WindowCreatedEventArgs>{ using type = llm::OS::UI::Xaml::IWindowCreatedEventArgs; };
    template <> struct default_interface<llm::OS::UI::Xaml::XamlRoot>{ using type = llm::OS::UI::Xaml::IXamlRoot; };
    template <> struct default_interface<llm::OS::UI::Xaml::XamlRootChangedEventArgs>{ using type = llm::OS::UI::Xaml::IXamlRootChangedEventArgs; };
    template <> struct abi<llm::OS::UI::Xaml::IAdaptiveTrigger>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_MinWindowWidth(double*) noexcept = 0;
            virtual int32_t __stdcall put_MinWindowWidth(double) noexcept = 0;
            virtual int32_t __stdcall get_MinWindowHeight(double*) noexcept = 0;
            virtual int32_t __stdcall put_MinWindowHeight(double) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IAdaptiveTriggerFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(void*, void**, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IAdaptiveTriggerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_MinWindowWidthProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_MinWindowHeightProperty(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IApplication>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Resources(void**) noexcept = 0;
            virtual int32_t __stdcall put_Resources(void*) noexcept = 0;
            virtual int32_t __stdcall get_DebugSettings(void**) noexcept = 0;
            virtual int32_t __stdcall get_RequestedTheme(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_RequestedTheme(int32_t) noexcept = 0;
            virtual int32_t __stdcall add_UnhandledException(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_UnhandledException(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Suspending(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Suspending(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Resuming(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Resuming(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall Exit() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IApplication2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_FocusVisualKind(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_FocusVisualKind(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_RequiresPointerMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_RequiresPointerMode(int32_t) noexcept = 0;
            virtual int32_t __stdcall add_LeavingBackground(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_LeavingBackground(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_EnteredBackground(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_EnteredBackground(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IApplication3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_HighContrastAdjustment(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_HighContrastAdjustment(uint32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IApplicationFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(void*, void**, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IApplicationInitializationCallbackParams>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IApplicationOverrides>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall OnActivated(void*) noexcept = 0;
            virtual int32_t __stdcall OnLaunched(void*) noexcept = 0;
            virtual int32_t __stdcall OnFileActivated(void*) noexcept = 0;
            virtual int32_t __stdcall OnSearchActivated(void*) noexcept = 0;
            virtual int32_t __stdcall OnShareTargetActivated(void*) noexcept = 0;
            virtual int32_t __stdcall OnFileOpenPickerActivated(void*) noexcept = 0;
            virtual int32_t __stdcall OnFileSavePickerActivated(void*) noexcept = 0;
            virtual int32_t __stdcall OnCachedFileUpdaterActivated(void*) noexcept = 0;
            virtual int32_t __stdcall OnWindowCreated(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IApplicationOverrides2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall OnBackgroundActivated(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IApplicationStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Current(void**) noexcept = 0;
            virtual int32_t __stdcall Start(void*) noexcept = 0;
            virtual int32_t __stdcall LoadComponent(void*, void*) noexcept = 0;
            virtual int32_t __stdcall LoadComponentWithResourceLocation(void*, void*, int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IBindingFailedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Message(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IBringIntoViewOptions>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AnimationDesired(bool*) noexcept = 0;
            virtual int32_t __stdcall put_AnimationDesired(bool) noexcept = 0;
            virtual int32_t __stdcall get_TargetRect(void**) noexcept = 0;
            virtual int32_t __stdcall put_TargetRect(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IBringIntoViewOptions2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_HorizontalAlignmentRatio(double*) noexcept = 0;
            virtual int32_t __stdcall put_HorizontalAlignmentRatio(double) noexcept = 0;
            virtual int32_t __stdcall get_VerticalAlignmentRatio(double*) noexcept = 0;
            virtual int32_t __stdcall put_VerticalAlignmentRatio(double) noexcept = 0;
            virtual int32_t __stdcall get_HorizontalOffset(double*) noexcept = 0;
            virtual int32_t __stdcall put_HorizontalOffset(double) noexcept = 0;
            virtual int32_t __stdcall get_VerticalOffset(double*) noexcept = 0;
            virtual int32_t __stdcall put_VerticalOffset(double) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IBringIntoViewRequestedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_TargetElement(void**) noexcept = 0;
            virtual int32_t __stdcall put_TargetElement(void*) noexcept = 0;
            virtual int32_t __stdcall get_AnimationDesired(bool*) noexcept = 0;
            virtual int32_t __stdcall put_AnimationDesired(bool) noexcept = 0;
            virtual int32_t __stdcall get_TargetRect(llm::OS::Foundation::Rect*) noexcept = 0;
            virtual int32_t __stdcall put_TargetRect(llm::OS::Foundation::Rect) noexcept = 0;
            virtual int32_t __stdcall get_HorizontalAlignmentRatio(double*) noexcept = 0;
            virtual int32_t __stdcall get_VerticalAlignmentRatio(double*) noexcept = 0;
            virtual int32_t __stdcall get_HorizontalOffset(double*) noexcept = 0;
            virtual int32_t __stdcall put_HorizontalOffset(double) noexcept = 0;
            virtual int32_t __stdcall get_VerticalOffset(double*) noexcept = 0;
            virtual int32_t __stdcall put_VerticalOffset(double) noexcept = 0;
            virtual int32_t __stdcall get_Handled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_Handled(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IBrushTransition>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Duration(int64_t*) noexcept = 0;
            virtual int32_t __stdcall put_Duration(int64_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IBrushTransitionFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(void*, void**, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IColorPaletteResources>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AltHigh(void**) noexcept = 0;
            virtual int32_t __stdcall put_AltHigh(void*) noexcept = 0;
            virtual int32_t __stdcall get_AltLow(void**) noexcept = 0;
            virtual int32_t __stdcall put_AltLow(void*) noexcept = 0;
            virtual int32_t __stdcall get_AltMedium(void**) noexcept = 0;
            virtual int32_t __stdcall put_AltMedium(void*) noexcept = 0;
            virtual int32_t __stdcall get_AltMediumHigh(void**) noexcept = 0;
            virtual int32_t __stdcall put_AltMediumHigh(void*) noexcept = 0;
            virtual int32_t __stdcall get_AltMediumLow(void**) noexcept = 0;
            virtual int32_t __stdcall put_AltMediumLow(void*) noexcept = 0;
            virtual int32_t __stdcall get_BaseHigh(void**) noexcept = 0;
            virtual int32_t __stdcall put_BaseHigh(void*) noexcept = 0;
            virtual int32_t __stdcall get_BaseLow(void**) noexcept = 0;
            virtual int32_t __stdcall put_BaseLow(void*) noexcept = 0;
            virtual int32_t __stdcall get_BaseMedium(void**) noexcept = 0;
            virtual int32_t __stdcall put_BaseMedium(void*) noexcept = 0;
            virtual int32_t __stdcall get_BaseMediumHigh(void**) noexcept = 0;
            virtual int32_t __stdcall put_BaseMediumHigh(void*) noexcept = 0;
            virtual int32_t __stdcall get_BaseMediumLow(void**) noexcept = 0;
            virtual int32_t __stdcall put_BaseMediumLow(void*) noexcept = 0;
            virtual int32_t __stdcall get_ChromeAltLow(void**) noexcept = 0;
            virtual int32_t __stdcall put_ChromeAltLow(void*) noexcept = 0;
            virtual int32_t __stdcall get_ChromeBlackHigh(void**) noexcept = 0;
            virtual int32_t __stdcall put_ChromeBlackHigh(void*) noexcept = 0;
            virtual int32_t __stdcall get_ChromeBlackLow(void**) noexcept = 0;
            virtual int32_t __stdcall put_ChromeBlackLow(void*) noexcept = 0;
            virtual int32_t __stdcall get_ChromeBlackMediumLow(void**) noexcept = 0;
            virtual int32_t __stdcall put_ChromeBlackMediumLow(void*) noexcept = 0;
            virtual int32_t __stdcall get_ChromeBlackMedium(void**) noexcept = 0;
            virtual int32_t __stdcall put_ChromeBlackMedium(void*) noexcept = 0;
            virtual int32_t __stdcall get_ChromeDisabledHigh(void**) noexcept = 0;
            virtual int32_t __stdcall put_ChromeDisabledHigh(void*) noexcept = 0;
            virtual int32_t __stdcall get_ChromeDisabledLow(void**) noexcept = 0;
            virtual int32_t __stdcall put_ChromeDisabledLow(void*) noexcept = 0;
            virtual int32_t __stdcall get_ChromeHigh(void**) noexcept = 0;
            virtual int32_t __stdcall put_ChromeHigh(void*) noexcept = 0;
            virtual int32_t __stdcall get_ChromeLow(void**) noexcept = 0;
            virtual int32_t __stdcall put_ChromeLow(void*) noexcept = 0;
            virtual int32_t __stdcall get_ChromeMedium(void**) noexcept = 0;
            virtual int32_t __stdcall put_ChromeMedium(void*) noexcept = 0;
            virtual int32_t __stdcall get_ChromeMediumLow(void**) noexcept = 0;
            virtual int32_t __stdcall put_ChromeMediumLow(void*) noexcept = 0;
            virtual int32_t __stdcall get_ChromeWhite(void**) noexcept = 0;
            virtual int32_t __stdcall put_ChromeWhite(void*) noexcept = 0;
            virtual int32_t __stdcall get_ChromeGray(void**) noexcept = 0;
            virtual int32_t __stdcall put_ChromeGray(void*) noexcept = 0;
            virtual int32_t __stdcall get_ListLow(void**) noexcept = 0;
            virtual int32_t __stdcall put_ListLow(void*) noexcept = 0;
            virtual int32_t __stdcall get_ListMedium(void**) noexcept = 0;
            virtual int32_t __stdcall put_ListMedium(void*) noexcept = 0;
            virtual int32_t __stdcall get_ErrorText(void**) noexcept = 0;
            virtual int32_t __stdcall put_ErrorText(void*) noexcept = 0;
            virtual int32_t __stdcall get_Accent(void**) noexcept = 0;
            virtual int32_t __stdcall put_Accent(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IColorPaletteResourcesFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(void*, void**, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::ICornerRadiusHelper>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::ICornerRadiusHelperStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FromRadii(double, double, double, double, struct struct_Windows_UI_Xaml_CornerRadius*) noexcept = 0;
            virtual int32_t __stdcall FromUniformRadius(double, struct struct_Windows_UI_Xaml_CornerRadius*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IDataContextChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_NewValue(void**) noexcept = 0;
            virtual int32_t __stdcall get_Handled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_Handled(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IDataTemplate>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall LoadContent(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IDataTemplateExtension>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall ResetTemplate() noexcept = 0;
            virtual int32_t __stdcall ProcessBinding(uint32_t, bool*) noexcept = 0;
            virtual int32_t __stdcall ProcessBindings(void*, int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IDataTemplateFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(void*, void**, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IDataTemplateKey>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DataType(void**) noexcept = 0;
            virtual int32_t __stdcall put_DataType(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IDataTemplateKeyFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(void*, void**, void**) noexcept = 0;
            virtual int32_t __stdcall CreateInstanceWithType(void*, void*, void**, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IDataTemplateStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ExtensionInstanceProperty(void**) noexcept = 0;
            virtual int32_t __stdcall GetExtensionInstance(void*, void**) noexcept = 0;
            virtual int32_t __stdcall SetExtensionInstance(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IDebugSettings>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_EnableFrameRateCounter(bool*) noexcept = 0;
            virtual int32_t __stdcall put_EnableFrameRateCounter(bool) noexcept = 0;
            virtual int32_t __stdcall get_IsBindingTracingEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsBindingTracingEnabled(bool) noexcept = 0;
            virtual int32_t __stdcall get_IsOverdrawHeatMapEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsOverdrawHeatMapEnabled(bool) noexcept = 0;
            virtual int32_t __stdcall add_BindingFailed(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_BindingFailed(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IDebugSettings2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_EnableRedrawRegions(bool*) noexcept = 0;
            virtual int32_t __stdcall put_EnableRedrawRegions(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IDebugSettings3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsTextPerformanceVisualizationEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsTextPerformanceVisualizationEnabled(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IDebugSettings4>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_FailFastOnErrors(bool*) noexcept = 0;
            virtual int32_t __stdcall put_FailFastOnErrors(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IDependencyObject>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetValue(void*, void**) noexcept = 0;
            virtual int32_t __stdcall SetValue(void*, void*) noexcept = 0;
            virtual int32_t __stdcall ClearValue(void*) noexcept = 0;
            virtual int32_t __stdcall ReadLocalValue(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetAnimationBaseValue(void*, void**) noexcept = 0;
            virtual int32_t __stdcall get_Dispatcher(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IDependencyObject2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RegisterPropertyChangedCallback(void*, void*, int64_t*) noexcept = 0;
            virtual int32_t __stdcall UnregisterPropertyChangedCallback(void*, int64_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IDependencyObjectCollectionFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(void*, void**, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IDependencyObjectFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(void*, void**, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IDependencyProperty>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetMetadata(struct struct_Windows_UI_Xaml_Interop_TypeName, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IDependencyPropertyChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Property(void**) noexcept = 0;
            virtual int32_t __stdcall get_OldValue(void**) noexcept = 0;
            virtual int32_t __stdcall get_NewValue(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IDependencyPropertyStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_UnsetValue(void**) noexcept = 0;
            virtual int32_t __stdcall Register(void*, struct struct_Windows_UI_Xaml_Interop_TypeName, struct struct_Windows_UI_Xaml_Interop_TypeName, void*, void**) noexcept = 0;
            virtual int32_t __stdcall RegisterAttached(void*, struct struct_Windows_UI_Xaml_Interop_TypeName, struct struct_Windows_UI_Xaml_Interop_TypeName, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IDispatcherTimer>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Interval(int64_t*) noexcept = 0;
            virtual int32_t __stdcall put_Interval(int64_t) noexcept = 0;
            virtual int32_t __stdcall get_IsEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall add_Tick(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Tick(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall Start() noexcept = 0;
            virtual int32_t __stdcall Stop() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IDispatcherTimerFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(void*, void**, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IDragEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Handled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_Handled(bool) noexcept = 0;
            virtual int32_t __stdcall get_Data(void**) noexcept = 0;
            virtual int32_t __stdcall put_Data(void*) noexcept = 0;
            virtual int32_t __stdcall GetPosition(void*, llm::OS::Foundation::Point*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IDragEventArgs2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DataView(void**) noexcept = 0;
            virtual int32_t __stdcall get_DragUIOverride(void**) noexcept = 0;
            virtual int32_t __stdcall get_Modifiers(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_AcceptedOperation(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_AcceptedOperation(uint32_t) noexcept = 0;
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IDragEventArgs3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AllowedOperations(uint32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IDragOperationDeferral>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Complete() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IDragStartingEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Cancel(bool*) noexcept = 0;
            virtual int32_t __stdcall put_Cancel(bool) noexcept = 0;
            virtual int32_t __stdcall get_Data(void**) noexcept = 0;
            virtual int32_t __stdcall get_DragUI(void**) noexcept = 0;
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
            virtual int32_t __stdcall GetPosition(void*, llm::OS::Foundation::Point*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IDragStartingEventArgs2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AllowedOperations(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_AllowedOperations(uint32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IDragUI>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SetContentFromBitmapImage(void*) noexcept = 0;
            virtual int32_t __stdcall SetContentFromBitmapImageWithAnchorPoint(void*, llm::OS::Foundation::Point) noexcept = 0;
            virtual int32_t __stdcall SetContentFromSoftwareBitmap(void*) noexcept = 0;
            virtual int32_t __stdcall SetContentFromSoftwareBitmapWithAnchorPoint(void*, llm::OS::Foundation::Point) noexcept = 0;
            virtual int32_t __stdcall SetContentFromDataPackage() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IDragUIOverride>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Caption(void**) noexcept = 0;
            virtual int32_t __stdcall put_Caption(void*) noexcept = 0;
            virtual int32_t __stdcall get_IsContentVisible(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsContentVisible(bool) noexcept = 0;
            virtual int32_t __stdcall get_IsCaptionVisible(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsCaptionVisible(bool) noexcept = 0;
            virtual int32_t __stdcall get_IsGlyphVisible(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsGlyphVisible(bool) noexcept = 0;
            virtual int32_t __stdcall Clear() noexcept = 0;
            virtual int32_t __stdcall SetContentFromBitmapImage(void*) noexcept = 0;
            virtual int32_t __stdcall SetContentFromBitmapImageWithAnchorPoint(void*, llm::OS::Foundation::Point) noexcept = 0;
            virtual int32_t __stdcall SetContentFromSoftwareBitmap(void*) noexcept = 0;
            virtual int32_t __stdcall SetContentFromSoftwareBitmapWithAnchorPoint(void*, llm::OS::Foundation::Point) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IDropCompletedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DropResult(uint32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IDurationHelper>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IDurationHelperStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Automatic(struct struct_Windows_UI_Xaml_Duration*) noexcept = 0;
            virtual int32_t __stdcall get_Forever(struct struct_Windows_UI_Xaml_Duration*) noexcept = 0;
            virtual int32_t __stdcall Compare(struct struct_Windows_UI_Xaml_Duration, struct struct_Windows_UI_Xaml_Duration, int32_t*) noexcept = 0;
            virtual int32_t __stdcall FromTimeSpan(int64_t, struct struct_Windows_UI_Xaml_Duration*) noexcept = 0;
            virtual int32_t __stdcall GetHasTimeSpan(struct struct_Windows_UI_Xaml_Duration, bool*) noexcept = 0;
            virtual int32_t __stdcall Add(struct struct_Windows_UI_Xaml_Duration, struct struct_Windows_UI_Xaml_Duration, struct struct_Windows_UI_Xaml_Duration*) noexcept = 0;
            virtual int32_t __stdcall Equals(struct struct_Windows_UI_Xaml_Duration, struct struct_Windows_UI_Xaml_Duration, bool*) noexcept = 0;
            virtual int32_t __stdcall Subtract(struct struct_Windows_UI_Xaml_Duration, struct struct_Windows_UI_Xaml_Duration, struct struct_Windows_UI_Xaml_Duration*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IEffectiveViewportChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_EffectiveViewport(llm::OS::Foundation::Rect*) noexcept = 0;
            virtual int32_t __stdcall get_MaxViewport(llm::OS::Foundation::Rect*) noexcept = 0;
            virtual int32_t __stdcall get_BringIntoViewDistanceX(double*) noexcept = 0;
            virtual int32_t __stdcall get_BringIntoViewDistanceY(double*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IElementFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetElement(void*, void**) noexcept = 0;
            virtual int32_t __stdcall RecycleElement(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IElementFactoryGetArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Data(void**) noexcept = 0;
            virtual int32_t __stdcall put_Data(void*) noexcept = 0;
            virtual int32_t __stdcall get_Parent(void**) noexcept = 0;
            virtual int32_t __stdcall put_Parent(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IElementFactoryGetArgsFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(void*, void**, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IElementFactoryRecycleArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Element(void**) noexcept = 0;
            virtual int32_t __stdcall put_Element(void*) noexcept = 0;
            virtual int32_t __stdcall get_Parent(void**) noexcept = 0;
            virtual int32_t __stdcall put_Parent(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IElementFactoryRecycleArgsFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(void*, void**, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IElementSoundPlayer>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IElementSoundPlayerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Volume(double*) noexcept = 0;
            virtual int32_t __stdcall put_Volume(double) noexcept = 0;
            virtual int32_t __stdcall get_State(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_State(int32_t) noexcept = 0;
            virtual int32_t __stdcall Play(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IElementSoundPlayerStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SpatialAudioMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_SpatialAudioMode(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IEventTrigger>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_RoutedEvent(void**) noexcept = 0;
            virtual int32_t __stdcall put_RoutedEvent(void*) noexcept = 0;
            virtual int32_t __stdcall get_Actions(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IExceptionRoutedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ErrorMessage(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IExceptionRoutedEventArgsFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IFrameworkElement>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Triggers(void**) noexcept = 0;
            virtual int32_t __stdcall get_Resources(void**) noexcept = 0;
            virtual int32_t __stdcall put_Resources(void*) noexcept = 0;
            virtual int32_t __stdcall get_Tag(void**) noexcept = 0;
            virtual int32_t __stdcall put_Tag(void*) noexcept = 0;
            virtual int32_t __stdcall get_Language(void**) noexcept = 0;
            virtual int32_t __stdcall put_Language(void*) noexcept = 0;
            virtual int32_t __stdcall get_ActualWidth(double*) noexcept = 0;
            virtual int32_t __stdcall get_ActualHeight(double*) noexcept = 0;
            virtual int32_t __stdcall get_Width(double*) noexcept = 0;
            virtual int32_t __stdcall put_Width(double) noexcept = 0;
            virtual int32_t __stdcall get_Height(double*) noexcept = 0;
            virtual int32_t __stdcall put_Height(double) noexcept = 0;
            virtual int32_t __stdcall get_MinWidth(double*) noexcept = 0;
            virtual int32_t __stdcall put_MinWidth(double) noexcept = 0;
            virtual int32_t __stdcall get_MaxWidth(double*) noexcept = 0;
            virtual int32_t __stdcall put_MaxWidth(double) noexcept = 0;
            virtual int32_t __stdcall get_MinHeight(double*) noexcept = 0;
            virtual int32_t __stdcall put_MinHeight(double) noexcept = 0;
            virtual int32_t __stdcall get_MaxHeight(double*) noexcept = 0;
            virtual int32_t __stdcall put_MaxHeight(double) noexcept = 0;
            virtual int32_t __stdcall get_HorizontalAlignment(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_HorizontalAlignment(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_VerticalAlignment(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_VerticalAlignment(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_Margin(struct struct_Windows_UI_Xaml_Thickness*) noexcept = 0;
            virtual int32_t __stdcall put_Margin(struct struct_Windows_UI_Xaml_Thickness) noexcept = 0;
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall put_Name(void*) noexcept = 0;
            virtual int32_t __stdcall get_BaseUri(void**) noexcept = 0;
            virtual int32_t __stdcall get_DataContext(void**) noexcept = 0;
            virtual int32_t __stdcall put_DataContext(void*) noexcept = 0;
            virtual int32_t __stdcall get_Style(void**) noexcept = 0;
            virtual int32_t __stdcall put_Style(void*) noexcept = 0;
            virtual int32_t __stdcall get_Parent(void**) noexcept = 0;
            virtual int32_t __stdcall get_FlowDirection(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_FlowDirection(int32_t) noexcept = 0;
            virtual int32_t __stdcall add_Loaded(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Loaded(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Unloaded(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Unloaded(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_SizeChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_SizeChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_LayoutUpdated(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_LayoutUpdated(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall FindName(void*, void**) noexcept = 0;
            virtual int32_t __stdcall SetBinding(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IFrameworkElement2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_RequestedTheme(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_RequestedTheme(int32_t) noexcept = 0;
            virtual int32_t __stdcall add_DataContextChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_DataContextChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall GetBindingExpression(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IFrameworkElement3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_Loading(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Loading(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IFrameworkElement4>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AllowFocusOnInteraction(bool*) noexcept = 0;
            virtual int32_t __stdcall put_AllowFocusOnInteraction(bool) noexcept = 0;
            virtual int32_t __stdcall get_FocusVisualMargin(struct struct_Windows_UI_Xaml_Thickness*) noexcept = 0;
            virtual int32_t __stdcall put_FocusVisualMargin(struct struct_Windows_UI_Xaml_Thickness) noexcept = 0;
            virtual int32_t __stdcall get_FocusVisualSecondaryThickness(struct struct_Windows_UI_Xaml_Thickness*) noexcept = 0;
            virtual int32_t __stdcall put_FocusVisualSecondaryThickness(struct struct_Windows_UI_Xaml_Thickness) noexcept = 0;
            virtual int32_t __stdcall get_FocusVisualPrimaryThickness(struct struct_Windows_UI_Xaml_Thickness*) noexcept = 0;
            virtual int32_t __stdcall put_FocusVisualPrimaryThickness(struct struct_Windows_UI_Xaml_Thickness) noexcept = 0;
            virtual int32_t __stdcall get_FocusVisualSecondaryBrush(void**) noexcept = 0;
            virtual int32_t __stdcall put_FocusVisualSecondaryBrush(void*) noexcept = 0;
            virtual int32_t __stdcall get_FocusVisualPrimaryBrush(void**) noexcept = 0;
            virtual int32_t __stdcall put_FocusVisualPrimaryBrush(void*) noexcept = 0;
            virtual int32_t __stdcall get_AllowFocusWhenDisabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_AllowFocusWhenDisabled(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IFrameworkElement6>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ActualTheme(int32_t*) noexcept = 0;
            virtual int32_t __stdcall add_ActualThemeChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ActualThemeChanged(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IFrameworkElement7>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsLoaded(bool*) noexcept = 0;
            virtual int32_t __stdcall add_EffectiveViewportChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_EffectiveViewportChanged(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IFrameworkElementFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(void*, void**, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IFrameworkElementOverrides>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall MeasureOverride(llm::OS::Foundation::Size, llm::OS::Foundation::Size*) noexcept = 0;
            virtual int32_t __stdcall ArrangeOverride(llm::OS::Foundation::Size, llm::OS::Foundation::Size*) noexcept = 0;
            virtual int32_t __stdcall OnApplyTemplate() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IFrameworkElementOverrides2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GoToElementStateCore(void*, bool, bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IFrameworkElementProtected7>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall InvalidateViewport() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IFrameworkElementStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_TagProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_LanguageProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_ActualWidthProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_ActualHeightProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_WidthProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_HeightProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_MinWidthProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_MaxWidthProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_MinHeightProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_MaxHeightProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_HorizontalAlignmentProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_VerticalAlignmentProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_MarginProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_NameProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_DataContextProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_StyleProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_FlowDirectionProperty(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IFrameworkElementStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_RequestedThemeProperty(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IFrameworkElementStatics4>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AllowFocusOnInteractionProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_FocusVisualMarginProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_FocusVisualSecondaryThicknessProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_FocusVisualPrimaryThicknessProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_FocusVisualSecondaryBrushProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_FocusVisualPrimaryBrushProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_AllowFocusWhenDisabledProperty(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IFrameworkElementStatics5>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall DeferTree(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IFrameworkElementStatics6>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ActualThemeProperty(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IFrameworkTemplate>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IFrameworkTemplateFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(void*, void**, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IFrameworkView>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IFrameworkViewSource>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IGridLengthHelper>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IGridLengthHelperStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Auto(struct struct_Windows_UI_Xaml_GridLength*) noexcept = 0;
            virtual int32_t __stdcall FromPixels(double, struct struct_Windows_UI_Xaml_GridLength*) noexcept = 0;
            virtual int32_t __stdcall FromValueAndType(double, int32_t, struct struct_Windows_UI_Xaml_GridLength*) noexcept = 0;
            virtual int32_t __stdcall GetIsAbsolute(struct struct_Windows_UI_Xaml_GridLength, bool*) noexcept = 0;
            virtual int32_t __stdcall GetIsAuto(struct struct_Windows_UI_Xaml_GridLength, bool*) noexcept = 0;
            virtual int32_t __stdcall GetIsStar(struct struct_Windows_UI_Xaml_GridLength, bool*) noexcept = 0;
            virtual int32_t __stdcall Equals(struct struct_Windows_UI_Xaml_GridLength, struct struct_Windows_UI_Xaml_GridLength, bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IMediaFailedRoutedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ErrorTrace(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IPointHelper>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IPointHelperStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FromCoordinates(float, float, llm::OS::Foundation::Point*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IPropertyMetadata>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DefaultValue(void**) noexcept = 0;
            virtual int32_t __stdcall get_CreateDefaultValueCallback(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IPropertyMetadataFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstanceWithDefaultValue(void*, void*, void**, void**) noexcept = 0;
            virtual int32_t __stdcall CreateInstanceWithDefaultValueAndCallback(void*, void*, void*, void**, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IPropertyMetadataStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateWithDefaultValue(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateWithDefaultValueAndCallback(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateWithFactory(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateWithFactoryAndCallback(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IPropertyPath>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Path(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IPropertyPathFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IRectHelper>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IRectHelperStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Empty(llm::OS::Foundation::Rect*) noexcept = 0;
            virtual int32_t __stdcall FromCoordinatesAndDimensions(float, float, float, float, llm::OS::Foundation::Rect*) noexcept = 0;
            virtual int32_t __stdcall FromPoints(llm::OS::Foundation::Point, llm::OS::Foundation::Point, llm::OS::Foundation::Rect*) noexcept = 0;
            virtual int32_t __stdcall FromLocationAndSize(llm::OS::Foundation::Point, llm::OS::Foundation::Size, llm::OS::Foundation::Rect*) noexcept = 0;
            virtual int32_t __stdcall GetIsEmpty(llm::OS::Foundation::Rect, bool*) noexcept = 0;
            virtual int32_t __stdcall GetBottom(llm::OS::Foundation::Rect, float*) noexcept = 0;
            virtual int32_t __stdcall GetLeft(llm::OS::Foundation::Rect, float*) noexcept = 0;
            virtual int32_t __stdcall GetRight(llm::OS::Foundation::Rect, float*) noexcept = 0;
            virtual int32_t __stdcall GetTop(llm::OS::Foundation::Rect, float*) noexcept = 0;
            virtual int32_t __stdcall Contains(llm::OS::Foundation::Rect, llm::OS::Foundation::Point, bool*) noexcept = 0;
            virtual int32_t __stdcall Equals(llm::OS::Foundation::Rect, llm::OS::Foundation::Rect, bool*) noexcept = 0;
            virtual int32_t __stdcall Intersect(llm::OS::Foundation::Rect, llm::OS::Foundation::Rect, llm::OS::Foundation::Rect*) noexcept = 0;
            virtual int32_t __stdcall UnionWithPoint(llm::OS::Foundation::Rect, llm::OS::Foundation::Point, llm::OS::Foundation::Rect*) noexcept = 0;
            virtual int32_t __stdcall UnionWithRect(llm::OS::Foundation::Rect, llm::OS::Foundation::Rect, llm::OS::Foundation::Rect*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IResourceDictionary>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Source(void**) noexcept = 0;
            virtual int32_t __stdcall put_Source(void*) noexcept = 0;
            virtual int32_t __stdcall get_MergedDictionaries(void**) noexcept = 0;
            virtual int32_t __stdcall get_ThemeDictionaries(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IResourceDictionaryFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(void*, void**, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IRoutedEvent>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IRoutedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_OriginalSource(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IRoutedEventArgsFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(void*, void**, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IScalarTransition>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Duration(int64_t*) noexcept = 0;
            virtual int32_t __stdcall put_Duration(int64_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IScalarTransitionFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(void*, void**, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::ISetter>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Property(void**) noexcept = 0;
            virtual int32_t __stdcall put_Property(void*) noexcept = 0;
            virtual int32_t __stdcall get_Value(void**) noexcept = 0;
            virtual int32_t __stdcall put_Value(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::ISetter2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Target(void**) noexcept = 0;
            virtual int32_t __stdcall put_Target(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::ISetterBase>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsSealed(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::ISetterBaseCollection>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsSealed(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::ISetterBaseFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::ISetterFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::ISizeChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_PreviousSize(llm::OS::Foundation::Size*) noexcept = 0;
            virtual int32_t __stdcall get_NewSize(llm::OS::Foundation::Size*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::ISizeHelper>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::ISizeHelperStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Empty(llm::OS::Foundation::Size*) noexcept = 0;
            virtual int32_t __stdcall FromDimensions(float, float, llm::OS::Foundation::Size*) noexcept = 0;
            virtual int32_t __stdcall GetIsEmpty(llm::OS::Foundation::Size, bool*) noexcept = 0;
            virtual int32_t __stdcall Equals(llm::OS::Foundation::Size, llm::OS::Foundation::Size, bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IStateTrigger>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsActive(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsActive(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IStateTriggerBase>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IStateTriggerBaseFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(void*, void**, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IStateTriggerBaseProtected>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SetActive(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IStateTriggerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsActiveProperty(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IStyle>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsSealed(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Setters(void**) noexcept = 0;
            virtual int32_t __stdcall get_TargetType(struct struct_Windows_UI_Xaml_Interop_TypeName*) noexcept = 0;
            virtual int32_t __stdcall put_TargetType(struct struct_Windows_UI_Xaml_Interop_TypeName) noexcept = 0;
            virtual int32_t __stdcall get_BasedOn(void**) noexcept = 0;
            virtual int32_t __stdcall put_BasedOn(void*) noexcept = 0;
            virtual int32_t __stdcall Seal() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IStyleFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(struct struct_Windows_UI_Xaml_Interop_TypeName, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::ITargetPropertyPath>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Path(void**) noexcept = 0;
            virtual int32_t __stdcall put_Path(void*) noexcept = 0;
            virtual int32_t __stdcall get_Target(void**) noexcept = 0;
            virtual int32_t __stdcall put_Target(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::ITargetPropertyPathFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IThicknessHelper>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IThicknessHelperStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FromLengths(double, double, double, double, struct struct_Windows_UI_Xaml_Thickness*) noexcept = 0;
            virtual int32_t __stdcall FromUniformLength(double, struct struct_Windows_UI_Xaml_Thickness*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::ITriggerAction>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::ITriggerActionFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::ITriggerBase>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::ITriggerBaseFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IUIElement>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DesiredSize(llm::OS::Foundation::Size*) noexcept = 0;
            virtual int32_t __stdcall get_AllowDrop(bool*) noexcept = 0;
            virtual int32_t __stdcall put_AllowDrop(bool) noexcept = 0;
            virtual int32_t __stdcall get_Opacity(double*) noexcept = 0;
            virtual int32_t __stdcall put_Opacity(double) noexcept = 0;
            virtual int32_t __stdcall get_Clip(void**) noexcept = 0;
            virtual int32_t __stdcall put_Clip(void*) noexcept = 0;
            virtual int32_t __stdcall get_RenderTransform(void**) noexcept = 0;
            virtual int32_t __stdcall put_RenderTransform(void*) noexcept = 0;
            virtual int32_t __stdcall get_Projection(void**) noexcept = 0;
            virtual int32_t __stdcall put_Projection(void*) noexcept = 0;
            virtual int32_t __stdcall get_RenderTransformOrigin(llm::OS::Foundation::Point*) noexcept = 0;
            virtual int32_t __stdcall put_RenderTransformOrigin(llm::OS::Foundation::Point) noexcept = 0;
            virtual int32_t __stdcall get_IsHitTestVisible(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsHitTestVisible(bool) noexcept = 0;
            virtual int32_t __stdcall get_Visibility(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Visibility(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_RenderSize(llm::OS::Foundation::Size*) noexcept = 0;
            virtual int32_t __stdcall get_UseLayoutRounding(bool*) noexcept = 0;
            virtual int32_t __stdcall put_UseLayoutRounding(bool) noexcept = 0;
            virtual int32_t __stdcall get_Transitions(void**) noexcept = 0;
            virtual int32_t __stdcall put_Transitions(void*) noexcept = 0;
            virtual int32_t __stdcall get_CacheMode(void**) noexcept = 0;
            virtual int32_t __stdcall put_CacheMode(void*) noexcept = 0;
            virtual int32_t __stdcall get_IsTapEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsTapEnabled(bool) noexcept = 0;
            virtual int32_t __stdcall get_IsDoubleTapEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsDoubleTapEnabled(bool) noexcept = 0;
            virtual int32_t __stdcall get_IsRightTapEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsRightTapEnabled(bool) noexcept = 0;
            virtual int32_t __stdcall get_IsHoldingEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsHoldingEnabled(bool) noexcept = 0;
            virtual int32_t __stdcall get_ManipulationMode(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_ManipulationMode(uint32_t) noexcept = 0;
            virtual int32_t __stdcall get_PointerCaptures(void**) noexcept = 0;
            virtual int32_t __stdcall add_KeyUp(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_KeyUp(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_KeyDown(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_KeyDown(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_GotFocus(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_GotFocus(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_LostFocus(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_LostFocus(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_DragEnter(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_DragEnter(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_DragLeave(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_DragLeave(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_DragOver(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_DragOver(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Drop(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Drop(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_PointerPressed(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PointerPressed(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_PointerMoved(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PointerMoved(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_PointerReleased(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PointerReleased(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_PointerEntered(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PointerEntered(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_PointerExited(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PointerExited(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_PointerCaptureLost(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PointerCaptureLost(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_PointerCanceled(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PointerCanceled(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_PointerWheelChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PointerWheelChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Tapped(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Tapped(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_DoubleTapped(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_DoubleTapped(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Holding(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Holding(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_RightTapped(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_RightTapped(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_ManipulationStarting(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ManipulationStarting(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_ManipulationInertiaStarting(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ManipulationInertiaStarting(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_ManipulationStarted(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ManipulationStarted(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_ManipulationDelta(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ManipulationDelta(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_ManipulationCompleted(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ManipulationCompleted(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall Measure(llm::OS::Foundation::Size) noexcept = 0;
            virtual int32_t __stdcall Arrange(llm::OS::Foundation::Rect) noexcept = 0;
            virtual int32_t __stdcall CapturePointer(void*, bool*) noexcept = 0;
            virtual int32_t __stdcall ReleasePointerCapture(void*) noexcept = 0;
            virtual int32_t __stdcall ReleasePointerCaptures() noexcept = 0;
            virtual int32_t __stdcall AddHandler(void*, void*, bool) noexcept = 0;
            virtual int32_t __stdcall RemoveHandler(void*, void*) noexcept = 0;
            virtual int32_t __stdcall TransformToVisual(void*, void**) noexcept = 0;
            virtual int32_t __stdcall InvalidateMeasure() noexcept = 0;
            virtual int32_t __stdcall InvalidateArrange() noexcept = 0;
            virtual int32_t __stdcall UpdateLayout() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IUIElement10>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ActualOffset(llm::OS::Foundation::Numerics::float3*) noexcept = 0;
            virtual int32_t __stdcall get_ActualSize(llm::OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall get_XamlRoot(void**) noexcept = 0;
            virtual int32_t __stdcall put_XamlRoot(void*) noexcept = 0;
            virtual int32_t __stdcall get_UIContext(void**) noexcept = 0;
            virtual int32_t __stdcall get_Shadow(void**) noexcept = 0;
            virtual int32_t __stdcall put_Shadow(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IUIElement2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_CompositeMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_CompositeMode(int32_t) noexcept = 0;
            virtual int32_t __stdcall CancelDirectManipulations(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IUIElement3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Transform3D(void**) noexcept = 0;
            virtual int32_t __stdcall put_Transform3D(void*) noexcept = 0;
            virtual int32_t __stdcall get_CanDrag(bool*) noexcept = 0;
            virtual int32_t __stdcall put_CanDrag(bool) noexcept = 0;
            virtual int32_t __stdcall add_DragStarting(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_DragStarting(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_DropCompleted(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_DropCompleted(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall StartDragAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IUIElement4>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ContextFlyout(void**) noexcept = 0;
            virtual int32_t __stdcall put_ContextFlyout(void*) noexcept = 0;
            virtual int32_t __stdcall get_ExitDisplayModeOnAccessKeyInvoked(bool*) noexcept = 0;
            virtual int32_t __stdcall put_ExitDisplayModeOnAccessKeyInvoked(bool) noexcept = 0;
            virtual int32_t __stdcall get_IsAccessKeyScope(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsAccessKeyScope(bool) noexcept = 0;
            virtual int32_t __stdcall get_AccessKeyScopeOwner(void**) noexcept = 0;
            virtual int32_t __stdcall put_AccessKeyScopeOwner(void*) noexcept = 0;
            virtual int32_t __stdcall get_AccessKey(void**) noexcept = 0;
            virtual int32_t __stdcall put_AccessKey(void*) noexcept = 0;
            virtual int32_t __stdcall add_ContextRequested(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ContextRequested(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_ContextCanceled(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ContextCanceled(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_AccessKeyDisplayRequested(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_AccessKeyDisplayRequested(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_AccessKeyDisplayDismissed(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_AccessKeyDisplayDismissed(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_AccessKeyInvoked(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_AccessKeyInvoked(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IUIElement5>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Lights(void**) noexcept = 0;
            virtual int32_t __stdcall get_KeyTipPlacementMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_KeyTipPlacementMode(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_KeyTipHorizontalOffset(double*) noexcept = 0;
            virtual int32_t __stdcall put_KeyTipHorizontalOffset(double) noexcept = 0;
            virtual int32_t __stdcall get_KeyTipVerticalOffset(double*) noexcept = 0;
            virtual int32_t __stdcall put_KeyTipVerticalOffset(double) noexcept = 0;
            virtual int32_t __stdcall get_XYFocusKeyboardNavigation(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_XYFocusKeyboardNavigation(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_XYFocusUpNavigationStrategy(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_XYFocusUpNavigationStrategy(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_XYFocusDownNavigationStrategy(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_XYFocusDownNavigationStrategy(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_XYFocusLeftNavigationStrategy(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_XYFocusLeftNavigationStrategy(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_XYFocusRightNavigationStrategy(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_XYFocusRightNavigationStrategy(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_HighContrastAdjustment(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_HighContrastAdjustment(uint32_t) noexcept = 0;
            virtual int32_t __stdcall get_TabFocusNavigation(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_TabFocusNavigation(int32_t) noexcept = 0;
            virtual int32_t __stdcall add_GettingFocus(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_GettingFocus(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_LosingFocus(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_LosingFocus(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_NoFocusCandidateFound(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_NoFocusCandidateFound(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall StartBringIntoView() noexcept = 0;
            virtual int32_t __stdcall StartBringIntoViewWithOptions(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IUIElement7>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_KeyboardAccelerators(void**) noexcept = 0;
            virtual int32_t __stdcall add_CharacterReceived(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_CharacterReceived(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_ProcessKeyboardAccelerators(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ProcessKeyboardAccelerators(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_PreviewKeyDown(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PreviewKeyDown(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_PreviewKeyUp(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PreviewKeyUp(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall TryInvokeKeyboardAccelerator(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IUIElement8>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_KeyTipTarget(void**) noexcept = 0;
            virtual int32_t __stdcall put_KeyTipTarget(void*) noexcept = 0;
            virtual int32_t __stdcall get_KeyboardAcceleratorPlacementTarget(void**) noexcept = 0;
            virtual int32_t __stdcall put_KeyboardAcceleratorPlacementTarget(void*) noexcept = 0;
            virtual int32_t __stdcall get_KeyboardAcceleratorPlacementMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_KeyboardAcceleratorPlacementMode(int32_t) noexcept = 0;
            virtual int32_t __stdcall add_BringIntoViewRequested(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_BringIntoViewRequested(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IUIElement9>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_CanBeScrollAnchor(bool*) noexcept = 0;
            virtual int32_t __stdcall put_CanBeScrollAnchor(bool) noexcept = 0;
            virtual int32_t __stdcall get_OpacityTransition(void**) noexcept = 0;
            virtual int32_t __stdcall put_OpacityTransition(void*) noexcept = 0;
            virtual int32_t __stdcall get_Translation(llm::OS::Foundation::Numerics::float3*) noexcept = 0;
            virtual int32_t __stdcall put_Translation(llm::OS::Foundation::Numerics::float3) noexcept = 0;
            virtual int32_t __stdcall get_TranslationTransition(void**) noexcept = 0;
            virtual int32_t __stdcall put_TranslationTransition(void*) noexcept = 0;
            virtual int32_t __stdcall get_Rotation(float*) noexcept = 0;
            virtual int32_t __stdcall put_Rotation(float) noexcept = 0;
            virtual int32_t __stdcall get_RotationTransition(void**) noexcept = 0;
            virtual int32_t __stdcall put_RotationTransition(void*) noexcept = 0;
            virtual int32_t __stdcall get_Scale(llm::OS::Foundation::Numerics::float3*) noexcept = 0;
            virtual int32_t __stdcall put_Scale(llm::OS::Foundation::Numerics::float3) noexcept = 0;
            virtual int32_t __stdcall get_ScaleTransition(void**) noexcept = 0;
            virtual int32_t __stdcall put_ScaleTransition(void*) noexcept = 0;
            virtual int32_t __stdcall get_TransformMatrix(llm::OS::Foundation::Numerics::float4x4*) noexcept = 0;
            virtual int32_t __stdcall put_TransformMatrix(llm::OS::Foundation::Numerics::float4x4) noexcept = 0;
            virtual int32_t __stdcall get_CenterPoint(llm::OS::Foundation::Numerics::float3*) noexcept = 0;
            virtual int32_t __stdcall put_CenterPoint(llm::OS::Foundation::Numerics::float3) noexcept = 0;
            virtual int32_t __stdcall get_RotationAxis(llm::OS::Foundation::Numerics::float3*) noexcept = 0;
            virtual int32_t __stdcall put_RotationAxis(llm::OS::Foundation::Numerics::float3) noexcept = 0;
            virtual int32_t __stdcall StartAnimation(void*) noexcept = 0;
            virtual int32_t __stdcall StopAnimation(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IUIElementFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IUIElementOverrides>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall OnCreateAutomationPeer(void**) noexcept = 0;
            virtual int32_t __stdcall OnDisconnectVisualChildren() noexcept = 0;
            virtual int32_t __stdcall FindSubElementsForTouchTargeting(llm::OS::Foundation::Point, llm::OS::Foundation::Rect, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IUIElementOverrides7>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetChildrenInTabFocusOrder(void**) noexcept = 0;
            virtual int32_t __stdcall OnProcessKeyboardAccelerators(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IUIElementOverrides8>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall OnKeyboardAcceleratorInvoked(void*) noexcept = 0;
            virtual int32_t __stdcall OnBringIntoViewRequested(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IUIElementOverrides9>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall PopulatePropertyInfoOverride(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IUIElementStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_KeyDownEvent(void**) noexcept = 0;
            virtual int32_t __stdcall get_KeyUpEvent(void**) noexcept = 0;
            virtual int32_t __stdcall get_PointerEnteredEvent(void**) noexcept = 0;
            virtual int32_t __stdcall get_PointerPressedEvent(void**) noexcept = 0;
            virtual int32_t __stdcall get_PointerMovedEvent(void**) noexcept = 0;
            virtual int32_t __stdcall get_PointerReleasedEvent(void**) noexcept = 0;
            virtual int32_t __stdcall get_PointerExitedEvent(void**) noexcept = 0;
            virtual int32_t __stdcall get_PointerCaptureLostEvent(void**) noexcept = 0;
            virtual int32_t __stdcall get_PointerCanceledEvent(void**) noexcept = 0;
            virtual int32_t __stdcall get_PointerWheelChangedEvent(void**) noexcept = 0;
            virtual int32_t __stdcall get_TappedEvent(void**) noexcept = 0;
            virtual int32_t __stdcall get_DoubleTappedEvent(void**) noexcept = 0;
            virtual int32_t __stdcall get_HoldingEvent(void**) noexcept = 0;
            virtual int32_t __stdcall get_RightTappedEvent(void**) noexcept = 0;
            virtual int32_t __stdcall get_ManipulationStartingEvent(void**) noexcept = 0;
            virtual int32_t __stdcall get_ManipulationInertiaStartingEvent(void**) noexcept = 0;
            virtual int32_t __stdcall get_ManipulationStartedEvent(void**) noexcept = 0;
            virtual int32_t __stdcall get_ManipulationDeltaEvent(void**) noexcept = 0;
            virtual int32_t __stdcall get_ManipulationCompletedEvent(void**) noexcept = 0;
            virtual int32_t __stdcall get_DragEnterEvent(void**) noexcept = 0;
            virtual int32_t __stdcall get_DragLeaveEvent(void**) noexcept = 0;
            virtual int32_t __stdcall get_DragOverEvent(void**) noexcept = 0;
            virtual int32_t __stdcall get_DropEvent(void**) noexcept = 0;
            virtual int32_t __stdcall get_AllowDropProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_OpacityProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_ClipProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_RenderTransformProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_ProjectionProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_RenderTransformOriginProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsHitTestVisibleProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_VisibilityProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_UseLayoutRoundingProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_TransitionsProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_CacheModeProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsTapEnabledProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsDoubleTapEnabledProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsRightTapEnabledProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsHoldingEnabledProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_ManipulationModeProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_PointerCapturesProperty(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IUIElementStatics10>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ShadowProperty(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IUIElementStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_CompositeModeProperty(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IUIElementStatics3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Transform3DProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_CanDragProperty(void**) noexcept = 0;
            virtual int32_t __stdcall TryStartDirectManipulation(void*, bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IUIElementStatics4>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ContextFlyoutProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_ExitDisplayModeOnAccessKeyInvokedProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsAccessKeyScopeProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_AccessKeyScopeOwnerProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_AccessKeyProperty(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IUIElementStatics5>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_LightsProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_KeyTipPlacementModeProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_KeyTipHorizontalOffsetProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_KeyTipVerticalOffsetProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_XYFocusKeyboardNavigationProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_XYFocusUpNavigationStrategyProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_XYFocusDownNavigationStrategyProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_XYFocusLeftNavigationStrategyProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_XYFocusRightNavigationStrategyProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_HighContrastAdjustmentProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_TabFocusNavigationProperty(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IUIElementStatics6>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_GettingFocusEvent(void**) noexcept = 0;
            virtual int32_t __stdcall get_LosingFocusEvent(void**) noexcept = 0;
            virtual int32_t __stdcall get_NoFocusCandidateFoundEvent(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IUIElementStatics7>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_PreviewKeyDownEvent(void**) noexcept = 0;
            virtual int32_t __stdcall get_CharacterReceivedEvent(void**) noexcept = 0;
            virtual int32_t __stdcall get_PreviewKeyUpEvent(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IUIElementStatics8>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_BringIntoViewRequestedEvent(void**) noexcept = 0;
            virtual int32_t __stdcall get_ContextRequestedEvent(void**) noexcept = 0;
            virtual int32_t __stdcall get_KeyTipTargetProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_KeyboardAcceleratorPlacementTargetProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_KeyboardAcceleratorPlacementModeProperty(void**) noexcept = 0;
            virtual int32_t __stdcall RegisterAsScrollPort(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IUIElementStatics9>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_CanBeScrollAnchorProperty(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IUIElementWeakCollection>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IUIElementWeakCollectionFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(void*, void**, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IUnhandledExceptionEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Exception(llm::hresult*) noexcept = 0;
            virtual int32_t __stdcall get_Message(void**) noexcept = 0;
            virtual int32_t __stdcall get_Handled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_Handled(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IVector3Transition>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Duration(int64_t*) noexcept = 0;
            virtual int32_t __stdcall put_Duration(int64_t) noexcept = 0;
            virtual int32_t __stdcall get_Components(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Components(uint32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IVector3TransitionFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(void*, void**, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IVisualState>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall get_Storyboard(void**) noexcept = 0;
            virtual int32_t __stdcall put_Storyboard(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IVisualState2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Setters(void**) noexcept = 0;
            virtual int32_t __stdcall get_StateTriggers(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IVisualStateChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_OldState(void**) noexcept = 0;
            virtual int32_t __stdcall put_OldState(void*) noexcept = 0;
            virtual int32_t __stdcall get_NewState(void**) noexcept = 0;
            virtual int32_t __stdcall put_NewState(void*) noexcept = 0;
            virtual int32_t __stdcall get_Control(void**) noexcept = 0;
            virtual int32_t __stdcall put_Control(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IVisualStateGroup>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall get_Transitions(void**) noexcept = 0;
            virtual int32_t __stdcall get_States(void**) noexcept = 0;
            virtual int32_t __stdcall get_CurrentState(void**) noexcept = 0;
            virtual int32_t __stdcall add_CurrentStateChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_CurrentStateChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_CurrentStateChanging(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_CurrentStateChanging(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IVisualStateManager>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IVisualStateManagerFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(void*, void**, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IVisualStateManagerOverrides>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GoToStateCore(void*, void*, void*, void*, void*, bool, bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IVisualStateManagerProtected>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RaiseCurrentStateChanging(void*, void*, void*, void*) noexcept = 0;
            virtual int32_t __stdcall RaiseCurrentStateChanged(void*, void*, void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IVisualStateManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetVisualStateGroups(void*, void**) noexcept = 0;
            virtual int32_t __stdcall get_CustomVisualStateManagerProperty(void**) noexcept = 0;
            virtual int32_t __stdcall GetCustomVisualStateManager(void*, void**) noexcept = 0;
            virtual int32_t __stdcall SetCustomVisualStateManager(void*, void*) noexcept = 0;
            virtual int32_t __stdcall GoToState(void*, void*, bool, bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IVisualTransition>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_GeneratedDuration(struct struct_Windows_UI_Xaml_Duration*) noexcept = 0;
            virtual int32_t __stdcall put_GeneratedDuration(struct struct_Windows_UI_Xaml_Duration) noexcept = 0;
            virtual int32_t __stdcall get_GeneratedEasingFunction(void**) noexcept = 0;
            virtual int32_t __stdcall put_GeneratedEasingFunction(void*) noexcept = 0;
            virtual int32_t __stdcall get_To(void**) noexcept = 0;
            virtual int32_t __stdcall put_To(void*) noexcept = 0;
            virtual int32_t __stdcall get_From(void**) noexcept = 0;
            virtual int32_t __stdcall put_From(void*) noexcept = 0;
            virtual int32_t __stdcall get_Storyboard(void**) noexcept = 0;
            virtual int32_t __stdcall put_Storyboard(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IVisualTransitionFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(void*, void**, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IWindow>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Bounds(llm::OS::Foundation::Rect*) noexcept = 0;
            virtual int32_t __stdcall get_Visible(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Content(void**) noexcept = 0;
            virtual int32_t __stdcall put_Content(void*) noexcept = 0;
            virtual int32_t __stdcall get_CoreWindow(void**) noexcept = 0;
            virtual int32_t __stdcall get_Dispatcher(void**) noexcept = 0;
            virtual int32_t __stdcall add_Activated(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Activated(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Closed(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Closed(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_SizeChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_SizeChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_VisibilityChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_VisibilityChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall Activate() noexcept = 0;
            virtual int32_t __stdcall Close() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IWindow2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SetTitleBar(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IWindow3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Compositor(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IWindow4>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_UIContext(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IWindowCreatedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Window(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IWindowStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Current(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IXamlRoot>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Content(void**) noexcept = 0;
            virtual int32_t __stdcall get_Size(llm::OS::Foundation::Size*) noexcept = 0;
            virtual int32_t __stdcall get_RasterizationScale(double*) noexcept = 0;
            virtual int32_t __stdcall get_IsHostVisible(bool*) noexcept = 0;
            virtual int32_t __stdcall get_UIContext(void**) noexcept = 0;
            virtual int32_t __stdcall add_Changed(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Changed(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::IXamlRootChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::ApplicationInitializationCallback>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::BindingFailedEventHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::CreateDefaultValueCallback>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::DependencyPropertyChangedCallback>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::DependencyPropertyChangedEventHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::DragEventHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::EnteredBackgroundEventHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::ExceptionRoutedEventHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::LeavingBackgroundEventHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::PropertyChangedCallback>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::RoutedEventHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::SizeChangedEventHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::SuspendingEventHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::UnhandledExceptionEventHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::VisualStateChangedEventHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::WindowActivatedEventHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::WindowClosedEventHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::WindowSizeChangedEventHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::WindowVisibilityChangedEventHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, void*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IAdaptiveTrigger
    {
        [[nodiscard]] LLM_IMPL_AUTO(double) MinWindowWidth() const;
        LLM_IMPL_AUTO(void) MinWindowWidth(double value) const;
        [[nodiscard]] LLM_IMPL_AUTO(double) MinWindowHeight() const;
        LLM_IMPL_AUTO(void) MinWindowHeight(double value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IAdaptiveTrigger>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IAdaptiveTrigger<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IAdaptiveTriggerFactory
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::AdaptiveTrigger) CreateInstance(llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IAdaptiveTriggerFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IAdaptiveTriggerFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IAdaptiveTriggerStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) MinWindowWidthProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) MinWindowHeightProperty() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IAdaptiveTriggerStatics>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IAdaptiveTriggerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IApplication
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::ResourceDictionary) Resources() const;
        LLM_IMPL_AUTO(void) Resources(llm::OS::UI::Xaml::ResourceDictionary const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DebugSettings) DebugSettings() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::ApplicationTheme) RequestedTheme() const;
        LLM_IMPL_AUTO(void) RequestedTheme(llm::OS::UI::Xaml::ApplicationTheme const& value) const;
        LLM_IMPL_AUTO(llm::event_token) UnhandledException(llm::OS::UI::Xaml::UnhandledExceptionEventHandler const& handler) const;
        using UnhandledException_revoker = impl::event_revoker<llm::OS::UI::Xaml::IApplication, &impl::abi_t<llm::OS::UI::Xaml::IApplication>::remove_UnhandledException>;
        [[nodiscard]] UnhandledException_revoker UnhandledException(auto_revoke_t, llm::OS::UI::Xaml::UnhandledExceptionEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) UnhandledException(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) Suspending(llm::OS::UI::Xaml::SuspendingEventHandler const& handler) const;
        using Suspending_revoker = impl::event_revoker<llm::OS::UI::Xaml::IApplication, &impl::abi_t<llm::OS::UI::Xaml::IApplication>::remove_Suspending>;
        [[nodiscard]] Suspending_revoker Suspending(auto_revoke_t, llm::OS::UI::Xaml::SuspendingEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) Suspending(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) Resuming(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const;
        using Resuming_revoker = impl::event_revoker<llm::OS::UI::Xaml::IApplication, &impl::abi_t<llm::OS::UI::Xaml::IApplication>::remove_Resuming>;
        [[nodiscard]] Resuming_revoker Resuming(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) Resuming(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(void) Exit() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IApplication>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IApplication<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IApplication2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::FocusVisualKind) FocusVisualKind() const;
        LLM_IMPL_AUTO(void) FocusVisualKind(llm::OS::UI::Xaml::FocusVisualKind const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::ApplicationRequiresPointerMode) RequiresPointerMode() const;
        LLM_IMPL_AUTO(void) RequiresPointerMode(llm::OS::UI::Xaml::ApplicationRequiresPointerMode const& value) const;
        LLM_IMPL_AUTO(llm::event_token) LeavingBackground(llm::OS::UI::Xaml::LeavingBackgroundEventHandler const& handler) const;
        using LeavingBackground_revoker = impl::event_revoker<llm::OS::UI::Xaml::IApplication2, &impl::abi_t<llm::OS::UI::Xaml::IApplication2>::remove_LeavingBackground>;
        [[nodiscard]] LeavingBackground_revoker LeavingBackground(auto_revoke_t, llm::OS::UI::Xaml::LeavingBackgroundEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) LeavingBackground(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) EnteredBackground(llm::OS::UI::Xaml::EnteredBackgroundEventHandler const& handler) const;
        using EnteredBackground_revoker = impl::event_revoker<llm::OS::UI::Xaml::IApplication2, &impl::abi_t<llm::OS::UI::Xaml::IApplication2>::remove_EnteredBackground>;
        [[nodiscard]] EnteredBackground_revoker EnteredBackground(auto_revoke_t, llm::OS::UI::Xaml::EnteredBackgroundEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) EnteredBackground(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm::OS::UI::Xaml::IApplication2>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IApplication2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IApplication3
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::ApplicationHighContrastAdjustment) HighContrastAdjustment() const;
        LLM_IMPL_AUTO(void) HighContrastAdjustment(llm::OS::UI::Xaml::ApplicationHighContrastAdjustment const& value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IApplication3>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IApplication3<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IApplicationFactory
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::Application) CreateInstance(llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IApplicationFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IApplicationFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IApplicationInitializationCallbackParams
    {
    };
    template <> struct consume<llm::OS::UI::Xaml::IApplicationInitializationCallbackParams>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IApplicationInitializationCallbackParams<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IApplicationOverrides
    {
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
    template <> struct consume<llm::OS::UI::Xaml::IApplicationOverrides>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IApplicationOverrides<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IApplicationOverrides2
    {
        LLM_IMPL_AUTO(void) OnBackgroundActivated(llm::OS::ApplicationModel::Activation::BackgroundActivatedEventArgs const& args) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IApplicationOverrides2>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IApplicationOverrides2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IApplicationStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Application) Current() const;
        LLM_IMPL_AUTO(void) Start(llm::OS::UI::Xaml::ApplicationInitializationCallback const& callback) const;
        LLM_IMPL_AUTO(void) LoadComponent(llm::OS::Foundation::IInspectable const& component, llm::OS::Foundation::Uri const& resourceLocator) const;
        LLM_IMPL_AUTO(void) LoadComponent(llm::OS::Foundation::IInspectable const& component, llm::OS::Foundation::Uri const& resourceLocator, llm::OS::UI::Xaml::Controls::Primitives::ComponentResourceLocation const& componentResourceLocation) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IApplicationStatics>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IApplicationStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IBindingFailedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Message() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IBindingFailedEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IBindingFailedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IBringIntoViewOptions
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) AnimationDesired() const;
        LLM_IMPL_AUTO(void) AnimationDesired(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::Rect>) TargetRect() const;
        LLM_IMPL_AUTO(void) TargetRect(llm::OS::Foundation::IReference<llm::OS::Foundation::Rect> const& value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IBringIntoViewOptions>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IBringIntoViewOptions<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IBringIntoViewOptions2
    {
        [[nodiscard]] LLM_IMPL_AUTO(double) HorizontalAlignmentRatio() const;
        LLM_IMPL_AUTO(void) HorizontalAlignmentRatio(double value) const;
        [[nodiscard]] LLM_IMPL_AUTO(double) VerticalAlignmentRatio() const;
        LLM_IMPL_AUTO(void) VerticalAlignmentRatio(double value) const;
        [[nodiscard]] LLM_IMPL_AUTO(double) HorizontalOffset() const;
        LLM_IMPL_AUTO(void) HorizontalOffset(double value) const;
        [[nodiscard]] LLM_IMPL_AUTO(double) VerticalOffset() const;
        LLM_IMPL_AUTO(void) VerticalOffset(double value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IBringIntoViewOptions2>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IBringIntoViewOptions2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IBringIntoViewRequestedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::UIElement) TargetElement() const;
        LLM_IMPL_AUTO(void) TargetElement(llm::OS::UI::Xaml::UIElement const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) AnimationDesired() const;
        LLM_IMPL_AUTO(void) AnimationDesired(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Rect) TargetRect() const;
        LLM_IMPL_AUTO(void) TargetRect(llm::OS::Foundation::Rect const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(double) HorizontalAlignmentRatio() const;
        [[nodiscard]] LLM_IMPL_AUTO(double) VerticalAlignmentRatio() const;
        [[nodiscard]] LLM_IMPL_AUTO(double) HorizontalOffset() const;
        LLM_IMPL_AUTO(void) HorizontalOffset(double value) const;
        [[nodiscard]] LLM_IMPL_AUTO(double) VerticalOffset() const;
        LLM_IMPL_AUTO(void) VerticalOffset(double value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) Handled() const;
        LLM_IMPL_AUTO(void) Handled(bool value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IBringIntoViewRequestedEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IBringIntoViewRequestedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IBrushTransition
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) Duration() const;
        LLM_IMPL_AUTO(void) Duration(llm::OS::Foundation::TimeSpan const& value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IBrushTransition>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IBrushTransition<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IBrushTransitionFactory
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::BrushTransition) CreateInstance(llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IBrushTransitionFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IBrushTransitionFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IColorPaletteResources
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) AltHigh() const;
        LLM_IMPL_AUTO(void) AltHigh(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) AltLow() const;
        LLM_IMPL_AUTO(void) AltLow(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) AltMedium() const;
        LLM_IMPL_AUTO(void) AltMedium(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) AltMediumHigh() const;
        LLM_IMPL_AUTO(void) AltMediumHigh(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) AltMediumLow() const;
        LLM_IMPL_AUTO(void) AltMediumLow(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) BaseHigh() const;
        LLM_IMPL_AUTO(void) BaseHigh(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) BaseLow() const;
        LLM_IMPL_AUTO(void) BaseLow(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) BaseMedium() const;
        LLM_IMPL_AUTO(void) BaseMedium(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) BaseMediumHigh() const;
        LLM_IMPL_AUTO(void) BaseMediumHigh(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) BaseMediumLow() const;
        LLM_IMPL_AUTO(void) BaseMediumLow(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) ChromeAltLow() const;
        LLM_IMPL_AUTO(void) ChromeAltLow(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) ChromeBlackHigh() const;
        LLM_IMPL_AUTO(void) ChromeBlackHigh(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) ChromeBlackLow() const;
        LLM_IMPL_AUTO(void) ChromeBlackLow(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) ChromeBlackMediumLow() const;
        LLM_IMPL_AUTO(void) ChromeBlackMediumLow(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) ChromeBlackMedium() const;
        LLM_IMPL_AUTO(void) ChromeBlackMedium(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) ChromeDisabledHigh() const;
        LLM_IMPL_AUTO(void) ChromeDisabledHigh(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) ChromeDisabledLow() const;
        LLM_IMPL_AUTO(void) ChromeDisabledLow(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) ChromeHigh() const;
        LLM_IMPL_AUTO(void) ChromeHigh(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) ChromeLow() const;
        LLM_IMPL_AUTO(void) ChromeLow(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) ChromeMedium() const;
        LLM_IMPL_AUTO(void) ChromeMedium(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) ChromeMediumLow() const;
        LLM_IMPL_AUTO(void) ChromeMediumLow(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) ChromeWhite() const;
        LLM_IMPL_AUTO(void) ChromeWhite(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) ChromeGray() const;
        LLM_IMPL_AUTO(void) ChromeGray(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) ListLow() const;
        LLM_IMPL_AUTO(void) ListLow(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) ListMedium() const;
        LLM_IMPL_AUTO(void) ListMedium(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) ErrorText() const;
        LLM_IMPL_AUTO(void) ErrorText(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) Accent() const;
        LLM_IMPL_AUTO(void) Accent(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IColorPaletteResources>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IColorPaletteResources<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IColorPaletteResourcesFactory
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::ColorPaletteResources) CreateInstance(llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IColorPaletteResourcesFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IColorPaletteResourcesFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_ICornerRadiusHelper
    {
    };
    template <> struct consume<llm::OS::UI::Xaml::ICornerRadiusHelper>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_ICornerRadiusHelper<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_ICornerRadiusHelperStatics
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::CornerRadius) FromRadii(double topLeft, double topRight, double bottomRight, double bottomLeft) const;
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::CornerRadius) FromUniformRadius(double uniformRadius) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::ICornerRadiusHelperStatics>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_ICornerRadiusHelperStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IDataContextChangedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) NewValue() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) Handled() const;
        LLM_IMPL_AUTO(void) Handled(bool value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IDataContextChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IDataContextChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IDataTemplate
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyObject) LoadContent() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IDataTemplate>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IDataTemplate<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IDataTemplateExtension
    {
        LLM_IMPL_AUTO(void) ResetTemplate() const;
        LLM_IMPL_AUTO(bool) ProcessBinding(uint32_t phase) const;
        LLM_IMPL_AUTO(int32_t) ProcessBindings(llm::OS::UI::Xaml::Controls::ContainerContentChangingEventArgs const& arg) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IDataTemplateExtension>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IDataTemplateExtension<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IDataTemplateFactory
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::DataTemplate) CreateInstance(llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IDataTemplateFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IDataTemplateFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IDataTemplateKey
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) DataType() const;
        LLM_IMPL_AUTO(void) DataType(llm::OS::Foundation::IInspectable const& value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IDataTemplateKey>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IDataTemplateKey<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IDataTemplateKeyFactory
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::DataTemplateKey) CreateInstance(llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const;
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::DataTemplateKey) CreateInstanceWithType(llm::OS::Foundation::IInspectable const& dataType, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IDataTemplateKeyFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IDataTemplateKeyFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IDataTemplateStatics2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) ExtensionInstanceProperty() const;
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::IDataTemplateExtension) GetExtensionInstance(llm::OS::UI::Xaml::FrameworkElement const& element) const;
        LLM_IMPL_AUTO(void) SetExtensionInstance(llm::OS::UI::Xaml::FrameworkElement const& element, llm::OS::UI::Xaml::IDataTemplateExtension const& value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IDataTemplateStatics2>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IDataTemplateStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IDebugSettings
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) EnableFrameRateCounter() const;
        LLM_IMPL_AUTO(void) EnableFrameRateCounter(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsBindingTracingEnabled() const;
        LLM_IMPL_AUTO(void) IsBindingTracingEnabled(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsOverdrawHeatMapEnabled() const;
        LLM_IMPL_AUTO(void) IsOverdrawHeatMapEnabled(bool value) const;
        LLM_IMPL_AUTO(llm::event_token) BindingFailed(llm::OS::UI::Xaml::BindingFailedEventHandler const& handler) const;
        using BindingFailed_revoker = impl::event_revoker<llm::OS::UI::Xaml::IDebugSettings, &impl::abi_t<llm::OS::UI::Xaml::IDebugSettings>::remove_BindingFailed>;
        [[nodiscard]] BindingFailed_revoker BindingFailed(auto_revoke_t, llm::OS::UI::Xaml::BindingFailedEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) BindingFailed(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm::OS::UI::Xaml::IDebugSettings>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IDebugSettings<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IDebugSettings2
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) EnableRedrawRegions() const;
        LLM_IMPL_AUTO(void) EnableRedrawRegions(bool value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IDebugSettings2>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IDebugSettings2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IDebugSettings3
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsTextPerformanceVisualizationEnabled() const;
        LLM_IMPL_AUTO(void) IsTextPerformanceVisualizationEnabled(bool value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IDebugSettings3>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IDebugSettings3<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IDebugSettings4
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) FailFastOnErrors() const;
        LLM_IMPL_AUTO(void) FailFastOnErrors(bool value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IDebugSettings4>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IDebugSettings4<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IDependencyObject
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) GetValue(llm::OS::UI::Xaml::DependencyProperty const& dp) const;
        LLM_IMPL_AUTO(void) SetValue(llm::OS::UI::Xaml::DependencyProperty const& dp, llm::OS::Foundation::IInspectable const& value) const;
        LLM_IMPL_AUTO(void) ClearValue(llm::OS::UI::Xaml::DependencyProperty const& dp) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) ReadLocalValue(llm::OS::UI::Xaml::DependencyProperty const& dp) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) GetAnimationBaseValue(llm::OS::UI::Xaml::DependencyProperty const& dp) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Core::CoreDispatcher) Dispatcher() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IDependencyObject>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IDependencyObject<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IDependencyObject2
    {
        LLM_IMPL_AUTO(int64_t) RegisterPropertyChangedCallback(llm::OS::UI::Xaml::DependencyProperty const& dp, llm::OS::UI::Xaml::DependencyPropertyChangedCallback const& callback) const;
        LLM_IMPL_AUTO(void) UnregisterPropertyChangedCallback(llm::OS::UI::Xaml::DependencyProperty const& dp, int64_t token) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IDependencyObject2>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IDependencyObject2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IDependencyObjectCollectionFactory
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyObjectCollection) CreateInstance(llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IDependencyObjectCollectionFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IDependencyObjectCollectionFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IDependencyObjectFactory
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyObject) CreateInstance(llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IDependencyObjectFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IDependencyObjectFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IDependencyProperty
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::PropertyMetadata) GetMetadata(llm::OS::UI::Xaml::Interop::TypeName const& forType) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IDependencyProperty>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IDependencyProperty<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IDependencyPropertyChangedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) Property() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) OldValue() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) NewValue() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IDependencyPropertyChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IDependencyPropertyChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IDependencyPropertyStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) UnsetValue() const;
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) Register(param::hstring const& name, llm::OS::UI::Xaml::Interop::TypeName const& propertyType, llm::OS::UI::Xaml::Interop::TypeName const& ownerType, llm::OS::UI::Xaml::PropertyMetadata const& typeMetadata) const;
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) RegisterAttached(param::hstring const& name, llm::OS::UI::Xaml::Interop::TypeName const& propertyType, llm::OS::UI::Xaml::Interop::TypeName const& ownerType, llm::OS::UI::Xaml::PropertyMetadata const& defaultMetadata) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IDependencyPropertyStatics>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IDependencyPropertyStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IDispatcherTimer
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) Interval() const;
        LLM_IMPL_AUTO(void) Interval(llm::OS::Foundation::TimeSpan const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsEnabled() const;
        LLM_IMPL_AUTO(llm::event_token) Tick(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const;
        using Tick_revoker = impl::event_revoker<llm::OS::UI::Xaml::IDispatcherTimer, &impl::abi_t<llm::OS::UI::Xaml::IDispatcherTimer>::remove_Tick>;
        [[nodiscard]] Tick_revoker Tick(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) Tick(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(void) Start() const;
        LLM_IMPL_AUTO(void) Stop() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IDispatcherTimer>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IDispatcherTimer<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IDispatcherTimerFactory
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::DispatcherTimer) CreateInstance(llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IDispatcherTimerFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IDispatcherTimerFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IDragEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Handled() const;
        LLM_IMPL_AUTO(void) Handled(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::DataTransfer::DataPackage) Data() const;
        LLM_IMPL_AUTO(void) Data(llm::OS::ApplicationModel::DataTransfer::DataPackage const& value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Point) GetPosition(llm::OS::UI::Xaml::UIElement const& relativeTo) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IDragEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IDragEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IDragEventArgs2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::DataTransfer::DataPackageView) DataView() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DragUIOverride) DragUIOverride() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::DataTransfer::DragDrop::DragDropModifiers) Modifiers() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::DataTransfer::DataPackageOperation) AcceptedOperation() const;
        LLM_IMPL_AUTO(void) AcceptedOperation(llm::OS::ApplicationModel::DataTransfer::DataPackageOperation const& value) const;
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::DragOperationDeferral) GetDeferral() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IDragEventArgs2>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IDragEventArgs2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IDragEventArgs3
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::DataTransfer::DataPackageOperation) AllowedOperations() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IDragEventArgs3>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IDragEventArgs3<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IDragOperationDeferral
    {
        LLM_IMPL_AUTO(void) Complete() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IDragOperationDeferral>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IDragOperationDeferral<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IDragStartingEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Cancel() const;
        LLM_IMPL_AUTO(void) Cancel(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::DataTransfer::DataPackage) Data() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DragUI) DragUI() const;
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::DragOperationDeferral) GetDeferral() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Point) GetPosition(llm::OS::UI::Xaml::UIElement const& relativeTo) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IDragStartingEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IDragStartingEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IDragStartingEventArgs2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::DataTransfer::DataPackageOperation) AllowedOperations() const;
        LLM_IMPL_AUTO(void) AllowedOperations(llm::OS::ApplicationModel::DataTransfer::DataPackageOperation const& value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IDragStartingEventArgs2>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IDragStartingEventArgs2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IDragUI
    {
        LLM_IMPL_AUTO(void) SetContentFromBitmapImage(llm::OS::UI::Xaml::Media::Imaging::BitmapImage const& bitmapImage) const;
        LLM_IMPL_AUTO(void) SetContentFromBitmapImage(llm::OS::UI::Xaml::Media::Imaging::BitmapImage const& bitmapImage, llm::OS::Foundation::Point const& anchorPoint) const;
        LLM_IMPL_AUTO(void) SetContentFromSoftwareBitmap(llm::OS::Graphics::Imaging::SoftwareBitmap const& softwareBitmap) const;
        LLM_IMPL_AUTO(void) SetContentFromSoftwareBitmap(llm::OS::Graphics::Imaging::SoftwareBitmap const& softwareBitmap, llm::OS::Foundation::Point const& anchorPoint) const;
        LLM_IMPL_AUTO(void) SetContentFromDataPackage() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IDragUI>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IDragUI<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IDragUIOverride
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Caption() const;
        LLM_IMPL_AUTO(void) Caption(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsContentVisible() const;
        LLM_IMPL_AUTO(void) IsContentVisible(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsCaptionVisible() const;
        LLM_IMPL_AUTO(void) IsCaptionVisible(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsGlyphVisible() const;
        LLM_IMPL_AUTO(void) IsGlyphVisible(bool value) const;
        LLM_IMPL_AUTO(void) Clear() const;
        LLM_IMPL_AUTO(void) SetContentFromBitmapImage(llm::OS::UI::Xaml::Media::Imaging::BitmapImage const& bitmapImage) const;
        LLM_IMPL_AUTO(void) SetContentFromBitmapImage(llm::OS::UI::Xaml::Media::Imaging::BitmapImage const& bitmapImage, llm::OS::Foundation::Point const& anchorPoint) const;
        LLM_IMPL_AUTO(void) SetContentFromSoftwareBitmap(llm::OS::Graphics::Imaging::SoftwareBitmap const& softwareBitmap) const;
        LLM_IMPL_AUTO(void) SetContentFromSoftwareBitmap(llm::OS::Graphics::Imaging::SoftwareBitmap const& softwareBitmap, llm::OS::Foundation::Point const& anchorPoint) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IDragUIOverride>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IDragUIOverride<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IDropCompletedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::DataTransfer::DataPackageOperation) DropResult() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IDropCompletedEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IDropCompletedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IDurationHelper
    {
    };
    template <> struct consume<llm::OS::UI::Xaml::IDurationHelper>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IDurationHelper<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IDurationHelperStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Duration) Automatic() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Duration) Forever() const;
        LLM_IMPL_AUTO(int32_t) Compare(llm::OS::UI::Xaml::Duration const& duration1, llm::OS::UI::Xaml::Duration const& duration2) const;
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::Duration) FromTimeSpan(llm::OS::Foundation::TimeSpan const& timeSpan) const;
        LLM_IMPL_AUTO(bool) GetHasTimeSpan(llm::OS::UI::Xaml::Duration const& target) const;
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::Duration) Add(llm::OS::UI::Xaml::Duration const& target, llm::OS::UI::Xaml::Duration const& duration) const;
        LLM_IMPL_AUTO(bool) Equals(llm::OS::UI::Xaml::Duration const& target, llm::OS::UI::Xaml::Duration const& value) const;
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::Duration) Subtract(llm::OS::UI::Xaml::Duration const& target, llm::OS::UI::Xaml::Duration const& duration) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IDurationHelperStatics>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IDurationHelperStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IEffectiveViewportChangedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Rect) EffectiveViewport() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Rect) MaxViewport() const;
        [[nodiscard]] LLM_IMPL_AUTO(double) BringIntoViewDistanceX() const;
        [[nodiscard]] LLM_IMPL_AUTO(double) BringIntoViewDistanceY() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IEffectiveViewportChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IEffectiveViewportChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IElementFactory
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::UIElement) GetElement(llm::OS::UI::Xaml::ElementFactoryGetArgs const& args) const;
        LLM_IMPL_AUTO(void) RecycleElement(llm::OS::UI::Xaml::ElementFactoryRecycleArgs const& args) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IElementFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IElementFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IElementFactoryGetArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) Data() const;
        LLM_IMPL_AUTO(void) Data(llm::OS::Foundation::IInspectable const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::UIElement) Parent() const;
        LLM_IMPL_AUTO(void) Parent(llm::OS::UI::Xaml::UIElement const& value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IElementFactoryGetArgs>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IElementFactoryGetArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IElementFactoryGetArgsFactory
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::ElementFactoryGetArgs) CreateInstance(llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IElementFactoryGetArgsFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IElementFactoryGetArgsFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IElementFactoryRecycleArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::UIElement) Element() const;
        LLM_IMPL_AUTO(void) Element(llm::OS::UI::Xaml::UIElement const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::UIElement) Parent() const;
        LLM_IMPL_AUTO(void) Parent(llm::OS::UI::Xaml::UIElement const& value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IElementFactoryRecycleArgs>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IElementFactoryRecycleArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IElementFactoryRecycleArgsFactory
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::ElementFactoryRecycleArgs) CreateInstance(llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IElementFactoryRecycleArgsFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IElementFactoryRecycleArgsFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IElementSoundPlayer
    {
    };
    template <> struct consume<llm::OS::UI::Xaml::IElementSoundPlayer>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IElementSoundPlayer<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IElementSoundPlayerStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(double) Volume() const;
        LLM_IMPL_AUTO(void) Volume(double value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::ElementSoundPlayerState) State() const;
        LLM_IMPL_AUTO(void) State(llm::OS::UI::Xaml::ElementSoundPlayerState const& value) const;
        LLM_IMPL_AUTO(void) Play(llm::OS::UI::Xaml::ElementSoundKind const& sound) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IElementSoundPlayerStatics>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IElementSoundPlayerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IElementSoundPlayerStatics2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::ElementSpatialAudioMode) SpatialAudioMode() const;
        LLM_IMPL_AUTO(void) SpatialAudioMode(llm::OS::UI::Xaml::ElementSpatialAudioMode const& value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IElementSoundPlayerStatics2>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IElementSoundPlayerStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IEventTrigger
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEvent) RoutedEvent() const;
        LLM_IMPL_AUTO(void) RoutedEvent(llm::OS::UI::Xaml::RoutedEvent const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::TriggerActionCollection) Actions() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IEventTrigger>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IEventTrigger<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IExceptionRoutedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ErrorMessage() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IExceptionRoutedEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IExceptionRoutedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IExceptionRoutedEventArgsFactory
    {
    };
    template <> struct consume<llm::OS::UI::Xaml::IExceptionRoutedEventArgsFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IExceptionRoutedEventArgsFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IFrameworkElement
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::TriggerCollection) Triggers() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::ResourceDictionary) Resources() const;
        LLM_IMPL_AUTO(void) Resources(llm::OS::UI::Xaml::ResourceDictionary const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) Tag() const;
        LLM_IMPL_AUTO(void) Tag(llm::OS::Foundation::IInspectable const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Language() const;
        LLM_IMPL_AUTO(void) Language(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(double) ActualWidth() const;
        [[nodiscard]] LLM_IMPL_AUTO(double) ActualHeight() const;
        [[nodiscard]] LLM_IMPL_AUTO(double) Width() const;
        LLM_IMPL_AUTO(void) Width(double value) const;
        [[nodiscard]] LLM_IMPL_AUTO(double) Height() const;
        LLM_IMPL_AUTO(void) Height(double value) const;
        [[nodiscard]] LLM_IMPL_AUTO(double) MinWidth() const;
        LLM_IMPL_AUTO(void) MinWidth(double value) const;
        [[nodiscard]] LLM_IMPL_AUTO(double) MaxWidth() const;
        LLM_IMPL_AUTO(void) MaxWidth(double value) const;
        [[nodiscard]] LLM_IMPL_AUTO(double) MinHeight() const;
        LLM_IMPL_AUTO(void) MinHeight(double value) const;
        [[nodiscard]] LLM_IMPL_AUTO(double) MaxHeight() const;
        LLM_IMPL_AUTO(void) MaxHeight(double value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::HorizontalAlignment) HorizontalAlignment() const;
        LLM_IMPL_AUTO(void) HorizontalAlignment(llm::OS::UI::Xaml::HorizontalAlignment const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::VerticalAlignment) VerticalAlignment() const;
        LLM_IMPL_AUTO(void) VerticalAlignment(llm::OS::UI::Xaml::VerticalAlignment const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Thickness) Margin() const;
        LLM_IMPL_AUTO(void) Margin(llm::OS::UI::Xaml::Thickness const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        LLM_IMPL_AUTO(void) Name(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Uri) BaseUri() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) DataContext() const;
        LLM_IMPL_AUTO(void) DataContext(llm::OS::Foundation::IInspectable const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Style) Style() const;
        LLM_IMPL_AUTO(void) Style(llm::OS::UI::Xaml::Style const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyObject) Parent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::FlowDirection) FlowDirection() const;
        LLM_IMPL_AUTO(void) FlowDirection(llm::OS::UI::Xaml::FlowDirection const& value) const;
        LLM_IMPL_AUTO(llm::event_token) Loaded(llm::OS::UI::Xaml::RoutedEventHandler const& handler) const;
        using Loaded_revoker = impl::event_revoker<llm::OS::UI::Xaml::IFrameworkElement, &impl::abi_t<llm::OS::UI::Xaml::IFrameworkElement>::remove_Loaded>;
        [[nodiscard]] Loaded_revoker Loaded(auto_revoke_t, llm::OS::UI::Xaml::RoutedEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) Loaded(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) Unloaded(llm::OS::UI::Xaml::RoutedEventHandler const& handler) const;
        using Unloaded_revoker = impl::event_revoker<llm::OS::UI::Xaml::IFrameworkElement, &impl::abi_t<llm::OS::UI::Xaml::IFrameworkElement>::remove_Unloaded>;
        [[nodiscard]] Unloaded_revoker Unloaded(auto_revoke_t, llm::OS::UI::Xaml::RoutedEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) Unloaded(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) SizeChanged(llm::OS::UI::Xaml::SizeChangedEventHandler const& handler) const;
        using SizeChanged_revoker = impl::event_revoker<llm::OS::UI::Xaml::IFrameworkElement, &impl::abi_t<llm::OS::UI::Xaml::IFrameworkElement>::remove_SizeChanged>;
        [[nodiscard]] SizeChanged_revoker SizeChanged(auto_revoke_t, llm::OS::UI::Xaml::SizeChangedEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) SizeChanged(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) LayoutUpdated(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const;
        using LayoutUpdated_revoker = impl::event_revoker<llm::OS::UI::Xaml::IFrameworkElement, &impl::abi_t<llm::OS::UI::Xaml::IFrameworkElement>::remove_LayoutUpdated>;
        [[nodiscard]] LayoutUpdated_revoker LayoutUpdated(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) LayoutUpdated(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) FindName(param::hstring const& name) const;
        LLM_IMPL_AUTO(void) SetBinding(llm::OS::UI::Xaml::DependencyProperty const& dp, llm::OS::UI::Xaml::Data::BindingBase const& binding) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IFrameworkElement>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IFrameworkElement<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IFrameworkElement2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::ElementTheme) RequestedTheme() const;
        LLM_IMPL_AUTO(void) RequestedTheme(llm::OS::UI::Xaml::ElementTheme const& value) const;
        LLM_IMPL_AUTO(llm::event_token) DataContextChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::DataContextChangedEventArgs> const& handler) const;
        using DataContextChanged_revoker = impl::event_revoker<llm::OS::UI::Xaml::IFrameworkElement2, &impl::abi_t<llm::OS::UI::Xaml::IFrameworkElement2>::remove_DataContextChanged>;
        [[nodiscard]] DataContextChanged_revoker DataContextChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::DataContextChangedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) DataContextChanged(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::Data::BindingExpression) GetBindingExpression(llm::OS::UI::Xaml::DependencyProperty const& dp) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IFrameworkElement2>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IFrameworkElement2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IFrameworkElement3
    {
        LLM_IMPL_AUTO(llm::event_token) Loading(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::FrameworkElement, llm::OS::Foundation::IInspectable> const& handler) const;
        using Loading_revoker = impl::event_revoker<llm::OS::UI::Xaml::IFrameworkElement3, &impl::abi_t<llm::OS::UI::Xaml::IFrameworkElement3>::remove_Loading>;
        [[nodiscard]] Loading_revoker Loading(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::FrameworkElement, llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) Loading(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm::OS::UI::Xaml::IFrameworkElement3>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IFrameworkElement3<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IFrameworkElement4
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) AllowFocusOnInteraction() const;
        LLM_IMPL_AUTO(void) AllowFocusOnInteraction(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Thickness) FocusVisualMargin() const;
        LLM_IMPL_AUTO(void) FocusVisualMargin(llm::OS::UI::Xaml::Thickness const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Thickness) FocusVisualSecondaryThickness() const;
        LLM_IMPL_AUTO(void) FocusVisualSecondaryThickness(llm::OS::UI::Xaml::Thickness const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Thickness) FocusVisualPrimaryThickness() const;
        LLM_IMPL_AUTO(void) FocusVisualPrimaryThickness(llm::OS::UI::Xaml::Thickness const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Media::Brush) FocusVisualSecondaryBrush() const;
        LLM_IMPL_AUTO(void) FocusVisualSecondaryBrush(llm::OS::UI::Xaml::Media::Brush const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Media::Brush) FocusVisualPrimaryBrush() const;
        LLM_IMPL_AUTO(void) FocusVisualPrimaryBrush(llm::OS::UI::Xaml::Media::Brush const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) AllowFocusWhenDisabled() const;
        LLM_IMPL_AUTO(void) AllowFocusWhenDisabled(bool value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IFrameworkElement4>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IFrameworkElement4<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IFrameworkElement6
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::ElementTheme) ActualTheme() const;
        LLM_IMPL_AUTO(llm::event_token) ActualThemeChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::FrameworkElement, llm::OS::Foundation::IInspectable> const& handler) const;
        using ActualThemeChanged_revoker = impl::event_revoker<llm::OS::UI::Xaml::IFrameworkElement6, &impl::abi_t<llm::OS::UI::Xaml::IFrameworkElement6>::remove_ActualThemeChanged>;
        [[nodiscard]] ActualThemeChanged_revoker ActualThemeChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::FrameworkElement, llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) ActualThemeChanged(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm::OS::UI::Xaml::IFrameworkElement6>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IFrameworkElement6<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IFrameworkElement7
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsLoaded() const;
        LLM_IMPL_AUTO(llm::event_token) EffectiveViewportChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::EffectiveViewportChangedEventArgs> const& handler) const;
        using EffectiveViewportChanged_revoker = impl::event_revoker<llm::OS::UI::Xaml::IFrameworkElement7, &impl::abi_t<llm::OS::UI::Xaml::IFrameworkElement7>::remove_EffectiveViewportChanged>;
        [[nodiscard]] EffectiveViewportChanged_revoker EffectiveViewportChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::EffectiveViewportChangedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) EffectiveViewportChanged(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm::OS::UI::Xaml::IFrameworkElement7>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IFrameworkElement7<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IFrameworkElementFactory
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::FrameworkElement) CreateInstance(llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IFrameworkElementFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IFrameworkElementFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IFrameworkElementOverrides
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::Size) MeasureOverride(llm::OS::Foundation::Size const& availableSize) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Size) ArrangeOverride(llm::OS::Foundation::Size const& finalSize) const;
        LLM_IMPL_AUTO(void) OnApplyTemplate() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IFrameworkElementOverrides>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IFrameworkElementOverrides<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IFrameworkElementOverrides2
    {
        LLM_IMPL_AUTO(bool) GoToElementStateCore(param::hstring const& stateName, bool useTransitions) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IFrameworkElementOverrides2>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IFrameworkElementOverrides2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IFrameworkElementProtected7
    {
        LLM_IMPL_AUTO(void) InvalidateViewport() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IFrameworkElementProtected7>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IFrameworkElementProtected7<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IFrameworkElementStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) TagProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) LanguageProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) ActualWidthProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) ActualHeightProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) WidthProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) HeightProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) MinWidthProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) MaxWidthProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) MinHeightProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) MaxHeightProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) HorizontalAlignmentProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) VerticalAlignmentProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) MarginProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) NameProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) DataContextProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) StyleProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) FlowDirectionProperty() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IFrameworkElementStatics>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IFrameworkElementStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IFrameworkElementStatics2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) RequestedThemeProperty() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IFrameworkElementStatics2>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IFrameworkElementStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IFrameworkElementStatics4
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) AllowFocusOnInteractionProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) FocusVisualMarginProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) FocusVisualSecondaryThicknessProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) FocusVisualPrimaryThicknessProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) FocusVisualSecondaryBrushProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) FocusVisualPrimaryBrushProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) AllowFocusWhenDisabledProperty() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IFrameworkElementStatics4>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IFrameworkElementStatics4<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IFrameworkElementStatics5
    {
        LLM_IMPL_AUTO(void) DeferTree(llm::OS::UI::Xaml::DependencyObject const& element) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IFrameworkElementStatics5>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IFrameworkElementStatics5<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IFrameworkElementStatics6
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) ActualThemeProperty() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IFrameworkElementStatics6>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IFrameworkElementStatics6<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IFrameworkTemplate
    {
    };
    template <> struct consume<llm::OS::UI::Xaml::IFrameworkTemplate>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IFrameworkTemplate<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IFrameworkTemplateFactory
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::FrameworkTemplate) CreateInstance(llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IFrameworkTemplateFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IFrameworkTemplateFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IFrameworkView
    {
    };
    template <> struct consume<llm::OS::UI::Xaml::IFrameworkView>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IFrameworkView<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IFrameworkViewSource
    {
    };
    template <> struct consume<llm::OS::UI::Xaml::IFrameworkViewSource>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IFrameworkViewSource<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IGridLengthHelper
    {
    };
    template <> struct consume<llm::OS::UI::Xaml::IGridLengthHelper>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IGridLengthHelper<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IGridLengthHelperStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::GridLength) Auto() const;
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::GridLength) FromPixels(double pixels) const;
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::GridLength) FromValueAndType(double value, llm::OS::UI::Xaml::GridUnitType const& type) const;
        LLM_IMPL_AUTO(bool) GetIsAbsolute(llm::OS::UI::Xaml::GridLength const& target) const;
        LLM_IMPL_AUTO(bool) GetIsAuto(llm::OS::UI::Xaml::GridLength const& target) const;
        LLM_IMPL_AUTO(bool) GetIsStar(llm::OS::UI::Xaml::GridLength const& target) const;
        LLM_IMPL_AUTO(bool) Equals(llm::OS::UI::Xaml::GridLength const& target, llm::OS::UI::Xaml::GridLength const& value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IGridLengthHelperStatics>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IGridLengthHelperStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IMediaFailedRoutedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ErrorTrace() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IMediaFailedRoutedEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IMediaFailedRoutedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IPointHelper
    {
    };
    template <> struct consume<llm::OS::UI::Xaml::IPointHelper>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IPointHelper<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IPointHelperStatics
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::Point) FromCoordinates(float x, float y) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IPointHelperStatics>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IPointHelperStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IPropertyMetadata
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) DefaultValue() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::CreateDefaultValueCallback) CreateDefaultValueCallback() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IPropertyMetadata>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IPropertyMetadata<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IPropertyMetadataFactory
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::PropertyMetadata) CreateInstanceWithDefaultValue(llm::OS::Foundation::IInspectable const& defaultValue, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const;
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::PropertyMetadata) CreateInstanceWithDefaultValueAndCallback(llm::OS::Foundation::IInspectable const& defaultValue, llm::OS::UI::Xaml::PropertyChangedCallback const& propertyChangedCallback, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IPropertyMetadataFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IPropertyMetadataFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IPropertyMetadataStatics
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::PropertyMetadata) Create(llm::OS::Foundation::IInspectable const& defaultValue) const;
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::PropertyMetadata) Create(llm::OS::Foundation::IInspectable const& defaultValue, llm::OS::UI::Xaml::PropertyChangedCallback const& propertyChangedCallback) const;
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::PropertyMetadata) Create(llm::OS::UI::Xaml::CreateDefaultValueCallback const& createDefaultValueCallback) const;
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::PropertyMetadata) Create(llm::OS::UI::Xaml::CreateDefaultValueCallback const& createDefaultValueCallback, llm::OS::UI::Xaml::PropertyChangedCallback const& propertyChangedCallback) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IPropertyMetadataStatics>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IPropertyMetadataStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IPropertyPath
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Path() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IPropertyPath>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IPropertyPath<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IPropertyPathFactory
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::PropertyPath) CreateInstance(param::hstring const& path) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IPropertyPathFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IPropertyPathFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IRectHelper
    {
    };
    template <> struct consume<llm::OS::UI::Xaml::IRectHelper>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IRectHelper<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IRectHelperStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Rect) Empty() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Rect) FromCoordinatesAndDimensions(float x, float y, float width, float height) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Rect) FromPoints(llm::OS::Foundation::Point const& point1, llm::OS::Foundation::Point const& point2) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Rect) FromLocationAndSize(llm::OS::Foundation::Point const& location, llm::OS::Foundation::Size const& size) const;
        LLM_IMPL_AUTO(bool) GetIsEmpty(llm::OS::Foundation::Rect const& target) const;
        LLM_IMPL_AUTO(float) GetBottom(llm::OS::Foundation::Rect const& target) const;
        LLM_IMPL_AUTO(float) GetLeft(llm::OS::Foundation::Rect const& target) const;
        LLM_IMPL_AUTO(float) GetRight(llm::OS::Foundation::Rect const& target) const;
        LLM_IMPL_AUTO(float) GetTop(llm::OS::Foundation::Rect const& target) const;
        LLM_IMPL_AUTO(bool) Contains(llm::OS::Foundation::Rect const& target, llm::OS::Foundation::Point const& point) const;
        LLM_IMPL_AUTO(bool) Equals(llm::OS::Foundation::Rect const& target, llm::OS::Foundation::Rect const& value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Rect) Intersect(llm::OS::Foundation::Rect const& target, llm::OS::Foundation::Rect const& rect) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Rect) Union(llm::OS::Foundation::Rect const& target, llm::OS::Foundation::Point const& point) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Rect) Union(llm::OS::Foundation::Rect const& target, llm::OS::Foundation::Rect const& rect) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IRectHelperStatics>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IRectHelperStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IResourceDictionary
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Uri) Source() const;
        LLM_IMPL_AUTO(void) Source(llm::OS::Foundation::Uri const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::ResourceDictionary>) MergedDictionaries() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMap<llm::OS::Foundation::IInspectable, llm::OS::Foundation::IInspectable>) ThemeDictionaries() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IResourceDictionary>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IResourceDictionary<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IResourceDictionaryFactory
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::ResourceDictionary) CreateInstance(llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IResourceDictionaryFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IResourceDictionaryFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IRoutedEvent
    {
    };
    template <> struct consume<llm::OS::UI::Xaml::IRoutedEvent>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IRoutedEvent<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IRoutedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) OriginalSource() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IRoutedEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IRoutedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IRoutedEventArgsFactory
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEventArgs) CreateInstance(llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IRoutedEventArgsFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IRoutedEventArgsFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IScalarTransition
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) Duration() const;
        LLM_IMPL_AUTO(void) Duration(llm::OS::Foundation::TimeSpan const& value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IScalarTransition>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IScalarTransition<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IScalarTransitionFactory
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::ScalarTransition) CreateInstance(llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IScalarTransitionFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IScalarTransitionFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_ISetter
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) Property() const;
        LLM_IMPL_AUTO(void) Property(llm::OS::UI::Xaml::DependencyProperty const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) Value() const;
        LLM_IMPL_AUTO(void) Value(llm::OS::Foundation::IInspectable const& value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::ISetter>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_ISetter<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_ISetter2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::TargetPropertyPath) Target() const;
        LLM_IMPL_AUTO(void) Target(llm::OS::UI::Xaml::TargetPropertyPath const& value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::ISetter2>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_ISetter2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_ISetterBase
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsSealed() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::ISetterBase>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_ISetterBase<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_ISetterBaseCollection
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsSealed() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::ISetterBaseCollection>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_ISetterBaseCollection<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_ISetterBaseFactory
    {
    };
    template <> struct consume<llm::OS::UI::Xaml::ISetterBaseFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_ISetterBaseFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_ISetterFactory
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::Setter) CreateInstance(llm::OS::UI::Xaml::DependencyProperty const& targetProperty, llm::OS::Foundation::IInspectable const& value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::ISetterFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_ISetterFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_ISizeChangedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Size) PreviousSize() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Size) NewSize() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::ISizeChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_ISizeChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_ISizeHelper
    {
    };
    template <> struct consume<llm::OS::UI::Xaml::ISizeHelper>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_ISizeHelper<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_ISizeHelperStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Size) Empty() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Size) FromDimensions(float width, float height) const;
        LLM_IMPL_AUTO(bool) GetIsEmpty(llm::OS::Foundation::Size const& target) const;
        LLM_IMPL_AUTO(bool) Equals(llm::OS::Foundation::Size const& target, llm::OS::Foundation::Size const& value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::ISizeHelperStatics>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_ISizeHelperStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IStateTrigger
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsActive() const;
        LLM_IMPL_AUTO(void) IsActive(bool value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IStateTrigger>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IStateTrigger<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IStateTriggerBase
    {
    };
    template <> struct consume<llm::OS::UI::Xaml::IStateTriggerBase>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IStateTriggerBase<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IStateTriggerBaseFactory
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::StateTriggerBase) CreateInstance(llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IStateTriggerBaseFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IStateTriggerBaseFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IStateTriggerBaseProtected
    {
        LLM_IMPL_AUTO(void) SetActive(bool IsActive) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IStateTriggerBaseProtected>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IStateTriggerBaseProtected<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IStateTriggerStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) IsActiveProperty() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IStateTriggerStatics>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IStateTriggerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IStyle
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsSealed() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::SetterBaseCollection) Setters() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Interop::TypeName) TargetType() const;
        LLM_IMPL_AUTO(void) TargetType(llm::OS::UI::Xaml::Interop::TypeName const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Style) BasedOn() const;
        LLM_IMPL_AUTO(void) BasedOn(llm::OS::UI::Xaml::Style const& value) const;
        LLM_IMPL_AUTO(void) Seal() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IStyle>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IStyle<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IStyleFactory
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::Style) CreateInstance(llm::OS::UI::Xaml::Interop::TypeName const& targetType) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IStyleFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IStyleFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_ITargetPropertyPath
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::PropertyPath) Path() const;
        LLM_IMPL_AUTO(void) Path(llm::OS::UI::Xaml::PropertyPath const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) Target() const;
        LLM_IMPL_AUTO(void) Target(llm::OS::Foundation::IInspectable const& value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::ITargetPropertyPath>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_ITargetPropertyPath<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_ITargetPropertyPathFactory
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::TargetPropertyPath) CreateInstance(llm::OS::UI::Xaml::DependencyProperty const& targetProperty) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::ITargetPropertyPathFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_ITargetPropertyPathFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IThicknessHelper
    {
    };
    template <> struct consume<llm::OS::UI::Xaml::IThicknessHelper>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IThicknessHelper<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IThicknessHelperStatics
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::Thickness) FromLengths(double left, double top, double right, double bottom) const;
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::Thickness) FromUniformLength(double uniformLength) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IThicknessHelperStatics>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IThicknessHelperStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_ITriggerAction
    {
    };
    template <> struct consume<llm::OS::UI::Xaml::ITriggerAction>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_ITriggerAction<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_ITriggerActionFactory
    {
    };
    template <> struct consume<llm::OS::UI::Xaml::ITriggerActionFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_ITriggerActionFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_ITriggerBase
    {
    };
    template <> struct consume<llm::OS::UI::Xaml::ITriggerBase>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_ITriggerBase<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_ITriggerBaseFactory
    {
    };
    template <> struct consume<llm::OS::UI::Xaml::ITriggerBaseFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_ITriggerBaseFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IUIElement
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Size) DesiredSize() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) AllowDrop() const;
        LLM_IMPL_AUTO(void) AllowDrop(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(double) Opacity() const;
        LLM_IMPL_AUTO(void) Opacity(double value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Media::RectangleGeometry) Clip() const;
        LLM_IMPL_AUTO(void) Clip(llm::OS::UI::Xaml::Media::RectangleGeometry const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Media::Transform) RenderTransform() const;
        LLM_IMPL_AUTO(void) RenderTransform(llm::OS::UI::Xaml::Media::Transform const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Media::Projection) Projection() const;
        LLM_IMPL_AUTO(void) Projection(llm::OS::UI::Xaml::Media::Projection const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Point) RenderTransformOrigin() const;
        LLM_IMPL_AUTO(void) RenderTransformOrigin(llm::OS::Foundation::Point const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsHitTestVisible() const;
        LLM_IMPL_AUTO(void) IsHitTestVisible(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Visibility) Visibility() const;
        LLM_IMPL_AUTO(void) Visibility(llm::OS::UI::Xaml::Visibility const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Size) RenderSize() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) UseLayoutRounding() const;
        LLM_IMPL_AUTO(void) UseLayoutRounding(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Media::Animation::TransitionCollection) Transitions() const;
        LLM_IMPL_AUTO(void) Transitions(llm::OS::UI::Xaml::Media::Animation::TransitionCollection const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Media::CacheMode) CacheMode() const;
        LLM_IMPL_AUTO(void) CacheMode(llm::OS::UI::Xaml::Media::CacheMode const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsTapEnabled() const;
        LLM_IMPL_AUTO(void) IsTapEnabled(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsDoubleTapEnabled() const;
        LLM_IMPL_AUTO(void) IsDoubleTapEnabled(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsRightTapEnabled() const;
        LLM_IMPL_AUTO(void) IsRightTapEnabled(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsHoldingEnabled() const;
        LLM_IMPL_AUTO(void) IsHoldingEnabled(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Input::ManipulationModes) ManipulationMode() const;
        LLM_IMPL_AUTO(void) ManipulationMode(llm::OS::UI::Xaml::Input::ManipulationModes const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::Xaml::Input::Pointer>) PointerCaptures() const;
        LLM_IMPL_AUTO(llm::event_token) KeyUp(llm::OS::UI::Xaml::Input::KeyEventHandler const& handler) const;
        using KeyUp_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement, &impl::abi_t<llm::OS::UI::Xaml::IUIElement>::remove_KeyUp>;
        [[nodiscard]] KeyUp_revoker KeyUp(auto_revoke_t, llm::OS::UI::Xaml::Input::KeyEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) KeyUp(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) KeyDown(llm::OS::UI::Xaml::Input::KeyEventHandler const& handler) const;
        using KeyDown_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement, &impl::abi_t<llm::OS::UI::Xaml::IUIElement>::remove_KeyDown>;
        [[nodiscard]] KeyDown_revoker KeyDown(auto_revoke_t, llm::OS::UI::Xaml::Input::KeyEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) KeyDown(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) GotFocus(llm::OS::UI::Xaml::RoutedEventHandler const& handler) const;
        using GotFocus_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement, &impl::abi_t<llm::OS::UI::Xaml::IUIElement>::remove_GotFocus>;
        [[nodiscard]] GotFocus_revoker GotFocus(auto_revoke_t, llm::OS::UI::Xaml::RoutedEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) GotFocus(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) LostFocus(llm::OS::UI::Xaml::RoutedEventHandler const& handler) const;
        using LostFocus_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement, &impl::abi_t<llm::OS::UI::Xaml::IUIElement>::remove_LostFocus>;
        [[nodiscard]] LostFocus_revoker LostFocus(auto_revoke_t, llm::OS::UI::Xaml::RoutedEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) LostFocus(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) DragEnter(llm::OS::UI::Xaml::DragEventHandler const& handler) const;
        using DragEnter_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement, &impl::abi_t<llm::OS::UI::Xaml::IUIElement>::remove_DragEnter>;
        [[nodiscard]] DragEnter_revoker DragEnter(auto_revoke_t, llm::OS::UI::Xaml::DragEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) DragEnter(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) DragLeave(llm::OS::UI::Xaml::DragEventHandler const& handler) const;
        using DragLeave_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement, &impl::abi_t<llm::OS::UI::Xaml::IUIElement>::remove_DragLeave>;
        [[nodiscard]] DragLeave_revoker DragLeave(auto_revoke_t, llm::OS::UI::Xaml::DragEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) DragLeave(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) DragOver(llm::OS::UI::Xaml::DragEventHandler const& handler) const;
        using DragOver_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement, &impl::abi_t<llm::OS::UI::Xaml::IUIElement>::remove_DragOver>;
        [[nodiscard]] DragOver_revoker DragOver(auto_revoke_t, llm::OS::UI::Xaml::DragEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) DragOver(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) Drop(llm::OS::UI::Xaml::DragEventHandler const& handler) const;
        using Drop_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement, &impl::abi_t<llm::OS::UI::Xaml::IUIElement>::remove_Drop>;
        [[nodiscard]] Drop_revoker Drop(auto_revoke_t, llm::OS::UI::Xaml::DragEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) Drop(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) PointerPressed(llm::OS::UI::Xaml::Input::PointerEventHandler const& handler) const;
        using PointerPressed_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement, &impl::abi_t<llm::OS::UI::Xaml::IUIElement>::remove_PointerPressed>;
        [[nodiscard]] PointerPressed_revoker PointerPressed(auto_revoke_t, llm::OS::UI::Xaml::Input::PointerEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) PointerPressed(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) PointerMoved(llm::OS::UI::Xaml::Input::PointerEventHandler const& handler) const;
        using PointerMoved_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement, &impl::abi_t<llm::OS::UI::Xaml::IUIElement>::remove_PointerMoved>;
        [[nodiscard]] PointerMoved_revoker PointerMoved(auto_revoke_t, llm::OS::UI::Xaml::Input::PointerEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) PointerMoved(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) PointerReleased(llm::OS::UI::Xaml::Input::PointerEventHandler const& handler) const;
        using PointerReleased_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement, &impl::abi_t<llm::OS::UI::Xaml::IUIElement>::remove_PointerReleased>;
        [[nodiscard]] PointerReleased_revoker PointerReleased(auto_revoke_t, llm::OS::UI::Xaml::Input::PointerEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) PointerReleased(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) PointerEntered(llm::OS::UI::Xaml::Input::PointerEventHandler const& handler) const;
        using PointerEntered_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement, &impl::abi_t<llm::OS::UI::Xaml::IUIElement>::remove_PointerEntered>;
        [[nodiscard]] PointerEntered_revoker PointerEntered(auto_revoke_t, llm::OS::UI::Xaml::Input::PointerEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) PointerEntered(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) PointerExited(llm::OS::UI::Xaml::Input::PointerEventHandler const& handler) const;
        using PointerExited_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement, &impl::abi_t<llm::OS::UI::Xaml::IUIElement>::remove_PointerExited>;
        [[nodiscard]] PointerExited_revoker PointerExited(auto_revoke_t, llm::OS::UI::Xaml::Input::PointerEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) PointerExited(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) PointerCaptureLost(llm::OS::UI::Xaml::Input::PointerEventHandler const& handler) const;
        using PointerCaptureLost_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement, &impl::abi_t<llm::OS::UI::Xaml::IUIElement>::remove_PointerCaptureLost>;
        [[nodiscard]] PointerCaptureLost_revoker PointerCaptureLost(auto_revoke_t, llm::OS::UI::Xaml::Input::PointerEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) PointerCaptureLost(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) PointerCanceled(llm::OS::UI::Xaml::Input::PointerEventHandler const& handler) const;
        using PointerCanceled_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement, &impl::abi_t<llm::OS::UI::Xaml::IUIElement>::remove_PointerCanceled>;
        [[nodiscard]] PointerCanceled_revoker PointerCanceled(auto_revoke_t, llm::OS::UI::Xaml::Input::PointerEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) PointerCanceled(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) PointerWheelChanged(llm::OS::UI::Xaml::Input::PointerEventHandler const& handler) const;
        using PointerWheelChanged_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement, &impl::abi_t<llm::OS::UI::Xaml::IUIElement>::remove_PointerWheelChanged>;
        [[nodiscard]] PointerWheelChanged_revoker PointerWheelChanged(auto_revoke_t, llm::OS::UI::Xaml::Input::PointerEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) PointerWheelChanged(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) Tapped(llm::OS::UI::Xaml::Input::TappedEventHandler const& handler) const;
        using Tapped_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement, &impl::abi_t<llm::OS::UI::Xaml::IUIElement>::remove_Tapped>;
        [[nodiscard]] Tapped_revoker Tapped(auto_revoke_t, llm::OS::UI::Xaml::Input::TappedEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) Tapped(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) DoubleTapped(llm::OS::UI::Xaml::Input::DoubleTappedEventHandler const& handler) const;
        using DoubleTapped_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement, &impl::abi_t<llm::OS::UI::Xaml::IUIElement>::remove_DoubleTapped>;
        [[nodiscard]] DoubleTapped_revoker DoubleTapped(auto_revoke_t, llm::OS::UI::Xaml::Input::DoubleTappedEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) DoubleTapped(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) Holding(llm::OS::UI::Xaml::Input::HoldingEventHandler const& handler) const;
        using Holding_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement, &impl::abi_t<llm::OS::UI::Xaml::IUIElement>::remove_Holding>;
        [[nodiscard]] Holding_revoker Holding(auto_revoke_t, llm::OS::UI::Xaml::Input::HoldingEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) Holding(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) RightTapped(llm::OS::UI::Xaml::Input::RightTappedEventHandler const& handler) const;
        using RightTapped_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement, &impl::abi_t<llm::OS::UI::Xaml::IUIElement>::remove_RightTapped>;
        [[nodiscard]] RightTapped_revoker RightTapped(auto_revoke_t, llm::OS::UI::Xaml::Input::RightTappedEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) RightTapped(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) ManipulationStarting(llm::OS::UI::Xaml::Input::ManipulationStartingEventHandler const& handler) const;
        using ManipulationStarting_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement, &impl::abi_t<llm::OS::UI::Xaml::IUIElement>::remove_ManipulationStarting>;
        [[nodiscard]] ManipulationStarting_revoker ManipulationStarting(auto_revoke_t, llm::OS::UI::Xaml::Input::ManipulationStartingEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) ManipulationStarting(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) ManipulationInertiaStarting(llm::OS::UI::Xaml::Input::ManipulationInertiaStartingEventHandler const& handler) const;
        using ManipulationInertiaStarting_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement, &impl::abi_t<llm::OS::UI::Xaml::IUIElement>::remove_ManipulationInertiaStarting>;
        [[nodiscard]] ManipulationInertiaStarting_revoker ManipulationInertiaStarting(auto_revoke_t, llm::OS::UI::Xaml::Input::ManipulationInertiaStartingEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) ManipulationInertiaStarting(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) ManipulationStarted(llm::OS::UI::Xaml::Input::ManipulationStartedEventHandler const& handler) const;
        using ManipulationStarted_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement, &impl::abi_t<llm::OS::UI::Xaml::IUIElement>::remove_ManipulationStarted>;
        [[nodiscard]] ManipulationStarted_revoker ManipulationStarted(auto_revoke_t, llm::OS::UI::Xaml::Input::ManipulationStartedEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) ManipulationStarted(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) ManipulationDelta(llm::OS::UI::Xaml::Input::ManipulationDeltaEventHandler const& handler) const;
        using ManipulationDelta_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement, &impl::abi_t<llm::OS::UI::Xaml::IUIElement>::remove_ManipulationDelta>;
        [[nodiscard]] ManipulationDelta_revoker ManipulationDelta(auto_revoke_t, llm::OS::UI::Xaml::Input::ManipulationDeltaEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) ManipulationDelta(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) ManipulationCompleted(llm::OS::UI::Xaml::Input::ManipulationCompletedEventHandler const& handler) const;
        using ManipulationCompleted_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement, &impl::abi_t<llm::OS::UI::Xaml::IUIElement>::remove_ManipulationCompleted>;
        [[nodiscard]] ManipulationCompleted_revoker ManipulationCompleted(auto_revoke_t, llm::OS::UI::Xaml::Input::ManipulationCompletedEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) ManipulationCompleted(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(void) Measure(llm::OS::Foundation::Size const& availableSize) const;
        LLM_IMPL_AUTO(void) Arrange(llm::OS::Foundation::Rect const& finalRect) const;
        LLM_IMPL_AUTO(bool) CapturePointer(llm::OS::UI::Xaml::Input::Pointer const& value) const;
        LLM_IMPL_AUTO(void) ReleasePointerCapture(llm::OS::UI::Xaml::Input::Pointer const& value) const;
        LLM_IMPL_AUTO(void) ReleasePointerCaptures() const;
        LLM_IMPL_AUTO(void) AddHandler(llm::OS::UI::Xaml::RoutedEvent const& routedEvent, llm::OS::Foundation::IInspectable const& handler, bool handledEventsToo) const;
        LLM_IMPL_AUTO(void) RemoveHandler(llm::OS::UI::Xaml::RoutedEvent const& routedEvent, llm::OS::Foundation::IInspectable const& handler) const;
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::Media::GeneralTransform) TransformToVisual(llm::OS::UI::Xaml::UIElement const& visual) const;
        LLM_IMPL_AUTO(void) InvalidateMeasure() const;
        LLM_IMPL_AUTO(void) InvalidateArrange() const;
        LLM_IMPL_AUTO(void) UpdateLayout() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IUIElement>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IUIElement<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IUIElement10
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) ActualOffset() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) ActualSize() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::XamlRoot) XamlRoot() const;
        LLM_IMPL_AUTO(void) XamlRoot(llm::OS::UI::Xaml::XamlRoot const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::UIContext) UIContext() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Media::Shadow) Shadow() const;
        LLM_IMPL_AUTO(void) Shadow(llm::OS::UI::Xaml::Media::Shadow const& value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IUIElement10>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IUIElement10<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IUIElement2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Media::ElementCompositeMode) CompositeMode() const;
        LLM_IMPL_AUTO(void) CompositeMode(llm::OS::UI::Xaml::Media::ElementCompositeMode const& value) const;
        LLM_IMPL_AUTO(bool) CancelDirectManipulations() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IUIElement2>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IUIElement2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IUIElement3
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Media::Media3D::Transform3D) Transform3D() const;
        LLM_IMPL_AUTO(void) Transform3D(llm::OS::UI::Xaml::Media::Media3D::Transform3D const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) CanDrag() const;
        LLM_IMPL_AUTO(void) CanDrag(bool value) const;
        LLM_IMPL_AUTO(llm::event_token) DragStarting(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DragStartingEventArgs> const& handler) const;
        using DragStarting_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement3, &impl::abi_t<llm::OS::UI::Xaml::IUIElement3>::remove_DragStarting>;
        [[nodiscard]] DragStarting_revoker DragStarting(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DragStartingEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) DragStarting(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) DropCompleted(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DropCompletedEventArgs> const& handler) const;
        using DropCompleted_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement3, &impl::abi_t<llm::OS::UI::Xaml::IUIElement3>::remove_DropCompleted>;
        [[nodiscard]] DropCompleted_revoker DropCompleted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DropCompletedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) DropCompleted(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::DataTransfer::DataPackageOperation>) StartDragAsync(llm::OS::UI::Input::PointerPoint const& pointerPoint) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IUIElement3>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IUIElement3<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IUIElement4
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Controls::Primitives::FlyoutBase) ContextFlyout() const;
        LLM_IMPL_AUTO(void) ContextFlyout(llm::OS::UI::Xaml::Controls::Primitives::FlyoutBase const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) ExitDisplayModeOnAccessKeyInvoked() const;
        LLM_IMPL_AUTO(void) ExitDisplayModeOnAccessKeyInvoked(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsAccessKeyScope() const;
        LLM_IMPL_AUTO(void) IsAccessKeyScope(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyObject) AccessKeyScopeOwner() const;
        LLM_IMPL_AUTO(void) AccessKeyScopeOwner(llm::OS::UI::Xaml::DependencyObject const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AccessKey() const;
        LLM_IMPL_AUTO(void) AccessKey(param::hstring const& value) const;
        LLM_IMPL_AUTO(llm::event_token) ContextRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::Input::ContextRequestedEventArgs> const& handler) const;
        using ContextRequested_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement4, &impl::abi_t<llm::OS::UI::Xaml::IUIElement4>::remove_ContextRequested>;
        [[nodiscard]] ContextRequested_revoker ContextRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::Input::ContextRequestedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) ContextRequested(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) ContextCanceled(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::RoutedEventArgs> const& handler) const;
        using ContextCanceled_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement4, &impl::abi_t<llm::OS::UI::Xaml::IUIElement4>::remove_ContextCanceled>;
        [[nodiscard]] ContextCanceled_revoker ContextCanceled(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::RoutedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) ContextCanceled(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) AccessKeyDisplayRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::Input::AccessKeyDisplayRequestedEventArgs> const& handler) const;
        using AccessKeyDisplayRequested_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement4, &impl::abi_t<llm::OS::UI::Xaml::IUIElement4>::remove_AccessKeyDisplayRequested>;
        [[nodiscard]] AccessKeyDisplayRequested_revoker AccessKeyDisplayRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::Input::AccessKeyDisplayRequestedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) AccessKeyDisplayRequested(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) AccessKeyDisplayDismissed(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::Input::AccessKeyDisplayDismissedEventArgs> const& handler) const;
        using AccessKeyDisplayDismissed_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement4, &impl::abi_t<llm::OS::UI::Xaml::IUIElement4>::remove_AccessKeyDisplayDismissed>;
        [[nodiscard]] AccessKeyDisplayDismissed_revoker AccessKeyDisplayDismissed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::Input::AccessKeyDisplayDismissedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) AccessKeyDisplayDismissed(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) AccessKeyInvoked(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::Input::AccessKeyInvokedEventArgs> const& handler) const;
        using AccessKeyInvoked_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement4, &impl::abi_t<llm::OS::UI::Xaml::IUIElement4>::remove_AccessKeyInvoked>;
        [[nodiscard]] AccessKeyInvoked_revoker AccessKeyInvoked(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::Input::AccessKeyInvokedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) AccessKeyInvoked(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm::OS::UI::Xaml::IUIElement4>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IUIElement4<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IUIElement5
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Media::XamlLight>) Lights() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Input::KeyTipPlacementMode) KeyTipPlacementMode() const;
        LLM_IMPL_AUTO(void) KeyTipPlacementMode(llm::OS::UI::Xaml::Input::KeyTipPlacementMode const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(double) KeyTipHorizontalOffset() const;
        LLM_IMPL_AUTO(void) KeyTipHorizontalOffset(double value) const;
        [[nodiscard]] LLM_IMPL_AUTO(double) KeyTipVerticalOffset() const;
        LLM_IMPL_AUTO(void) KeyTipVerticalOffset(double value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Input::XYFocusKeyboardNavigationMode) XYFocusKeyboardNavigation() const;
        LLM_IMPL_AUTO(void) XYFocusKeyboardNavigation(llm::OS::UI::Xaml::Input::XYFocusKeyboardNavigationMode const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Input::XYFocusNavigationStrategy) XYFocusUpNavigationStrategy() const;
        LLM_IMPL_AUTO(void) XYFocusUpNavigationStrategy(llm::OS::UI::Xaml::Input::XYFocusNavigationStrategy const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Input::XYFocusNavigationStrategy) XYFocusDownNavigationStrategy() const;
        LLM_IMPL_AUTO(void) XYFocusDownNavigationStrategy(llm::OS::UI::Xaml::Input::XYFocusNavigationStrategy const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Input::XYFocusNavigationStrategy) XYFocusLeftNavigationStrategy() const;
        LLM_IMPL_AUTO(void) XYFocusLeftNavigationStrategy(llm::OS::UI::Xaml::Input::XYFocusNavigationStrategy const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Input::XYFocusNavigationStrategy) XYFocusRightNavigationStrategy() const;
        LLM_IMPL_AUTO(void) XYFocusRightNavigationStrategy(llm::OS::UI::Xaml::Input::XYFocusNavigationStrategy const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::ElementHighContrastAdjustment) HighContrastAdjustment() const;
        LLM_IMPL_AUTO(void) HighContrastAdjustment(llm::OS::UI::Xaml::ElementHighContrastAdjustment const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Input::KeyboardNavigationMode) TabFocusNavigation() const;
        LLM_IMPL_AUTO(void) TabFocusNavigation(llm::OS::UI::Xaml::Input::KeyboardNavigationMode const& value) const;
        LLM_IMPL_AUTO(llm::event_token) GettingFocus(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::Input::GettingFocusEventArgs> const& handler) const;
        using GettingFocus_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement5, &impl::abi_t<llm::OS::UI::Xaml::IUIElement5>::remove_GettingFocus>;
        [[nodiscard]] GettingFocus_revoker GettingFocus(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::Input::GettingFocusEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) GettingFocus(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) LosingFocus(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::Input::LosingFocusEventArgs> const& handler) const;
        using LosingFocus_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement5, &impl::abi_t<llm::OS::UI::Xaml::IUIElement5>::remove_LosingFocus>;
        [[nodiscard]] LosingFocus_revoker LosingFocus(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::Input::LosingFocusEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) LosingFocus(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) NoFocusCandidateFound(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::Input::NoFocusCandidateFoundEventArgs> const& handler) const;
        using NoFocusCandidateFound_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement5, &impl::abi_t<llm::OS::UI::Xaml::IUIElement5>::remove_NoFocusCandidateFound>;
        [[nodiscard]] NoFocusCandidateFound_revoker NoFocusCandidateFound(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::Input::NoFocusCandidateFoundEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) NoFocusCandidateFound(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(void) StartBringIntoView() const;
        LLM_IMPL_AUTO(void) StartBringIntoView(llm::OS::UI::Xaml::BringIntoViewOptions const& options) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IUIElement5>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IUIElement5<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IUIElement7
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Input::KeyboardAccelerator>) KeyboardAccelerators() const;
        LLM_IMPL_AUTO(llm::event_token) CharacterReceived(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::Input::CharacterReceivedRoutedEventArgs> const& handler) const;
        using CharacterReceived_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement7, &impl::abi_t<llm::OS::UI::Xaml::IUIElement7>::remove_CharacterReceived>;
        [[nodiscard]] CharacterReceived_revoker CharacterReceived(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::Input::CharacterReceivedRoutedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) CharacterReceived(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) ProcessKeyboardAccelerators(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::Input::ProcessKeyboardAcceleratorEventArgs> const& handler) const;
        using ProcessKeyboardAccelerators_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement7, &impl::abi_t<llm::OS::UI::Xaml::IUIElement7>::remove_ProcessKeyboardAccelerators>;
        [[nodiscard]] ProcessKeyboardAccelerators_revoker ProcessKeyboardAccelerators(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::Input::ProcessKeyboardAcceleratorEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) ProcessKeyboardAccelerators(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) PreviewKeyDown(llm::OS::UI::Xaml::Input::KeyEventHandler const& handler) const;
        using PreviewKeyDown_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement7, &impl::abi_t<llm::OS::UI::Xaml::IUIElement7>::remove_PreviewKeyDown>;
        [[nodiscard]] PreviewKeyDown_revoker PreviewKeyDown(auto_revoke_t, llm::OS::UI::Xaml::Input::KeyEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) PreviewKeyDown(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) PreviewKeyUp(llm::OS::UI::Xaml::Input::KeyEventHandler const& handler) const;
        using PreviewKeyUp_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement7, &impl::abi_t<llm::OS::UI::Xaml::IUIElement7>::remove_PreviewKeyUp>;
        [[nodiscard]] PreviewKeyUp_revoker PreviewKeyUp(auto_revoke_t, llm::OS::UI::Xaml::Input::KeyEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) PreviewKeyUp(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(void) TryInvokeKeyboardAccelerator(llm::OS::UI::Xaml::Input::ProcessKeyboardAcceleratorEventArgs const& args) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IUIElement7>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IUIElement7<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IUIElement8
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyObject) KeyTipTarget() const;
        LLM_IMPL_AUTO(void) KeyTipTarget(llm::OS::UI::Xaml::DependencyObject const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyObject) KeyboardAcceleratorPlacementTarget() const;
        LLM_IMPL_AUTO(void) KeyboardAcceleratorPlacementTarget(llm::OS::UI::Xaml::DependencyObject const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Input::KeyboardAcceleratorPlacementMode) KeyboardAcceleratorPlacementMode() const;
        LLM_IMPL_AUTO(void) KeyboardAcceleratorPlacementMode(llm::OS::UI::Xaml::Input::KeyboardAcceleratorPlacementMode const& value) const;
        LLM_IMPL_AUTO(llm::event_token) BringIntoViewRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::BringIntoViewRequestedEventArgs> const& handler) const;
        using BringIntoViewRequested_revoker = impl::event_revoker<llm::OS::UI::Xaml::IUIElement8, &impl::abi_t<llm::OS::UI::Xaml::IUIElement8>::remove_BringIntoViewRequested>;
        [[nodiscard]] BringIntoViewRequested_revoker BringIntoViewRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::BringIntoViewRequestedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) BringIntoViewRequested(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm::OS::UI::Xaml::IUIElement8>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IUIElement8<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IUIElement9
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) CanBeScrollAnchor() const;
        LLM_IMPL_AUTO(void) CanBeScrollAnchor(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::ScalarTransition) OpacityTransition() const;
        LLM_IMPL_AUTO(void) OpacityTransition(llm::OS::UI::Xaml::ScalarTransition const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) Translation() const;
        LLM_IMPL_AUTO(void) Translation(llm::OS::Foundation::Numerics::float3 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Vector3Transition) TranslationTransition() const;
        LLM_IMPL_AUTO(void) TranslationTransition(llm::OS::UI::Xaml::Vector3Transition const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) Rotation() const;
        LLM_IMPL_AUTO(void) Rotation(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::ScalarTransition) RotationTransition() const;
        LLM_IMPL_AUTO(void) RotationTransition(llm::OS::UI::Xaml::ScalarTransition const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) Scale() const;
        LLM_IMPL_AUTO(void) Scale(llm::OS::Foundation::Numerics::float3 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Vector3Transition) ScaleTransition() const;
        LLM_IMPL_AUTO(void) ScaleTransition(llm::OS::UI::Xaml::Vector3Transition const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float4x4) TransformMatrix() const;
        LLM_IMPL_AUTO(void) TransformMatrix(llm::OS::Foundation::Numerics::float4x4 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) CenterPoint() const;
        LLM_IMPL_AUTO(void) CenterPoint(llm::OS::Foundation::Numerics::float3 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) RotationAxis() const;
        LLM_IMPL_AUTO(void) RotationAxis(llm::OS::Foundation::Numerics::float3 const& value) const;
        LLM_IMPL_AUTO(void) StartAnimation(llm::OS::UI::Composition::ICompositionAnimationBase const& animation) const;
        LLM_IMPL_AUTO(void) StopAnimation(llm::OS::UI::Composition::ICompositionAnimationBase const& animation) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IUIElement9>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IUIElement9<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IUIElementFactory
    {
    };
    template <> struct consume<llm::OS::UI::Xaml::IUIElementFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IUIElementFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IUIElementOverrides
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutomationPeer) OnCreateAutomationPeer() const;
        LLM_IMPL_AUTO(void) OnDisconnectVisualChildren() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::Point>>) FindSubElementsForTouchTargeting(llm::OS::Foundation::Point const& point, llm::OS::Foundation::Rect const& boundingRect) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IUIElementOverrides>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IUIElementOverrides<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IUIElementOverrides7
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IIterable<llm::OS::UI::Xaml::DependencyObject>) GetChildrenInTabFocusOrder() const;
        LLM_IMPL_AUTO(void) OnProcessKeyboardAccelerators(llm::OS::UI::Xaml::Input::ProcessKeyboardAcceleratorEventArgs const& args) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IUIElementOverrides7>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IUIElementOverrides7<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IUIElementOverrides8
    {
        LLM_IMPL_AUTO(void) OnKeyboardAcceleratorInvoked(llm::OS::UI::Xaml::Input::KeyboardAcceleratorInvokedEventArgs const& args) const;
        LLM_IMPL_AUTO(void) OnBringIntoViewRequested(llm::OS::UI::Xaml::BringIntoViewRequestedEventArgs const& e) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IUIElementOverrides8>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IUIElementOverrides8<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IUIElementOverrides9
    {
        LLM_IMPL_AUTO(void) PopulatePropertyInfoOverride(param::hstring const& propertyName, llm::OS::UI::Composition::AnimationPropertyInfo const& animationPropertyInfo) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IUIElementOverrides9>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IUIElementOverrides9<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IUIElementStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEvent) KeyDownEvent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEvent) KeyUpEvent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEvent) PointerEnteredEvent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEvent) PointerPressedEvent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEvent) PointerMovedEvent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEvent) PointerReleasedEvent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEvent) PointerExitedEvent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEvent) PointerCaptureLostEvent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEvent) PointerCanceledEvent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEvent) PointerWheelChangedEvent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEvent) TappedEvent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEvent) DoubleTappedEvent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEvent) HoldingEvent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEvent) RightTappedEvent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEvent) ManipulationStartingEvent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEvent) ManipulationInertiaStartingEvent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEvent) ManipulationStartedEvent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEvent) ManipulationDeltaEvent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEvent) ManipulationCompletedEvent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEvent) DragEnterEvent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEvent) DragLeaveEvent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEvent) DragOverEvent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEvent) DropEvent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) AllowDropProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) OpacityProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) ClipProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) RenderTransformProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) ProjectionProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) RenderTransformOriginProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) IsHitTestVisibleProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) VisibilityProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) UseLayoutRoundingProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) TransitionsProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) CacheModeProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) IsTapEnabledProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) IsDoubleTapEnabledProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) IsRightTapEnabledProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) IsHoldingEnabledProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) ManipulationModeProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) PointerCapturesProperty() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IUIElementStatics>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IUIElementStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IUIElementStatics10
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) ShadowProperty() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IUIElementStatics10>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IUIElementStatics10<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IUIElementStatics2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) CompositeModeProperty() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IUIElementStatics2>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IUIElementStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IUIElementStatics3
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) Transform3DProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) CanDragProperty() const;
        LLM_IMPL_AUTO(bool) TryStartDirectManipulation(llm::OS::UI::Xaml::Input::Pointer const& value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IUIElementStatics3>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IUIElementStatics3<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IUIElementStatics4
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) ContextFlyoutProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) ExitDisplayModeOnAccessKeyInvokedProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) IsAccessKeyScopeProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) AccessKeyScopeOwnerProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) AccessKeyProperty() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IUIElementStatics4>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IUIElementStatics4<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IUIElementStatics5
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) LightsProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) KeyTipPlacementModeProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) KeyTipHorizontalOffsetProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) KeyTipVerticalOffsetProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) XYFocusKeyboardNavigationProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) XYFocusUpNavigationStrategyProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) XYFocusDownNavigationStrategyProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) XYFocusLeftNavigationStrategyProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) XYFocusRightNavigationStrategyProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) HighContrastAdjustmentProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) TabFocusNavigationProperty() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IUIElementStatics5>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IUIElementStatics5<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IUIElementStatics6
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEvent) GettingFocusEvent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEvent) LosingFocusEvent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEvent) NoFocusCandidateFoundEvent() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IUIElementStatics6>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IUIElementStatics6<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IUIElementStatics7
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEvent) PreviewKeyDownEvent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEvent) CharacterReceivedEvent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEvent) PreviewKeyUpEvent() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IUIElementStatics7>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IUIElementStatics7<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IUIElementStatics8
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEvent) BringIntoViewRequestedEvent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::RoutedEvent) ContextRequestedEvent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) KeyTipTargetProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) KeyboardAcceleratorPlacementTargetProperty() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) KeyboardAcceleratorPlacementModeProperty() const;
        LLM_IMPL_AUTO(void) RegisterAsScrollPort(llm::OS::UI::Xaml::UIElement const& element) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IUIElementStatics8>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IUIElementStatics8<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IUIElementStatics9
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) CanBeScrollAnchorProperty() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IUIElementStatics9>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IUIElementStatics9<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IUIElementWeakCollection
    {
    };
    template <> struct consume<llm::OS::UI::Xaml::IUIElementWeakCollection>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IUIElementWeakCollection<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IUIElementWeakCollectionFactory
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::UIElementWeakCollection) CreateInstance(llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IUIElementWeakCollectionFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IUIElementWeakCollectionFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IUnhandledExceptionEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) Exception() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Message() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) Handled() const;
        LLM_IMPL_AUTO(void) Handled(bool value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IUnhandledExceptionEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IUnhandledExceptionEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IVector3Transition
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) Duration() const;
        LLM_IMPL_AUTO(void) Duration(llm::OS::Foundation::TimeSpan const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Vector3TransitionComponents) Components() const;
        LLM_IMPL_AUTO(void) Components(llm::OS::UI::Xaml::Vector3TransitionComponents const& value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IVector3Transition>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IVector3Transition<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IVector3TransitionFactory
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::Vector3Transition) CreateInstance(llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IVector3TransitionFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IVector3TransitionFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IVisualState
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Media::Animation::Storyboard) Storyboard() const;
        LLM_IMPL_AUTO(void) Storyboard(llm::OS::UI::Xaml::Media::Animation::Storyboard const& value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IVisualState>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IVisualState<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IVisualState2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::SetterBaseCollection) Setters() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::StateTriggerBase>) StateTriggers() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IVisualState2>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IVisualState2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IVisualStateChangedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::VisualState) OldState() const;
        LLM_IMPL_AUTO(void) OldState(llm::OS::UI::Xaml::VisualState const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::VisualState) NewState() const;
        LLM_IMPL_AUTO(void) NewState(llm::OS::UI::Xaml::VisualState const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Controls::Control) Control() const;
        LLM_IMPL_AUTO(void) Control(llm::OS::UI::Xaml::Controls::Control const& value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IVisualStateChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IVisualStateChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IVisualStateGroup
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::VisualTransition>) Transitions() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::VisualState>) States() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::VisualState) CurrentState() const;
        LLM_IMPL_AUTO(llm::event_token) CurrentStateChanged(llm::OS::UI::Xaml::VisualStateChangedEventHandler const& handler) const;
        using CurrentStateChanged_revoker = impl::event_revoker<llm::OS::UI::Xaml::IVisualStateGroup, &impl::abi_t<llm::OS::UI::Xaml::IVisualStateGroup>::remove_CurrentStateChanged>;
        [[nodiscard]] CurrentStateChanged_revoker CurrentStateChanged(auto_revoke_t, llm::OS::UI::Xaml::VisualStateChangedEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) CurrentStateChanged(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) CurrentStateChanging(llm::OS::UI::Xaml::VisualStateChangedEventHandler const& handler) const;
        using CurrentStateChanging_revoker = impl::event_revoker<llm::OS::UI::Xaml::IVisualStateGroup, &impl::abi_t<llm::OS::UI::Xaml::IVisualStateGroup>::remove_CurrentStateChanging>;
        [[nodiscard]] CurrentStateChanging_revoker CurrentStateChanging(auto_revoke_t, llm::OS::UI::Xaml::VisualStateChangedEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) CurrentStateChanging(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm::OS::UI::Xaml::IVisualStateGroup>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IVisualStateGroup<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IVisualStateManager
    {
    };
    template <> struct consume<llm::OS::UI::Xaml::IVisualStateManager>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IVisualStateManager<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IVisualStateManagerFactory
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::VisualStateManager) CreateInstance(llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IVisualStateManagerFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IVisualStateManagerFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IVisualStateManagerOverrides
    {
        LLM_IMPL_AUTO(bool) GoToStateCore(llm::OS::UI::Xaml::Controls::Control const& control, llm::OS::UI::Xaml::FrameworkElement const& templateRoot, param::hstring const& stateName, llm::OS::UI::Xaml::VisualStateGroup const& group, llm::OS::UI::Xaml::VisualState const& state, bool useTransitions) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IVisualStateManagerOverrides>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IVisualStateManagerOverrides<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IVisualStateManagerProtected
    {
        LLM_IMPL_AUTO(void) RaiseCurrentStateChanging(llm::OS::UI::Xaml::VisualStateGroup const& stateGroup, llm::OS::UI::Xaml::VisualState const& oldState, llm::OS::UI::Xaml::VisualState const& newState, llm::OS::UI::Xaml::Controls::Control const& control) const;
        LLM_IMPL_AUTO(void) RaiseCurrentStateChanged(llm::OS::UI::Xaml::VisualStateGroup const& stateGroup, llm::OS::UI::Xaml::VisualState const& oldState, llm::OS::UI::Xaml::VisualState const& newState, llm::OS::UI::Xaml::Controls::Control const& control) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IVisualStateManagerProtected>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IVisualStateManagerProtected<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IVisualStateManagerStatics
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::VisualStateGroup>) GetVisualStateGroups(llm::OS::UI::Xaml::FrameworkElement const& obj) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) CustomVisualStateManagerProperty() const;
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::VisualStateManager) GetCustomVisualStateManager(llm::OS::UI::Xaml::FrameworkElement const& obj) const;
        LLM_IMPL_AUTO(void) SetCustomVisualStateManager(llm::OS::UI::Xaml::FrameworkElement const& obj, llm::OS::UI::Xaml::VisualStateManager const& value) const;
        LLM_IMPL_AUTO(bool) GoToState(llm::OS::UI::Xaml::Controls::Control const& control, param::hstring const& stateName, bool useTransitions) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IVisualStateManagerStatics>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IVisualStateManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IVisualTransition
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Duration) GeneratedDuration() const;
        LLM_IMPL_AUTO(void) GeneratedDuration(llm::OS::UI::Xaml::Duration const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Media::Animation::EasingFunctionBase) GeneratedEasingFunction() const;
        LLM_IMPL_AUTO(void) GeneratedEasingFunction(llm::OS::UI::Xaml::Media::Animation::EasingFunctionBase const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) To() const;
        LLM_IMPL_AUTO(void) To(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) From() const;
        LLM_IMPL_AUTO(void) From(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Media::Animation::Storyboard) Storyboard() const;
        LLM_IMPL_AUTO(void) Storyboard(llm::OS::UI::Xaml::Media::Animation::Storyboard const& value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IVisualTransition>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IVisualTransition<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IVisualTransitionFactory
    {
        LLM_IMPL_AUTO(llm::OS::UI::Xaml::VisualTransition) CreateInstance(llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IVisualTransitionFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IVisualTransitionFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IWindow
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Rect) Bounds() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) Visible() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::UIElement) Content() const;
        LLM_IMPL_AUTO(void) Content(llm::OS::UI::Xaml::UIElement const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Core::CoreWindow) CoreWindow() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Core::CoreDispatcher) Dispatcher() const;
        LLM_IMPL_AUTO(llm::event_token) Activated(llm::OS::UI::Xaml::WindowActivatedEventHandler const& handler) const;
        using Activated_revoker = impl::event_revoker<llm::OS::UI::Xaml::IWindow, &impl::abi_t<llm::OS::UI::Xaml::IWindow>::remove_Activated>;
        [[nodiscard]] Activated_revoker Activated(auto_revoke_t, llm::OS::UI::Xaml::WindowActivatedEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) Activated(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) Closed(llm::OS::UI::Xaml::WindowClosedEventHandler const& handler) const;
        using Closed_revoker = impl::event_revoker<llm::OS::UI::Xaml::IWindow, &impl::abi_t<llm::OS::UI::Xaml::IWindow>::remove_Closed>;
        [[nodiscard]] Closed_revoker Closed(auto_revoke_t, llm::OS::UI::Xaml::WindowClosedEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) Closed(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) SizeChanged(llm::OS::UI::Xaml::WindowSizeChangedEventHandler const& handler) const;
        using SizeChanged_revoker = impl::event_revoker<llm::OS::UI::Xaml::IWindow, &impl::abi_t<llm::OS::UI::Xaml::IWindow>::remove_SizeChanged>;
        [[nodiscard]] SizeChanged_revoker SizeChanged(auto_revoke_t, llm::OS::UI::Xaml::WindowSizeChangedEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) SizeChanged(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) VisibilityChanged(llm::OS::UI::Xaml::WindowVisibilityChangedEventHandler const& handler) const;
        using VisibilityChanged_revoker = impl::event_revoker<llm::OS::UI::Xaml::IWindow, &impl::abi_t<llm::OS::UI::Xaml::IWindow>::remove_VisibilityChanged>;
        [[nodiscard]] VisibilityChanged_revoker VisibilityChanged(auto_revoke_t, llm::OS::UI::Xaml::WindowVisibilityChangedEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) VisibilityChanged(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(void) Activate() const;
        LLM_IMPL_AUTO(void) Close() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IWindow>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IWindow<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IWindow2
    {
        LLM_IMPL_AUTO(void) SetTitleBar(llm::OS::UI::Xaml::UIElement const& value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IWindow2>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IWindow2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IWindow3
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Composition::Compositor) Compositor() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IWindow3>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IWindow3<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IWindow4
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::UIContext) UIContext() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IWindow4>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IWindow4<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IWindowCreatedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Window) Window() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IWindowCreatedEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IWindowCreatedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IWindowStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::Window) Current() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::IWindowStatics>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IWindowStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IXamlRoot
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Xaml::UIElement) Content() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Size) Size() const;
        [[nodiscard]] LLM_IMPL_AUTO(double) RasterizationScale() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsHostVisible() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::UIContext) UIContext() const;
        LLM_IMPL_AUTO(llm::event_token) Changed(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::XamlRoot, llm::OS::UI::Xaml::XamlRootChangedEventArgs> const& handler) const;
        using Changed_revoker = impl::event_revoker<llm::OS::UI::Xaml::IXamlRoot, &impl::abi_t<llm::OS::UI::Xaml::IXamlRoot>::remove_Changed>;
        [[nodiscard]] Changed_revoker Changed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Xaml::XamlRoot, llm::OS::UI::Xaml::XamlRootChangedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) Changed(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm::OS::UI::Xaml::IXamlRoot>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IXamlRoot<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_IXamlRootChangedEventArgs
    {
    };
    template <> struct consume<llm::OS::UI::Xaml::IXamlRootChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_IXamlRootChangedEventArgs<D>;
    };
    struct struct_Windows_UI_Xaml_CornerRadius
    {
        double TopLeft;
        double TopRight;
        double BottomRight;
        double BottomLeft;
    };
    template <> struct abi<Windows::UI::Xaml::CornerRadius>
    {
        using type = struct_Windows_UI_Xaml_CornerRadius;
    };
    struct struct_Windows_UI_Xaml_Duration
    {
        int64_t TimeSpan;
        int32_t Type;
    };
    template <> struct abi<Windows::UI::Xaml::Duration>
    {
        using type = struct_Windows_UI_Xaml_Duration;
    };
    struct struct_Windows_UI_Xaml_GridLength
    {
        double Value;
        int32_t GridUnitType;
    };
    template <> struct abi<Windows::UI::Xaml::GridLength>
    {
        using type = struct_Windows_UI_Xaml_GridLength;
    };
    struct struct_Windows_UI_Xaml_Thickness
    {
        double Left;
        double Top;
        double Right;
        double Bottom;
    };
    template <> struct abi<Windows::UI::Xaml::Thickness>
    {
        using type = struct_Windows_UI_Xaml_Thickness;
    };
}
#endif