#include<iostream>

class String;
String operator+(const String&  left, const String&  right);

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
	char* get_str()
	{
		return str;
	}

	void set_str(const char *str)
	{
		delete[] this->str;
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		strcpy(this->str, str);
	}


	explicit String(int size = 40) :size(size), str(new char[size] {})
	{
		//this->size = size;
		//this->str = new char[size] {};
		std::cout << "DefaultConstructor:\t" << this << std::endl;
	}
	String(const char* str) :String(strlen(str) + 1)
	{
		//this->size = strlen(str) + 1;
		//this->str = new char[size] {};
		for (int i = 0; i < size; i++)	this->str[i] = str[i];
		std::cout << "Constructor:\t" << this << std::endl;
	}
	String(const String& other) :String(other.str)
	{
		//this->size = other.size;
		//this->str = new char[size] {};
		//////for (int i = 0; i < size; i++)	this->str[i] = other.str[i];
		//// *this = other.str;
		//strcpy(this->str, other.str);
		std::cout << "CopyConstructor: " << this << std::endl;
	}

	// move constructor
	String(String&& other) :size(other.size), str(other.str)
	{
		//this->size = other.size; //niet
		//this->str = other.str;	//niet2
		other.str = nullptr;
		std::cout << std::endl << "=================== " << "Move construcktor\t" << this << std::endl;
	}
	// move assignment
	String& operator= (String && other) 
	{
		delete str;
		this->str = other.str;
		other.str = nullptr;
		std::cout << std::endl << "--------------------- " << "Move assignment\t" << this << std::endl;
		return *this;
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
	String& operator+=(const String& other)
	{
		//String buffer = *this;
		//delete[] this->str;
		//this->size += other.size;
		//this->str = new char[size] {};
		//
		//for (int i = 0; i < buffer.get_size() - 1; i++)str[i] = buffer[i];
		//for (int i = 0; i < other.get_size() - 1; i++)str[buffer.get_size() - 1 + i] = other[i];
		//
		//std::cout << "+=:\t\t" << this << std::endl;
		//return *this;
		return *this = *this + other;
	}
	const char &operator[](int i) const
	{
		// index получить
		// char  вернуть
		//Вернуть значение(char) по индексу 
		return str[i];
	}
	char &operator[](int i)
	{
		// index получить
		// char  вернуть
		//Вернуть значение(char) по индексу 
		return str[i];
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
std::istream& operator>>(std::istream& is, String& obj)
{
	char* sz_str = new char[USHRT_MAX] {};
	is >> sz_str;
	sz_str = (char*)realloc(sz_str, strlen(sz_str) + 1);
	obj.set_str(sz_str);
	delete[] sz_str;
	return is;
	//return is >> obj.get_str();
}
/////////////////////////////////////////////////////////////////////////////////

String operator+(const String&  left, const String&  right)
{
	String cat(left.get_size() + right.get_size()-1); // = заменили на ()
	int nachalo = 0;
	for (int i = 0; i < left.get_size() - 1; i++, nachalo++)cat[i] = left[i];
	//nachalo--;
	for (int i = 0; i < right.get_size(); i++, nachalo++)	cat[nachalo] = right[i];
	return cat;
}

bool operator==(const String& left, const String& right)
{
	if (strlen(left.get_str()) != strlen(right.get_str())) return false;
	for (int i = 0; left[i] != 0 && right[i] != 0; i++)
	{
		if (left[i] != right[i]) return false;
	}
	//if (left.get_size() == right.get_size())
	//{
	//	for (int i = 0; i < left.get_size(); i++)
	//	{ 
	//		if (left[i] != right[i]) return false;
	//	}
		return true;
	//}
	//return false;
	////return (left.get_size() == right.get_size() && left.get_str() == right.get_str());	//некорректно работает
}
bool operator!=(const String& left, const String& right)
{
	return !(left == right);
}
bool operator>(const String& left, const String& right)
{
	////return left.get_str() > right.get_str();
	//if (strcmp(left.get_str(), right.get_str()) < 0) return true;
	//else return false;
	return strcmp(left.get_str(), right.get_str()) < 0 ? true : false;
}
bool operator<(const String& left, const String& right)
{
	//return left.get_str() < right.get_str();
	return strcmp(left.get_str(), right.get_str()) > 0 ? true : false;
}
bool operator>=(const String& left, const String& right)
{
	return left.get_str() >= right.get_str();
}
bool operator<=(const String& left, const String& right)
{
	return left.get_str() <= right.get_str();
}


//#define BASE_CHECK
//#define MOVE_OPERATORS
#define COMPARISON

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
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
	std::cout << std::endl << str1 << std::endl;

	str3 = str2 + str1;
	std::cout << "======================================================================" << std::endl;
	std::cout << str3 << std::endl;
	std::cout << "======================================================================" << std::endl;
#endif // BASE_CHECK

#ifdef MOVE_OPERATORS
	String str1 = "Hello";
	String str2("World");
	String str3 = str1 + str2;
	std::cout << str3 << std::endl;

	String str4 = String("_random");
	std::cout << std::endl <<"str4 = " << str4 << std::endl << std::endl ;

	str2 = str2 + str4;
	//str4 += str1;
	std::cout << std::endl << str2 << std::endl << std::endl;
#endif // MOVE_OPERATORS

#ifdef COMPARISON
	String str1 = "Hello";
	String str2 = "World";
	String str3 = str2;


	//String str4; 
	//std::cin >> str4;
	//std::cout << str4;


	if (str1 == str2)	std::cout << "Равны" << std::endl;
	if (str1 != str2)	std::cout << "НЕ равны" << std::endl;
	/////////////////////////////////////////////////////////////////////

	//if (str2 == str3)	std::cout << "Равны" << std::endl;
	//if (str2 != str3)	std::cout << "НЕ равны" << std::endl;
	//if (str2 > str3) std::cout << "Больше" << std::endl;
	//if (str2 < str3) std::cout << "Меньше" << std::endl;
	//if (str2 >= str3) std::cout << " Больше-Равно" << std::endl;
	//if (str2 <= str3) std::cout << " Меньше-Равно" << std::endl;

	std::cout << str1 << " == " << str2 << " = " << (str1 == str2) << std::endl;
	std::cout << str3 << " == " << str2 << " = " << (str3 == str2) << std::endl;
	std::cout << str3 << " != " << str2 << " = " << (str3 != str2) << std::endl;
	std::cout << str1 << " > " << str2 << " = " << (str1 > str2) << std::endl;
	std::cout << str1 << " < " << str2 << " = " << (str1 < str2) << std::endl;
	std::cout << str1 << " <= " << str2 << " = " << (str1 <= str2) << std::endl;
#endif // COMPARISON

}