#ifndef FILEHELPER_H
#define FILEHELPER_H
#include <fstream>
#include <vector>
#include <string>
#include "Parser.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"


using namespace std;

class FileHelper {
public:
    static void SaveLast(const  string& fileName, int Id) {
         ofstream file(fileName);
        file << Id;
        file.close();
    }


    static int getLast(const  string& fileName) {
         ifstream file(fileName);
        int Id = 0;
        file >> Id;
        file.close();
        return Id;
    }

    static void saveClient(Client c) {
        int id = getLast("ClientLastId.txt");
         ofstream file("Clients.txt",  ios::app);
        file << id + 1 << '&' << c.Getname() << '&' << c.Getpassword() << '&' << c.Getbalance() <<  endl;
        file.close();
        SaveLast("ClientLastId.txt", id + 1);
    }

    static void saveEmployee(Employee e) {
        int id = getLast("EmployeeLastId.txt");
         ofstream file("Employees.txt",  ios::app);
        file << id + 1 << '&' << e.Getname() << '&' << e.Getpassword() << '&' << e.Getsalary() <<  endl;
        file.close();
        SaveLast("EmployeeLastId.txt", id + 1);
    }

    static void saveAdmin(Admin a) {
        int id = getLast("AdminLastId.txt");
         ofstream file("Admins.txt",  ios::app);
        file << id + 1 << '&' << a.Getname() << '&' << a.Getpassword() << '&' << a.Getsalary() <<  endl; // Adjust as needed
        file.close();
        SaveLast("AdminLastId.txt", id + 1);
    }

    static  vector<Client> getClients() {
         vector<Client> allClients;
         string line;
         ifstream file("Clients.txt");
        while ( getline(file, line)) {
            Client c = Parser::ParseToClient(line);
            allClients.push_back(c);
        }
        file.close();
        return allClients;
    }

    static  vector<Employee> getEmployees() {
         vector<Employee> allEmployees;
         string line;
         ifstream file("Employees.txt");
        while ( getline(file, line)) {
            Employee e = Parser::ParseToEmployee(line);
            allEmployees.push_back(e);
        }
        file.close();
        return allEmployees;
    }

    static  vector<Admin> getAdmins() {
         vector<Admin> allAdmins;
         string line;
         ifstream file("Admins.txt");
        while ( getline(file, line)) {
            Admin a = Parser::ParseToAdmin(line);
            allAdmins.push_back(a);
        }
        file.close();
        return allAdmins;
    }

    static void clearFile(const  string& fileName, const  string& lastIdFile) {
         ofstream file1(fileName,  ios::trunc);
        file1.close();
         ofstream file2(lastIdFile);
        file2 << 0;
        file2.close();
    }
};

#endif // FILEHELPER_H
