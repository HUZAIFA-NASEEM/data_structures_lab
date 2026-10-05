#include <iostream>
#include <string>
using namespace std;
class Node {
public:
    string playerName;
    Node* next;

    Node(const string& name) : playerName(name), next(NULL) {}
};
class GameTurns {
private:
    Node* tail;  
public:
    GameTurns() : tail(NULL) {}
    ~GameTurns() {
        if (tail == NULL) return;
        Node* temp = tail->next;  
        tail->next = NULL;         
        while (temp != NULL) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
    void addPlayer(const string& name) {
        Node* newNode = new Node(name);
        if (tail == NULL) {
            tail = newNode;
            tail->next = tail;         
        } else {
            newNode->next = tail->next;
            tail->next = newNode;      
            tail = newNode;           
        }
    }
    void displayTurns() const {
        if (tail == NULL) return;
        cout << "\nEach player's turn (once):\n";
        Node* temp = tail->next;
        int turn = 1;
        do {
            cout << "  Turn " << turn++ << ": " << temp->playerName << endl;
            temp = temp->next;
        } while (temp != tail->next);
    }

    void demonstrateCircular(int totalTurns) const {
        if (tail == NULL) return;
        cout << "\nSimulating " << totalTurns << " turns (wrap-around demo):\n";
        Node* temp = tail->next;
        for (int i = 1; i <= totalTurns; i++) {
            cout << "  Turn " << i << ": " << temp->playerName;
            if (temp == tail)
                cout << "   <-- last player, next turn goes back to first";
            cout << endl;
            temp = temp->next;
        }
        cout << "\nLast player's next pointer points to: "
             << tail->next->playerName << " (the first player)\n";
    }
};
int main() {
    GameTurns game;
    game.addPlayer("Ali");
    game.addPlayer("Sara");
    game.addPlayer("Huzaifa");
    game.addPlayer("Ahmed");
    game.addPlayer("Zainab");

    game.displayTurns();
    game.demonstrateCircular(8);

    return 0;
}
