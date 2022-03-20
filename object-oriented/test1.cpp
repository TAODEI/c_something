#include <iostream>
using namespace std;

class Date {
  public:
    int y, m, d;
    Date(int y, int m, int d) : y(y), m(m), d(d) {}

    void NewDay() {
        d++;
        int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(!(y % 400) || !(y % 4) && y % 100) {
            months[1] = 29;
        }

        if (d > months[m-1]) {
            d -= months[m-1];
            m++;
        }
        if (m == 13) {
            m = 1;
            y++;
        }
    }
    void ShowDate() {
        cout << y << "." << m << "." << d << endl;
    }
};

int main() {
    Date data(2021, 11, 9);
    for(int i = 0; i < 100; i++) {
        data.NewDay();
    }
    data.ShowDate();
}
