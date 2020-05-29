#include<iostream>
#include<thread>
#include<conio.h>
using namespace std::chrono_literals;

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
		//std::cout << "Tank ready:\t" << this << std::endl;
	}
	~Tank()
	{
		std::cout << "Tank destroyed:\t" << this << std::endl;
	}

	//bool not_empty()
	//{
	//	return fuel_level;
	//}
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
	double give_fuel(double amount)
	{
		fuel_level -= amount;
		if (fuel_level < 0)fuel_level = 0;
		return fuel_level;
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
		this->consuption = consuption < 3 ? 3 : consuption>20 ? 20 : consuption;
		this->consuption_per_second = this->consuption / 1000;
		is_started = false;
		//std::cout << "Engine is ready:\t" << this << std::endl;
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

class Car
{
	Engine engine;
	Tank tank;
	bool driver_inside;
	unsigned int speed;
	unsigned int max_speed;
	struct ControlPanel
	{
		//поток (thread) - ето последовательность команд процессораю В потоке запускается выполнение какой-то функции.
		std::thread* main_thread;	//етот поток создается при создании машины и существует столько, сколько существует машины
		//етот поток принимает команды пользователя, позволяет войти и выйти из машины, а следовательно рождает и останавливает остальные потоки
		std::thread* panel_thread;	//панель приборов. Мы видим панель приборов и можем на нее повлиять только когда мы находимся в машине
		//етот поток независим от работы двигателя. Он существует только тогда когда водитель находится внутри
		//этот поток отслеживает состояние,, в том числе и бака
		std::thread* idle_thread;	//холостой ход двигателя. создается, когда мы заводим машину, и удаляется когда мы останавливаем двигатель
									//етот поток влияет на состояние бака
		std::thread* wheelinng_thread;

		ControlPanel()
		{
			main_thread = panel_thread = idle_thread = wheelinng_thread = nullptr;
		}
	}control_panel;


public:
	Car(double tank_volume, double engine_consumption, unsigned int max_speed = 250) :
		tank(tank_volume), engine(engine_consumption), driver_inside(false), speed(0), max_speed(max_speed
		)
	{
		control_panel.main_thread = new std::thread(&Car::control, this);
		std::cout << "Your car is ready to go." << std::endl;
		std::cout << "[Enter] - to get in. \n[F] - to fill tank" << std::endl;
	}
	~Car()
	{
		control_panel.main_thread->join();
		std::cout << "Your car is over" << std::endl;
	}

	//			Functions:
	void get_in()
	{
		driver_inside = true;
		control_panel.panel_thread = new std::thread(&Car::panel, this);
	}
	void get_out()
	{
		driver_inside = false;
		control_panel.panel_thread->join();
		system("cls");
		std::cout << "You are on street, please press [Enter] to get in\n";
	}
	bool is_driver_inside()const
	{
		return driver_inside;
	}
	void fill(double fuel)
	{
		tank.fill(fuel);
	}
	void start()
	{
		if (!tank.get_fuel_level())
		{
			std::cout << "No fuel.\n";
			return;
		}
		if (driver_inside)
		{
			engine.start();
			control_panel.idle_thread = new std::thread(&Car::idle, this);
		}
	}
	void stop()
	{
		engine.stop();
		control_panel.idle_thread->join();
	}
	void panel()const
	{
		while (driver_inside)
		{
			system("CLS");
			std::cout << "Engine is " << (engine.started() ? "started" : "stopped");
			std::cout << "\tFuel:\t" << tank.get_fuel_level() << " liters.\t" << std::endl;
			//if (tank.get_fuel_level() < 5) std::cout << "Low Fuel\n";
			std::cout << (tank.get_fuel_level() < 5 ? "Low Fuel\n" : "\n");
			std::cout << speed << " km/h.\n";
			std::cout << "[Enter] - to get out\n";
			std::cout << "[I] - to ignite\n";
			//std::cout << "[R] - to ride(not working)\n";


			std::this_thread::sleep_for(500ms);
		}
	}
	void idle()
	{
		while (engine.started() && tank.give_fuel(engine.get_consuption_per_second()))
		{

			std::this_thread::sleep_for(1s);
		}
		engine.stop();
	}
	//void ride()
	//{
	//	
	//	// Зависимость потребления от скорости ?
	//	while (engine.started() && tank.give_fuel((tank.get_fuel_level() >= 5 ? 0.005 : 0.001) * this->speed))
	//	{
	//		std::cout << "я еду?\n"; //проверка на активность. потом удалить
	//		
	//		std::this_thread::sleep_for(1s);
	//	}
	//	//engine.stop();
	//}
	void control()
	{

		char key = 0;
		do
		{
			key = _getch();
			switch (key)
			{
				//case 'E':
			case 13:
				if (!is_driver_inside())get_in();
				else get_out();
				break;
			case'F':
			case'f':
				if (!driver_inside)
				{
					double amount;
					std::cout << "How much? "; std::cin >> amount;
					fill(amount);
				}
				else
				{
					std::cout << "Get out of car!" << std::endl;
				}
				break;
			case 'I':
			case 'i':	//ignition
				if (!engine.started())
				{
					start();
				}
				else
				{
					stop();
				}
				break;
			case 'W':
			case 'w':
				if (engine.started())
				{
					speed += 10;
					if (speed > max_speed) speed = max_speed;
				}
				break;
			case 'S':
			case 's':
				if(speed > 20)speed -= 20;
				else if (speed > 10) speed -= 10;
				else if (speed > 5) speed -= 5;
				else speed = 0;
				break;
			}


			std::this_thread::sleep_for(1s);
			if
					(
					speed > 0 &&
					control_panel.wheelinng_thread == nullptr
					)
			{
				control_panel.wheelinng_thread = new std::thread(&Car::free_wheeling, this);
			}
			/*else if (speed>0&&!control_panel.wheelinng_thread->joinable()) 
			{ 
				control_panel.wheelinng_thread = new std::thread(&Car::free_wheeling, this);
			}*/
			else if
					(
					speed == 0 &&
					control_panel.wheelinng_thread &&
					control_panel.wheelinng_thread->joinable()
					)
			{
				control_panel.wheelinng_thread->join();
				control_panel.wheelinng_thread = nullptr;
			}
		} while (key != 27);
	}

	////////////////////////////////	Driving		////////////////////////////
	void accellerate()
	{
		if (engine.started() && speed < max_speed)
		{
			speed += 10;
		}
		if (speed > max_speed)speed = max_speed;
		//std::this_thread::sleep_for(1s);
	}
	void free_wheeling()
	{

		while (speed > 0)
		{
			speed--;
			std::this_thread::sleep_for(1s);
		}
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

		Car bmw(60, 8);

}