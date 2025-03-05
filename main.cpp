#include<iostream>
#include<string>
#include<vector>
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

    Client client1(100, "Alice44", "password123", 2000);
    Client client2(235, "Bob68", "securepass", 3000);
    Client client3(101, "Mona", "password555", 5000);
    Client client4(102, "yasser", "password589", 5000);

    // Static data for employees
    Employee employee1(459, "Charlie", "empPass1", 4000);
    Employee employee2(444, "David", "empPass2", 5000);
    Employee employee3(455, "Ali", "empss2", 5000);

    ///////////////////////////////////////////////

    // Static data for admins
    Admin admin1(1, "Eve", "adminPass1", 6000);
    Admin admin2(2, "Frank", "adminPass2", 7000);

    // Adding admins
    cout << "\nAdding admins...\n";
    fileManager.AddAdmin(admin1);
    fileManager.AddAdmin(admin2);
    //

    // Adding clients
    cout << "\nAdding clients...\n";
    employee1.AddClient(client3);
    employee1.AddClient(client2);
    employee1.AddClient(client1);
    employee1.AddClient(client4);

    //Adding Employees
    cout << "\nAdding Employees...\n";
    admin1.AddEmployee(employee1);
    admin1.AddEmployee(employee2);
    admin1.AddEmployee(employee3);

    // Display all clients
    cout << "\nAll Clients:\n";
    employee1.ListClient();
    cout<<"\n============================================================\n";

    // Display all employees
    cout << "\nAll Employees:\n";
    admin1.ListEmployee();
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
        cout<<"\ntrue\n";*/
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

    cout<<allClients.size()<<"/"<<allEmployees.size()<<endl;
    cout << "Total Clients in allClients: " << allClients.size() << endl;
    cout << "Total Employees in allEmployees: " << allEmployees.size() << endl;


    return 0;
}
