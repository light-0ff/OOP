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
	Fraction(int integer = 0, double numerator = 0, double denominator = 0)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;
		std::cout << "DefaultConstructor:\t" << this << std::endl;;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		std::cout << "CopyConstructor: " << this << std::endl;
	}
	~Fraction()
	{
		std::cout << "Destructor:\t" << this << std::endl;
	}
	/////////////////////////////////////////////////////////////
	//		Operators
	Fraction operator=(const Fraction& other) //const
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		std::cout << "CoppyAssignment:\t" << this << std::endl;
		return *this;
	}
	Fraction& operator+=(const Fraction& other)
	{
		int HOK_A = NOK(this->denominator, other.denominator) / denominator;
		int HOK_B = NOK(this->denominator, other.denominator) / other.denominator;
		if (this->denominator != other.denominator)
		{
			std::cout << "THIS" << std::endl;
			this->integer += other.integer;
			this->numerator = numerator * HOK_A + other.numerator * HOK_B;
			this->denominator = other.denominator * HOK_A;
		}
		else {
			std::cout << "ELSE" << std::endl;
			this->integer += other.integer;
			this->numerator += other.numerator;
			this->denominator = denominator;
		}
		std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		return *this;
	}
	Fraction& operator-=(const Fraction& other)
	{
		int HOK_A = NOK(this->denominator, other.denominator) / denominator;
		int HOK_B = NOK(this->denominator, other.denominator) / other.denominator;
		if (this->denominator != other.denominator)
		{
			std::cout << "THIS" << std::endl;
			this->integer -= other.integer;
			this->numerator = numerator * HOK_A - other.numerator * HOK_B;
			this->denominator = denominator * HOK_A;
		}
		else {
			std::cout << "ELSE" << std::endl;
			this->integer -= other.integer;
			this->numerator -= other.numerator;
			this->denominator = denominator;
		}
		std::cout << "----------------------------------------------" << std::endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		if (this->denominator != other.denominator)
		{
			std::cout << "THIS" << std::endl;
			this->integer *= other.integer;
			this->numerator *= other.numerator;
			this->denominator *= other.denominator;
		}
		else {
			std::cout << "ELSE" << std::endl;
			this->integer *= other.integer;
			this->numerator *= other.numerator;
			this->denominator = denominator;
		}
		std::cout << "----------------------------------------------" << std::endl;
		return *this;
	}
	Fraction& operator/=(const Fraction& other)
	{
		if (this->denominator != other.denominator)
		{
			std::cout << "THIS" << std::endl;
			this->integer /= other.integer;
			this->numerator /= other.denominator;
			this->denominator /= other.numerator;
		}
		else {
			std::cout << "ELSE" << std::endl;
			this->integer -= other.integer;
			this->numerator -= other.denominator;
			this->denominator = numerator;
		}
		std::cout << "----------------------------------------------" << std::endl;
		return *this;
	}
	Fraction operator+(const Fraction& other) //const
	{
		int HOK_A = NOK(this->denominator, other.denominator) / denominator;
		int HOK_B = NOK(this->denominator, other.denominator) / other.denominator;
		Fraction result;
		if (this->denominator != other.denominator)
		{
			result.integer = 0;
			std::cout << result.integer << std::endl;

			result.numerator = (this->numerator * HOK_A) + (other.numerator * HOK_B);
			std::cout << result.numerator << std::endl;

			result.denominator = this->denominator * HOK_A;
			std::cout << result.denominator << std::endl;
		}
		else
		{
			result.integer = 0;
			std::cout << result.integer << std::endl;

			result.numerator = this->numerator + other.numerator;
			std::cout << result.numerator << std::endl;

			result.denominator = this->denominator;
			std::cout << result.denominator << std::endl;
		}

		result.print();

		return result;
	}
	Fraction operator-(const Fraction& other) //const
	{
		int HOK_A = NOK(this->denominator, other.denominator) / denominator;
		int HOK_B = NOK(this->denominator, other.denominator) / other.denominator;
		Fraction result;
		result.integer = 0;
		std::cout << result.integer << std::endl;

		result.numerator = ((this->numerator * HOK_A) - (other.numerator * HOK_B));
		std::cout << result.numerator << std::endl;

		if (this->denominator != other.denominator)
		{
			result.denominator = this->denominator * HOK_A;
		}
		std::cout << result.denominator << std::endl;

		result.print();
		return result;
	}
	Fraction operator*(const Fraction& other) const
	{

		Fraction result;
		result.integer = 0;
		std::cout << result.integer << std::endl;

		result.numerator = this->numerator * other.numerator;
		std::cout << result.numerator << std::endl;

		if (this->denominator != other.denominator)
		{
			result.denominator = this->denominator * other.denominator;
		}
		std::cout << result.denominator << std::endl;

		result.print();

		return result;
	}
	Fraction operator/(const Fraction& other) const
	{
		Fraction result;
		result.integer = 0;
		std::cout << result.integer << std::endl;

		result.numerator = this->numerator * other.denominator;
		std::cout << result.numerator << std::endl;

		if (this->denominator != other.denominator)
		{
			result.denominator = this->denominator * other.numerator;
		}
		std::cout << result.denominator << std::endl;

		result.print();

		return result;
	}
	//		Methods
	void print() const
	{
		std::cout << "x = " << integer << "(" << numerator << "/" << denominator << ")" << std::endl;
	}
	void to_proper()
	{
		if (numerator >= denominator)
		{
			this->integer += numerator / denominator;
			this->numerator = (numerator - (integer * denominator));
		}
		else {
			std::cout << "дробь и так правильная ";
		}
	}
	void to_improper()
	{
		this->numerator += integer * denominator;
		this->integer = 0;
	}

};



//Fraction operator+(const Fraction& left, const Fraction& right)
//{
//	return (1, 2, 3);
//}

void main()
{
	setlocale(LC_ALL, "");
	/*
	try
	{
	Fraction A;
	A.set_integer(2);
	A.set_numerator(3);
	A.set_denominator(0);
	}
	catch (std::exception e)
	{
	std::cerr << e.what() << std::endl;
	}
	*/
	std::cout << "Fraction A:" << std::endl;
	Fraction A;
	A.set_integer(1);
	A.set_numerator(8);
	A.set_denominator(12);

	std::cout << "\t первая дробь ";
	A.print();

	std::cout << "правельная дробь: \t";
	A.to_proper();
	A.print();
	std::cout << "неправельная дробь: \t";
	A.to_improper();
	A.print();
	std::cout << "снова правельная дробь: \t";
	A.to_proper();
	A.print();

	std::cout << delimiter << std::endl;
	std::cout << "Fraction B:" << std::endl;
	Fraction B;
	B.set_integer(0);
	B.set_numerator(2);
	B.set_denominator(20);

	std::cout << "\t вторая дробь ";
	B.print();

	std::cout << "Наименьшее общее кратное " << NOK(A.get_denominator(), B.get_denominator()) << std::endl;
	//
	//A += B;
	//A.print();
	//A -= B;
	//A.print();

	std::cout << delimiter << std::endl;
	std::cout << "Fraction C:" << std::endl;
	Fraction C = A + B;
	C.print();
	std::cout << line << std::endl;
	C = A - B;
	C.print();
	std::cout << line << std::endl;
	C = A * B;
	C.print();
	std::cout << line << std::endl;
	//C = A / B;
	C = C / B;
	C.print();
	std::cout << line << std::endl;
	
	std::cout << delimiter << std::endl;
}