#pragma once
#include "Manufactory.h"

class Employee
	:public Manufactory
{
protected:
	string name, surname;	
	int targetRaiting1, targetRaiting2, targetRaiting3, targetRaiting4, targetRaiting5;
public:
	Employee() {
		name = surname = "";
		targetRaiting1 = targetRaiting2 = targetRaiting3 = targetRaiting4 = targetRaiting5 = 0;
	}
	string getSurname();
	string getName();
	int getTargetRaiting2();
	int getTargetRaiting3();
	int getTargetRaiting1();
	int getTargetRaiting4();
	int getTargetRaiting5();
	friend ostream& operator >> (fstream & stream, Employee&worker);
	friend istream& operator >> (istream & stream, Employee&worker);
	friend ostream& operator << (ostream & stream, Employee&worker);
	friend ostream& operator << (fstream & stream, Employee&worker);
};