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
	~ForwardList()
	{
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
			std::cout << "\t Error: out of ramge" << std::endl;
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
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)
		{
			Temp = Temp->pNext;
		}
		delete Temp;
		Temp = Temp->pNext;
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


void main()
{
	setlocale(LC_ALL, "");
	int n;
	std::cout << "input size: "; std::cin >> n;
	//Element e(5);
	ForwardList fl;
	int index; 

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
	int number;
	std::cout << "������� ��������:"; std::cin >> number;
	fl.insert(index, number);
	fl.print();

	//std::cout << Delimeter << "������� ������ (��� ��������)" << std::endl;
	//fl.erase(index);
	//fl.print();

	ForwardList fl2;
	fl2.push_back(3);
	fl2.push_back(5);
	fl2.push_back(8);
	fl2.push_back(13);
	fl2.print();
	////��� ����� �������
	//int* pa = new int(2);
	//delete pa;
	//int* arr = new int[5]{ 2, 3, 5, 8, 13 };
	//delete[] arr;
}