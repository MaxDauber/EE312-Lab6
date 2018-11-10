#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "card.h"
#include "deck.h"
#include "player.h"
using namespace std;

Player::Player(){//default cconstruictor
    myName="placeholder";
};

void Player::addCard(Card c){// adds a card to the hand of the person
    myHand.push_back(c);
};  //adds a card to the hand

void Player::bookCards(Card c1, Card c2) {// places two cards if they have the same rank in the book
    if (c1.getRank() == c2.getRank()) {
        myBook.push_back(c1);
        myBook.push_back(c2);}
    }

    bool Player::checkHandForBook(Card &c1, Card &c2) {// checls the hand for a book, but doesnt actualy work
		for(int i=0; i<myHand.size(); i++){
			Card compare=myHand[i];
			for(int j=(i+1);j<myHand.size();j++){
				if(compare==myHand[j]){
					(c1)=compare;
					(c2)=myHand[j];
					return true;
				
				}
			
			
			}
			
		}
		return false;
	}

string Player::showHand() const{// turns the hand of the player into a string
	string returnstring;
	for(int i=0; i<myHand.size(); i++){
		returnstring+=myHand[i].toString();
		if(myHand.size()!=i+1){
			returnstring+=", ";
		}
	}
	return returnstring;
};


//uses some strategy to choose one card from the player's
//hand so they can say "Do you have a 4?"
Card Player::chooseCardFromHand() const{//just randomly picks a card from the persons hand and returns it as the guess
	int index= (rand() % myHand.size());
	return myHand[index];
}

string Player::showBooks() const{// turns the books of the player into a string 
	string returnstring;
	for(int i=0; i<myBook.size(); i++){
		returnstring+=myBook[i].toString();
		if(myBook.size()!=i+1){
			returnstring+=", ";
		}
	}
	return(returnstring);	
}


int Player::getHandSize() const{// returns the hand size of the person
	return(myHand.size());
}
int Player::getBookSize() const{//returns the number of cards in the book
	return(myBook.size());
}

bool Player::rankInHand(Card c) const{// checks to see if a person has a certain rank in their hand
    bool ret = false;
    for(int i=0; i<myHand.size(); i++) {
        if(c.getRank() == myHand[i].getRank()){
            ret = true;
        }
    }
    return ret;
}

bool Player::cardInHand(Card c) const{// sees if  aperson has a certain card in hand
    bool ret = false;
    for(int i=0; i<myHand.size(); i++) {
        if(c == myHand[i]){
            ret = true;
        }
    }
    return ret;

}

Card Player::removeCardFromHand(Card c){// removes a card from a persons hand
    if(cardInHand(c)){
        for(int i=0; i<myHand.size(); i++) {
            if(c == myHand[i]){
                Card ret = myHand[i];
  //              cout<<showHand()<<endl;
                myHand[i]=myHand[myHand.size()-1];
                myHand[myHand.size()-1]=ret;
//                cout<<showHand()<<endl;
                //iter_swap(myHand.begin() + i, myHand.end());
                myHand.pop_back();
               // cout<<showHand()<<endl;
                return ret;
            }
        }
    }
}
	Card Player::getCardwithRank(int l) const{// gets a card with the rank of integer l
	for(int i=0; i<myHand.size(); i++){
		if(l==myHand[i].getRank()){
			return(myHand[i]);
		}
	}
	}


bool Player::checkHandForPair(Card &c1, Card &c2){// checks the hand to see if a  pair exists, then returns the two cards with that rank
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
