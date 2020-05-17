#include "MyLinkList.h"
#include "Internal.h"

/* 
This function build an element of the list with the datas and functions given by the caller
	* the memory allocation for the element structure itself is done before the call of the function
*/
BOOL allocateGenericElement(genericElement* pElement, const void* pdata, const genericFunc* pGenFunction)
{
	BOOL success = TRUE;
	if ((pElement != NULL) && (pdata != NULL) && (pGenFunction != NULL))
	{
		// the initialisation of the pointer to the next element is done in the "add element" function
		pElement->pNext = NULL;
		
		/* memory allocation for the structure that store the functions used for the element */
		pElement->pGenFunction = (genericFunc*)malloc(sizeof(genericFunc));
		if (pElement->pGenFunction != NULL)
		{
			/* the structure of functions given by the caller is copied into the allocated memory and stored with the element */
			*(pElement->pGenFunction) = *pGenFunction;
			// the function -initCopy- given by the caller is used. this function must :
			//	- allocated memory for the element 
			//  - copy datas in this allocated memory
			//  - update the element pointer to this allocated memory
			(*((pElement->pGenFunction)->initCopy))(pdata, &pElement->pGenericValue);
		}
		else
			success = FALSE;
	}
	else
		success = FALSE;
	return success;
}

/*
This function deallocate the data structure stored in the element using the function provided by the caller
*/
BOOL deallocateGenericElement(const genericElement* pElement)
{
	BOOL success = TRUE;
	if (pElement != NULL)
	{
		if (pElement->pGenericValue != NULL)
		{
			// the function -deallocate- given by the caller is used. this function must :
			//	- free memory for the element data
			(*(pElement->pGenFunction->deallocate))(&pElement->pGenericValue);
			if (pElement->pGenericValue != NULL)
			{
				success = FALSE;
			}
		}
		else
			success = FALSE;
	}
	else
		success = FALSE;
	return success;
}

/*
This function :
	- allocate memory for an element
	- create the element using internal function
	- insert the element in the list
	- update the list counter
*/
BOOL addElementToGenericList( genericList* pList, const void* pdata, const genericFunc* pGenFunction)
{
	BOOL success = TRUE;
	genericElement* pElement;

	if ((pList !=  NULL) && (pdata != NULL) && (pGenFunction != NULL))
	{

		// allocate memory for the element that is going to be sore in the list
		pElement = (genericElement*)malloc(sizeof(genericElement));
		if (pElement != NULL)
		{
			// call the internal function to allocate the dats and initialise the element
			allocateGenericElement(pElement, pdata, pGenFunction);

			// if it's the first element of the list just add it to the list - no inseertion
			if (pList->nbElement == 0)
			{
				pList->nbElement = 1;
				pList->pListHead = pElement;
			}
			else
			{
				genericElement* pElementCourant = pList->pListHead;
				// reach the end of the list ...
				while (pElementCourant->pNext != NULL)
				{
					pElementCourant = pElementCourant->pNext;
				}
				// and insert the element at the end
				pElementCourant->pNext = pElement;
				pList->nbElement++;
			}
		}
		else
			success = FALSE;
	}
	else
		success = FALSE;
	return success;
}

/*
This function :
	- initialise the list
The list structure itself is created by the caller and the pointer to this list is passed as a pararemeter to this function
*/
BOOL initialiseList( genericList* pList)
{
	BOOL success = TRUE;
	if (pList != NULL)
	{
		pList->pListHead = NULL;
		pList->nbElement = 0;
	}
	else
		success = FALSE;
	return success;
}

/*
This function :
	- print all the element of the list
	- it uses the function given by the caller to print each element
*/
BOOL printElementList(const genericList* pList)
{
	BOOL success = TRUE;
	if (pList != NULL)
	{
		if (pList->nbElement != 0)
		{
			genericElement* pCourant = pList->pListHead;
			for (int i = 0; i < pList->nbElement; i++)
			{
				printf("Element %d of the list : \n",i);
				// call the function given by the caller
				(*(pCourant->pGenFunction->print))(pCourant->pGenericValue);
				pCourant = pCourant->pNext;
			}
		}
		else
			printf(" Liste vide \n");
	}
	else
		success = FALSE;
	return success;
}

/*
This function frees :
	- all the datas of the elements of the list (using the function given by the caller
	- the structure genericFunc that stores the functions given by the caller
	- the structure of the element GenericElement
*/
BOOL deallocateList(const genericList* pList)
{

	BOOL success = TRUE;
	if (pList != NULL)
	{
		if (pList->nbElement != 0)
		{
			genericElement* pOld;
			genericElement* pCourant = pList->pListHead;
			for (int i = 0; i < pList->nbElement; i++)
			{
				// call of the internal function to free the data stored in the genericElement
				deallocateGenericElement(pCourant);

				// free the structure used to store the functions
				memset(pCourant->pGenFunction, 0, sizeof(genericFunc));
				free(pCourant->pGenFunction);
				pCourant->pGenFunction = NULL;

				// free the structure genericElement it self
				pOld = pCourant;
				pCourant = pCourant->pNext;
				memset(pOld, 0, sizeof(genericElement));
				free(pOld);
				pOld = NULL;
			}
		}
		else
			success = FALSE;
	}
	else
		success = FALSE;
	return success;
}





