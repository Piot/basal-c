/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef BL_RECT_UTILS_H
#define BL_RECT_UTILS_H

#include <stdbool.h>

#include <basal/rect2i.h>
#include <tiny-libc/tiny_libc.h>

struct BlMatrix;

void BlRecti_multiply_matrix4(struct BlRecti* target, const struct BlRecti* source, const struct BlMatrix* matrix);
void BlRecti_penetration(const BlRecti* a, BlRecti* b, struct BlVector2i * separationAxis);
//void BlRecti_combine(BlRecti* result, const BlRecti* a, const BlRecti* b);

static inline bool BlRecti_is_intersect(const BlRecti* r1, const BlRecti* r2)
{
    return !(r2->vector.x >= r1->vector.x + r1->size.x || r2->vector.x + r2->size.x <= r1->vector.x ||
             r2->vector.y + r2->size.y <= r1->vector.y || r2->vector.y >= r1->vector.y + r1->size.y);
}

static inline void BlRecti_combine(BlRecti* result, const BlRecti* a, const BlRecti* b)
{
    result->vector.x = tc_min(a->vector.x, b->vector.x);
    result->vector.y = tc_min(a->vector.y, b->vector.y);
    int maxX = tc_max(a->vector.x + a->size.x, b->vector.x + b->size.x);
    int maxY = tc_max(a->vector.y + a->size.y, b->vector.y + b->size.y);
    result->size.x = maxX - result->vector.x;
    result->size.y = maxY - result->vector.y;
}

const char* BlRecti_to_string(const BlRecti * a);

#endif
