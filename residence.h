#ifndef __RESIDENCE_H__
#define __RESIDENCE_H__

#include <string>
#include "ownable.h"
#include "player.h"

class Residence : public Ownable {

	public:
	
	Residence(std::string name,int squarepos, int cost);
	~Residence();

	void getAction(Player *player);

};

#endif	
