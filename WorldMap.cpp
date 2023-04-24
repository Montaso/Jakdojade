#include "WorldMap.h"

WorldMap::WorldMap(const int& rows, const int& cols) : rows(rows), cols(cols), cities()
{
	worldMap = new char* [rows];

	for (int i = 0; i < rows; i++)
	{
		worldMap[i] = new char[cols];
	}
}

void WorldMap::LoadMap()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cin >> worldMap[i][j];
			/*if (worldMap[i][j] == '*')
			{
				String name = FindCityName(j, i);
				cities.Insert(new City(name, j, i));
			}*/
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
				cities.Insert(new City(name, j, i));
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
