#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
using namespace std;

class Student
{
private:
	int number;			//学号
	string name;		//姓名
	char gender;		//性别
	string major;		//专业
	int birthyear;		//出生年
	int birthmonth;		//出生月
public:
	Student();
	~Student();
	friend ostream & operator<<(ostream & os, Student & s1);	//重载输出流
	friend istream & operator>>(istream & is, Student & s1);	//重载输入流
	friend bool operator!=(Student & s1,int num);
	
	int getNumber(Student s);
	string getName(Student s);
	char getGender(Student s);
	string getMajor(Student s);
	int getBirthyear(Student s);
	int getBirthmonth(Student s);
	
	void setNumber(int number);
	void setName(string name);
	void setGender(char gender);
	void setMajor(string major);
	void setBirthyear(int birthyear);
	void setBirthmonth(int birthmonth);
};

#endif // STUDENT_H
