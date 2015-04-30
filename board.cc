#include "board.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include "square.h"
#include "unownable.h"
#include "ownable.h"
#include "academic.h"
#include "gym.h"
#include "residence.h"
#include <iomanip>
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

int sqWidth = 7;

string ev1Improve;
string ev2Improve;
string ev3Improve;
string physImprove;
string b1Improve;
string b2Improve;
string optImprove;
string eitImprove;
string bmhImprove;
string escImprove;
string lhiImprove;
string c2Improve;
string cphImprove;
string dweImprove;
string mcImprove;
string rchImprove;
string dcImprove;
string hhImprove;
string pasImprove;
string echImprove;
string mlImprove;
string alImprove;
string nestPlayer;
string ev1Player;
string need1Player;
string need2Player;
string need3Player;
string ev2Player;
string ev3Player;
string v1Player;
string physPlayer;
string b1Player;
string cifPlayer;
string b2Player;
string timsPlayer;
string optPlayer;
string eitPlayer;
string bmhPlayer;
string escPlayer;
string slc1Player;
string slc2Player;
string slc3Player;
string lhiPlayer;
string c2Player;
string uwpPlayer;
string revPlayer;
string cphPlayer;
string dwePlayer;
string mcPlayer;
string pacPlayer;
string coopPlayer;
string rchPlayer;
string dcPlayer;
string timsLinePlayer;
string hhPlayer;
string pasPlayer;
string echPlayer;
string mkvPlayer;
string tuitionPlayer;
string mlPlayer;
string alPlayer;
string osapPlayer;
string catBorder = "-------";
string empty = "       ";
string allEmpty = "       |";
string catBBorder = "_______|";


Board * Board::instance = NULL;

Board::Board() : timscups(0) {
	board = new Square *[40];
	board[0] = new UnOwnable("COLLECT OSAP", 0);
	board[1] = new Academic ("AL",1,40,"Arts1",50);
	board[2] = new UnOwnable("SLC",2);
	board[3] = new Academic("ML",3,60,"Arts1",50);
	board[4] = new UnOwnable("TUITION",4);
	board[5] = new Residence("MKV",5,200);
	board[6] = new Academic("ECH",6,100,"Arts2",50);
	board[7] = new UnOwnable("NEEDLES HALL",7);
	board[8] = new Academic("PAS",8,100,"Arts2",50);
	board[9] = new Academic("HH",9,120,"Arts2",50);
	board[10] = new UnOwnable("DC Tims Line",10);
	board[11] = new Academic("RCH",11,140,"Eng",100);
	board[12] = new Gym("PAC",12,150);
	board[13] = new Academic("DWE",13,140,"Eng",100);
	board[14] = new Academic("CPH",14,160,"Eng",100);
	board[15] = new Residence("UWP",15,200);
	board[16] = new Academic("LHI",16,180,"Health",100);
	board[17] = new UnOwnable("SLC",17);
	board[18] = new Academic("BMH",18,180,"Health",100);
	board[19] = new Academic("OPT",19,200,"Health",100);
	board[20] = new UnOwnable("Goose Nesting",20);
	board[21] = new Academic("EV1",21,220,"Env",150);
	board[22] = new UnOwnable("NEEDLES HALL",22);
	board[23] = new Academic("EV2",23,220,"Env",150);
	board[24] = new Academic("EV3",24,240,"Env",150);
	board[25] = new Residence("V1",25,200);
	board[26] = new Academic("PHYS",26,260,"Sci1",150);
	board[27] = new Academic("B1",27,260,"Sci1",150);
	board[28] = new Gym("CIF",28,150);
	board[29] = new Academic("B2",29,280,"Sci1",150);
	board[30] = new UnOwnable("GO TO TIMS", 30);
	board[31] = new Academic("EIT",31,300,"Sci2",200);
	board[32] = new Academic("ESC",32,300,"Sci2",200);	
	board[33] = new UnOwnable("SLC",33);
	board[34] = new Academic("C2",34,320,"Sci2",200);
	board[35] = new Residence("REV",35,200);
	board[36] = new UnOwnable("NEEDLES HALL",36);
	board[37] = new Academic("MC",37,350,"Math",200);
	board[38] = new Academic("DC",38,400,"Math",200);
	board[39] = new UnOwnable("COOP FEE", 39);

}

Board* Board::getInstance() {

	if (instance == NULL) {
		instance = new Board();
		atexit(cleanup);
	}
	return instance;
}

Board::~Board(){ 
	for (int i = 0; i < 40; ++i) {
		delete board[i];
	}
	delete [] board;
}


void Board::cleanup() {
	delete instance;
}

Square ** Board::getBoard() {
	return board;
}

void Board::addTotalcup() {
	++timscups;
}

void Board::minusTotalcup() {
	--timscups;
}

int Board::getTimscups() {
	return timscups;
}

void printEmpty() {
	for (int i = 0; i < 10; i++) {
		cout << empty;
	}
	cout << " ";
}

void printDivide() {
	cout << '|' << catBorder << '|';
        printEmpty();
        cout << '|' << catBorder << '|' << endl;
}

void printBDivide() {
	cout << '|' << catBBorder;
        printEmpty();
        cout << '|' << catBBorder << endl;
}

void printSqEmpty() {

	cout << '|' << empty << '|';
	printEmpty();
	cout << '|' << empty << '|' << endl;
	
}

void Board::printBoard() {
	
	// Top border
	for (int i = 0; i < 88; i++) {
		cout << '_';
	}
	cout << endl;
	
	// Row 1
	cout << '|' << left << setw(sqWidth) << "Goose" << '|' << setw(sqWidth) << ev1Improve << '|' << setw(sqWidth) << "NEEDLES" << '|' << setw(sqWidth) << ev2Improve << '|' << setw(sqWidth) << ev3Improve << '|' << left << setw(sqWidth) << "V1" << '|' << setw(sqWidth) << physImprove << '|' << setw(sqWidth) << b1Improve << '|' << setw(sqWidth) << left << "CIF" << '|' << setw(sqWidth) << b2Improve << '|' << setw(sqWidth) << "GO TO" << '|' << endl;	
	
	// Row 2
	cout << '|' << setw(sqWidth) << "Nesting" << '|' << catBorder << '|' << setw(sqWidth) << left << "HALL   " << '|' << catBorder << '|' << catBorder << '|'<< empty << '|' << catBorder << '|' << catBorder << '|' << empty << '|' << catBorder << '|' << left << setw(sqWidth) << "TIMS" << '|' << endl;	

	// Row 3
	cout << '|' << empty << '|' << setw(sqWidth) << left << "EV1" << '|' << empty << '|' << setw(sqWidth) << left << "EV2" << '|' << setw(sqWidth) << left << "EV3"	<< '|' << empty << '|' << setw(sqWidth) << left << "PHYS" << '|' << setw(sqWidth) << left << "B1" << '|' << empty << '|' << setw(sqWidth) << left << "B2" << '|' << empty << '|' << endl;

	// Row 4
	
	cout << '|' << setw(sqWidth) << nestPlayer << '|' << setw(sqWidth) << ev1Player << '|' << setw(sqWidth) << need1Player << '|' << setw(sqWidth) << ev2Player << '|' << setw(sqWidth) << ev3Player << '|' << setw(sqWidth) << v1Player << '|' << setw(sqWidth) << physPlayer << '|' << setw(sqWidth) << b1Player << '|' << setw(sqWidth) << cifPlayer << '|' << setw(sqWidth) << b2Player << '|' << setw(sqWidth) << timsPlayer << '|' << endl;

	// Row 5
	cout << "|";
	for (int i = 0; i < 11; i++) {
	cout << allEmpty;	
	}
	cout << endl;

	// Row 6
	cout << "|";
	for (int i = 0; i < 11; i++) {
	cout << catBBorder;
	}
	cout << endl;

	// Row 7
	cout << '|' << setw(sqWidth) << optImprove  << '|';
	printEmpty();
	cout << '|' << setw(sqWidth) << eitImprove  << '|' << endl;

	// Row 8
	printDivide();

	// Row 9
	cout << '|' << left << setw(sqWidth) << "OPT" << '|';
	printEmpty();
	cout << '|' << left << setw(sqWidth) << "EIT" << '|' << endl;

	// Row 10
	cout << '|' << left << setw(sqWidth) << optPlayer << '|';
	printEmpty();
	cout << '|' << left << setw(sqWidth) << eitPlayer << '|' << endl;

	// Row 11
	printBDivide();

	// Row 12
	cout << '|' << setw(sqWidth) << bmhImprove << '|';
	printEmpty();
	cout << '|' << setw(sqWidth) << escImprove << '|' << endl;

	// Row 13
	printDivide();

	// Row 14
	cout << '|' << left << setw(sqWidth) << "BMH" << '|';
        printEmpty();
        cout << '|' << left << setw(sqWidth) << "ESC" << '|' << endl;	

	// Row 15
	cout << '|' << left << setw(sqWidth) << bmhPlayer << '|';
        printEmpty();
        cout << '|' << left << setw(sqWidth) << escPlayer << '|' << endl;

	// Row 16
	printBDivide();

	// Row 17
	cout << '|' << left << setw(sqWidth) << "SLC" << '|';
	printEmpty();
	cout << '|' << left << setw(sqWidth) << "SLC" << '|' << endl;
	
	// Row 18
	printSqEmpty();

	// Row 19
	cout << '|' << left << setw(sqWidth) << slc1Player << '|';
        printEmpty();
        cout << '|' << left << setw(sqWidth) << slc2Player << '|' << endl;

	// Row 20
	printSqEmpty();

	// Row 21
	printBDivide();

	// Row 22
	cout << '|' << setw(sqWidth) << lhiImprove << '|';
        printEmpty();
        cout << '|' << setw(sqWidth) << c2Improve << '|' << endl;

	// Row 23
	printDivide();

	// Row 24
	cout << '|' << left << setw(sqWidth) << "LHI" << '|';
        printEmpty();
        cout << '|' << left << setw(sqWidth) << "C2" << '|' << endl;

	// Row 25
	cout << '|' << left << setw(sqWidth) << lhiPlayer << '|';
        cout << empty << " " << empty;
	for (int i = 0; i < 41; i++) {
	cout << '_';
	}
	cout << empty << " " << empty;
	cout << '|' << left << setw(sqWidth) << c2Player << '|' << endl;

	// Row 26
	cout << '|' << catBBorder;
	cout << empty << " " << empty << '|';
	for (int i = 0; i < 4; i++) {
	cout << empty << " ";
	}
	cout << empty << '|' << empty << " " << empty << '|' << catBBorder << endl;

	// Row 27
	cout << '|' << left << setw(sqWidth) << "UWP" << '|';
        cout << empty << " " << empty << "|  ###   ###   #####  ###   ###   ###   |" << empty << " " << empty;
	cout << '|' << left << setw(sqWidth) << "REV" << '|' << endl;
	
	// Row 28
        cout << '|' << empty << '|';
        cout << empty << " " << empty << "|  #  #  #  #     #  #   # #   # #   #  |" << empty << " " << empty;
        cout << '|' << empty << '|' << endl;

        // Row 29
        cout << '|' << left << setw(sqWidth) << uwpPlayer << '|';
        cout << empty << " " << empty << "|  ####  ####    #   #   # #   # #   #  |" << empty << " " << empty;
        cout << '|' << left << setw(sqWidth) << revPlayer << '|' << endl;

	// Row 30
	cout << '|' << empty << '|';
        cout << empty << " " << empty << "|  #   # #   #  #    #   # #   # #   #  |" << empty << " " << empty;
        cout << '|' << empty << '|' << endl;
	
	// Row 31
	cout << '|' << catBBorder;
        cout << empty << " " << empty << "|  ####  ####  #      ###   ###   ###   |" << empty << " " << empty;
        cout << '|' << catBBorder << endl;

	// Row 32
	cout << '|' << setw(sqWidth) << cphImprove << '|';
	cout << empty << " " << empty << '|';
	for (int i = 0; i < 39; i++) {
		cout << '_';
	}
	cout << '|' << empty << " " << empty;
	cout << '|' << setw(sqWidth) << "NEEDLES" << '|' << endl;

	// Row 33
	cout << '|' << catBorder << '|';
	printEmpty();
	cout << '|' << left << setw(sqWidth) << "HALL" << '|' << endl;
	
	// Row 34
	cout << '|' << left << setw(sqWidth) << "CPH" << '|';
	printEmpty();
	cout << '|' << empty << '|' << endl;

	// Row 35
	cout << '|' << setw(sqWidth) << cphPlayer << '|';
	printEmpty();
	cout << '|' << setw(sqWidth) << need2Player << '|' << endl;

	// Row 36
	printBDivide();

	// Row 37
	cout << '|' << setw(sqWidth) << dweImprove << '|';
        printEmpty();
        cout << '|' << setw(sqWidth) << mcImprove << '|' << endl;
	
	// Row 38
        printDivide();

        // Row 39
        cout << '|' << left << setw(sqWidth) << "DWE" << '|';
        printEmpty();
        cout << '|' << left << setw(sqWidth) << "MC" << '|' << endl;

	// Row 40
        cout << '|' << setw(sqWidth) << dwePlayer << '|';
        printEmpty();
        cout << '|' << setw(sqWidth) << mcPlayer << '|' << endl;

	// Row 41
	printBDivide();

	// Row 42
        cout << '|' << left << setw(sqWidth) << "PAC" << '|';
        printEmpty();
        cout << '|' << left << setw(sqWidth) << "COOP" << '|' << endl;

        // Row 43
	cout << '|' << empty << '|';
        printEmpty();
        cout << '|' << left << setw(sqWidth) << "FEE"  << '|' << endl;

        // Row 44
        cout << '|' << left << setw(sqWidth) << pacPlayer << '|';
        printEmpty();
        cout << '|' << left << setw(sqWidth) << coopPlayer << '|' << endl;

        // Row 45
        printSqEmpty();

        // Row 46
        printBDivide();

	 // Row 47
        cout << '|' << setw(sqWidth) << rchImprove  << '|';
        printEmpty();
        cout << '|' << setw(sqWidth) << dcImprove  << '|' << endl;

        // Row 48
        printDivide();

        // Row 49
        cout << '|' << left << setw(sqWidth) << "RCH" << '|';
        printEmpty();
        cout << '|' << left << setw(sqWidth) << "DC" << '|' << endl;

        // Row 50
        cout << '|' << left << setw(sqWidth) << rchPlayer << '|';
        printEmpty();	
        cout << '|' << left << setw(sqWidth) << dcPlayer << '|' << endl;	

	// Row 51
        cout << "|" << catBBorder;
        for (int i = 0; i < 71; i++) {
        cout << '_';
        }
        cout << "|" << catBBorder<< endl;

	 // Row 52
        cout << '|' << left << setw(sqWidth) << "DC Tims" << '|' << setw(sqWidth) << hhImprove << '|' << setw(sqWidth) << pasImprove << '|' << setw(sqWidth) << "NEEDLES" << '|' << setw(sqWidth) << echImprove << '|' << left << setw(sqWidth) << "MKV" << '|' << setw(sqWidth) << "TUITION" << '|' << setw(sqWidth) << mlImprove << '|' << setw(sqWidth) << left << "SLC" << '|' << setw(sqWidth) << alImprove << '|' << setw(sqWidth) << "COLLECT" << '|' << endl;

        // Row 53
        cout << '|' << setw(sqWidth) << "Line" << '|' << catBorder << '|' << catBorder << '|' << setw(sqWidth) << left << "HALL" << '|' << catBorder << '|' << empty << '|' << empty << '|' << catBorder << '|' << empty << '|' << catBorder << '|' << left << setw(sqWidth) << "OSAP" << '|' << endl;

        // Row 54
        cout << '|' << empty << '|' << setw(sqWidth) << left << "HH" << '|' << setw(sqWidth) << left << "PAS" << '|' << empty << '|' << setw(sqWidth) << left << "ECH" << '|' << empty << '|' << empty << '|' << setw(sqWidth) << left << "ML" << '|' << empty << '|' << setw(sqWidth) << left << "AL" << '|' << empty << '|' << endl;

        // Row 55

        cout << '|' << setw(sqWidth) << timsLinePlayer << '|' << setw(sqWidth) << hhPlayer << '|' << setw(sqWidth) << pasPlayer << '|' << setw(sqWidth) << need3Player << '|' << setw(sqWidth) << echPlayer << '|' << setw(sqWidth) << mkvPlayer << '|' << setw(sqWidth) << tuitionPlayer << '|' << setw(sqWidth) << mlPlayer << '|' << setw(sqWidth) << slc3Player << '|' << setw(sqWidth) << alPlayer << '|' << setw(sqWidth) << osapPlayer << '|' << endl;

        // Row 56
        cout << "|";
        for (int i = 0; i < 11; i++) {
        cout << catBBorder;
        }
        cout << endl;	
}



void Board::save(string fileName, int numPlayers, Player *players[8]) {

	ofstream file;
	file.open(fileName.c_str());
	
	// Read in Number of Players
	file << numPlayers << "\n";
	
	// Player info
	for (int i = 0; i < numPlayers; i++) {

		file << players[i]->getPlayername() << " ";
		file << players[i]->getBoardName() << " ";
		file << players[i]->getRollUp() << " ";
		file << players[i]->getMoney() << " ";
		file << players[i]->getCurrpos() << " ";	
	
		if (players[i]->getCurrpos() == 10) { // In Jail
			//int intimsline;
			if (players[i]->getTimsline() != -1) {
				file << "1 " << players[i]->getTimsline() << "\n";
			}
			else {
			file << "0" << "\n";	
			
			}
		}
		else {
			file << "\n";
		}
	}
	
	// Building info
	
		for (int i = 0; i < 40; i++) {
			Ownable *o = dynamic_cast<Ownable *>(board[i]);
			
			if (o) {
				file << o->getName() << " ";
				//if (o->getOwnerString() != "") {
				
		 			file << o->getOwnerString() << " ";
				//}
				//else {
				//	file << "BANK" << " ";
				//}
			
                        	if (o->getMortgaged()) {
					file << "-1" << "\n";
				}
				else {
					Academic *a = dynamic_cast<Academic *>(o);
					//if its a residence or a gym, improvements 0
					if (!a) {
						file << "0" << "\n";
					}
					//otherwise print the num of improvements
					else {
						file << a->getNumImp() << "\n";
					}
				}	
			}
			
		}
	file.close();	
}

/*void Board::load(string fileName) {
 	
	int numbPlayers;
	int money;
 
	ifstream ifs(fileName.c_str());
	ifs >> numbPlayers;
	
	// Initialize Players
        
	Player * players[numbPlayers];
        int pos = 0;
        while (pos != numbPlayers) {
                string name;
                string boardname;
                ifs >> name;
		ifs >> boardname;
		ifs >> money;
                players[pos] = new Player(name,boardname); 
		++pos;
        }

	int playPos;
	int timsLine;
	for (int i = 0; i < numbPlayers; i++) {
		ifs >> playPos;
		players[i]->setMoney(money);
		players[i]->setPlayerpos(playPos);
		
		if(playPos == 10) {
			ifs >> timsLine;	
			players[i]->setTimsline(timsLine);
		}
	}

	// Buildings
	 for (int i = 0; i < 40; i++) {
                        Ownable *o = dynamic_cast<Ownable *>(board[i]);
                        Academic *a = dynamic_cast<Academic*>(board[i]);

			string owner;
                        bool mortgaged;
                        int numimp;
                        bool monopoly;

                        ifs >> owner;
                        ifs >> mortgaged;
                        ifs >> numimp;
                        ifs >> monopoly;

		if(o) {

                        for (int i = 0; i < numbPlayers; i++) {
                                string pName = players[i]->getPlayername();
                        //      string oName = (*it)->getOwnerString();

                                if(pName == owner) {
                                        (o)->setOwner(players[i]);
                                }
                        }

                        (o)->setMortgage(mortgaged);
                       
			if(a) {
			 	a->setNumImp(numimp);
                        	a->setMonopoly(monopoly);

                        }
                }

	}

}*/


void Board::setImprovements() {
         //go through each square, if the square is an academic building, check which building it is, and set the improvements
         for (int i = 0; i < 40; ++i) {
                 Academic *a = dynamic_cast<Academic *>(board[i]);
                 // if its academic set improvements depending on the building
                 if (a) {
                         if (i == 1) { //AL Improvements 
				alImprove = "";
                                 for (int j = 0; j < a->getNumImp(); ++j) {
                                         alImprove += "I";
                                 }
                         }
                         if (i == 3) { //ML Improvements
				mlImprove = "";
                                 for (int j = 0; j < a->getNumImp(); ++j) {
                                         mlImprove += "I";
                                 }
                         }
                         if (i == 6) { //ECH Improvements
				echImprove = "";
                                 for (int j = 0; j < a->getNumImp(); ++j) {
                                         echImprove += "I";
                                 }
                         }
                         if (i == 8) { //PAS Improvements
				pasImprove = "";
                                 for (int j = 0; j < a->getNumImp(); ++j) {
                                         pasImprove += "I";
                                 }
                         }
                         if (i == 9) { //HH Improvements
				hhImprove = "";
				for (int j = 0; j < a->getNumImp(); ++j) {
					hhImprove += "I";
				}
			}
			if (i == 11) { //RCH Improvements
				rchImprove = "";
				for (int j = 0; j < a->getNumImp(); ++j) {
					rchImprove += "I";
				}
			}
			if (i == 13) { // DWE Improvements
				dweImprove = "";
				for (int j = 0; j < a->getNumImp(); ++j) {
					dweImprove += "I";
				}
			}
			if (i == 14) { //CPH Improvements
				cphImprove = "";
				for (int j = 0; j < a->getNumImp(); ++j) {
					cphImprove += "I";
				}
			}
			if (i == 16) { //LHI Improvements
				lhiImprove = "";
				for (int j = 0; j < a->getNumImp(); ++j) {
					lhiImprove += "I";
				}
			}
			if (i == 18) { //BMH Improvements
				bmhImprove = "";
				for (int j = 0; j < a->getNumImp(); ++j) {
					bmhImprove += "I";
				}
			}
			if (i == 19) { //OPT Improvements
				optImprove = "";
				for (int j = 0; j < a->getNumImp(); ++j) {
					optImprove += "I";
				}
			}
			if (i == 21) { //EV1 Improvements
				ev1Improve = "";
				for (int j = 0; j < a->getNumImp(); ++j) {
					ev1Improve += "I";
				}
			}
			if (i == 23) { //EV2 Improvements
				ev2Improve = "";
				for (int j = 0; j < a->getNumImp(); ++j) {
					ev2Improve += "I";
				}
			}
			if (i == 24) { //EV3 Improvements
				ev3Improve = "";
				for (int j = 0; j < a->getNumImp(); ++j) {
					ev3Improve += "I";
				}
			}
			if (i == 26) { //PHYS Improvements
				physImprove = "";
				for (int j = 0; j < a->getNumImp(); ++j) {
					physImprove += "I";
				}
			}
			if (i == 27) { //B1 Improvements
				b1Improve = "";
				for (int j = 0; j < a->getNumImp(); ++j) {
					b1Improve += "I";
				}
			}
			if (i == 29) { //B2 Improvements
				b2Improve = "";
				for (int j = 0; j < a->getNumImp(); ++j) {
					b2Improve += "I";
				}
			}
			if (i == 31) { //EIT Improvements
				eitImprove = "";
				for (int j = 0; j < a->getNumImp(); ++j) {
					eitImprove+= "I";
				}
			}
			if (i == 32) { //ESC Improvements
				escImprove = "";
				for (int j = 0; j < a->getNumImp(); ++j) {
					escImprove+= "I";
				}
			}
			if (i == 34) { //C2 Improvements
				c2Improve = "";
				for (int j = 0; j < a->getNumImp(); ++j) {
					c2Improve += "I";
				}
			}
			if (i == 37) { //MC Improvements
				mcImprove = "";
				for (int j = 0; j < a->getNumImp(); ++j) {
					mcImprove += "I";
				}
			}
			if (i == 39) { //DC Improvements
				dcImprove = "";
				for (int j = 0; j < a->getNumImp(); ++j) {
					dcImprove += "I";
				}
			}
		}
}	
}
/*
void Board::playerMove(string boardPlayer, int numPlayers, Player *players[numPlayers], int index) {
	//cout << "ENTERED playerMOVE" << endl;
                        boardPlayer = "";
                        for (int j = 0; j < numPlayers; j++) {
//			cout << "ENETED LOOP" << endl;
                                if (players[j] != NULL) {
                                        if (players[j]->getCurrpos() == index) {
                                                boardPlayer += players[j]->getBoardName();
                                        	cout << "CALLED";
					}
//						cout << "String is: " << boardPlayer;
                                        }
                                }
                        }


}*/

void Board::movePlayer(int numPlayers, Player *players[8]) {
//	cout << "CALLED";         
	for (int i = 0; i < 40; i++) {
		if(i == 0) {
			//playerMove(osapPlayer,numPlayers,players,0);
			osapPlayer = "";
			for (int j = 0; j < numPlayers; j++) {
				if (players[j] != NULL) {
					if (players[j]->getCurrpos() == 0) {
						osapPlayer += players[j]->getBoardName();
					}
				}	
			}
		} else if(i == 1) { // AL
			alPlayer = "";
			for (int j = 0; j < numPlayers; j++) {
				if (players[j] != NULL) {
					if (players[j]->getCurrpos() == 1) {
						alPlayer += players[j]->getBoardName();
					}
				}	
			}
		} else if (i == 2) { // SLC
			slc2Player = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 2) {
                                                 slc2Player += players[j]->getBoardName();
                                                 //cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
		} else if (i == 3) { // ML
			mlPlayer = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 3) {
                                                 mlPlayer += players[j]->getBoardName();
                                                 //cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }

		} else if (i == 4) { // Tuition
			tuitionPlayer = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 4) {
                                                 tuitionPlayer += players[j]->getBoardName();
                                                 //cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
		} else if (i == 5) { // MKV
			mkvPlayer = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 5) {
                                                 mkvPlayer += players[j]->getBoardName();
                                                 //cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
		} else if (i == 6) { // ECH
			echPlayer = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 6) {
                                                 echPlayer += players[j]->getBoardName();
                                                 //cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
		} else if (i == 7) { // NEEDLES HALL
			need3Player = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 7) {
                                                 need3Player += players[j]->getBoardName();
                                                 //cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
		} else if (i == 8) { // PAS
			pasPlayer = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 8) {
                                                 pasPlayer += players[j]->getBoardName();
                                                 //cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
		} else if (i == 9) { // HH
			hhPlayer = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 9) {
                                                 hhPlayer += players[j]->getBoardName();
                                         }
                                 }
                         }
		} else if (i == 10) { // DC TIMS LINE
			timsLinePlayer = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 10) {
                                                 timsLinePlayer += players[j]->getBoardName();
                                                 //cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
		} else if (i == 11) { // RCH
			rchPlayer = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 11) {
                                                 rchPlayer += players[j]->getBoardName();
                                                 //cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
		} else if (i == 12) { // PAC
			pacPlayer = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 12) {
                                                 pacPlayer += players[j]->getBoardName();
                //                                 cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
		} else if (i == 13) { // DWE
			dwePlayer = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 13) {
                                                 dwePlayer += players[j]->getBoardName();
                                                 cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
		} else if (i == 14) { // CPH
			cphPlayer = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 14) {
                                                 cphPlayer += players[j]->getBoardName();
                                                 //cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
		} else if (i == 15) { // UWP
			uwpPlayer = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 15) {
                                                 uwpPlayer += players[j]->getBoardName();
                                                 //cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
		} else if (i == 16) { // LHI
			lhiPlayer = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 16) {
                                                 lhiPlayer += players[j]->getBoardName();
                                                 //cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
		} else if (i == 17) { // SLC
			slc3Player = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 17) {
                                                 slc3Player += players[j]->getBoardName();
                                                 //cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
			//	playerMove(slc3Player,numPlayers,players,17);
		} else if (i == 18) { // BMH
			bmhPlayer = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 18) {
                                                 bmhPlayer += players[j]->getBoardName();
                                                 //cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
			//playerMove(bmhPlayer,numPlayers,players,18);
	 	} else if (i == 19) { // OPT
			optPlayer = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 19) {
                                                 optPlayer += players[j]->getBoardName();
                                                 //cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
		//	playerMove(optPlayer,numPlayers,players,19);
		} else if (i == 20) { // GOOSE
			nestPlayer = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 20) {
                                                 nestPlayer += players[j]->getBoardName();
                                                 //cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
			//playerMove(nestPlayer,numPlayers,players,20);
		} else if (i == 21) { // EV1
			ev1Player = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 21) {
                                                 ev1Player += players[j]->getBoardName();
                                                 //cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
			//playerMove(ev1Player,numPlayers,players,21);
		} else if (i == 22) { // NEEDLES HALL
			need1Player = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 22) {
                                                 need1Player += players[j]->getBoardName();
                                                 //cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
			//playerMove(need1Player,numPlayers,players,22);
		} else if (i == 23) { // EV2
			ev2Player = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 23) {
                                                 ev2Player += players[j]->getBoardName();
                          //                       cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
			//playerMove(ev2Player,numPlayers,players,23);
		} else if (i == 24) { // EV3
			ev3Player = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 24) {
                                                 ev3Player += players[j]->getBoardName();
                                                 //cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
			//playerMove(ev3Player,numPlayers,players,24);
		} else if (i == 25) { // V1
			v1Player = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 25) {
                                                 v1Player += players[j]->getBoardName();
                                                 cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
			//playerMove(v1Player,numPlayers,players,25);
		} else if (i == 26) { // PHYS
			physPlayer = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 26) {
                                                 physPlayer += players[j]->getBoardName();
                                                 //cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
			//playerMove(physPlayer,numPlayers,players,26);
		} else if (i == 27) { // B1
			b1Player = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 27) {
                                                 b1Player += players[j]->getBoardName();
                                                 //cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
			//playerMove(b1Player,numPlayers,players,27);
		} else if (i == 28) { // CIF
			cifPlayer = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 28) {
                                                 cifPlayer += players[j]->getBoardName();
                                                 //cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
			//playerMove(cifPlayer,numPlayers,players,28);
		} else if (i == 29) { // B2
			b2Player = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 29) {
                                                 b2Player += players[j]->getBoardName();
                                                 cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
			//playerMove(b2Player,numPlayers,players,29);
		} else if (i == 30) { // GO TO TIMS
			timsPlayer = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 30) {
                                                 timsPlayer += players[j]->getBoardName();
                                                 //cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
			//playerMove(timsPlayer,numPlayers,players,30);
		} else if (i == 31) { // EIT
			eitPlayer = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 31) {
                                                 eitPlayer += players[j]->getBoardName();
                                                 //cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
			//playerMove(eitPlayer,numPlayers,players,31);	
		} else if (i == 32) { // ESC
			escPlayer = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 32) {
                                                 escPlayer += players[j]->getBoardName();
                                                 //cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
			//playerMove(escPlayer,numPlayers,players,32);
		} else if (i == 33) { // SLC
			slc1Player = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 33) {
                                                 slc1Player += players[j]->getBoardName();
                                                 //cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
			//playerMove(slc1Player,numPlayers,players,33);
		} else if (i == 34) { // C2
			c2Player = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 34) {
                                                 c2Player += players[j]->getBoardName();
                                                 //cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
			//playerMove(c2Player,numPlayers,players,34);
		} else if (i == 35) { // REV
			revPlayer = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 35) {
                                                 revPlayer += players[j]->getBoardName();
                                                 //cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
			//playerMove(revPlayer,numPlayers,players,35);
		} else if (i == 36) { // NEEDLES
			need2Player = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 36) {
                                                 need2Player += players[j]->getBoardName();
                                                 //cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
			//playerMove(need2Player,numPlayers,players,36);
		} else if (i == 37) { // MC
			mcPlayer = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 37) {
                                                 mcPlayer += players[j]->getBoardName();
                                                 //cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
			//playerMove(mcPlayer,numPlayers,players,37);
		} else if (i == 38) { // COOP FEE
			coopPlayer = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 38) {
                                                 coopPlayer += players[j]->getBoardName();
                                                 //cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
			//playerMove(coopPlayer,numPlayers,players,38);		
		} else if (i == 39) { // DC
			dcPlayer = "";
			for (int j = 0; j < numPlayers; j++) {
                                 if (players[j] != NULL) {
                                         if (players[j]->getCurrpos() == 39) {
                                                 dcPlayer += players[j]->getBoardName();
                                                 //cout << "String is: " << mlPlayer;
                                         }
                                 }
                         }
		}
	}
}

/*	
for (vector<Ownable *>::iterator it = myproperties.begin(); it < myproperties.end();it++) {
		Academic *a = dynamic_cast<Academic *>(board[it]);

			string owner;
			bool mortgaged;	
			int numimp;
			bool monopoly;	

	 		ifs >> owner;      
                        ifs >> mortgaged;
                        ifs >> numimp;
                        ifs >> monopoly;

			for (int i = 0; i < numbPlayers; i++) {
                                if(players[i]->getPlayername() == a->getOwnerString()) {
                                        (*it)->setOwner(players[i]);
                                }
                        }
	
                        (*it)->setMortgage(mortgaged);
                        a->setNumImp(numimp);
                        a->setMonopoly(monopoly);
	
	}

}
*/
