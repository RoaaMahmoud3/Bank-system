#ifndef DATASOURCEINTERFACE_H
#define DATASOURCEINTERFACE_H
#include<iostream>
#include<string>
#include"Validation.h"
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;
class DataSourceInterface
{
public:
    virtual void AddClient(Client )=0 ;
    virtual void AddEmployee(Employee )=0 ;
    virtual void AddAdmin(Admin )=0 ;

    virtual void GetAllClients()  =0;
    virtual void GetAllEmployees()  =0;
    virtual void GetAllAdmins()  =0;

    virtual void RemoveAllClients()=0;
    virtual void RemoveAllEmployees()=0;
    virtual void RemoveAllAdmins()=0;

    virtual ~DataSourceInterface() {}

};

#endif // DATASOURCEINTERFACE_H
