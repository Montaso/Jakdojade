#include <iostream>
#include <chrono>
#include "String.h"
#include "City.h"
#include "Connection.h"
#include "Hashmap.h"
#include "WorldMap.h"
#include "RoadQueue.h"
#include "PositionVector.h"

//using namespace std::chrono;

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

	int rows, cols;
	std::cin >> cols >> rows;
	
	WorldMap worldMap(rows, cols);

	auto start = std::chrono::high_resolution_clock::now();
	worldMap.LoadMap();
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Time taken by function LoadMap(): " << duration.count() << " microseconds" << std::endl;
	
	worldMap.ReadCities();
	auto stop2 = std::chrono::high_resolution_clock::now();
	auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - stop);
	std::cout << "Time taken by function ReadCities(): " << duration2.count() << " microseconds" << std::endl;

	worldMap.ReadConnections();
	auto stop3 = std::chrono::high_resolution_clock::now();
	auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(stop3 - stop2);
	std::cout << "Time taken by function ReadConnections(): " << duration3.count() << " microseconds" << std::endl;
	

	worldMap.ReadFlights();
	auto stop4 = std::chrono::high_resolution_clock::now();
	auto duration4 = std::chrono::duration_cast<std::chrono::microseconds>(stop4 - stop3);
	std::cout << "Time taken by function ReadFlights(): " << duration4.count() << " microseconds" << std::endl;

	//std::cout << std::endl;
	//worldMap.Draw();
	return 0;
}