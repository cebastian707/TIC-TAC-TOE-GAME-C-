#pragma once
#include<iostream>
#pragma warning(disable:4996)
#include<iomanip>
#include"Tic_Tac_Toe.h"
#include<algorithm>
#include<limits.h>
#include<cstdlib>
#include<ctime>

/*Program Done By Cebastian Santiago Header File using the struct as the minimax which that will the computers move after we check the min and max return that
other then we got a couple private members two which are too Fill the board Num_Rows and Num_Cols the enum class filler the char board*/
using namespace std;

class Tic_Tac_Toe
{
private:
	//use two create the board
	int static const Num_Rows = 3;
	int static const Num_Cols = 3;
	struct Minimax
	{
		int row = 0;
		int col = 0;
	};
	//this is what we fill the board with
	enum class Player
	{
		none = '-',
		PLAYER_ONE = 'X',
		PLAYER_TWO = 'O',
		COMPUTER = 'O'
	};
	// create board using the enum class player
	Player Board[Num_Rows][Num_Cols];
	//this returns the optimal place to put the computer move using the minsearch functiona and the maxsearch function
	Minimax Move() {
		int score = numeric_limits<int>::max();
		Minimax Moves;
		for (int row = 0; row < Num_Rows; row++)
		{
			for (int col = 0; col < Num_Cols; col++)
			{
				if (Board[row][col] == Player::none)
				{
					Board[row][col] = Player::COMPUTER;
					int temp = maxsearch();
					Board[row][col] = Player::none;
					if (temp < score)
					{
						score = temp;
						Moves.row = row;
						Moves.col = col;
					}
				}
			}
		}
		return Moves;
	}
public:
	//this member public function checks if the game board is full or not
	int checkspaces(Player play) {
		for (int row = 0; row < Num_Rows; row++)
		{
			for (int col = 0; col < Num_Cols; col++)
			{
				if (Board[row][col] == play)
				{
					return 0;
				}
			}

		}
		return 1;
	}
	void Computer_Choose() {
		srand(time(NULL));
		int place = 0;
		place = rand() % 9;
		if (place == 1)
		{
			Board[0][0] = Player::COMPUTER;
			print_Board();
		}
		else if (place == 2)
		{
			Board[0][1] = Player::COMPUTER;
			print_Board();
		}
		else if (place == 3)
		{
			Board[0][2] = Player::COMPUTER;
			print_Board();

		}
		else if (place == 4)
		{
			Board[1][0] = Player::COMPUTER;
			print_Board();
		}
		else if (place == 5)
		{
			Board[1][1] = Player::COMPUTER;
			print_Board();
		}
		else if(place == 6)
		{
			Board[1][2] = Player::COMPUTER;
			print_Board();
		}
		else if (place == 7)
		{
			Board[2][0] = Player::COMPUTER;
			print_Board();
		}
		else if(place == 8)
		{
			Board[2][1] = Player::COMPUTER;
			print_Board();
		}
		else if (place == 9){
			Board[2][2] = Player::COMPUTER;
			print_Board();
		}

	}
	void AI_Goes_First();
	int Full_Board()const;
	void choose();
	void Computer_Movie();
	void AI_GAME();
	int maxsearch();
	int minsearch();
    void player_one();
	void player_Two();
	Tic_Tac_Toe();
	void print_Board();
	bool ISTIE(Player play);
	void Game();
	bool CHECK_WINNER(Player);
	//this is a display board to let the user know where to place his move on the board by entering numbers 1-9
	void displayboard() {
		for (int row = 2; row < Num_Rows; row++)
		{
			cout << setw(25) << " 1 |    2    |  3 " << endl;
			for (int col = 2; col < Num_Cols; col++)
			{
				cout << setw(25) << " --------------------------------  " << endl;
				cout << setw(25) << " 4 |    5    |  6 " << endl;
				cout << setw(25) << " --------------------------------  " << endl;
			}
			cout << setw(25) << " 7 |    8    |  9 " << endl;
		}
	}
};