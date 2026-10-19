#include <iostream>
using namespace std;
const int SIZE = 5;
int queue[SIZE];
int front = -1;
int rear = -1;
void enqueue()
{
    int token;
    if (rear == SIZE - 1)
    {
        cout << "Queue Overflow! No space available.\n";
    }
    else
    {
        cout << "Enter customer token number: ";
        cin >> token;
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = token;
        cout << "Customer added successfully.\n";
    }
}
void dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue Underflow! No customer waiting.\n";
    }
    else
    {
        cout << "Customer served: " << queue[front] << endl;
        front++;
        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
}
void display()
{
    if (front == -1)
    {
        cout << "No customers waiting.\n";
    }
    else
    {
        cout << "Waiting customers: ";

        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }

        cout << endl;
    }
}
void countCustomers()
{
    if (front == -1)
    {
        cout << "Number of waiting customers: 0\n";
    }
    else
    {
        cout << "Number of waiting customers: "
             << rear - front + 1 << endl;
    }
}
int main()
{
    int choice;
    do
    {
        cout << "\n--- Bank Customer Service ---\n";
        cout << "1. Add Customer\n";
        cout << "2. Serve Customer\n";
        cout << "3. Display Waiting Customers\n";
        cout << "4. Count Waiting Customers\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;

            case 4:
                countCustomers();
                break;

            case 5:
                cout << "Program ended.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);
    return 0;
}

