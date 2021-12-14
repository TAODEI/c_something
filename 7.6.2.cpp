#include <iostream>
using namespace std;

class Location {
  public:
    int x, y;
    Location(int x, int y) : x(x), y(y) {}

    Location operator + (Location l) {
        return Location(x + l.x, y + l.y);
    }

    Location operator - (Location l) {
        return Location(x - l.x, y - l.y);
    }
};

int main() {
    Location l1(5, 5);
    Location l2(3, 10);
    l1 = l2 + l1;
    cout << l1.x << " " << l1.y << endl;
}