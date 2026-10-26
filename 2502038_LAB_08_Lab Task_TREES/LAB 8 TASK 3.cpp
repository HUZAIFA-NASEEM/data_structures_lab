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

    bool search(Node* node, int key, int &comparisons) {
        if (node == NULL) {
            return false;
        }

        comparisons++;

        if (node->data == key) {
            return true;
        }
        else if (key < node->data) {
            return search(node->left, key, comparisons);
        }
        else {
            return search(node->right, key, comparisons);
        }
    }

    void searchBook(int key) {
        int comparisons = 0;
        bool found = search(root, key, comparisons);

        if (found) {
            cout << "Book Found" << endl;
        }
        else {
            cout << "Book Not Found" << endl;
        }

        cout << "Number of comparisons made: " << comparisons << endl;
    }
};

int main() {
    BST tree;

    int books[] = {40, 20, 60, 10, 30, 50, 70};
    for (int i = 0; i < 7; i++) {
        tree.insert(books[i]);
    }

    int bookID;
    cout << "Enter Book ID to search: ";
    cin >> bookID;

    tree.searchBook(bookID);

    return 0;
}
