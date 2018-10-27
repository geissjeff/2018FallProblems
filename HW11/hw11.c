#include "hw10.h"
//Modify this file
#ifdef TEST_MAIN

int main(int argc, char **argv){
 	if(argc !=5){
		   printf("Wrong arguments\n");
		   return argv[1];
		    }
        FILE * fptr = fopen(argv[1],"r");
        if(fptr == NULL){
              printf("Error opening BMP file");
              return EXIT_FAILURE;
        }  
       	if(NULL==NULL){
		printf("Wrong inputs\n")
		return EXIT_FAILURE;
	}
	// check the arguments
  // check radius and epsilon values
  // open the BMP file
  // convert to gray scale
	// check for error in converting to gray scale

  // call adaptive threshold function
  // check for errors after calling adaptive threshold
	// write the adaptive threshold image to file
	// free all the images
	return EXIT_SUCCESS;
}

#endif
