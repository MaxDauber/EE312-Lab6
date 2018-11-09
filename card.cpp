#include <iostream>
#include <string>
#include "card.h"

using namespace std;

Card::Card(){//default constructor
myRank=0;
mySuit=spades;

}

    Card::Card(int rank, Suit s){//the real constructor used that makes the object card
	
	myRank=rank;
	mySuit = s;
	
	}

    string Card::toString()const {//turns the card into a string using some switches
	string rest;
        switch(this->myRank) {
            case 1:
                rest = 'A';
                break;
            case 2:
                rest = '2';
                break;
            case 3 :
                rest = '3';
                break;
            case 4:
                rest = '4';
                break;
            case 5:
                rest = '5';
                break;
            case 6:
                rest = '6';
                break;
            case 7 :
                rest = '7';
                break;
            case 8:
                rest = '8';
                break;
            case 9:
                rest = '9';
                break;
            case 10:
                rest = "10";
                break;
            case 11:
                rest = 'J';
                break;
            case 12:
                rest = 'Q';
                break;
            case 13:
                rest = 'K';
                break;
        }
	switch(this->mySuit) {
        case spades:
            rest+='s';
            break;
        case hearts:
            rest+= 'h';
            break;
        case diamonds :
            rest += 'd';
            break;
        case clubs:
            rest += 'c';
            break;
    }

        return (rest);
	
	
	
	}
	

    bool Card::sameSuitAs(const Card& c) const{//checks to see if two cards have the same rank
    return(this->mySuit==c.mySuit);
}  // true if suit same as c
    int  Card::getRank() const{//returns the rank of the card
        return (this->myRank);
};  // return rank, 1..13
    string Card::suitString(Suit s) const{//returns the suit of the card as a string
        string rest;
        switch(s) {
            case spades:
                rest='s';
                break;
            case hearts:
                rest= 'h';
                break;
            case diamonds :
                rest = 'd';
                break;
            case clubs:
                rest = 'c';
                break;
        }
        return rest;

    };  // return "s", "h",...
    
    string Card::rankString(int r)       const{//returns the rank of the card as a string
        string rest;
        switch(r) {
            case 1:
                rest = 'A';
                break;
            case 2:
                rest = '2';
                break;
            case 3 :
                rest = '3';
                break;
            case 4:
                rest = '4';
                break;
            case 5:
                rest = '5';
                break;
            case 6:
                rest = '6';
                break;
            case 7 :
                rest = '7';
                break;
            case 8:
                rest = '8';
                break;
            case 9:
                rest = '9';
                break;
            case 10:
                rest = "10";
                break;
            case 11:
                rest = 'J';
                break;
            case 12:
                rest = 'Q';
                break;
            case 13:
                rest = 'K';
                break;
        }
        return rest;


    };  // return "A", "2", ..."Q"
    
    
    bool Card::operator == (const Card& rhs) const{//operator allowing for the comparison of cards
        return (
                this->myRank==rhs.myRank && this->mySuit==rhs.mySuit
                );


    }

    bool Card::operator != (const Card& rhs) const{//operator defininng if cards arent equal

        return (
                this->myRank!=rhs.myRank || this->mySuit!=rhs.mySuit
        );
    }
