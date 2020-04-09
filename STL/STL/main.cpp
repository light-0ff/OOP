#include<iostream>
#include<array>

#define ARRAY

const int SIZE = 5;

void print(const std::array<int, SIZE>& arr)
{
	for (std::array<int, SIZE>::const_iterator it = arr.cbegin(); it != arr.cend(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
}

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