#include <iostream>
#include <string>
using namespace std;
class Stack
{
private:
    string actions[10];
    int top;
public:
    Stack()
    {
        top = -1;
    }
    void push(string action)
    {
        top++;
        actions[top] = action;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "No action to undo!" << endl;
        }
        else
        {
            cout << "Undo action: " << actions[top] << endl;
            top--;
        }
    }
    void display()
    {
        if (top == -1)
        {
            cout << "No actions available." << endl;
        }
        else
        {
            for (int i = top; i >= 0; i--)
            {
                cout << actions[i] << endl;
            }
        }
    }
    void displayTop()
    {
        if (top == -1)
        {
            cout << "No current TOP action." << endl;
        }
        else
        {
            cout << "Current TOP action: "
                 << actions[top] << endl;
        }
    }
};
int main()
{
    Stack editor;
    editor.push("Type Hello");
    editor.push("Type World");
    editor.push("Add !");
    editor.push("Delete !");
    cout << "Actions (TOP to Bottom):" << endl;
    editor.display();
    cout << endl;
    cout << "Performing two Undo operations:" << endl;
    editor.pop();
    editor.pop();
    cout << endl;
    editor.displayTop();
    cout << endl;
    cout << "Remaining Actions:" << endl;
    editor.display();
    return 0;
}

