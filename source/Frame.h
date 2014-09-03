#include <SDL.h>

#pragma once
#ifndef CSPRITE_H_
#define CSPRITE_H_
#endif

#define TRUE 1
#define FALSE 0

class CFrame {

public:

	SDL_Surface *img;
	void load(char *path);
	void unload();
};