#include <iostream>
#include <string>
using namespace std;
class Node {
public:
    string songName;
    Node* next;

    Node(const string& name) : songName(name), next(NULL) {}
};
class MusicPlaylist {
private:
    Node* tail;    
    int count;
public:
    MusicPlaylist() : tail(NULL), count(0) {}
    ~MusicPlaylist() {
        if (tail == NULL) return;
        Node* temp = tail->next;
        tail->next = NULL;   
        while (temp != NULL) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
    void addSong(const string& name) {
        Node* newNode = new Node(name);
        if (tail == NULL) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }
    void displayAll() const {
        if (tail == NULL) return;
        cout << "\nPlaylist (all songs once):\n";
        Node* temp = tail->next;
        int i = 1;
        do {
            cout << "  " << i++ << ". " << temp->songName << endl;
            temp = temp->next;
        } while (temp != tail->next);
    }
    void play(int rounds) const {
        if (tail == NULL) return;
        cout << "\nPlaying playlist for " << rounds << " complete rounds:\n";
        Node* temp = tail->next;
        for (int r = 1; r <= rounds; r++) {
            cout << "\n  --- Round " << r << " ---\n";
            for (int s = 1; s <= count; s++) {
                cout << "  Now playing: " << temp->songName << endl;
                temp = temp->next; 
            }
            cout << "  (End of round " << r << " -> continues from \""
                 << temp->songName << "\")\n";
        }
    }
};
int main() {
    MusicPlaylist playlist;
    playlist.addSong("Tum Hi Ho");
    playlist.addSong("Kun Faya Kun");
    playlist.addSong("Dil Dil Pakistan");
    playlist.addSong("Pasoori");
    playlist.addSong("Afreen Afreen");
    playlist.displayAll();
    playlist.play(2);

    return 0;
}
