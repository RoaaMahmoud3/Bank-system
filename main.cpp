#include<iostream>
#include<string>
#include"Validation.h"
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include<fstream>
using namespace std;


int main()
{
    /*ofstream file("Client.txt");
    file.close();*/
    /*ofstream file("Employee.txt");
    file.close();*/
    /*ofstream file("Admin.txt");
    file.close();*/
    /*ofstream file("text.txt");
    file<<"this is my first\n";
    file<<"this is my first\n";
    file<<"this is my first\n";
    file.close();*/

    Admin m;
    m.Setname(Validation::Entername());
    m.Setpassword(Validation::Enterpassword());
    m.Setid(Validation::Enterid());
    m.Setsalary(Validation::Entersalary());
    m.Display();
    return 0;
}
