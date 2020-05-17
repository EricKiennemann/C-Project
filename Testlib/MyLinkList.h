#pragma once
#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef int BOOL;
#define TRUE 1
#define FALSE 0


typedef struct GElement genericElement;

/* structure to store functions dedicated to the treatment of the element put in the list */
typedef struct
{
	int (*print)(const void*);
	int (*initCopy)(const void*, void*);
	int (*deallocate)(void*);
}genericFunc;

/* 
structure to store the element on the list. For each element is stored : 
	- a pointer to the element itself : pGenericValue
	- a pointer to the next element on the list : pNext
	- a pointer to the structure to store the functions available to deal with this element
*/
typedef struct GElement
{
	void* pGenericValue;
	genericElement* pNext;
	genericFunc* pGenFunction;
}genericElement;

/*
structure to store the header of the list.
*/
typedef struct
{
	unsigned int nbElement;
	genericElement* pListHead;
}genericList;


/* only the public functions of the library are put in this MylinkList.h file */

BOOL initialiseList(genericList* pList);

BOOL addElementToGenericList( genericList* pList, const void* pdata, const genericFunc*);

BOOL printElementList(const genericList* pList);

BOOL deallocateList(const genericList* pList);

