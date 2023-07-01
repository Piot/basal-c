/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <basal/math.h>
#include <basal/vector2i.h>
#include <tiny-libc/tiny_libc.h>

BlVector2i blVector2iAddScale(BlVector2i a, BlVector2i b, int scale)
{
    BlVector2i result;

    result.x = a.x + b.x * scale;
    result.y = a.y + b.y * scale;

    return result;
}

BlVector2i blVector2iReflect(BlVector2i incoming, BlVector2i normal)
{
    int reflectDot = blVector2iDot(incoming, normal);
    return blVector2iSub(incoming, blVector2iScale(normal, reflectDot * 2));
}

int blVector2iDot(const BlVector2i a, const BlVector2i b)
{
    return a.x * b.x + a.y * b.y;
}

BlVector2i blVector2iSub(BlVector2i a, BlVector2i b)
{
    BlVector2i result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return result;
}

BlVector2i blVector2iScale(BlVector2i p, float scalar)
{
    BlVector2i result;

    result.x = (int) (p.x * scalar);
    result.y = (int) (p.y * scalar);

    return result;
}


float blVector2iLength(BlVector2i a)
{
    return blSqrt(a.x * a.x + a.y * a.y);
}

int blVector2iSquareLength(BlVector2i a)
{
    return a.x * a.x + a.y * a.y;
}

BlVector2i blVector2iUnit(BlVector2i a)
{
    float length = blVector2iLength(a);
    BlVector2i result;

    result.x = (int) (a.x / length);
    result.y = (int) (a.y / length);

    return result;
}

BlVector2i blVector2iAdd(BlVector2i a, BlVector2i b)
{
    BlVector2i result;

    result.x = a.x + b.x;
    result.y = a.y + b.y;

    return result;
}
