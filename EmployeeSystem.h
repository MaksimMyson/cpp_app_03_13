#include <string>

const int MAX_EMPLOYEES = 100;  // Максимальна кількість співробітників

struct Employee {
    std::string name;
    int age;
};

class EmployeeSystem {
public:
    EmployeeSystem(const std::string& file_path);

    void load_data();
    void save_data();

    void add_employee(const Employee& employee);
    bool edit_employee(const std::string& old_name, const Employee& new_employee);
    void delete_employee(const std::string& name);

    Employee* search_by_name(const std::string& name);
    int search_by_age(int age, Employee* result);
    int search_by_initial_letter(char letter, Employee* result);

private:
    std::string file_path;
    Employee employees[MAX_EMPLOYEES];
    int employee_count;
};