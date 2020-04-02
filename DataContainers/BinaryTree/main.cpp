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

	void insert(int data)
	{
		insert(data, this->getRoot());
	}
	void print()
	{
		print(this->Root);
		std::cout << std::endl;
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
		else
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(data);
			else insert(data, Root->pRight);
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
	//		Methods:
	void print(Element* Root)const
	{
		if (Root == nullptr) return;
		print(Root->pLeft);
		std::cout << Root->data << "\t";
		print(Root->pRight);
	}
};

void main()
{
	//std::cout << "Hello World";
	int n;
	std::cout << "Input numbers of elements: "; std::cin >> n;
	BTree T800;
	for (int i = 0; i < n; i++)
	{
		T800.insert(rand() % 100);
	}
	T800.print();

	std::cout << T800.minValue() << std::endl;
	std::cout << T800.maxValue() << std::endl;

}