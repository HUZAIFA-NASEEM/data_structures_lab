#include <iostream>
using namespace std;

struct Node {
    int rollNo;
    Node* next;
    Node(int r) : rollNo(r), next(nullptr) {}
};

class StudentList {
private:
    Node* head;

public:
    StudentList() : head(nullptr) {}

    ~StudentList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addStudent(int rollNo) {
        Node* newNode = new Node(rollNo);
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
            cout << "No students registered." << endl;
            return;
        }
        cout << "Registered Students:" << endl;
        Node* current = head;
        while (current != nullptr) {
            cout << current->rollNo;
            if (current->next != nullptr) cout << " -> ";
            current = current->next;
        }
        cout << endl;
    }

    bool search(int rollNo) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->rollNo == rollNo) return true;
            current = current->next;
        }
        return false;
    }
};

int main() {
    StudentList list;
    int choice, rollNo;

    do {
        cout << "\n===== Student Registration System =====" << endl;
        cout << "1. Register Student" << endl;
        cout << "2. Display Registered Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Roll Number: ";
                cin >> rollNo;
                list.addStudent(rollNo);
                cout << "Student registered successfully." << endl;
                break;
            case 2:
                list.display();
                break;
            case 3:
                cout << "Enter Roll Number to Search: ";
                cin >> rollNo;
                if (list.search(rollNo))
                    cout << "Student Found" << endl;
                else
                    cout << "Student Not Found" << endl;
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
