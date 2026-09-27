#include <iostream>
#include <string>
using namespace std;

class Account
{
protected:
    int accountNumber;
    string holderName;
    double balance;

public:
    Account(int accNo, string name, double bal)
    {
        accountNumber = accNo;
        holderName = name;
        balance = bal;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited Rs. " << amount << endl;
    }

    virtual void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawn Rs. " << amount << endl;
        }
        else
        {
            cout << "Insufficient Balance!" << endl;
        }
    }

    virtual double calculateInterest() = 0;

    virtual void display()
    {
        cout << "\nAccount Number : " << accountNumber << endl;
        cout << "Holder Name    : " << holderName << endl;
        cout << "Balance        : Rs. " << balance << endl;
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account
{
public:
    SavingsAccount(int accNo, string name, double bal)
        : Account(accNo, name, bal) {}

    double calculateInterest()
    {
        return balance * 0.04;
    }
};

class CurrentAccount : public Account
{
public:
    CurrentAccount(int accNo, string name, double bal)
        : Account(accNo, name, bal) {}

    double calculateInterest()
    {
        return 0;
    }
};

class FixedDepositAccount : public Account
{
public:
    FixedDepositAccount(int accNo, string name, double bal)
        : Account(accNo, name, bal) {}

    double calculateInterest()
    {
        return balance * 0.07;
    }
};

int main()
{
    SavingsAccount sa(1001, "Krishna", 50000);
    CurrentAccount ca(1002, "Rahul", 30000);
    FixedDepositAccount fda(1003, "Amit", 100000);

    cout << "===== BANKING SYSTEM =====" << endl;

    sa.display();
    cout << "Interest : Rs. " << sa.calculateInterest() << endl;

    ca.display();
    cout << "Interest : Rs. " << ca.calculateInterest() << endl;

    fda.display();
    cout << "Interest : Rs. " << fda.calculateInterest() << endl;

    return 0;
}
