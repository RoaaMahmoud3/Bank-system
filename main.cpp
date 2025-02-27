#include<iostream>
#include<string>
#include"Validation.h"
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "FileManager.h"
#include<fstream>
using namespace std;


int main() {
    /*Client m;
    m.Setname(Validation::Entername());
    m.Setpassword(Validation::Enterpassword());
    m.Setid(Validation::Enterid());
    m.Setbalance(Validation::Enterbalance());
    m.Display();*/




    //////////////////////////////////////
    FileManager fileManager;

    // Static data for clients

    Client client1(1, "Alice44", "password123", 2000);
    Client client2(2, "Bob68", "securepass", 3000);
    Client client3(1, "Mona", "password555", 5000);

    // Adding clients
    cout << "Adding clients...\n";
    fileManager.AddClient(client1);

    fileManager.AddClient(client2);
    //fileManager.AddClient(m);

    // Static data for employees
    Employee employee1(459, "Charlie", "empPass1", 4000);
    Employee employee2(444, "David", "empPass2", 5000);
    employee1.AddClient(client3);

    // Adding employees
    cout << "\nAdding employees...\n";
    fileManager.AddEmployee(employee1);
    fileManager.AddEmployee(employee2);

    // Static data for admins
    Admin admin1(1, "Eve", "adminPass1", 6000);
    Admin admin2(2, "Frank", "adminPass2", 7000);

    // Adding admins
    cout << "\nAdding admins...\n";
    fileManager.AddAdmin(admin1);
    fileManager.AddAdmin(admin2);
    //

    // Display all clients
    cout << "\nAll Clients:\n";
    fileManager.GetAllClients();
    cout<<"\n============================================================\n";

    // Display all employees
    cout << "\nAll Employees:\n";
    fileManager.GetAllEmployees();
    cout<<"\n============================================================\n";

    // Display all admins
    cout << "\nAll Admins:\n";
    fileManager.GetAllAdmins();
    cout<<"\n============================================================\n";
    fileManager.UpdateClients();
    fileManager.UpdateEmployees();
    fileManager.UpdateEmployees();
    ///////////////
    /*(employee1.SearchClient(1))
        cout<<"\ntrue\n";

     employee1.ListClient();*/

     /////////////////////////////

    //Remove all clients
    /*cout << "\nRemoving all clients...\n";
    fileManager.RemoveAllClients();
    cout << "Clients after removal:\n";
    fileManager.GetAllClients(); // Should show no clients

    // Remove all employees
    cout << "\nRemoving all employees...\n";
    fileManager.RemoveAllEmployees();
    cout << "Employees after removal:\n";
    fileManager.GetAllEmployees(); // Should show no employees

    // Remove all admins
    cout << "\nRemoving all admins...\n";
    fileManager.RemoveAllAdmins();
    cout << "Admins after removal:\n";
    fileManager.GetAllAdmins(); // Should show no admins*/

    return 0;
}
