#include "core\vector.h"
#include "core\point.h"
#include <math.h>

using namespace rt;

Vector Vector::operator+(const Vector& b) const {
	Vector result;

	result.x = x + b.x;
	result.y = y + b.y;
	result.z = z + b.z;

	return result;
}

Vector Vector::operator-(const Vector& b) const {
	Vector result;

	result.x = x - b.x;
	result.y = y - b.y;
	result.z = z - b.z;

	return result;
}

float Vector::length() const {
	float length = sqrtf(x*x + y*y + z*z);
	return length;
}

float Vector::lensqr() const {
	float lensqr = x*x + y*y + z*z;
	return lensqr;
}

Vector Vector::normalize() const {
	Vector result;
	
	float length = sqrtf(x*x + y*y + z*z);
	result.x = x / length;
	result.y = y / length;
	result.z = z / length;

	return result;
}

bool Vector::operator==(const Vector& b) const {
	if (x == b.x && y == b.y && z == b.z)
		return true;
	return false;
}

bool Vector::operator!=(const Vector& b) const {
	if (x == b.x && y == b.y && z == b.z)
		return false;
	return true;
}

Vector rt::operator*(float scalar, const Vector& b) {
	Vector result;

	result.x = b.x * scalar;
	result.y = b.y * scalar;
	result.z = b.z * scalar;

	return result;
}

Vector rt::operator*(const Vector& a, float scalar) {
	Vector result;

	result.x = a.x * scalar;
	result.y = a.y * scalar;
	result.z = a.z * scalar;

	return result;
}

Vector rt::operator/(const Vector& a, float scalar) {
	Vector result;

	result.x = a.x / scalar;
	result.y = a.y / scalar;
	result.z = a.z / scalar;

	return result;
}

Vector rt::cross(const Vector& a, const Vector& b) {
	Vector result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;

	return result;
}

float rt::dot(const Vector& a, const Vector& b) {
	float result;

	result = a.x * b.x + a.y * b.y + a.z * b.z;

	return result;
}

Vector rt::min(const Vector& a, const Vector& b) {
	Vector result;

	if (a.x < b.x)
		result.x = a.x;
	else
		result.x = b.x;

	if (a.y < b.y)
		result.y = a.y;
	else
		result.y = b.y;

	if (a.z < b.z)
		result.z = a.z;
	else
		result.z = b.z;

	return result;
}

Vector rt::max(const Vector& a, const Vector& b) {
	Vector result;

	if (a.x > b.x)
		result.x = a.x;
	else
		result.x = b.x;

	if (a.y > b.y)
		result.y = a.y;
	else
		result.y = b.y;

	if (a.z > b.z)
		result.z = a.z;
	else
		result.z = b.z;

	return result;
}

Point rt::operator+(const Point& a, const Vector& b) {
	Point newPoint;

	newPoint.x = a.x + b.x;
	newPoint.y = a.y + b.y;
	newPoint.z = a.z + b.z;

	return newPoint;
}

Point rt::operator+(const Vector& a, const Point& b) {
	Point newPoint;

	newPoint.x = a.x + b.x;
	newPoint.y = a.y + b.y;
	newPoint.z = a.z + b.z;

	return newPoint;
}

Point rt::operator-(const Point& a, const Vector& b) {
	Point newPoint;

	newPoint.x = a.x - b.x;
	newPoint.y = a.y - b.y;
	newPoint.z = a.z - b.z;

	return newPoint;
}

/*Point operator*(const Float4& scale, const Point& p) {
	Point newPoint;

	newPoint.x = scale * p.x;
	newPoint.y = scale * p.y;
	newPoint.z = scale * p.z;

	return newPoint;
}
*/