/*
 * Math.h
 *
 *  Created on: Apr 28, 2012
 *      Author: wdxu
 */

#ifndef MATH_H_
#define MATH_H_

#include <math.h>

namespace Tn
{

inline float round(float r)
{
    return (r >= 0.0f) ? floor(r + 0.5f) : ceil(r - 0.5f);
}

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::                                                                         :*/
/*::  This routine calculates the distance between two points (given the     :*/
/*::  latitude/longitude of those points). It is being used to calculate     :*/
/*::  the distance between two locations. Return distance unit is KM         :*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
inline float calculateGeoDistance(double lat1, double lon1, double lat2, double lon2)
{
    static const double pi = 3.14159265358979323846;
    double theta, dist, coefficient = pi / 180;
    theta = lon1 - lon2;
    dist = sin(lat1 * coefficient) * sin(lat2 * coefficient) + cos(lat1 * coefficient) * cos(lat2 * coefficient) * cos(theta * coefficient);
    dist = acos(dist);
    dist = dist / coefficient * 60 * 1.1515 * 1.609344;
    return dist;
}

}

#endif /* MATH_H_ */
