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


    Admin m;
    m.Setname(Validation::Entername());
    m.Setpassword(Validation::Enterpassword());
    m.Setid(Validation::Enterid());
    m.Setsalary(Validation::Entersalary());
    m.Display();
    return 0;
}
