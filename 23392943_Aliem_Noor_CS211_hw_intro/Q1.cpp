//Q1
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

void concat1(int n, string str[], string &s_out) {
	for (int i = 0; i < n; i++) {
		s_out += str[i];
	}
	cout << s_out;
}

string concat2(int n, string str[]) {
	string out;
	for (int i = 0; i < n; i++) {
		out += str[i];
	}
	return out;
}

string& concat3(int n, string str[]){ // Explain why this is unsafe
	string out;
	for (int i = 0; i < n; i++) {
		out += str[i];
	}
	return out;
}// concat3 is unsafe because it's output is pass-by-reference 
 //which is out of the scope of the function. 

int main()
{
	int n = 4;
	string str[] = { "first", "Second", "THIRD", "fourth" };
	string s1;
	concat1(n, str, s1);
	cout << "s1 = " << s1 << endl;
	string s2 = concat2(n, str);
	cout << "s2 = " << s2 << endl;
	string s3 = concat3(n, str);
	cout << "s3 = " << s3 << endl;

    return 0;
}