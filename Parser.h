#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <vector>
#include <sstream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

using namespace std;

class Parser {
private:
    static vector<string> Split(string line) {
        vector<string> result;
        string item;

        for (char ch : line) {
            if (ch == '&') {
                result.push_back(item);
                item.clear();
            }
            else {
                item += ch;
            }
        }
        if (!item.empty()) {
            result.push_back(item);
        }

        return result;
    }

public:
    static Client ParseToClient(string line) {
         vector< string> tokens = Split(line);
        return Client( stoi(tokens[0]), tokens[1], tokens[2],  stod(tokens[3]));
    }

    static Employee ParseToEmployee(string line) {
         vector< string> tokens = Split(line);
        return Employee( stoi(tokens[0]), tokens[1], tokens[2],  stod(tokens[3]));
    }

    static Admin ParseToAdmin(string line) {
         vector< string> tokens = Split(line);
        return Admin( stoi(tokens[0]), tokens[1], tokens[2],  stod(tokens[3]));
    }
};

#endif // PARSER_H
