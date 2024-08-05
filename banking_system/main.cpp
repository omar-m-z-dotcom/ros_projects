#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Function to convert a string to lowercase
string toLower(string &str)
{
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// Function to find account index by name (case insensitive)
int findAccount(vector<string> &accountNames, string &name)
{
    for (int i = 0; i < accountNames.size(); ++i)
    {
        if (toLower(accountNames[i]) == toLower(name))
        {
            return i; // returns index if account found
        }
    }
    return -1; // returns -1 if Account not found
}

int main()
{
    vector<string> accountNames;
    vector<double> accountBalances;
    int choice;
    string name;
    double deposit, withdrawal, interestRate;

    cout << "Welcome to the Banking System!" << endl;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Create Account\n";
        cout << "2. Check Balance\n";
        cout << "3. Withdraw\n";
        cout << "4. Deposit\n";
        cout << "5. Calculate Interest\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter account name: ";
            cin >> name;
            if (findAccount(accountNames, name) != -1)
            {
                cout << "Account already exists!" << endl;
                break;
            }
            accountNames.push_back(name);
            accountBalances.push_back(0);
            cout << "Account created successfully!" << endl;
            break;
        }

        case 2:
        {
            cout << "Enter account name: ";
            cin >> name;
            int index = findAccount(accountNames, name);
            if (index == -1)
            {
                cout << "Account not found!" << endl;
                break;
            }
            cout << "Balance: $" << accountBalances[index] << endl;
            break;
        }

        case 3:
        {
            cout << "Enter account name: ";
            cin >> name;
            int index = findAccount(accountNames, name);
            if (index == -1)
            {
                cout << "Account not found!" << endl;
                break;
            }
            cout << "Enter amount to withdraw: ";
            cin >> withdrawal;
            if (withdrawal <= 0)
            {
                cout << "Invalid withdrawal amount!" << endl;
                break;
            }
            else if (withdrawal > accountBalances[index])
            {
                cout << "Insufficient balance! current balance is: $" << accountBalances[index] << endl;
                break;
            }
            accountBalances[index] -= withdrawal;
            cout << "Withdrawal successful! current balance is: $" << accountBalances[index] << endl;
            break;
        }

        case 4:
        {
            cout << "Enter account name: ";
            cin >> name;
            int index = findAccount(accountNames, name);
            if (index == -1)
            {
                cout << "Account not found!" << endl;
                break;
            }
            cout << "Enter amount to deposit: ";
            cin >> deposit;
            if (deposit <= 0)
            {
                cout << "Invalid deposit amount!" << endl;
                break;
            }
            accountBalances[index] += deposit;
            cout << "Deposit successful! current balance is: $" << accountBalances[index] << endl;
            break;
        }

        case 5:
        {
            cout << "Enter account name: ";
            cin >> name;
            int index = findAccount(accountNames, name);
            if (index == -1)
            {
                cout << "Account not found!" << endl;
                break;
            }
            cout << "Enter interest rate: ";
            cin >> interestRate;
            accountBalances[index] += accountBalances[index] * interestRate / 100;
            cout << "Interest calculated successfully! current balance is: $" << accountBalances[index] << endl;
            break;
        }

        case 6:
        {
            cout << "Exiting the program..." << endl;
            break;
        }

        default:
        {
            cout << "Invalid choice! Please enter a number between 1-6." << endl;
            break;
        }
        }
    } while (choice != 6);

    return 0;
}