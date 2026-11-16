
#include <iostream>
#include <algorithm>
using namespace std;
class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;
    Node(int value) {
        key = value;
        left = NULL;
        right = NULL;
        height = 1;
    }
};
class AVLTree {
public:
    int getHeight(Node* node) {
        if (node == NULL)
            return 0;
        return node->height;
    }
    int getBalance(Node* node) {
        if (node == NULL)
            return 0;

        return getHeight(node->left) -
               getHeight(node->right);
    }  
    Node* rightRotate(Node* y) {

        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = 1 + max(getHeight(y->left),
                            getHeight(y->right));
        x->height = 1 + max(getHeight(x->left),
                            getHeight(x->right));
        return x;
    }
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = 1 + max(getHeight(x->left),
                            getHeight(x->right));
        y->height = 1 + max(getHeight(y->left),
                            getHeight(y->right));
        return y;
    }
    Node* insert(Node* root, int key) {    
        if (root == NULL)
            return new Node(key);
        if (key < root->key)
            root->left = insert(root->left, key);
        else if (key > root->key)
            root->right = insert(root->right, key);
        else
            return root;   
        root->height = 1 + max(getHeight(root->left),
                               getHeight(root->right));
        int balance = getBalance(root);
        if (balance > 1 && key < root->left->key)
            return rightRotate(root);
        if (balance < -1 && key > root->right->key)
            return leftRotate(root);
        if (balance > 1 && key > root->left->key) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && key < root->right->key) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }
    void inorder(Node* root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->key << " ";
            inorder(root->right);
        }
    }
    void display(Node* root, int space = 0) {
        if (root == NULL)
            return;
        space += 5;
        display(root->right, space);
        cout << endl;
       for (int i = 5; i < space; i++)
            cout << " ";
        cout << root->key
             << " (BF=" << getBalance(root) << ")";
        display(root->left, space);
    }
};
int main() {
    AVLTree tree;
    Node* root = NULL;
    int tokens[] = {15, 25, 35, 45, 55, 65, 75};
    for (int i = 0; i < 7; i++) {
        root = tree.insert(root, tokens[i]);
    }
    cout << "In-order Traversal:\n";
    tree.inorder(root);
    cout << "\n\nFinal Balanced AVL Tree:\n";
    tree.display(root);
    cout << endl;
    return 0;
}

