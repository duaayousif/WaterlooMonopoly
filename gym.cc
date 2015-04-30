#include <string>
#include "player.h"
#include "gym.h"
#include "board.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Gym::Gym(string name, int squarepos, int cost) :  Ownable(name,squarepos,cost) {}

Gym::~Gym() {}

int rolldice() {
	srand(time(NULL));
	return rand() % 6 + 1;
}

int result() {
	int first = rolldice();
	int second = rolldice();
	return first+second;
}

void Gym::getAction(Player *player) {
	bool mortg = getMortgaged();
	string ans;
	if (propertyowner == NULL) {
		cout << "Would you like to buy this property for $" << getCost() << " or auction?" << endl;
		cin >> ans;
		if (ans == "buy") {
			//int pos = player->getCurrpos();
          		Square **b = (player->boardinstance)->getBoard();
			player->buy(b[getSquarepos()]);
		}
	}
	else if (player == propertyowner) {
		cout << "You already own this building!" << endl;
	}
	//If its not mortgaged and the player isnt the owner;
	else if (!mortg && (player != propertyowner)) {
		cout << "Roll the dice again!" << endl;
		int sum = result();
		cout << "You rolled " << sum << endl;
		int numowned = propertyowner->getGymsowned();
		if (numowned == 1) {
			cout << "Pay $" << sum*4 << " to " << propertyowner->getPlayername() << endl;
			player->setMoney(-1*sum*4);
			propertyowner->setMoney(sum*4);
		}
		else if (numowned == 2) {
			cout << "Pay $" << sum*10 << " to " << propertyowner->getPlayername() << endl;
			player->setMoney(-1*sum*10);
			propertyowner->setMoney(sum*10);
		}
	}
}


