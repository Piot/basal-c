/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <basal/basal_vector3.h>

bl_vector3 bl_vector3_make(float x, float y, float z)
{
    bl_vector3 point;

    point.x = x;
    point.y = y;
    point.z = z;

    return point;
}
