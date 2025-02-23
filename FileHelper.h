#ifndef FILEHELPER_H
#define FILEHELPER_H
#include <fstream>
#include "Parser.h"

class FileHelper{
private:
    static void SaveLast(string fileName,int Id){
        ofstream file;
        file.open(fileName);
        file<<Id;
        file.close();
        }
public:
    static int getLast(string fileName){
        ifstream file;
        file.open(fileName);
        int Id;
        file>> Id;
        file.close();
        return Id;
    }
    static void saveClient(client c){
        int id = getLast("ClientLastId.txt");
        fstream file;
        file.open("Clients.txt", ios::app);
        file << id + 1 << '&' << c.getName() << '&' << c.getPassword() << '&' << c.getBalance() << endl;
        file.close();
        saveLast("ClientLastId.txt", id + 1);
    }
    static void saveEmployee(){
        int id = getLast(lastIdFile);
    fstream file;
    file.open(fileName, ios::app);
    file << id + 1 << '&' << e.getName() << '&' << e.getPassword() << '&' << e.getSalary() << endl;
    file.close();
    saveLast(lastIdFile, id + 1);
    }
    static void getClients(){
        string line;
    ifstream file;
    file.open("Clients.txt");
    while (getline(file, line)) {
        Client c = Parser::parseToClient(line);
        allClients.push_back(c);
    }
    file.close();
    }
    static void getemployee(){
        string line;
    ifstream file;
    file.open("Employees.txt");
    while (getline(file, line)) {
        Employee e = Parser::parseToEmployee(line);
        allEmployees.push_back(e);
    }
    static void getAdmins(){
        string line;
    ifstream file;
    file.open("Admins.txt");
    while (getline(file, line)) {
        Admin a = Parser::parseToAdmin(line);
        allAdmins.push_back(a);
    }
    file.close();
    }
    static void clearFile(string fileName,string lastIdFile){
        fstream file1, file2;
    file1.open(fileName, ios::out);
    file1.close();
    file2.open(lastIdFile, ios::out);
    file2 << 0;
    file2.close();
    }


};

#endif // FILEHELPER_H
