#include<iostream>
#include<string>

#define Delimiter "\n__________________________________________________\n"

template<typename T>
class List
{
	class Element
	{
		T data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(T data, Element* pNext = nullptr, Element* pPrev = nullptr) :data(data), pNext(pNext), pPrev(pPrev)
		{
			std::cout << "EConstructor:\t" << this << std::endl;
		}
		~Element()
		{
			std::cout << "EDestructor:\t" << this << std::endl;
		}
		friend class List;
	};
	Element* head; //�������� ��������� �� ������ ������
	Element* tail; //��������� �� ����� ������
	unsigned int size; //���������� ��������� ������
public:

	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp)
		{
			this->Temp = Temp;
			//std::cout << "ItConstructor:\t" << this << std::endl;
		}
		~Iterator()
		{
			//std::cout << "ItDestructor:\t" << this << std::endl;
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
		const T& operator*()const
		{
			return Temp->data;
		}
		T& operator*()
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

	const Iterator begin()const
	{
		return this->head;
	}
	Iterator begin()
	{
		return this->head;
	}

	const Iterator end()const
	{
		return nullptr;
	}
	Iterator end()
	{
		return nullptr;
	}
	//////////////////////////////////////////////////////////
	class ReverseIterator
	{
		Element* Temp;
	public:
		ReverseIterator(Element* Temp)
		{
			this->Temp = Temp;
			//std::cout << "RConstructor:\t" << this << std::endl;
		}
		~ReverseIterator()
		{

		}
		
		//		Operators
		ReverseIterator& operator++()
		{
			Temp = Temp->pPrev;
			return *this;
		}
		ReverseIterator& operator++(int)
		{
			ReverseIterator old = *this;
			Temp = Temp->pPrev;
			return old;
		}
		const T& operator*()const
		{
			return Temp->data;
		}
		T& operator*()
		{
			return Temp->data;
		}

		bool operator==(const ReverseIterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const ReverseIterator& other)const
		{
			return this->Temp != other.Temp;
		}
	};
	const ReverseIterator rbegin()const
	{
		return tail;
	}
	const ReverseIterator rend()const
	{
		return nullptr;
	}

	///////////////////////////////////////////////////////
	List()
	{
		head = tail = nullptr;
		size = 0;
		std::cout << "LConstructor:\t" << this << std::endl;
	}
	List(std::initializer_list<T> il) :List()
	{
		std::cout << typeid(il.begin()).name() << std::endl;
		/*for (int const* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}*/
		for (T i : il)
		{
			push_back(i);
		}
	}
	List(const List<T>& other) :List()
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
	List(List<T>&& other)
	{
		this->head = other.head;
		this->tail = other.tail;
		this->size = other.size;
		other.head = other.tail = nullptr;
		std::cout << "LMoveConstructor: " << this << std::endl;
	}
	~List()
	{
		while (head)pop_front();
		//while (tail)pop_back();
		std::cout << "LDestructor:\t" << this << std::endl;
	}

	//		Operators:
	List<T>& operator=(List<T>&& other)
	{
		while (head)pop_front();
		this->head = other.head;
		this->tail = other.tail;
		this->size = other.size;
		other.head = other.tail = nullptr;
		std::cout << "LMoveAssignment: " << this << std::endl;
		return *this;
	}
	List<T>& operator=(const List<T>& other)
	{
		if (this == &other) return *this;
		while (head)pop_front();
		for (Element* Temp = other.head; Temp; Temp++)
		{
			push_back(Temp->data);
		}
		std::cout << std::endl << "LCopyAssignment\t" << this << std::endl;
		return *this;
	}

	//		Adding elements
	void push_front(T data)
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
	void push_back(T data)
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
	void insert(int index, T data)
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
		//Temp = Temp->pNext = Temp->pNext->pPrev = new Element(data, Temp->pNext, Temp);		//Temp->pNext->pPrev = Temp; //���������� ������ ������ �������� � ��������� �������
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

template<typename T>
List<T> operator+(const List<T>& left, const List<T>& right)
{
	List<T> buffer = left;
	//for (List<T>::Iterator it = right.begin(); it != right.end(); it++)
	//{
	//	buffer.push_back(*it);
	//}
	for (T i : right) buffer.push_back(i);
	std::cout << "Global operator +" << std::endl;
	return buffer;
}

//#define BASE_CHECK
//#define CONSTRUCTORS_CHECK
//#define OPERATOR_PLUS_CHECK
#define TEMPLATE_CHECK

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
#ifdef OPERATOR_PLUS_CHECK
	/*int arr[] = { 3, 5, 8, 13, 21 };
	for (int i : arr)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;*/


	List list = { 3, 5, 8, 13, 21 };

	for (List::Iterator it = list.begin(); it != list.end(); it++)
		std::cout << *it << "\t";
	std::cout << Delimiter << std::endl;

	List list2 = { 1, 2, 3 };
	for (List::Iterator it = list2.begin(); it != list2.end(); it++)	std::cout << *it << "\t";
	std::cout << Delimiter << std::endl;

	for (int i : list + list2)
	{
		std::cout << i << std::endl;
	}
	std::cout << Delimiter << std::endl;

	List list3;
	list3 = list + list2;
	list3.print();

	for (List::ReverseIterator rit = list3.rbegin(); rit != list3.rend(); rit++)
	{
		std::cout << *rit << "\t";
	}
	std::cout << std::endl;
#endif // OPERATOR_PLUS_CHECK
#ifdef TEMPLATE_CHECK
	
	List<int> list1 = { 3, 5, 8, 13, 21 };
	for (List<int>::Iterator it = list1.begin(); it != list1.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;

	/*List<double> list2 = { 2.7, 3.14, 5.5 };
	for(double i:list2) std::cout << i << "\t";
	std::cout << std::endl;

	List<std::string> list3 = { "Hello", "World", "How", "are", "you?" };
	for (std::string i : list3)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;*/

	List<int> list2 = { 34, 55, 89 };
	for (int i : list2)
		std::cout << i << "\t";
	std::cout << std::endl; 

	List<int> list3 = list1 + list2;
	list3.print();

#endif // TEMPLATE_CHECK

}