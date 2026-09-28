#include <iostream>
#include <string>
using namespace std;

struct Node {
    string patientId;
    Node* next;
    Node(const string& id) : patientId(id), next(nullptr) {}
};

class PatientQueue {
private:
    Node* head;

public:
    PatientQueue() : head(nullptr) {}

    ~PatientQueue() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addPatient(const string& id) {
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
            cout << "No patients waiting." << endl;
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            cout << current->patientId;
            if (current->next != nullptr) cout << " -> ";
            current = current->next;
        }
        cout << endl;
    }

    void servePatient() {
        if (head == nullptr) {
            cout << "No patients to serve." << endl;
            return;
        }
        Node* temp = head;
        cout << "Patient " << temp->patientId << " is being served." << endl;
        head = head->next;
        delete temp;
    }
};

int main() {
    PatientQueue queue;
    int choice;
    string id;

    do {
        cout << "\n===== Hospital Patient Queue =====" << endl;
        cout << "1. Add Patient" << endl;
        cout << "2. Display Waiting Patients" << endl;
        cout << "3. Serve First Patient" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Patient ID: ";
                cin >> id;
                queue.addPatient(id);
                cout << "Patient added to the queue." << endl;
                break;
            case 2:
                cout << "Waiting Patients:" << endl;
                queue.display();
                break;
            case 3:
                queue.servePatient();
                cout << "Updated Queue:" << endl;
                queue.display();
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
