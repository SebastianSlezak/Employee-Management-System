#include "JippVector.h"
#include <iostream>
#include <fstream>
#include <string>

#include "Employee.h"

void addEmployee(JippVector<Employee>& employees) {
    string name, surname;
    int id;
    float salary;

    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter surname: ";
    cin >> surname;
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter salary: ";
    cin >> salary;

    employees.pushBack(Employee(name, surname, id, salary));
    cout << "Employee added successfully." << endl;
}

void editEmployee(JippVector<Employee>& employees) {
    int index;

    cout << "Enter index of employee to edit: ";
    cin >> index;

    if (index < 0 || index >= employees.getSize()) {
        cout << "Invalid index!" << endl;
        return;
    }

    string name, surname;
    int id;
    float salary;

    cout << "Enter new name: ";
    cin >> name;

    cout << "Enter new surname: ";
    cin >> surname;

    cout << "Enter new ID: ";
    cin >> id;

    cout << "Enter new salary: ";
    cin >> salary;

    employees.erase(index);

    employees.insert(index, Employee(name, surname, id, salary));
    cout << "Employee edited successfully." << endl;
}

void deleteEmployee(JippVector<Employee>& employees) {
    int index;
    cout << "Enter index of employee to delete: ";
    cin >> index;

    if (index < 0 || index >= employees.getSize()) {
        cout << "Invalid index!" << endl;
        return;
    }

    employees.erase(index);
    cout << "Employee deleted successfully." << endl;
}

void displayEmployees(const JippVector<Employee>& employees) {
    for (int i = 0; i < employees.getSize(); ++i) {
        cout << "Employee " << i << ": " << employees[i].name << " " << employees[i].surname;
        cout << ", ID: " << employees[i].id << ", Salary: " << employees[i].salary << "\n";
    }
    if (employees.isEmpty()) {
        cout << "No employees to display.\n";
    }
}

void loadFromFile(JippVector<Employee>& employees, const string& filename) {}
void saveToFile(const JippVector<Employee>& employees, const string& filename) {}

int main() {
    JippVector<Employee> employees;
    bool running = true;
    int choice;

    while (running) {
        cout << "1. Add Employee" << endl;
        cout << "2. Edit Employee" << endl;
        cout << "3. Delete Employee" << endl;
        cout << "4. Display Employees" << endl;
        cout << "5. Save to File" << endl;
        cout << "6. Load from File" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: " << endl;

        cin >> choice;

        switch (choice) {
        case 1: addEmployee(employees); break;
        case 2: editEmployee(employees); break;
        case 3: deleteEmployee(employees); break;
        case 4: displayEmployees(employees); break;
        case 5: saveToFile(employees, "employees.dat"); break;
        case 6: loadFromFile(employees, "employees.dat"); break;
        case 7: running = false; break;
        default: cout << "Invalid choice!\n";
        }
    }

    return 0;
}
