#include <iostream>
#include <vector>
#include <fstream>

struct dataPoint { int x, y; };

std::vector<dataPoint> pts = {};

int func(int x)
{
	return 10 * x*x + 2 * x - 25;
}

int main()
{
	int xmin = 0, xmax = 0;

	std::cout << "Input XMIN\n";
	std::cin >> xmin;
	std::cout << "Input XMAX\n";
	std::cin >> xmax;

	if (xmin > xmax)
	{
		int buf = xmax; 
		xmax = xmin;
		xmin = buf;
	}

	int xcur = xmin;

	do
	{
		pts.push_back({xcur,func(xcur)});
		xcur++;
	} while (xcur < xmax);

	std::ofstream dataWriter("dataOutput.csv");
	for (int i = 0; i < pts.size(); i++)
	{
		dataWriter << pts[i].x << ";" << pts[i].y << "\n";
	}
	dataWriter.close();
	system("pause");
}