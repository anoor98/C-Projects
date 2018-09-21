#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

void sum_array(int j, const double *a, double &sum) {
	sum = 0;
	for (int i = 0; i < j; ++i){
		sum += a[i];
	}
}

int main() {
	int n = 5;
	double d[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double *pa = NULL;
	double *pb = NULL;
	for (int i = 0; i < n; ++i){
		cout << d[i] << " ";
	}
	cout << endl;
	
	pa = new double[n];
	pb = new double[n];

	//pa = pb = new double[n];
	for (int i = 0; i < n; ++i) {
		pa[i] = 0;
		for (int j = 0; j <= i; ++j) {
			pa[i] = pa[i] + d[j];
		}
	}

	for (int i = 0; i < n; ++i) {
		sum_array(i, d, pb[i]);         	
	}

	for (int i = 0; i < n; ++i) {
		cout << d[i] << " " << pa[i] << " " << pb[i] << endl;         	
	}

	delete pa; 
	delete pb;

	return 0;
}
