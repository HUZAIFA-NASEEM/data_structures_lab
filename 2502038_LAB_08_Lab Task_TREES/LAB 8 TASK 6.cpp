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
private:
    Node* root;

    Node* insert(Node* node, int val, bool &inserted) {
        if (node == NULL) {
            inserted = true;
            return new Node(val);
        }

        if (val < node->data) {
            node->left = insert(node->left, val, inserted);
        }
        else if (val > node->data) {
            node->right = insert(node->right, val, inserted);
        }
        else {
            inserted = false; 
        }

        return node;
    }

    bool search(Node* node, int key) {
        if (node == NULL)
            return false;

        if (node->data == key)
            return true;
        else if (key < node->data)
            return search(node->left, key);
        else
            return search(node->right, key);
    }

    Node* findMin(Node* node) {
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int key, bool &deleted) {
        if (node == NULL) {
            deleted = false;
            return node;
        }

        if (key < node->data) {
            node->left = deleteNode(node->left, key, deleted);
        }
        else if (key > node->data) {
            node->right = deleteNode(node->right, key, deleted);
        }
        else {
            deleted = true;

          
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
                node->right = deleteNode(node->right, temp->data, deleted);
            }
        }
        return node;
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

    void destroyTree(Node* node) {
        if (node == NULL)
            return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

public:
    BST() {
        root = NULL;
    }

    ~BST() {
        destroyTree(root);
    }

    void insertProduct(int val) {
        bool inserted = false;
        root = insert(root, val, inserted);

        if (inserted)
            cout << "Product ID " << val << " inserted successfully." << endl;
        else
            cout << "Duplicate Product ID! Insertion failed." << endl;
    }

    void searchProduct(int key) {
        if (search(root, key))
            cout << "Product ID " << key << " found in inventory." << endl;
        else
            cout << "Product ID " << key << " not found." << endl;
    }

    void deleteProduct(int key) {
        bool deleted = false;
        root = deleteNode(root, key, deleted);

        if (deleted)
            cout << "Product ID " << key << " deleted successfully." << endl;
        else
            cout << "Product ID " << key << " not found. Deletion failed." << endl;
    }

    void displayInOrder() {
        if (root == NULL) {
            cout << "Inventory is empty." << endl;
            return;
        }
        cout << "In-order Traversal: ";
        inOrder(root);
        cout << endl;
    }

    void displayPreOrder() {
        if (root == NULL) {
            cout << "Inventory is empty." << endl;
            return;
        }
        cout << "Pre-order Traversal: ";
        preOrder(root);
        cout << endl;
    }

    void displayPostOrder() {
        if (root == NULL) {
            cout << "Inventory is empty." << endl;
            return;
        }
        cout << "Post-order Traversal: ";
        postOrder(root);
        cout << endl;
    }
};

int main() {
    BST inventory;
    int choice, id;

    do {
        cout << "\n===== Online Store Inventory =====" << endl;
        cout << "1. Insert a product ID" << endl;
        cout << "2. Search for a product ID" << endl;
        cout << "3. Delete a product ID" << endl;
        cout << "4. Display in-order traversal" << endl;
        cout << "5. Display pre-order traversal" << endl;
        cout << "6. Display post-order traversal" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Product ID to insert: ";
                cin >> id;
                inventory.insertProduct(id);
                break;

            case 2:
                cout << "Enter Product ID to search: ";
                cin >> id;
                inventory.searchProduct(id);
                break;

            case 3:
                cout << "Enter Product ID to delete: ";
                cin >> id;
                inventory.deleteProduct(id);
                break;

            case 4:
                inventory.displayInOrder();
                break;

            case 5:
                inventory.displayPreOrder();
                break;

            case 6:
                inventory.displayPostOrder();
                break;

            case 7:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
