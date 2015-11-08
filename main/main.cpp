#include <SDL.h>
#include "SDL_thread.h"
#include <stdio.h>
#include <string>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;
SDL_Window * gWindow = NULL;
SDL_Surface * gScreenSurface = NULL;
SDL_Surface * gCurrentScreenSurface = NULL;

bool init();
bool loadMedia();
void close();

void a_julia(SDL_Window *);
void a_cameras();
void a_solids();
void a_indexing();
void a_instancing();
void a_lighting();
void a_materials();
void a_distributed();
void a_light();
void a_textures();
void a_smooth();
void a_mappers();
void a_bumpmappers();

enum KeyPressSurface {
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

bool init() {
	bool flag = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL not initialized! SDL_Error: %s\n", SDL_GetError());
		flag = false;
	}
	else {
		gWindow = SDL_CreateWindow("Computer Graphics", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			flag = false;;
		}
		else {
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return flag;
}

static int windowLoop(void * ptr) {
	a_julia(gWindow);
	return 1;
}

static int computingImages(void * ptr) {
	a_cameras();
	return 1;
}
 
void close() {
	SDL_FreeSurface(gCurrentScreenSurface);
	gCurrentScreenSurface = NULL;

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_Quit();
}

int main(int argc, char* argv[])
{
	if (!init()) {
		printf("Failed to initialize!");
	}
	else {
		SDL_Thread *t1, *t2;
		int threadReturnValue;

		t1 = SDL_CreateThread(windowLoop, "Window", (void *)NULL);

		printf("Computing Camera Images! Please wait...");
		t2 = SDL_CreateThread(computingImages, "Computing_Images", (void *)NULL);

		if (t2 == NULL) {
			printf("\nSDL_CreateThread failed: %s\n", SDL_GetError());
		}
		else {
			SDL_WaitThread(t2, &threadReturnValue);
			printf("Completed!");
		}

		bool quit = false;
		SDL_Event event;

		while (!quit) {
			while (SDL_PollEvent(&event) != 0) {
				if (event.type == SDL_QUIT) {
					quit = true;
				}
			}

		}

		close();
	}
    return 0;
}
