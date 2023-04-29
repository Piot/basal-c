/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef BL_MATRIX_H
#define BL_MATRIX_H

#include <clog/clog.h>
#include <stdbool.h>

typedef struct BlMatrix {
    float m[16];
} BlMatrix;

#include <basal/matrix_common.h>

void blMatrixVerify(const BlMatrix* matrix);

#endif
