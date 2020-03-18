#include<iostream>

#define Delimiter "\n_________________________\n"

class List
{
	class Element
	{
		int data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(int data, Element* pNext = nullptr, Element* pPrev = nullptr) :data(data), pNext(pNext), pPrev(pPrev)
		{
			std::cout << "EConstructor:\t" << this << std::endl;
		}
		~Element()
		{
			std::cout << "EDestructor:\t" << this << std::endl;
		}
		friend class List;
	};
	Element* head; //—одержит указатель на начало списка
	Element* tail; //”казывает на конец списка
	unsigned int size; //количество елементов списка
public:
	List()
	{
		head = tail = nullptr;
		std::cout << "LConstructor:\t" << this << std::endl;
	}
	~List()
	{
		std::cout << "LDestructor:\t" << this << std::endl;
	}

	//		Adding elements
	void push_front(int data)
	{
		if (head == nullptr)
		{
			head = tail = new Element(data);
			return;
		}
		head = head->pPrev = new Element(data, head);
		size++;
	}
	//		Removing elements

	//		Methods:
	void print()
	{
		for (Element* Temp = head; Temp != nullptr; Temp = Temp->pNext)
		{
			std::cout << Temp->pPrev << "\t" << Temp << "\t" << Temp->data << "\t" << Temp->pNext << std::endl;
		}
		std::cout << "List size:\t" << size << std::endl;
	}
	void print_reverse()
	{
		for (Element* Temp = tail; Temp != nullptr; Temp = Temp->pPrev)
		{
			std::cout << Temp->pPrev << "\t" << Temp << "\t" << Temp->data << "\t" << Temp->pNext << std::endl;
		}
		std::cout << "List size:\t" << size << std::endl;
	}
};
void main()
{
	setlocale(LC_ALL, "");
	int n;
	std::cout << "Input size: "; std::cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}
	list.print();
	list.print_reverse();

}