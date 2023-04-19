#include <iostream>
#include "String.h"
#include "City.h"
#include "Connection.h"
#include "Hashmap.h"

using namespace std;

int main()
{
	Hashmap abc;
	abc.Insert(new City("1miasteczko1"));
	abc.Insert(new City("1miasteczko1"));
	abc.Insert(new City("1miasteczko2"));
	abc.Insert(new City("2miasto2"));

	for (int i = 0; i < HASHMAP_ARR_SIZE; i++)
	{
		if (abc[i]->IsOccupied()) cout << abc[i]->GetSize() << endl;
	}

	return 0;
}