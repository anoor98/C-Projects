#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	vector<vector<int>> vv;
	vector<int> vec1, vec2, vec3;

	vec1.push_back(1);
	vec2.push_back(2); vec2.push_back(3);
	vec3.push_back(4); vec3.push_back(5); vec3.push_back(6); vec3.push_back(7);
	
	vv.push_back(vec1);
	vv.push_back(vec2);
	vv.push_back(vec3);

	for (int i = 0; i < vv.size(); ++i) {
		vector<int> &temp = vv[i];
		for (int j = 0; j < temp.size(); ++j) {
			cout << i << " " << j << " " 
			<< temp[j] << " " << vv[i][j];
		}
		cout << endl;
	}
	return 0;
}
