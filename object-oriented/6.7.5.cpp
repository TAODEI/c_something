#include <iostream>
using namespace std;

class Clock {
    public:
    int H, M, S;
    void ShowTime() {
        cout << H << ":" << M << ":" << S << endl;
    }
    void SetTime(int H = 0, int M = 0, int S = 0) {
        this->H = H;
        this->M = M;
        this->S = S;
    }
    
    Clock(int H = 0, int M = 0, int S = 0) : H(H), M(M), S(S) {}
    // friend class NewClock;
};

class NewClock : protected Clock {
    public:
    NewClock(int H = 0, int M = 0, int S = 0) : Clock(H, M, S) {}

    string ShowType() {
        if (H >= 12) {
            return "PM";
        } else {
            return "AM";
        }
    }
};
