#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

const double* get_const_element(const vector<double> &v, int n) {
	if(n < 0 || n > v.size() - 1) 
	    return NULL;
	else 
	    return &v[n];
}   // etc

int main() {
    int len = 5;
    vector<double> v;
    for(int i = 0; i < len; ++i) {
        v.push_back(i + 1.2);
    }
    
	for(int i = -1; i < len + 2; ++i){
		const double *tmp = get_const_element(v, i);
		if(tmp == NULL) 
		    cout << i << endl;
		else 
		    cout << *tmp << endl;
	}
	
	return 0;
}
