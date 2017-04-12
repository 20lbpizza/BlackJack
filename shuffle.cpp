
#include <SFML/Graphics.hpp>
#include <iostream>

int main(){

	// A deck will be represented as an array of 52 cards
	// Suits are determined by floor(card/13) with:
	// 0 = Spades
	// 1 = Clubs
	// 2 = Hearts
	// 3 = Diamonds

	// Initialize deck then generate output

	int deck[52];
	for(int i = 0; i < 52  ; i++){
		deck[i] = i + 1;
		std::cout<<"\nThe calue of card" << i +1 << "is" << deck[i]; 
	}
	return 0;

	
}

// Option 2 - Create a deck class with a shuffle function?
// Option 3 - same as 2 except also represent cards as structs

/*
 *Shuffling 
 * Could be done with multiple decks
 * Randomly add cards from one deck to another
 * example:
 *  shuffle(deckA){
 *  	Create empty deckB
 *  	Repeat until deckA is empty
 *  		Pick random int between 0 and deckA.size
 *              Transfer(deckA,deckB,int)
 *      Copy deckB to deckA
 *      Delete deckB
 *  }
 *
 * shuffleDiscard(deckA){
 *	Put all cards on field into discard deck
 *	add discard deck to deckA
 *	shuffle(deckA)
 * }
 *
 * If the deck is not a specific class then it wil be an array and an integer will keep track of the top card
 * 
 * Array
 * Pros/Cons
   -> Pro - Easy to implement
   -> Con - Fixed deck size
   -> Con - Less informative card tracking
   ->  
 * 
 *
 */



