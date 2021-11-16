#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

class Clock {
  private:
    int h;
    int m;
    int s;
    int zone; // 范围[-12, 12] 例如 中国为+8
  public:
    Clock(int h, int m, int s, int zone) : h(h), m(m), s(s), zone(zone) {}
    Clock() {}

    void Print() {
        cout << "h:" << h << "  m:" << m << "  s:" << s << "  " << h - zone
             << endl;
    }
    bool Comp(Clock c) {
        if (h - zone > c.h - c.zone) {
            return true;
        } else if (h - zone == c.h - c.zone) {
            if (m > c.m) {
                return true;
            } else if (m == c.m) {
                if (s < c.s) {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
};

int main() {
    // 初始化随机种子
    srand((unsigned)time(NULL));
    int count = 20;

    // 定义 count 个Clock对象，其h, m, s, zone均由随机生成
    Clock *cs = new Clock[count];

    for (int i = 0; i < count; i++) {
        // rand()函数 随机生成 0 到无穷 之间的一个整数
        int h = rand() % 24;
        int m = rand() % 60;
        int s = rand() % 60;
        int zone = rand() % 25 - 12;
        Clock tmp = Clock(h, m, s, zone);
        cs[i] = tmp;
    }

    int flag;
    for (int i = 1; i < count; i++) {
        int flag = 0;
        for (int j = 0; j < count - 1; j++) {
            if (cs[j].Comp(cs[j + 1])) {
                Clock tmp = cs[j];
                cs[j] = cs[j + 1];
                cs[j + 1] = tmp;
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }

    // 显示排序后的结果
    for (int i = 0; i < count; i++) {
        cs[i].Print();
    }

    // 释放动态数组空间
    delete cs;
}