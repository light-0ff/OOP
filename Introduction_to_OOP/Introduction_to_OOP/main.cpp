#include<iostream>
#include <math.h>

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
		//if ��������� ����������� ��������
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//		Constructor's:
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
	Point operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		std::cout << "CoppyAssignment:\t" << this << std::endl;
		return *this;
	}

	//		Methods
	void print() const
	{
		std::cout << "x = " << x << "\t" << "y = " << y << std::endl;
	}
	
	double distance(const Point& other) const //������ (1) const ���-�� �� �������� ��������
	{
		/*double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
		return distance;*/

		return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
	}
	
	Point add(const Point& other)
	{

	}
};
double distance2(const Point& A, const Point& B)
{
	//return sqrt((B.get_x() - A.get_x()) * (B.get_x() - A.get_x()) + (B.get_y() - A.get_y()) * (B.get_y() - A.get_y()));
	double x_distance = B.get_x() - A.get_x();
	double y_distance = B.get_y() - A.get_y();
	double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
	return distance;
}

//#define BASICS
//#define ENCAPSULATION
//#define CONSTRUCTORS
//#define DISTANCE
//#define ASSIGNMENT_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASICS
	int a;		//��������� ���������� 'a', ���� 'int'.
	Point A;	//��������� ���������� 'A', ���� 'Point'
				//��������(���������) ������ 'A' ���� 'Point'.
	A.x = 5;
	A.y = 2;
	std::cout << A.x << "\t" << A.y << std::endl;

	Point* pA = &A; //��������� ��������� �� 'Point' 'pA' �� ����� 'A'
	std::cout << pA->x << "\t" << pA->y << std::endl;
	std::cout << (*pA).x << "\t" << (*pA).y << std::endl;
#endif // BASICS
	/*
		'.'	 -	�������� ������� ������� (Point operator),
				������������ ��� ��������� � ����� (������) ������ �� ����� ������
		'->' -	������� ����������� ������� (Arrow operator),
				������������ ��� ��������� � ����� ������ �� ������ ������
				����� ��������� �������� ����� ��� ������ ������ ����������, �� �� ������ ����� ������ ����� ������ ��� ������ 'this'

	*/

#ifdef ENCAPSULATION
	Point A;
	A.set_x(3);
	A.set_y(5);
	std::cout << A.get_x() << "\t" << A.get_y() << std::endl;
#endif // enncapsulation
#ifdef CONSTRUCTORS
	const Point B; //��������� 
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


	//Point B;	//Default constructor
	//B = A;		//Copy Assignment
#endif // CONSTRUCTORS
#ifdef ASSIGNMENT_CHECK
	//Singlle argumetn constructor:
	/*Point A = 5;
	Point B(8);*/

	//Point C(5, 2);
	//Point D = C; //assignnemt
	//Point E;
	//E = D; //Copy assignment

	int a, b, c;
	a = b = c = 0;

	Point A, B, C;
	A = B = C = Point(5, 3);
#endif // ASSIGNMENT_CHECK
#ifdef DISTANCE
	Point A(5, 2);
	Point B(8, 3);
	A.print();
	B.print();
	std::cout << A.distance(B) << std::endl << std::endl;

	std::cout <<"	���������: " << distance2(A, B) << std::endl;
	A.print();
	B.print();

#endif // DISTANCE

	//���������� ����������

	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(5, 2);
	Point B(8, 3);
	Point C;
	//C = A + B;

}