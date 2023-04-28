/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef bl_transform_h
#define bl_transform_h

#include <basal/basal_matrix.h>

typedef struct bl_transform {
    bl_matrix local_matrix;
    bl_matrix world_matrix;

    struct bl_transform* parent;
    struct bl_transform** children;
    int max_children_count;
    int children_count;
} bl_transform;

void bl_transform_init(bl_transform* self);

void bl_transform_world_get_translate(bl_transform* self, struct bl_vector3* position);

#endif
