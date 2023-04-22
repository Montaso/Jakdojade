#pragma once
#include "City.h"

#define HASHMAP_ARR_SIZE 100
class Hashmap
{
	City_List** cityListArr;
	int Hash(const String& key);

public:
	Hashmap();
	
	void Insert(City* newCity);
	City_List* operator[] (const size_t& index) const;

	~Hashmap();
};

