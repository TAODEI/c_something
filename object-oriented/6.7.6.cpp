#include "6.7.5.cpp"
#include <iostream>
using namespace std;

class Date {
  public:
    int y, m, d;
    Date(int y, int m, int d) : y(y), m(m), d(d) {}
    int Year() const {
        return y;
    }

    int Month() const {
        return m;
    }

    int Day() const {
        return d;
    }

    void ShowDate() {
        cout << y << "." << m << "." << d << endl;
    }
};

class ClockWithDate : protected Clock, protected Date {
  public:
    ClockWithDate(int y, int m, int d, int H = 0, int M = 0, int S = 0)
        : Date(y, m, d), Clock(H, M, S) {}
    void Show() {
        ShowDate();
        ShowTime();
    }
    void AddSeconds(int seconds) {
        int minutes = process(seconds, S, 60);
        int hours = process(minutes, M, 60);
        int days = process(hours, H, 24);
        int months = processMonthByDay(days);

        processYear(months);
    }

  private:
    int process(int num, int &attribute, int base) {
        attribute = (num + attribute) % base;
        return (num + attribute) / base;
    }

    int processMonthByDay(int day) {
        int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int tag = 1;
        if(!(y % 400) || !(y % 4) && y % 100) {
            months[1] = 29;
            tag = 0; // 用以计算润年对二月的影响, 但仍有一定问题
        }
        day += d;
        int month = 0;
        int num = months[m - 1];
        for (int i = m;; i++) {
            if (tag == 3) {
                months[1] = 29;
                tag = 0;
            }
            if (day <= num) {
                d = day - num + months[i - 1];
                break;
            }
            num += months[i];
            if (i == 2) {
                tag++;
                months[1] = 28;
            }
            if (!tag && i == 12) { // 当年是润年, 但已经过了二月
                tag = 1;
            }
            if (i == 12) {
                i = 0;
            }
            month++;
        }
        return month;
    }
    void processYear(int month) {
        int newMonth = month + m;
        m = newMonth % 12;

        if (m == 0) {
            m = 12;
        }
        y += (newMonth - m) / 12;
    }
};

int main() {
    ClockWithDate clock(2021, 10, 26, 15, 28);
    clock.Show();
    int s = 10 * 60;
    clock.AddSeconds(s);
    clock.Show();
    s *= 60; // 十小时
    clock.AddSeconds(s);
    clock.Show();
    s *= 24; // 十天
    clock.AddSeconds(s);
    clock.Show();
}