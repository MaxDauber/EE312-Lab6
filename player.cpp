#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "card.h"
#include "deck.h"
#include "player.h"
using namespace std;

Player::Player(){
    myName="zx";
};

void Player::addCard(Card c){
    myHand.push_back(c);
};  //adds a card to the hand
void Player::bookCards(Card c1, Card c2){
    if(c1.getRank()==c2.getRank()){
        myBook.push_back(c1);
        myBook.push_back(c2);}
    }




    bool Player::checkHandForBook(Card &c1, Card &c2){
	
		for(int i=0; i<myHand.size(); i++){
			Card compare=myHand[i];
			for(int j=(i+1);j<myHand.size();j++){
				if(compare==myHand[j]){
					(c1)=compare;
					(c2)=myHand[j];
					return(true);
				
				}
			
			
			}
			
		}
		return(false);
	
	
	}

string Player::showHand() const{
	string returnstring;
	for(int i=0; i<myHand.size(); i++){
		returnstring+=myHand[i].toString();
		if(myHand.size()!=i+1){
			returnstring+=", ";
		}
	}
	return(returnstring);
};


//uses some strategy to choose one card from the player's
//hand so they can say "Do you have a 4?"
Card Player::chooseCardFromHand() const{
	int index= (rand() % myHand.size());
	return(myHand[index]);
	
};

string Player::showBooks() const{
	string returnstring;
	for(int i=0; i<myBook.size(); i++){
		returnstring+=myBook[i].toString();
		if(myBook.size()!=i+1){
			returnstring+=", ";
		}
	}
	return(returnstring);	
};


int Player::getHandSize() const{
	return(myHand.size());


};
int Player::getBookSize() const{
	return(myBook.size());
	
	
};

bool Player::rankInHand(Card c) const{
    bool ret = false;
    for(int i=0; i<myHand.size(); i++) {
        if(c.getRank() == myHand[i].getRank()){
            ret = true;
        }
    }
    return ret;
};

bool Player::cardInHand(Card c) const{
    bool ret = false;
    for(int i=0; i<myHand.size(); i++) {
        if(c == myHand[i]){
            ret = true;
        }
    }
    return ret;

};

Card Player::removeCardFromHand(Card c){
    if(cardInHand(c)){
        for(int i=0; i<myHand.size(); i++) {
            if(c == myHand[i]){
                Card ret = myHand[i];
                iter_swap(myHand.begin() + i, myHand.begin() + myHand.size());
                myHand.pop_back();
                return ret;
            }
        }
    }
};
	Card Player::getCardwithRank(int l) const{
	for(int i=0; i<myHand.size(); i++){
		if(l==myHand[i].getRank()){
			return(myHand[i]);
		}
	}
	};


bool Player::checkHandForPair(Card &c1, Card &c2){
    for(int i = 0; i<myHand.size(); i++){
        for(int j = i + 1; j<myHand.size(); j++){
            if(myHand[i].getRank() == myHand[j].getRank()){
                c1 = myHand[i];
                c2 = myHand[j];
                return true;
            }
        }
    }
    return false;
}
