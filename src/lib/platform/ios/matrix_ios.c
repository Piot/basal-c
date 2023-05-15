/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#if defined TORNADO_OS_IOS_

#include <basal/matrix.h>

#include <basal/quaternion.h>
#include <basal/rect2.h>
#include <basal/vector3.h>

#include <clog/clog.h>

void blMatrixinit(BlMatrix* self)
{
    self->matrix = GLKMatrix4Identity;
}

void blMatrixinit_vector_quaternion(BlMatrix* self, const BlVector3* position, const BlQuaternion* rotation)
{
    GLKQuaternion quaternion = GLKQuaternionMake(rotation->v.x, rotation->v.y, rotation->v.z, rotation->w);

    GLKMatrix4 rotation_matrix = GLKMatrix4MakeWithQuaternion(quaternion);
    GLKMatrix4 translation_matrix = GLKMatrix4MakeTranslation(position->x, position->y, position->z);

    self->matrix = GLKMatrix4Multiply(translation_matrix, rotation_matrix);
}

void blMatrixset_scale(BlMatrix* self, const struct BlVector3 scale)
{
    self->matrix.m[0] = scale.x;
    self->matrix.m[5] = scale.y;
    self->matrix.m[10] = scale.z;
}

void blMatrixinit_vector(BlMatrix* self, const BlVector3* position)
{
    self->matrix = GLKMatrix4MakeTranslation(position->x, position->y, position->z);
}

void blMatrixmultiply(BlMatrix* destination, const BlMatrix* a, const BlMatrix* b)
{
    destination->matrix = GLKMatrix4Multiply(a->matrix, b->matrix);
}

void blMatrixget_translate(const BlMatrix* self, BlVector3* position)
{
    position->x = self->matrix.m[12];
    position->y = self->matrix.m[13];
    position->z = self->matrix.m[14];
}

void blMatrixinit_perspective(BlMatrix* self, float fov, float aspect, float near_z,
                                float far_z)
{
    self->matrix = GLKMatrix4MakePerspective(fov, aspect, near_z, far_z);
}

void blMatrixinit_frustum(BlMatrix* self, float left, float right, float bottom, float top, float near_z,
                            float far_z)
{
    self->matrix = GLKMatrix4MakeFrustum(left, right, bottom, top, near_z, far_z);
}

void blMatrixinit_ortho(BlMatrix* self, BlRect* rect, float near_z, float far_z)
{
    float half_width = rect->size.width / 2.0f;
    float half_height = rect->size.height / 2.0f;
    float left = rect->vector.x - half_width;
    float right = rect->vector.x + half_width;
    float bottom = rect->vector.y - half_height;
    float top = rect->vector.y + half_height;

    self->matrix = GLKMatrix4MakeOrtho(left, right, bottom, top, near_z, far_z);
}

void blMatrixcopy(BlMatrix* destination, const BlMatrix* source)
{
    *destination = *source;
}

const float* blMatrixRaw(const BlMatrix* self)
{
    return self->matrix.m;
}

void blMatrixinvert(BlMatrix* destination, const BlMatrix* source)
{
    bool is_inverted = 0;

    destination->matrix = GLKMatrix4Invert(source->matrix, &is_inverted);

    CLOG_ASSERT(is_inverted, "Problem with inversion");
}
#else
static int dummy;

#endif
