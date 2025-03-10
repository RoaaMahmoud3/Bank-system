#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include <iostream>
#include <string>
#include "Employee.h"
#include "Client.h"
#include "Validation.h"
#include "FileManager.h"
#include "FileHelper.h"
#include "ClientManger.h"

using namespace std;

class EmployeeManager {
public:
    static void printEmployeeMenu() {
        cout<<"\n============\n";
        cout<<"   Employee Menu  \n";
        cout<<"==============\n";
        cout << "1. New Client\n";
        cout << "2. List All Clients\n";
        cout << "3. Search for Client\n";
        cout << "4. Edit Client Info\n";
        cout << "5. Update Password .\n";
        cout << "6. Print information about Employee .\n";
        cout << "7. Logout\n";
        cout << "Choose an option: ";
    }

    static void newClient(Employee* employee) {
        Client client;
        client.Setname(Validation::Entername());
        client.Setpassword(Validation::Enterpassword());
        client.Setid(FileHelper::getLast("ClientLastId.txt")+1);
        client.Setbalance(Validation::Enterbalance());
        employee->AddClient(client);
        cout << "Client added.\n";
    }

    static void listAllClients(Employee* employee) {
        employee->ListClient();
    }

    static void searchForClient(Employee* employee) {
        int id;
        cout << "Enter Client ID: ";
        cin >> id;
        Client* client = employee->SearchClient(id);
        if (client) {
            client->Display();
        } else {
            cout << "Client not found.\n";
        }
    }

    static void editClientInfo(Employee* employee) {
        int id;
        cout << "Enter Client ID to edit: ";
        cin >> id;
        Client* client = employee->SearchClient(id);
        if (client) {
            string name = Validation::Entername();
            string password = Validation::Enterpassword();
            double balance = Validation::Enterbalance();
            employee->EditClient(id, name, password, balance);
            cout << "Client updated.\n";
        } else {
            cout << "Client not found.\n";
        }
    }

    static Employee* login(int id, string password) {
        for(eit= allEmployees.begin() ; eit != allEmployees.end() ; eit++){
            if(eit->Getid() == id) return &(*eit);
        }
        cout << "Login failed.\n";
        return NULL;
    }

    static bool employeeOptions(Employee* employee) {
        while (true) {
            printEmployeeMenu();
            FileManager fileManager;
            int choice;
            cin >> choice;
            switch (choice) {
                case 1:
                    newClient(employee);
                    fileManager.UpdateClients();
                    break;
                case 2:
                    listAllClients(employee);
                    break;
                case 3:
                    searchForClient(employee);
                    break;
                case 4:
                    editClientInfo(employee);
                    fileManager.UpdateClients();
                    break;
                case 5:
                    ClientManger::UpdatePassword(employee);
                    fileManager.UpdateEmployees();
                    break;
                case 6:
                    employee->Display();
                    break;
                case 7:
                    return false; // Logout
                default:
                    cout << "Invalid choice.\n";
                    employeeOptions(employee);
                    return true;
            }
        }
    }
};

#endif // EMPLOYEEMANAGER_H

