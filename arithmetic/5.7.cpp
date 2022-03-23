//
// Created by TAODEI on 2022/3/20.
//
#include <iostream>

using namespace std;

int multiplication(int n, int m) {
    if (n == 1) {
        return m;
    }

    if (n % 2 == 0) {
        return multiplication(n / 2, 2 * m);
    }

    return multiplication((n - 1) / 2, 2 * m) + m;
}

int main() {
    cout << multiplication(50, 65) << " " << 50 * 65 << endl;
}