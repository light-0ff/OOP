#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<map>

//#define STL_MAP
#define DICTIONARY

void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_MAP
	std::map<int, std::string> week =
	{
		std::pair<int, std::string>(0, "Sunday"),
		std::pair<int, std::string>(1, "Monday"),
		std::pair<int, std::string>(2, "Tuesday"),
		std::pair<int, std::string>(3, "Wednesday"),
		std::pair<int, std::string>(4, "Thursday"),
		std::pair<int, std::string>(5, "Friday"),
		std::pair<int, std::string>(6, "Saturday")
	};

	int number;

	/*for (std::map<int, std::string>::iterator it = week.begin(); it != week.end(); it++)
	{
		std::cout << it->first << "\t" << it->second << std::endl;

	}*/
	int arr[] = { 3, 5, 8, 13, 21 };
	/*for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;*/
	for (auto m_it : week)
	{
		std::cout << m_it.first << "\t" << m_it.second << std::endl;
	}

	//std::cout << "������� ���� ������� ����� �� 1 �� 7: "; std::cin >> number;
	//std::cout << "��� ������� ���� ������ " << week.find(number % 7)->second << std::endl;
	//����� find ���������� �������� �� ������� � �������� ������, ���� ����� ����� ��� ������ � ����������
	//� ��������� ������ - �������� �� ����� ����������  
#endif // STL_MAP

#ifdef DICTIONARY
	std::map<std::string, std::vector<std::string>> dictionary =
	{
		std::pair<std::string, std::vector<std::string>>("friend", {"����", "��������"}),
		std::pair<std::string, std::vector<std::string>>("space", {"������������", "������"}),
		std::pair<std::string, std::vector<std::string>>("flour", {"����"}),
		std::pair<std::string, std::vector<std::string>>("floor", {"���", "����"}),
	};
	for (std::map<std::string, std::vector<std::string>>::iterator it = dictionary.begin(); it != dictionary.end(); it++)
	{
		//std::cout << (*it).first << "\t" << it->second << std::endl;
		std::cout << it->first << "\t";
		for (std::vector<std::string>::iterator jt = it->second.begin(); jt != it->second.end(); jt++)
		{
			std::cout << *jt << ", ";
		}
		std::cout << "\b\b;\n";
	}

	for (auto m_it : dictionary)
	{
		std::cout << m_it.first << ":\n";
		for (std::string l_it : m_it.second)
		{
			std::cout << " - " << l_it << ";\n";
		}
	}

#endif // DICTIONARY


}