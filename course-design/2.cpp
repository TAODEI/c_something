#include <iostream>

using namespace std;

class Set {
    int *val;
    int size;

public:
    int len;

    Set(int size) : size(size) {
        len = 0;
        val = new int[size];
    }

    bool operator<=(const Set &s) const {
        for (int i = 0; i < len; i++) {
            if (!s.isBelong(val[i])) {
                return false;
            }
        }

        return true;
    }

    Set operator|(const Set &s) const {

        Set tmp(size + s.size);

        tmp += s;
        tmp += *this;

        return tmp;
    }

    Set operator&(const Set &s) const {
        Set tmp(size);

        for (int i = 0; i < len; i++) {
            if (s.isBelong(val[i])) {
                tmp += val[i];
            }
        }
        return tmp;
    }

    Set operator-(const Set &s) const {
        Set tmp(size);

        for (int i = 0; i < len; i++) {
            if (!s.isBelong(val[i])) {
                tmp += val[i];
            }
        }
        return tmp;
    }

    Set operator+=(int ele) {
        if (isBelong(ele)) {
            return *this;
        }
        if (len + 1 > size) {
            size *= 2;
            auto tmp = new int[size];
            for (int i = 0; i < len; i++) {
                tmp[i] = val[i];
            }
            delete[] val;
            val = tmp;
        }

        val[len] = ele;
        len++;
        return *this;
    }

    Set operator+=(const Set &s) {
        for (int i = 0; i < s.len; i++) {
            *this += s.val[i];
        }

        return *this;
    }

    Set operator-=(int ele) {
        Set tmp(size);
        for (int i = 0; i < len; i++) {
            if (ele != val[i]) {
                cout << i << " " << val[i] << " ";
                tmp += val[i];
            }
        }
        delete[] val;
        val = tmp.val;

        return *this;
    }

    Set operator-=(const Set &s) {
        Set tmp(size);

        for (int i = 0; i < len; i++) {
            if (!s.isBelong(val[i])) {
                tmp += val[i];
            }
        }
        this->val = tmp.val;
        this->len = tmp.len;
        return *this;
    }

    bool isBelong(int ele) const {
        for (int i = 0; i < len; i++) {
            if (val[i] == ele) {
                return true;
            }
        }
        return false;
    }

    void Print() const {
        cout << "print: ";
        for (int i = 0; i < len; i++) {
            cout << val[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Set s1(20), s2(10);
    s1 += 1;
    s1 += 2;
    s1 += 3;
    s1 += 4;
    s2 += 5;
    s2 += 2;
    s2 += 6;
    s2 += 7;
    s2 += 1;

    cout << "s1 ";
    s1.Print();
    cout << "s2 ";
    s2.Print();
    auto t1 = s1 | s2;
    auto t2 = s1 & s2;
    auto t3 = s1 - s2;

    cout << "|  ";
    t1.Print();
    cout << "&  ";
    t2.Print();
    cout << "-  ";
    t3.Print();

    s1 += s2;
    cout << "+= ";
    s1.Print();
    s1 -= s2;
    cout << "-= ";
    s1.Print();
}