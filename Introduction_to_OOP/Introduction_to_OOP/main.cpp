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
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
};

//#define basics
#define enncapsulation

void main()
{
	setlocale(LC_ALL, "");
#ifdef basics
	int a;		//��������� ���������� 'a', ���� 'int'.
	Point A;	//��������� ���������� 'A', ���� 'Point'
				//��������(���������) ������ 'A' ���� 'Point'.
	A.x = 5;
	A.y = 2;
	std::cout << A.x << "\t" << A.y << std::endl;

	Point* pA = &A; //��������� ��������� �� 'Point' 'pA' �� ����� 'A'
	std::cout << pA->x << "\t" << pA->y << std::endl;
	std::cout << (*pA).x << "\t" << (*pA).y << std::endl;
#endif // basics
	/*
		'.'	 -	�������� ������� ������� (Point operator),
				������������ ��� ��������� � ����� (������) ������ �� ����� ������
		'->' -	������� ����������� ������� (Arrow operator),
				������������ ��� ��������� � ����� ������ �� ������ ������
				����� ��������� �������� ����� ��� ������ ������ ����������, �� �� ������ ����� ������ ����� ������ ��� ������ 'this'

	*/

#ifdef enncapsulation
	Point A;
	A.set_x(3);
	A.set_y(5);
	std::cout << A.get_x() << "\t" << A.get_y() << std::endl;
#endif // enncapsulation

}