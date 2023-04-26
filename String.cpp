#include "String.h"
#include <ctype.h>

#define STRING_LENGTH 8

String::String()
{
	this->value = new char[STRING_LENGTH];
	this->size = 0;
	this->buffers = 1;

	this->value[0] = '\0';
	this->size++;
}

String::String(const char* other)
{
	this->value = new char[STRING_LENGTH];
	this->size = 0;
	this->buffers = 1;

	while (other[size] != '\0')
	{
		if (size >= STRING_LENGTH * this->buffers)
		{
			this->addBuffer();
		}
		this->value[size] = other[size];
		this->size++;
	}

	if (this->size >= STRING_LENGTH * this->buffers)
	{
		this->addBuffer();
	}
	this->value[size] = '\0';
	this->size++;

}

String::String(const String& other)
{
	this->size = other.size;
	this->buffers = other.buffers;
	this->value = new char[STRING_LENGTH * buffers];

	for (int i = 0; i < other.size; i++)
	{
		this->value[i] = other.value[i];
	}
}

String& String::operator=(const String& right)
{
	//delete previous values
	delete[] value;
	this->size = right.size;
	this->buffers = right.buffers;

	//allocate new value memory
	this->value = new char[STRING_LENGTH * buffers];

	for (int i = 0; i < size; i++)
	{
		this->value[i] = right.value[i];
	}

	return *this;
}

String& String::operator+=(const char& right)
{
	if (this->size >= STRING_LENGTH * buffers)
	{
		this->addBuffer();
	}
	value[size - 1] = right;
	value[size] = '\0';
	size++;

	return *this;
}

String& String::operator+=(const String& right)
{
	String tmp(*this);

	delete[] this->value;
	this->value = new char[(tmp.size + right.size) / STRING_LENGTH + 1];
	this->size = 0;
	this->buffers = (tmp.size + right.size) / STRING_LENGTH + 1;

	for (int i = 0; i < tmp.size - 1; i++)
	{
		this->value[size] = tmp[size];
		size++;
	}
	for (int i = 0; i < right.size; i++)
	{
		this->value[size] = right.value[i];
		size++;
	}
	return *this;
}

bool String::operator==(const String& right) const
{
	if (this->size != right.size) return false;
	for (int i = 0; i < this->size; i++)
	{
		if (this->value[i] != right.value[i]) return false;
	}
	return true;
}
bool String::operator!=(const String& right) const
{
	if (this->size != right.size) return true;
	for (int i = 0; i < this->size; i++)
	{
		if (this->value[i] != right.value[i]) return true;
	}
	return false;
}

char& String::operator[](const size_t& index) const
{
	return this->value[index];
}

std::ostream& operator<<(std::ostream& os, const String& string)
{
	os << string.value;
	return os;
}

std::istream& operator>>(std::istream& is, String& string)
{
	char* inputVal = new char[128];
	
	is >> inputVal;
	string = inputVal;

	delete[] inputVal;
	return is;
}

//void String::deleteLastEmpty()
//{
//	int tmp = size - 2;
//	while (isspace(this->value[tmp]))
//	{
//		this->value[tmp] = '\0';
//		this->size -= 1;
//		tmp--;
//	}
//}

void String::addBuffer()
{
	this->buffers += 1;
	char* tmp = value;
	this->value = new char[buffers * STRING_LENGTH];

	int i = 0;
	while (tmp[i] != '\0' && i < buffers * STRING_LENGTH - 1)
	{
		this->value[i] = tmp[i];
		i++;
	}
	this->value[i] = '\0';

	delete[] tmp;
}

const int& String::Size() const
{
	return this->size;
}

char* String::getVal() const
{
	return this->value;
}

bool String::isNumber(const String& txt) const
{
	for (int i = 0; i < txt.size - 1; i++)
	{
		if (txt.value[i] < '0' || txt.value[i] > '9') return false;
	}
	return true;
}

int String::toNumber() const
{
	int sum = 0;
	int exponent = 1;
	for (int i = this->Size() - 2; i >= 0; i--)
	{
		sum += (value[i] - '0') * exponent;
		exponent *= 10;
	}

	return sum;
}

String::~String()
{
	delete[] this->value;
	this->size = 0;
	this->buffers = 0;
}