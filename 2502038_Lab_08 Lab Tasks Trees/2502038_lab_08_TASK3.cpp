
#include <iostream>
#include <string>
using namespace std;
class Node {
public:
    string folder;
    Node* left;
    Node* right;
    Node(string name) {
        folder = name;
        left = NULL;
        right = NULL;
    }
};
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->folder << " ";
        inorder(root->right);
    }
}
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->folder << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->folder << " ";
    }
}
int main() {
    Node* root = new Node("Computer");
    root->left = new Node("Documents");
    root->right = new Node("Downloads");
    root->left->left = new Node("Assignments");
    root->left->right = new Node("Projects");
    root->right->left = new Node("Images");
    root->right->right = new Node("Videos");
    cout << "In-order Traversal:\n";
    inorder(root);
    cout << "\n\nPre-order Traversal:\n";
    preorder(root);
    cout << "\n\nPost-order Traversal:\n";
    postorder(root);
    return 0;
}

