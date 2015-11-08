#include <core/image.h>
#include <core/point.h>
#include <core/vector.h>
#include <core/scalar.h>
#include <core/julia.h>
#include <rt/ray.h>
#include <rt/cameras/perspective.h>
#include <rt/cameras/orthographic.h>
#include <iostream>
#include <rt/renderer.h>

using namespace rt;


void a_cameras() {
    Image img(800, 800);
    Image low(128, 128);

    PerspectiveCamera pcam(Point(0, 0, 0), Vector(1, 0, 0.1), Vector(0, 0, 1), pi/3, pi/3);
    Renderer r1(&pcam,0);
    r1.test_render2(img);
    r1.test_render2(low);
    img.writePNG("a1-2.png");
    low.writePNG("a1-2-low.png");
	
    PerspectiveCamera pcam2(Point(0, 0, 0), Vector(0.5, 0.5, 0.3), Vector(0, 0, 1), pi * 0.9f, pi * 0.9f);
    Renderer r12(&pcam2,0);
    r12.test_render2(img);
    img.writePNG("a1-3.png");

    OrthographicCamera ocam(Point(0, 0, 0), Vector(0.1, 0.1, 1), Vector(0.2, 1.0, 0.2), 10.f, 10.f);
    Renderer r2(&ocam,0);
    r2.test_render2(img);
    img.writePNG("a1-4.png");
}
