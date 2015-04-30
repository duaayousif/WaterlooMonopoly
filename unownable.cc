#include <iostream>
#include <cstdlib>
#include <string>
#include "unownable.h"
#include "player.h"
#include "board.h"

using namespace std;


// Probability arrays && helpers

string slc[24] = {"Back 3", "Back 3", "Back 3","Back 2","Back 2","Back 2","Back 2","Back 1","Back 1","Back 1","Back 1",
			"Forward 1","Forward 1","Forward 1","Forward 2","Forward 2","Forward 2","Forward 2",
			"Forward 3","Forward 3","Forward 3","Forward 3","Go to DC Tims Line","Advance to Collect OSAP"};

int needleshall[18] = {-200,-100,-100,-50,-50,-50,25,25,25,25,25,25,50,50,50,100,100,200};

// 1% chance of getting a roll up the rim cup
int rollup[100] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		   	
// Returns a random number from 0-23
int slcgetrand() {
	srand(time(NULL));
	return rand() % 23;
}

// Returns a random number from 0-17
int nhgetrand() {
	srand(time(NULL));
	return rand() % 17;
}

// Returns a random number from 0-99
int rolluprand() {
	srand(time(NULL));
	return rand() % 99;
} 


UnOwnable::UnOwnable(string name, int squarepos) : Square(name,squarepos) {}

UnOwnable::~UnOwnable() {}


void UnOwnable::SlcNh(Player *currplayer) {

	//cout << "Entered fxn for SLC" << endl;
	Board *ActualBoard = currplayer->boardinstance;
	Square **currboard = (currplayer->boardinstance)->getBoard();
	if (ActualBoard->getTimscups() < 4) {
		int cuprand = rolluprand();
		//cout << "RAND CUP NUM IS: " << cuprand << endl;
		//If the player gets a tims cup card
		if (rollup[cuprand] == 1) {
			//cout << "reached if roll up cup rand is 1 (so got the roll up cup)" << endl;
			cout << "Congrats, you've won a Roll up Tims cup!" << endl;
			currplayer->addRollcup();
			ActualBoard->addTotalcup();
			return;
		}
	}
		//If SLC:
		int pos = currplayer->getCurrpos();
		if (pos == 2 || pos == 17 || pos == 33) {
			cout << "You will be randomly moved on the board!" << endl;
			int slcrand = slcgetrand();
			string command = slc[slcrand];
			if (command == "Back 3") {
				cout << "You've been moved back 3 spaces." << endl;
				currplayer->setCurrpos(-3);
				cout << "You're currently at " << currboard[currplayer->getCurrpos()]->getName() << endl;
				currboard[currplayer->getCurrpos()]->getAction(currplayer);
			}
			else if (command == "Back 2") {
				cout << "You've been moved back 2 spaces." << endl;
				currplayer->setCurrpos(-2);
				cout << "You're currently at " << currboard[currplayer->getCurrpos()]->getName() << endl;
				currboard[currplayer->getCurrpos()]->getAction(currplayer);
			}
			else if (command == "Back 1") {
				cout << "You've been moved back 1 space." << endl;
				currplayer->setCurrpos(-1);
				cout << "You're currently at " << currboard[currplayer->getCurrpos()]->getName() << endl;
				currboard[currplayer->getCurrpos()]->getAction(currplayer);
			}
			else if (command == "Forward 1") {
				cout << "You've been moved up 1 space." << endl;
				currplayer->setCurrpos(1);
				cout << "You're currently at " << currboard[currplayer->getCurrpos()]->getName() << endl;
				currboard[currplayer->getCurrpos()]->getAction(currplayer);
			}
			else if (command == "Forward 2") {
				cout << "You've been moved up 2 spaces." << endl;
				currplayer->setCurrpos(2);
				cout << "You're currently at " << currboard[currplayer->getCurrpos()]->getName() << endl;
				currboard[currplayer->getCurrpos()]->getAction(currplayer);
			}
			else if (command == "Forward 3") {
				cout << "You've been moved up 3 spaces." << endl;
				currplayer->setCurrpos(3);
				cout << "You're currently at " << currboard[currplayer->getCurrpos()]->getName() << endl;
				currboard[currplayer->getCurrpos()]->getAction(currplayer);
			}
			else if (command == "Go to DC Tims Line") {
				currplayer->setTotims();
				cout << "You've been moved to the DC Tims Line!" << endl;
				//currboard[currplayer->getCurrpos()]->getAction(currplayer);
			}
		
			//command is "Advance to Collect OSAP"
			else {
				currplayer->setToosap();
				cout << "You've advance to Collect OSAP!" << endl;
				//currboard[currplayer->getCurrpos()]->getAction(currplayer);
			}
		}
		
		//If NEEDLES HALL:
		else if (pos == 7 || pos == 22 || pos == 36) {
			cout << "You will either lose or gain an amount of your savings" << endl;
			int nhrand = nhgetrand();
			int change = needleshall[nhrand];
			cout << "Action: " << change << endl;
			currplayer->setMoney(change);		// fix
			cout << "You now have $" << currplayer->getMoney() << endl;
		}
	}

 
void UnOwnable::getAction(Player *player) {
	int pos = player->getCurrpos();
	// COLLECT OSAP is handled in the setCurrpos(move) fxn in player.h
	// GO TO TIMS is handles in setCurrpos(move) in player.h
	///////DCtims line??? in roll fxn?
	if (pos == 20) {
		cout << player->getPlayername() << " just got attacked by a flock of nesting geese! " << endl;
	}
	//Todo: do we have to choose according to which is less or ask the player wat they want??
	else if (pos == 4) {
		// lands on "Tuition"
		int totalworth = player->getTotalworth();
		int perc = 0.10 * totalworth;
		cout << "Would you like to pay 10 percent of your total worth ($" << perc << ") or $300? Choose from (worth,300)" << endl;
		string command;
		cin >> command;
		if (command == "worth") {
			cout << "Pay $" << perc << endl;
			player->setMoney(-perc);
		}
		else {
			cout << "Pay $300" << endl;
			player->setMoney(-300);
		}
	//Lands on pay coop fee
	}
	else if (pos == 38) {
		cout << "Pay $150 for Coop Fees" << endl;
		// Pays $150 to the bank. (Do we need to keep track of how much bank has?)
		player->setMoney(-150);
	}
	//Land on SLC or Needles
	else if (pos == 2 || pos == 7 || pos == 17 || pos == 22 || pos == 33 || pos == 36) {
		//cout << "before SLC else if" << endl;
		SlcNh(player);
		//cout << "After SlcNh" << endl;
	}
}
	
