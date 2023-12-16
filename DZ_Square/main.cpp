#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Shape 
{
public:
    virtual float area() = 0;
};

class Rectangle : public Shape
{
private:
    float length, width;

public:
    Rectangle(float l, float w) : length(l), width(w) {}

    float area() override 
    {
        return length * width;
    }
};

class Circle : public Shape 
{
private:
    float radius;

public:
    Circle(float r) : radius(r) {}

    float area() override 
    {
        return 3.14 * radius * radius;
    } 
};

class RightTriangle : public Shape 
{
private:
    float base, height;

public:
    RightTriangle(float b, float h) : base(b), height(h) {}

    float area() override 
    {
        return 0.5 * base * height;
    }
};

class Trapezoid : public Shape 
{
private:
    float a, b, height;

public:
    Trapezoid(float a_, float b_, float h_) : a(a_), b(b_), height(h_) {}

    float area() override 
    {
        return 0.5 * (a + b) * height;
    }
};

int main() 
{
    Rectangle rectangle(3.0, 4.0);
    Circle circle(5.0);
    RightTriangle triangle(4.0, 3.0);
    Trapezoid trapezoid(2.0, 5.0, 4.0);

    vector<Shape*> shapes = { &rectangle, &circle, &triangle, &trapezoid };

    for (const auto& shape : shapes) 
    {
        cout << "Area: " << shape->area() << endl;
    }

    return 0;
}