#include"header.h"


//#define BASE_CHECK
//#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, "");
	int data;
	int index;
	//std::cout << "Input size: "; std::cin >> data;
#ifdef BASE_CHECK
	List list;
	for (int i = 0; i < data; i++)
	{
		list.push_back(rand() % 100);
	}
	list.print();

	std::cout << Delimiter;
	try
	{
		std::cout << "Input index: "; std::cin >> index;
		//std::cout << "Input nomber: "; std::cin >> data;
		//list.insert(index, n);	
		list.erase(index);
		list.print();
		list.print_reverse();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

#endif // BASE_CHECK
#ifdef CONSTRUCTORS_CHECK
	List list = { 3, 5, 8, 13, 21 };
	//list = list;
	list.print();
	list.print_reverse();
	std::cout << Delimiter << std::endl;

	List list2 = list;
	//list2 = list;
	list2.print();
	list2.print_reverse();

#endif // CONSTRUCTORS_CHECK

	//#ifdef DEBUG
	int arr[] = { 3, 5, 8, 13, 21 };
	for (int i : arr)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;

	/*List list = { 3, 5, 8, 13, 21 };
	List list2 = { 1, 2, 3, 4, 5 };

	List list3 = list + list2;
	list3.print();
	list3.print_reverse();
	std::cout << Delimiter << std::endl;*/


	List list = { 3, 5, 8, 13, 21 };

	for (List::Iterator it = list.begin(); it != list.end(); it++)
		std::cout << *it << "\t";
	std::cout << Delimiter << std::endl;
	
	List list2 = { 1, 2, 3 };
	for (List::Iterator it = list2.begin(); it != list2.end(); it++)	std::cout << *it << "\t";
	std::cout << Delimiter  << std::endl;

	for (int i : list + list2)
	{
		std::cout << i << std::endl;
	}
	std::cout << Delimiter << std::endl;

	List list3;
	list3 = list + list2;
	//list3.print();
	for (List::Iterator it = list3.begin(); it != list.end(); it++) // нужно задом наперед
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
	//#endif // DEBUG
	
}