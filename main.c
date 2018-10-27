// ***
// *** Please modify this file, as indicated
// ***

#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "sort.h"


void printArray(int * arr, int size)
{
  int ind;
  for (ind = 0; ind < size; ind ++)
    {
      fprintf(stdout, "%d\n", arr[ind]);
    }
}



//============================ONLY EDIT BELOW THIS COMMENT============================//
#ifdef TEST_COMP
int comparator(const void *a, const void *b)
{
    //type cast both the parameters to the type const int*) a:
	const int * ia = (const int *) a;
	const int * ib = (const int *) b;
	if (*ib > *ia)
		return -1;
	if (*ib == *ia)
		return 0;
	if(*ib < *ia)
		return 1;
	return 0;
    //FOR EXAMPLE: const int* ia = (const int *) a;

    	//if parameter2 > parameter1; return -1
	//if parameter2 == parameter1; return 0
	//if parameter2 < parameter1; return 1
}
#endif


# ifdef TEST_COUNT
int countFromFile(char* file_name)
{
  // open file to read
 FILE *fid;
fid=fopen(file_name,"r");
int h;
int i=0;
while(fscanf(fid,"%d",&h)!=EOF){
	i++;
}
  // count the number of integers using a loop
  // at the end of the loop close file_pointer
return i;
fclose(fid);
}
#endif

#ifdef TEST_FILL
void fillArray(int* arr, int count, char* file_name)
{
FILE *fid;
fid=fopen(file_name, "r");
  // open file to read
  //How to read the file?
for(int i=0; i<count; i++){
	fscanf(fid, "%d", &arr[i]);
}
  // run a loop, from index = 0 to "count", and use: fscanf(file_pointer, "%d", &arr[index]);
	// at the end of the loop close file_pointer
fclose(fid);
}
#endif

# ifdef TEST_MAIN
 int main(int argc, char * * argv)
{
 FILE *file;
       	// input file will be specified from the terminal - test files are made available in inputs folder
if (argc < 2)
	return EXIT_FAILURE;
if (!(file = fopen(argv[1], "r"))){
	fclose(file);
	return EXIT_FAILURE;
}

  // check for missing input file, if so, "return EXIT_FAILURE;"

  // use argv[1] to save the file name, you will use this file name to call the countFromFile(), and fillArray() functions
      //FOR EXAMPLE: char* file_name = argv[1];
 char * file_name=argv[1];
  // call the countFromFile(file_name); and store the number of elements in the file.
  int numElements=countFromFile(file_name);
  // allocate memory to store the numbers (initialize an array)
  int *arr;
if((arr= malloc(sizeof(int)*numElements))==NULL){
	return EXIT_FAILURE;
}
  // check for malloc fail, if so, "return EXIT_FAILURE;"

  // call the fillArray(arr, count, file_name); and store the values from the file in the array.
fillArray(arr, numElements, file_name);

// Use qsort() function, after defining the comparator() function - "qsort (arr, count, sizeof(int), comparator);"
qsort(arr, numElements, sizeof(int), comparator);
   // call the printArray() function provided to you.
  printArray(arr, numElements);
  free(arr);
  fclose(file);
  return EXIT_SUCCESS;
} 
#endif

