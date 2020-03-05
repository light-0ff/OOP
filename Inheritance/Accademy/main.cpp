#include"Accademi.h"
//#include"Academy.cpp"

//#define SET_ACCADEMY
#define POLIMORPHISM
//#define REGEX_TEST
//#define REGEX_GROUP
//#define REGEX_MAIL 
//#define REGEX_PHONE
//#define CONVERT_PHONE
void main()
{
	//setlocale(LC_ALL, ".OCP");
	setlocale(LC_ALL, "");
#ifdef SET_ACCADEMY
	Human human("Тупенко", "Васыль", 18);
	//human.print();

	Student stud("Тупенко", "Васыль", 18, "Дизайн", "СТ ДВ 37");
	//stud.print();

	Teacher tech("Einstein", "Albert", 141, "Физика", 5);
	//tech.print();

	Graduate exit("Попов", "Сергей", 22, "Философия", "asdf", 95, 70, "быть или не ьыть", "Albert");
	//exit.print();

	Human* group2[] =	//Домашка
	{
		&tech,
		&stud,
		&exit,
		&human
	};

	for (int i = 0; i < sizeof(group2) / sizeof(Human*); i++)
	{
		group2[i]->print();
	}
#endif // SET_ACCADEMY
#ifdef POLIMORPHISM
	Human* group[] =
	{
		new Student("Ковальчук23", "Антон??", 15, "РПО", "СТ ПВ 35", 95, 100),
		new Student("Кравцов", "Артем", 15, "РПО", "СТ ПВ 35", 85, 97),
		new Teacher("Кобылинский", "Андрей", 42, "Hardware & Windows", 5, 0),
		new Student("Горбенко", "Богдан", 16, "РПО", "СТ ПВ 35", 99, 100),
		new Graduate("Маслак", "Михаил", 17, "РПО", "СТ ПВ 35", 95, 100, "3dShooter Development", "ОА"),
		new Teacher("Котун", "Олег", 35, "С++", 5, 32),
		new Graduate("Колач", "Геннадий", 21, "РПО", "СТ ПВ 35", 96, 100, "Разработка игр для Android", "Someone")
	};

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		std::cout << "--------------------------------------------------------------------------------\n";
		group[i]->print();
	}

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete group[i];
	}
#endif // POLIMORPHISM
#ifdef REGEX_TEST
	//--------------здесь нужен setlocale(LC_ALL, ".OCP");
	std::string name;
	std::cout << " Input name: "; /*std::cin >> name;*/ getline(std::cin, name);
	std::regex rgx("[A-Z][a-z]{1,10}");
	std::cout << std::regex_match(name, rgx, std::regex_constants::match_default) << std::endl;
#endif // TEST
#ifdef REGEX_GROUP
	std::wstring group;
	std::cout << " Input group: "; 
	/*std::cin >> group;*/	getline(std::wcin, group);
	std::wcout << group << std::endl;
	//std::wregex rgx_ru(L"(СТ|ПС)(_| )(ПУ|ПВ|ИТУ|ИТВ|ДУ|ДВ)(_| )\\d{2}|\\d[абв]");
	std::wregex rgx_eng(L"(ST|PS(_| )(SB|VS))[_ \-](PU|PV|ITU|ITV|DU|DV)[_ \-]\\d{2}[abc]?");
	//std::wcout << std::regex_match(group, rgx_ru, std::regex_constants::match_default) << std::endl;
	std::wregex rgx_replace(L" |\-");
	group = std::regex_replace(group, rgx_replace, L"_", std::regex_constants::match_default);
	std::wcout << std::regex_match(group, rgx_eng, std::regex_constants::match_default) << std::endl;
	std::wcout << group << std::endl;

#endif // REGEX_GROUP
#ifdef REGEX_MAIL
	std::string email = "vasya@gmail.com";
	//std::string email;
	//std::cout << " Input E-mail: ";
	//getline(std::cin, email);
	std::cout << email << std::endl;
	std::regex rgx_mail("\\w{3,20}@[a-z]{1,10}[.][a-z]{2,4}(.[a-z]{2})?");
	std::cout << std::regex_match(email, rgx_mail, std::regex_constants::match_default) << std::endl;

#endif // REGEX_MAIL
#ifdef REGEX_PHONE
	std::string phone = "+38(099)123-45-67";
	//std::regex rgx_phone ("\\+\\d{2}\\(\\d{3}\\)\\d{3}(-\\d{2}){2}");
	std::regex rgx_phone (R"(\+\d{2}\(\d{3}\)\d{3}(-\d{2}){2})");
	//std::cout << (R"(\\+\\d{2}\\(\\d{3}\\)\\d{3}(-\\d{2}){2})") << std::endl;
	std::cout << std::regex_match(phone, rgx_phone, std::regex_constants::match_default) << std::endl;
#endif // REGEX_PHONE
#ifdef CONVERT_PHONE
	std::string phone = "380991234567";
	std::regex rgx("\\d{12}");
	
	if (std::regex_match(phone, rgx, std::regex_constants::match_default))
	{
		phone.insert(0, "+");
		phone.insert(phone.size() - 10, "(");
		phone.insert(phone.size() - 7, ")");
		phone.insert(phone.size() - 4, "-");
		phone.insert(phone.size() - 2, "-");
	}
	std::cout << phone << std::endl;
#endif // CONVERT_PHONE


}