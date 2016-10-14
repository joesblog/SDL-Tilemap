#pragma once
#include "globs.h"
#include "Map.h"
#include "graphics.h"

extern SDL_Surface *screen;
void draw(SDL_Surface* screen, Map* map);

void drawMap(Map * map);


extern void delay(unsigned int frameLimit);
 