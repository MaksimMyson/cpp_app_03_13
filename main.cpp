#include "EmployeeSystem.h"
#include <iostream>
using namespace std;



int main() {
    string file_path = "employees_data.txt";
    EmployeeSystem employee_system(file_path);

    while (true) {
        cout << "\n1. Add an employee" << endl;
        cout << "2. Edit employee data" << endl;
        cout << "3. Delete an employee " << endl;
        cout << "4. Search for an employee by last name" << endl;
        cout << "5. Remove all employees" << endl;
        cout << "6. Save and exit" << endl;

        int choice;
        cout << "Select an option: " << endl;
        cin >> choice; 
        switch (choice) {
        case 1: {
            string name;
            int age;
            cout << "Enter the name of the employee: " << endl;
            cin >> name; 
            cout << "Enter the employee's age: " << endl;
            cin >> age;
            Employee new_employee{ name, age };
            employee_system.add_employee(new_employee);
            break;
        }
        case 2: {
            string old_name, new_name;
            int new_age;
            cout << "Enter the last name of the employee to edit: " << endl;
            cin >> old_name;
            cout << "Enter a new employee name: " << endl;
            cin >> new_name;
            cout << "Enter the new age of the employee: " << endl;
            cin >> new_age;
            Employee new_employee{ new_name, new_age };
            if (!employee_system.edit_employee(old_name, new_employee)) {
                cout << "Employee with last name" << old_name << " not found" << endl;
            }
            break;
        }
        case 3: {
            string name;
            cout << "Enter the last name of the employee to delete: " << endl;
            cin >> name;
            employee_system.delete_employee(name);
            break;
        }
        case 4: {
            string name;
            cout << "Enter the last name of the employee to search: " << endl;
            cin >> name;
            Employee* found_employee = employee_system.search_by_name(name);
            if (found_employee != nullptr) {
                cout << "Employee found:" << found_employee->name << " (Age: " << found_employee->age << ")\n" << endl;
            }
            else {
                cout << "Employee with last name" << name << " not found." << endl;
            }
            break;
        }
        case 5: {
            int age;
            cout << "Enter the age to remove employees:" << endl;
            cin >> age;
            Employee result[MAX_EMPLOYEES];
            int count = employee_system.search_by_age(age, result);
            if (count > 0) {
                cout << "Age employees" << age << ":" << endl;
                for (int i = 0; i < count; ++i) {
                    cout << result[i].name << " (Age: " << result[i].age << ")" << endl;
                }
            }
            else {
                cout << "Age employees " << age << " not found." << endl;
            }
            break;
        }
        case 6: {
            employee_system.save_data();
            cout << "Data saved successfully. The program terminates." << endl;
            return 0;
        }
        default: {
            cout << "Incorrect choice. Try again." << endl;
        }
        }
    }

    return 0;
}