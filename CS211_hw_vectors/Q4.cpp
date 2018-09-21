#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <ostream>
using namespace std;

vector<string> concat_vec(const vector<string> &vs1, const vector<string> &vs2) {
	vector<string> concat_vec(vs1.size() + vs2.size());
	for(int i = 0; i < vs1.size(); ++i){
		concat_vec.push_back(vs1[i]);
	}

	for(int i = 0; i < vs2.size(); ++i){
		concat_vec.push_back(vs2[i]);
	}

	return concat_vec;
}

int main() {
    vector<string> v;
    v.push_back("x");
    v.push_back("y");
    v.push_back("z");
    v.push_back("b");
    v.push_back("a");
    // (populate v)
    v = concat_vec(v,v);     // all three are v
    for(int i = 0; i < v.size(); ++i){
		cout << v[i];
	}
	cout << endl;
    // (print result)
    v = concat_vec(v,v);     // call it twice!
    for(int i = 0; i < v.size(); ++i){
		cout << v[i];
	}
	cout << endl;
    // (print result)
    
    return 0;
    }