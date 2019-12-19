#include<iostream>

class Point
{
	double x;
	double y;
public:
	double get_x() const
	{
		return x;
	}
	double get_y() const
	{
		return y;
	}
	void set_x(double x) //const
	{
		if (/*x >= 100 && x <= 100*/ abs(x) <= 100)
		{
			this->x = x;
		}
		else
		{
			this->x = 0;
		}
		//if фильтрует некоректные згачени€
	}
	void set_y(double y)
	{
		this->y = y;
	}
	//		Constructor's:
	/*Point()
	{
		x = y = 0;
		std::cout << "DefaultConstructor:\t" << this << std::endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		std::cout << "DefaultConstructor:\t" << this << std::endl;;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		std::cout << "CopyConstructor: " << this << std::endl;
	}
	~Point()
	{
		std::cout << "Destructor:\t" << this << std::endl;
	}
	//Operators
	void operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		std::cout << "CoppyAssignment:\t" << this << std::endl;
	}

	//		Methods
	void print() const
	{
		std::cout << "x = " << x << "\t" << "y = " << y << std::endl;
	}
};

//#define BASICS
//#define ENCAPSULATION
//#define CONSTRUCTORS

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASICS
	int a;		//об€вление переменной 'a', типа 'int'.
	Point A;	//об€вление переменной 'A', типа 'Point'
				//—оздание(об€вление) обекта 'A' типа 'Point'.
	A.x = 5;
	A.y = 2;
	std::cout << A.x << "\t" << A.y << std::endl;

	Point* pA = &A; //ќб€вление указател€ на 'Point' 'pA' на адрес 'A'
	std::cout << pA->x << "\t" << pA->y << std::endl;
	std::cout << (*pA).x << "\t" << (*pA).y << std::endl;
#endif // BASICS
	/*
		'.'	 -	ќператор пр€мого доступа (Point operator),
				используетс€ дл€ обращени€ к пол€м (членам) обекта по имени обекта
		'->' -	ќперато коственного доступа (Arrow operator),
				используетс€ дл€ обращени€ к нол€м обекта по адресу обекта
				„асто возникают ситуации когда им€ обекта узнать невозможно, но мы всегда можем узнать адрес обекта при помощи 'this'

	*/

#ifdef ENCAPSULATION
	Point A;
	A.set_x(3);
	A.set_y(5);
	std::cout << A.get_x() << "\t" << A.get_y() << std::endl;
#endif // enncapsulation
#ifdef CONSTRUCTORS
	const Point B; //ќб€вление 
	//std::cout << B.get_x() << std::endl;
	B.print();
	
	Point C = 5;
	C.print();

	Point D(6);
	D.print();

	Point E(5, 2);
	E.print();

	//Copy construct
	Point F = E;
	F.print();
	Point G;
	G = E;
	G.print();


#endif // CONSTRUCTORS

	Point A(5, 2);
	A.print();
	Point B;	//Default constructor
	B = A;		//Copy Assignment
	B.print();
	//Copy assignment

}