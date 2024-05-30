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
#ifndef LLM_OS_UI_Xaml_Controls_Maps_2_H
#define LLM_OS_UI_Xaml_Controls_Maps_2_H
#include "llm/impl/Windows.Devices.Geolocation.1.h"
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Services.Maps.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.UI.Composition.1.h"
#include "llm/impl/Windows.UI.Xaml.1.h"
#include "llm/impl/Windows.UI.Xaml.Controls.1.h"
#include "llm/impl/Windows.UI.Xaml.Controls.Maps.1.h"
LLM_EXPORT namespace llm::OS::UI::Xaml::Controls::Maps
{
    struct MapZoomLevelRange
    {
        double Min;
        double Max;
    };
    inline bool operator==(MapZoomLevelRange const& left, MapZoomLevelRange const& right) noexcept
    {
        return left.Min == right.Min && left.Max == right.Max;
    }
    inline bool operator!=(MapZoomLevelRange const& left, MapZoomLevelRange const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) CustomMapTileDataSource : llm::OS::UI::Xaml::Controls::Maps::ICustomMapTileDataSource,
        impl::base<CustomMapTileDataSource, llm::OS::UI::Xaml::Controls::Maps::MapTileDataSource, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<CustomMapTileDataSource, llm::OS::UI::Xaml::Controls::Maps::IMapTileDataSource, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        CustomMapTileDataSource(std::nullptr_t) noexcept {}
        CustomMapTileDataSource(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::ICustomMapTileDataSource(ptr, take_ownership_from_abi) {}
        CustomMapTileDataSource();
    };
    struct __declspec(empty_bases) HttpMapTileDataSource : llm::OS::UI::Xaml::Controls::Maps::IHttpMapTileDataSource,
        impl::base<HttpMapTileDataSource, llm::OS::UI::Xaml::Controls::Maps::MapTileDataSource, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<HttpMapTileDataSource, llm::OS::UI::Xaml::Controls::Maps::IMapTileDataSource, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        HttpMapTileDataSource(std::nullptr_t) noexcept {}
        HttpMapTileDataSource(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IHttpMapTileDataSource(ptr, take_ownership_from_abi) {}
        HttpMapTileDataSource();
        explicit HttpMapTileDataSource(param::hstring const& uriFormatString);
    };
    struct __declspec(empty_bases) LocalMapTileDataSource : llm::OS::UI::Xaml::Controls::Maps::ILocalMapTileDataSource,
        impl::base<LocalMapTileDataSource, llm::OS::UI::Xaml::Controls::Maps::MapTileDataSource, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<LocalMapTileDataSource, llm::OS::UI::Xaml::Controls::Maps::IMapTileDataSource, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        LocalMapTileDataSource(std::nullptr_t) noexcept {}
        LocalMapTileDataSource(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::ILocalMapTileDataSource(ptr, take_ownership_from_abi) {}
        LocalMapTileDataSource();
        explicit LocalMapTileDataSource(param::hstring const& uriFormatString);
    };
    struct __declspec(empty_bases) MapActualCameraChangedEventArgs : llm::OS::UI::Xaml::Controls::Maps::IMapActualCameraChangedEventArgs,
        impl::require<MapActualCameraChangedEventArgs, llm::OS::UI::Xaml::Controls::Maps::IMapActualCameraChangedEventArgs2>
    {
        MapActualCameraChangedEventArgs(std::nullptr_t) noexcept {}
        MapActualCameraChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapActualCameraChangedEventArgs(ptr, take_ownership_from_abi) {}
        MapActualCameraChangedEventArgs();
    };
    struct __declspec(empty_bases) MapActualCameraChangingEventArgs : llm::OS::UI::Xaml::Controls::Maps::IMapActualCameraChangingEventArgs,
        impl::require<MapActualCameraChangingEventArgs, llm::OS::UI::Xaml::Controls::Maps::IMapActualCameraChangingEventArgs2>
    {
        MapActualCameraChangingEventArgs(std::nullptr_t) noexcept {}
        MapActualCameraChangingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapActualCameraChangingEventArgs(ptr, take_ownership_from_abi) {}
        MapActualCameraChangingEventArgs();
    };
    struct __declspec(empty_bases) MapBillboard : llm::OS::UI::Xaml::Controls::Maps::IMapBillboard,
        impl::base<MapBillboard, llm::OS::UI::Xaml::Controls::Maps::MapElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<MapBillboard, llm::OS::UI::Xaml::Controls::Maps::IMapElement, llm::OS::UI::Xaml::Controls::Maps::IMapElement2, llm::OS::UI::Xaml::Controls::Maps::IMapElement3, llm::OS::UI::Xaml::Controls::Maps::IMapElement4, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        MapBillboard(std::nullptr_t) noexcept {}
        MapBillboard(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapBillboard(ptr, take_ownership_from_abi) {}
        explicit MapBillboard(llm::OS::UI::Xaml::Controls::Maps::MapCamera const& camera);
        [[nodiscard]] static auto LocationProperty();
        [[nodiscard]] static auto NormalizedAnchorPointProperty();
        [[nodiscard]] static auto CollisionBehaviorDesiredProperty();
    };
    struct __declspec(empty_bases) MapCamera : llm::OS::UI::Xaml::Controls::Maps::IMapCamera,
        impl::base<MapCamera, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<MapCamera, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        MapCamera(std::nullptr_t) noexcept {}
        MapCamera(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapCamera(ptr, take_ownership_from_abi) {}
        explicit MapCamera(llm::OS::Devices::Geolocation::Geopoint const& location);
        MapCamera(llm::OS::Devices::Geolocation::Geopoint const& location, double headingInDegrees);
        MapCamera(llm::OS::Devices::Geolocation::Geopoint const& location, double headingInDegrees, double pitchInDegrees);
        MapCamera(llm::OS::Devices::Geolocation::Geopoint const& location, double headingInDegrees, double pitchInDegrees, double rollInDegrees, double fieldOfViewInDegrees);
    };
    struct __declspec(empty_bases) MapContextRequestedEventArgs : llm::OS::UI::Xaml::Controls::Maps::IMapContextRequestedEventArgs
    {
        MapContextRequestedEventArgs(std::nullptr_t) noexcept {}
        MapContextRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapContextRequestedEventArgs(ptr, take_ownership_from_abi) {}
        MapContextRequestedEventArgs();
    };
    struct __declspec(empty_bases) MapControl : llm::OS::UI::Xaml::Controls::Maps::IMapControl,
        impl::base<MapControl, llm::OS::UI::Xaml::Controls::Control, llm::OS::UI::Xaml::FrameworkElement, llm::OS::UI::Xaml::UIElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<MapControl, llm::OS::UI::Xaml::Controls::Maps::IMapControl2, llm::OS::UI::Xaml::Controls::Maps::IMapControl3, llm::OS::UI::Xaml::Controls::Maps::IMapControl4, llm::OS::UI::Xaml::Controls::Maps::IMapControl5, llm::OS::UI::Xaml::Controls::Maps::IMapControl6, llm::OS::UI::Xaml::Controls::Maps::IMapControl7, llm::OS::UI::Xaml::Controls::Maps::IMapControl8, llm::OS::UI::Xaml::Controls::IControl, llm::OS::UI::Xaml::Controls::IControl2, llm::OS::UI::Xaml::Controls::IControl3, llm::OS::UI::Xaml::Controls::IControl4, llm::OS::UI::Xaml::Controls::IControl5, llm::OS::UI::Xaml::Controls::IControl7, llm::OS::UI::Xaml::Controls::IControlProtected, llm::OS::UI::Xaml::Controls::IControlOverrides, llm::OS::UI::Xaml::Controls::IControlOverrides6, llm::OS::UI::Xaml::IFrameworkElement, llm::OS::UI::Xaml::IFrameworkElement2, llm::OS::UI::Xaml::IFrameworkElement3, llm::OS::UI::Xaml::IFrameworkElement4, llm::OS::UI::Xaml::IFrameworkElement6, llm::OS::UI::Xaml::IFrameworkElement7, llm::OS::UI::Xaml::IFrameworkElementProtected7, llm::OS::UI::Xaml::IFrameworkElementOverrides, llm::OS::UI::Xaml::IFrameworkElementOverrides2, llm::OS::UI::Xaml::IUIElement, llm::OS::UI::Xaml::IUIElement2, llm::OS::UI::Xaml::IUIElement3, llm::OS::UI::Xaml::IUIElement4, llm::OS::UI::Xaml::IUIElement5, llm::OS::UI::Xaml::IUIElement7, llm::OS::UI::Xaml::IUIElement8, llm::OS::UI::Xaml::IUIElement9, llm::OS::UI::Xaml::IUIElement10, llm::OS::UI::Xaml::IUIElementOverrides, llm::OS::UI::Xaml::IUIElementOverrides7, llm::OS::UI::Xaml::IUIElementOverrides8, llm::OS::UI::Xaml::IUIElementOverrides9, llm::OS::UI::Composition::IAnimationObject, llm::OS::UI::Composition::IVisualElement, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        MapControl(std::nullptr_t) noexcept {}
        MapControl(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapControl(ptr, take_ownership_from_abi) {}
        MapControl();
        using llm::OS::UI::Xaml::Controls::Maps::IMapControl::FindMapElementsAtOffset;
        using impl::consume_t<MapControl, llm::OS::UI::Xaml::Controls::Maps::IMapControl5>::FindMapElementsAtOffset;
        using llm::OS::UI::Xaml::Controls::Maps::IMapControl::GetLocationFromOffset;
        using impl::consume_t<MapControl, llm::OS::UI::Xaml::Controls::Maps::IMapControl5>::GetLocationFromOffset;
        using llm::OS::UI::Xaml::Controls::Maps::IMapControl::Style;
        using impl::consume_t<MapControl, llm::OS::UI::Xaml::IFrameworkElement>::Style;
        [[nodiscard]] static auto CenterProperty();
        [[nodiscard]] static auto ChildrenProperty();
        [[nodiscard]] static auto ColorSchemeProperty();
        [[nodiscard]] static auto DesiredPitchProperty();
        [[nodiscard]] static auto HeadingProperty();
        [[nodiscard]] static auto LandmarksVisibleProperty();
        [[nodiscard]] static auto LoadingStatusProperty();
        [[nodiscard]] static auto MapServiceTokenProperty();
        [[nodiscard]] static auto PedestrianFeaturesVisibleProperty();
        [[nodiscard]] static auto PitchProperty();
        [[nodiscard]] static auto StyleProperty();
        [[nodiscard]] static auto TrafficFlowVisibleProperty();
        [[nodiscard]] static auto TransformOriginProperty();
        [[nodiscard]] static auto WatermarkModeProperty();
        [[nodiscard]] static auto ZoomLevelProperty();
        [[nodiscard]] static auto MapElementsProperty();
        [[nodiscard]] static auto RoutesProperty();
        [[nodiscard]] static auto TileSourcesProperty();
        [[nodiscard]] static auto LocationProperty();
        static auto GetLocation(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetLocation(llm::OS::UI::Xaml::DependencyObject const& element, llm::OS::Devices::Geolocation::Geopoint const& value);
        [[nodiscard]] static auto NormalizedAnchorPointProperty();
        static auto GetNormalizedAnchorPoint(llm::OS::UI::Xaml::DependencyObject const& element);
        static auto SetNormalizedAnchorPoint(llm::OS::UI::Xaml::DependencyObject const& element, llm::OS::Foundation::Point const& value);
        [[nodiscard]] static auto BusinessLandmarksVisibleProperty();
        [[nodiscard]] static auto TransitFeaturesVisibleProperty();
        [[nodiscard]] static auto PanInteractionModeProperty();
        [[nodiscard]] static auto RotateInteractionModeProperty();
        [[nodiscard]] static auto TiltInteractionModeProperty();
        [[nodiscard]] static auto ZoomInteractionModeProperty();
        [[nodiscard]] static auto Is3DSupportedProperty();
        [[nodiscard]] static auto IsStreetsideSupportedProperty();
        [[nodiscard]] static auto SceneProperty();
        [[nodiscard]] static auto BusinessLandmarksEnabledProperty();
        [[nodiscard]] static auto TransitFeaturesEnabledProperty();
        [[nodiscard]] static auto MapProjectionProperty();
        [[nodiscard]] static auto StyleSheetProperty();
        [[nodiscard]] static auto ViewPaddingProperty();
        [[nodiscard]] static auto LayersProperty();
        [[nodiscard]] static auto RegionProperty();
        [[nodiscard]] static auto CanTiltDownProperty();
        [[nodiscard]] static auto CanTiltUpProperty();
        [[nodiscard]] static auto CanZoomInProperty();
        [[nodiscard]] static auto CanZoomOutProperty();
    };
    struct __declspec(empty_bases) MapControlBusinessLandmarkClickEventArgs : llm::OS::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkClickEventArgs
    {
        MapControlBusinessLandmarkClickEventArgs(std::nullptr_t) noexcept {}
        MapControlBusinessLandmarkClickEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkClickEventArgs(ptr, take_ownership_from_abi) {}
        MapControlBusinessLandmarkClickEventArgs();
    };
    struct __declspec(empty_bases) MapControlBusinessLandmarkPointerEnteredEventArgs : llm::OS::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkPointerEnteredEventArgs
    {
        MapControlBusinessLandmarkPointerEnteredEventArgs(std::nullptr_t) noexcept {}
        MapControlBusinessLandmarkPointerEnteredEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkPointerEnteredEventArgs(ptr, take_ownership_from_abi) {}
        MapControlBusinessLandmarkPointerEnteredEventArgs();
    };
    struct __declspec(empty_bases) MapControlBusinessLandmarkPointerExitedEventArgs : llm::OS::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkPointerExitedEventArgs
    {
        MapControlBusinessLandmarkPointerExitedEventArgs(std::nullptr_t) noexcept {}
        MapControlBusinessLandmarkPointerExitedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkPointerExitedEventArgs(ptr, take_ownership_from_abi) {}
        MapControlBusinessLandmarkPointerExitedEventArgs();
    };
    struct __declspec(empty_bases) MapControlBusinessLandmarkRightTappedEventArgs : llm::OS::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkRightTappedEventArgs
    {
        MapControlBusinessLandmarkRightTappedEventArgs(std::nullptr_t) noexcept {}
        MapControlBusinessLandmarkRightTappedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkRightTappedEventArgs(ptr, take_ownership_from_abi) {}
        MapControlBusinessLandmarkRightTappedEventArgs();
    };
    struct __declspec(empty_bases) MapControlDataHelper : llm::OS::UI::Xaml::Controls::Maps::IMapControlDataHelper,
        impl::base<MapControlDataHelper, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<MapControlDataHelper, llm::OS::UI::Xaml::Controls::Maps::IMapControlDataHelper2, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        MapControlDataHelper(std::nullptr_t) noexcept {}
        MapControlDataHelper(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapControlDataHelper(ptr, take_ownership_from_abi) {}
        explicit MapControlDataHelper(llm::OS::UI::Xaml::Controls::Maps::MapControl const& map);
        static auto CreateMapControl(bool rasterRenderMode);
    };
    struct __declspec(empty_bases) MapControlTransitFeatureClickEventArgs : llm::OS::UI::Xaml::Controls::Maps::IMapControlTransitFeatureClickEventArgs
    {
        MapControlTransitFeatureClickEventArgs(std::nullptr_t) noexcept {}
        MapControlTransitFeatureClickEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapControlTransitFeatureClickEventArgs(ptr, take_ownership_from_abi) {}
        MapControlTransitFeatureClickEventArgs();
    };
    struct __declspec(empty_bases) MapControlTransitFeaturePointerEnteredEventArgs : llm::OS::UI::Xaml::Controls::Maps::IMapControlTransitFeaturePointerEnteredEventArgs
    {
        MapControlTransitFeaturePointerEnteredEventArgs(std::nullptr_t) noexcept {}
        MapControlTransitFeaturePointerEnteredEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapControlTransitFeaturePointerEnteredEventArgs(ptr, take_ownership_from_abi) {}
        MapControlTransitFeaturePointerEnteredEventArgs();
    };
    struct __declspec(empty_bases) MapControlTransitFeaturePointerExitedEventArgs : llm::OS::UI::Xaml::Controls::Maps::IMapControlTransitFeaturePointerExitedEventArgs
    {
        MapControlTransitFeaturePointerExitedEventArgs(std::nullptr_t) noexcept {}
        MapControlTransitFeaturePointerExitedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapControlTransitFeaturePointerExitedEventArgs(ptr, take_ownership_from_abi) {}
        MapControlTransitFeaturePointerExitedEventArgs();
    };
    struct __declspec(empty_bases) MapControlTransitFeatureRightTappedEventArgs : llm::OS::UI::Xaml::Controls::Maps::IMapControlTransitFeatureRightTappedEventArgs
    {
        MapControlTransitFeatureRightTappedEventArgs(std::nullptr_t) noexcept {}
        MapControlTransitFeatureRightTappedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapControlTransitFeatureRightTappedEventArgs(ptr, take_ownership_from_abi) {}
        MapControlTransitFeatureRightTappedEventArgs();
    };
    struct __declspec(empty_bases) MapCustomExperience : llm::OS::UI::Xaml::Controls::Maps::IMapCustomExperience,
        impl::base<MapCustomExperience, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<MapCustomExperience, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        MapCustomExperience(std::nullptr_t) noexcept {}
        MapCustomExperience(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapCustomExperience(ptr, take_ownership_from_abi) {}
        MapCustomExperience();
    };
    struct __declspec(empty_bases) MapCustomExperienceChangedEventArgs : llm::OS::UI::Xaml::Controls::Maps::IMapCustomExperienceChangedEventArgs
    {
        MapCustomExperienceChangedEventArgs(std::nullptr_t) noexcept {}
        MapCustomExperienceChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapCustomExperienceChangedEventArgs(ptr, take_ownership_from_abi) {}
        MapCustomExperienceChangedEventArgs();
    };
    struct __declspec(empty_bases) MapElement : llm::OS::UI::Xaml::Controls::Maps::IMapElement,
        impl::base<MapElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<MapElement, llm::OS::UI::Xaml::Controls::Maps::IMapElement2, llm::OS::UI::Xaml::Controls::Maps::IMapElement3, llm::OS::UI::Xaml::Controls::Maps::IMapElement4, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        MapElement(std::nullptr_t) noexcept {}
        MapElement(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapElement(ptr, take_ownership_from_abi) {}
        MapElement();
        [[nodiscard]] static auto ZIndexProperty();
        [[nodiscard]] static auto VisibleProperty();
        [[nodiscard]] static auto MapTabIndexProperty();
        [[nodiscard]] static auto MapStyleSheetEntryProperty();
        [[nodiscard]] static auto MapStyleSheetEntryStateProperty();
        [[nodiscard]] static auto TagProperty();
        [[nodiscard]] static auto IsEnabledProperty();
    };
    struct __declspec(empty_bases) MapElement3D : llm::OS::UI::Xaml::Controls::Maps::IMapElement3D,
        impl::base<MapElement3D, llm::OS::UI::Xaml::Controls::Maps::MapElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<MapElement3D, llm::OS::UI::Xaml::Controls::Maps::IMapElement, llm::OS::UI::Xaml::Controls::Maps::IMapElement2, llm::OS::UI::Xaml::Controls::Maps::IMapElement3, llm::OS::UI::Xaml::Controls::Maps::IMapElement4, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        MapElement3D(std::nullptr_t) noexcept {}
        MapElement3D(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapElement3D(ptr, take_ownership_from_abi) {}
        MapElement3D();
        [[nodiscard]] static auto LocationProperty();
        [[nodiscard]] static auto HeadingProperty();
        [[nodiscard]] static auto PitchProperty();
        [[nodiscard]] static auto RollProperty();
        [[nodiscard]] static auto ScaleProperty();
    };
    struct __declspec(empty_bases) MapElementClickEventArgs : llm::OS::UI::Xaml::Controls::Maps::IMapElementClickEventArgs
    {
        MapElementClickEventArgs(std::nullptr_t) noexcept {}
        MapElementClickEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapElementClickEventArgs(ptr, take_ownership_from_abi) {}
        MapElementClickEventArgs();
    };
    struct __declspec(empty_bases) MapElementPointerEnteredEventArgs : llm::OS::UI::Xaml::Controls::Maps::IMapElementPointerEnteredEventArgs
    {
        MapElementPointerEnteredEventArgs(std::nullptr_t) noexcept {}
        MapElementPointerEnteredEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapElementPointerEnteredEventArgs(ptr, take_ownership_from_abi) {}
        MapElementPointerEnteredEventArgs();
    };
    struct __declspec(empty_bases) MapElementPointerExitedEventArgs : llm::OS::UI::Xaml::Controls::Maps::IMapElementPointerExitedEventArgs
    {
        MapElementPointerExitedEventArgs(std::nullptr_t) noexcept {}
        MapElementPointerExitedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapElementPointerExitedEventArgs(ptr, take_ownership_from_abi) {}
        MapElementPointerExitedEventArgs();
    };
    struct __declspec(empty_bases) MapElementsLayer : llm::OS::UI::Xaml::Controls::Maps::IMapElementsLayer,
        impl::base<MapElementsLayer, llm::OS::UI::Xaml::Controls::Maps::MapLayer, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<MapElementsLayer, llm::OS::UI::Xaml::Controls::Maps::IMapLayer, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        MapElementsLayer(std::nullptr_t) noexcept {}
        MapElementsLayer(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapElementsLayer(ptr, take_ownership_from_abi) {}
        MapElementsLayer();
        [[nodiscard]] static auto MapElementsProperty();
    };
    struct __declspec(empty_bases) MapElementsLayerClickEventArgs : llm::OS::UI::Xaml::Controls::Maps::IMapElementsLayerClickEventArgs
    {
        MapElementsLayerClickEventArgs(std::nullptr_t) noexcept {}
        MapElementsLayerClickEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapElementsLayerClickEventArgs(ptr, take_ownership_from_abi) {}
        MapElementsLayerClickEventArgs();
    };
    struct __declspec(empty_bases) MapElementsLayerContextRequestedEventArgs : llm::OS::UI::Xaml::Controls::Maps::IMapElementsLayerContextRequestedEventArgs
    {
        MapElementsLayerContextRequestedEventArgs(std::nullptr_t) noexcept {}
        MapElementsLayerContextRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapElementsLayerContextRequestedEventArgs(ptr, take_ownership_from_abi) {}
        MapElementsLayerContextRequestedEventArgs();
    };
    struct __declspec(empty_bases) MapElementsLayerPointerEnteredEventArgs : llm::OS::UI::Xaml::Controls::Maps::IMapElementsLayerPointerEnteredEventArgs
    {
        MapElementsLayerPointerEnteredEventArgs(std::nullptr_t) noexcept {}
        MapElementsLayerPointerEnteredEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapElementsLayerPointerEnteredEventArgs(ptr, take_ownership_from_abi) {}
        MapElementsLayerPointerEnteredEventArgs();
    };
    struct __declspec(empty_bases) MapElementsLayerPointerExitedEventArgs : llm::OS::UI::Xaml::Controls::Maps::IMapElementsLayerPointerExitedEventArgs
    {
        MapElementsLayerPointerExitedEventArgs(std::nullptr_t) noexcept {}
        MapElementsLayerPointerExitedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapElementsLayerPointerExitedEventArgs(ptr, take_ownership_from_abi) {}
        MapElementsLayerPointerExitedEventArgs();
    };
    struct __declspec(empty_bases) MapIcon : llm::OS::UI::Xaml::Controls::Maps::IMapIcon,
        impl::base<MapIcon, llm::OS::UI::Xaml::Controls::Maps::MapElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<MapIcon, llm::OS::UI::Xaml::Controls::Maps::IMapIcon2, llm::OS::UI::Xaml::Controls::Maps::IMapElement, llm::OS::UI::Xaml::Controls::Maps::IMapElement2, llm::OS::UI::Xaml::Controls::Maps::IMapElement3, llm::OS::UI::Xaml::Controls::Maps::IMapElement4, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        MapIcon(std::nullptr_t) noexcept {}
        MapIcon(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapIcon(ptr, take_ownership_from_abi) {}
        MapIcon();
        [[nodiscard]] static auto LocationProperty();
        [[nodiscard]] static auto TitleProperty();
        [[nodiscard]] static auto NormalizedAnchorPointProperty();
        [[nodiscard]] static auto CollisionBehaviorDesiredProperty();
    };
    struct __declspec(empty_bases) MapInputEventArgs : llm::OS::UI::Xaml::Controls::Maps::IMapInputEventArgs,
        impl::base<MapInputEventArgs, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<MapInputEventArgs, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        MapInputEventArgs(std::nullptr_t) noexcept {}
        MapInputEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapInputEventArgs(ptr, take_ownership_from_abi) {}
        MapInputEventArgs();
    };
    struct __declspec(empty_bases) MapItemsControl : llm::OS::UI::Xaml::Controls::Maps::IMapItemsControl,
        impl::base<MapItemsControl, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<MapItemsControl, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        MapItemsControl(std::nullptr_t) noexcept {}
        MapItemsControl(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapItemsControl(ptr, take_ownership_from_abi) {}
        MapItemsControl();
        [[nodiscard]] static auto ItemsSourceProperty();
        [[nodiscard]] static auto ItemsProperty();
        [[nodiscard]] static auto ItemTemplateProperty();
    };
    struct __declspec(empty_bases) MapLayer : llm::OS::UI::Xaml::Controls::Maps::IMapLayer,
        impl::base<MapLayer, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<MapLayer, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        MapLayer(std::nullptr_t) noexcept {}
        MapLayer(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapLayer(ptr, take_ownership_from_abi) {}
        MapLayer();
        [[nodiscard]] static auto MapTabIndexProperty();
        [[nodiscard]] static auto VisibleProperty();
        [[nodiscard]] static auto ZIndexProperty();
    };
    struct __declspec(empty_bases) MapModel3D : llm::OS::UI::Xaml::Controls::Maps::IMapModel3D,
        impl::base<MapModel3D, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<MapModel3D, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        MapModel3D(std::nullptr_t) noexcept {}
        MapModel3D(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapModel3D(ptr, take_ownership_from_abi) {}
        MapModel3D();
        static auto CreateFrom3MFAsync(llm::OS::Storage::Streams::IRandomAccessStreamReference const& source);
        static auto CreateFrom3MFAsync(llm::OS::Storage::Streams::IRandomAccessStreamReference const& source, llm::OS::UI::Xaml::Controls::Maps::MapModel3DShadingOption const& shadingOption);
    };
    struct __declspec(empty_bases) MapPolygon : llm::OS::UI::Xaml::Controls::Maps::IMapPolygon,
        impl::base<MapPolygon, llm::OS::UI::Xaml::Controls::Maps::MapElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<MapPolygon, llm::OS::UI::Xaml::Controls::Maps::IMapPolygon2, llm::OS::UI::Xaml::Controls::Maps::IMapElement, llm::OS::UI::Xaml::Controls::Maps::IMapElement2, llm::OS::UI::Xaml::Controls::Maps::IMapElement3, llm::OS::UI::Xaml::Controls::Maps::IMapElement4, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        MapPolygon(std::nullptr_t) noexcept {}
        MapPolygon(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapPolygon(ptr, take_ownership_from_abi) {}
        MapPolygon();
        [[nodiscard]] static auto PathProperty();
        [[nodiscard]] static auto StrokeThicknessProperty();
        [[nodiscard]] static auto StrokeDashedProperty();
    };
    struct __declspec(empty_bases) MapPolyline : llm::OS::UI::Xaml::Controls::Maps::IMapPolyline,
        impl::base<MapPolyline, llm::OS::UI::Xaml::Controls::Maps::MapElement, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<MapPolyline, llm::OS::UI::Xaml::Controls::Maps::IMapElement, llm::OS::UI::Xaml::Controls::Maps::IMapElement2, llm::OS::UI::Xaml::Controls::Maps::IMapElement3, llm::OS::UI::Xaml::Controls::Maps::IMapElement4, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        MapPolyline(std::nullptr_t) noexcept {}
        MapPolyline(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapPolyline(ptr, take_ownership_from_abi) {}
        MapPolyline();
        [[nodiscard]] static auto PathProperty();
        [[nodiscard]] static auto StrokeDashedProperty();
    };
    struct __declspec(empty_bases) MapRightTappedEventArgs : llm::OS::UI::Xaml::Controls::Maps::IMapRightTappedEventArgs
    {
        MapRightTappedEventArgs(std::nullptr_t) noexcept {}
        MapRightTappedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapRightTappedEventArgs(ptr, take_ownership_from_abi) {}
        MapRightTappedEventArgs();
    };
    struct __declspec(empty_bases) MapRouteView : llm::OS::UI::Xaml::Controls::Maps::IMapRouteView,
        impl::base<MapRouteView, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<MapRouteView, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        MapRouteView(std::nullptr_t) noexcept {}
        MapRouteView(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapRouteView(ptr, take_ownership_from_abi) {}
        explicit MapRouteView(llm::OS::Services::Maps::MapRoute const& route);
    };
    struct __declspec(empty_bases) MapScene : llm::OS::UI::Xaml::Controls::Maps::IMapScene,
        impl::base<MapScene, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<MapScene, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        MapScene(std::nullptr_t) noexcept {}
        MapScene(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapScene(ptr, take_ownership_from_abi) {}
        static auto CreateFromBoundingBox(llm::OS::Devices::Geolocation::GeoboundingBox const& bounds);
        static auto CreateFromBoundingBox(llm::OS::Devices::Geolocation::GeoboundingBox const& bounds, double headingInDegrees, double pitchInDegrees);
        static auto CreateFromCamera(llm::OS::UI::Xaml::Controls::Maps::MapCamera const& camera);
        static auto CreateFromLocation(llm::OS::Devices::Geolocation::Geopoint const& location);
        static auto CreateFromLocation(llm::OS::Devices::Geolocation::Geopoint const& location, double headingInDegrees, double pitchInDegrees);
        static auto CreateFromLocationAndRadius(llm::OS::Devices::Geolocation::Geopoint const& location, double radiusInMeters);
        static auto CreateFromLocationAndRadius(llm::OS::Devices::Geolocation::Geopoint const& location, double radiusInMeters, double headingInDegrees, double pitchInDegrees);
        static auto CreateFromLocations(param::iterable<llm::OS::Devices::Geolocation::Geopoint> const& locations);
        static auto CreateFromLocations(param::iterable<llm::OS::Devices::Geolocation::Geopoint> const& locations, double headingInDegrees, double pitchInDegrees);
    };
    struct __declspec(empty_bases) MapStyleSheet : llm::OS::UI::Xaml::Controls::Maps::IMapStyleSheet,
        impl::base<MapStyleSheet, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<MapStyleSheet, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        MapStyleSheet(std::nullptr_t) noexcept {}
        MapStyleSheet(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapStyleSheet(ptr, take_ownership_from_abi) {}
        static auto Aerial();
        static auto AerialWithOverlay();
        static auto RoadLight();
        static auto RoadDark();
        static auto RoadHighContrastLight();
        static auto RoadHighContrastDark();
        static auto Combine(param::iterable<llm::OS::UI::Xaml::Controls::Maps::MapStyleSheet> const& styleSheets);
        static auto ParseFromJson(param::hstring const& styleAsJson);
        static auto TryParseFromJson(param::hstring const& styleAsJson, llm::OS::UI::Xaml::Controls::Maps::MapStyleSheet& styleSheet);
    };
    struct MapStyleSheetEntries
    {
        MapStyleSheetEntries() = delete;
        [[nodiscard]] static auto Area();
        [[nodiscard]] static auto Airport();
        [[nodiscard]] static auto Cemetery();
        [[nodiscard]] static auto Continent();
        [[nodiscard]] static auto Education();
        [[nodiscard]] static auto IndigenousPeoplesReserve();
        [[nodiscard]] static auto Island();
        [[nodiscard]] static auto Medical();
        [[nodiscard]] static auto Military();
        [[nodiscard]] static auto Nautical();
        [[nodiscard]] static auto Neighborhood();
        [[nodiscard]] static auto Runway();
        [[nodiscard]] static auto Sand();
        [[nodiscard]] static auto ShoppingCenter();
        [[nodiscard]] static auto Stadium();
        [[nodiscard]] static auto Vegetation();
        [[nodiscard]] static auto Forest();
        [[nodiscard]] static auto GolfCourse();
        [[nodiscard]] static auto Park();
        [[nodiscard]] static auto PlayingField();
        [[nodiscard]] static auto Reserve();
        [[nodiscard]] static auto Point();
        [[nodiscard]] static auto NaturalPoint();
        [[nodiscard]] static auto Peak();
        [[nodiscard]] static auto VolcanicPeak();
        [[nodiscard]] static auto WaterPoint();
        [[nodiscard]] static auto PointOfInterest();
        [[nodiscard]] static auto Business();
        [[nodiscard]] static auto FoodPoint();
        [[nodiscard]] static auto PopulatedPlace();
        [[nodiscard]] static auto Capital();
        [[nodiscard]] static auto AdminDistrictCapital();
        [[nodiscard]] static auto CountryRegionCapital();
        [[nodiscard]] static auto RoadShield();
        [[nodiscard]] static auto RoadExit();
        [[nodiscard]] static auto Transit();
        [[nodiscard]] static auto Political();
        [[nodiscard]] static auto CountryRegion();
        [[nodiscard]] static auto AdminDistrict();
        [[nodiscard]] static auto District();
        [[nodiscard]] static auto Structure();
        [[nodiscard]] static auto Building();
        [[nodiscard]] static auto EducationBuilding();
        [[nodiscard]] static auto MedicalBuilding();
        [[nodiscard]] static auto TransitBuilding();
        [[nodiscard]] static auto Transportation();
        [[nodiscard]] static auto Road();
        [[nodiscard]] static auto ControlledAccessHighway();
        [[nodiscard]] static auto HighSpeedRamp();
        [[nodiscard]] static auto Highway();
        [[nodiscard]] static auto MajorRoad();
        [[nodiscard]] static auto ArterialRoad();
        [[nodiscard]] static auto Street();
        [[nodiscard]] static auto Ramp();
        [[nodiscard]] static auto UnpavedStreet();
        [[nodiscard]] static auto TollRoad();
        [[nodiscard]] static auto Railway();
        [[nodiscard]] static auto Trail();
        [[nodiscard]] static auto WaterRoute();
        [[nodiscard]] static auto Water();
        [[nodiscard]] static auto River();
        [[nodiscard]] static auto RouteLine();
        [[nodiscard]] static auto WalkingRoute();
        [[nodiscard]] static auto DrivingRoute();
    };
    struct MapStyleSheetEntryStates
    {
        MapStyleSheetEntryStates() = delete;
        [[nodiscard]] static auto Disabled();
        [[nodiscard]] static auto Hover();
        [[nodiscard]] static auto Selected();
    };
    struct __declspec(empty_bases) MapTargetCameraChangedEventArgs : llm::OS::UI::Xaml::Controls::Maps::IMapTargetCameraChangedEventArgs,
        impl::require<MapTargetCameraChangedEventArgs, llm::OS::UI::Xaml::Controls::Maps::IMapTargetCameraChangedEventArgs2>
    {
        MapTargetCameraChangedEventArgs(std::nullptr_t) noexcept {}
        MapTargetCameraChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapTargetCameraChangedEventArgs(ptr, take_ownership_from_abi) {}
        MapTargetCameraChangedEventArgs();
    };
    struct __declspec(empty_bases) MapTileBitmapRequest : llm::OS::UI::Xaml::Controls::Maps::IMapTileBitmapRequest
    {
        MapTileBitmapRequest(std::nullptr_t) noexcept {}
        MapTileBitmapRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapTileBitmapRequest(ptr, take_ownership_from_abi) {}
        MapTileBitmapRequest();
    };
    struct __declspec(empty_bases) MapTileBitmapRequestDeferral : llm::OS::UI::Xaml::Controls::Maps::IMapTileBitmapRequestDeferral
    {
        MapTileBitmapRequestDeferral(std::nullptr_t) noexcept {}
        MapTileBitmapRequestDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapTileBitmapRequestDeferral(ptr, take_ownership_from_abi) {}
        MapTileBitmapRequestDeferral();
    };
    struct __declspec(empty_bases) MapTileBitmapRequestedEventArgs : llm::OS::UI::Xaml::Controls::Maps::IMapTileBitmapRequestedEventArgs,
        impl::require<MapTileBitmapRequestedEventArgs, llm::OS::UI::Xaml::Controls::Maps::IMapTileBitmapRequestedEventArgs2>
    {
        MapTileBitmapRequestedEventArgs(std::nullptr_t) noexcept {}
        MapTileBitmapRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapTileBitmapRequestedEventArgs(ptr, take_ownership_from_abi) {}
        MapTileBitmapRequestedEventArgs();
    };
    struct __declspec(empty_bases) MapTileDataSource : llm::OS::UI::Xaml::Controls::Maps::IMapTileDataSource,
        impl::base<MapTileDataSource, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<MapTileDataSource, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        MapTileDataSource(std::nullptr_t) noexcept {}
        MapTileDataSource(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapTileDataSource(ptr, take_ownership_from_abi) {}
        MapTileDataSource();
    };
    struct __declspec(empty_bases) MapTileSource : llm::OS::UI::Xaml::Controls::Maps::IMapTileSource,
        impl::base<MapTileSource, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<MapTileSource, llm::OS::UI::Xaml::Controls::Maps::IMapTileSource2, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        MapTileSource(std::nullptr_t) noexcept {}
        MapTileSource(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapTileSource(ptr, take_ownership_from_abi) {}
        MapTileSource();
        explicit MapTileSource(llm::OS::UI::Xaml::Controls::Maps::MapTileDataSource const& dataSource);
        MapTileSource(llm::OS::UI::Xaml::Controls::Maps::MapTileDataSource const& dataSource, llm::OS::UI::Xaml::Controls::Maps::MapZoomLevelRange const& zoomLevelRange);
        MapTileSource(llm::OS::UI::Xaml::Controls::Maps::MapTileDataSource const& dataSource, llm::OS::UI::Xaml::Controls::Maps::MapZoomLevelRange const& zoomLevelRange, llm::OS::Devices::Geolocation::GeoboundingBox const& bounds);
        MapTileSource(llm::OS::UI::Xaml::Controls::Maps::MapTileDataSource const& dataSource, llm::OS::UI::Xaml::Controls::Maps::MapZoomLevelRange const& zoomLevelRange, llm::OS::Devices::Geolocation::GeoboundingBox const& bounds, int32_t tileSizeInPixels);
        [[nodiscard]] static auto DataSourceProperty();
        [[nodiscard]] static auto LayerProperty();
        [[nodiscard]] static auto ZoomLevelRangeProperty();
        [[nodiscard]] static auto BoundsProperty();
        [[nodiscard]] static auto AllowOverstretchProperty();
        [[nodiscard]] static auto IsFadingEnabledProperty();
        [[nodiscard]] static auto IsTransparencyEnabledProperty();
        [[nodiscard]] static auto IsRetryEnabledProperty();
        [[nodiscard]] static auto ZIndexProperty();
        [[nodiscard]] static auto TilePixelSizeProperty();
        [[nodiscard]] static auto VisibleProperty();
        [[nodiscard]] static auto AnimationStateProperty();
        [[nodiscard]] static auto AutoPlayProperty();
        [[nodiscard]] static auto FrameCountProperty();
        [[nodiscard]] static auto FrameDurationProperty();
    };
    struct __declspec(empty_bases) MapTileUriRequest : llm::OS::UI::Xaml::Controls::Maps::IMapTileUriRequest
    {
        MapTileUriRequest(std::nullptr_t) noexcept {}
        MapTileUriRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapTileUriRequest(ptr, take_ownership_from_abi) {}
        MapTileUriRequest();
    };
    struct __declspec(empty_bases) MapTileUriRequestDeferral : llm::OS::UI::Xaml::Controls::Maps::IMapTileUriRequestDeferral
    {
        MapTileUriRequestDeferral(std::nullptr_t) noexcept {}
        MapTileUriRequestDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapTileUriRequestDeferral(ptr, take_ownership_from_abi) {}
        MapTileUriRequestDeferral();
    };
    struct __declspec(empty_bases) MapTileUriRequestedEventArgs : llm::OS::UI::Xaml::Controls::Maps::IMapTileUriRequestedEventArgs,
        impl::require<MapTileUriRequestedEventArgs, llm::OS::UI::Xaml::Controls::Maps::IMapTileUriRequestedEventArgs2>
    {
        MapTileUriRequestedEventArgs(std::nullptr_t) noexcept {}
        MapTileUriRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IMapTileUriRequestedEventArgs(ptr, take_ownership_from_abi) {}
        MapTileUriRequestedEventArgs();
    };
    struct __declspec(empty_bases) StreetsideExperience : llm::OS::UI::Xaml::Controls::Maps::IStreetsideExperience,
        impl::base<StreetsideExperience, llm::OS::UI::Xaml::Controls::Maps::MapCustomExperience, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<StreetsideExperience, llm::OS::UI::Xaml::Controls::Maps::IMapCustomExperience, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        StreetsideExperience(std::nullptr_t) noexcept {}
        StreetsideExperience(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IStreetsideExperience(ptr, take_ownership_from_abi) {}
        explicit StreetsideExperience(llm::OS::UI::Xaml::Controls::Maps::StreetsidePanorama const& panorama);
        StreetsideExperience(llm::OS::UI::Xaml::Controls::Maps::StreetsidePanorama const& panorama, double headingInDegrees, double pitchInDegrees, double fieldOfViewInDegrees);
    };
    struct __declspec(empty_bases) StreetsidePanorama : llm::OS::UI::Xaml::Controls::Maps::IStreetsidePanorama,
        impl::base<StreetsidePanorama, llm::OS::UI::Xaml::DependencyObject>,
        impl::require<StreetsidePanorama, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>
    {
        StreetsidePanorama(std::nullptr_t) noexcept {}
        StreetsidePanorama(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Controls::Maps::IStreetsidePanorama(ptr, take_ownership_from_abi) {}
        static auto FindNearbyAsync(llm::OS::Devices::Geolocation::Geopoint const& location);
        static auto FindNearbyAsync(llm::OS::Devices::Geolocation::Geopoint const& location, double radiusInMeters);
    };
}
#endif
