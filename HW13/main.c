/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw13.h"
/****************** DO NOT Modify this file above this line *************************/

// Modify the following function
//#ifdef TEST_MAIN

int main(int argc, char **argv)
{
	// if argc is less than 2 then, return EXIT_FAILURE
	if(argc < 2)
		return EXIT_FAILURE;
	FILE * file = fopen(argv[1], "r");
	if(file == NULL)
		return EXIT_FAILURE;

	// input file is specified through the Makefile.

	// open file to read

	// check for fopen fail. If so, return EXIT_FAILURE
	int count = 0;
	int hold;
	while(fscanf(file, "%d", &hold) == 1)
		count++;
	// count the number of integers in the file.
	int * array = (int *)malloc(count *sizeof(int));
	if(array == NULL)
		return EXIT_FAILURE;
	// allocate memory to store the numbers
	count = 0;
	// check for malloc fail, if so, return EXIT_FAILURE
	fseek(file, 0, SEEK_SET);
	while(fscanf(file, "%d", &array[count]) == 1)
		count++;
	// use fscanf to read the file, and store its contents into an array.
	Node * head = (Node *)malloc(sizeof(Node));
	LinkedListCreate(&head , count, array);
	
	// create head node to store the head of the linked list.
	// call the appropriate function to create the rest of the linked list, with the values of the array.
	Divide(&head);
	// Divide is a function to break the lists into smaller sublists.
	// You are supposed to find the mid-point of the list, and then break the list into two lists.
		// Then the sub-lists are broken down further into smaller sub-lists.
		// Refer to the example in the README
	 // Tip: check for memory errors.
	fclose(file);
	free(array);
	return EXIT_SUCCESS;
}

//#endif
