#pragma once
#include <iostream>
#include "String.h"
#include "Hashmap.h"

struct Position
{
	int x, y;
};

class WorldMap
{
	int rows;
	int cols;
	char** worldMap;
	Hashmap cities;

public:
	WorldMap(const int& rows, const int& cols);
	
	void LoadMap();
	void ReadCities();

	String FindCityName(const int& x, const int& y);
	bool IsInside(const int& x, const int& y);
	bool IsNameChar(const char& sign);
	bool IsNameStart(const int& x, const int& y);
	
	void Draw();
};

