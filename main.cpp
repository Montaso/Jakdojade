#include <iostream>
#include "String.h"
#include "City.h"
#include "Connection.h"
#include "Hashmap.h"

char** LoadMap(int rows, int cols)
{
	char** worldArr = new char*[rows];

	for (int i = 0; i < rows; i++)
	{
		worldArr[i] = new char[cols];

		for (int j = 0; j < cols; j++)
		{
			std::cin >> worldArr[i][j];
		}
	}
	return worldArr;
}


int main()
{
	Hashmap abc;
	abc.Insert(new City("1miasteczko1"));
	abc.Insert(new City("1miasteczko1"));
	abc.Insert(new City("1miasteczko2"));
	abc.Insert(new City("2miasto2"));

	int rows, cols;
	std::cin >> rows >> cols;
	char** worldMap = LoadMap(rows, cols);
	
	return 0;
}