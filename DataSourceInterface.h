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
    virtual void AddClient(const Client& client)=0 ;
    virtual void AddEmployee(const Employee& employee)=0 ;
    virtual void AddAdmin(const Admin& admin)=0 ;

    virtual void GetAllClients() const =0;
    virtual void GetAllEmployees() const =0;
    virtual void GetAllAdmins() const =0;

    virtual void RemoveAllClients()=0;
    virtual void RemoveAllEmployees()=0;
    virtual void RemoveAllAdmins()=0;

    virtual ~DataSourceInterface() {}

};

#endif // DATASOURCEINTERFACE_H
