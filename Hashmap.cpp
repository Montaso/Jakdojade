#include "Hashmap.h"

int Hashmap::Hash(const String& key)
{
	int hash_val = 0;
	for (int i = 0; i < key.Size(); i++)
	{
		hash_val += key[i];
	}
	return hash_val % key.Size();
}

Hashmap::Hashmap()
{
	cityListArr = new City_List*[HASHMAP_ARR_SIZE];

	for (int i = 0; i < HASHMAP_ARR_SIZE; i++)
	{
		cityListArr[i] = nullptr;
	}
}

void Hashmap::Insert(City* newCity)
{
	int index = Hash(newCity->GetName().getVal());
	if (cityListArr[index] != nullptr)
	{
		cityListArr[index]->pushBack(newCity);
	}
	else
	{
		cityListArr[index] = new City_List(newCity);
	}
}

City_List* Hashmap::operator[](const size_t& index) const
{
	return cityListArr[index];
}

Hashmap::~Hashmap()
{
	for (int i = 0; i < HASHMAP_ARR_SIZE; i++)
	{
		if (cityListArr[i] != nullptr)
		{
			delete cityListArr[i];
		}
	}
	delete[] cityListArr;
}
