#pragma once

#include "JippVector.h"
#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string name;
    string surname;
    int id;
    float salary;

public:
    Employee() : name(""), surname(""), id(0), salary(0.0f) {}

    Employee(string name, string surname, int id, float salary)
        : name(name), surname(surname), id(id), salary(salary) {}

    string getName() const {
        return name;
    }

    string getSurname() const {
        return surname;
    }

    int getId() const {
        return id;
    }

    float getSalary() const {
        return salary;
    }

    void addEmployee(JippVector<Employee>& employees);
    void editEmployee(JippVector<Employee>& employees);
    void deleteEmployee(JippVector<Employee>& employees);
    void displayEmployees(const JippVector<Employee>& employees);
    void loadFromFile(JippVector<Employee>& employees, const string& filename);
    void saveToFile(const JippVector<Employee>& employees, const string& filename);
    void displayRange(const JippVector<Employee>& employees);
    void insertEmployee(JippVector<Employee>& employees);
    float calculateTotalSalary(const JippVector<Employee>& employees);
    void searchBySurname(const JippVector<Employee>& employees);
};