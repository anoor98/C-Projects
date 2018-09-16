#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

class PointXY {
public:
	PointXY() { x = 0; y = 0; }
	void set(double a, double b) { x = a; y = b; }
	double getx() const { return x; }
	double gety() const { return y; }
private:
	double x, y;
};

void area_perimeter(const PointXY &a, double area, double perimeter) {
	perimeter = distance(a[0], a[1]) + 
				distance(a[1], a[2]) + 
				distance(a[2], a[0]);
	double s = perimeter / 2.0;
	area = sqrt(s * (s - distance(a[0], a[1]))
			* (s - distance(a[1], a[2]))
			* (s - distance(a[2], a[0])));
}

double distance(const PointXY &u, const PointXY &v) {
	double a = (u.getx() - v.getx()) * (u.getx() - v.getx());
	double b = (u.gety() - v.gety()) * (u.gety() - v.gety());
	return sqrt(a + b);
}

int main() {
	int n = 3;
	vector<PointXY> v(n);
	// set x,y coordinates
	double area, perimeter;
	area_perimeter(v, area, perimeter);               // function call
	area_perimeter(v, area, perimeter);               // call twice why not
	cout << "area = " << area << endl;
	cout << "perimeter = " << perimeter << endl;
    return 0;
}