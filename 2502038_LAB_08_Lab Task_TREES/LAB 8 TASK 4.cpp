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

    Node* findMin(Node* node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }

    Node* deleteNode(Node* node, int key) {
        if (node == NULL) {
            return node;
        }

        if (key < node->data) {
            node->left = deleteNode(node->left, key);
        }
        else if (key > node->data) {
            node->right = deleteNode(node->right, key);
        }
        else {
            
            if (node->left == NULL && node->right == NULL) {
                delete node;
                return NULL;
            }
         
            else if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
           
            else {
                Node* temp = findMin(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }
        return node;
    }

    void deleteEmployee(int key) {
        root = deleteNode(root, key);
    }

    void inOrder(Node* node) {
        if (node == NULL)
            return;

        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    void display() {
        cout << "Remaining Employee IDs (Ascending Order): ";
        inOrder(root);
        cout << endl;
    }
};

int main() {
    BST tree;

    int ids[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) {
        tree.insert(ids[i]);
    }

    cout << "Initial Employee IDs:" << endl;
    tree.display();

    int empID;
    cout << "\nEnter Employee ID to delete: ";
    cin >> empID;

    tree.deleteEmployee(empID);

    cout << "\nAfter Deletion:" << endl;
    tree.display();

    return 0;
}
