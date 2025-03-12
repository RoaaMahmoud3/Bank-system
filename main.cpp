#include<iostream>
#include<string>
#include<vector>
#include"Validation.h"
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "FileManager.h"
#include "AdminManager.h"
#include "ClientManger.h"
#include<fstream>
#include "EmployeeManager.h"
#include "Screens.h"
using namespace std;


int main() {

    // Static data for admins
    Admin admin1(1, "EVEEMAHMOUD", "adminPass1", 6000);
    Admin admin2(2, "FrankAHMED", "adminPass2", 7000);

    Screens::runApp();

    return 0;
}
