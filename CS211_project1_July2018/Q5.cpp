//Q5
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double sqrt_Babylonian(double a){
	double guess0 = 0, guess1 = 1; // guess0 = last guess, guess1 = current guess
	
	while (abs(guess1 - guess0) >= 0.001) {
		guess0 = guess1;
		guess1 = (guess1 + (a / guess1)) / 2;
		cout << fixed << showpoint;
		cout << setprecision(4);
		cout << guess1 << endl;
	}
	
	return guess1;
}

/*
sqrt_Babylonian(23392943) printsthe following:
i		xi
0		1
1		11696472.0000
2		5848237.0000
3		2924120.5000
4		1462064.2500
5		731040.1250
6		365536.0623
7		182800.0293
8		91463.9997
9		45859.8805
10		23184.9882
11		12096.9788
12		7015.3814
13		5174.9516
14		4847.6847
15		4836.6378
16		4836.6252
17		4836.6252
18		4836.6252 
*/