#include "Hashmap.h"

int Hashmap::Hash(const String& key) const
{
	long long int hash_val = 0;
	int base = 'Z' - 'A' + 1;
	int exp = 0;
	int poweredNmb;
	for (int i = 0; key[i] != '\0'; i++)
	{
		char sign = key[i];
		poweredNmb = base;
		for (int j = 0; j < exp; j++)
		{
			poweredNmb = poweredNmb * base;
		}

		if (sign >= '0' and sign <= '9')
		{
			hash_val += (sign - '0') * poweredNmb;
		}
		else
		{
			hash_val += (sign - 'A' + 10) * poweredNmb;
		}
		exp = (i + 1) % 3;
		/*if (sign >= '0' and sign <= '9')
		{
			hash_val += (sign - '0') * (i + 1) * 1009;
		}
		else
		{
			hash_val += (sign - 'A' + 10) * (i + 1) * 1009;
		}*/
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

City* Hashmap::FindCity(const String& cityName) const
{
	int index = Hash(cityName);
	if (cityListArr[index]->GetSize() == 1)
	{
		return (*cityListArr[index])[0];
	}
	else if (cityListArr[index]->GetSize() >= 1)
	{
		return (*cityListArr[index])[cityName];
	}
	else return nullptr;
}

City_List* Hashmap::operator[](const size_t& index) const
{
	return cityListArr[index];
}

void Hashmap::WriteListSizes()
{
	int cnt = 0;
	for (int i = 0; i < HASHMAP_ARR_SIZE; i++)
	{
		if (cityListArr[i] != nullptr)
		{
			cnt++;
			std::cout << cityListArr[i]->GetSize() << std::endl;
		}
	}
	//std::cout << cnt << std::endl;
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
