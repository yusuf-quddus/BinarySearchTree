#pragma once

#include <iostream>
#include <string>

class Person {
private:
	std::string name;
	std::string birthday;
	std::string value;
public:
	// Constructors
	Person();
	Person(std::string);
	Person(std::string, std::string, std::string);

	// Setters
	void setName(std::string);
	void setBirthday(std::string);

	// Getters
	std::string getName();
	std::string getBirthday();

	// Operator Overloads
	friend bool operator > (Person, Person);
	friend bool operator < (Person, Person);
	friend bool operator == (Person, Person);
	friend std::ostream& operator << (std::ostream&, const Person&);
};