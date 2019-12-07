#include <iostream>
#include <string>
#include <fstream>
#include "Person.h"

Person::Person()
{
	name = "";
	birthday = "";
	value = "";
};

Person::Person(std::string n) {
	name = n;
}


Person::Person(std::string n, std::string b, std::string v) {
	name = n;
	birthday = b;
	value = v;
}


/*
setName
set name of person
pre: string
post: set name
return: void
*/
void Person::setName(std::string n) {
	name = n;
}



/*
setBirthday
set birthday of person
pre: string
post: set birthday
return: void
*/
void Person::setBirthday(std::string b) {
	birthday = b;
}



/*
getName
returns name
pre:
post: return name variable
return: string
*/
std::string Person::getName() {
	return name;
}

/*
getBirthday
returns birthday
pre:
post: return birthday variable
return: string
*/
std::string Person::getBirthday() {
	return birthday;
}




/////////////////////////////////////////////////////////////
//					Operator Overloading		           //							
////////////////////////////////////////////////////////////

/*
operator >
returns true if p1 > p2
pre: person 1 and person 2
post: return boolean
return: bool
*/

bool operator > (Person p1, Person p2)
{
	if (p1.value == "birthday" && p2.value == "birthday")
	{
		if (p1.birthday > p2.birthday)
			return true;
		else
			return false;
	}

	else if (p1.value == "name" && p2.value == "name")
	{
		if (p1.name > p2.name)
			return true;
		else
			return false;
	}

	else
	{
		std::cout << "Value error. " << std::endl;
		return 1;
	}
}

/*
operator <
returns true if p1 < p2
pre: person 1 and person 2
post: return boolean
return: bool
*/
bool operator < (Person p1, Person p2)
{
	if (p1.value == "birthday" && p2.value == "birthday")
	{
		if (p1.birthday < p2.birthday)
			return true;
		else
			return false;
	}

	else if (p1.value == "name" && p2.value == "name")
	{
		if (p1.name < p2.name)
			return true;
		else
			return false;
	}

	else
	{
		std::cout << "Value error. " << std::endl;
		return 1;
	}
}

/*
operator ==
returns true if p1 == p2
pre: person 1 and person 2
post: return boolean
return: bool
*/
bool operator == (Person p1, Person p2)
{
	if (p1.value == "birthday" && p2.value == "birthday")
	{
		if (p1.birthday == p2.birthday)
			return true;
		else
			return false;
	}

	else if (p1.value == "name" && p2.value == "name")
	{
		if (p1.name == p2.name)
			return true;
		else
			return false;
	}

	else
	{
		std::cout << "Value error. " << std::endl;
		return 1;
	}
}

/*
operator <<
returns ostream and outputs person information
pre: ostream and person
post: return ostream, outputs person info
return: ostream
*/
std::ostream& operator << (std::ostream& out, const Person& p)
{
	out << p.name << "\t" << p.birthday << std::endl;
	return out;
}