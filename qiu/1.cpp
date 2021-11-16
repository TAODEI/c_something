#include <iostream>

using namespace std;

class ComplexNum {
private:
    double r;  // 实部
    double i;  // 虚部
public:
    ComplexNum() {}
    ComplexNum(double r, double i) : r(r), i(i) {}
    ComplexNum(const ComplexNum & c) {
        r = c.r;
        i = c.i;
    }
    ~ComplexNum() {}

    void Print() {
        cout << "real: " << r << "  imaginary: " << i << endl;
    }

    ComplexNum add(const ComplexNum & c) {
        double R = c.r + r;
        double I = c.i + i;
        return ComplexNum(R, I);
    }

};

int main() {
    ComplexNum c1(3, 4), c2(5, 8);
    ComplexNum c3;

    c3 = c1.add(c2);
    c3.Print();
}