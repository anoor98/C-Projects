#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	string name("Aliem");
	vector<char> vchar;
	cout << vchar.size() << "" << vchar.capacity() << endl;

 	for(int i = 0; i < name.size(); ++i) {
		vchar.push_back(name[i]);
		cout << vchar[i] << "" << vchar.size() << "" <<
			vchar.capacity() << "" << vchar.front() <<
			"" << vchar.back() << endl;
	}

	for(int i = 0; i < vchar.size(); ++i) {
		vchar[i] = toupper(vchar[i]);
		cout << vchar[i] << "" << vchar.size() << "" <<
			vchar.capacity() << "" << vchar.front() <<
			"" << vchar.back() << endl;
	}

	vchar.pop_back();
	for(int i = 0; i < vchar.size(); ++i) {
		cout << vchar.size() << "" << vchar.capacity() 
		<< "" << vchar.front() << "" << vchar.back() << endl;
	}

	vchar.clear();
	cout << vchar.size() << vchar.capacity() << endl;

	return 0;
}