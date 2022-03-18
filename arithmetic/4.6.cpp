#include <iostream>
using namespace std;

void LeftReverse(char *a, int begin, int end) {
    for (int i = 0; i < (end - begin + 1) / 2; i++) {
        a[begin + i] ^= a[end - i] ^= a[begin + i] ^= a[end - i];
    }
    for (int i = begin; i <= end; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    char a[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

    LeftReverse(a, 0, 3 - 1);
    LeftReverse(a, 3, 8 - 1);
    LeftReverse(a, 0, 8 - 1);
    for (int i = 0; i < 8; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}