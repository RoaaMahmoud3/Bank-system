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
         //vector<Client> clients = FileHelper::getClients();
         FileHelper::getClients();
        for (Client client : allClients) {
            client.Display();
        }
    }

    void GetAllEmployees(){
        FileHelper::getEmployees();
        for (Employee employee : allEmployees) {
            employee.Display();
        }
    }

    void GetAllAdmins(){
        FileHelper::getAdmins();
        for (Admin admin : allAdmins) {
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
    ////////////////////////////////////////////////////////////////////
    void UpdateClients(){
        RemoveAllClients();
        for(cit= allClients.begin() ; cit != allClients.end() ; cit++)
            AddClient(*cit);
    }
    void UpdateEmployees(){
        RemoveAllEmployees();
        for(eit= allEmployees.begin() ; eit != allEmployees.end() ; eit++)
           AddEmployee(*eit);
    }
    void UpdateAdmins(){
        RemoveAllAdmins();
        for(ait= allAdmins.begin() ; ait != allAdmins.end() ; ait++)
           AddAdmin(*ait);
    }
};

#endif // FILEMANAGER_H
