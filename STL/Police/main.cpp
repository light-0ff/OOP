#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<list>
#include<Windows.h>
#include<array>
#include<conio.h>
#include<boost/algorithm/string.hpp>

const int MENU_SIZE = 11;

#define DEL "\n---------------------------------------\n";
#define LIC_PLATE_INP	std::wcout<<"Введите номер автомобиля: ";		std::wstring licensePlate;	std::getline(std::wcin, licensePlate);
#define VIO_INP			std::wcout<<"Введите правонарушение: ";			std::wstring violation;		std::getline(std::wcin, violation); 

void printFullMap(const std::map<std::wstring, std::list<std::wstring>>& map);
void printOne(const std::map<std::wstring, std::list<std::wstring>>& map);

std::map<std::wstring, std::list<std::wstring>> init();
void insert(std::map<std::wstring, std::list<std::wstring>>& map);

//void removePair(const std::map<std::wstring, std::list<std::wstring>>& map);
//void removeViol(const std::map<std::wstring, std::list<std::wstring>>& map);

void save(const std::map<std::wstring, std::list<std::wstring>>& map);
void load(std::map<std::wstring, std::list<std::wstring>>& map);

void menu();
void printMenu(std::array<bool, MENU_SIZE> optionActive);

std::list<std::wstring> EventList;

void printEL();
void loadEL();
void saveEL();

#define CHECKER

void main()
{
	setlocale(LC_ALL, "");

#ifdef CHECKER
	std::map<std::wstring, std::list<std::wstring>> PoliceDB = init();
	//load(PoliceDB);
	printFullMap(PoliceDB);
#endif // CHECKER
	_getch();//	just for pause
	menu();
	
}

void menu()
{
	std::map<std::wstring, std::list<std::wstring>> PoliceDB = init();
	std::array<bool, MENU_SIZE> optionActive = { true, false, false, false, false, false, false, false, false, false, false };
	char key = 72;
	while (key != 27) {
		system("cls");
		printMenu(optionActive);
		key = _getch();
		for (int i = 0; i < optionActive.size(); i++)
		{
			if ((key == 72 || key == 80) && optionActive[i]) {
				optionActive[i] = false;
				if (key == 72) { i == 0 ? optionActive[optionActive.size() - 1] = true : optionActive[i - 1] = true; }
				else if (key == 80) { (i == optionActive.size() - 1) ? optionActive[0] = true : optionActive[i + 1] = true; }
				i = optionActive.size();
			}
			else if (optionActive[i]&&((key>47&&key<58)||key==45)) {
				optionActive[i] = false;
				switch (char(key))
				{
				case '1':optionActive[0] = true; break;
				case '2':optionActive[1] = true; break;
				case '3':optionActive[2] = true; break;
				case '4':optionActive[3] = true; break;
				case '5':optionActive[4] = true; break;
				case '6':optionActive[5] = true; break;
				case '7':optionActive[6] = true; break;
				case '8':optionActive[7] = true; break;
				case '9':optionActive[8] = true; break;
				case '0':optionActive[9] = true; break;
				case '-':optionActive[10] = true; break;
				default:break;
				}
				i = optionActive.size();
			}
			if (key == 13) {
				system("cls");
				do {
					if (optionActive[0]) printFullMap(PoliceDB);
					if (optionActive[1]) printOne(PoliceDB);
					if (optionActive[2]) insert(PoliceDB);
					//if (optionActive[3]) removePair(PoliceDB);
					//if (optionActive[4]) removeViol(PoliceDB);
					if (optionActive[5]) load(PoliceDB);
					if (optionActive[6]) save(PoliceDB);

					if (optionActive[7]) printEL();
					if (optionActive[8]) saveEL();
					if (optionActive[9]) loadEL();
					if (optionActive[10]) { EventList.clear(); std::wcout << L"\n\nЖурнал событий очищен"; std::wcout << L"\n\n\t[Esc] Exit\t\t\t[Any key] clean\n"; }
				} while (_getch() != 27); //------------------------------------------------------------
			}
		}
	}
}

void printMenu(std::array<bool, MENU_SIZE> optionActive)
{
	std::wcout << "\n\n";
	std::array<std::pair<std::wstring, std::wstring>, MENU_SIZE> menuOptions = {
		std::pair<std::wstring, std::wstring>
		(L"\t\t>>>>>\tPRINT FULL DB\t<<<<<\n", L"\t\t\tPRINT FULL DB\n"),
		std::pair<std::wstring, std::wstring>
		(L"\t\t>>>>>\tPRINT ONE\t<<<<<\n", L"\t\t\tPRINT ONE\n"),

		std::pair<std::wstring, std::wstring>
		(L"\t\t>>>>>\tADD NEW\t\t<<<<<\n", L"\t\t\tADD NEW\n"),

		std::pair<std::wstring, std::wstring>
		(L"\t\t>>>>>\tERASE\t\t<<<<<\n", L"\t\t\tERASE\n"),
		std::pair<std::wstring, std::wstring>
		(L"\t\t>>>>>\tREMOVE VIOL\t<<<<<\n", L"\t\t\tREMOVE VIOL\n"),

		std::pair<std::wstring, std::wstring>
		(L"\t\t>>>>>\tLOAD DB\t\t<<<<<\n", L"\t\t\tLOAD DB\n"),
		std::pair<std::wstring, std::wstring>
		(L"\t\t>>>>>\tSAVE DB\t\t<<<<<\n", L"\t\t\tSAVE DB\n"),

		std::pair<std::wstring, std::wstring>
		(L"\t\t>>>>>\tPRINT EL\t<<<<<\n", L"\t\t\tPRINT EL\n"),
		std::pair<std::wstring, std::wstring>
		(L"\t\t>>>>>\tSAVE EL\t\t<<<<<\n", L"\t\t\tSAVE EL\n"),

		std::pair<std::wstring, std::wstring>
		(L"\t\t>>>>>\tLOAD EL\t\t<<<<<\n", L"\t\t\tLOAD EL\n"),
		std::pair<std::wstring, std::wstring>
		(L"\t\t>>>>>\tCLEAN EL\t<<<<<\n", L"\t\t\tCLEAN EL\n")
	};
	std::wcout << "\n\t\t ~~~ Traffic Police Database ~~~\n\n";
	for (int i = 0; i < menuOptions.size(); i++)
	{
		if (optionActive[i]) std::wcout << menuOptions[i].first;
		else std::wcout << menuOptions[i].second;
		if (i == 6) std::wcout << "\n";
	}
	std::wcout << "\n\n\t[Esc] Exit\t\t\t[Enter] Choose\n";
}

void printFullMap(const std::map<std::wstring, std::list<std::wstring>>& map)
{
	//---------------------------------------------------------------
	for (std::pair<std::wstring, std::list<std::wstring>> m_it : map)
	{
		std::wcout << m_it.first << " : ";
		if (m_it.second.empty()) std::wcout << "\t\t\t\t\t...empty...";
		else {
			for (std::list<std::wstring>::iterator l_it = m_it.second.begin(); l_it != m_it.second.end(); l_it)
			{
				std::wcout << "\n\t" << *l_it;
				l_it++;
				if (l_it != m_it.second.end()) std::wcout << ",";
			}
			std::wcout << ";\n";
		}
		DEL;
	}
	EventList.push_back(L"База данных напечатана");

	std::wcout << "\n\n\t[Esc] Exit\t\t\t[Any key] Print\n";

}

void printOne(const std::map<std::wstring, std::list<std::wstring>>& map)
{
	LIC_PLATE_INP
	std::wcout << "\n\n";
	bool notFound = true;
	for (std::pair<std::wstring, std::list<std::wstring>> m_it : map)
	{
		if (m_it.first == licensePlate)
		{
			std::wcout << m_it.first << ":\n";
			if(m_it.second.empty()) std::wcout << L"\t...empty...";
			else {
				for (std::wstring l_it : m_it.second) {
					std::wcout << "\t" << l_it << L"\n";
					notFound = false;
					EventList.push_back(L"Напечатаны правонарушения по номеру: " + licensePlate);
				}
			}
			break;
		}
	}

}

std::map<std::wstring, std::list<std::wstring>> init()
{
	std::map<std::wstring, std::list<std::wstring>> PoliceDB =
	{
		std::pair<std::wstring, std::list<std::wstring>>
		(L"BI0000BI", {L"превышение скорости", L"воздение в нетрезвом состоянии"}),

		std::pair<std::wstring, std::list<std::wstring>>
		(L"BI0001BI", {L"езда по встречке"}),

		std::pair<std::wstring, std::list<std::wstring>>
		(L"BI0002BI", {L"парковка а неположеном месте"}),

		std::pair<std::wstring, std::list<std::wstring>>
		(L"BI0003BI", {L"проезд на красный", L"плюнул в полицейского"})
	};
	EventList.push_back(L"База данный проинициализирована");
	return PoliceDB;
}
void insert(std::map<std::wstring, std::list<std::wstring>>& map)
{
	LIC_PLATE_INP
	if (licensePlate.size() < 6) { std::wcout << L"\n\nВы не указали номер автомобиля."; }
	else {
		VIO_INP
		if(violation.size()<10) { std::wcout << L"\n\nВы не указали правонарушение."; }
		else {
			std::map<std::wstring, std::list<std::wstring>>::iterator offender = map.find(licensePlate);
			if (offender != map.end())offender->second.push_back(violation);
			else {
				map.insert(std::pair<std::wstring, std::list<std::wstring>>(licensePlate, { violation }));
				EventList.push_back(L"Добавлен новый номер транспортного средства");
				std::wcout << L"\n\nДобавлен новый номер транспортного средства.";
			}
		}
	}
	
}

//void removePair(const std::map<std::wstring, std::list<std::wstring>>& map)
//void removeViol(const std::map<std::wstring, std::list<std::wstring>>& map)

void save(const std::map<std::wstring, std::list<std::wstring>>& map)
{
	std::wofstream fout(L"base.txt");
	for (std::pair<std::wstring, std::list<std::wstring>> m_it : map)
	{
		fout << m_it.first << ":";
		for (std::wstring l_it : m_it.second)
		{
			fout << " " << l_it << ",";
		}
		fout.seekp(-1, std::ios::cur);
		fout << ";\n";
	}
	fout.close();
	EventList.push_back(L"Базза данных сохранена");
	std::wcout << L"Database saved in file \"base.txt\" in project folder\n\n";
	std::wcout << L"\n\n\t[Esc] Exit\t\t\t[Any key] Resave\n";
	system("start notepad base.txt");
}
void load(std::map<std::wstring, std::list<std::wstring>>& map)
{
	map.clear();
	std::wcout << L"Database is cleaned.\n\n";
	std::wstring licensePlate;
	std::wstring violation;
	std::list<std::wstring> violationList;

	std::wifstream fin(L"base.txt");

	if (fin.is_open())
	{
		bool firstLine = false;
		while (!fin.eof())
		{
			if (firstLine) std::getline(fin, licensePlate, L'\n');
			firstLine = true;
			std::getline(fin, licensePlate, L':');
			if (licensePlate == L"")break;
			//
			std::getline(fin, violation, L';');
			//
			boost::algorithm::split(violationList, violation, boost::is_any_of(L",L"));
			//
			map.insert(
				std::pair<std::wstring, std::list<std::wstring>>
				(licensePlate, violationList)
			);
			if (violation.size() == 0)map[licensePlate].clear();
		}
		EventList.push_back(L"База данных загружена");
		std::wcout << L"Database is loaded. \n\n";
	}
	else {
		EventList.push_back(L"Файл загрузки не найден");
		std::wcout << L"Error: file is not found";
	}
	std::wcout << "\n\n\t[Esc] Exit\t\t\t[Any key] Reload\n";
}

void printEL()
{
	std::wcout << "events: " << EventList.size() << " | " << DEL;
	for (std::wstring ev :EventList)
	{
		std::wcout << L"\n\t" << ev;
		if (EventList.size() < 20)std::wcout << L"\n";
	}
	EventList.push_back(L"Журнал событий просмотрен");
	std::wcout << L"\n\n\t[Esc] Exit\t\t\t[Any key] Refresh\n";
}
void loadEL()
{
	EventList.clear();
	std::wstring event;

	std::wifstream fin(L"evlist.txt");
	if (fin.is_open())
	{
		while(!fin.eof())
		{
			std::getline(fin, event, L'\n');
			std::wcout << event << L"\n";
			EventList.push_back(event);
		}
		EventList.push_back(L"Журнал событий загружен");
		std::wcout << L"\n\nЖурнал событий загружен";
	}
	else {
		EventList.push_back(L"Файл загрузки не найден");
		std::wcout << L"Error: file is not found";
	}
	std::wcout << L"\n\n\t[Esc] Exit\t\t\t[Any key] Reload\n";
}
void saveEL()
{
	std::wofstream fout(L"evlist.txt");
	int count = 1;
	for (std::wstring ev : EventList)
	{
		fout << ev;
		if (count < EventList.size() - 1) std::wcout << "\n"; count++;
	}
	fout.close();
	EventList.push_back(L"Журнал событий сохранен");
	std::wcout << L"\n\nЖурнал событий сохранен";
	std::wcout << L"\n\n\t[Esc] Exit\t\t\t[Any key] Resave\n";
}