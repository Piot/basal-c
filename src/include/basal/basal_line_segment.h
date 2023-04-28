/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef blLineSegmenth
#define blLineSegmenth

#include <basal/basal_size2.h>
#include <basal/basal_size2i.h>
#include <stdbool.h>

#include <basal/circle.h>
#include <basal/vector2.h>

#include <basal/collision.h>

typedef struct BlLineSegment {
    BlVector2 a;
    BlVector2 b;
} BlLineSegment;


BlVector2 blLineSegmentClosestPoint(const BlLineSegment segment, const BlVector2 query);


BlCollision blLineSegmentCircleIntersect(const BlLineSegment segment, const BlCircle circle);

#endif
