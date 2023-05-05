/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef BL_VECTOR2I_H
#define BL_VECTOR2I_H

typedef struct BlVector2i {
    int x;
    int y;
} BlVector2i;

BlVector2i blVector2iSub(BlVector2i a, BlVector2i b);
int blVector2iDot(const BlVector2i a, const BlVector2i b);
BlVector2i blVector2iReflect(BlVector2i incoming, BlVector2i normal);
BlVector2i blVector2iAddScale(BlVector2i a, BlVector2i b, int scale);
BlVector2i blVector2iScale(BlVector2i p, float scalar);
BlVector2i blVector2iUnit(BlVector2i a);
BlVector2i blVector2iAdd(BlVector2i a, BlVector2i b);
float blVector2iLength(BlVector2i a);
int blVector2iSquareLength(BlVector2i a);

#endif
