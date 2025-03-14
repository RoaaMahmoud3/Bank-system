#ifndef SCREENS_H
#define SCREENS_H
#include "FileManager.h"

class Screens
{
public:
    static void bankName(){
        cout<<"\n================\n";
        cout<<"    Bloom Bank     \n";
        cout<<"================  \n";
    }
    static void welcome(){
        cout<<"WElcome\nBloom Bank is at your service .\n";
    }
    static void loginOptions(){
        cout<<"1.Client ."<<endl;
        cout<<"2.Employee ."<<endl;
        cout<<"3.Admin ."<<endl;
        cout<<"login as : ";
    }
    static int loginAs(){
        loginOptions();
        int number; // user choice
        cin>>number;
        if(number==1 || number==2 || number==3) return number;
        else{
            return loginAs();
        }
    }
    static void invalid(int c){
        cout<<"Error password or id .\n";
        loginScreen(c);
    }
    static void logout(){
        loginScreen(loginAs());
    }
    static void loginScreen(int c){
        int id;
        string password;

        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Password: ";
        cin >> password;

        switch (c) {
            case 1: {
                Client* client = ClientManger::login(id, password);
                if (client) {
                    ClientManger::ClientOptions(client);
                } else {
                    invalid(c);
                }
                break;
            }
            case 2: {
                Employee* employee = EmployeeManager::login(id, password);
                if (employee) {
                    EmployeeManager::employeeOptions(employee);
                } else {
                    invalid(c);
                }
                break;
            }
            case 3: {
                Admin* admin = AdminManager::login(id, password);
                if (admin) {
                    AdminManager::AdminOptions(admin);
                } else {
                    invalid(c);
                }
                break;
            }
            default:
                cout << "Invalid option.\n";
        }
    }
    static void runApp() {
        FileManager fileManager;
        fileManager.GetAllAdmins();
        fileManager.GetAllClients();
        fileManager.GetAllEmployees();
        bankName();
        welcome();
        int choice;
        while ((choice = loginAs()) != 0) {
            loginScreen(choice);
            cout << "Thank you for using Bloom Bank. Goodbye!\n";
            cout<<"===========================================\n";
            cout<<endl;
        }

    }

};

#endif // SCREENS_H
