/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <basal/basal_matrix.h>
#include <basal/basal_rect2.h>
#include <basal/basal_rect_utils.h>
#include <basal/basal_vector3.h>

static void bl_vector3_multiply_matrix4(bl_vector3* result, const bl_vector3* vector, const bl_matrix* matrix)
{
    bl_vector3 v;

    v.x = vector->x * matrix->m[0] + vector->y * matrix->m[3] + vector->z * matrix->m[6] + matrix->m[12];
    v.y = vector->x * matrix->m[1] + vector->y * matrix->m[4] + vector->z * matrix->m[7] + matrix->m[13];
    v.z = vector->x * matrix->m[2] + vector->y * matrix->m[5] + vector->z * matrix->m[8] + matrix->m[14];

    result->x = v.x;
    result->y = v.y;
    result->z = v.z;
}

static void bl_vector3i_multiply_matrix4(bl_vector3i* result, const bl_vector3i* vector, const bl_matrix* matrix)
{
    bl_vector3 source;

    source.x = vector->x;
    source.y = vector->y;
    source.z = vector->z;

    bl_vector3 result3;

    bl_vector3_multiply_matrix4(&result3, &source, matrix);

    result->x = result3.x;
    result->y = result3.y;
    result->z = result3.z;
}

static void bl_vector2i_multiply_matrix4(bl_vector2i* result, const bl_vector2i* vector, const bl_matrix* matrix)
{
    bl_vector3i source;

    source.x = vector->x;
    source.y = vector->y;
    source.z = 0;

    bl_vector3i result3;

    bl_vector3i_multiply_matrix4(&result3, &source, matrix);

    result->x = result3.x;
    result->y = result3.y;
}

void bl_recti_multiply_matrix4(bl_recti* target, const bl_recti* source, const bl_matrix* matrix)
{
    bl_vector2i_multiply_matrix4(&target->vector, &source->vector, matrix);

    target->size.width = (source->size.width * matrix->m[0]);
    target->size.height = (source->size.height * matrix->m[5]);
}

static void bl_recti_flipx(bl_recti* target, const bl_recti* source)
{
    target->vector.y = source->vector.y + source->size.height;
}
/*
bool bl_recti_is_intersect(const bl_recti* a, bl_recti* b)
{
    return !(a->vector.x > b->vector.x + b->size.width || a->vector.x + a->size.width <= b->vector.x ||
             a->vector.y > b->vector.y + b->size.height || a->vector.y + a->size.height <= b->vector.y);
}
*/

const char* bl_recti_to_string(const bl_recti * a)
{
    static char buf[64];

    tc_snprintf(buf, 64, "%d,%d (%dx%d)", a->vector.x, a->vector.y, a->size.width, a->size.height);

    return buf;
}

void bl_recti_penetration(const bl_recti* a, bl_recti* b, struct bl_vector2i* separationAxis)
{
    int sumWidth = a->size.width + b->size.width;
    int sumHeight = a->size.height + b->size.height;

    int deltaX = a->vector.x - b->vector.x;
    int absDeltaX = abs(deltaX);
    int deltaY = a->vector.y - b->vector.y;
    int absDeltaY = abs(deltaY);

    if (absDeltaX >= sumWidth || absDeltaY >= sumHeight) {
        CLOG_ERROR("shouldn't happen")
        separationAxis->x = 0;
        separationAxis->y = 0;
        return;
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
