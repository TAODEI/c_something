//
// Created by TAODEI on 2022/3/30.
//

#include <algorithm>
#include <iostream>

using namespace std;

int ackermann(int m, int n) {
    int dp[m];
    for (int i = 0; i < m; i++) {
        dp[i] = i + 1;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {

            dp[j] = dp[j - 1] + ((m - 2) * m);
        }
    }
}

int Ackermann(int m, int n) {
    if (m == 0) {
        return n + 1;
    }
    if (n == 0) {
        return Ackermann(m - 1, 1);
    }
    return Ackermann(m - 1, Ackermann(m, n - 1));
}

int main() {
//    cout << Ackermann(1, 3) << endl;
    int m = 4;
    int n = 7;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << Ackermann(i, j) << " ";
        }
        cout << endl;
    }
    // 2, 3
    // 1, (2, 2)
    // (1, (1, (2, 1)))
    // (1, (1, (1, (2, 0))))  2, 0 == 1, 1 == 3
    // (1, (1, (1, (0, (1, 0))))) 1, 0 == 0, 1 == 2
    // (1, (1, (1, 3)))
}