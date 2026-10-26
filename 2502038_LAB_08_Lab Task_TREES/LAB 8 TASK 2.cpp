#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    Node* insert(Node* node, int val) {
        if (node == NULL) {
            return new Node(val);
        }

        if (val < node->data) {
            node->left = insert(node->left, val);
        }
        else if (val > node->data) {
            node->right = insert(node->right, val);
        }

        return node;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    void inOrder(Node* node) {
        if (node == NULL)
            return;

        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    void display() {
        cout << "Roll Numbers in Ascending Order: ";
        inOrder(root);
        cout << endl;
    }
};

int main() {
    BST tree;

    int rolls[] = {45, 25, 65, 15, 35, 55, 75};
    for (int i = 0; i < 7; i++) {
        tree.insert(rolls[i]);
    }

    cout << "After inserting initial roll numbers:" << endl;
    tree.display();
 
    int r1, r2;
    cout << "\nEnter two additional roll numbers: ";
    cin >> r1 >> r2;

    tree.insert(r1);
    tree.insert(r2);

    cout << "\nAfter inserting additional roll numbers:" << endl;
    tree.display();

    return 0;
}
