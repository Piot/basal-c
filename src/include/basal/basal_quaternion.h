/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef bl_quaternion_h
#define bl_quaternion_h

#include <basal/basal_vector3.h>

typedef struct bl_quaternion {
    bl_vector3 v;
    float w;
} bl_quaternion;

void bl_quaternion_from_euler(bl_quaternion* q, float roll, float pitch, float yaw);
void bl_quaternion_to_euler(bl_quaternion* q, float* roll, float* pitch, float* yaw);

#endif
