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
	Human human("�������", "������", 18);
	//human.print();

	Student stud("�������", "������", 18, "������", "�� �� 37");
	//stud.print();

	Teacher tech("Einstein", "Albert", 141, "������", 5);
	//tech.print();

	Graduate exit("�����", "������", 22, "���������", "asdf", 95, 70, "���� ��� �� ����", "Albert");
	//exit.print();

	Human* group2[] =	//�������
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
		new Student("���������23", "�����??", 15, "���", "�� �� 35", 95, 100),
		new Student("�������", "�����", 15, "���", "�� �� 35", 85, 97),
		new Teacher("�����������", "������", 42, "Hardware & Windows", 5, 0),
		new Student("��������", "������", 16, "���", "�� �� 35", 99, 100),
		new Graduate("������", "������", 17, "���", "�� �� 35", 95, 100, "3dShooter Development", "��"),
		new Teacher("�����", "����", 35, "�++", 5, 32),
		new Graduate("�����", "��������", 21, "���", "�� �� 35", 96, 100, "���������� ��� ��� Android", "Someone")
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
	//--------------����� ����� setlocale(LC_ALL, ".OCP");
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
	//std::wregex rgx_ru(L"(��|��)(_| )(��|��|���|���|��|��)(_| )\\d{2}|\\d[���]");
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