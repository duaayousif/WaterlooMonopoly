#include <string>
#include "residence.h"
#include "board.h"
#include <iostream>


using namespace std;

Residence::Residence(std::string name, int squarepos, int cost) : Ownable(name,squarepos,cost) {}

Residence::~Residence() {}

void Residence::getAction(Player *player) {
	//int pos = player->getCurrpos();
	Square **b = (player->boardinstance)->getBoard();
	bool mortg = getMortgaged();	
	string ans;
	// If its not mortgaged, and the player isnt the owner
	if (propertyowner == NULL) {
		cout << "Do you want to buy this building for $" << getCost() << " or auction? Choose (buy,auction)." << endl;
		cin >> ans;
		if (ans == "buy") {
			player->buy(b[squarepos]);
		}
		//add else here
	}
	else if (player == propertyowner) {
		cout << "You already own this building!" << endl;
	}
	else if (!mortg && (player != propertyowner)) {
		int numowned = propertyowner->getResowned();
		if (numowned == 1) { cout <<"Pay $25 to "<< propertyowner->getPlayername() << endl;  player->setMoney(-25); propertyowner->setMoney(25);}
		else if (numowned == 2) { cout << "Pay $50 to " << propertyowner->getPlayername() << endl; player->setMoney(-50); propertyowner->setMoney(50);}
		else if (numowned == 3) { cout << "Pay $100 to " << propertyowner->getPlayername() << endl; player->setMoney(-100); propertyowner->setMoney(100);}
		else if (numowned == 4) { cout << "Pay $200 to " << propertyowner->getPlayername() << endl; player->setMoney(-200); propertyowner->setMoney(200);}
	}
}
