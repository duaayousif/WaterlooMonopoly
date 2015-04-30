#ifndef __PLAYER_H__
#define  __PLAYER_H__
#include <vector>
#include "square.h"
#include <string>
#include "ownable.h"
#include "board.h"

class Ownable;

class Player {

	//Name of player
	std::string name;
	//Representation of player on the board
	std::string boardname;
	//Pointer to an array of all the ownable properties the player owns
	//std::vector<Ownable *> myproperties;
	//set to 0 if person is still in auction, set to 1 if they withdraw
	int withdraw;
	//amount player owes
	int owing;
	int alreadyrolled;
	int timsline;
	//Total money the player currently has
	int money;
	//Number of gyms the player owns
	int gymsowned;
	//Number of residences the player owns
	int resowned;
	int currpos;
	int rollup;
	
	public:
	Board *boardinstance;
	//Pointer to an array of all the ownable properties the player owns
        std::vector<Ownable *> myproperties;
	//Constructor
        Player(std::string name, std::string boardname);
        //Destructor
        ~Player();
	//Method to that moves the position of the player(updates currpos)
	std::string getPlayername();//
	std::vector<Ownable *> getMyproperties();
	std::string getBoardName();//
	int getMoney();//
	void loadSetMoney(int change);
	void setMoney(int change);//
	int getCurrpos();//
	//updates currpos to currpos + move
	void setCurrpos(int move);//
	void setTotims();//
	void timsSetterLoad(int num);
	void setToosap();//
	void addRollcup();//
	void useRollcup();//
	void setRollcup(int rollcup);
	int getTotalworth();//
	int getGymsowned();//
	void setGymsowned();//
	void minusResowned();
	int getResowned();//
	void setResowned();//
	void minusGymsowned();
	int getTimsline();//
	int getRollUp();
	//Probably wont need next 2 variables, delete them at the end if we dont use them
	//int getNumdoubles();//
	//void setNumdoubles(int x);//
	bool getAlreadyRolled();
	void setAlreadyRolled();
	// if x = 1, add 1 to the number of times player is in the tims line, if 0, reset back to 0 (not in tims line)
	void setTimsline(int x);//
	void buy(Square *property);//
	void Monopoly();
	void roll();//
	void paytims();//
	void improve(std::string building,std::string decision);//
	void bankrupt();
	void bankrupt(Player *player);
	void testingRoll();
	void setWithdraw(bool x);
	bool getWithdraw();
	bool CanTrade(Player* player,Ownable *o);
	std::vector<Ownable *>::iterator findOwnableProperties(std::vector<Ownable *>::iterator propertiesIt, std::vector<Ownable *>::iterator end, std::string name);
	void accept(Player *other, std::string give, std::string receive);
	void trade(Player *other, std::string give, std::string receive);
	void assets();	
	void setPlayerpos(int playerPos);
};

#endif
