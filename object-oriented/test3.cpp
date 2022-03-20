#include <iostream>
#include <string.h>
using namespace std;

const int SIZE = 1000;

class Stack {
    public:
    char *stackarray;
    int tos;

    Stack() {
        stackarray = new char[SIZE];
        tos = -1;
    }

    Stack(const Stack &s) {
        stackarray = new char[SIZE];

        for (int i = 0; i < strlen(s.stackarray); i++) {
            stackarray[i] = s.stackarray[i];
        }
        tos = s.tos;
    }


    char Pop() {
        if (!IsEmpty()) {
            char last = stackarray[tos];
            tos--;
            return last;
        } else {
            return '!';
        }

    }

    bool Push(char ele) {
        if (!isFull()) {
            tos++;
            stackarray[tos] = ele;
            return true;
        } else {
            return false;
        }
    }

    char min() {
        Stack s(*this);

        char ele;
        if(!s.IsEmpty()) {
            ele = Pop();
        } else {
            return '!';
        }

        while(!s.IsEmpty()) {
            char _ = s.Pop();
            if(ele > _) {
                ele = _;
            }
        }
        return ele;
    }

    bool IsEmpty() {
        return tos == -1;
    }
    private:

    bool isFull() {
        return tos == SIZE-1;
    }
};

int main() {
    Stack s;
    s.Push('6');
    s.Push('1');

    cout << s.Pop() << endl;
    s.Push('a');
    s.Push('1');

    cout << s.min() << endl;
}