#include <iostream>
#include <chrono>
#include "String.h"
#include "City.h"
#include "Connection.h"
#include "Hashmap.h"
#include "WorldMap.h"
#include "RoadQueue.h"
#include "PositionVector.h"

using namespace std::chrono;

int main()
{
	/*PositionVector testArr;
	for (int i = 0; i < 10000; i++)
	{
		testArr.Insert({ 1, 1 });
	}*/
	/*RoadQueue testQ;
	PositionB a = { 0,0 }, b = { 5,5 };

	testQ.Enqueue(a);
	testQ.Enqueue(b);
	testQ.Dequeue();

	RoadNode* peek = testQ.Peek();
	testQ.Dequeue();*/

	auto start = high_resolution_clock::now();
	int rows, cols;
	std::cin >> cols >> rows;
	
	WorldMap worldMap(rows, cols);
	worldMap.LoadMap();
	worldMap.ReadCities();
	worldMap.ReadConnections();
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	std::cout << std::endl;
	std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;
	//worldMap.Draw();
	return 0;
}