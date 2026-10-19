#include <iostream>
using namespace std;
const int SIZE = 5;
int queue[SIZE];
int front = -1;
int rear = -1;
void enqueue()
{
    int packet;
    if ((rear + 1) % SIZE == front)
    {
        cout << "Queue is full! Cannot add packet.\n";
    }
    else
    {
        cout << "Enter packet ID: ";
        cin >> packet;
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % SIZE;
        }
        queue[rear] = packet;
        cout << "Packet added successfully.\n";
    }
}
void dequeue()
{
    if (front == -1)
    {
        cout << "Queue is empty! No packet to transmit.\n";
    }
    else
    {
        cout << "Packet transmitted: " << queue[front] << endl;

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
    }
}
void display()
{
    if (front == -1)
    {
        cout << "No packets waiting for transmission.\n";
    }
    else
    {
        cout << "Packets waiting: ";
        int i = front;
        while (true)
        {
            cout << queue[i] << " ";
            if (i == rear)
            {
                break;
            }
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
}
int main()
{
    int choice;
    do
    {
        cout << "\n--- Network Packet Management ---\n";
        cout << "1. Add Packet\n";
        cout << "2. Transmit Packet\n";
        cout << "3. Display Packets\n";
        cout << "4. Exit\n";
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
                cout << "Program ended.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);
    return 0;
}

