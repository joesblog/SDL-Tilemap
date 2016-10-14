#include "main.h"

extern void delay(unsigned int);
extern int standardDelay = 16;
extern SDL_Surface* gScreenSurface;
extern SDL_Renderer* gRenderer;
extern SDL_Renderer* gTRenderer;

extern SDL_Surface* gBackgroundImage;
extern SDL_Surface* gBrickImage;
extern SDL_Texture* gBackgroundTex;
extern SDL_Texture* gBrickTex;

extern SDL_Texture* gBigTexture;
extern Uint32 pixelFormat;

extern SDL_Rect gBrickSrcR;
extern SDL_Rect gBackgroundSrcR;
extern SDL_Rect gDestSrcR;
extern unsigned int frameLimit;

bool quit = false;

int wmain(int argc, char* argv)
{
	main(argc, argv);
}



int main(int argc, char* argv)
{

	 

	if (!init())
	{

		printf("failed to init\n");
	}
	 


	mainloop();

 
	close();
	return 0;
}


void mainloop() {
	while (!quit)
	{
		input.getInput();
	
		input.doMap(map);

		drawMap(map);
		draw(gScreenSurface, map);

		delay(frameLimit);

	/*	SDL_FillRect(gScreenSurface, NULL, SDL_MapRGB(gScreenSurface->format, 0xFF, 0x22, 0xFF));
		SDL_BlitScaled(gBackgroundImage, NULL, gScreenSurface, &stretchrect);*/
		//SDL_UpdateWindowSurface(gWindow);

	}

}
bool loadmedia()
{
	bool success = true;

	gBackgroundImage = graphics::loadSurface("C:\\_temp\\tutorial12\\gfx\\background.png");
	if (gBackgroundImage == NULL)
	{
	
		printf("failed to load background image!");
		quit = true;
	}
	;
	gBackgroundTex = graphics::loadTexture("C:\\_temp\\tutorial12\\gfx\\background.png");


	gBrickImage = graphics::loadSurface("C:\\_temp\\tutorial12\\gfx\\brick.png");
	if (gBrickImage == NULL)
	{

		printf("failed to load brick image!");
		quit = true;
	}
	gBrickTex = graphics::loadTexture("C:\\_temp\\tutorial12\\gfx\\brick.png");
//	SDL_SetTextureBlendMode(gBrickTex, SDL_BLENDMODE_BLEND);

	gBrickSrcR.x = 0;
	gBrickSrcR.y = 0;
	gBrickSrcR.w = TILE_SIZE;
	gBrickSrcR.h = TILE_SIZE;





	gBackgroundSrcR.x = 0;
	gBackgroundSrcR.y = 0;
	gBackgroundSrcR.w = SCREEN_WIDTH;
	gBackgroundSrcR.h = SCREEN_HEIGHT;
	return success;
}
 
bool init()
{
	frameLimit = SDL_GetTicks() + standardDelay;

	bool resSuccess = true; 
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		resSuccess = false;
		printf("Could not init video\n");
	}
	else {
		gWindow = SDL_CreateWindow("Untitled", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			resSuccess = false;
			printf("Could not create window\n");

		}
		else {
			gScreenSurface = SDL_GetWindowSurface(gWindow);
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
		 


			map = new Map();

			map->loadMap("C:\\_temp\\map01.dat");

			loadmedia();


			
		}

	}


	return resSuccess;
}

extern void  close()
{
	SDL_DestroyWindow(gWindow);
	SDL_Quit();
	exit(0);

}