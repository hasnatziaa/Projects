#include <iostream>
#include <cmath>
using namespace std;

void table(int num1)
{
    cout << "\nTable of " << num1 << endl;
    for (int i = num1; i <= num1 * 10; i += num1)
        cout << i << " ";
    cout << endl;
}

int main()
{
    int num1, num2;
    int choice;
    do
    {
        cout << "\n---Advanced Calculator---" << endl;
        cout << "1.Addition 2.Subtraction 3.Multiplication 4.Division 5.Square\n6.Square root 7.Cube root 8.Remainder 9.Table 10.Exit" << endl;
        cout << "\nEnter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter 1st number : ";
            cin >> num1;
            cout << "Enter 2nd number : ";
            cin >> num2;
            cout << "\nResult = " << num1 + num2 << endl;
            break;

        case 2:
            cout << "Enter 1st number : ";
            cin >> num1;
            cout << "Enter 2nd number : ";
            cin >> num2;
            cout << "\nResult = " << num1 - num2 << endl;
            break;

        case 3:
            cout << "Enter 1st number : ";
            cin >> num1;
            cout << "Enter 2nd number : ";
            cin >> num2;
            cout << "\nResult = " << num1 * num2 << endl;
            break;

        case 4:
            cout << "Enter Dividend : ";
            cin >> num1;
            cout << "Enter Divisor : ";
            cin >> num2;
            if (num2 == 0)
                cout << "Error: Division by 0 is not possible." << endl;
            else
                cout << "\nResult = " << float(num1) / num2 << endl;
            break;

        case 5:
            cout << "Enter a number : ";
            cin >> num1;
            cout << "\nResult = " << num1 * num1 << endl;
            break;

        case 6:
            cout << "Enter a number : ";
            cin >> num1;
            cout << "\nResult = " << sqrt(num1) << endl;
            break;

        case 7:
            cout << "Enter a number : ";
            cin >> num1;
            cout << "\nResult = " << cbrt(num1) << endl;
            break;

        case 8:
            cout << "Enter Dividend : ";
            cin >> num1;
            cout << "Enter Divisor : ";
            cin >> num2;
            if (num2 == 0)
                cout << "Error: Division by 0 is not possible." << endl;
            else
                cout << "\nRemainder = " << num1 % num2 << endl;
            break;

        case 9:
            cout << "Enter a number : ";
            cin >> num1;
            table(num1);
            break;

        case 10:
            cout << "Exiting Program...";
            break;

        default:
            cout << "Invalid Choice";
            break;
        }
    } while (choice != 10);
    return 0;
}