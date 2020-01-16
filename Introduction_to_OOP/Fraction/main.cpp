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
public: //get & set методы

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
	Fraction operator+(const Fraction& other) //const
	{
		//if (this->denominator != other.denominator)
		//{
		//	result.integer = 0;
		//	result.numerator = (this->numerator * HOK_A) + (other.numerator * HOK_B);
		//	result.denominator = this->denominator * HOK_A;
		//}
		//else
		//{
		//	result.integer = 0;
		//	result.numerator = this->numerator + other.numerator;
		//	result.denominator = this->denominator;
		//}
		Fraction result;
		Fraction left = *this;
		Fraction right = other;
		left.to_improper();
		right.to_improper();
		int HOK_A = NOK(left.denominator, right.denominator) / left.denominator;
		int HOK_B = NOK(left.denominator, right.denominator) / right.denominator;
		if (left.denominator != right.denominator)
		{
			int NOK = left.denominator * HOK_A;
			result.numerator = (left.numerator * HOK_A) + (right.numerator * HOK_B);
			result.denominator = left.denominator * HOK_A;
		}
		else
		{
			result.numerator = left.numerator + right.numerator;
			result.denominator = left.denominator;
		}

		result.to_proper();
		return result;
	}
	Fraction operator-(const Fraction& other) //const
	{
		Fraction result;
		Fraction left = *this;
		Fraction right = other;
		left.to_improper();
		right.to_improper();
		int HOK_A = NOK(left.denominator, right.denominator) / left.denominator;
		int HOK_B = NOK(left.denominator, right.denominator) / right.denominator;

		if (left.denominator != right.denominator)
		{
			result.numerator = (left.numerator * HOK_A) - (right.numerator * HOK_B);
			result.denominator = left.denominator * HOK_A;
		}
		else
		{
			result.numerator = left.numerator - right.numerator;
			result.denominator = left.denominator;
		}
		result.to_proper();
		return result;
	}
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
	Fraction operator/(const Fraction& other) const
	{
		Fraction result;
		Fraction left = *this;
		Fraction right = other;
		left.to_improper();
		right.to_improper();
		result.numerator = left.numerator * right.denominator;
		result.denominator = left.denominator * right.numerator;
		result.to_proper();
		//if (other.integer) {
		//	result.numerator = this->numerator * (other.denominator + other.integer * other.denominator);
		//}
		//if (other.integer == 0) {
		//	result.numerator = this->numerator * other.denominator;
		//}

		return result;
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
		//	std::cout << "дробь и так правильная ";
		//}
	}
	void to_improper()
	{
		this->numerator += integer * denominator;
		this->integer = 0;
	}

};

Fraction operator*(Fraction left, Fraction right)
{
		left.to_improper();
		right.to_improper();
		Fraction result(0,left.get_numerator() * right.get_numerator(), left.get_denominator() * right.get_denominator());
		//result.numerator = left.numerator * right.numerator;
		//result.denominator = left.denominator * right.denominator;
		result.to_proper();
		return result;
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
	A = A - C;
	std::cout << line << "A = A - C = ";
	A.print();
#endif // constructors_check

}