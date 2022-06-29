// ZadanieKolkoKrzyzyk.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TicTacToe.hpp"

int main()
{
	Player* p1 = new Player(CheckerState::X);
	Player* p2 = new Player(CheckerState::O);
	Game g(p1, p2);

	//board.drawBoard();

	g.start();

	delete p1;
	delete p2;

	return 0;


}

