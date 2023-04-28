/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef bl_vector3_h
#define bl_vector3_h

#include <stdbool.h>

typedef struct bl_vector3 {
    float x;
    float y;
    float z;
} bl_vector3;

typedef struct bl_vector3i {
    int x;
    int y;
    int z;
} bl_vector3i;

bl_vector3 bl_vector3_make(float x, float y, float z);

#endif
