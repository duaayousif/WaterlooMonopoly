#include <sstream>
#include "board.h"
#include "player.h"
#include "academic.h"
#include "residence.h"
#include "ownable.h"
#include "gym.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;


//Global variables

const int maxPlayers = 8;
Player* players[maxPlayers];
int numPlayers;


int main (int argc, char *argv[]) {

	bool testingmode = 0;
	bool loadmode = 0;
	for (int i = 0; i < maxPlayers; i++){
		players[i] = NULL;
	}

	srand(time(NULL));
	Board *b = b->getInstance();
	Square **squares = b->getBoard();

	string filename;
	if (argc != 1) { // If there is command line arguements, check for load and testing
		for (int i = 1; i < argc; ++i) {
			string s = argv[i];
			if (s == "-testing") {
				testingmode = 1;
			}
		}
		for (int i = 1; i < argc; ++i) {
			string s = argv[i];
			if (s == "-load") {
				loadmode = 1;
				filename = argv[i+1];
				break;
			}
		}

	}
	if (loadmode) {
		//read in number of players	
		ifstream ifs(filename.c_str());
		ifs >> numPlayers;
		for (int i = 0; i < numPlayers; i ++) {
			string name;
			string boardname;
			ifs >> name;
			ifs >> boardname;
			players[i] = new Player(name,boardname);
			int numRollCup;
			ifs >> numRollCup;
			players[i]->setRollcup(numRollCup);
			int money;
			ifs >> money;
			players[i]->loadSetMoney(money);
			int currPos;
			ifs >> currPos;
			players[i]->setPlayerpos(currPos);
			cout << players[i]->getCurrpos() << endl;
			if (currPos == 10) {
				//boolean value that tells u if ur in the line or not
				int tims;
				ifs >> tims;
				if (tims) {
					int howmanyturns;
					ifs >> howmanyturns;
					players[i]->timsSetterLoad(howmanyturns);
				}
			}
			
		}
		// Copying the Players ends here
		string line;

		while (getline(ifs,line)) {
			//get rid of any empty line read in from getline.
			if(line == "") continue;
			stringstream ss(line);
			string buildingname;
			ss >> buildingname;
			string ownerstring;
			ss >> ownerstring;
			int improves;
			ss >> improves;
			
			// Reads in line by line
			// Go through the buildings to find building name, and set the owner to ownerstring 

			for (int i = 0; i < 40; ++i) {

				if (squares[i]->getName() == buildingname) {
					Player *owner;
					for (int j = 0; j < numPlayers; j++) {
						Ownable *o = dynamic_cast<Ownable *>(squares[i]);
						if (o) {
							if (o->getOwner() == NULL) {
								if (players[j]->getPlayername() == ownerstring) {
									owner = players[j];
									o->setOwner(owner);
									o->setOwnerString(ownerstring);
									owner->myproperties.push_back(o);
									Academic *a = dynamic_cast<Academic *> (o);
									Residence *r = dynamic_cast<Residence *>(o);
									Gym *g = dynamic_cast<Gym*>(o);
										if (improves != -1) {
											if (a) {
												a->setNumImp(improves);
											} 
											if (r) {
												players[j]->setResowned();
											}
											if (g) {
												players[j]->setGymsowned();
											}
										}
										//The case where improves = -1, mortgage the building
										else {
											o->setMortgage(1);
										}
								} // closes if player name == ownerstring
						       } // closes if (owner == null)
						} //closes (if ownable)
					}//Closes inner for loop which goes through players
				} //Closes (if buildingname = squares[i]->getName()
			} // Closes the for loop

		} //Closes the while loop	
		//set the monopolies for each person
		for (int i = 0; i < numPlayers; ++i) {
			players[i]->Monopoly();
		}
		//set the improvements of each building
		b->setImprovements();
		cout << "Welcome back to the game!" << endl;
								
	} // Closes if Load
		else {  // Start initializing a new game
			cout << "Welcome to Building Buyer 7000!" << endl;
			cout << "Enter the number of players (2-8): " << endl;
			cin >> numPlayers;
			cout << "Enter the name of each player, followed by the character that will represent the on the board." << endl;
			cout << "Choose from: {Goose G, GRT B, Doughnut D, Professor P, Student S, Money $, Laptop L, Tie T}" << endl;
			int pos = 0;
				while (pos != numPlayers) {
					string name;
					string boardname;
					cin >> name;
					cin >> boardname;
					players[pos] = new Player(name,boardname);
					++pos;
				}
			for (int i = 0; i <numPlayers; ++i) {
				osapPlayer += players[i]->getBoardName();
			}
			cout << "The number of players is: " << numPlayers << endl;
			for (int i = 0; i < numPlayers; ++i) {
				cout << "Player name: " << players[i]->getPlayername() << endl;
				cout << "Player piece: " << players[i]->getBoardName() << endl;
			}

		} //end initializing a new game

	//executes for both loaded game and new game
	b->movePlayer(numPlayers,players);
	b->printBoard();
	int currentplayer = 0;
	string command;
  	
	if (numPlayers > 1) {
		cout << players[currentplayer]->getPlayername() << "s Turn" << endl;
		cout << players[currentplayer]->getPlayername() <<", Enter a command" << endl;
	}

	while (cin >> command) {
			if (command == "roll") {
				if (players[currentplayer]->getAlreadyRolled()) {
					cout << "You've already rolled. Enter a valid command or pass control to next player" << endl;
				}
				else {
					if (testingmode) {
						players[currentplayer]->testingRoll();
						b->getBoard()[players[currentplayer]->getCurrpos()]->getAction(players[currentplayer]);
						b->movePlayer(numPlayers,players);
						b->printBoard();
						players[currentplayer]->setAlreadyRolled();
							
					}
					else {
						players[currentplayer]->roll();
						b->getBoard()[players[currentplayer]->getCurrpos()]->getAction(players[currentplayer]);
						b->movePlayer(numPlayers,players);  
						b->printBoard();
						players[currentplayer]->setAlreadyRolled();
                                          }

				}
			}
			if (command == "next") {	

				// Handles all boundary cases

				players[currentplayer]->setAlreadyRolled();
				if (currentplayer+1 == maxPlayers) {
					currentplayer = 0;
				}
				if (players[currentplayer] == NULL) {
					for (int i = currentplayer; i < maxPlayers; i++) {
				                 
                                               if (players[currentplayer] == NULL) {
                                                      currentplayer++;
                                                       if (i == maxPlayers-1){
                                                            currentplayer = 0;
                                                       }
						}                                                         
                                         }
				}
				 else if (players[currentplayer+1] == NULL) {
					currentplayer++;
					for (int i = currentplayer; i < maxPlayers; i++) {
						if (players[currentplayer] == NULL) {
							currentplayer++;
							if (i == maxPlayers-1) {
								currentplayer = 0;
							}
						}
					}
				} 
				else {
					currentplayer++;
				}

			}
			if (command == "assets") {
				players[currentplayer]->assets();
			}
			if (command == "improve") {

				//cout << "Reached improve" << endl;
				string building;
				cin >> building;
				string decision;
				cin >> decision;
				players[currentplayer]->improve(building,decision);
			}
			if (command == "trade") {
				string name;
				cin >> name;
				string give;
				string recieve;
				cin >> give;
				cin >> recieve;
				cout << "GIVE IS " <<give<< "RECIEVE IS: " <<recieve<< "NAME IS : "<< name <<endl;
				//find the player(fix for when players lose)
				Player *tradepartner;
				for (int i = 0; i < numPlayers; ++i) {
					if (name == players[i]->getPlayername()) {
						tradepartner = players[i];
						break;
					}
				}
				cout << "TRADE PARTNER IS: " << tradepartner->getPlayername() << endl;
				players[currentplayer]->trade(tradepartner,give,recieve);
			}
			if (command == "mortgage") {
				string prop;
				cin >> prop;
				for (int i = 0; i < 40; ++i) {
					Ownable *o = dynamic_cast<Ownable*>(b->getBoard()[i]);
					if ((b->getBoard()[i]->getName()) == prop) {
						if (o) {
							o->Mortgage();
						}
					}
				}
			}
			if (command == "unmortgage") {
				string prop;
				cin >> prop;
				for (int i = 0; i < 40; ++i) {
					Ownable *o = dynamic_cast<Ownable*>(b->getBoard()[i]);
					if (b->getBoard()[i]->getName() == prop) {
						if (o) {
							o->unMortgage();
						}
					}
				}
			}
			if (command == "bankrupt") {
				// see if where they currently at is an ownable building or unownable to c if they were bankrupt by bank or other player
				Ownable *o = dynamic_cast<Ownable *> (squares[players[currentplayer]->getCurrpos()]);

				if (o) {
					players[currentplayer]->bankrupt(o->getOwner());
				}
				else {
					players[currentplayer]->bankrupt();
				}
				--numPlayers;
				players[currentplayer] = NULL;
			}
			if (command == "quit") {
				cout << "Thanks for playing!" << endl;
				for (int i = 0; i < maxPlayers; i++) {
					if (players[i] != NULL) {
						delete players[i];	
					}
				}
			// Board is deleted at exit
				
				return 0;
			}
			if (command == "save") {
				string filename;
				cout << "Enter a file name" << endl;
				cin >> filename;
				b->save(filename,numPlayers,players);
				for (int i = 0; i < maxPlayers; ++i) {
					if (players[i] != NULL) {
						delete players[i];	
					}
				}
				return 0;
			}
		 

		if(numPlayers>1) {
			cout << players[currentplayer]->getPlayername() <<", Enter a command" << endl;
		} 
	}

	// only reach here when theres one players left a winner 
	string winner;
	
	// Find who the winner is
	for (int i = 0; i < maxPlayers; ++i) {
		if (players[i] != NULL) {
			winner = players[i]->getPlayername();
			delete players[i];
			break;
		}
	}
	cout << winner << " is the winner! Thanks for playing" << endl;

}
