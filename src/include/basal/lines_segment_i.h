/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
typedef struct blLineSegmenti {
    bl_vector2i a;
    bl_vector2i b;
} blLineSegmenti;

typedef struct BlCollisioni {
    float depth;
    bl_vector2i normal;
    bl_vector2i point;
} BlCollisioni;

BlCollisioni blLineSegmenti_circle_intersect(const blLineSegmenti segment, const bl_circle_i circle);

bl_vector2i blLineSegmenti_closest_point(const blLineSegmenti segment, const bl_vector2i query);