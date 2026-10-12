#include <iostream>
#include <string>
using namespace std;
class Stack
{
private:
    string pages[10];
    int top;
public:
    Stack()
    {
        top = -1;
    }
    void push(string page)
    {
        top++;
        pages[top] = page;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty!" << endl;
        }
        else
        {
            cout << "Back button pressed. Removed: "
                 << pages[top] << endl;
            top--;
        }
    }
    void display()
    {
        if (top == -1)
        {
            cout << "Browsing history is empty." << endl;
        }
        else
        {
            for (int i = top; i >= 0; i--)
            {
                cout << pages[i] << endl;
            }
        }
    }
    void displayTop()
    {
        if (top == -1)
        {
            cout << "No current page." << endl;
        }
        else
        {
            cout << "Current TOP page: " << pages[top] << endl;
        }
    }
};
int main()
{
    Stack browser;
    browser.push("Google");
    browser.push("YouTube");
    browser.push("Facebook");
    browser.push("GitHub");
    cout << "Browsing History (TOP to Bottom):" << endl;
    browser.display();
    cout << endl;
    browser.pop();
    cout << endl;
    browser.displayTop();
    cout << endl;
    cout << "Remaining Browsing History:" << endl;
    browser.display();
    return 0;
}

