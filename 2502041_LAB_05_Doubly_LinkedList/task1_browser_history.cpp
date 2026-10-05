
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string website;
    Node* prev;
    Node* next;

    Node(const string& site) : website(site), prev(NULL), next(NULL) {}
};

class BrowserHistory {
private:
    Node* head;     
    Node* tail;     
    Node* current;  
public:
    BrowserHistory() : head(NULL), tail(NULL), current(NULL) {}

    ~BrowserHistory() {
        Node* temp = head;
        while (temp != NULL) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
    void visit(const string& site) {
        Node* newNode = new Node(site);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        current = tail;
    }  
    void displayForward() const {
        cout << "\nHistory (First Visited -> Last Visited):\n";
        Node* temp = head;
        int i = 1;
        while (temp != NULL) {
            cout << "  " << i++ << ". " << temp->website << endl;
            temp = temp->next;
        }
    }   
    void displayBackward() const {
        cout << "\nHistory (Last Visited -> First Visited):\n";
        Node* temp = tail;
        int i = 1;
        while (temp != NULL) {
            cout << "  " << i++ << ". " << temp->website << endl;
            temp = temp->prev;
        }
    }
    void goBack() {
        if (current != NULL && current->prev != NULL) {
            current = current->prev;
            cout << "Back    -> " << current->website << endl;
        } else {
            cout << "Back    -> No earlier page (already at first page)\n";
        }
    }

    
    void goForward() {
        if (current != NULL && current->next != NULL) {
            current = current->next;
            cout << "Forward -> " << current->website << endl;
        } else {
            cout << "Forward -> No later page (already at last page)\n";
        }
    }

    void showCurrent() const {
        if (current) cout << "Current page: " << current->website << endl;
    }
};
int main() {
    BrowserHistory history;

    history.visit("www.google.com");
    history.visit("www.youtube.com");
    history.visit("www.github.com");
    history.visit("www.stackoverflow.com");
    history.visit("www.wikipedia.org");

    history.displayForward();
    history.displayBackward();

    cout << "\n--- Navigation using prev and next pointers ---\n";
    history.showCurrent();
    history.goBack();
    history.goBack();
    history.goForward();
    history.goBack();
    history.goBack();
    history.goBack();   
    history.goBack();   
    history.goForward();
    history.showCurrent();

    return 0;
}
