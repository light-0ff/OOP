#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<forward_list>

//#define ARRAY
//#define VECTOR
//#define DEQUE
#define FORWARD_LIST

#ifdef ARRAY
const int SIZE = 5;

void print(const std::array<int, SIZE>& arr)
{
	for (std::array<int, SIZE>::const_iterator it = arr.cbegin(); it != arr.cend(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
}
#endif // ARRAY

void main()
{

#ifdef ARRAY
	//array - это контейнер, который хранит обекты в статическом массиве.
	std::array<int, SIZE> arr = { 3, 5, 8};
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;

	for (std::array<int, SIZE>::iterator it = arr.begin();it != arr.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;

	for (std::array<int, SIZE>::reverse_iterator rit = arr.rbegin(); rit != arr.rend(); rit++)
	{
		std::cout << *rit << "\t";
	}
	std::cout << std::endl;

	print(arr);
	std::cout<< arr.max_size() << std::endl;
#endif // ARRAY
#ifdef VECTOR
	//vector - контейнер который хранит данные в виде динамического массива
	std::vector<int> vec{ 0,1,1,2,3,5,8,13,21,34 };
	vec.push_back(55);	//после добавления, делает запас по вместимости для следующих дополнений
	vec.shrink_to_fit(); //уменьшает место, убирает запас памяти

	try
	{
		for (int i = 0; i < vec.size(); i++)
		{
			//std::cout << vec[i] << "\t";
			std::cout << vec.at(i) << "\t";
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << "what????????";
	}
	
	std::cout << std::endl;
	std::cout << "vector size:\t" << vec.size() << std::endl;
	std::cout << "vector capacity:" << vec.capacity() << std::endl;
	std::cout << "vector max size:" << vec.max_size() << std::endl;

	int index;
	int value;
	std::cout << "type index: "; std::cin >> index;
	std::cout << "type value: "; std::cin >> value;
	/*std::vector<int>::iterator position = vec.begin() + index;
	vec.insert(position, value);*/
	vec.insert(vec.begin() + index, 3, value); // 3 - количество раз добавлений
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
	std::cout << "vector size:\t" << vec.size() << std::endl;
	std::cout << "vector capacity:" << vec.capacity() << std::endl;
	std::cout << "vector max size:" << vec.max_size() << std::endl;
	
#endif // VECTOR
#ifdef DEQUE
	std::deque<int> de{ 3, 5, 8, 13 };
	de.push_front(0);
	de.push_front(1);
	de.push_front(1);
	de.push_front(2);
	for (int i : de)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;
#endif // DEQUE
#ifdef FORWARD_LIST
	std::forward_list<int> list = { 3, 5, 8, 13, 21 };
	/*for (int i = 0; i < 5; i++)
	{
		//NO SUBSCRIBT OPERATOR!!!
		std::cout << list[i] << "\t";
	}*/
	/*for (int i : list)
	{
		std::cout << i << "\t";
	}*/
	for (std::forward_list<int>::iterator it = list.begin(); it != list.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;

	int index, value;
	std::cout << "insert index: "; std::cin >> index;
	std::cout << "insert value: "; std::cin >> value;
	std::forward_list<int>::iterator position = list.begin();
	for (int i = 0; i < index - 1; i++)
	{
		position++;
	}

	list.insert_after(position, value);
	for (std::forward_list<int>::iterator it = list.begin(); it != list.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
#endif // FORWARD_LIST

}

/*
STL - Standart Template Library

1) sequence containers
	array
	vector
	deque

2) associative containers
3) container adaptors
*/