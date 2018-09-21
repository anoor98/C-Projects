//Q6
#include <iostream>
using namespace std;

bool divisible_9(int n, int &s){
	s = 0;
	for( ; n != 0 ;){ // s = sum of digits in n.
		s += (n%10);
		n /= 10;
	}
	if(s > 9){
		n = s;
		return divisible_9(n, s);
	}
	else if(s <= 9){
		if(s == 9) return true;
		else return false;
	}

}