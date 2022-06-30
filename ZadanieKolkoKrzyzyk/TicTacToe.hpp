#pragma once
#include <iostream>


class Board;

enum class CheckerState { EMPTY, O, X};

class Board
{
	CheckerState table[3][3];
	bool checkRows();
	bool checkCols();
	bool checkDiagonal();

public:
	Board();
	CheckerState check(int x, int y) const;
	void set(CheckerState cs, int x, int y);
	bool isOver();
	bool xWon(); // or CheckerState whoWon()
	//void drawBoard();
};



class Player
{
	//Board* board; // nie jest potrzebne bo przekazujemy w metodzie makeTurn;
	CheckerState colour; //poniewaz chekerstate to rowniez puste pole to teoretycznie gracz moglby grac pustymi polami


public:
	Player(CheckerState cs);
	bool makeTurn(Board* board);

};

class Game
{
	Player* currentPlayer;
	Player* player1;
	Player* player2;
	Board board;
	void swapPlayer();


	public:
		Game(Player* p1,Player* p2);
		void start(); 
		void reset(); //czyœci planszê


};

std::ostream& operator << (std::ostream& s, const Board& );


std::ostream& operator << (std::ostream& s, const CheckerState& cs);

