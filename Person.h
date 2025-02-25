#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    int id;
    string name, password;
public:
    Person(){
        this->id=0;
        this->name=" ";
        this->password=" ";
    }
    Person(int id , string name, string password){
        this->id=id;
        this->name=name;
        this->password=password;
    }
    void Setid(int id){
        this->id=id;
    }
    int Getid(){
        return id;
    }
    void Setname(string name){
        this->name=name;
    }
    string Getname(){
        return name;
    }
    void Setpassword(string password){
        this->password=password;
    }
    string Getpassword(){
        return password;
    }
    void Display(){
        cout << "\nId: " << Getid() << " .\n";
        cout << "Name: " << Getname() << " .\n";
        cout << "Password: " << Getpassword() << " .\n";
    }

};

#endif // PERSON_H
