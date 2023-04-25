#pragma once
#include "Position.h"

class PositionVector
{
	Position* pos;
	int size;
	int maxSize;

public:
	PositionVector();

	int Size() const;
	Position& operator[](const size_t& index) const;
	void AddBuffer();
	void Insert(const Position& newPos);

	~PositionVector();
};

