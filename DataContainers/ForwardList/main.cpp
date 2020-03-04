#include<iostream>

class Element
{
	int Data;		//«начение елемента
	Element* pNext;	//јдресс следующего елемента
public:
	Element(int Data, Element* pNext = nullptr):Data(Data), pNext(pNext)
	{
		std::cout << "EConstructor:\t" << this << std::endl;
	}
	~Element()
	{
		std::cout << "EDestructor:\t" << this << std::endl;
	}
	friend class ForwardList;
};

class ForwardList
{
	Element* Head;
public:
	ForwardList()
	{
		Head = nullptr; //≈сли список пуст, то его голова указывает на 0.
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
		//Element* New = new Element(Data);
		//Temp->pNext = New;
		Temp->pNext = new Element(Data);
	}


	//		Methods
	void print()const
	{
		Element* Temp = Head;		//»тератор - указатель, при  помощи которого можно получить доступ к елементам структуры данных
		while (Temp != nullptr)
		{
			std::cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << std::endl;
			Temp = Temp->pNext;
		}
	}
};


void main()
{
	setlocale(LC_ALL, "");
	int n;
	std::cout << "input size: "; std::cin >> n;
	//Element e(5);
	ForwardList fl;

	for (int i = 0; i < n; i++)
	{
		fl.push_back(rand() % 200);
	}

	fl.push_back(1024);
	fl.print();
}