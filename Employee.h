#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <vector>
#include"Validation.h"
#include "Person.h"
#include "Client.h"
using namespace std;

class Employee :public Person{
private:
    double salary;
public:
    Employee(){
        this->salary=0;
    }
    Employee(int id,string name,string password,double salary):Person(id,name,password){
        this->salary=salary;
    }
    void Setsalary(double salary) {
        this->salary=salary;
    }
    double Getsalary(){
        return salary;
    }
    void Display() {
        Person::Display();
        cout<<"Salary : "<<Getsalary()<<" .\n";
    }
    void AddClient(Client& client){
        allClients.push_back(client);

    }
    Client* SearchClient(int id){
        for(cit= allClients.begin() ; cit != allClients.end() ; cit++){
            if(cit->Getid() == id) return &(*cit);
        }
        return NULL;
    }
    void ListClient(){
        for(cit= allClients.begin() ; cit != allClients.end() ; cit++){
            cit->Display();
            cout<<"========\n";
        }
    }
    void EditClient(int id, string name, string password, double balance){
        SearchClient(id)->Setname(name);
        SearchClient(id)->Setpassword(password);
        SearchClient(id)->Setbalance(balance);
    }
};

static vector<Employee> allEmployees;
static vector<Employee> ::iterator eit;
#endif // EMPLOYEE_H
