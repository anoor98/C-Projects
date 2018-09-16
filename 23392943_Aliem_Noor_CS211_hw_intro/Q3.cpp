//Q3
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int RPM(int a, int b) {
	int sum = 0;
	while (a > 0) {
		if (a % 2 != 0) {
			sum += b;
    }

    a = a / 2;
    b = b * 2;
	}
	return sum;
}

int main() {
	int x = 2339, y = 2943;
	cout << RPM(x, y);
	return 0;
}
