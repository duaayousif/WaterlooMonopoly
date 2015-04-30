#ifndef __SQUARE_H__
#define __SQUARE_H__
#include <string>
class Player;

class Square {

	protected:

	std::string name;
	int squarepos;

	public:


	std::string getName();
	int getSquarepos();
	Square(std::string name, int squarepos);
	virtual ~Square() = 0;
	
	// But getAction() is not defined in Ownable
	virtual void getAction(Player *player)=0;

};

#endif
