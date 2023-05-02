#pragma once
class City;

class Connection
{
	City* sourceCity;
	City* connected;
	int roadLength;

	Connection* next;

public:
	Connection();
	Connection(City* sourceCity, City* city, const int& roadLength);
	Connection(const Connection& other);

	Connection* GetNext() const;
	const int& GetLength() const;
	City* GetSourceCity() const;
	City* GetConnectedCity() const;

	void SetNext(Connection*& nextCon);
	void SetDistance(const int& newDist);

	~Connection();
};

class Connection_List
{
	Connection* head;
	Connection* last;
	int size;
public:
	Connection_List();
	Connection_List(Connection*& headConnection);

	Connection* GetHead() const;
	const int& Size() const;

	void pushBack(const Connection& newConnection);
	void pushBack(Connection* newConnection);

	~Connection_List();
};

