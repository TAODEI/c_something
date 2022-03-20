#include <iostream>
using namespace std;

const float PI = 3.14;

class Point {
    int x, y;

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

class Circle : public Point {
  private:
    float radius;

  public:
    Circle(int x, int y, float r) : Point(x, y) {
        radius = r;
    }
    float Area() {
        return PI * radius * radius;
    }

    float Circumference() {
        return 2 * PI * radius;
    } 
};

class Cylinder : public Circle {
  private:
    float h;

  public:
    Cylinder(int x, int y, float r, float h) : Circle(x, y, r), h(h){}

    float Surface() {
        return 2 * Area() + Circumference() * h;
    }
};

int main() {
    Cylinder cylinder(1, 1, 5, 10);
    cout << cylinder.Surface() << endl;
}