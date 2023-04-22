#include "City.h"
#include <iostream>

City::City() : name(""), next(nullptr) {}
City::City(const String& name) : name(name), next(nullptr) {}
City::City(const char*& name) : name(name), next(nullptr) {}

void City::AddConnection(const Connection& newConnection)
{
	connections.pushBack(newConnection);
}
void City::AddConnection(City* city, const int& roadLength)
{
	Connection* newConnection = new Connection(city, roadLength);
	connections.pushBack(*newConnection);
}
City* City::GetNext() const
{
	return this->next;
}
const String& City::GetName() const
{
	return this->name;
}

void City::SetNext(City*& nextCity)
{
	this->next = nextCity;
}

City::~City()
{
	
};

City_List::City_List() : head(nullptr), size(0) {};
City_List::City_List(City*& headCity) : head(headCity), size(1) {}

void City_List::pushBack(City* newCity)
{
	if (this->head == nullptr)
	{
		this->head = newCity;
	}
	else
	{
		City* tmp = this->head;
		while (tmp->GetNext() != nullptr)
		{
			tmp = tmp->GetNext();
		}
		tmp->SetNext(newCity);
	}
	this->size++;
}

City* City_List::operator[](const size_t& index) const
{
	//if (head == nullptr) return nullptr;
	int tmpIndex = index;
	City* tmp = head;
	
	for (int i = 0; i < tmpIndex; i++)
	{
		if (tmp == nullptr) return nullptr;
		tmp = tmp->GetNext();
	}
	return tmp;
}

bool City_List::IsOccupied() const
{
	if (this->head == nullptr) return false;
	else return true;
}

const int& City_List::GetSize() const
{
	return this->size;
}

City_List::~City_List() 
{
	City* tmp = head;
	while (tmp != nullptr)
	{
		City* next = tmp->GetNext();
		delete tmp;
		tmp = next;
	}
};
