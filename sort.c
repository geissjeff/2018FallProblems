// ***
// *** You MUST modify this file, only the ssort function
// ***

#include "sort.h"
#include <stdio.h>
#include <stdbool.h>

static bool checkOrder(int * arr, int size)
// a static function is visible only in this file
// This function returns true if the array elements are
// in the ascending order.
// false, otherwise
{
  int ind;
  for (ind = 0; ind < (size - 1); ind ++)
    {
      if (arr[ind] > arr[ind + 1])
	{
	  return false;
	}
    }
  return true;
}

#ifdef TEST_SORT
void ssort(int * arr, int size)
{
  // This function has two levels of for
  // The first level specifies which element in the array
  // The second level finds the smallest element among the unsorted
  // elements

  // After finding the smallest element among the unsorted elements,
  // swap it with the element of the index from the first level
  
  // call checkOrder to see whether this function correctly sorts the
  // elements
	if ( size > 1 ){
		int small=arr[0];
		int loc=0;
		int temp;
		for(int i=0; i<size && arr[i] != '\0'; i++){
			loc=i;
			small= arr[i];
			for(int j=i; j<size; j++){
				if(small > arr[j]){
					loc=j;
					small=arr[j];
				}
			}
			if (loc != i){
				temp=arr[i];
				arr[i]=small;
				arr[loc]=temp;
			}
			
		}
	}
	else
		return;
 
 if (checkOrder(arr, size) == false)
    {
      fprintf(stderr, "checkOrder returns false\n");
    }
}
#endif
