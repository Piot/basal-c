/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <basal/basal_transform.h>

void bl_transform_init(bl_transform* self)
{
    bl_matrix_init(&self->local_matrix);
    bl_matrix_init(&self->world_matrix);

    self->parent = 0;
    self->children = 0;
    self->max_children_count = 0;
    self->children_count = 0;
}

void bl_transform_world_get_translate(bl_transform* self, struct bl_vector3* position)
{
    bl_matrix_get_translate(&self->world_matrix, position);
}
