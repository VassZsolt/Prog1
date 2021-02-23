#include "Simple_window.h" 
#include "Graph.h" 

int main()
{
	Point tl{ 100,100 };
	Simple_window win{ tl,600,400," My window" };
	
	Axis xa{ Axis::x, Point{20,200}, 560, 28, "x axis" };
	xa.set_color(Color::black);
	win.attach(xa); 
	Axis ya{ Axis::y, Point{300,380}, 360, 18, "y axis" };
	ya.set_color(Color::black);
	win.attach(ya); 

	Graph_lib::Polygon poly; 
	poly.add(Point{ 310,150 }); 
	poly.add(Point{ 360,50 });
	poly.add(Point{ 410,150 });
	poly.set_color(Color::red);
	win.attach(poly);

	Graph_lib::Rectangle r{ Point{100,100}, 100, 50 };
	r.set_color(Color::blue);
	r.set_fill_color(Color::yellow);
	r.set_style(Line_style(Line_style::dash, 2));
	win.attach(r);

	Closed_polyline poly_rect;
	poly_rect.add(Point{ 50,300 });
	poly_rect.add(Point{ 100,300 });
	poly_rect.add(Point{ 100,350 });
	poly_rect.add(Point{ 50,350 });
	poly_rect.add(Point{ 80,330 });
	poly_rect.set_color(Color::dark_green);
	win.attach(poly_rect);

	Text t{ Point{100,170}, "Best graphic ever" };
	t.set_color(Color::dark_blue);
	t.set_font(Font::times_bold);
	t.set_font_size(20);
	win.attach(t);

	Image img{ Point{10,10},"image2.jpg" };
	win.attach(img);

	win.wait_for_button();
}