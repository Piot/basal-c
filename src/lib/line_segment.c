/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include "clog/clog.h"
#include <basal/line_segment.h>

BlVector2 blLineSegmentClosestPoint(const BlLineSegment segment, const BlVector2 query)
{
    BlVector2 tangent = blVector2Sub(segment.b, segment.a);

    BlVector2 vectorToA = blVector2Sub(query, segment.a);

    BlVector2 vectorToB = blVector2Sub(query, segment.b);

    float dotToA = blVector2Dot(vectorToA, tangent);
    if (dotToA <= 0.0f) {
        return segment.a;
    }

    float dotToB = blVector2Dot(vectorToB, tangent);
    if (dotToB >= 0.0f) {
        return segment.b;
    }

    BlVector2 tangentUnitVector = blVector2Unit(tangent);

    float projectMultiply = blVector2Dot(tangentUnitVector, vectorToA);
    BlVector2 projectVector = blVector2Scale(tangentUnitVector, projectMultiply);

    return blVector2Add(segment.a, projectVector);
}

BlCollision blLineSegmentCircleIntersect(const BlLineSegment segment, const BlCircle circle)
{
    BlVector2 closestPoint = blLineSegmentClosestPoint(segment, circle.center);

    BlVector2 deltaCircleCenterAndClosestPoint = blVector2Sub(circle.center, closestPoint);

    BlCollision result;
    result.depth = 0;
    result.normal.x = 0;
    result.normal.y = 0;

    float deltaCircleCenterAndClosestPointDot = blVector2Dot(deltaCircleCenterAndClosestPoint,
                                                             deltaCircleCenterAndClosestPoint);
    float radiusSquareDistance = circle.radius * circle.radius;

    if (deltaCircleCenterAndClosestPointDot > radiusSquareDistance) {
        return result;
    }

    float distanceBetweenCircleAndClosestPoint = blVector2Length(deltaCircleCenterAndClosestPoint);
    result.depth = ((float) circle.radius) - distanceBetweenCircleAndClosestPoint;
    result.normal = blVector2Scale(deltaCircleCenterAndClosestPoint, 1.0f / distanceBetweenCircleAndClosestPoint);
    result.point = closestPoint;

    return result;
}
