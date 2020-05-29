#include "Employee.h"
#include "Bools.h"

ostream & operator>>(fstream & stream, Employee & worker)
{
	stream >> worker.departmentName >> worker.surname >> worker.name >> worker.personPosition >> worker.targetRaiting2 >> worker.targetRaiting1 >> worker.targetRaiting3 >> worker.targetRaiting4 >> worker.targetRaiting5;
	return stream;
}

istream & operator>>(istream & stream, Employee & worker)
{
	while (1) {
		cout << "¬ведите название отдела сотрудника" << endl;
		stream >> worker.departmentName;
		if (checkString(worker.departmentName)) break;
		else worker.departmentName = "";
	}
	while (1) {
		cout << "¬ведите фамилию сотрудника" << endl;
		stream >> worker.surname;
		if (checkString(worker.surname)) break;
		else worker.surname = "";
	}
	while (1) {
		cout << "¬ведите им€ сотрудника" << endl;
		stream >> worker.name;
		if (checkString(worker.name)) break;
		else worker.name = "";
	}
	while (1) {
		cout << "¬ведите должность сотрудника" << endl;
		stream >> worker.personPosition;
		if (checkString(worker.personPosition)) break;
		else worker.personPosition = "";
	}
	while (1) {
		cout << "¬ведите оценку первой цели" << endl;
		stream >> worker.targetRaiting1;
		if (checkNumber(worker.targetRaiting1) && worker.targetRaiting1 < 6) break;
		else cout << "ќценка должна быть меньше или равна 5" << endl;
	}
	while (1) {
		cout << "¬ведите оценку второй цели" << endl;
		stream >> worker.targetRaiting2;
		if (checkNumber(worker.targetRaiting2) && worker.targetRaiting2 < 6 && worker.targetRaiting2 != worker.targetRaiting1) break;
		else cout << "ќценка должна быть меньше или равна 5 и не равна предыдущей " << endl;
	}
	while (1) {
		cout << "¬ведите оценку третьей цели"<< endl;
		stream >> worker.targetRaiting3;
		if (checkNumber(worker.targetRaiting3) && worker.targetRaiting3 < 6 && worker.targetRaiting3 != worker.targetRaiting1 && worker.targetRaiting3 != worker.targetRaiting2) break;
		else cout << "ќценка должна быть меньше или равна 5 и не равна предыдущим" << endl;
	}	
	while (1) {
		cout << "¬ведите оценку четвЄртой цели" << endl;
		stream >> worker.targetRaiting4;
		if (checkNumber(worker.targetRaiting4) && worker.targetRaiting4 < 6 && worker.targetRaiting4 != worker.targetRaiting1 && worker.targetRaiting4 != worker.targetRaiting2 && worker.targetRaiting4 != worker.targetRaiting3) break;
		else cout << "ќценка должна быть меньше или равна 5 и не равна предыдущим" << endl;
	}	
	while (1) {
		cout << "¬ведите оценку п€той цели" << endl;
		stream >> worker.targetRaiting5;
		if (checkNumber(worker.targetRaiting5) && worker.targetRaiting5 < 6 && worker.targetRaiting5 != worker.targetRaiting1 && worker.targetRaiting5 != worker.targetRaiting2 && worker.targetRaiting5 != worker.targetRaiting3 && worker.targetRaiting5 != worker.targetRaiting4) break;
		else cout << "ќценка должна быть меньше или равна 5 и не равна предыдущим" << endl;
	}
	return stream;
}

ostream & operator<<(ostream & stream, Employee & worker)
{
	stream << "|" << setw(21) << worker.getFactoryName() << "|" << setw(20) << worker.getSurname() << "|" << setw(20) << worker.getName() << "|" << setw(20) << worker.getPersonPosition() << "|" << setw(20) << worker.getTargetRaiting1() << "|" << setw(20) << worker.getTargetRaiting2() << "|" << setw(20) << worker.getTargetRaiting3() << "|" << setw(21) << worker.getTargetRaiting4() << "|" << setw(20) << worker.getTargetRaiting5() << "|";
	return stream;
}

ostream & operator<<(fstream & stream, Employee & worker)
{
	stream << worker.getFactoryName() << " " << worker.getSurname() << " " << worker.getName() << " " << worker.getPersonPosition() << " " << worker.getTargetRaiting1() << " " << worker.getTargetRaiting2() << " " << worker.getTargetRaiting3() << " " << worker.getTargetRaiting4() << " " << worker.getTargetRaiting5();
	return stream;
}

string Employee::getSurname()
{
	return surname;
}

string Employee::getName()
{
	return name;
}

int Employee::getTargetRaiting1()
{
	return targetRaiting1;
}

int Employee::getTargetRaiting2()
{
	return targetRaiting2;
}

int Employee::getTargetRaiting3()
{
	return targetRaiting3;
}

int Employee::getTargetRaiting4()
{
	return targetRaiting4;
}

int Employee::getTargetRaiting5()
{
	return targetRaiting5;
}