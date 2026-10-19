#include <iostream>
using namespace std;
const int SIZE = 5;
int deque[SIZE];
int front = 0;
int rear = -1;
int count = 0;
void insertFront()
{
    if (count == SIZE)
    {
        cout << "Deque is full!\n";
    }
    else
    {
        int id;
        cout << "Enter passenger request ID: ";
        cin >> id;
        if (count == 0)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            front = (front - 1 + SIZE) % SIZE;
        }
        deque[front] = id;
        count++;
        cout << "Request added at front.\n";
    }
}
void insertRear()
{
    if (count == SIZE)
    {
        cout << "Deque is full!\n";
    }
    else
    {
        int id;
        cout << "Enter passenger request ID: ";
        cin >> id;

        if (count == 0)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % SIZE;
        }
        deque[rear] = id;
        count++;
        cout << "Request added at rear.\n";
    }
}
void deleteFront()
{
    if (count == 0)
    {
        cout << "Deque is empty!\n";
    }
    else
    {
        cout << "Removed request: " << deque[front] << endl;
        front = (front + 1) % SIZE;
        count--;
        if (count == 0)
        {
            front = 0;
            rear = -1;
        }
    }
}
void deleteRear()
{
    if (count == 0)
    {
        cout << "Deque is empty!\n";
    }
    else
    {
        cout << "Removed request: " << deque[rear] << endl;
        rear = (rear - 1 + SIZE) % SSSIZE;
        count--;
        if (count == 0)
        {
            front = 0;
            rear = -1;
        }
    }
}
void display()
{
    if (count == 0)
    {
        cout << "No passenger requests.\n";
    }
    else
    {
        cout << "Requests from front to rear: ";
        for (int i = 0; i < count; i++)
        {
            cout << deque[(front + i) % SIZE] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int choice;

    do
    {
        cout << "\n--- Train Station Deque ---\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at Rear\n";
        cout << "3. Remove from Front\n";
        cout << "4. Remove from Rear\n";
        cout << "5. Display Requests\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                insertFront();
                break;

            case 2:
                insertRear();
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}

