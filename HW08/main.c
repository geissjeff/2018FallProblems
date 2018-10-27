//
// Update this file as indicated.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include "shuffle.h"

#ifdef TEST_MAIN
int main(int argc, char ** argv)
{
	char deck[MAX_SIZE] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
	 
	if( argc != 3){
	
		return EXIT_FAILURE;
	}
	int k = argv[1];
	CardDeck orig_deck;
	orig_deck.size = MAX_SIZE;
	// Check for missing inputs
	// Create a structure variable (corresponding to the original deck)
        // Ensure you initialize the srtuct variable "size" with MAX_SIZE (declared in utility.h)
        // initialize cards to 0 since it will be populated using memcpy(..)
	memcpy(orig_deck.cards, deck, MAX_SIZE * sizeof(orig_deck.cards[0]));
    // Use memcpy(),
        //For example: memcpy(orig_deck.cards, deck, MAX_SIZE * sizeof(orig_deck.cards[0]));
	orig_deck.size = strol(argv[1], NULL, 10);
	// Read the number of cards from the terminal input
	   // For example orig_deck.size = strtol(argv[1], NULL, 10);

	//call shuffle(orig_deck);
	shuffle(orig_deck);

	return EXIT_SUCCESS;
}
#endif
