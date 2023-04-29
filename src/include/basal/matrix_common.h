/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef BL_MATRIX_COMMON_H
#define BL_MATRIX_COMMON_H

#include <stdbool.h>

struct BlQuaternion;
struct BlVector3;
struct BlRect2;
struct BlMatrix;

void blMatrixInit(BlMatrix* self);
void blMatrixInitVectorQuaternion(BlMatrix* self, const struct BlVector3* position,
                                      const struct BlQuaternion* rotation);
void blMatrixInitVector(BlMatrix* self, const struct BlVector3* position);
void blMatrixInitPerspective(BlMatrix* self, float fov, float aspect, float near_z,
                                float far_z);
void blMatrixInitOrtho(BlMatrix* self, struct BlRect2* rect, float near_z, float far_z);
void blMatrixInitOrthoLh(BlMatrix* self, struct BlRect2* rect, float near_z, float far_z);
void blMatrixMultiply(BlMatrix* destination, const BlMatrix* a, const BlMatrix* b);
void blMatrixGetTranslate(const BlMatrix* self, struct BlVector3* position);
void blMatrixSetTranslate(BlMatrix* self, const struct BlVector3 position);
void blMatrixInvert(BlMatrix* destination, const BlMatrix* source);
void blMatrixSetScale(BlMatrix* self, const struct BlVector3 scale);
void blMatrixDebug(const BlMatrix* self, const char* debug_string);
const float* blMatrixRaw(const BlMatrix* self);

#endif
