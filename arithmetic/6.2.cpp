//
// Created by TAODEI on 2022/3/25.
//

#include <iostream>

using namespace std;

const int n = 13;

void printPath(int path[n], int index) {
    cout << index << " ";
    if (index == 0) {
        return;
    }
    printPath(path, path[index]);
}

void getMinPath(int map[n][n]) {
    int Min[n] = {0};
    int path[n] = {0};
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (map[i][j] == 0) {
                continue;
            }
            if (Min[j] == 0) {
                path[j] = i;
                Min[j] = Min[i] + map[i][j];
                continue;
            }
            if (Min[i] + map[i][j] < Min[j]) {
                Min[j] = Min[i] + map[i][j];
                path[j] = i;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << Min[i] << " ";
    }
    cout << endl;
    cout << "path: ";
    printPath(path, 12);

}

int main() {
    int map[n][n] = {
            {0, 5, 3},
            {0, 0, 0, 1, 3, 6},
            {0, 0, 0, 0, 8, 7, 6},
            {0, 0, 0, 0, 0, 0, 0, 6, 8},
            {0, 0, 0, 0, 0, 0, 0, 3, 5},
            {0, 0, 0, 0, 0, 0, 0, 0, 3, 3},
            {0, 0, 0, 0, 0, 0, 0, 0, 8, 4},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 5},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 2},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 6},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
    };
    getMinPath(map);
}