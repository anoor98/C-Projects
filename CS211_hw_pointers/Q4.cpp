#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

void swap(int *u, int *v) {                                               // #1
	cout << "(b)  "  << (*u) << "   " << (*v) << endl;
	double tmp = *u;                 // save temporary value (dereference) // #2
	*u = *v;                         // copy dereference                   // #3
	*v = tmp;                        // assign dereference                 // #4
	cout << "(c)  "  << (*u) << "   " << (*v) << endl;                     // #5
}

int main() {
	int i = 3;
	int j = 4;
	cout << "(a)  "  << i << "   " << j << endl;
	swap(&i, &j);                                                          // #6
	cout << "(d)  "  << i << "   " << j << endl;
	return 0;
}
/*
1) The the "&" notation applied to both variables in the swap function allows for the pointers to point to the values of the variables i and j.
2) "u" and "v" point to the memory address of variables "i" and "j".
3) "temp" is the value of "*u", "*u" points to the address of "i", "&i" dereferences "*u" to have the value of i so temp = i.
4) on statement #3, "i" is operated on to equal the value of "j".
5) 4 is copied on to "i" in statements #3.
6) temp contains the value of 3, and that number is copied onto "*v".
7) i becomes 4 and j becomes 3.
*/