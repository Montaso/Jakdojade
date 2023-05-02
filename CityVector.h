#pragma once
#include "City.h"

class CityVector
{
	City** cities;
	int size;
	int maxSize;

public:
	CityVector();

	int Size() const;
	City* operator[](const size_t& index) const;

	void AddBuffer();
	void Insert(City* newCity);

	~CityVector();
};

