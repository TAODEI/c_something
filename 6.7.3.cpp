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
};

class Table {
  protected:
    float weight, height;

  public:
    Table(float weight, float height) : weight(weight), height(height) {}
};

class RoundTable : public Circle, public Table {
    float size;

  public:
    RoundTable(int x, int y, float r, float weight, float height)
        : Circle(x, y, r), Table(weight, height) {
        size = Area();
    }
    string GetInfo() {
        char info[100];
        sprintf(info, "infomation:\nsize: %.2f, weight: %.2f, height: %.2f\n", size, weight, height);
        return info;
    }
};

int main() {
    RoundTable table = RoundTable(2, 2, 5, 10.5, 5.5);
    auto info = table.GetInfo();
    cout << info << endl;
}