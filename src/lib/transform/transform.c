/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <basal/transform.h>

void blTransformInit(BlTransform* self)
{
    blMatrixInit(&self->local_matrix);
    blMatrixInit(&self->world_matrix);

    self->parent = 0;
    self->children = 0;
    self->max_children_count = 0;
    self->children_count = 0;
}

void blTransformWorldGetTranslate(const BlTransform* self, struct BlVector3* position)
{
    blMatrixGetTranslate(&self->world_matrix, position);
}
