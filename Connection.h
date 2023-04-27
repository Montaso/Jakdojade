#pragma once
class City;

class Connection
{
	City* connected;
	int roadLength;

	Connection* next;

public:
	Connection();
	Connection(City* city, const int& roadLength);
	Connection(const Connection& other);

	Connection* GetNext() const;
	void SetNext(Connection*& nextCon);

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

	void pushBack(const Connection& newConnection);
	void pushBack(Connection* newConnection);

	~Connection_List();
};

