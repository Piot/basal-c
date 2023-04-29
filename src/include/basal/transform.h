/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef BL_TRANSFORM_H
#define BL_TRANSFORM_H

#include <basal/matrix.h>

typedef struct BlTransform {
    BlMatrix local_matrix;
    BlMatrix world_matrix;

    struct BlTransform* parent;
    struct BlTransform** children;
    int max_children_count;
    int children_count;
} BlTransform;

void blTransformInit(BlTransform* self);
void blTransformWorldGetTranslate(const BlTransform* self, struct BlVector3* position);

#endif
