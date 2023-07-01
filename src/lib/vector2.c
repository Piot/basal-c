/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <basal/math.h>
#include <basal/vector2.h>

BlVector2 blVector2Make(float a, float b)
{
    BlVector2 point;

    point.x = a;
    point.y = b;

    return point;
}

BlVector2 blVector2Scale(BlVector2 p, float scalar)
{
    return blVector2Make(p.x * scalar, p.y * scalar);
}

BlVector2 blVector2Add(BlVector2 a, BlVector2 b)
{
    return blVector2Make(a.x + b.x, a.y + b.y);
}

BlVector2 blVector2AddScale(BlVector2 a, BlVector2 b, float scale)
{
    BlVector2 result;

    result.x = a.x + b.x * scale;
    result.y = a.y + b.y * scale;

    return result;
}

BlVector2 blVector2Zero(void)
{
    BlVector2 result;
    result.x = 0;
    result.y = 0;

    return result;
}

BlVector2 blVector2Sub(BlVector2 a, BlVector2 b)
{
    BlVector2 result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return result;
}

float blVector2Length(BlVector2 a)
{
    return blSqrt(a.x * a.x + a.y * a.y);
}

float blVector2SquareLength(BlVector2 a)
{
    return a.x * a.x + a.y * a.y;
}

BlVector2 blVector2Unit(BlVector2 a)
{
    float length = blVector2Length(a);
    BlVector2 result;

    result.x = a.x / length;
    result.y = a.y / length;

    return result;
}

float blVector2Dot(BlVector2 a, BlVector2 b)
{
    return a.x * b.x + a.y * b.y;
}

BlVector2 blVector2Reflect(BlVector2 incoming, BlVector2 normal)
{
    float reflectDot = blVector2Dot(incoming, normal);
    return blVector2Sub(incoming, blVector2Scale(normal, reflectDot * 2));
}

BlVector2 blVector2Normal(BlVector2 a, BlVector2 b)
{
    return blVector2Unit(blVector2Make(a.y - b.y, b.x - a.x));
}

BlVector2 blVector2Direction(BlVector2 from, BlVector2 to)
{
    BlVector2 result = blVector2Sub(to, from);

    result = blVector2Unit(result);
    return result;
}

BlVector2 blVector2FromAngle(float angle)
{
    BlVector2 direction;
    direction.x = blCos(angle);
    direction.y = blSin(angle);

    return direction;
}

float blVector2ToAngle(BlVector2 a)
{
    return blAtan2(a.y, a.x);
}

float blAngleMinimalDiff(float a, float b)
{
    float diff = blFmod(a - b + BL_PI, BL_2PI) - BL_PI;
    return diff < -BL_PI ? diff + BL_2PI : diff;
}
