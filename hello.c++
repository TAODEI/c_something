#include <iostream>

// using namespace std;
using std::cout;
using std::endl;

class Clock{
    public:
        int Hours;
        int Minutes;
        int Seconds;
        void settime(int h,int m,int s);
        // Clock(int h,int m,int s){
        //     Hours=h;
        //     Minutes=m;
        //     Seconds=s;
        // }

};
    void Clock::settime(int h,int m,int s){
        Hours=h;
        
    }

int main() {
    Clock *pchar = new Clock[10];
    Clock c1();
    int a1, a2 = 12u;
    std::cout << "hello world!" << endl;
    cout << "hello c++" << endl;
    // std::cin >> a1 >> a2;
    cout << a2 << sizeof(long double) << endl;
    return 0;
}