#ifndef CLIENTMANGER_H
#define CLIENTMANGER_H
#include <iostream>
#include <string>
#include <vector>
#include "Employee.h"
#include "Person.h"
#include"Validation.h"
#include "FileManager.h"
class ClientManger
{
public:
    static void PrintClientMenu(){
        cout<<"      ClientMenu     \n";
        cout<<"========================\n";
        cout<<"1.Display My info"<<endl;
        cout<<"1.Check Balance"<<endl;
        cout<<"2.Update Password"<<endl;
        cout<<"3.Withdraw"<<endl;
        cout<<"4.Deposit"<<endl;
        cout<<"5.Transfer Amount"<<endl;
        cout<<"6.Logout"<<endl;
    }
    static void UpdatePassword(Person*person){
        person->Setpassword(Validation::Enterpassword());
        cout<<"\n Password Updated \n";
    }
    static Client* login(int id,string password){
        for(cit= allClients.begin() ; cit !=allClients.end() ; cit++){
            if(cit->Getid() == id && cit->Getpassword() ==password)
                return &(*cit) ;
        }
        return NULL;
    }
    static bool ClientOptions(Client* client){
        PrintClientMenu();
        cout<<"Enter your choice : ";
        Employee e;
        double amount;
        int choice,id;
        cin>>choice;
        cout<<endl;
        FileManager fileManager;
        switch(choice){
        case 1:
            client->Display();
            break;
        case 2:
            client->Checkbalance();
            break;
        case 3:
            UpdatePassword(client);
            fileManager.UpdateClients();
            break;
        case 4:{
            cout<<"Enter amount to Withdraw : ";
            cin>>amount;
            client->Withdraw(amount);
            fileManager.UpdateClients();
            break;
        }
        case 5:{
            cout<<"Enter amount to Deposit : ";
            cin>>amount;
            client->Deposit(amount);
            fileManager.UpdateClients();
            break;
        }
        case 6:{
            cout<<" Enter id : ";
            cin>>id;
            while (e.SearchClient(id) ==NULL){
                cout<<"invalid id"<<endl;
                cout<<"Enter id : ";
                cin>>id;
            }
            cout<<"Enter amount to transfer : ";
            cin>>amount;
            client->Transfer(amount , *(e.SearchClient(id)));
            fileManager.UpdateClients();
            break;
        }
        case 7:
            return false;
            break;
        default:
            cout << "Invalid option, please try again.\n";
            ClientOptions(client);
            return true;
        }
        ClientOptions(client);
        return true;
    }

};

#endif // CLIENTMANGER_H
