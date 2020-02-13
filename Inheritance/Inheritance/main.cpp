#include<iostream>

class Box
{
	double width;
	double heigh;
	double lengh;
	bool closed;
public:
	Box(double width , double lengh , double heigh ) :width(width), lengh(lengh), heigh(heigh), closed(true)
	{
		std::cout << "BoxConstructor\t" << this << std::endl;
	}
	~Box()
	{
		std::cout << "BoxDestructor\t" << this << std::endl;
	}

	void open()
	{
		if (closed) 
		{
			std::cout << " U OPEN the f*ckin BOX" << std::endl;
			closed = false;
		}
		else	std::cout << "BOX already OPEN" << std::endl;

	}
	void close()
	{
		if (!closed)
		{
			std::cout << "Closing the BOX" << std::endl;
			closed = true;
		}
		else	std::cout << "BOX already CLOSED" << std::endl;
	}

	void get_status()const
	{
			std::cout << "Box is " << (closed ? "closed" : "opened") << std::endl;
	}
};

class GiftBox :public Box
{
	std::string cover_color;
	bool bant;
public:
	GiftBox(double width, double lengh, double heigh, std::string color):Box(width, lengh, heigh)
	{
		std::cout << "GB_constructor" << this << std::endl;
	}
	~GiftBox()
	{
		std::cout << "GB_DE_constructor" << this << std::endl;
	}

};

void main()
{
	setlocale(LC_ALL, "");

	Box box1(2, 2, 1);
	box1.get_status();
	box1.open();
	box1.get_status();
	box1.close();
	box1.get_status();

	GiftBox box2( 2, 2, 1, "green");
	box2.get_status();
}