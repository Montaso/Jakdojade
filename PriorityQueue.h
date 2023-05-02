#pragma once
#include "Connection.h"
#include <iostream>

class PriorityQueue
{
	Connection* connections;
	int size;
	int maxSize;
public:
	PriorityQueue();

	int Size() const;
	const int& Parent(const int& index) const;
	const int& Left(const int& index) const;
	const int& Right(const int& index) const;
	void Swap(const int& index1, const int& index2);

	void AddBuffer();
	void Enqueue(const Connection& connection);
	void Dequeue();
	void Heapify(const int& index);

	const Connection& Peek();
};

