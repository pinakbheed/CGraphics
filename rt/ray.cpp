#include "rt\ray.h"

using namespace rt;

Point Ray::getPoint(float distance) const {
	Point newPoint;
	
	newPoint.x = o.x + d.x * distance;
	newPoint.y = o.y + d.y * distance;
	newPoint.z = o.z + d.z * distance;

	return newPoint;
}