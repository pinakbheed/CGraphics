#include "core\color.h"

using namespace rt;

RGBColor RGBColor::operator+(const RGBColor& c) const {
	RGBColor result;

	result.r = r + c.r;
	result.g = g + c.g;
	result.b = b + c.b;

	return result;
}

RGBColor RGBColor::operator-(const RGBColor& c) const {
	RGBColor result;

	result.r = r - c.r;
	result.g = g - c.g;
	result.b = b - c.b;

	return result;
}

RGBColor RGBColor::operator*(const RGBColor& c) const {
	RGBColor result;

	result.r = r * c.r;
	result.g = g * c.g;
	result.b = b * c.b;

	return result;
}

RGBColor RGBColor::clamp() const {
	RGBColor color;

	if (r > 1) {
		color.r = 1;
	}
	else if (r < 0) {
		color.r = 0;
	}
	else {
		color.r = r;
	}

	if (g > 1) {
		color.g = 1;
	}		
	else if (g < 0) {
		color.g = 0;
	}
	else {
		color.g = g;
	}

	if (b > 1) {
		color.b = 1;
	}
	else if (b < 0) {
		color.b = 0;
	}
	else {
		color.b = b;
	}

	return color;
}

RGBColor rt::operator*(float scalar, const RGBColor& b) {
	RGBColor result;

	result.r = b.r * scalar;
	result.g = b.g * scalar;
	result.b = b.b * scalar;

	return result;
}

RGBColor rt::operator*(const RGBColor& a, float scalar) {
	RGBColor result;

	result.r = a.r * scalar;
	result.g = a.g * scalar;
	result.b = a.b * scalar;

	return result;
}

RGBColor rt::operator/(const RGBColor& a, float scalar) {
	RGBColor result;

	result.r = a.r / scalar;
	result.g = a.g / scalar;
	result.b = a.b / scalar;

	return result;
}