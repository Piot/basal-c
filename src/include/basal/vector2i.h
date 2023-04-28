/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef BL_VECTOR2I_H
#define BL_VECTOR2I_H

typedef struct bl_vector2i {
    int x;
    int y;
} bl_vector2i;


bl_vector2i bl_vector2i_subtract(bl_vector2i a, bl_vector2i b);
int bl_vector2i_dot(const bl_vector2i a, const bl_vector2i b);
bl_vector2i bl_vector2i_reflect(bl_vector2i incoming, bl_vector2i normal);
bl_vector2i bl_vector2i_add_scale(bl_vector2i a, bl_vector2i b, int scale);
bl_vector2i bl_vector2i_mul_scalar(bl_vector2i p, float scalar);
float bl_vector2i_length(bl_vector2i a);
bl_vector2i bl_vector2i_unit(bl_vector2i a);
bl_vector2i bl_vector2i_add(bl_vector2i a, bl_vector2i b);
int bl_vector2i_square_length(bl_vector2i a);

#endif
