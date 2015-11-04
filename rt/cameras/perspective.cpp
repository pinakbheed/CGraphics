#include "rt\cameras\perspective.h"
#include "core\vector.h"
#include "core\point.h"
#include "rt\ray.h"

using namespace rt;

PerspectiveCamera::PerspectiveCamera(const Point& center, const Vector& forward, const Vector& up, float verticalOpeningAngle, float horizonalOpeningAngle) {

}

Ray PerspectiveCamera::getPrimaryRay(float x, float y) const {
	Ray ray;

	return ray;
}