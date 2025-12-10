#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class BankAccount {
private:
    double balance;

public:
    // Constructor - initializes balance to 0
    BankAccount() {
        balance = 0.0;
    }

    // Method to deposit funds into the account
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << fixed << setprecision(2);
            cout << "Deposited: $" << amount << endl;
            cout << "New Balance: $" << balance << endl;
            saveTransaction("Deposit", amount);
        }
        else {
            cout << "Invalid deposit amount. Must be positive." << endl;
        }
    }

    // Method to make a purchase (deduct from balance)
    void makePurchase(string item, double cost) {
        if (cost <= 0) {
            cout << "Invalid purchase amount." << endl;
            return;
        }

        if (cost > balance) {
            cout << "Insufficient funds for " << item << endl;
            cout << "Purchase amount: $" << cost << endl;
            cout << "Available balance: $" << balance << endl;
        }
        else {
            balance -= cost;
            cout << "Purchased " << item << " for $" << cost << endl;
            cout << "Remaining Balance: $" << balance << endl;
            saveTransaction("Purchase - " + item, cost);
        }
    }

    // Method to display current balance
    void displayBalance() {
        cout << fixed << setprecision(2);
        cout << "\n==================================" << endl;
        cout << "Current Balance: $" << balance << endl;
        cout << "==================================" << endl;
    }

    // Method to save each transaction to a file
    void saveTransaction(string type, double amount) {
        ofstream file("transactions.txt", ios::app);  // Open in append mode

        if (file.is_open()) {
            file << fixed << setprecision(2);
            file << type << ": $" << amount << endl;
            file.close();
        }
        else {
            cout << "Error: Unable to save transaction to file." << endl;
        }
    }
};

int main() {
    cout << "===== Bank Account Simulation =====" << endl;
    cout << endl;

    // Create a BankAccount object
    BankAccount myAccount;

    // Add initial deposit
    cout << "--- Initial Deposit ---" << endl;
    myAccount.deposit(100.00);
    cout << endl;

    // Make first purchase
    cout << "--- Purchase 1 ---" << endl;
    myAccount.makePurchase("Coffee", 4.50);
    cout << endl;

    // Make second purchase
    cout << "--- Purchase 2 ---" << endl;
    myAccount.makePurchase("Book", 25.00);
    cout << endl;

    // Make third purchase
    cout << "--- Purchase 3 ---" << endl;
    myAccount.makePurchase("Lunch", 12.75);
    cout << endl;

    // Display final balance
    cout << "--- Final Account Status ---" << endl;
    myAccount.displayBalance();
    cout << endl;

    cout << "All transactions have been saved to transactions.txt" << endl;

    return 0;
}