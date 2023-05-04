/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef BL_MATH_H
#define BL_MATH_H

#include <math.h>

#define BL_PI_2 (1.570796f)
#define BL_PI (3.141592f)
#define BL_2PI (6.283185f)

#define blSqrt(f) sqrtf(f)
#define blFabs(f) ((float) fabsf(f))
#define blFSign(f) ((f) < 0.f ? -1.f : (f) > 0.f ? 1.f : 0.f)
#define blAcos(f) ((float) acosf(f))
#define blSin(f) ((float) sinf(f))
#define blCos(f) ((float) cosf(f))

#define blAtan2(f, g) ((float) atan2f(f, g))
#define blAsin(f) ((float) asinf(f))
#define blTan(f) ((float) tanf(f))
#define blFmod(f, g) ((float) fmodf(f, g))

#define blPow(a, b) pow((a), (b))

#define blClampf(v, min, max) (min < max ? (v < min ? min : v > max ? max : v) : (v < max ? max : v > min ? min : v))

#endif
