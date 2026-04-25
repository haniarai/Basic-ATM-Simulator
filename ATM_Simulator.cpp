#include <iostream>
using namespace std;

int main() {
    cout << "=================================\n";
    cout << "   Welcome to the ATM Simulator  \n";
    cout << "=================================\n\n";

    const int CORRECT_PIN = 1234;
    const int MAX_TRIES = 3;
    double balance = 1000.0;

    int pin, attempts = 0;
    bool authenticated = false;

    while (attempts < MAX_TRIES) {
        cout << "Enter your 4-digit PIN: ";
        cin >> pin;

        if (pin == CORRECT_PIN) {
            authenticated = true;
            break;
        } else {
            attempts++;
            cout << "Incorrect PIN. ";
            if (attempts < MAX_TRIES) {
                cout << "Try again (" << (MAX_TRIES - attempts) << " attempt(s) left).\n";
            } else {
                cout << "No attempts left. Exiting.\n";
            }
        }
    }

    if (!authenticated) {
        return 0; 
    }

    int choice;
    do {
        cout << "\n==== ATM Menu ====\n";
        cout << "1. Check Balance\n";
        cout << "2. Withdraw\n";
        cout << "3. Deposit\n";
        cout << "4. Exit\n";
        cout << "Select an option: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Your current balance is: PKR " << balance << "\n";
        }
        else if (choice == 2) {
            double amount;
            cout << "Enter amount to withdraw: PKR ";
            cin >> amount;

            if (amount > 0 && amount <= balance) {
                balance -= amount;
                cout << "Please collect your cash. New balance: PKR " << balance << "\n";
            } else {
                cout << "Invalid amount or insufficient funds.\n";
            }
        }
        else if (choice == 3) {
            double amount;
            cout << "Enter amount to deposit: PKR ";
            cin >> amount;

            if (amount > 0) {
                balance += amount;
                cout << "Amount deposited successfully. New balance: PKR " << balance << "\n";
            } else {
                cout << "Invalid deposit amount.\n";
            }
        }
        else if (choice == 4) {
            cout << "Thank you for using our ATM. Goodbye!\n";
        }
        else {
            cout << "Invalid option. Please select between 1-4.\n";
        }

    } while (choice != 4);

    return 0;
}

