#include"header.h"


List::Element::Element(int data, Element* pNext, Element* pPrev) :data(data), pNext(pNext), pPrev(pPrev)
{
	std::cout << "EConstructor:\t" << this << std::endl;
}
List::Element::~Element()
{
	std::cout << "EDestructor:\t" << this << std::endl;
}
///////////////////////////////////////////////////////////////////////

List::Iterator::Iterator(Element* Temp)
{
	this->Temp = Temp;
	//std::cout << "ItConstructor:\t" << this << std::endl;
}
List::Iterator::~Iterator()
{
	//std::cout << "ItDestructor:\t" << this << std::endl;
}

//		Operators:
List::Iterator& List::Iterator::operator++()
{
	Temp = Temp->pNext;
	return *this;
}
List::Iterator List::Iterator::operator++(int)
{
	Iterator old = *this;
	Temp = Temp->pNext;
	return old;
}
const int& List::Iterator::operator*()const
{
	return Temp->data;
}
int& List::Iterator::operator*()
{
	return Temp->data;
}
bool List::Iterator::operator==(const Iterator& other)const
{
	return this->Temp == other.Temp;
}
bool List::Iterator::operator!=(const Iterator& other)const
{
	return this->Temp != other.Temp;
}
/////////////////////////////////////////////////////////////////

const List::Iterator List::begin()const
{
	return this->head;
}
const List::Iterator List::end()const
{
	return nullptr;
}
List::Iterator List::begin()
{
	return this->head;
}
List::Iterator List::end()
{
	return nullptr;
}
/////////////////////////////////////////////////////////////////////
class ReverseIterator
{
	List::Element* Temp;
public:
	ReverseIterator(List::Element* Temp)
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
	const int& operator*()const
	{
		return Temp->data;
	}
	int& operator*()
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
//////////////////////////////////////////////////////////////////////////////////
List::List()
{
	head = tail = nullptr;
	size = 0;
	std::cout << "LConstructor:\t" << this << std::endl;
}
List::List(std::initializer_list<int> il) :List()
{
	std::cout << typeid(il.begin()).name() << std::endl;
	/*for (int const* it = il.begin(); it != il.end(); it++)
	{
		push_back(*it);
	}*/
	for (int i : il)
	{
		push_back(i);
	}
}
List::List(const List& other) :List()
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
List::List(List&& other)
{
	this->head = other.head;
	this->tail = other.tail;
	this->size = other.size;
	other.head = other.tail = nullptr;
	std::cout << "LMoveConstructor: " << this << std::endl;
}
List::~List()
{
	while (head)pop_front();
	//while (tail)pop_back();
	std::cout << "LDestructor:\t" << this << std::endl;
}

//		Operators:
List& List::operator=(List&& other)
{
	while (head)pop_front();
	this->head = other.head;
	this->tail = other.tail;
	this->size = other.size;
	other.head = other.tail = nullptr;
	std::cout << "LMoveAssignment: " << this << std::endl;
	return *this;
}
List& List::operator=(const List& other)
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
void List::push_front(int data)
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
void List::push_back(int data)
{
	if (head == nullptr)
	{
		push_front(data);
		return;
	}
	tail = tail->pNext = new Element(data, nullptr, tail);
	size++;

}
void List::insert(int index, int data)
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
void List::pop_front()
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
void List::pop_back()
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
void List::erase(int index)
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
void List::print()
{
	for (Element* Temp = head; Temp != nullptr; Temp = Temp->pNext)
	{
		std::cout << Temp->pPrev << "\t" << Temp << "\t" << Temp->data << "\t" << Temp->pNext << std::endl;
	}
	std::cout << "List size:\t" << size << std::endl;
}
void List::print_reverse()
{
	for (Element* Temp = tail; Temp != nullptr; Temp = Temp->pPrev)
	{
		std::cout << Temp->pPrev << "\t" << Temp << "\t" << Temp->data << "\t" << Temp->pNext << std::endl;
	}
	std::cout << "List size:\t" << size << std::endl;
}

List operator+(const List& left, const List& right)
{
	List buffer = left;
	for (List::Iterator it = right.begin(); it != right.end(); it++)
	{
		buffer.push_back(*it);
	}
	std::cout << "Global operator +" << std::endl;
	return buffer;
}
//////////////////////////////////////////////////////////////