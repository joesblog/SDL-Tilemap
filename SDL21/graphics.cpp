#include "graphics.h"


extern SDL_Surface* gScreenSurface;
extern SDL_Renderer* gRenderer;
SDL_Texture * graphics::loadTexture(std::string path)
{
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	SDL_Texture *newTexture;

	if (loadedSurface == NULL)
	{
		printf("Failed to load image %s\n", path.c_str());
		quit = true;
	}

	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0, 0));
	newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);

	if (newTexture == NULL)
	{
		printf("Failed to create texture from image %s\n", path.c_str());
		quit = true;
	}

	SDL_FreeSurface(loadedSurface); 

	return newTexture;
}

SDL_Surface * graphics::loadSurface(std::string path)
{
	SDL_Surface* optSurface = NULL;

	SDL_Surface *loadedSurface = IMG_Load(path.c_str());

	if (loadedSurface == NULL)
	{
		printf("Failed to load image %s\n", path.c_str());
		quit = true;
	}
	else {
		SDL_SetColorKey(loadedSurface, SDL_RLEACCEL, SDL_MapRGB(loadedSurface->format, 0xff, 0xff, 0xff));

		optSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, NULL);
		SDL_FreeSurface(loadedSurface);
	}

	return optSurface;

}

void graphics::drawImage(SDL_Surface * image, int x, int y, SDL_Surface * screen)
{
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	dest.w = image->w;
	dest.h = image->h;

	SDL_BlitSurface(image, NULL, screen, &dest);
}

 

void graphics::handleRenderer() {
	SDL_RenderClear(gRenderer);


}

graphics::graphics()
{
}


graphics::~graphics()
{
}
