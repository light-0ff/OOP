#include<iostream>

#define Delimeter "\n_________________________\n"
// static . -> (:: - Scope operator)
class Element
{
	int Data;		//�������� ��������
	Element* pNext;	//������ ���������� ��������
	static int count;	// ������� ��������� ������
public:
	Element(int Data, Element* pNext = nullptr):Data(Data), pNext(pNext)
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
	ForwardList()
	{
		Head = nullptr; //���� ������ ����, �� ��� ������ ��������� �� 0.
		Size = 0;
		std::cout << "FLConstructor:\t" << this << std::endl;
	}
	ForwardList(int size) :ForwardList()
	{
		//for (int i = 0; i < size; i++)
		//{
		//	push_front(rand() % 200);
		//}
		while(size--)push_front(rand() % 200);
	}
	~ForwardList()
	{
		while (Head) pop_front();
		std::cout << "FLDestructor:\t" << this << std::endl;
	}


	//		Adding elements:
	void push_front(int Data)
	{
		Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;
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
		Element* New = new Element(Data);
		New->pNext = Temp->pNext;
		Temp->pNext = New;
		Size++;
	}

	//		Removing elements:
	void pop_front()
	{
		Element* buffer = Head; // ���������� ������ ���������� ��������
		Head = Head->pNext; //��������� ������� �� ������
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
		//if (index == Size - 1)
		//{
		//	pop_back();
		//	return;
		//}
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
		Element* Temp = Head;		//�������� - ���������, ���  ������ �������� ����� �������� ������ � ��������� ��������� ������
		while (Temp != nullptr)
		{
			std::cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << std::endl;
			Temp = Temp->pNext;
		}
		std::cout << "List size: " << Size << " elements.\n";
	}
};

//#define FIRST_LIST
//#define SECOND_LIST
void main()
{
	setlocale(LC_ALL, "");
	int n;
	//Element e(5);
	int index; 
	int number;
#ifdef FIRST_LIST
	ForwardList fl;

	for (int i = 0; i < n; i++)
	{
		fl.push_back(rand() % 200);
	}
	std::cout << Delimeter << std::endl;
	fl.push_back(1024);
	fl.print();

	std::cout << Delimeter << "������� 1�:" << std::endl;
	fl.pop_front();
	fl.print();
	std::cout << Delimeter << "������� ���������:" << std::endl;
	fl.pop_back();
	fl.print();

	std::cout << Delimeter << "������� ������ (��� ����������)" << std::endl;
	std::cin >> index;
	std::cout << "������� ��������:"; std::cin >> number;
	fl.insert(index, number);
	fl.print();

	std::cout << "input size: "; std::cin >> n;
#endif // FIRST_LIST

	//std::cout << Delimeter << "������� ������ (��� ��������)" << std::endl;
	//fl.erase(index);
	//fl.print();
#ifdef SECOND_LIST
	ForwardList fl2;
	fl2.push_back(3);
	fl2.push_back(5);
	fl2.push_back(8);
	fl2.push_back(13);
	fl2.print();

	std::cout << Delimeter << "������� ������ (��� ��������)" << std::endl;
	std::cin >> index;
	fl2.erase(index);
	fl2.print();

#endif // SECOND_LIST


	std::cout << Delimeter << "������� ������ ������" << std::endl;
	std::cin >> number;
	ForwardList fl3(number);
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



	////��� ����� �������
	//int* pa = new int(2);
	//delete pa;
	//int* arr = new int[5]{ 2, 3, 5, 8, 13 };
	//delete[] arr;
}