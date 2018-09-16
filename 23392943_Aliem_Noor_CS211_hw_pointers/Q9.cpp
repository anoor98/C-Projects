#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int i = 6;
	int j = 3;
	int k = 0;
	int *p1 = &i;
	int *p2 = &j;
	
	k = (*p1) + (*p2);        // equivalent to k = i + j
	cout << k << endl;
	k = (*p1) - (*p2);        // equivalent to k = i - j
	cout << k << endl;
	k = (*p1) * (*p2);        // equivalent to k = i * j
	cout << k << endl;
	k = (*p1) / (*p2);        // equivalent to k = i / j
	cout << k << endl;

	k = *p1 + *p2;            // equivalent to k = i + j
	cout << k << endl;
	k = *p1 - *p2;            // equivalent to k = i - j
	cout << k << endl;
	k = *p1 * *p2;            // equivalent to k = i * j
	cout << k << endl;
	k = *p1 / *p2;            // equivalent to k = i / j
	cout << k << endl;

	return 0;
}