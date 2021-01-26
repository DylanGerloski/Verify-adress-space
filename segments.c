//Dylan Gerloski
//mini Project 3

#include "segments.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* txtFunc1();		//Txt segment, functions that return the text string to the text pointers
char* txtFunc2();

char *dataSegment1 = "data 1"; 	//dataSegment. data segment in initalized data.
char *dataSegment2 = "data 2";

char *bssSegment1;		//bss segment. data is uninitialiized
char *bssSegment2;

void stackInit1();		//stack functions to grow the stack
char* stackInit2();

void init_pointers()
{
	text_ptr_1 = txtFunc1;		//assigning text pointers to the text functions
	text_ptr_2 = txtFunc2;

	data_ptr_1 = malloc(sizeof(*dataSegment1));	//set size of each data pointer to size of text it will be holding
	*data_ptr_1 = *dataSegment1;			//in these cases, datasegment 1 and 2 will be holding the text data
	strcpy(data_ptr_1, dataSegment1);
	data_ptr_2 = malloc(sizeof(*dataSegment2));
	*data_ptr_2 = *dataSegment2;			//data ptr now contains adress that is contained in datasegment
	strcpy(data_ptr_2, dataSegment2);


	//this section of code assigns a value to the bss segments and then points the bss pointer to the segment

	bssSegment1 = malloc(sizeof("bss 1"));		
	strcpy(bssSegment1, "bss 1");
	bss_ptr_1 = malloc(sizeof(*bssSegment1));
	*bss_ptr_1 = *bssSegment1;
	strcpy(bss_ptr_1, bssSegment1);

	bssSegment2 = malloc(sizeof("bss 2"));
        strcpy(bssSegment2, "bss 2");
        bss_ptr_2 = malloc(sizeof(*bssSegment2));
        *bss_ptr_2 = *bssSegment2;
        strcpy(bss_ptr_2, bssSegment2);
	
	stackInit1(); //initalized heap, all initlilization done in functions


	//heap segment is simpily alocating space for heap pointers. The heap grows when new space is allocated.
	char* heapSegment1 = "heap 1";
	heap_ptr_1 = malloc(sizeof(*heapSegment1));
	*heap_ptr_1 = *heapSegment1;
	strcpy(heap_ptr_1, heapSegment1);
	
	char* heapSegment2 = "heap 2";
        heap_ptr_2 = malloc(sizeof(*heapSegment2));
        *heap_ptr_2 = *heapSegment2;
        strcpy(heap_ptr_2, heapSegment2);
         


}

void free_pointers()
{

	//frees all pointers that need to be freed
	free(data_ptr_1);
	free(data_ptr_2);
	free(bss_ptr_1);
	free(bss_ptr_2);
	free(heap_ptr_1);
	free(heap_ptr_2);
	free(stack_ptr_1);
	free(bssSegment1);
	free(bssSegment2);
}

char *txtFunc1(){
	return "text 1";
}

char *txtFunc2(){
	return "text 2";
}



//stack init1 initialized first stack pointer, and then sets the 2nd pointer to the 2ns function, which in turn grows the stack
//since a new function is being called.
void stackInit1(){
	char *stackSegment1 = "Stack 1";
	stack_ptr_1 = malloc(sizeof(*stackSegment1));
	*stack_ptr_1 = *stackSegment1;
	strcpy(stack_ptr_1, stackSegment1);
	stack_ptr_2 = stackInit2();
}

char* stackInit2(){
        char *stackSegment2 = "Stack 2";  
	stack_ptr_2 = malloc(sizeof(*stackSegment2));
        *stack_ptr_2 = *stackSegment2;
        strcpy(stack_ptr_2, stackSegment2);
	return stackSegment2;
}

