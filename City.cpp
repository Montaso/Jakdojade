#include "City.h"
#include <iostream>

City::City() : name(""), next(nullptr), x(-1), y(-1), connections(nullptr), visited(false), sourceCity(nullptr), distance(-1) {}
City::City(const String& name) : name(name), next(nullptr), x(-1), y(-1), connections(nullptr), visited(false), sourceCity(nullptr), distance(-1) {}
City::City(const char*& name) : name(name), next(nullptr), x(-1), y(-1), connections(nullptr), visited(false), sourceCity(nullptr), distance(-1) {}
City::City(const String& name, const int& x, const int& y) : name(name), next(nullptr), x(x), y(y), connections(nullptr), visited(false), sourceCity(nullptr), distance(-1) {}
City::City(const char*& name, const int& x, const int& y) : name(name), next(nullptr), x(x), y(y), connections(nullptr), visited(false), sourceCity(nullptr), distance(-1) {}

void City::AddConnection(const Connection& newConnection)
{
	if (connections == nullptr)
	{
		connections = new Connection_List();
	}
	connections->pushBack(newConnection);
}
void City::AddConnection(City* source, City* city, const int& roadLength)
{
	if (connections == nullptr)
	{
		connections = new Connection_List();
	}
	Connection* newConnection = new Connection(source, city, roadLength);
	connections->pushBack(newConnection);
}
City* City::GetNext() const
{
	return this->next;
}
const String& City::GetName() const
{
	return this->name;
}

Connection_List* City::GetConnections() const
{
	return connections;
}

const bool& City::Visited() const
{
	return visited;
}

const int& City::GetDistance() const
{
	return distance;
}

City* City::GetSourceCity() const
{
	return sourceCity;
}

void City::SetNext(City*& nextCity)
{
	this->next = nextCity;
}

void City::SetVisited(const bool& isVisited)
{
	visited = isVisited;
}

void City::SetDistance(const int& newDist)
{
	this->distance = newDist;
}

void City::SetSourceCity(City* newSourceCity)
{
	sourceCity = newSourceCity;
}

City::~City()
{
	if (connections != nullptr)
	{
		delete connections;
	}
};

City_List::City_List() : head(nullptr), last(nullptr), size(0) {};
City_List::City_List(City*& headCity) : head(headCity), last(headCity), size(1) {}

void City_List::pushBack(City* newCity)
{
	if (this->head == nullptr)
	{
		this->head = newCity;
		this->last = newCity;
	}
	else
	{
		City* tmp = this->last;
		tmp->SetNext(newCity);
		this->last = tmp->GetNext();
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

City* City_List::operator[](const String& cityName) const
{
	City* tmp = head;
	while (tmp != nullptr)
	{
		if (tmp->GetName() == cityName) return tmp;
		tmp = tmp->GetNext();
	}
	return nullptr;
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
