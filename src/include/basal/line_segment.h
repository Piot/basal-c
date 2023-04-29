/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef BL_LINE_SEGMENT_H
#define BL_LINE_SEGMENT_H

#include <basal/circle.h>
#include <basal/collision.h>
#include <basal/size2.h>
#include <basal/size2i.h>
#include <basal/vector2.h>
#include <stdbool.h>

typedef struct BlLineSegment {
    BlVector2 a;
    BlVector2 b;
} BlLineSegment;

BlVector2 blLineSegmentClosestPoint(const BlLineSegment segment, const BlVector2 query);
BlCollision blLineSegmentCircleIntersect(const BlLineSegment segment, const BlCircle circle);

#endif
