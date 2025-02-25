#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <fstream>
#include <vector>
#include <string>
#include "Parser.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "DataSourceInterface.h"
#include "FileHelper.h"

using namespace std;

class FileManager : public DataSourceInterface {
public:
    void AddClient(Client client){
        FileHelper::saveClient(client);
    }

    void AddEmployee(Employee employee){
        FileHelper::saveEmployee(employee);
    }

    void AddAdmin(Admin admin){
        FileHelper::saveAdmin(admin);
    }

    void GetAllClients(){
         vector<Client> clients = FileHelper::getClients();
        for (Client client : clients) {
            client.Display();
        }
    }

    void GetAllEmployees(){
         vector<Employee> employees = FileHelper::getEmployees();
        for (Employee employee : employees) {
            employee.Display();
        }
    }

    void GetAllAdmins(){
         vector<Admin> admins = FileHelper::getAdmins();
        for (Admin admin : admins) {
            admin.Display();
        }
    }

    void RemoveAllClients(){
        FileHelper::clearFile("Clients.txt", "ClientLastId.txt");
    }

    void RemoveAllEmployees(){
        FileHelper::clearFile("Employees.txt", "EmployeeLastId.txt");
    }

    void RemoveAllAdmins(){
        FileHelper::clearFile("Admins.txt", "AdminLastId.txt");
    }
    void UpdateClient(){
        RemoveAllClients();
        for(cit= allClients.begin() ; cit != allClients.end() ; cit++)
            AddClient(*cit);
    }
    void UpdateEmployees(){
        RemoveAllEmployees();
        for(eit= allEmployees.begin() ; eit != allEmployees.end() ; eit++)
           AddEmployee(*eit);
    }
};

#endif // FILEMANAGER_H
