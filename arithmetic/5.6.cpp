//
// Created by TAODEI on 2022/3/23.
//

#include <iostream>
#include <iterator>

using namespace std;

class Heap {
    int data[100];
    int len;
public:
    Heap() {
        int tmp[] = {100, 50, 15, 25, 5, 1, 2, 16};
        copy(begin(tmp), end(tmp), begin(data));
        len = 8;
    }

    void Print() {
        for (int i = 0; i < len; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    bool DeleteEle(int index) {
        if (index >= len) {
            return false;
        }

        data[index] = data[len - 1];
        len--;
        int root = (index - 1) / 2;
        if (data[root] < data[index]) {
            toUp(root, index);
        } else {
            toDown(index);
        }
        return true;
    }

    void toUp(int root, int child) {
        if (data[root] >= data[child]) {
            return;
        }
        data[root] ^= data[child] ^= data[root] ^= data[child];
        if (root == 0) {
            return;
        }
        toUp((child - 1) / 2, child);
    }

    void toDown(int root) {
        int child = (root + 1) * 2;
        if (child > len) {
            return;
        }
        if (child == len) {
            if (data[child-1] > data[root]) {
                data[root] ^= data[child-1] ^= data[root] ^= data[child-1];
            }
            return;
        }
        int max = data[child - 1] > data[child] ? child - 1: child;
        data[root] ^= data[max] ^= data[root] ^= data[max];

        toDown(max);
    }

};

//           100
//      50          15
//   25    5      1    2
//  16
int main() {
    Heap h = Heap();
    h.Print();
    bool ok = h.DeleteEle(0);
    if (ok) {
        cout << endl;
        h.Print();
    } else {
        cout << "not found" << endl;
    }
}
