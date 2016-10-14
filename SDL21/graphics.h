#pragma once
#include "globs.h"
#include <string> 
class graphics
{
public:
	static SDL_Texture* loadTexture(std::string path);
	static SDL_Surface* loadSurface(std::string path);
	static void drawImage(SDL_Surface* image, int x, int y, SDL_Surface * screen);
	static void handleRenderer();

	graphics();
	~graphics();
};

