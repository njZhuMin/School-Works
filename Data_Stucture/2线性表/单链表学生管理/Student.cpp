#include "Student.h"
#include <iostream>
using namespace std;
Student::Student()
{
}

Student::~Student()
{
}

ostream & operator<<(ostream & os,Student & s1)
{
	os<<"Number:"<<s1.getNumber(s1)<<endl;
	os<<"Name:"<<s1.getName(s1)<<endl;
	os<<"Gender:"<<s1.getGender(s1)<<endl;
	os<<"Major:"<<s1.getMajor(s1)<<endl;
	os<<"Birthyear:"<<s1.getBirthyear(s1)<<endl;
	os<<"Birthmonth:"<<s1.getBirthmonth(s1)<<endl;
	return os;
}

istream & operator>>(istream & is,Student & s1)
{
	cout << "Number:";
	is >> s1.number;
	cout << "Name:";
	is >> s1.name;
	cout << "Gender:";
	is >> s1.gender;
	cout << "Major:";
	is >> s1.major;
	cout << "Birthyear:";
	is >> s1.birthyear;
	cout << "Birthmonth:";
	is >> s1.birthmonth;
	return is;
}

bool operator!=(Student & s1,int num)
{
	return (s1.number!=num);
}

int Student::getNumber(Student s)
{
	return number;
}

string Student::getName(Student s)
{
	return name;
}

char Student::getGender(Student s)
{
	return gender;
}
	
string Student::getMajor(Student s)
{
	return major;
}
	
int Student::getBirthyear(Student s)
{
	return birthyear;
}

int Student::getBirthmonth(Student s)
{
	return birthmonth;
}
	
void Student::setNumber(int number)
{
	this->number = number;
}

void Student::setName(string name)
{
	this->name = name;
}

void Student::setGender(char gender)
{
	this->gender = gender;
}

void Student::setMajor(string major)
{
	this->major = major;
}

void Student::setBirthyear(int birthyear)
{
	this->birthyear = birthyear;	
}

void Student::setBirthmonth(int birthmonth)
{
	this->birthmonth = birthmonth;
}
