#include <iostream>

using namespace std;

class Shape
{
protected:
	int width;
	int height;

	Shape(int width, int height)
	{
		this->width = width;
		this->height = height;
	}
};

class Rectangle : public Shape
{
public:
	Rectangle(int width, int height) : Shape(width, height)
	{
	}

	float Area()
	{
		return width * height;
	}
};

class Triangle : public Shape
{
public:
	Triangle(int width, int height) : Shape(width, height)
	{
	}

	float Area()
	{
		return 0.5 * width * height;
	}
};

class Display1
{
public:
	void Display()
	{
		cout << "I'm from Display1" << endl;
	}
};

class Display2
{
public:
	void Display()
	{
		cout << "I'm from Display2" << endl;
	}
};


int main()
{
	Rectangle r(5,7);
	cout << r.Area() << endl;
	Triangle t(5,7);
	cout << t.Area() << endl;
	Display2 alpha;
	alpha.Display();
	return 0;
}