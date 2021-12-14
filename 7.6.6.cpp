#include <iostream>
using namespace std;
#define π 3.14

class Shape {
  public:
    virtual float Area() const = 0;
    virtual void Show() const = 0;
};

class Recrangle : public Shape {
    private:
    int h;
  public:
    Recrangle(int h) : h(h) {}
    float Area() const {
        return h;
    }
    void Show() const {}
};

class Circle : public Shape {
  private:
    int r;
  public:
    Circle(int r) : r(r) {}
    float Area() const {
        return π * r * r;
    }
    void Show() const {
        cout << "r " << r << endl;
    }
};

int main() {
    Circle circle(10);
    Shape *p = &circle;
    cout << p->Area() << endl;
    p->Show();
}