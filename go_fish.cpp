//
// Created by Max Dauber on 11/7/18.
//
#include <iostream>    // Provides cout and cin
#include <fstream>
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;
int isWinner(Player &p1, Player &p2){
    if(p1.getBookSize()>26){
        return (1);
    }
    if(p2.getBookSize()>26){
        return (2);
    }

    return(0);
}


void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}

int main( )
{
    int numCards = 5;
    ofstream outFile;
    outFile.open("gofish_results.txt");

    Player p1("Joe");
    Player p2("Jane");

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
    Card cardrequest;
    Card cardtogive;
    while(isWinner(p1,p2)==0) {
        cout << p1.getName() << " has : " << p1.showHand() << endl;
        cout << p2.getName() << " has : " << p2.showHand() << endl;
        cardrequest=p2.chooseCardFromHand();
        if(p1.rankInHand(cardrequest)){
			cardtogive=p1.getCardwithRank(cardrequest.getRank());
			p1.removeCardFromHand(cardtogive);
			p2.addCard(	p1.removeCardFromHand(cardtogive));
        }
        else{while(d.size()>51){p2.addCard(d.dealCard());}}

    }
    outFile.close();
    return EXIT_SUCCESS;
}


