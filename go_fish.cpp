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

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;

    outFile.close();

    return EXIT_SUCCESS;
}

bool isWinner(Player &p1, Player &p2){
    return true;
}
