#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

/*#include <vld.h> visual studio memory leak detection*/

#include "Stack.h"

void testIntegers(Stack ** stack)
{
	int * removedItem = NULL;
	int * item1= mallocAndBzero(sizeof(int));
	int * item2= mallocAndBzero(sizeof(int));
	int * item3= mallocAndBzero(sizeof(int));

	*item1 = 11;
	*item2 = 22;
	*item3 = 33;	
		
	printf("Stack size: %lu \n", (unsigned long)stackSize(stack));

	stackPushFront(stack, item1);
	printf("Item pushed onto stack: %d \n", *item1);

	stackPushFront(stack, item2);
	printf("Item pushed onto stack: %d \n", *item2);

	printf("Stack size: %lu \n", (unsigned long)stackSize(stack));

	removedItem = (int*)(stackPopFront(stack));
	printf("Removed item from stack: %d \n", *removedItem);
	freeAndNull(removedItem);

	printf("Stack size: %lu \n", (unsigned long)stackSize(stack));

	stackPushFront(stack, item3);
	printf("Item pushed onto stack: %d \n", *item3);

	printf("Stack size: %lu \n", (unsigned long)stackSize(stack));

	stackPrintStackInformationIntegers(stack);
}

void testFloats(Stack ** stack)
{
	float * removedItem = NULL;	
	float * item1= mallocAndBzero(sizeof(float));
	float * item2= mallocAndBzero(sizeof(float));
	float * item3= mallocAndBzero(sizeof(float));

	*item1 = 11.1F;
	*item2 = 22.2F;
	*item3 = 33.3F;

	printf("Stack size: %lu \n", (unsigned long)stackSize(stack));

	stackPushFront(stack, item1);
	printf("Item pushed onto stack: %f \n", *item1);

	stackPushFront(stack, item2);
	printf("Item pushed onto stack: %f \n", *item2);

	stackPrintStackInformationFloats(stack);

	removedItem = (float*)(stackPopFront(stack));
	printf("Removed item from stack: %f \n", *removedItem);
	freeAndNull(removedItem);

	removedItem = (float*)(stackPopFront(stack));
	printf("Removed item from stack: %f \n", *removedItem);
	freeAndNull(removedItem);

	printf("Stack size: %lu \n", (unsigned long)stackSize(stack));

	stackPushFront(stack, item3);
	printf("Item pushed onto stack: %f \n", *item3);

	printf("Stack size: %lu \n", (unsigned long)stackSize(stack));

	stackPrintStackInformationFloats(stack);
}


void testDoubles(Stack ** stack)
{
	double * removedItem = NULL;	
	double * item1= mallocAndBzero(sizeof(double));
	double * item2= mallocAndBzero(sizeof(double));
	double * item3= mallocAndBzero(sizeof(double));

	*item1 = 11.1;
	*item2 = 22.2;
	*item3 = 33.3;

	printf("Stack size: %lu \n", (unsigned long)stackSize(stack));

	stackPushFront(stack, item1);
	printf("Item pushed onto stack: %f \n", *item1);

	stackPushFront(stack, item2);
	printf("Item pushed onto stack: %f \n", *item2);

	stackPrintStackInformationDoubles(stack);

	removedItem = (double*)(stackPopFront(stack));
	printf("Removed item from stack: %f \n", *removedItem);
	freeAndNull(removedItem);

	removedItem = (double*)(stackPopFront(stack));
	printf("Removed item from stack: %f \n", *removedItem);
	freeAndNull(removedItem);

	printf("Stack size: %lu \n", (unsigned long)stackSize(stack));

	stackPushFront(stack, item3);
	printf("Item pushed onto stack: %f \n", *item3);

	printf("Stack size: %lu \n", (unsigned long)stackSize(stack));

	stackPrintStackInformationDoubles(stack);
}


void testCharacters(Stack ** stack)
{
	char * removedItem = NULL;
	char * item1= mallocAndBzero(sizeof(char));
	char * item2= mallocAndBzero(sizeof(char));
	char * item3= mallocAndBzero(sizeof(char));

	*item1 = 'a';
	*item2 = 'b';
	*item3 = 'c';
	

	printf("Stack size: %lu \n", (unsigned long)stackSize(stack));

	stackPushFront(stack, item1);
	printf("Item pushed onto stack: %c \n", *item1);

	removedItem = (char*)(stackPopFront(stack));
	printf("Removed item from stack: %c \n", *removedItem);
	freeAndNull(removedItem);

	stackPushFront(stack, item3);
	printf("Item pushed onto stack: %c \n", *item3);

	stackPushFront(stack, item2);
	printf("Item pushed onto stack: %c \n", *item2);
	
	stackPrintStackInformationCharacters(stack);
	
	removedItem = (char*)(stackPopFront(stack));
	printf("Removed item from stack: %c \n", *removedItem);
	freeAndNull(removedItem);

	printf("Stack size: %lu \n", (unsigned long)stackSize(stack));

	stackPrintStackInformationCharacters(stack);
}

void testCharacterStrings(Stack ** stack)
{
	char *item1 = "first";
	char *item2 = "second";
	char *item3 = "third";
	char * removedItem = NULL;

	printf("Stack size: %lu \n", (unsigned long)stackSize(stack));

	stackPushFront(stack, item1);
	printf("Item pushed onto stack: %s \n", item1);

	stackPushFront(stack, item3);
	printf("Item pushed onto stack: %s \n", item3);	

	stackPushFront(stack, item2);
	printf("Item pushed onto stack: %s \n", item2);

	printf("Stack size: %lu \n", (unsigned long)stackSize(stack));

	stackPrintStackInformationCharacterStrings(stack);

	removedItem = (char*)(stackPopFront(stack));
	printf("Removed item from stack: %s \n", removedItem);
	/*printf("length: %d \n", strlen(removedItem));*/

	removedItem = (char*)(stackPopFront(stack));
	printf("Removed item from stack: %s \n", removedItem);

	removedItem = (char*)(stackPopFront(stack));
	printf("Removed item from stack: %s \n", removedItem);
	
	printf("Stack size: %lu \n", (unsigned long)stackSize(stack));
}


int main()
{    
	Stack * stack = stackInitialize();
	printf("\n\nStack initialized.\n\n");
	
	/* Choose a test */
	/*testIntegers(&stack);*/
	/*testFloats(&stack);*/
	/*testDoubles(&stack);*/
	/*testCharacters(&stack);*/
	testCharacterStrings(&stack);

	stackEraseAllElements(&stack, 1);
	stackDestroy(&stack);	
	printf("\nStack destroyed.\n\n");

	/*system("pause");*/
	return EXIT_SUCCESS;
}
