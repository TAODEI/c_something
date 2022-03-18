#include <iostream>
#include "1.cpp"
using namespace std;

template <class T> class Queue {
  private:
    T *data;
    int size;
    int front, rear;
  public:
    T g(T a, T b);
    Queue(int size) : size(size) {
        data = new T[size];

        front = -1; 
        rear = -1;
    }

    bool GetHead(T &ele) {
        if (IsEmpty()) {
            return false;
        } 

        ele = data[front];
    }

    void Push(T ele) {
        if (IsFull()) {
            auto q = Queue<T>(size * 2);
            q.data = data;
            *this = q;
        }

        front = (front+1) % size;
        data[front] = ele;
        
    }
    bool Pop(T &ele) {
        if (IsEmpty()) {
            return false;
        }

        rear = (rear+1) % size;
        ele = data[rear];
        if (rear == front) {
            rear = -1;
            front = -1;
        }
        return true;
    }
    bool IsEmpty() {
        return front = -1;
    }

    bool IsFull() {
        return front == rear;
    }
};

int main() {
    Queue<Shape *>ss(10);
    for (int i = 0; i < 10; i++) {
        Shape *s;
        if (rand() % 2) {
            s = new Rectangle(rand() % 20, rand() % 20);
        } else {
            s = new Circle(rand() % 20);
        }
        ss.Push(s);
    }
}