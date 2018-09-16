//Q4
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <sstream>
#include <cctype>
using namespace std;

bool word_match(string s1, string s2) {
	for(int i = 0; i < s1.length(); i++){
	    s1[i] = toupper(s1[i]);
	    }
	for(int i = 0; i < s1.length(); i++){
	    s2[i] = toupper(s2[i]);
	    }
    return s1 == s2;
}

int main(){
	string s1, s2;
	bool b;
	s1 = "alice";
	s2 = "AlIce";
	b = word_match(s1, s2);
	
	if (b == true)
		cout << "true:   [" << s1 << "]    [" << s2 << "]" << endl;
	else
		cout << "false:  [" << s1 << "]    [" << s2 << "]" << endl;
    return 0;
}