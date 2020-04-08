#include<iostream>

class BTree
{
	class Element
	{
		int data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int data, Element* pLeft = nullptr, Element* pRight = nullptr) :data(data), pLeft(pLeft), pRight(pRight)
		{
			std::cout << "EConstructor:\t" << this << std::endl;
		}
		~Element()
		{
			std::cout << "EDestructor:\t" << this << std::endl;
		}
		friend class BTree;
	}*Root;
public:
	Element* getRoot()
	{
		return this->Root;
	}
	BTree() :Root(nullptr)
	{
		std::cout << "TConstructor:\t" << this << std::endl;
	}
	~BTree()
	{
		clear(this->Root);
		std::cout << "TDestructor:\t" << this << std::endl;
	}
	//		Fake "Wraper"	---------------------------------------------
	void insert(int data)
	{
		insert(data, this->getRoot());
	}
	void erase(int Data)
	{
		erase(Data, this->Root);
	}
	int minValue()
	{
		/*int info = Root->data;
		minValue(this->Root, info);
		return info;*/
		return minValue(this->Root);
	}
	int maxValue()
	{
		return maxValue(this->Root);
	}
	int count()const
	{
		return count(this->Root);
	}
	int sum()const
	{
		return sum(this->Root);
	}
	double avg()const
	{
		return (double)sum(this->Root) / count(this->Root);
	}

	void print()
	{
		print(this->Root);
		std::cout << std::endl;
	}
	//-----------------------------------------------
private:
	//			Adding elements
	void insert(int data, Element* Root)
	{
		if (this->Root == nullptr) //Если дерево пустое, то добавляем элемент прямо в корень.
		{
			this->Root = new Element(data);
			return;
		}
		if (Root == nullptr) return;
		if (data < Root->data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(data);
			else insert(data, Root->pLeft);
		}
		else if(data > Root->data)
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(data);
			else insert(data, Root->pRight);
		}
	}
	void erase(int Data, Element*& Root)
	{
		if (Root == nullptr)return;
		if (Data < Root->data)
		{
			erase(Data, Root->pLeft);
		}
		else if (Data > Root->data)
		{
			erase(Data, Root->pRight);
		}
		else if (Data == Root->data)
		{
			if (Root->pLeft == Root->pRight)
			{
				delete Root;
				Root = nullptr;
			}
			else if (count(Root->pLeft) /*> count(Root->pRight)*/)
			{
				Root->data = maxValue(Root->pLeft);
				erase(maxValue(Root->pLeft), Root->pLeft);
			}
			else
			{
				Root->data = minValue(Root->pRight);
				erase(minValue(Root->pRight), Root->pRight);
			}
		}
	}
	void clear(Element* Root)
	{
		if (Root == nullptr)return;
		clear(Root->pLeft);
		clear(Root->pRight);
		delete Root;
	}
	int minValue(Element* Root)const
	{
		/*if (Root->pLeft == nullptr)return Root->data;
		minValue(Root->pLeft);*/
		return Root->pLeft == nullptr ? Root->data : minValue(Root->pLeft);
		/*
		if (Root == nullptr)return info;
		if (info > Root->data)
		{
			info = Root->data;
		}
		minValue(Root->pLeft, info);
		return info;
		*/
	}
	int maxValue(Element* Root)const
	{
		return Root->pRight == nullptr ? Root->data : maxValue(Root->pRight);
	}
	int count(Element* Root)const
	{
		if (Root == nullptr)return 0;
		return count(Root->pLeft) + count(Root->pRight) + 1;
	}
	int sum(Element* Root)const
	{
		if (Root == nullptr)return 0;
		return sum(Root->pLeft) + sum(Root->pRight) + Root->data;
	}


	//		Methods:
	void print(Element* Root)const
	{
		if (Root == nullptr) return;
		print(Root->pLeft);
		std::cout << Root->data << "\t";
		print(Root->pRight);
	}
};

//#define BASE_CHECK
//#define ERASE_CHECK

void main()
{
	//std::cout << "Hello World";
#ifdef BASE_CHECK
	int n;
	std::cout << "Input numbers of elements: "; std::cin >> n;
	BTree T800;
	for (int i = 0; i < n; i++)
	{
		T800.insert(rand() % 100);
	}
	T800.print();
	std::cout << std::endl;

	std::cout << "Min Value: " << T800.minValue() << std::endl;
	std::cout << "Max Value: " << T800.maxValue() << std::endl;
	std::cout << "Nomber of elements: " << T800.count() << std::endl;
	std::cout << "Summa:\t\t" << T800.sum() << std::endl;
	std::cout << "Avarage:\t\t" << T800.avg() << std::endl;
	int value;
	std::cout << "Type Value to erase: "; std::cin >> value;
	T800.erase(value);
	T800.print();
	std::cout << "Nomber of elements: " << T800.count() << std::endl;
#endif // BASE_CHECK
#ifdef ERASE_CHECK
	BTree T800;
	T800.insert(50);

	T800.insert(25);
	T800.insert(20);
	T800.insert(30);
	
	T800.insert(80);
	T800.insert(64);
	T800.insert(85);
	T800.print();
	std::cout << std::endl;

	int value;
	std::cout << "Type Value to erase: "; std::cin >> value;
	T800.erase(value);
	T800.print();

#endif // ERASE_CHECK
	/*
	BTree T800 = { 50, 25, 30, 75, 64, 85};

	int value;
	std::cout << "Type Value to erase: "; std::cin >> value;
	T800.erase(value);
	T800.print();

	BTree T1000 = T800;
	T1000.print();
	*/
}