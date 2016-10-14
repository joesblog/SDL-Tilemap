#pragma once
#include "globs.h" 
#include "Map.h"
class Input
{
	 
	int left, right, up, down;

public:
	Input();
	~Input();
	void getInput();
	void doMap(Map* map);
};