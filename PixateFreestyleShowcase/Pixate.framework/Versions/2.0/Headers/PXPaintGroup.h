//
//  PXPaintGroup.h
//  Pixate
//
//  Created by Kevin Lindsey on 7/2/12.
//  Copyright (c) 2012 Pixate, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PXPaint.h"

/**
 *  A PXPaintGroup allows a collection of PXPaints to be treated as a single fill. This can reduce the number of
 *  contours required when filling the same region. This class is particularly useful when overlapping fills use alpha
 *  and/or blend modes
 */
@interface PXPaintGroup : NSObject <PXPaint>

@property (nonatomic, readonly) NSArray *paints;

/**
 *  Initialize a newly allocated paint group, adding the specified list of paints
 */
- (id)initWithPaints:(NSArray *)paints;

/**
 *  Add the specified paint to this group of paints
 *
 *  @param paint The paint to add
 */
- (void)addPaint:(id<PXPaint>)paint;

@end
