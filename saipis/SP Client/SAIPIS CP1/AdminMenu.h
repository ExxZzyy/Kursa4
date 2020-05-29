#pragma once
#include "UserMenu.h"
#include "Employee.h"
class AdminMenu : public UserMenu, public Employee {
public:
	void adminMenu();
	void insert();
	void redact();
	void del();
	void fileCreating();
	void fileInsert();
};