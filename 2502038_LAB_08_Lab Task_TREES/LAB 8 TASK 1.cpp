#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = NULL;
        right = NULL;
    }
};

void displayTree(Node* node) {
    if (node == NULL)
        return;

    string leftName = (node->left != NULL) ? node->left->name : "None";
    string rightName = (node->right != NULL) ? node->right->name : "None";

    cout << "Person: " << node->name 
         << " | Left Child: " << leftName 
         << " | Right Child: " << rightName << endl;

    displayTree(node->left);
    displayTree(node->right);
}

int main() {
    Node* root = new Node("Ali");

    root->left = new Node("Ahmed");
    root->right = new Node("Fatima");

    root->left->left = new Node("Sara");
    root->left->right = new Node("Omar");

    root->right->left = new Node("Zain");
    root->right->right = new Node("Ayesha");

    cout << "Family Tree (Binary Tree):\n\n";
    displayTree(root);

    return 0;
}
