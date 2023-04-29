/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <basal/vector3.h>

BlVector3 blVector3Make(float x, float y, float z)
{
    BlVector3 point;

    point.x = x;
    point.y = y;
    point.z = z;

    return point;
}
