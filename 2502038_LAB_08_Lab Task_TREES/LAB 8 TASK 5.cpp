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

    void preOrder(Node* node) {
        if (node == NULL)
            return;

        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void postOrder(Node* node) {
        if (node == NULL)
            return;

        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }

    void displayTraversals() {
        cout << "In-order Traversal   (Left, Root, Right): ";
        inOrder(root);
        cout << endl;

        cout << "Pre-order Traversal  (Root, Left, Right): ";
        preOrder(root);
        cout << endl;

        cout << "Post-order Traversal (Left, Right, Root): ";
        postOrder(root);
        cout << endl;

        cout << "\nNote: In-order traversal displays the IDs in ascending order." << endl;
    }
};

int main() {
    BST tree;

    int ids[] = {40, 20, 60, 10, 30, 50, 70};
    for (int i = 0; i < 7; i++) {
        tree.insert(ids[i]);
    }

    cout << "Patient Record IDs using different Traversals:\n" << endl;
    tree.displayTraversals();

    return 0;
}
