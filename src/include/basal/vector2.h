/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef blVector2h
#define blVector2h

#include <stdbool.h>

typedef struct BlVector2 {
    float x;
    float y;
} BlVector2;

BlVector2 blVector2Make(float a, float b);
BlVector2 blVector2Scale(BlVector2 p, float scalar);
BlVector2 blVector2Add(BlVector2 a, BlVector2 b);
BlVector2 blVector2Sub(BlVector2 a, BlVector2 b);
BlVector2 blVector2AddScale(BlVector2 a, BlVector2 b, float scale);
BlVector2 blVector2Zero(void);
float blVector2Length(BlVector2 a);
float blVector2SquareLength(BlVector2 a);
BlVector2 blVector2Unit(BlVector2 a);
float blVector2Dot(BlVector2 a, BlVector2 b);
BlVector2 blVector2Normal(BlVector2 a, BlVector2 b);
BlVector2 blVector2Direction(BlVector2 from, BlVector2 to);
BlVector2 blVector2Reflect(BlVector2 incoming, BlVector2 normal);
BlVector2 blVector2FromAngle(float angle);
float blVector2ToAngle(BlVector2 a);

float blAngleMinimalDiff(float a, float b);


#endif
