#include "core\point.h"
#include "core\vector.h"

using namespace rt;

Vector Point::operator-(const Point& b) const {
	Vector result;

	result.x = x - b.x;
	result.y = y - b.y;
	result.z = z - b.z;

	return result;
}

bool Point::operator==(const Point& b) const {
	if (x == b.x && y == b.y && z == b.z) {
		return true;
	}

	return false;
}

bool Point::operator!=(const Point& b) const {
	if (x == b.x && y == b.y && z == b.z) {
		return false;
	}

	return true;
}

Point rt::operator*(float scalar, const Point& b) {
	Point newPoint;

	newPoint.x = scalar * b.x;
	newPoint.y = scalar * b.y;
	newPoint.z = scalar * b.z;

	return newPoint;
}

Point rt::operator*(const Point& a, float scalar) {
	Point newPoint;

	newPoint.x = scalar * a.x;
	newPoint.y = scalar * a.y;
	newPoint.z = scalar * a.z;

	return newPoint;
}

Point rt::min(const Point& a, const Point& b) {
	Point newPoint;
	
	//to implement

	return newPoint;
}

Point rt::max(const Point& a, const Point& b) {
	Point newPoint;

	//to implement

	return newPoint;
}