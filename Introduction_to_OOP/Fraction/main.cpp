#include<iostream>
#include <math.h>

#define delimiter "\n========================================================\n"
#define line "\n-----------------------------------------\n"

int NOD(int n1, int n2)
{
	int div;
	if (n1 == n2)  return n1;
	int d = n1 - n2;
	if (d < 0) {
		d = -d;  div = NOD(n1, d);
	}
	else
		div = NOD(n2, d);
	return div;
}
int NOK(int n1, int n2)
{
	return n1 * n2 / NOD(n1, n2);
}

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public: //get & set ������

	int get_integer() const
	{
		return integer;
	}
	int get_numerator() const
	{
		return numerator;
	}
	int get_denominator() const
	{
		return denominator;
	}

	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(double numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(double denominator)
	{
		if (denominator != 0)
		{
			this->denominator = denominator;
		}
		else
		{
			this->denominator = 1;
			//throw std::exception("F*ckin F..k, nilza tak delat!!!");
		}
		this->denominator = denominator ? denominator : 1;
	}
	////////////////////////////////////////////////////////////////
	//		Constructor's:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		std::cout << "ZeroConstructor:\t" << this << std::endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		std::cout << "SingleArgConstruct:\t" << this << std::endl;
	}
	Fraction(double numerator, double denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->denominator = denominator;
		std::cout << "DoubleArgConstructor:\t" << this << std::endl;
	}
	Fraction(int integer, double numerator , double denominator )
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;
		std::cout << "DefaultConstructor:\t" << this << std::endl;
	}
	//Fraction(const Fraction& other)
	//{
	//	this->integer = other.integer;
	//	this->numerator = other.numerator;
	//	this->denominator = other.denominator;
	//	std::cout << "CopyConstructor: " << this << std::endl;
	//}
	~Fraction()
	{
		std::cout << "Destructor:\t" << this << std::endl;
	}
	/////////////////////////////////////////////////////////////
	//		Operators

	//Fraction operator+(const Fraction& other) //const
	//{
	//	//if (this->denominator != other.denominator)
	//	//{
	//	//	result.integer = 0;
	//	//	result.numerator = (this->numerator * HOK_A) + (other.numerator * HOK_B);
	//	//	result.denominator = this->denominator * HOK_A;
	//	//}
	//	//else
	//	//{
	//	//	result.integer = 0;
	//	//	result.numerator = this->numerator + other.numerator;
	//	//	result.denominator = this->denominator;
	//	//}
	//	Fraction result;
	//	Fraction left = *this;
	//	Fraction right = other;
	//	left.to_improper();
	//	right.to_improper();
	//	int HOK_A = NOK(left.denominator, right.denominator) / left.denominator;
	//	int HOK_B = NOK(left.denominator, right.denominator) / right.denominator;
	//	if (left.denominator != right.denominator)
	//	{
	//		result.numerator = (left.numerator * HOK_A) + (right.numerator * HOK_B);
	//		result.denominator = left.denominator * HOK_A;
	//	}
	//	else
	//	{
	//		result.numerator = left.numerator + right.numerator;
	//		result.denominator = left.denominator;
	//	}
	//	result.to_proper();
	//	return result;
	//}
	//Fraction operator-(const Fraction& other) //const
	//{
	//	Fraction result;
	//	Fraction left = *this;
	//	Fraction right = other;
	//	left.to_improper();
	//	right.to_improper();
	//	int HOK_A = NOK(left.denominator, right.denominator) / left.denominator;
	//	int HOK_B = NOK(left.denominator, right.denominator) / right.denominator;
	//	if (left.denominator != right.denominator)
	//	{
	//		result.numerator = (left.numerator * HOK_A) - (right.numerator * HOK_B);
	//		result.denominator = left.denominator * HOK_A;
	//	}
	//	else
	//	{
	//		result.numerator = left.numerator - right.numerator;
	//		result.denominator = left.denominator;
	//	}
	//	result.to_proper();
	//	return result;
	//}
//	Fraction operator*(const Fraction& other) const
//	{
//		Fraction result;
//		Fraction left = *this;
//		Fraction right = other;
//		left.to_improper();
//		right.to_improper();
//		result.numerator = left.numerator * right.numerator;
//		result.denominator = left.denominator * right.denominator;
//		result.to_proper();
//	/*	if (other.integer) {
//			result.numerator = this->numerator * (other.denominator + other.integer * other.denominator);
//		}
//		if (other.integer == 0) {
//			result.numerator = this->numerator * other.numerator;
//		}
//
//		if (this->denominator != other.denominator)
//		{
//			result.denominator = this->denominator * other.denominator;
//		}
//*/
//		return result;
//	}
	//Fraction operator/(const Fraction& other) const
	//{
	//	Fraction result;
	//	Fraction left = *this;
	//	Fraction right = other;
	//	left.to_improper();
	//	right.to_improper();
	//	result.numerator = left.numerator * right.denominator;
	//	result.denominator = left.denominator * right.numerator;
	//	result.to_proper();
	//	//if (other.integer) {
	//	//	result.numerator = this->numerator * (other.denominator + other.integer * other.denominator);
	//	//}
	//	//if (other.integer == 0) {
	//	//	result.numerator = this->numerator * other.denominator;
	//	//}
	//	return result;
	//}
	Fraction& operator+=(const Fraction& other) //const
	{
		Fraction left = *this;
		Fraction right = other;
		left.to_improper();
		right.to_improper();
		int HOK_A = NOK(left.denominator, right.denominator) / left.denominator;
		int HOK_B = NOK(left.denominator, right.denominator) / right.denominator;
		if (left.denominator != right.denominator)
		{
			left.numerator = (left.numerator * HOK_A) + (right.numerator * HOK_B);
			left.denominator = left.denominator * HOK_A;
		}
		else
		{
			left.numerator = left.numerator + right.numerator;
			left.denominator = left.denominator;
		}

		left.to_proper();
		*this = left;
		//this->integer = left.get_integer();
		//this->numerator = left.get_numerator();
		//this->denominator = left.get_denominator();
		return *this;
	}
	Fraction& operator-=(const Fraction& other) //const
	{
		Fraction left = *this;
		Fraction right = other;
		left.to_improper();
		right.to_improper();
		int HOK_A = NOK(left.denominator, right.denominator) / left.denominator;
		int HOK_B = NOK(left.denominator, right.denominator) / right.denominator;
		if (left.denominator != right.denominator)
		{
			left.numerator = (left.numerator * HOK_A) - (right.numerator * HOK_B);
			left.denominator = left.denominator * HOK_A;
		}
		else
		{
			left.numerator = left.numerator - right.numerator;
			left.denominator = left.denominator;
		}
		left.to_proper();
		*this = left;
		//this->integer = left.get_integer();
		//this->numerator = left.get_numerator();
		//this->denominator = left.get_denominator();
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		Fraction left = *this;
		Fraction right = other;
		left.to_improper();
		right.to_improper();
		left.numerator = left.numerator * right.numerator;
		left.denominator = left.denominator * right.denominator;
		
		left.to_proper();
		*this = left;
		//this->integer = left.get_integer();
		//this->numerator = left.get_numerator();
		//this->denominator = left.get_denominator();
		return *this;
	}
	Fraction operator/=(const Fraction& other)
	{
		Fraction left = *this;
		Fraction right = other;
		left.to_improper();
		right.to_improper();
		left.numerator = left.numerator * right.denominator;
		left.denominator = left.denominator * right.numerator;

		left.to_proper();
		*this = left;
		//this->integer = left.get_integer();
		//this->numerator = left.get_numerator();
		//this->denominator = left.get_denominator();
		return *this;
	}

	//		Methods
	void print() const
	{
		//std::cout << "x = " << integer << "(" << numerator << "/" << denominator << ")" << std::endl;
		if (integer)std::cout << integer;
		if (numerator)
		{
			if (integer)std::cout << "(";
			std::cout << numerator << "/" << denominator;
			if (integer)std::cout << ")";
		}
		if (integer == 0 && numerator == 0)std::cout << 0;
		std::cout << std::endl;
	}
	void to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		//if (numerator >= denominator)
		//{
		//	this->integer += numerator / denominator;
		//	this->numerator = (numerator - (integer * denominator));
		//}
		//else {
		//	std::cout << "����� � ��� ���������� ";
		//}
	}
	void to_improper()
	{
		this->numerator += integer * denominator;
		this->integer = 0;
	}

};

Fraction operator+(Fraction left, Fraction right)
{
	Fraction result;

	left.to_improper();
	right.to_improper();
	int HOK_A = NOK(left.get_denominator(), right.get_denominator()) / left.get_denominator();
	int HOK_B = NOK(left.get_denominator(), right.get_denominator()) / right.get_denominator();
	if (left.get_denominator() != right.get_denominator())
	{
		result.set_numerator ( left.get_numerator() * HOK_A + right.get_numerator() * HOK_B);
		result.set_denominator ( left.get_denominator() * HOK_A);
		//Fraction resilt(0, (left.get_numerator() * HOK_A) + (right.get_numerator() * HOK_B), left.get_denominator() * HOK_A);
	}
	else
	{
		result.set_numerator ( left.get_numerator() + right.get_numerator());
		result.set_denominator ( left.get_denominator());
		//Fraction result(0, left.get_numerator() + right.get_numerator(), left.get_denominator());
	}

	result.to_proper();
	return result;
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	
	int HOK_A = NOK(left.get_denominator(), right.get_denominator()) / left.get_denominator();
	int HOK_B = NOK(left.get_denominator(), right.get_denominator()) / right.get_denominator();
	Fraction result;
	
	if (left.get_denominator() != right.get_denominator())
	{
		result.set_numerator(left.get_numerator() * HOK_A - right.get_numerator() * HOK_B);
		result.set_denominator(left.get_denominator() * HOK_A);
		//Fraction result(0, (left.get_numerator() * HOK_A) - (right.get_numerator() * HOK_B), left.get_denominator() * HOK_A);
	}
	else
	{
		result.set_numerator(left.get_numerator() - right.get_numerator());
		result.set_denominator(left.get_denominator());
		//Fraction result(0, left.get_numerator() - right.get_numerator(), left.get_denominator());
	}
	result.to_proper();
	return result;
}
Fraction operator*(Fraction left, Fraction right)
{
		left.to_improper();
		right.to_improper();
		Fraction result(0,left.get_numerator() * right.get_numerator(), left.get_denominator() * right.get_denominator());

		result.to_proper();
		return result;
}
Fraction operator/(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction result(0, left.get_numerator() * right.get_denominator(), left.get_denominator() * right.get_numerator());

	result.to_proper();
	return result;
}

////////////////////////////////////////////////////////
Fraction operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	//Fraction result;
	//if (left.get_denominator() == right.get_denominator())
	//{
	//	Fraction result(0, left.get_numerator() > right.get_numerator() ? left.get_numerator() : right.get_numerator(), left.get_denominator());
	//}
	//else
	//{
	//	double cheat_left = left.get_numerator() / left.get_denominator();
	//	double cheat_right = right.get_numerator() / right.get_denominator();
	//	if (cheat_left > cheat_right)
	//	{
	//		Fraction result(0, left.get_numerator(), left.get_denominator());
	//	}
	//	else
	//	{
	//		Fraction result(0, right.get_numerator(), right.get_denominator());
	//	}
	//}
	//
	//return result;
	double cheat_left = left.get_numerator() / left.get_denominator();
	double cheat_right = right.get_numerator() / right.get_denominator();
	//std::wcout << delimiter << std::endl << std::endl;
	if (cheat_left > cheat_right)
	{
		left.print();
		std::cout << "TRUE" << std::endl;
		return 1;
	}
	else
	{
		right.print();
		std::cout << "FALSE" << std::endl;
		return 0;
	}
}
Fraction operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	double cheat_left = left.get_numerator() / left.get_denominator();
	double cheat_right = right.get_numerator() / right.get_denominator();
	//std::wcout << delimiter << std::endl << std::endl;
	if (cheat_left < cheat_right)
	{
		left.print();
		std::cout << "TRUE" << std::endl;
		return 1;
	}
	else
	{
		right.print();
		std::cout << "FALSE" << std::endl;
		return 0;
	}
}
Fraction operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	//double cheat_left = left.get_numerator() / left.get_denominator();
	//double cheat_right = right.get_numerator() / right.get_denominator();
	//std::wcout << delimiter << std::endl << std::endl;
	//if (cheat_left == cheat_right)
	//{
	//	std::cout << "TRUE" << std::endl;
	//	return 1;
	//}
	//else
	//{
	//	std::cout << "FALSE" << std::endl;
	//	return 0;
	//}
	if (left.get_denominator() == right.get_denominator())
	{
		if (left.get_numerator() == right.get_numerator())
		{
			std::cout << "TRUE" << std::endl;
			return 1;
		}
		else
		{
			std::cout << "FALSE" << std::endl;
			return 0;
		}
	}
	else
	{
		int HOK_A = NOK(left.get_denominator(), right.get_denominator()) / left.get_denominator();
		int HOK_B = NOK(left.get_denominator(), right.get_denominator()) / right.get_denominator();
		if (left.get_numerator() * HOK_A == right.get_numerator() * HOK_B)
		{
			std::cout << "TRUE" << std::endl;
			return 1;
		}
		else
		{
			std::cout << "FALSE" << std::endl;
			return 0;
		}
	}
}

#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	std::cout << "A = ";
	A.print();
	std::cout << line << std::endl;

	Fraction B = 3;
	std::cout << "B = ";
	B.print();
	std::cout << line << std::endl;

	Fraction C(1, 2);
	std::cout << "C = ";
	C.print();
	std::cout << line << std::endl;

	Fraction D(3, 2, 5);
	std::cout << "D = ";
	D.print();
	D.to_improper();
	D.print();
	std::cout << line << std::endl;

	Fraction E(7, 10);
	std::cout << "E = ";
	E.print();
	E.to_proper();
	E.print();
	A = D * E;
	std::cout << line << "A = D * E = ";
	A.print();
	A = D + E;
	std::cout << line << "A = D + E = ";
	A.print();
	A -= C;
	std::cout << line << "A = A - C = ";
	A.print();

	std::cout << line << A.get_integer() << "(" << A.get_numerator() << "/" << A.get_denominator() << ")" << " > " << B.get_integer() << "(" << B.get_numerator() << "/" << B.get_denominator() << ")" << std::endl;
	A > C;
	std::cout << line << A.get_integer() << "(" << A.get_numerator() << "/" << A.get_denominator() << ")" << " < " << B.get_integer() << "(" << B.get_numerator() << "/" << B.get_denominator() << ")" << std::endl;
	A < C;
	A.print();
	Fraction X(1, 2); X.print();
	Fraction Z(5, 10); Z.print();
	std::cout << line << X.get_integer() << "(" << X.get_numerator() << "/" << X.get_denominator() << ")" << " == " << Z.get_integer() << "(" << Z.get_numerator() << "/" << Z.get_denominator() << ")" << std::endl;
	X == Z;
	std::cout << line;
#endif // constructors_check

}