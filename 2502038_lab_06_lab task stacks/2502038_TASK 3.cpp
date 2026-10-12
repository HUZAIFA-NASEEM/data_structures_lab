
#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
    string patientID;
    Node* next;
    Node(string id)
    {
        patientID = id;
        next = NULL;
    }
};
class Stack
{
private:
    Node* top;
public:
    Stack()
    {
        top = NULL;
    }
    void push(string id)
    {
        Node* newNode = new Node(id);
        newNode->next = top;
        top = newNode;
    }
    void pop()
    {
        if (top == NULL)
        {
            cout << "No patient requests available." << endl;
        }
        else
        {
            Node* temp = top;
            cout << "Handled patient request: "
                 << top->patientID << endl;
            top = top->next;
            delete temp;
        }
    }
    void display()
    {
        if (top == NULL)
        {
            cout << "No patient requests available." << endl;
        }
        else
        {
            Node* temp = top;
            while (temp != NULL)
            {
                cout << temp->patientID << endl;
                temp = temp->next;
            }
        }
    }
    void displayTop()
    {
        if (top == NULL)
        {
            cout << "No TOP request available." << endl;
        }
        else
        {
            cout << "Current TOP request: "
                 << top->patientID << endl;
        }
    }
    ~Stack()
    {
        while (top != NULL)
        {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};
int main()
{
    Stack hospital;
    hospital.push("P101");
    hospital.push("P102");
    hospital.push("P103");
    hospital.push("P104");
    cout << "Patient Requests (TOP to Bottom):" << endl;
    hospital.display();
    cout << endl;
    hospital.pop();
    cout << endl;
    hospital.displayTop();
    cout << endl;
    cout << "Remaining Patient Requests:" << endl;
    hospital.display();
    return 0;
}

