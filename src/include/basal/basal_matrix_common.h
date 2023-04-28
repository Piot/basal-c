/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef matrix_common_h
#define matrix_common_h

#include <stdbool.h>

struct bl_quaternion;
struct bl_vector3;
struct bl_rect;
struct bl_matrix;
struct bl_rect;

void bl_matrix_init(bl_matrix* self);
void bl_matrix_init_vector_quaternion(bl_matrix* self, const struct bl_vector3* position,
                                      const struct bl_quaternion* rotation);
void bl_matrix_init_vector(bl_matrix* self, const struct bl_vector3* position);
void bl_matrix_init_perspective(bl_matrix* self, float fov, float aspect, float near_z,
                                float far_z);
void bl_matrix_init_ortho(bl_matrix* self, struct bl_rect* rect, float near_z, float far_z);
void bl_matrix_init_ortho_lh(bl_matrix* self, struct bl_rect* rect, float near_z, float far_z);
void bl_matrix_multiply(bl_matrix* destination, const bl_matrix* a, const bl_matrix* b);
void bl_matrix_get_translate(const bl_matrix* self, struct bl_vector3* position);
void bl_matrix_set_translate(bl_matrix* self, const struct bl_vector3 position);
void bl_matrix_invert(bl_matrix* destination, const bl_matrix* source);
void bl_matrix_copy(bl_matrix* destination, const bl_matrix* source);
void bl_matrix_set_scale(bl_matrix* self, const struct bl_vector3 scale);
void bl_matrix_debug(const bl_matrix* self, const char* debug_string);
const float* bl_matrix_raw(const bl_matrix* self);

#endif
