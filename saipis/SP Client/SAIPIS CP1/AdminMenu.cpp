#include "AdminMenu.h"

vector<Employee> employee;
vector<Employee> forFile;

fstream dataBaseIsOpen;
ofstream dataBaseIsEmpty;
string pathFileFactory = "factory.txt";

void AdminMenu::adminMenu()
{
	int choice = 1;
	while (choice != 0) {
		forFile.clear();
		cout << "���� ��������������:" << endl;
		cout << "1.������� ����� ��" << endl;
		cout << "2.�������� ������ " << endl;
		cout << "3.������������� ������" << endl;
		cout << "4.������� ������" << endl;
		cout << "5.����������� ������" << endl;
		cout << "6.����� ������" << endl;
		cout << "7.�������� ������" << endl;
		cout << "8.����� ������������" << endl;
		cout << "9.�������� ������ � ����" << endl;
		cout << "0.����� �� �������� ����" << endl;
		cout << ">>>";
		cin >> choice; white;
		system("cls");
		switch (choice) {
		case 1: {
			try
			{
				fileCreating();
			}
			catch (logic_error & le)
			{
				red cout << le.what() << endl; white
			}
			break;
		}
		case 2: {
			insert();
			break;
		}
		case 3: {
			redact();
			break;
		}
		case 4: {
			try
			{
				del();
			}
			catch (logic_error & le)
			{
				red cout << le.what() << endl; white
			}
			break;
		}
		case 5: {
			sort();
			break;
		}
		case 6: {
			try
			{
				search();
			}
			catch (invalid_argument & ia)
			{
				red cout << ia.what() << endl; white
			}
			break;
		}
		case 7: {
			show(forFile);
			break;
		}
		case 8: {
			Raiting();
			break;
		}
		case 9: {
			fileInsert();
			break;
		}
		case 0: {
			break;
		}
		default: {
			red failure white;
			break;
		}
		}
	}
}

void AdminMenu::insert()
{
	Employee w1;
	cin >> w1;
	employee.push_back(w1);
}

void AdminMenu::redact()
{
	forFile.clear();
	dataBaseIsOpen.open(pathFileFactory);
	if (dataBaseIsOpen.is_open()) {
		while (!dataBaseIsOpen.eof()) {
			Employee w;
			dataBaseIsOpen >> w;
			forFile.push_back(w);
		}
		int position = 0, number = 0;
		show(forFile);
		cout << "������� �����: " << endl;
		cin >> number;
		for (auto it = forFile.begin(); it != forFile.end() - 1; it++) {
			if (number == position + 1) {
				Employee w;
				cin >> w;
				forFile.emplace(it, w);
			//	forFile.erase(it--);
				position--;
				break;
			}
			else position++;
		}
		if (position != forFile.size()) {
			dataBaseIsOpen.close();
			cout << "������ ����� ������" << endl;
			dataBaseIsEmpty.open(pathFileFactory);
			dataBaseIsEmpty.close();
		}
		else throw logic_error("������ ������ �� ����������");
	}
	else {
		throw logic_error("������ ��� �������� �����");
		dataBaseIsOpen.close();
	}
}

void AdminMenu::del()
{
	try
	{
		forFile.clear();
		dataBaseIsOpen.open(pathFileFactory);
		if (dataBaseIsOpen.is_open()) {
			while (!dataBaseIsOpen.eof()) {
				Employee w;
				dataBaseIsOpen >> w;
				forFile.push_back(w);
			}
			int position = 0, number = 0;
			show(forFile);
			cout << "������� �����: " << endl;
			cin >> number;
			for (auto it = forFile.begin(); it != forFile.end(); it++) {
				if (number == position + 1) {
					forFile.erase(it);
					position--;
					break;
				}
				else position++;
			}
			if (position != forFile.size()) {
				green cout << "��������� � ����� ������� ������� ������" << endl; white
				dataBaseIsEmpty.open(pathFileFactory);
				for (auto it = forFile.begin(); it != forFile.end(); it++) {
					dataBaseIsEmpty << *it << endl;
				}
				forFile.clear();
				show(forFile);
				dataBaseIsEmpty.close();
			}
			else throw logic_error("����� ����� �� ����������");
		}
		else throw logic_error("������ ��� �������� �����");
		dataBaseIsOpen.close();
	}
	catch (logic_error & le)
	{
		red cout << le.what() << endl; white
	}
}

void AdminMenu::fileCreating()
{
	try
	{
		dataBaseIsOpen.open(pathFileFactory);
		if (!dataBaseIsOpen.is_open()) {
			dataBaseIsEmpty.open(pathFileFactory);
			green cout << "�� ������� �������" << endl; white
			dataBaseIsEmpty.close();
		}
		else {
			throw logic_error("�� ��� ����������");
		}
	}
	catch (logic_error & le)
	{
		red cout << le.what() << endl; white
	}
	dataBaseIsOpen.close();
}

void AdminMenu::fileInsert()
{
	if (employee.empty()) {
		throw range_error("����������� ������");
	}
	else {
		dataBaseIsOpen.open(pathFileFactory);
		if (dataBaseIsOpen.is_open()) {
			dataBaseIsOpen.close();
			dataBaseIsOpen.open(pathFileFactory, fstream::app);
			for (auto it = employee.begin(); it != employee.end(); it++) {
				dataBaseIsOpen << *it << endl;
			}

			green cout << "������ ������� �������� � ��" << endl; white
		}
		else {
			red cout << "����������� ������ � ��" << endl; white
		}
		dataBaseIsOpen.close();
	}
}

void UserMenu::userMenu()
{
	int choice = 1;
	while (choice != 0) {
		forFile.clear();
		cout << "���� ��������������:" << endl;
		cout << "1.����������� ������" << endl;
		cout << "2.����� ������" << endl;
		cout << "3.�������� ������" << endl;
		cout << "4.����� ������������" << endl;
		cout << "0.����� �� �������� ����" << endl;
		green cout << ">>>";
		cin >> choice; white;
		system("cls");
		switch (choice) {
		case 1: {
			sort();
			break;
		}
		case 2: {
			try
			{
				search();
			}
			catch (invalid_argument & ia)
			{
				red cout << ia.what() << endl; white
			}
			break;
		}
		case 3: {
			show(forFile);
			break;
		}
		case 4: {
			Raiting();
			break;
		}
		case 0: {
			break;
		}
		default: {
			red failure white;
			break;
		}
		}
	}
}

void UserMenu::show(vector<Employee> w)
{
	dataBaseIsOpen.open(pathFileFactory);
	if (dataBaseIsOpen.is_open()) {
		while (!dataBaseIsOpen.eof()) {
			Employee workerObject;
			dataBaseIsOpen >> workerObject;
			w.push_back(workerObject);
		}
		int count = 1;
		cout << "*****************************************************************************************************************************************************************************************************" << endl;
		cout << setw(5) << "�" << "|" << setw(21) << "�������� ������" << "|" << setw(20) << "������� ����������" << "|" << setw(20) << "��� ����������" << "|" << setw(20) << "��������� ����������" << "|" << setw(20) << "������ ������ ����" << "|" << setw(20) << "������ ������ ����" << "|" << setw(20) << "������ ������� ����" << "|" << setw(20) << "������ �������� ����" << "|" << setw(20) << "������ ����� ����" << "|" << endl;
		cout << "*****************************************************************************************************************************************************************************************************"<< endl;

		for (auto it = w.begin(); it != w.end() -1 ; it++) {
			cout << setw(3) << count++ << ") " << *it << endl;
			cout << "*****************************************************************************************************************************************************************************************************" << endl;
		}
		cout << "\n" << endl;
	}
	else throw logic_error("������ ��� �������� ��");
	w.clear();
	dataBaseIsOpen.close();
}

void UserMenu::search()
{
	dataBaseIsOpen.open(pathFileFactory);
	if (dataBaseIsOpen.is_open()) {
		int choice = 1;
		while (choice != 0) {
			cout << left << "����� ��:" << endl;
			cout << "1.�������� ������ ����������" << endl;
			cout << "2.������� ����������" << endl;
			cout << "3.����� ����������" << endl;
			cout << "4.��������� ����������" << endl;
			cout << "5.���������� ������ ������ ����" << endl;
			cout << "6.���������� ������ ������ ����" << endl;
			cout << "7.���������� ������ ������� ����" << endl;
			cout << "8.���������� ������ �������� ����" << endl;
			cout << "9.���������� ������ ����� ����" << endl;
			cout << "0.�����" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1: {
				forFile.clear();
				while(!dataBaseIsOpen.eof()) {
					Employee w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				int count = 0;
				string factoryName;
				cin.get();
				getline(cin, factoryName);
				for (auto it = forFile.begin(); it != forFile.end(); it++) {
					if (strstr(it->getFactoryName().c_str(), factoryName.c_str()) != NULL)
						cout << *it << endl;
					else count++;
				}
				if (count == forFile.size()) throw invalid_argument("������ �� �������");
				break;
			}
			case 2: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Employee w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				int count = 0;
				string surname;
				cin.get();
				getline(cin, surname);
				for (auto it = forFile.begin(); it != forFile.end(); it++) {
					if (strstr(it->getSurname().c_str(), surname.c_str()) != NULL)
						cout << *it << endl;
					else count++;
				}
				if (count == forFile.size()) throw invalid_argument("������ �� �������");
				break;
			}
			case 3: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Employee w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				int count = 0;
				string name;
				cin.get();
				getline(cin, name);
				for (auto it = forFile.begin(); it != forFile.end(); it++) {
					if (strstr(it->getName().c_str(), name.c_str()) != NULL)
						cout << *it << endl;
					else count++;
				}
				if (count == forFile.size()) throw invalid_argument("������ �� �������");
				break;
			}
			case 4: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Employee w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				int count = 0;
				string personPosition;
				cin.get();
				getline(cin, personPosition);
				for (auto it = forFile.begin(); it != forFile.end(); it++) {
					if (strstr(it->getPersonPosition().c_str(), personPosition.c_str()) != NULL)
						cout << *it << endl;
					else count++;
				}
				if (count == forFile.size()) throw invalid_argument("������ �� �������");
				break;
			}
			case 5: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Employee w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				int count = 0;
				string tr1;
				cin.get();
				getline(cin, tr1);
				for (auto it = forFile.begin(); it != forFile.end(); it++) {
					if (strstr(to_string(it->getTargetRaiting1()).c_str(), tr1.c_str()) != NULL)
						cout << *it << endl;
					else count++;
				}
				if (count == forFile.size()) throw invalid_argument("������ �� �������");
				break;
			}
			case 6: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Employee w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				int count = 0;
				string tr2;
				cin.get();
				getline(cin, tr2);
				for (auto it = forFile.begin(); it != forFile.end(); it++) {
					if (strstr(to_string(it->getTargetRaiting2()).c_str(), tr2.c_str()) != NULL)
						cout << *it << endl;
					else count++;
				}
				if (count == forFile.size()) throw invalid_argument("������ �� �������");
				break;
			}
			case 7: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Employee w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				int count = 0;
				string tr3;
				cin.get();
				getline(cin, tr3);
				for (auto it = forFile.begin(); it != forFile.end(); it++) {
					if (strstr(to_string(it->getTargetRaiting3()).c_str(), tr3.c_str()) != NULL)
						cout << *it << endl;
					else count++;
				}
				if (count == forFile.size()) throw invalid_argument("������ �� �������");
				break;
			}
			case 8: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Employee w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				int count = 0;
				string tr4;
				cin.get();
				getline(cin, tr4);
				for (auto it = forFile.begin(); it != forFile.end(); it++) {
					if (strstr(to_string(it->getTargetRaiting3()).c_str(), tr4.c_str()) != NULL)
						cout << *it << endl;
					else count++;
				}
				if (count == forFile.size()) throw invalid_argument("������ �� �������");
				break;
			}
			case 9: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Employee w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				int count = 0;
				string tr5;
				cin.get();
				getline(cin, tr5);
				for (auto it = forFile.begin(); it != forFile.end(); it++) {
					if (strstr(to_string(it->getTargetRaiting3()).c_str(), tr5.c_str()) != NULL)
						cout << *it << endl;
					else count++;
				}
				if (count == forFile.size()) throw invalid_argument("������ �� �������");
				break;
			}
			case 0: {
				break;
			}
			default: {
				red failure white;
				break;
			}
			}
		}
	}
	else {
		red cout << "����������� ������ � ��" << endl; white
	}
	dataBaseIsOpen.close();
}

void UserMenu::sort()
{
	dataBaseIsOpen.open(pathFileFactory);
	if (dataBaseIsOpen.is_open()) {
		int choice = 1;
		while (choice != 0) {
			cout << "���������� ��:" << endl;
			cout << "1.�������� ������ ����������" << endl;
			cout << "2.������� ����������" << endl;
			cout << "3.����� ����������" << endl;
			cout << "4.��������� ����������" << endl;
			cout << "5.���������� ������ ������ ����" << endl;
			cout << "6.���������� ������ ������ ����" << endl;
			cout << "7.���������� ������ ������� ����" << endl;
			cout << "8.���������� ������ �������� ����" << endl;
			cout << "9.���������� ������ ����� ����" << endl;
			cout << "10.���������� � ���� ��������������� ������" << endl;
			cout << "0.����� �� ������� ����" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Employee w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				for (auto it1 = forFile.begin(); it1 != forFile.end() - 1; it1++) {
					for (auto it2 = forFile.begin(); it2 != forFile.end() - 1; it2++) {
						if (strcmp(it1->getFactoryName().c_str(), it2->getFactoryName().c_str()) < 0) {
							Employee w = *it1;
							*it1 = *it2;
							*it2 = w;
						}
					}
				}
				break;
			}
			case 2: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Employee w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				for (auto it1 = forFile.begin(); it1 != forFile.end() - 1; it1++) {
					for (auto it2 = forFile.begin(); it2 != forFile.end() - 1; it2++) {
						if (strcmp(it1->getSurname().c_str(), it2->getSurname().c_str()) < 0) {
							Employee w = *it1;
							*it1 = *it2;
							*it2 = w;
						}
					}
				}
				break;
			}
			case 3: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Employee w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				for (auto it1 = forFile.begin(); it1 != forFile.end() - 1; it1++) {
					for (auto it2 = forFile.begin(); it2 != forFile.end() - 1; it2++) {
						if (strcmp(it1->getName().c_str(), it2->getName().c_str()) < 0) {
							Employee w = *it1;
							*it1 = *it2;
							*it2 = w;
						}
					}
				}
				break;
			}
			case 4: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Employee w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				for (auto it1 = forFile.begin(); it1 != forFile.end() - 1; it1++) {
					for (auto it2 = forFile.begin(); it2 != forFile.end() - 1; it2++) {
						if (strcmp(it1->getPersonPosition().c_str(), it2->getPersonPosition().c_str()) < 0) {
							Employee w = *it1;
							*it1 = *it2;
							*it2 = w;
						}
					}
				}
				break;
			}
			case 5: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Employee w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				for (auto it1 = forFile.begin(); it1 != forFile.end() - 1; it1++) {
					for (auto it2 = forFile.begin(); it2 != forFile.end() - 1; it2++) {
						if (it1->getTargetRaiting1() < it2->getTargetRaiting1()) {
							Employee w = *it1;
							*it1 = *it2;
							*it2 = w;
						}
					}
				}
				break;
			}
			case 6: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Employee w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				for (auto it1 = forFile.begin(); it1 != forFile.end() - 1; it1++) {
					for (auto it2 = forFile.begin(); it2 != forFile.end() - 1; it2++) {
						if (it1->getTargetRaiting2() < it2->getTargetRaiting2()) {
							Employee w = *it1;
							*it1 = *it2;
							*it2 = w;
						}
					}
				}
				break;
			}
			case 7: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Employee w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				for (auto it1 = forFile.begin(); it1 != forFile.end() - 1; it1++) {
					for (auto it2 = forFile.begin(); it2 != forFile.end() - 1; it2++) {
						if (it1->getTargetRaiting3() < it2->getTargetRaiting3()) {
							Employee w = *it1;
							*it1 = *it2;
							*it2 = w;
						}
					}
				}
				break;
			}
			case 8: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Employee w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				for (auto it1 = forFile.begin(); it1 != forFile.end() - 1; it1++) {
					for (auto it2 = forFile.begin(); it2 != forFile.end() - 1; it2++) {
						if (it1->getTargetRaiting4() < it2->getTargetRaiting4()) {
							Employee w = *it1;
							*it1 = *it2;
							*it2 = w;
						}
					}
				}
				break;
			}
			case 9: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Employee w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				for (auto it1 = forFile.begin(); it1 != forFile.end() - 1; it1++) {
					for (auto it2 = forFile.begin(); it2 != forFile.end() - 1; it2++) {
						if (it1->getTargetRaiting5() < it2->getTargetRaiting5()) {
							Employee w = *it1;
							*it1 = *it2;
							*it2 = w;
						}
					}
				}
				break;
			}
			case 10: {
				if (forFile.empty()) {
					red cout << "������ �� �������������" << endl; white
				}
				else {
					dataBaseIsEmpty.open(pathFileFactory);
					for (auto it = forFile.begin(); it != forFile.end(); it++) {
						dataBaseIsEmpty << *it << endl;
					}
					green cout << "��������������� ������ ������������ � ����" << endl; white
						dataBaseIsEmpty.close();
				}
				break;
			}
			case 0: {
				break;
			}
			default: {
				red failure white;
				break;
			}
			}
		}
	}
	else {
		red cout << "����������� ������ � ��" << endl; white
	}
	dataBaseIsOpen.close();
}

void UserMenu::Raiting()
{
	forFile.clear();
	dataBaseIsOpen.open(pathFileFactory);
	if (dataBaseIsOpen.is_open()) {
		int count = 0;
		while (!dataBaseIsOpen.eof()) {
			Employee w;
			dataBaseIsOpen >> w;
			forFile.push_back(w);
			count++;
		}
		double **matrix = new double*[count];
		for (int i = 0; i < count; i++) {
			matrix[i] = new double[100];
		}
		int summ = 0;
		double* weights = new double[count] , * summColumns = new double[count];

		for (int i = 0; i < count; i++) {
			weights[i] = 0;
			summColumns[i] = 0;
		}		

		int rows = 0, columns = 0;

		for (auto it = forFile.begin(); it != forFile.end(); it++) {
			matrix[columns][rows] = it->getTargetRaiting1();
			rows++;
		}

		columns++;
		rows = 0;

		for (auto it = forFile.begin(); it != forFile.end(); it++) {
			matrix[columns][rows] = it->getTargetRaiting2();
			rows++;
		}

		rows = 0;
		columns++;

		for (auto it = forFile.begin(); it != forFile.end(); it++) {
			matrix[columns][rows] = it->getTargetRaiting3();
			rows++;
		}

		rows = 0;
		columns++;

		for (auto it = forFile.begin(); it != forFile.end(); it++) {
			matrix[columns][rows] = it->getTargetRaiting4();
			rows++;
		}

		rows = 0;
		columns++;

		for (auto it = forFile.begin(); it != forFile.end(); it++) {
			matrix[columns][rows] = it->getTargetRaiting5();
			rows++;
	 	}

		columns++;
		
		cout << "�������� ������� ������������:" << endl;
		cout << "Z/E ";
		int point = 0;
		while (point != rows -1) {
			cout << "E" << point + 1<< " ";
			point++;
		}
		cout << endl;
		for (int i = 0; i < columns; i++) {
			cout << "Z" << i + 1 << "  ";
			for (int j = 0; j < rows -1 ; j++) {
				cout << matrix[i][j] << "  ";
			}
			cout << endl;
		}

		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < rows; j++) {
				matrix[i][j] = 5 - matrix[i][j];
				summ = matrix[i][j] + summ;				
			}
		}
		summ = summ - 25;

		for (int i = 0; i < rows ; i++) {
			for (int j = 0; j < columns +2; j++) {
				summColumns[i] = summColumns[i] + matrix[i][j];
			}
		}
	//	for (int i = 0; i < columns; i++) {
	//		cout << summColumns[i] << "  ";
	// 	}

		for (int i = 0; i < columns; i++) {
			weights[i] = (summColumns[i]/summ);
		}
		
		cout << "\n���������������� ������� ������������:" << endl;
		cout << "Z/E ";
		int point1 = 0;
		while (point1 != rows -1 ) {
			cout << "E" << point1 + 1 << " ";
			point1++;
		}
		cout << endl;
		for (int i = 0; i < columns; i++) {
			cout << "Z" << i + 1 << "  ";
			for (int j = 0; j < rows -1; j++) {
				cout << matrix[i][j] << "  ";
			}
			cout << endl;
		}
	//	cout << "����� = " << summ << endl;
		cout << "E - �������" << endl;
		cout << "Z - ����" << endl;		
	green	cout << "������� ���� �����: \n";
		for (int i = 0; i < columns; i++) {
		cout << i+1 << ") " << weights[i] << "  " <<"\n";
		} white
		cout << endl;
		delete[] matrix;
		delete weights;
	}
	else cout << "������ ��� �������� ��" << endl;
	dataBaseIsOpen.close();
}