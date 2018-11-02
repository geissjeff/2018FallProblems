/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include "hw13.h"

//#ifdef LINKEDLIST
// Do not modify this function, we are using this within ifdef block for
// ease of grading.
void LinkedListPrint(Node * * source)
{

	Node *temp = * source;

	while(temp!=NULL)
	{
		if(temp->next!=NULL)
		{
			printf("%d,",temp->value);
		}
		else
		{
			printf("%d",temp->value);
		}
		temp=temp->next;
	}
	printf("\n");
}
//#endif


/********** Do Not modify the file above this line, you can modify below ***********/
//#ifdef TEST_CREATENODE

Node * CreateNode(int val)
//val: value of the element of the node to be created
{
	// Define a new variable of type Node
	// Initialize "next", and "value" appropriately

	//return the newNode
   Node * newNode = (Node *)malloc(sizeof(Node));
   newNode->value = val;
   newNode->next = NULL;
   return newNode;
}
//#endif

//#ifdef TEST_LINKEDLISTCREATE
//head: the head of the singly linkedlist.
//len: the length of the array.
//arr: the array with the contents of the input file.

//This function will create and initialize the singly linkedlist with length=len,

void LinkedListCreate(Node * * source, int len, int* arr)
{
	// This function is similar to the one in HW12.
	Node * this;
	Node * prev;
	prev = *source;
	prev->value = arr[0];
	for(int i = 1; i < len; i++){
		this = CreateNode(arr[i]);
                prev->next = this;
                prev = this;
        }
	// Tip: use CreateNode(arr[index])
}
//#endif


//#ifdef TEST_SPLIT
// source is the Node corresponding to the head of the list
// head1 is the list corresponding upper half of the list. (After Partition)
// head2 is the list corresponding lower half of the list. (After Partition)
void SplitList(Node* source, Node** head1, Node** head2) 
{ 
	// Find  the mid point of the list.
	int count = 1;
	Node * n  = source;
	while(n->next != NULL){
		count++;
		n = n->next;
	}
	int midpoint = count / 2;
	int displace = count - midpoint;	
		//in case of an even number of nodes, mid point will be floor(<num_elements>/2)
			//Example: 1,2,3,4
				// The list should split into 1,2 and 3,4

		//in case of an odd number of nodes, mid point will be <num_elements>/2
			//Example: 1,2,3,4,5
				// The list should split into 1,2,3 and 4,5				
	count = 1;
	n = source;
	while(count < displace){
		n = n->next;
		count++;
	}
	*head1 = source;
	Node * hold = n->next;
	*head2 = hold;
	n->next = NULL;
    	// Tip: head1 will point to the source node.
	// Tip: head2 will point to the mid-point of the list.
	// Tip: Ensure you break the link between the sub-lists.
} 
//#endif


//#ifdef TEST_DIV
void Divide(Node** source)
{
	// Declare a node, to hold the current head of source list.
	// Declare nodes, to hold the two the heads of the two sub-lists.
  	Node * head1;
	Node * head2;
	if(*source == NULL || (*source)->next == NULL){
		free(*source);
		return;
	}
	// Check for the base case -- length 0 or 1
		// if so, return;
 	SplitList(*source,&head1,&head2);
 	// Use SpiltList(...) to partition the list into sub lists.
	LinkedListPrint(&head1);
	LinkedListPrint(&head2);
	// Use LinkedListPrint(...); to print the upper sub-list.
	// Use LinkedListPrint(...); to print the lower sub-list
		// DO NOT USE YOUR OWN PRINT FUNCTION.
	Divide(&head1);
	Divide(&head2);	
       		// Recursively Divide(...) both sub-lists, to find their respective mid-points
	 // till only one or no elements are left in the sub-lists.
} 
//#endif

