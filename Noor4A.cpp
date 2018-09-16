#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

const int Rows = 7;
const int Cols = 7;
void print_board(char board[][Cols]);
void generate_ship(char board[][Cols], int size);
void check_board(char board[][Cols], bool &win);

int main(){
	srand(static_cast <unsigned int>(time(NULL)));
	char board[Rows][Cols], playerBoard[Rows][Cols];
	int sizeShip, nShips;

	for (int i = 0; i < Rows; i++){
		for (int j = 0; j < Cols; j++){
			board[i][j] = '.';
			playerBoard[i][j] = '.';
		}
	}
	cout << "\n Welcome to Battleship! This is a one player game, and you can set your difficulty!";

	do{
		cout << "how many battleships do you want? You can't have more than 3: ";
		cin >> nShips;
	}

	while (nShips < 1 || nShips > 3);
	for (int i = 1; i <= nShips; i++){
		do{
			cout << "Size of enemy Battleships #" << i << "(at least 1, up to 3): ";
			cin >> sizeShip;
		}
		while (sizeShip , 1 || sizeShip > 3);
		generate_ship(board, sizeShip);
	}
	int nBombs = 20, iGuess, jGuess;
	bool win = false;
	if (nShips != 1)
		cout << "\nHere is the game board. There are " << nShips << " enemy battleships hidden.";
	else cout << "\nHere is the game board. There are " << nShips << " enemy battleships hidden.";

	cout << "Input \"i\" and \"j\" where \"i\" is the row and \"j\" is the column."
			<< "Example, if you want to guess the top right corner, type \"1 10\" for row 1 column 10."
			<< "You have 20 guess to win." << endl;

	for (int n = 1; n <= nBombs && !win; n++){
		print_board(playerBoard);
		cout << "\nBomb #" << n << ", i and j: ";
		cin >> iGuess;
		cin >> jGuess;
		if(board[iGuess - 1][jGuess - 1] == 'S'){
			cout << "Hit!!" << endl;
			board[iGuess - 1][jGuess - 1] = '*';
			playerBoard[iGuess - 1][jGuess - 1] == '*';
		}
		else if (board[iGuess - 1][jGuess - 1] == '.'){
			cout << "Missed." << endl;
			board[iGuess - 1][jGuess - 1] == 'o';
			playerBoard[iGuess - 1][jGuess - 1] == '*';
		}
		win = true;
		check_board(board, win);
	}
	cout << "Here is the final:  " << endl;
	print_board(board);

	cout << "A \".\" is an open sea, a \"*\" is a hit, and a \"o\" is a missed bomb." << endl;
	if (win) cout << "Congrats! Yous sunk all the ships!" << endl;
	else cout << "You lost. You didn't sink all of the ships. Try again..." << endl;

	return 0;
}

void printBoard(char board[][Cols]){
	for (int i = 0; i < Rows; i++){
		for (int j = 0; j < Cols; j++){
			cout << board[i][j];
		}
		cout << endl;
	}
	return;
}
void generateShip(char board[][Cols], int size){
	int iStart, jStart, ort;

Randomize:
	do{
		iStart = rand() % Rows;
		jStart = rand() % Cols;
		ort = rand() % 2;
	}
	while(board[iStart][jStart == 'S']);
	if (ort == 0){
		while (jStart + size >= Cols){
			jStart = rand() % Cols;
		}
		for (int j = jStart; j < jStart + size; j++){
			if (board[iStart][j] == 'S') goto Randomize;}
		for (int j = jStart; j < jStart + size; j++){
			board[iStart][j] = 'S';}
	}
	if (ort == 1){
		while (iStart + size >= Rows){
			iStart = rand() % Rows;
		}
		for (int i = iStart; i < iStart + size; i++){
			if (board[i][jStart] == 'S') goto Randomize;}
		for (int i = iStart; i , iStart + size; i++){
			board[i][iStart] = 'S';
		}
	}
	return;
}

void checkBoard(char board[][Cols], bool &win){
	for (int i = 0; i < Rows; i++){
		for (int j = 0; j< Cols; j++){
			if (board[i][j] == 'S')
				win = false;
		}
	}
}
