#include <iostream>
using namespace std;
void addExpense(int expenses[], int &count)
{
    if (count >= 30)
    {
        cout << "\nMaximum limit reached! Cannot add more expenses.\n";
        return;
    }
    int amount;
    cout << "Enter expense amount: ";
    cin >> amount;
    if (amount <= 0)
    {
        cout << "Invalid amount.\n";
        return;
    }
    expenses[count] = amount;
    count++;
    cout << "Expense added!\n";
}
void showExpenses(int expenses[], int count)
{
    if (count == 0)
    {
        cout << "\nNo expenses recorded.\n";
        return;
    }
    cout << "\nList of Expenses:\n";
    for (int i = 0; i < count; i++)
    {
        cout << "Expense " << i + 1 << ": " << expenses[i] << endl;
    }
}
int calculateTotal(int expenses[], int count)
{
    int total = 0;
    for (int i = 0; i < count; i++)
    {
        total += expenses[i];
    }
    return total;
}
void menu(int expenses[], int &count)
{
    int choice;
    cout << "\n===== Daily Expense Tracker =====\n";
    cout << "1. Add Expense\n2. Show All Expenses\n3. Show Total\n4. Exit" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    if (choice == 1)
    {
        addExpense(expenses, count);
    }
    else if (choice == 2)
    {
        showExpenses(expenses, count);
    }
    else if (choice == 3)
    {
        cout << "Total Expense: "
             << calculateTotal(expenses, count) << endl;
    }
    else if (choice == 4)
    {
        cout << "Exiting program...\n";
        return;
    }
    else
    {
        cout << "Invalid choice!\n";
    }
    menu(expenses, count);
}
int main()
{
    int expenses[30];
    int count = 0;
    menu(expenses, count);
    return 0;
}