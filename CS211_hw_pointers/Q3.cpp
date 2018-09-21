#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int n = 3;
	int i = 3;
	int a[] = {5, 6, 7};
	int *p1 = NULL;
	
	p1 =a;
	for (i = 0; i < n; ++i) { 
		cout << a[i] << " " << p[i] << endl; 
	}

	i = p1[2];
	cout << i << " " << a[2] << " " << p1[2];

	for (i = 0; i < n; ++i) {
		p1[i] = -2 * p1[i];
		cout << a[i] << " " << p1[i] << endl;
	}

	return 0;
}