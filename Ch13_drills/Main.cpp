#include "Simple_window.h"
#include "Graph.h"

int main()
{
	int max_width = 800;
	int max_height = 1000;
	Simple_window win(Point{ 100,100 }, max_width, max_height, "Title");

	int x_size = win.x_max(); 
	int y_size = win.y_max();
	int x_grid = 100;
	int y_grid = 100;
	Lines grid;
	for (int x = x_grid; x < 900; x += x_grid)
		grid.add(Point{ x,0 }, Point{ x,y_size }); // vertical line
	for (int y = y_grid; y < 900; y += y_grid)
		grid.add(Point{ 0,y }, Point{ x_size,y });
	win.attach(grid);
	
	Vector_ref <Graph_lib::Rectangle> rects;
	for (int i = 0; i < 900; i += 100)
	{
		rects.push_back(new Graph_lib::Rectangle(Point{ i,i }, 100, 100));
		rects[rects.size() - 1].set_fill_color(Color::red);
		win.attach(rects[rects.size() - 1]);
	}
	Vector_ref <Image> imgs;	
	int x = 0;
	for (int i = 200; i < 700; i += 200)
	{
		imgs.push_back(new Image{ Point{ x,i },"200_200.jpeg"  });
		x += 200;
		win.attach(imgs[imgs.size() - 1]);
	}

	int xc = 0, yc=0;
	while (true)
	{
		
		for(int i=0; i<32; i++)
		{
			Image path{ Point{xc,yc},"100_100.jpeg" };
			if (i < 7)
			{
				xc += 100;
			}
			if ((i >=7) && (i<16))
			{
				yc += 100;
			}
			if ((i >= 16) && (i < 23))
			{
				xc -= 100;
			}
			if(i>=23)
			{
				yc -= 100;
			}
			win.attach(path);
			win.wait_for_button();
		}
		
	}	
}
