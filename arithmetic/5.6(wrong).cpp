#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int data) : data(data) {
        left = nullptr;
        right = nullptr;
    }
};

class Tree {
    Node *root;
    int count;
    bool preOrder(Node* root, int ele) {
        if (ele == -1) {
            cout << root->data << " ";
            count++;
        }
        if (ele > root->data) {
            return false;
        }
        if (ele == root->data) {
            adjust(&root);
            return true;
        }

        if (root->left) {
            return preOrder(root->left, ele);
        }
        if (root->right) {
            return preOrder(root->right, ele);
        }
        return false;
    }

  public:
    void Init() {
        count = 0;
        root = new Node(100);
        root->left = new Node(50);
        root->right = new Node(15);
        root->left->left = new Node(25);
        root->left->right = new Node(5);
        root->right->left = new Node(1);
        root->right->right = new Node(2);
        root->right->right->right = new Node(0);
    }
//           100
//      50          15
//   25    5      1    2
//                      0
    void adjust(Node **root) {
        if (!(*root)->left) {
            *root = (*root)->right;
            return;
        }
        if (!(*root)->right) {
            *root = (*root)->left;
            return;
        }

        if ((*root)->left->data > (*root)->right->data) {
            (*root)->data = (*root)->left->data;
            adjust(&(*root)->left);
        } else {
            (*root)->data = (*root)->right->data;
            adjust(&(*root)->right);
        }
    }

    bool DeleteEle(int ele) {
        return preOrder(root, ele);
    }

    void Print() {
        preOrder(root, -1);
        cout << endl << count << endl;
        count = 0;
    }
};

int main() {
    Tree t;
    t.Init();
    t.Print();
    bool ok = t.DeleteEle(15);
    if (ok) {
        cout << endl;
        t.Print();
    } else {
        cout << "cant find" << endl;
    }
}
