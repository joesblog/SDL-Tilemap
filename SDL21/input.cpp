#include "input.h"


Input::Input()
{
}

Input::~Input()
{
}


 
void Input::getInput()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				quit = true;

				break;
			case SDLK_UP:
				up = 1;
				break;

			case SDLK_DOWN:
				down = 1;
				break;

			case SDLK_LEFT:
				left = 1;
				break;

			case SDLK_RIGHT:
				right = 1;
				break;
			default:
				break;
			}
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_UP:
				up = 0;
				break;

			case SDLK_DOWN:
				down = 0;
				break;

			case SDLK_LEFT:
				left = 0;
				break;

			case SDLK_RIGHT:
				right = 0;
				break;

			default:
				break;
			}
			break;
		default:
			break;
		}

	}
}

void Input::doMap(Map* map)
{



	if (left == 1)
	{
		map->startX -= SCROLL_SPEED;
	 
		if (map->startX < 0)
		{
			map->startX = 0;
		}
	}

	else if (right == 1)
	{
		map->startX += SCROLL_SPEED;
 
		if (map->startX + SCREEN_WIDTH >= map->maxX)
		{
			map->startX = map->maxX - SCREEN_WIDTH;
		}
	}

	if (up == 1)
	{
		map->startY -= SCROLL_SPEED;

		if (map->startY < 0)
		{
			map->startY = 0;
		}
	}

	else if (down == 1)
	{
		map->startY += SCROLL_SPEED;

		if (map->startY + SCREEN_HEIGHT >= map->maxY)
		{
			map->startY = map->maxY - SCREEN_HEIGHT;
		}
	}
}

