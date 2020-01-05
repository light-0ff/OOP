#include<iostream>

class Fraction
{
	int integer;
	double numerator;
	double denominator;
public: //
	//get & set методы
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
	Fraction(/*double x = integer,*/ double numerator = 0, double denominator = 0)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;
		std::cout << "DefaultConstructor:\t" << this << std::endl;;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.denominator;
		this->denominator = other.denominator;
		std::cout << "CopyConstructor: " << this << std::endl;
	}
	~Fraction()
	{
		std::cout << "Destructor:\t" << this << std::endl;
	}
/////////////////////////////////////////////////////////////
		//		Operators
	Fraction operator+(const Fraction& other) const
	{
		//int HOK_A = HOK(this->denominator, other.denominator) / this->denominator;
		//int HOK_B = HOK(this->denominator, other.denominator) / other.denominator;
		Fraction result;
		result.numerator = (this->numerator * other.denominator) + (other.numerator * this->denominator);
		result.denominator = this->denominator * other.denominator;
		result.integer = 0;
		return result;
	}
	Fraction operator-(const Fraction& other) const
	{
		Fraction result;
		result.numerator = (this->numerator * other.denominator) - (other.numerator * this->denominator);
		result.denominator = this->denominator * other.denominator;
		result.integer = 0;
		return result;
	}
	Fraction operator*(const Fraction& other) const
	{
		Fraction result;
		result.numerator = this->numerator * other.numerator;
		result.denominator = this->denominator * other.denominator;
		result.integer = 0;
		return result;
	}
	Fraction operator/(const Fraction& other) const
	{
		Fraction result;
		result.numerator = this->numerator * other.denominator;
		result.denominator = this->denominator * other.numerator;
		result.integer = 0;
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
			this->numerator = 0;
		}
	}
	void to_improper()
	{
		this->numerator += integer * denominator;
		this->integer = 0;
	}
};

//int HOK(int denominator1, int denominator2)
//{
//	return denominator1 * denominator2 / HOK(denominator1, denominator2);
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
	Fraction A;
	A.set_integer(0);
	A.set_numerator(4);
	A.set_denominator(7);

	A.print();

	A.to_proper();
	A.print();
	A.to_improper();
	A.print();

	Fraction B;
	B.set_integer(0);
	B.set_numerator(2);
	B.set_denominator(5);

	B.print();

	Fraction C = A / B;
	C.print();

}