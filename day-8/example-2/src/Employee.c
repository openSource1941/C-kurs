/*
 * Employee.c
 *
 *  Created on: Feb 16, 2022
 *      Author: sgojkovic
 */

/*
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
}EmployeeList;*/

#include "Employee.h"

employee* EmployeeCreate(char* name , char* group_name,float experience)
{
	employee* new_emp = (employee*)malloc(sizeof(employee));
	strcpy(new_emp->name, name);
	strcpy(new_emp->group, group_name);
	new_emp->experience = experience;
	new_emp->next = NULL;
	new_emp->prev = NULL;
	return new_emp;
}

void EmployeeListCreate(EmployeeList* emp_list)
{
	emp_list->head = NULL;
	emp_list->tail = NULL;
	emp_list->size = 0;
}

void EmployeeListDestroy(EmployeeList* emp_list)
{
	employee* temp;
	temp = emp_list->head;
	while(temp!=NULL)
	{
		free(temp->prev);
		temp = temp->next;
	}
}

void EmployeeListInsert(EmployeeList* emp_list, employee* emp, int n)
{
	employee* temp = emp_list->head;
	if(emp_list->size == 0)
	{
		emp_list->head =emp;
		emp_list->tail = emp;
		emp_list->size++;
	}
	else if (emp_list->size+1 == n)
	{
		int i = 1;
		while(temp != NULL && i < n-1 )
		{
			temp = temp->next;
			i++;
		}
		temp->next = emp;
		emp->prev = temp;
		emp_list->size++;
	}
	else
	{
		int i = 1;
		while(temp != NULL && i < n )
		{
			temp = temp->next;
			i++;
		}

		emp->next = temp;
		emp->prev = temp->prev;
		temp->prev = emp;
		if(emp->prev != 0)
		{
			emp->prev->next = emp;
		}
		emp_list->size++;
	}


	if (n == 1)
	{
		emp_list->head = emp;
	}
	else if (n == emp_list->size)
	{
		emp_list->tail =emp;
	}

}

void EmployeeListDelete(EmployeeList* emp_list,  int n)
{
	employee* temp;

	if(n == 1)
	{
		temp = emp_list->head;
		temp->next->prev = NULL;
		emp_list->head = temp->next;
		free(temp);
	}
	else if (emp_list->size == n)
	{
		temp = emp_list->tail;
		temp->prev->next = NULL;
		emp_list->tail = temp->prev;
		free(temp);
	}
	else
	{
		temp = emp_list->head;
		int i = 1;
		while(temp != NULL && i < n )
		{
			temp = temp->next;
			i++;
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		free(temp);
	}
	emp_list->size--;
}

employee* EmployeeListGetElement(EmployeeList* emp_list, int n)
{
	employee* temp;
	temp =emp_list->head;
	int i = 1;
	while(temp != NULL && i < n )
	{
		temp = temp->next;
		i++;
	}
	return temp;
}

int EmployeeListSize(EmployeeList* emp_list)
{
	return emp_list->size;
}

void EmployeeListDump(EmployeeList* emp_list)
{
	employee* temp;
	temp = emp_list->head;
	printf("Elementi liste:\n");
	for(int i = 0; i<emp_list->size; i++)
	{
		printf("%d. element je: %s, %s, %.2f\n",i+1 , temp->name, temp->group,temp->experience);
		temp = temp->next;
	}
}
