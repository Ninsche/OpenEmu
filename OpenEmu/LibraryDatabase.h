//
//  LibraryDatabase.h
//  OpenEmuMockup
//
//  Created by Christoph Leimbrock on 31.03.11.
//  Copyright 2011 none. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface LibraryDatabase : NSObject {
@private	
    NSArrayController* romsController;
    
    NSPersistentStoreCoordinator *__persistentStoreCoordinator;
    NSManagedObjectModel *__managedObjectModel;
    NSManagedObjectContext *__managedObjectContext;
    
    NSURL* __databaseURL;
}

- (BOOL)save:(NSError**)error;
#pragma mark -
#pragma mark Database queries
- (NSArray*)systems;
- (NSInteger)systemsCount;

- (NSUInteger)collectionsCount;
- (NSArray*)collections;

- (NSArray*)romsForPredicate:(NSPredicate*)predicate;
- (NSArray*)romsInCollection:(id)collection;
#pragma mark -
#pragma mark Database Collection editing
- (void)removeCollection:(NSManagedObject*)collection;

- (id)addNewCollection:(NSString*)name;
- (id)addNewSmartCollection:(NSString*)name;
- (id)addNewCollectionFolder:(NSString*)name;

#pragma mark -
#pragma mark Database Game editing
- (void)addGamesFromPath:(NSString*)path toCollection:(NSManagedObject*)collection searchSubfolders:(BOOL)subfolderFlag;
/*
- (void)addRomsWithFiles:(NSArray*)files;
- (void)addRomWithFile:(NSString*)file;

- (void)deleteRomWithID:(id)romID;
- (void)deleteRomsWithIDs:(NSArray*)romIDs;

- (void)updateRom:(id)newValues;
- (void)updateRoms:(NSArray*)newValues;

#pragma mark -
#pragma mark Basic Collection Handling
- (void)addRom:(id)rom toCollection:(id)collection;
- (void)removeRom:(id)rom fromCollection:(id)collection;
- (void)moveRomAtIndex:(id)index toIndex:(id)newIndex;

#pragma mark -
#pragma mark Smart Collection Handling
- (void)addRule:(id)rule toCollection:(id)collection;
- (void)removeRule:(id)rule fromCollection:(id)collection;
*/

@end
