//Aliem Noor
//Assignment 6B
#include <cstdlib>
#include <cmath>
#include <vector>
#include <iostream>
#include <sstream>
#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

using namespace Graph_lib;
using namespace std;

double x_cord (double r, double a ){
	double x;
	return x;
}

double y_cord (double r, double a ){
	double y,z;
	z= 200-r;
	y = 250 + z;
	return y;
}

double angle (double num, double i){
	double angle;
	return angle;
}

int main(){
	srand(time(0));
	while (true){
		int cycle;
		cout<<"Enter the number of sides for a shape: ";
		cin>> cycle;
		if(cycle<0)  break;
		Simple_window win(Point(100,100),500,500,"Program Assignment 6B");
		 shape c1(Point(250,250),200);
		 c1.set_color(rand()%232+23);
		 win.attach(c1);
		Vector_ref <shape> shape;
		for (int i=0; i< cycle;++i) {
			double gennum, r;
			gennum= rand() % 48 + 2;
			r =radius(gennum);
			for (int j = 1; j<=gennum;++j){
				double x, y, a;
				a= angle(gennum, j);
				x= x_cord(r,a);
				y= y_cord(r,a);
				shape* pr= new shape(Point(x,y),r);
				shape.push_back(pr);
				pr->set_color(rand()%232+23);
				win.attach(*pr);
			}
		}
		win.wait_for_button();
	}
	return 0;
}
