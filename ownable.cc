#include <string>
#include "ownable.h"
#include <iostream>
#include "academic.h"

using namespace std;


Ownable::Ownable(string name, int squarepos, int cost) : Square(name,squarepos),cost(cost),mortgaged(0),owner("BANK"),propertyowner(NULL) {}

Ownable::~Ownable() {}



int Ownable::getCost() { return cost; }

bool Ownable::getMortgaged()  { return mortgaged; }

/*bool Ownable::getBought() { return bought; }*/

void Ownable::setOwner(Player *p) {
	propertyowner = p;
}

string  Ownable::getOwnerString() {
	return owner;
}

void Ownable::setOwnerString(string own) {
	owner = own;
}
	
Player * Ownable::getOwner() { return propertyowner; }

	
void Ownable::Mortgage() {
//	cout << "ENTERED MORTGAGE" << endl;
//	cout << "MORTGAGE BEFORE: " << mortgaged << endl;
	Academic *a = dynamic_cast<Academic *>(this);
	if (mortgaged) { //whether its res or gym or academic, check if its already 
		cout << "Already mortgaged!" << endl;
		return;
	}
	//if its not academic and its not mortgaged, set mortgaged to 1
	else if (!a) {
		mortgaged = 1;
		propertyowner->setMoney(cost/2);
		return;
	}
	// if its an academic building, make sure there are no improvements
	else { 
		if (a->getNumImp() > 0) {
			cout << "You must sell all your improvements before mortgaging property" << endl;
			return;
		}
		else {
			// if there are no improvements, mortgage it
			mortgaged = 1;
			propertyowner->setMoney(cost/2);
		}
	}
//	cout << "MORTGAGE AFTER: " << mortgaged << endl;
}


void Ownable::unMortgage() {

	if(getMortgaged()) {
		int moneyOwed = (getCost()/2)*1.1;
		propertyowner->setMoney(-1*moneyOwed);
		mortgaged = 0;
	 } else {
		cout << "This property is already mortgaged." << endl;
	}
}

void Ownable::setMortgage(bool mortgage) {
	
	mortgaged = mortgage;
}

/*
void Ownable::Auction(int numPlayers, int numbidders, Player * players[numPlayers]){
	Player *highestbidder;
  //      int numbidders = currnumplayers;
        int currbid;
        string decision;
                                 
        while (numbidders != 1) {
              for(int i = 0; i < numPlayers;++i) {
              //if still in the game and hasnt withdrew yet
                      if (players[i] != NULL && (!players[i]->getWithdraw())) {
                                cout << players[i]->getPlayername() << ", Would you like to bid or withdraw? Choose (bid,withdraw)" << endl;
                                cin >> decision;
                                if (decision == "withdraw") {
                                          players[i]->setWithdraw(1);
                                          cout << players[i]->getPlayername() << " has withdrew." << endl;
                                          --numbidders;
                                          continue;
                                }       
                                else if (decision == "bid") {
                                          cout << "Whats your bid? " << endl;
                                          cin >> currbid; 
                                          highestbidder = players[i];
                                          cout << highestbidder->getPlayername() << " has the highest bid at " << currbid << endl;
                                }
                      }
               }
        }
	cout << highestbidder->getPlayername() << " now owns " << name << endl;
        highestbidder->setMoney(-currbid);
	setOwner(highestbidder);
}*/

void Ownable::getAction(Player *player) {}
