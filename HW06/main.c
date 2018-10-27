// ***
// *** Please modify this file, as indicated
// ***

#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "vector.h"

/*-------------------------------MODIFY BELOW THIS LINE-------------------------------*/

#ifdef TEST_MAIN
int main(int argc, char * * argv)
{
    // input file will be specified from the terminal - test files are made available in inputs folder
if(argc != 3){
	return EXIT_FAILURE;
}
    	// check 
    // for missing input file/output file, if so, "return EXIT_FAILURE;"
    FILE *infile;
    FILE *outfile;
    //
    // store the input file name in a variable, from argv[1]. For example, char* in_file = argv[1];
    // store the output file name in a variable, from argv[2]. For example, char* out_file = argv[2];
char * in_file = argv[1];
char * out_file = argv[2];
    if (!(infile = fopen(in_file, "r"))){
 	return EXIT_FAILURE;
    }
	fclose(infile);
    if (!(outfile = fopen(out_file, "w"))){
   	    return EXIT_FAILURE;
    }
	fclose(outfile);
    // call numberOfElements(in_file) to obtain the number of elements in the file.
long num = numberOfElements(in_file);
    // allocate memory to store the numbers (initialize an array of structures)
Vector* vector;

if ((vector = malloc(num*sizeof(Vector)))==NULL)
   return EXIT_FAILURE;
	       	// check for malloc fail, if so, "return EXIT_FAILURE;"
fillVector(vector, num, in_file);

    //call the fillVector(vector, count, in_file); and store the values from the file in the array of strucures.
qsort(vector,num, sizeof(Vector), cmp);

    //Use qsort() function, after defining the comparator() function.
            //ENSURE THE COMPARATOR FUNCTION IS USED TO SORT THE ARRAY OF STRUCTURES W.R.T. THE STRUCTURE VARIABLE "x".

writeFile(vector, num, out_file);
     //call the writeFile(vector,count, out_file); to save the sorted vector into the file.
free(vector);
return EXIT_SUCCESS;
}
#endif

