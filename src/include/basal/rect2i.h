/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef bl_rect2i_h
#define bl_rect2i_h

#include <basal/size2.h>
#include <basal/size2i.h>
#include <stdbool.h>

#include <basal/vector2i.h>

typedef struct bl_recti {
    bl_vector2i vector;
    BlSize2i size;
} bl_recti;

#endif

