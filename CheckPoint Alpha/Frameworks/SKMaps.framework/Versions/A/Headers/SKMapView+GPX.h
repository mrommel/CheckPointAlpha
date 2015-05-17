//
//  SKMapView+GPX.h
//  SKMaps
//
//  Copyright (c) 2013 Skobbler. All rights reserved.
//

#import "SKMaps/SKMapView.h"
#import "SKDefinitions.h"

@class SKGPXDataComponent;

/**
 */
@interface SKMapView(GPX)

#pragma mark - Loading

/** Loads and parses a GPS data file ( GPX or KML ).
 @param filePath The path to the file.
 @param fileType The type of the file (SKGPXFileType or SKKMLFileType).
 @return Success/Failure of loading the GPS data file.
 */
- (BOOL)loadGPSDataFileAtPath:(NSString *)filePath withType:(GPSDataFileType)fileType;

/** Unloads current GPS Data loaded file.
 */
- (void)unloadCurrentGPSDataFile;

/** Returns the GPX components from the loaded GPX file.
 @param gpxDataComponentType The type of the GPX components to be returned.
 @return An array of SKGPXDataComponent objects.
 */
- (NSArray *)dataComponentsFromLoadedFileWithType:(SKGPXComponentType)gpxDataComponentType;

#pragma mark - Drawing

/** If the current loaded file contains multiple tracks, this method is used to set the main one.
 @param gpxDataComponent The GPX component that will be set as main track.
 */
- (BOOL)setMainGPXDataComponent:(SKGPXDataComponent *)gpxDataComponent;

/** Renders on the map a GPX component from the current loaded GPS data file.
 @param gpxDataComponent The GPX component that will be rendered.
 */
- (BOOL)drawGPXDataComponent:(SKGPXDataComponent *)gpxDataComponent;

/** Renders on the map all the GPX components given from the current loaded GPS data file.
 @param gpxDataComponents The array of GPX components that will be rendered.
 */
- (BOOL)drawGPXDataComponents:(NSArray *)gpxDataComponents;

/**Returns an array with the coordinates of the specified GPX component from the current loaded GPS data file.
 @param gpxDataComponent The gpx component for required locations.
 @return An array of CLLocation objects.
 */
- (NSArray*)locationsForGPXDataComponent:(SKGPXDataComponent *)gpxDataComponent;

/**drawTrackWithCoordinates: draws a track with the coordinates in array adn with a given type and name. The GPX component must be given by the client with the preferred name and type.
 @param trackPoints An array with CLLocation objects.
 @param gpxDataComponent The data component for the given points.
 */
- (void)drawTrackWithCoordinates:(NSArray *)trackPoints andGPXDataComponent:(SKGPXDataComponent *)gpxDataComponent;

#pragma mark - Editing

/**Renames the given GPX component with the new name.
 @param gpxComponent The gpx component for editing.
 @param newName The string which represents the new name.
 @return YES is renaming was successful, NO otherwise.
 */
- (BOOL)renameComponent:(SKGPXDataComponent *)gpxComponent withNewName:(NSString *)newName;

/**Deletes the given GPX component from the file.
 @param gpxComponent The gpx component for deletion.
 @return YES is deletion was successful, NO otherwise.
 */
- (BOOL)deleteComponent:(SKGPXDataComponent *)gpxComponent;

@end
