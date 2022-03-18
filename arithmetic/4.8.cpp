#include <iostream>
#include <math.h>
using namespace std;

struct P {
    int x, y;
    P(int x, int y) : x(x), y(y) {}
    P() {}
};

class Map {
  public:
    P data[10];
    int len;
    Map() {
        len = 0;
    }

    void insert(P tmp) {
        if (len == 0) {
            data[0] = tmp;
            len = 1;
            return;
        }

        int i;
        for (i = 0; i < len; i++) {
            if (tmp.x < data[i].x) {
                for (int j = len; j >= i; j--) {
                    data[j] = data[j - 1];
                }
                break;
            }
        }
        data[i] = tmp;
        len++;
    }

    void Print() {
        for (int i = 0; i < 10; i++) {
            cout << data[i].x << " ";
        }
        cout << endl;
    }

    int GetDistance(int p1, int p2) {
        return sqrt(pow(data[p1].x - data[p2].x, 2) + pow(data[p1].y - data[p2].y, 2));
    }

    int Patition(int start, int end) {
        if (end - start == 1) {
            return GetDistance(start, end);
        }

        if (end - start == 2) {
            int d1 = GetDistance(start, start + 1);
            int d2 = GetDistance(start + 1, end);
            int d3 = GetDistance(start, end);
            if (d1 < d2 && d1 < d3) {
                return d1;
            } else {
                return d3 > d2 ? d2 : d3;
            }
        }

        int mid = (start + end) / 2;
        int d = Patition(start, mid);
        int tmp = Patition(mid + 1, end);
        if (d > tmp) {
            d = tmp;
        }

        int index = 0;
        P p[10];
        for (int i = mid; i >= start && data[mid].x - data[i].x < d; i--, index++) {
            p[index] = data[i];
        }
        for (int i = mid + 1; i <= end && data[i].x - data[mid].x < d; i++, index++) {
            p[index] = data[i];
        }
        sort(p);
        for (int i = 0; i < index; i++) {
            for (int j = i + 1; j < index; j++) {
                if (p[j].y - p[i].y >= d) {
                    break;
                } else {
                    int d3 = GetDistance(i, j);
                    if (d3 < d) {
                        d = d3;
                    }
                }
            }
        }

        return d;
    }
};

int main() {
    Map m;
    for (int i = 0; i < 10; i++) {
        P tmp = P(rand() % 100, rand() % 100);
        m.insert(tmp);
    }

    m.Print();
}