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
    void AddClient(Client client) override {
        FileHelper::saveClient(client);
    }

    void AddEmployee(Employee employee) override {
        int lastId = FileHelper::getLast("lastEmployeeId.txt");
        Employee newEmployee(lastId + 1, employee.Getname(), employee.Getpassword(), employee.Getsalary());
        FileHelper::saveEmployee(newEmployee);
        FileHelper::SaveLast("lastEmployeeId.txt", newEmployee.Getid());
    }

    void AddAdmin(Admin admin) override {
        FileHelper::saveAdmin(admin);
    }

    void GetAllClients() override {
         vector<Client> clients = FileHelper::getClients();
        for (Client client : clients) {
            client.Display();
        }
    }

    void GetAllEmployees() override {
         vector<Employee> employees = FileHelper::getEmployees();
        for (Employee employee : employees) {
            employee.Display();
        }
    }

    void GetAllAdmins() override {
         vector<Admin> admins = FileHelper::getAdmins();
        for (Admin admin : admins) {
            admin.Display();
        }
    }

    void RemoveAllClients() override {
        FileHelper::clearFile("Clients.txt", "ClientLastId.txt");
    }

    void RemoveAllEmployees() override {
        FileHelper::clearFile("Employees.txt", "EmployeeLastId.txt");
    }

    void RemoveAllAdmins() override {
        FileHelper::clearFile("Admins.txt", "AdminLastId.txt");
    }
};

#endif // FILEMANAGER_H
