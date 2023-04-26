#pragma once
#include "City.h"

#define HASHMAP_ARR_SIZE 10099 //10099
class Hashmap
{
	City_List** cityListArr;
	int Hash(const String& key) const;

public:
	Hashmap();
	
	void Insert(City* newCity);

	City* FindCity(const String& cityName) const;
	City_List* operator[] (const size_t& index) const;

	void WriteListSizes();
	~Hashmap();
};

