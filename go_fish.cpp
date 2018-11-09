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
    Player p1("Max");
    Player p2("Jacob");
    Deck d;  //create a deck of cards
    Card cardrequest;
    Card cardtogive;
    bool whosTurn =false;

    cout << "Welcome to Go Fish!\nThe contestants are: Max and Jacob\n\n";
    ofstream outFile;
    outFile.open("gofish_results.txt");
    d.shuffle();
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    cout << p1.getName() << " has : " << p1.showHand() << endl;
    cout << p2.getName() << " has : " << p2.showHand() << "\n\n";

    while(isWinner(p1,p2)==0) {
        if (!whosTurn) {
            while (!whosTurn) {
                cout<<p2.getName()<<" asks - Do you have a ";
                cardrequest = p2.chooseCardFromHand();
                cout << cardrequest.rankString(cardrequest.getRank()) << "?" << endl;
                cout<< p1.getName()<<" says - ";
                if (p1.rankInHand(cardrequest)) {
                    cout << "Yes! I have a " << cardrequest.rankString(cardrequest.getRank()) << endl;
                    cout << p2.getName() << " books the pair of " << cardrequest.rankString(cardrequest.getRank())  <<"s" << "\n\n";
                    cardtogive = p1.getCardwithRank(cardrequest.getRank());
                    p1.removeCardFromHand(cardtogive);
                    p2.addCard(p1.removeCardFromHand(cardtogive));
                    p2.checkHandForPair(cardtogive, cardrequest);
                    p2.bookCards(cardtogive, cardrequest);
                    p2.removeCardFromHand(cardrequest);
                    p2.removeCardFromHand(cardtogive);
                } else {
                    cout << "Go Fish!" << endl;
                    if (d.size() > 0) {
                        Card temp = d.dealCard();
                        cout << p2.getName() << " draws " << temp.rankString(temp.getRank()) << "\n\n";
                        p2.addCard(temp);
                    }
                    whosTurn = true;
                }
            }
        } else {
            while (whosTurn) {
                cout<<p1.getName()<<" asks - Do you have a ";
                cardrequest = p1.chooseCardFromHand();
                cout << cardrequest.rankString(cardrequest.getRank()) << "?" << endl;
                cout<<p2.getName()<<" says - ";
                if (p2.rankInHand(cardrequest)) {
                    cout << "Yes! I have a " << cardrequest.rankString(cardrequest.getRank()) << endl;
                    cout << p1.getName() << " books the pair of " << cardrequest.rankString(cardrequest.getRank()) <<"s"<< "\n\n";
                    cardtogive = p2.getCardwithRank(cardrequest.getRank());
                    p2.removeCardFromHand(cardtogive);
                    p1.addCard(p1.removeCardFromHand(cardtogive));
                    p1.checkHandForPair(cardtogive, cardrequest);
                    p1.bookCards(cardtogive, cardrequest);
                    p1.removeCardFromHand(cardrequest);
                    p1.removeCardFromHand(cardtogive);

                } else {
                    cout << "Go Fish!" << endl;
                    if (d.size() > 0) {
                        Card temp = d.dealCard();
                        cout << p1.getName() << " draws " << temp.rankString(temp.getRank()) << "\n\n";
                        p1.addCard(temp);
                    }
                    whosTurn = false;
                }

            }
        }
    if(p1.checkHandForBook(cardrequest,cardtogive)){
        p1.bookCards(cardrequest, cardtogive);

    }
        if(p1.checkHandForPair(cardrequest,cardtogive)){
            p1.bookCards(cardrequest, cardtogive);
            p1.removeCardFromHand(cardrequest);
            p1.removeCardFromHand(cardtogive);
        }
        if(p2.checkHandForPair(cardrequest,cardtogive)){
            p2.bookCards(cardrequest, cardtogive);
            p2.removeCardFromHand(cardrequest);
            p2.removeCardFromHand(cardtogive);
        }

    }


    if(isWinner(p1,p2) == 1){
        outFile << p1.getName() << " is the winner! ";
        cout << p1.getName() << " is the winner! ";
        cout<<p1.showBooks();
    }
    else{
        outFile << p2.getName() << " is the winner! ";
        cout << p2.getName() << " is the winner! ";
        cout<<p2.showBooks();
    }
    outFile.close();
    return EXIT_SUCCESS;
}
