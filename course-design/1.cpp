#include <iostream>
#define π 3.14
using namespace std;

class Shape {
  public:
    virtual float Area() const = 0;
    virtual void Show() const = 0;
};

class Rectangle : public Shape {
    float l, h;
    public:
    Rectangle(float l, float h) : l(l), h(h) {}
    Rectangle() {}

    float Area() const {
        return l * h / 2;
    }
    
    void Show() const {
        cout << "l:" << l << "\n" << "h:" << h << endl;
    }
};

class Circle : public Shape {
    float r;
    public:
    Circle(float r) :r(r) {}

    float Area() const {
        return π * r * r;
    }

    void Show() const {
        cout << "r:" << r << endl;
    }
};

// int main() {
//     Circle circle(10);
//     Shape *p = &circle;
//     Shape *r = new Rectangle(5, 10);
//     cout << p->Area() << " " << r->Area() << endl;
//     r->Show();
// }