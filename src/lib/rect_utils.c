/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <basal/matrix.h>
#include <basal/rect2.h>
#include <basal/rect_utils.h>
#include <basal/vector3.h>

static void blVector3multiply_matrix4(BlVector3* result, const BlVector3* vector, const BlMatrix* matrix)
{
    BlVector3 v;

    v.x = vector->x * matrix->m[0] + vector->y * matrix->m[3] + vector->z * matrix->m[6] + matrix->m[12];
    v.y = vector->x * matrix->m[1] + vector->y * matrix->m[4] + vector->z * matrix->m[7] + matrix->m[13];
    v.z = vector->x * matrix->m[2] + vector->y * matrix->m[5] + vector->z * matrix->m[8] + matrix->m[14];

    result->x = v.x;
    result->y = v.y;
    result->z = v.z;
}

static void BlVector3i_multiply_matrix4(BlVector3i* result, const BlVector3i* vector, const BlMatrix* matrix)
{
    BlVector3 source;

    source.x = (float) vector->x;
    source.y = (float) vector->y;
    source.z = (float) vector->z;

    BlVector3 result3;

    blVector3multiply_matrix4(&result3, &source, matrix);

    result->x = (int) result3.x;
    result->y = (int) result3.y;
    result->z = (int) result3.z;
}

static void BlVector2i_multiply_matrix4(BlVector2i* result, const BlVector2i* vector, const BlMatrix* matrix)
{
    BlVector3i source;

    source.x = vector->x;
    source.y = vector->y;
    source.z = 0;

    BlVector3i result3;

    BlVector3i_multiply_matrix4(&result3, &source, matrix);

    result->x = result3.x;
    result->y = result3.y;
}

void BlRecti_multiply_matrix4(BlRecti* target, const BlRecti* source, const BlMatrix* matrix)
{
    BlVector2i_multiply_matrix4(&target->vector, &source->vector, matrix);

    target->size.x = (int) ((float)source->size.x * matrix->m[0]);
    target->size.y = (int) ((float)source->size.y * matrix->m[5]);
}

/*
static void BlRecti_flipX(BlRecti* target, const BlRecti* source)
{
    target->vector.y = source->vector.y + source->size.y;
}

bool BlRecti_is_intersect(const BlRecti* a, BlRecti* b)
{
    return !(a->vector.x > b->vector.x + b->size.x || a->vector.x + a->size.x <= b->vector.x ||
             a->vector.y > b->vector.y + b->size.y || a->vector.y + a->size.y <= b->vector.y);
}
*/

const char* BlRecti_to_string(const BlRecti* a)
{
    static char buf[64];

    tc_snprintf(buf, 64, "%d,%d (%dx%d)", a->vector.x, a->vector.y, a->size.x, a->size.y);

    return buf;
}

void BlRecti_penetration(const BlRecti* a, BlRecti* b, struct BlVector2i* separationAxis)
{
    int sumWidth = a->size.x + b->size.x;
    int sumHeight = a->size.y + b->size.y;

    int deltaX = a->vector.x - b->vector.x;
    int absDeltaX = abs(deltaX);
    int deltaY = a->vector.y - b->vector.y;
    int absDeltaY = abs(deltaY);

    if (absDeltaX >= sumWidth || absDeltaY >= sumHeight) {
        CLOG_ERROR("shouldn't happen")
        // separationAxis->x = 0;
        // separationAxis->y = 0;
        // return;
    }

    int separationX = sumWidth - absDeltaX;
    int separationY = sumHeight - absDeltaY;

    if (separationX < separationY) {
        if (separationX > 0) {
            separationY = 0;
        }
    } else if (separationY > 0) {
        separationX = 0;
    }

    if (deltaX < 0) {
        separationX = -separationX;
    }

    if (deltaY < 0) {
        separationY = -separationY;
    }

    separationAxis->x = separationX;
    separationAxis->y = separationY;
}
