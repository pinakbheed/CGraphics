#include <core/point.h>
#include <core/vector.h>
#include <core/color.h>
#include <core/scalar.h>
#include <core/julia.h>
#include <core/image.h>
#include <rt/renderer.h>
#include <SDL.h>

typedef unsigned char byte;

using namespace rt;

void a_julia(SDL_Window * gWindow) {
    Image img(800, 800);
    Renderer engine(0,0);
	engine.test_render1(img);
	
	RGBColor * it = img.getPixels();
	byte * ptr = (byte *)malloc(img.width()*img.height() * 3);
	byte * head = ptr;

	int limit = img.width() * img.height();

	for (int k = 0; k < limit; k++) {
		RGBColor v = it[k].clamp();
		*ptr++ = (byte)(v.b * 255);
		*ptr++ = (byte)(v.g * 255);
		*ptr++ = (byte)(v.r * 255);
	}

	Uint32 rmask = 0x000000ff;
	Uint32 gmask = 0x0000ff00;
	Uint32 bmask = 0x00ff0000;
	
	SDL_Surface * image = SDL_CreateRGBSurfaceFrom(head, img.width(), img.height(), 24, img.width() * 3, rmask, gmask, bmask, 0);

	SDL_BlitSurface(image, NULL, SDL_GetWindowSurface(gWindow), NULL);
	SDL_UpdateWindowSurface(gWindow);
	
	img.writePNG("fractal.png");
}
