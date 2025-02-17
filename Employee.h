#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include"Validation.h"
#include "Person.h"
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
};

#endif // EMPLOYEE_H
