#pragma once
#include<iostream>
///////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// CLASS DECLARATION /////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

class String;
String operator+(const String&  left, const String&  right);
bool operator==(const String& left, const String& right);
bool operator!=(const String& left, const String& right);
bool operator>(const String& left, const String& right);
bool operator<(const String& left, const String& right);
bool operator>=(const String& left, const String& right);
bool operator<=(const String& left, const String& right);

std::ostream& operator<<(std::ostream& os, const String& obj);
std::istream& operator>>(std::istream& is, String& obj);

class String
{
	int size;	//number of bytes
	char* str;

public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();
	void set_str(const char *str);

	explicit String(int size = 40);
	String(const char* str);
	String(const String& other);
	String(String&& other);	// move constructor
	String& operator= (String && other); // move assignment
	~String();

	//	Operators
	String& operator=(const String& other);
	String& operator+=(const String& other);

	const char &operator[](int i) const;
	char &operator[](int i);

	//	Methods
	void print();
};
