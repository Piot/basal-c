/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef BL_QUATERNION_H
#define BL_QUATERNION_H

#include <basal/vector3.h>

typedef struct BlQuaternion {
    BlVector3 v;
    float w;
} BlQuaternion;

void blQuaternionFromEuler(BlQuaternion* q, float roll, float pitch, float yaw);
void blQuaternionToEuler(BlQuaternion* q, float* roll, float* pitch, float* yaw);

#endif
