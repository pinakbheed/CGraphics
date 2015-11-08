#include "rt\cameras\orthographic.h"
#include "core\vector.h"
#include "core\point.h"
#include "rt\ray.h"

using namespace rt;

OrthographicCamera::OrthographicCamera(Point& center, Vector& forward, Vector& up, float scaleX, float scaleY) {
	this->center = center;
	this->zAxis = forward.normalize();
	this->xAxis = cross(up, forward).normalize();
	this->yAxis = cross(zAxis, xAxis).normalize();

	this->scaleX = scaleX;
	this->scaleY = scaleY;
}

Ray OrthographicCamera::getPrimaryRay(float x, float y) const {
	Point rayOrigin;

	rayOrigin = center + x * scaleX * xAxis + y * scaleY * yAxis;

	return Ray(rayOrigin, zAxis);
}