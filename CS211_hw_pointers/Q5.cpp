#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

void array_dbl(int n, int *u) {                         // #1
	for (int i = 0; i < n; ++i) {
		u[i] = 2*u[i];
	}
}

int main() {
	int n = 3;
	int a[] = {5, 6, 7};
	int *p1 = a;
	for (int i = 0; i < n; ++i) {
		cout << a[i] << endl;
	}
	cout << endl;
	// #2                                                // #2
	array_dbl(n, a);
	// #3                                                // #3
	array_dbl(n, p1);
	for (int i = 0; i < n; ++i) {
		cout << a[i] << endl;
	}
	cout << endl;
	// #4                                                // #4
	return 0;
}

/*
1) In the first funstion call, "u" points to the memory address of array "a".
2) in the second function call "u" points to the memory address of "p1" and "p1" is the memory address of array "a".
*/