// ***
// *** You MUST modify this file
// ***

#include "josephus.h"
#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_JOSEPHUS
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails,
  if (arr == NULL || n < 1)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
  // initialize all elements
if (k < 2){
	return;
}
for (int i=0; i<n;i++){
	arr[i]=i+1;
}
  
  // counting to k,
int pos=0;
for(int j=0; j<n; j++){
	for(int w=0;w<k-1 || arr[pos]==0;w++){
		if(arr[pos] == 0){
			w--;
		}
		if(++pos == n){
			pos = 0;
		}
	}
	printf("%d\n",pos); 
	arr[pos]=0;
	if(++pos == n){
		pos=0;
	}
} 
 // mark the eliminated element
  // print the index of the marked element
  // repeat until only one element is unmarked




  // print the last one




  // release the memory of the array
  free (arr);
}
#endif
