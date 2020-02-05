#include<iostream>
#include<string>


class String
{
	int size;	//number of bytes
	char* str;

public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	////void set_size(int size)
	////{
	////	this->size = size;
	////}
	void set_str(char *str)
	{
		this->str = str;
	}


	String(int size = 20)
	{
		this->size = size;
		this->str = new char[size] {};
		std::cout << "DefaultConstructor:\t" << this << std::endl;
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i]=str[i];
		}
		std::cout << "Constructor:\t" << this << std::endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		////for (int i = 0; i < size; i++)
		////{
		////	this->str[i] = other.str[i];
		////}
		// *this = other.str;
		strcpy(this->str, other.str);
		std::cout << "CopyConstructor: " << this << std::endl;
	}
	~String()
	{
		delete[] this->str;
		std::cout << "Destructor:\t" << this << std::endl;
	}

	//	Operators
	String& operator=(const String& other)
	{
		if (this == &other) return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		//for (int i = 0; i < size; i++) this->str[i] = other.str[i];
		strcpy(this->str, other.str);
		std::cout << "CoppyAssignment:\t" << this << std::endl;
		return *this;
	}

	//	Methods
	void print()
	{
		std::cout << size << "\t" << str << std::endl;
		std::cout << std::endl;
	}
};


std::ostream& operator<<(std::ostream& os, const String& obj)
{
	//	std::cout << obj.get_str();
	return os << obj.get_str();
}
std::istream& operator>>(std::istream& is,  String& obj)
{
	int size = sizeof(obj);
	char* stroka = new char[size] {};
	//std::string stroka;
	//std::getline(std::cin, stroka);
	obj.set_str(stroka);
	std::cout << "Введите текст из " << size - 1 << " символов: \t";
	return is >> stroka;
}


void main()
{
	setlocale(LC_ALL, "");
	String str1;
	str1.print();

	String str2 = "Hello";
	str2.print();

	String str3 = str2; //Copy constructtor
	str3.print();

	str1 = str2;	//Copy assignment
	str1.print();

	str1 = str1;
	str1.print();

	std::cin >> str1;
	std::cout << str1 << std::endl;
}