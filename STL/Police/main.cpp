#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<list>
#include<Windows.h>
#include<boost/algorithm/string.hpp>

#define delimiter "\n---------------------------------------\n";

std::map < std::string, std::list<std::string>> init();
void print_full_base(const std::map<std::string, std::list<std::string>>& base);
void save(const std::map<std::string, std::list<std::string>>& base);
void load(std::map<std::string, std::list<std::string>>& base);
void insert(std::map<std::string, std::list<std::string>>& base);

void main()
{
	setlocale(LC_ALL, "");
	//map - это контейнер который хранит данные в виде бинорного дерева. 
	//Каждый элемент этого дерева представляет собой ПАРУЖ key - value.

	std::map<std::string, std::list<std::string>> base = init();
	print_full_base(base);
	//std::cout<<typeid(std::string("Hello").c_str())
	load(base);

	//insert(base);
	print_full_base(base);
	//save(base);
}

std::map < std::string, std::list<std::string>> init()
{
	std::map<std::string, std::list<std::string>> base =
	{
		std::pair <std::string, std::list<std::string>>("BI 0000 BI", {"привышение скорости", "вождение в нетрезвом состоянии"}),
		std::pair<std::string, std::list<std::string>>("BI 0001 BI",{"езда по встречке"}),
		std::pair<std::string, std::list<std::string>>("BI 0002 BI",{"парковка в неположенном месте"}),
		std::pair<std::string, std::list<std::string>>("BI 0003 BI",{"проезд на красный", "привышение скорости", "плюнул в полицейского"})
	};
	return base;
}
void print_full_base(const std::map<std::string, std::list<std::string>>& base)
{
	for (auto m_it : base)
	{
		std::cout << m_it.first << ":\n";
		for (std::string l_it : m_it.second)
		{
			std::cout << " - " << l_it << ";\n";
		}
		std::cout << delimiter;
	}
	/*for (std::map<std::string, std::list<std::string>>::iterator m_it = base.begin(); m_it != base.end(); m_it++)
{
	std::cout << m_it->first << ":\n";
	for (std::list<std::string>::iterator l_it = m_it->second.begin(); l_it != m_it->second.end(); l_it++)
	{
		std::cout << " - " << l_it->c_str() << ";\n";
	}
std::cout << delimiter;
}*/

}

void save(const std::map<std::string, std::list<std::string>>& base)
{
	std::ofstream fout("base.txt");
	//CSV - Comma Separated values;
	for (std::pair<std::string, std::list<std::string>> i : base)
	{
		fout << i.first << ":";
		for (std::string j : i.second)
		{
			fout << " " << j << ",";
		}
		fout.seekp(-1, std::ios::cur);//удаляет последний символ, перед ";"
		fout << ";\n";
	}
	fout.close();
	system("start notepad base.txt");

}

void load(std::map<std::string, std::list<std::string>>& base)
{
	base.clear();
	print_full_base(base);
	std::cout << "after clearing\n";
	system("PAUSE");

	std::string license_plate;
	std::string violation;
	std::list<std::string> violation_list;

	std::ifstream fin("base.txt");

	//SetConsoleCP(1251);
	//SetConsoleCP(866);
	if (fin.is_open())
	{
		//std::fstream& stream = fin
		//std::cout << fin.tellg() << std::endl;
		while (!fin.eof())
		{
			//fin.getline(license_plate.c_str(), 20, ":");
			std::getline(fin, license_plate, ':');
			if (license_plate.size() == 0)break;
			std::getline(fin, violation, ';');
			//std::cout << license_plate << " - " << violation << std::endl;

			boost::algorithm::split(violation_list, violation, boost::is_any_of(","));
			//base.insert(std::pair <std::string, std::list<std::string>>(license_plate, violation_list));
			
			std::cout << license_plate << ":";
			for (std::string i : violation_list) std::cout << i << ", "; std::cout << ";\n";
			/*print_full_base(base);
			system("PAUSE");*/
		}
	}
	//SetConsoleCP(866);
	else
	{
		std::cerr << "Error: file is not found";
	}

	fin.close();

}

void insert(std::map<std::string, std::list<std::string>>& base)
{
	std::string license_plate;
	std::string violation;
	std::cout << "Введите номер автомобиля: ";	//std::cin >> license_plate;
	SetConsoleCP(1251);
	std::getline(std::cin, license_plate);
	SetConsoleCP(866);
	std::cout << "Введите правонарушение: ";	//std::cin >> violation;
	SetConsoleCP(1251);

	if (license_plate.size() == 0 || violation.size() == 0) return;

	std::getline(std::cin, violation);
	SetConsoleCP(866);
	std::map<std::string, std::list<std::string>>::iterator offender = base.find(license_plate);
	if (offender != base.end())
	{
		//ЕСЛИ номер уже есть в базе то добавляем нарушение к сушествующему номеру
		offender->second.push_back(violation);
	}
	else
	{
		//Создаем нового нарушителя в базу
		base.insert(std::pair<std::string, std::list<std::string>>(license_plate, { violation }));
	}
}