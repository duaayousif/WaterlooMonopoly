#ifndef __ACADEMIC_H__
#define __ACADEMIC_H__

#include <string>
#include "ownable.h"

class Academic : public Ownable {

	std::string block;
	int numimp;
	int impcost;
	//1 if someone owns monopoly which includes this building, 0 otherwise
	bool monopoly;

	public:

	Academic(std::string name, int squarepos, int cost, std::string block, int impcost);
	~Academic();
	int getNumImp();
	void incNumImp();
	void decNumImp();
	void setNumImp(int imp);
	int getImpCost();
	bool getMonopoly();
	std::string getBlock();
	void setMonopoly(bool x);
	void getAction(Player *player);

};

#endif 	
			
