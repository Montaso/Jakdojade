#pragma once
#include "String.h";
#include "Connection.h"

class City
{
	String name;
	int x, y;
	Connection_List* connections;
	City* next;

public:
	City();
	City(const String& name);
	City(const char*& name);
	City(const String& name, const int& x, const int& y);
	City(const char*& name, const int& x, const int& y);

	void AddConnection(const Connection& newConnection);
	void AddConnection(City* city, const int& roadLength);

	City* GetNext() const;
	const String& GetName() const;

	void SetNext(City*& nextCity);

	~City();
};

class City_List
{
	City* head;
	City* last;
	int size;
public:
	City_List();
	City_List(City*& headCity);

	void pushBack(City* newCity);

	City* operator[](const size_t& index) const;
	City* operator[](const String& cityName) const;

	bool IsOccupied() const;

	const int& GetSize() const;

	~City_List();
};

