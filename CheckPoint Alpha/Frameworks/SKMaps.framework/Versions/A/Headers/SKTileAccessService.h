//
//  SKTileAccessService.h
//  SKMaps
//  Copyright (c) 2013 Skobbler. All rights reserved.


#import "SKMaps/SKDefinitions.h"

@class SKTileAccessService;
@class SKBoundingBox;
/**
 SKTileAccesssServiceDelegate provides a notifications regarding downloaded tiles.
 */
@protocol SKTileAccesssServiceDelegate <NSObject>

/**
 Called when a tile is newly downloaded.
 @param tileAccessService Sender SKTileAccessService reference.
 @param identifier The ID of the tile.
 @param type The tileType of the tile, defined in SKDefinitions.
 @param version The versionNumber of the tile.
 */
-(void)tileAccessService: (SKTileAccessService*)tileAccessService didRecieveTileWithID:(int)identifier type:(SKTileType)type version:(int)version;

@end

/**
 SKTileAccessService provides advanced access to specific map tiles. Used for sending tiles to external devices or other features.
 */
@interface SKTileAccessService : NSObject

/**
 SKTileAccessService's delegate, providing downloaded tiles callbacks.
 */
@property(nonatomic,weak)id<SKTileAccesssServiceDelegate> delegate;

/**Retrieves the tile with a specified ID and operation.
 @param tileID The ID of the tyle.
 @param tileType The type of the tyle.
 @param operationType The operation type.
 @param tileData NSData that will be populated with raw tile data.
 @return The path to the requested map tile.
 */
-(NSString *)tilePathForTileWithID:(int)tileID type:(SKTileType)tileType operationType:(SKOperationType)operationType tileData:(NSData**)tileData;

/**Retrieves tiles of a specified type ( or types, using masks ) from a given bounding box.
 @param tileType The type of the tyles that are retrieved.
 @param operationType The operation type.
 @param boundingBox The boundingBox in which the tiles are retrieved.
 @return The path to the map tiles of the specific type that are in a given bounding box
 */
-(NSArray *)tilePathsForTilesWithType:(SKTileType)tileType operationType:(SKOperationType)operationType boundingBox:(SKBoundingBox *)boundingBox;
@end
