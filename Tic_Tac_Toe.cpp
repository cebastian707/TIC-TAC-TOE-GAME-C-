/*CPP file that works with the hearder file*/
//by Cebastian Santiago

#pragma warning(disable:4996)
#include<iostream>
#include<iomanip>
#include"Tic_Tac_Toe.h"
#include<algorithm>
#include<limits>
#include<ctime>

using namespace std;
/*Checks if the board is full
*/
int Tic_Tac_Toe::Full_Board()const {
	for (int row = 0; row < Num_Rows; row++)
	{
		for (int col = 0; col < Num_Cols; col++)
		{
			if (Board[row][col] == Player::none){
				return 0;
			}
		}
	}
	return 1;
}

/* Let's the user pick between playing againest another player or againest the AI
*/
void Tic_Tac_Toe::choose() {
	int num = 0;
	cout << " Welcome to Tic Tac Toe 2.0 ! " << endl;
	cout << " **************************** " << endl;
	cout << " 1.Human Vs Human " <<endl;
	cout << " 2. Human Vs AI " << endl;
	cout << " 3. AI (goes first) Vs Human " << endl;
	cout << " ****************************\n " << endl;
	cout << endl;
	cout << " What Do you want to play?: ";
	cin >> num;
	while (num < 0  || num > 3 || !cin)
	{
		cin.clear();
		cin.ignore('300', '\n');
		cout << " You typed something incorrect retype ! " << endl;
		cout << " What Do you want to play: ?";
		cin >> num;
	}
	switch (num)
	{
	case 1:Game();
		break;
	case 2:AI_GAME();
		break;
	case 3:AI_Goes_First();
		break;
	}	

}
/* Function checks all posible outcomes for the Maximizer 
*/
int Tic_Tac_Toe::maxsearch() {
	//if player one has won return there score
	if (CHECK_WINNER(Player::PLAYER_ONE))
	{
		return 10;
	}
	//if computer has won returns there score
	else if (CHECK_WINNER(Player::COMPUTER))
	{
		return -10;
	}
	//returns a tie if no one one
	else if (ISTIE(Player::none))
	{
		return 0;
	}
		//Goes through the board and grabs the maxium value
		int score = numeric_limits<int>::min();
		for (int row = 0; row < Num_Rows; row++)
		{
			for (int col = 0; col < Num_Cols; col++)
			{
				if (Board[row][col] == Player::none)
				{
					Board[row][col] = Player::PLAYER_ONE;
					score = max(score, minsearch());
					Board[row][col] = Player::none;
				}
			}
		}
		return score;
	
}
//Function checks all possible outcomes for the Minimizer
int Tic_Tac_Toe::minsearch() {
	//if player one has won return there score
	if (CHECK_WINNER(Player::PLAYER_ONE))
	{
		return 10;
	}
	//if computer has won returns there score
	else if (CHECK_WINNER(Player::COMPUTER))
	{
		return -10;
	}
	//returns a tie if no one one
	else if (ISTIE(Player::none))
	{
		return 0;
	}
	//Goes through the board and grabs the minimum value
	int score = numeric_limits<int>::max();
	for (int row = 0; row < Num_Rows; row++)
	{
		for (int col = 0; col < Num_Cols; col++)
		{
			if (Board[row][col] == Player::none)
			{
				Board[row][col] = Player::COMPUTER;
				score = min(score, maxsearch());
				Board[row][col] = Player::none;
			}
		}
	}
	return score;
}

//this plays the AI function
void Tic_Tac_Toe::AI_GAME() {
	cout << " ***************** " << endl;
	cout << " Human VS Computer " << endl;
	cout << " -----------------\n " << endl;
	cout << endl;
	displayboard();
	cout << endl;
	while (ISTIE(Player::none) == false)
	{

		player_one();
		if (CHECK_WINNER(Player::PLAYER_ONE) == true)
		{
			cout << setw(25) << " Fuck you you won! " << endl;
			break;
		}
		Computer_Movie();
		if (CHECK_WINNER(Player::COMPUTER) == true)
		{
			cout << endl;
			cout <<  setw(25) << " I will take over world i won!" << endl;
			exit(0);
		}


	}
}
//computer move using the minimax function
void Tic_Tac_Toe::Computer_Movie() {
	cout << " My Move friend: ";
	Minimax moves = Move();
	cout << moves.row << moves.col << endl;
	Board[moves.row][moves.col] = Player::COMPUTER;
	print_Board();
	if (ISTIE(Player::none) == true)
	{
		cout << endl;
		cout << endl;
		cout << setw(25) << " Tie " << endl;
		exit(0);
	}
}


//construtor that fills the board with the eumn class none
Tic_Tac_Toe::Tic_Tac_Toe() {
	for (int row = 0; row < Num_Rows; row++)
	{
		for (int col = 0; col < Num_Cols; col++)
		{
			Board[row][col] = Player::none;
		}
	}
}
//this prints the board for the game we type cast this becuase were using enum class and we call it in computer move and two other member functions 
void Tic_Tac_Toe::print_Board() {
	
	for (int row = 0; row < Num_Rows; row++)
	{
		
		cout << setw(25) << " |        | " << endl;
		cout << setw(25) << " |        | " << endl;
		cout << setw(25) << " |        | " << endl;
		cout << setw(25) << " |        | " << endl;
		for (int col = 0; col < Num_Cols; col++)
		{
			cout << setw(10) << static_cast<char>(Board[row][col]);
		}
		cout << endl;
		if (row < 2)
		{
			cout << setw(35) << " ---------------------------- " << endl;

		}

	}
}



//member funtion checks if its a tie
bool Tic_Tac_Toe::ISTIE(Player tie) {

	if (Board[0][0] != tie && Board[0][1] != tie && Board[0][2] != tie && Board[1][0] != tie && Board[1][1] != tie && Board[1][2] != tie && Board[2][0] != tie && Board[2][1] != tie && Board[2][2] != tie){
		return true;
	}
	
	else{
		return false;
	}
}
//choose were too place player ones option onn the game board
void Tic_Tac_Toe::player_one() {
		int choose = 0;
		cout << "Enter your chose player one as coordinate system ex(1-9): ";
		cin >> choose;
		while (choose < 0 || choose > 9 || !cin)
		{
			cin.clear();
			cin.ignore('300', '\n');
			cout << " Incorrect retype !" << endl;
			cout << "Enter your chose player one as coordinate system ex(1-9): ";
			cin >> choose;
		}
		if (choose == 1)
		{
			Board[0][0] = Player::PLAYER_ONE;
			cout << endl;
			print_Board();
			cout << endl;
		}
		else if (choose == 2)
		{
			Board[0][1] = Player::PLAYER_ONE;
			cout << endl;
			print_Board();
			cout << endl;
		}
		else if (choose == 3)
		{

			Board[0][2] = Player::PLAYER_ONE;
			cout << endl;
			print_Board();
			cout << endl;
		}
		else if (choose == 4)
		{
			Board[1][0] = Player::PLAYER_ONE;
			cout << endl;
			print_Board();
			cout << endl;
		}
		else if (choose == 5)
		{
			Board[1][1] = Player::PLAYER_ONE;
			cout << endl;
			print_Board();
			cout << endl;

		}
		else if (choose == 6)
		{
			Board[1][2] = Player::PLAYER_ONE;
			cout << endl;
			print_Board();
			cout << endl;

		}
		else if (choose == 7)
		{
			Board[2][0] = Player::PLAYER_ONE;
			cout << endl;
			print_Board();
			cout << endl;

		}
		else if (choose == 8)
		{
			Board[2][1] = Player::PLAYER_ONE;
			cout << endl;
			print_Board();
			cout << endl;

		}
		else if (choose == 9)
		{
			Board[2][2] = Player::PLAYER_ONE;
			cout << endl;
			print_Board();
			cout << endl;

		}
		if (ISTIE(Player::none) == true)
		{
			cout << endl;
			cout << endl;
			cout << setw(25) << " Tie " << endl;
			exit(0);
		}
	
}

//choose were two player two opition on the game board
void Tic_Tac_Toe::player_Two() {

	int choose = 0;
	cout << "Enter your chose player two as coordinate system ex(1-9): ";
	cin >> choose;
	while (choose < 0 || choose > 9 || !cin){
		cin.clear();
		cin.ignore('300', '\n');
		cout << " Incorrect retype !" << endl;
		cout << "Enter your chose player two as coordinate system ex(1-9): ";
		cin >> choose;
	}

	if (choose == 1){
		Board[0][0] = Player::PLAYER_TWO;
		cout << endl;
		print_Board();
		cout << endl;
	}
	else if (choose == 2){
		Board[0][1] = Player::PLAYER_TWO;
		cout << endl;
		print_Board();
		cout << endl;
	}
	else if (choose == 3){
		Board[0][2] = Player::PLAYER_TWO;
		cout << endl;
		print_Board();
		cout << endl;
	}
	else if (choose == 4){
		Board[1][0] = Player::PLAYER_TWO;
		cout << endl;
		print_Board();
		cout << endl;
	}
	else if (choose == 5){
		Board[1][1] = Player::PLAYER_TWO;
		cout << endl;
		print_Board();
		cout << endl;
	}
	else if (choose == 6){
		Board[1][2] = Player::PLAYER_TWO;
		cout << endl;
		print_Board();
		cout << endl;

	}
	else if (choose == 7){
		Board[2][0] = Player::PLAYER_TWO;
		cout << endl;
		print_Board();
		cout << endl;

	}
	else if (choose == 8){
		Board[2][1] = Player::PLAYER_TWO;
		cout << endl;
		print_Board();
		cout << endl;

	}
	else if (choose == 9){
		Board[2][2] = Player::PLAYER_TWO;
		cout << endl;
		print_Board();
		cout << endl;

	}
	if (ISTIE(Player::none) == true){
		cout << endl;
		cout << endl;
		cout << setw(35) << " Tie " << endl;
		exit(0);
	}

}

//function checks to see who won 
bool Tic_Tac_Toe::CHECK_WINNER(Player player){
	for (int row = 0; row < Num_Rows; row++){
		if (Board[row][0] == player && Board[row][1] == player && Board[row][2] == player){
			return true;
		}
	}

	for (int col = 0; col < Num_Cols; col++){
		if (Board[0][col] == player && Board[1][col] == player && Board[2][col] == player){
			return true;
		}

	}

	if (Board[0][0] == player && Board[1][1] == player && Board[2][2] == player){
		return true;
	}

	if (Board[0][2] == player && Board[1][1] == player && Board[2][0] == player){
		return true;
	}
	else{
		return false;
	}
}


//function that lets you play againest each user
void Tic_Tac_Toe::Game() {
	cout << " *********************** " << endl;
	cout << " welcome to Tic Tac Toe " << endl;
	cout << " Human Vs Human " << endl;
	cout << " -----------------------\n " << endl;
	cout << endl;
	displayboard();
	cout << endl;
	while (Full_Board() != 1)
	{
		if (ISTIE(Player::none) == true)
		{
			cout << endl;
			cout << endl;
			cout << setw(35) << " Tie " << endl;
			exit(0);
		}

		cout << endl;
		cout << endl;
		player_one();
		cout << endl;
		cout << endl;
		if (CHECK_WINNER(Player::PLAYER_ONE) == true)
		{
			cout << setw(30) << " Player one has won. " << endl;
			break;
		}
		cout << endl;
		cout << endl;
		player_Two();
		if (CHECK_WINNER(Player::PLAYER_TWO) == true)
		{
			cout << setw(30) << " Player two won " << endl;
		}

		cout << endl;
	}

}
void Tic_Tac_Toe::AI_Goes_First()
{

	cout << " ***************** " << endl;
	cout << " Computer Vs Human " << endl;
	cout << " -----------------\n " << endl;
	cout << endl;
	displayboard();
	cout << endl;
	Computer_Choose();
	cout << endl;
	while (Full_Board() != 1)
	{
		player_one();
		cout << endl;
		cout << endl;
		if (CHECK_WINNER(Player::PLAYER_ONE) == true)
		{
			cout << setw(25) << " you won! " << endl;
			break;
		}



		Computer_Movie();
		cout << endl;
		cout << endl;
		if (CHECK_WINNER(Player::COMPUTER) == true)
		{
			cout << endl;
			cout << setw(25) << "I beat you human!" << endl;
			break;
		}
	}

}


