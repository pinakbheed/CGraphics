#include "rt\ray.h"

using namespace rt;

Ray::Ray(const Point& o, const Vector& d) {
	this->o = o;
	this->d = d;
}

Ray::Ray(Point * o, Vector * d) {
	this->o = *o;
	this->d = *d;
}

Point Ray::getPoint(float distance) const {
	Point newPoint;
	
	newPoint.x = o.x + d.x * distance;
	newPoint.y = o.y + d.y * distance;
	newPoint.z = o.z + d.z * distance;

	return newPoint;
}