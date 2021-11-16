#include <iostream>
#include <cmath>
using namespace std;

class Point {
    int x, y;

  public:
    Point(int x, int y) : x(x), y(y) {}

    friend class Line;
};

class Line {
    Point start;
    Point end;

  public:
    Line(int x1, int y1, int x2, int y2) : start(x1, y1), end(x2, y2) {}
    double Len() {
        return hypot(start.x - end.x, start.y - end.y);
    }
};

int main() {
    auto l = Line(1, 5, 2, 6);
    cout << l.Len() << endl;
}