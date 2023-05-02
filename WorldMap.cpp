#include "WorldMap.h"
#define CHAR_ARR_BUFOR 64

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
			char newChar = getchar();
			if (isspace(newChar))
			{
				j--;
				continue;
			}
			worldMap[i][j] = newChar;
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
				//String name = "";
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

void WorldMap::ReadFlights()
{
	int flights;
	std::cin >> flights;
	//char* name1 = new char[CHAR_ARR_BUFOR];
	//char* name2 = new char[CHAR_ARR_BUFOR];
	//char* dstc = new char[CHAR_ARR_BUFOR];

	getchar();
	for (int i = 0; i < flights; i++)
	{
		
		//ReadCityName(name1);
		//ReadCityName(name2);

		//std::cin >> name1;
		//std::cin >> name2;
		//ReadCityName(dstc);
		//getchar();
		String name1_S = ReadCityName();
		String name2_S = ReadCityName();
		String distance = ReadCityName();
		int distanceI = distance.toNumber();
		
		//String name1_S(name1);
		//String name2_S(name2);
		
		City* left = cities.FindCity(name1_S);
		City* right = cities.FindCity(name2_S);
		
		left->AddConnection(left, right, distanceI);

		//if ((i+1) % 100000 == 0) printf("%d\n", i+1);
		//printf("added connection between: %s, and %s\n", name1.getVal(), name2.getVal());
		/*printf("%s\n", name1.getVal());
		printf("%s\n", name2.getVal());
		printf("%d\n\n", distanceI);*/
	}
	//delete[] name1;
	//delete[] name2;
	//delete[] dstc;
}

void WorldMap::FindPaths()
{
	int count;
	std::cin >> count;
	getchar();
	for (int i = 0; i < count; i++)
	{
		String name1 = ReadCityName();
		String name2 = ReadCityName();
		char mode = getchar();
		getchar();

		City* left = cities.FindCity(name1);
		City* right = cities.FindCity(name2);
		DijkstraPathFind(left, right, mode);
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

String WorldMap::ReadCityName()
{
	String newName;
	char newChar;
	while (true)
	{
		newChar = getchar();
		if (!isspace(newChar))
		{
			newName += newChar;
		}
		else
		{
			break;
		}
	}
	return newName;
}

void WorldMap::ReadCityName(char* cityName)
{
	int i = 0;
	//char tmp;
	while (true)
	{
		cityName[i] = getchar();
		//tmp = getchar();
		if (cityName[i] == ' ' || cityName[i] == '\n')
		{
			cityName[i] = '\0';
			break;
		}
		else
		{
			i++;
		}
	}
	//return cityName;
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
				}
				else if(visitedRoad[newPos.y][newPos.x] == false && worldMap[newPos.y][newPos.x] == '*' && !(newPos.x == startPos.x && newPos.y == startPos.y))
				{
					citiesMap[startPos.y][startPos.x]->AddConnection(citiesMap[startPos.y][startPos.x], citiesMap[newPos.y][newPos.x], queue.Peek()->GetDistance()+1);
					//std::cout << "new connection from: (" << startPos.x << ", " << startPos.y << ") to (" <<
						//newPos.x << ", " << newPos.y << ") with length: " << queue.Peek()->GetDistance() + 1 << std::endl;
				}
				visitedPositions.Insert(newPos);
				visitedRoad[newPos.y][newPos.x] = true;
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

void WorldMap::DijkstraPathFind(City* from, City* destination, char mode)
{
	PriorityQueue prioQ;
	CityVector visited;
	CityVector output;

	City* currentCity;
	City* destinationCity;
	City* sourceCity;
	Connection_List* citiesConnections = from->GetConnections();
	if (citiesConnections == nullptr)
	{
		std::cout << '0' << std::endl;
		return;
	}
	Connection* tmp = citiesConnections->GetHead();

	while (tmp != nullptr)
	{
		prioQ.Enqueue(*tmp);
		tmp = tmp->GetNext();
	}
	visited.Insert(from);
	from->SetVisited(true);
	from->SetSourceCity(nullptr);
	from->SetDistance(0);

	while (prioQ.Size() > 0)
	{
		currentCity = prioQ.Peek().GetConnectedCity();
		sourceCity = prioQ.Peek().GetSourceCity();
		if (currentCity->GetDistance() == -1)
		{
			int possibleDistance = prioQ.Peek().GetLength();
			currentCity->SetSourceCity(sourceCity);
			currentCity->SetDistance(possibleDistance);
		}
		else if (currentCity->GetDistance() > prioQ.Peek().GetLength())
		{
			currentCity->SetSourceCity(sourceCity);
			currentCity->SetDistance(prioQ.Peek().GetLength());
		}

		if (!currentCity->Visited())
		{
			citiesConnections = currentCity->GetConnections();
			if (citiesConnections != nullptr)
			{
				tmp = citiesConnections->GetHead();
				while (tmp != nullptr)
				{
					destinationCity = tmp->GetConnectedCity();
					if (!destinationCity->Visited())
					{
						Connection newCon = *tmp;
						newCon.SetDistance(newCon.GetLength() + currentCity->GetDistance());
						prioQ.Enqueue(newCon);
					}
					tmp = tmp->GetNext();
				}
			}
			visited.Insert(currentCity);
			currentCity->SetVisited(true);
		}
		prioQ.Dequeue();
	}

	City* tmpCity = destination->GetSourceCity();
	if (tmpCity == nullptr)
	{
		mode = '0';
	}
	switch (mode)
	{
	case '0':
		std::cout << destination->GetDistance() << std::endl;
		break;
	case '1':
		do
		{
			output.Insert(tmpCity);
			tmpCity = tmpCity->GetSourceCity();
		} while (tmpCity != nullptr);

		std::cout << destination->GetDistance() << ' ';
		for (int i = output.Size() - 2; i >= 0; i--)
		{
			std::cout << output[i]->GetName().getVal() << ' ';
		}
		std::cout << std::endl;

		break;
	}

	for (int i = 0; i < visited.Size(); i++)
	{
		visited[i]->SetVisited(false);
		//std::cout << "Miasto: " << visited[i]->GetName().getVal() << ' ' << visited[i]->GetDistance() << std::endl;
		visited[i]->SetDistance(-1);
		visited[i]->SetSourceCity(nullptr);
	}
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
