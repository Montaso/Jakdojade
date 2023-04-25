#pragma once
#include <iostream>
#include "String.h"
#include "Hashmap.h"
#include "RoadQueue.h"
#include "PositionVector.h"

class WorldMap
{
	int rows;
	int cols;
	char** worldMap;
	City*** citiesMap;
	Hashmap cities;

	bool** visitedRoad;
public:
	WorldMap(const int& rows, const int& cols);
	
	char GetWorldField(const int& x, const int& y);

	void LoadMap();
	void ReadCities();
	void ReadConnections();

	String FindCityName(const int& x, const int& y);
	bool IsInside(const int& x, const int& y);
	bool IsNameChar(const char& sign);
	bool IsNameStart(const int& x, const int& y);
	bool IsVisitedRoad(const int& x, const int& y);

	void FindNeighboursBFS(const Position& startPos);
	void Draw();

	~WorldMap();
};

