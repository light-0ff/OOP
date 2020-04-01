#pragma once
#include<iostream>
#include<Windows.h>

#define Delimiter "\n__________________________________________________\n"

class List
{
	class Element
	{
		int data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(int data, Element* pNext = nullptr, Element* pPrev = nullptr);
		~Element();
		friend class List;
	};
	Element* head; //—одержит указатель на начало списка
	Element* tail; //”казывает на конец списка
	unsigned int size; //количество елементов списка
public:

	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp);
		~Iterator();

		//		Operators:
		Iterator& operator++();
		Iterator operator++(int);
		const int& operator*()const;
		int& operator*();
		bool operator==(const Iterator& other)const;
		bool operator!=(const Iterator& other)const;
	};

	const Iterator begin()const;
	Iterator begin();
	const Iterator end()const;
	Iterator end();
	/////////////////////////////////
	class ReverseIterator
	{
		List::Element* Temp;
	public:
		ReverseIterator(List::Element* Temp);
		~ReverseIterator();

		//		Operators
		ReverseIterator& operator++();
		ReverseIterator& operator++(int);
		const int& operator*()const;
		int& operator*();

		bool operator==(const ReverseIterator& other)const;
		bool operator!=(const ReverseIterator& other)const;
	};
	const ReverseIterator rbegin()const;
	const ReverseIterator rend()const;
	////////////////////////////////
	List();
	List(std::initializer_list<int> il);
	List(const List& other);
	List(List&& other);
	~List();

	//		Operators:
	List& operator=(List&& other);
	List& operator=(const List& other);

	//		Adding elements
	void push_front(int data);
	void push_back(int data);
	void insert(int index, int data);

	//		Removing elements
	void pop_front();
	void pop_back();
	void erase(int index);

	//		Methods:
	void print();
	void print_reverse();
};

List operator+(const List& left, const List& right);