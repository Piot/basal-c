/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#if defined TORNADO_OS_IOS_

#include <basal/basal_matrix.h>

#include <basal/basal_quaternion.h>
#include <basal/basal_rect2.h>
#include <basal/basal_vector3.h>

#include <clog/clog.h>

void bl_matrix_init(bl_matrix* self)
{
    self->matrix = GLKMatrix4Identity;
}

void bl_matrix_init_vector_quaternion(bl_matrix* self, const bl_vector3* position, const bl_quaternion* rotation)
{
    GLKQuaternion quaternion = GLKQuaternionMake(rotation->v.x, rotation->v.y, rotation->v.z, rotation->w);

    GLKMatrix4 rotation_matrix = GLKMatrix4MakeWithQuaternion(quaternion);
    GLKMatrix4 translation_matrix = GLKMatrix4MakeTranslation(position->x, position->y, position->z);

    self->matrix = GLKMatrix4Multiply(translation_matrix, rotation_matrix);
}

void bl_matrix_set_scale(bl_matrix* self, const struct bl_vector3 scale)
{
    self->matrix.m[0] = scale.x;
    self->matrix.m[5] = scale.y;
    self->matrix.m[10] = scale.z;
}

void bl_matrix_init_vector(bl_matrix* self, const bl_vector3* position)
{
    self->matrix = GLKMatrix4MakeTranslation(position->x, position->y, position->z);
}

void bl_matrix_multiply(bl_matrix* destination, const bl_matrix* a, const bl_matrix* b)
{
    destination->matrix = GLKMatrix4Multiply(a->matrix, b->matrix);
}

void bl_matrix_get_translate(const bl_matrix* self, bl_vector3* position)
{
    position->x = self->matrix.m[12];
    position->y = self->matrix.m[13];
    position->z = self->matrix.m[14];
}

void bl_matrix_init_perspective(bl_matrix* self, float fov, float aspect, float near_z,
                                float far_z)
{
    self->matrix = GLKMatrix4MakePerspective(fov, aspect, near_z, far_z);
}

void bl_matrix_init_frustum(bl_matrix* self, float left, float right, float bottom, float top, float near_z,
                            float far_z)
{
    self->matrix = GLKMatrix4MakeFrustum(left, right, bottom, top, near_z, far_z);
}

void bl_matrix_init_ortho(bl_matrix* self, bl_rect* rect, float near_z, float far_z)
{
    float half_width = rect->size.width / 2.0f;
    float half_height = rect->size.height / 2.0f;
    float left = rect->vector.x - half_width;
    float right = rect->vector.x + half_width;
    float bottom = rect->vector.y - half_height;
    float top = rect->vector.y + half_height;

    self->matrix = GLKMatrix4MakeOrtho(left, right, bottom, top, near_z, far_z);
}

void bl_matrix_copy(bl_matrix* destination, const bl_matrix* source)
{
    *destination = *source;
}

const float* bl_matrix_raw(const bl_matrix* self)
{
    return self->matrix.m;
}

void bl_matrix_invert(bl_matrix* destination, const bl_matrix* source)
{
    bool is_inverted = 0;

    destination->matrix = GLKMatrix4Invert(source->matrix, &is_inverted);

    CLOG_ASSERT(is_inverted, "Problem with inversion");
}
#else
static int dummy;

#endif
