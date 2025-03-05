#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <string>
#include <vector>
#include"Validation.h"
#include "Person.h"
using namespace std;

class Client: public Person{
private:
    double balance;
public:

    Client() {
       this->balance = 0;
    }
    Client(int id, string name, string password, double balance) : Person(id, name, password) {
        this->balance=balance;
    }
    void Setbalance(double balance) {
        this->balance=balance;
    }
    double Getbalance() {
        return balance;
    }
    void Deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << " .\nNew Balance: " << balance << " .\n";
        }
        else {
            cout << "Invalid deposit amount! Must be positive.\n";
        }
    }

    void Withdraw(double amount) {
        if (amount <= 0) {
            cout << "Error: Withdrawal amount must be greater than 0.\n";
            return;
        }
        if (amount > balance) {
            cout << "Error: The amount must be less than balance.\n";
            return;
        }
        balance -= amount;
        cout << "Withdrawn: " << amount << " .\nNew Balance: " << balance << " .\n";
    }
    void Transfer(double amount, Client &recipient) {
        if (amount <= 0) {
            cout << "Error: Transfer amount must be greater than 0.\n";
            return;
        }

        if (amount > balance) {
            cout << "Error: The amount must be less than balance.\n";
            return;
        }
        balance -= amount;
        recipient.Deposit(amount);
        cout << "Transferred: " << amount << " to Client ID: " << recipient.Getid() << "\n";
    }
    void Checkbalance(){
        cout << "Current Balance: " << Getbalance()<< ".\n";
    }
    void Display() {
        Person::Display();
        cout << "Balance: " << Getbalance() << " .\n";
    }
};

static vector<Client> allClients;
static vector<Client> ::iterator cit;

#endif // CLIENT_H
