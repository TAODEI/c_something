#include <iostream>


using namespace std;

// struct Node {
//     int data;
//     Node *left, *right;
//     Node(int data) : data(data) {
//         left = nullptr;
//         right = nullptr;
//     }
// };

// void adjust(Node **root) {
//     *root = (*root)->right;
// }

int main(void) {
    int d;
    FILE *p = fopen("123", "r");
    fscanf(p, "%d", &d);

    cout << d << endl;
	// Node *root = new Node(100);
    // root->right = new Node(50);
    // adjust(&root);
    // cout << root->data << endl;
}