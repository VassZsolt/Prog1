#include "Simple_window.h"

double one(double x) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x * x; }
//double cos(double x) { return cos(x); }
double sloping_cos(double x) { return cos(x) + slope(x); }

int main()
{
	int xmax = 600;
	int ymax = 600;

	int x_orig = xmax / 2;
	int y_orig = ymax / 2;

	int rmin = -10;
	int rmax = 11;

	int n_points = 400;

	Simple_window win(Point(100, 100), xmax, ymax, "Function graphs");

	Point origo{ x_orig,y_orig };

	int xlength = xmax - 200;
	int ylength = ymax - 200;

	int xscale = 20, yscale = 20;

	Axis x{ Axis::x, Point{100,y_orig}, xlength, xlength / xscale, "x" };
	Axis y{ Axis::y, Point{x_orig,ylength + 100}, ylength, ylength / yscale, "y" };
	
	Graph_lib::Function s(one, rmin, rmax, origo, n_points, xscale, yscale);
	Graph_lib::Function s2(slope, rmin, rmax, origo, n_points, xscale, yscale);
	Text s2_label{ Point{140,400},"x/2" };
	Graph_lib::Function s3(square, rmin, rmax, origo, n_points, xscale, yscale);
	//Graph_lib::Function s4(cos, rmin, rmax, origo, n_points, xscale, yscale);
	Graph_lib::Function s5(sloping_cos, rmin, rmax, origo, n_points, xscale, yscale);

	x.set_color(Color::red);
	y.set_color(Color::red);
	s.set_color(Color::black);
	s2.set_color(Color::green);
	s2_label.set_color(Color::green);
	s3.set_color(Color::dark_green);
	//s4.set_color(Color::blue);
	s5.set_color(Color::yellow);

	win.attach(x);
	win.attach(y);
	win.attach(s);
	win.attach(s2);
	win.attach(s2_label);
	win.attach(s3);
	//win.attach(s4);
	win.attach(s5);

	win.wait_for_button();
}