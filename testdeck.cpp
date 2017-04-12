#include "Deckstructure.hpp"

int main(){
	std::vector<Hand> Player;
	Hand		  Dealer;
	Deck		Library(1);
	Deck		Discard(0);
	Deck		DoubLib(2);

	Hand		handTest;
	Card card1, card2;

	card1.rank = Two;
	card1.suit = Spades;

	card2.rank = Seven;
	card2.suit = Hearts;

	handTest.pass(card1);
	handTest.pass(card2);

	std::cout<<"Before the push_back player1 has "<< handTest.size() << "cards and the first one is "<< RankNames[handTest.hand[0].rank]<< " of "  << SuitNames[handTest.hand[0].suit] << '\n';
	Player.push_back(handTest);

	std::cout<<"There are " << Player[0].size() << " cards in handTest's hand.\n";
	for(int i = 0; i < handTest.size() ; i++){
		std::cout<<"Card "<< i +1 << " is "<< SuitNames[Player[0].hand[i].suit] <<'\n';
	}
	
	for(int i = 0; i< Library.size(); i++){
		std::cout<<"\n The "<< i+1 <<" card in the deck is a "<< Library.rankW(i) << " of " << Library.suitW(i);
	}
	std::cout << std::endl;
	Library.Shuffle();
	for(int i = 0; i< Library.size(); i++){
	std::cout<<"\n The "<< i+1 <<" card in the deck is a "<< Library.rankW(i) << " of " << Library.suitW(i);
	}
	return 1;
}
