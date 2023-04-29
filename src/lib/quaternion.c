/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <basal/math.h>
#include <basal/quaternion.h>

static void blQuaternionNormalize(BlQuaternion* q)
{
    float scale = blSqrt(q->v.x * q->v.x + q->v.y * q->v.y + q->v.z * q->v.z + q->w * q->w);

    if (blFabs(scale) < 0.0001f) {
        return;
    }
    q->v.x /= scale;
    q->v.y /= scale;
    q->v.z /= scale;
    q->w /= scale;
}

void blQuaternionFromEuler(BlQuaternion* q, float z, float x, float y)
{
    float half_x = x / 2.0f;
    float half_y = y / 2.0f;
    float half_z = z / 2.0f;

    float sin_x = blSin(half_x);
    float sin_y = blSin(half_y);
    float sin_z = blSin(half_z);

    float cos_x = blCos(half_x);
    float cos_y = blCos(half_y);
    float cos_z = blCos(half_z);

    q->w = cos_x * cos_y * cos_z - sin_x * sin_y * sin_z;
    q->v.x = sin_x * sin_y * cos_z + cos_x * cos_y * sin_z;
    q->v.y = sin_x * cos_y * cos_z + cos_x * sin_y * sin_z;
    q->v.z = cos_x * sin_y * cos_z - sin_x * cos_y * sin_z;

    blQuaternionNormalize(q);
}

void blQuaternionToEuler(BlQuaternion* q, float* roll, float* pitch, float* yaw)
{
    float sqz = q->v.z * q->v.z;
    float sqw = q->w * q->w;
    float sqy = q->v.y * q->v.y;

    *yaw = blAtan2(2.0f * q->v.x * q->w + 2.0f * q->v.y * q->v.z, 1.0f - 2.0f * (sqz + sqw));
    *pitch = blAsin(2.0f * (q->v.x * q->v.z - q->w * q->v.y));
    *roll = blAtan2(2.0f * q->v.x * q->v.y + 2.0f * q->v.z * q->w, 1.0f - 2.0f * (sqy + sqz));
}
