#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include <string>
#include <vector>
#include"Validation.h"
#include "Person.h"
#include "Employee.h"
using namespace std;

class Admin: public Employee{
private:

public:
    Admin(){
    }
    Admin(int id , string name, string password,double  salary):Employee(id ,name,password,salary){
    }
    void AddEmployee(Employee& employee){
        allEmployees.push_back(employee);
    }
    Employee* SearchEmployee(int id){
        for(eit= allEmployees.begin() ; eit != allEmployees.end() ; eit++){
            if(eit->Getid() == id) return &(*eit);
        }
        return NULL;
    }
    void ListEmployee(){
        for(eit= allEmployees.begin() ; eit != allEmployees.end() ; eit++){
            eit->Display();
            cout<<"========\n";
        }
    }
    void EditEmployee(int id, string name, string password, double salary){
        SearchEmployee(id)->Setname(name);
        SearchEmployee(id)->Setpassword(password);
        SearchEmployee(id)->Setsalary(salary);
    }

};

static vector<Admin> allAdmins;
static vector<Admin> ::iterator ait;

#endif // ADMIN_H
