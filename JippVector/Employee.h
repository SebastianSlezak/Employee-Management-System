#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "JippVector.h"
#include <iostream>
#include <string>

using namespace std;

class Employee {
public:
    string name;
    string surname;
    int id;
    float salary;

    Employee() : name(""), surname(""), id(0), salary(0.0f) {}

    Employee(string name, string surname, int id, float salary)
        : name(name), surname(surname), id(id), salary(salary) {}

    void addEmployee(JippVector<Employee>& employees);
    void editEmployee(JippVector<Employee>& employees);
    void deleteEmployee(JippVector<Employee>& employees);
    void displayEmployees(const JippVector<Employee>& employees);
    void loadFromFile(JippVector<Employee>& employees, const string& filename);
    void saveToFile(const JippVector<Employee>& employees, const string& filename);
};

#endif //EMPLOYEE_H