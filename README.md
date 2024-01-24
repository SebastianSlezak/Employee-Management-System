# Employee Management System

## Overview
This Employee Management System is a console-based C++ application for managing employee records. It enables adding, editing, deleting, and displaying employees, as well as saving and loading data from files.

## Dependencies
- `Employee.h`: Defines the `Employee` class.
- `JippVector.h`: Implements the `JippVector` template class, a custom vector-like container.

## Employee Class (`Employee.h`)
### Attributes
- `name`: The employee's name.
- `surname`: The employee's surname.
- `id`: The employee's unique identifier.
- `salary`: The employee's salary.

### Public Methods
- `Employee()`: Default constructor.
- `Employee(string, string, int, float)`: Parameterized constructor.
- `getName()`: Returns the employee's name.
- `getSurname()`: Returns the employee's surname.
- `getId()`: Returns the employee's ID.
- `getSalary()`: Returns the employee's salary.

## JippVector Class Template (`JippVector.h`)
A template-based dynamic array implementation.
### Methods
- `JippVector()`: Default constructor.
- `JippVector(size_t)`: Constructor with initial capacity.
- `pushBack(const T&)`, `pushFront(const T&)`: Insert elements.
- `insert(size_t, const T&)`, `erase(size_t)`: Modify elements.
- `operator[](size_t)`: Access elements.
- Other capacity management and size checking methods.

## Main Application (`Employee.cpp`)
### Functions
- `addEmployee(JippVector<Employee>&)`: Adds a new employee.
- `editEmployee(JippVector<Employee>&)`: Edits an existing employee.
- `deleteEmployee(JippVector<Employee>&)`: Deletes an employee.
- `displayEmployees(const JippVector<Employee>&)`: Displays all employees.
- `saveToFile(const JippVector<Employee>&, const string&)`: Saves data to file.
- `loadFromFile(JippVector<Employee>&, const string&)`: Loads data from file.
- `displayRange(const JippVector<Employee>&)`: Displays a range of employees.
- `insertEmployee(JippVector<Employee>&)`: Inserts an employee at a specific index.
- `calculateTotalSalary(const JippVector<Employee>&)`: Calculates total salary.
- `searchBySurname(const JippVector<Employee>&)`: Searches employees by surname.
- `main()`: Entry point, provides a menu-driven interface.

## How to Use
1. Compile the program using a C++ compiler.
2. Run the executable.
3. Follow the on-screen prompts to manage employee records.

## Contributing
Feel free to fork this repository and submit pull requests for any improvements or bug fixes.
