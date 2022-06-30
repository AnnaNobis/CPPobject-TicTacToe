#include "TicTacToe.hpp"
#include <iostream>



Board::Board()
{
   
}

CheckerState Board::check(int x, int y) const
{
    return table[x][y];
}

void Board::set(CheckerState cs, int x, int y)
{
   table[x][y] = cs;

}

bool Board::isOver()
{
    return checkRows() || checkCols() || checkDiagonal();

}

bool Board::checkRows()
{
   
    for (int i = 0; i < 3; i++)
    {
        if (table[i][0] != CheckerState::EMPTY &&
            (table[i][0] == table[i][1]) &&
            (table[i][1] == table[i][2]))

            return true;
    }
    return false;
}

bool Board::checkCols()
{
    bool result = false;
    for (int i = 0; i < 3; i++)
    {
        if ((table[0][i] != CheckerState::EMPTY) &&
            (table[0][i] == table[1][i] &&
             table[1][i] == table[2][i]))
           return true;
    }
    return false;
}

bool Board::checkDiagonal()
{
  
    return ((table[0][0] != CheckerState::EMPTY &&
        table[0][0] == table[1][1] &&
            table[1][1] == table[2][2]) ||
        (table[2][0] != CheckerState::EMPTY &&
        table[2][0] == table[1][1] &&
        table[1][1] == table[0][2]));
      
     
  }

bool Board::xWon()
{
    return false;
}

//void Board::drawBoard()
//{
//    std::cout << " " << table[0][0] << " |" << " " << table[0][1] << " |" << " " << table[0][2] << std::endl;
//    std::cout << "___|___|___ \n";
//    std::cout << " " << table[1][0] << " |" << " " << table[1][1] << " |" << " " << table[1][2] << std::endl;
//    std::cout << "___|___|___ \n";
//    std::cout << " " << table[2][0] << " |" << " " << table[2][1] << " |" << " " << table[2][2] << std::endl;
//    std::cout << "   |   |   ";
//}

bool Player::makeTurn(Board* board)
{
    	std::cout << "You're player: " << colour << std::endl;
        int x = 0;
        int y= 0;
	do
	{
		std::cout << "Make your move: ";
		std::cin >> x;
        std::cin >> y;
	} while (board->check(x, y) != CheckerState::EMPTY);

	board->set(colour, x, y);
	
    return true;
}

Game::Game(Player* p1, Player* p2)
{
  
    this->player1 = p1;
   this-> player2 = p2;
    currentPlayer = player1;

   // reset();

}

void Game::start()
{
    system("cls");
    std::cout << "Welcome to Tic Tac Toe!" << std::endl;
    std::cout << board;
    std::cout << "Make your move: ";


    do
    {
        this->swapPlayer();
        currentPlayer->makeTurn(&board);
        std::cout << board;

    }

    while (!board.isOver());
    
    if (board.xWon())
        std::cout << "X won" << std::endl;
    else
        std::cout << "O won" << std::endl;
}



void Game::reset()
{
    system("cls");

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board.set(CheckerState::EMPTY, i, j);
    
}

void Game::swapPlayer()
{
    if (currentPlayer == player1)
    {
        currentPlayer = player2;
    }
    else
    {
        currentPlayer = player1;
    }
}



Player::Player(CheckerState cs)
{
    this->colour = cs;
}

std::ostream& operator << (std::ostream& s, const Board& board)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
           // CheckerState cs = board.check(i, j);
            s << board.check(i, j);
            s << " ";
            /*	 s << board.check(i, j); // nie pozwala mi na taki zapis: s << board.check(i, j) DLACZEGO?
                s << " ";*/
        }
        s << std::endl;
    }
    return s;

}

std::ostream& operator << (std::ostream& s, const CheckerState& cs)
//std::count zaminiamy na s
{
    if (cs == CheckerState::EMPTY)
        s << "-";
    else if (cs == CheckerState::X)
        s << "X";
    else if (cs == CheckerState::O)
        s << "O";
    return s;
}
