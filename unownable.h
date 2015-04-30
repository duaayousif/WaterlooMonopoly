#ifndef __UNOWNABLE_H__
#define __UNOWNABLE_H__

#include "square.h"
#include <string>
#include "board.h"
#include "player.h"

class UnOwnable : public Square {

	public:
	
	UnOwnable(std::string name, int squarepos);
	~UnOwnable();

	void SlcNh(Player *currplayer);
	void getAction(Player *player);
};

#endif

	
