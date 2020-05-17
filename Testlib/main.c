
#include "MyLinkList.h"
#include "intFunction.h"

main()
{
	// declaration of the 2 variables that will bu put in the list
	int a = 5;
	int b = 6;

	// declaration of the variable that is used to store the functions created to manipulate the types put in the list
	// type defined in MyLinkList.h
	genericFunc IntFunction;
	// initialisation of this structure with the functions created in intFunction.c and intFunction.h
	IntFunction.deallocate = (int (*)(void*))(deallocateInt);
	IntFunction.initCopy = (int (*)(void*, void*))(initCopyInt);
	IntFunction.print = (int (*)(void*))(printInt);

	// declaration of the variable, header of the list
	// type defined in MyLinkList.h
	genericList List;
	// call of the function of the libray to initialise the list - mandatory 
	initialiseList(&List);

	// call of the function of the library to add an element to the list
	//	- the data must be passed by reference,
	//	- the structure with the functions also by reference
	addElementToGenericList(&List, &a , &IntFunction);
	addElementToGenericList(&List, &b, &IntFunction);

	// call of the function of the library print the whole list
	printElementList(&List);

	// To use elements of the lists do as follow :
	// print the first element of the list
	printf(" first element %d \n", *(int*)((List.pListHead)->pGenericValue));
	// Go to Next element
	genericElement* pCourant = (List.pListHead)->pNext;
	// Print the second element of the list
	printf(" second element %d \n", *(int*)(pCourant->pGenericValue));

	// free the list when no more use
	deallocateList(&List);
}