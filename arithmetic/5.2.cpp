#include <iostream>

using namespace std;

int *r;
int n;
int key;

int BinSearch(int low, int high) {
    if (low > high) {
        return -1;
    }

    int mid = (low + high) / 2;
    if (r[mid] == key) {
        return mid;
    } else if (r[mid] > key) {
        return BinSearch(low, mid - 1);
    } else {
        return BinSearch(mid + 1, mid - 1);
    }

}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    r = a;
    n = 5;
    key = 0;
    int res = BinSearch(0, 5);
    cout << res << endl;
}
