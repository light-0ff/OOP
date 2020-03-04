#pragma once
#include<iostream>
#include<string>
#include<regex>
#include<Windows.h>

class Human
{
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name() const
	{
		return last_name;
	}
	const std::string& get_first_name() const
	{
		return first_name;
	}
	const unsigned int get_age() const
	{
		return age;
	}

	void set_last_name(const std::string& last_name)
	{
		//std::regex exp ("\\w");
		this->last_name = last_name;
		//std::wregex rgx_eng(L"[A-Z][a-z]{1,10}");
		//std::regex_match(last_name, rgx_eng, std::regex_constants::match_default) == true ? this->last_name :this->last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	//Constructor
	Human(const std::string& last_name, const std::string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		std::cout << "HConstructor:\t" << this << std::endl;
	}
	virtual ~Human()
	{
		std::cout << "HDestructor:\t" << this << std::endl;
	}
	virtual void print()const
	{
		//std::ios_base::left;
		std::cout.width(8);
		std::cout << last_name << "\t";
		std::cout.width(10);
		std::cout << first_name << "\t";
		std::cout.width(8);
		std::cout << age << std::endl;
	}
};

class Student :public Human
{
	std::string spec;
	std::string group;
	unsigned int rating;
	unsigned int attendence;
public:
	const std::string&	get_speciality()const
	{
		return spec;
	}
	const std::string& get_group() const
	{
		return group;
	}
	unsigned int get_rating() const
	{
		return rating;
	}
	unsigned int get_attendence() const
	{
		return attendence;
	}
	void set_speciality(const std::string& spec)
	{
		this->spec = spec;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(unsigned int rating)
	{
		this->rating = rating <= 100 ? rating : 100;
	}
	void set_attendence(unsigned int attendence)
	{
		this->attendence = attendence <= 100 ? attendence : 100;
	}

	//	Constructors
	Student
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& spec, const std::string group, unsigned int rating = 0, unsigned int attendence = 0
	) :Human(last_name, first_name, age)
	{
		set_speciality(spec);
		set_group(group);
		set_rating(rating);
		set_attendence(attendence);
		//this->rating = this->attendence = 0;
		std::cout << "SConstructor:\t" << this << std::endl;
	}
	~Student()
	{
		std::cout << "SDestructor:\t" << this << std::endl;
	}
	void print()const
	{
		Human::print();
		std::cout << spec << "\t" << group << "\t успеваемость " << rating << "%, посещения " << attendence << "%\n";
	}
};

class Teacher :public Human
{
	std::string subject;
	unsigned int experience;
	unsigned int evil;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	unsigned int get_evil()const
	{
		return evil;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	void set_evil(unsigned int evil)
	{
		this->evil = evil;
	}
	//constr
	Teacher
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& subject, unsigned int experience, unsigned int evil = 20
	) :Human(last_name, first_name, age)
	{
		set_subject(subject);
		set_experience(experience);
		set_evil(evil);
		std::cout << "TConstructor:\t" << this << std::endl;
	}
	~Teacher()
	{
		std::cout << "TDestructor:\t" << this << std::endl;
	}

	void print()const
	{
		Human::print();
		std::cout << "Предмет: " << subject << "\t опыт: " << experience << " лет\t стрессоустойчивость: " << evil << "%" << "\n";
	}
};

class Graduate :public Student
{
	std::string diploma_theme;
	std::string curator;
	void set_diploma_theme(const std::string& diploma_theme)
	{
		this->diploma_theme = diploma_theme;
	}
public:
	const std::string get_diploma_theme()const
	{
		return diploma_theme;
	}
	const std::string get_curator()const
	{
		return curator;
	}
	//private:
	//	void set_diploma_theme(const std::string& diploma_theme)
	//	{
	//		this->diploma_theme = diploma_theme;
	//	}
	//public:
	void set_curator(const std::string& curator)
	{
		this->curator = curator;
	}

	// Constructor's:
	Graduate
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& spec, const std::string group, unsigned int rating, unsigned int attendence,
		const std::string& diploma_theme, const std::string& curator
	) :Student(last_name, first_name, age,
		spec, group, rating, attendence)
	{
		set_diploma_theme(diploma_theme);
		set_curator(curator);
		std::cout << "GConstructor:\t" << this << std::endl;
	}
	~Graduate()
	{
		std::cout << "GDestructor:\t" << this << std::endl;
	}
	void print()const
	{
		Student::print();
		std::cout << "Diploma theme:\t" << diploma_theme << " Куратор: " << curator << std::endl;
	}

};