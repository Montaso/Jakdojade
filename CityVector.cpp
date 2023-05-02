#include "CityVector.h"

CityVector::CityVector()
{
	cities = nullptr;
	size = 0;
	maxSize = 1;
}

int CityVector::Size() const
{
	return size;
}

City* CityVector::operator[](const size_t& index) const
{
	return cities[index];
}

void CityVector::AddBuffer()
{
	maxSize *= 2;
	City** tmp = cities;

	this->cities = new City * [maxSize];
	for (int i = 0; i < size; i++)
	{
		this->cities[i] = tmp[i];
		//tmp[i] = nullptr;
	}
	delete[] tmp;
}

void CityVector::Insert(City* newCity)
{
	if (size == 0)
	{
		cities = new City* [1];
	}
	else if (size == maxSize)
	{
		AddBuffer();
	}
	cities[size] = newCity;
	size += 1;
}

CityVector::~CityVector()
{
	delete[] cities;
}
