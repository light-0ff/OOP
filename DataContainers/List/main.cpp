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
	Element* head; //Содержит указатель на начало списка
	Element* tail; //Указывает на конец списка
	unsigned int size; //количество елементов списка
public:

	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp)
		{
			this->Temp = Temp;
#ifdef DEBUG
			std::cout << "ItConstructor:\t" << this << std::endl;
#endif // DEBUG
		}
		~Iterator()
		{
#ifdef DEBUG
			std::cout << "ItDestructor:\t" << this << std::endl;
#endif //DEBUG
		}

		//		Operators:
		Iterator& operator++()
		{
			Temp = Temp->pNext;
			return *this;
		}

		Iterator operator++(int)
		{
			Iterator old = *this;
			Temp = Temp->pNext;
			return old;
		}

		const int& operator*()const
		{
			return Temp->data;
		}

		int& operator*()
		{
			return Temp->data;
		}

		bool operator==(const Iterator& other)const 
		{
			return this->Temp == other.Temp;
		}

		bool operator!=(const Iterator& other)const
		{
			return this->Temp != other.Temp;
		}
	};

	List()
	{
		head = tail = nullptr;
		size = 0;
		std::cout << "LConstructor:\t" << this << std::endl;
	}
	List(std::initializer_list<int> il) :List()
	{
		std::cout << typeid(il.begin()).name() << std::endl;
		for (int const* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
	}
	List(const List& other) :List()
	{
	/*	for (Element* Temp = other.head; Temp; Temp = Temp->pNext)
		{
			push_back(Temp->data);
		}*/
		for (Iterator it = other.head; it != nullptr; it++)
		{
			push_back(*it);
		}
		std::cout << "LCopyConstructor:\t" << this << std::endl;
	}
	~List()
	{
		while (head)pop_front();
		//while (tail)pop_back();
		std::cout << "LDestructor:\t" << this << std::endl;
	}

	//		Operators:
	List& operator=(const List& other)
	{
		if (this == &other) return *this;
		while (head)pop_front();
		for (Element* Temp = other.head; Temp; Temp++) push_back(Temp->data);
		std::cout << std::endl << "LCopyAssignment\t" << this << std::endl;
		return *this;
	}

	//		Adding elements
	void push_front(int data)
	{
		if (head == nullptr)
		{
			head = tail = new Element(data);
			size++;
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
			//size++;
			return;
		}
		tail = tail->pNext = new Element(data, nullptr, tail);
		size++;

	}
	void insert(int index, int data)
	{
		if (index > size)	throw std::exception("Error: out of ramge");
		//if (index == 0)
		//{	push_front(data);
		//	return;
		//}
		Element* Temp;
		if (index < size / 2)
		{
			Temp = head;
			for (int i = 0; i < index; i++)	Temp = Temp->pNext;
		}
		else
		{
			Temp = tail;
			for (int i = 0; i < size - 1 - index; i++)	Temp = Temp->pPrev;
		}
		Temp->pPrev = Temp->pPrev->pNext = new Element(data, Temp, Temp->pPrev);
		//Temp = Temp->pNext = Temp->pNext->pPrev = new Element(data, Temp->pNext, Temp);		//Temp->pNext->pPrev = Temp; //записывает адресс нового елемента в следующий елемент
		size++;
	}
	//		Removing elements
	void pop_front()
	{
		if (head == tail)
		{
			delete head;
			head = tail = nullptr;
			if (size)size--;
			return;
		}
		head = head->pNext;
		delete head->pPrev;
		head->pPrev = nullptr;
		size--;
	}
	void pop_back()
	{
		if (head == tail)
		{
			delete tail;
			head = tail = nullptr;
			if (size)size--;
			return;
		}
		tail = tail->pPrev;
		delete tail->pNext;
		tail->pNext = nullptr;
		size--;
	}
	void erase(int index)
	{
		if (index >= size)	throw std::exception("Error: out of ramge when erasing");
		if (index == 0)
		{
			pop_front();
			return;
		}
		if (index == size - 1)
		{
			pop_back();
			return;
		}
		Element* Temp;
		if (index < size / 2)
		{
			Temp = head;
			for (int i = 0; i < index - 1; i++)	Temp = Temp->pNext;
		}
		else
		{
			Temp = tail;
			for (int i = 0; i < size - 1 - index; i++)	Temp = Temp->pPrev;
		}
		
		Temp->pPrev->pNext = Temp->pNext;	//exclude deleted element from list
		Temp->pNext->pPrev = Temp->pPrev;
		delete Temp;
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

//#define BASE_CHECK
//#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, "");
	int data;
	int index;
	std::cout << "Input size: "; std::cin >> data;
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
	List list = { 3, 5, 8, 13, 21};
	list = list;
	list.print();
	list.print_reverse();
	std::cout << Delimiter << std::endl;

	List list2 = list;
	//list2 = list;
	list2.print();
	list2.print_reverse();

#endif // CONSTRUCTORS_CHECK

	int arr[] = { 3, 5, 8, 13, 21 };
	for (int i : arr)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;

	List list = { 3, 5, 8, 13, 21 };
	//for (int i : list)
	//{
	//	std::cout << i << std::endl;
	//}

}