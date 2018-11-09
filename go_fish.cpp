//
// Created by Max Dauber on 11/7/18.
// and Jacob Grimm
#include <iostream>    // Provides cout and cin
#include <fstream>
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;
int isWinner(Player &p1, Player &p2){// function to determine a winner, the winner is whoever reaches 26 cards in their book first
    if(p1.getBookSize()>=26){
        return (1);
    }
    if(p2.getBookSize()>=26){
        return (2);
    }

    return(0);
}



void dealHand(Deck &d, Player &p, int numCards)// function to deal a hand
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}

int main( )
{
    int numCards = 7;// number of cards for 2 players
    Player p1("Max");
    Player p2("Jacob");
    Deck d;  //create a deck of cards
    Card cardrequest;//when a person asks for a card uses this variable card
    Card cardtogive;// when a person is giving up their ccard uses this card 
    bool whosTurn =false;// when this bool is false its p2's turn, when it is true it is p1's. alternates everyturn

    ofstream outFile;
    outFile.open("gofish_results.txt");
    cout << "Welcome to Go Fish!\nThe contestants are: Max and Jacob\n\n";// have it outing to std output and the file
    outFile << "Welcome to Go Fish!\nThe contestants are: Max and Jacob\n\n";
    d.shuffle();
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

 //   cout << p1.getName() << " has : " << p1.showHand() << endl;
   // cout << p2.getName() << " has : " << p2.showHand() << "\n\n";

    while(isWinner(p1,p2)==0) {//main loop running while no one  has won
        cout << p1.getName() << " has : " << p1.showHand() << endl;
        outFile << p1.getName() << " has : " << p1.showHand() << endl;
   	    cout << p2.getName() << " has : " << p2.showHand() << "\n\n";
        outFile << p2.getName() << " has : " << p2.showHand() << "\n\n";
        if (!whosTurn) { 			// when its p2s turn
            while (!whosTurn) {			 // p2s turn looop
                if(p2.getHandSize()==0){		//if they have an empty hand it prompts them to draw one
                    cardrequest =Card(20, Card::spades);
                }
                else{
                cout<<p2.getName()<<" asks - Do you have a ";
                outFile<<p2.getName()<<" asks - Do you have a ";
                cardrequest = p2.chooseCardFromHand();// player chooses card
                cout << cardrequest.rankString(cardrequest.getRank()) << "?" << endl;
                outFile<< cardrequest.rankString(cardrequest.getRank()) << "?" << endl;// regular talking
                cout<< p1.getName()<<" says - ";
                outFile<< p1.getName()<<" says - ";
                }
                if (p1.rankInHand(cardrequest)) {// if the card requested is in p1's hand
                    cout << "Yes! I have a " << cardrequest.rankString(cardrequest.getRank()) << endl;
                    outFile << "Yes! I have a " << cardrequest.rankString(cardrequest.getRank()) << endl;
                    cout << p2.getName() << " books the pair of " << cardrequest.rankString(cardrequest.getRank())  <<"s" << "\n\n";
                    outFile << p2.getName() << " books the pair of " << cardrequest.rankString(cardrequest.getRank())  <<"s" << "\n\n";
                    cardtogive = p1.getCardwithRank(cardrequest.getRank());
                    p1.removeCardFromHand(cardtogive); //removes card from p1
                    p2.addCard((cardtogive));
                    p2.checkHandForPair(cardtogive, cardrequest);
                    p2.bookCards(cardtogive, cardrequest);//books the cards and then removes both cards from his hand
                    p2.removeCardFromHand(cardrequest);
                    p2.removeCardFromHand(cardtogive);
                }
                else {//if the card isnt requested doesnt exist then we draw a card
                  //  if(cardrequest!=Card(20, Card::spades)){
                    cout << "Go Fish!" << endl;
                    outFile << "Go Fish!" << endl;
                    if (d.size() > 0) {
                        Card temp = d.dealCard();
                        cout << p2.getName() << " draws " << temp.toString() << "\n\n";
                        outFile << p2.getName() << " draws " << temp.toString() << "\n\n";
                        p2.addCard(temp);
                    }
                    else{// debugging tool if the deck is ever emoty
                        cout<<"nomore";
                        outFile<<"nomore";
                    }

                    whosTurn = true;//sets it to the other players turn
                }
            }
        } else {
            while (whosTurn) {// main loop for p1
                if(p1.getHandSize()==0){// if hand is empty does that
                    cardrequest =Card(20, Card::spades);
                }
                else{
                    cout<<p1.getName()<<" asks - Do you have a ";
                    outFile<<p1.getName()<<" asks - Do you have a ";
                cardrequest = p1.chooseCardFromHand();
                cout << cardrequest.rankString(cardrequest.getRank()) << "?" << endl;
                outFile << cardrequest.rankString(cardrequest.getRank()) << "?" << endl;
                cout<<p2.getName()<<" says - ";
                outFile<<p2.getName()<<" says - ";
                }


                if (p2.rankInHand(cardrequest)) {// does the same thing for p2 above this for p1
                    cout << "Yes! I have a " << cardrequest.toString() << endl;
                    outFile << "Yes! I have a " << cardrequest.toString() << endl;
                    cout << p1.getName() << " books the pair of " << cardrequest.rankString(cardrequest.getRank()) <<"s"<< "\n\n";
                    outFile << p1.getName() << " books the pair of " << cardrequest.rankString(cardrequest.getRank()) <<"s"<< "\n\n";
                    cardtogive = p2.getCardwithRank(cardrequest.getRank());
                    p2.removeCardFromHand(cardtogive);
                    p1.addCard((cardtogive));
                    p1.checkHandForPair(cardtogive, cardrequest);
                    p1.bookCards(cardtogive, cardrequest);
                    p1.removeCardFromHand(cardrequest);
                    p1.removeCardFromHand(cardtogive);

                } else {
                    //if(cardrequest!=Card(20, Card::spades)) {
                        cout << "Go Fish!" << endl;//}
                        outFile << "Go Fish!" << endl;
                        if (d.size() > 0) {
                            Card temp = d.dealCard();
                            cout << p1.getName() << " draws " << temp.toString() << "\n\n";
                            outFile << p1.getName() << " draws " << temp.toString() << "\n\n";
                            p1.addCard(temp);
                        }
                        else{
                            cout<<"nomore";
                            outFile<<"nomore";
                        }

                    whosTurn = false;// switcehs turns
                }

            }
        }
    if(p1.checkHandForBook(cardrequest,cardtogive)){// checks their hands at the end of the turn 
        p1.bookCards(cardrequest, cardtogive);

    }
        if(p1.checkHandForPair(cardrequest,cardtogive)){// goes thru both players hands at the end just to make sure they didnt draw a book, if they did it books them
            p1.bookCards(cardrequest, cardtogive);
            p1.removeCardFromHand(cardrequest);
            p1.removeCardFromHand(cardtogive);
            cout << p1.getName() << " books the pair of " << cardrequest.rankString(cardrequest.getRank())  <<"s" << "\n\n";
            outFile << p1.getName() << " books the pair of " << cardrequest.rankString(cardrequest.getRank())  <<"s" << "\n\n";

        }
        if(p2.checkHandForPair(cardrequest,cardtogive)){
            p2.bookCards(cardrequest, cardtogive);
            p2.removeCardFromHand(cardrequest);
            p2.removeCardFromHand(cardtogive);
            cout << p2.getName() << " books the pair of " << cardrequest.rankString(cardrequest.getRank())  <<"s" << "\n\n";
            outFile << p2.getName() << " books the pair of " << cardrequest.rankString(cardrequest.getRank())  <<"s" << "\n\n";

        }

    }


    if(isWinner(p1,p2) == 1){// end of program outputs the winner
        outFile << p1.getName() << " is the winner! ";
        cout << p1.getName() << " is the winner! ";
        outFile << p1.showBooks();
        cout<<p1.showBooks();
    }
    else{
        outFile << p2.getName() << " is the winner! ";
        cout << p2.getName() << " is the winner! ";
        outFile << p2.showBooks();
        cout<<p2.showBooks();
    }
    outFile.close();// end of file
    return EXIT_SUCCESS;
}
