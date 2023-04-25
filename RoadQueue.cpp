#include "RoadQueue.h"

RoadNode::RoadNode() : roadPos({ -1,-1 }), next(nullptr), distanceTraveled(0) {};
RoadNode::RoadNode(const Position& pos) : roadPos(pos), next(nullptr), distanceTraveled(0) {};
RoadNode::RoadNode(const Position& pos, const int& distance) : roadPos(pos), next(nullptr), distanceTraveled(distance) {};

RoadNode* RoadNode::GetNext() const
{
	return next;
}

int RoadNode::GetRow() const
{
	return roadPos.y;
}

int RoadNode::GetCol() const
{
	return roadPos.x;
}

const Position& RoadNode::GetPos() const
{
	return roadPos;
}

int RoadNode::GetDistance() const
{
	return distanceTraveled;
}

void RoadNode::SetNext(RoadNode* newNext)
{
	this->next = newNext;
}

RoadQueue::RoadQueue() : head(nullptr), end(nullptr), size(0) {}
const int& RoadQueue::Size() const
{
	return size;
}
;

void RoadQueue::Enqueue(RoadNode* newNode)
{
	RoadNode* tmp = end;
	if (tmp == nullptr)
	{
		this->head = newNode;
		this->end = newNode;
	}
	else
	{
		end->SetNext(newNode);
		this->end = newNode;
	}
	this->size++;
}

void RoadQueue::Enqueue(const Position& newPos)
{
	RoadNode* newNode = new RoadNode(newPos);
	RoadNode* tmp = end;
	if (tmp == nullptr)
	{
		this->head = newNode;
		this->end = newNode;
	}
	else
	{
		end->SetNext(newNode);
		this->end = newNode;
	}
	this->size++;
}

void RoadQueue::Enqueue(const Position& newPos, const int& distance)
{
	RoadNode* newNode = new RoadNode(newPos, distance);
	RoadNode* tmp = end;
	if (tmp == nullptr)
	{
		this->head = newNode;
		this->end = newNode;
	}
	else
	{
		end->SetNext(newNode);
		this->end = newNode;
	}
	this->size++;
}

void RoadQueue::Dequeue()
{
	RoadNode* tmp = head;
	if (tmp == nullptr) return;
	else
	{
		this->head = tmp->GetNext();
		delete[] tmp;
	}
	this->size--;
}

RoadNode* RoadQueue::Peek()
{
	return this->head;
}
