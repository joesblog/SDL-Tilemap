#pragma once
#include <SDL.h>
#include "input.h"
#include "Map.h"
#include "globs.h"
#include "graphics.h"
#include "draw.h"
int main(int argc, char * argv);
unsigned int frameLimit;
bool init();
void close();
void mainloop();
bool loadmedia();
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Renderer* gTRenderer = NULL;

SDL_Surface* gBackgroundImage = NULL;
SDL_Surface* gBrickImage = NULL;
SDL_Texture* gBackgroundTex = NULL;
SDL_Texture* gBrickTex = NULL;

SDL_Texture* gBigTexture = NULL;
Uint32 pixelFormat; 

SDL_Rect gBrickSrcR ;
SDL_Rect gBackgroundSrcR;
SDL_Rect gBackgroundDestR;

SDL_Surface* tile = NULL;
Map* map;
Input input;