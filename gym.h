#ifndef __GYM_H__
#define __GYM_H__

#include <string>
#include "ownable.h"
#include "player.h"

class Gym : public Ownable {

	public:

	Gym(std::string name, int squarepos, int cost);
	~Gym();

	void getAction(Player *player);

};

#endif

