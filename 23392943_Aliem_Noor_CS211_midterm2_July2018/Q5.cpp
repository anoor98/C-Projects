#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

/*
int main() {
	int n = 5;
	vector<int> vi(n);
	//int n1 = 2339, n2 = 2943;
	cout << vi.size() << "  " << vi.capacity() << endl;          // #1
	vi.clear();
	cout << vi.size() << "  " << vi.capacity() << endl;          // #2
	int n1 = 2339, n2 = 2943; // #3 (write on one line)
	vi.push_back(n1); vi.push_back(n2); //  push back n1, n2 onto vector vi                    // #4 (write on separate lines)
	
	for (int i = 0; i < vi.size(); i++)
		cout << vi[i] << endl;
	int *ip = new int, max = vi[0];
	ip = &max;
	for (int i = 0; i < vi.size(); ++i) {// set contents of ip to largest integer in vector vi  // #5 (if equal, use n1)
		if (vi[i] > max) max = vi[i];
	}
	cout << ip << endl;                      // #6
	for (int i = 0; i < vi.size(); ++i) {												   // increment contents of ip by 7                       // #7
		ip[i] = +7;
		cout << ip[i] << endl;  //#8
	}

	delete ip;											   // release dynamic memory (if required)                // #9 (if not required, say so)
	return 0;
}
*/
void print(const string* ps)
{
	int len = ps->size();      // #1
		cout << len << endl;
	cout << *ps << endl;              // #2
}
int main()
{
	vector<string> vs;
	cout << vs.size() << "  " << vs.capacity() << endl;  // #3
	string s1("Aliem"), s2("Noor");                       // #4 (write on one line)
	vs.push_back(s1); vs.push_back(s2);											   //  push back s1, s2 onto vector vs            // #5 (write on separate lines)
	cout << vs.size() << "  " << vs.capacity() << endl;  // #6
	string *ps = NULL;
	for (int i = 0; i < vs.size(); i++) {
		ps = &vs[i];                      // #7
			cout << *ps << endl;            // #8 ** use pointer **
	}

	if (s1.size() == s2.size()) ps = &s2;
	if (s1.size() > s2.size()) ps = &s1;
	else ps = &s2;  // #9 (if same length, use s1)
	print(ps);


	cout << "Memory release not required." << endl;// release dynamic memory (if required)        // #10 (if not required, say so)
	return 0;
}