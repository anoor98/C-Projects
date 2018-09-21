#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

class PointDbl;
class PointInt;

class PointDbl {
	public:
		PointDbl() { x = 0; y = 0; }
		void set(double a, double b) { x = a; y = b; } //set method
		double getx() const { return x; } //accessor method
		double gety() const { return y; } //accessor method
		PointDbl& operator= (const PointDbl &rhs) { //operator=...
			if(this == &rhs) return *this;
			x = rhs.getx();
			y = rhs.gety();
			return *this;
		}
	private:
		double x, y;
};

class PointInt {
	public:
		PointInt() { x = 0; y = 0; }
		void set(int a, int b) { x = a; y = b; } // set method
		int getx() const { return x; } //accessor method
		int gety() const { return y; } //accessor method
		PointInt& operator= (const PointInt &rhs) { // operator= ...   
			if(this == &rhs) return *this;
			x = rhs.getx();
			y = rhs.gety();
			return *this;
		}
	private:
	int x, y;
};

bool operator== (const PointDbl &u, const PointDbl &v){
	if((u.getx() == v.getx()) && (u.gety() == v.gety())) return true;
	else return false;
}
bool operator== (const PointInt &u, const PointInt &v){
	if((u.getx() == v.getx()) && (u.gety() == v.gety())) return true;
	else return false;
}
bool operator== (const PointDbl &u, const PointInt &v){
	if((u.getx() == v.getx()) && (u.gety() == v.gety())) return true;
	else return false;
}
bool operator== (const PointInt &u, const PointDbl &v){
	if((u.getx() == v.getx()) && (u.gety() == v.gety())) return true;
	else return false;
}

bool operator!= (const PointDbl &u, const PointDbl &v){
	if((u.getx() != v.getx()) || (u.gety() != v.gety())) return true;
	else return false;
}
bool operator!= (const PointInt &u, const PointInt &v){
	if((u.getx() != v.getx()) || (u.gety() != v.gety())) return true;
	else return false;
}
bool operator!= (const PointDbl &u, const PointInt &v){
	if((u.getx() != v.getx()) || (u.gety() != v.gety())) return true;
	else return false;
}
bool operator!= (const PointInt &u, const PointDbl &v){
	if((u.getx() != v.getx()) || (u.gety() != v.gety())) return true;
	else return false;
}

PointDbl operator+ (PointDbl &u, PointInt &v){
	PointDbl x;
	x.set(u.getx() + v.getx(), u.gety() + v.gety())
	return x;
}

PointDbl operator+ (PointInt &u, PointDbl &v){
	PointDbl x;
	x.set(u.getx() + v.getx(), u.gety() + v.gety())
	return x;
}

int main() {
	PointDbl dp, pdbl;
	PointInt ip, pint;
	pdbl.set(1.1, 2.2);
	pint.set(3, 4);
	dp = pint;                     // Dbl = Int
	ip = pdbl;                     // Int = Dbl
	PointDbl s1 = pdbl + pint;     // Dbl + Int returns Dbl
	PointDbl s2 = pint + pdbl;     // Int + Dbl returns Dbl
	cout << "dp " << dp.getx() << "  " << dp.gety() << endl;
	cout << "ip " << ip.getx() << "  " << ip.gety() << endl;
	cout << "s1 " << s1.getx() << "  " << s1.gety() << endl;
	cout << "s2 " << s2.getx() << "  " << s2.gety() << endl;
	return 0;
}