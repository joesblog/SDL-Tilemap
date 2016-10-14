#pragma once
#include "globs.h"
class Map
{

public:
	int startX, startY;
	int maxX, maxY;
	int tile[MAX_MAP_Y][MAX_MAP_X];
	Map( );
	void loadMap(char* name);

	~Map();
 

};

