/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef bl_rect_utils_h
#define bl_rect_utils_h

#include <stdbool.h>

#include <basal/rect2i.h>
#include <tiny-libc/tiny_libc.h>

struct bl_matrix;

void bl_recti_multiply_matrix4(struct bl_recti* target, const struct bl_recti* source, const struct bl_matrix* matrix);
void bl_recti_penetration(const bl_recti* a, bl_recti* b, struct bl_vector2i* separationAxis);
//void bl_recti_combine(bl_recti* result, const bl_recti* a, const bl_recti* b);

static inline bool bl_recti_is_intersect(const bl_recti* r1, const bl_recti* r2)
{
    return !(r2->vector.x >= r1->vector.x + r1->size.width || r2->vector.x + r2->size.width <= r1->vector.x ||
             r2->vector.y + r2->size.height <= r1->vector.y || r2->vector.y >= r1->vector.y + r1->size.height);
}

static inline void bl_recti_combine(bl_recti* result, const bl_recti* a, const bl_recti* b)
{
    result->vector.x = tc_min(a->vector.x, b->vector.x);
    result->vector.y = tc_min(a->vector.y, b->vector.y);
    int maxX = tc_max(a->vector.x + a->size.width, b->vector.x + b->size.width);
    int maxY = tc_max(a->vector.y + a->size.height, b->vector.y + b->size.height);
    result->size.width = maxX - result->vector.x;
    result->size.height = maxY - result->vector.y;
}

const char* bl_recti_to_string(const bl_recti * a);

#endif
