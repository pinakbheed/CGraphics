#include "rt\cameras\orthographic.h"
#include "core\vector.h"
#include "core\point.h"
#include "rt\ray.h"

using namespace rt;

OrthographicCamera::OrthographicCamera(const Point& center, const Vector& forward, const Vector& up, float scaleX, float scaleY) {

}

Ray OrthographicCamera::getPrimaryRay(float x, float y) const {
	Ray ray;

	return ray;
}