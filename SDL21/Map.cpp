#include "Map.h"
#include "globs.h"

Map::Map()
{


}
 
void Map::loadMap(char* name)
{
	FILE *fp;

	int x, y;
	
	fp = fopen(name, "r");


	if (fp == NULL)
	{
		printf("Failed to open map %s\n", name);

		quit = true;
	}
	else {
	
		for (y = 0; y < MAX_MAP_Y; y++)
		{
			for (x = 0; x < MAX_MAP_X; x++)
			{

				fscanf(fp, "%d", &tile[y][x]);

			}
		}
	 
		startX = startY = 0;
		maxX = MAX_MAP_X * TILE_SIZE;
		maxY = MAX_MAP_Y * TILE_SIZE;

		fclose(fp);
	}


}



Map::~Map()
{
}
