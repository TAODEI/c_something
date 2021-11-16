#include <iostream>
using namespace std;

const float PI = 3.14;

class Point {
    int x;
    int y;

  protected:
    Point(int X, int Y) {
        x = X;
        y = Y;
    }

  public:
    int GetX() {
        return x;
    }
    int GetY() {
        return y;
    }
};

class Rectangle : protected Point {
    int length;
    int width;

  public:
    Rectangle(int x1, int y1, int x2, int y2) : Point(x1, y1) {
        length = x2 - GetX();
        width = y2 - GetY();
    }
    int Area() {
        return length * width;
    }
};

class Circle : public Point {
    float radius;

  public:
    Circle(int x, int y, float r) : Point(x, y) {
        radius = r;
    }
    float Area() {
        return PI * radius * radius;
    }
};