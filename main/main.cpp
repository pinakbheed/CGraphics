#include <SDL.h>
#include <stdio.h>
#include <string>

const int SCREEN_WIDTH = 300;
const int SCREEN_HEIGHT = 300;
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

bool loadMedia() {
	bool success = true;

	/*gCurrentScreenSurface = SDL_LoadBMP("test.bmp");
	if (gCurrentScreenSurface == NULL) {
		printf("Unable to load image! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}*/

	return success;
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
	bool quit = false;
	SDL_Event event;

	if (!init()) {
		printf("Failed to initialize!");
	}
	else {
		if (!loadMedia()) {
			printf("Failed to load media!");
		}
		else {
			while (!quit) {
				while (SDL_PollEvent(&event) != 0) {
					if (event.type == SDL_QUIT) {
						quit = true;
					}
				}

				a_cameras();
				a_julia(gWindow);
				
				//SDL_BlitSurface(gCurrentScreenSurface, NULL, gScreenSurface, NULL);
				//SDL_UpdateWindowSurface(gWindow);
			}
		}
	}

	close();

    /*a_cameras();
	a_julia();*/

    return 0;
}