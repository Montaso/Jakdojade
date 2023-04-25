#include "WorldMap.h"

WorldMap::WorldMap(const int& rows, const int& cols) : rows(rows), cols(cols), cities()
{
	worldMap = new char* [rows];
	citiesMap = new City** [rows];
	visitedRoad = new bool* [rows];

	for (int i = 0; i < rows; i++)
	{
		worldMap[i] = new char[cols];
		citiesMap[i] = new City* [cols];
		visitedRoad[i] = new bool[cols];
		for (int j = 0; j < cols; j++)
		{
			visitedRoad[i][j] = false;
		}
	}
}

char WorldMap::GetWorldField(const int& x, const int& y)
{
	return worldMap[y][x];
}

void WorldMap::LoadMap()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cin >> worldMap[i][j];
			citiesMap[i][j] = nullptr;
		}
	}
}

void WorldMap::ReadCities()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (worldMap[i][j] == '*')
			{
				String name = FindCityName(j, i);
				City* newCity = new City(name, j, i);
				cities.Insert(newCity);
				citiesMap[i][j] = newCity;
			}
		}
	}
}

void WorldMap::ReadConnections()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (citiesMap[i][j] != nullptr)
			{
				FindNeighboursBFS({j, i});
			}
		}
	}
}

String WorldMap::FindCityName(const int& x, const int& y)
{
	String name;
	bool reverse = false;
	Position positions[8] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1} };

	for (auto p : positions)
	{
		if (IsInside(x + p.x, y + p.y) && IsNameStart(x + p.x, y + p.y))
		{
			for (int i = 0; IsInside(x + p.x + i, y + p.y) && IsNameChar(worldMap[y + p.y][x + p.x + i]); i++)
			{
				name += worldMap[y + p.y][x + p.x + i];
			}
			for (int i = -1; IsInside(x + p.x + i, y + p.y) && IsNameChar(worldMap[y + p.y][x + p.x + i]); i--)
			{
				name += worldMap[y + p.y][x + p.x + i];
				reverse = true;
			}
			if (reverse)
			{
				for (int i = 0; i < name.Size() / 2; i++)
				{
					char tmp = name[i];
					name[i] = name[name.Size() - i - 2];
					name[name.Size() - i - 2] = tmp;
				}
			}
			return name;
		}
	}
	return name;
}

bool WorldMap::IsInside(const int& x, const int& y)
{
	if (x >= cols || y >= rows || x < 0 || y < 0) return false;
	return true;
}

bool WorldMap::IsNameChar(const char& sign)
{
	if (sign >= '0' && sign <= '9') return true;
	else if (sign >= 'A' && sign <= 'Z') return true;
	return false;
}

bool WorldMap::IsNameStart(const int& x, const int& y)
{
	bool leftCh = false, rightCh = false;
	if (!IsNameChar(worldMap[y][x])) return false;
	else
	{
		if (IsInside(x + 1, y))
		{
			if (IsNameChar(worldMap[y][x + 1]))
			{
				rightCh = true;
			}
		}
		if (IsInside(x - 1, y))
		{
			if (IsNameChar(worldMap[y][x - 1]))
			{
				leftCh = true;
			}
		}
		if (leftCh == true && rightCh == true) return false;
	}
	return true;
}

bool WorldMap::IsVisitedRoad(const int& x, const int& y)
{
	if (worldMap[y][x] != '#') return true;
	else if (visitedRoad[y][x] == true) return true;
	return false;
}

void WorldMap::FindNeighboursBFS(const Position& startPos)
{
	RoadQueue queue;
	PositionVector visitedPositions;
	Position directions[4] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };

	queue.Enqueue(startPos);
	visitedPositions.Insert(startPos);

	while (queue.Size() != 0)
	{
		
		for (auto d : directions)
		{
			//Position newPos = { startPos.x + d.x, startPos.y + d.y };
			Position newPos = queue.Peek()->GetPos();
			newPos.x += d.x;
			newPos.y += d.y;

			if (IsInside(newPos.x, newPos.y))
			{
				if (IsVisitedRoad(newPos.x, newPos.y) == false)
				{
					queue.Enqueue(newPos, queue.Peek()->GetDistance() + 1);
					visitedPositions.Insert(newPos);
					visitedRoad[newPos.y][newPos.x] = true;
				}
				else if(worldMap[newPos.y][newPos.x] == '*' && !(newPos.x == startPos.x && newPos.y == startPos.y))
				{
					citiesMap[startPos.y][startPos.x]->AddConnection(citiesMap[newPos.y][newPos.x], queue.Peek()->GetDistance()+1);
					std::cout << "new connection from: (" << startPos.x << ", " << startPos.y << ") to (" <<
						newPos.x << ", " << newPos.y << ") with length: " << queue.Peek()->GetDistance() + 1 << std::endl;
				}
			}
		}
		queue.Dequeue();
	}

	for (int i = 0; i < visitedPositions.Size(); i++)
	{
		Position p = visitedPositions[i];
		visitedRoad[p.y][p.x] = false;
	}
	/*for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << visitedRoad[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;*/
}

void WorldMap::Draw()
{
	/*for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << worldMap[i][j];
		}
		std::cout << std::endl;
	}*/
	cities.WriteListSizes();
}

WorldMap::~WorldMap()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] worldMap[i];
		delete[] visitedRoad[i];
		delete[] citiesMap[i];
	}
	delete[] worldMap;
	delete[] visitedRoad;
	delete[] citiesMap;
}
