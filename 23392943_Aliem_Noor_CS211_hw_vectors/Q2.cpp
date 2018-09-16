#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

//Q2
int main(){
	int n = 10;
	vector<int> v(n);
	cout << v.size() << " " << v.capacity() 
		<< " " << v.front() << " " << v.back() << endl;
	
	v[0] = 2; v[1] = 3; v[2] = 3; v[3] = 9; v[4] = 2; v[5] = 9; v[6] = 4; v[7] = 3;
//	v = {2, 3, 3, 9, 2, 9, 4, 3};

	for(int i = 0; i < v.size(); ++i){
		cout << v[i];
	}
//	cout << v.back();
	cout << endl;

	v.resize(13, -1);
	for(int i = 0; i < v.size(); i++){
		cout << v[i];
	}
	cout << endl;

	cout << v.size() << "" << v.capacity() 
		<< "" << v.front() << "" << v.back() << endl;

	vector<int> w;
	cout << w.size() << "" << w.capacity() << endl;
	w = v;
	for(int i = 0; i < w.size(); ++i){
		cout << w[i];
	}
	cout << w.size() << "" << w.capacity() 
		<< "" << w.front() << "" << w.back() << endl;

	vector<string> s;
//	s = v;

	return 0;
}
