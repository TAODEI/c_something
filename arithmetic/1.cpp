#include <iostream>
#include <list>
using namespace std;

int main() {
    int n = 100000;
    cout << rand();
    int r[n];
    for (int i = 0; i < n; i++) {
        r[i] = rand() % 10000;
    }

    int count1 = 0;
    int count2 = 0;
    list<int> l;
    for (int i = n - 1; i >= 0; i--) {
        l.push_front(r[i]);
    }

    auto it2 = l.begin();
    for (auto it1 = l.begin(); it1 != l.end(); it1++) {
        for (it2 = it1, it2++; it2 != l.end(); it2++) {
            count1++;
            if (*it1 == *it2) {
                count2++;
                l.erase(it2++);
                it2--;
            }
        }
    }

    for (auto it1 = l.begin(); it1 != l.end(); it1++) {
        cout << *it1 << " ";
    }
    cout << endl << count1 << endl << count2 << endl;
}