/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <basal/math.h>
#include <basal/rect.h>

BlCollision blRectCircleIntersect(BlRect rectangle, BlCircle circle)
{
    float closestX = blClampf(circle.center.x, rectangle.position.x, rectangle.position.x + rectangle.size.x);
    float closestY = blClampf(circle.center.y, rectangle.position.y, rectangle.position.y + rectangle.size.y);

    float distanceX = circle.center.x - closestX;
    float distanceY = circle.center.y - closestY;

    float distanceSquared = (distanceX * distanceX) + (distanceY * distanceY);
    float circleRadiusSquared = circle.radius * circle.radius;

    BlCollision result;
    if (distanceSquared < circleRadiusSquared) {
        result.depth = blSqrt(circleRadiusSquared - distanceSquared);
    } else {
        result.depth = 0.0f;
    }

    return result;
}
