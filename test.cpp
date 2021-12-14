#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.front() << " ";
    q.pop();
    cout << q.front() << endl;
}




#include <stdio.h>
class AA {
    int n;
//   private:
//     float l1;
//     float l2;
//     float l3;
//     ~Ctriangle();

  public:
    AA(int k):n(k){}
    int get(){
        return n;
    }
    int get() const {
        return n + 1;
    }
};

class test {
  public:
    test() {
        cout << 1;
    }
};

    // int i = 1;
    // // int a = 0;
    // // i += i++;
    // i += i + (i = 4);

    // // cout << i << endl;cout << a << endl;
    // printf("%d\n", i);


struct Node {
    int Data;
    Node *Next;
    Node(int x) : Data(x), Next(NULL) {}
};

typedef struct {
    int low;
    int high;
} boundary; //子序列的上下界类型
// void QSort_NotRecurve(int SQList &L) //快速排序的非递归算法
// {
//     low = 1;
//     high = L.length;
//     InitStack(S);                        // S的元素为boundary类型
//     while (low < high && !StackEmpty(S)) { //注意排序结束的条件
//         if (high - low > 2) { //如果当前子序列长度大于3且尚未排好序
//             pivot = Partition(L, low, high); //进行一趟划分
//             if (high - pivot > pivot - low) {
//                 Push(S, {pivot + 1, high}); //把长的子序列边界入栈
//                 high = pivot - 1;           //短的子序列留待下次排序
//             } else {
//                 Push(S, {low, pivot - 1});
//                 low = pivot + 1;
//             }
//         } else if (low < high &&
//                    high - low < 3) { //如果当前子序列长度小于3且尚未排好序
//             Easy_Sort(L, low, high); //直接进行比较排序
//             low = high;              //当前子序列标志为已排好序
//         } else { //如果当前子序列已排好序但栈中还有未排序的子序列
//             Pop(S, a); //从栈中取出一个子序列
//             low = a.low;
//             high = a.high;
//         }
//     }
// } // QSort_NotRecurve

// bool Compare(Person p1, Person p2) {
//     if (p1.sheng > p2.sheng) {
//         return true;
//     } else if (p1.sheng < p2.sheng) {
//         return false;
//     } else if (p1.sheng == p2.sheng) {
//         if (p1.shi > p2.shei) {
//             return true;
//         } else if (p1.shi < p2.shi) {
//             return false;
//         } else if (p1.shi == p2.shi) {
//             if (p1.sheng > p2.sheng) {
//                 return true;
//             } else {
//                 return false;
//             }
//         }
//     }
// }