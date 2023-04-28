/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <basal/math.h>
#include <basal/vector2i.h>
#include <tiny-libc/tiny_libc.h>

bl_vector2i bl_vector2i_add_scale(bl_vector2i a, bl_vector2i b, int scale)
{
    bl_vector2i result;

    result.x = a.x + b.x * scale;
    result.y = a.y + b.y * scale;

    return result;
}

bl_vector2i bl_vector2i_reflect(bl_vector2i incoming, bl_vector2i normal)
{
    int reflectDot = bl_vector2i_dot(incoming, normal);
    return bl_vector2i_subtract(incoming, bl_vector2i_mul_scalar(normal, reflectDot * 2));
}

int bl_vector2i_dot(const bl_vector2i a, const bl_vector2i b)
{
    return a.x * b.x + a.y * b.y;
}

bl_vector2i bl_vector2i_subtract(bl_vector2i a, bl_vector2i b)
{
    bl_vector2i result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return result;
}

bl_vector2i bl_vector2i_mul_scalar(bl_vector2i p, float scalar)
{
    bl_vector2i result;

    result.x = p.x * scalar;
    result.y = p.y * scalar;

    return result;
}


float bl_vector2i_length(bl_vector2i a)
{
    return blSqrt(a.x * a.x + a.y * a.y);
}


int bl_vector2i_square_length(bl_vector2i a)
{
    return a.x * a.x + a.y * a.y;
}

bl_vector2i bl_vector2i_unit(bl_vector2i a)
{
    int length = bl_vector2i_length(a);
    bl_vector2i result;

    result.x = a.x / length;
    result.y = a.y / length;

    return result;
}

bl_vector2i bl_vector2i_add(bl_vector2i a, bl_vector2i b)
{
    bl_vector2i result;

    result.x = a.x + b.x;
    result.y = a.y + b.y;

    return result;
}
