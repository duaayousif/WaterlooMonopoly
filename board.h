#ifndef __BOARD_H__
#define __BOARD_H__

#include "square.h"

class Player;

extern std::string ev1Improve;
extern std::string ev2Improve;
extern std::string ev3Improve;
extern std::string physImprove;
extern std::string b1Improve;
extern std::string b2Improve;
extern std::string optImprove;
extern std::string eitImprove;
extern std::string bmhImprove;
extern std::string escImprove;
extern std::string lhiImprove;
extern std::string c2Improve;
extern std::string cphImprove;
extern std::string dweImprove;
extern std::string mcImprove;
extern std::string rchImprove;
extern std::string dcImprove;
extern std::string hhImprove;
extern std::string pasImprove;
extern std::string echImprove;
extern std::string mlImprove;
extern std::string alImprove;

extern std::string nestPlayer;
extern std::string ev1Player;
extern std::string need1Player;
extern std::string need2Player;
extern std::string need3Player;
extern std::string ev2Player;
extern std::string ev3Player;
extern std::string v1Player;
extern std::string physPlayer;
extern std::string b1Player;
extern std::string cifPlayer;
extern std::string b2Player;
extern std::string timsPlayer;
extern std::string optPlayer;
extern std::string eitPlayer;
extern std::string bmhPlayer;
extern std::string escPlayer;
extern std::string slc1Player;
extern std::string slc2Player;
extern std::string slc3Player;
extern std::string lhiPlayer;
extern std::string c2Player;
extern std::string uwpPlayer;
extern std::string revPlayer;
extern std::string cphPlayer;
extern std::string dwePlayer;
extern std::string mcPlayer;
extern std::string pacPlayer;
extern std::string coopPlayer;
extern std::string rchPlayer;
extern std::string dcPlayer;
extern std::string timsLinePlayer;
extern std::string hhPlayer;
extern std::string pasPlayer;
extern std::string echPlayer;
extern std::string mkvPlayer;
extern std::string tuitionPlayer;
extern std::string mlPlayer;
extern std::string alPlayer;
extern std::string osapPlayer;

//extern int numPlayers;

//extern Player * players;

class Board {
	Board();
	static Board *instance;
	static void cleanup();
	//the total number of tims cups in the game
	int timscups;
	// the board
	Square ** board;
	public:
	~Board();
	//Static method to initialize the board
	static Board *getInstance();
	//Method to print the board
	void printBoard();
	Square ** getBoard();
	//Method to add improvement to board
	void setImprovements();
	//Moves the player on the board
	//void movePlayer();
	//Adds one tims cup to the total
	void addTotalcup();
//	void minusCurrPlayers();
//	Player * getPlayers();
	//Takes away a tims cup from the player(called when they use it to get out of the line)
	void minusTotalcup();
	int getTimscups();
	void save(std::string fileName, int numPlayers, Player * players[8]);
	//void load(std::string fileName);
	void movePlayer(int numPlayers, Player *players[8]);
//	void playerMove(std::string boardPlayer, int numPlayers, Player *players[numPlayers], int index);
};
#endif
	

