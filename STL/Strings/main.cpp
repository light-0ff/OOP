#include<iostream>
#include<string>
//using namespace std;

//#define C_WIDE_STRINGS

void main()
{
	setlocale(LC_ALL, ".OCP");
#ifdef C_WIDE_STRINGS
	wchar_t str[256] = L"Привет";	//ANSI ASCII string (1 byte)256 символов
	std::wcout << str << "----------------" << std::endl;
	//Unicode: UTF-8, UTF-16, UTF-32 (1 byte/ 2 byte/ 4byre)
	//Multibyte
	std::cout << sizeof(wchar_t) << std::endl;
	std::wcout << L"Введите строку: "; std::wcin >> str;
	//wcin.getline(str, 256);
	wcscat_s(str, L"World");

	std::wcout << str << std::endl;
	std::wcout << wcslen(str) << std::endl;
#endif // C_WIDE_STRINGS

	std::wstring str = L"Hello World";
	std::wcout << str << std::endl;


}