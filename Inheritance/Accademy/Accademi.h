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
	const std::string& get_last_name() const;

	const std::string& get_first_name() const;

	const unsigned int get_age() const;

	void set_last_name(const std::string& last_name);

	void set_first_name(const std::string& first_name);

	void set_age(unsigned int age);

	//Constructor
	Human(const std::string& last_name, const std::string& first_name, unsigned int age);

	virtual ~Human();

	virtual void print()const;

};

class Student :public Human
{
	std::string spec;
	std::string group;
	unsigned int rating;
	unsigned int attendence;
public:
	const std::string&	get_speciality()const;

	const std::string& get_group() const;
	
	unsigned int get_rating() const;

	unsigned int get_attendence() const;

	void set_speciality(const std::string& spec);

	void set_group(const std::string& group);

	void set_rating(unsigned int rating);

	void set_attendence(unsigned int attendence);

	//	Constructors
	Student
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& spec, const std::string group, unsigned int rating = 0, unsigned int attendence = 0
	);
	~Student();

	void print()const;

};

class Teacher :public Human
{
	std::string subject;
	unsigned int experience;
	unsigned int evil;
public:
	const std::string& get_subject()const;

	unsigned int get_experience()const;

	unsigned int get_evil()const;
	
	void set_subject(const std::string& subject);

	void set_experience(unsigned int experience);

	void set_evil(unsigned int evil);

	//constr
	Teacher
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& subject, unsigned int experience, unsigned int evil = 20
	);
	~Teacher();

	void print()const;

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
	const std::string get_diploma_theme()const;

	const std::string get_curator()const;

	void set_curator(const std::string& curator);

	// Constructor's:
	Graduate
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& spec, const std::string group, unsigned int rating, unsigned int attendence,
		const std::string& diploma_theme, const std::string& curator
	);
	~Graduate();

	void print()const;

};