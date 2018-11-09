#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "card.h"
#include "deck.h"
using namespace std;
Deck::Deck(){
myIndex=0;
    for(int i=0; i<4; i++){
        Card::Suit s;
        switch (i){
            case(0): s=Card::spades;
                break;
            case (1): s= Card::hearts;
                break;
            case (2): s=Card::diamonds;
                break;
            case (3): s= Card::clubs;
                break;
        }
        for(int k=1; k<=13; k++){
            myCards[myIndex]=Card(k,s);
            myIndex++;
        }
    }
    myIndex=0;
}           // pristine, sorted deck

void Deck::shuffle(){
    Card c;
    int index1=0;
    int index23=0;
    for(int i=0; i<1000; i++) {
            index1 = (rand() % 52);
            index23 = (rand() % 52);
        c=myCards[index23];
        myCards[index23]=myCards[index1];
        myCards[index1]=c;
    }

};   // shuffle the cards in the current deck


Card Deck::dealCard(){
    if(myIndex<52){
    Card returncard;
    returncard=myCards[myIndex];
    myIndex++;
    return (returncard);}

};   // get a card, after 52 are dealt, fail

int  Deck::size() const{

    return(52-myIndex);//error source in the future

}; // # cards left in the deck
