#include "PositionVector.h"

#define VECTOR_START_BUFOR 1
#define VECTOR_INCREASE_NUMBER 2

PositionVector::PositionVector()
{
	pos = nullptr;
	size = 0;
	maxSize = 1;
}

int PositionVector::Size() const
{
	return size;
}

Position& PositionVector::operator[](const size_t& index) const
{
	return pos[index];
}

void PositionVector::AddBuffer()
{
	maxSize *= VECTOR_INCREASE_NUMBER;
	Position* tmp = pos;
	this->pos = new Position[maxSize];

	for (int i = 0; i < size; i++)
	{
		this->pos[i] = tmp[i];
	}
	delete[] tmp;
}

void PositionVector::Insert(const Position& newPos)
{
	if (size == 0)
	{
		pos = new Position[VECTOR_START_BUFOR];
	}
	else if (size == maxSize)
	{
		AddBuffer();
	}
	pos[size] = newPos;
	size += 1;
}

PositionVector::~PositionVector()
{
	delete[] pos;
}
