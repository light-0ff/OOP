#include<iostream>

#define Delimiter "\n_________________________\n"
// static . -> (:: - Scope operator)
class Element
{
	int Data;		//Значение елемента
	Element* pNext;	//Адресс следующего елемента
	static int count;	// подсчет елементов списка
public:
	const int getData()const
	{
		return Data;
	}
	const Element* getpNext()const
	{
		return pNext;
	}
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
		std::cout << "EConstructor:\t" << this << std::endl;
	}
	~Element()
	{
		count--;
		std::cout << "EDestructor:\t" << this << std::endl;
	}
	friend class ForwardList;
};

int Element::count = 0;

class ForwardList
{
	Element* Head;
	unsigned int Size;
public:
	const Element* get_head()const
	{
		return Head;
	}
	unsigned int get_size()const
	{
		return Size;
	}
	ForwardList()
	{
		Head = nullptr; //Если список пуст, то его голова указывает на 0.
		Size = 0;
		std::cout << "FLConstructor:\t" << this << std::endl;
	}
	ForwardList(int size) :ForwardList()
	{
		//for (int i = 0; i < size; i++) push_front(rand() % 200);
		while (size--)push_front(0);
	}
	ForwardList(const std::initializer_list<int>& il) :ForwardList()
	{
		for (const int* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
	}
	ForwardList(const ForwardList& other) :ForwardList()
	{
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext) push_back(Temp->Data);
		std::cout << "FLCopyConstructor: " << this << std::endl;
	}
	ForwardList(ForwardList&& other)
	{
		this->Head = other.Head;
		this->Size = other.Size;
		other.Head = nullptr;
		std::cout << "FLMoveConstructor: " << this << std::endl;
	}
	
	~ForwardList()
	{
		while (Head) pop_front();
		std::cout << "FLDestructor:\t" << this << std::endl;
	}

	//		Operators
	ForwardList& operator=(ForwardList&& other)
	{
		this->Head = other.Head;
		this->Size = other.Size;
		other.Head = nullptr;
		std::cout << "FLMoveAssignment: " << this << std::endl;
		return *this;
	}
	ForwardList& operator=(const ForwardList& other)
	{
		while (Head)pop_front();
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext) push_back(Temp->Data);
		std::cout << std::endl << "FLCopyAssignment\t" << this << std::endl;
		return *this;
	}
	const int& operator[](int index)const
	{
		Element* Temp = Head;		// Итератор
		for (int i = 0; i < index; i++) Temp = Temp->pNext;
		return Temp->Data;
	}
	int& operator[](int index)
	{
		Element* Temp = Head;		// Итератор
		for (int i = 0; i < index; i++) Temp = Temp->pNext;
		return Temp->Data;
	}
	
	//		Adding elements:
	void push_front(int Data)
	{
		//Element* New = new Element(Data);
		//New->pNext = Head;
		//Head = New;
		Head = new Element(Data, Head);
		Size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		Element* Temp = Head;
		while (Temp->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = new Element(Data);
		Size++;
	}
	void insert(int index, int Data)
	{
		if (index > Size)
		{
			throw std::exception("Error: out of ramge");
			return;
		}
		if (index == 0)
		{
			push_front(Data);
			return;
		}
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)
		{
			Temp = Temp->pNext;
		}
		//Element* New = new Element(Data);
		//New->pNext = Temp->pNext;
		//Temp->pNext = New;
		Temp->pNext = new Element(Data, Temp->pNext);
		Size++;
	}

	//		Removing elements:
	void pop_front()
	{
		Element* buffer = Head; // Запоминаем аддрес удаляемого елемента
		Head = Head->pNext; //Исключаем елемент из списка
		delete buffer;
		Size--;
	}
	void pop_back()
	{
		Element* Temp = Head;
		while (Temp->pNext->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		delete Temp->pNext;
		Temp->pNext = nullptr;
		Size--;
	}
	void erase(int index)
	{
		if (index >= this->Size)
		{
			throw std::exception("Error: out of ramge when erasing");
			return;
		}
		if (index <= 0)
		{
			pop_front();
			return;
		}
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)	Temp = Temp->pNext;
		Element* buffer = Temp->pNext;	//save addres of deleted element
		Temp->pNext = Temp->pNext->pNext;	//exclude deleted element from list
		delete buffer;		//remove element from memory
		Size--;
	}

	//		Methods
	void print()const
	{
		Element* Temp = Head;		//Итератор - указатель, при  помощи которого можно получить доступ к елементам структуры данных
		while (Temp != nullptr)
		{
			std::cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << std::endl;
			Temp = Temp->pNext;
		}
		std::cout << "List size: " << Size << " elements.\n";
	}
};

/*
ForwardList operator+(const ForwardList& left, const  ForwardList& right)
{
	ForwardList New = left;	// Вариант CopyConstructor
		
					// ||	|  |	 |  |
	//////////		Временнй вариант		////////////////
	//ForwardList New;									 //
	//for (int i = 0; i < left.get_size(); i++)			//
	//{												   //
	//	New.push_back(left[i]);						  //
	//}												 //
	////////////////////////////////////////////////////

	//	Добавляем в конец right список
	for (int i = 0; i < right.get_size(); i++)	New.push_back(right[i]);
	return New;
} */
ForwardList operator+(const ForwardList& left, const  ForwardList& right)
{
	ForwardList buffer = left;	// Вариант CopyConstructor
	for (const Element* Temp = right.get_head(); Temp != nullptr; Temp = Temp->getpNext()) 
	{ buffer.push_back(Temp->getData()); }
	return buffer;
}
//#define BASE_FUNCTION_CHECK
//#define FIRST_LIST
//#define SECOND_LIST
//#define CONSTRUCTORS_CHECK_1
#define CONSTRUCTORS_CHECK_2
void main()
{
	setlocale(LC_ALL, "");
	int n;
	//Element e(5);
	int index; 
	int number;
#ifdef BASE_FUNCTION_CHECK
#ifdef FIRST_LIST
	ForwardList fl;

	for (int i = 0; i < n; i++)
	{
		fl.push_back(rand() % 200);
	}
	std::cout << Delimiter << std::endl;
	fl.push_back(1024);
	fl.print();

	std::cout << Delimiter << "удалить 1й:" << std::endl;
	fl.pop_front();
	fl.print();
	std::cout << Delimiter << "удалить последний:" << std::endl;
	fl.pop_back();
	fl.print();

	std::cout << Delimiter << "Введите индекс (для добавления)" << std::endl;
	std::cin >> index;
	std::cout << "Введите значение:"; std::cin >> number;
	fl.insert(index, number);
	fl.print();

	std::cout << "input size: "; std::cin >> n;
#endif // FIRST_LIST

	//std::cout << Delimeter << "Введите индекс (для удаления)" << std::endl;
	//fl.erase(index);
	//fl.print();
#ifdef SECOND_LIST
	ForwardList fl2;
	fl2.push_back(3);
	fl2.push_back(5);
	fl2.push_back(8);
	fl2.push_back(13);
	fl2.print();

	std::cout << Delimiter << "Введите индекс (для удаления)" << std::endl;
	std::cin >> index;
	fl2.erase(index);
	fl2.print();

#endif // SECOND_LIST

	std::cout << Delimiter << "Введите размер списка" << std::endl;
	std::cin >> number;
	ForwardList fl3(number);
	fl3.print();

	std::cout << Delimiter << "Введите индекс: " << std::endl;
	std::cin >> index;
	std::cout << "Введите значение:"; std::cin >> number;
	fl3.insert(index, number);
	fl3.print();
	//try
	//{
	//	std::cout << "input index" << std::endl; std::cin >> index;
	//	fl3.erase(index);
	//	fl3.print();
	//}
	//catch (const std::exception& e)
	//{
	//	/*
	//	cin  - Console input
	//	cout - Console output
	//	cerr - Console Error
	//	*/
	//	std::cerr << e.what() << std::endl;
	//}

#endif // BASE_FUNCTION_CHECK
#ifdef CONSTRUCTORS_CHECK_1
	std::cout << Delimiter << "Введите размер: " ;
	std::cin >> index;
	ForwardList fl(index);
	fl.print();
	fl.push_back(3);
	fl.push_back(5);
	fl.push_back(8);
	fl.push_back(13);
	fl.print();
	for (int i = 0; i < fl.get_size(); i++)
	{
		fl[i] = rand() % 100;
	}
	for (int i = 0; i < fl.get_size(); i++)
	{
		std::cout << fl[i] << "\t";
	}
	std::cout << std::endl;

#endif // CONSTRUCTORS_CHECK
#ifdef CONSTRUCTORS_CHECK_2
	ForwardList list = { 3, 5, 8, 13, 21 };
	list.print();
	//for (int i = 0; i < list.get_size(); i++) std::cout << list[i] << "\t";
	ForwardList list2 = {34, 55, 89};	
	list2.print();
	ForwardList list3;
	list3 = list + list2;
	list3.print();

	//std::cout << Delimiter << std::endl;
	//ForwardList list2 = { 1, 2, 3, 4, 5 };
	//std::cout << Delimiter << std::endl;
	//std::cout << Delimiter << std::endl;
	//ForwardList list3 = list + list2;
	//std::cout << Delimiter << std::endl;
	//list3.print();
	//std::cout << Delimiter << std::endl;
	//std::cout << Delimiter << std::endl;


#endif // CONSTRUCTORS_CHECK_2




	////как нужно удалять
	//int* pa = new int(2);
	//delete pa;
	//int* arr = new int[5]{ 2, 3, 5, 8, 13 };
	//delete[] arr;
}