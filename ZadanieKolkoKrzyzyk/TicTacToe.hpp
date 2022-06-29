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
	bool makeTurn(Board);

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

std::ostream& operator << (std::ostream& s, const Board& board)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			CheckerState cs = board.check(i, j);
			s << " ";
		/*	 s << board.check(i, j); // nie pozwala mi na taki zapis: s << board.check(i, j) DLACZEGO?
			s << " ";*/
		}
		s<< std::endl;
	}
	return s;

}

std::ostream& operator << (std::ostream& s, const CheckerState& cs)
	//std::count zaminiamy na s
{if (cs == CheckerState::EMPTY)
s << "-";
else if (cs == CheckerState::X)
s << "X";
else if (cs == CheckerState::O)
s << "O";
return s;
}


