#include "Connection.h"
//#include "City.h"

Connection::Connection() : connected(nullptr), roadLength(0), next(nullptr) {};

Connection::Connection(City* city, const int& roadLength) : connected(city), roadLength(roadLength), next(nullptr) {}

Connection::Connection(const Connection& other) : connected(other.connected), roadLength(other.roadLength), next(other.next) {}

Connection* Connection::GetNext() const
{
	return this->next;
}

void Connection::SetNext(Connection*& nextCon)
{
	this->next = nextCon;
}

Connection::~Connection()
{
	//delete[] this->connected;
	this->connected = nullptr;
	this->roadLength = 0;
	this->next = nullptr;

	/*if (this->next != nullptr)
	{
		delete[] this->next;
	}*/
};



Connection_List::Connection_List() : head(nullptr), last(nullptr), size(0) {}
Connection_List::Connection_List(Connection*& headConnection)
{
	this->head = headConnection;
	this->last = headConnection;
	this->size = 1;
}

void Connection_List::pushBack(const Connection& newConnection)
{
	Connection* newCon = new Connection(newConnection);
	if (this->head == nullptr)
	{
		this->head = newCon;
		this->last = newCon;
		this->size++;
		return;
	}

	Connection* tmp = this->last;
	if(tmp != nullptr)
	{
		tmp->SetNext(newCon);
		this->last = newCon;
		this->size++;
	}
	
}

void Connection_List::pushBack(Connection* newConnection)
{
	if (this->head == nullptr)
	{
		this->head = newConnection;
		this->last = newConnection;
		this->size++;
		return;
	}

	Connection* tmp = this->last;
	if (tmp != nullptr)
	{
		tmp->SetNext(newConnection);
		this->last = newConnection;
		this->size++;
	}
}

Connection_List::~Connection_List() 
{
	Connection* tmp = head;
	while (tmp != nullptr)
	{
		Connection* next = tmp->GetNext();
		delete tmp;
		tmp = next;
	}
	
};