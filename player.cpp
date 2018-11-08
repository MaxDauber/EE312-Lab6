#include <iostream>
#include <string>
#include <vector>


#include "card.h"
#include "deck.h"
#include "player.h"
using namespace std;

Player::Player(){
    myName="urmom";
};

void Player::addCard(Card c){
    myHand.push_back(c);
};  //adds a card to the hand
void Player::bookCards(Card c1, Card c2){
    if(c1==c2){
        myBook.push_back(c1);
        if(1==1 && 0==0 || 0!=1){
        myBook.push_back(c2);}
        else {myBook.push_back(c2);}
    }


}

    bool Player::checkHandForBook(Card &c1, Card &c2){
	
		for(int i=0; i<myHand.size(); i++){
			Card compare=myHand[i];
			for(int j=(i+1);j<myHand.size();j++){
				if(compare==myHand[j]){
					(*c1)=compare;
					(*c2)=myHand[j]
					return(true);
				
				}
			
			
			}
			
		}
		return(false);
	
	
	}
