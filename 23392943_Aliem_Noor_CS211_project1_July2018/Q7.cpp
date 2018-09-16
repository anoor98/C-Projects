//Q7
#include <iostream>
#include <cmath>
using namespace std;

bool divisible_11(int n, int &s){
	//if(n < 10) return n;
	int i = 1, s1 = 0, s2 = 0; // i counts number of digits in n. s1 = odd sum, s2 = even sum
	for(int m = n ; m != 0; m /= 10, i++){ // There is definitely a more elegant way to do this.
	}
	if(i % 2 != 0){ // n is odd, so singles-digit is odd.
		for( ; n != 0; n /= 100){
			s1 += n % 10;
			s2 += (n/10)%10;
		}
	}
	if(i % 2 == 0){ // n is even, so singles-digit is even.
		for( ; n != 0; n /= 100){
			s1 += (n/10)%10;
			s2 += n % 10;
		}
	}
	s = abs(s1 - s2);
	if(s == 0) return true;
	else if(s < 11) return false;
	if(s >= 11){
		n = s;
		return divisible_11(n, s);
	}
}