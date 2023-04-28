/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef BASAL_COLLISION_H
#define BASAL_COLLISION_H

#include <basal/vector2.h>

typedef struct BlCollision {
    float depth;
    BlVector2 normal;
    BlVector2 point;
} BlCollision;

#endif
