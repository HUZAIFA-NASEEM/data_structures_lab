#include <iostream>
#include <string>
using namespace std;

struct Node {
    string productId;
    Node* next;
    Node(const string& id) : productId(id), next(nullptr) {}
};

class ShoppingCart {
private:
    Node* head;

public:
    ShoppingCart() : head(nullptr) {}

    ~ShoppingCart() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addProduct(const string& id) {
        Node* newNode = new Node(id);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    void display() const {
        if (head == nullptr) {
            cout << "Cart is empty." << endl;
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            cout << current->productId;
            if (current->next != nullptr) cout << " -> ";
            current = current->next;
        }
        cout << endl;
    }

    bool removeProduct(const string& id) {
        if (head == nullptr) return false;

        if (head->productId == id) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->productId != id) {
            current = current->next;
        }

        if (current->next == nullptr) return false;

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        return true;
    }
};

int main() {
    ShoppingCart cart;
    int choice;
    string id;

    do {
        cout << "\n===== Online Shopping Cart =====" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Display Cart" << endl;
        cout << "3. Remove Product" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Product ID: ";
                cin >> id;
                cart.addProduct(id);
                cout << "Product added to cart." << endl;
                break;
            case 2:
                cout << "Shopping Cart:" << endl;
                cart.display();
                break;
            case 3:
                cout << "Remove Product: ";
                cin >> id;
                if (cart.removeProduct(id)) {
                    cout << "Updated Cart:" << endl;
                    cart.display();
                } else {
                    cout << "Product not found in cart." << endl;
                }
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
