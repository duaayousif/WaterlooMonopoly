#ifndef __OWNABLE_H__

#define __OWNABLE_H__

#include "square.h"
#include <string>
#include "player.h"

class Ownable : public Square {

	protected:

	int cost;
	bool mortgaged;
	std::string owner;
//	bool bought;
	Player *propertyowner;
	public:
	int getCost();
	bool getMortgaged();
	//bool getBought();
	//Player * getOwner();	
	void setOwner(Player *p);
	//void setOwnerString(std::string own);
	std::string getOwnerString();
	void setOwnerString(std::string own);
	Player * getOwner();
	void Mortgage();	
	void unMortgage();
	void setMortgage(bool mortgage);
//	void Auction(int numPlayers, int numbidders, Player * players[numPlayers]);
	void getAction(Player *player);
	
	Ownable(std::string name, int squarepos,int cost);
	~Ownable();

};

#endif
