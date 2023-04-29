/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef blVector3h
#define blVector3h

#include <stdbool.h>

typedef struct BlVector3 {
    float x;
    float y;
    float z;
} BlVector3;

typedef struct bl_vector3i {
    int x;
    int y;
    int z;
} bl_vector3i;

BlVector3 blVector3Make(float x, float y, float z);

#endif
