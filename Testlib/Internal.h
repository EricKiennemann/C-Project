#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "MyLinkList.h"

/* internal.h  group functions from the library that are not public */

BOOL allocateGenericElement( genericElement* pElement, const void* pdata, const genericFunc* pGenFunction);

BOOL deallocateGenericElement(const genericElement* pElement);



