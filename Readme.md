// this function realise :
// - delete the value (set the variable to 0)
// - free the memory
// - set the pointer to Null

Aims of the "MyLinkList" Library :
* build a library in standard C that is able to deal with any type
* apply the concepts seen in "Software Engineering" DSTI class, especially around pointers, arguments passed by value or by adress, shallow copy or deep copy.

The library "package" include three files :
* MyLinkLib.lib
* MyLinkList.h - the header file to be included

A very simple example of using the library is given :
* intfunction.h : declaration of the functions to use integers
* intfunction.c : definition of the functions to use integers
* main.c : main program to use the libray
Source files of the library are also provided :
* MyLinkList.cpp - the definition of the functions of the library
* internal.h : declaration of internal functions

Link List

The link list is a very simple one :
* a structure with the data to store and a link to the next structure in the list
* a header structure with a pointer to the first element of the list and a counter to know the number of element in the list
The choice is to insert new elements at the end of the list

Implementation
The choice is to store all the datas by "deep copy". That means that all the datas in the elements in the list are copy of the elements passed by the caller.
the idea is to dynamically allocate all the datas, store a generic pointer to the datas and free the memory at the end.
Since the library has no idea about the structure of the datas given by the caller, a structure is defined in the library to host "manipulation functions".
Those functions must be developped outside the library for each different type store in the library and passed to the library through the dedicated structure.
At that point, the library need 3 "manipulation function" to work :
* a function to initialise (allocate dynamic memory) and copy the data in that allocated memory
* a function to print the data
* a function to free the data (set the data to 0, free the memory, set the pointer to NULL)


