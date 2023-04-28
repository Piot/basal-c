/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef bl_matrix_generic_h
#define bl_matrix_generic_h

#include <clog/clog.h>
#include <stdbool.h>

typedef struct bl_matrix {
    float m[16];
} bl_matrix;

#include <basal/basal_matrix_common.h>

void verifyMatrix(const bl_matrix* matrix);

#endif
