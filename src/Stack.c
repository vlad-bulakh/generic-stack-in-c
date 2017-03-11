

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h> /* memcpy, memset */

#include "Stack.h"

size_t INITIAL_SIZE = 0;
int SMALL_DELIMETER_LENGTH = 35;
int MEDIUM_DELIMETER_LENGTH = 55;
char NUL_TERMINATING_CHARACTER = '\0';

/*-----------------------------------------------------*/
Stack * stackInitialize()
{
	Stack * stackPointer = NULL;
	stackPointer = mallocAndBzero(sizeof(Stack));
	stackPointer->topNode = NULL;
	stackPointer->size = INITIAL_SIZE;
	return stackPointer;
}

void stackDestroy(Stack ** stackPointerToPointer)
{
	Stack * stackPointer = (*stackPointerToPointer);
	assert(stackPointer != NULL);
	freeAndNull(*stackPointerToPointer);
}
/*-----------------------------------------------------*/


/*-----------------------------------------------------*/
size_t stackSize(Stack ** stackPointerToPointer)
{
	Stack * stackPointer = (*stackPointerToPointer);
	assert(stackPointer != NULL);
	return (stackPointer->size);
}

void stackPushFront(Stack ** stackPointerToPointer, void * dataPointer)
{
	Stack * stackPointer = (*stackPointerToPointer);
	node * nodePointer =  NULL;

	assert(stackPointer != NULL);
	assert(dataPointer != NULL);
	
	nodePointer = mallocAndBzero(sizeof(node));
	nodePointer->data = dataPointer;

	nodePointer->next = stackPointer->topNode;
	stackPointer->topNode = nodePointer;

	stackPointer->size += 1;
}

void * stackPopFront(Stack ** stackPointerToPointer)
{
	Stack * stackPointer = (*stackPointerToPointer);
	void * dataPointer = NULL;
	node ** currentNode = &(stackPointer->topNode);
	node * previousNode = NULL;

	assert(stackPointer != NULL);
	assert(stackPointer->topNode != NULL);
	assert(stackPointer->size > 0);

	dataPointer = stackPointer->topNode->data;
	previousNode = (*currentNode)->next;
	freeAndNull(*currentNode);
	stackPointer->topNode = previousNode;

	stackPointer->size -= 1;
	return dataPointer;
}

void stackEraseAllElements(Stack ** stackPointerToPointer, int freeData)
{
	Stack * stackPointer = (*stackPointerToPointer);
	node * tempNode = NULL;
	node ** currentNode = NULL;

	assert(stackPointer != NULL);

	/* Iterate until the end of the stack. */
	currentNode = &(stackPointer->topNode);
	while((*currentNode) != NULL)
	{	
		tempNode = ((*currentNode)->next);
		if (freeData){freeAndNull((*currentNode)->data);}		
		freeAndNull(*currentNode);
		*currentNode = tempNode;		
	}
	stackPointer->size = 0;
}
/*-----------------------------------------------------*/





/*-----------------------------------------------------*/
void * mallocAndBzero(size_t size)
{
	void * returnPointer = malloc(size);
	if(returnPointer == NULL)
	{
		fprintf(stderr, "\n\n Error. Malloc() call failed - out of memory! \n\n");
		exit(EXIT_FAILURE);
	}
	memset (returnPointer, 0, size);
	return returnPointer;
}

void freeAndNullMemory(void ** memory)
{
	if (memory != NULL && (*memory) != NULL)
	{
		free(*memory);
		*memory = NULL;
	}
	else
	{
		fprintf(stderr, "\n\nError. Memory already free! \n\n");
	}
}
/*-----------------------------------------------------*/



/*-----------------------------------------------------*/
char * repeatCharacter(char characterToPrint, size_t numberOfRepetitions)
{
	char * characterString = NULL;
	char * tempCharacterString = NULL;
	size_t characterStringSize = 0;

	while (characterStringSize < numberOfRepetitions)
	{
		tempCharacterString = mallocAndBzero((characterStringSize+2) * (sizeof(char)));
		memcpy(tempCharacterString, characterString, characterStringSize);
		if(characterString!=NULL)
		{
			freeAndNull(characterString);
		}
		characterString = tempCharacterString;
		characterString[characterStringSize] = characterToPrint;
		characterStringSize++;
	}
	if (characterString!=NULL)
	{
		characterString[characterStringSize] = NUL_TERMINATING_CHARACTER;
	}

	return characterString;
}
/*-----------------------------------------------------*/




/*PRINT FUNCTIONS*/
/*-----------------------------------------------------*/
void stackPrint(Stack ** stackPointerToPointer, void (*printFunction)(void *))
{
	Stack * stackPointer = (*stackPointerToPointer);
	node ** current_node = NULL;
	void * data = NULL;
	int itemPosition = 0;
	char * smallDelimeter = repeatCharacter('-', SMALL_DELIMETER_LENGTH);
	char * mediumDelimeter = repeatCharacter('~', MEDIUM_DELIMETER_LENGTH);

	fprintf(stdout, "\n\n\n%s", mediumDelimeter);
	fprintf(stdout, "\nBEGIN PRINTING STACK INFORMATION");
	fprintf(stdout, "\n\n%s %lu", "Number of items in stack:", (unsigned long)stackSize(stackPointerToPointer));
	fprintf(stdout, "\n\nItem position:\t\tItem value:");
	fprintf(stdout, "\n%s", smallDelimeter);

	current_node = &(stackPointer->topNode);
	while((*current_node) != NULL)
	{
		fprintf(stdout, "\n %d\t\t\t", itemPosition);
		data = (*current_node)->data;
		(*printFunction)(data);
		current_node = &(*current_node)->next;
		itemPosition++;
	}

	fprintf(stdout, "\n\nEND PRINTING STACK INFORMATION");
	fprintf(stdout, "\n%s\n\n\n", mediumDelimeter);

	freeAndNull(smallDelimeter);
	freeAndNull(mediumDelimeter);
}

void printInteger(void * valueToPrint)
{
	fprintf(stdout, "%d", *(int *)valueToPrint);
}
void printUnsignedInteger(void * valueToPrint)
{
	fprintf(stdout, "%u", *(unsigned int *)valueToPrint);
}
void printShort(void * valueToPrint)
{
	fprintf(stdout, "%hi", *(short *)valueToPrint);
}
void printUnsignedShort(void * valueToPrint)
{
	fprintf(stdout, "%hu", *(unsigned short *)valueToPrint);
}
void printLong(void * valueToPrint)
{
	fprintf(stdout, "%li", *(long *)valueToPrint);
}
void printUnsignedLong(void * valueToPrint)
{
	fprintf(stdout, "%lu", *(unsigned long *)valueToPrint);
}
void printFloat(void * valueToPrint)
{
	fprintf(stdout, "%f", *(float *)valueToPrint);
}
void printDouble(void * valueToPrint)
{
	fprintf(stdout, "%f", *(double *)valueToPrint);
}
void printCharacter(void * valueToPrint)
{
	fprintf(stdout, "%c", *(char *)valueToPrint);
}
void printCharacterString(void * valueToPrint)
{
	fprintf(stdout, "%s", (char *)valueToPrint);
}


void stackPrintStackInformationIntegers(Stack ** stackPointerToPointer)
{
	stackPrint(stackPointerToPointer, printInteger);
}
void stackPrintStackInformationUnsignedIntegers(Stack ** stackPointerToPointer)
{
	stackPrint(stackPointerToPointer, printUnsignedInteger);
}
void stackPrintStackInformationShort(Stack ** stackPointerToPointer)
{
	stackPrint(stackPointerToPointer, printShort);
}
void stackPrintStackInformationUnsignedShort(Stack ** stackPointerToPointer)
{
	stackPrint(stackPointerToPointer, printUnsignedShort);
}
void stackPrintStackInformationLong(Stack ** stackPointerToPointer)
{
	stackPrint(stackPointerToPointer, printLong);
}
void stackPrintStackInformationUnsignedLong(Stack ** stackPointerToPointer)
{
	stackPrint(stackPointerToPointer, printUnsignedLong);
}
void stackPrintStackInformationFloats(Stack ** stackPointerToPointer)
{
	stackPrint(stackPointerToPointer, printFloat);
}
void stackPrintStackInformationDoubles(Stack ** stackPointerToPointer)
{
	stackPrint(stackPointerToPointer, printDouble);
}
void stackPrintStackInformationCharacters(Stack ** stackPointerToPointer)
{
	stackPrint(stackPointerToPointer, printCharacter);
}
void stackPrintStackInformationCharacterStrings(Stack ** stackPointerToPointer)
{
	stackPrint(stackPointerToPointer, printCharacterString);
}
/*-----------------------------------------------------*/
