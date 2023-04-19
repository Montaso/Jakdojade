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
	cityListArr = new City_List[HASHMAP_ARR_SIZE];
}

void Hashmap::Insert(City* newCity)
{
	int index = Hash(newCity->GetName().getVal());
	if (cityListArr[index].IsOccupied())
	{
		cityListArr[index].pushBack(newCity);
	}
	else
	{
		cityListArr[index] = newCity;
	}
}

City_List* Hashmap::operator[](const size_t& index) const
{
	return &cityListArr[index];
}
