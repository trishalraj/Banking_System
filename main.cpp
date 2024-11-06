#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class BankAccount {
    private:
        int accountNumber;
        string accountHolderName;
        double balance;

    public:
        BankAccount(int accNo, string name, double initialBalance)
            : accountNumber(accNo), accountHolderName(name), balance(initialBalance) {}

        int getAccountNumber() const { return accountNumber; }
        string getAccountHolderName() const { return accountHolderName; }
        double getBalance() const { return balance; }

        void deposit(double amount) {
            if (amount > 0) {
                balance += amount;
                cout << "Amount Rs." << amount << " deposited successfully.\n";
            } else {
                cout << "Invalid deposit amount.\n";
            }
        }

        void withdraw(double amount) {
            if (amount > 0 && amount <= balance) {
                balance -= amount;
                cout << "Amount Rs." << amount << " withdrawn successfully.\n";
            } else {
                cout << "Invalid withdrawal amount or insufficient balance.\n";
            }
        }

        void displayAccountInfo() const {
            cout << fixed << setprecision(2);
            cout << "Account Number: " << accountNumber << endl;
            cout << "Account Holder: " << accountHolderName << endl;
            cout << "Balance: Rs." << balance << endl;
        }
};

class BankSystem {
    private:
        vector<BankAccount> accounts;
        int nextAccountNumber;

    public:
        BankSystem() : nextAccountNumber(390578456) {}

        void createAccount() {
            string name;
            double initialDeposit;

            cout << "Enter account holder's name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter initial deposit amount: Rs. ";
            cin >> initialDeposit;

            if (initialDeposit >= 0) {
                BankAccount newAccount(nextAccountNumber, name, initialDeposit);
                accounts.push_back(newAccount);
                cout << "Account created successfully. Account Number: " << nextAccountNumber << "\n";
                nextAccountNumber++;
            } else {
                cout << "Initial deposit cannot be negative.\n";
            }
        }

        BankAccount* findAccount(int accountNumber) {
            for (size_t i = 0; i < accounts.size(); i++) {
                if (accounts[i].getAccountNumber() == accountNumber) {
                    return &accounts[i];
                }
            }
            return nullptr;
        }

        void depositMoney() {
            int accountNumber;
            double amount;

            cout << "Enter account number: ";
            cin >> accountNumber;

            BankAccount* account = findAccount(accountNumber);
            if (account) {
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account->deposit(amount);
            } else {
                cout << "Account not found.\n";
            }
        }

        void withdrawMoney() {
            int accountNumber;
            double amount;

            cout << "Enter account number: ";
            cin >> accountNumber;

            BankAccount* account = findAccount(accountNumber);
            if (account) {
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account->withdraw(amount);
            } else {
                cout << "Account not found.\n";
            }
        }

        void displayAccount() {
            int accountNumber;

            cout << "Enter account number: ";
            cin >> accountNumber;

            BankAccount* account = findAccount(accountNumber);
            if (account) {
                account->displayAccountInfo();
            } else {
                cout << "Account not found.\n";
            }
        }

        void displayAllAccounts() const {
            if (accounts.empty()) {
                cout << "No accounts found.\n";
                return;
            }

            for (size_t i = 0; i < accounts.size(); i++) {
                accounts[i].displayAccountInfo();
                cout << "-------------------------\n";
            }
        }
};

void displayMenu() {
    cout << "\n--- Banking System Menu ---\n";
    cout << "1. Create New Account\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Display Account Information\n";
    cout << "5. Display All Accounts\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    BankSystem bankSystem;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                bankSystem.createAccount();
                break;
            case 2:
                bankSystem.depositMoney();
                break;
            case 3:
                bankSystem.withdrawMoney();
                break;
            case 4:
                bankSystem.displayAccount();
                break;
            case 5:
                bankSystem.displayAllAccounts();
                break;
            case 6:
                cout << "Thank you for using the Banking System. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
