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
			this->str[i] = str[i];
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

	// move constructor
	String(String&& x) : str(x.str)
	{
		x.str = nullptr;
		std::cout << std::endl << "=================== " << "Move construcktor" << std::endl << std::endl;
	}
	// move assignment
	String& operator= (String && x) {
	delete str;
	str = x.str;
	x.str = nullptr;
	std::cout << std::endl << "--------------------- "<<"Move assignment" << std::endl << std::endl;
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
std::istream& operator>>(std::istream& is, String& obj)
{
	int size = sizeof(obj);
	char* stroka = new char[size] {};
	//std::string stroka;
	//std::getline(std::cin, stroka);
	obj.set_str(stroka);
	std::cout << "Введите текст из " << size - 1 << " символов: \t";
	//stroka[size-1] = '\0';
	return is >> stroka;
}

String operator+(const String&  left, const String&  right)
{
	//String cat(left.get_size() + right.get_size());
	//strcat(cat.get_str(), left.get_str());
	//strcat(cat.get_str(), right.get_str());

	String cat = left.get_size() + right.get_size()-1;
	int nachalo = 0;
	for (int i = 0; i < left.get_size() - 1; i++, nachalo++)cat[i] = left[i];
	//nachalo--;
	for (int i = 0; i < right.get_size(); i++, nachalo++)	cat[nachalo] = right[i];

	return cat;
}

//#define BASE_CHECK

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

	String str1 = "Hello";
	String str2("World");
	String str3 = str1 + str2;
	std::cout << str3 << std::endl;

	String str4 = String("_random");
	std::cout << std::endl <<"str4 = " << str4 << std::endl << std::endl ;

	str2 = str2 + str4;
	str4 += str1;
	std::cout << std::endl << str4 << std::endl << std::endl;
	}