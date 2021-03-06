/*
 * Employee.h
 *
 *  Created on: Feb 16, 2022
 *      Author: sgojkovic
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NAME_SIZE 30
#define GROUP_NAME_SIZE 30



typedef struct employee{
	char name[NAME_SIZE];
	char group[GROUP_NAME_SIZE];
	float experience;
	struct employee* prev;
	struct employee* next;

}employee;

typedef struct EmployeeList{

	employee* head;
	employee* tail;
	int size;
}EmployeeList;

employee* EmployeeCreate(char* , char* ,float);
void EmployeeListCreate(EmployeeList*);
void EmployeeListDestroy(EmployeeList*);
void EmployeeListInsert(EmployeeList*, employee*, int);
void EmployeeListDelete(EmployeeList*, int);
employee* EmployeeListGetElement(EmployeeList*, int);
int EmployeeListSize(EmployeeList*);
void EmployeeListDump(EmployeeList*);








#endif /* EMPLOYEE_H_ */
