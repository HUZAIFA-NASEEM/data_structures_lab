
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string imageName;
    Node* prev;
    Node* next;

    Node(const string& name) : imageName(name), prev(NULL), next(NULL) {}
};

class ImageGallery {
private:
    Node* head;     
    Node* tail;     
    Node* current; 

public:
    ImageGallery() : head(NULL), tail(NULL), current(NULL) {}

    ~ImageGallery() {
        Node* temp = head;
        while (temp != NULL) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }

    void addImage(const string& name) {
        Node* newNode = new Node(name);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void displayForward() const {
        cout << "\nGallery (First -> Last):\n";
        Node* temp = head;
        int i = 1;
        while (temp != NULL) {
            cout << "  " << i++ << ". " << temp->imageName << endl;
            temp = temp->next;
        }
    }

    void displayBackward() const {
        cout << "\nGallery (Last -> First):\n";
        Node* temp = tail;
        int i = 1;
        while (temp != NULL) {
            cout << "  " << i++ << ". " << temp->imageName << endl;
            temp = temp->prev;
        }
    }
    void startViewing() {
        current = head;
        cout << "\nViewing starts at: " << current->imageName << endl;
    }
    void nextImage() {
        if (current && current->next) {
            current = current->next;
            cout << "  [next] -> " << current->imageName << endl;
        } else {
            cout << "  [next] -> Already at the last image\n";
        }
    }

    void previousImage() {
        if (current && current->prev) {
            current = current->prev;
            cout << "  [prev] -> " << current->imageName << endl;
        } else {
            cout << "  [prev] -> Already at the first image\n";
        }
    }
};
int main() {
    ImageGallery gallery;

    gallery.addImage("sunset.jpg");
    gallery.addImage("mountain.png");
    gallery.addImage("beach.jpg");
    gallery.addImage("city_night.png");
    gallery.addImage("forest.jpg");
    gallery.displayForward();    
    gallery.displayBackward();   
    cout << "\n--- Moving in both directions using next and prev ---";
    gallery.startViewing();
    gallery.nextImage();
    gallery.nextImage();
    gallery.nextImage();
    gallery.previousImage();
    gallery.previousImage();
    gallery.previousImage();
    gallery.previousImage();   
    gallery.previousImage();   

    return 0;
}
