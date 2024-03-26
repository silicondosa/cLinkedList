// CLinkedList_example.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <cLinkedList.h>

void displayList(cLinkedList* myList)
{
	cListElem *myElem;
	int i = 0;
	for (myElem = cListFirstElem(myList), i = 0; myElem != NULL; myElem = cListNextElem(myList, myElem), i+=1) {
		printf("\tElement [%d]: %0.4f\n", i, *((double*)(myElem->obj)));
	}
}

void main()
{
	printf("This is an example for using the cLinkedList library.\n");

	printf("Create a linked list object and initialized it.\n");
	cLinkedList	linkedList;
	cLinkedList *myList = &linkedList;
	cListInit(myList);
	printf("\tCreated a linked list: it has %d elements in it.\n", cListLength(myList));

	printf("Check if it really is empty (YES=1/NO=0): %d\n", cListEmpty(myList));

	printf("Append a three floating-point elements to it.");
	double a = 0.0;
	double b = 1.0, c = 2.0;
	cListAppend(myList, (void*)&a);
	cListAppend(myList, (void*)&b);
	cListAppend(myList, (void*)&c);

	printf("Display the contents of the linked list...\n");
	displayList(myList);

	printf("Find 1.0, insert 1.5 after it\n");
	cListElem* anElem = cListFindElem(myList, (void*)&b);
	double d = 1.5;
	cListInsertAfter(myList, (void*)&d, anElem);
	displayList(myList);

	printf("Now, find the element for and unlink 0.0 using the list element\n");
	cListUnlinkElem(myList, cListFindElem(myList, (void*)&a));
	//cListUnlinkData(myList, (void*)&a);
	displayList(myList);

	printf("Directly unlink 2.0 without first finding the linked list element.\n");
	cListUnlinkData(myList, (void*)&c);
	displayList(myList);
	
	printf("The linked list is built in dynamic memory. So, always unlink all elements before you quit.\n");
	cListUnlinkAll(myList);
	printf("Check if it really is empty (YES=1/NO=0): %d\n", cListEmpty(myList));
	
	printf("Okay, bye!\n");

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
