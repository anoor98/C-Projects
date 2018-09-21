//Q5
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <sstream>
#include <cctype>
#include "stdafx.h"
using namespace std;

void print_even(int n)

void print_odd(int n)

int main(){
	for (int i = 10; i < 20; ++i) {
	print_even(i);
	}
	return 0;
}

void print_even(int n){
	if (n%2 == 0)
	cout << "n is even: " << n << endl;
	else
	print_odd(n);
}

void print_odd(int n){
	if (n%2 != 0)
	cout << "n is odd: " << n << endl;
	else
	print_even(n);
}