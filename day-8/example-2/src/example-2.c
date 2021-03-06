/*
 ============================================================================
 Name        : example-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"

int main() {
	EmployeeList emp_list;
	EmployeeListCreate(&emp_list);
	employee* emp;
	emp = EmployeeCreate("Stefan", "Syrmia", 1.5);
	EmployeeListInsert(&emp_list, emp, 1);
	employee* emp1;
	emp1 = EmployeeCreate("Nikola", "Syrmia", 8.5);
	EmployeeListInsert(&emp_list, emp1, 2);
	employee* emp2;
	emp2 = EmployeeCreate("Bojan", "Syrmia", 5);
	EmployeeListInsert(&emp_list, emp2, 1);
	employee* emp3;
	emp3 = EmployeeCreate("Luka", "Syrmia", 2);
	EmployeeListInsert(&emp_list, emp3, 3);
	EmployeeListDump(&emp_list);
	EmployeeListDelete(&emp_list, 1);
	EmployeeListDump(&emp_list);

	return 0;
}
