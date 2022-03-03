#include <iostream>
#include <list>
using namespace std;

int main() {
    int n = 10;
    int r[10] = {4, 2, 5, 12, 4, 2, 5, 4, 92, 0};

    list<int> l;
    for (int i = n - 1; i >= 0; i--) {
        l.push_front(r[i]);
    }

    auto it2 = l.begin();
    for (auto it1 = l.begin(); it1 != l.end(); it1++) {
        for (it2 = it1, it2++; it2 != l.end(); it2++) {

            if (*it1 == *it2) {

                l.erase(it2++);
                it2--;
                
                for (auto it1 = l.begin(); it1 != l.end(); it1++) {
                    cout << *it1 << " ";
                }
                cout << endl;
            }
        }
    }
}