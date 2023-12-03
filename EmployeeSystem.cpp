#include "EmployeeSystem.h"
#include <iostream>
#include <fstream>

using namespace std;

EmployeeSystem::EmployeeSystem(const string& file_path) : file_path(file_path), employee_count(0) {
    load_data();
}

void EmployeeSystem::load_data() {
    try {
        ifstream file(file_path);
        if (!file.is_open()) {
            return;
        }

        while (file >> employees[employee_count].name >> employees[employee_count].age) {
            employee_count++;
            if (employee_count >= MAX_EMPLOYEES) {
                cerr << "Maximum number of employees reached." << endl;
                break;
            }
        }

        file.close();
    }
    catch (const exception& e) {
        cerr << "Error loading data: " << e.what() << endl;
    }
}

void EmployeeSystem::save_data() {
    try {
        ofstream file(file_path);
        if (!file.is_open()) {
            throw runtime_error("Unable to open file for writing.");
        }

        for (int i = 0; i < employee_count; ++i) {
            file << employees[i].name << ' ' << employees[i].age << '\n';
        }

        file.close();
    }
    catch (const exception& e) {
        cerr << "Error saving data: " << e.what() << endl;
    }
}

void EmployeeSystem::add_employee(const Employee& employee) {
    if (employee_count < MAX_EMPLOYEES) {
        employees[employee_count++] = employee;
        save_data();
    }
    else {
        cerr << "Maximum number of employees reached." << endl;
    }
}

bool EmployeeSystem::edit_employee(const string& old_name, const Employee& new_employee) {
    for (int i = 0; i < employee_count; ++i) {
        if (employees[i].name == old_name) {
            employees[i] = new_employee;
            save_data();
            return true;
        }
    }
    return false;
}

void EmployeeSystem::delete_employee(const string& name) {
    for (int i = 0; i < employee_count; ++i) {
        if (employees[i].name == name) {
            for (int j = i; j < employee_count - 1; ++j) {
                employees[j] = employees[j + 1];
            }
            employee_count--;
            save_data();
            return;
        }
    }
}

Employee* EmployeeSystem::search_by_name(const string& name) {
    for (int i = 0; i < employee_count; ++i) {
        if (employees[i].name == name) {
            return &employees[i];
        }
    }
    return nullptr;
}

int EmployeeSystem::search_by_age(int age, Employee* result) {
    int count = 0;
    for (int i = 0; i < employee_count; ++i) {
        if (employees[i].age == age) {
            result[count++] = employees[i];
        }
    }
    return count;
}

int EmployeeSystem::search_by_initial_letter(char letter, Employee* result) {
    int count = 0;
    for (int i = 0; i < employee_count; ++i) {
        if (!employees[i].name.empty() && employees[i].name[0] == letter) {
            result[count++] = employees[i];
        }
    }
    return count;
}