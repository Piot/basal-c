/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <basal/math.h>
#include <basal/basal_matrix.h>
#include <basal/basal_quaternion.h>
#include <basal/basal_rect2.h>
#include <basal/basal_vector3.h>
#include <tiny-libc/tiny_libc.h>
#include <stdbool.h>
#include <clog/clog.h>

void bl_matrix_init(bl_matrix* self)
{
    tc_mem_clear_type_n(self->m, 16);
    float* m = self->m;

    m[0] = 1.0f;
    m[1 * 4 + 1] = 1.0f;
    m[2 * 4 + 2] = 1.0f;
    m[3 * 4 + 3] = 1.0f;
}

void verifyMatrix(const bl_matrix* matrix)
{
    for (size_t i = 0; i < 16; i++) {
        float v = matrix->m[i];
        float abs = fabsf(v);
        if (abs > 30000.0f) {
            CLOG_ERROR("bl_matrix has too big values!")
        }
    }
}

void bl_matrix_init_perspective(bl_matrix* self, float _fovy, float _aspect, float near_z,
                                float far_z)
{
    const float height = 1.0f / blTan(_fovy * 0.5f);
    float width = height / _aspect;
    float distance = near_z - far_z;
    float aa = (far_z + near_z) / distance;
    float bb = (2 * far_z * near_z) / distance;

    float* _result = self->m;

    tc_mem_clear_type_n(_result, 16);

    _result[0] = width;
    _result[1 * 4 + 1] = height;
    _result[2 * 4 + 2] = aa;
    _result[2 * 4 + 3] = -1.0f;
    _result[3 * 4 + 2] = bb;
}

void bl_matrix_init_ortho(bl_matrix* self, struct bl_rect* rect, float near_z, float far_z)
{
    float* _result = self->m;

    tc_mem_clear_type_n(_result, 16);

    _result[0] = 2.0f / rect->size.width;
    _result[1 * 4 + 1] = 2.0f / rect->size.height;
    _result[2 * 4 + 2] = -2.0f / (far_z - near_z);
    _result[3 * 4 + 3] = 1.0f;

    float left = rect->vector.x;
    float right = rect->vector.x + rect->size.width;
    float top = rect->vector.y + rect->size.height;
    float bottom = rect->vector.y;

    float ral = right + left;
    float rsl = right - left;
    float tab = top + bottom;
    float tsb = top - bottom;
    float fan = far_z + near_z;
    float fsn = far_z - near_z;

    _result[3 * 4 + 0] = -ral / rsl;
    _result[3 * 4 + 1] = -tab / tsb;
    _result[3 * 4 + 2] = -fan / fsn;
}

void bl_matrix_init_ortho_lh(bl_matrix* self, struct bl_rect* rect, float near_z, float far_z)
{
    float* _result = self->m;

    tc_mem_clear_type_n(_result, 16);

    _result[0] = 2.0f / rect->size.width;
    _result[1 * 4 + 1] = 2.0f / rect->size.height;
    _result[2 * 4 + 2] = 1.0f / (near_z - far_z);
    _result[3 * 4 + 3] = 1.0f;

    float left = rect->vector.x;
    float right = rect->vector.x + rect->size.width;
    float top = rect->vector.y;
    float bottom = rect->vector.y + rect->size.height;

    float ral = right + left;
    float rsl = right - left;
    float bat = bottom + top;
    float bst = bottom - top;
    float nsf = near_z - far_z;

    _result[3 * 4 + 0] = -ral / rsl;
    _result[3 * 4 + 1] = -bat / bst;
    _result[3 * 4 + 2] = near_z / nsf;
}

void bl_matrix_invert(bl_matrix* destination, const bl_matrix* source)
{
    const float* _a = source->m;
    float* _result = destination->m;

    float xx = _a[0];
    float xy = _a[1];
    float xz = _a[2];
    float xw = _a[3];
    float yx = _a[4];
    float yy = _a[5];
    float yz = _a[6];
    float yw = _a[7];
    float zx = _a[8];
    float zy = _a[9];
    float zz = _a[10];
    float zw = _a[11];
    float wx = _a[12];
    float wy = _a[13];
    float wz = _a[14];
    float ww = _a[15];

    float det = 0.0f;

    det += xx * (yy * (zz * ww - zw * wz) - yz * (zy * ww - zw * wy) + yw * (zy * wz - zz * wy));
    det -= xy * (yx * (zz * ww - zw * wz) - yz * (zx * ww - zw * wx) + yw * (zx * wz - zz * wx));
    det += xz * (yx * (zy * ww - zw * wy) - yy * (zx * ww - zw * wx) + yw * (zx * wy - zy * wx));
    det -= xw * (yx * (zy * wz - zz * wy) - yy * (zx * wz - zz * wx) + yz * (zx * wy - zy * wx));

    float invDet = 1.0f / det;

    _result[0] = +(yy * (zz * ww - wz * zw) - yz * (zy * ww - wy * zw) + yw * (zy * wz - wy * zz)) * invDet;
    _result[1] = -(xy * (zz * ww - wz * zw) - xz * (zy * ww - wy * zw) + xw * (zy * wz - wy * zz)) * invDet;
    _result[2] = +(xy * (yz * ww - wz * yw) - xz * (yy * ww - wy * yw) + xw * (yy * wz - wy * yz)) * invDet;
    _result[3] = -(xy * (yz * zw - zz * yw) - xz * (yy * zw - zy * yw) + xw * (yy * zz - zy * yz)) * invDet;

    _result[4] = -(yx * (zz * ww - wz * zw) - yz * (zx * ww - wx * zw) + yw * (zx * wz - wx * zz)) * invDet;
    _result[5] = +(xx * (zz * ww - wz * zw) - xz * (zx * ww - wx * zw) + xw * (zx * wz - wx * zz)) * invDet;
    _result[6] = -(xx * (yz * ww - wz * yw) - xz * (yx * ww - wx * yw) + xw * (yx * wz - wx * yz)) * invDet;
    _result[7] = +(xx * (yz * zw - zz * yw) - xz * (yx * zw - zx * yw) + xw * (yx * zz - zx * yz)) * invDet;

    _result[8] = +(yx * (zy * ww - wy * zw) - yy * (zx * ww - wx * zw) + yw * (zx * wy - wx * zy)) * invDet;
    _result[9] = -(xx * (zy * ww - wy * zw) - xy * (zx * ww - wx * zw) + xw * (zx * wy - wx * zy)) * invDet;
    _result[10] = +(xx * (yy * ww - wy * yw) - xy * (yx * ww - wx * yw) + xw * (yx * wy - wx * yy)) * invDet;
    _result[11] = -(xx * (yy * zw - zy * yw) - xy * (yx * zw - zx * yw) + xw * (yx * zy - zx * yy)) * invDet;

    _result[12] = -(yx * (zy * wz - wy * zz) - yy * (zx * wz - wx * zz) + yz * (zx * wy - wx * zy)) * invDet;
    _result[13] = +(xx * (zy * wz - wy * zz) - xy * (zx * wz - wx * zz) + xz * (zx * wy - wx * zy)) * invDet;
    _result[14] = -(xx * (yy * wz - wy * yz) - xy * (yx * wz - wx * yz) + xz * (yx * wy - wx * yy)) * invDet;
    _result[15] = +(xx * (yy * zz - zy * yz) - xy * (yx * zz - zx * yz) + xz * (yx * zy - zx * yy)) * invDet;
}

void bl_matrix_init_vector(bl_matrix* self, const bl_vector3* position)
{
    bl_matrix_init(self);
    self->m[12] = position->x;
    self->m[13] = position->y;
    self->m[14] = position->z;
}

static void bl_matrix_set_quaternion(bl_matrix* self, const bl_quaternion* quaternion)
{
    const float X = quaternion->v.x;
    const float Y = quaternion->v.y;
    const float Z = quaternion->v.z;
    const float W = quaternion->w;

    float* d = self->m;

    float xx = X * X;
    float xy = X * Y;
    float xz = X * Z;
    float xw = X * W;

    float yy = Y * Y;
    float yz = Y * Z;
    float yw = Y * W;

    float zz = Z * Z;
    float zw = Z * W;

    d[0] = 1 - 2 * (yy + zz);
    d[1] = 2 * (xy + zw);
    d[2] = 2 * (xz - yw);

    d[4] = 2 * (xy - zw);
    d[5] = 1 - 2 * (xx + zz);
    d[6] = 2 * (yz + xw);

    d[8] = 2 * (xz + yw);
    d[9] = 2 * (yz - xw);
    d[10] = 1 - 2 * (xx + yy);

    d[15] = 1.0f;
}

void bl_matrix_init_vector_quaternion(bl_matrix* self, const bl_vector3* position, const bl_quaternion* rotation)
{
    bl_matrix_init_vector(self, position);
    bl_matrix_set_quaternion(self, rotation);
}

void bl_matrix_multiply(bl_matrix* destination, const bl_matrix* b_matrix, const bl_matrix* a_matrix)
{
    const float* a = a_matrix->m;
    const float* b = b_matrix->m;
    float sum;

    float t[16];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            sum = 0;
            for (int n = 0; n < 4; n++) {
                sum += a[i * 4 + n] * b[n * 4 + j];
            }
            t[i * 4 + j] = sum;
        }
    }

    tc_memcpy_type(float, destination->m, t, 16);
}

void bl_matrix_get_translate(const bl_matrix* self, struct bl_vector3* position)
{
    position->x = self->m[12];
    position->y = self->m[13];
    position->z = self->m[14];
}

void bl_matrix_set_translate(bl_matrix* self, const struct bl_vector3 pos)
{
    self->m[12] = pos.x;
    self->m[13] = pos.y;
    self->m[14] = pos.z;
}

void bl_matrix_set_scale(bl_matrix* self, const struct bl_vector3 scale)
{
    self->m[0] = scale.x;
    self->m[5] = scale.y;
    self->m[10] = scale.z;
}

void bl_matrix_copy(bl_matrix* destination, const bl_matrix* source)
{
    *destination = *source;
}

const float* bl_matrix_raw(const bl_matrix* self)
{
    return self->m;
}
