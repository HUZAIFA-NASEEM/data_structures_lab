
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
void displayTree(Node* root) {
    if (root == NULL)
        return;
    cout << "Member: " << root->name << endl;
    cout << "Left Child: ";
    if (root->left != NULL)
        cout << root->left->name;
    else
        cout << "None";
    cout << endl;
    cout << "Right Child: ";
    if (root->right != NULL)
        cout << root->right->name;
    else
        cout << "None";
    cout << "\n\n";
    displayTree(root->left);
    displayTree(root->right);
}
int main() {
    Node* root = new Node("HOD");
    root->left = new Node("Coordinator A");
    root->right = new Node("Coordinator B");
    root->left->left = new Node("Faculty 1");
    root->left->right = new Node("Faculty 2");
    root->right->left = new Node("Faculty 3");
    root->right->right = new Node("Faculty 4");
    cout << "UNIVERSITY DEPARTMENT HIERARCHY\n\n";
    displayTree(root);

    return 0;
}

