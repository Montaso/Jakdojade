#pragma once
#include "Position.h"

class RoadNode
{
	Position roadPos;
	int distanceTraveled;
	RoadNode* next;
public:
	RoadNode();
	RoadNode(const Position& pos);
	RoadNode(const Position& pos, const int& distance);

	RoadNode* GetNext() const;
	int GetRow() const;
	int GetCol() const;
	const Position& GetPos() const;
	int GetDistance() const;

	void SetNext(RoadNode* newNext);
};

class RoadQueue
{
	RoadNode* head;
	RoadNode* end;
	int size;
public:
	RoadQueue();

	const int& Size() const;

	void Enqueue(RoadNode* newNode);
	void Enqueue(const Position& newPos);
	void Enqueue(const Position& newPos, const int& distance);

	void Dequeue();
	RoadNode* Peek();
};

