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
	int a;		//обявление переменной 'a', типа 'int'.
	Point A;	//обявление переменной 'A', типа 'Point'
				//Создание(обявление) обекта 'A' типа 'Point'.
	A.x = 5;
	A.y = 2;
	std::cout << A.x << "\t" << A.y << std::endl;

	Point* pA = &A; //Обявление указателя на 'Point' 'pA' на адрес 'A'
	std::cout << pA->x << "\t" << pA->y << std::endl;
	std::cout << (*pA).x << "\t" << (*pA).y << std::endl;
#endif // basics
	/*
		'.'	 -	Оператор прямого доступа (Point operator),
				используется для обращения к полям (членам) обекта по имени обекта
		'->' -	Операто коственного доступа (Arrow operator),
				используется для обращения к нолям обекта по адресу обекта
				Часто возникают ситуации когда имя обекта узнать невозможно, но мы всегда можем узнать адрес обекта при помощи 'this'

	*/

#ifdef enncapsulation
	Point A;
	A.set_x(3);
	A.set_y(5);
	std::cout << A.get_x() << "\t" << A.get_y() << std::endl;
#endif // enncapsulation

}