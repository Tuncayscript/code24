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
#ifndef LLM_OS_UI_Composition_0_H
#define LLM_OS_UI_Composition_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    struct EventRegistrationToken;
    struct HResult;
    struct IAsyncAction;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename T> struct __declspec(empty_bases) IReference;
    struct Point;
    struct Size;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IIterable;
    template <typename K, typename V> struct __declspec(empty_bases) IMap;
    template <typename T> struct __declspec(empty_bases) IVector;
}
LLM_EXPORT namespace llm:OS::Foundation::Numerics
{
}
LLM_EXPORT namespace llm:OS::Graphics
{
    struct IGeometrySource2D;
    struct PointInt32;
    struct RectInt32;
    struct SizeInt32;
}
LLM_EXPORT namespace llm:OS::Graphics::DirectX
{
    enum class DirectXAlphaMode : int32_t;
    enum class DirectXColorSpace : int32_t;
    enum class DirectXPixelFormat : int32_t;
}
LLM_EXPORT namespace llm:OS::Graphics::Effects
{
    struct IGraphicsEffect;
}
LLM_EXPORT namespace llm:OS::System
{
    struct DispatcherQueue;
}
LLM_EXPORT namespace llm:OS::UI
{
    struct Color;
}
LLM_EXPORT namespace llm:OS::UI::Core
{
    struct CoreDispatcher;
}
LLM_EXPORT namespace llm:OS::UI::Composition
{
    enum class AnimationControllerProgressBehavior : int32_t
    {
        Default = 0,
        IncludesDelayTime = 1,
    };
    enum class AnimationDelayBehavior : int32_t
    {
        SetInitialValueAfterDelay = 0,
        SetInitialValueBeforeDelay = 1,
    };
    enum class AnimationDirection : int32_t
    {
        Normal = 0,
        Reverse = 1,
        Alternate = 2,
        AlternateReverse = 3,
    };
    enum class AnimationIterationBehavior : int32_t
    {
        Count = 0,
        Forever = 1,
    };
    enum class AnimationPropertyAccessMode : int32_t
    {
        None = 0,
        ReadOnly = 1,
        WriteOnly = 2,
        ReadWrite = 3,
    };
    enum class AnimationStopBehavior : int32_t
    {
        LeaveCurrentValue = 0,
        SetToInitialValue = 1,
        SetToFinalValue = 2,
    };
    enum class CompositionBackfaceVisibility : int32_t
    {
        Inherit = 0,
        Visible = 1,
        Hidden = 2,
    };
    enum class CompositionBatchTypes : uint32_t
    {
        None = 0,
        Animation = 0x1,
        Effect = 0x2,
        InfiniteAnimation = 0x4,
        AllAnimations = 0x5,
    };
    enum class CompositionBitmapInterpolationMode : int32_t
    {
        NearestNeighbor = 0,
        Linear = 1,
        MagLinearMinLinearMipLinear = 2,
        MagLinearMinLinearMipNearest = 3,
        MagLinearMinNearestMipLinear = 4,
        MagLinearMinNearestMipNearest = 5,
        MagNearestMinLinearMipLinear = 6,
        MagNearestMinLinearMipNearest = 7,
        MagNearestMinNearestMipLinear = 8,
        MagNearestMinNearestMipNearest = 9,
    };
    enum class CompositionBorderMode : int32_t
    {
        Inherit = 0,
        Soft = 1,
        Hard = 2,
    };
    enum class CompositionColorSpace : int32_t
    {
        Auto = 0,
        Hsl = 1,
        Rgb = 2,
        HslLinear = 3,
        RgbLinear = 4,
    };
    enum class CompositionCompositeMode : int32_t
    {
        Inherit = 0,
        SourceOver = 1,
        DestinationInvert = 2,
        MinBlend = 3,
    };
    enum class CompositionDropShadowSourcePolicy : int32_t
    {
        Default = 0,
        InheritFromVisualContent = 1,
    };
    enum class CompositionEasingFunctionMode : int32_t
    {
        In = 0,
        Out = 1,
        InOut = 2,
    };
    enum class CompositionEffectFactoryLoadStatus : int32_t
    {
        Success = 0,
        EffectTooComplex = 1,
        Pending = 2,
        Other = -1,
    };
    enum class CompositionGetValueStatus : int32_t
    {
        Succeeded = 0,
        TypeMismatch = 1,
        NotFound = 2,
    };
    enum class CompositionGradientExtendMode : int32_t
    {
        Clamp = 0,
        Wrap = 1,
        Mirror = 2,
    };
    enum class CompositionMappingMode : int32_t
    {
        Absolute = 0,
        Relative = 1,
    };
    enum class CompositionStretch : int32_t
    {
        None = 0,
        Fill = 1,
        Uniform = 2,
        UniformToFill = 3,
    };
    enum class CompositionStrokeCap : int32_t
    {
        Flat = 0,
        Square = 1,
        Round = 2,
        Triangle = 3,
    };
    enum class CompositionStrokeLineJoin : int32_t
    {
        Miter = 0,
        Bevel = 1,
        Round = 2,
        MiterOrBevel = 3,
    };
    struct IAmbientLight;
    struct IAmbientLight2;
    struct IAnimationController;
    struct IAnimationControllerStatics;
    struct IAnimationObject;
    struct IAnimationPropertyInfo;
    struct IAnimationPropertyInfo2;
    struct IBackEasingFunction;
    struct IBooleanKeyFrameAnimation;
    struct IBounceEasingFunction;
    struct IBounceScalarNaturalMotionAnimation;
    struct IBounceVector2NaturalMotionAnimation;
    struct IBounceVector3NaturalMotionAnimation;
    struct ICircleEasingFunction;
    struct IColorKeyFrameAnimation;
    struct ICompositionAnimation;
    struct ICompositionAnimation2;
    struct ICompositionAnimation3;
    struct ICompositionAnimation4;
    struct ICompositionAnimationBase;
    struct ICompositionAnimationFactory;
    struct ICompositionAnimationGroup;
    struct ICompositionBackdropBrush;
    struct ICompositionBatchCompletedEventArgs;
    struct ICompositionBrush;
    struct ICompositionBrushFactory;
    struct ICompositionCapabilities;
    struct ICompositionCapabilitiesStatics;
    struct ICompositionClip;
    struct ICompositionClip2;
    struct ICompositionClipFactory;
    struct ICompositionColorBrush;
    struct ICompositionColorGradientStop;
    struct ICompositionColorGradientStopCollection;
    struct ICompositionCommitBatch;
    struct ICompositionContainerShape;
    struct ICompositionDrawingSurface;
    struct ICompositionDrawingSurface2;
    struct ICompositionDrawingSurfaceFactory;
    struct ICompositionEasingFunction;
    struct ICompositionEasingFunctionFactory;
    struct ICompositionEasingFunctionStatics;
    struct ICompositionEffectBrush;
    struct ICompositionEffectFactory;
    struct ICompositionEffectSourceParameter;
    struct ICompositionEffectSourceParameterFactory;
    struct ICompositionEllipseGeometry;
    struct ICompositionGeometricClip;
    struct ICompositionGeometry;
    struct ICompositionGeometryFactory;
    struct ICompositionGradientBrush;
    struct ICompositionGradientBrush2;
    struct ICompositionGradientBrushFactory;
    struct ICompositionGraphicsDevice;
    struct ICompositionGraphicsDevice2;
    struct ICompositionGraphicsDevice3;
    struct ICompositionGraphicsDevice4;
    struct ICompositionLight;
    struct ICompositionLight2;
    struct ICompositionLight3;
    struct ICompositionLightFactory;
    struct ICompositionLineGeometry;
    struct ICompositionLinearGradientBrush;
    struct ICompositionMaskBrush;
    struct ICompositionMipmapSurface;
    struct ICompositionNineGridBrush;
    struct ICompositionObject;
    struct ICompositionObject2;
    struct ICompositionObject3;
    struct ICompositionObject4;
    struct ICompositionObject5;
    struct ICompositionObjectFactory;
    struct ICompositionObjectStatics;
    struct ICompositionPath;
    struct ICompositionPathFactory;
    struct ICompositionPathGeometry;
    struct ICompositionProjectedShadow;
    struct ICompositionProjectedShadowCaster;
    struct ICompositionProjectedShadowCasterCollection;
    struct ICompositionProjectedShadowCasterCollectionStatics;
    struct ICompositionProjectedShadowReceiver;
    struct ICompositionProjectedShadowReceiverUnorderedCollection;
    struct ICompositionPropertySet;
    struct ICompositionPropertySet2;
    struct ICompositionRadialGradientBrush;
    struct ICompositionRectangleGeometry;
    struct ICompositionRoundedRectangleGeometry;
    struct ICompositionScopedBatch;
    struct ICompositionShadow;
    struct ICompositionShadowFactory;
    struct ICompositionShape;
    struct ICompositionShapeFactory;
    struct ICompositionSpriteShape;
    struct ICompositionSupportsSystemBackdrop;
    struct ICompositionSurface;
    struct ICompositionSurfaceBrush;
    struct ICompositionSurfaceBrush2;
    struct ICompositionSurfaceBrush3;
    struct ICompositionSurfaceFacade;
    struct ICompositionTarget;
    struct ICompositionTargetFactory;
    struct ICompositionTexture;
    struct ICompositionTextureFactory;
    struct ICompositionTransform;
    struct ICompositionTransformFactory;
    struct ICompositionViewBox;
    struct ICompositionVirtualDrawingSurface;
    struct ICompositionVirtualDrawingSurfaceFactory;
    struct ICompositionVisualSurface;
    struct ICompositor;
    struct ICompositor2;
    struct ICompositor3;
    struct ICompositor4;
    struct ICompositor5;
    struct ICompositor6;
    struct ICompositor7;
    struct ICompositor8;
    struct ICompositorStatics;
    struct ICompositorWithBlurredWallpaperBackdropBrush;
    struct ICompositorWithProjectedShadow;
    struct ICompositorWithRadialGradient;
    struct ICompositorWithVisualSurface;
    struct IContainerVisual;
    struct IContainerVisualFactory;
    struct ICubicBezierEasingFunction;
    struct IDelegatedInkTrailVisual;
    struct IDelegatedInkTrailVisualStatics;
    struct IDistantLight;
    struct IDistantLight2;
    struct IDropShadow;
    struct IDropShadow2;
    struct IElasticEasingFunction;
    struct IExponentialEasingFunction;
    struct IExpressionAnimation;
    struct IImplicitAnimationCollection;
    struct IInsetClip;
    struct IKeyFrameAnimation;
    struct IKeyFrameAnimation2;
    struct IKeyFrameAnimation3;
    struct IKeyFrameAnimationFactory;
    struct ILayerVisual;
    struct ILayerVisual2;
    struct ILinearEasingFunction;
    struct INaturalMotionAnimation;
    struct INaturalMotionAnimationFactory;
    struct IPathKeyFrameAnimation;
    struct IPointLight;
    struct IPointLight2;
    struct IPointLight3;
    struct IPowerEasingFunction;
    struct IQuaternionKeyFrameAnimation;
    struct IRectangleClip;
    struct IRedirectVisual;
    struct IRenderingDeviceReplacedEventArgs;
    struct IScalarKeyFrameAnimation;
    struct IScalarNaturalMotionAnimation;
    struct IScalarNaturalMotionAnimationFactory;
    struct IShapeVisual;
    struct ISineEasingFunction;
    struct ISpotLight;
    struct ISpotLight2;
    struct ISpotLight3;
    struct ISpringScalarNaturalMotionAnimation;
    struct ISpringVector2NaturalMotionAnimation;
    struct ISpringVector3NaturalMotionAnimation;
    struct ISpriteVisual;
    struct ISpriteVisual2;
    struct IStepEasingFunction;
    struct IVector2KeyFrameAnimation;
    struct IVector2NaturalMotionAnimation;
    struct IVector2NaturalMotionAnimationFactory;
    struct IVector3KeyFrameAnimation;
    struct IVector3NaturalMotionAnimation;
    struct IVector3NaturalMotionAnimationFactory;
    struct IVector4KeyFrameAnimation;
    struct IVisual;
    struct IVisual2;
    struct IVisual3;
    struct IVisual4;
    struct IVisualCollection;
    struct IVisualElement;
    struct IVisualElement2;
    struct IVisualFactory;
    struct IVisualUnorderedCollection;
    struct AmbientLight;
    struct AnimationController;
    struct AnimationPropertyInfo;
    struct BackEasingFunction;
    struct BooleanKeyFrameAnimation;
    struct BounceEasingFunction;
    struct BounceScalarNaturalMotionAnimation;
    struct BounceVector2NaturalMotionAnimation;
    struct BounceVector3NaturalMotionAnimation;
    struct CircleEasingFunction;
    struct ColorKeyFrameAnimation;
    struct CompositionAnimation;
    struct CompositionAnimationGroup;
    struct CompositionBackdropBrush;
    struct CompositionBatchCompletedEventArgs;
    struct CompositionBrush;
    struct CompositionCapabilities;
    struct CompositionClip;
    struct CompositionColorBrush;
    struct CompositionColorGradientStop;
    struct CompositionColorGradientStopCollection;
    struct CompositionCommitBatch;
    struct CompositionContainerShape;
    struct CompositionDrawingSurface;
    struct CompositionEasingFunction;
    struct CompositionEffectBrush;
    struct CompositionEffectFactory;
    struct CompositionEffectSourceParameter;
    struct CompositionEllipseGeometry;
    struct CompositionGeometricClip;
    struct CompositionGeometry;
    struct CompositionGradientBrush;
    struct CompositionGraphicsDevice;
    struct CompositionLight;
    struct CompositionLineGeometry;
    struct CompositionLinearGradientBrush;
    struct CompositionMaskBrush;
    struct CompositionMipmapSurface;
    struct CompositionNineGridBrush;
    struct CompositionObject;
    struct CompositionPath;
    struct CompositionPathGeometry;
    struct CompositionProjectedShadow;
    struct CompositionProjectedShadowCaster;
    struct CompositionProjectedShadowCasterCollection;
    struct CompositionProjectedShadowReceiver;
    struct CompositionProjectedShadowReceiverUnorderedCollection;
    struct CompositionPropertySet;
    struct CompositionRadialGradientBrush;
    struct CompositionRectangleGeometry;
    struct CompositionRoundedRectangleGeometry;
    struct CompositionScopedBatch;
    struct CompositionShadow;
    struct CompositionShape;
    struct CompositionShapeCollection;
    struct CompositionSpriteShape;
    struct CompositionStrokeDashArray;
    struct CompositionSurfaceBrush;
    struct CompositionTarget;
    struct CompositionTexture;
    struct CompositionTransform;
    struct CompositionViewBox;
    struct CompositionVirtualDrawingSurface;
    struct CompositionVisualSurface;
    struct Compositor;
    struct ContainerVisual;
    struct CubicBezierEasingFunction;
    struct DelegatedInkTrailVisual;
    struct DistantLight;
    struct DropShadow;
    struct ElasticEasingFunction;
    struct ExponentialEasingFunction;
    struct ExpressionAnimation;
    struct ImplicitAnimationCollection;
    struct InitialValueExpressionCollection;
    struct InsetClip;
    struct KeyFrameAnimation;
    struct LayerVisual;
    struct LinearEasingFunction;
    struct NaturalMotionAnimation;
    struct PathKeyFrameAnimation;
    struct PointLight;
    struct PowerEasingFunction;
    struct QuaternionKeyFrameAnimation;
    struct RectangleClip;
    struct RedirectVisual;
    struct RenderingDeviceReplacedEventArgs;
    struct ScalarKeyFrameAnimation;
    struct ScalarNaturalMotionAnimation;
    struct ShapeVisual;
    struct SineEasingFunction;
    struct SpotLight;
    struct SpringScalarNaturalMotionAnimation;
    struct SpringVector2NaturalMotionAnimation;
    struct SpringVector3NaturalMotionAnimation;
    struct SpriteVisual;
    struct StepEasingFunction;
    struct Vector2KeyFrameAnimation;
    struct Vector2NaturalMotionAnimation;
    struct Vector3KeyFrameAnimation;
    struct Vector3NaturalMotionAnimation;
    struct Vector4KeyFrameAnimation;
    struct Visual;
    struct VisualCollection;
    struct VisualUnorderedCollection;
    struct InkTrailPoint;
}
namespace llm::impl
{
    template <> struct category<llm:OS::UI::Composition::IAmbientLight>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IAmbientLight2>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IAnimationController>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IAnimationControllerStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IAnimationObject>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IAnimationPropertyInfo>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IAnimationPropertyInfo2>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IBackEasingFunction>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IBooleanKeyFrameAnimation>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IBounceEasingFunction>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IBounceScalarNaturalMotionAnimation>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IBounceVector2NaturalMotionAnimation>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IBounceVector3NaturalMotionAnimation>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICircleEasingFunction>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IColorKeyFrameAnimation>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionAnimation>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionAnimation2>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionAnimation3>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionAnimation4>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionAnimationBase>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionAnimationFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionAnimationGroup>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionBackdropBrush>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionBatchCompletedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionBrush>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionBrushFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionCapabilities>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionCapabilitiesStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionClip>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionClip2>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionClipFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionColorBrush>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionColorGradientStop>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionColorGradientStopCollection>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionCommitBatch>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionContainerShape>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionDrawingSurface>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionDrawingSurface2>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionDrawingSurfaceFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionEasingFunction>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionEasingFunctionFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionEasingFunctionStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionEffectBrush>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionEffectFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionEffectSourceParameter>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionEffectSourceParameterFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionEllipseGeometry>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionGeometricClip>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionGeometry>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionGeometryFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionGradientBrush>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionGradientBrush2>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionGradientBrushFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionGraphicsDevice>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionGraphicsDevice2>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionGraphicsDevice3>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionGraphicsDevice4>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionLight>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionLight2>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionLight3>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionLightFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionLineGeometry>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionLinearGradientBrush>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionMaskBrush>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionMipmapSurface>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionNineGridBrush>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionObject>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionObject2>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionObject3>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionObject4>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionObject5>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionObjectFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionObjectStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionPath>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionPathFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionPathGeometry>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionProjectedShadow>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionProjectedShadowCaster>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionProjectedShadowCasterCollection>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionProjectedShadowCasterCollectionStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionProjectedShadowReceiver>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionProjectedShadowReceiverUnorderedCollection>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionPropertySet>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionPropertySet2>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionRadialGradientBrush>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionRectangleGeometry>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionRoundedRectangleGeometry>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionScopedBatch>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionShadow>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionShadowFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionShape>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionShapeFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionSpriteShape>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionSupportsSystemBackdrop>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionSurface>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionSurfaceBrush>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionSurfaceBrush2>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionSurfaceBrush3>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionSurfaceFacade>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionTarget>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionTargetFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionTexture>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionTextureFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionTransform>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionTransformFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionViewBox>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionVirtualDrawingSurface>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionVirtualDrawingSurfaceFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositionVisualSurface>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositor>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositor2>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositor3>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositor4>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositor5>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositor6>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositor7>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositor8>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositorStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositorWithBlurredWallpaperBackdropBrush>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositorWithProjectedShadow>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositorWithRadialGradient>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICompositorWithVisualSurface>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IContainerVisual>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IContainerVisualFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ICubicBezierEasingFunction>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IDelegatedInkTrailVisual>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IDelegatedInkTrailVisualStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IDistantLight>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IDistantLight2>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IDropShadow>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IDropShadow2>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IElasticEasingFunction>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IExponentialEasingFunction>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IExpressionAnimation>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IImplicitAnimationCollection>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IInsetClip>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IKeyFrameAnimation>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IKeyFrameAnimation2>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IKeyFrameAnimation3>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IKeyFrameAnimationFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ILayerVisual>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ILayerVisual2>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ILinearEasingFunction>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::INaturalMotionAnimation>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::INaturalMotionAnimationFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IPathKeyFrameAnimation>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IPointLight>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IPointLight2>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IPointLight3>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IPowerEasingFunction>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IQuaternionKeyFrameAnimation>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IRectangleClip>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IRedirectVisual>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IRenderingDeviceReplacedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IScalarKeyFrameAnimation>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IScalarNaturalMotionAnimation>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IScalarNaturalMotionAnimationFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IShapeVisual>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ISineEasingFunction>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ISpotLight>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ISpotLight2>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ISpotLight3>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ISpringScalarNaturalMotionAnimation>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ISpringVector2NaturalMotionAnimation>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ISpringVector3NaturalMotionAnimation>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ISpriteVisual>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::ISpriteVisual2>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IStepEasingFunction>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IVector2KeyFrameAnimation>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IVector2NaturalMotionAnimation>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IVector2NaturalMotionAnimationFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IVector3KeyFrameAnimation>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IVector3NaturalMotionAnimation>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IVector3NaturalMotionAnimationFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IVector4KeyFrameAnimation>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IVisual>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IVisual2>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IVisual3>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IVisual4>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IVisualCollection>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IVisualElement>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IVisualElement2>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IVisualFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::IVisualUnorderedCollection>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::AmbientLight>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::AnimationController>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::AnimationPropertyInfo>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::BackEasingFunction>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::BooleanKeyFrameAnimation>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::BounceEasingFunction>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::BounceScalarNaturalMotionAnimation>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::BounceVector2NaturalMotionAnimation>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::BounceVector3NaturalMotionAnimation>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CircleEasingFunction>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::ColorKeyFrameAnimation>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionAnimation>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionAnimationGroup>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionBackdropBrush>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionBatchCompletedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionBrush>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionCapabilities>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionClip>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionColorBrush>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionColorGradientStop>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionColorGradientStopCollection>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionCommitBatch>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionContainerShape>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionDrawingSurface>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionEasingFunction>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionEffectBrush>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionEffectFactory>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionEffectSourceParameter>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionEllipseGeometry>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionGeometricClip>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionGeometry>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionGradientBrush>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionGraphicsDevice>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionLight>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionLineGeometry>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionLinearGradientBrush>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionMaskBrush>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionMipmapSurface>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionNineGridBrush>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionObject>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionPath>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionPathGeometry>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionProjectedShadow>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionProjectedShadowCaster>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionProjectedShadowCasterCollection>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionProjectedShadowReceiver>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionProjectedShadowReceiverUnorderedCollection>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionPropertySet>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionRadialGradientBrush>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionRectangleGeometry>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionRoundedRectangleGeometry>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionScopedBatch>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionShadow>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionShape>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionShapeCollection>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionSpriteShape>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionStrokeDashArray>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionSurfaceBrush>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionTarget>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionTexture>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionTransform>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionViewBox>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionVirtualDrawingSurface>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionVisualSurface>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::Compositor>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::ContainerVisual>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::CubicBezierEasingFunction>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::DelegatedInkTrailVisual>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::DistantLight>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::DropShadow>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::ElasticEasingFunction>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::ExponentialEasingFunction>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::ExpressionAnimation>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::ImplicitAnimationCollection>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::InitialValueExpressionCollection>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::InsetClip>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::KeyFrameAnimation>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::LayerVisual>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::LinearEasingFunction>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::NaturalMotionAnimation>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::PathKeyFrameAnimation>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::PointLight>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::PowerEasingFunction>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::QuaternionKeyFrameAnimation>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::RectangleClip>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::RedirectVisual>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::RenderingDeviceReplacedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::ScalarKeyFrameAnimation>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::ScalarNaturalMotionAnimation>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::ShapeVisual>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::SineEasingFunction>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::SpotLight>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::SpringScalarNaturalMotionAnimation>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::SpringVector2NaturalMotionAnimation>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::SpringVector3NaturalMotionAnimation>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::SpriteVisual>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::StepEasingFunction>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::Vector2KeyFrameAnimation>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::Vector2NaturalMotionAnimation>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::Vector3KeyFrameAnimation>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::Vector3NaturalMotionAnimation>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::Vector4KeyFrameAnimation>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::Visual>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::VisualCollection>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::VisualUnorderedCollection>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::AnimationControllerProgressBehavior>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Composition::AnimationDelayBehavior>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Composition::AnimationDirection>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Composition::AnimationIterationBehavior>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Composition::AnimationPropertyAccessMode>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Composition::AnimationStopBehavior>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionBackfaceVisibility>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionBatchTypes>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionBitmapInterpolationMode>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionBorderMode>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionColorSpace>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionCompositeMode>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionDropShadowSourcePolicy>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionEasingFunctionMode>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionEffectFactoryLoadStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionGetValueStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionGradientExtendMode>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionMappingMode>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionStretch>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionStrokeCap>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Composition::CompositionStrokeLineJoin>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Composition::InkTrailPoint>{ using type = struct_category<llm:OS::Foundation::Point, float>; };
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::AmbientLight> = L"Windows.UI.Composition.AmbientLight";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::AnimationController> = L"Windows.UI.Composition.AnimationController";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::AnimationPropertyInfo> = L"Windows.UI.Composition.AnimationPropertyInfo";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::BackEasingFunction> = L"Windows.UI.Composition.BackEasingFunction";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::BooleanKeyFrameAnimation> = L"Windows.UI.Composition.BooleanKeyFrameAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::BounceEasingFunction> = L"Windows.UI.Composition.BounceEasingFunction";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::BounceScalarNaturalMotionAnimation> = L"Windows.UI.Composition.BounceScalarNaturalMotionAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::BounceVector2NaturalMotionAnimation> = L"Windows.UI.Composition.BounceVector2NaturalMotionAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::BounceVector3NaturalMotionAnimation> = L"Windows.UI.Composition.BounceVector3NaturalMotionAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CircleEasingFunction> = L"Windows.UI.Composition.CircleEasingFunction";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ColorKeyFrameAnimation> = L"Windows.UI.Composition.ColorKeyFrameAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionAnimation> = L"Windows.UI.Composition.CompositionAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionAnimationGroup> = L"Windows.UI.Composition.CompositionAnimationGroup";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionBackdropBrush> = L"Windows.UI.Composition.CompositionBackdropBrush";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionBatchCompletedEventArgs> = L"Windows.UI.Composition.CompositionBatchCompletedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionBrush> = L"Windows.UI.Composition.CompositionBrush";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionCapabilities> = L"Windows.UI.Composition.CompositionCapabilities";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionClip> = L"Windows.UI.Composition.CompositionClip";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionColorBrush> = L"Windows.UI.Composition.CompositionColorBrush";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionColorGradientStop> = L"Windows.UI.Composition.CompositionColorGradientStop";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionColorGradientStopCollection> = L"Windows.UI.Composition.CompositionColorGradientStopCollection";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionCommitBatch> = L"Windows.UI.Composition.CompositionCommitBatch";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionContainerShape> = L"Windows.UI.Composition.CompositionContainerShape";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionDrawingSurface> = L"Windows.UI.Composition.CompositionDrawingSurface";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionEasingFunction> = L"Windows.UI.Composition.CompositionEasingFunction";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionEffectBrush> = L"Windows.UI.Composition.CompositionEffectBrush";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionEffectFactory> = L"Windows.UI.Composition.CompositionEffectFactory";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionEffectSourceParameter> = L"Windows.UI.Composition.CompositionEffectSourceParameter";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionEllipseGeometry> = L"Windows.UI.Composition.CompositionEllipseGeometry";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionGeometricClip> = L"Windows.UI.Composition.CompositionGeometricClip";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionGeometry> = L"Windows.UI.Composition.CompositionGeometry";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionGradientBrush> = L"Windows.UI.Composition.CompositionGradientBrush";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionGraphicsDevice> = L"Windows.UI.Composition.CompositionGraphicsDevice";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionLight> = L"Windows.UI.Composition.CompositionLight";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionLineGeometry> = L"Windows.UI.Composition.CompositionLineGeometry";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionLinearGradientBrush> = L"Windows.UI.Composition.CompositionLinearGradientBrush";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionMaskBrush> = L"Windows.UI.Composition.CompositionMaskBrush";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionMipmapSurface> = L"Windows.UI.Composition.CompositionMipmapSurface";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionNineGridBrush> = L"Windows.UI.Composition.CompositionNineGridBrush";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionObject> = L"Windows.UI.Composition.CompositionObject";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionPath> = L"Windows.UI.Composition.CompositionPath";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionPathGeometry> = L"Windows.UI.Composition.CompositionPathGeometry";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionProjectedShadow> = L"Windows.UI.Composition.CompositionProjectedShadow";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionProjectedShadowCaster> = L"Windows.UI.Composition.CompositionProjectedShadowCaster";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionProjectedShadowCasterCollection> = L"Windows.UI.Composition.CompositionProjectedShadowCasterCollection";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionProjectedShadowReceiver> = L"Windows.UI.Composition.CompositionProjectedShadowReceiver";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionProjectedShadowReceiverUnorderedCollection> = L"Windows.UI.Composition.CompositionProjectedShadowReceiverUnorderedCollection";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionPropertySet> = L"Windows.UI.Composition.CompositionPropertySet";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionRadialGradientBrush> = L"Windows.UI.Composition.CompositionRadialGradientBrush";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionRectangleGeometry> = L"Windows.UI.Composition.CompositionRectangleGeometry";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionRoundedRectangleGeometry> = L"Windows.UI.Composition.CompositionRoundedRectangleGeometry";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionScopedBatch> = L"Windows.UI.Composition.CompositionScopedBatch";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionShadow> = L"Windows.UI.Composition.CompositionShadow";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionShape> = L"Windows.UI.Composition.CompositionShape";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionShapeCollection> = L"Windows.UI.Composition.CompositionShapeCollection";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionSpriteShape> = L"Windows.UI.Composition.CompositionSpriteShape";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionStrokeDashArray> = L"Windows.UI.Composition.CompositionStrokeDashArray";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionSurfaceBrush> = L"Windows.UI.Composition.CompositionSurfaceBrush";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionTarget> = L"Windows.UI.Composition.CompositionTarget";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionTexture> = L"Windows.UI.Composition.CompositionTexture";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionTransform> = L"Windows.UI.Composition.CompositionTransform";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionViewBox> = L"Windows.UI.Composition.CompositionViewBox";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionVirtualDrawingSurface> = L"Windows.UI.Composition.CompositionVirtualDrawingSurface";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionVisualSurface> = L"Windows.UI.Composition.CompositionVisualSurface";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::Compositor> = L"Windows.UI.Composition.Compositor";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ContainerVisual> = L"Windows.UI.Composition.ContainerVisual";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CubicBezierEasingFunction> = L"Windows.UI.Composition.CubicBezierEasingFunction";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::DelegatedInkTrailVisual> = L"Windows.UI.Composition.DelegatedInkTrailVisual";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::DistantLight> = L"Windows.UI.Composition.DistantLight";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::DropShadow> = L"Windows.UI.Composition.DropShadow";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ElasticEasingFunction> = L"Windows.UI.Composition.ElasticEasingFunction";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ExponentialEasingFunction> = L"Windows.UI.Composition.ExponentialEasingFunction";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ExpressionAnimation> = L"Windows.UI.Composition.ExpressionAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ImplicitAnimationCollection> = L"Windows.UI.Composition.ImplicitAnimationCollection";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::InitialValueExpressionCollection> = L"Windows.UI.Composition.InitialValueExpressionCollection";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::InsetClip> = L"Windows.UI.Composition.InsetClip";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::KeyFrameAnimation> = L"Windows.UI.Composition.KeyFrameAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::LayerVisual> = L"Windows.UI.Composition.LayerVisual";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::LinearEasingFunction> = L"Windows.UI.Composition.LinearEasingFunction";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::NaturalMotionAnimation> = L"Windows.UI.Composition.NaturalMotionAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::PathKeyFrameAnimation> = L"Windows.UI.Composition.PathKeyFrameAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::PointLight> = L"Windows.UI.Composition.PointLight";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::PowerEasingFunction> = L"Windows.UI.Composition.PowerEasingFunction";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::QuaternionKeyFrameAnimation> = L"Windows.UI.Composition.QuaternionKeyFrameAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::RectangleClip> = L"Windows.UI.Composition.RectangleClip";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::RedirectVisual> = L"Windows.UI.Composition.RedirectVisual";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::RenderingDeviceReplacedEventArgs> = L"Windows.UI.Composition.RenderingDeviceReplacedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ScalarKeyFrameAnimation> = L"Windows.UI.Composition.ScalarKeyFrameAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ScalarNaturalMotionAnimation> = L"Windows.UI.Composition.ScalarNaturalMotionAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ShapeVisual> = L"Windows.UI.Composition.ShapeVisual";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::SineEasingFunction> = L"Windows.UI.Composition.SineEasingFunction";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::SpotLight> = L"Windows.UI.Composition.SpotLight";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::SpringScalarNaturalMotionAnimation> = L"Windows.UI.Composition.SpringScalarNaturalMotionAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::SpringVector2NaturalMotionAnimation> = L"Windows.UI.Composition.SpringVector2NaturalMotionAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::SpringVector3NaturalMotionAnimation> = L"Windows.UI.Composition.SpringVector3NaturalMotionAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::SpriteVisual> = L"Windows.UI.Composition.SpriteVisual";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::StepEasingFunction> = L"Windows.UI.Composition.StepEasingFunction";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::Vector2KeyFrameAnimation> = L"Windows.UI.Composition.Vector2KeyFrameAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::Vector2NaturalMotionAnimation> = L"Windows.UI.Composition.Vector2NaturalMotionAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::Vector3KeyFrameAnimation> = L"Windows.UI.Composition.Vector3KeyFrameAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::Vector3NaturalMotionAnimation> = L"Windows.UI.Composition.Vector3NaturalMotionAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::Vector4KeyFrameAnimation> = L"Windows.UI.Composition.Vector4KeyFrameAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::Visual> = L"Windows.UI.Composition.Visual";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::VisualCollection> = L"Windows.UI.Composition.VisualCollection";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::VisualUnorderedCollection> = L"Windows.UI.Composition.VisualUnorderedCollection";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::AnimationControllerProgressBehavior> = L"Windows.UI.Composition.AnimationControllerProgressBehavior";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::AnimationDelayBehavior> = L"Windows.UI.Composition.AnimationDelayBehavior";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::AnimationDirection> = L"Windows.UI.Composition.AnimationDirection";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::AnimationIterationBehavior> = L"Windows.UI.Composition.AnimationIterationBehavior";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::AnimationPropertyAccessMode> = L"Windows.UI.Composition.AnimationPropertyAccessMode";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::AnimationStopBehavior> = L"Windows.UI.Composition.AnimationStopBehavior";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionBackfaceVisibility> = L"Windows.UI.Composition.CompositionBackfaceVisibility";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionBatchTypes> = L"Windows.UI.Composition.CompositionBatchTypes";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionBitmapInterpolationMode> = L"Windows.UI.Composition.CompositionBitmapInterpolationMode";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionBorderMode> = L"Windows.UI.Composition.CompositionBorderMode";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionColorSpace> = L"Windows.UI.Composition.CompositionColorSpace";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionCompositeMode> = L"Windows.UI.Composition.CompositionCompositeMode";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionDropShadowSourcePolicy> = L"Windows.UI.Composition.CompositionDropShadowSourcePolicy";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionEasingFunctionMode> = L"Windows.UI.Composition.CompositionEasingFunctionMode";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionEffectFactoryLoadStatus> = L"Windows.UI.Composition.CompositionEffectFactoryLoadStatus";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionGetValueStatus> = L"Windows.UI.Composition.CompositionGetValueStatus";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionGradientExtendMode> = L"Windows.UI.Composition.CompositionGradientExtendMode";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionMappingMode> = L"Windows.UI.Composition.CompositionMappingMode";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionStretch> = L"Windows.UI.Composition.CompositionStretch";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionStrokeCap> = L"Windows.UI.Composition.CompositionStrokeCap";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::CompositionStrokeLineJoin> = L"Windows.UI.Composition.CompositionStrokeLineJoin";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::InkTrailPoint> = L"Windows.UI.Composition.InkTrailPoint";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IAmbientLight> = L"Windows.UI.Composition.IAmbientLight";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IAmbientLight2> = L"Windows.UI.Composition.IAmbientLight2";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IAnimationController> = L"Windows.UI.Composition.IAnimationController";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IAnimationControllerStatics> = L"Windows.UI.Composition.IAnimationControllerStatics";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IAnimationObject> = L"Windows.UI.Composition.IAnimationObject";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IAnimationPropertyInfo> = L"Windows.UI.Composition.IAnimationPropertyInfo";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IAnimationPropertyInfo2> = L"Windows.UI.Composition.IAnimationPropertyInfo2";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IBackEasingFunction> = L"Windows.UI.Composition.IBackEasingFunction";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IBooleanKeyFrameAnimation> = L"Windows.UI.Composition.IBooleanKeyFrameAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IBounceEasingFunction> = L"Windows.UI.Composition.IBounceEasingFunction";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IBounceScalarNaturalMotionAnimation> = L"Windows.UI.Composition.IBounceScalarNaturalMotionAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IBounceVector2NaturalMotionAnimation> = L"Windows.UI.Composition.IBounceVector2NaturalMotionAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IBounceVector3NaturalMotionAnimation> = L"Windows.UI.Composition.IBounceVector3NaturalMotionAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICircleEasingFunction> = L"Windows.UI.Composition.ICircleEasingFunction";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IColorKeyFrameAnimation> = L"Windows.UI.Composition.IColorKeyFrameAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionAnimation> = L"Windows.UI.Composition.ICompositionAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionAnimation2> = L"Windows.UI.Composition.ICompositionAnimation2";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionAnimation3> = L"Windows.UI.Composition.ICompositionAnimation3";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionAnimation4> = L"Windows.UI.Composition.ICompositionAnimation4";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionAnimationBase> = L"Windows.UI.Composition.ICompositionAnimationBase";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionAnimationFactory> = L"Windows.UI.Composition.ICompositionAnimationFactory";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionAnimationGroup> = L"Windows.UI.Composition.ICompositionAnimationGroup";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionBackdropBrush> = L"Windows.UI.Composition.ICompositionBackdropBrush";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionBatchCompletedEventArgs> = L"Windows.UI.Composition.ICompositionBatchCompletedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionBrush> = L"Windows.UI.Composition.ICompositionBrush";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionBrushFactory> = L"Windows.UI.Composition.ICompositionBrushFactory";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionCapabilities> = L"Windows.UI.Composition.ICompositionCapabilities";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionCapabilitiesStatics> = L"Windows.UI.Composition.ICompositionCapabilitiesStatics";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionClip> = L"Windows.UI.Composition.ICompositionClip";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionClip2> = L"Windows.UI.Composition.ICompositionClip2";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionClipFactory> = L"Windows.UI.Composition.ICompositionClipFactory";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionColorBrush> = L"Windows.UI.Composition.ICompositionColorBrush";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionColorGradientStop> = L"Windows.UI.Composition.ICompositionColorGradientStop";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionColorGradientStopCollection> = L"Windows.UI.Composition.ICompositionColorGradientStopCollection";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionCommitBatch> = L"Windows.UI.Composition.ICompositionCommitBatch";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionContainerShape> = L"Windows.UI.Composition.ICompositionContainerShape";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionDrawingSurface> = L"Windows.UI.Composition.ICompositionDrawingSurface";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionDrawingSurface2> = L"Windows.UI.Composition.ICompositionDrawingSurface2";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionDrawingSurfaceFactory> = L"Windows.UI.Composition.ICompositionDrawingSurfaceFactory";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionEasingFunction> = L"Windows.UI.Composition.ICompositionEasingFunction";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionEasingFunctionFactory> = L"Windows.UI.Composition.ICompositionEasingFunctionFactory";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionEasingFunctionStatics> = L"Windows.UI.Composition.ICompositionEasingFunctionStatics";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionEffectBrush> = L"Windows.UI.Composition.ICompositionEffectBrush";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionEffectFactory> = L"Windows.UI.Composition.ICompositionEffectFactory";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionEffectSourceParameter> = L"Windows.UI.Composition.ICompositionEffectSourceParameter";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionEffectSourceParameterFactory> = L"Windows.UI.Composition.ICompositionEffectSourceParameterFactory";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionEllipseGeometry> = L"Windows.UI.Composition.ICompositionEllipseGeometry";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionGeometricClip> = L"Windows.UI.Composition.ICompositionGeometricClip";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionGeometry> = L"Windows.UI.Composition.ICompositionGeometry";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionGeometryFactory> = L"Windows.UI.Composition.ICompositionGeometryFactory";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionGradientBrush> = L"Windows.UI.Composition.ICompositionGradientBrush";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionGradientBrush2> = L"Windows.UI.Composition.ICompositionGradientBrush2";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionGradientBrushFactory> = L"Windows.UI.Composition.ICompositionGradientBrushFactory";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionGraphicsDevice> = L"Windows.UI.Composition.ICompositionGraphicsDevice";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionGraphicsDevice2> = L"Windows.UI.Composition.ICompositionGraphicsDevice2";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionGraphicsDevice3> = L"Windows.UI.Composition.ICompositionGraphicsDevice3";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionGraphicsDevice4> = L"Windows.UI.Composition.ICompositionGraphicsDevice4";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionLight> = L"Windows.UI.Composition.ICompositionLight";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionLight2> = L"Windows.UI.Composition.ICompositionLight2";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionLight3> = L"Windows.UI.Composition.ICompositionLight3";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionLightFactory> = L"Windows.UI.Composition.ICompositionLightFactory";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionLineGeometry> = L"Windows.UI.Composition.ICompositionLineGeometry";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionLinearGradientBrush> = L"Windows.UI.Composition.ICompositionLinearGradientBrush";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionMaskBrush> = L"Windows.UI.Composition.ICompositionMaskBrush";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionMipmapSurface> = L"Windows.UI.Composition.ICompositionMipmapSurface";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionNineGridBrush> = L"Windows.UI.Composition.ICompositionNineGridBrush";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionObject> = L"Windows.UI.Composition.ICompositionObject";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionObject2> = L"Windows.UI.Composition.ICompositionObject2";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionObject3> = L"Windows.UI.Composition.ICompositionObject3";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionObject4> = L"Windows.UI.Composition.ICompositionObject4";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionObject5> = L"Windows.UI.Composition.ICompositionObject5";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionObjectFactory> = L"Windows.UI.Composition.ICompositionObjectFactory";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionObjectStatics> = L"Windows.UI.Composition.ICompositionObjectStatics";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionPath> = L"Windows.UI.Composition.ICompositionPath";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionPathFactory> = L"Windows.UI.Composition.ICompositionPathFactory";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionPathGeometry> = L"Windows.UI.Composition.ICompositionPathGeometry";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionProjectedShadow> = L"Windows.UI.Composition.ICompositionProjectedShadow";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionProjectedShadowCaster> = L"Windows.UI.Composition.ICompositionProjectedShadowCaster";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionProjectedShadowCasterCollection> = L"Windows.UI.Composition.ICompositionProjectedShadowCasterCollection";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionProjectedShadowCasterCollectionStatics> = L"Windows.UI.Composition.ICompositionProjectedShadowCasterCollectionStatics";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionProjectedShadowReceiver> = L"Windows.UI.Composition.ICompositionProjectedShadowReceiver";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionProjectedShadowReceiverUnorderedCollection> = L"Windows.UI.Composition.ICompositionProjectedShadowReceiverUnorderedCollection";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionPropertySet> = L"Windows.UI.Composition.ICompositionPropertySet";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionPropertySet2> = L"Windows.UI.Composition.ICompositionPropertySet2";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionRadialGradientBrush> = L"Windows.UI.Composition.ICompositionRadialGradientBrush";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionRectangleGeometry> = L"Windows.UI.Composition.ICompositionRectangleGeometry";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionRoundedRectangleGeometry> = L"Windows.UI.Composition.ICompositionRoundedRectangleGeometry";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionScopedBatch> = L"Windows.UI.Composition.ICompositionScopedBatch";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionShadow> = L"Windows.UI.Composition.ICompositionShadow";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionShadowFactory> = L"Windows.UI.Composition.ICompositionShadowFactory";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionShape> = L"Windows.UI.Composition.ICompositionShape";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionShapeFactory> = L"Windows.UI.Composition.ICompositionShapeFactory";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionSpriteShape> = L"Windows.UI.Composition.ICompositionSpriteShape";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionSupportsSystemBackdrop> = L"Windows.UI.Composition.ICompositionSupportsSystemBackdrop";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionSurface> = L"Windows.UI.Composition.ICompositionSurface";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionSurfaceBrush> = L"Windows.UI.Composition.ICompositionSurfaceBrush";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionSurfaceBrush2> = L"Windows.UI.Composition.ICompositionSurfaceBrush2";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionSurfaceBrush3> = L"Windows.UI.Composition.ICompositionSurfaceBrush3";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionSurfaceFacade> = L"Windows.UI.Composition.ICompositionSurfaceFacade";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionTarget> = L"Windows.UI.Composition.ICompositionTarget";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionTargetFactory> = L"Windows.UI.Composition.ICompositionTargetFactory";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionTexture> = L"Windows.UI.Composition.ICompositionTexture";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionTextureFactory> = L"Windows.UI.Composition.ICompositionTextureFactory";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionTransform> = L"Windows.UI.Composition.ICompositionTransform";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionTransformFactory> = L"Windows.UI.Composition.ICompositionTransformFactory";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionViewBox> = L"Windows.UI.Composition.ICompositionViewBox";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionVirtualDrawingSurface> = L"Windows.UI.Composition.ICompositionVirtualDrawingSurface";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionVirtualDrawingSurfaceFactory> = L"Windows.UI.Composition.ICompositionVirtualDrawingSurfaceFactory";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositionVisualSurface> = L"Windows.UI.Composition.ICompositionVisualSurface";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositor> = L"Windows.UI.Composition.ICompositor";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositor2> = L"Windows.UI.Composition.ICompositor2";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositor3> = L"Windows.UI.Composition.ICompositor3";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositor4> = L"Windows.UI.Composition.ICompositor4";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositor5> = L"Windows.UI.Composition.ICompositor5";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositor6> = L"Windows.UI.Composition.ICompositor6";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositor7> = L"Windows.UI.Composition.ICompositor7";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositor8> = L"Windows.UI.Composition.ICompositor8";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositorStatics> = L"Windows.UI.Composition.ICompositorStatics";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositorWithBlurredWallpaperBackdropBrush> = L"Windows.UI.Composition.ICompositorWithBlurredWallpaperBackdropBrush";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositorWithProjectedShadow> = L"Windows.UI.Composition.ICompositorWithProjectedShadow";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositorWithRadialGradient> = L"Windows.UI.Composition.ICompositorWithRadialGradient";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICompositorWithVisualSurface> = L"Windows.UI.Composition.ICompositorWithVisualSurface";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IContainerVisual> = L"Windows.UI.Composition.IContainerVisual";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IContainerVisualFactory> = L"Windows.UI.Composition.IContainerVisualFactory";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ICubicBezierEasingFunction> = L"Windows.UI.Composition.ICubicBezierEasingFunction";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IDelegatedInkTrailVisual> = L"Windows.UI.Composition.IDelegatedInkTrailVisual";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IDelegatedInkTrailVisualStatics> = L"Windows.UI.Composition.IDelegatedInkTrailVisualStatics";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IDistantLight> = L"Windows.UI.Composition.IDistantLight";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IDistantLight2> = L"Windows.UI.Composition.IDistantLight2";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IDropShadow> = L"Windows.UI.Composition.IDropShadow";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IDropShadow2> = L"Windows.UI.Composition.IDropShadow2";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IElasticEasingFunction> = L"Windows.UI.Composition.IElasticEasingFunction";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IExponentialEasingFunction> = L"Windows.UI.Composition.IExponentialEasingFunction";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IExpressionAnimation> = L"Windows.UI.Composition.IExpressionAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IImplicitAnimationCollection> = L"Windows.UI.Composition.IImplicitAnimationCollection";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IInsetClip> = L"Windows.UI.Composition.IInsetClip";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IKeyFrameAnimation> = L"Windows.UI.Composition.IKeyFrameAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IKeyFrameAnimation2> = L"Windows.UI.Composition.IKeyFrameAnimation2";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IKeyFrameAnimation3> = L"Windows.UI.Composition.IKeyFrameAnimation3";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IKeyFrameAnimationFactory> = L"Windows.UI.Composition.IKeyFrameAnimationFactory";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ILayerVisual> = L"Windows.UI.Composition.ILayerVisual";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ILayerVisual2> = L"Windows.UI.Composition.ILayerVisual2";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ILinearEasingFunction> = L"Windows.UI.Composition.ILinearEasingFunction";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::INaturalMotionAnimation> = L"Windows.UI.Composition.INaturalMotionAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::INaturalMotionAnimationFactory> = L"Windows.UI.Composition.INaturalMotionAnimationFactory";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IPathKeyFrameAnimation> = L"Windows.UI.Composition.IPathKeyFrameAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IPointLight> = L"Windows.UI.Composition.IPointLight";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IPointLight2> = L"Windows.UI.Composition.IPointLight2";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IPointLight3> = L"Windows.UI.Composition.IPointLight3";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IPowerEasingFunction> = L"Windows.UI.Composition.IPowerEasingFunction";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IQuaternionKeyFrameAnimation> = L"Windows.UI.Composition.IQuaternionKeyFrameAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IRectangleClip> = L"Windows.UI.Composition.IRectangleClip";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IRedirectVisual> = L"Windows.UI.Composition.IRedirectVisual";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IRenderingDeviceReplacedEventArgs> = L"Windows.UI.Composition.IRenderingDeviceReplacedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IScalarKeyFrameAnimation> = L"Windows.UI.Composition.IScalarKeyFrameAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IScalarNaturalMotionAnimation> = L"Windows.UI.Composition.IScalarNaturalMotionAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IScalarNaturalMotionAnimationFactory> = L"Windows.UI.Composition.IScalarNaturalMotionAnimationFactory";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IShapeVisual> = L"Windows.UI.Composition.IShapeVisual";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ISineEasingFunction> = L"Windows.UI.Composition.ISineEasingFunction";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ISpotLight> = L"Windows.UI.Composition.ISpotLight";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ISpotLight2> = L"Windows.UI.Composition.ISpotLight2";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ISpotLight3> = L"Windows.UI.Composition.ISpotLight3";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ISpringScalarNaturalMotionAnimation> = L"Windows.UI.Composition.ISpringScalarNaturalMotionAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ISpringVector2NaturalMotionAnimation> = L"Windows.UI.Composition.ISpringVector2NaturalMotionAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ISpringVector3NaturalMotionAnimation> = L"Windows.UI.Composition.ISpringVector3NaturalMotionAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ISpriteVisual> = L"Windows.UI.Composition.ISpriteVisual";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::ISpriteVisual2> = L"Windows.UI.Composition.ISpriteVisual2";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IStepEasingFunction> = L"Windows.UI.Composition.IStepEasingFunction";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IVector2KeyFrameAnimation> = L"Windows.UI.Composition.IVector2KeyFrameAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IVector2NaturalMotionAnimation> = L"Windows.UI.Composition.IVector2NaturalMotionAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IVector2NaturalMotionAnimationFactory> = L"Windows.UI.Composition.IVector2NaturalMotionAnimationFactory";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IVector3KeyFrameAnimation> = L"Windows.UI.Composition.IVector3KeyFrameAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IVector3NaturalMotionAnimation> = L"Windows.UI.Composition.IVector3NaturalMotionAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IVector3NaturalMotionAnimationFactory> = L"Windows.UI.Composition.IVector3NaturalMotionAnimationFactory";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IVector4KeyFrameAnimation> = L"Windows.UI.Composition.IVector4KeyFrameAnimation";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IVisual> = L"Windows.UI.Composition.IVisual";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IVisual2> = L"Windows.UI.Composition.IVisual2";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IVisual3> = L"Windows.UI.Composition.IVisual3";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IVisual4> = L"Windows.UI.Composition.IVisual4";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IVisualCollection> = L"Windows.UI.Composition.IVisualCollection";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IVisualElement> = L"Windows.UI.Composition.IVisualElement";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IVisualElement2> = L"Windows.UI.Composition.IVisualElement2";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IVisualFactory> = L"Windows.UI.Composition.IVisualFactory";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::IVisualUnorderedCollection> = L"Windows.UI.Composition.IVisualUnorderedCollection";
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IAmbientLight>{ 0xA48130A1,0xB7C4,0x46F7,{ 0xB9,0xBF,0xDA,0xF4,0x3A,0x44,0xE6,0xEE } }; // A48130A1-B7C4-46F7-B9BF-DAF43A44E6EE
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IAmbientLight2>{ 0x3B64A6BF,0x5F97,0x4C94,{ 0x86,0xE5,0x04,0x2D,0xD3,0x86,0xB2,0x7D } }; // 3B64A6BF-5F97-4C94-86E5-042DD386B27D
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IAnimationController>{ 0xC934EFD2,0x0722,0x4F5F,{ 0xA4,0xE2,0x95,0x10,0xF3,0xD4,0x3B,0xF7 } }; // C934EFD2-0722-4F5F-A4E2-9510F3D43BF7
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IAnimationControllerStatics>{ 0xE71164DF,0x651B,0x4800,{ 0xB9,0xE5,0x6A,0x3B,0xCF,0xED,0x33,0x65 } }; // E71164DF-651B-4800-B9E5-6A3BCFED3365
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IAnimationObject>{ 0xE7141E0A,0x04B8,0x4FC5,{ 0xA4,0xDC,0x19,0x53,0x92,0xE5,0x78,0x07 } }; // E7141E0A-04B8-4FC5-A4DC-195392E57807
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IAnimationPropertyInfo>{ 0xF4716F05,0xED77,0x4E3C,{ 0xB3,0x28,0x5C,0x39,0x85,0xB3,0x73,0x8F } }; // F4716F05-ED77-4E3C-B328-5C3985B3738F
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IAnimationPropertyInfo2>{ 0x591720B4,0x7472,0x5218,{ 0x8B,0x39,0xDF,0xFE,0x61,0x5A,0xE6,0xDA } }; // 591720B4-7472-5218-8B39-DFFE615AE6DA
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IBackEasingFunction>{ 0xB8560DA4,0x5E3C,0x545D,{ 0xB2,0x63,0x79,0x87,0xA2,0xBD,0x27,0xCB } }; // B8560DA4-5E3C-545D-B263-7987A2BD27CB
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IBooleanKeyFrameAnimation>{ 0x95E23A08,0xD1F4,0x4972,{ 0x97,0x70,0x3E,0xFE,0x68,0xD8,0x2E,0x14 } }; // 95E23A08-D1F4-4972-9770-3EFE68D82E14
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IBounceEasingFunction>{ 0xE7FDB44B,0xAAD5,0x5174,{ 0x94,0x21,0xEE,0xF8,0xB7,0x5A,0x6A,0x43 } }; // E7FDB44B-AAD5-5174-9421-EEF8B75A6A43
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IBounceScalarNaturalMotionAnimation>{ 0xBAA30DCC,0xA633,0x4618,{ 0x9B,0x06,0x7F,0x7C,0x72,0xC8,0x7C,0xFF } }; // BAA30DCC-A633-4618-9B06-7F7C72C87CFF
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IBounceVector2NaturalMotionAnimation>{ 0xDA344196,0x2154,0x4B3C,{ 0x88,0xAA,0x47,0x36,0x12,0x04,0xEC,0xCD } }; // DA344196-2154-4B3C-88AA-47361204ECCD
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IBounceVector3NaturalMotionAnimation>{ 0x47DABC31,0x10D3,0x4518,{ 0x86,0xF1,0x09,0xCA,0xF7,0x42,0xD1,0x13 } }; // 47DABC31-10D3-4518-86F1-09CAF742D113
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICircleEasingFunction>{ 0x1E07222A,0x6F82,0x5A28,{ 0x87,0x48,0x2E,0x92,0xFC,0x46,0xEE,0x2B } }; // 1E07222A-6F82-5A28-8748-2E92FC46EE2B
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IColorKeyFrameAnimation>{ 0x93ADB5E9,0x8E05,0x4593,{ 0x84,0xA3,0xDC,0xA1,0x52,0x78,0x1E,0x56 } }; // 93ADB5E9-8E05-4593-84A3-DCA152781E56
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionAnimation>{ 0x464C4C2C,0x1CAA,0x4061,{ 0x9B,0x40,0xE1,0x3F,0xDE,0x15,0x03,0xCA } }; // 464C4C2C-1CAA-4061-9B40-E13FDE1503CA
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionAnimation2>{ 0x369B603E,0xA80F,0x4948,{ 0x93,0xE3,0xED,0x23,0xFB,0x38,0xC6,0xCB } }; // 369B603E-A80F-4948-93E3-ED23FB38C6CB
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionAnimation3>{ 0xD51E030D,0x7DA4,0x4BD7,{ 0xBC,0x2D,0xF4,0x51,0x75,0x29,0xF4,0x3A } }; // D51E030D-7DA4-4BD7-BC2D-F4517529F43A
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionAnimation4>{ 0x770137BE,0x76BC,0x4E23,{ 0xBF,0xED,0xFE,0x9C,0xC2,0x0F,0x6E,0xC9 } }; // 770137BE-76BC-4E23-BFED-FE9CC20F6EC9
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionAnimationBase>{ 0x1C2C2999,0xE818,0x48D3,{ 0xA6,0xDD,0xD7,0x8C,0x82,0xF8,0xAC,0xE9 } }; // 1C2C2999-E818-48D3-A6DD-D78C82F8ACE9
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionAnimationFactory>{ 0x10F6C4FB,0x6E51,0x4C25,{ 0xBB,0xD3,0x58,0x6A,0x9B,0xEC,0x3E,0xF4 } }; // 10F6C4FB-6E51-4C25-BBD3-586A9BEC3EF4
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionAnimationGroup>{ 0x5E7CC90C,0xCD14,0x4E07,{ 0x8A,0x55,0xC7,0x25,0x27,0xAA,0xBD,0xAC } }; // 5E7CC90C-CD14-4E07-8A55-C72527AABDAC
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionBackdropBrush>{ 0xC5ACAE58,0x3898,0x499E,{ 0x8D,0x7F,0x22,0x4E,0x91,0x28,0x6A,0x5D } }; // C5ACAE58-3898-499E-8D7F-224E91286A5D
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionBatchCompletedEventArgs>{ 0x0D00DAD0,0x9464,0x450A,{ 0xA5,0x62,0x2E,0x26,0x98,0xB0,0xA8,0x12 } }; // 0D00DAD0-9464-450A-A562-2E2698B0A812
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionBrush>{ 0xAB0D7608,0x30C0,0x40E9,{ 0xB5,0x68,0xB6,0x0A,0x6B,0xD1,0xFB,0x46 } }; // AB0D7608-30C0-40E9-B568-B60A6BD1FB46
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionBrushFactory>{ 0xDA53FB4C,0x4650,0x47C4,{ 0xAD,0x76,0x76,0x53,0x79,0x60,0x7E,0xD6 } }; // DA53FB4C-4650-47C4-AD76-765379607ED6
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionCapabilities>{ 0x8253353E,0xB517,0x48BC,{ 0xB1,0xE8,0x4B,0x35,0x61,0xA2,0xE1,0x81 } }; // 8253353E-B517-48BC-B1E8-4B3561A2E181
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionCapabilitiesStatics>{ 0xF7B7A86E,0x6416,0x49E5,{ 0x8D,0xDF,0xAF,0xE9,0x49,0xE2,0x05,0x62 } }; // F7B7A86E-6416-49E5-8DDF-AFE949E20562
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionClip>{ 0x1CCD2A52,0xCFC7,0x4ACE,{ 0x99,0x83,0x14,0x6B,0xB8,0xEB,0x6A,0x3C } }; // 1CCD2A52-CFC7-4ACE-9983-146BB8EB6A3C
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionClip2>{ 0x5893E069,0x3516,0x40E1,{ 0x89,0xE0,0x5B,0xA9,0x24,0x92,0x72,0x35 } }; // 5893E069-3516-40E1-89E0-5BA924927235
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionClipFactory>{ 0xB9484CAF,0x20C7,0x4AED,{ 0xAC,0x4A,0x9C,0x78,0xBA,0x13,0x02,0xCF } }; // B9484CAF-20C7-4AED-AC4A-9C78BA1302CF
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionColorBrush>{ 0x2B264C5E,0xBF35,0x4831,{ 0x86,0x42,0xCF,0x70,0xC2,0x0F,0xFF,0x2F } }; // 2B264C5E-BF35-4831-8642-CF70C20FFF2F
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionColorGradientStop>{ 0x6F00CA92,0xC801,0x4E41,{ 0x9A,0x8F,0xA5,0x3E,0x20,0xF5,0x77,0x78 } }; // 6F00CA92-C801-4E41-9A8F-A53E20F57778
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionColorGradientStopCollection>{ 0x9F1D20EC,0x7B04,0x4B1D,{ 0x90,0xBC,0x9F,0xA3,0x2C,0x0C,0xFD,0x26 } }; // 9F1D20EC-7B04-4B1D-90BC-9FA32C0CFD26
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionCommitBatch>{ 0x0D00DAD0,0xCA07,0x4400,{ 0x8C,0x8E,0xCB,0x5D,0xB0,0x85,0x59,0xCC } }; // 0D00DAD0-CA07-4400-8C8E-CB5DB08559CC
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionContainerShape>{ 0x4F5E859B,0x2E5B,0x44A8,{ 0x98,0x2C,0xAA,0x0F,0x69,0xC1,0x60,0x59 } }; // 4F5E859B-2E5B-44A8-982C-AA0F69C16059
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionDrawingSurface>{ 0xA166C300,0xFAD0,0x4D11,{ 0x9E,0x67,0xE4,0x33,0x16,0x2F,0xF4,0x9E } }; // A166C300-FAD0-4D11-9E67-E433162FF49E
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionDrawingSurface2>{ 0xFAD0E88B,0xE354,0x44E8,{ 0x8E,0x3D,0xC4,0x88,0x0D,0x5A,0x21,0x3F } }; // FAD0E88B-E354-44E8-8E3D-C4880D5A213F
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionDrawingSurfaceFactory>{ 0x9497B00A,0x312D,0x46B9,{ 0x9D,0xB3,0x41,0x2F,0xD7,0x94,0x64,0xC8 } }; // 9497B00A-312D-46B9-9DB3-412FD79464C8
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionEasingFunction>{ 0x5145E356,0xBF79,0x4EA8,{ 0x8C,0xC2,0x6B,0x5B,0x47,0x2E,0x6C,0x9A } }; // 5145E356-BF79-4EA8-8CC2-6B5B472E6C9A
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionEasingFunctionFactory>{ 0x60840774,0x3DA0,0x4949,{ 0x82,0x00,0x72,0x06,0xC0,0x01,0x90,0xA0 } }; // 60840774-3DA0-4949-8200-7206C00190A0
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionEasingFunctionStatics>{ 0x17A766B6,0x2936,0x53EA,{ 0xB5,0xAF,0xC6,0x42,0xF4,0xA6,0x10,0x83 } }; // 17A766B6-2936-53EA-B5AF-C642F4A61083
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionEffectBrush>{ 0xBF7F795E,0x83CC,0x44BF,{ 0xA4,0x47,0x3E,0x3C,0x07,0x17,0x89,0xEC } }; // BF7F795E-83CC-44BF-A447-3E3C071789EC
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionEffectFactory>{ 0xBE5624AF,0xBA7E,0x4510,{ 0x98,0x50,0x41,0xC0,0xB4,0xFF,0x74,0xDF } }; // BE5624AF-BA7E-4510-9850-41C0B4FF74DF
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionEffectSourceParameter>{ 0x858AB13A,0x3292,0x4E4E,{ 0xB3,0xBB,0x2B,0x6C,0x65,0x44,0xA6,0xEE } }; // 858AB13A-3292-4E4E-B3BB-2B6C6544A6EE
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionEffectSourceParameterFactory>{ 0xB3D9F276,0xABA3,0x4724,{ 0xAC,0xF3,0xD0,0x39,0x74,0x64,0xDB,0x1C } }; // B3D9F276-ABA3-4724-ACF3-D0397464DB1C
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionEllipseGeometry>{ 0x4801F884,0xF6AD,0x4B93,{ 0xAF,0xA9,0x89,0x7B,0x64,0xE5,0x7B,0x1F } }; // 4801F884-F6AD-4B93-AFA9-897B64E57B1F
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionGeometricClip>{ 0xC840B581,0x81C9,0x4444,{ 0xA2,0xC1,0xCC,0xAE,0xCE,0x3A,0x50,0xE5 } }; // C840B581-81C9-4444-A2C1-CCAECE3A50E5
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionGeometry>{ 0xE985217C,0x6A17,0x4207,{ 0xAB,0xD8,0x5F,0xD3,0xDD,0x61,0x2A,0x9D } }; // E985217C-6A17-4207-ABD8-5FD3DD612A9D
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionGeometryFactory>{ 0xBFFEBFE1,0x8C25,0x480B,{ 0x9F,0x56,0xFE,0xD6,0xB2,0x88,0x05,0x5D } }; // BFFEBFE1-8C25-480B-9F56-FED6B288055D
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionGradientBrush>{ 0x1D9709E0,0xFFC6,0x4C0E,{ 0xA9,0xAB,0x34,0x14,0x4D,0x4C,0x90,0x98 } }; // 1D9709E0-FFC6-4C0E-A9AB-34144D4C9098
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionGradientBrush2>{ 0x899DD5A1,0xB4C7,0x4B33,{ 0xA1,0xB6,0x26,0x4A,0xDD,0xC2,0x6D,0x10 } }; // 899DD5A1-B4C7-4B33-A1B6-264ADDC26D10
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionGradientBrushFactory>{ 0x56D765D7,0xF189,0x48C9,{ 0x9C,0x8D,0x94,0xDA,0xF1,0xBE,0xC0,0x10 } }; // 56D765D7-F189-48C9-9C8D-94DAF1BEC010
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionGraphicsDevice>{ 0xFB22C6E1,0x80A2,0x4667,{ 0x99,0x36,0xDB,0xEA,0xF6,0xEE,0xFE,0x95 } }; // FB22C6E1-80A2-4667-9936-DBEAF6EEFE95
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionGraphicsDevice2>{ 0x0FB8BDF6,0xC0F0,0x4BCC,{ 0x9F,0xB8,0x08,0x49,0x82,0x49,0x0D,0x7D } }; // 0FB8BDF6-C0F0-4BCC-9FB8-084982490D7D
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionGraphicsDevice3>{ 0x37F67514,0xD3EF,0x49D1,{ 0xB6,0x9D,0x0D,0x8E,0xAB,0xEB,0x36,0x26 } }; // 37F67514-D3EF-49D1-B69D-0D8EABEB3626
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionGraphicsDevice4>{ 0x5A73BFF9,0xA97F,0x4CF5,{ 0xBA,0x46,0x98,0xEF,0x35,0x8E,0x71,0xB1 } }; // 5A73BFF9-A97F-4CF5-BA46-98EF358E71B1
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionLight>{ 0x41A6D7C2,0x2E5D,0x4BC1,{ 0xB0,0x9E,0x8F,0x0A,0x03,0xE3,0xD8,0xD3 } }; // 41A6D7C2-2E5D-4BC1-B09E-8F0A03E3D8D3
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionLight2>{ 0xA7BCDA72,0xF35D,0x425D,{ 0x9B,0x98,0x23,0xF4,0x20,0x5F,0x66,0x69 } }; // A7BCDA72-F35D-425D-9B98-23F4205F6669
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionLight3>{ 0x4B0B00E4,0xDF07,0x4959,{ 0xB7,0xA4,0x4F,0x7E,0x42,0x33,0xF8,0x38 } }; // 4B0B00E4-DF07-4959-B7A4-4F7E4233F838
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionLightFactory>{ 0x069CF306,0xDA3C,0x4B44,{ 0x83,0x8A,0x5E,0x03,0xD5,0x1A,0xCE,0x55 } }; // 069CF306-DA3C-4B44-838A-5E03D51ACE55
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionLineGeometry>{ 0xDD7615A4,0x0C9A,0x4B67,{ 0x8D,0xCE,0x44,0x0A,0x5B,0xF9,0xCD,0xEC } }; // DD7615A4-0C9A-4B67-8DCE-440A5BF9CDEC
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionLinearGradientBrush>{ 0x983BC519,0xA9DB,0x413C,{ 0xA2,0xD8,0x2A,0x90,0x56,0xFC,0x52,0x5E } }; // 983BC519-A9DB-413C-A2D8-2A9056FC525E
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionMaskBrush>{ 0x522CF09E,0xBE6B,0x4F41,{ 0xBE,0x49,0xF9,0x22,0x6D,0x47,0x1B,0x4A } }; // 522CF09E-BE6B-4F41-BE49-F9226D471B4A
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionMipmapSurface>{ 0x4863675C,0xCF4A,0x4B1C,{ 0x9E,0xCE,0xC5,0xEC,0x0C,0x2B,0x2F,0xE6 } }; // 4863675C-CF4A-4B1C-9ECE-C5EC0C2B2FE6
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionNineGridBrush>{ 0xF25154E4,0xBC8C,0x4BE7,{ 0xB8,0x0F,0x86,0x85,0xB8,0x3C,0x01,0x86 } }; // F25154E4-BC8C-4BE7-B80F-8685B83C0186
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionObject>{ 0xBCB4AD45,0x7609,0x4550,{ 0x93,0x4F,0x16,0x00,0x2A,0x68,0xFD,0xED } }; // BCB4AD45-7609-4550-934F-16002A68FDED
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionObject2>{ 0xEF874EA1,0x5CFF,0x4B68,{ 0x9E,0x30,0xA1,0x51,0x9D,0x08,0xBA,0x03 } }; // EF874EA1-5CFF-4B68-9E30-A1519D08BA03
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionObject3>{ 0x4BC27925,0xDACD,0x4CF2,{ 0x98,0xB1,0x98,0x6B,0x76,0xE7,0xEB,0xE6 } }; // 4BC27925-DACD-4CF2-98B1-986B76E7EBE6
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionObject4>{ 0x0BB3784C,0x346B,0x4A7C,{ 0x96,0x6B,0x73,0x10,0x96,0x65,0x53,0xD5 } }; // 0BB3784C-346B-4A7C-966B-7310966553D5
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionObject5>{ 0x1D7F391B,0xA130,0x5265,{ 0xA6,0x2B,0x60,0xB8,0xE6,0x68,0x96,0x5A } }; // 1D7F391B-A130-5265-A62B-60B8E668965A
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionObjectFactory>{ 0x51205C5E,0x558A,0x4F2A,{ 0x8D,0x39,0x37,0xBF,0xE1,0xE2,0x0D,0xDD } }; // 51205C5E-558A-4F2A-8D39-37BFE1E20DDD
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionObjectStatics>{ 0xC1ED052F,0x1BA2,0x44BA,{ 0xA9,0x04,0x6A,0x88,0x2A,0x0A,0x5A,0xDB } }; // C1ED052F-1BA2-44BA-A904-6A882A0A5ADB
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionPath>{ 0x66DA1D5F,0x2E10,0x4F22,{ 0x8A,0x06,0x0A,0x81,0x51,0x91,0x9E,0x60 } }; // 66DA1D5F-2E10-4F22-8A06-0A8151919E60
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionPathFactory>{ 0x9C1E8C6A,0x0F33,0x4751,{ 0x94,0x37,0xEB,0x3F,0xB9,0xD3,0xAB,0x07 } }; // 9C1E8C6A-0F33-4751-9437-EB3FB9D3AB07
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionPathGeometry>{ 0x0B6A417E,0x2C77,0x4C23,{ 0xAF,0x5E,0x63,0x04,0xC1,0x47,0xBB,0x61 } }; // 0B6A417E-2C77-4C23-AF5E-6304C147BB61
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionProjectedShadow>{ 0x285B8E72,0x4328,0x523F,{ 0xBC,0xF2,0x55,0x57,0xC5,0x2C,0x3B,0x25 } }; // 285B8E72-4328-523F-BCF2-5557C52C3B25
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionProjectedShadowCaster>{ 0xB1D7D426,0x1E36,0x5A62,{ 0xBE,0x56,0xA1,0x61,0x12,0xFD,0xD1,0x48 } }; // B1D7D426-1E36-5A62-BE56-A16112FDD148
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionProjectedShadowCasterCollection>{ 0xD2525C0C,0xE07F,0x58A3,{ 0xAC,0x91,0x37,0xF7,0x3E,0xE9,0x17,0x40 } }; // D2525C0C-E07F-58A3-AC91-37F73EE91740
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionProjectedShadowCasterCollectionStatics>{ 0x56FBB136,0xE94F,0x5299,{ 0xAB,0x5B,0x6E,0x15,0xE3,0x8B,0xD8,0x99 } }; // 56FBB136-E94F-5299-AB5B-6E15E38BD899
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionProjectedShadowReceiver>{ 0x1377985A,0x6A49,0x536A,{ 0x9B,0xE4,0xA9,0x6A,0x8E,0x52,0x98,0xA9 } }; // 1377985A-6A49-536A-9BE4-A96A8E5298A9
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionProjectedShadowReceiverUnorderedCollection>{ 0x02B3E3B7,0x27D2,0x599F,{ 0xAC,0x4B,0xAB,0x78,0x7C,0xDD,0xE6,0xFD } }; // 02B3E3B7-27D2-599F-AC4B-AB787CDDE6FD
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionPropertySet>{ 0xC9D6D202,0x5F67,0x4453,{ 0x91,0x17,0x9E,0xAD,0xD4,0x30,0xD3,0xC2 } }; // C9D6D202-5F67-4453-9117-9EADD430D3C2
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionPropertySet2>{ 0xDE80731E,0xA211,0x4455,{ 0x88,0x80,0x7D,0x0F,0x3F,0x6A,0x44,0xFD } }; // DE80731E-A211-4455-8880-7D0F3F6A44FD
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionRadialGradientBrush>{ 0x3D3B50C5,0xE3FA,0x4CE2,{ 0xB9,0xFC,0x3E,0xE1,0x25,0x61,0x78,0x8F } }; // 3D3B50C5-E3FA-4CE2-B9FC-3EE12561788F
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionRectangleGeometry>{ 0x0CD51428,0x5356,0x4246,{ 0xAE,0xCF,0x7A,0x0B,0x76,0x97,0x54,0x00 } }; // 0CD51428-5356-4246-AECF-7A0B76975400
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionRoundedRectangleGeometry>{ 0x8770C822,0x1D50,0x4B8B,{ 0xB0,0x13,0x7C,0x9A,0x0E,0x46,0x93,0x5F } }; // 8770C822-1D50-4B8B-B013-7C9A0E46935F
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionScopedBatch>{ 0x0D00DAD0,0xFB07,0x46FD,{ 0x8C,0x72,0x62,0x80,0xD1,0xA3,0xD1,0xDD } }; // 0D00DAD0-FB07-46FD-8C72-6280D1A3D1DD
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionShadow>{ 0x329E52E2,0x4335,0x49CC,{ 0xB1,0x4A,0x37,0x78,0x2D,0x10,0xF0,0xC4 } }; // 329E52E2-4335-49CC-B14A-37782D10F0C4
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionShadowFactory>{ 0x221F492F,0xDCBA,0x4B91,{ 0x99,0x9E,0x1D,0xC2,0x17,0xA0,0x15,0x30 } }; // 221F492F-DCBA-4B91-999E-1DC217A01530
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionShape>{ 0xB47CE2F7,0x9A88,0x42C4,{ 0x9E,0x87,0x2E,0x50,0x0C,0xA8,0x68,0x8C } }; // B47CE2F7-9A88-42C4-9E87-2E500CA8688C
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionShapeFactory>{ 0x1DFC36D0,0xB05A,0x44EF,{ 0x82,0xB0,0x12,0x11,0x8B,0xCD,0x4C,0xD0 } }; // 1DFC36D0-B05A-44EF-82B0-12118BCD4CD0
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionSpriteShape>{ 0x401B61BB,0x0007,0x4363,{ 0xB1,0xF3,0x6B,0xCC,0x00,0x3F,0xB8,0x3E } }; // 401B61BB-0007-4363-B1F3-6BCC003FB83E
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionSupportsSystemBackdrop>{ 0x397DAFE4,0xB6C2,0x5BB9,{ 0x95,0x1D,0xF5,0x70,0x7D,0xE8,0xB7,0xBC } }; // 397DAFE4-B6C2-5BB9-951D-F5707DE8B7BC
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionSurface>{ 0x1527540D,0x42C7,0x47A6,{ 0xA4,0x08,0x66,0x8F,0x79,0xA9,0x0D,0xFB } }; // 1527540D-42C7-47A6-A408-668F79A90DFB
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionSurfaceBrush>{ 0xAD016D79,0x1E4C,0x4C0D,{ 0x9C,0x29,0x83,0x33,0x8C,0x87,0xC1,0x62 } }; // AD016D79-1E4C-4C0D-9C29-83338C87C162
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionSurfaceBrush2>{ 0xD27174D5,0x64F5,0x4692,{ 0x9D,0xC7,0x71,0xB6,0x1D,0x7E,0x58,0x80 } }; // D27174D5-64F5-4692-9DC7-71B61D7E5880
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionSurfaceBrush3>{ 0x550BB289,0x1FE0,0x42E5,{ 0x81,0x95,0x1E,0xEF,0xA8,0x7F,0xF0,0x8E } }; // 550BB289-1FE0-42E5-8195-1EEFA87FF08E
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionSurfaceFacade>{ 0xE01622C8,0x2332,0x55C7,{ 0x88,0x68,0xA7,0x31,0x2C,0x5C,0x22,0x9D } }; // E01622C8-2332-55C7-8868-A7312C5C229D
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionTarget>{ 0xA1BEA8BA,0xD726,0x4663,{ 0x81,0x29,0x6B,0x5E,0x79,0x27,0xFF,0xA6 } }; // A1BEA8BA-D726-4663-8129-6B5E7927FFA6
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionTargetFactory>{ 0x93CD9D2B,0x8516,0x4B14,{ 0xA8,0xCE,0xF4,0x9E,0x21,0x19,0xEC,0x42 } }; // 93CD9D2B-8516-4B14-A8CE-F49E2119EC42
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionTexture>{ 0x347D03A0,0x1C0A,0x4C0B,{ 0xB2,0x32,0x85,0x70,0xB2,0xB1,0xA4,0xEA } }; // 347D03A0-1C0A-4C0B-B232-8570B2B1A4EA
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionTextureFactory>{ 0x09D9523D,0x471C,0x5AB5,{ 0xB0,0x53,0xB5,0x68,0xEE,0x46,0xEB,0xFB } }; // 09D9523D-471C-5AB5-B053-B568EE46EBFB
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionTransform>{ 0x7CD54529,0xFBED,0x4112,{ 0xAB,0xC5,0x18,0x59,0x06,0xDD,0x92,0x7C } }; // 7CD54529-FBED-4112-ABC5-185906DD927C
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionTransformFactory>{ 0xAAAECA26,0xC149,0x517A,{ 0x8F,0x72,0x6B,0xFF,0x7A,0x65,0xCE,0x08 } }; // AAAECA26-C149-517A-8F72-6BFF7A65CE08
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionViewBox>{ 0xB440BF07,0x068F,0x4537,{ 0x84,0xC6,0x4E,0xCB,0xE0,0x19,0xE1,0xF4 } }; // B440BF07-068F-4537-84C6-4ECBE019E1F4
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionVirtualDrawingSurface>{ 0xA9C384DB,0x8740,0x4F94,{ 0x8B,0x9D,0xB6,0x85,0x21,0xE7,0x86,0x3D } }; // A9C384DB-8740-4F94-8B9D-B68521E7863D
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionVirtualDrawingSurfaceFactory>{ 0x6766106C,0xD56B,0x4A49,{ 0xB1,0xDF,0x50,0x76,0xA0,0x62,0x07,0x68 } }; // 6766106C-D56B-4A49-B1DF-5076A0620768
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositionVisualSurface>{ 0xB224D803,0x4F6E,0x4A3F,{ 0x8C,0xAE,0x3D,0xC1,0xCD,0xA7,0x4F,0xC6 } }; // B224D803-4F6E-4A3F-8CAE-3DC1CDA74FC6
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositor>{ 0xB403CA50,0x7F8C,0x4E83,{ 0x98,0x5F,0xCC,0x45,0x06,0x00,0x36,0xD8 } }; // B403CA50-7F8C-4E83-985F-CC45060036D8
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositor2>{ 0x735081DC,0x5E24,0x45DA,{ 0xA3,0x8F,0xE3,0x2C,0xC3,0x49,0xA9,0xA0 } }; // 735081DC-5E24-45DA-A38F-E32CC349A9A0
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositor3>{ 0xC9DD8EF0,0x6EB1,0x4E3C,{ 0xA6,0x58,0x67,0x5D,0x9C,0x64,0xD4,0xAB } }; // C9DD8EF0-6EB1-4E3C-A658-675D9C64D4AB
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositor4>{ 0xAE47E78A,0x7910,0x4425,{ 0xA4,0x82,0xA0,0x5B,0x75,0x8A,0xDC,0xE9 } }; // AE47E78A-7910-4425-A482-A05B758ADCE9
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositor5>{ 0x48EA31AD,0x7FCD,0x4076,{ 0xA7,0x9C,0x90,0xCC,0x4B,0x85,0x2C,0x9B } }; // 48EA31AD-7FCD-4076-A79C-90CC4B852C9B
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositor6>{ 0x7A38B2BD,0xCEC8,0x4EEB,{ 0x83,0x0F,0xD8,0xD0,0x7A,0xED,0xEB,0xC3 } }; // 7A38B2BD-CEC8-4EEB-830F-D8D07AEDEBC3
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositor7>{ 0xD3483FAD,0x9A12,0x53BA,{ 0xBF,0xC8,0x88,0xB7,0xFF,0x79,0x77,0xC6 } }; // D3483FAD-9A12-53BA-BFC8-88B7FF7977C6
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositor8>{ 0x9A0BDEE2,0xFE7B,0x5F62,{ 0xA3,0x66,0x9C,0xF8,0xEF,0xFE,0x21,0x12 } }; // 9A0BDEE2-FE7B-5F62-A366-9CF8EFFE2112
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositorStatics>{ 0x080DB93E,0x121E,0x4D97,{ 0x8B,0x74,0x1D,0xFC,0xF9,0x19,0x87,0xEA } }; // 080DB93E-121E-4D97-8B74-1DFCF91987EA
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositorWithBlurredWallpaperBackdropBrush>{ 0x0D8FB190,0xF122,0x5B8D,{ 0x9F,0xDD,0x54,0x3B,0x0D,0x8E,0xB7,0xF3 } }; // 0D8FB190-F122-5B8D-9FDD-543B0D8EB7F3
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositorWithProjectedShadow>{ 0xA2E6330E,0x8A60,0x5A38,{ 0xBB,0x85,0xB4,0x4E,0xA9,0x01,0x67,0x7C } }; // A2E6330E-8A60-5A38-BB85-B44EA901677C
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositorWithRadialGradient>{ 0x98B9C1A7,0x8E71,0x4B53,{ 0xB4,0xA8,0x69,0xBA,0x5D,0x19,0xDC,0x5B } }; // 98B9C1A7-8E71-4B53-B4A8-69BA5D19DC5B
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICompositorWithVisualSurface>{ 0xCFA1658B,0x0123,0x4551,{ 0x88,0x91,0x89,0xBD,0xCC,0x40,0x32,0x2B } }; // CFA1658B-0123-4551-8891-89BDCC40322B
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IContainerVisual>{ 0x02F6BC74,0xED20,0x4773,{ 0xAF,0xE6,0xD4,0x9B,0x4A,0x93,0xDB,0x32 } }; // 02F6BC74-ED20-4773-AFE6-D49B4A93DB32
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IContainerVisualFactory>{ 0x0363A65B,0xC7DA,0x4D9A,{ 0x95,0xF4,0x69,0xB5,0xC8,0xDF,0x67,0x0B } }; // 0363A65B-C7DA-4D9A-95F4-69B5C8DF670B
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ICubicBezierEasingFunction>{ 0x32350666,0xC1E8,0x44F9,{ 0x96,0xB8,0xC9,0x8A,0xCF,0x0A,0xE6,0x98 } }; // 32350666-C1E8-44F9-96B8-C98ACF0AE698
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IDelegatedInkTrailVisual>{ 0x856E60B1,0xE1AB,0x5B23,{ 0x8E,0x3D,0xD5,0x13,0xF2,0x21,0xC9,0x98 } }; // 856E60B1-E1AB-5B23-8E3D-D513F221C998
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IDelegatedInkTrailVisualStatics>{ 0x0DAF6BD5,0x42C6,0x555C,{ 0x92,0x67,0xE0,0xAC,0x66,0x3A,0xF8,0x36 } }; // 0DAF6BD5-42C6-555C-9267-E0AC663AF836
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IDistantLight>{ 0x318CFAFC,0x5CE3,0x4B55,{ 0xAB,0x5D,0x07,0xA0,0x03,0x53,0xAC,0x99 } }; // 318CFAFC-5CE3-4B55-AB5D-07A00353AC99
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IDistantLight2>{ 0xDBCDAA1C,0x294B,0x48D7,{ 0xB6,0x0E,0x76,0xDF,0x64,0xAA,0x39,0x2B } }; // DBCDAA1C-294B-48D7-B60E-76DF64AA392B
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IDropShadow>{ 0xCB977C07,0xA154,0x4851,{ 0x85,0xE7,0xA8,0x92,0x4C,0x84,0xFA,0xD8 } }; // CB977C07-A154-4851-85E7-A8924C84FAD8
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IDropShadow2>{ 0x6C4218BC,0x15B9,0x4C2D,{ 0x8D,0x4A,0x07,0x67,0xDF,0x11,0x97,0x7A } }; // 6C4218BC-15B9-4C2D-8D4A-0767DF11977A
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IElasticEasingFunction>{ 0x66DE6285,0x054E,0x5594,{ 0x84,0x75,0xC2,0x2C,0xB5,0x1F,0x1B,0xD5 } }; // 66DE6285-054E-5594-8475-C22CB51F1BD5
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IExponentialEasingFunction>{ 0x6F7D1A51,0x98D2,0x5638,{ 0xA3,0x4A,0x00,0x48,0x65,0x54,0xC7,0x50 } }; // 6F7D1A51-98D2-5638-A34A-00486554C750
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IExpressionAnimation>{ 0x6ACC5431,0x7D3D,0x4BF3,{ 0xAB,0xB6,0xF4,0x4B,0xDC,0x48,0x88,0xC1 } }; // 6ACC5431-7D3D-4BF3-ABB6-F44BDC4888C1
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IImplicitAnimationCollection>{ 0x0598A3FF,0x0A92,0x4C9D,{ 0xA4,0x27,0xB2,0x55,0x19,0x25,0x0D,0xBF } }; // 0598A3FF-0A92-4C9D-A427-B25519250DBF
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IInsetClip>{ 0x1E73E647,0x84C7,0x477A,{ 0xB4,0x74,0x58,0x80,0xE0,0x44,0x2E,0x15 } }; // 1E73E647-84C7-477A-B474-5880E0442E15
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IKeyFrameAnimation>{ 0x126E7F22,0x3AE9,0x4540,{ 0x9A,0x8A,0xDE,0xAE,0x8A,0x4A,0x4A,0x84 } }; // 126E7F22-3AE9-4540-9A8A-DEAE8A4A4A84
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IKeyFrameAnimation2>{ 0xF4B488BB,0x2940,0x4EC0,{ 0xA4,0x1A,0xEB,0x6D,0x80,0x1A,0x2F,0x18 } }; // F4B488BB-2940-4EC0-A41A-EB6D801A2F18
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IKeyFrameAnimation3>{ 0x845BF0B4,0xD8DE,0x462F,{ 0x87,0x53,0xC8,0x0D,0x43,0xC6,0xFF,0x5A } }; // 845BF0B4-D8DE-462F-8753-C80D43C6FF5A
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IKeyFrameAnimationFactory>{ 0xBF0803F8,0x712A,0x4FC1,{ 0x8C,0x87,0x97,0x08,0x59,0xED,0x8D,0x2E } }; // BF0803F8-712A-4FC1-8C87-970859ED8D2E
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ILayerVisual>{ 0xAF843985,0x0444,0x4887,{ 0x8E,0x83,0xB4,0x0B,0x25,0x3F,0x82,0x2C } }; // AF843985-0444-4887-8E83-B40B253F822C
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ILayerVisual2>{ 0x98F9AEEB,0x6F23,0x49F1,{ 0x90,0xB1,0x1F,0x59,0xA1,0x4F,0xBC,0xE3 } }; // 98F9AEEB-6F23-49F1-90B1-1F59A14FBCE3
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ILinearEasingFunction>{ 0x9400975A,0xC7A6,0x46B3,{ 0xAC,0xF7,0x1A,0x26,0x8A,0x0A,0x11,0x7D } }; // 9400975A-C7A6-46B3-ACF7-1A268A0A117D
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::INaturalMotionAnimation>{ 0x438DE12D,0x769B,0x4821,{ 0xA9,0x49,0x28,0x4A,0x65,0x47,0xE8,0x73 } }; // 438DE12D-769B-4821-A949-284A6547E873
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::INaturalMotionAnimationFactory>{ 0xF53ACB06,0xCF6A,0x4387,{ 0xA3,0xFE,0x52,0x21,0xF3,0xE7,0xE0,0xE0 } }; // F53ACB06-CF6A-4387-A3FE-5221F3E7E0E0
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IPathKeyFrameAnimation>{ 0x9D0D18C9,0x1576,0x4B3F,{ 0xBE,0x60,0x1D,0x50,0x31,0xF5,0xE7,0x1B } }; // 9D0D18C9-1576-4B3F-BE60-1D5031F5E71B
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IPointLight>{ 0xB18545B3,0x0C5A,0x4AB0,{ 0xBE,0xDC,0x4F,0x35,0x46,0x94,0x82,0x72 } }; // B18545B3-0C5A-4AB0-BEDC-4F3546948272
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IPointLight2>{ 0xEFE98F2C,0x0678,0x4F69,{ 0xB1,0x64,0xA8,0x10,0xD9,0x95,0xBC,0xB7 } }; // EFE98F2C-0678-4F69-B164-A810D995BCB7
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IPointLight3>{ 0x4C0A8367,0xD4E9,0x468A,{ 0x87,0xAE,0x7B,0xA4,0x3A,0xB2,0x94,0x85 } }; // 4C0A8367-D4E9-468A-87AE-7BA43AB29485
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IPowerEasingFunction>{ 0xC3FF53D6,0x138B,0x5815,{ 0x89,0x1A,0xB7,0xF6,0x15,0xCC,0xC5,0x63 } }; // C3FF53D6-138B-5815-891A-B7F615CCC563
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IQuaternionKeyFrameAnimation>{ 0x404E5835,0xECF6,0x4240,{ 0x85,0x20,0x67,0x12,0x79,0xCF,0x36,0xBC } }; // 404E5835-ECF6-4240-8520-671279CF36BC
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IRectangleClip>{ 0xB3E7549E,0x00B4,0x5B53,{ 0x8B,0xE8,0x35,0x3F,0x6C,0x43,0x31,0x01 } }; // B3E7549E-00B4-5B53-8BE8-353F6C433101
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IRedirectVisual>{ 0x8CC6E340,0x8B75,0x5422,{ 0xB0,0x6F,0x09,0xFF,0xE9,0xF8,0x61,0x7E } }; // 8CC6E340-8B75-5422-B06F-09FFE9F8617E
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IRenderingDeviceReplacedEventArgs>{ 0x3A31AC7D,0x28BF,0x4E7A,{ 0x85,0x24,0x71,0x67,0x9D,0x48,0x0F,0x38 } }; // 3A31AC7D-28BF-4E7A-8524-71679D480F38
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IScalarKeyFrameAnimation>{ 0xAE288FA9,0x252C,0x4B95,{ 0xA7,0x25,0xBF,0x85,0xE3,0x80,0x00,0xA1 } }; // AE288FA9-252C-4B95-A725-BF85E38000A1
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IScalarNaturalMotionAnimation>{ 0x94A94581,0xBF92,0x495B,{ 0xB5,0xBD,0xD2,0xC6,0x59,0x43,0x07,0x37 } }; // 94A94581-BF92-495B-B5BD-D2C659430737
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IScalarNaturalMotionAnimationFactory>{ 0x835AA4FC,0x671C,0x41DD,{ 0xAF,0x48,0xAE,0x8D,0xEF,0x8B,0x15,0x29 } }; // 835AA4FC-671C-41DD-AF48-AE8DEF8B1529
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IShapeVisual>{ 0xF2BD13C3,0xBA7E,0x4B0F,{ 0x91,0x26,0xFF,0xB7,0x53,0x6B,0x81,0x76 } }; // F2BD13C3-BA7E-4B0F-9126-FFB7536B8176
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ISineEasingFunction>{ 0xF1B518BF,0x9563,0x5474,{ 0xBD,0x13,0x44,0xB2,0xDF,0x4B,0x1D,0x58 } }; // F1B518BF-9563-5474-BD13-44B2DF4B1D58
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ISpotLight>{ 0x5A9FE273,0x44A1,0x4F95,{ 0xA4,0x22,0x8F,0xA5,0x11,0x6B,0xDB,0x44 } }; // 5A9FE273-44A1-4F95-A422-8FA5116BDB44
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ISpotLight2>{ 0x64EE615E,0x0686,0x4DEA,{ 0xA9,0xE8,0xBC,0x3A,0x8C,0x70,0x14,0x59 } }; // 64EE615E-0686-4DEA-A9E8-BC3A8C701459
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ISpotLight3>{ 0xE4D03EEA,0x131F,0x480E,{ 0x85,0x9E,0xB8,0x27,0x05,0xB7,0x43,0x60 } }; // E4D03EEA-131F-480E-859E-B82705B74360
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ISpringScalarNaturalMotionAnimation>{ 0x0572A95F,0x37F9,0x4FBE,{ 0xB8,0x7B,0x5C,0xD0,0x3A,0x89,0x50,0x1C } }; // 0572A95F-37F9-4FBE-B87B-5CD03A89501C
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ISpringVector2NaturalMotionAnimation>{ 0x23F494B5,0xEE73,0x4F0F,{ 0xA4,0x23,0x40,0x2B,0x94,0x6D,0xF4,0xB3 } }; // 23F494B5-EE73-4F0F-A423-402B946DF4B3
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ISpringVector3NaturalMotionAnimation>{ 0x6C8749DF,0xD57B,0x4794,{ 0x8E,0x2D,0xCE,0xCB,0x11,0xE1,0x94,0xE5 } }; // 6C8749DF-D57B-4794-8E2D-CECB11E194E5
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ISpriteVisual>{ 0x08E05581,0x1AD1,0x4F97,{ 0x97,0x57,0x40,0x2D,0x76,0xE4,0x23,0x3B } }; // 08E05581-1AD1-4F97-9757-402D76E4233B
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::ISpriteVisual2>{ 0x588C9664,0x997A,0x4850,{ 0x91,0xFE,0x53,0xCB,0x58,0xF8,0x1C,0xE9 } }; // 588C9664-997A-4850-91FE-53CB58F81CE9
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IStepEasingFunction>{ 0xD0CAA74B,0x560C,0x4A0B,{ 0xA5,0xF6,0x20,0x6C,0xA8,0xC3,0xEC,0xD6 } }; // D0CAA74B-560C-4A0B-A5F6-206CA8C3ECD6
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IVector2KeyFrameAnimation>{ 0xDF414515,0x4E29,0x4F11,{ 0xB5,0x5E,0xBF,0x2A,0x6E,0xB3,0x62,0x94 } }; // DF414515-4E29-4F11-B55E-BF2A6EB36294
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IVector2NaturalMotionAnimation>{ 0x0F3E0B7D,0xE512,0x479D,{ 0xA0,0x0C,0x77,0xC9,0x3A,0x30,0xA3,0x95 } }; // 0F3E0B7D-E512-479D-A00C-77C93A30A395
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IVector2NaturalMotionAnimationFactory>{ 0x8C74FF61,0x0761,0x48A2,{ 0xBD,0xDB,0x6A,0xFC,0xC5,0x2B,0x89,0xD8 } }; // 8C74FF61-0761-48A2-BDDB-6AFCC52B89D8
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IVector3KeyFrameAnimation>{ 0xC8039DAA,0xA281,0x43C2,{ 0xA7,0x3D,0xB6,0x8E,0x3C,0x53,0x3C,0x40 } }; // C8039DAA-A281-43C2-A73D-B68E3C533C40
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IVector3NaturalMotionAnimation>{ 0x9C17042C,0xE2CA,0x45AD,{ 0x96,0x9E,0x4E,0x78,0xB7,0xB9,0xAD,0x41 } }; // 9C17042C-E2CA-45AD-969E-4E78B7B9AD41
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IVector3NaturalMotionAnimationFactory>{ 0x21A81D2F,0x0880,0x457B,{ 0xAC,0x87,0xB6,0x09,0x01,0x8C,0x87,0x6D } }; // 21A81D2F-0880-457B-AC87-B609018C876D
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IVector4KeyFrameAnimation>{ 0x2457945B,0xADDD,0x4385,{ 0x96,0x06,0xB6,0xA3,0xD5,0xE4,0xE1,0xB9 } }; // 2457945B-ADDD-4385-9606-B6A3D5E4E1B9
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IVisual>{ 0x117E202D,0xA859,0x4C89,{ 0x87,0x3B,0xC2,0xAA,0x56,0x67,0x88,0xE3 } }; // 117E202D-A859-4C89-873B-C2AA566788E3
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IVisual2>{ 0x3052B611,0x56C3,0x4C3E,{ 0x8B,0xF3,0xF6,0xE1,0xAD,0x47,0x3F,0x06 } }; // 3052B611-56C3-4C3E-8BF3-F6E1AD473F06
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IVisual3>{ 0x30BE580D,0xF4B6,0x4AB7,{ 0x80,0xDD,0x37,0x38,0xCB,0xAC,0x9F,0x2C } }; // 30BE580D-F4B6-4AB7-80DD-3738CBAC9F2C
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IVisual4>{ 0x9476BF11,0xE24B,0x5BF9,{ 0x9E,0xBE,0x62,0x74,0x10,0x9B,0x27,0x11 } }; // 9476BF11-E24B-5BF9-9EBE-6274109B2711
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IVisualCollection>{ 0x8B745505,0xFD3E,0x4A98,{ 0x84,0xA8,0xE9,0x49,0x46,0x8C,0x6B,0xCB } }; // 8B745505-FD3E-4A98-84A8-E949468C6BCB
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IVisualElement>{ 0x01E64612,0x1D82,0x42F4,{ 0x8E,0x3F,0xA7,0x22,0xDE,0xD3,0x3F,0xC7 } }; // 01E64612-1D82-42F4-8E3F-A722DED33FC7
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IVisualElement2>{ 0x993AE8A0,0x6057,0x5E40,{ 0x91,0x8C,0xE0,0x6E,0x0B,0x7E,0x7C,0x64 } }; // 993AE8A0-6057-5E40-918C-E06E0B7E7C64
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IVisualFactory>{ 0xAD0FF93E,0xB502,0x4EB5,{ 0x87,0xB4,0x9A,0x38,0xA7,0x1D,0x01,0x37 } }; // AD0FF93E-B502-4EB5-87B4-9A38A71D0137
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::IVisualUnorderedCollection>{ 0x338FAA70,0x54C8,0x40A7,{ 0x80,0x29,0xC9,0xCE,0xEB,0x0A,0xA2,0x50 } }; // 338FAA70-54C8-40A7-8029-C9CEEB0AA250
    template <> struct default_interface<llm:OS::UI::Composition::AmbientLight>{ using type = llm:OS::UI::Composition::IAmbientLight; };
    template <> struct default_interface<llm:OS::UI::Composition::AnimationController>{ using type = llm:OS::UI::Composition::IAnimationController; };
    template <> struct default_interface<llm:OS::UI::Composition::AnimationPropertyInfo>{ using type = llm:OS::UI::Composition::IAnimationPropertyInfo; };
    template <> struct default_interface<llm:OS::UI::Composition::BackEasingFunction>{ using type = llm:OS::UI::Composition::IBackEasingFunction; };
    template <> struct default_interface<llm:OS::UI::Composition::BooleanKeyFrameAnimation>{ using type = llm:OS::UI::Composition::IBooleanKeyFrameAnimation; };
    template <> struct default_interface<llm:OS::UI::Composition::BounceEasingFunction>{ using type = llm:OS::UI::Composition::IBounceEasingFunction; };
    template <> struct default_interface<llm:OS::UI::Composition::BounceScalarNaturalMotionAnimation>{ using type = llm:OS::UI::Composition::IBounceScalarNaturalMotionAnimation; };
    template <> struct default_interface<llm:OS::UI::Composition::BounceVector2NaturalMotionAnimation>{ using type = llm:OS::UI::Composition::IBounceVector2NaturalMotionAnimation; };
    template <> struct default_interface<llm:OS::UI::Composition::BounceVector3NaturalMotionAnimation>{ using type = llm:OS::UI::Composition::IBounceVector3NaturalMotionAnimation; };
    template <> struct default_interface<llm:OS::UI::Composition::CircleEasingFunction>{ using type = llm:OS::UI::Composition::ICircleEasingFunction; };
    template <> struct default_interface<llm:OS::UI::Composition::ColorKeyFrameAnimation>{ using type = llm:OS::UI::Composition::IColorKeyFrameAnimation; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionAnimation>{ using type = llm:OS::UI::Composition::ICompositionAnimation; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionAnimationGroup>{ using type = llm:OS::UI::Composition::ICompositionAnimationGroup; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionBackdropBrush>{ using type = llm:OS::UI::Composition::ICompositionBackdropBrush; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionBatchCompletedEventArgs>{ using type = llm:OS::UI::Composition::ICompositionBatchCompletedEventArgs; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionBrush>{ using type = llm:OS::UI::Composition::ICompositionBrush; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionCapabilities>{ using type = llm:OS::UI::Composition::ICompositionCapabilities; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionClip>{ using type = llm:OS::UI::Composition::ICompositionClip; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionColorBrush>{ using type = llm:OS::UI::Composition::ICompositionColorBrush; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionColorGradientStop>{ using type = llm:OS::UI::Composition::ICompositionColorGradientStop; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionColorGradientStopCollection>{ using type = llm:OS::UI::Composition::ICompositionColorGradientStopCollection; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionCommitBatch>{ using type = llm:OS::UI::Composition::ICompositionCommitBatch; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionContainerShape>{ using type = llm:OS::UI::Composition::ICompositionContainerShape; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionDrawingSurface>{ using type = llm:OS::UI::Composition::ICompositionDrawingSurface; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionEasingFunction>{ using type = llm:OS::UI::Composition::ICompositionEasingFunction; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionEffectBrush>{ using type = llm:OS::UI::Composition::ICompositionEffectBrush; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionEffectFactory>{ using type = llm:OS::UI::Composition::ICompositionEffectFactory; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionEffectSourceParameter>{ using type = llm:OS::UI::Composition::ICompositionEffectSourceParameter; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionEllipseGeometry>{ using type = llm:OS::UI::Composition::ICompositionEllipseGeometry; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionGeometricClip>{ using type = llm:OS::UI::Composition::ICompositionGeometricClip; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionGeometry>{ using type = llm:OS::UI::Composition::ICompositionGeometry; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionGradientBrush>{ using type = llm:OS::UI::Composition::ICompositionGradientBrush; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionGraphicsDevice>{ using type = llm:OS::UI::Composition::ICompositionGraphicsDevice; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionLight>{ using type = llm:OS::UI::Composition::ICompositionLight; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionLineGeometry>{ using type = llm:OS::UI::Composition::ICompositionLineGeometry; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionLinearGradientBrush>{ using type = llm:OS::UI::Composition::ICompositionLinearGradientBrush; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionMaskBrush>{ using type = llm:OS::UI::Composition::ICompositionMaskBrush; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionMipmapSurface>{ using type = llm:OS::UI::Composition::ICompositionMipmapSurface; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionNineGridBrush>{ using type = llm:OS::UI::Composition::ICompositionNineGridBrush; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionObject>{ using type = llm:OS::UI::Composition::ICompositionObject; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionPath>{ using type = llm:OS::UI::Composition::ICompositionPath; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionPathGeometry>{ using type = llm:OS::UI::Composition::ICompositionPathGeometry; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionProjectedShadow>{ using type = llm:OS::UI::Composition::ICompositionProjectedShadow; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionProjectedShadowCaster>{ using type = llm:OS::UI::Composition::ICompositionProjectedShadowCaster; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionProjectedShadowCasterCollection>{ using type = llm:OS::UI::Composition::ICompositionProjectedShadowCasterCollection; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionProjectedShadowReceiver>{ using type = llm:OS::UI::Composition::ICompositionProjectedShadowReceiver; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionProjectedShadowReceiverUnorderedCollection>{ using type = llm:OS::UI::Composition::ICompositionProjectedShadowReceiverUnorderedCollection; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionPropertySet>{ using type = llm:OS::UI::Composition::ICompositionPropertySet; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionRadialGradientBrush>{ using type = llm:OS::UI::Composition::ICompositionRadialGradientBrush; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionRectangleGeometry>{ using type = llm:OS::UI::Composition::ICompositionRectangleGeometry; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionRoundedRectangleGeometry>{ using type = llm:OS::UI::Composition::ICompositionRoundedRectangleGeometry; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionScopedBatch>{ using type = llm:OS::UI::Composition::ICompositionScopedBatch; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionShadow>{ using type = llm:OS::UI::Composition::ICompositionShadow; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionShape>{ using type = llm:OS::UI::Composition::ICompositionShape; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionShapeCollection>{ using type = llm:OS::Foundation::Collections::IVector<llm:OS::UI::Composition::CompositionShape>; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionSpriteShape>{ using type = llm:OS::UI::Composition::ICompositionSpriteShape; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionStrokeDashArray>{ using type = llm:OS::Foundation::Collections::IVector<float>; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionSurfaceBrush>{ using type = llm:OS::UI::Composition::ICompositionSurfaceBrush; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionTarget>{ using type = llm:OS::UI::Composition::ICompositionTarget; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionTexture>{ using type = llm:OS::UI::Composition::ICompositionTexture; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionTransform>{ using type = llm:OS::UI::Composition::ICompositionTransform; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionViewBox>{ using type = llm:OS::UI::Composition::ICompositionViewBox; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionVirtualDrawingSurface>{ using type = llm:OS::UI::Composition::ICompositionVirtualDrawingSurface; };
    template <> struct default_interface<llm:OS::UI::Composition::CompositionVisualSurface>{ using type = llm:OS::UI::Composition::ICompositionVisualSurface; };
    template <> struct default_interface<llm:OS::UI::Composition::Compositor>{ using type = llm:OS::UI::Composition::ICompositor; };
    template <> struct default_interface<llm:OS::UI::Composition::ContainerVisual>{ using type = llm:OS::UI::Composition::IContainerVisual; };
    template <> struct default_interface<llm:OS::UI::Composition::CubicBezierEasingFunction>{ using type = llm:OS::UI::Composition::ICubicBezierEasingFunction; };
    template <> struct default_interface<llm:OS::UI::Composition::DelegatedInkTrailVisual>{ using type = llm:OS::UI::Composition::IDelegatedInkTrailVisual; };
    template <> struct default_interface<llm:OS::UI::Composition::DistantLight>{ using type = llm:OS::UI::Composition::IDistantLight; };
    template <> struct default_interface<llm:OS::UI::Composition::DropShadow>{ using type = llm:OS::UI::Composition::IDropShadow; };
    template <> struct default_interface<llm:OS::UI::Composition::ElasticEasingFunction>{ using type = llm:OS::UI::Composition::IElasticEasingFunction; };
    template <> struct default_interface<llm:OS::UI::Composition::ExponentialEasingFunction>{ using type = llm:OS::UI::Composition::IExponentialEasingFunction; };
    template <> struct default_interface<llm:OS::UI::Composition::ExpressionAnimation>{ using type = llm:OS::UI::Composition::IExpressionAnimation; };
    template <> struct default_interface<llm:OS::UI::Composition::ImplicitAnimationCollection>{ using type = llm:OS::UI::Composition::IImplicitAnimationCollection; };
    template <> struct default_interface<llm:OS::UI::Composition::InitialValueExpressionCollection>{ using type = llm:OS::Foundation::Collections::IMap<hstring, hstring>; };
    template <> struct default_interface<llm:OS::UI::Composition::InsetClip>{ using type = llm:OS::UI::Composition::IInsetClip; };
    template <> struct default_interface<llm:OS::UI::Composition::KeyFrameAnimation>{ using type = llm:OS::UI::Composition::IKeyFrameAnimation; };
    template <> struct default_interface<llm:OS::UI::Composition::LayerVisual>{ using type = llm:OS::UI::Composition::ILayerVisual; };
    template <> struct default_interface<llm:OS::UI::Composition::LinearEasingFunction>{ using type = llm:OS::UI::Composition::ILinearEasingFunction; };
    template <> struct default_interface<llm:OS::UI::Composition::NaturalMotionAnimation>{ using type = llm:OS::UI::Composition::INaturalMotionAnimation; };
    template <> struct default_interface<llm:OS::UI::Composition::PathKeyFrameAnimation>{ using type = llm:OS::UI::Composition::IPathKeyFrameAnimation; };
    template <> struct default_interface<llm:OS::UI::Composition::PointLight>{ using type = llm:OS::UI::Composition::IPointLight; };
    template <> struct default_interface<llm:OS::UI::Composition::PowerEasingFunction>{ using type = llm:OS::UI::Composition::IPowerEasingFunction; };
    template <> struct default_interface<llm:OS::UI::Composition::QuaternionKeyFrameAnimation>{ using type = llm:OS::UI::Composition::IQuaternionKeyFrameAnimation; };
    template <> struct default_interface<llm:OS::UI::Composition::RectangleClip>{ using type = llm:OS::UI::Composition::IRectangleClip; };
    template <> struct default_interface<llm:OS::UI::Composition::RedirectVisual>{ using type = llm:OS::UI::Composition::IRedirectVisual; };
    template <> struct default_interface<llm:OS::UI::Composition::RenderingDeviceReplacedEventArgs>{ using type = llm:OS::UI::Composition::IRenderingDeviceReplacedEventArgs; };
    template <> struct default_interface<llm:OS::UI::Composition::ScalarKeyFrameAnimation>{ using type = llm:OS::UI::Composition::IScalarKeyFrameAnimation; };
    template <> struct default_interface<llm:OS::UI::Composition::ScalarNaturalMotionAnimation>{ using type = llm:OS::UI::Composition::IScalarNaturalMotionAnimation; };
    template <> struct default_interface<llm:OS::UI::Composition::ShapeVisual>{ using type = llm:OS::UI::Composition::IShapeVisual; };
    template <> struct default_interface<llm:OS::UI::Composition::SineEasingFunction>{ using type = llm:OS::UI::Composition::ISineEasingFunction; };
    template <> struct default_interface<llm:OS::UI::Composition::SpotLight>{ using type = llm:OS::UI::Composition::ISpotLight; };
    template <> struct default_interface<llm:OS::UI::Composition::SpringScalarNaturalMotionAnimation>{ using type = llm:OS::UI::Composition::ISpringScalarNaturalMotionAnimation; };
    template <> struct default_interface<llm:OS::UI::Composition::SpringVector2NaturalMotionAnimation>{ using type = llm:OS::UI::Composition::ISpringVector2NaturalMotionAnimation; };
    template <> struct default_interface<llm:OS::UI::Composition::SpringVector3NaturalMotionAnimation>{ using type = llm:OS::UI::Composition::ISpringVector3NaturalMotionAnimation; };
    template <> struct default_interface<llm:OS::UI::Composition::SpriteVisual>{ using type = llm:OS::UI::Composition::ISpriteVisual; };
    template <> struct default_interface<llm:OS::UI::Composition::StepEasingFunction>{ using type = llm:OS::UI::Composition::IStepEasingFunction; };
    template <> struct default_interface<llm:OS::UI::Composition::Vector2KeyFrameAnimation>{ using type = llm:OS::UI::Composition::IVector2KeyFrameAnimation; };
    template <> struct default_interface<llm:OS::UI::Composition::Vector2NaturalMotionAnimation>{ using type = llm:OS::UI::Composition::IVector2NaturalMotionAnimation; };
    template <> struct default_interface<llm:OS::UI::Composition::Vector3KeyFrameAnimation>{ using type = llm:OS::UI::Composition::IVector3KeyFrameAnimation; };
    template <> struct default_interface<llm:OS::UI::Composition::Vector3NaturalMotionAnimation>{ using type = llm:OS::UI::Composition::IVector3NaturalMotionAnimation; };
    template <> struct default_interface<llm:OS::UI::Composition::Vector4KeyFrameAnimation>{ using type = llm:OS::UI::Composition::IVector4KeyFrameAnimation; };
    template <> struct default_interface<llm:OS::UI::Composition::Visual>{ using type = llm:OS::UI::Composition::IVisual; };
    template <> struct default_interface<llm:OS::UI::Composition::VisualCollection>{ using type = llm:OS::UI::Composition::IVisualCollection; };
    template <> struct default_interface<llm:OS::UI::Composition::VisualUnorderedCollection>{ using type = llm:OS::UI::Composition::IVisualUnorderedCollection; };
    template <> struct abi<llm:OS::UI::Composition::IAmbientLight>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Color(struct struct_Windows_UI_Color*) noexcept = 0;
            virtual int32_t __stdcall put_Color(struct struct_Windows_UI_Color) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IAmbientLight2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Intensity(float*) noexcept = 0;
            virtual int32_t __stdcall put_Intensity(float) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IAnimationController>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_PlaybackRate(float*) noexcept = 0;
            virtual int32_t __stdcall put_PlaybackRate(float) noexcept = 0;
            virtual int32_t __stdcall get_Progress(float*) noexcept = 0;
            virtual int32_t __stdcall put_Progress(float) noexcept = 0;
            virtual int32_t __stdcall get_ProgressBehavior(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_ProgressBehavior(int32_t) noexcept = 0;
            virtual int32_t __stdcall Pause() noexcept = 0;
            virtual int32_t __stdcall Resume() noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IAnimationControllerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_MaxPlaybackRate(float*) noexcept = 0;
            virtual int32_t __stdcall get_MinPlaybackRate(float*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IAnimationObject>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall PopulatePropertyInfo(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IAnimationPropertyInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AccessMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_AccessMode(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IAnimationPropertyInfo2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetResolvedCompositionObject(void**) noexcept = 0;
            virtual int32_t __stdcall GetResolvedCompositionObjectProperty(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IBackEasingFunction>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Mode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Amplitude(float*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IBooleanKeyFrameAnimation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall InsertKeyFrame(float, bool) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IBounceEasingFunction>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Mode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Bounces(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Bounciness(float*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IBounceScalarNaturalMotionAnimation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Acceleration(float*) noexcept = 0;
            virtual int32_t __stdcall put_Acceleration(float) noexcept = 0;
            virtual int32_t __stdcall get_Restitution(float*) noexcept = 0;
            virtual int32_t __stdcall put_Restitution(float) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IBounceVector2NaturalMotionAnimation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Acceleration(float*) noexcept = 0;
            virtual int32_t __stdcall put_Acceleration(float) noexcept = 0;
            virtual int32_t __stdcall get_Restitution(float*) noexcept = 0;
            virtual int32_t __stdcall put_Restitution(float) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IBounceVector3NaturalMotionAnimation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Acceleration(float*) noexcept = 0;
            virtual int32_t __stdcall put_Acceleration(float) noexcept = 0;
            virtual int32_t __stdcall get_Restitution(float*) noexcept = 0;
            virtual int32_t __stdcall put_Restitution(float) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICircleEasingFunction>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Mode(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IColorKeyFrameAnimation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_InterpolationColorSpace(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_InterpolationColorSpace(int32_t) noexcept = 0;
            virtual int32_t __stdcall InsertKeyFrame(float, struct struct_Windows_UI_Color) noexcept = 0;
            virtual int32_t __stdcall InsertKeyFrameWithEasingFunction(float, struct struct_Windows_UI_Color, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionAnimation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall ClearAllParameters() noexcept = 0;
            virtual int32_t __stdcall ClearParameter(void*) noexcept = 0;
            virtual int32_t __stdcall SetColorParameter(void*, struct struct_Windows_UI_Color) noexcept = 0;
            virtual int32_t __stdcall SetMatrix3x2Parameter(void*, llm:OS::Foundation::Numerics::float3x2) noexcept = 0;
            virtual int32_t __stdcall SetMatrix4x4Parameter(void*, llm:OS::Foundation::Numerics::float4x4) noexcept = 0;
            virtual int32_t __stdcall SetQuaternionParameter(void*, llm:OS::Foundation::Numerics::quaternion) noexcept = 0;
            virtual int32_t __stdcall SetReferenceParameter(void*, void*) noexcept = 0;
            virtual int32_t __stdcall SetScalarParameter(void*, float) noexcept = 0;
            virtual int32_t __stdcall SetVector2Parameter(void*, llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall SetVector3Parameter(void*, llm:OS::Foundation::Numerics::float3) noexcept = 0;
            virtual int32_t __stdcall SetVector4Parameter(void*, llm:OS::Foundation::Numerics::float4) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionAnimation2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SetBooleanParameter(void*, bool) noexcept = 0;
            virtual int32_t __stdcall get_Target(void**) noexcept = 0;
            virtual int32_t __stdcall put_Target(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionAnimation3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_InitialValueExpressions(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionAnimation4>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SetExpressionReferenceParameter(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionAnimationBase>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionAnimationFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionAnimationGroup>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Count(int32_t*) noexcept = 0;
            virtual int32_t __stdcall Add(void*) noexcept = 0;
            virtual int32_t __stdcall Remove(void*) noexcept = 0;
            virtual int32_t __stdcall RemoveAll() noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionBackdropBrush>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionBatchCompletedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionBrush>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionBrushFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionCapabilities>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall AreEffectsSupported(bool*) noexcept = 0;
            virtual int32_t __stdcall AreEffectsFast(bool*) noexcept = 0;
            virtual int32_t __stdcall add_Changed(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Changed(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionCapabilitiesStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetForCurrentView(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionClip>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionClip2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AnchorPoint(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_AnchorPoint(llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall get_CenterPoint(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_CenterPoint(llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall get_Offset(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_Offset(llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall get_RotationAngle(float*) noexcept = 0;
            virtual int32_t __stdcall put_RotationAngle(float) noexcept = 0;
            virtual int32_t __stdcall get_RotationAngleInDegrees(float*) noexcept = 0;
            virtual int32_t __stdcall put_RotationAngleInDegrees(float) noexcept = 0;
            virtual int32_t __stdcall get_Scale(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_Scale(llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall get_TransformMatrix(llm:OS::Foundation::Numerics::float3x2*) noexcept = 0;
            virtual int32_t __stdcall put_TransformMatrix(llm:OS::Foundation::Numerics::float3x2) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionClipFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionColorBrush>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Color(struct struct_Windows_UI_Color*) noexcept = 0;
            virtual int32_t __stdcall put_Color(struct struct_Windows_UI_Color) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionColorGradientStop>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Color(struct struct_Windows_UI_Color*) noexcept = 0;
            virtual int32_t __stdcall put_Color(struct struct_Windows_UI_Color) noexcept = 0;
            virtual int32_t __stdcall get_Offset(float*) noexcept = 0;
            virtual int32_t __stdcall put_Offset(float) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionColorGradientStopCollection>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionCommitBatch>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsActive(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsEnded(bool*) noexcept = 0;
            virtual int32_t __stdcall add_Completed(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Completed(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionContainerShape>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Shapes(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionDrawingSurface>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AlphaMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_PixelFormat(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Size(llm:OS::Foundation::Size*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionDrawingSurface2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SizeInt32(struct struct_Windows_Graphics_SizeInt32*) noexcept = 0;
            virtual int32_t __stdcall Resize(struct struct_Windows_Graphics_SizeInt32) noexcept = 0;
            virtual int32_t __stdcall Scroll(struct struct_Windows_Graphics_PointInt32) noexcept = 0;
            virtual int32_t __stdcall ScrollRect(struct struct_Windows_Graphics_PointInt32, struct struct_Windows_Graphics_RectInt32) noexcept = 0;
            virtual int32_t __stdcall ScrollWithClip(struct struct_Windows_Graphics_PointInt32, struct struct_Windows_Graphics_RectInt32) noexcept = 0;
            virtual int32_t __stdcall ScrollRectWithClip(struct struct_Windows_Graphics_PointInt32, struct struct_Windows_Graphics_RectInt32, struct struct_Windows_Graphics_RectInt32) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionDrawingSurfaceFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionEasingFunction>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionEasingFunctionFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionEasingFunctionStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateCubicBezierEasingFunction(void*, llm:OS::Foundation::Numerics::float2, llm:OS::Foundation::Numerics::float2, void**) noexcept = 0;
            virtual int32_t __stdcall CreateLinearEasingFunction(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateStepEasingFunction(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateStepEasingFunctionWithStepCount(void*, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall CreateBackEasingFunction(void*, int32_t, float, void**) noexcept = 0;
            virtual int32_t __stdcall CreateBounceEasingFunction(void*, int32_t, int32_t, float, void**) noexcept = 0;
            virtual int32_t __stdcall CreateCircleEasingFunction(void*, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall CreateElasticEasingFunction(void*, int32_t, int32_t, float, void**) noexcept = 0;
            virtual int32_t __stdcall CreateExponentialEasingFunction(void*, int32_t, float, void**) noexcept = 0;
            virtual int32_t __stdcall CreatePowerEasingFunction(void*, int32_t, float, void**) noexcept = 0;
            virtual int32_t __stdcall CreateSineEasingFunction(void*, int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionEffectBrush>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetSourceParameter(void*, void**) noexcept = 0;
            virtual int32_t __stdcall SetSourceParameter(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionEffectFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateBrush(void**) noexcept = 0;
            virtual int32_t __stdcall get_ExtendedError(llm::hresult*) noexcept = 0;
            virtual int32_t __stdcall get_LoadStatus(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionEffectSourceParameter>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionEffectSourceParameterFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionEllipseGeometry>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Center(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_Center(llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall get_Radius(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_Radius(llm:OS::Foundation::Numerics::float2) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionGeometricClip>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Geometry(void**) noexcept = 0;
            virtual int32_t __stdcall put_Geometry(void*) noexcept = 0;
            virtual int32_t __stdcall get_ViewBox(void**) noexcept = 0;
            virtual int32_t __stdcall put_ViewBox(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionGeometry>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_TrimEnd(float*) noexcept = 0;
            virtual int32_t __stdcall put_TrimEnd(float) noexcept = 0;
            virtual int32_t __stdcall get_TrimOffset(float*) noexcept = 0;
            virtual int32_t __stdcall put_TrimOffset(float) noexcept = 0;
            virtual int32_t __stdcall get_TrimStart(float*) noexcept = 0;
            virtual int32_t __stdcall put_TrimStart(float) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionGeometryFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionGradientBrush>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AnchorPoint(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_AnchorPoint(llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall get_CenterPoint(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_CenterPoint(llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall get_ColorStops(void**) noexcept = 0;
            virtual int32_t __stdcall get_ExtendMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_ExtendMode(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_InterpolationSpace(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_InterpolationSpace(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_Offset(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_Offset(llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall get_RotationAngle(float*) noexcept = 0;
            virtual int32_t __stdcall put_RotationAngle(float) noexcept = 0;
            virtual int32_t __stdcall get_RotationAngleInDegrees(float*) noexcept = 0;
            virtual int32_t __stdcall put_RotationAngleInDegrees(float) noexcept = 0;
            virtual int32_t __stdcall get_Scale(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_Scale(llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall get_TransformMatrix(llm:OS::Foundation::Numerics::float3x2*) noexcept = 0;
            virtual int32_t __stdcall put_TransformMatrix(llm:OS::Foundation::Numerics::float3x2) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionGradientBrush2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_MappingMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_MappingMode(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionGradientBrushFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionGraphicsDevice>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateDrawingSurface(llm:OS::Foundation::Size, int32_t, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall add_RenderingDeviceReplaced(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_RenderingDeviceReplaced(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionGraphicsDevice2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateDrawingSurface2(struct struct_Windows_Graphics_SizeInt32, int32_t, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall CreateVirtualDrawingSurface(struct struct_Windows_Graphics_SizeInt32, int32_t, int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionGraphicsDevice3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateMipmapSurface(struct struct_Windows_Graphics_SizeInt32, int32_t, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall Trim() noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionGraphicsDevice4>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CaptureAsync(void*, struct struct_Windows_Graphics_SizeInt32, int32_t, int32_t, float, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionLight>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Targets(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionLight2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ExclusionsFromTargets(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionLight3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsEnabled(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionLightFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionLineGeometry>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Start(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_Start(llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall get_End(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_End(llm:OS::Foundation::Numerics::float2) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionLinearGradientBrush>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_EndPoint(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_EndPoint(llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall get_StartPoint(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_StartPoint(llm:OS::Foundation::Numerics::float2) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionMaskBrush>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Mask(void**) noexcept = 0;
            virtual int32_t __stdcall put_Mask(void*) noexcept = 0;
            virtual int32_t __stdcall get_Source(void**) noexcept = 0;
            virtual int32_t __stdcall put_Source(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionMipmapSurface>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_LevelCount(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_AlphaMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_PixelFormat(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_SizeInt32(struct struct_Windows_Graphics_SizeInt32*) noexcept = 0;
            virtual int32_t __stdcall GetDrawingSurfaceForLevel(uint32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionNineGridBrush>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_BottomInset(float*) noexcept = 0;
            virtual int32_t __stdcall put_BottomInset(float) noexcept = 0;
            virtual int32_t __stdcall get_BottomInsetScale(float*) noexcept = 0;
            virtual int32_t __stdcall put_BottomInsetScale(float) noexcept = 0;
            virtual int32_t __stdcall get_IsCenterHollow(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsCenterHollow(bool) noexcept = 0;
            virtual int32_t __stdcall get_LeftInset(float*) noexcept = 0;
            virtual int32_t __stdcall put_LeftInset(float) noexcept = 0;
            virtual int32_t __stdcall get_LeftInsetScale(float*) noexcept = 0;
            virtual int32_t __stdcall put_LeftInsetScale(float) noexcept = 0;
            virtual int32_t __stdcall get_RightInset(float*) noexcept = 0;
            virtual int32_t __stdcall put_RightInset(float) noexcept = 0;
            virtual int32_t __stdcall get_RightInsetScale(float*) noexcept = 0;
            virtual int32_t __stdcall put_RightInsetScale(float) noexcept = 0;
            virtual int32_t __stdcall get_Source(void**) noexcept = 0;
            virtual int32_t __stdcall put_Source(void*) noexcept = 0;
            virtual int32_t __stdcall get_TopInset(float*) noexcept = 0;
            virtual int32_t __stdcall put_TopInset(float) noexcept = 0;
            virtual int32_t __stdcall get_TopInsetScale(float*) noexcept = 0;
            virtual int32_t __stdcall put_TopInsetScale(float) noexcept = 0;
            virtual int32_t __stdcall SetInsets(float) noexcept = 0;
            virtual int32_t __stdcall SetInsetsWithValues(float, float, float, float) noexcept = 0;
            virtual int32_t __stdcall SetInsetScales(float) noexcept = 0;
            virtual int32_t __stdcall SetInsetScalesWithValues(float, float, float, float) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionObject>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Compositor(void**) noexcept = 0;
            virtual int32_t __stdcall get_Dispatcher(void**) noexcept = 0;
            virtual int32_t __stdcall get_Properties(void**) noexcept = 0;
            virtual int32_t __stdcall StartAnimation(void*, void*) noexcept = 0;
            virtual int32_t __stdcall StopAnimation(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionObject2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Comment(void**) noexcept = 0;
            virtual int32_t __stdcall put_Comment(void*) noexcept = 0;
            virtual int32_t __stdcall get_ImplicitAnimations(void**) noexcept = 0;
            virtual int32_t __stdcall put_ImplicitAnimations(void*) noexcept = 0;
            virtual int32_t __stdcall StartAnimationGroup(void*) noexcept = 0;
            virtual int32_t __stdcall StopAnimationGroup(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionObject3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DispatcherQueue(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionObject4>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall TryGetAnimationController(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionObject5>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall StartAnimationWithController(void*, void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionObjectFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionObjectStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall StartAnimationWithIAnimationObject(void*, void*, void*) noexcept = 0;
            virtual int32_t __stdcall StartAnimationGroupWithIAnimationObject(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionPath>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionPathFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionPathGeometry>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Path(void**) noexcept = 0;
            virtual int32_t __stdcall put_Path(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionProjectedShadow>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_BlurRadiusMultiplier(float*) noexcept = 0;
            virtual int32_t __stdcall put_BlurRadiusMultiplier(float) noexcept = 0;
            virtual int32_t __stdcall get_Casters(void**) noexcept = 0;
            virtual int32_t __stdcall get_LightSource(void**) noexcept = 0;
            virtual int32_t __stdcall put_LightSource(void*) noexcept = 0;
            virtual int32_t __stdcall get_MaxBlurRadius(float*) noexcept = 0;
            virtual int32_t __stdcall put_MaxBlurRadius(float) noexcept = 0;
            virtual int32_t __stdcall get_MinBlurRadius(float*) noexcept = 0;
            virtual int32_t __stdcall put_MinBlurRadius(float) noexcept = 0;
            virtual int32_t __stdcall get_Receivers(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionProjectedShadowCaster>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Brush(void**) noexcept = 0;
            virtual int32_t __stdcall put_Brush(void*) noexcept = 0;
            virtual int32_t __stdcall get_CastingVisual(void**) noexcept = 0;
            virtual int32_t __stdcall put_CastingVisual(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionProjectedShadowCasterCollection>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Count(int32_t*) noexcept = 0;
            virtual int32_t __stdcall InsertAbove(void*, void*) noexcept = 0;
            virtual int32_t __stdcall InsertAtBottom(void*) noexcept = 0;
            virtual int32_t __stdcall InsertAtTop(void*) noexcept = 0;
            virtual int32_t __stdcall InsertBelow(void*, void*) noexcept = 0;
            virtual int32_t __stdcall Remove(void*) noexcept = 0;
            virtual int32_t __stdcall RemoveAll() noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionProjectedShadowCasterCollectionStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_MaxRespectedCasters(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionProjectedShadowReceiver>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ReceivingVisual(void**) noexcept = 0;
            virtual int32_t __stdcall put_ReceivingVisual(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionProjectedShadowReceiverUnorderedCollection>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Add(void*) noexcept = 0;
            virtual int32_t __stdcall get_Count(int32_t*) noexcept = 0;
            virtual int32_t __stdcall Remove(void*) noexcept = 0;
            virtual int32_t __stdcall RemoveAll() noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionPropertySet>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall InsertColor(void*, struct struct_Windows_UI_Color) noexcept = 0;
            virtual int32_t __stdcall InsertMatrix3x2(void*, llm:OS::Foundation::Numerics::float3x2) noexcept = 0;
            virtual int32_t __stdcall InsertMatrix4x4(void*, llm:OS::Foundation::Numerics::float4x4) noexcept = 0;
            virtual int32_t __stdcall InsertQuaternion(void*, llm:OS::Foundation::Numerics::quaternion) noexcept = 0;
            virtual int32_t __stdcall InsertScalar(void*, float) noexcept = 0;
            virtual int32_t __stdcall InsertVector2(void*, llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall InsertVector3(void*, llm:OS::Foundation::Numerics::float3) noexcept = 0;
            virtual int32_t __stdcall InsertVector4(void*, llm:OS::Foundation::Numerics::float4) noexcept = 0;
            virtual int32_t __stdcall TryGetColor(void*, struct struct_Windows_UI_Color*, int32_t*) noexcept = 0;
            virtual int32_t __stdcall TryGetMatrix3x2(void*, llm:OS::Foundation::Numerics::float3x2*, int32_t*) noexcept = 0;
            virtual int32_t __stdcall TryGetMatrix4x4(void*, llm:OS::Foundation::Numerics::float4x4*, int32_t*) noexcept = 0;
            virtual int32_t __stdcall TryGetQuaternion(void*, llm:OS::Foundation::Numerics::quaternion*, int32_t*) noexcept = 0;
            virtual int32_t __stdcall TryGetScalar(void*, float*, int32_t*) noexcept = 0;
            virtual int32_t __stdcall TryGetVector2(void*, llm:OS::Foundation::Numerics::float2*, int32_t*) noexcept = 0;
            virtual int32_t __stdcall TryGetVector3(void*, llm:OS::Foundation::Numerics::float3*, int32_t*) noexcept = 0;
            virtual int32_t __stdcall TryGetVector4(void*, llm:OS::Foundation::Numerics::float4*, int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionPropertySet2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall InsertBoolean(void*, bool) noexcept = 0;
            virtual int32_t __stdcall TryGetBoolean(void*, bool*, int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionRadialGradientBrush>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_EllipseCenter(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_EllipseCenter(llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall get_EllipseRadius(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_EllipseRadius(llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall get_GradientOriginOffset(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_GradientOriginOffset(llm:OS::Foundation::Numerics::float2) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionRectangleGeometry>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Offset(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_Offset(llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall get_Size(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_Size(llm:OS::Foundation::Numerics::float2) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionRoundedRectangleGeometry>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_CornerRadius(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_CornerRadius(llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall get_Offset(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_Offset(llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall get_Size(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_Size(llm:OS::Foundation::Numerics::float2) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionScopedBatch>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsActive(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsEnded(bool*) noexcept = 0;
            virtual int32_t __stdcall End() noexcept = 0;
            virtual int32_t __stdcall Resume() noexcept = 0;
            virtual int32_t __stdcall Suspend() noexcept = 0;
            virtual int32_t __stdcall add_Completed(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Completed(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionShadow>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionShadowFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionShape>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_CenterPoint(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_CenterPoint(llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall get_Offset(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_Offset(llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall get_RotationAngle(float*) noexcept = 0;
            virtual int32_t __stdcall put_RotationAngle(float) noexcept = 0;
            virtual int32_t __stdcall get_RotationAngleInDegrees(float*) noexcept = 0;
            virtual int32_t __stdcall put_RotationAngleInDegrees(float) noexcept = 0;
            virtual int32_t __stdcall get_Scale(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_Scale(llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall get_TransformMatrix(llm:OS::Foundation::Numerics::float3x2*) noexcept = 0;
            virtual int32_t __stdcall put_TransformMatrix(llm:OS::Foundation::Numerics::float3x2) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionShapeFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionSpriteShape>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_FillBrush(void**) noexcept = 0;
            virtual int32_t __stdcall put_FillBrush(void*) noexcept = 0;
            virtual int32_t __stdcall get_Geometry(void**) noexcept = 0;
            virtual int32_t __stdcall put_Geometry(void*) noexcept = 0;
            virtual int32_t __stdcall get_IsStrokeNonScaling(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsStrokeNonScaling(bool) noexcept = 0;
            virtual int32_t __stdcall get_StrokeBrush(void**) noexcept = 0;
            virtual int32_t __stdcall put_StrokeBrush(void*) noexcept = 0;
            virtual int32_t __stdcall get_StrokeDashArray(void**) noexcept = 0;
            virtual int32_t __stdcall get_StrokeDashCap(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_StrokeDashCap(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_StrokeDashOffset(float*) noexcept = 0;
            virtual int32_t __stdcall put_StrokeDashOffset(float) noexcept = 0;
            virtual int32_t __stdcall get_StrokeEndCap(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_StrokeEndCap(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_StrokeLineJoin(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_StrokeLineJoin(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_StrokeMiterLimit(float*) noexcept = 0;
            virtual int32_t __stdcall put_StrokeMiterLimit(float) noexcept = 0;
            virtual int32_t __stdcall get_StrokeStartCap(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_StrokeStartCap(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_StrokeThickness(float*) noexcept = 0;
            virtual int32_t __stdcall put_StrokeThickness(float) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionSupportsSystemBackdrop>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SystemBackdrop(void**) noexcept = 0;
            virtual int32_t __stdcall put_SystemBackdrop(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionSurface>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionSurfaceBrush>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_BitmapInterpolationMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_BitmapInterpolationMode(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_HorizontalAlignmentRatio(float*) noexcept = 0;
            virtual int32_t __stdcall put_HorizontalAlignmentRatio(float) noexcept = 0;
            virtual int32_t __stdcall get_Stretch(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Stretch(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_Surface(void**) noexcept = 0;
            virtual int32_t __stdcall put_Surface(void*) noexcept = 0;
            virtual int32_t __stdcall get_VerticalAlignmentRatio(float*) noexcept = 0;
            virtual int32_t __stdcall put_VerticalAlignmentRatio(float) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionSurfaceBrush2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AnchorPoint(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_AnchorPoint(llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall get_CenterPoint(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_CenterPoint(llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall get_Offset(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_Offset(llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall get_RotationAngle(float*) noexcept = 0;
            virtual int32_t __stdcall put_RotationAngle(float) noexcept = 0;
            virtual int32_t __stdcall get_RotationAngleInDegrees(float*) noexcept = 0;
            virtual int32_t __stdcall put_RotationAngleInDegrees(float) noexcept = 0;
            virtual int32_t __stdcall get_Scale(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_Scale(llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall get_TransformMatrix(llm:OS::Foundation::Numerics::float3x2*) noexcept = 0;
            virtual int32_t __stdcall put_TransformMatrix(llm:OS::Foundation::Numerics::float3x2) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionSurfaceBrush3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SnapToPixels(bool*) noexcept = 0;
            virtual int32_t __stdcall put_SnapToPixels(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionSurfaceFacade>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetRealSurface(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionTarget>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Root(void**) noexcept = 0;
            virtual int32_t __stdcall put_Root(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionTargetFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionTexture>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SourceRect(struct struct_Windows_Graphics_RectInt32*) noexcept = 0;
            virtual int32_t __stdcall put_SourceRect(struct struct_Windows_Graphics_RectInt32) noexcept = 0;
            virtual int32_t __stdcall get_AlphaMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_AlphaMode(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_ColorSpace(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_ColorSpace(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionTextureFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionTransform>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionTransformFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionViewBox>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_HorizontalAlignmentRatio(float*) noexcept = 0;
            virtual int32_t __stdcall put_HorizontalAlignmentRatio(float) noexcept = 0;
            virtual int32_t __stdcall get_Offset(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_Offset(llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall get_Size(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_Size(llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall get_Stretch(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Stretch(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_VerticalAlignmentRatio(float*) noexcept = 0;
            virtual int32_t __stdcall put_VerticalAlignmentRatio(float) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionVirtualDrawingSurface>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Trim(uint32_t, struct struct_Windows_Graphics_RectInt32*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionVirtualDrawingSurfaceFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositionVisualSurface>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SourceVisual(void**) noexcept = 0;
            virtual int32_t __stdcall put_SourceVisual(void*) noexcept = 0;
            virtual int32_t __stdcall get_SourceOffset(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_SourceOffset(llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall get_SourceSize(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_SourceSize(llm:OS::Foundation::Numerics::float2) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositor>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateColorKeyFrameAnimation(void**) noexcept = 0;
            virtual int32_t __stdcall CreateColorBrush(void**) noexcept = 0;
            virtual int32_t __stdcall CreateColorBrushWithColor(struct struct_Windows_UI_Color, void**) noexcept = 0;
            virtual int32_t __stdcall CreateContainerVisual(void**) noexcept = 0;
            virtual int32_t __stdcall CreateCubicBezierEasingFunction(llm:OS::Foundation::Numerics::float2, llm:OS::Foundation::Numerics::float2, void**) noexcept = 0;
            virtual int32_t __stdcall CreateEffectFactory(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateEffectFactoryWithProperties(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateExpressionAnimation(void**) noexcept = 0;
            virtual int32_t __stdcall CreateExpressionAnimationWithExpression(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateInsetClip(void**) noexcept = 0;
            virtual int32_t __stdcall CreateInsetClipWithInsets(float, float, float, float, void**) noexcept = 0;
            virtual int32_t __stdcall CreateLinearEasingFunction(void**) noexcept = 0;
            virtual int32_t __stdcall CreatePropertySet(void**) noexcept = 0;
            virtual int32_t __stdcall CreateQuaternionKeyFrameAnimation(void**) noexcept = 0;
            virtual int32_t __stdcall CreateScalarKeyFrameAnimation(void**) noexcept = 0;
            virtual int32_t __stdcall CreateScopedBatch(uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall CreateSpriteVisual(void**) noexcept = 0;
            virtual int32_t __stdcall CreateSurfaceBrush(void**) noexcept = 0;
            virtual int32_t __stdcall CreateSurfaceBrushWithSurface(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateTargetForCurrentView(void**) noexcept = 0;
            virtual int32_t __stdcall CreateVector2KeyFrameAnimation(void**) noexcept = 0;
            virtual int32_t __stdcall CreateVector3KeyFrameAnimation(void**) noexcept = 0;
            virtual int32_t __stdcall CreateVector4KeyFrameAnimation(void**) noexcept = 0;
            virtual int32_t __stdcall GetCommitBatch(uint32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositor2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateAmbientLight(void**) noexcept = 0;
            virtual int32_t __stdcall CreateAnimationGroup(void**) noexcept = 0;
            virtual int32_t __stdcall CreateBackdropBrush(void**) noexcept = 0;
            virtual int32_t __stdcall CreateDistantLight(void**) noexcept = 0;
            virtual int32_t __stdcall CreateDropShadow(void**) noexcept = 0;
            virtual int32_t __stdcall CreateImplicitAnimationCollection(void**) noexcept = 0;
            virtual int32_t __stdcall CreateLayerVisual(void**) noexcept = 0;
            virtual int32_t __stdcall CreateMaskBrush(void**) noexcept = 0;
            virtual int32_t __stdcall CreateNineGridBrush(void**) noexcept = 0;
            virtual int32_t __stdcall CreatePointLight(void**) noexcept = 0;
            virtual int32_t __stdcall CreateSpotLight(void**) noexcept = 0;
            virtual int32_t __stdcall CreateStepEasingFunction(void**) noexcept = 0;
            virtual int32_t __stdcall CreateStepEasingFunctionWithStepCount(int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositor3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateHostBackdropBrush(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositor4>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateColorGradientStop(void**) noexcept = 0;
            virtual int32_t __stdcall CreateColorGradientStopWithOffsetAndColor(float, struct struct_Windows_UI_Color, void**) noexcept = 0;
            virtual int32_t __stdcall CreateLinearGradientBrush(void**) noexcept = 0;
            virtual int32_t __stdcall CreateSpringScalarAnimation(void**) noexcept = 0;
            virtual int32_t __stdcall CreateSpringVector2Animation(void**) noexcept = 0;
            virtual int32_t __stdcall CreateSpringVector3Animation(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositor5>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Comment(void**) noexcept = 0;
            virtual int32_t __stdcall put_Comment(void*) noexcept = 0;
            virtual int32_t __stdcall get_GlobalPlaybackRate(float*) noexcept = 0;
            virtual int32_t __stdcall put_GlobalPlaybackRate(float) noexcept = 0;
            virtual int32_t __stdcall CreateBounceScalarAnimation(void**) noexcept = 0;
            virtual int32_t __stdcall CreateBounceVector2Animation(void**) noexcept = 0;
            virtual int32_t __stdcall CreateBounceVector3Animation(void**) noexcept = 0;
            virtual int32_t __stdcall CreateContainerShape(void**) noexcept = 0;
            virtual int32_t __stdcall CreateEllipseGeometry(void**) noexcept = 0;
            virtual int32_t __stdcall CreateLineGeometry(void**) noexcept = 0;
            virtual int32_t __stdcall CreatePathGeometry(void**) noexcept = 0;
            virtual int32_t __stdcall CreatePathGeometryWithPath(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreatePathKeyFrameAnimation(void**) noexcept = 0;
            virtual int32_t __stdcall CreateRectangleGeometry(void**) noexcept = 0;
            virtual int32_t __stdcall CreateRoundedRectangleGeometry(void**) noexcept = 0;
            virtual int32_t __stdcall CreateShapeVisual(void**) noexcept = 0;
            virtual int32_t __stdcall CreateSpriteShape(void**) noexcept = 0;
            virtual int32_t __stdcall CreateSpriteShapeWithGeometry(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateViewBox(void**) noexcept = 0;
            virtual int32_t __stdcall RequestCommitAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositor6>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateGeometricClip(void**) noexcept = 0;
            virtual int32_t __stdcall CreateGeometricClipWithGeometry(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateRedirectVisual(void**) noexcept = 0;
            virtual int32_t __stdcall CreateRedirectVisualWithSourceVisual(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateBooleanKeyFrameAnimation(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositor7>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DispatcherQueue(void**) noexcept = 0;
            virtual int32_t __stdcall CreateAnimationPropertyInfo(void**) noexcept = 0;
            virtual int32_t __stdcall CreateRectangleClip(void**) noexcept = 0;
            virtual int32_t __stdcall CreateRectangleClipWithSides(float, float, float, float, void**) noexcept = 0;
            virtual int32_t __stdcall CreateRectangleClipWithSidesAndRadius(float, float, float, float, llm:OS::Foundation::Numerics::float2, llm:OS::Foundation::Numerics::float2, llm:OS::Foundation::Numerics::float2, llm:OS::Foundation::Numerics::float2, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositor8>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateAnimationController(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositorStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_MaxGlobalPlaybackRate(float*) noexcept = 0;
            virtual int32_t __stdcall get_MinGlobalPlaybackRate(float*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositorWithBlurredWallpaperBackdropBrush>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall TryCreateBlurredWallpaperBackdropBrush(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositorWithProjectedShadow>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateProjectedShadowCaster(void**) noexcept = 0;
            virtual int32_t __stdcall CreateProjectedShadow(void**) noexcept = 0;
            virtual int32_t __stdcall CreateProjectedShadowReceiver(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositorWithRadialGradient>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateRadialGradientBrush(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICompositorWithVisualSurface>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateVisualSurface(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IContainerVisual>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Children(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IContainerVisualFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ICubicBezierEasingFunction>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ControlPoint1(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall get_ControlPoint2(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IDelegatedInkTrailVisual>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall AddTrailPoints(uint32_t, struct struct_Windows_UI_Composition_InkTrailPoint*, uint32_t*) noexcept = 0;
            virtual int32_t __stdcall AddTrailPointsWithPrediction(uint32_t, struct struct_Windows_UI_Composition_InkTrailPoint*, uint32_t, struct struct_Windows_UI_Composition_InkTrailPoint*, uint32_t*) noexcept = 0;
            virtual int32_t __stdcall RemoveTrailPoints(uint32_t) noexcept = 0;
            virtual int32_t __stdcall StartNewTrail(struct struct_Windows_UI_Color) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IDelegatedInkTrailVisualStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateForSwapChain(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IDistantLight>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Color(struct struct_Windows_UI_Color*) noexcept = 0;
            virtual int32_t __stdcall put_Color(struct struct_Windows_UI_Color) noexcept = 0;
            virtual int32_t __stdcall get_CoordinateSpace(void**) noexcept = 0;
            virtual int32_t __stdcall put_CoordinateSpace(void*) noexcept = 0;
            virtual int32_t __stdcall get_Direction(llm:OS::Foundation::Numerics::float3*) noexcept = 0;
            virtual int32_t __stdcall put_Direction(llm:OS::Foundation::Numerics::float3) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IDistantLight2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Intensity(float*) noexcept = 0;
            virtual int32_t __stdcall put_Intensity(float) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IDropShadow>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_BlurRadius(float*) noexcept = 0;
            virtual int32_t __stdcall put_BlurRadius(float) noexcept = 0;
            virtual int32_t __stdcall get_Color(struct struct_Windows_UI_Color*) noexcept = 0;
            virtual int32_t __stdcall put_Color(struct struct_Windows_UI_Color) noexcept = 0;
            virtual int32_t __stdcall get_Mask(void**) noexcept = 0;
            virtual int32_t __stdcall put_Mask(void*) noexcept = 0;
            virtual int32_t __stdcall get_Offset(llm:OS::Foundation::Numerics::float3*) noexcept = 0;
            virtual int32_t __stdcall put_Offset(llm:OS::Foundation::Numerics::float3) noexcept = 0;
            virtual int32_t __stdcall get_Opacity(float*) noexcept = 0;
            virtual int32_t __stdcall put_Opacity(float) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IDropShadow2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SourcePolicy(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_SourcePolicy(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IElasticEasingFunction>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Mode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Oscillations(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Springiness(float*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IExponentialEasingFunction>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Mode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Exponent(float*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IExpressionAnimation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Expression(void**) noexcept = 0;
            virtual int32_t __stdcall put_Expression(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IImplicitAnimationCollection>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IInsetClip>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_BottomInset(float*) noexcept = 0;
            virtual int32_t __stdcall put_BottomInset(float) noexcept = 0;
            virtual int32_t __stdcall get_LeftInset(float*) noexcept = 0;
            virtual int32_t __stdcall put_LeftInset(float) noexcept = 0;
            virtual int32_t __stdcall get_RightInset(float*) noexcept = 0;
            virtual int32_t __stdcall put_RightInset(float) noexcept = 0;
            virtual int32_t __stdcall get_TopInset(float*) noexcept = 0;
            virtual int32_t __stdcall put_TopInset(float) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IKeyFrameAnimation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DelayTime(int64_t*) noexcept = 0;
            virtual int32_t __stdcall put_DelayTime(int64_t) noexcept = 0;
            virtual int32_t __stdcall get_Duration(int64_t*) noexcept = 0;
            virtual int32_t __stdcall put_Duration(int64_t) noexcept = 0;
            virtual int32_t __stdcall get_IterationBehavior(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_IterationBehavior(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_IterationCount(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_IterationCount(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_KeyFrameCount(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_StopBehavior(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_StopBehavior(int32_t) noexcept = 0;
            virtual int32_t __stdcall InsertExpressionKeyFrame(float, void*) noexcept = 0;
            virtual int32_t __stdcall InsertExpressionKeyFrameWithEasingFunction(float, void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IKeyFrameAnimation2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Direction(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Direction(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IKeyFrameAnimation3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DelayBehavior(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_DelayBehavior(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IKeyFrameAnimationFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ILayerVisual>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Effect(void**) noexcept = 0;
            virtual int32_t __stdcall put_Effect(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ILayerVisual2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Shadow(void**) noexcept = 0;
            virtual int32_t __stdcall put_Shadow(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ILinearEasingFunction>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::INaturalMotionAnimation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DelayBehavior(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_DelayBehavior(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_DelayTime(int64_t*) noexcept = 0;
            virtual int32_t __stdcall put_DelayTime(int64_t) noexcept = 0;
            virtual int32_t __stdcall get_StopBehavior(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_StopBehavior(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::INaturalMotionAnimationFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IPathKeyFrameAnimation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall InsertKeyFrame(float, void*) noexcept = 0;
            virtual int32_t __stdcall InsertKeyFrameWithEasingFunction(float, void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IPointLight>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Color(struct struct_Windows_UI_Color*) noexcept = 0;
            virtual int32_t __stdcall put_Color(struct struct_Windows_UI_Color) noexcept = 0;
            virtual int32_t __stdcall get_ConstantAttenuation(float*) noexcept = 0;
            virtual int32_t __stdcall put_ConstantAttenuation(float) noexcept = 0;
            virtual int32_t __stdcall get_CoordinateSpace(void**) noexcept = 0;
            virtual int32_t __stdcall put_CoordinateSpace(void*) noexcept = 0;
            virtual int32_t __stdcall get_LinearAttenuation(float*) noexcept = 0;
            virtual int32_t __stdcall put_LinearAttenuation(float) noexcept = 0;
            virtual int32_t __stdcall get_Offset(llm:OS::Foundation::Numerics::float3*) noexcept = 0;
            virtual int32_t __stdcall put_Offset(llm:OS::Foundation::Numerics::float3) noexcept = 0;
            virtual int32_t __stdcall get_QuadraticAttenuation(float*) noexcept = 0;
            virtual int32_t __stdcall put_QuadraticAttenuation(float) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IPointLight2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Intensity(float*) noexcept = 0;
            virtual int32_t __stdcall put_Intensity(float) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IPointLight3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_MinAttenuationCutoff(float*) noexcept = 0;
            virtual int32_t __stdcall put_MinAttenuationCutoff(float) noexcept = 0;
            virtual int32_t __stdcall get_MaxAttenuationCutoff(float*) noexcept = 0;
            virtual int32_t __stdcall put_MaxAttenuationCutoff(float) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IPowerEasingFunction>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Mode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Power(float*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IQuaternionKeyFrameAnimation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall InsertKeyFrame(float, llm:OS::Foundation::Numerics::quaternion) noexcept = 0;
            virtual int32_t __stdcall InsertKeyFrameWithEasingFunction(float, llm:OS::Foundation::Numerics::quaternion, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IRectangleClip>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Bottom(float*) noexcept = 0;
            virtual int32_t __stdcall put_Bottom(float) noexcept = 0;
            virtual int32_t __stdcall get_BottomLeftRadius(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_BottomLeftRadius(llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall get_BottomRightRadius(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_BottomRightRadius(llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall get_Left(float*) noexcept = 0;
            virtual int32_t __stdcall put_Left(float) noexcept = 0;
            virtual int32_t __stdcall get_Right(float*) noexcept = 0;
            virtual int32_t __stdcall put_Right(float) noexcept = 0;
            virtual int32_t __stdcall get_Top(float*) noexcept = 0;
            virtual int32_t __stdcall put_Top(float) noexcept = 0;
            virtual int32_t __stdcall get_TopLeftRadius(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_TopLeftRadius(llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall get_TopRightRadius(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_TopRightRadius(llm:OS::Foundation::Numerics::float2) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IRedirectVisual>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Source(void**) noexcept = 0;
            virtual int32_t __stdcall put_Source(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IRenderingDeviceReplacedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_GraphicsDevice(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IScalarKeyFrameAnimation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall InsertKeyFrame(float, float) noexcept = 0;
            virtual int32_t __stdcall InsertKeyFrameWithEasingFunction(float, float, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IScalarNaturalMotionAnimation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_FinalValue(void**) noexcept = 0;
            virtual int32_t __stdcall put_FinalValue(void*) noexcept = 0;
            virtual int32_t __stdcall get_InitialValue(void**) noexcept = 0;
            virtual int32_t __stdcall put_InitialValue(void*) noexcept = 0;
            virtual int32_t __stdcall get_InitialVelocity(float*) noexcept = 0;
            virtual int32_t __stdcall put_InitialVelocity(float) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IScalarNaturalMotionAnimationFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IShapeVisual>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Shapes(void**) noexcept = 0;
            virtual int32_t __stdcall get_ViewBox(void**) noexcept = 0;
            virtual int32_t __stdcall put_ViewBox(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ISineEasingFunction>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Mode(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ISpotLight>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ConstantAttenuation(float*) noexcept = 0;
            virtual int32_t __stdcall put_ConstantAttenuation(float) noexcept = 0;
            virtual int32_t __stdcall get_CoordinateSpace(void**) noexcept = 0;
            virtual int32_t __stdcall put_CoordinateSpace(void*) noexcept = 0;
            virtual int32_t __stdcall get_Direction(llm:OS::Foundation::Numerics::float3*) noexcept = 0;
            virtual int32_t __stdcall put_Direction(llm:OS::Foundation::Numerics::float3) noexcept = 0;
            virtual int32_t __stdcall get_InnerConeAngle(float*) noexcept = 0;
            virtual int32_t __stdcall put_InnerConeAngle(float) noexcept = 0;
            virtual int32_t __stdcall get_InnerConeAngleInDegrees(float*) noexcept = 0;
            virtual int32_t __stdcall put_InnerConeAngleInDegrees(float) noexcept = 0;
            virtual int32_t __stdcall get_InnerConeColor(struct struct_Windows_UI_Color*) noexcept = 0;
            virtual int32_t __stdcall put_InnerConeColor(struct struct_Windows_UI_Color) noexcept = 0;
            virtual int32_t __stdcall get_LinearAttenuation(float*) noexcept = 0;
            virtual int32_t __stdcall put_LinearAttenuation(float) noexcept = 0;
            virtual int32_t __stdcall get_Offset(llm:OS::Foundation::Numerics::float3*) noexcept = 0;
            virtual int32_t __stdcall put_Offset(llm:OS::Foundation::Numerics::float3) noexcept = 0;
            virtual int32_t __stdcall get_OuterConeAngle(float*) noexcept = 0;
            virtual int32_t __stdcall put_OuterConeAngle(float) noexcept = 0;
            virtual int32_t __stdcall get_OuterConeAngleInDegrees(float*) noexcept = 0;
            virtual int32_t __stdcall put_OuterConeAngleInDegrees(float) noexcept = 0;
            virtual int32_t __stdcall get_OuterConeColor(struct struct_Windows_UI_Color*) noexcept = 0;
            virtual int32_t __stdcall put_OuterConeColor(struct struct_Windows_UI_Color) noexcept = 0;
            virtual int32_t __stdcall get_QuadraticAttenuation(float*) noexcept = 0;
            virtual int32_t __stdcall put_QuadraticAttenuation(float) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ISpotLight2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_InnerConeIntensity(float*) noexcept = 0;
            virtual int32_t __stdcall put_InnerConeIntensity(float) noexcept = 0;
            virtual int32_t __stdcall get_OuterConeIntensity(float*) noexcept = 0;
            virtual int32_t __stdcall put_OuterConeIntensity(float) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ISpotLight3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_MinAttenuationCutoff(float*) noexcept = 0;
            virtual int32_t __stdcall put_MinAttenuationCutoff(float) noexcept = 0;
            virtual int32_t __stdcall get_MaxAttenuationCutoff(float*) noexcept = 0;
            virtual int32_t __stdcall put_MaxAttenuationCutoff(float) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ISpringScalarNaturalMotionAnimation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DampingRatio(float*) noexcept = 0;
            virtual int32_t __stdcall put_DampingRatio(float) noexcept = 0;
            virtual int32_t __stdcall get_Period(int64_t*) noexcept = 0;
            virtual int32_t __stdcall put_Period(int64_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ISpringVector2NaturalMotionAnimation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DampingRatio(float*) noexcept = 0;
            virtual int32_t __stdcall put_DampingRatio(float) noexcept = 0;
            virtual int32_t __stdcall get_Period(int64_t*) noexcept = 0;
            virtual int32_t __stdcall put_Period(int64_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ISpringVector3NaturalMotionAnimation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DampingRatio(float*) noexcept = 0;
            virtual int32_t __stdcall put_DampingRatio(float) noexcept = 0;
            virtual int32_t __stdcall get_Period(int64_t*) noexcept = 0;
            virtual int32_t __stdcall put_Period(int64_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ISpriteVisual>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Brush(void**) noexcept = 0;
            virtual int32_t __stdcall put_Brush(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::ISpriteVisual2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Shadow(void**) noexcept = 0;
            virtual int32_t __stdcall put_Shadow(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IStepEasingFunction>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_FinalStep(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_FinalStep(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_InitialStep(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_InitialStep(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_IsFinalStepSingleFrame(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsFinalStepSingleFrame(bool) noexcept = 0;
            virtual int32_t __stdcall get_IsInitialStepSingleFrame(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsInitialStepSingleFrame(bool) noexcept = 0;
            virtual int32_t __stdcall get_StepCount(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_StepCount(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IVector2KeyFrameAnimation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall InsertKeyFrame(float, llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall InsertKeyFrameWithEasingFunction(float, llm:OS::Foundation::Numerics::float2, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IVector2NaturalMotionAnimation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_FinalValue(void**) noexcept = 0;
            virtual int32_t __stdcall put_FinalValue(void*) noexcept = 0;
            virtual int32_t __stdcall get_InitialValue(void**) noexcept = 0;
            virtual int32_t __stdcall put_InitialValue(void*) noexcept = 0;
            virtual int32_t __stdcall get_InitialVelocity(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_InitialVelocity(llm:OS::Foundation::Numerics::float2) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IVector2NaturalMotionAnimationFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IVector3KeyFrameAnimation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall InsertKeyFrame(float, llm:OS::Foundation::Numerics::float3) noexcept = 0;
            virtual int32_t __stdcall InsertKeyFrameWithEasingFunction(float, llm:OS::Foundation::Numerics::float3, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IVector3NaturalMotionAnimation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_FinalValue(void**) noexcept = 0;
            virtual int32_t __stdcall put_FinalValue(void*) noexcept = 0;
            virtual int32_t __stdcall get_InitialValue(void**) noexcept = 0;
            virtual int32_t __stdcall put_InitialValue(void*) noexcept = 0;
            virtual int32_t __stdcall get_InitialVelocity(llm:OS::Foundation::Numerics::float3*) noexcept = 0;
            virtual int32_t __stdcall put_InitialVelocity(llm:OS::Foundation::Numerics::float3) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IVector3NaturalMotionAnimationFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IVector4KeyFrameAnimation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall InsertKeyFrame(float, llm:OS::Foundation::Numerics::float4) noexcept = 0;
            virtual int32_t __stdcall InsertKeyFrameWithEasingFunction(float, llm:OS::Foundation::Numerics::float4, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IVisual>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AnchorPoint(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_AnchorPoint(llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall get_BackfaceVisibility(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_BackfaceVisibility(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_BorderMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_BorderMode(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_CenterPoint(llm:OS::Foundation::Numerics::float3*) noexcept = 0;
            virtual int32_t __stdcall put_CenterPoint(llm:OS::Foundation::Numerics::float3) noexcept = 0;
            virtual int32_t __stdcall get_Clip(void**) noexcept = 0;
            virtual int32_t __stdcall put_Clip(void*) noexcept = 0;
            virtual int32_t __stdcall get_CompositeMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_CompositeMode(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_IsVisible(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsVisible(bool) noexcept = 0;
            virtual int32_t __stdcall get_Offset(llm:OS::Foundation::Numerics::float3*) noexcept = 0;
            virtual int32_t __stdcall put_Offset(llm:OS::Foundation::Numerics::float3) noexcept = 0;
            virtual int32_t __stdcall get_Opacity(float*) noexcept = 0;
            virtual int32_t __stdcall put_Opacity(float) noexcept = 0;
            virtual int32_t __stdcall get_Orientation(llm:OS::Foundation::Numerics::quaternion*) noexcept = 0;
            virtual int32_t __stdcall put_Orientation(llm:OS::Foundation::Numerics::quaternion) noexcept = 0;
            virtual int32_t __stdcall get_Parent(void**) noexcept = 0;
            virtual int32_t __stdcall get_RotationAngle(float*) noexcept = 0;
            virtual int32_t __stdcall put_RotationAngle(float) noexcept = 0;
            virtual int32_t __stdcall get_RotationAngleInDegrees(float*) noexcept = 0;
            virtual int32_t __stdcall put_RotationAngleInDegrees(float) noexcept = 0;
            virtual int32_t __stdcall get_RotationAxis(llm:OS::Foundation::Numerics::float3*) noexcept = 0;
            virtual int32_t __stdcall put_RotationAxis(llm:OS::Foundation::Numerics::float3) noexcept = 0;
            virtual int32_t __stdcall get_Scale(llm:OS::Foundation::Numerics::float3*) noexcept = 0;
            virtual int32_t __stdcall put_Scale(llm:OS::Foundation::Numerics::float3) noexcept = 0;
            virtual int32_t __stdcall get_Size(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_Size(llm:OS::Foundation::Numerics::float2) noexcept = 0;
            virtual int32_t __stdcall get_TransformMatrix(llm:OS::Foundation::Numerics::float4x4*) noexcept = 0;
            virtual int32_t __stdcall put_TransformMatrix(llm:OS::Foundation::Numerics::float4x4) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IVisual2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ParentForTransform(void**) noexcept = 0;
            virtual int32_t __stdcall put_ParentForTransform(void*) noexcept = 0;
            virtual int32_t __stdcall get_RelativeOffsetAdjustment(llm:OS::Foundation::Numerics::float3*) noexcept = 0;
            virtual int32_t __stdcall put_RelativeOffsetAdjustment(llm:OS::Foundation::Numerics::float3) noexcept = 0;
            virtual int32_t __stdcall get_RelativeSizeAdjustment(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall put_RelativeSizeAdjustment(llm:OS::Foundation::Numerics::float2) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IVisual3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsHitTestVisible(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsHitTestVisible(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IVisual4>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsPixelSnappingEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsPixelSnappingEnabled(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IVisualCollection>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Count(int32_t*) noexcept = 0;
            virtual int32_t __stdcall InsertAbove(void*, void*) noexcept = 0;
            virtual int32_t __stdcall InsertAtBottom(void*) noexcept = 0;
            virtual int32_t __stdcall InsertAtTop(void*) noexcept = 0;
            virtual int32_t __stdcall InsertBelow(void*, void*) noexcept = 0;
            virtual int32_t __stdcall Remove(void*) noexcept = 0;
            virtual int32_t __stdcall RemoveAll() noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IVisualElement>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IVisualElement2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetVisualInternal(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IVisualFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Composition::IVisualUnorderedCollection>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Count(int32_t*) noexcept = 0;
            virtual int32_t __stdcall Add(void*) noexcept = 0;
            virtual int32_t __stdcall Remove(void*) noexcept = 0;
            virtual int32_t __stdcall RemoveAll() noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IAmbientLight
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Color) Color() const;
        LLM_IMPL_AUTO(void) Color(llm:OS::UI::Color const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IAmbientLight>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IAmbientLight<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IAmbientLight2
    {
        [[nodiscard]] LLM_IMPL_AUTO(float) Intensity() const;
        LLM_IMPL_AUTO(void) Intensity(float value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IAmbientLight2>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IAmbientLight2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IAnimationController
    {
        [[nodiscard]] LLM_IMPL_AUTO(float) PlaybackRate() const;
        LLM_IMPL_AUTO(void) PlaybackRate(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) Progress() const;
        LLM_IMPL_AUTO(void) Progress(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::AnimationControllerProgressBehavior) ProgressBehavior() const;
        LLM_IMPL_AUTO(void) ProgressBehavior(llm:OS::UI::Composition::AnimationControllerProgressBehavior const& value) const;
        LLM_IMPL_AUTO(void) Pause() const;
        LLM_IMPL_AUTO(void) Resume() const;
    };
    template <> struct consume<llm:OS::UI::Composition::IAnimationController>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IAnimationController<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IAnimationControllerStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(float) MaxPlaybackRate() const;
        [[nodiscard]] LLM_IMPL_AUTO(float) MinPlaybackRate() const;
    };
    template <> struct consume<llm:OS::UI::Composition::IAnimationControllerStatics>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IAnimationControllerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IAnimationObject
    {
        LLM_IMPL_AUTO(void) PopulatePropertyInfo(param::hstring const& propertyName, llm:OS::UI::Composition::AnimationPropertyInfo const& propertyInfo) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IAnimationObject>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IAnimationObject<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IAnimationPropertyInfo
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::AnimationPropertyAccessMode) AccessMode() const;
        LLM_IMPL_AUTO(void) AccessMode(llm:OS::UI::Composition::AnimationPropertyAccessMode const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IAnimationPropertyInfo>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IAnimationPropertyInfo<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IAnimationPropertyInfo2
    {
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionObject) GetResolvedCompositionObject() const;
        LLM_IMPL_AUTO(hstring) GetResolvedCompositionObjectProperty() const;
    };
    template <> struct consume<llm:OS::UI::Composition::IAnimationPropertyInfo2>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IAnimationPropertyInfo2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IBackEasingFunction
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionEasingFunctionMode) Mode() const;
        [[nodiscard]] LLM_IMPL_AUTO(float) Amplitude() const;
    };
    template <> struct consume<llm:OS::UI::Composition::IBackEasingFunction>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IBackEasingFunction<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IBooleanKeyFrameAnimation
    {
        LLM_IMPL_AUTO(void) InsertKeyFrame(float normalizedProgressKey, bool value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IBooleanKeyFrameAnimation>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IBooleanKeyFrameAnimation<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IBounceEasingFunction
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionEasingFunctionMode) Mode() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) Bounces() const;
        [[nodiscard]] LLM_IMPL_AUTO(float) Bounciness() const;
    };
    template <> struct consume<llm:OS::UI::Composition::IBounceEasingFunction>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IBounceEasingFunction<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IBounceScalarNaturalMotionAnimation
    {
        [[nodiscard]] LLM_IMPL_AUTO(float) Acceleration() const;
        LLM_IMPL_AUTO(void) Acceleration(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) Restitution() const;
        LLM_IMPL_AUTO(void) Restitution(float value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IBounceScalarNaturalMotionAnimation>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IBounceScalarNaturalMotionAnimation<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IBounceVector2NaturalMotionAnimation
    {
        [[nodiscard]] LLM_IMPL_AUTO(float) Acceleration() const;
        LLM_IMPL_AUTO(void) Acceleration(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) Restitution() const;
        LLM_IMPL_AUTO(void) Restitution(float value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IBounceVector2NaturalMotionAnimation>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IBounceVector2NaturalMotionAnimation<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IBounceVector3NaturalMotionAnimation
    {
        [[nodiscard]] LLM_IMPL_AUTO(float) Acceleration() const;
        LLM_IMPL_AUTO(void) Acceleration(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) Restitution() const;
        LLM_IMPL_AUTO(void) Restitution(float value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IBounceVector3NaturalMotionAnimation>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IBounceVector3NaturalMotionAnimation<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICircleEasingFunction
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionEasingFunctionMode) Mode() const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICircleEasingFunction>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICircleEasingFunction<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IColorKeyFrameAnimation
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionColorSpace) InterpolationColorSpace() const;
        LLM_IMPL_AUTO(void) InterpolationColorSpace(llm:OS::UI::Composition::CompositionColorSpace const& value) const;
        LLM_IMPL_AUTO(void) InsertKeyFrame(float normalizedProgressKey, llm:OS::UI::Color const& value) const;
        LLM_IMPL_AUTO(void) InsertKeyFrame(float normalizedProgressKey, llm:OS::UI::Color const& value, llm:OS::UI::Composition::CompositionEasingFunction const& easingFunction) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IColorKeyFrameAnimation>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IColorKeyFrameAnimation<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionAnimation
    {
        LLM_IMPL_AUTO(void) ClearAllParameters() const;
        LLM_IMPL_AUTO(void) ClearParameter(param::hstring const& key) const;
        LLM_IMPL_AUTO(void) SetColorParameter(param::hstring const& key, llm:OS::UI::Color const& value) const;
        LLM_IMPL_AUTO(void) SetMatrix3x2Parameter(param::hstring const& key, llm:OS::Foundation::Numerics::float3x2 const& value) const;
        LLM_IMPL_AUTO(void) SetMatrix4x4Parameter(param::hstring const& key, llm:OS::Foundation::Numerics::float4x4 const& value) const;
        LLM_IMPL_AUTO(void) SetQuaternionParameter(param::hstring const& key, llm:OS::Foundation::Numerics::quaternion const& value) const;
        LLM_IMPL_AUTO(void) SetReferenceParameter(param::hstring const& key, llm:OS::UI::Composition::CompositionObject const& compositionObject) const;
        LLM_IMPL_AUTO(void) SetScalarParameter(param::hstring const& key, float value) const;
        LLM_IMPL_AUTO(void) SetVector2Parameter(param::hstring const& key, llm:OS::Foundation::Numerics::float2 const& value) const;
        LLM_IMPL_AUTO(void) SetVector3Parameter(param::hstring const& key, llm:OS::Foundation::Numerics::float3 const& value) const;
        LLM_IMPL_AUTO(void) SetVector4Parameter(param::hstring const& key, llm:OS::Foundation::Numerics::float4 const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionAnimation>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionAnimation<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionAnimation2
    {
        LLM_IMPL_AUTO(void) SetBooleanParameter(param::hstring const& key, bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Target() const;
        LLM_IMPL_AUTO(void) Target(param::hstring const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionAnimation2>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionAnimation2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionAnimation3
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::InitialValueExpressionCollection) InitialValueExpressions() const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionAnimation3>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionAnimation3<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionAnimation4
    {
        LLM_IMPL_AUTO(void) SetExpressionReferenceParameter(param::hstring const& parameterName, llm:OS::UI::Composition::IAnimationObject const& source) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionAnimation4>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionAnimation4<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionAnimationBase
    {
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionAnimationBase>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionAnimationBase<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionAnimationFactory
    {
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionAnimationFactory>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionAnimationFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionAnimationGroup
    {
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) Count() const;
        LLM_IMPL_AUTO(void) Add(llm:OS::UI::Composition::CompositionAnimation const& value) const;
        LLM_IMPL_AUTO(void) Remove(llm:OS::UI::Composition::CompositionAnimation const& value) const;
        LLM_IMPL_AUTO(void) RemoveAll() const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionAnimationGroup>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionAnimationGroup<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionBackdropBrush
    {
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionBackdropBrush>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionBackdropBrush<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionBatchCompletedEventArgs
    {
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionBatchCompletedEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionBatchCompletedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionBrush
    {
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionBrush>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionBrush<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionBrushFactory
    {
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionBrushFactory>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionBrushFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionCapabilities
    {
        LLM_IMPL_AUTO(bool) AreEffectsSupported() const;
        LLM_IMPL_AUTO(bool) AreEffectsFast() const;
        LLM_IMPL_AUTO(llm::event_token) Changed(llm:OS::Foundation::TypedEventHandler<llm:OS::UI::Composition::CompositionCapabilities, llm:OS::Foundation::IInspectable> const& handler) const;
        using Changed_revoker = impl::event_revoker<llm:OS::UI::Composition::ICompositionCapabilities, &impl::abi_t<llm:OS::UI::Composition::ICompositionCapabilities>::remove_Changed>;
        [[nodiscard]] Changed_revoker Changed(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::UI::Composition::CompositionCapabilities, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) Changed(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionCapabilities>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionCapabilities<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionCapabilitiesStatics
    {
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionCapabilities) GetForCurrentView() const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionCapabilitiesStatics>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionCapabilitiesStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionClip
    {
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionClip>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionClip<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionClip2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) AnchorPoint() const;
        LLM_IMPL_AUTO(void) AnchorPoint(llm:OS::Foundation::Numerics::float2 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) CenterPoint() const;
        LLM_IMPL_AUTO(void) CenterPoint(llm:OS::Foundation::Numerics::float2 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) Offset() const;
        LLM_IMPL_AUTO(void) Offset(llm:OS::Foundation::Numerics::float2 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) RotationAngle() const;
        LLM_IMPL_AUTO(void) RotationAngle(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) RotationAngleInDegrees() const;
        LLM_IMPL_AUTO(void) RotationAngleInDegrees(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) Scale() const;
        LLM_IMPL_AUTO(void) Scale(llm:OS::Foundation::Numerics::float2 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float3x2) TransformMatrix() const;
        LLM_IMPL_AUTO(void) TransformMatrix(llm:OS::Foundation::Numerics::float3x2 const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionClip2>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionClip2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionClipFactory
    {
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionClipFactory>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionClipFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionColorBrush
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Color) Color() const;
        LLM_IMPL_AUTO(void) Color(llm:OS::UI::Color const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionColorBrush>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionColorBrush<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionColorGradientStop
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Color) Color() const;
        LLM_IMPL_AUTO(void) Color(llm:OS::UI::Color const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) Offset() const;
        LLM_IMPL_AUTO(void) Offset(float value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionColorGradientStop>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionColorGradientStop<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionColorGradientStopCollection
    {
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionColorGradientStopCollection>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionColorGradientStopCollection<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionCommitBatch
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsActive() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsEnded() const;
        LLM_IMPL_AUTO(llm::event_token) Completed(llm:OS::Foundation::TypedEventHandler<llm:OS::Foundation::IInspectable, llm:OS::UI::Composition::CompositionBatchCompletedEventArgs> const& handler) const;
        using Completed_revoker = impl::event_revoker<llm:OS::UI::Composition::ICompositionCommitBatch, &impl::abi_t<llm:OS::UI::Composition::ICompositionCommitBatch>::remove_Completed>;
        [[nodiscard]] Completed_revoker Completed(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Foundation::IInspectable, llm:OS::UI::Composition::CompositionBatchCompletedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) Completed(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionCommitBatch>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionCommitBatch<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionContainerShape
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionShapeCollection) Shapes() const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionContainerShape>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionContainerShape<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionDrawingSurface
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::DirectX::DirectXAlphaMode) AlphaMode() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::DirectX::DirectXPixelFormat) PixelFormat() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Size) Size() const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionDrawingSurface>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionDrawingSurface<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionDrawingSurface2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::SizeInt32) SizeInt32() const;
        LLM_IMPL_AUTO(void) Resize(llm:OS::Graphics::SizeInt32 const& sizePixels) const;
        LLM_IMPL_AUTO(void) Scroll(llm:OS::Graphics::PointInt32 const& offset) const;
        LLM_IMPL_AUTO(void) Scroll(llm:OS::Graphics::PointInt32 const& offset, llm:OS::Graphics::RectInt32 const& scrollRect) const;
        LLM_IMPL_AUTO(void) ScrollWithClip(llm:OS::Graphics::PointInt32 const& offset, llm:OS::Graphics::RectInt32 const& clipRect) const;
        LLM_IMPL_AUTO(void) ScrollWithClip(llm:OS::Graphics::PointInt32 const& offset, llm:OS::Graphics::RectInt32 const& clipRect, llm:OS::Graphics::RectInt32 const& scrollRect) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionDrawingSurface2>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionDrawingSurface2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionDrawingSurfaceFactory
    {
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionDrawingSurfaceFactory>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionDrawingSurfaceFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionEasingFunction
    {
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionEasingFunction>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionEasingFunction<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionEasingFunctionFactory
    {
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionEasingFunctionFactory>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionEasingFunctionFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionEasingFunctionStatics
    {
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CubicBezierEasingFunction) CreateCubicBezierEasingFunction(llm:OS::UI::Composition::Compositor const& owner, llm:OS::Foundation::Numerics::float2 const& controlPoint1, llm:OS::Foundation::Numerics::float2 const& controlPoint2) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::LinearEasingFunction) CreateLinearEasingFunction(llm:OS::UI::Composition::Compositor const& owner) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::StepEasingFunction) CreateStepEasingFunction(llm:OS::UI::Composition::Compositor const& owner) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::StepEasingFunction) CreateStepEasingFunction(llm:OS::UI::Composition::Compositor const& owner, int32_t stepCount) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::BackEasingFunction) CreateBackEasingFunction(llm:OS::UI::Composition::Compositor const& owner, llm:OS::UI::Composition::CompositionEasingFunctionMode const& mode, float amplitude) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::BounceEasingFunction) CreateBounceEasingFunction(llm:OS::UI::Composition::Compositor const& owner, llm:OS::UI::Composition::CompositionEasingFunctionMode const& mode, int32_t bounces, float bounciness) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CircleEasingFunction) CreateCircleEasingFunction(llm:OS::UI::Composition::Compositor const& owner, llm:OS::UI::Composition::CompositionEasingFunctionMode const& mode) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::ElasticEasingFunction) CreateElasticEasingFunction(llm:OS::UI::Composition::Compositor const& owner, llm:OS::UI::Composition::CompositionEasingFunctionMode const& mode, int32_t oscillations, float springiness) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::ExponentialEasingFunction) CreateExponentialEasingFunction(llm:OS::UI::Composition::Compositor const& owner, llm:OS::UI::Composition::CompositionEasingFunctionMode const& mode, float exponent) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::PowerEasingFunction) CreatePowerEasingFunction(llm:OS::UI::Composition::Compositor const& owner, llm:OS::UI::Composition::CompositionEasingFunctionMode const& mode, float power) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::SineEasingFunction) CreateSineEasingFunction(llm:OS::UI::Composition::Compositor const& owner, llm:OS::UI::Composition::CompositionEasingFunctionMode const& mode) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionEasingFunctionStatics>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionEasingFunctionStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionEffectBrush
    {
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionBrush) GetSourceParameter(param::hstring const& name) const;
        LLM_IMPL_AUTO(void) SetSourceParameter(param::hstring const& name, llm:OS::UI::Composition::CompositionBrush const& source) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionEffectBrush>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionEffectBrush<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionEffectFactory
    {
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionEffectBrush) CreateBrush() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) ExtendedError() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionEffectFactoryLoadStatus) LoadStatus() const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionEffectFactory>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionEffectFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionEffectSourceParameter
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionEffectSourceParameter>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionEffectSourceParameter<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionEffectSourceParameterFactory
    {
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionEffectSourceParameter) Create(param::hstring const& name) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionEffectSourceParameterFactory>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionEffectSourceParameterFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionEllipseGeometry
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) Center() const;
        LLM_IMPL_AUTO(void) Center(llm:OS::Foundation::Numerics::float2 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) Radius() const;
        LLM_IMPL_AUTO(void) Radius(llm:OS::Foundation::Numerics::float2 const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionEllipseGeometry>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionEllipseGeometry<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionGeometricClip
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionGeometry) Geometry() const;
        LLM_IMPL_AUTO(void) Geometry(llm:OS::UI::Composition::CompositionGeometry const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionViewBox) ViewBox() const;
        LLM_IMPL_AUTO(void) ViewBox(llm:OS::UI::Composition::CompositionViewBox const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionGeometricClip>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionGeometricClip<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionGeometry
    {
        [[nodiscard]] LLM_IMPL_AUTO(float) TrimEnd() const;
        LLM_IMPL_AUTO(void) TrimEnd(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) TrimOffset() const;
        LLM_IMPL_AUTO(void) TrimOffset(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) TrimStart() const;
        LLM_IMPL_AUTO(void) TrimStart(float value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionGeometry>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionGeometry<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionGeometryFactory
    {
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionGeometryFactory>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionGeometryFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionGradientBrush
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) AnchorPoint() const;
        LLM_IMPL_AUTO(void) AnchorPoint(llm:OS::Foundation::Numerics::float2 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) CenterPoint() const;
        LLM_IMPL_AUTO(void) CenterPoint(llm:OS::Foundation::Numerics::float2 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionColorGradientStopCollection) ColorStops() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionGradientExtendMode) ExtendMode() const;
        LLM_IMPL_AUTO(void) ExtendMode(llm:OS::UI::Composition::CompositionGradientExtendMode const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionColorSpace) InterpolationSpace() const;
        LLM_IMPL_AUTO(void) InterpolationSpace(llm:OS::UI::Composition::CompositionColorSpace const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) Offset() const;
        LLM_IMPL_AUTO(void) Offset(llm:OS::Foundation::Numerics::float2 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) RotationAngle() const;
        LLM_IMPL_AUTO(void) RotationAngle(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) RotationAngleInDegrees() const;
        LLM_IMPL_AUTO(void) RotationAngleInDegrees(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) Scale() const;
        LLM_IMPL_AUTO(void) Scale(llm:OS::Foundation::Numerics::float2 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float3x2) TransformMatrix() const;
        LLM_IMPL_AUTO(void) TransformMatrix(llm:OS::Foundation::Numerics::float3x2 const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionGradientBrush>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionGradientBrush<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionGradientBrush2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionMappingMode) MappingMode() const;
        LLM_IMPL_AUTO(void) MappingMode(llm:OS::UI::Composition::CompositionMappingMode const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionGradientBrush2>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionGradientBrush2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionGradientBrushFactory
    {
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionGradientBrushFactory>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionGradientBrushFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionGraphicsDevice
    {
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionDrawingSurface) CreateDrawingSurface(llm:OS::Foundation::Size const& sizePixels, llm:OS::Graphics::DirectX::DirectXPixelFormat const& pixelFormat, llm:OS::Graphics::DirectX::DirectXAlphaMode const& alphaMode) const;
        LLM_IMPL_AUTO(llm::event_token) RenderingDeviceReplaced(llm:OS::Foundation::TypedEventHandler<llm:OS::UI::Composition::CompositionGraphicsDevice, llm:OS::UI::Composition::RenderingDeviceReplacedEventArgs> const& handler) const;
        using RenderingDeviceReplaced_revoker = impl::event_revoker<llm:OS::UI::Composition::ICompositionGraphicsDevice, &impl::abi_t<llm:OS::UI::Composition::ICompositionGraphicsDevice>::remove_RenderingDeviceReplaced>;
        [[nodiscard]] RenderingDeviceReplaced_revoker RenderingDeviceReplaced(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::UI::Composition::CompositionGraphicsDevice, llm:OS::UI::Composition::RenderingDeviceReplacedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) RenderingDeviceReplaced(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionGraphicsDevice>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionGraphicsDevice<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionGraphicsDevice2
    {
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionDrawingSurface) CreateDrawingSurface2(llm:OS::Graphics::SizeInt32 const& sizePixels, llm:OS::Graphics::DirectX::DirectXPixelFormat const& pixelFormat, llm:OS::Graphics::DirectX::DirectXAlphaMode const& alphaMode) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionVirtualDrawingSurface) CreateVirtualDrawingSurface(llm:OS::Graphics::SizeInt32 const& sizePixels, llm:OS::Graphics::DirectX::DirectXPixelFormat const& pixelFormat, llm:OS::Graphics::DirectX::DirectXAlphaMode const& alphaMode) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionGraphicsDevice2>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionGraphicsDevice2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionGraphicsDevice3
    {
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionMipmapSurface) CreateMipmapSurface(llm:OS::Graphics::SizeInt32 const& sizePixels, llm:OS::Graphics::DirectX::DirectXPixelFormat const& pixelFormat, llm:OS::Graphics::DirectX::DirectXAlphaMode const& alphaMode) const;
        LLM_IMPL_AUTO(void) Trim() const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionGraphicsDevice3>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionGraphicsDevice3<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionGraphicsDevice4
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::UI::Composition::ICompositionSurface>) CaptureAsync(llm:OS::UI::Composition::Visual const& captureVisual, llm:OS::Graphics::SizeInt32 const& size, llm:OS::Graphics::DirectX::DirectXPixelFormat const& pixelFormat, llm:OS::Graphics::DirectX::DirectXAlphaMode const& alphaMode, float sdrBoost) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionGraphicsDevice4>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionGraphicsDevice4<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionLight
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::VisualUnorderedCollection) Targets() const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionLight>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionLight<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionLight2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::VisualUnorderedCollection) ExclusionsFromTargets() const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionLight2>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionLight2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionLight3
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsEnabled() const;
        LLM_IMPL_AUTO(void) IsEnabled(bool value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionLight3>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionLight3<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionLightFactory
    {
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionLightFactory>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionLightFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionLineGeometry
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) Start() const;
        LLM_IMPL_AUTO(void) Start(llm:OS::Foundation::Numerics::float2 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) End() const;
        LLM_IMPL_AUTO(void) End(llm:OS::Foundation::Numerics::float2 const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionLineGeometry>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionLineGeometry<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionLinearGradientBrush
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) EndPoint() const;
        LLM_IMPL_AUTO(void) EndPoint(llm:OS::Foundation::Numerics::float2 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) StartPoint() const;
        LLM_IMPL_AUTO(void) StartPoint(llm:OS::Foundation::Numerics::float2 const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionLinearGradientBrush>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionLinearGradientBrush<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionMaskBrush
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionBrush) Mask() const;
        LLM_IMPL_AUTO(void) Mask(llm:OS::UI::Composition::CompositionBrush const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionBrush) Source() const;
        LLM_IMPL_AUTO(void) Source(llm:OS::UI::Composition::CompositionBrush const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionMaskBrush>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionMaskBrush<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionMipmapSurface
    {
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) LevelCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::DirectX::DirectXAlphaMode) AlphaMode() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::DirectX::DirectXPixelFormat) PixelFormat() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::SizeInt32) SizeInt32() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionDrawingSurface) GetDrawingSurfaceForLevel(uint32_t level) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionMipmapSurface>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionMipmapSurface<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionNineGridBrush
    {
        [[nodiscard]] LLM_IMPL_AUTO(float) BottomInset() const;
        LLM_IMPL_AUTO(void) BottomInset(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) BottomInsetScale() const;
        LLM_IMPL_AUTO(void) BottomInsetScale(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsCenterHollow() const;
        LLM_IMPL_AUTO(void) IsCenterHollow(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) LeftInset() const;
        LLM_IMPL_AUTO(void) LeftInset(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) LeftInsetScale() const;
        LLM_IMPL_AUTO(void) LeftInsetScale(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) RightInset() const;
        LLM_IMPL_AUTO(void) RightInset(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) RightInsetScale() const;
        LLM_IMPL_AUTO(void) RightInsetScale(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionBrush) Source() const;
        LLM_IMPL_AUTO(void) Source(llm:OS::UI::Composition::CompositionBrush const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) TopInset() const;
        LLM_IMPL_AUTO(void) TopInset(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) TopInsetScale() const;
        LLM_IMPL_AUTO(void) TopInsetScale(float value) const;
        LLM_IMPL_AUTO(void) SetInsets(float inset) const;
        LLM_IMPL_AUTO(void) SetInsets(float left, float top, float right, float bottom) const;
        LLM_IMPL_AUTO(void) SetInsetScales(float scale) const;
        LLM_IMPL_AUTO(void) SetInsetScales(float left, float top, float right, float bottom) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionNineGridBrush>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionNineGridBrush<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionObject
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::Compositor) Compositor() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Core::CoreDispatcher) Dispatcher() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionPropertySet) Properties() const;
        LLM_IMPL_AUTO(void) StartAnimation(param::hstring const& propertyName, llm:OS::UI::Composition::CompositionAnimation const& animation) const;
        LLM_IMPL_AUTO(void) StopAnimation(param::hstring const& propertyName) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionObject>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionObject<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionObject2
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Comment() const;
        LLM_IMPL_AUTO(void) Comment(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::ImplicitAnimationCollection) ImplicitAnimations() const;
        LLM_IMPL_AUTO(void) ImplicitAnimations(llm:OS::UI::Composition::ImplicitAnimationCollection const& value) const;
        LLM_IMPL_AUTO(void) StartAnimationGroup(llm:OS::UI::Composition::ICompositionAnimationBase const& value) const;
        LLM_IMPL_AUTO(void) StopAnimationGroup(llm:OS::UI::Composition::ICompositionAnimationBase const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionObject2>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionObject2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionObject3
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::DispatcherQueue) DispatcherQueue() const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionObject3>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionObject3<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionObject4
    {
        LLM_IMPL_AUTO(llm:OS::UI::Composition::AnimationController) TryGetAnimationController(param::hstring const& propertyName) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionObject4>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionObject4<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionObject5
    {
        LLM_IMPL_AUTO(void) StartAnimation(param::hstring const& propertyName, llm:OS::UI::Composition::CompositionAnimation const& animation, llm:OS::UI::Composition::AnimationController const& animationController) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionObject5>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionObject5<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionObjectFactory
    {
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionObjectFactory>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionObjectFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionObjectStatics
    {
        LLM_IMPL_AUTO(void) StartAnimationWithIAnimationObject(llm:OS::UI::Composition::IAnimationObject const& target, param::hstring const& propertyName, llm:OS::UI::Composition::CompositionAnimation const& animation) const;
        LLM_IMPL_AUTO(void) StartAnimationGroupWithIAnimationObject(llm:OS::UI::Composition::IAnimationObject const& target, llm:OS::UI::Composition::ICompositionAnimationBase const& animation) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionObjectStatics>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionObjectStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionPath
    {
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionPath>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionPath<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionPathFactory
    {
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionPath) Create(llm:OS::Graphics::IGeometrySource2D const& source) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionPathFactory>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionPathFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionPathGeometry
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionPath) Path() const;
        LLM_IMPL_AUTO(void) Path(llm:OS::UI::Composition::CompositionPath const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionPathGeometry>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionPathGeometry<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionProjectedShadow
    {
        [[nodiscard]] LLM_IMPL_AUTO(float) BlurRadiusMultiplier() const;
        LLM_IMPL_AUTO(void) BlurRadiusMultiplier(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionProjectedShadowCasterCollection) Casters() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionLight) LightSource() const;
        LLM_IMPL_AUTO(void) LightSource(llm:OS::UI::Composition::CompositionLight const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) MaxBlurRadius() const;
        LLM_IMPL_AUTO(void) MaxBlurRadius(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) MinBlurRadius() const;
        LLM_IMPL_AUTO(void) MinBlurRadius(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionProjectedShadowReceiverUnorderedCollection) Receivers() const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionProjectedShadow>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionProjectedShadow<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionProjectedShadowCaster
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionBrush) Brush() const;
        LLM_IMPL_AUTO(void) Brush(llm:OS::UI::Composition::CompositionBrush const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::Visual) CastingVisual() const;
        LLM_IMPL_AUTO(void) CastingVisual(llm:OS::UI::Composition::Visual const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionProjectedShadowCaster>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionProjectedShadowCaster<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionProjectedShadowCasterCollection
    {
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) Count() const;
        LLM_IMPL_AUTO(void) InsertAbove(llm:OS::UI::Composition::CompositionProjectedShadowCaster const& newCaster, llm:OS::UI::Composition::CompositionProjectedShadowCaster const& reference) const;
        LLM_IMPL_AUTO(void) InsertAtBottom(llm:OS::UI::Composition::CompositionProjectedShadowCaster const& newCaster) const;
        LLM_IMPL_AUTO(void) InsertAtTop(llm:OS::UI::Composition::CompositionProjectedShadowCaster const& newCaster) const;
        LLM_IMPL_AUTO(void) InsertBelow(llm:OS::UI::Composition::CompositionProjectedShadowCaster const& newCaster, llm:OS::UI::Composition::CompositionProjectedShadowCaster const& reference) const;
        LLM_IMPL_AUTO(void) Remove(llm:OS::UI::Composition::CompositionProjectedShadowCaster const& caster) const;
        LLM_IMPL_AUTO(void) RemoveAll() const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionProjectedShadowCasterCollection>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionProjectedShadowCasterCollection<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionProjectedShadowCasterCollectionStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) MaxRespectedCasters() const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionProjectedShadowCasterCollectionStatics>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionProjectedShadowCasterCollectionStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionProjectedShadowReceiver
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::Visual) ReceivingVisual() const;
        LLM_IMPL_AUTO(void) ReceivingVisual(llm:OS::UI::Composition::Visual const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionProjectedShadowReceiver>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionProjectedShadowReceiver<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionProjectedShadowReceiverUnorderedCollection
    {
        LLM_IMPL_AUTO(void) Add(llm:OS::UI::Composition::CompositionProjectedShadowReceiver const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) Count() const;
        LLM_IMPL_AUTO(void) Remove(llm:OS::UI::Composition::CompositionProjectedShadowReceiver const& value) const;
        LLM_IMPL_AUTO(void) RemoveAll() const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionProjectedShadowReceiverUnorderedCollection>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionProjectedShadowReceiverUnorderedCollection<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionPropertySet
    {
        LLM_IMPL_AUTO(void) InsertColor(param::hstring const& propertyName, llm:OS::UI::Color const& value) const;
        LLM_IMPL_AUTO(void) InsertMatrix3x2(param::hstring const& propertyName, llm:OS::Foundation::Numerics::float3x2 const& value) const;
        LLM_IMPL_AUTO(void) InsertMatrix4x4(param::hstring const& propertyName, llm:OS::Foundation::Numerics::float4x4 const& value) const;
        LLM_IMPL_AUTO(void) InsertQuaternion(param::hstring const& propertyName, llm:OS::Foundation::Numerics::quaternion const& value) const;
        LLM_IMPL_AUTO(void) InsertScalar(param::hstring const& propertyName, float value) const;
        LLM_IMPL_AUTO(void) InsertVector2(param::hstring const& propertyName, llm:OS::Foundation::Numerics::float2 const& value) const;
        LLM_IMPL_AUTO(void) InsertVector3(param::hstring const& propertyName, llm:OS::Foundation::Numerics::float3 const& value) const;
        LLM_IMPL_AUTO(void) InsertVector4(param::hstring const& propertyName, llm:OS::Foundation::Numerics::float4 const& value) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionGetValueStatus) TryGetColor(param::hstring const& propertyName, llm:OS::UI::Color& value) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionGetValueStatus) TryGetMatrix3x2(param::hstring const& propertyName, llm:OS::Foundation::Numerics::float3x2& value) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionGetValueStatus) TryGetMatrix4x4(param::hstring const& propertyName, llm:OS::Foundation::Numerics::float4x4& value) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionGetValueStatus) TryGetQuaternion(param::hstring const& propertyName, llm:OS::Foundation::Numerics::quaternion& value) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionGetValueStatus) TryGetScalar(param::hstring const& propertyName, float& value) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionGetValueStatus) TryGetVector2(param::hstring const& propertyName, llm:OS::Foundation::Numerics::float2& value) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionGetValueStatus) TryGetVector3(param::hstring const& propertyName, llm:OS::Foundation::Numerics::float3& value) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionGetValueStatus) TryGetVector4(param::hstring const& propertyName, llm:OS::Foundation::Numerics::float4& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionPropertySet>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionPropertySet<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionPropertySet2
    {
        LLM_IMPL_AUTO(void) InsertBoolean(param::hstring const& propertyName, bool value) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionGetValueStatus) TryGetBoolean(param::hstring const& propertyName, bool& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionPropertySet2>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionPropertySet2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionRadialGradientBrush
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) EllipseCenter() const;
        LLM_IMPL_AUTO(void) EllipseCenter(llm:OS::Foundation::Numerics::float2 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) EllipseRadius() const;
        LLM_IMPL_AUTO(void) EllipseRadius(llm:OS::Foundation::Numerics::float2 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) GradientOriginOffset() const;
        LLM_IMPL_AUTO(void) GradientOriginOffset(llm:OS::Foundation::Numerics::float2 const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionRadialGradientBrush>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionRadialGradientBrush<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionRectangleGeometry
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) Offset() const;
        LLM_IMPL_AUTO(void) Offset(llm:OS::Foundation::Numerics::float2 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) Size() const;
        LLM_IMPL_AUTO(void) Size(llm:OS::Foundation::Numerics::float2 const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionRectangleGeometry>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionRectangleGeometry<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionRoundedRectangleGeometry
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) CornerRadius() const;
        LLM_IMPL_AUTO(void) CornerRadius(llm:OS::Foundation::Numerics::float2 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) Offset() const;
        LLM_IMPL_AUTO(void) Offset(llm:OS::Foundation::Numerics::float2 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) Size() const;
        LLM_IMPL_AUTO(void) Size(llm:OS::Foundation::Numerics::float2 const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionRoundedRectangleGeometry>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionRoundedRectangleGeometry<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionScopedBatch
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsActive() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsEnded() const;
        LLM_IMPL_AUTO(void) End() const;
        LLM_IMPL_AUTO(void) Resume() const;
        LLM_IMPL_AUTO(void) Suspend() const;
        LLM_IMPL_AUTO(llm::event_token) Completed(llm:OS::Foundation::TypedEventHandler<llm:OS::Foundation::IInspectable, llm:OS::UI::Composition::CompositionBatchCompletedEventArgs> const& handler) const;
        using Completed_revoker = impl::event_revoker<llm:OS::UI::Composition::ICompositionScopedBatch, &impl::abi_t<llm:OS::UI::Composition::ICompositionScopedBatch>::remove_Completed>;
        [[nodiscard]] Completed_revoker Completed(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Foundation::IInspectable, llm:OS::UI::Composition::CompositionBatchCompletedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) Completed(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionScopedBatch>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionScopedBatch<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionShadow
    {
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionShadow>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionShadow<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionShadowFactory
    {
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionShadowFactory>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionShadowFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionShape
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) CenterPoint() const;
        LLM_IMPL_AUTO(void) CenterPoint(llm:OS::Foundation::Numerics::float2 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) Offset() const;
        LLM_IMPL_AUTO(void) Offset(llm:OS::Foundation::Numerics::float2 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) RotationAngle() const;
        LLM_IMPL_AUTO(void) RotationAngle(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) RotationAngleInDegrees() const;
        LLM_IMPL_AUTO(void) RotationAngleInDegrees(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) Scale() const;
        LLM_IMPL_AUTO(void) Scale(llm:OS::Foundation::Numerics::float2 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float3x2) TransformMatrix() const;
        LLM_IMPL_AUTO(void) TransformMatrix(llm:OS::Foundation::Numerics::float3x2 const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionShape>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionShape<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionShapeFactory
    {
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionShapeFactory>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionShapeFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionSpriteShape
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionBrush) FillBrush() const;
        LLM_IMPL_AUTO(void) FillBrush(llm:OS::UI::Composition::CompositionBrush const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionGeometry) Geometry() const;
        LLM_IMPL_AUTO(void) Geometry(llm:OS::UI::Composition::CompositionGeometry const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsStrokeNonScaling() const;
        LLM_IMPL_AUTO(void) IsStrokeNonScaling(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionBrush) StrokeBrush() const;
        LLM_IMPL_AUTO(void) StrokeBrush(llm:OS::UI::Composition::CompositionBrush const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionStrokeDashArray) StrokeDashArray() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionStrokeCap) StrokeDashCap() const;
        LLM_IMPL_AUTO(void) StrokeDashCap(llm:OS::UI::Composition::CompositionStrokeCap const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) StrokeDashOffset() const;
        LLM_IMPL_AUTO(void) StrokeDashOffset(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionStrokeCap) StrokeEndCap() const;
        LLM_IMPL_AUTO(void) StrokeEndCap(llm:OS::UI::Composition::CompositionStrokeCap const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionStrokeLineJoin) StrokeLineJoin() const;
        LLM_IMPL_AUTO(void) StrokeLineJoin(llm:OS::UI::Composition::CompositionStrokeLineJoin const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) StrokeMiterLimit() const;
        LLM_IMPL_AUTO(void) StrokeMiterLimit(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionStrokeCap) StrokeStartCap() const;
        LLM_IMPL_AUTO(void) StrokeStartCap(llm:OS::UI::Composition::CompositionStrokeCap const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) StrokeThickness() const;
        LLM_IMPL_AUTO(void) StrokeThickness(float value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionSpriteShape>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionSpriteShape<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionSupportsSystemBackdrop
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionBrush) SystemBackdrop() const;
        LLM_IMPL_AUTO(void) SystemBackdrop(llm:OS::UI::Composition::CompositionBrush const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionSupportsSystemBackdrop>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionSupportsSystemBackdrop<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionSurface
    {
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionSurface>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionSurface<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionSurfaceBrush
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionBitmapInterpolationMode) BitmapInterpolationMode() const;
        LLM_IMPL_AUTO(void) BitmapInterpolationMode(llm:OS::UI::Composition::CompositionBitmapInterpolationMode const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) HorizontalAlignmentRatio() const;
        LLM_IMPL_AUTO(void) HorizontalAlignmentRatio(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionStretch) Stretch() const;
        LLM_IMPL_AUTO(void) Stretch(llm:OS::UI::Composition::CompositionStretch const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::ICompositionSurface) Surface() const;
        LLM_IMPL_AUTO(void) Surface(llm:OS::UI::Composition::ICompositionSurface const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) VerticalAlignmentRatio() const;
        LLM_IMPL_AUTO(void) VerticalAlignmentRatio(float value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionSurfaceBrush>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionSurfaceBrush<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionSurfaceBrush2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) AnchorPoint() const;
        LLM_IMPL_AUTO(void) AnchorPoint(llm:OS::Foundation::Numerics::float2 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) CenterPoint() const;
        LLM_IMPL_AUTO(void) CenterPoint(llm:OS::Foundation::Numerics::float2 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) Offset() const;
        LLM_IMPL_AUTO(void) Offset(llm:OS::Foundation::Numerics::float2 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) RotationAngle() const;
        LLM_IMPL_AUTO(void) RotationAngle(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) RotationAngleInDegrees() const;
        LLM_IMPL_AUTO(void) RotationAngleInDegrees(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) Scale() const;
        LLM_IMPL_AUTO(void) Scale(llm:OS::Foundation::Numerics::float2 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float3x2) TransformMatrix() const;
        LLM_IMPL_AUTO(void) TransformMatrix(llm:OS::Foundation::Numerics::float3x2 const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionSurfaceBrush2>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionSurfaceBrush2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionSurfaceBrush3
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) SnapToPixels() const;
        LLM_IMPL_AUTO(void) SnapToPixels(bool value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionSurfaceBrush3>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionSurfaceBrush3<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionSurfaceFacade
    {
        LLM_IMPL_AUTO(llm:OS::UI::Composition::ICompositionSurface) GetRealSurface() const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionSurfaceFacade>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionSurfaceFacade<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionTarget
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::Visual) Root() const;
        LLM_IMPL_AUTO(void) Root(llm:OS::UI::Composition::Visual const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionTarget>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionTarget<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionTargetFactory
    {
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionTargetFactory>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionTargetFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionTexture
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::RectInt32) SourceRect() const;
        LLM_IMPL_AUTO(void) SourceRect(llm:OS::Graphics::RectInt32 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::DirectX::DirectXAlphaMode) AlphaMode() const;
        LLM_IMPL_AUTO(void) AlphaMode(llm:OS::Graphics::DirectX::DirectXAlphaMode const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::DirectX::DirectXColorSpace) ColorSpace() const;
        LLM_IMPL_AUTO(void) ColorSpace(llm:OS::Graphics::DirectX::DirectXColorSpace const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionTexture>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionTexture<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionTextureFactory
    {
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionTextureFactory>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionTextureFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionTransform
    {
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionTransform>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionTransform<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionTransformFactory
    {
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionTransformFactory>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionTransformFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionViewBox
    {
        [[nodiscard]] LLM_IMPL_AUTO(float) HorizontalAlignmentRatio() const;
        LLM_IMPL_AUTO(void) HorizontalAlignmentRatio(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) Offset() const;
        LLM_IMPL_AUTO(void) Offset(llm:OS::Foundation::Numerics::float2 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) Size() const;
        LLM_IMPL_AUTO(void) Size(llm:OS::Foundation::Numerics::float2 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionStretch) Stretch() const;
        LLM_IMPL_AUTO(void) Stretch(llm:OS::UI::Composition::CompositionStretch const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) VerticalAlignmentRatio() const;
        LLM_IMPL_AUTO(void) VerticalAlignmentRatio(float value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionViewBox>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionViewBox<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionVirtualDrawingSurface
    {
        LLM_IMPL_AUTO(void) Trim(array_view<llm:OS::Graphics::RectInt32 const> rects) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionVirtualDrawingSurface>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionVirtualDrawingSurface<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionVirtualDrawingSurfaceFactory
    {
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionVirtualDrawingSurfaceFactory>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionVirtualDrawingSurfaceFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositionVisualSurface
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::Visual) SourceVisual() const;
        LLM_IMPL_AUTO(void) SourceVisual(llm:OS::UI::Composition::Visual const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) SourceOffset() const;
        LLM_IMPL_AUTO(void) SourceOffset(llm:OS::Foundation::Numerics::float2 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) SourceSize() const;
        LLM_IMPL_AUTO(void) SourceSize(llm:OS::Foundation::Numerics::float2 const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositionVisualSurface>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositionVisualSurface<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositor
    {
        LLM_IMPL_AUTO(llm:OS::UI::Composition::ColorKeyFrameAnimation) CreateColorKeyFrameAnimation() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionColorBrush) CreateColorBrush() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionColorBrush) CreateColorBrush(llm:OS::UI::Color const& color) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::ContainerVisual) CreateContainerVisual() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CubicBezierEasingFunction) CreateCubicBezierEasingFunction(llm:OS::Foundation::Numerics::float2 const& controlPoint1, llm:OS::Foundation::Numerics::float2 const& controlPoint2) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionEffectFactory) CreateEffectFactory(llm:OS::Graphics::Effects::IGraphicsEffect const& graphicsEffect) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionEffectFactory) CreateEffectFactory(llm:OS::Graphics::Effects::IGraphicsEffect const& graphicsEffect, param::iterable<hstring> const& animatableProperties) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::ExpressionAnimation) CreateExpressionAnimation() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::ExpressionAnimation) CreateExpressionAnimation(param::hstring const& expression) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::InsetClip) CreateInsetClip() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::InsetClip) CreateInsetClip(float leftInset, float topInset, float rightInset, float bottomInset) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::LinearEasingFunction) CreateLinearEasingFunction() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionPropertySet) CreatePropertySet() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::QuaternionKeyFrameAnimation) CreateQuaternionKeyFrameAnimation() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::ScalarKeyFrameAnimation) CreateScalarKeyFrameAnimation() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionScopedBatch) CreateScopedBatch(llm:OS::UI::Composition::CompositionBatchTypes const& batchType) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::SpriteVisual) CreateSpriteVisual() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionSurfaceBrush) CreateSurfaceBrush() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionSurfaceBrush) CreateSurfaceBrush(llm:OS::UI::Composition::ICompositionSurface const& surface) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionTarget) CreateTargetForCurrentView() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::Vector2KeyFrameAnimation) CreateVector2KeyFrameAnimation() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::Vector3KeyFrameAnimation) CreateVector3KeyFrameAnimation() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::Vector4KeyFrameAnimation) CreateVector4KeyFrameAnimation() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionCommitBatch) GetCommitBatch(llm:OS::UI::Composition::CompositionBatchTypes const& batchType) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositor>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositor<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositor2
    {
        LLM_IMPL_AUTO(llm:OS::UI::Composition::AmbientLight) CreateAmbientLight() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionAnimationGroup) CreateAnimationGroup() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionBackdropBrush) CreateBackdropBrush() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::DistantLight) CreateDistantLight() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::DropShadow) CreateDropShadow() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::ImplicitAnimationCollection) CreateImplicitAnimationCollection() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::LayerVisual) CreateLayerVisual() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionMaskBrush) CreateMaskBrush() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionNineGridBrush) CreateNineGridBrush() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::PointLight) CreatePointLight() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::SpotLight) CreateSpotLight() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::StepEasingFunction) CreateStepEasingFunction() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::StepEasingFunction) CreateStepEasingFunction(int32_t stepCount) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositor2>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositor2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositor3
    {
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionBackdropBrush) CreateHostBackdropBrush() const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositor3>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositor3<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositor4
    {
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionColorGradientStop) CreateColorGradientStop() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionColorGradientStop) CreateColorGradientStop(float offset, llm:OS::UI::Color const& color) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionLinearGradientBrush) CreateLinearGradientBrush() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::SpringScalarNaturalMotionAnimation) CreateSpringScalarAnimation() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::SpringVector2NaturalMotionAnimation) CreateSpringVector2Animation() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::SpringVector3NaturalMotionAnimation) CreateSpringVector3Animation() const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositor4>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositor4<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositor5
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Comment() const;
        LLM_IMPL_AUTO(void) Comment(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) GlobalPlaybackRate() const;
        LLM_IMPL_AUTO(void) GlobalPlaybackRate(float value) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::BounceScalarNaturalMotionAnimation) CreateBounceScalarAnimation() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::BounceVector2NaturalMotionAnimation) CreateBounceVector2Animation() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::BounceVector3NaturalMotionAnimation) CreateBounceVector3Animation() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionContainerShape) CreateContainerShape() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionEllipseGeometry) CreateEllipseGeometry() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionLineGeometry) CreateLineGeometry() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionPathGeometry) CreatePathGeometry() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionPathGeometry) CreatePathGeometry(llm:OS::UI::Composition::CompositionPath const& path) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::PathKeyFrameAnimation) CreatePathKeyFrameAnimation() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionRectangleGeometry) CreateRectangleGeometry() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionRoundedRectangleGeometry) CreateRoundedRectangleGeometry() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::ShapeVisual) CreateShapeVisual() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionSpriteShape) CreateSpriteShape() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionSpriteShape) CreateSpriteShape(llm:OS::UI::Composition::CompositionGeometry const& geometry) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionViewBox) CreateViewBox() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) RequestCommitAsync() const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositor5>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositor5<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositor6
    {
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionGeometricClip) CreateGeometricClip() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionGeometricClip) CreateGeometricClip(llm:OS::UI::Composition::CompositionGeometry const& geometry) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::RedirectVisual) CreateRedirectVisual() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::RedirectVisual) CreateRedirectVisual(llm:OS::UI::Composition::Visual const& source) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::BooleanKeyFrameAnimation) CreateBooleanKeyFrameAnimation() const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositor6>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositor6<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositor7
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::DispatcherQueue) DispatcherQueue() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::AnimationPropertyInfo) CreateAnimationPropertyInfo() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::RectangleClip) CreateRectangleClip() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::RectangleClip) CreateRectangleClip(float left, float top, float right, float bottom) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::RectangleClip) CreateRectangleClip(float left, float top, float right, float bottom, llm:OS::Foundation::Numerics::float2 const& topLeftRadius, llm:OS::Foundation::Numerics::float2 const& topRightRadius, llm:OS::Foundation::Numerics::float2 const& bottomRightRadius, llm:OS::Foundation::Numerics::float2 const& bottomLeftRadius) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositor7>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositor7<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositor8
    {
        LLM_IMPL_AUTO(llm:OS::UI::Composition::AnimationController) CreateAnimationController() const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositor8>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositor8<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositorStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(float) MaxGlobalPlaybackRate() const;
        [[nodiscard]] LLM_IMPL_AUTO(float) MinGlobalPlaybackRate() const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositorStatics>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositorStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositorWithBlurredWallpaperBackdropBrush
    {
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionBackdropBrush) TryCreateBlurredWallpaperBackdropBrush() const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositorWithBlurredWallpaperBackdropBrush>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositorWithBlurredWallpaperBackdropBrush<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositorWithProjectedShadow
    {
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionProjectedShadowCaster) CreateProjectedShadowCaster() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionProjectedShadow) CreateProjectedShadow() const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionProjectedShadowReceiver) CreateProjectedShadowReceiver() const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositorWithProjectedShadow>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositorWithProjectedShadow<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositorWithRadialGradient
    {
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionRadialGradientBrush) CreateRadialGradientBrush() const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositorWithRadialGradient>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositorWithRadialGradient<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICompositorWithVisualSurface
    {
        LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionVisualSurface) CreateVisualSurface() const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICompositorWithVisualSurface>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICompositorWithVisualSurface<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IContainerVisual
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::VisualCollection) Children() const;
    };
    template <> struct consume<llm:OS::UI::Composition::IContainerVisual>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IContainerVisual<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IContainerVisualFactory
    {
    };
    template <> struct consume<llm:OS::UI::Composition::IContainerVisualFactory>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IContainerVisualFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ICubicBezierEasingFunction
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) ControlPoint1() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) ControlPoint2() const;
    };
    template <> struct consume<llm:OS::UI::Composition::ICubicBezierEasingFunction>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ICubicBezierEasingFunction<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IDelegatedInkTrailVisual
    {
        LLM_IMPL_AUTO(uint32_t) AddTrailPoints(array_view<llm:OS::UI::Composition::InkTrailPoint const> inkPoints) const;
        LLM_IMPL_AUTO(uint32_t) AddTrailPointsWithPrediction(array_view<llm:OS::UI::Composition::InkTrailPoint const> inkPoints, array_view<llm:OS::UI::Composition::InkTrailPoint const> predictedInkPoints) const;
        LLM_IMPL_AUTO(void) RemoveTrailPoints(uint32_t generationId) const;
        LLM_IMPL_AUTO(void) StartNewTrail(llm:OS::UI::Color const& color) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IDelegatedInkTrailVisual>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IDelegatedInkTrailVisual<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IDelegatedInkTrailVisualStatics
    {
        LLM_IMPL_AUTO(llm:OS::UI::Composition::DelegatedInkTrailVisual) Create(llm:OS::UI::Composition::Compositor const& compositor) const;
        LLM_IMPL_AUTO(llm:OS::UI::Composition::DelegatedInkTrailVisual) CreateForSwapChain(llm:OS::UI::Composition::Compositor const& compositor, llm:OS::UI::Composition::ICompositionSurface const& swapChain) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IDelegatedInkTrailVisualStatics>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IDelegatedInkTrailVisualStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IDistantLight
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Color) Color() const;
        LLM_IMPL_AUTO(void) Color(llm:OS::UI::Color const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::Visual) CoordinateSpace() const;
        LLM_IMPL_AUTO(void) CoordinateSpace(llm:OS::UI::Composition::Visual const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float3) Direction() const;
        LLM_IMPL_AUTO(void) Direction(llm:OS::Foundation::Numerics::float3 const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IDistantLight>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IDistantLight<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IDistantLight2
    {
        [[nodiscard]] LLM_IMPL_AUTO(float) Intensity() const;
        LLM_IMPL_AUTO(void) Intensity(float value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IDistantLight2>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IDistantLight2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IDropShadow
    {
        [[nodiscard]] LLM_IMPL_AUTO(float) BlurRadius() const;
        LLM_IMPL_AUTO(void) BlurRadius(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Color) Color() const;
        LLM_IMPL_AUTO(void) Color(llm:OS::UI::Color const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionBrush) Mask() const;
        LLM_IMPL_AUTO(void) Mask(llm:OS::UI::Composition::CompositionBrush const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float3) Offset() const;
        LLM_IMPL_AUTO(void) Offset(llm:OS::Foundation::Numerics::float3 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) Opacity() const;
        LLM_IMPL_AUTO(void) Opacity(float value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IDropShadow>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IDropShadow<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IDropShadow2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionDropShadowSourcePolicy) SourcePolicy() const;
        LLM_IMPL_AUTO(void) SourcePolicy(llm:OS::UI::Composition::CompositionDropShadowSourcePolicy const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IDropShadow2>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IDropShadow2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IElasticEasingFunction
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionEasingFunctionMode) Mode() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) Oscillations() const;
        [[nodiscard]] LLM_IMPL_AUTO(float) Springiness() const;
    };
    template <> struct consume<llm:OS::UI::Composition::IElasticEasingFunction>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IElasticEasingFunction<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IExponentialEasingFunction
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionEasingFunctionMode) Mode() const;
        [[nodiscard]] LLM_IMPL_AUTO(float) Exponent() const;
    };
    template <> struct consume<llm:OS::UI::Composition::IExponentialEasingFunction>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IExponentialEasingFunction<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IExpressionAnimation
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Expression() const;
        LLM_IMPL_AUTO(void) Expression(param::hstring const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IExpressionAnimation>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IExpressionAnimation<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IImplicitAnimationCollection
    {
    };
    template <> struct consume<llm:OS::UI::Composition::IImplicitAnimationCollection>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IImplicitAnimationCollection<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IInsetClip
    {
        [[nodiscard]] LLM_IMPL_AUTO(float) BottomInset() const;
        LLM_IMPL_AUTO(void) BottomInset(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) LeftInset() const;
        LLM_IMPL_AUTO(void) LeftInset(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) RightInset() const;
        LLM_IMPL_AUTO(void) RightInset(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) TopInset() const;
        LLM_IMPL_AUTO(void) TopInset(float value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IInsetClip>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IInsetClip<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IKeyFrameAnimation
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) DelayTime() const;
        LLM_IMPL_AUTO(void) DelayTime(llm:OS::Foundation::TimeSpan const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) Duration() const;
        LLM_IMPL_AUTO(void) Duration(llm:OS::Foundation::TimeSpan const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::AnimationIterationBehavior) IterationBehavior() const;
        LLM_IMPL_AUTO(void) IterationBehavior(llm:OS::UI::Composition::AnimationIterationBehavior const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) IterationCount() const;
        LLM_IMPL_AUTO(void) IterationCount(int32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) KeyFrameCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::AnimationStopBehavior) StopBehavior() const;
        LLM_IMPL_AUTO(void) StopBehavior(llm:OS::UI::Composition::AnimationStopBehavior const& value) const;
        LLM_IMPL_AUTO(void) InsertExpressionKeyFrame(float normalizedProgressKey, param::hstring const& value) const;
        LLM_IMPL_AUTO(void) InsertExpressionKeyFrame(float normalizedProgressKey, param::hstring const& value, llm:OS::UI::Composition::CompositionEasingFunction const& easingFunction) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IKeyFrameAnimation>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IKeyFrameAnimation<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IKeyFrameAnimation2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::AnimationDirection) Direction() const;
        LLM_IMPL_AUTO(void) Direction(llm:OS::UI::Composition::AnimationDirection const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IKeyFrameAnimation2>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IKeyFrameAnimation2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IKeyFrameAnimation3
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::AnimationDelayBehavior) DelayBehavior() const;
        LLM_IMPL_AUTO(void) DelayBehavior(llm:OS::UI::Composition::AnimationDelayBehavior const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IKeyFrameAnimation3>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IKeyFrameAnimation3<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IKeyFrameAnimationFactory
    {
    };
    template <> struct consume<llm:OS::UI::Composition::IKeyFrameAnimationFactory>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IKeyFrameAnimationFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ILayerVisual
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionEffectBrush) Effect() const;
        LLM_IMPL_AUTO(void) Effect(llm:OS::UI::Composition::CompositionEffectBrush const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ILayerVisual>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ILayerVisual<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ILayerVisual2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionShadow) Shadow() const;
        LLM_IMPL_AUTO(void) Shadow(llm:OS::UI::Composition::CompositionShadow const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ILayerVisual2>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ILayerVisual2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ILinearEasingFunction
    {
    };
    template <> struct consume<llm:OS::UI::Composition::ILinearEasingFunction>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ILinearEasingFunction<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_INaturalMotionAnimation
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::AnimationDelayBehavior) DelayBehavior() const;
        LLM_IMPL_AUTO(void) DelayBehavior(llm:OS::UI::Composition::AnimationDelayBehavior const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) DelayTime() const;
        LLM_IMPL_AUTO(void) DelayTime(llm:OS::Foundation::TimeSpan const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::AnimationStopBehavior) StopBehavior() const;
        LLM_IMPL_AUTO(void) StopBehavior(llm:OS::UI::Composition::AnimationStopBehavior const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::INaturalMotionAnimation>
    {
        template <typename D> using type = consume_Windows_UI_Composition_INaturalMotionAnimation<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_INaturalMotionAnimationFactory
    {
    };
    template <> struct consume<llm:OS::UI::Composition::INaturalMotionAnimationFactory>
    {
        template <typename D> using type = consume_Windows_UI_Composition_INaturalMotionAnimationFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IPathKeyFrameAnimation
    {
        LLM_IMPL_AUTO(void) InsertKeyFrame(float normalizedProgressKey, llm:OS::UI::Composition::CompositionPath const& path) const;
        LLM_IMPL_AUTO(void) InsertKeyFrame(float normalizedProgressKey, llm:OS::UI::Composition::CompositionPath const& path, llm:OS::UI::Composition::CompositionEasingFunction const& easingFunction) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IPathKeyFrameAnimation>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IPathKeyFrameAnimation<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IPointLight
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Color) Color() const;
        LLM_IMPL_AUTO(void) Color(llm:OS::UI::Color const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) ConstantAttenuation() const;
        LLM_IMPL_AUTO(void) ConstantAttenuation(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::Visual) CoordinateSpace() const;
        LLM_IMPL_AUTO(void) CoordinateSpace(llm:OS::UI::Composition::Visual const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) LinearAttenuation() const;
        LLM_IMPL_AUTO(void) LinearAttenuation(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float3) Offset() const;
        LLM_IMPL_AUTO(void) Offset(llm:OS::Foundation::Numerics::float3 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) QuadraticAttenuation() const;
        LLM_IMPL_AUTO(void) QuadraticAttenuation(float value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IPointLight>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IPointLight<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IPointLight2
    {
        [[nodiscard]] LLM_IMPL_AUTO(float) Intensity() const;
        LLM_IMPL_AUTO(void) Intensity(float value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IPointLight2>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IPointLight2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IPointLight3
    {
        [[nodiscard]] LLM_IMPL_AUTO(float) MinAttenuationCutoff() const;
        LLM_IMPL_AUTO(void) MinAttenuationCutoff(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) MaxAttenuationCutoff() const;
        LLM_IMPL_AUTO(void) MaxAttenuationCutoff(float value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IPointLight3>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IPointLight3<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IPowerEasingFunction
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionEasingFunctionMode) Mode() const;
        [[nodiscard]] LLM_IMPL_AUTO(float) Power() const;
    };
    template <> struct consume<llm:OS::UI::Composition::IPowerEasingFunction>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IPowerEasingFunction<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IQuaternionKeyFrameAnimation
    {
        LLM_IMPL_AUTO(void) InsertKeyFrame(float normalizedProgressKey, llm:OS::Foundation::Numerics::quaternion const& value) const;
        LLM_IMPL_AUTO(void) InsertKeyFrame(float normalizedProgressKey, llm:OS::Foundation::Numerics::quaternion const& value, llm:OS::UI::Composition::CompositionEasingFunction const& easingFunction) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IQuaternionKeyFrameAnimation>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IQuaternionKeyFrameAnimation<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IRectangleClip
    {
        [[nodiscard]] LLM_IMPL_AUTO(float) Bottom() const;
        LLM_IMPL_AUTO(void) Bottom(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) BottomLeftRadius() const;
        LLM_IMPL_AUTO(void) BottomLeftRadius(llm:OS::Foundation::Numerics::float2 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) BottomRightRadius() const;
        LLM_IMPL_AUTO(void) BottomRightRadius(llm:OS::Foundation::Numerics::float2 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) Left() const;
        LLM_IMPL_AUTO(void) Left(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) Right() const;
        LLM_IMPL_AUTO(void) Right(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) Top() const;
        LLM_IMPL_AUTO(void) Top(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) TopLeftRadius() const;
        LLM_IMPL_AUTO(void) TopLeftRadius(llm:OS::Foundation::Numerics::float2 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) TopRightRadius() const;
        LLM_IMPL_AUTO(void) TopRightRadius(llm:OS::Foundation::Numerics::float2 const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IRectangleClip>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IRectangleClip<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IRedirectVisual
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::Visual) Source() const;
        LLM_IMPL_AUTO(void) Source(llm:OS::UI::Composition::Visual const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IRedirectVisual>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IRedirectVisual<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IRenderingDeviceReplacedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionGraphicsDevice) GraphicsDevice() const;
    };
    template <> struct consume<llm:OS::UI::Composition::IRenderingDeviceReplacedEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IRenderingDeviceReplacedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IScalarKeyFrameAnimation
    {
        LLM_IMPL_AUTO(void) InsertKeyFrame(float normalizedProgressKey, float value) const;
        LLM_IMPL_AUTO(void) InsertKeyFrame(float normalizedProgressKey, float value, llm:OS::UI::Composition::CompositionEasingFunction const& easingFunction) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IScalarKeyFrameAnimation>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IScalarKeyFrameAnimation<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IScalarNaturalMotionAnimation
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IReference<float>) FinalValue() const;
        LLM_IMPL_AUTO(void) FinalValue(llm:OS::Foundation::IReference<float> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IReference<float>) InitialValue() const;
        LLM_IMPL_AUTO(void) InitialValue(llm:OS::Foundation::IReference<float> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) InitialVelocity() const;
        LLM_IMPL_AUTO(void) InitialVelocity(float value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IScalarNaturalMotionAnimation>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IScalarNaturalMotionAnimation<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IScalarNaturalMotionAnimationFactory
    {
    };
    template <> struct consume<llm:OS::UI::Composition::IScalarNaturalMotionAnimationFactory>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IScalarNaturalMotionAnimationFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IShapeVisual
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionShapeCollection) Shapes() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionViewBox) ViewBox() const;
        LLM_IMPL_AUTO(void) ViewBox(llm:OS::UI::Composition::CompositionViewBox const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IShapeVisual>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IShapeVisual<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ISineEasingFunction
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionEasingFunctionMode) Mode() const;
    };
    template <> struct consume<llm:OS::UI::Composition::ISineEasingFunction>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ISineEasingFunction<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ISpotLight
    {
        [[nodiscard]] LLM_IMPL_AUTO(float) ConstantAttenuation() const;
        LLM_IMPL_AUTO(void) ConstantAttenuation(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::Visual) CoordinateSpace() const;
        LLM_IMPL_AUTO(void) CoordinateSpace(llm:OS::UI::Composition::Visual const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float3) Direction() const;
        LLM_IMPL_AUTO(void) Direction(llm:OS::Foundation::Numerics::float3 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) InnerConeAngle() const;
        LLM_IMPL_AUTO(void) InnerConeAngle(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) InnerConeAngleInDegrees() const;
        LLM_IMPL_AUTO(void) InnerConeAngleInDegrees(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Color) InnerConeColor() const;
        LLM_IMPL_AUTO(void) InnerConeColor(llm:OS::UI::Color const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) LinearAttenuation() const;
        LLM_IMPL_AUTO(void) LinearAttenuation(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float3) Offset() const;
        LLM_IMPL_AUTO(void) Offset(llm:OS::Foundation::Numerics::float3 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) OuterConeAngle() const;
        LLM_IMPL_AUTO(void) OuterConeAngle(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) OuterConeAngleInDegrees() const;
        LLM_IMPL_AUTO(void) OuterConeAngleInDegrees(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Color) OuterConeColor() const;
        LLM_IMPL_AUTO(void) OuterConeColor(llm:OS::UI::Color const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) QuadraticAttenuation() const;
        LLM_IMPL_AUTO(void) QuadraticAttenuation(float value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ISpotLight>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ISpotLight<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ISpotLight2
    {
        [[nodiscard]] LLM_IMPL_AUTO(float) InnerConeIntensity() const;
        LLM_IMPL_AUTO(void) InnerConeIntensity(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) OuterConeIntensity() const;
        LLM_IMPL_AUTO(void) OuterConeIntensity(float value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ISpotLight2>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ISpotLight2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ISpotLight3
    {
        [[nodiscard]] LLM_IMPL_AUTO(float) MinAttenuationCutoff() const;
        LLM_IMPL_AUTO(void) MinAttenuationCutoff(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) MaxAttenuationCutoff() const;
        LLM_IMPL_AUTO(void) MaxAttenuationCutoff(float value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ISpotLight3>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ISpotLight3<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ISpringScalarNaturalMotionAnimation
    {
        [[nodiscard]] LLM_IMPL_AUTO(float) DampingRatio() const;
        LLM_IMPL_AUTO(void) DampingRatio(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) Period() const;
        LLM_IMPL_AUTO(void) Period(llm:OS::Foundation::TimeSpan const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ISpringScalarNaturalMotionAnimation>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ISpringScalarNaturalMotionAnimation<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ISpringVector2NaturalMotionAnimation
    {
        [[nodiscard]] LLM_IMPL_AUTO(float) DampingRatio() const;
        LLM_IMPL_AUTO(void) DampingRatio(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) Period() const;
        LLM_IMPL_AUTO(void) Period(llm:OS::Foundation::TimeSpan const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ISpringVector2NaturalMotionAnimation>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ISpringVector2NaturalMotionAnimation<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ISpringVector3NaturalMotionAnimation
    {
        [[nodiscard]] LLM_IMPL_AUTO(float) DampingRatio() const;
        LLM_IMPL_AUTO(void) DampingRatio(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) Period() const;
        LLM_IMPL_AUTO(void) Period(llm:OS::Foundation::TimeSpan const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ISpringVector3NaturalMotionAnimation>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ISpringVector3NaturalMotionAnimation<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ISpriteVisual
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionBrush) Brush() const;
        LLM_IMPL_AUTO(void) Brush(llm:OS::UI::Composition::CompositionBrush const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ISpriteVisual>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ISpriteVisual<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_ISpriteVisual2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionShadow) Shadow() const;
        LLM_IMPL_AUTO(void) Shadow(llm:OS::UI::Composition::CompositionShadow const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::ISpriteVisual2>
    {
        template <typename D> using type = consume_Windows_UI_Composition_ISpriteVisual2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IStepEasingFunction
    {
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) FinalStep() const;
        LLM_IMPL_AUTO(void) FinalStep(int32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) InitialStep() const;
        LLM_IMPL_AUTO(void) InitialStep(int32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsFinalStepSingleFrame() const;
        LLM_IMPL_AUTO(void) IsFinalStepSingleFrame(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsInitialStepSingleFrame() const;
        LLM_IMPL_AUTO(void) IsInitialStepSingleFrame(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) StepCount() const;
        LLM_IMPL_AUTO(void) StepCount(int32_t value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IStepEasingFunction>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IStepEasingFunction<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IVector2KeyFrameAnimation
    {
        LLM_IMPL_AUTO(void) InsertKeyFrame(float normalizedProgressKey, llm:OS::Foundation::Numerics::float2 const& value) const;
        LLM_IMPL_AUTO(void) InsertKeyFrame(float normalizedProgressKey, llm:OS::Foundation::Numerics::float2 const& value, llm:OS::UI::Composition::CompositionEasingFunction const& easingFunction) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IVector2KeyFrameAnimation>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IVector2KeyFrameAnimation<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IVector2NaturalMotionAnimation
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IReference<llm:OS::Foundation::Numerics::float2>) FinalValue() const;
        LLM_IMPL_AUTO(void) FinalValue(llm:OS::Foundation::IReference<llm:OS::Foundation::Numerics::float2> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IReference<llm:OS::Foundation::Numerics::float2>) InitialValue() const;
        LLM_IMPL_AUTO(void) InitialValue(llm:OS::Foundation::IReference<llm:OS::Foundation::Numerics::float2> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) InitialVelocity() const;
        LLM_IMPL_AUTO(void) InitialVelocity(llm:OS::Foundation::Numerics::float2 const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IVector2NaturalMotionAnimation>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IVector2NaturalMotionAnimation<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IVector2NaturalMotionAnimationFactory
    {
    };
    template <> struct consume<llm:OS::UI::Composition::IVector2NaturalMotionAnimationFactory>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IVector2NaturalMotionAnimationFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IVector3KeyFrameAnimation
    {
        LLM_IMPL_AUTO(void) InsertKeyFrame(float normalizedProgressKey, llm:OS::Foundation::Numerics::float3 const& value) const;
        LLM_IMPL_AUTO(void) InsertKeyFrame(float normalizedProgressKey, llm:OS::Foundation::Numerics::float3 const& value, llm:OS::UI::Composition::CompositionEasingFunction const& easingFunction) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IVector3KeyFrameAnimation>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IVector3KeyFrameAnimation<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IVector3NaturalMotionAnimation
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IReference<llm:OS::Foundation::Numerics::float3>) FinalValue() const;
        LLM_IMPL_AUTO(void) FinalValue(llm:OS::Foundation::IReference<llm:OS::Foundation::Numerics::float3> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IReference<llm:OS::Foundation::Numerics::float3>) InitialValue() const;
        LLM_IMPL_AUTO(void) InitialValue(llm:OS::Foundation::IReference<llm:OS::Foundation::Numerics::float3> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float3) InitialVelocity() const;
        LLM_IMPL_AUTO(void) InitialVelocity(llm:OS::Foundation::Numerics::float3 const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IVector3NaturalMotionAnimation>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IVector3NaturalMotionAnimation<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IVector3NaturalMotionAnimationFactory
    {
    };
    template <> struct consume<llm:OS::UI::Composition::IVector3NaturalMotionAnimationFactory>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IVector3NaturalMotionAnimationFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IVector4KeyFrameAnimation
    {
        LLM_IMPL_AUTO(void) InsertKeyFrame(float normalizedProgressKey, llm:OS::Foundation::Numerics::float4 const& value) const;
        LLM_IMPL_AUTO(void) InsertKeyFrame(float normalizedProgressKey, llm:OS::Foundation::Numerics::float4 const& value, llm:OS::UI::Composition::CompositionEasingFunction const& easingFunction) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IVector4KeyFrameAnimation>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IVector4KeyFrameAnimation<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IVisual
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) AnchorPoint() const;
        LLM_IMPL_AUTO(void) AnchorPoint(llm:OS::Foundation::Numerics::float2 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionBackfaceVisibility) BackfaceVisibility() const;
        LLM_IMPL_AUTO(void) BackfaceVisibility(llm:OS::UI::Composition::CompositionBackfaceVisibility const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionBorderMode) BorderMode() const;
        LLM_IMPL_AUTO(void) BorderMode(llm:OS::UI::Composition::CompositionBorderMode const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float3) CenterPoint() const;
        LLM_IMPL_AUTO(void) CenterPoint(llm:OS::Foundation::Numerics::float3 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionClip) Clip() const;
        LLM_IMPL_AUTO(void) Clip(llm:OS::UI::Composition::CompositionClip const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::CompositionCompositeMode) CompositeMode() const;
        LLM_IMPL_AUTO(void) CompositeMode(llm:OS::UI::Composition::CompositionCompositeMode const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsVisible() const;
        LLM_IMPL_AUTO(void) IsVisible(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float3) Offset() const;
        LLM_IMPL_AUTO(void) Offset(llm:OS::Foundation::Numerics::float3 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) Opacity() const;
        LLM_IMPL_AUTO(void) Opacity(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::quaternion) Orientation() const;
        LLM_IMPL_AUTO(void) Orientation(llm:OS::Foundation::Numerics::quaternion const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::ContainerVisual) Parent() const;
        [[nodiscard]] LLM_IMPL_AUTO(float) RotationAngle() const;
        LLM_IMPL_AUTO(void) RotationAngle(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) RotationAngleInDegrees() const;
        LLM_IMPL_AUTO(void) RotationAngleInDegrees(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float3) RotationAxis() const;
        LLM_IMPL_AUTO(void) RotationAxis(llm:OS::Foundation::Numerics::float3 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float3) Scale() const;
        LLM_IMPL_AUTO(void) Scale(llm:OS::Foundation::Numerics::float3 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) Size() const;
        LLM_IMPL_AUTO(void) Size(llm:OS::Foundation::Numerics::float2 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float4x4) TransformMatrix() const;
        LLM_IMPL_AUTO(void) TransformMatrix(llm:OS::Foundation::Numerics::float4x4 const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IVisual>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IVisual<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IVisual2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::Visual) ParentForTransform() const;
        LLM_IMPL_AUTO(void) ParentForTransform(llm:OS::UI::Composition::Visual const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float3) RelativeOffsetAdjustment() const;
        LLM_IMPL_AUTO(void) RelativeOffsetAdjustment(llm:OS::Foundation::Numerics::float3 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) RelativeSizeAdjustment() const;
        LLM_IMPL_AUTO(void) RelativeSizeAdjustment(llm:OS::Foundation::Numerics::float2 const& value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IVisual2>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IVisual2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IVisual3
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsHitTestVisible() const;
        LLM_IMPL_AUTO(void) IsHitTestVisible(bool value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IVisual3>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IVisual3<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IVisual4
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsPixelSnappingEnabled() const;
        LLM_IMPL_AUTO(void) IsPixelSnappingEnabled(bool value) const;
    };
    template <> struct consume<llm:OS::UI::Composition::IVisual4>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IVisual4<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IVisualCollection
    {
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) Count() const;
        LLM_IMPL_AUTO(void) InsertAbove(llm:OS::UI::Composition::Visual const& newChild, llm:OS::UI::Composition::Visual const& sibling) const;
        LLM_IMPL_AUTO(void) InsertAtBottom(llm:OS::UI::Composition::Visual const& newChild) const;
        LLM_IMPL_AUTO(void) InsertAtTop(llm:OS::UI::Composition::Visual const& newChild) const;
        LLM_IMPL_AUTO(void) InsertBelow(llm:OS::UI::Composition::Visual const& newChild, llm:OS::UI::Composition::Visual const& sibling) const;
        LLM_IMPL_AUTO(void) Remove(llm:OS::UI::Composition::Visual const& child) const;
        LLM_IMPL_AUTO(void) RemoveAll() const;
    };
    template <> struct consume<llm:OS::UI::Composition::IVisualCollection>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IVisualCollection<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IVisualElement
    {
    };
    template <> struct consume<llm:OS::UI::Composition::IVisualElement>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IVisualElement<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IVisualElement2
    {
        LLM_IMPL_AUTO(llm:OS::UI::Composition::Visual) GetVisualInternal() const;
    };
    template <> struct consume<llm:OS::UI::Composition::IVisualElement2>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IVisualElement2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IVisualFactory
    {
    };
    template <> struct consume<llm:OS::UI::Composition::IVisualFactory>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IVisualFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_IVisualUnorderedCollection
    {
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) Count() const;
        LLM_IMPL_AUTO(void) Add(llm:OS::UI::Composition::Visual const& newVisual) const;
        LLM_IMPL_AUTO(void) Remove(llm:OS::UI::Composition::Visual const& visual) const;
        LLM_IMPL_AUTO(void) RemoveAll() const;
    };
    template <> struct consume<llm:OS::UI::Composition::IVisualUnorderedCollection>
    {
        template <typename D> using type = consume_Windows_UI_Composition_IVisualUnorderedCollection<D>;
    };
    struct struct_Windows_UI_Composition_InkTrailPoint
    {
        llm:OS::Foundation::Point Point;
        float Radius;
    };
    template <> struct abi<Windows::UI::Composition::InkTrailPoint>
    {
        using type = struct_Windows_UI_Composition_InkTrailPoint;
    };
}
#endif
