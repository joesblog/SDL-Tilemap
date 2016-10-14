#include "draw.h"

extern SDL_Renderer* gRenderer;

extern SDL_Surface* gBackgroundImage;
extern SDL_Surface* gBrickImage;
extern SDL_Surface* gScreenSurface;
extern int standardDelay;
extern SDL_Texture* gBackgroundTex;
extern SDL_Texture* gBrickTex;
extern SDL_Rect gBrickSrcR;
extern SDL_Rect gBackgroundSrcR;
extern unsigned int frameLimit;
extern SDL_Renderer* gTRenderer;
extern SDL_Texture* gBigTexture;
extern Uint32 pixelFormat;
void draw(SDL_Surface* screen, Map* map){

	drawMap(map);


 
}


void drawMap(Map* map)
{

	 
	int x, y, mapX, x1, x2, mapY, y1, y2;
	mapX = map->startX / TILE_SIZE;
	x1 = (map->startX % TILE_SIZE) * -1;
	x2 = x1 + SCREEN_WIDTH + (x1 == 0 ? 0 : TILE_SIZE);

	mapY = map->startY / TILE_SIZE;
	y1 = (map->startY % TILE_SIZE) * -1;
	y2 = y1 + SCREEN_HEIGHT + (y1 == 0 ? 0 : TILE_SIZE);

	
	SDL_QueryTexture(gBrickTex, &pixelFormat, NULL, NULL, NULL);
	SDL_SetRenderTarget(gRenderer, gBigTexture);
	SDL_RenderClear(gRenderer);
	SDL_RenderCopy(gRenderer, gBackgroundTex, NULL, &gBackgroundSrcR);

	for (y = y1; y<y2; y += TILE_SIZE)
	{
		mapX = map->startX / TILE_SIZE;

		for (x = x1; x<x2; x += TILE_SIZE)
		{

			if (map->tile[mapY][mapX] != 0)
			{
			//graphics::drawImage(gBrickImage, x, y,gScreenSurface);
				 
				SDL_Rect r;
				r.x = x;
				r.y = y;
				r.w = TILE_SIZE ;
				r.h = TILE_SIZE ;
				SDL_RenderCopy(gRenderer, gBrickTex, NULL, &r);

				
				

			}

			mapX++;
		}

		mapY++;
	}
	SDL_SetRenderTarget(gRenderer, NULL);
	SDL_RenderPresent(gRenderer);





}

void delay(unsigned int frameLimit)
{
	unsigned int ticks = SDL_GetTicks();

	if (frameLimit < ticks) return;

	if (frameLimit > ticks + standardDelay) SDL_Delay(standardDelay);

	else { SDL_Delay(frameLimit - ticks); }
	
}
