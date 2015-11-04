#include "rt\renderer.h"
#include "core\image.h"
#include "core\point.h"
#include "core\julia.h"
#include "core\vector.h"

using namespace rt;

float a1computeWeight(float fx, float fy, const Point& c, float div) {
	Point v(fx, fy, 0.5f);
	v = v - Vector::rep(0.5f);
	v = v * 2.0f;
	int numIter = julia(v, c);
	return numIter / (numIter + div);
}

RGBColor a1computeColor(uint x, uint y, uint width, uint height) {
	float fx = float(x) / float(width);
	float fy = float(y) / float(height);
	RGBColor color = RGBColor::rep(0.0f);
	color = color + a1computeWeight(fx, fy, Point(-0.8f, 0.156f, 0.0f), 64.0f) * RGBColor(0.8f, 0.8f, 1.0f);
	color = color + a1computeWeight(fx, fy, Point(-0.6f, 0.2f, 0.0f), 64.0f)*0.2f * RGBColor(0.5f, 0.5f, -0.2f);
	color = color + a1computeWeight(fy, fx, Point(0.285f, 0.0f, 0.0f), 64.0f) * RGBColor(0.2f, 0.3f, 0.4f);
	return RGBColor::rep(1.0f) - color;
}

Renderer::Renderer(Camera * cam, Integrator * integrator) {

}

void Renderer::setSamples(uint samples) {

}

void Renderer::render(Image& img) {
	
}

void Renderer::test_render1(Image& img) {
	int limit = img.width() * img.height();
	uint i = 0, j = 0;
	
	for (int k = 0; k < limit; k++) {
		if (j >= img.width()) {
			i++;
			j = 0;
		}
		img.setPixelColor(j, i, a1computeColor(j, i, img.width(), img.height()));
		j++;
	}
}

void Renderer::test_render2(Image& img) {
	int limit = img.width() * img.height();
	uint i = 0, j = 0;

	RGBColor z;
	z.r = 0.f;
	z.g = 1.f;
	z.b = 1.f;

	for (int k = 0; k < limit; k++) {
		if (j >= img.width()) {
			i++;
			j = 0;
		}

		img.setPixelColor(j, i, z);
		j++;
	}
}