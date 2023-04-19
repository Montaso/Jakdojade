#pragma once
#include "String.h";
#include "Connection.h"

class City
{
	String name;
	Connection_List connections;
	City* next;

public:
	City();
	City(const String& name);
	City(const char*& name);

	void AddConnection(const Connection& newConnection);
	void AddConnection(City* city, const int& roadLength);

	City* GetNext() const;
	const String& GetName() const;

	void SetNext(City*& nextCity);
};

class City_List
{
	City* head;
	int size;
public:
	City_List();
	City_List(City*& headCity);

	void pushBack(City* newCity);

	City* operator[](const size_t& index) const;
	bool IsOccupied() const;

	const int& GetSize() const;

	~City_List();
};
