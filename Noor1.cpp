//Aliem Noor
//Going To Boston Implementation
#define AUTO_GENERATE
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int roll() {return rand() % 6 + 1;}

int maxFunction(int a, int b, int c, int score){
    a = rand() % 6 + 1;
	b = rand() % 6 + 1;
    c = rand() % 6 + 1;
    cout << "You rolled ( " << b << ", " << c << " ) --> ";
    if (max(b, c) == b){
        c = rand() % 6 + 1;
        cout << "You rolled ( " << c << " ) --> ";}
    else if (max(b, c) == c){
        b = rand() % 6 + 1;
        cout << "You rolled ( " << b << " ) --> ";}
    score = a + b + c;
    cout << "You scored " << score << ".";
    return score;}

int main(){
	srand(time(0));
	int round = 1;
	int comp_bank, player_bank; comp_bank = player_bank = 1000;
	cout << "The computer has $" << comp_bank << ", and you have $" << player_bank << endl;

	while (true){
		int bet;
		cout << "[Round " << round++ << "]" << endl;
		int CD1 = roll(); int CD2 = roll(); int CD3 = roll();
		int Csum = CD1 + CD2 + CD3; int comp = Csum;
		int PD1 = roll(); int PD2 = roll(); int PD3 = roll();
		int Psum = PD1 + PD2 + PD3; int player = Psum;
		cout << "Computer got (" << CD1 << "," << CD2 << "," << "?" << ")" << endl;
		cout << "You got (" << PD1 << "," << PD2 << "," << "?" << ")" << endl;
		cout << "How much will you bet? ";
#ifndef AUTO_GENERATE
		int bet; cin >> bet;
#else
		cout << bet << endl;
		bet = rand() % 10 + 1;
			while (bet < 1 || bet > 10) {
				cout << "Error. Bet must be numbers between $1-$10. How much will you bet? " << endl;
				cin >> bet;
				continue;}
#endif
		cout << "You had (" << PD1 << "," << PD2 << "," << PD3 << ")" << endl;
		cout << "Computer had (" << CD1 << "," << CD2 << "," << CD3 << ")" << endl;
		if (PD1 == PD2 && PD2 == PD3 && PD1 == PD3
			&& CD1 != CD2 && CD2 != CD3 && CD1 != CD3){
			cout << "Big Fish" << endl;
			player_bank += 50 * bet;
			comp_bank -= 50 * bet;
			cout << "The computer has $" << comp_bank << " and you have $" << player_bank << endl;
			if (comp_bank <= 0) break;
			continue;}

		if (max(max(PD1, PD2), PD3) == PD1){
		    Psum = maxFunction(PD1, PD2, PD3, Psum);}
		else if (max(max(PD1, PD2), PD3) == PD2){
		    Psum = maxFunction(PD2, PD1, PD3, Psum);}
		else if (max(max(PD1, PD2), PD3) == PD3){
		    Psum = maxFunction(PD3, PD2, PD1, Psum);}
		if (player > comp) {
			cout << "You Win! " << endl;
			player_bank += bet * (player - comp);
			comp_bank -= bet * (player - comp);
			cout << "The computer has $" << comp_bank << " and you have $" << player_bank << endl;
			if (comp_bank <= 0) break;
			continue;}

		if (CD1 == CD2 && CD2 == CD3 && CD1 == CD3
			&& PD1 != PD2 && PD2 != PD3 && PD1 != PD3){
			cout << "Big Fish!!" << endl;
			player_bank -= 50 * bet;
			comp_bank += 50 * bet;
			cout << "The computer has $" << comp_bank << " and you have $" << player_bank << endl;
			continue;}

		if (max(max(CD1, CD2), CD3) == CD1){
			Csum = maxFunction(CD1, CD2, CD3, Csum);}
		else if (max(max(CD1, CD2), CD3) == CD2){
		    Csum = maxFunction(CD2, CD1, CD3, Csum);}
		else if (max(max(PD1, CD2), CD3) == CD3){
		    Csum = maxFunction(CD3, CD2, CD1, Csum);}
		if (player < comp) {
			cout << "You lost!" << endl;
			player_bank -= bet * (comp - player);
			comp_bank += bet * (comp - player);
			cout << "The computer has $" << comp_bank << " and you have $" << player_bank << endl;
			if (player_bank <= 0) break;
			continue;}

		cout << "Draw" << endl;
	}
	cout << "Goodbye" << endl;
	return 0;
}
