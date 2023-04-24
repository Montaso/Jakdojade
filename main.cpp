#include <iostream>
#include <chrono>
#include "String.h"
#include "City.h"
#include "Connection.h"
#include "Hashmap.h"
#include "WorldMap.h"

using namespace std::chrono;

int main()
{
	//Hashmap abc;
	//abc.Insert(new City("1miasteczko1"));
	//abc.Insert(new City("1miasteczko1"));
	//abc.Insert(new City("1miasteczko2"));
	//abc.Insert(new City("2miasto2"));
	auto start = high_resolution_clock::now();
	int rows, cols;
	std::cin >> cols >> rows;
	
	std::cout << "start worldMap" << std::endl;
	WorldMap worldMap(rows, cols);
	std::cout << "start loadMap" << std::endl;
	worldMap.LoadMap();
	std::cout << "start readCities" << std::endl;
	worldMap.ReadCities();
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	/*char** worldMap = LoadMap(rows, cols);*/
	std::cout << std::endl;
	std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;
	//worldMap.Draw();
	return 0;
}