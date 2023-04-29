/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <basal/circle.h>

bool blCircleOverlap(BlCircle a, BlCircle b)
{
    BlVector2 diff = blVector2Sub(a.center, b.center);

    float squareLength = blVector2SquareLength(diff);
    float totalRadius = a.radius + b.radius;

    return (squareLength < totalRadius*totalRadius);
}
