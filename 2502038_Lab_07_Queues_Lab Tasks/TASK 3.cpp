#include <iostream>
using namespace std;
const int SIZE = 5;
string patient[SIZE];
int priority[SIZE];
int count = 0;
void insertPatient()
{
    if (count == SIZE)
    {
        cout << "Queue is full!\n";
        return;
    }
    cout << "Enter patient ID: ";
    cin >> patient[count];
    cout << "Enter priority (1 is highest): ";
    cin >> priority[count];
    count++;
    cout << "Patient added successfully.\n";
}
void treatPatient()
{
    if (count == 0)
    {
        cout << "No patients waiting.\n";
        return;
    }
    int pos = 0;
    for (int i = 1; i < count; i++)
    {
        if (priority[i] < priority[pos])
        {
            pos = i;
        }
    }
    cout << "Treating patient: " << patient[pos] << endl;
    for (int i = pos; i < count - 1; i++)
    {
        patient[i] = patient[i + 1];
        priority[i] = priority[i + 1];
    }
    count--;
}
void display()
{
    if (count == 0)
    {
        cout << "No patients waiting.\n";
        return;
    }
    cout << "\nWaiting Patients:\n";
    for (int i = 0; i < count; i++)
    {
        cout << "Patient ID: " << patient[i]
             << ", Priority: " << priority[i] << endl;
    }
}
int main()
{
    int choice;
    do
    {
        cout << "\n--- Hospital Priority Queue ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Treat Patient\n";
        cout << "3. Display Patients\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                insertPatient();
                break;
            case 2:
                treatPatient();
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

