#include<iostream>

#define DELIMETER std::cout<<"\n______________________________________\n";

class Tank
{
	unsigned int volume;	//характерезует обект, показывает какой он(обект), меняться не может
	double fuel_level;		//состояне обекта, которое может меняться
public:
	const unsigned int get_volume()const
	{
		return volume;
	}
	const double get_fuel_level()const
	{
		return fuel_level;
	}
	

	Tank(const unsigned int volume)
	{
		this->volume = volume < 20 ? 20 : volume>100 ? 100 : volume;
		this->fuel_level = 0;
		std::cout << "Tank ready:\t" << this << std::endl;
	}
	~Tank()
	{
		std::cout << "Tank destroyed:\t" << this << std::endl;
	}

	void fill(double fuel)
	{
		if (fuel < 0)return;
		if (fuel_level + fuel <= volume)
		{
			this->fuel_level += fuel;
		}
		else
		{
			fuel_level = volume;
		}
	}
	void info() const
	{
		std::cout << "Tank volume:\t" << volume << "\t liters.\t\t";
		std::cout << "Fuel level:\t" << fuel_level << "\t liters." << std::endl;
	}
};

class Engine
{
	double consuption;
	double consuption_per_second;
	bool is_started;
public:
	const double get_consuption()const
	{
		return consuption;
	}
	const double get_consuption_per_second()const
	{
		return consuption_per_second;
	}
	Engine(double consuption)
	{
		this->consuption = consuption<3 ? 3 : consuption>20 ? 20 : consuption;
		this->consuption_per_second = this->consuption / 1000;
		is_started = false;
		std::cout << "Engine is ready:\t" << this << std::endl;
	}
	~Engine()
	{
		std::cout << "Engine is over:\t" << this << std::endl;
	}

	void start()
	{
		is_started = true;
	}
	void stop()
	{
		is_started = false;
	}
	bool started()const
	{
		return is_started;
	}
	void info()const
	{
		std::cout << "Engine consuption:\t" << get_consuption() << "liters per 100 km" << std::endl;
		std::cout << "Consuption per sec:\t" << get_consuption_per_second() << "liters per sec" << std::endl;
		std::cout << "Engine is " << (is_started ? "started" : "stopped") << std::endl;
	}

};

//#define TANKHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef TANKHECK
	Tank tank(40);
	tank.info();
	DELIMETER
		tank.fill(20);
	tank.info();
	DELIMETER
		tank.fill(30);
	tank.info();
	DELIMETER
#endif // TANKHECK



}