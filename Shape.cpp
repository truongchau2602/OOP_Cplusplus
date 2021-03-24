#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

class Point
{
private:
    int x;
    int y;
public:
    void update(int x,int y)
    {
        this->x=x;
        this->y=y;
    }
    int get_x()
    {
        return x;
    }
    int get_y()
    {
        return y;
    }
    float compute_distance(Point p)
    {
        return sqrt(pow((x-p.get_x()),2)+pow((y-p.get_y()),2));
    }
};
class Shape
{
protected:
    Point center;
public:
    virtual float compute_area()=0;
    virtual float compute_circumference()=0;
    float compute_distance(Point p)
    {
        return center.compute_distance(p);
    }
    Point get_center()
    {
        return center;
    }
};
class Circle: public Shape
{
private:
    int r;
public:
    Circle(int x, int y,int r)
    {
        center.update(x,y);
        this ->r=r;
    }
    float compute_area()
    {
        return r*3.14*r;
    }
    float compute_circumference()
    {
        return r*2*3.14;
    }
};
class Square:public Shape
{
private:
    int side;
public:
    Square(int side,int x, int y)
    {
        center.update(x,y);
        this ->side=side;
    }
    float compute_area()
    {
        return side*side;
    }
    float compute_circumference()
    {
        return side*4;
    }
};
class Rectangle : public Shape{
private:
	int a;
	int b;
public:
	Rectangle(int x, int y, int a, int b) {
		center.update(x, y);
		this->a = a;
		this->b = b;
	}
	float compute_area() {
		return a*b;
	}
	float compute_circumference() {
		return 2*(a+b);
	}
};


int main()
{
    Shape* circle = new Circle(1,2,3);
    cout<<"Circle area ="<<circle->compute_area()<<endl;
    cout<<"Circle circumference ="<< circle->compute_circumference()<<endl;

    Shape* square = new Square(3,1,5);
    cout<<"Square area ="<<square->compute_area()<<endl;
    cout<<"Square circumference ="<< square->compute_circumference()<<endl;
    cout<<"Distance of square to circle is: "<<square->compute_distance(circle->get_center())<<endl;

    Shape* rectangle = new Rectangle(1,2,3,4);
	cout<<"Rec area "<<rectangle->compute_area()<<endl;
	cout<<"Rec circum "<<rectangle->compute_circumference()<<endl;
	cout<<"The distance of rectangle to circle is "<<rectangle->compute_distance(circle->get_center())<<endl;
    /*
    Shape* rectangle = new Rectangle(1,2,3,4);
    cout<<"Rec area ="<<rectangle->compute_area()<<endl;
    cout<<"Rec circumference ="<< rectangle->compute_circumference()<<endl;
    */

}
