#include "Hashmap.h"

int Hashmap::Hash(const String& key)
{
	int hash_val = 0;
	for (int i = 0; key[i] != '\0'; i++)
	{
		char sign = key[i];
		if (sign >= '0' and sign <= '9')
		{
			hash_val += (sign - '0') * i;
		}
		else
		{
			hash_val += (sign - 'A' + 10) * i;
		}
		
	}
	return hash_val % HASHMAP_ARR_SIZE;
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

void Hashmap::WriteListSizes()
{
	for (int i = 0; i < HASHMAP_ARR_SIZE; i++)
	{
		if (cityListArr[i] != nullptr)
		{
			std::cout << cityListArr[i]->GetSize() << std::endl;
		}
	}
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
