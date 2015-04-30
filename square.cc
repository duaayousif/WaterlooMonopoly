#include "square.h"
#include <string>
#include <iostream>

using namespace std;

Square::Square(string name,int squarepos) : name(name), squarepos(squarepos) {}

Square::~Square() {}

string Square::getName() {
	return name;
}

int Square::getSquarepos() { return squarepos; }


