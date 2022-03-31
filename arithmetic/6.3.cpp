//
// Created by TAODEI on 2022/3/26.
//

#include <algorithm>
#include <iostream>
using namespace std;

int zeroOneBackpack2(int value[], int weight[], int items, int volume) {
    int dp[5][6] = {0};
    for (int i = 0; i < items; i++) {
        for (int j = 0; j < volume; j++) {
            if (weight[i] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
    return dp[items - 1][volume - 1];
}
//int zeroOneBackpack(int value[], int weight[], int items, int volume) {
//    /**
//     * 0-1背包，二维数组实现
//     * */
//    int dp[items + 1][volume + 1];
//    for (int i = 1; i <= items; ++i) {
//        for (int j = 1; j <= volume; ++j) {
//            if (weight[i] > j)
//                dp[i][j] = dp[i - 1][j];
//            else
//                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
//        }
//    }
//    return dp[items][volume];
//}
int main() {
    int weight[] = {3, 2, 1, 4, 5};
    int value[] = {25, 20, 15, 40, 50};
//    cout << zeroOneBackpack(value, weight, 5, 6) << endl;
    cout << zeroOneBackpack2(value, weight, 5, 6) << endl;
}