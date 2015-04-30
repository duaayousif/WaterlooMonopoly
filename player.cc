#include <iostream>
#include <vector>
#include <string>
#include "board.h"
#include "square.h"
#include "player.h"
#include "ownable.h"
#include "academic.h"
#include "residence.h"
#include "gym.h"
#include <cstdlib>
#include <sstream>

using namespace std;


Player::Player(string name,string boardname) : name(name), boardname(boardname), myproperties(vector<Ownable*> ()),withdraw(0),owing(0),alreadyrolled(0),timsline(-1),money(1500),gymsowned(0),resowned(0),currpos(0),rollup(0) {
		 boardinstance = boardinstance->getInstance();
}

//the number of buildings in each monopoly

const int arts1Max = 2;
const int arts2Max = 3;
const int engMax = 3;
const int healthMax = 3;
const int envMax = 3;
const int sci1Max =3;
const int sci2Max = 3;
const int mathMax = 2;

//The different monopolies 
string arts1Monopoly[2] = {"AL","ML"};
string arts2Monopoly[3] = {"ECH","PAS","HH"};
string engMonopoly[3] = {"RCH","DWE","CPH"};
string healthMonopoly[3] = {"LHI","BMH","OPT"};
string envMonopoly[3] = {"EV1","EV2","EV3"};
string sci1Monopoly[3] = {"PHYS","B1","B2"};
string sci2Monopoly[3] = {"EIT","ESC","C2"};
string mathMonopoly[2] = {"MC","DC"};

Player::~Player() { }//no they point to the board

//roll a single dice helper
int randomdice() {
	return rand() % 6 + 1;
}

int Player::getRollUp() {
	return rollup;
}
//returns true if rolls doubles, false otherwise
bool isdoubles(int first, int second) {
	bool isdub = 0;
	if (first == second) {
		isdub = 1;
	}
	return isdub;
}


vector<Ownable *> Player::getMyproperties() {
	return myproperties;
}

void Player::loadSetMoney(int change) {
	
	money = change;	

}

int Player::getMoney() {
	return money;
}



void Player::setMoney(int change) {
//	cout << "ENTERED SET MONEY FXN" << endl;
	money += change;
}

string Player::getPlayername() {
	return name;
}

string Player::getBoardName() {
	return boardname;
}

bool Player::getAlreadyRolled() {
	return alreadyrolled;
}

void Player::setAlreadyRolled(){
	if (alreadyrolled == 0) {
		alreadyrolled = 1;
	}
	else {
		alreadyrolled = 0;
	}
}

int Player::getCurrpos() {
	return currpos;
}

void Player::setPlayerpos(int playerPos) {
	currpos = playerPos;
}

void Player::setCurrpos(int move) {
	Square **board = boardinstance->getBoard();
	//If the landed on GO TO TIMS ( they also dont collect $200 from osap)
	if (move+currpos == 30) {
		cout << "You landed on GO TO TIMS" << endl;
		setTotims();
		return;
	}
	else {	
		if (currpos + move >= 40) {
		//they pass Collect OSAP square, collect $200, move to appropriate position
			setMoney(200);
			int x = 40 - currpos;
			int newpos = move - x;
			currpos = newpos;
			cout << "You landed on " << board[currpos]->getName() << endl;
			cout << name << " passed GO. Collect $200 " << endl;
//			cout << getPlayername() << " landed on " << theboard[getCurrpos()]->getName();
		}
		else if (currpos + move == 0) {
		//so they can collect 200 if they move back two spaces to OSAP
			setToosap();
		}
		else {
		// if we can just add normally, (player does not pass Collect OSAP
			currpos+=move;
			cout << name << " has landed on " << board[currpos]->getName() << endl;
			//Ownable *o = dynamic_cast<Ownable *>(board[currpos]);
		}
	}
	
}

void Player::setTotims() {
	currpos = 10;
	timsline = 0;
	cout << name << " is in the tims line!" << endl;
}

void Player::setToosap() {
	//Collects 200 (not handled in the setCurrpos function for this case)
	cout << name << " can collect $200" << endl;
	setMoney(200);
	currpos = 0;
}

void Player::addRollcup() {
	++rollup;
	
}

void Player::useRollcup() {
	if (rollup > 0 && rollup <= 4) {		
		--rollup;
	cout << "You are out of the Tims line! You've used 1 roll up the rim cup. You have " << rollup << " cups left." << endl;
	setTimsline(-1);
	}
	else {
		cout << "You dont have any roll up the rim cups to use" << endl;
	}
}

void Player::setRollcup(int rollcup) {
	rollup = rollcup;
}

int Player::getResowned() {
	return resowned;
}

void Player::setResowned() {
	++resowned;
}

void Player::minusResowned() {
	--resowned;
}

int Player::getGymsowned() { 
	return gymsowned;
}

void Player::setGymsowned() {
	++gymsowned;
}

void Player::minusGymsowned() {
	--gymsowned;
}

int Player::getTimsline() {
	return timsline;
}
void Player::timsSetterLoad(int num) {
	timsline = num;
}

void Player::setTimsline(int x) {
	if (x == 1) {
		//add one to the number of times player is in tims line
		timsline++;
	}
	//set back to -1, the player left the tims line
	else if (x == -1) {
		timsline = -1;
	}
}

void Player::paytims() {
	setMoney(-50);
	setTimsline(-1);
}
/*
int Player::getNumdoubles() {
	return numdoubles;
}*/


void Player::setWithdraw(bool x) {
	withdraw = x;
}

bool Player::getWithdraw() {
	return withdraw;
}

//x can only be 0 or 1 (add 1 or reset back to 0)
/*void Player::setNumdoubles(int x) {
	if (x==0) {
		numdoubles = 0;
	}
	else {
		numdoubles++;
	}
}*/
	
void Player::roll() {
	//Square ** theboard = boardinstance->getBoard();
	int line = getTimsline();
	if (line == 0 || line == 1) {
		cout << "You're in the tims line, you can either roll doubles, pay $50 or use a roll up the Rim cup. Choose from (roll,pay,cup)." << endl;
		string command;
		cin >> command;
		if (command == "roll") {
			cout << "Roll two dice" << endl;
			int first = randomdice();
			int second = randomdice();
			if (isdoubles(first,second)) {
				cout << "Congrats! You've rolled doubles. You are no longer in the Tims line!" << endl;
				setTimsline(-1);
			}
			else {	
				cout << "You didnt roll doubles, better luck next time!" << endl;
				// add one to the number of turns in the tims line the player has
				setTimsline(1);
			}
		}
		else if (command == "pay") {
			cout << "You have $" << money << " before paying to get out of Tims line. " << endl;
			paytims();
			cout << "You are out of the Tims line. " << "You now have $" << money << " left." << endl;
		}
		else if (command == "cup") {
			// useRollcup() will also make sure that they have one to use
			useRollcup();
		}
	}
	else if (line == 2) {
		cout << "It's you're third turn in the Tims line. You can either roll doubles, pay $50 or use a roll up the Rim cup. ";
		cout << "If you dont roll doubles, you must pay or use a roll up cup. Choose from (roll,pay,cup)" << endl;
		string command;
		cin >> command;
		if (command == "roll" ) {
			int first = randomdice();
			int second = randomdice();
			cout << "Roll two dice" << endl;
			if (isdoubles(first,second)) {
				cout << "Congrats, you've rolled doubles. You are no longer in the Tims line!" << endl;
				setTimsline(-1);
			}
			else {
				string action;
				cout << "You didnt roll doubles, you must pay $50 or use a roll up the Rim cup. Choose (pay,cup)" << endl;
				cin >> action;
				if (action == "pay") {
					cout << "You have $" << money << " before paying to get out of Tims line. " << endl;
					paytims();
					cout << "You are out of the Tims line. " << "You now have $" << money << " left." << endl;
				}
				else if (action == "cup") {
					useRollcup();
				}
				setCurrpos(first+second);
				
			}
		}
		else if (command == "pay") {
			cout << "You have $" << money << " before paying to get out of Tims line. " << endl;
                        paytims();
                        cout << "You are out of the Tims line. " << "You now have $" << money << " left." << endl;
		}
		else if (command == "cup") {
			useRollcup();
		}
	}
	//the player isnt in the tims line
	else {
		string prompt; //(should be roll)
		cout << "It's " << getPlayername() << "s turn. Roll the dice!" << endl;
		int first = randomdice();
		int sec = randomdice();
		cout << "Rolled: " << first << " and " << sec << endl;	
		if (first == sec) {
			cout << "You rolled doubles! Roll again" << endl;
			cin >> prompt; //(should be roll)
			if (prompt != "roll") {
				cout << "Invalid command, you need to roll again" << endl;
			}
			int first2 = randomdice();
			int sec2 = randomdice();
			if (first2 == sec2) {
				cout << "Rolled: " << first2 << " and " << sec2 << endl;
				cout << "You've rolled doubles again! Roll again" << endl;
				cin >> prompt; //(should be roll )
				if (prompt != "roll") {
					cout << " Invalid command, you need to roll again" << endl;
				}
				int first3 = randomdice();
				int sec3 = randomdice();
				if (first3==sec3) {	
					cout << "Rolled: " << first3 << " and " << sec3 << endl;
					cout << "It's your third time rolling doubles, Go to the tims line!" << endl;
					setTimsline(1);
				}
				else {
					cout << "Phew! You didn't roll doubles for the 3rd time." << endl;
					setCurrpos(first3+sec3);
					//theboard[getCurrpos()]->getAction(this);
				}
			}
			else {
				cout << "Rolled: " << first2 << " and " <<sec2;
				setCurrpos(first2+sec2);
//			cout << "right before get position after 1 = roll" << endl;
//				theboard[getCurrpos()]->getAction(this);
			}
		}
		else {	
//			cout << "reached right before set current position" << "players current pos: " << getCurrpos() << endl;
			setCurrpos(first+sec);
//			cout << "going to get action" << endl;
			//theboard[getCurrpos()]->getAction(this);
		}
	}
}
	
											
int Player::getTotalworth() {
	int sum = money;
	for (vector<Ownable *>::iterator it = myproperties.begin(); it < myproperties.end();it++) {
		sum += (*it)->getCost();
		Academic *a = dynamic_cast<Academic *>(*it);
		//If its an academic building(so not a gym or a residence), add cost of improvements
		if (a) {
			int totalimp = a->getNumImp();
			int improvementcost = a->getImpCost();
			sum += (totalimp * improvementcost);
		}
	}
	return sum;
}


void Player::improve(string building, string decision) {
//	cout << "Entered improve in player" << endl;
	for (vector<Ownable *>::iterator it = myproperties.begin(); it < myproperties.end();it++) {
		if ((*it)->getName() == building) {
		 Academic *a = dynamic_cast<Academic *>(*it);
			if (a) { 
//				cout << "passed if a" << endl;
				if(a->getMonopoly() && a->getOwner() == this) {
                			if (decision == "buy") {
//						cout << "entered buy in improve in player" << endl;
                       				setMoney(-1*(a->getImpCost()));
                       				a->incNumImp();
						boardinstance->setImprovements();
                				} 
					else if (decision == "sell") {
                       				setMoney((a->getImpCost())/2);
                       				a->decNumImp();
						boardinstance->setImprovements();
                			}
					boardinstance->printBoard();
				}
				else {
                			cout << "Sorry you don't own all the buildings of this monopoly yet." << endl;
        			}
			}	
		
			else { 
				cout << "Cant improve a non academic building!" << endl;
			}
		} 
			
	}
}	
	
void Player::buy(Square *property) {
	//Check if its already owned
	Ownable *o = dynamic_cast<Ownable *>(property);
	if (!o) {
		cout << "This property cannot be purchased" <<endl;
	} 
	else {
		if (o->getOwner() == this) {
			cout << "You already own this property" << endl;
		}
		else if (o->getOwner() != NULL) {
			cout << "This property is already owned! " << endl;
		}
		else {
			//add the property to the players building, and set them as the owner
			myproperties.push_back(o);

			//cout << "OWNER IS: " << o->getOwnerString(); << endl;
			o->setOwner(this);
			//cout << "THIS
			o->setOwnerString(name);
			cout << name << " now owns " << property->getName() << endl;
			//Check if its a gym or a residence so you can add to the count
			Gym *g = dynamic_cast<Gym *>(property);
			Residence *r = dynamic_cast<Residence *>(property);
			if (r) {
				++resowned;
			}
			if (g) {
				++gymsowned;
			}
			setMoney(-1 * o->getCost());
		}	
	}
}


/*void Player::Auction(int Currnumplayers) {*/
	

//Bankrupt to bank//AUCTION PART ?? 
void Player::bankrupt() {
	for(vector<Ownable *>::iterator it = myproperties.begin(); it < myproperties.end();it++) {
		(*it)->setOwner(NULL);
		(*it)->setOwnerString("");
		(*it)->setMortgage(0);
		Academic *a = dynamic_cast<Academic *>(*it);
		if (a) {
			a->setNumImp(0);
			a->setMonopoly(0);
		}
	}
	//destroy all roll up cups
	for (int i = 0 ; i < rollup; ++i) {
		boardinstance->minusTotalcup();
	}
}
	


//Bankrupt to a player, has to pay a player rent but doesnt have it
void Player::bankrupt(Player *player) {
	//dont need this part (this command is only available wen someone actually goes bankrupt
	/*Board *theboard = boardinstance->getInstance();
	int before = getMoney();
	int worth = getTotalworth();
	Square ** b = theboard->getBoard();
	b[getCurrpos()]->getAction(this);
	int diff = before-getMoney();
	bool bankrupt = 0;
	if (worth < diff) {
		bankrupt = 1;
	} else {
		bankrupt = 0;
	}
	//give all you buildings to the person you owe money to
	*/

	//Move all the buildings of the bankrupt player to the player they own money to, reset the owner
	for(vector<Ownable *>::iterator it = myproperties.begin(); it < myproperties.end();it++) {
		//accept will set the owner to the player
		accept(player,0,(*it)->getName());
		//for each building that was mortgaged, player pays 10% its cost
		if ((*it)->getMortgaged()) {
			player->setMoney(-0.10 * ((*it)->getCost()/2));
		}
	}
	//player inherits banrupt player roll up cups
	for (int i = 0 ; i < rollup; ++i) {
		player->addRollcup();
	}

	// in main set the player to null
}
	
	




void Player::assets() {

	cout << name << "s current assets: " << endl;
	cout << "Current savings: " << getMoney() << endl;
	cout << "Buildings owned: " << myproperties.size() << endl;
	for (vector<Ownable *>::iterator it = myproperties.begin(); it < myproperties.end();it++) {
        	 	//cout << (*it)->getName() << endl;
			//Check which type of building it is, then you can customize the things you want to show the player; (num res they own, how many improv);
			Academic *a = dynamic_cast<Academic *>(*it);
			Residence *r = dynamic_cast<Residence *>(*it);
			Gym *g = dynamic_cast<Gym *>(*it);
			if (a) {
				cout << "Building name: " << a->getName() << endl;
				bool mort = a->getMortgaged();
				if (mort) {
					cout << "Mortgaged" << endl;
				}
				else {
					cout << "Not mortgaged" << endl;
				}
				//If the player owns all the buildings in that monopoly , print the number of improvements
				if (a->getMonopoly() == 1) {
					cout << "Monopoly owned" << endl;
					cout << "Number of improvements: " << a->getNumImp() << endl;
				}
			}
			else if (r) {
				cout << "Building name: " << r->getName() << endl;
				bool mort = r->getMortgaged();
				if (mort) {
					cout << "Mortgaged" << endl;
				} else {
					cout << "Not mortgaged" << endl;
				}
								
			}
			else if (g) {
				cout << "Building name: " << g->getName() << endl;
			}
	}
			cout << "Numer of residences owned: " << resowned << endl;
			cout << "Number of gyms owned: " << gymsowned << endl;
}

		



vector<Ownable *>::iterator Player::findOwnableProperties(vector<Ownable *>::iterator propertiesIt, vector<Ownable *>::iterator end, string name){
        for( ; propertiesIt != end ; propertiesIt++){
           if ((*propertiesIt)->getName() == name) {
              return propertiesIt;
           }
        }
        return propertiesIt; //(ERROR? for return null)
    }
	
	//	tMoney(-1*a);
bool Player::CanTrade(Player* player,Ownable *o) {

//	cout << "STARTS CAN TRADE " << endl;
	bool istradable = 1;
	Academic *a = dynamic_cast<Academic*>(o);
	string BlockToFind;
	if (a) {
		BlockToFind = a->getBlock();
	}
	else {
		return istradable;
	}
	if (a) {
		if (a->getMonopoly()) {
			for(vector<Ownable*>::iterator it = player->myproperties.begin(); it < player->myproperties.end(); it++) {
				Academic *isacd = dynamic_cast<Academic*>(*it);
				if (isacd) {
					if (isacd->getBlock() == BlockToFind) {

						cout << "BLOCK : " << BlockToFind;
						if (isacd->getNumImp() != 0) {
							istradable = 0;
							cout << "Must sell improvements on all buildings of a monopoly before trade. " << endl;
							break;
						}
					}
				}
			}
		}
	}

//	cout << "IS TRADABLE IS: " << istradable << endl;
	return istradable;
}
				

void Player::accept(Player *other, string give, string receive) {


	stringstream ss(give);
	stringstream bb(receive);
	int a;
	int b;

	

	if(ss >> a) {
		// Offering money for building
		vector<Ownable* >::iterator position = findOwnableProperties(other->myproperties.begin(), other->myproperties.end(), receive);
		//Make sure that the building ur recieving doesnt have improvements or non of buildings in its block have improvements
		if (CanTrade(other,(*position))) {
			(*position)->setOwner(this);
			(*position)->setOwnerString(name);
			myproperties.push_back(*position);
			other->myproperties.erase(position);
			setMoney(-1*a);
			other->setMoney(a);
			Residence* r = dynamic_cast<Residence *>(*position);
			Gym* g = dynamic_cast<Gym *>(*position);
			if (r) {
				++resowned;
				other->minusResowned();
			}
			if (g) {
				++gymsowned;
				other->minusGymsowned();
			}

			cout << getPlayername() << " has traded $" << a << " for " << receive << " with " << other->getPlayername() <<endl;
		}
	}
	else if (bb >> b) {
		//Offering building fo some green
		vector<Ownable* >::iterator position = findOwnableProperties(myproperties.begin(), myproperties.end(), give);
		//Make sure the building or any of the buildings in its block dont have improvements
		if (CanTrade(this,(*position))) {
			(*position)->setOwner(other);
			(*position)->setOwnerString(other->getPlayername());
			other->myproperties.push_back(*position);
			myproperties.erase(position);
			setMoney(b);
			other->setMoney(-1*b);
			Residence* r = dynamic_cast<Residence *>(*position);
                        Gym* g = dynamic_cast<Gym *>(*position);
                        if (r) {
                                --resowned;
                                other->setResowned();
                        }
                        if (g) {
                                --gymsowned;
                                other->setGymsowned();
                        }
			

			cout << getPlayername() << " has traded " << give << " for $" << receive << " with " << other->getPlayername() << endl;
		}
	}
	else {	//Offering building for building
                vector<Ownable* >::iterator position = findOwnableProperties(myproperties.begin(), myproperties.end(), give);
		vector<Ownable* >::iterator otherpos = findOwnableProperties(other->myproperties.begin(), other->myproperties.end(), receive);
//		cout << "REACHES BEFORE CAN TRADE" <<endl;
		//Ownable * mytemp = *position;
		//Ownable * othertemp = *otherpos;
		
	//	Academic *aaa = dynamic_cast<Academic *>(mytemp);
	//	Academic *aaaa = dynamic_cast<Academic *>(othertemp);
	//	int cantrade1 = 0;
	//	int cantrade2 = 0
	//	if (aaa) {
	
		if ((CanTrade(this,(*position))) && (CanTrade(other,(*otherpos)))) {

			//cout << "After if" << endl;
			//Ownable *pos1 = *position;
			Ownable *pos2 = *otherpos;
			//cout << "AFTER POS1 = ... " << endl;
			Residence* r = dynamic_cast<Residence *>(*position);
                        Gym* g = dynamic_cast<Gym *>(*position);
			//cout << "AFTER DYNAMIC CASTS 1" <<endl;
                        if (r) {
                                --resowned;
                                other->setResowned();
                        }
                        if (g) {
                                --gymsowned;
                                other->setGymsowned();
                        }


			Residence* rr = dynamic_cast<Residence *>(*otherpos);
                        Gym* gg = dynamic_cast<Gym *>(*otherpos);

			//cout << "AFTER DYNAMIC CASTS 2 " << endl;
                        if (rr) {
                                ++resowned;
                                other->minusResowned();
                        }
                        if (gg) {
                                ++gymsowned;
                                other->minusGymsowned();
                        }

			


			//cout << "REACHES THIS " << endl;
			//cout << ((*position)->getOwner)->getPlayername();
			(*position)->setOwner(other);
			//cout << "REACHES THIS 1" << endl;

			(*position)->setOwnerString(other->getPlayername());
			//cout << "REACHES THIS 2" << endl;
                	other->myproperties.push_back(*position);
			//cout << "REACHES THIS 3" << endl;
                	myproperties.erase(position);
			
			//cout << "REACHES THIS 4" << endl;
//			(*otherpos)->setOwner(this);
			pos2->setOwner(this);
			//cout << "REACHES THIS 5" << endl;
//			(*otherpos)->setOwnerString(name);
			pos2->setOwnerString(name);
			//cout << "REACHES THIS 6" << endl;



			myproperties.push_back(pos2);

		         vector<Ownable* >::iterator otherpostemp = findOwnableProperties(other->myproperties.begin(), other->myproperties.end(), receive);
                	other->myproperties.erase(otherpostemp);
			//cout << "REACHES THIS 7" << endl;


			cout << getPlayername() << " has traded " << give << " for " << receive << " with " << other->getPlayername() << endl;
		}
	}
}



void Player::trade(Player *other, string give, string receive) {

	cout << getPlayername() << " wants to trade " << give << " for " << receive << " with " << other->getPlayername() << ". Choose (accept,reject)" << endl;
	/////	check if person actually has the building and stufff	
	string answer;
	cin >> answer;
	if (answer == "accept") {
		
		accept(other,give,receive);
	
	} else if (answer == "reject") {
		
		cout << "naw b" << endl;
	
	}
}

void Player::Monopoly() {
  
  //        cout << "ENTERED MONOPOLY in player.cc" << endl;
          int arts1 = 0;
          int arts2 = 0;
          int eng = 0;
          int health = 0;
          int env = 0;
          int sci1 = 0;
          int sci2 = 0;
          int math = 0;
  
         //Check how many buildings the player has from each block
         for (vector<Ownable *>::iterator it = myproperties.begin(); it < myproperties.end();it++) {
                 Academic *a = dynamic_cast<Academic *> (*it);
                 //cout << "BLOCK IS : " << a->getBlock();
                 if (a) {
                         string block = a->getBlock();
                         if (block == "Arts1") {
//			cout << "reached if block = arts1" << endl;
                                 ++arts1;
                         }
                         else if (block == "Arts2") {
                                 ++arts2;
                         }
                         else if (block == "Eng") {
  //                       cout << "REACHED IF BLOCK = Eng " << endl;
                                 ++eng;
                         }
                         else if (block == "Health") {
                                 ++health;
                         }
                         else if (block == "Env") {
                                 ++env;
                         }
                         else if (block == "Sci1") {
                                 ++sci1;
                         }
                         else if (block == "Sci2") {
                                 ++sci2;
                         }
                         else if (block == "Math") {
                                 ++math;
                         }
		}
	}
        	Square ** b = boardinstance->getBoard();
         //now you have how many of each block the player has, compare against the length of array for that block.
         	for (int i = 0; i < 40; ++i) {
                	 Academic *a = dynamic_cast<Academic *> (b[i]);
                 	if (a) {
                        	 if (arts1 == arts1Max) {
                     //           	 cout << "Reaches art1==arts1max" << endl;
                                	 if (a->getBlock() == "Arts1") {
                                        	 a->setMonopoly(1);
                                	 }
                                 	else {
                                       		 a->setMonopoly(0);
                                 	}
                         	}
                        	 if (arts2 == arts2Max) {
                                	 if (a->getBlock() == "Arts2") {
                                        	 a->setMonopoly(1);
                                 	}
                                 	else {
                                        	 a->setMonopoly(0);
                                 	}
                         	}
                         	if (eng == engMax) {
                                	 if (a->getBlock() == "Eng") {
                                        	 a->setMonopoly(1);
                                 	}
                                 	else {
                                        	a->setMonopoly(0);
                                 	}
                         	}
                         	if (health == healthMax) {
                                	 if (a->getBlock() == "Health") {
                                        	 a->setMonopoly(1);
                                 	}
                                 	else {
                                        	a->setMonopoly(0);
                                 	}
                         	}
                         	if (env == envMax) {
                                	if (a->getBlock() == "Env") {
                                        	 a->setMonopoly(1);
                                 	}
                                	else {
                                        	a->setMonopoly(0);
                                	}
                         	}
                         	if (sci1 == sci1Max) {
                                 	if (a->getBlock() == "Sci1") {
                                         	a->setMonopoly(1);
                                 	}
                                 	else {
                                        	a->setMonopoly(0);
                                 	}
                        	 }	
                        	 if (sci2 == sci2Max) {
                                	 if (a->getBlock() == "Sci2") {
                                        	 a->setMonopoly(1);
                                 	 }
                                 	else {
                                        	a->setMonopoly(0);
                                 	}
                         	}	
                         	if (math == mathMax) {
                                	if (a->getBlock() == "Math") {
                                        	 a->setMonopoly(1);
                                 	}
                                 	else {
                                       	 	a->setMonopoly(0);
                                 	}
                         	}
			}
		}
	}








//SAME ROLLING FUNCTION, but values are inputted from stdin

void Player::testingRoll(){
//        Square ** theboard = boardinstance->getBoard();
         int line = getTimsline();
         if (line == 0 || line == 1) {
                 cout << "You're in the tims line, you can either roll doubles, pay $50 or use a roll up the Rim cup. Choose from (roll,pay,cup)." << endl;
                 string command;
                 cin >> command;
                 if (command == "roll") {
                         cout << "Roll two dice" << endl;
                         int first;
                         int second;
			//for testing read values from cin
			 cin >> first >> second;
                         if (isdoubles(first,second)) {
                                 cout << "Congrats! You've rolled doubles. You are no longer in the Tims line!" << endl;
                                 setTimsline(-1);
                         }
                         else {
                                 cout << "You didnt roll doubles, better luck next time!" << endl;
                                 // add one to the number of turns in the tims line the player has
                                 setTimsline(1);
                         }
                 }
                 else if (command == "pay") {
                         cout << "You have $" << money << " before paying to get out of Tims line. " << endl;
                         paytims();
                         cout << "You are out of the Tims line. " << "You now have $" << money << " left." << endl;
                 }
                 else if (command == "cup") {
                          useRollcup(); // will also make sure that they have one to use
		}
	}
         else if (line == 2) {
                 cout << "It's you're third turn in the Tims line. You can either roll doubles, pay $50 or use a roll up the Rim cup. ";
                 cout << "If you dont roll doubles, you must pay or use a roll up cup. Choose from (roll,pay,cup)" << endl;
                 string command;
                 cin >> command;
                 if (command == "roll" ) {
                         int first;
                         int second;
			 cin >> first >> second;
                         cout << "Roll two dice" << endl;
                         if (isdoubles(first,second)) {
                                 cout << "Congrats, you've rolled doubles. You are no longer in the Tims line!" << endl;
                                 setTimsline(-1);
                         }
                         else {
                                 string action;
                                 cout << "You didnt roll doubles, you must pay $50 or use a roll up the Rim cup. Choose (pay,cup)" << endl;
                                 cin >> action;
                                 if (action == "pay") {
                                         cout << "You have $" << money << " before paying to get out of Tims line. " << endl;
                                         paytims();
                                         cout << "You are out of the Tims line. " << "You now have $" << money << " left." << endl;
                                 }
                                 else if (action == "cup") {
                                         useRollcup();
					cout << "You are out of the tims line." << endl;
                                 }
                                 //move the sum of the dice of last attempt to roll doubles
                                 setCurrpos(first+second);
      //                           theboard[getCurrpos()]->getAction(this);
 
                         }
                 }
                 else if (command == "pay") {
                         cout << "You have $" << money << " before paying to get out of Tims line. " << endl;
                         paytims();
                         cout << "You are out of the Tims line. " << "You now have $" << money << " left." << endl;
                 }
                 else if (command == "cup") {
                         useRollcup();
                 }
         }
         else {
                 string prompt; //(should be roll)
                 cout << "It's " << getPlayername() << "s turn. Roll the dice!" << endl;
                 int first;
                 int sec;
		 cin >> first >> sec;
                 cout << "Rolled: " << first << " and " << sec << endl;
                 if (isdoubles(first,sec)) {
                         cout << "You rolled doubles! Roll again" << endl;
                         cin >> prompt; //(should be roll)
                         if (prompt != "roll") {
                                 cout << "Invalid command, you need to roll again" << endl;
                         }
                         //setNumdoubles(1);
			cout << "second roll afer first set of doubles" << endl;
                         int first2;
                         int sec2;
			 cin >> first2 >> sec2;
                         if (isdoubles(first2,sec2)) {
                                 cout << "Rolled: " << first2 << " and " << sec2 << endl;
                                 cout << "You've rolled doubles again! Roll again" << endl;
                                 cin >> prompt; //(should be roll )
                                 //if (prompt != "roll") {
                                  //       cout << " Invalid command, you need to roll again" << endl;
                                 //}
  //                               setNumdoubles(1);
                                 int first3;
                                 int sec3;
				 cin >> first3 >> sec3;
                                 if (isdoubles(first3,sec3)) {
                                         cout << "Rolled: " << first3 << " and " << sec3 << endl;
                                         cout << "It's your third time rolling doubles, Go to the tims line!" << endl;
                                         //setNumdoubles(1);
                                         setTotims();
					 setTimsline(1);
                                 }
                                 else {
                                         cout << "Phew! You didn't roll doubles for the 3rd time." << endl;
                                         setCurrpos(first3+sec3);
    //                                     theboard[getCurrpos()]->getAction(this);
                                 }
                         }
                         else {
                                 cout << "Rolled: " << first2 << " and " <<sec2;
                                 setCurrpos(first2+sec2);
  //                               theboard[getCurrpos()]->getAction(this);
                         }
                 }
                 else {
  //                     cout << "reached right before set current position" << "players current pos: " << getCurrpos() << endl;
                         setCurrpos(first+sec);
//	cout << "right before getaction end of roll" << endl;
//			theboard[getCurrpos()]->getAction(this);
                 }
         } 
//         setNumdoubles(0);
 }




//assume want to delete first academic
/*
int Player::getTotalworth() {
	Academic *a = NULL;
	for (vector<Ownable *>::iterator it = myproperties.begin(); it < myproperties.end();it++) {
		*a = dynamic_cast<Academic *>(*it);
		if (a) {
 			break;
		}
	}
        if(a) { myproperties.erase(a); }
}*/


		
	

	
