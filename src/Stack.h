

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

void * mallocAndBzero(size_t);
void freeAndNullMemory(void **);
#define freeAndNull(memory) freeAndNullMemory((void **) &(memory))

#endif


#ifndef Stack_
#define Stack_

typedef struct node
{
	void * data;
	struct node * next;
} node;

typedef struct Stack
{
	struct node * topNode;
	size_t size;
} Stack;

Stack * stackInitialize();
void stackDestroy(Stack **);
void stackEraseAllElements(Stack **, int);
size_t stackSize(Stack **);
void stackPushFront(Stack **, void *);
void * stackPopFront(Stack **);

void stackPrintStackInformationIntegers(Stack **);
void stackPrintStackInformationUnsignedIntegers(Stack **);
void stackPrintStackInformationShort(Stack **);
void stackPrintStackInformationUnsignedShort(Stack **);
void stackPrintStackInformationLong(Stack **);
void stackPrintStackInformationUnsignedLong(Stack **);
void stackPrintStackInformationFloats(Stack **);
void stackPrintStackInformationDoubles(Stack **);
void stackPrintStackInformationCharacters(Stack **);
void stackPrintStackInformationCharacterStrings(Stack **);


/*private*/
void stackPrint(Stack **, void (*)(void *));

#endif


