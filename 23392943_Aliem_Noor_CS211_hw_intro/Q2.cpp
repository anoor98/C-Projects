//Q2
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

void swap1(int a, int b){
    int c = a;
    a = b;
    b = c;
}
/*
swap1 takes a copy of the variable and modifies the values 
of those copies but does not modify the values of the 
original variables.
*/

void swap2(int &a, int &b){
    int c = a;
    a = b;
    b = c;
}
/*
swap2 takes the original variables and modifies them successfully through
pass-by-reference.
*/

void swap3(int a[]){
    int c = a[0];
    a[0] = a[1];
    a[1] = c;
}

int main(){
    int a = 3, b = 4, c = 5, d = 6;
    cout << "original:  "  << a << "   " << b  << "   " << c  << "   " << d << endl;
    swap1(a,b);
    cout << "swap1:  "  << a << "   " << b << endl; // swap1: 3 4
    swap2(c,d);
    cout << "swap2:  "  << c << "   " << d << endl; // swap2: 6 5
    
    return 0;
}
