#include "academic.h"
#include "board.h"
#include <string>
#include <iostream>
#include <vector>


using namespace std;


//Constructor & Destructor

Academic::Academic(string name, int squarepos, int cost, string block, int impcost) : Ownable(name,squarepos,cost), block(block), impcost(impcost) {}

Academic::~Academic() {}

	
//Arrays for Tuition with Improvements

int alTuition [6] = {2,10,30,90,160,250};
int mlTuition [6] = {4,20,60,180,320,450};
int echTuition [6] = {6,30,90,270,400,500};
int pasTuition [6] = {6,30,90,270,400,500};
int hhTuition [6] = {8,40,100,300,450,600};
int rchTuition [6] = {10,50,150,450,625,700};
int dweTuition [6] = {10,50,150,450,625,700};
int cphTuition [6] = {12,60,180,500,700,900};
int lhiTuition [6] = {14,70,200,550,750,950};
int bmhTuition [6] = {14,70,200,550,750,950};
int optTuition [6] = {16,80,220,600,800,1000};
int ev1Tuition [6] = {18,90,250,700,875,1050};
int ev2Tuition [6] = {18,90,250,700,875,1050};
int ev3Tuition [6] = {20,100,300,750,925,1100};
int physTuition [6] = {22,110,330,800,975,1150};
int b1Tuition [6] = {22,110,330,800,975,1150};
int b2Tuition [6] = {24,120,360,850,1025,1200};
int eitTuition [6] = {26,130,390,900,1100,1275};
int escTuition [6] = {26,130,390,900,1100,1275};
int c2Tuition [6] = {28,150,450,1000,1200,1400};
int mcTuition [6] = {35,175,500,1100,1300,1500};
int dcTuition [6] = {50,200,600,1400,1700,2000};

//Getters

int Academic::getNumImp() { return numimp; }

void Academic::incNumImp() {
	
	 numimp++;
	
}

void Academic::decNumImp() {

	 numimp--;

}

void Academic::setNumImp(int imp) {
	
	numimp = imp;

}

int Academic::getImpCost() { return impcost; }

bool Academic::getMonopoly() { return monopoly; }

string Academic::getBlock(){ return block; }

void Academic::setMonopoly(bool x) {
	if (x == 1) {
		monopoly = 1;
	}
	else if (x == 0) {
		monopoly = 0;
	}
}
			





void Academic::getAction(Player *player) {
//cout << "ACADEMIC GET ACTION IS CALLED" << endl;       
        int pos = player->getCurrpos();
	Square **b = (player->boardinstance)->getBoard();
	Academic *a = dynamic_cast<Academic *>(b[pos]);
//	cout << "POS IS: " << pos << endl;
       	int numbImprov = getNumImp(); 
//	cout << "Num improvements is: " << numbImprov << endl;	
	string ans;
	//no one owns this building
	if (getOwner() == NULL) {
		cout << "Would you like to purchase for $" << getCost() << " ? Choose(buy,auction)." << endl;
		cin >> ans;
		if (ans == "buy") {
			player->buy(b[pos]);
			player->Monopoly();
		}
		//else {			
	}
	//player is the owner
	else if (getOwner() == player) {
		cout << "You own this building!" << endl;
	}
	//owner is someone else
	else {
		if (pos == 1) { //lands on AL
			cout << getOwner()->getPlayername() << " owns this property. " << endl;
			cout << player->getPlayername() << " owes " << (a->getOwner())->getPlayername() << " $" << alTuition[numbImprov] << endl;
			player->setMoney(-alTuition[numbImprov]);
			getOwner()->setMoney(alTuition[numbImprov]);

        	} else if (pos == 3) { //lands on ML
			 cout << getOwner()->getPlayername() << " owns this property. " << endl;
			cout << player->getPlayername() << " owes " << (a->getOwner())->getPlayername() << " $" << mlTuition[numbImprov] << endl;
			player->setMoney(-mlTuition[numbImprov]);		
			getOwner()->setMoney(mlTuition[numbImprov]);
		} else if (pos == 6) { //lands on ECH
			cout << player->getPlayername() << " owes " << (a->getOwner())->getPlayername() << " $" << echTuition[numbImprov] << endl;
			player->setMoney(-echTuition[numbImprov]);
			getOwner()->setMoney(echTuition[numbImprov]); 

		} else if (pos == 8) { //lands on PAS
			 cout << getOwner()->getPlayername() << " owns this property. " << endl;
			cout << player->getPlayername() << " owes " << (a->getOwner())->getPlayername() << " $" << pasTuition[numbImprov] << endl;
			player->setMoney(-pasTuition[numbImprov]);
			getOwner()->setMoney(pasTuition[numbImprov]);
	
		} else if (pos == 9) { //lands on HH
			 cout << getOwner()->getPlayername() << " owns this property. " << endl;
			cout << player->getPlayername() << " owes " << (a->getOwner())->getPlayername() << " $" << hhTuition[numbImprov] << endl;
			player->setMoney(-hhTuition[numbImprov]);
			getOwner()->setMoney(hhTuition[numbImprov]);
		} else if (pos == 11) { //lands on RCH
			 cout << getOwner()->getPlayername() << " owns this property. " << endl;
			cout << player->getPlayername() << " owes " << (a->getOwner())->getPlayername() << " $" << rchTuition[numbImprov] << endl;
			player->setMoney(-rchTuition[numbImprov]);
			getOwner()->setMoney(rchTuition[numbImprov]);

		} else if (pos == 13) { //lands on DWE
			 cout << getOwner()->getPlayername() << " owns this property. " << endl;
			cout << player->getPlayername() << " owes " << (a->getOwner())->getPlayername() << " $" << dweTuition[numbImprov] << endl;
			player->setMoney(-dweTuition[numbImprov]);
			getOwner()->setMoney(dweTuition[numbImprov]);

		} else if (pos == 14) { //lands on CPH
			 cout << getOwner()->getPlayername() << " owns this property. " << endl;
			cout << player->getPlayername() << " owes " << (a->getOwner())->getPlayername() << " $" << cphTuition[numbImprov] << endl;
			player->setMoney(-cphTuition[numbImprov]);
			getOwner()->setMoney(cphTuition[numbImprov]);

		} else if (pos == 16) { //lands on LHI
			cout << getOwner()->getPlayername() << " owns this property. " << endl;
			cout << player->getPlayername() << " owes " << (a->getOwner())->getPlayername() << " $" << lhiTuition[numbImprov] << endl;
			player->setMoney(-lhiTuition[numbImprov]);
			getOwner()->setMoney(lhiTuition[numbImprov]);

		} else if (pos == 18) { //lands on BMH
			 cout << getOwner()->getPlayername() << " owns this property. " << endl;
			cout << player->getPlayername() << " owes " << (a->getOwner())->getPlayername() << " $" << bmhTuition[numbImprov] << endl;
			player->setMoney(-bmhTuition[numbImprov]);
			getOwner()->setMoney(bmhTuition[numbImprov]);

		} else if (pos == 19) { //lands on OPT
			 cout << getOwner()->getPlayername() << " owns this property. " << endl;
			cout << player->getPlayername() << " owes " << (a->getOwner())->getPlayername() << " $" << optTuition[numbImprov] << endl;
			player->setMoney(-optTuition[numbImprov]);
			getOwner()->setMoney(optTuition[numbImprov]);

		} else if (pos == 21) { // lands on EV1
			 cout << getOwner()->getPlayername() << " owns this property. " << endl;
			cout << player->getPlayername() << " owes " << (a->getOwner())->getPlayername() << " $" << ev1Tuition[numbImprov] << endl;
			player->setMoney(-ev1Tuition[numbImprov]);
			getOwner()->setMoney(ev1Tuition[numbImprov]);

		} else if (pos == 23) { //lands on EV2
			 cout << getOwner()->getPlayername() << " owns this property. " << endl;
			cout << player->getPlayername() << " owes " << (a->getOwner())->getPlayername() << " $" << ev2Tuition[numbImprov] << endl;
			player->setMoney(-ev2Tuition[numbImprov]);
			getOwner()->setMoney(ev2Tuition[numbImprov]);
	
		} else if (pos == 24) { //lands on EV3
			 cout << getOwner()->getPlayername() << " owns this property. " << endl;
			cout << player->getPlayername() << " owes " << (a->getOwner())->getPlayername() << " $" << ev3Tuition[numbImprov] << endl;
			player->setMoney(-ev3Tuition[numbImprov]);
			getOwner()->setMoney(ev3Tuition[numbImprov]);

		} else if (pos == 26) { //lands on PHYS
			 cout << getOwner()->getPlayername() << " owns this property. " << endl;
			cout << player->getPlayername() << " owes " << (a->getOwner())->getPlayername() << " $" << physTuition[numbImprov] << endl;
			player->setMoney(-physTuition[numbImprov]);
			getOwner()->setMoney(physTuition[numbImprov]);

		} else if (pos == 27) { //lands on B1
			 cout << getOwner()->getPlayername() << " owns this property. " << endl;
			cout << player->getPlayername() << " owes " << (a->getOwner())->getPlayername() << " $" << b1Tuition[numbImprov] << endl;
			player->setMoney(-b1Tuition[numbImprov]);
			getOwner()->setMoney(b1Tuition[numbImprov]);
	
		} else if (pos == 29) { //lands on B2
			 cout << getOwner()->getPlayername() << " owns this property. " << endl;
			cout << player->getPlayername() << " owes " << (a->getOwner())->getPlayername() << " $" << b2Tuition[numbImprov] << endl;
			player->setMoney(-b2Tuition[numbImprov]);
			getOwner()->setMoney(b2Tuition[numbImprov]);
	
		} else if (pos == 31) { //lands on EIT
			 cout << getOwner()->getPlayername() << " owns this property. " << endl;
			cout << player->getPlayername() << " owes " << (a->getOwner())->getPlayername() << " $" << eitTuition[numbImprov] << endl;
			player->setMoney(-eitTuition[numbImprov]);
			getOwner()->setMoney(eitTuition[numbImprov]);

		} else if (pos == 32) { //lands on ESC
			 cout << getOwner()->getPlayername() << " owns this property. " << endl;
			cout << player->getPlayername() << " owes " << (a->getOwner())->getPlayername() << " $" << escTuition[numbImprov] << endl;
			player->setMoney(-escTuition[numbImprov]);
			getOwner()->setMoney(escTuition[numbImprov]);		

		} else if (pos == 34) { //lands on C2
			 cout << getOwner()->getPlayername() << " owns this property. " << endl;
			cout << player->getPlayername() << " owes " << (a->getOwner())->getPlayername() << " $" << c2Tuition[numbImprov] << endl;
			player->setMoney(-c2Tuition[numbImprov]);
			getOwner()->setMoney(c2Tuition[numbImprov]);
	
		} else if (pos == 37) { //lands on MC
			 cout << getOwner()->getPlayername() << " owns this property. " << endl;
			cout << player->getPlayername() << " owes " << (a->getOwner())->getPlayername() << " $" << mcTuition[numbImprov] << endl;
			player->setMoney(-mcTuition[numbImprov]);
			getOwner()->setMoney(mcTuition[numbImprov]);

		} else if (pos == 39) { //lands on DC
			 cout << getOwner()->getPlayername() << " owns this property. " << endl;
			cout << player->getPlayername() << " owes " << (a->getOwner())->getPlayername() << " $" << dcTuition[numbImprov] << endl;
			player->setMoney(-dcTuition[numbImprov]);
			getOwner()->setMoney(dcTuition[numbImprov]);

		}
	}	
}

