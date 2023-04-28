/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef bl_circle_h
#define bl_circle_h

#include <basal/basal_size2.h>
#include <basal/basal_size2i.h>
#include <stdbool.h>

#include <basal/vector2.h>

typedef struct BlCircle {
    BlVector2 center;
    float radius;
} BlCircle;

bool blCircleOverlap(BlCircle a, BlCircle b);

#endif
