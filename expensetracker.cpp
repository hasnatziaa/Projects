#include <iostream>
#include <fstream>
using namespace std;

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

struct Expense
{
    int amount;
    string category;
    int day, month, year;
};

void saveToFile(Expense expenses[], int count)
{
    ofstream file("expenses.txt");
    for (int i = 0; i < count; i++)
    {
        file << expenses[i].amount << " "
             << expenses[i].category << " "
             << expenses[i].day << " "
             << expenses[i].month << " "
             << expenses[i].year << endl;
    }
    file.close();
}

void loadFromFile(Expense expenses[], int &count)
{
    ifstream file("expenses.txt");
    if (!file)
        return;

    while (!file.eof())
    {
        file >> expenses[count].amount >> expenses[count].category >> expenses[count].day >> expenses[count].month >> expenses[count].year;

        if (file)
            count++;
    }

    file.close();
}

void addExpense(Expense expenses[], int &count)
{
    cout << CYAN << "\n=== Add New Expense ===" << RESET << endl;

    if (count >= 30)
    {
        cout << RED << "Maximum limit reached!\n"
             << RESET;
        return;
    }
    Expense e;
    cout << WHITE << "Enter expense amount: " << RESET;
    cin >> e.amount;
    cout << BLUE << "\nChoose Category:\n"
         << RESET;
    cout << "1. Food\n2. Transport\n3. Bills\n4. Shopping\n5. Other\n";
    int c;
    cin >> c;
    switch (c)
    {
    case 1:
        e.category = "Food";
        break;
    case 2:
        e.category = "Transport";
        break;
    case 3:
        e.category = "Bills";
        break;
    case 4:
        e.category = "Shopping";
        break;
    default:
        e.category = "Other";
        break;
    }
    cout << WHITE << "Enter date (DD MM YYYY): " << RESET;
    cin >> e.day >> e.month >> e.year;
    expenses[count] = e;
    count++;
    saveToFile(expenses, count);
    cout << GREEN << "\nExpense Added Successfully!\n"
         << RESET;
}

void showExpenses(Expense expenses[], int count)
{
    cout << CYAN << "\n=== All Expenses ===" << RESET << endl;
    if (count == 0)
    {
        cout << RED << "No expenses found.\n"
             << RESET;
        return;
    }
    for (int i = 0; i < count; i++)
    {
        cout << YELLOW << "Expense " << i + 1 << ": " << RESET
             << expenses[i].amount << " (" << expenses[i].category << ") "
             << "Date: " << expenses[i].day << "/" << expenses[i].month << "/" << expenses[i].year
             << endl;
    }
}

int calculateTotal(Expense expenses[], int count)
{
    int sum = 0;
    for (int i = 0; i < count; i++)
        sum += expenses[i].amount;
    return sum;
}

int calculateDaily(Expense expenses[], int count, int d, int m, int y)
{
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        if (expenses[i].day == d && expenses[i].month == m && expenses[i].year == y)
            sum += expenses[i].amount;
    }
    return sum;
}

int dateDifference(int d1, int m1, int y1, int d2, int m2, int y2)
{
    return (y2 - y1) * 365 + (m2 - m1) * 30 + (d2 - d1);
}

int calculateRange(Expense expenses[], int count, int d, int m, int y, int days)
{
    int total = 0;
    for (int i = 0; i < count; i++)
    {
        int diff = dateDifference(expenses[i].day, expenses[i].month, expenses[i].year,
                                  d, m, y);

        if (diff >= 0 && diff < days)
            total += expenses[i].amount;
    }
    return total;
}

void showReport(Expense expenses[], int count)
{
    cout << CYAN << "\n=== Expense Report ===" << RESET << endl;

    int d, m, y;
    cout << WHITE << "Enter today's date (DD MM YYYY): " << RESET;
    cin >> d >> m >> y;

    cout << GREEN << "\nToday's Expense: " << calculateDaily(expenses, count, d, m, y) << RESET << endl;
    cout << YELLOW << "Last 7 Days Expense: " << calculateRange(expenses, count, d, m, y, 7) << RESET << endl;
    cout << RED << "Last 30 Days Expense: " << calculateRange(expenses, count, d, m, y, 30) << RESET << endl;
}

void menu(Expense expenses[], int &count)
{
    while (true)
    {
        cout << CYAN << "\n===== Expense Tracker =====" << RESET << endl;

        cout << BLUE;
        cout << "1. Add Expense\n";
        cout << "2. Show All Expenses\n";
        cout << "3. Show Total Expense\n";
        cout << "4. Daily/Weekly/Monthly Report\n";
        cout << "5. Exit\n";
        cout << RESET;

        cout << WHITE << "Enter choice: " << RESET;

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            addExpense(expenses, count);
            break;
        case 2:
            showExpenses(expenses, count);
            break;
        case 3:
            cout << GREEN << "Total Expense: "
                 << calculateTotal(expenses, count)
                 << RESET << endl;
            break;
        case 4:
            showReport(expenses, count);
            break;
        case 5:
            cout << RED << "\nExiting program...\n"
                 << RESET;
            return;
        default:
            cout << RED << "Invalid choice!\n"
                 << RESET;
        }
    }
}

int main()
{
    Expense expenses[30];
    int count = 0;
    loadFromFile(expenses, count);
    menu(expenses, count);
    return 0;
}