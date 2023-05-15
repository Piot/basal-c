/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef BlRect2i_h
#define BlRect2i_h

#include <basal/size2.h>
#include <basal/size2i.h>
#include <stdbool.h>

#include <basal/vector2i.h>

typedef struct BlRecti {
    BlVector2i vector;
    BlSize2i size;
} BlRecti;

#endif

