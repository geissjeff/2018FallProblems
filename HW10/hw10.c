#include "hw10.h"
//modify the main() function
#ifdef TEST_MAINFUNC

int main(int argc, char **argv){
	if(argc !=3){
		printf("Wrong arguments\n");
		return argv[1];
	}
	FILE * fptr = fopen(argv[1],"r");
	if(fptr == NULL){
		printf("Error opening BMP file");
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
	free(fptr);
	return EXIT_SUCCESS;
}

#endif
