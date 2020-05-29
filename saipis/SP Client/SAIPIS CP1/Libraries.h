#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <vector>
#include <exception>
#include <map>

using namespace std;

#define failure cout << "Данная функция отсутствует" << endl;
#define green SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
#define red SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
#define white SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
