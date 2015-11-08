#include "rt\cameras\perspective.h"
#include "core\vector.h"
#include "core\point.h"
#include "rt\ray.h"
#include <math.h>

using namespace rt;

PerspectiveCamera::PerspectiveCamera(const Point& center, const Vector& forward, const Vector& up, float verticalOpeningAngle, float horizonalOpeningAngle) {
	this->center = center;
	this->zAxis = forward.normalize();
	this->xAxis = cross(up, forward).normalize();
	this->yAxis = cross(this->zAxis, this->xAxis).normalize();

	this->verticalOpeningAngle = verticalOpeningAngle;
	this->horizonalOpeningAngle = horizonalOpeningAngle;

	if ((verticalOpeningAngle / horizonalOpeningAngle) > 1) 
		angle = verticalOpeningAngle;
	else 
		angle = horizonalOpeningAngle;

	this->focus = 1.0 / tan(angle / 2.0);
	this->ratio = verticalOpeningAngle / horizonalOpeningAngle;
}

Ray PerspectiveCamera::getPrimaryRay(float x, float y) const {
	Vector rayOrigin;

	/*rayOrigin.x = center->x + x * scaleX * horizontal->x;
	rayOrigin.y = center->y + y * scaleY * up->y;*/

	/*Vector z = horizontal->scale(x * scaleX) + up->scale(y * scaleY);
	rayOrigin.x = z.x;
	rayOrigin.y = z.y;*/
	
	Vector dir;

	if (this->ratio > 1) // the horizontal axis is longer
		dir = (x * xAxis * ratio + y * yAxis + focus * zAxis).normalize();
	else
		dir = (x * xAxis + y * yAxis * ratio + focus * zAxis).normalize();
	
	return Ray(center, dir);
}