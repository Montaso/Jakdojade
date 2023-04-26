#pragma once
#include <iostream>

class String
{
	char* value;
	int size;
	int buffers;

public:
	String();
	String(const char* other);
	String(const String& other);

	String& operator=(const String& right);
	String& operator+=(const char& right);
	String& operator+=(const String& right);
	bool operator==(const String& right) const;
	bool operator!=(const String& right) const;
	char& operator[](const size_t& index) const;
	friend std::ostream& operator<<(std::ostream& os, const String& string);
	friend std::istream& operator>>(std::istream& is, String& string);

	void addBuffer();

	const int& Size() const;
	char* getVal() const;

	bool isNumber(const String& txt) const;
	int toNumber() const;

	~String();
};

