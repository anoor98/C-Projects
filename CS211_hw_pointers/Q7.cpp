#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main() {
	double x = 8.9;
	double *pd = new double;                // dynamic memory
		
	*pd = 10.2;
	if (x < (*pd))
		cout << "x < (*pd) true" << x << " " << *pd << endl;
	else	
		cout << "x < (*pd) false" << x << " " << *pd << endl;

	if ((*pd) > x)
		cout << "(*pd) > x true" << *pd << " " << x << endl;
	else	
		cout << "(*pd) > x false" << *pd << " " << x << endl;

	delete pd;

	//pd = new int;
	pd = new double;
	*pd = - 6.7;
	if (x < (*pd))
		cout << "x < (*pd) true" << x << " " << *pd << endl;
	else	
		cout << "x < (*pd) false" << x << " " << *pd << endl;

	return 0;
}
