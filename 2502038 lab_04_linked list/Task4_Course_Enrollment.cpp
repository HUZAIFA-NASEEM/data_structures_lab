#include <iostream>
using namespace std;

struct Node {
    int rollNo;
    Node* next;
    Node(int r) : rollNo(r), next(nullptr) {}
};

class CourseList {
private:
    Node* head;

public:
    CourseList() : head(nullptr) {}

    ~CourseList() {
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

    void insertAtBeginning(int rollNo) {
        Node* newNode = new Node(rollNo);
        newNode->next = head;
        head = newNode;
    }

    bool search(int rollNo) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->rollNo == rollNo) return true;
            current = current->next;
        }
        return false;
    }

    void display() const {
        if (head == nullptr) {
            cout << "No students enrolled." << endl;
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            cout << current->rollNo;
            if (current->next != nullptr) cout << " -> ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    CourseList course;
    int choice, rollNo;

    do {
        cout << "\n===== University Course Enrollment =====" << endl;
        cout << "1. Add Student (End of List)" << endl;
        cout << "2. Insert Student at Beginning" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Display Enrolled Students" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Roll Number: ";
                cin >> rollNo;
                course.addStudent(rollNo);
                cout << "Student added successfully." << endl;
                break;
            case 2:
                cout << "Enter Roll Number: ";
                cin >> rollNo;
                course.insertAtBeginning(rollNo);
                cout << "Student inserted at the beginning." << endl;
                break;
            case 3:
                cout << "Enter Roll Number to Search: ";
                cin >> rollNo;
                if (course.search(rollNo))
                    cout << "Student Found" << endl;
                else
                    cout << "Student Not Found" << endl;
                break;
            case 4:
                cout << "Enrolled Students:" << endl;
                course.display();
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
