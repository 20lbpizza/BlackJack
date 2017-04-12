#ifndef DECK_H
#define DECK_H

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <random>

/* Declaration of Suit/Rank->Card->Hand/Decks */
enum Suit{Spades,Hearts,Clubs,Diamonds};
enum Rank{Ace,Two,Three,Four,Five,Six,Seven,Eight,Nine,Ten,Jack,Queen,King};

std::string SuitNames[] = {"Spades","Hearts","Clubs","Diamonds"};
std::string RankNames[] = {"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};


typedef struct Card{
	int rank;
	int suit;
}Card;

class Hand{
	int value;
	public:     
	std::deque<Card> hand;
	void Calculate();
	int Ask(){ return value;}
	void pass(Card);
	int size();
};

class Deck{
	std::deque<Card> deck;
	public:
	Deck(int);
	int size();
	int suit(int);
	int rank(int);
	std::string suitW(int);
	std::string rankW(int);
	void Shuffle();
};

/* Hand methods */
void Hand::Calculate(){
	int a = hand.size();
	value = 0;
	for(int i = 0; i < a; i++){
		value += hand[a].rank;
	}
}

void Hand::pass(Card card){
	hand.push_back(card);
}

int Hand::size(){
	int a = hand.size();
	return a;
}

/* Deck methods */
Deck::Deck (int a){
	//int a represents the number of decks - 52 cards each - default is 0
	Card card;

	for(int i = 0; i < a; i++){
		for(int j = 0; j < 4; j++){
			for(int k = 0; k < 13; k++){
				card.suit = j;
				card.rank = k;
				deck.push_back(card);
			}
		}
	}
}

int Deck::size() {
	return deck.size();
}

int Deck::rank(int a) {
	return deck[a].rank;
}

int Deck::suit(int a) {
	return deck[a].suit;
}

std::string Deck::rankW(int a) {
	int b = deck[a].rank;
	return RankNames[b];
}

std::string Deck::suitW(int a) {
	int b = deck[a].suit;
	return SuitNames[b];
}

/*As far as shuffling the discard pile back into the library, it may be better to create a transfer() fnc and keep shuffle for whole deck only*/
// Shuffle phase 1 - randomly pull cards from the deck to the shuffle stack
// Shuffle phase 2 - randomly pull cards from the shuffle stack back to the deck
void Deck::Shuffle(){
	int a;
	std::deque<Card> shuffle;
	while(deck.size() > 0){
		std::random_device rd;
		std::mt19937 rng(rd());
		std::uniform_int_distribution<int> uni(1,deck.size());
		a = uni(rng) - 1;
		shuffle.push_back(deck[a]);
		deck.erase(deck.begin() + a);
	}
	while(shuffle.size() > 0){
		std::random_device rd;
		std::mt19937 rng(rd());
		std::uniform_int_distribution<int> uni(1,shuffle.size());
		a = uni(rng) - 1;
		deck.push_back(shuffle[a]);
		shuffle.erase(shuffle.begin() + a);
	}
		
}
	

#endif

