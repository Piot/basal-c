/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef BL_CIRCLE_H
#define BL_CIRCLE_H

#include <basal/size2.h>
#include <basal/size2i.h>
#include <basal/vector2.h>
#include <stdbool.h>

typedef struct BlCircle {
    BlVector2 center;
    float radius;
} BlCircle;

bool blCircleOverlap(BlCircle a, BlCircle b);

#endif
