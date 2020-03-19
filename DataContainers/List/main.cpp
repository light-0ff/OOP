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
	void push_back(int data)
	{
		if (head == nullptr)
		{
			push_front(data);
			return;
		}
		tail = tail->pNext = new Element(data, tail->pNext, tail);
		size++;
	}
	void insert(int index, int data)
	{
		if (index > size)
		{	throw std::exception("Error: out of ramge");
			return;
		}
		if (index == 0)
		{	push_front(data);
			return;
		}
		Element* Temp = head;
		for (int i = 0; i < index - 1; i++)	Temp = Temp->pNext;
		Temp = Temp->pNext = Temp->pNext->pPrev = new Element(data, Temp->pNext, Temp);
		//Temp->pNext->pPrev = Temp; //записывает адресс нового елемента в следующий елемент
	}
	//		Removing elements
	void pop_front()
	{
		Element* buffer = head;
		head = head->pNext;
		head->pPrev = nullptr;
		delete buffer;
		size--;
	}
	void pop_back()
	{
		Element* buffer = tail;
		tail = buffer = nullptr;
		delete buffer;
		size--;
	}
	void erase(int index)
	{
		if (index >= this->size)
		{	throw std::exception("Error: out of ramge when erasing");
			return;
		}
		if (index <= 0)
		{	pop_front();
			return;
		}
		Element* Temp = head;
		for (int i = 0; i < index - 1; i++)	Temp = Temp->pNext;
		Element* buffer = Temp->pNext;		//save addres of deleted element
		Temp->pNext = Temp->pNext->pNext;	//exclude deleted element from list
		Temp->pNext->pPrev = Temp->pNext->pPrev->pPrev;
		delete buffer;
		size--;

	}
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
	int index;
	std::cout << "Input size: "; std::cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}
	list.print();
	std::cout << Delimiter;
	//list.push_back(999);		// ƒобавить в конец
	std::cout << "Input index: "; std::cin >> index;
	//list.insert(index, 2222);	// ƒобавить по индексу
	/* std::cout << "Input nomber: "; std::cin >> n;
	list.insert(index, n);	*/	
	list.erase(index);
	list.print();
	list.print_reverse();
}