#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int i = 3;
	int j = 4;
	int *p1 = &i;
	int *p2 = &j;

	cout << i << " " << *p1 << endl;
	cout << j << " " << *p2 << endl;

	*p1 = *p2;
	cout << i << " " << j << " " << *p1 << " " << *p2 << endl;

	*p1 = j * 2;
	*p2 = j + 3;
	cout << i << " " << j << " " << *p1 << " " << *p2 << endl;

	p1 = p2;	
	cout << i << " " << j << " " << *p1 << " " << *p2 << endl;

	return 0;
}