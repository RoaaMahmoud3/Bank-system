#ifndef ADMINMANAGER_H
#define ADMINMANAGER_H
#include <iostream>
#include <string>
#include <vector>
#include"Validation.h"
#include "Person.h"
#include "Employee.h"
#include "FileManager.h"
#include "FileHelper.h"

class AdminManager
{
public:
    static void printAdminMenu(){
        cout<<"\n============\n";
        cout<<"   Admin Menu  \n";
        cout<<"==============\n";
        cout<<"1. Add Client .\n";
        cout<<"2. Search about Client .\n";
        cout<<"3. List of Clients .\n";
        cout<<"4. Edit Client .\n";
        cout<<"5. Add Employee .\n";
        cout<<"6. Search about Employee .\n";
        cout<<"7. List of Employees .\n";
        cout<<"8. Edit Employee .\n";
        cout<<"9. Print information about Admin\n";
        cout<<"10. Log out .\n";
        cout<<"=========================\n";
    }

    static Admin* login(int id, string password){
        for(ait = allAdmins.begin(); ait != allAdmins.end() ; ait++){
            if(ait->Getid() == id && ait->Getpassword()==password) return &(*ait);
        }
        cout << "ERROR MESSAGE!\nThis account does not exist .\n";
        return NULL;
    }

    static bool AdminOptions(Admin* admin){
        printAdminMenu();
        cout<<"Enter your choice : ";
        int number;
        cin>>number;
        cout<<endl;
        Employee employee;
        Client client;
        FileManager fileManager;
        switch (number){
        case 1:
            client.Setname(Validation::Entername());
            client.Setpassword(Validation::Enterpassword());
            client.Setid(FileHelper::getLast("ClientLastId.txt")+1);
            client.Setbalance(Validation::Enterbalance());
            admin->AddClient(client);
            fileManager.UpdateClients();
            cout<<"\nClient added successfully .\n";
            break;
        case 2:{
            int id;
            cout<<"Enter client id : ";
            cin>>id;
            if(admin->SearchClient(id)== NULL){
                cout<<"\nClient not found .\n";
            }
            else{
                admin->SearchClient(id)->Display();
            }
            break;
        }
        case 3:
            //fileManager.UpdateClients();
            cout<<"All clients : \n";
            admin->ListClient();
            break;
        case 4:{
            int id;
            string name , password;
            double balance;
            cout<<"Enter id: ";
            cin>>id;
            if(admin->SearchClient(id)== NULL){
                cout<<"\nClient not found .\n";
            }
            else{
                cout<<"now you can edit information \n";
                client.Setname(Validation::Entername());
                client.Setpassword(Validation::Enterpassword());
                client.Setbalance(Validation::Enterbalance());
                admin->EditClient(id,name,password,balance);
                fileManager.UpdateClients();
            cout<<"Client information updated .\n";
            }
            break;
        }
        case 5:
            employee.Setname(Validation::Entername());
            employee.Setpassword(Validation::Enterpassword());
            employee.Setid(FileHelper::getLast("EmployeeLastId.txt")+1);
            employee.Setsalary(Validation::Entersalary());
            admin->AddEmployee(employee);
            fileManager.UpdateEmployees();
            cout<<"\nEmployee added successfully .\n";
            break;
        case 6:{
            int id;
            cout<<"Enter employee id : ";
            cin>>id;
            if(admin->SearchEmployee(id)== NULL){
                cout<<"\nEmployee not found .\n";
            }
            else{
                admin->SearchEmployee(id)->Display();
            }
            break;
        }
        case 7:
            cout<<"All employee:\n";
            admin->ListEmployee();
            break;
        case 8:{

            int id;
            string name , password;
            double salary;
            cout<<"Enter id: ";
            cin>>id;
            if(admin->SearchEmployee(id)== NULL){
                cout<<"\nEmployee not found .\n";
            }
            else{
                cout<<"now you can edit information \n";
                employee.Setname(Validation::Entername());
                employee.Setpassword(Validation::Enterpassword());
                employee.Setsalary(Validation::Entersalary());
                admin->EditEmployee(id,name,password,salary);
                fileManager.UpdateEmployees();
                cout<<"Employee information updated .\n";
            }
            break;
        }
        case 9:
            admin->Display();
            break;
        case 10:
            return false;
            break;
        default:
            cout << "Invalid option, please try again.\n";
            AdminOptions(admin);
            return true;
        }
        AdminOptions(admin);
        return true;

    }
};

#endif // ADMINMANAGER_H
