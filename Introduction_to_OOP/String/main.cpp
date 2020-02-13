#include"string.h"

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
	std::cout << str3 << " <= " << str2 << " = " << (str3 <= str2) << std::endl;
#endif // COMPARISON

}