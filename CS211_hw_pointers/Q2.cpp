#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int i = 3;
	int j = 4;
	int a[] = {5, 6, 7};
	double x = 8.9;

	int *p1 = &i;
	int *p2 = &j;
	double *pd = NULL;

	pd = &x;
	cout << x << " " << *pd;

	//pd = &j;
	//pd = p2;

	return 0;
}