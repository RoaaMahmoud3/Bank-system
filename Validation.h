#ifndef VALIDATION_H
#define VALIDATION_H
#include <iostream>
#include <string>
using namespace std;
class Validation
{
private:
    static bool isValidName(string name) {
        if (name.length() < 5 || name.length() > 20) return false;
        for (char c : name) {
            if (!isalpha(c)) return false;
        }
        return true;
    }

    static bool isValidPassword(string password) {
        return password.length() >= 8 && password.length() <= 20;
    }

    static bool isValidBalance(double balance) {
        return balance >= 1500;
    }

    static bool isValidSalary(double salary) {
        return salary >= 5000;
    }
    static bool isValidId(int id) {
        string idstr= to_string(id);
        return idstr.size() == 8 ;
    }

public:

    static string Entername(){
        string name;
        cout<<"Enter name: ";
        cin>>name;
        while(!isValidName(name)){
            cout<<"Invalid name! Name must be alphabetic with length between 5 and 20 .\n";
            cout<<"Enter name: ";
            cin>>name;
        }
        cout<<endl;
        return name;
    }
    static string Enterpassword(){
        string password;
        cout<<"Enter password: ";
        cin>>password;
        while(!isValidPassword(password)){
            cout << "Invalid password! Password must be between 8 and 20 characters .\n";
            cout<<"Enter password: ";
            cin>>password;
        }
        cout<<endl;
        return password;
    }
    static double Enterbalance(){
        double balance;
        cout<<"Enter balance: ";
        cin>>balance;
        while(!isValidBalance(balance)){
            cout <<"Invalid balance! Minimum balance is 1500 .\n";
            cout<<"Enter balance: ";
            cin>>balance;
        }
        cout<<endl;
        return balance;
    }
    static double Entersalary(){
        double salary;
        cout<<"Enter salary: ";
        cin>>salary;
        while(!isValidSalary(salary)){
            cout <<"Invalid salary! Minimum salary is 5000 .\n";
            cout<<"Enter salary: ";
            cin>>salary;
        }
        cout<<endl;
        return salary;
    }
    static double Enterid(){
        int id;
        cout<<"Enter id: ";
        cin>>id;
        while(!isValidId(id)){
            cout <<"Invalid Id! must be 8 numbers .\n";
            cout<<"Enter id: ";
            cin>>id;
        }
        cout<<endl;
        return id;
    }
};

#endif // VALIDATION_H
